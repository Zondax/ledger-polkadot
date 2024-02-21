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

swap_globals_t G_swap_state;

// Save the BSS address where we will write the return value when finished
static uint8_t* G_swap_sign_return_value_address;

////////////////////////////////////////////////////////////////

bool copy_transaction_parameters(create_transaction_parameters_t* sign_transaction_params) {
    if (sign_transaction_params == NULL) {
        return false;
    }

    // First copy parameters to stack, and then to global data.
    // We need this "trick" as the input data position can overlap with globals
    char destination_address[65] = {0};
    uint8_t amount[16] = {0};
    uint8_t amount_length = {0};
    uint8_t fees[8] = {0};

    strncpy(destination_address,
            sign_transaction_params->destination_address,
            sizeof(destination_address) - 1);

    if ((destination_address[sizeof(destination_address) - 1] != '\0') ||
        (sign_transaction_params->amount_length > 16) ||
        (sign_transaction_params->fee_amount_length > 8)) {
        return false;
    }

    // store amount as big endian in 16 bytes, so the passed data should be alligned to right
    // input {0xEE, 0x00, 0xFF} should be stored like {0x00, 0x00, 0x00, 0x00, 0x00, 0xEE, 0x00, 0xFF}
    memcpy(amount + 16 - sign_transaction_params->amount_length,
           sign_transaction_params->amount,
           sign_transaction_params->amount_length);

    memcpy(fees + 8 - sign_transaction_params->fee_amount_length,
           sign_transaction_params->fee_amount,
           sign_transaction_params->fee_amount_length);

    amount_length = sign_transaction_params->amount_length;

    // Full reset the global variables
    os_explicit_zero_BSS_segment();

    // Keep the address at which we'll reply the signing status
    G_swap_sign_return_value_address = &sign_transaction_params->result;

    // Commit the values read from exchange to the clean global space
    G_swap_state.amount_length = amount_length;
    memcpy(G_swap_state.amount,amount,sizeof(amount));
    memcpy(G_swap_state.destination_address,
           destination_address,
           sizeof(G_swap_state.destination_address));
    readU64BE(fees, &G_swap_state.fees);

    return true;
}

parser_error_t check_swap_conditions(const parser_context_t *ctx) {
    parser_error_t err = parser_unexpected_error;
    if (ctx == NULL) {
        return err;
    }
    // Check method.
    const char * valid_tx_method = "Balances Transfer allow death";
    char tmp_str[80] = {0};
    snprintf(tmp_str, sizeof(tmp_str), "%s %s", _getMethod_ModuleName(ctx->tx_obj->transactionVersion,
                                                                    ctx->tx_obj->callIndex.moduleIdx),
                                                _getMethod_Name(ctx->tx_obj->transactionVersion,
                                                                ctx->tx_obj->callIndex.moduleIdx,
                                                                ctx->tx_obj->callIndex.idx));

    if (strnlen(tmp_str, sizeof(tmp_str)) != strlen(valid_tx_method) ||
        strncmp(tmp_str, &valid_tx_method[0], strlen(valid_tx_method)) != 0) {
         ZEMU_LOGF(200, "Wrong swap tx method (%s, should be : %s).\n", tmp_str, valid_tx_method);
         return parser_swap_tx_wrong_method;
    }

    // Check transaction method arguments number. Balance transfer Should be 2 (for tx v18).
    if (_getMethod_NumItems(ctx->tx_obj->transactionVersion,
                           ctx->tx_obj->callIndex.moduleIdx,
                           ctx->tx_obj->callIndex.idx) != 2) {
        zemu_log("Wrong swap tx method arguments count.\n");
        return parser_swap_tx_wrong_method_args_num;
    }

    // Check destination address.
    MEMZERO(tmp_str,sizeof(tmp_str));
    uint8_t pageCount = 0;
    err = _getMethod_ItemValue(ctx->tx_obj->transactionVersion,
                            &ctx->tx_obj->method,
                            ctx->tx_obj->callIndex.moduleIdx, ctx->tx_obj->callIndex.idx, 0,
                            tmp_str, sizeof(tmp_str),
                            0, &pageCount);

    if (err != parser_ok) {
        zemu_log("Could not parse swap tx destination address.\n");
        return err;
    }

    if (strncmp(tmp_str, &(G_swap_state.destination_address[0]), sizeof(G_swap_state.destination_address)) != 0) {
         ZEMU_LOGF(200, "Wrong swap tx destination address ('%s', should be : '%s').\n", tmp_str, G_swap_state.destination_address);
         return parser_swap_tx_wrong_dest_addr;
    }

    // Check amount.
    MEMZERO(tmp_str, sizeof(tmp_str));
    err = _getMethod_ItemValue(ctx->tx_obj->transactionVersion,
                            &ctx->tx_obj->method,
                            ctx->tx_obj->callIndex.moduleIdx, ctx->tx_obj->callIndex.idx, 1,
                            tmp_str, sizeof(tmp_str),
                            0, &pageCount);

    if(err != parser_ok)
    {
        zemu_log("Could not parse swap tx amount.\n");
        return err;
    }

    char tmp_amount[100] = {0};
    const zxerr_t zxerr = bytesAmountToStringBalance(G_swap_state.amount, sizeof(G_swap_state.amount), tmp_amount, sizeof(tmp_amount));

    const size_t strLen = strlen(tmp_str);
    const size_t amountLen = strlen(tmp_amount);
    if (zxerr != zxerr_ok || strLen != amountLen || strncmp(tmp_str, tmp_amount, strLen)) {
        ZEMU_LOGF(200, "Wrong swap tx amount (%s, should be : %s).\n", tmp_str, tmp_amount);
        return parser_swap_tx_wrong_amount;
    }

    zemu_log("Swap parameters verified by current tx\n");
    return err;
}

void __attribute__((noreturn)) finalize_exchange_sign_transaction(bool is_success) {
    *G_swap_sign_return_value_address = is_success;
    os_lib_end();
}
