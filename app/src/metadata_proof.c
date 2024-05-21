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

#include "metadata_proof.h"

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "metadata_reader.h"
#include "metadata_types.h"
#include "parser_common.h"
#include "parser_impl.h"
#include "scale_helper.h"
#include "zxblake3.h"

#define ROOT_IDX 0

/**
 * @brief Get the left child index of a given node in a binary tree.
 *
 * @param id The index of the current node.
 * @return The index of the left child node.
 */
static uint32_t getLeftChild(uint32_t id) {
    // 2 * id + 1
    return (id << 1) + 1;
}

/**
 * @brief Get the right child index of a given node in a binary tree.
 *
 * @param id The index of the current node.
 * @return The index of the right child node.
 */
static uint32_t getRightChild(uint32_t id) {
    // 2 * id + 2
    return (id << 1) + 2;
}

/**
 * @brief Calculate the integer base-2 logarithm of a given input.
 *
 * @param input The input value.
 * @return The base-2 logarithm of the input, or UINT8_MAX if the input is 0.
 */
static uint8_t log2i(uint32_t input) {
    if (input == 0) {
        return UINT8_MAX;
    }

    uint8_t log2 = 0;
    while (input >>= 1) {
        log2++;
    }

    return log2;
}

/**
 * @brief Check if a given index is a descendant of a leaf in a binary tree.
 *
 * @param index The index to check.
 * @param leaf The leaf index.
 * @return true if the index is a descendant of the leaf, false otherwise.
 */
static bool isDescendant(uint32_t index, uint32_t leaf) {
    if (index == 0) {
        return true;
    }

    // we can't calculate log2i(UINT32_MAX + 1)
    // it's a corner case, will never happen in real life
    if (leaf <= index || leaf == UINT32_MAX) {
        return false;
    }

    index++;
    leaf++;

    // since leaf > index, log2i(leaf) >= log2i(index)
    // at max this is 30, the error is a false positive here
    const uint8_t levelDiff = log2i(leaf) - log2i(index);

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wshift-count-overflow"
    return index == (leaf >> levelDiff);
#pragma GCC diagnostic pop
}

/**
 * @brief Check if a given index is a lemma in a binary tree.
 *
 * @param index The index to check.
 * @param leaf The leaf index.
 * @return true if the index is a lemma, false otherwise.
 */
static bool isLemma(uint32_t index, uint32_t leaf) {
    // if nextLeaf is descendant of index, then we need to compute a hash
    // if not, then we can go and grab next lemma
    return !isDescendant(index, leaf);
}

/**
 * @brief Compute the hash of a leaf node in the proof.
 *
 * @param proof The proof structure containing the leaf node.
 * @return parser_error_t Error code indicating the result of the operation.
 */
static parser_error_t hashLeaf(Proof_t *proof) {
    const uint16_t initialOffset = proof->registry.registry.offset;
    CHECK_ERROR(readType(&proof->registry.registry, &proof->lastEntry));

    // Compute hash from entry and store it in proof->hash
    CHECK_ERROR(zxblake3_hash_init());
    CHECK_ERROR(zxblake3_hash_update(proof->registry.registry.buffer + initialOffset,
                                     (proof->registry.registry.offset - initialOffset)));
    CHECK_ERROR(zxblake3_hash_finalize(proof->hash, BLAKE3_OUT_LEN));

    return parser_ok;
}

/**
 * @brief Merge two branches in a binary tree and compute their combined hash.
 *
 * @param left The hash of the left branch.
 * @param right The hash of the right branch.
 * @param output The output buffer for the combined hash.
 * @return parser_error_t Error code indicating the result of the operation.
 */
// Declaring array sizes as static will trigger a warning if the user pass an array smaller than the size
static parser_error_t mergeBranches(uint8_t left[BLAKE3_STATIC_SIZE],
                                    uint8_t right[BLAKE3_STATIC_SIZE],
                                    uint8_t output[BLAKE3_STATIC_SIZE]) {
    zxblake3_hash_init();
    CHECK_ERROR(zxblake3_hash_update(left, BLAKE3_OUT_LEN));
    CHECK_ERROR(zxblake3_hash_update(right, BLAKE3_OUT_LEN));
    CHECK_ERROR(zxblake3_hash_finalize(output, BLAKE3_OUT_LEN));

    return parser_ok;
}

/**
 * @brief Get the next index from the indices array.
 *
 * @param indices The parser context containing the indices array.
 * @param nextIndex The output buffer for the next index.
 * @return parser_error_t Error code indicating the result of the operation.
 */
// Get next index function will return next index from indices array
// If it reaches the last element, it will set offset to UINT32_MAX
static parser_error_t getNextIndex(parser_context_t *indices, uint32_t *nextIndex) {
    if (indices == NULL || nextIndex == NULL) {
        return parser_unexpected_value;
    }

    if (indices->bufferLen == indices->offset) {
        *nextIndex = UINT32_MAX;
        return parser_ok;
    }

    CHECK_ERROR(_readUInt32(indices, nextIndex));

    return parser_ok;
}

/**
 * @brief Compute the hash for a given index in the proof.
 *
 * @param index The index to compute the hash for.
 * @param proof The proof structure containing the necessary data.
 * @return parser_error_t Error code indicating the result of the operation.
 */
