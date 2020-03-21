/*******************************************************************************
*   (c) 2019 Zondax GmbH
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

#include <zxmacros.h>
#include <zxtypes.h>

bool_t bignumLittleEndian_bcdprint(char *outBuffer, uint16_t outBufferLen, const uint8_t *inBCD, uint16_t inBCDLen);
void bignumLittleEndian_to_bcd(uint8_t *bcdOut, uint16_t bcdOutLen, const uint8_t *binValue, uint16_t binValueLen);

bool_t bignumBigEndian_bcdprint(char *outBuffer, uint16_t outBufferLen, const uint8_t *bcdIn, uint16_t bcdInLen);
void bignumBigEndian_to_bcd(uint8_t *bcdOut, uint16_t bcdOutLen, const uint8_t *binValue, uint16_t binValueLen);


#ifdef __cplusplus
}
#endif
