/*******************************************************************************
 *  (c) 2018 - 2024  Zondax AG
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

#include "parser_impl.h"

const char *parser_getErrorDescription(parser_error_t err) {
    switch (err) {
        // General errors
        case parser_ok:
            return "No error";
        case parser_no_data:
            return "No more data";
        case parser_init_context_empty:
            return "Initialized empty context";
        case parser_display_idx_out_of_range:
            return "display_idx_out_of_range";
        case parser_display_page_out_of_range:
            return "display_page_out_of_range";
        case parser_wrong_metadata_digest:
            return "wrong metadata digest";
        // Coin specific
        case parser_spec_not_supported:
            return "Spec version not supported";
        case parser_tx_version_not_supported:
            return "Txn version not supported";
        case parser_not_allowed:
            return "Not allowed";
        case parser_not_supported:
            return "Not supported";
        case parser_unexpected_buffer_end:
            return "Unexpected buffer end";
        case parser_unexpected_value:
            return "Unexpected value";
        case parser_value_out_of_range:
            return "Value out of range";
        case parser_value_too_many_bytes:
            return "Value too many bytes";
        case parser_unexpected_module:
            return "Unexpected module index";
        case parser_unexpected_callIndex:
            return "Method not supported";
        case parser_unexpected_unparsed_bytes:
            return "Unexpected unparsed bytes";
        case parser_print_not_supported:
            return "Value cannot be printed";
        case parser_tx_nesting_not_supported:
            return "Call nesting not supported";
        case parser_tx_nesting_limit_reached:
            return "Max nested calls reached";
        case parser_tx_call_vec_too_large:
            return "Call vector exceeds limit";
        // Swap specific.
        case parser_swap_tx_wrong_method:
            return "Swap txn wrong method";
        case parser_swap_tx_wrong_method_args_num:
            return "Swap txn wrong method args count";
        case parser_swap_tx_wrong_dest_addr:
            return "Swap txn wrong destination addr";
        case parser_swap_tx_wrong_amount:
            return "Swap txn wrong amount";
        default:
            return "Unrecognized error code";
    }
}

GEN_DEF_READFIX_UNSIGNED(8)

GEN_DEF_READFIX_UNSIGNED(16)

GEN_DEF_READFIX_UNSIGNED(32)

GEN_DEF_READFIX_UNSIGNED(64)

parser_error_t readBool(parser_context_t *ctx, bool *val) {
    CHECK_INPUT(val);

    const uint8_t byte = *(ctx->buffer + ctx->offset);
    CTX_CHECK_AND_ADVANCE(ctx, 1)

    if (byte > 0x01U) {
        return parser_unexpected_value;
    }

    *val = (byte == 0x01U) ? true : false;
    return parser_ok;
}

parser_error_t readCompactInt(parser_context_t *ctx, CompactInt_t *val) {
    CHECK_INPUT(val);

    val->ptr = ctx->buffer + ctx->offset;
    const uint8_t mode = *val->ptr & 0x03U;  // get mode from two least significant bits

    uint64_t tmp = {0};
    switch (mode) {
        case 0:  // single byte
            val->len = 1;
            CTX_CHECK_AND_ADVANCE(ctx, val->len)
            _getValue(val, &tmp);
            break;
        case 1:  // 2-byte
            val->len = 2;
            CTX_CHECK_AND_ADVANCE(ctx, val->len)
            _getValue(val, &tmp);
            break;
        case 2:  // 4-byte
            val->len = 4;
            CTX_CHECK_AND_ADVANCE(ctx, val->len)
            _getValue(val, &tmp);
            break;
        case 3:  // bigint
            val->len = (*val->ptr >> 2U) + 4 + 1;
            CTX_CHECK_AND_ADVANCE(ctx, val->len)
            break;
        default:
            // this is actually impossible
            return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _getValue(const CompactInt_t *compact, uint64_t *value) {
    if (compact == NULL || value == NULL) {
        return parser_no_data;
    }
    *value = 0;

    switch (compact->len) {
        case 1:
            *value = (*compact->ptr) >> 2U;
            break;
        case 2:
            *value = (*compact->ptr) >> 2U;
            *value += *(compact->ptr + 1) << 6U;
            if (*value < 64U) {
                return parser_value_out_of_range;
            }
            break;
        case 4:
            *value = (*compact->ptr) >> 2U;
            *value += *(compact->ptr + 1) << 6U;
            *value += *(compact->ptr + 2) << (8U + 6U);
            *value += *(compact->ptr + 3) << (16U + 6U);
            if (*value < 16383U) {
                return parser_value_out_of_range;
            }
            break;
        default:
            return parser_value_out_of_range;
    }
    return parser_ok;
}

// inspiration from
// https://github.com/paritytech/polkadot-sdk/blob/0d3c67d96beda62b729e8328c5755358ac244246/substrate/primitives/runtime/src/generic/era.rs
parser_error_t _readEra(parser_context_t *ctx, pd_ExtrinsicEra_t *era) {
    CHECK_INPUT(ctx);

    era->isMortal = 0;
    era->period = 0;
    era->phase = 0;

    uint8_t first = 0;
    CHECK_ERROR(_readUInt8(ctx, &first));
    if (first == 0) {
        return parser_ok;
    }

    era->isMortal = 1;
    uint16_t encoded = (uint16_t)first;
    CHECK_ERROR(_readUInt8(ctx, &first));
    encoded += (uint16_t)first << 8;

    // we're sure it does not overflow u32 (at max is 2^16)
    era->period = (uint32_t)(2U << (encoded % (1U << 4U)));
    // at max is 2^4
    uint8_t quantize_factor = (uint8_t)(era->period >> 12U);
    quantize_factor = (quantize_factor == 0 ? 1 : quantize_factor);

    era->phase = (uint16_t)((encoded >> 4U) * quantize_factor);

    if (era->period >= 4 && era->phase < era->period) {
        return parser_ok;
    }

    return parser_unexpected_value;
}
