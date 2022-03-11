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

#if defined (TARGET_NANOS) || defined(TARGET_NANOX) || defined(TARGET_NANOS2)

#include "os.h"
#include "cx.h"

#define MEMCPY_NV nvm_write

// This macros are kept for backwards compatibility
// the most recent SDK has unified implementations and deprecated the original os_***
#define MEMCPY memmove
#define MEMMOVE memmove
#define MEMSET memset
#define MEMCMP memcmp
#define MEMZERO explicit_bzero

#if defined(TARGET_NANOX) || defined(TARGET_NANOS2)
#include "ux.h"
#define NV_CONST const
#define NV_VOLATILE volatile
#define IS_UX_ALLOWED (G_ux_params.len != BOLOS_UX_IGNORE && G_ux_params.len != BOLOS_UX_CONTINUE)
#else
#include "ux.h"
#include "os_io_seproxyhal.h"
#define NV_CONST
#define NV_VOLATILE
#define IS_UX_ALLOWED (G_ux_params.len != BOLOS_UX_IGNORE && G_ux_params.len != BOLOS_UX_CONTINUE)
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
#endif
