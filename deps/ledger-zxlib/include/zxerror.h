/*******************************************************************************
*   (c) 2018 Zondax GmbH
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

#include "zxmacros.h"

#ifdef __cplusplus
extern "C" {
#endif

#define CHECK_ZXERR(CALL) { \
    zxerr_t err = CALL;  \
    if (err!=zxerr_ok) return err;}

typedef enum {
    zxerr_unknown = 0b00000000,
    zxerr_ok = 0b00000011,
    zxerr_no_data = 0b00000101,
    zxerr_buffer_too_small = 0b00000110,
    zxerr_out_of_bounds = 0b00001001,
    zxerr_encoding_failed = 0b00001010,
    zxerr_invalid_crypto_settings = 0b00001100,
    zxerr_ledger_api_error = 0b00001111,
} zxerr_t;

__Z_INLINE uint8_t getErrorMessage(char *buffer, uint16_t bufferLen, zxerr_t err) {
    MEMZERO(buffer, bufferLen);

    switch (err) {
        case zxerr_unknown:
            snprintf(buffer, bufferLen, "zxerr_unknown");
            break;
        case zxerr_ok:
            snprintf(buffer, bufferLen, "zxerr_ok");
            break;
        case zxerr_no_data:
            snprintf(buffer, bufferLen, "zxerr_no_data");
            break;
        case zxerr_out_of_bounds:
            snprintf(buffer, bufferLen, "zxerr_out_of_bounds");
            break;
        case zxerr_encoding_failed:
            snprintf(buffer, bufferLen, "zxerr_encoding_failed");
            break;
        case zxerr_invalid_crypto_settings:
            snprintf(buffer, bufferLen, "zxerr_invalid_crypto_settings");
            break;
        case zxerr_ledger_api_error:
            snprintf(buffer, bufferLen, "zxerr_ledger_api_error");
            break;
        default:
            snprintf(buffer, bufferLen, "err N/A");
    }

    return strlen(buffer);
}

//0b00000000
//0b00000011
//0b00000101
//0b00000110
//0b00001001
//0b00001010
//0b00001100
//0b00001111
//0b00010001
//0b00010010
//0b00010100
//0b00010111
//0b00011000
//0b00011011
//0b00011101
//0b00011110
//0b00100001
//0b00100010
//0b00100100
//0b00100111
//0b00101000
//0b00101011
//0b00101101
//0b00101110
//0b00110000
//0b00110011
//0b00110101
//0b00110110
//0b00111001
//0b00111010
//0b00111100
//0b00111111

#ifdef __cplusplus
}
#endif
