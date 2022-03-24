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

#if !defined (TARGET_NANOS) && !defined(TARGET_NANOX) && !defined(TARGET_NANOS2)

// This macros are kept for backwards compatibility
// the most recent SDK has unified implementations and deprecated the original os_***
#define MEMMOVE memmove
#define MEMSET memset
#define MEMCPY memcpy
#define MEMCMP memcmp
#define MEMCPY_NV memcpy

#define PIC(x) (x)
#define CHECK_APP_CANARY() {}
#define CX_ECCINFO_PARITY_ODD 1u
#define CX_ECCINFO_xGTn 2u

#ifndef __APPLE__
#define MEMZERO explicit_bzero
#else
__Z_INLINE void __memzero(void *buffer, size_t s) { memset(buffer, 0, s); }
#define MEMZERO __memzero
#endif

#endif
