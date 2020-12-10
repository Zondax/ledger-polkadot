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

#include "parser_common.h"
#include "substrate_functions.h"
#include <stddef.h>
#include <stdint.h>

#define CHECK_ERROR(FUNC_CALL)          \
    {                                   \
        parser_error_t err = FUNC_CALL; \
        if (err != parser_ok)           \
            return err;                 \
    }

parser_error_t _readMethodBasic(parser_context_t* c, uint8_t moduleIdx, uint8_t callIdx, pd_MethodBasic_t* method);

parser_error_t _readMethod(parser_context_t* c, uint8_t moduleIdx, uint8_t callIdx, pd_Method_t* method);

const char* _getMethod_ModuleName(uint8_t moduleIdx);

const char* _getMethod_Name(uint8_t moduleIdx, uint8_t callIdx);

const char* _getMethod_ItemName(uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx);

uint8_t _getMethod_NumItems(uint8_t moduleIdx, uint8_t callIdx, pd_Method_t* method);

parser_error_t _getMethod_ItemValue(
    pd_Method_t* m, uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx,
    char* outValue, uint16_t outValueLen,
    uint8_t pageIdx, uint8_t* pageCount);

#ifdef __cplusplus
}
#endif
