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
#include "bignum.h"
#include "crypto.h"
#include "lib_standard_app/swap_lib_calls.h"
#include "parser.h"
#include "swap.h"
#include "swap_utils.h"
#include "zxformat.h"

#define SWAP_EXPECTED_ITEMS 4u
#define MAX_ADDRESS_CHAR_LENGTH 64u
#define MAX_AMOUNT_LENGTH 16u
#define MAX_FEES_LENGTH 8u

swap_globals_t G_swap_state;

// Save the BSS address where we will write the return value when finished
static uint8_t *G_swap_sign_return_value_address;

////////////////////////////////////////////////////////////////

bool copy_transaction_parameters(create_transaction_parameters_t *sign_transaction_params) {
    if (sign_transaction_params == NULL) {
        return false;
    }

    // First copy parameters to stack, and then to global data.
    // We need this "trick" as the input data position can overlap with globals
    char destination_address[MAX_ADDRESS_CHAR_LENGTH + 1] = {0};
    uint8_t amount[MAX_AMOUNT_LENGTH] = {0};
    uint8_t amount_length = {0};
    uint8_t fees[MAX_FEES_LENGTH] = {0};

    strncpy(destination_address, sign_transaction_params->destination_address, sizeof(destination_address) - 1);

    if ((destination_address[sizeof(destination_address) - 1] != '\0') || (sign_transaction_params->amount_length > MAX_AMOUNT_LENGTH) ||
        (sign_transaction_params->fee_amount_length > MAX_FEES_LENGTH)) {
        return false;
    }

    // store amount as big endian in 16 bytes, so the passed data should be alligned to right
    // input {0xEE, 0x00, 0xFF} should be stored like {0x00, 0x00, 0x00, 0x00, 0x00, 0xEE, 0x00, 0xFF}
    memcpy(amount + MAX_AMOUNT_LENGTH - sign_transaction_params->amount_length, sign_transaction_params->amount,
           sign_transaction_params->amount_length);

    memcpy(fees + MAX_FEES_LENGTH - sign_transaction_params->fee_amount_length, sign_transaction_params->fee_amount,
           sign_transaction_params->fee_amount_length);

    amount_length = sign_transaction_params->amount_length;

    // Full reset the global variables
    os_explicit_zero_BSS_segment();

    // Keep the address at which we'll reply the signing status
    G_swap_sign_return_value_address = &sign_transaction_params->result;

    // Commit the values read from exchange to the clean global space
    G_swap_state.amount_length = amount_length;
    memcpy(G_swap_state.amount, amount, sizeof(amount));
    memcpy(G_swap_state.destination_address, destination_address, sizeof(G_swap_state.destination_address));
    readU64BE(fees, &G_swap_state.fees);

    return true;
}