static parser_error_t getHash(uint32_t index, Proof_t *proof) {
    const uint16_t tmpOffset = proof->indices.indices.offset;
    uint32_t nextIndex = 0;
    CHECK_ERROR(getNextIndex(&proof->indices.indices, &nextIndex));

    // Check if this index is used
    if (index == nextIndex) {
        CHECK_ERROR(hashLeaf(proof));
        return parser_ok;
    }

    // If nextIndex doesn't match the requested, restore the offset
    proof->indices.indices.offset = tmpOffset;

    // Check if this index is a lemma
    if (isLemma(index, nextIndex)) {
        CTX_CHECK_AVAIL(&proof->lemmas.lemmas, BLAKE3_OUT_LEN);
        memcpy(proof->hash, proof->lemmas.lemmas.buffer + proof->lemmas.lemmas.offset, BLAKE3_OUT_LEN);
        proof->lemmas.lemmas.offset += BLAKE3_OUT_LEN;
        return parser_ok;
    }

    CHECK_ERROR(checkStack());

    // Go and find left and right children
    uint8_t leftHash[BLAKE3_OUT_LEN] = {0};
    uint8_t rightHash[BLAKE3_OUT_LEN] = {0};

    CHECK_ERROR(getHash(getLeftChild(index), proof));
    memcpy(leftHash, proof->hash, BLAKE3_OUT_LEN);

    CHECK_ERROR(getHash(getRightChild(index), proof));
    memcpy(rightHash, proof->hash, BLAKE3_OUT_LEN);

    mergeBranches(leftHash, rightHash, proof->hash);

    return freeStack();
}

/**
 * @brief Compute the metadata digest for a given metadata structure.
 *
 * @param metadata The metadata structure containing the necessary data.
 * @param metadataDigest The output buffer for the computed metadata digest.
 * @return parser_error_t Error code indicating the result of the operation.
 */
parser_error_t getMetadataDigest(Metadata_t *metadata, uint8_t metadataDigest[BLAKE3_STATIC_SIZE]) {
    Proof_t proof = {0};
    proof.registry = metadata->shortMetadata.shortRegistry;
    proof.lemmas = metadata->shortMetadata.lemmas;
    proof.indices = metadata->shortMetadata.indices;

    // CHECK_ERROR(setInitialConditions(&proof));
    const uint8_t MAX_ONE_BYTE_COMPACT = 0x3F;

    const ExtraInfo_t *extraInfo = &metadata->shortMetadata.extraInfo;

    // get rootHash of registry
    CHECK_ERROR(getHash(ROOT_IDX, &proof));

    // get hash of descriptor
    uint8_t extrinsicMetadataHash[BLAKE3_OUT_LEN] = {0};
    CHECK_ERROR(zxblake3_hash(metadata->shortMetadata.extrinsic.ctx.buffer, metadata->shortMetadata.extrinsic.ctx.bufferLen,
                              extrinsicMetadataHash, sizeof(extrinsicMetadataHash)));

    // Calculate metadata digest
    CHECK_ERROR(zxblake3_hash_init());

    // MetadataDigest V1
    const uint8_t metadatadaDigestVersion = 0x01;
    CHECK_ERROR(zxblake3_hash_update(&metadatadaDigestVersion, 1));

    // types_tree_root
    CHECK_ERROR(zxblake3_hash_update(proof.hash, sizeof(proof.hash)));

    // extrinsic_metadata_hash
    CHECK_ERROR(zxblake3_hash_update(extrinsicMetadataHash, sizeof(extrinsicMetadataHash)));

    // spec_version
    CHECK_ERROR(zxblake3_hash_update((const uint8_t *)&extraInfo->specVersion, sizeof(extraInfo->specVersion)));

    // Restricted to specName shorter than MAX_ONE_BYTE_COMPACT
    // spec_name: compactInt(len) | spec_name[]
    if (extraInfo->specName.len > MAX_ONE_BYTE_COMPACT) {
        return parser_value_out_of_range;
    }

    const uint8_t specNameLenCompact = extraInfo->specName.len << 2;
    CHECK_ERROR(zxblake3_hash_update(&specNameLenCompact, 1));
    CHECK_ERROR(zxblake3_hash_update(extraInfo->specName.ptr, extraInfo->specName.len));

    // base58_prefix
    CHECK_ERROR(zxblake3_hash_update((const uint8_t *)&extraInfo->base58prefix, sizeof(extraInfo->base58prefix)));

    // decimals
    CHECK_ERROR(zxblake3_hash_update(&extraInfo->decimals, sizeof(extraInfo->decimals)));

    // Restricted to unit shorter than MAX_ONE_BYTE_COMPACT
    // unit: compactInt(len) | unit[]
    if (extraInfo->unit.len > MAX_ONE_BYTE_COMPACT) {
        return parser_value_out_of_range;
    }

    const uint8_t unitLenCompact = extraInfo->unit.len << 2;
    CHECK_ERROR(zxblake3_hash_update(&unitLenCompact, 1));
    CHECK_ERROR(zxblake3_hash_update(extraInfo->unit.ptr, extraInfo->unit.len));

    CHECK_ERROR(zxblake3_hash_finalize(metadataDigest, BLAKE3_OUT_LEN));  // we're sure that we have 32 bytes of space

    return parser_ok;
}
