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

#ifdef __cplusplus
extern "C" {
#endif

#include "zxmacros.h"
#include "zxerror.h"

#define NUM_TO_STR(TYPE) __Z_INLINE const char * TYPE##_to_str(char *data, int dataLen, TYPE##_t number) { \
    if (dataLen < 2) return "Buffer too small";     \
    MEMZERO(data, dataLen);                         \
    char *p = data;                                 \
    if (number < 0) { *(p++) = '-'; data++; }       \
    else if (number == 0) { *(p++) = '0'; }         \
    TYPE##_t tmp;                                   \
    while (number != 0) {                           \
        if (p - data >= (dataLen - 1)) {    return "Buffer too small";  }   \
        tmp = number % 10;                          \
        tmp = tmp < 0 ? -tmp : tmp;                 \
        *(p++) = (char) ('0' + tmp);                \
        number /= 10u;                              \
    }                                               \
    while (p > data) {                              \
        p--;                                        \
        char z = *data; *data = *p; *p = z;         \
        data++;                                     \
    }                                               \
    return NULL;                                    \
}

NUM_TO_STR(int32)

NUM_TO_STR(int64)

NUM_TO_STR(uint64)

size_t z_strlen(const char *buffer, size_t maxSize);

zxerr_t z_str3join(char *buffer, size_t bufferSize, const char *prefix, const char *suffix);

__Z_INLINE void bip32_to_str(char *s, uint32_t max, const uint32_t *path, uint8_t pathLen) {
    MEMZERO(s, max);

    if (pathLen == 0) {
        snprintf(s, max, "EMPTY PATH");
        return;
    }

    if (pathLen > 5) {
        snprintf(s, max, "ERROR");
        return;
    }

    uint32_t offset = 0;
    for (uint16_t i = 0; i < pathLen; i++) {
        size_t written;

        // Warning: overcomplicated because Ledger's snprintf does not return number of written bytes

        snprintf(s + offset, max - offset, "%d", path[i] & 0x7FFFFFFFu);
        written = strlen(s + offset);
        if (written == 0 || written >= max - offset) {
            snprintf(s, max, "ERROR");
            return;
        }
        offset += written;

        if ((path[i] & 0x80000000u) != 0) {
            snprintf(s + offset, max - offset, "'");
            written = strlen(s + offset);
            if (written == 0 || written >= max - offset) {
                snprintf(s, max, "ERROR");
                return;
            }
            offset += written;
        }

        if (i != pathLen - 1) {
            snprintf(s + offset, max - offset, "/");
            written = strlen(s + offset);
            if (written == 0 || written >= max - offset) {
                snprintf(s, max, "ERROR");
                return;
            }
            offset += written;
        }
    }
}

__Z_INLINE void bip44_to_str(char *s, uint32_t max, const uint32_t path[5]) {
    bip32_to_str(s, max, path, 5);
}

__Z_INLINE int8_t str_to_int8(const char *start, const char *end, char *error) {
    int sign = 1;
    if (*start == '-') {
        sign = -1;
        start++;
    }

    int64_t value = 0;
    int multiplier = 1;
    for (const char *s = end - 1; s >= start; s--) {
        int delta = (*s - '0');
        if (delta >= 0 && delta <= 9) {
            value += (delta * multiplier);
            multiplier *= 10;
        } else {
            if (error != NULL) {
                *error = 1;
                return 0;
            }
        }
    }

    value *= sign;
    if (value >= INT8_MIN && value <= INT8_MAX) {
        return (int8_t) value;
    }
    if (error != NULL) {
        *error = 1;
    }
    return 0;
}

__Z_INLINE int64_t str_to_int64(const char *start, const char *end, char *error) {
    int sign = 1;
    if (*start == '-') {
        sign = -1;
        start++;
    }

    int64_t value = 0;
    int64_t multiplier = 1;
    for (const char *s = end - 1; s >= start; s--) {
        int64_t delta = (*s - '0');
        if (delta >= 0 && delta <= 9) {
            value += delta * multiplier;
            multiplier *= 10;
        } else {
            if (error != NULL) {
                *error = 1;
                return 0;
            }
        }
    }

    return value * sign;
}

uint8_t intstr_to_fpstr_inplace(char *number, size_t number_max_size, uint8_t decimalPlaces);

__Z_INLINE uint8_t fpstr_to_str(char *out, uint16_t outLen, const char *number, uint8_t decimals) {
    MEMZERO(out, outLen);
    size_t digits = strlen(number);

    if (decimals == 0) {
        if (digits == 0) {
            snprintf(out, outLen, "0");
            return 0;
        }

        if (outLen < digits) {
            snprintf(out, outLen, "ERR");
            return 1;
        }

        // No need for formatting
        snprintf(out, outLen, "%s", number);
        return 0;
    }

    if ((outLen < decimals + 2)) {
        snprintf(out, outLen, "ERR");
        return 1;
    }

    if (outLen < digits + 2) {
        snprintf(out, outLen, "ERR");
        return 1;
    }

    if (digits <= decimals) {
        if (outLen <= decimals + 2) {
            snprintf(out, outLen, "ERR");
            return 1;
        }

        // First part
        snprintf(out, outLen, "0.");
        out += 2;
        outLen -= 2;

        MEMSET(out, '0', decimals - digits);
        out += decimals - digits;
        outLen -= decimals - digits;

        snprintf(out, outLen, "%s", number);
        return 0;
    }

    const size_t shift = digits - decimals;
    snprintf(out, outLen, "%s", number);
    number += shift;

    out += shift;
    outLen -= shift;

    *out++ = '.';
    outLen--;
    snprintf(out, outLen, "%s", number);
    return 0;
}

