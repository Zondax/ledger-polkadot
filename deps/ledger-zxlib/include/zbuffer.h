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
#pragma once

#include <inttypes.h>
#include <stdint.h>

typedef enum {
    zb_no_error,
    zb_misaligned_buffer,
    zb_not_allocated
} zbuffer_error_e;

// allocate a block at the end of the stack
// maximum size will not be checked
zbuffer_error_e zb_allocate(uint16_t size);

// deallocate memory block as the end of the stack
zbuffer_error_e zb_deallocate();

// obtain a pointer to the allocated block
zbuffer_error_e zb_get(uint8_t **buffer);

// check that the block boundary has not been corrupted
zbuffer_error_e zb_check_canary();
