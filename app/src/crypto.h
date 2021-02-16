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

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <zxmacros.h>
#include "coin.h"
#include <stdbool.h>
#include <sigutils.h>
#include "zxerror.h"

#ifdef SUPPORT_SR25519
// Flash
typedef struct {
    uint8_t sk[SK_LEN_25519];
    uint8_t pk[PK_LEN_25519];
    uint8_t signdata[MAX_SIGN_SIZE];
    uint8_t signature[SIG_PLUS_TYPE_LEN];
} sr25519_signdata_t;

extern uint16_t sr25519_signdataLen;

#if defined(TARGET_NANOS) || defined(TARGET_NANOX)
sr25519_signdata_t NV_CONST N_srdata_impl __attribute__ ((aligned(64)));
#define N_sr25519_signdata (*(NV_VOLATILE sr25519_signdata_t *)PIC(&N_srdata_impl))
#endif

zxerr_t zeroize_sr25519_signdata() {
    uint8_t dummysk[SK_LEN_25519];
    MEMZERO(dummysk, SK_LEN_25519);
    uint8_t dummypk[PK_LEN_25519];
    MEMZERO(dummypk, PK_LEN_25519);
    uint8_t dummysigndata[MAX_SIGN_SIZE];
    MEMZERO(dummysigndata, MAX_SIGN_SIZE);
    uint8_t dummysignature[SIG_PLUS_TYPE_LEN];
    MEMZERO(dummysignature, SIG_PLUS_TYPE_LEN);

    MEMCPY_NV((void *) &N_sr25519_signdata.sk, dummysk, SK_LEN_25519);
    MEMCPY_NV((void *) &N_sr25519_signdata.pk, dummypk, PK_LEN_25519);
    MEMCPY_NV((void *) &N_sr25519_signdata.signdata, dummysigndata, MAX_SIGN_SIZE);
    MEMCPY_NV((void *) &N_sr25519_signdata.signature, dummysignature, SIG_PLUS_TYPE_LEN);
    sr25519_signdataLen = 0;
    return zxerr_ok;
}

#else

zxerr_t zeroize_sr25519_signdata() {
    return zxerr_ok;
}

#endif

//#define SS58_BLAKE_PREFIX  (const unsigned char *) "SS58PRE"
//#define SS58_BLAKE_PREFIX_LEN 7
#define SS58_ADDRESS_MAX_LEN 60u

#define PREFIX_SIGNATURE_TYPE_ED25519  0
#define PREFIX_SIGNATURE_TYPE_SR25519  1
#define PREFIX_SIGNATURE_TYPE_EDCSA    2
#define MIN_BUFFER_LENGTH              235
#define START_BUFFER                   33

extern uint32_t hdPath[HDPATH_LEN_DEFAULT];

uint8_t crypto_SS58EncodePubkey(uint8_t *buffer, uint16_t buffer_len,
                                uint8_t addressType, const uint8_t *pubkey);

zxerr_t crypto_fillAddress(key_kind_e addressKind, uint8_t *buffer, uint16_t bufferLen, uint16_t *addrResponseLen);

zxerr_t crypto_sign_sr25519_prephase(uint8_t *buffer, uint16_t bufferLen, const uint8_t *message, uint16_t messageLen);

zxerr_t crypto_sign_sr25519(uint8_t *signature, uint16_t signatureMaxlen,
                            uint16_t *signatureLen);

zxerr_t crypto_sign_ed25519(uint8_t *signature, uint16_t signatureMaxlen,
                            const uint8_t *message, uint16_t messageLen,
                            uint16_t *signatureLen);

#ifdef __cplusplus
}
#endif
