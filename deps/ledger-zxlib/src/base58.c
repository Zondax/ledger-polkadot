/*******************************************************************************
*   Adapted from Ledger App - Bitcoin Wallet
*   (c) 2019 Zondax GmbH
*
*   Ledger App - Bitcoin Wallet
*   (c) 2016-2019 Ledger
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

#include "base58.h"
#include "zxmacros.h"

#define MAX_DEC_INPUT_SIZE 164
#define MAX_ENC_INPUT_SIZE 120

unsigned char const BASE58TABLE[] = {
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
        0xff, 0x0, 0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8, 0xff, 0xff,
        0xff, 0xff, 0xff, 0xff, 0xff, 0x9, 0xa, 0xb, 0xc, 0xd, 0xe, 0xf,
        0x10, 0xff, 0x11, 0x12, 0x13, 0x14, 0x15, 0xff, 0x16, 0x17, 0x18, 0x19,
        0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f, 0x20, 0xff, 0xff, 0xff, 0xff, 0xff,
        0xff, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2a, 0x2b,
        0xff, 0x2c, 0x2d, 0x2e, 0x2f, 0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36,
        0x37, 0x38, 0x39, 0xff, 0xff, 0xff, 0xff, 0xff};

unsigned char const BASE58ALPHABET[] = {
        '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F',
        'G', 'H', 'J', 'K', 'L', 'M', 'N', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W',
        'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'm',
        'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int decode_base58(const char *in, size_t length,
                  unsigned char *out, size_t *outlen) {
    unsigned char tmp[MAX_DEC_INPUT_SIZE];
    unsigned char buffer[MAX_DEC_INPUT_SIZE] = {0};
    unsigned char i;
    unsigned char j;
    unsigned char startAt;
    unsigned char zeroCount = 0;
    if (length > MAX_DEC_INPUT_SIZE) {
        return -1;
    }
    MEMMOVE(tmp, in, length);
    for (i = 0; i < length; i++) {
        if (in[i] >= sizeof(BASE58TABLE)) {
            return -1;
        }
        tmp[i] = BASE58TABLE[(int) in[i]];
        if (tmp[i] == 0xff) {
            return -1;
        }
    }
    while ((zeroCount < length) && (tmp[zeroCount] == 0)) {
        ++zeroCount;
    }
    j = length;
    startAt = zeroCount;
    while (startAt < length) {
        unsigned short remainder = 0;
        unsigned char divLoop;
        for (divLoop = startAt; divLoop < length; divLoop++) {
            unsigned short digit256 = (unsigned short) (tmp[divLoop] & 0xff);
            unsigned short tmpDiv = remainder * 58 + digit256;
            tmp[divLoop] = (unsigned char) (tmpDiv / 256);
            remainder = (tmpDiv % 256);
        }
        if (tmp[startAt] == 0) {
            ++startAt;
        }
        buffer[--j] = (unsigned char) remainder;
    }
    while ((j < length) && (buffer[j] == 0)) {
        ++j;
    }
    length = length - (j - zeroCount);
    if (*outlen < length) {
        return -1;
    }

    MEMMOVE(out, buffer + j - zeroCount, length);
    *outlen = length;
    return 0;
}

int encode_base58(const unsigned char *in, size_t length,
                  unsigned char *out, size_t *outlen) {
    unsigned char buffer[MAX_ENC_INPUT_SIZE * 138 / 100 + 1] = {0};
    size_t i, j;
    size_t startAt, stopAt;
    size_t zeroCount = 0;
    size_t outputSize;

    if (length > MAX_ENC_INPUT_SIZE) {
        return -1;
    }

    while ((zeroCount < length) && (in[zeroCount] == 0)) {
        ++zeroCount;
    }

    outputSize = (length - zeroCount) * 138 / 100 + 1;
    stopAt = outputSize - 1;
    for (startAt = zeroCount; startAt < length; startAt++) {
        int carry = in[startAt];
        for (j = outputSize - 1; (int) j >= 0; j--) {
            carry += 256 * buffer[j];
            buffer[j] = carry % 58;
            carry /= 58;

            if (j <= stopAt - 1 && carry == 0) {
                break;
            }
        }
        stopAt = j;
    }

    j = 0;
    while (j < outputSize && buffer[j] == 0) {
        j += 1;
    }

    if (*outlen < zeroCount + outputSize - j) {
        *outlen = zeroCount + outputSize - j;
        return -1;
    }

    MEMSET(out, BASE58ALPHABET[0], zeroCount);

    i = zeroCount;
    while (j < outputSize) {
        out[i++] = BASE58ALPHABET[buffer[j++]];
    }
    *outlen = i;
    return 0;
}

char encode_base58_clip(const unsigned char v) {
    return BASE58ALPHABET[v % 58];
}
