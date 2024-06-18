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

#include "parser_impl.h"

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <zxformat.h>
#include <zxmacros.h>

#include "bignum.h"
#include "coin.h"
#include "crypto_helper.h"
#include "metadata_parser.h"
#include "metadata_reader.h"
#include "metadata_types.h"
#include "parser_common.h"
#include "parser_strings.h"
#include "parser_txdef.h"
#include "scale_helper.h"
#include "substrate_types.h"

/**
 * @brief Parses a transaction object.
 *
 * @param txObj Pointer to the transaction object to be parsed.
 * @return parser_error_t Returns parser_ok if parsing is successful, otherwise returns an error code.
 */
parser_error_t transaction_parse(parser_tx_t *txObj) {
    if (txObj == NULL) {
        return parser_no_data;
    }

    // Shortcuts
    Blob_t *blob = &txObj->blob;
    Metadata_t *metadata = &txObj->metadata;
    parser_context_t *blobBuf = &blob->blobBuf;
    parser_context_t *metadataBuf = &metadata->metadataBuf;

    // Parse the transaction blob according to short metadata
    CHECK_ERROR(getType(metadataBuf, &metadata->palletEntry, metadata->shortMetadata.extrinsic.callType.byId));
    if (metadata->palletEntry.kind != Enumeration) {
        return parser_unexpected_value;
    }

    //---------------------------------
    // Read transaction fields
    RegistryEntry_t tmpEntry = {0};
    PrintItem_t printItem = {0};
    CHECK_ERROR(parseMetadataEntry(blobBuf, metadataBuf, metadata->palletEntry.typeId, &tmpEntry, &printItem));
    txObj->blob.totalMethodItems = printItem.itemCount;

    //---------------------------------
    // Read signed extensions
    SignedExtension_t tmpExtension = {0};

    printItem.itemCount = 0;
    metadata->shortMetadata.extrinsic.signedExtensions.ctx.offset = 0;

    // We need to iterate over the signed extension twice
    blob->sigExtStartOffset = blobBuf->offset;
    for (uint32_t i = 0; i < metadata->shortMetadata.extrinsic.signedExtensions.len; i++) {
        CHECK_ERROR(readSignedExtension(&metadata->shortMetadata.extrinsic.signedExtensions.ctx, &tmpExtension));
        const uint8_t initialItemCount = printItem.itemCount;
        const uint16_t initialOffset = blobBuf->offset;

        bool hasTip = false;
        const uint64_t identifierLen = tmpExtension.identifier.len;
        // we have custom logic for Era
        if (identifierLen == strlen(STR_ERA) &&
            strncmp((const char *)tmpExtension.identifier.ptr, STR_ERA, identifierLen) == 0) {
            pd_ExtrinsicEra_t tmpEra = {0};
            CHECK_ERROR(_readEra(blobBuf, &tmpEra));
            printItem.itemCount += tmpEra.isMortal ? 3 : 1;
            continue;
        }

        // Extract Mode if present
        if (identifierLen == strlen(STR_METADATA_HASH) &&
            strncmp((const char *)tmpExtension.identifier.ptr, STR_METADATA_HASH, identifierLen) == 0) {

            // The following byte must be 0x01
            if(*(blobBuf->buffer + blobBuf->offset)!= 0x01) {
                return parser_wrong_metadata_digest;
            }

            PrintItem_t tmpPrintItem = {0};
            tmpPrintItem.printing = true;
            tmpPrintItem.target = 1;
            tmpPrintItem.itemCount = 0;
            const uint16_t tmpBlobOffset = blobBuf->offset;
            CHECK_ERROR(parseTypeRef(blobBuf, metadataBuf, &tmpEntry, &tmpExtension.includedInExtrinsic, &tmpPrintItem));

            // Check that Mode is enabled
            if (tmpPrintItem.item.val.len != strlen(STR_MODE_ENABLED) || strncmp((const char *)tmpPrintItem.item.val.ptr, STR_MODE_ENABLED, tmpPrintItem.item.val.len) != 0) {
                return parser_wrong_metadata_digest;
            }
            blobBuf->offset = tmpBlobOffset;
        }
        CHECK_ERROR(parseTypeRef(blobBuf, metadataBuf, &tmpEntry, &tmpExtension.includedInExtrinsic, &printItem));

        // first case is tip without assetid, second case is tip with assetid
        // both cases start with Compact<u128> as tip
        // we want to show it also if expert mode is disabled if tip != 0
        if (strncmp((const char *)tmpExtension.identifier.ptr, STR_TIP, tmpExtension.identifier.len) == 0 ||
            strncmp((const char *)tmpExtension.identifier.ptr, STR_TIP_WITH_ASSETID, tmpExtension.identifier.len) == 0) {
            CHECK_ERROR(getType(metadataBuf, &tmpEntry, tmpExtension.includedInExtrinsic.byId));
            if (tmpEntry.kind == Composite) {
                Field_t entry = {0};
                parser_context_t fields = tmpEntry.composite.ctx;
                fields.offset = 0;
                CHECK_ERROR(readField(&fields, &entry));
                if (entry.type.index >= CompactU8 && entry.type.index <= CompactU256) {
                    parser_context_t tmpBlob = *blobBuf;
                    tmpBlob.offset = initialOffset;
                    CompactInt_t tmpCompact = {0};
                    CHECK_ERROR(readCompactInt(&tmpBlob, &tmpCompact));
                    if (tmpCompact.len != 1 || *tmpCompact.ptr != 0) {
                        hasTip = true;
                    }
                }
            }
        }
        if (hasTip) {
            txObj->blob.tipItems = printItem.itemCount - initialItemCount;
        }
    }

    metadata->shortMetadata.extrinsic.signedExtensions.ctx.offset = 0;
    for (uint32_t i = 0; i < metadata->shortMetadata.extrinsic.signedExtensions.len; i++) {
        CHECK_ERROR(readSignedExtension(&metadata->shortMetadata.extrinsic.signedExtensions.ctx, &tmpExtension));

        const uint64_t identifierLen = tmpExtension.identifier.len;
        // Extract CheckMetadataHash if present
        if (identifierLen == strlen(STR_METADATA_HASH) &&
            strncmp((const char *)tmpExtension.identifier.ptr, STR_METADATA_HASH, identifierLen) == 0) {
            PrintItem_t tmpPrintItem = {0};
            tmpPrintItem.printing = true;
            tmpPrintItem.target = 1;
            tmpPrintItem.itemCount = 0;
            const uint16_t tmpBlobOffset = blobBuf->offset;
            CHECK_ERROR(parseTypeRef(blobBuf, metadataBuf, &tmpEntry, &tmpExtension.includedInSignedData, &tmpPrintItem));

            txObj->checkMetadataDigest.hasBytes = true;
            txObj->checkMetadataDigest.bytes.ptr = tmpPrintItem.item.val.ptr;
            txObj->checkMetadataDigest.bytes.len = tmpPrintItem.item.val.len;

            blobBuf->offset = tmpBlobOffset;
        }
        CHECK_ERROR(parseTypeRef(blobBuf, metadataBuf, &tmpEntry, &tmpExtension.includedInSignedData, &printItem));
    }

    txObj->blob.totalSigExtItems = printItem.itemCount;

    if (blobBuf->offset < blobBuf->bufferLen) {
        return parser_unexpected_unparsed_bytes;
    }

    if (blobBuf->offset > blobBuf->bufferLen) {
        return parser_unexpected_buffer_end;
    }

    return parser_ok;
}

/**
 * @brief Verifies the metadata of a transaction object.
 *
 * @param txObj Pointer to the transaction object whose metadata is to be verified.
 * @return parser_error_t Returns parser_ok if verification is successful, otherwise returns an error code.
 */
parser_error_t verifyMetadata(parser_tx_t *txObj) {
    if (txObj == NULL) {
        return parser_no_data;
    }

    // CheckMetadataHash must be present and its length must be 32 bytes
    if (!txObj->checkMetadataDigest.hasBytes || txObj->checkMetadataDigest.bytes.len != BLAKE3_OUT_LEN) {
        return parser_wrong_metadata_digest;
    }

    // Perform comparison between local computed digest and the one from the signed extension
    return (memcmp(txObj->metadataDigest, txObj->checkMetadataDigest.bytes.ptr, BLAKE3_OUT_LEN) == 0)
               ? parser_ok
               : parser_wrong_metadata_digest;
}
