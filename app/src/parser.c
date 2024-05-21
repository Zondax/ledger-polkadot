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
#include "parser.h"

#include <stdio.h>

#include "app_mode.h"
#include "bignum.h"
#include "metadata_parser.h"
#include "metadata_proof.h"
#include "metadata_reader.h"
#include "parser_common.h"
#include "parser_impl.h"
#include "parser_print.h"
#include "parser_strings.h"
#include "scale_helper.h"
#include "view.h"

#define TMP_BUFFER_SIZE 39U

static parser_error_t parser_init(parser_tx_t *txObj, const uint8_t *inputBuffer, uint16_t bufferLen, uint16_t blobLen) {
    if (txObj == NULL || inputBuffer == NULL || bufferLen < blobLen || bufferLen == 0) {
        return parser_init_context_empty;
    }

    MEMZERO(txObj, sizeof(*txObj));

    txObj->blob.blobBuf.buffer = inputBuffer;
    txObj->blob.blobBuf.bufferLen = blobLen;
    txObj->metadata.metadataBuf.buffer = inputBuffer + blobLen;
    txObj->metadata.metadataBuf.bufferLen = bufferLen - blobLen;
    txObj->checkMetadataDigest.hasBytes = false;

    return parser_ok;
}

parser_error_t parser_parse(parser_tx_t *txObj, const uint8_t *inputBuffer, uint16_t bufferLen, uint16_t blobLen) {
    // Initialize txObj with input params
    CHECK_ERROR(parser_init(txObj, inputBuffer, bufferLen, blobLen));

    // Parse metadata
    CHECK_ERROR(metadata_read(txObj));

    // Get root hash
    CHECK_ERROR(getMetadataDigest(&txObj->metadata, txObj->metadataDigest));

    // Parse transaction blob
    CHECK_ERROR(transaction_parse(txObj));

    // Verify that the used metadata is good
    CHECK_ERROR(verifyMetadata(txObj));

    return parser_ok;
}

parser_error_t parser_validate(parser_tx_t *txObj) {
    uint8_t numItems = 0;
    CHECK_ERROR(parser_getNumItems(txObj, &numItems));

    // These temporal buffers won't be used to display the information.
    // This step will verify that every element can be retrieved
    char tmpKey[TMP_BUFFER_SIZE] = {0};
    char tmpVal[TMP_BUFFER_SIZE] = {0};
    uint8_t pageCount = 0;

    ui_field_t uiFields = {.displayIdx = 0,
                           .outKey = tmpKey,
                           .outKeyLen = sizeof(tmpKey),
                           .outVal = tmpVal,
                           .outValLen = sizeof(tmpVal),
                           .pageIdx = 0,
                           .pageCount = &pageCount};

    // Iterate through all items to check that all can be shown and are valid
    for (uint8_t idx = 0; idx < numItems; idx++) {
        uiFields.displayIdx = idx;
        CHECK_ERROR(parser_getItem(txObj, &uiFields));
    }

    return parser_ok;
}

parser_error_t parser_getNumItems(parser_tx_t *txObj, uint8_t *numItems) {
    if (txObj == NULL || numItems == NULL) {
        return parser_no_data;
    }

    // if we're in normal mode we want to show only method items + tip (if exists)
    // if we're in expert mode we want to show everything
    uint16_t items = txObj->blob.totalMethodItems;
    items++;  // chain name
    items += app_mode_expert() ? txObj->blob.totalSigExtItems : txObj->blob.tipItems;

    if (items > UINT8_MAX) {
        return parser_value_out_of_range;
    }
    *numItems = (uint8_t)items;

    return parser_ok;
}

