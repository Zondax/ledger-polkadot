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

#include <stdbool.h>
#include <stdint.h>

#include "coin.h"
#include "parser_common.h"
#include "parser_txdef.h"
#include "substrate_types.h"
#include "zxblake3.h"

#ifdef __cplusplus
extern "C" {
#define BLAKE3_STATIC_SIZE 32
#else
#define BLAKE3_STATIC_SIZE static BLAKE3_OUT_LEN
#endif

typedef struct {
    uint8_t hash[BLAKE3_OUT_LEN];
    ShortRegistry_t registry;
    MerkleIndices_t indices;
    MerkleLemmas_t lemmas;
    RegistryEntry_t lastEntry;
    uint8_t variantIndex;
    uint16_t initialEntryOffset;
} Proof_t;

parser_error_t getMetadataDigest(Metadata_t *metadata, uint8_t metadataDigest[BLAKE3_STATIC_SIZE]);

#ifdef __cplusplus
}
#endif
