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

#include "metadata_reader.h"

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "metadata_types.h"
#include "parser_common.h"
#include "parser_impl.h"
#include "parser_txdef.h"
#include "scale_helper.h"
#include "substrate_types.h"
#include "zxmacros.h"

#if defined(TARGET_NANOS) || defined(TARGET_NANOX) || defined(TARGET_NANOS2) || defined(TARGET_STAX) || defined(TARGET_FLEX)
#define STACK_SHIFT   20
#define MINIMUM_STACK 400
#else
static uint16_t recursionDepthCounter = 0;
#define MAX_RECURSION_DEPTH 50
#endif

/**
 * @brief Checks the available stack space to prevent stack overflow.
 *
 * @return parser_error_t Returns parser_running_out_of_stack if stack space is insufficient, otherwise parser_ok.
 */
parser_error_t checkStack() {
#if defined(TARGET_NANOS) || defined(TARGET_NANOX) || defined(TARGET_NANOS2) || defined(TARGET_STAX) || defined(TARGET_FLEX)
    // NOLINTNEXTLINE(readability-identifier-length): here `p` is fine
    void *p = NULL;
    const uint32_t availableStack = (uint32_t)((void *)&p) + STACK_SHIFT - (uint32_t)&app_stack_canary;
    ZEMU_LOGF(50, "Available stack: %d\n", availableStack)
    if (availableStack <= MINIMUM_STACK) {
        return parser_running_out_of_stack;
    }
#else
    if (recursionDepthCounter >= MAX_RECURSION_DEPTH) {
        return parser_running_out_of_stack;
    }
    recursionDepthCounter++;
#endif
    return parser_ok;
}

/**
 * @brief Frees the stack space by decrementing the recursion depth counter.
 *
 * @return parser_error_t Always returns parser_ok.
 */
parser_error_t freeStack() {
#if !defined(TARGET_NANOS) && !defined(TARGET_NANOX) && !defined(TARGET_NANOS2) && !defined(TARGET_STAX) && \
    !defined(TARGET_FLEX)
    if (recursionDepthCounter > 0) {
        recursionDepthCounter--;
    }
#endif
    return parser_ok;
}

/**
 * @brief Reads a TypeRef from the parser context.
 *
 * @param ctx The parser context.
 * @param type The TypeRef to be read.
 * @return parser_error_t Returns parser_ok on success, otherwise an error code.
 */
parser_error_t readTypeRef(parser_context_t *ctx, TypeRef_t *type) {
    CHECK_INPUT(type);

    MEMZERO(type, sizeof(*type));
    CHECK_ERROR(_readUInt8(ctx, &type->index));
    if (type->index == ById) {
        CHECK_ERROR(readCompactU32(ctx, &type->byId));
    }
    return parser_ok;
}

/**
 * @brief Reads a Field from the parser context.
 *
 * @param ctx The parser context.
 * @param entry The Field to be read.
 * @return parser_error_t Returns parser_ok on success, otherwise an error code.
 */
parser_error_t readField(parser_context_t *ctx, Field_t *entry) {
    CHECK_INPUT(entry);

    // Read opt<name>
    CHECK_ERROR(readOptBytes(ctx, &entry->name));
    // Read type
    CHECK_ERROR(readTypeRef(ctx, &entry->type));
    // Read opt<typeName>
    CHECK_ERROR(readOptBytes(ctx, &entry->typeName));

    return parser_ok;
}

/**
 * @brief Reads a Composite field from the parser context.
 *
 * @param ctx The parser context.
 * @param composite The Composite field to be read.
 * @return parser_error_t Returns parser_ok on success, otherwise an error code.
 */
static parser_error_t readCompositeField(parser_context_t *ctx, Composite_t *composite) {
    CHECK_INPUT(composite);

    // Read fields len
    CHECK_ERROR(readCompactU32(ctx, &composite->len));
    const uint16_t startOffset = ctx->offset;
    composite->ctx.buffer = ctx->buffer + startOffset;

    Field_t entry = {0};
    for (uint32_t i = 0; i < composite->len; i++) {
        CHECK_ERROR(readField(ctx, &entry));
    }
    composite->ctx.bufferLen = ctx->offset - startOffset;

    return parser_ok;
}

