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
#include "rslib.h"
#include "zxmacros.h"
#include "ristretto.h"

uint16_t sr25519_signdataLen;
uint32_t hdPath[HDPATH_LEN_DEFAULT];

zxerr_t crypto_extractPublicKey(key_kind_e addressKind, const uint32_t path[HDPATH_LEN_DEFAULT],
                                uint8_t *pubKey, uint16_t pubKeyLen) {
    cx_ecfp_public_key_t cx_publicKey;
    cx_ecfp_private_key_t cx_privateKey;
    uint8_t privateKeyData[SK_LEN_25519];
    MEMZERO(privateKeyData, SK_LEN_25519);

    if (pubKeyLen < PK_LEN_25519) {
        return zxerr_invalid_crypto_settings;
    }

    BEGIN_TRY
    {
        TRY
        {
            // Generate keys
            os_perso_derive_node_bip32_seed_key(
                    HDW_NORMAL,
                    CX_CURVE_Ed25519,
                    path,
                    HDPATH_LEN_DEFAULT,
                    privateKeyData,
                    NULL,
                    NULL,
                    0);

            switch (addressKind) {
                case key_ed25519: {
                    cx_ecfp_init_private_key(CX_CURVE_Ed25519, privateKeyData, 32, &cx_privateKey);
                    cx_ecfp_init_public_key(CX_CURVE_Ed25519, NULL, 0, &cx_publicKey);
                    cx_ecfp_generate_pair(CX_CURVE_Ed25519, &cx_publicKey, &cx_privateKey, 1);
                    for (unsigned int i = 0; i < PK_LEN_25519; i++) {
                        pubKey[i] = cx_publicKey.W[64 - i];
                    }

                    if ((cx_publicKey.W[PK_LEN_25519] & 1) != 0) {
                        pubKey[31] |= 0x80;
                    }
                    break;
                }
#ifdef SUPPORT_SR25519
                    case key_sr25519:
                            get_sr25519_sk(privateKeyData);
                            crypto_scalarmult_ristretto255_base_sdk(pubKey, privateKeyData);
                        break;
#endif
                default:
                    CLOSE_TRY;
                    return zxerr_invalid_crypto_settings;
            }
        }
        FINALLY
        {
            MEMZERO(&cx_privateKey, sizeof(cx_privateKey));
            MEMZERO(privateKeyData, SK_LEN_25519);
        }
    }
    END_TRY;

    return zxerr_ok;
}

zxerr_t crypto_sign_ed25519(uint8_t *signature, uint16_t signatureMaxlen,
                            const uint8_t *message, uint16_t messageLen,
                            uint16_t *signatureLen) {
    const uint8_t *toSign = message;
    uint8_t messageDigest[BLAKE2B_DIGEST_SIZE];

    if (messageLen > MAX_SIGN_SIZE) {
        // Hash it
        cx_blake2b_t ctx;
        cx_blake2b_init(&ctx, 256);
        cx_hash(&ctx.header, CX_LAST, message, messageLen, messageDigest, BLAKE2B_DIGEST_SIZE);
        toSign = messageDigest;
        messageLen = BLAKE2B_DIGEST_SIZE;
    }

    cx_ecfp_private_key_t cx_privateKey;
    uint8_t privateKeyData[SK_LEN_25519];
    int signatureLength = 0;
    unsigned int info = 0;

    BEGIN_TRY
    {
        TRY
        {
            // Generate keys
            os_perso_derive_node_bip32_seed_key(
                    HDW_NORMAL,
                    CX_CURVE_Ed25519,
                    hdPath,
                    HDPATH_LEN_DEFAULT,
                    privateKeyData,
                    NULL,
                    NULL,
                    0);

            cx_ecfp_init_private_key(CX_CURVE_Ed25519, privateKeyData, SCALAR_LEN_ED25519, &cx_privateKey);

            // Sign
            *signature = PREFIX_SIGNATURE_TYPE_ED25519;
            signatureLength = cx_eddsa_sign(&cx_privateKey,
                                            CX_LAST,
                                            CX_SHA512,
                                            toSign,
                                            messageLen,
                                            NULL,
                                            0,
                                            signature + 1,
                                            signatureMaxlen - 1,
                                            &info);

        }
        CATCH_ALL
        {
            MEMZERO(&cx_privateKey, sizeof(cx_privateKey));
            *signatureLen = 0;
            CLOSE_TRY;
            return zxerr_unknown;
        };
        FINALLY
        {
            MEMZERO(&cx_privateKey, sizeof(cx_privateKey));
            MEMZERO(privateKeyData, SK_LEN_25519);
            MEMZERO(signature + signatureLength + 1, signatureMaxlen - signatureLength - 1);
        }
    }
    END_TRY;
    return zxerr_ok;
}

