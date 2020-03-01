/*******************************************************************************
*   (c) 2019 ZondaX GmbH
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
#include <stddef.h>
#include "bech32.h"
#include "segwit_addr.h"
#include "bittools.h"

void bech32EncodeFromBytes(char *output,
                           const char *hrp,
                           const uint8_t *data,
                           size_t data_len) {
    output[0] = 0;
    if (data_len > 128) {
        return;
    }

    uint8_t tmp_data[128];
    size_t tmp_size = 0;

    convert_bits(tmp_data, &tmp_size, 5, data, data_len, 8, 0);
    bech32_encode(output, hrp, tmp_data, tmp_size);
}
