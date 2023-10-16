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
#include "bignum.h"
#include "zxformat.h"
#include "substrate_dispatch.h"
#include "lib_standard_app/swap_lib_calls.h"

void handle_get_printable_amount( get_printable_amount_parameters_t* params) {
    if (params == NULL) {
        return;
    }
    uint8_t amount[16];

    MEMZERO(amount, sizeof(amount));
    MEMZERO(params->printable_amount, sizeof(params->printable_amount));

    if (params->amount_length > 16) {
        return;
    }

    memcpy(amount + 16 - params->amount_length, params->amount, params->amount_length);

    char tmp_amount[100] = {0};
    const zxerr_t zxerr = bytesAmountToStringBalance(amount, sizeof(amount), tmp_amount, sizeof(tmp_amount));

    if (zxerr != zxerr_ok || strnlen(tmp_amount, sizeof(tmp_amount)) > sizeof(params->printable_amount)) {
        return;
    }
    strncpy(params->printable_amount, tmp_amount, sizeof(params->printable_amount) - 1);
}
