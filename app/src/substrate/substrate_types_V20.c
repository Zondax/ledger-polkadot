/*******************************************************************************
 *  (c) 2019 - 2023 Zondax AG
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
#include "coin.h"
#include "parser_impl.h"
#include "substrate_dispatch_V20.h"
#include "substrate_strings.h"

#include <stddef.h>
#include <stdint.h>
#include <zxformat.h>
#include <zxmacros.h>

parser_error_t _readBoxVersionedMultiAssets_V20(parser_context_t* c, pd_BoxVersionedMultiAssets_V20_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // V0
        CHECK_ERROR(_readVecMultiAssetV0(c, &v->vecMultiassetV0))
        break;
    case 1: // V1
        CHECK_ERROR(_readVecMultiAssetV1(c, &v->vecMultiassetV1))
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _readBoxVersionedMultiLocation_V20(parser_context_t* c, pd_BoxVersionedMultiLocation_V20_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // V0
        CHECK_ERROR(_readMultiLocationV0(c, &v->multilocationV0))
        break;
    case 1: // V1
        CHECK_ERROR(_readMultiLocationV1(c, &v->multilocationV1))
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _readWeightLimit_V20(parser_context_t* c, pd_WeightLimit_V20_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // Unlimited
        break;
    case 1: // Limited
        CHECK_ERROR(_readCompactu64(c, &v->limited))
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

///////////////////////////////////
///////////////////////////////////
///////////////////////////////////

parser_error_t _toStringBoxVersionedMultiAssets_V20(
    const pd_BoxVersionedMultiAssets_V20_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    switch (v->value) {
    case 0: // V0
        CHECK_ERROR(_toStringVecMultiAssetV0(&v->vecMultiassetV0, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 1: // V1
        CHECK_ERROR(_toStringVecMultiAssetV1(&v->vecMultiassetV1, outValue, outValueLen, pageIdx, pageCount))
        break;
    default:
        return parser_not_supported;
    }

    return parser_ok;
}

parser_error_t _toStringBoxVersionedMultiLocation_V20(
    const pd_BoxVersionedMultiLocation_V20_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    switch (v->value) {
    case 0: // V0
        CHECK_ERROR(_toStringMultiLocationV0(&v->multilocationV0, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 1: // V1
        CHECK_ERROR(_toStringMultiLocationV1(&v->multilocationV1, outValue, outValueLen, pageIdx, pageCount))
        break;
    default:
        return parser_not_supported;
    }

    return parser_ok;
}

parser_error_t _toStringWeightLimit_V20(
    const pd_WeightLimit_V20_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    switch (v->value) {
    case 0: // Unlimited
        *pageCount = 1;
        snprintf(outValue, outValueLen, "Unlimited");
        break;
    case 1: // Limited
        CHECK_ERROR(_toStringCompactu64(&v->limited, outValue, outValueLen, pageIdx, pageCount))
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}
