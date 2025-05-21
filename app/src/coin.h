/*******************************************************************************
 *  (c) 2018 - 2024 Zondax AG
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

/// Defines the current app CLA
#define CLA 0xF9

/// These are app specific INS
#define INS_SIGN_RAW 0x03

//////////////

#define HDPATH_LEN_DEFAULT            5
#define HDPATH_0_DEFAULT              (0x80000000 | 0x2c)
#define HDPATH_1_DEFAULT              (0x80000000 | 0x162)

#define SK_LEN_25519                  64u
#define SCALAR_LEN_ED25519            32u
#define SIG_PLUS_TYPE_LEN             65u

#define PK_LEN_25519                  32u
#define MAX_SIGN_SIZE                 256u
#define BLAKE2B_DIGEST_SIZE           32u

#define SECP256K1_PK_LEN_UNCOMPRESSED 65u
#define SECP256K1_PK_LEN              33u
#define SECP256K1_ADDRESS_LEN         20u

#ifdef MIGRATION_APP
#define MENU_MAIN_APP_LINE1 "DOT migration"
#define MENU_MAIN_APP_LINE2 "Ready"
#define APPVERSION_LINE1    "DOT migration"
#else
#define MENU_MAIN_APP_LINE1 "Polkadot"
#define MENU_MAIN_APP_LINE2 "Ready"
#define APPVERSION_LINE1    "Polkadot"
#endif
#define APPVERSION_LINE2 "v" APPVERSION

#ifdef __cplusplus
}
#endif
