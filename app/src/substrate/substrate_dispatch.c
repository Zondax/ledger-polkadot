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
#include "substrate_dispatch.h"
#include "parser_impl.h"

#include "zxmacros.h"
#include <stdint.h>

parser_error_t _readMethod(
    parser_context_t* c,
    uint8_t moduleIdx,
    uint8_t callIdx,
    pd_Method_t* method)
{
    switch (c->tx_obj->transactionVersion) {
    case 24:
        return _readMethod_V24(c, moduleIdx, callIdx, &method->V24);
    case 23:
        return _readMethod_V23(c, moduleIdx, callIdx, &method->V23);
    default:
        return parser_tx_version_not_supported;
    }
}

uint8_t _getMethod_NumItems(uint32_t transactionVersion, uint8_t moduleIdx, uint8_t callIdx)
{
    switch (transactionVersion) {
    case 24:
        return _getMethod_NumItems_V24(moduleIdx, callIdx);
    case 23:
        return _getMethod_NumItems_V23(moduleIdx, callIdx);
    default:
        return parser_tx_version_not_supported;
    }
}

const char* _getMethod_ModuleName(uint32_t transactionVersion, uint8_t moduleIdx)
{
    switch (transactionVersion) {
    case 24:
        return _getMethod_ModuleName_V24(moduleIdx);
    case 23:
        return _getMethod_ModuleName_V23(moduleIdx);
    default:
        return NULL;
    }
}

const char* _getMethod_Name(uint32_t transactionVersion, uint8_t moduleIdx, uint8_t callIdx)
{
    switch (transactionVersion) {
    case 24:
        return _getMethod_Name_V24(moduleIdx, callIdx);
    case 23:
        return _getMethod_Name_V23(moduleIdx, callIdx);
    default:
        return 0;
    }
}

const char* _getMethod_ItemName(uint32_t transactionVersion, uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx)
{
    switch (transactionVersion) {
    case 24:
        return _getMethod_ItemName_V24(moduleIdx, callIdx, itemIdx);
    case 23:
        return _getMethod_ItemName_V23(moduleIdx, callIdx, itemIdx);
    default:
        return NULL;
    }
}

parser_error_t _getMethod_ItemValue(uint32_t transactionVersion, pd_Method_t* m, uint8_t moduleIdx, uint8_t callIdx,
    uint8_t itemIdx, char* outValue, uint16_t outValueLen,
    uint8_t pageIdx, uint8_t* pageCount)
{
    switch (transactionVersion) {
    case 24:
        return _getMethod_ItemValue_V24(&m->V24, moduleIdx, callIdx, itemIdx, outValue,
            outValueLen, pageIdx, pageCount);
    case 23:
        return _getMethod_ItemValue_V23(&m->V23, moduleIdx, callIdx, itemIdx, outValue,
            outValueLen, pageIdx, pageCount);
    default:
        return parser_tx_version_not_supported;
    }
}

bool _getMethod_ItemIsExpert(uint32_t transactionVersion, uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx)
{
    switch (transactionVersion) {
    case 24:
        return _getMethod_ItemIsExpert_V24(moduleIdx, callIdx, itemIdx);
    case 23:
        return _getMethod_ItemIsExpert_V23(moduleIdx, callIdx, itemIdx);
    default:
        return false;
    }
}

bool _getMethod_IsNestingSupported(uint32_t transactionVersion, uint8_t moduleIdx, uint8_t callIdx)
{
    switch (transactionVersion) {
    case 24:
        return _getMethod_IsNestingSupported_V24(moduleIdx, callIdx);
    case 23:
        return _getMethod_IsNestingSupported_V23(moduleIdx, callIdx);
    default:
        return false;
    }
}
