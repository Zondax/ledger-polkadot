/*******************************************************************************
*   (c) 2020 Zondax GmbH
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

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    no_error = 0,
    invalid_derPrefix,
    invalid_payloadLen,
    invalid_rmaker,
    invalid_rLen,
    invalid_smarker,
    invalid_sLen,
} err_convert_e;

err_convert_e convertDERtoRSV(const uint8_t *inSignatureDER,
                              unsigned int inInfo,
                              uint8_t *outR,
                              uint8_t *outS,
                              uint8_t *outV);

#ifdef __cplusplus
}
#endif