parser_error_t parser_getItem(parser_tx_t *txObj, ui_field_t *uiFields) {
    MEMZERO(uiFields->outKey, uiFields->outKeyLen);
    MEMZERO(uiFields->outVal, uiFields->outValLen);
    snprintf(uiFields->outKey, uiFields->outKeyLen, "?");
    snprintf(uiFields->outVal, uiFields->outValLen, "?");
    *uiFields->pageCount = 1;

    uint8_t numItems = 0;
    CHECK_ERROR(parser_getNumItems(txObj, &numItems));
    CHECK_APP_CANARY()

    if (uiFields->displayIdx >= numItems) {
        return parser_no_data;
    }

    if (uiFields->displayIdx == 0) {
        snprintf(uiFields->outKey, uiFields->outKeyLen, "Chain");
        snprintf(uiFields->outVal, uiFields->outValLen, "%.*s", (int)txObj->metadata.shortMetadata.extraInfo.specName.len,
                 txObj->metadata.shortMetadata.extraInfo.specName.ptr);
        return parser_ok;
    }

    RegistryEntry_t tmpEntry = {0};
    PrintItem_t printItem = {0};
    printItem.base58prefix = txObj->metadata.shortMetadata.extraInfo.base58prefix;
    printItem.decimals = txObj->metadata.shortMetadata.extraInfo.decimals;
    printItem.unit = txObj->metadata.shortMetadata.extraInfo.unit;
    printItem.printing = true;

    parser_context_t *blobBuf = &txObj->blob.blobBuf;
    parser_context_t *metadataBuf = &txObj->metadata.metadataBuf;

    if (uiFields->displayIdx <= txObj->blob.totalMethodItems) {
        // we need to reset blob offset to continue
        blobBuf->offset = 0;
        printItem.target = uiFields->displayIdx;

        CHECK_ERROR(parseMetadataEntry(blobBuf, metadataBuf, txObj->metadata.palletEntry.typeId, &tmpEntry, &printItem));
        snprintf(uiFields->outKey, uiFields->outKeyLen, "%.*s", (int)printItem.item.key.len, printItem.item.key.ptr);
        CHECK_ERROR(printGenericItem(uiFields, &printItem));
        return parser_ok;
    }

    printItem.target = uiFields->displayIdx - txObj->blob.totalMethodItems;
    blobBuf->offset = txObj->blob.sigExtStartOffset;
    const uint32_t sigExtEntries = txObj->metadata.shortMetadata.extrinsic.signedExtensions.len;
    parser_context_t *signedExtensions = &txObj->metadata.shortMetadata.extrinsic.signedExtensions.ctx;
    signedExtensions->offset = 0;
    SignedExtension_t tmpExtension = {0};

    if (app_mode_expert()) {
        for (uint32_t i = 0; i < sigExtEntries; i++) {
            CHECK_ERROR(readSignedExtension(signedExtensions, &tmpExtension));

            // we have custom logic for Era
            if (strncmp((const char *)tmpExtension.identifier.ptr, STR_ERA, tmpExtension.identifier.len) == 0) {
                pd_ExtrinsicEra_t tmpEra = {0};
                CHECK_ERROR(_readEra(blobBuf, &tmpEra));

                if (printItem.itemCount + 1 == printItem.target) {
                    snprintf(uiFields->outKey, uiFields->outKeyLen, "Mortality");
                    snprintf(uiFields->outVal, uiFields->outValLen, tmpEra.isMortal ? "Mortal" : "Immortal");
                    return parser_ok;
                }

                if (tmpEra.isMortal) {
                    if (printItem.itemCount + 2 == printItem.target) {
                        snprintf(uiFields->outKey, uiFields->outKeyLen, "Era Period");
                        snprintf(uiFields->outVal, uiFields->outValLen, "%d", tmpEra.period);
                        return parser_ok;
                    }

                    if (printItem.itemCount + 3 == printItem.target) {
                        snprintf(uiFields->outKey, uiFields->outKeyLen, "Era Phase");
                        snprintf(uiFields->outVal, uiFields->outValLen, "%d", tmpEra.phase);
                        return parser_ok;
                    }
                }

                printItem.itemCount += tmpEra.isMortal ? 3 : 1;
                continue;
            }

            CHECK_ERROR(parseTypeRef(blobBuf, metadataBuf, &tmpEntry, &tmpExtension.includedInExtrinsic, &printItem));

            if (printItem.itemCount == printItem.target && printItem.item.valEnc != EncNoEncoding) {
                if (strncmp((const char *)tmpExtension.identifier.ptr, STR_TIP, tmpExtension.identifier.len) == 0) {
                    snprintf(uiFields->outKey, uiFields->outKeyLen, "Tip");
                } else if (strncmp((const char *)tmpExtension.identifier.ptr, STR_TIP_WITH_ASSETID,
                                   tmpExtension.identifier.len) == 0) {
                    snprintf(uiFields->outKey, uiFields->outKeyLen, "Tip");

                    if (printItem.item.valEnc == EncBalance) {
                        printItem.item.valEnc = EncUnsigned;
                    } else if (printItem.item.valEnc == EncCompactBalance) {
                        printItem.item.valEnc = EncCompact;
                    } else {
                        // here we're on AssetId part
                        snprintf(uiFields->outKey, uiFields->outKeyLen, "Tip Asset Id");
                    }
                } else {
                    snprintf(uiFields->outKey, uiFields->outKeyLen, "%.*s", (int)tmpExtension.identifier.len,
                             tmpExtension.identifier.ptr);
                }

                CHECK_ERROR(printGenericItem(uiFields, &printItem));
                return parser_ok;
            }
        }

        signedExtensions->offset = 0;

        for (uint32_t i = 0; i < sigExtEntries; i++) {
            printItem.item.valEnc = EncNoEncoding;
            CHECK_ERROR(readSignedExtension(signedExtensions, &tmpExtension));
            CHECK_ERROR(parseTypeRef(blobBuf, metadataBuf, &tmpEntry, &tmpExtension.includedInSignedData, &printItem));

            if (printItem.itemCount == printItem.target && printItem.item.valEnc != EncNoEncoding) {
                // we have custom title in case of era and tip
                if (strncmp((const char *)tmpExtension.identifier.ptr, STR_ERA, tmpExtension.identifier.len) == 0) {
                    snprintf(uiFields->outKey, uiFields->outKeyLen, "Mortality Block");
                } else {
                    snprintf(uiFields->outKey, uiFields->outKeyLen, "%.*s", (int)tmpExtension.identifier.len,
                             tmpExtension.identifier.ptr);
                }

                CHECK_ERROR(printGenericItem(uiFields, &printItem));
                return parser_ok;
            }
        }
    } else {  // only print tip
        for (uint32_t i = 0; i < sigExtEntries; i++) {
            printItem.printing = false;
            CHECK_ERROR(readSignedExtension(signedExtensions, &tmpExtension));

            if (strncmp((const char *)tmpExtension.identifier.ptr, STR_TIP, tmpExtension.identifier.len) == 0 ||
                strncmp((const char *)tmpExtension.identifier.ptr, STR_TIP_WITH_ASSETID, tmpExtension.identifier.len) == 0) {
                printItem.printing = true;
                printItem.itemCount = 0;
            }

            CHECK_ERROR(parseTypeRef(blobBuf, metadataBuf, &tmpEntry, &tmpExtension.includedInExtrinsic, &printItem));

            if (printItem.printing && printItem.itemCount == printItem.target && printItem.item.valEnc != EncNoEncoding) {
                snprintf(uiFields->outKey, uiFields->outKeyLen, "Tip");

                if (strncmp((const char *)tmpExtension.identifier.ptr, STR_TIP_WITH_ASSETID, tmpExtension.identifier.len) ==
                    0) {
                    if (printItem.item.valEnc == EncBalance) {
                        printItem.item.valEnc = EncUnsigned;
                    } else if (printItem.item.valEnc == EncCompactBalance) {
                        printItem.item.valEnc = EncCompact;
                    } else {
                        // here we're on AssetId part
                        snprintf(uiFields->outKey, uiFields->outKeyLen, "Tip Asset Id");
                    }
                }

                CHECK_ERROR(printGenericItem(uiFields, &printItem));
                return parser_ok;
            }
        }
    }

    return parser_no_data;
}
