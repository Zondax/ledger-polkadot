/*******************************************************************************
*   (c) 2016 Ledger
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

#include <stdint.h>
#include <stdio.h>

typedef struct {
    uint8_t *data;
    uint16_t size;
    uint16_t pos;
    uint8_t in_use: 1;
} buffer_state_t;

/// Initialize buffer
/// \param ram_buffer
/// \param ram_buffer_size
/// \param flash_buffer
/// \param flash_buffer_size
void buffering_init(uint8_t *ram_buffer,
                    uint16_t ram_buffer_size,
                    uint8_t *flash_buffer,
                    uint16_t flash_buffer_size);

/// Reset buffer
void buffering_reset();

/// Append data to the buffer
/// \param data
/// \param length
/// \return the number of appended bytes
int buffering_append(uint8_t *data, int length);

/// buffering_get_ram_buffer
/// \return
buffer_state_t *buffering_get_ram_buffer();

/// buffering_get_flash_buffer
/// \return
buffer_state_t *buffering_get_flash_buffer();

/// buffering_get_buffer
/// \return
buffer_state_t *buffering_get_buffer();

#ifdef __cplusplus
}
#endif
