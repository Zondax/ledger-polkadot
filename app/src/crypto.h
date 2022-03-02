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

zxerr_t crypto_sign_ed25519(uint8_t *signature, uint16_t signatureMaxlen, const uint8_t *message, uint16_t messageLen);

#ifdef SUPPORT_SR25519
void zeroize_sr25519_signdata(void);

void copy_sr25519_signdata(uint8_t *buffer);

zxerr_t crypto_sign_sr25519(const uint8_t *message, size_t messageLen);
#endif

#ifdef __cplusplus
}
#endif
