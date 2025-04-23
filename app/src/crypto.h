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

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <sigutils.h>
#include <stdbool.h>
#include <zxmacros.h>

#include "addr.h"
#include "coin.h"
#include "zxerror.h"

extern uint32_t hdPath[HDPATH_LEN_DEFAULT];

zxerr_t crypto_fillAddress(
    uint8_t *buffer, uint16_t bufferLen, uint16_t *addrResponseLen, uint16_t ss58prefix, const scheme_type_e address_scheme);

zxerr_t crypto_fillAddress_standalone(uint8_t *params,
                                      uint8_t paramsSize,
                                      uint8_t *buffer,
                                      uint16_t bufferLen,
                                      uint16_t *addrResponseLen,
                                      uint16_t ss58prefix);

zxerr_t crypto_sign_ed25519(uint8_t *signature, uint16_t signatureMaxlen, const uint8_t *message, uint16_t messageLen);

zxerr_t crypto_sign_secp256k1(
    uint8_t *output, uint16_t outputLen, const uint8_t *message, uint16_t messageLen, uint16_t *sigSize);

#ifdef __cplusplus
}
#endif
