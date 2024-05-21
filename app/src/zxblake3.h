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

#include "blake3.h"
#include "parser_common.h"
#include "zxerror.h"

#ifdef __cplusplus
extern "C" {
#endif

parser_error_t zxblake3_hash(const uint8_t *in, uint16_t inLen, uint8_t *out, uint16_t outLen);

parser_error_t zxblake3_hash_init();
parser_error_t zxblake3_hash_update(const uint8_t *in, uint16_t inLen);
parser_error_t zxblake3_hash_finalize(uint8_t *out, uint16_t outLen);

#ifdef __cplusplus
}
#endif
