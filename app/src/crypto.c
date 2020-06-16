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
#include "coin.h"

#include "base58.h"

uint32_t hdPath[HDPATH_LEN_DEFAULT];
#define SS58_BLAKE_PREFIX  (const unsigned char *) "SS58PRE"
#define SS58_BLAKE_PREFIX_LEN 7

#define SIGNATURE_TYPE_ED25519  0
#define SIGNATURE_TYPE_SR25519  1
#define SIGNATURE_TYPE_EDCSA    2

#if defined(TARGET_NANOS) || defined(TARGET_NANOX)
#include "cx.h"

void crypto_extractPublicKey(const uint32_t path[HDPATH_LEN_DEFAULT], uint8_t *pubKey, uint16_t pubKeyLen) {
    cx_ecfp_public_key_t cx_publicKey;
    cx_ecfp_private_key_t cx_privateKey;
    uint8_t privateKeyData[32];

    if (pubKeyLen < PK_LEN_ED25519) {
        return;
    }

    BEGIN_TRY
    {
        TRY {
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

            cx_ecfp_init_private_key(CX_CURVE_Ed25519, privateKeyData, 32, &cx_privateKey);
            cx_ecfp_init_public_key(CX_CURVE_Ed25519, NULL, 0, &cx_publicKey);
            cx_ecfp_generate_pair(CX_CURVE_Ed25519, &cx_publicKey, &cx_privateKey, 1);
        }
        FINALLY {
            MEMZERO(&cx_privateKey, sizeof(cx_privateKey));
            MEMZERO(privateKeyData, 32);
        }
    }
    END_TRY;

    // Format pubkey
    for (int i = 0; i < 32; i++) {
        pubKey[i] = cx_publicKey.W[64 - i];
    }

    if ((cx_publicKey.W[32] & 1) != 0) {
        pubKey[31] |= 0x80;
    }
}

uint16_t crypto_sign(uint8_t *signature, uint16_t signatureMaxlen, const uint8_t *message, uint16_t messageLen) {
    const uint8_t *toSign = message;
    uint8_t messageDigest[32];

    if (messageLen > 256) {
        // Hash it
        cx_blake2b_t ctx;
        cx_blake2b_init(&ctx, 256);
        cx_hash(&ctx.header, CX_LAST, message, messageLen, messageDigest, 32);
        toSign = messageDigest;
        messageLen = 32;
    }

    cx_ecfp_private_key_t cx_privateKey;
    uint8_t privateKeyData[32];
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
            cx_ecfp_init_private_key(CX_CURVE_Ed25519, privateKeyData, 32, &cx_privateKey);

            // Sign
            *signature = SIGNATURE_TYPE_ED25519;
            signatureLength = cx_eddsa_sign(&cx_privateKey,
                                            CX_LAST,
                                            CX_SHA512,
                                            toSign,
                                            messageLen,
                                            NULL,
                                            0,
                                            signature+1,
                                            signatureMaxlen-1,
                                            &info);
        }
        CATCH_ALL {
            return 0;
        };
        FINALLY {
            MEMZERO(&cx_privateKey, sizeof(cx_privateKey));
            MEMZERO(privateKeyData, 32);
        }
    }
    END_TRY;

    return signatureLength + 1;
}

int ss58hash(const unsigned char *in, unsigned int inLen,
                   unsigned char *out, unsigned int outLen) {

    cx_blake2b_t ctx;
    cx_blake2b_init(&ctx, 512);
    cx_hash(&ctx.header, 0, SS58_BLAKE_PREFIX, SS58_BLAKE_PREFIX_LEN, NULL, 0);
    cx_hash(&ctx.header, CX_LAST, in, inLen, out, outLen);

    return 0;
}
#else

#include <hexutils.h>
#include "blake2.h"

char *crypto_testPubKey;

void crypto_extractPublicKey(const uint32_t path[HDPATH_LEN_DEFAULT], uint8_t *pubKey, uint16_t pubKeyLen) {
    ///////////////////////////////////////
    // THIS IS ONLY USED FOR TEST PURPOSES
    ///////////////////////////////////////

    // Empty version for non-Ledger devices
    MEMZERO(pubKey, pubKeyLen);

    if (crypto_testPubKey != NULL) {
        parseHexString(pubKey, pubKeyLen, crypto_testPubKey);
    } else {
        const char *str = "8d16d62802ca55326ec52bf76a8543b90e2aba5bcf6cd195c0d6fc1ef38fa1b3";
        parseHexString(pubKey, pubKeyLen, str);
    }
}

uint16_t crypto_sign(uint8_t *signature,
                     uint16_t signatureMaxlen,
                     const uint8_t *message,
                     uint16_t messageLen) {
    // Empty version for non-Ledger devices
    return 0;
}

int ss58hash(const unsigned char *in, unsigned int inLen,
             unsigned char *out, unsigned int outLen) {
    blake2b_state s;
    blake2b_init(&s, 64);
    blake2b_update(&s, SS58_BLAKE_PREFIX, SS58_BLAKE_PREFIX_LEN);
    blake2b_update(&s, in, inLen);
    blake2b_final(&s, out, outLen);
    return 0;
}

#endif

uint8_t crypto_SS58EncodePubkey(uint8_t *buffer, uint16_t buffer_len,
                                uint8_t addressType, const uint8_t *pubkey) {
    if (buffer == NULL || buffer_len < SS58_ADDRESS_MAX_LEN) {
        return 0;
    }
    if (pubkey == NULL) {
        return 0;
    }
    MEMZERO(buffer, buffer_len);

    uint8_t unencoded[35];
    uint8_t hash[64];

    unencoded[0] = addressType;                  // address type
    MEMCPY(unencoded + 1, pubkey, 32);           // account id
    ss58hash((uint8_t *) unencoded, 33, hash, 64);
    unencoded[33] = hash[0];
    unencoded[34] = hash[1];

    size_t outLen = buffer_len;
    encode_base58(unencoded, 35, buffer, &outLen);

    return outLen;
}

uint16_t crypto_fillAddress(uint8_t *buffer, uint16_t bufferLen) {
    if (bufferLen < PK_LEN_ED25519 + SS58_ADDRESS_MAX_LEN) {
        return 0;
    }
    MEMZERO(buffer, bufferLen);
    crypto_extractPublicKey(hdPath, buffer, bufferLen);

    size_t outLen = crypto_SS58EncodePubkey(buffer + PK_LEN_ED25519,
                                            bufferLen - PK_LEN_ED25519,
                                            PK_ADDRESS_TYPE, buffer);

    return PK_LEN_ED25519 + outLen;
}
