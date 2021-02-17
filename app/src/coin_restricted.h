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
#include "coin_ss58.h"

#define HDPATH_2_STASH       (0x80000000u | 0u)
#define HDPATH_2_VALIDATOR   (0x80000000u | 1u)
#define HDPATH_3_DEFAULT     (0x80000000u)
#define HDPATH_4_DEFAULT     (0x80000000u)

#define MENU_MAIN_APP_LINE1                 "Polkadot | sec"
#define MENU_MAIN_APP_LINE2                 "Ledgeracio"
#define MENU_MAIN_APP_LINE2_SECRET          "??????????"
#define APPVERSION_LINE1                    "Polkadot | sec"
#define APPVERSION_LINE2                    "v" APPVERSION

#ifdef __cplusplus
}
#endif
