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
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wextern-c-compat"
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>
#include <stdint.h>

#define GET_PD_CALL(CALL, VERSION) (PD_CALL_##CALL##_V##VERSION)

#include "substrate_methods_V5.h"
#include "substrate_methods_V6.h"
#include "substrate_types_V5.h"
#include "substrate_types_V6.h"

typedef union {
    pd_Method_V6_t V6;
    pd_Method_V5_t V5;
} pd_Method_t;

typedef union {
    pd_MethodNested_V6_t V6;
    pd_MethodNested_V5_t V5;
} pd_MethodNested_t;

#ifdef __cplusplus
}
#endif
