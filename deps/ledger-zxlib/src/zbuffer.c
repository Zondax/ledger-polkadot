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

#include "zbuffer.h"
#include "zxmacros.h"

typedef struct {
    uint8_t *ptr;
    uint16_t size;
} zbuffer_t;

zbuffer_t zbuffer_internal;

#define CANARY_EXPECTED 0x987def82u

zbuffer_error_e zb_get(uint8_t **buffer) {
#if defined (TARGET_NANOS) || defined(TARGET_NANOX)
    *buffer = NULL;
    if (zbuffer_internal.size == 0 || zbuffer_internal.ptr == NULL) {
        return zb_not_allocated;
    }
    *buffer = zbuffer_internal.ptr;
#endif
    return zb_no_error;
}

zbuffer_error_e zb_init() {
#if defined (TARGET_NANOS) || defined(TARGET_NANOX)
    zbuffer_internal.size = 0;
    zbuffer_internal.ptr = NULL;
#endif
    return zb_no_error;
}

zbuffer_error_e zb_allocate(uint16_t size) {
#if defined (TARGET_NANOS) || defined(TARGET_NANOX)
    if (size % 4 != 0) {
        size += size % 4;
    }
    zbuffer_internal.size = size;
    zbuffer_internal.ptr = (uint8_t * )(&app_stack_canary + 4);

    uint32_t *zb_canary = (uint32_t * )(zbuffer_internal.ptr + zbuffer_internal.size + 4);
    *zb_canary = CANARY_EXPECTED;
#endif
    return zb_no_error;
}

zbuffer_error_e zb_deallocate() {
#if defined (TARGET_NANOS) || defined(TARGET_NANOX)
    if (zbuffer_internal.size == 0) {
        return zb_not_allocated;
    }

    // Flush any information
    MEMZERO(zbuffer_internal.ptr, zbuffer_internal.size);

    zb_init();
#endif
    return zb_no_error;
}

zbuffer_error_e zb_check_canary() {
#if defined (TARGET_NANOS) || defined(TARGET_NANOX)
    CHECK_APP_CANARY();
    if (zbuffer_internal.size != 0) {
        // allocated
        uint32_t *zb_canary = (uint32_t * )(zbuffer_internal.ptr + zbuffer_internal.size + 4);
        if (*zb_canary != CANARY_EXPECTED) {
            handle_stack_overflow();
        }
    }
#endif
    return zb_no_error;
}