// Ensure the received transaction matches what was validated in the Exchange app UI
parser_error_t check_swap_conditions(parser_tx_t *txObj) {
    parser_error_t err = parser_unexpected_error;
    if (txObj == NULL) {
        return err;
    }
    // Check transaction method arguments number. Balance transfer Should be 4 (for tx v26).
    // [chainID | dest(address type) |  dest(address) | value(amount)]
    if (txObj->blob.totalMethodItems != SWAP_EXPECTED_ITEMS) {
        ZEMU_LOGF(100, "Wrong swap tx method arguments count %d.\n", txObj->blob.totalMethodItems);
        return parser_swap_tx_wrong_method_args_num;
    }

    if (txObj->blob.tipItems != 0) {
        ZEMU_LOGF(100, "Refusing tipItems, expected 0, received %d.\n", txObj->blob.tipItems);
        return parser_swap_tx_wrong_method_args_num;
    }

    // Check network.
    const char *valid_network = "polkadot";
    char tmpKey[20] = {0};
    char tmpValue[65] = {0};

    uint8_t pageCount = 0;
    ui_field_t uiFields = {.displayIdx = 0,
                           .outKey = tmpKey,
                           .outKeyLen = sizeof(tmpKey),
                           .outVal = tmpValue,
                           .outValLen = sizeof(tmpValue),
                           .pageIdx = 0,
                           .pageCount = &pageCount};

    CHECK_ERROR(parser_getItem(txObj, &uiFields));
    if (strncmp(valid_network, tmpValue, strlen(valid_network) + 1) != 0) {
        ZEMU_LOGF(200, "Swap not enabled on %s network.\n", tmpValue);
        return parser_swap_tx_wrong_method;
    }

    // Check method.
    uiFields.displayIdx = 1;
    MEMZERO(tmpKey, sizeof(tmpKey));
    MEMZERO(tmpValue, sizeof(tmpValue));
    const char *valid_tx_pallet = "Balances";
    const char *valid_tx_call = "transfer_allow_death";

    CHECK_ERROR(parser_getItem(txObj, &uiFields));
    if (strncmp(valid_tx_pallet, tmpKey, strlen(valid_tx_pallet) + 1) != 0 ||
        strncmp(valid_tx_call, tmpValue, strlen(valid_tx_call) + 1) != 0) {
        ZEMU_LOGF(200, "Wrong swap tx method (%s %s, should be : %s %s).\n", tmpKey, tmpValue, valid_tx_pallet,
                  valid_tx_call);
        return parser_swap_tx_wrong_method;
    }

    // Check destination id
    uiFields.displayIdx = 2;
    MEMZERO(tmpKey, sizeof(tmpKey));
    MEMZERO(tmpValue, sizeof(tmpValue));
    const char *valid_field = "dest";
    CHECK_ERROR(parser_getItem(txObj, &uiFields));
    if (strncmp(valid_field, tmpKey, strlen(valid_field) + 1) != 0) {
        ZEMU_LOGF(200, "Wrong field (%s, should be : %s).\n", tmpKey, valid_field);
        return parser_swap_tx_wrong_method;
    }

    // // Check destination address.
    uiFields.displayIdx = 3;
    MEMZERO(tmpKey, sizeof(tmpKey));
    MEMZERO(tmpValue, sizeof(tmpValue));
    if (parser_getItem(txObj, &uiFields) != parser_ok) {
        ZEMU_LOGF(100, "Could not parse swap tx destination address.\n");
        return parser_swap_tx_wrong_dest_addr;
    }

    if (strncmp(tmpValue, G_swap_state.destination_address, sizeof(G_swap_state.destination_address)) != 0) {
        ZEMU_LOGF(200, "Wrong swap tx destination address ('%s', should be : '%s').\n", tmpValue,
                  G_swap_state.destination_address);
        return parser_swap_tx_wrong_dest_addr;
    }

    // Check amount.
    uiFields.displayIdx = 4;
    MEMZERO(tmpKey, sizeof(tmpKey));
    MEMZERO(tmpValue, sizeof(tmpValue));
    if (parser_getItem(txObj, &uiFields) != parser_ok) {
        ZEMU_LOGF(100, "Could not parse swap tx amount.\n");
        return parser_swap_tx_wrong_amount;
    }
    char tmpAmount[100] = {0};
    const zxerr_t zxerr =
        bytesAmountToStringBalance(G_swap_state.amount, sizeof(G_swap_state.amount), tmpAmount, sizeof(tmpAmount));

    const size_t strLen = strlen(tmpValue);
    const size_t amountLen = strlen(tmpAmount);
    if (zxerr != zxerr_ok || strLen != amountLen || strncmp(tmpValue, tmpAmount, strLen) != 0) {
        ZEMU_LOGF(200, "Wrong swap tx amount (%s, should be : %s).\n", tmpValue, tmpAmount);
        return parser_swap_tx_wrong_amount;
    }

    ZEMU_LOGF(50, "Swap parameters verified by current tx\n");
    return parser_ok;
}

void __attribute__((noreturn)) finalize_exchange_sign_transaction(bool is_success) {
    *G_swap_sign_return_value_address = is_success;
    os_lib_end();
}
