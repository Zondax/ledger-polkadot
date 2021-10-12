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
#include "zxformat.h"
#include <string.h>
#include <zxerror.h>
#include "utf8.h"

size_t asciify(char *utf8_in_ascii_out) {
    return asciify_ext(utf8_in_ascii_out, utf8_in_ascii_out);
}

size_t asciify_ext(const char *utf8_in, char *ascii_only_out) {
    void *p = (void *) utf8_in;
    char *q = ascii_only_out;

    // utf8valid returns zero on success
    while (*((char *) p) && utf8valid(p) == 0) {
        utf8_int32_t tmp_codepoint = 0;
        p = utf8codepoint(p, &tmp_codepoint);
        *q = (char) ((tmp_codepoint >= 32 && tmp_codepoint <= (int32_t) 0x7F) ? tmp_codepoint : '.');
        q++;
    }

    // Terminate string
    *q = 0;
    return q - ascii_only_out;
}

uint8_t intstr_to_fpstr_inplace(char *number, size_t number_max_size, uint8_t decimalPlaces) {
    uint16_t numChars = strnlen(number, number_max_size);
    MEMZERO(number + numChars, number_max_size - numChars);

    if (number_max_size < 1) {
        // No space to do anything
        return 0;
    }

    if (number_max_size <= numChars) {
        // No space to do anything
        return 0;
    }

    if (numChars == 0) {
        // Empty number, make a zero
        snprintf(number, number_max_size, "0");
        numChars = 1;
    }

    // Check all are numbers
    uint16_t firstDigit = numChars;
    for (int i = 0; i < numChars; i++) {
        if (number[i] < '0' || number[i] > '9') {
            snprintf(number, number_max_size, "ERR");
            return 0;
        }
        if (number[i] != '0' && firstDigit > i) {
            firstDigit = i;
        }
    }

    // Trim any incorrect leading zeros
    if (firstDigit == numChars) {
        snprintf(number, number_max_size, "0");
        numChars = 1;
    } else {
        // Trim leading zeros
        MEMCPY(number, number + firstDigit, numChars - firstDigit);
        MEMZERO(number + numChars - firstDigit, firstDigit);
    }

    // If there are no decimal places return
    if (decimalPlaces == 0) {
        return numChars;
    }

    // Now insert decimal point

//        0123456789012     <-decimal places
//        abcd              < numChars = 4
//                 abcd     < shift
//        000000000abcd     < fill
//        0.00000000abcd    < add decimal point

    if (numChars < decimalPlaces + 1) {
        // Move to end
        const uint16_t padSize = decimalPlaces - numChars + 1;
        MEMMOVE(number + padSize, number, numChars);
        MEMSET(number, '0', padSize);
        numChars = strlen(number);
    }

    // add decimal point
    const uint16_t pointPosition = numChars - decimalPlaces;
    MEMMOVE(number + pointPosition + 1, number + pointPosition, decimalPlaces);  // shift content
    number[pointPosition] = '.';

    numChars = strlen(number);
    return numChars;
}

size_t z_strlen(const char *buffer, size_t maxSize) {
    if (buffer == NULL) return 0;
    const size_t tmp = strlen(buffer);
    return tmp < maxSize ? tmp : maxSize;
}

zxerr_t z_str3join(char *buffer, size_t bufferSize, const char *prefix, const char *suffix) {
    size_t messageSize = z_strlen(buffer, bufferSize);
    const size_t prefixSize = z_strlen(prefix, bufferSize);
    const size_t suffixSize = z_strlen(suffix, bufferSize);

    size_t requiredSize = 1 /* termination */ + messageSize + prefixSize + suffixSize;

    if (bufferSize < requiredSize) {
        snprintf(buffer, bufferSize, "ERR???");
        return zxerr_buffer_too_small;
    }

    if (suffixSize > 0) {
        memmove(buffer + messageSize, suffix, suffixSize);
        buffer[messageSize + suffixSize] = 0;
    }

    // shift and add prefix
    if (prefixSize > 0) {
        memmove(buffer + prefixSize, buffer, messageSize + suffixSize + 1);
        memmove(buffer, prefix, prefixSize);
    }

    return zxerr_ok;
}
