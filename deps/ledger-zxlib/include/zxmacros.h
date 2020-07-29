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

#pragma clang diagnostic push
#pragma ide diagnostic ignored "modernize-use-nullptr"
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
#pragma ide diagnostic ignored "OCUnusedMacroInspection"
#pragma ide diagnostic ignored "modernize-deprecated-headers"

#ifdef __cplusplus
extern "C" {
#endif

void check_app_canary();

#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include "string.h"

#ifndef __APPLE__
extern void explicit_bzero(void *s, size_t n) __THROW __nonnull ((1));
#endif
#define __Z_INLINE inline __attribute__((always_inline)) static

void handle_stack_overflow();

#if defined(LEDGER_SPECIFIC)
#include "bolos_target.h"
#endif

#define NV_ALIGN __attribute__ ((aligned(64)))

#if defined (TARGET_NANOS) || defined(TARGET_NANOX)

#include "bolos_target.h"
#include "os.h"
#include "cx.h"

#if defined(TARGET_NANOX)
#include "ux.h"
#define NV_CONST const
#define NV_VOLATILE volatile
#define IS_UX_ALLOWED (G_ux_params.len != BOLOS_UX_IGNORE && G_ux_params.len != BOLOS_UX_CONTINUE)
#else
#include "os_io_seproxyhal.h"
#define NV_CONST
#define NV_VOLATILE
#define IS_UX_ALLOWED (ux.params.len != BOLOS_UX_IGNORE && ux.params.len != BOLOS_UX_CONTINUE)
#endif

#define CHECK_APP_CANARY() check_app_canary();
#define APP_STACK_CANARY_MAGIC 0xDEAD0031
extern unsigned int app_stack_canary;

#define WAIT_EVENT() io_seproxyhal_spi_recv(G_io_seproxyhal_spi_buffer, sizeof(G_io_seproxyhal_spi_buffer), 0)

#define UX_WAIT()  \
    while (!UX_DISPLAYED()) {  WAIT_EVENT();  UX_DISPLAY_NEXT_ELEMENT(); } \
    WAIT_EVENT(); \
    io_seproxyhal_general_status(); \
    WAIT_EVENT()

#define MEMMOVE os_memmove
#define MEMSET os_memset
#define MEMCPY os_memcpy
#define MEMCMP os_memcmp
#define MEMCPY_NV nvm_write
#define MEMZERO explicit_bzero

#else

#ifndef PIC
#define PIC(x) (x)
#endif

#define CHECK_APP_CANARY() {}

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
#endif

#define SET_NV(DST, TYPE, VAL) { \
    TYPE nvset_tmp=(VAL); \
    MEMCPY_NV((void*) PIC(DST), (void *) PIC(&nvset_tmp), sizeof(TYPE)); \
}

#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
#define ZX_SWAP(v) (((v) & 0x000000FFu) << 24u | ((v) & 0x0000FF00u) << 8u | ((v) & 0x00FF0000u) >> 8u | ((v) & 0xFF000000u) >> 24u)
#define HtoNL(v) ZX_SWAP( v )
#define NtoHL(v) ZX_SWAP( v )
#else
#define HtoNL(x) (x)
#define NtoHL(x) (x)
#endif

#define sizeof_field(type, member) sizeof(((type *)0)->member)
#define array_length(array) (sizeof(array) / sizeof((array)[0]))

__Z_INLINE void strncpy_s(char *dst, const char *src, size_t dstSize) {
    MEMZERO(dst, dstSize);
    strncpy(dst, src, dstSize - 1);
}

void zemu_log_stack(char *ctx);

__Z_INLINE void zemu_log(char *buf)
{
#if defined(ZEMU_LOGGING)
    #if defined (TARGET_NANOS) || defined(TARGET_NANOX)
    asm volatile (
    "movs r0, #0x04\n"
    "movs r1, %0\n"
    "svc      0xab\n"
    :: "r"(buf) : "r0", "r1"
    );
    #endif
#endif
}

#ifdef __cplusplus
}
#endif

#pragma clang diagnostic pop

#include "zxformat.h"
