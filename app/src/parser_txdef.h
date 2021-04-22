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

#include <stdint.h>
#include <stddef.h>
#include "substrate_methods.h"

#ifdef TARGET_NANOX
#define MAX_CALL_NESTING_SIZE 6
#define MAX_CALL_VEC_SIZE 6
#else
#define MAX_CALL_NESTING_SIZE 2
#define MAX_CALL_VEC_SIZE 5
#endif

typedef struct {
    pd_CallIndex_t   callIndex;
    pd_Method_t method;

    pd_ExtrinsicEra_t era;
    pd_CompactIndex_t nonce;
    pd_CompactBalance_t tip;
    uint32_t specVersion;
    uint32_t transactionVersion;

    pd_Hash_t genesisHash;
    pd_Hash_t blockHash;

    pd_NestCallIdx_t nestCallIdx;
} parser_tx_t;

#ifdef __cplusplus
}
#endif
