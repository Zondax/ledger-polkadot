/*******************************************************************************
*   (c) 2016 Ledger
*   (c) 2018 - 2023 Zondax AG
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
#include "swap.h"
#include "crypto.h"
#include "zxformat.h"
#include "substrate_dispatch.h"
#include "lib_standard_app/swap_lib_calls.h"


void handle_check_address(check_address_parameters_t* params) {
    if (params == NULL || params->address_to_check == NULL || params->address_parameters_length < 2) {
        return;
    }
    params->result = 0;
    uint8_t buffer[100] = {0};
    uint16_t replyLen = 0;

    // address parameters have the following structure
    // address kind (1 byte) | path length (1 byte) | bip44 path (4 * pathLength bytes)
    const key_kind_e add_kind = (key_kind_e) *params->address_parameters;

    zxerr_t err = crypto_fillAddress_standalone((uint8_t*) params->address_parameters + 2,
                                                (uint8_t) params->address_parameters_length - 2,
                                                add_kind,
                                                buffer,
                                                sizeof(buffer),
                                                &replyLen);
    if (err != zxerr_ok || replyLen <= PK_LEN_25519) {
        MEMZERO(buffer, sizeof(buffer));
        return;
    }

    const uint8_t *address = buffer + PK_LEN_25519;
    const uint8_t addressLen = replyLen - PK_LEN_25519;

    // Exchange guarantees that the input string is '\0' terminated
    uint8_t address_to_check_len = strlen(params->address_to_check);

    if (addressLen == address_to_check_len &&
        memcmp(address, params->address_to_check, addressLen) == 0) {
        params->result = 1;
    }
}
