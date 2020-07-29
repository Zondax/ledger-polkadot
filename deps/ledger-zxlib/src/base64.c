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
#include <zxmacros.h>
#include "base64.h"

#define BASE64_PADDING_CHAR '='

const char base64_charset[] = {
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
        'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
        'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
        'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '/',
};

uint16_t base64_encode(char *out, uint16_t outlen, const uint8_t *in, uint16_t inlen) {
    MEMZERO(out, outlen);

    // Check uppeer bound or bailout
    uint16_t minspace = inlen / 6;
    if (inlen % 6 != 0) minspace++;
    minspace++; // zero termination
    if (outlen < minspace) {
        return 0;
    }

    int8_t carry_count = 0;
    uint8_t carry_value = 0;
    uint16_t out_idx = 0;

    for (uint16_t i = 0; i < inlen; i++) {
        const uint8_t c = in[i];

        const uint8_t shift = (6 - carry_count);
        const uint8_t idx = (carry_value << shift) | (c >> (carry_count + 2));
        carry_value = c & (0xFFu >> shift);
        carry_count += 2;

        out[out_idx++] = base64_charset[idx];

        // Check if we have another complete byte ready
        if (carry_count == 6) {
            out[out_idx++] = base64_charset[carry_value];
            carry_value = 0;
            carry_count = 0;
        }
    }

    // If there is any left over add and pad
    if (carry_count > 0) {
        out[out_idx++] = base64_charset[carry_value << (6 - carry_count)];
        while (carry_count < 6) {
            out[out_idx++] = BASE64_PADDING_CHAR;
            carry_count += 2;
        }
    }

    return out_idx;
}
