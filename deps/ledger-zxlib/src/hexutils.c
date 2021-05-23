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

#include <ctype.h>
#include <string.h>
#include "hexutils.h"

uint8_t hex2dec(char c, char *out) {
    c = (char) tolower((int) c);

    if (!isxdigit((int) c)) {
        return 1;
    }

    if (isdigit((int) c)) {
        *out = (char) (c - '0');
        return 0;
    }

    *out = (char) (c - 'a' + 10);
    return 0;
}

size_t parseHexString(uint8_t *out, uint16_t outLen, const char *input) {
    size_t len = strnlen(input, outLen * 2u + 1u);
    if ( (len / 2) > outLen) {
        return 0;
    }
    if (len % 2 == 1) {
        return 0;
    }

    for (size_t i = 0; i < len; i += 2) {
        char tmp1, tmp2;
        if (hex2dec(input[i], &tmp1))
            return 0;
        if (hex2dec(input[i + 1], &tmp2))
            return 0;

        out[i >> 1u] = (tmp1 << 4u) + tmp2;
    }

    return (len / 2);
}
