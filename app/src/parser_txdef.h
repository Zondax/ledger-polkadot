/*******************************************************************************
 *  (c) 2018 - 2024 Zondax AG
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

#include "blake3.h"
#include "metadata_types.h"

// Check what will be stored in ShortRegistry struct
typedef struct {
    uint32_t entries;
    parser_context_t registry;
} ShortRegistry_t;

typedef struct {
    uint32_t entries;
    parser_context_t indices;
} MerkleIndices_t;

typedef struct {
    uint32_t entries;
    parser_context_t lemmas;
} MerkleLemmas_t;

typedef struct {
    parser_context_t ctx;
    uint8_t version;
    TypeRef_t addressType;
    TypeRef_t callType;
    TypeRef_t signatureType;
    Vector_t signedExtensions;
} ExtrinsicMetadata_t;

typedef struct {
    parser_context_t ctx;
    uint32_t specVersion;
    Bytes_t specName;
    uint16_t base58prefix;
    uint8_t decimals;
    Bytes_t unit;  // tokenSymbol
} ExtraInfo_t;

typedef struct {
    ShortRegistry_t shortRegistry;
    MerkleIndices_t indices;
    MerkleLemmas_t lemmas;
    ExtrinsicMetadata_t extrinsic;
    ExtraInfo_t extraInfo;
} ShortMetadata_t;

typedef struct {
    ShortMetadata_t shortMetadata;
    RegistryEntry_t palletEntry;
    parser_context_t metadataBuf;
} Metadata_t;

typedef struct {
    uint8_t totalMethodItems;
    uint8_t tipItems;
    uint8_t totalSigExtItems;
    parser_context_t blobBuf;
    uint16_t sigExtStartOffset;
} Blob_t;

typedef struct {
    Metadata_t metadata;
    Blob_t blob;
    uint8_t metadataDigest[BLAKE3_OUT_LEN];
    OptBytes_t checkMetadataDigest;
} parser_tx_t;

#ifdef __cplusplus
}
#endif
