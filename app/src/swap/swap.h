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
#pragma once

#include "stdbool.h"
#include "stdint.h"
#include "zxerror.h"
#include "parser_common.h"
#include "lib_standard_app/swap_lib_calls.h"

typedef struct {
    uint8_t amount[16];
    uint8_t amount_length;
    uint64_t fees;
    char destination_address[65];
    /* Is swap mode */
    uint8_t called_from_swap;
    uint8_t should_exit;
} swap_globals_t;

extern swap_globals_t G_swap_state;

// Handler for swap features
parser_error_t check_swap_conditions(const parser_context_t *ctx);
void handle_check_address(check_address_parameters_t* params);
void handle_get_printable_amount(get_printable_amount_parameters_t* params);
bool copy_transaction_parameters(create_transaction_parameters_t* sign_transaction_params);
void __attribute__((noreturn)) finalize_exchange_sign_transaction(bool is_success);

// Helper functions for swap handlers
zxerr_t bytesAmountToStringBalance(uint8_t *amount, uint8_t amount_len, char *out, uint8_t out_len);
zxerr_t readU64BE(uint8_t* input, uint64_t *output);
zxerr_t readU32BE(uint8_t* input, uint32_t *output);
