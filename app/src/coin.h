/*******************************************************************************
*  (c) 2019 ZondaX GmbH
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

#define DECIMAL_PLACES      12              // Specific to Kusama
#define BIP44_0_DEFAULT                  (0x80000000 | 0x2c)
#define BIP44_1_DEFAULT                  (0x80000000 | 0x1b2)       // 434

#define PK_ADDRESS_TYPE     02

#define SUPPORTED_SPEC_VERSION LEDGER_MINOR_VERSION

#define MENU_MAIN_APP_LINE1 "Kusama"
#define MENU_MAIN_APP_LINE2 "Web3"

#define VIEW_ADDRESS_BUFFER_OFFSET    (PK_LEN)

#ifdef __cplusplus
}
#endif