__Z_INLINE uint16_t fpuint64_to_str(char *out, uint16_t outLen, const uint64_t value, uint8_t decimals) {
    char buffer[30];
    MEMZERO(buffer, sizeof(buffer));
    uint64_to_str(buffer, sizeof(buffer), value);
    fpstr_to_str(out, outLen, buffer, decimals);
    return (uint16_t) strlen(out);
}

__Z_INLINE void number_inplace_trimming(char *s, uint8_t non_trimmed) {
    const size_t len = strlen(s);
    if (len == 0 || len == 1 || len > 1024) {
        return;
    }

    int16_t dec_point = -1;
    for (int16_t i = 0; i < (int16_t) len && dec_point < 0; i++) {
        if (s[i] == '.') {
            dec_point = i;
        }
    }
    if (dec_point < 0) {
        return;
    }

    const size_t limit = (size_t) dec_point + non_trimmed;
    for (size_t i = (len - 1); i > limit && s[i] == '0'; i--) {
        s[i] = 0;
    }
}

__Z_INLINE uint64_t uint64_from_BEarray(const uint8_t data[8]) {
    uint64_t result = 0;
    for (uint8_t i = 0; i < 8u; i++) {
        result <<= 8u;
        result += data[i];
    }
    return result;
}

__Z_INLINE uint32_t array_to_hexstr(char *dst, uint16_t dstLen, const uint8_t *src, uint8_t count) {
    MEMZERO(dst, dstLen);
    if (dstLen < (count * 2 + 1)) {
        return 0;
    }

    const char hexchars[] = "0123456789abcdef";
    for (uint8_t i = 0; i < count; i++, src++) {
        *dst++ = hexchars[*src >> 4u];
        *dst++ = hexchars[*src & 0x0Fu];
    }
    *dst = 0; // terminate string

    return (uint32_t) (count * 2);
}

__Z_INLINE void pageStringExt(char *outValue, uint16_t outValueLen,
                              const char *inValue, uint16_t inValueLen,
                              uint8_t pageIdx, uint8_t *pageCount) {
    MEMZERO(outValue, outValueLen);
    *pageCount = 0;

    outValueLen--;  // leave space for NULL termination
    if (outValueLen == 0) {
        return;
    }

    if (inValueLen == 0) {
        return;
    }

    *pageCount = (uint8_t) (inValueLen / outValueLen);
    const uint16_t lastChunkLen = (inValueLen % outValueLen);

    if (lastChunkLen > 0) {
        (*pageCount)++;
    }

    if (pageIdx < *pageCount) {
        if (lastChunkLen > 0 && pageIdx == *pageCount - 1) {
            MEMCPY(outValue, inValue + (pageIdx * outValueLen), lastChunkLen);
        } else {
            MEMCPY(outValue, inValue + (pageIdx * outValueLen), outValueLen);
        }
    }
}

__Z_INLINE void pageString(char *outValue, uint16_t outValueLen,
                           const char *inValue,
                           uint8_t pageIdx, uint8_t *pageCount) {
    pageStringExt(outValue, outValueLen, inValue, (uint16_t) strlen(inValue), pageIdx, pageCount);
}

__Z_INLINE zxerr_t formatBufferData(
        const uint8_t *ptr,
        uint64_t len,
        char *outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t *pageCount) {
    char bufferUI[500 + 1];
    MEMZERO(bufferUI, sizeof(bufferUI));
    MEMZERO(outValue, 0);
    CHECK_APP_CANARY()

    if (len >= sizeof(bufferUI)) {
        return zxerr_buffer_too_small;
    }
    memcpy(bufferUI, ptr, len);

    // Check we have all ascii
    uint8_t allAscii = 1;
    for (size_t i = 0; i < len && allAscii; i++) {
        if (bufferUI[i] < 32 || bufferUI[i] > 127) {
            allAscii = 0;
        }
    }

    if (!allAscii) {
        bufferUI[0] = '0';
        bufferUI[1] = 'x';
        if (array_to_hexstr(bufferUI + 2, sizeof(bufferUI) - 2, ptr, len) == 0) {
            return zxerr_buffer_too_small;
        }
    }

    pageString(outValue, outValueLen, bufferUI, pageIdx, pageCount);

    return zxerr_ok;
}

size_t asciify(char *utf8_in);

size_t asciify_ext(const char *utf8_in, char *ascii_only_out);

#ifdef __cplusplus
}
#endif