/**
 * @brief Reads an Enumeration variant from the parser context.
 *
 * @param ctx The parser context.
 * @param entry The Enumeration variant to be read.
 * @return parser_error_t Returns parser_ok on success, otherwise an error code.
 */
parser_error_t readEnumerationVariant(parser_context_t *ctx, Enumeration_t *entry) {
    if (ctx == NULL || entry == NULL) {
        return parser_no_data;
    }

    // Read name
    CHECK_ERROR(readBytes(ctx, &entry->name));
    // Read fields
    CHECK_ERROR(readCompositeField(ctx, &entry->fields));
    // Read index
    CHECK_ERROR(readCompactU32(ctx, &entry->index));

    return parser_ok;
}

/**
 * @brief Reads a Sequence from the parser context.
 *
 * @param ctx The parser context.
 * @param sequence The Sequence to be read.
 * @return parser_error_t Returns parser_ok on success, otherwise an error code.
 */
static parser_error_t readSequence(parser_context_t *ctx, Sequence_t *sequence) {
    CHECK_INPUT(sequence);

    // Read type
    CHECK_ERROR(readTypeRef(ctx, sequence));
    return parser_ok;
}

/**
 * @brief Reads an Array from the parser context.
 *
 * @param ctx The parser context.
 * @param array The Array to be read.
 * @return parser_error_t Returns parser_ok on success, otherwise an error code.
 */
static parser_error_t readArray(parser_context_t *ctx, Array_t *array) {
    CHECK_INPUT(array);

    // Read len
    CHECK_ERROR(_readUInt32(ctx, &array->len));
    // Read type
    CHECK_ERROR(readTypeRef(ctx, &array->typeParam));
    return parser_ok;
}

/**
 * @brief Reads a Tuple from the parser context.
 *
 * @param ctx The parser context.
 * @param tuple The Tuple to be read.
 * @return parser_error_t Returns parser_ok on success, otherwise an error code.
 */
static parser_error_t readTuple(parser_context_t *ctx, Tuple_t *tuple) {
    CHECK_INPUT(tuple);

    // Read vec
    CHECK_ERROR(readCompactU32(ctx, &tuple->len));
    tuple->ctx.buffer = ctx->buffer + ctx->offset;
    const uint16_t startOffset = ctx->offset;

    for (uint32_t i = 0; i < tuple->len; i++) {
        TypeRef_t entry = {0};
        CHECK_ERROR(readTypeRef(ctx, &entry));
    }
    tuple->ctx.bufferLen = ctx->offset - startOffset;

    return parser_ok;
}

/**
 * @brief Reads a BitSequence from the parser context.
 *
 * @param ctx The parser context.
 * @param bitSequence The BitSequence to be read.
 * @return parser_error_t Returns parser_ok on success, otherwise an error code.
 */
static parser_error_t readBitSequence(parser_context_t *ctx, BitSequence_t *bitSequence) {
    CHECK_INPUT(bitSequence);

    // Read num bytes
    CHECK_ERROR(_readUInt8(ctx, &bitSequence->numBytes))
    // Read least significant bit first (boolean field)
    uint8_t tmpLSB = 0;
    CHECK_ERROR(_readUInt8(ctx, &tmpLSB))
    if (tmpLSB > 1) {
        return parser_value_out_of_range;
    }
    bitSequence->lsbFirst = (bool)tmpLSB;
    return parser_ok;
}

/**
 * @brief Reads a Type entry from the "short-metadata".
 *
 * @param ctx The parser context.
 * @param entry The Type entry to be read.
 * @return parser_error_t Returns parser_ok on success, otherwise an error code.
 */
