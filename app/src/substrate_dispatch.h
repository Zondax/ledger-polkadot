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
#include "stdbool.h"
#include "substrate_dispatch_V6.h"
#include "substrate_dispatch_V7.h"
#include <stddef.h>
#include <stdint.h>

#define GEN_GETCALL(CALL) _getpdCall_##CALL(ctx->tx_obj->transactionVersion)
#define GEN_DEC_GETCALL(CALL) uint32_t _getpdCall_##CALL(uint32_t txVersion)
#define GEN_DEF_GETCALL(CALL)                      \
    uint32_t _getpdCall_##CALL(uint32_t txVersion) \
    {                                              \
        switch (txVersion) {                       \
                                                   \
        case 7:                                    \
            return PD_CALL_##CALL##_V7;            \
                                                   \
        case 6:                                    \
            return PD_CALL_##CALL##_V6;            \
                                                   \
        default:                                   \
            return 0;                              \
        }                                          \
    }

parser_error_t _readMethod(parser_context_t* c, uint8_t moduleIdx, uint8_t callIdx, pd_Method_t* method);
uint8_t _getMethod_NumItems(uint32_t transactionVersion, uint8_t moduleIdx, uint8_t callIdx);
const char* _getMethod_ModuleName(uint32_t transactionVersion, uint8_t moduleIdx);
const char* _getMethod_Name(uint32_t transactionVersion, uint8_t moduleIdx, uint8_t callIdx);
const char* _getMethod_ItemName(uint32_t transactionVersion, uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx);

parser_error_t _getMethod_ItemValue(
    uint32_t transactionVersion,
    pd_Method_t* m, uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx,
    char* outValue, uint16_t outValueLen,
    uint8_t pageIdx, uint8_t* pageCount);

bool _getMethod_ItemIsExpert(uint32_t transactionVersion, uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx);
bool _getMethod_IsNestingSupported(uint32_t transactionVersion, uint8_t moduleIdx, uint8_t callIdx);

//Special getters
#if defined(APP_RESTRICTED)
parser_error_t parser_validate_staking_targets(parser_context_t* c);
GEN_DEC_GETCALL(STAKING);
GEN_DEC_GETCALL(STAKING_VALIDATE);
GEN_DEC_GETCALL(STAKING_SET_PAYEE);
GEN_DEC_GETCALL(STAKING_CHILL);
GEN_DEC_GETCALL(STAKING_NOMINATE);
GEN_DEC_GETCALL(SESSION);
GEN_DEC_GETCALL(SESSION_SET_KEYS);
GEN_DEC_GETCALL(SESSION_PURGE_KEYS);
#endif

#ifdef __cplusplus
}
#endif
