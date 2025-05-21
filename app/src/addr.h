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

#include <stdint.h>

#include "zxerror.h"
#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Address type
 * enum 1 was reserved for sr25519 which is not supported
 */
typedef enum {
    ed25519 = 0,
    secp256k1 = 2,
} scheme_type_e;

extern scheme_type_e scheme;

/// Return the number of items in the address view
zxerr_t addr_getNumItems(uint8_t *num_items);

/// Gets an specific item from the address view (including paging)
zxerr_t addr_getItem(int8_t displayIdx,
                     char *outKey,
                     uint16_t outKeyLen,
                     char *outValue,
                     uint16_t outValueLen,
                     uint8_t pageIdx,
                     uint8_t *pageCount);

#ifdef __cplusplus
}
#endif