parser_error_t readType(parser_context_t *ctx, RegistryEntry_t *entry) {
    CHECK_INPUT(entry)

    // Read path
    CHECK_ERROR(readCompactU32(ctx, &entry->path.len));
    entry->path.ctx.buffer = ctx->buffer + ctx->offset;
    const uint16_t pathStartOffset = ctx->offset;
    for (uint32_t i = 0; i < entry->path.len; i++) {
        Bytes_t pathEntry = {0};
        CHECK_ERROR(readBytes(ctx, &pathEntry));
    }
    entry->path.ctx.bufferLen = ctx->offset - pathStartOffset;

    // Read type_def
    uint8_t tmpType = 0;
    CHECK_ERROR(_readUInt8(ctx, &tmpType));
    if (tmpType >= TypeDefLast) {
        return parser_value_out_of_range;
    }
    entry->kind = (TypeDef_e)tmpType;
    switch (entry->kind) {
        case Composite:
            CHECK_ERROR(readCompositeField(ctx, &entry->composite));
            break;
        case Enumeration:
            CHECK_ERROR(readEnumerationVariant(ctx, &entry->enumeration));
            break;
        case Sequence:
            CHECK_ERROR(readSequence(ctx, &entry->sequence));
            break;
        case Array:
            CHECK_ERROR(readArray(ctx, &entry->array));
            break;
        case Tuple:
            CHECK_ERROR(readTuple(ctx, &entry->tuple));
            break;
        case BitSequenceType:
            CHECK_ERROR(readBitSequence(ctx, &entry->bitSequence));
            break;
        default:
            return parser_unexpected_value;
    }

    // Read type_id
    CHECK_ERROR(readCompactU32(ctx, &entry->typeId))
    return parser_ok;
}

/**
 * @brief Reads the ShortRegistry (renamed as Leaves in shorterner crate) from the parser context.
 *
 * @param ctx The parser context.
 * @param registry The ShortRegistry to be read.
 * @return parser_error_t Returns parser_ok on success, otherwise an error code.
 */
static parser_error_t readShortRegistry(parser_context_t *ctx, ShortRegistry_t *registry) {
    if (ctx == NULL || registry == NULL) {
        return parser_error_dummy;
    }

    CHECK_ERROR(readCompactU32(ctx, &registry->entries));
    registry->registry.buffer = ctx->buffer + ctx->offset;
    RegistryEntry_t tmpEntry = {0};
    for (uint32_t idx = 0; idx < registry->entries; idx++) {
        CHECK_ERROR(readType(ctx, &tmpEntry));
    }
    registry->registry.bufferLen = ctx->buffer + ctx->offset - registry->registry.buffer;
    return parser_ok;
}

/**
 * @brief Reads Merkle indices from the parser context.
 *
 * @param ctx The parser context.
 * @param indices The Merkle indices to be read.
 * @return parser_error_t Returns parser_ok on success, otherwise an error code.
 */
static parser_error_t readMerkleIndices(parser_context_t *ctx, MerkleIndices_t *indices) {
    if (ctx == NULL || indices == NULL) {
        return parser_no_data;
    }

    CHECK_ERROR(readCompactU32(ctx, &indices->entries));
    indices->indices.buffer = ctx->buffer + ctx->offset;
    indices->indices.offset = 0;
    indices->indices.bufferLen = 4 * indices->entries;

    uint32_t tmpIndex = 0;
    for (uint32_t idx = 0; idx < indices->entries; idx++) {
        CHECK_ERROR(_readUInt32(ctx, &tmpIndex));  // indices are [u32]
    }
    return parser_ok;
}

/**
 * @brief Reads Merkle lemmas from the parser context.
 *
 * @param ctx The parser context.
 * @param lemmas The Merkle lemmas to be read.
 * @return parser_error_t Returns parser_ok on success, otherwise an error code.
 */
static parser_error_t readMerkleLemmas(parser_context_t *ctx, MerkleLemmas_t *lemmas) {
    if (ctx == NULL || lemmas == NULL) {
        return parser_no_data;
    }

    CHECK_ERROR(readCompactU32(ctx, &lemmas->entries));

    lemmas->lemmas.buffer = ctx->buffer + ctx->offset;
    lemmas->lemmas.offset = 0;
    lemmas->lemmas.bufferLen = 32 * lemmas->entries;
    for (uint32_t idx = 0; idx < lemmas->entries; idx++) {
        CTX_CHECK_AND_ADVANCE(ctx, 32);  // lemmas are [u8;32]
    }
    return parser_ok;
}

