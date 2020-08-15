/*******************************************************************************
*   (c) 2018 Zondax GmbH
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

#include "zxmacros.h"
#include <stdbool.h>
#include "zxerror.h"

#define ALLOW_LIST_SIZE                 128
// Length is limited to 63 because it must be zero terminated
#define ALLOW_LIST_ITEM_ADDRESS_SIZE    64

typedef struct {
    uint8_t address[ALLOW_LIST_ITEM_ADDRESS_SIZE];
} allowlist_item_t;

typedef struct {
    uint32_t nonce;
    uint32_t len;
    uint8_t signature[64];  // Ed25519
} allowlist_header_t;

typedef struct {
    allowlist_header_t header;
    allowlist_item_t items[ALLOW_LIST_SIZE];
} allowlist_t;

#ifdef __cplusplus
extern "C" {
#endif

bool allowlist_pubkey_is_set();

bool allowlist_pubkey_get(uint8_t *out, size_t outLen);

bool allowlist_pubkey_set(const uint8_t *in, size_t inLen);

bool allowlist_is_active();

void allowlist_hash(uint8_t *digest);

bool allowlist_item_validate(const char *address);

bool allowlist_list_validate(const uint8_t *new_list_buffer, size_t new_list_buffer_len);

bool allowlist_upgrade(const uint8_t *new_list_buffer, size_t new_list_buffer_len);

zxerr_t allowlist_getNumItems(uint8_t *num_items);

zxerr_t allowlist_getItem(int8_t displayIdx,
                          char *outKey, uint16_t outKeyLen,
                          char *outValue, uint16_t outValueLen,
                          uint8_t pageIdx, uint8_t *pageCount);

#ifdef __cplusplus
}
#endif
