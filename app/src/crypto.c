/*******************************************************************************
*   (c) 2019 Zondax GmbH
*
*  Licensed under the Apache License, Version 2.0 (the "License");
*  you may not use this file except in compliance with the License.
*  You may obtain a copy of the License at
*
*      http://www.apache.org/licenses/LICENSE-2.0
*
*  Unless required by applicable law or agreed to in writing, software
*  distributed under the License is distributed on an "AS IS" BASIS,
*  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*  See the License for the specific language governing permissions and
*  limitations under the License.
********************************************************************************/

#include "crypto.h"
#include "base58.h"
#include "coin.h"
#include "cx.h"
#include "zxmacros.h"
#include "ristretto.h"
#include "crypto_helper.h"

#ifdef SUPPORT_SR25519
#include "rslib.h"
#endif

uint32_t hdPath[HDPATH_LEN_DEFAULT];

static zxerr_t crypto_extractPublicKey(key_kind_e addressKind, uint8_t *pubKey, uint16_t pubKeyLen) {
    if (pubKey == NULL || pubKeyLen < PK_LEN_25519) {
        return zxerr_invalid_crypto_settings;
    }

    zxerr_t error = zxerr_unknown;
    cx_ecfp_public_key_t cx_publicKey;
    cx_ecfp_private_key_t cx_privateKey;
    uint8_t privateKeyData[SK_LEN_25519] = {0};

    // Generate keys
    CATCH_CXERROR(os_derive_bip32_with_seed_no_throw(HDW_NORMAL,
                                                     CX_CURVE_Ed25519,
                                                     hdPath,
                                                     HDPATH_LEN_DEFAULT,
                                                     privateKeyData,
                                                     NULL,
                                                     NULL,
                                                     0))

    switch (addressKind) {
        case key_ed25519: {
            CATCH_CXERROR(cx_ecfp_init_private_key_no_throw(CX_CURVE_Ed25519, privateKeyData, 32, &cx_privateKey))
            CATCH_CXERROR(cx_ecfp_init_public_key_no_throw(CX_CURVE_Ed25519, NULL, 0, &cx_publicKey))
            CATCH_CXERROR(cx_ecfp_generate_pair_no_throw(CX_CURVE_Ed25519, &cx_publicKey, &cx_privateKey, 1))
            for (unsigned int i = 0; i < PK_LEN_25519; i++) {
                pubKey[i] = cx_publicKey.W[64 - i];
            }

            if ((cx_publicKey.W[PK_LEN_25519] & 1) != 0) {
                pubKey[31] |= 0x80;
            }
            error = zxerr_ok;
            break;
        }
#ifdef SUPPORT_SR25519
        case key_sr25519:
            get_sr25519_sk(privateKeyData);
            CATCH_CXERROR(crypto_scalarmult_ristretto255_base_sdk(pubKey, privateKeyData))
            error = zxerr_ok;
            break;
#endif
        default:
            error = zxerr_invalid_crypto_settings;
            break;
    }

catch_cx_error:
    MEMZERO(&cx_privateKey, sizeof(cx_privateKey));
    MEMZERO(privateKeyData, SK_LEN_25519);

    if (error != zxerr_ok) {
        MEMZERO(pubKey, pubKeyLen);
    }
    return error;
}

zxerr_t crypto_sign_ed25519(uint8_t *signature, uint16_t signatureMaxlen, const uint8_t *message, uint16_t messageLen) {
    if (signature == NULL || message == NULL || signatureMaxlen < SIG_PLUS_TYPE_LEN) {
        return zxerr_unknown;
    }
    cx_ecfp_private_key_t cx_privateKey;
    uint8_t privateKeyData[SK_LEN_25519] = {0};

    const uint8_t *toSign = message;
    uint8_t messageDigest[BLAKE2B_DIGEST_SIZE] = {0};

    zxerr_t error = zxerr_unknown;

    if (messageLen > MAX_SIGN_SIZE) {
        // Hash it
        cx_blake2b_t ctx;
        CATCH_CXERROR(cx_blake2b_init_no_throw(&ctx, 256))
        CATCH_CXERROR(cx_hash_no_throw(&ctx.header, CX_LAST, message, messageLen, messageDigest, BLAKE2B_DIGEST_SIZE))
        toSign = messageDigest;
        messageLen = BLAKE2B_DIGEST_SIZE;
    }

    // Generate keys
    CATCH_CXERROR(os_derive_bip32_with_seed_no_throw(HDW_NORMAL,
                                                     CX_CURVE_Ed25519,
                                                     hdPath,
                                                     HDPATH_LEN_DEFAULT,
                                                     privateKeyData,
                                                     NULL,
                                                     NULL,
                                                     0))

    CATCH_CXERROR(cx_ecfp_init_private_key_no_throw(CX_CURVE_Ed25519, privateKeyData, SCALAR_LEN_ED25519, &cx_privateKey))

    // Sign
    *signature = PREFIX_SIGNATURE_TYPE_ED25519;
    CATCH_CXERROR(cx_eddsa_sign_no_throw(&cx_privateKey,
                                         CX_SHA512,
                                         toSign,
                                         messageLen,
                                         signature + 1,
                                         signatureMaxlen - 1))
    error = zxerr_ok;

catch_cx_error:
    MEMZERO(&cx_privateKey, sizeof(cx_privateKey));
    MEMZERO(privateKeyData, SK_LEN_25519);

    if (error != zxerr_ok) {
        MEMZERO(signature, signatureMaxlen);
    }

    return error;
}

