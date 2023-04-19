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

#include "substrate_types.h"
#include <stddef.h>
#include <stdint.h>

// Versioned types functions for tx version V20

typedef struct {
    uint8_t value;
    union {
        pd_VecMultiAssetV0_t vecMultiassetV0;
        pd_VecMultiAssetV1_t vecMultiassetV1;
    };
} pd_BoxVersionedMultiAssets_V20_t;

typedef struct {
    uint8_t value;
    union {
        pd_MultiLocationV0_t multilocationV0;
        pd_MultiLocationV1_t multilocationV1;
    };
} pd_BoxVersionedMultiLocation_V20_t;

typedef struct {
    uint8_t value;
    pd_Compactu64_t limited;
} pd_WeightLimit_V20_t;

#ifdef __cplusplus
}
#endif
