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
#include "zxtypes.h"
#include "bignum.h"

bool_t bignumLittleEndian_bcdprint(char *outBuffer, uint16_t outBufferLen,
                                   const uint8_t *inBCD, uint16_t inBCDLen) {
    static const char hexchars[] = "0123456789ABCDEF";
    uint8_t started = 0;
    MEMZERO(outBuffer, outBufferLen);

    if (outBufferLen < 4) {
        return bool_false;
    }

    if (inBCDLen * 2 > outBufferLen) {
        strcpy(outBuffer, "ERR");
        return bool_false;
    }

    for (uint8_t i = 0; i < inBCDLen; i++, inBCD++) {
        if (started || *inBCD != 0) {
            if (started || (*inBCD >> 4u) != 0) {
                *outBuffer = hexchars[*inBCD >> 4u];
                outBuffer++;
            }
            *outBuffer = hexchars[*inBCD & 0x0Fu];
            outBuffer++;
            started = 1;
        }
    }

    if (!started) {
        strcpy(outBuffer, "0");
    }

    return bool_true;
}

void bignumLittleEndian_to_bcd(uint8_t *bcdOut, uint16_t bcdOutLen,
                               const uint8_t *binValue, uint16_t binValueLen) {
    MEMZERO(bcdOut, bcdOutLen);

    uint8_t carry;
    for (uint16_t bitIdx = 0; bitIdx < binValueLen * 8; bitIdx++) {
        // Fix bcd
        for (uint16_t j = 0; j < bcdOutLen; j++) {
            if ((bcdOut[j] & 0x0Fu) > 0x04u) {
                bcdOut[j] += 0x03u;
            }
            if ((bcdOut[j] & 0xF0u) > 0x40u) {
                bcdOut[j] += 0x30u;
            }
        }

        // get bit
        const uint16_t byteIdx = bitIdx >> 3u;
        const uint8_t mask = 0x80u >> (bitIdx & 0x7u);
        carry = (uint8_t) ((binValue[binValueLen - byteIdx - 1] & mask) > 0);

        // Shift bcd
        for (uint16_t j = 0; j < bcdOutLen; j++) {
            uint8_t carry2 = (uint8_t) (bcdOut[bcdOutLen - j - 1] > 127u);
            bcdOut[bcdOutLen - j - 1] <<= 1u;
            bcdOut[bcdOutLen - j - 1] += carry;
            carry = carry2;
        }
    }
}

bool_t bignumBigEndian_bcdprint(char *outBuffer, uint16_t outBufferLen,
                                const uint8_t *bcdIn, uint16_t bcdInLen) {
    static const char hexchars[] = "0123456789ABCDEF";
    uint8_t started = 0;
    MEMZERO(outBuffer, outBufferLen);

    if (outBufferLen < 4) {
        return bool_false;
    }

    if (bcdInLen * 2 > outBufferLen) {
        strcpy(outBuffer, "ERR");
        return bool_false;
    }

    for (uint16_t i = 0; i < bcdInLen; i++) {
        uint8_t v = bcdIn[bcdInLen - i - 1];
        if (started || v != 0) {
            if (started || (v >> 4u) != 0) {
                *outBuffer = hexchars[v >> 4u];
                outBuffer++;
            }
            *outBuffer = hexchars[v & 0x0Fu];
            outBuffer++;
            started = 1;
        }
    }

    if (!started) {
        strcpy(outBuffer, "0");
    }

    return bool_true;
}

void bignumBigEndian_to_bcd(uint8_t *bcdOut, uint16_t bcdOutLen,
                            const uint8_t *binValue, uint16_t binValueLen) {
    MEMZERO(bcdOut, bcdOutLen);

    uint8_t carry;
    for (uint16_t bitIdx = 0; bitIdx < binValueLen * 8; bitIdx++) {
        // Fix bcd
        for (uint16_t j = 0; j < bcdOutLen; j++) {
            if ((bcdOut[j] & 0x0Fu) > 0x04u) {
                bcdOut[j] += 0x03u;
            }
            if ((bcdOut[j] & 0xF0u) > 0x40u) {
                bcdOut[j] += 0x30u;
            }
        }

        // get bit
        const uint16_t byteIdx = bitIdx >> 3u;
        const uint8_t mask = 0x80u >> (bitIdx & 0x7u);
        carry = (uint8_t) ((binValue[byteIdx] & mask) > 0);

        // Shift bcd
        for (uint16_t j = 0; j < bcdOutLen; j++) {
            uint8_t carry2 = (uint8_t) (bcdOut[j] > 127u);
            bcdOut[j] <<= 1u;
            bcdOut[j] += carry;
            carry = carry2;
        }
    }
}