/**
 * @brief Reads a SignedExtension from the parser context.
 *
 * @param ctx The parser context.
 * @param extension The SignedExtension to be read.
 * @return parser_error_t Returns parser_ok on success, otherwise an error code.
 */
parser_error_t readSignedExtension(parser_context_t *ctx, SignedExtension_t *extension) {
    CHECK_INPUT(extension);

    CHECK_ERROR(readBytes(ctx, &extension->identifier));
    CHECK_ERROR(readTypeRef(ctx, &extension->includedInExtrinsic));
    CHECK_ERROR(readTypeRef(ctx, &extension->includedInSignedData));
    return parser_ok;
}

/**
 * @brief Checks if a keyword exists in a given path.
 *
 * @param path The path to be checked.
 * @param keyword The keyword to search for.
 * @param found Pointer to a boolean that will be set to true if the keyword is found, otherwise false.
 * @return parser_error_t Returns parser_ok on success, otherwise an error code.
 */
parser_error_t checkPathKeyword(Vector_t *path, const char *keyword, bool *found) {
    if (path == NULL || keyword == NULL || found == NULL) {
        return parser_no_data;
    }

    // Keyword must end with null terminator
    const uint32_t keywordLen = strlen(keyword);
    *found = false;
    path->ctx.offset = 0;
    for (uint32_t i = 0; i < path->len; i++) {
        Bytes_t pathEntry = {0};
        CHECK_ERROR(readBytes(&path->ctx, &pathEntry));
        if (pathEntry.len == keywordLen && strncmp((const char *)pathEntry.ptr, keyword, keywordLen) == 0) {
            *found = true;
            break;
        }
    }
    return parser_ok;
}

/**
 * @brief Reads the extrinsic metadata from the parser context.
 *
 * @param ctx The parser context.
 * @param extrinsic The ExtrinsicMetadata to be read.
 * @return parser_error_t Returns parser_ok on success, otherwise an error code.
 */
static parser_error_t readExtrinsicMetadata(parser_context_t *ctx, ExtrinsicMetadata_t *extrinsic) {
    CHECK_INPUT(extrinsic);

    const uint16_t initialOffset = ctx->offset;
    extrinsic->ctx.buffer = ctx->buffer + initialOffset;
    extrinsic->ctx.offset = 0;
    CHECK_ERROR(_readUInt8(ctx, &extrinsic->version));

    CHECK_ERROR(readTypeRef(ctx, &extrinsic->addressType));
    CHECK_ERROR(readTypeRef(ctx, &extrinsic->callType));
    CHECK_ERROR(readTypeRef(ctx, &extrinsic->signatureType));

    CHECK_ERROR(readCompactU32(ctx, &extrinsic->signedExtensions.len));
    const uint16_t sigExtInitialOffset = ctx->offset;
    extrinsic->signedExtensions.ctx.buffer = ctx->buffer + sigExtInitialOffset;
    extrinsic->signedExtensions.ctx.offset = 0;

    SignedExtension_t extension = {0};
    for (uint32_t i = 0; i < extrinsic->signedExtensions.len; i++) {
        CHECK_ERROR(readSignedExtension(ctx, &extension));
    }
    extrinsic->signedExtensions.ctx.bufferLen = ctx->offset - sigExtInitialOffset;
    extrinsic->ctx.bufferLen = ctx->offset - initialOffset;
    return parser_ok;
}

/**
 * @brief Reads the extra information from the parser context.
 *
 * @param ctx The parser context.
 * @param extraInfo The ExtraInfo to be read.
 * @return parser_error_t Returns parser_ok on success, otherwise an error code.
 */
