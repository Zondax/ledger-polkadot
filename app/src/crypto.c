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

uint32_t hdPath[HDPATH_LEN_DEFAULT];

zxerr_t crypto_extractPublicKey(key_kind_e addressKind, const uint32_t path[HDPATH_LEN_DEFAULT],
                                uint8_t *pubKey, uint16_t pubKeyLen) {
    cx_ecfp_public_key_t cx_publicKey;
    cx_ecfp_private_key_t cx_privateKey;
    uint8_t privateKeyData[SK_LEN_25519];

    if (pubKeyLen < PK_LEN_25519) {
        return zxerr_invalid_crypto_settings;
    }

    zxerr_t err = zxerr_ok;
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
                    err = zxerr_invalid_crypto_settings;
                    break;
            }
        }
        CATCH_ALL
        {
            err = zxerr_unknown;
        }
        FINALLY
        {
            MEMZERO(&cx_privateKey, sizeof(cx_privateKey));
            MEMZERO(privateKeyData, SK_LEN_25519);
        }
    }
    END_TRY;

    return err;
}

zxerr_t crypto_sign_ed25519(uint8_t *signature, uint16_t signatureMaxlen, const uint8_t *message, uint16_t messageLen) {
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
    unsigned int info = 0;

    zxerr_t err = zxerr_ok;
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
            cx_eddsa_sign(&cx_privateKey,
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
            err = zxerr_unknown;
        }
        FINALLY
        {
            MEMZERO(&cx_privateKey, sizeof(cx_privateKey));
            MEMZERO(privateKeyData, SK_LEN_25519);
        }
    }
    END_TRY;

    return err;
}

#ifdef SUPPORT_SR25519
static uint8_t sr25519_signature[SIG_PLUS_TYPE_LEN];

void zeroize_sr25519_signdata(void) {
    explicit_bzero(sr25519_signature, sizeof(sr25519_signature));
}

void copy_sr25519_signdata(uint8_t *buffer) {
    memcpy(buffer, sr25519_signature, SIG_PLUS_TYPE_LEN);
}

static zxerr_t crypto_sign_sr25519_helper(const uint8_t *data, size_t len) {
    uint8_t sk[SK_LEN_25519];
    uint8_t pk[PK_LEN_25519];

    zxerr_t err = zxerr_ok;
    int ret = 0;

    BEGIN_TRY
    {
        TRY
        {
            os_perso_derive_node_bip32_seed_key(
                    HDW_NORMAL,
                    CX_CURVE_Ed25519,
                    hdPath,
                    HDPATH_LEN_DEFAULT,
                    sk,
                    NULL,
                    NULL,
                    0);
            get_sr25519_sk(sk);
            ret = crypto_scalarmult_ristretto255_base_sdk(pk, sk);
            if (ret == 0) {
                *sr25519_signature = PREFIX_SIGNATURE_TYPE_SR25519;
                sign_sr25519_phase1((const uint8_t *)&sk, (const uint8_t *)&pk, NULL, 0,
                                    data, len, sr25519_signature + 1);

                ret = crypto_scalarmult_ristretto255_base_sdk(sr25519_signature + 1, sr25519_signature + 1 + PK_LEN_25519);
            }
        }
        CATCH_ALL
        {
            err = zxerr_unknown;
        }
        FINALLY
        {
        }
    }
    END_TRY;

    if (ret != 0 || err != zxerr_ok) {
        err = zxerr_unknown;
        explicit_bzero(sr25519_signature, sizeof(sr25519_signature));
    } else {
        sign_sr25519_phase2((const uint8_t *)sk, (const uint8_t *)pk, NULL, 0,
                            data, len, sr25519_signature + 1);
    }

    MEMZERO(pk, sizeof(pk));
    MEMZERO(sk, sizeof(sk));

    return err;
}

zxerr_t crypto_sign_sr25519(const uint8_t *message, size_t messageLen) {
    uint8_t messageDigest[BLAKE2B_DIGEST_SIZE];
    const uint8_t *data;
    size_t len;

    if (messageLen > MAX_SIGN_SIZE) {
        cx_blake2b_t ctx;
        cx_blake2b_init(&ctx, 256);
        cx_hash(&ctx.header, CX_LAST, message, messageLen, messageDigest, BLAKE2B_DIGEST_SIZE);
        data = messageDigest;
        len = BLAKE2B_DIGEST_SIZE;
    } else {
        data = message;
        len = messageLen;
    }

    return crypto_sign_sr25519_helper(data, len);
}
#endif

zxerr_t crypto_fillAddress(key_kind_e addressKind, uint8_t *buffer, uint16_t bufferLen, uint16_t *addrResponseLen) {
    if (bufferLen < PK_LEN_25519 + SS58_ADDRESS_MAX_LEN) {
        return zxerr_unknown;
    }
    MEMZERO(buffer, bufferLen);
    CHECK_ZXERR(crypto_extractPublicKey(addressKind, hdPath, buffer, bufferLen))

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
