/*******************************************************************************
 *   (c) 2018 - 2024 Zondax AG
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
#include "crypto_helper.h"
#include "cx.h"
#include "zxmacros.h"

#define PREFIX_SIGNATURE_TYPE_ED25519 0

uint32_t hdPath[HDPATH_LEN_DEFAULT];

static zxerr_t crypto_extractPublicKey(uint8_t *pubKey, uint16_t pubKeyLen, uint32_t *hdPath_to_use) {
    if (pubKey == NULL || pubKeyLen < PK_LEN_25519) {
        return zxerr_buffer_too_small;
    }

    zxerr_t error = zxerr_unknown;
    cx_ecfp_public_key_t cx_publicKey;
    cx_ecfp_private_key_t cx_privateKey;
    uint8_t privateKeyData[SK_LEN_25519] = {0};

    // Generate keys
    CATCH_CXERROR(os_derive_bip32_with_seed_no_throw(HDW_NORMAL, CX_CURVE_Ed25519, hdPath_to_use, HDPATH_LEN_DEFAULT,
                                                     privateKeyData, NULL, NULL, 0));

    CATCH_CXERROR(cx_ecfp_init_private_key_no_throw(CX_CURVE_Ed25519, privateKeyData, 32, &cx_privateKey));
    CATCH_CXERROR(cx_ecfp_init_public_key_no_throw(CX_CURVE_Ed25519, NULL, 0, &cx_publicKey));
    CATCH_CXERROR(cx_ecfp_generate_pair_no_throw(CX_CURVE_Ed25519, &cx_publicKey, &cx_privateKey, 1));
    for (unsigned int i = 0; i < PK_LEN_25519; i++) {
        pubKey[i] = cx_publicKey.W[64 - i];
    }

    if ((cx_publicKey.W[PK_LEN_25519] & 1) != 0) {
        pubKey[31] |= 0x80;
    }
    error = zxerr_ok;

catch_cx_error:
    MEMZERO(&cx_privateKey, sizeof(cx_privateKey));
    MEMZERO(privateKeyData, SK_LEN_25519);

    if (error != zxerr_ok) {
        MEMZERO(pubKey, pubKeyLen);
    }
    return error;
}

zxerr_t crypto_sign_ed25519(uint8_t *signature, uint16_t signatureMaxlen, const uint8_t *message, uint16_t messageLen) {
    if (signature == NULL || message == NULL || signatureMaxlen < SIG_PLUS_TYPE_LEN || messageLen == 0) {
        return zxerr_buffer_too_small;
    }
    cx_ecfp_private_key_t cx_privateKey;
    uint8_t privateKeyData[SK_LEN_25519] = {0};

    const uint8_t *toSign = message;
    uint8_t messageDigest[BLAKE2B_DIGEST_SIZE] = {0};

    zxerr_t error = zxerr_unknown;

    if (messageLen > MAX_SIGN_SIZE) {
        // Hash it
        cx_blake2b_t ctx;
        CATCH_CXERROR(cx_blake2b_init_no_throw(&ctx, 256));
        CATCH_CXERROR(cx_hash_no_throw(&ctx.header, CX_LAST, message, messageLen, messageDigest, BLAKE2B_DIGEST_SIZE));
        toSign = messageDigest;
        messageLen = BLAKE2B_DIGEST_SIZE;
    }

    // Generate keys
    CATCH_CXERROR(os_derive_bip32_with_seed_no_throw(HDW_NORMAL, CX_CURVE_Ed25519, hdPath, HDPATH_LEN_DEFAULT,
                                                     privateKeyData, NULL, NULL, 0));

    CATCH_CXERROR(cx_ecfp_init_private_key_no_throw(CX_CURVE_Ed25519, privateKeyData, SCALAR_LEN_ED25519, &cx_privateKey));

    // Sign
    *signature = PREFIX_SIGNATURE_TYPE_ED25519;
    CATCH_CXERROR(cx_eddsa_sign_no_throw(&cx_privateKey, CX_SHA512, toSign, messageLen, signature + 1, signatureMaxlen - 1));
    error = zxerr_ok;

catch_cx_error:
    MEMZERO(&cx_privateKey, sizeof(cx_privateKey));
    MEMZERO(privateKeyData, SK_LEN_25519);

    if (error != zxerr_ok) {
        MEMZERO(signature, signatureMaxlen);
    }

    return error;
}

// Helper function to fill a crypto address using a given hdPath
static zxerr_t crypto_fillAddress_helper(
    uint8_t *buffer, uint16_t bufferLen, uint16_t *addrResponseLen, uint16_t ss58prefix, uint32_t *hdPath_to_use) {
    if (bufferLen < PK_LEN_25519 + SS58_ADDRESS_MAX_LEN) {
        return zxerr_buffer_too_small;
    }
    MEMZERO(buffer, bufferLen);
    CHECK_ZXERR(crypto_extractPublicKey(buffer, bufferLen, hdPath_to_use))

    const uint8_t outLen = crypto_SS58EncodePubkey(buffer + PK_LEN_25519, bufferLen - PK_LEN_25519, ss58prefix, buffer);
    if (outLen == 0) {
        MEMZERO(buffer, bufferLen);
        return zxerr_unknown;
    }

    *addrResponseLen = PK_LEN_25519 + outLen;
    return zxerr_ok;
}

// fill a crypto address using the global hdpath
zxerr_t crypto_fillAddress(uint8_t *buffer, uint16_t bufferLen, uint16_t *addrResponseLen, const uint16_t ss58prefix) {
    return crypto_fillAddress_helper(buffer, bufferLen, addrResponseLen, ss58prefix, hdPath);
}

#if 0
// fill a crypto address using a locally computed hdpath
zxerr_t crypto_fillAddress_standalone(uint8_t *params, uint8_t paramsSize, uint8_t *buffer, uint16_t bufferLen,
                                      uint16_t *addrResponseLen, const uint16_t ss58prefix) {
    uint32_t local_hdPath[HDPATH_LEN_DEFAULT];

    if (paramsSize != (sizeof(uint32_t) * HDPATH_LEN_DEFAULT)) {
        return zxerr_invalid_crypto_settings;
    }

    for (uint32_t i = 0; i < HDPATH_LEN_DEFAULT; i++) {
        CHECK_ZXERR(readU32BE(params + (i * 4), &local_hdPath[i]))
    }

    return crypto_fillAddress_helper(buffer, bufferLen, addrResponseLen, ss58prefix, local_hdPath);
}
#endif