static parser_error_t readExtraInfo(parser_context_t *ctx, ExtraInfo_t *extraInfo) {
    CHECK_INPUT(extraInfo);

    const uint16_t initialOffset = ctx->offset;
    extraInfo->ctx.buffer = ctx->buffer + initialOffset;
    CHECK_ERROR(_readUInt32(ctx, &extraInfo->specVersion));
    CHECK_ERROR(readBytes(ctx, &extraInfo->specName));
    CHECK_ERROR(_readUInt16(ctx, &extraInfo->base58prefix));
    CHECK_ERROR(_readUInt8(ctx, &extraInfo->decimals));
    CHECK_ERROR(readBytes(ctx, &extraInfo->unit));
    extraInfo->ctx.bufferLen = ctx->offset - initialOffset;
    return parser_ok;
}

/**
 * @brief Reads the metadata context from the beginning and returns the requested typeId.
 *
 * @param ctx The parser context.
 * @param type The RegistryEntry to be read.
 * @param typeId The typeId to be searched.
 * @return parser_error_t Returns parser_ok on success, otherwise an error code.
 */
parser_error_t getType(parser_context_t *ctx, RegistryEntry_t *type, uint32_t typeId) {
    if (ctx == NULL || type == NULL) {
        return parser_no_data;
    }

    // Reset offset to start from the beginning
    ctx->offset = 0;

    uint32_t entries = 0;
    CHECK_ERROR(readCompactU32(ctx, &entries));
    for (uint32_t idx = 0; idx < entries; idx++) {
        CHECK_ERROR(readType(ctx, type));
        if (type->typeId == typeId) {
            return parser_ok;
        }
    }
    return parser_unexpected_buffer_end;
}

/**
 * @brief Reads the metadata context from the beginning and returns the requested variant.
 *
 * @param ctx The parser context.
 * @param type The RegistryEntry to be read.
 * @param typeId The typeId to be searched.
 * @param index The index of the variant to be searched.
 * @return parser_error_t Returns parser_ok on success, otherwise an error code.
 */
parser_error_t getVariant(parser_context_t *ctx, RegistryEntry_t *type, uint32_t typeId, uint8_t index) {
    if (ctx == NULL || type == NULL) {
        return parser_no_data;
    }

    // Reset offset to start from the beginning
    ctx->offset = 0;

    uint32_t entries = 0;
    CHECK_ERROR(readCompactU32(ctx, &entries));
    for (uint32_t idx = 0; idx < entries; idx++) {
        CHECK_ERROR(readType(ctx, type));
        if (type->kind == Enumeration && type->typeId == typeId && type->enumeration.index == index) {
            return parser_ok;
        }
    }
    return parser_unexpected_buffer_end;
}

parser_error_t metadata_read(parser_tx_t *txObj) {
    if (txObj == NULL) {
        return parser_no_data;
    }

    // We need to read this struct
    //  pub struct MetadataProof {
    //     proof: Proof,
    //     extrinsic: ExtrinsicMetadata<PortableForm>,
    //     extra_info: ExtraInfo,
    //  }

    // Where Proof is
    //  pub struct Proof {
    //     pub leaves: Vec<Type>,       --> ShortRegistry (short metadata)
    //     pub leaf_indices: Vec<u32>,  --> Used entries
    //     pub nodes: Vec<Hash>,        --> Lemmas
    //  }

    parser_context_t *metadata = &txObj->metadata.metadataBuf;
    ShortMetadata_t *shortMetadata = &txObj->metadata.shortMetadata;

    // Short registry (metadata) is called leaves
    CHECK_ERROR(readShortRegistry(metadata, &shortMetadata->shortRegistry));
    CHECK_ERROR(readMerkleIndices(metadata, &shortMetadata->indices));
    CHECK_ERROR(readMerkleLemmas(metadata, &shortMetadata->lemmas));

    CHECK_ERROR(readExtrinsicMetadata(metadata, &shortMetadata->extrinsic));
    CHECK_ERROR(readExtraInfo(metadata, &shortMetadata->extraInfo));

    if (metadata->offset < metadata->bufferLen) {
        return parser_unexpected_unparsed_bytes;
    }

    if (metadata->offset > metadata->bufferLen) {
        return parser_unexpected_buffer_end;
    }

    return parser_ok;
}
