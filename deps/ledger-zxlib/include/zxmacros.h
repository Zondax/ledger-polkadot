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
#define SAFE_HEARTBEAT(X)  X;
#else
#define NV_CONST
#define NV_VOL
// Disabling heartbeat (this was a Nano S workaround for U2F)
#define SAFE_HEARTBEAT(X)  X; /*io_seproxyhal_io_heartbeat(); X; io_seproxyhal_io_heartbeat();*/
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

#define sizeof_field(type, member) sizeof(((type *)0)->member)

#ifdef __cplusplus
}
#endif

#pragma clang diagnostic pop

#include "zxformat.h"
