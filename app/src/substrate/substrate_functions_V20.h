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
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "parser_common.h"
#include "substrate_methods_V20.h"
#include "substrate_types_V20.h"
#include <stddef.h>
#include <stdint.h>

// Versioned types functions for tx version V20

parser_error_t _readBoxVersionedMultiAssets_V20(parser_context_t* c, pd_BoxVersionedMultiAssets_V20_t* v);
parser_error_t _readBoxVersionedMultiLocation_V20(parser_context_t* c, pd_BoxVersionedMultiLocation_V20_t* v);
parser_error_t _readWeightLimit_V20(parser_context_t* c, pd_WeightLimit_V20_t* v);

parser_error_t _toStringBoxVersionedMultiAssets_V20(
    const pd_BoxVersionedMultiAssets_V20_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxVersionedMultiLocation_V20(
    const pd_BoxVersionedMultiLocation_V20_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringWeightLimit_V20(
    const pd_WeightLimit_V20_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

#ifdef __cplusplus
}
#endif
