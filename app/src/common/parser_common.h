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

#include "parser_txdef.h"
#include <stdint.h>
#include <stddef.h>

#define CHECK_PARSER_ERR(__CALL) { \
    parser_error_t __err = __CALL;  \
    CHECK_APP_CANARY()  \
    if (__err!=parser_ok) return __err;}

typedef enum {
    // Generic errors
    parser_ok = 0,
    parser_no_data,
    parser_init_context_empty,
    parser_display_idx_out_of_range,
    parser_display_page_out_of_range,
    parser_unexpected_error,
    // Coin specific
    parser_unexpected_address_type,
    parser_spec_not_supported,
    parser_tx_version_not_supported,
    parser_not_allowed,
    parser_not_supported,
    parser_unexpected_buffer_end,
    parser_unexpected_value,
    parser_value_out_of_range,
    parser_value_too_many_bytes,
    parser_unexpected_module,
    parser_unexpected_callIndex,
    parser_unexpected_unparsed_bytes,
    parser_print_not_supported,
    parser_tx_nesting_limit_reached,
    parser_tx_call_vec_too_large,
} parser_error_t;

typedef struct {
    const uint8_t *buffer;
    uint16_t bufferLen;
    uint16_t offset;
    parser_tx_t *tx_obj;
} parser_context_t;

#ifdef __cplusplus
}
#endif
