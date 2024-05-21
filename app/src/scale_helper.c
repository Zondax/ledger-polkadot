/*******************************************************************************
 *   (c) 2018 - 2024 Zondax AG
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
#include "parser_common.h"
#include "parser_impl.h"
#include "substrate_types.h"

parser_error_t readBytes(parser_context_t *ctx, Bytes_t *bytes) {
    CHECK_INPUT(bytes);

    CompactInt_t clen = {0};
    CHECK_ERROR(readCompactInt(ctx, &clen));
    CHECK_ERROR(_getValue(&clen, &bytes->len));

    bytes->ptr = ctx->buffer + ctx->offset;
    CTX_CHECK_AND_ADVANCE(ctx, bytes->len);

    return parser_ok;
}

parser_error_t readOptBytes(parser_context_t *ctx, OptBytes_t *optBytes) {
    CHECK_INPUT(optBytes);

    uint8_t hasBytes = 0;
    CHECK_ERROR(_readUInt8(ctx, &hasBytes));

    if (hasBytes > 0x01U) {
        return parser_value_out_of_range;
    }

    optBytes->hasBytes = (hasBytes == 0x01U) ? true : false;

    if (optBytes->hasBytes) {
        CompactInt_t clen = {0};
        CHECK_ERROR(readCompactInt(ctx, &clen));
        CHECK_ERROR(_getValue(&clen, &optBytes->bytes.len));

        optBytes->bytes.ptr = ctx->buffer + ctx->offset;
        CTX_CHECK_AND_ADVANCE(ctx, optBytes->bytes.len);
    }

    return parser_ok;
}

parser_error_t readCompactU64(parser_context_t *ctx, uint64_t *value) {
    CHECK_INPUT(value);

    CompactInt_t tmp = {0};
    CHECK_ERROR(readCompactInt(ctx, &tmp));
    CHECK_ERROR(_getValue(&tmp, value));

    return parser_ok;
}

parser_error_t readCompactU32(parser_context_t *ctx, uint32_t *value) {
    CHECK_INPUT(value);

    CompactInt_t tmp = {0};
    uint64_t tmpValue = 0;
    CHECK_ERROR(readCompactInt(ctx, &tmp));
    CHECK_ERROR(_getValue(&tmp, &tmpValue));

    if (tmpValue > UINT32_MAX) {
        return parser_value_out_of_range;
    }

    *value = (uint32_t)tmpValue;

    return parser_ok;
}