#ifdef SUPPORT_SR25519
static uint8_t sr25519_signature[SIG_PLUS_TYPE_LEN] = {0};

void zeroize_sr25519_signdata(void) {
    explicit_bzero(sr25519_signature, sizeof(sr25519_signature));
}

zxerr_t copy_sr25519_signdata(uint8_t *buffer, uint16_t bufferLen) {
    if (SIG_PLUS_TYPE_LEN > bufferLen) {
        return zxerr_buffer_too_small;
    }

    memcpy(buffer, sr25519_signature, SIG_PLUS_TYPE_LEN);
    return zxerr_ok;
}

static zxerr_t crypto_sign_sr25519_helper(const uint8_t *data, size_t len) {
    uint8_t privateKeyData[SK_LEN_25519] = {0};
    uint8_t pubkey[PK_LEN_25519] = {0};

    zxerr_t error = zxerr_unknown;

    // Generate keys
    CATCH_CXERROR(os_derive_bip32_with_seed_no_throw(HDW_NORMAL,
                                                     CX_CURVE_Ed25519,
                                                     hdPath,
                                                     HDPATH_LEN_DEFAULT,
                                                     privateKeyData,
                                                     NULL,
                                                     NULL,
                                                     0))

    get_sr25519_sk(privateKeyData);
    CATCH_CXERROR(crypto_scalarmult_ristretto255_base_sdk(pubkey, privateKeyData))
    *sr25519_signature = PREFIX_SIGNATURE_TYPE_SR25519;
    sign_sr25519_phase1(privateKeyData, pubkey, NULL, 0, data, len, sr25519_signature + 1);
    CATCH_CXERROR(crypto_scalarmult_ristretto255_base_sdk(sr25519_signature + 1, sr25519_signature + 1 + PK_LEN_25519))
    error = zxerr_ok;

catch_cx_error:
    if (error == zxerr_ok) {
        sign_sr25519_phase2((const uint8_t *)privateKeyData, (const uint8_t *)pubkey, NULL, 0,
                            data, len, sr25519_signature + 1);
    } else {
        explicit_bzero(sr25519_signature, sizeof(sr25519_signature));
    }

    MEMZERO(pubkey, sizeof(pubkey));
    MEMZERO(privateKeyData, sizeof(privateKeyData));

    return error;
}

zxerr_t crypto_sign_sr25519(const uint8_t *message, size_t messageLen) {
    if (message == NULL) {
        return zxerr_unknown;
    }

    uint8_t messageDigest[BLAKE2B_DIGEST_SIZE] = {0};
    const uint8_t *toSign = message;

    if (messageLen > MAX_SIGN_SIZE) {
        // Hash it
        cx_blake2b_t ctx;
        if  ((cx_blake2b_init_no_throw(&ctx, 256) != CX_OK) ||
            (cx_hash_no_throw(&ctx.header, CX_LAST, message, messageLen, messageDigest, BLAKE2B_DIGEST_SIZE) != CX_OK)) {
                return zxerr_unknown;
        }
        toSign = messageDigest;
        messageLen = BLAKE2B_DIGEST_SIZE;
    }

    return crypto_sign_sr25519_helper(toSign, messageLen);
}
#endif

zxerr_t crypto_fillAddress(key_kind_e addressKind, uint8_t *buffer, uint16_t bufferLen, uint16_t *addrResponseLen) {
    if (bufferLen < PK_LEN_25519 + SS58_ADDRESS_MAX_LEN) {
        return zxerr_unknown;
    }
    MEMZERO(buffer, bufferLen);
    CHECK_ZXERR(crypto_extractPublicKey(addressKind, buffer, bufferLen))

    size_t outLen = crypto_SS58EncodePubkey(buffer + PK_LEN_25519,
                                            bufferLen - PK_LEN_25519,
                                            PK_ADDRESS_TYPE, buffer);
    if (outLen == 0) {
        MEMZERO(buffer, bufferLen);
        return zxerr_unknown;
    }

    *addrResponseLen = PK_LEN_25519 + outLen;
    return zxerr_ok;
}
