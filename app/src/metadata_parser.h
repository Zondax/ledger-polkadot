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

#include "parser_common.h"
#include "parser_impl.h"

#define CALL_ID_STR        "Call"
#define PALLET_ID_STR      "RuntimeCall"

#define OPTION_ID_STR      "Option"
#define SOME_ID_STR        "Some"

#define ACCOUNTID32_ID_STR "AccountId32"
#define VOTE_ID_STR        "Vote"

/**
 * @brief Parse a metadata entry and update the print item accordingly.
 *
 * @param blob Pointer to the parser context for the blob.
 * @param metadata Pointer to the parser context for the metadata.
 * @param typeId Type ID of the metadata entry to parse.
 * @param tmpEntry Pointer to the temporary registry entry.
 * @param printItem Pointer to the print item to update.
 * @return parser_error_t Error code indicating the result of the operation.
 */
parser_error_t parseMetadataEntry(
    parser_context_t *blob, parser_context_t *metadata, uint32_t typeId, RegistryEntry_t *tmpEntry, PrintItem_t *printItem);

/**
 * @brief Parse a type reference and update the print item accordingly.
 *
 * @param blob Pointer to the parser context for the blob.
 * @param metadata Pointer to the parser context for the metadata.
 * @param tmpEntry Pointer to the temporary registry entry.
 * @param type Pointer to the type reference to parse.
 * @param printItem Pointer to the print item to update.
 * @return parser_error_t Error code indicating the result of the operation.
 */
parser_error_t parseTypeRef(parser_context_t *blob,
                            parser_context_t *metadata,
                            RegistryEntry_t *tmpEntry,
                            const TypeRef_t *type,
                            PrintItem_t *printItem);

#ifdef __cplusplus
}
#endif
