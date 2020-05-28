/*******************************************************************************
*  (c) 2019 Zondax GmbH
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

#include <stdint.h>
#include <stddef.h>

#define HDPATH_LEN_DEFAULT   5

#define HDPATH_0_DEFAULT     (0x80000000 | 0x2c)
#define HDPATH_1_DEFAULT     (0x80000000 | 0x1b2)       // 434
#define HDPATH_2_DEFAULT     (0x80000000u | 0u)
#define HDPATH_3_DEFAULT     (0u)
#define HDPATH_4_DEFAULT     (0u)

#define PK_LEN_ED25519       32u

typedef enum {
    addr_ed22519     = 0,
    addr_sr25519     = 1
} address_kind_e;

#define VIEW_ADDRESS_OFFSET_ED25519         (PK_LEN_ED25519)
#define VIEW_ADDRESS_ITEM_COUNT             2
#define VIEW_ADDRESS_LAST_PAGE_DEFAULT      0

#define MENU_MAIN_APP_LINE1 "Kusama"
#define MENU_MAIN_APP_LINE2 "Web3"
#define APPVERSION_LINE1 "Kusama"
#define APPVERSION_LINE2 "v"APPVERSION

// Specific to Kusama
#define PK_ADDRESS_TYPE     02
#define SUPPORTED_SPEC_VERSION LEDGER_MINOR_VERSION

#define COIN_AMOUNT_DECIMAL_PLACES      12
#define CRYPTO_BLOB_SKIP_BYTES          0

#ifdef __cplusplus
}
#endif
