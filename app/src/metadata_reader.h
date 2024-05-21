/*******************************************************************************
 *   (c) 2018 - 2024 Zondax AG
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

#include "metadata_types.h"
#include "parser_common.h"

parser_error_t checkStack();
parser_error_t freeStack();

parser_error_t metadata_read(parser_tx_t *txObj);

parser_error_t readType(parser_context_t *ctx, RegistryEntry_t *entry);
parser_error_t getVariant(parser_context_t *ctx, RegistryEntry_t *type, uint32_t typeId, uint8_t index);

// Helpers
parser_error_t checkPathKeyword(Vector_t *path, const char *keyword, bool *found);
parser_error_t readSignedExtension(parser_context_t *ctx, SignedExtension_t *extension);
parser_error_t getType(parser_context_t *ctx, RegistryEntry_t *type, uint32_t typeId);
parser_error_t readField(parser_context_t *ctx, Field_t *entry);
parser_error_t readTypeRef(parser_context_t *ctx, TypeRef_t *type);

#ifdef __cplusplus
}
#endif
