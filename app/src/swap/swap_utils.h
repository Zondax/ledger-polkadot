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
#pragma once

#include "stdbool.h"
#include "stdint.h"
#include "zxerror.h"

// Helper functions for swap handlers
zxerr_t bytesAmountToStringBalance(uint8_t *amount, uint8_t amount_len, char *out, uint8_t out_len);
zxerr_t readU64BE(uint8_t *input, uint64_t *output);
zxerr_t readU32BE(uint8_t *input, uint32_t *output);
