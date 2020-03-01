/*******************************************************************************
*   (c) 2019 ZondaX GmbH
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

#include <zxmacros.h>

#ifdef __cplusplus
extern "C" {
#endif

#define BIP44_LEN_DEFAULT 5u
#define ED25519_PK_LEN 32u
#define SS58_ADDRESS_MAX_LEN 60u

#define PK_LEN ED25519_PK_LEN

extern uint32_t bip44Path[BIP44_LEN_DEFAULT];

void crypto_extractPublicKey(const uint32_t path[BIP44_LEN_DEFAULT], uint8_t *pubKey, uint16_t pubKeyLen);

uint8_t crypto_SS58EncodePubkey(uint8_t *buffer, uint16_t buffer_len,
                                uint8_t addressType, const uint8_t *pubkey);

uint16_t crypto_fillAddress(uint8_t *buffer, uint16_t bufferLen);

uint16_t crypto_sign(uint8_t *signature,
                     uint16_t signatureMaxlen,
                     const uint8_t *message,
                     uint16_t messageLen);

#ifdef __cplusplus
}
#endif