#ifdef SUPPORT_SR25519
zxerr_t crypto_sign_sr25519_prephase(uint8_t *buffer, uint16_t bufferLen,
                                     const uint8_t *message, uint16_t messageLen) {
    if (messageLen > MAX_SIGN_SIZE) {
        uint8_t messageDigest[BLAKE2B_DIGEST_SIZE];
        cx_blake2b_t *ctx = (cx_blake2b_t *) buffer;
        cx_blake2b_init(ctx, 256);
        cx_hash(&ctx->header, CX_LAST, message, messageLen, messageDigest, BLAKE2B_DIGEST_SIZE);
        MEMCPY_NV((void *) &N_sr25519_signdata.signdata, messageDigest, BLAKE2B_DIGEST_SIZE);
        sr25519_signdataLen = BLAKE2B_DIGEST_SIZE;
    } else {
        MEMCPY_NV((void *) &N_sr25519_signdata.signdata, (void *) message, messageLen);
        sr25519_signdataLen = messageLen;
    }

    MEMZERO(buffer, bufferLen);
    uint8_t privateKeyData[SK_LEN_25519];
    MEMZERO(privateKeyData, SK_LEN_25519);
    os_perso_derive_node_bip32_seed_key(
            HDW_NORMAL,
            CX_CURVE_Ed25519,
            hdPath,
            HDPATH_LEN_DEFAULT,
            privateKeyData,
            NULL,
            NULL,
            0);

    uint8_t pubkey[PK_LEN_25519];
    MEMZERO(pubkey, PK_LEN_25519);
    get_sr25519_sk(privateKeyData);
    crypto_scalarmult_ristretto255_base_sdk(pubkey, privateKeyData);
    MEMCPY_NV((void *) &N_sr25519_signdata.sk, privateKeyData, SK_LEN_25519);
    MEMCPY_NV((void *) &N_sr25519_signdata.pk, pubkey, PK_LEN_25519);
    MEMZERO(buffer, bufferLen);
    return zxerr_ok;
}

zxerr_t crypto_sign_sr25519(uint8_t *signature, uint16_t signatureMaxlen,
                            uint16_t *signatureLen) {

    BEGIN_TRY
    {
        TRY
        {
            if (signatureMaxlen < MIN_BUFFER_LENGTH) {
                CLOSE_TRY;
                return zxerr_invalid_crypto_settings;
            }
            *signature = PREFIX_SIGNATURE_TYPE_SR25519;
            sign_sr25519_phase1((uint8_t *) &N_sr25519_signdata.sk, (uint8_t *) &N_sr25519_signdata.pk, NULL, 0,
                         (uint8_t *) &N_sr25519_signdata.signdata, sr25519_signdataLen, signature + 1);
            crypto_scalarmult_ristretto255_base_sdk(signature + 1, signature + 1 + PK_LEN_25519);
            sign_sr25519_phase2((uint8_t *) &N_sr25519_signdata.sk, (uint8_t *) &N_sr25519_signdata.pk, NULL, 0,
                         (uint8_t *) &N_sr25519_signdata.signdata, sr25519_signdataLen, signature + 1);
            MEMCPY_NV((void *) &N_sr25519_signdata.signature, signature, SIG_PLUS_TYPE_LEN);
        }
        CATCH_ALL
        {
            CLOSE_TRY;
            return zxerr_unknown;
        };
        FINALLY
        {
            MEMZERO(signature + SIG_PLUS_TYPE_LEN, signatureMaxlen - SIG_PLUS_TYPE_LEN);
        }
    }
    END_TRY;
    return zxerr_ok;
}
#endif

zxerr_t crypto_fillAddress(key_kind_e addressKind, uint8_t *buffer, uint16_t bufferLen, uint16_t *addrResponseLen) {
    if (bufferLen < PK_LEN_25519 + SS58_ADDRESS_MAX_LEN) {
        return 0;
    }
    MEMZERO(buffer, bufferLen);
    CHECK_ZXERR(crypto_extractPublicKey(addressKind, hdPath, buffer, bufferLen));

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
