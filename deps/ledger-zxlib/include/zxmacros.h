/*******************************************************************************
*   (c) 2018 ZondaX GmbH
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

#include "string.h"
#ifndef __APPLE__
extern void explicit_bzero(void *__s, size_t __n) __THROW __nonnull ((1));
#endif
#define __Z_INLINE inline __attribute__((always_inline)) static

#if defined(LEDGER_SPECIFIC)
#include "bolos_target.h"
#endif

#if defined(TARGET_NANOX)
#define NV_CONST const
#define NV_VOL volatile
#define SAFE_HEARTBEAT(X)  io_seproxyhal_io_heartbeat(); X; io_seproxyhal_io_heartbeat();
#else
#define NV_CONST
#define NV_VOL
#define SAFE_HEARTBEAT(X)  X;
#endif

#ifndef PIC
#define PIC(x) (x)
#endif

#define NV_ALIGN __attribute__ ((aligned(64)))

#if defined (TARGET_NANOS) || defined(TARGET_NANOX)

#include "bolos_target.h"
#include "os.h"
#include "cx.h"

#if defined(TARGET_NANOX)
#include "ux.h"
#else
#include "os_io_seproxyhal.h"
#endif

#define WAIT_EVENT() io_seproxyhal_spi_recv(G_io_seproxyhal_spi_buffer, sizeof(G_io_seproxyhal_spi_buffer), 0)

#define UX_WAIT()  \
    while (!UX_DISPLAYED()) {  WAIT_EVENT();  UX_DISPLAY_NEXT_ELEMENT(); } \
    WAIT_EVENT(); \
    io_seproxyhal_general_status(); \
    WAIT_EVENT()

#if defined(TARGET_NANOX)
#define IS_UX_ALLOWED (G_ux_params.len != BOLOS_UX_IGNORE && G_ux_params.len != BOLOS_UX_CONTINUE)
#else
#define IS_UX_ALLOWED (ux.params.len != BOLOS_UX_IGNORE && ux.params.len != BOLOS_UX_CONTINUE)
#endif

#define MEMMOVE os_memmove
#define MEMSET os_memset
#define MEMCPY os_memcpy
#define MEMCMP os_memcmp
#define MEMCPY_NV nvm_write
#define MEMZERO explicit_bzero

void debug_printf(void* buffer);

#undef LOG
#undef LOGSTACK
#define LOG(str) debug_printf(str)
extern unsigned int app_stack_canary;
void __logstack();
#define LOGSTACK() __logstack()

#else

#define MEMMOVE memmove
#define MEMSET memset
#define MEMCPY memcpy
#define MEMCMP memcmp
#define MEMCPY_NV memcpy

#define CX_ECCINFO_PARITY_ODD 1u
#define CX_ECCINFO_xGTn 2u

#ifndef __APPLE__
#define MEMZERO explicit_bzero
#else
__Z_INLINE void __memzero(void *buffer, size_t s) { memset(buffer, 0, s); }
#define MEMZERO __memzero
#endif

#define LOG(str)
#define LOGSTACK()
#endif

#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

#define SET_NV(DST, TYPE, VAL) { \
    TYPE nvset_tmp=(VAL); \
    MEMCPY_NV((void*) PIC(DST), (void *) PIC(&nvset_tmp), sizeof(TYPE)); \
}

#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
#define __SWAP(v) (((v) & 0x000000FFu) << 24u | ((v) & 0x0000FF00u) << 8u | ((v) & 0x00FF0000u) >> 8u | ((v) & 0xFF000000u) >> 24u)
#define HtoNL(v) __SWAP( v )
#define NtoHL(v) __SWAP( v )
#else
#define HtoNL(x) (x)
#define NtoHL(x) (x)
#endif

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

NUM_TO_STR(int64)

NUM_TO_STR(uint64)

__Z_INLINE void bip44_to_str(char *s, uint32_t max, const uint32_t path[5]) {
    snprintf(s, max, "%d%s%d%s%d%s%d%s%d%s",
             path[0] & 0x7FFFFFFFu, (path[0] & 0x80000000u) != 0 ? "'/" : "/",
             path[1] & 0x7FFFFFFFu, (path[1] & 0x80000000u) != 0 ? "'/" : "/",
             path[2] & 0x7FFFFFFFu, (path[2] & 0x80000000u) != 0 ? "'/" : "/",
             path[3] & 0x7FFFFFFFu, (path[3] & 0x80000000u) != 0 ? "'/" : "/",
             path[4] & 0x7FFFFFFFu, (path[4] & 0x80000000u) != 0 ? "'" : "");
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
    uint64_t multiplier = 1;
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

    return value * sign;
}

__Z_INLINE void fpstr_to_str(char *dst, const char *number, uint8_t decimals) {
    size_t digits = strlen(number);

    if (digits <= decimals) {
        *dst++ = '0';
        *dst++ = '.';
        for (uint16_t i = 0; i < decimals - digits; i++, dst++)
            *dst = '0';
        strcpy(dst, number);
    } else {
        strcpy(dst, number);
        const size_t shift = digits - decimals;
        dst = dst + shift;
        *dst++ = '.';

        const char *p = number + shift;
        strcpy(dst, p);
    }
}

__Z_INLINE void fpuint64_to_str(char *dst, const uint64_t value, uint8_t decimals) {
    char buffer[30];
    MEMZERO(buffer, sizeof(buffer));
    int64_to_str(buffer, 30, value);
    fpstr_to_str(dst, buffer, decimals);
}

__Z_INLINE uint64_t uint64_from_BEarray(const uint8_t data[8]) {
    uint64_t result = 0;
    for (uint8_t i = 0; i < 8u; i++) {
        result <<= 8u;
        result += data[i];
    }
    return result;
}

__Z_INLINE uint16_t array_to_hexstr(char *dst, uint16_t dstLen, const uint8_t *src, uint8_t count) {

    if (dstLen < (count * 2 + 1)) {
        return 0;
    }

    const char hexchars[] = "0123456789ABCDEF";
    for (uint8_t i = 0; i < count; i++, src++) {
        *dst++ = hexchars[*src >> 4u];
        *dst++ = hexchars[*src & 0x0Fu];
    }
    *dst = 0; // terminate string

    return count * 2;
}

__Z_INLINE void pageStringExt(char *outValue, uint16_t outValueLen,
                              const char *inValue, uint16_t inValueLen,
                              uint8_t pageIdx, uint8_t *pageCount) {
    MEMZERO(outValue, outValueLen);

    outValueLen--;  // leave space for NULL termination
    if (outValueLen == 0) {
        return;
    }

    if (inValueLen == 0) {
        *pageCount = 0;
        return;
    }

    *pageCount = (inValueLen / outValueLen);
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
    pageStringExt(outValue, outValueLen, inValue, strlen(inValue), pageIdx, pageCount);
}

///////////////////////
///////////////////////
///////////////////////
///////////////////////

size_t asciify(char *utf8_in);

size_t asciify_ext(const char *utf8_in, char *ascii_only_out);

#ifdef __cplusplus
}
#endif
