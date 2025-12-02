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

#include "metadata_parser.h"

#include <stddef.h>
#include <stdint.h>

#include "metadata_reader.h"
#include "metadata_types.h"
#include "parser_common.h"
#include "parser_impl.h"
#include "scale_helper.h"
#include "substrate_types.h"
#include "zxmacros.h"

// List of pallets that handle non-native tokens
// These pallets have their own asset registries with custom decimals/symbols
static const char *const rawBalancePallets[] = {
    "Assets",  // pallet-assets: fungible tokens
};

static const size_t rawBalancePalletsLen = sizeof(rawBalancePallets) / sizeof(rawBalancePallets[0]);

/**
 * @brief Check if the current pallet should skip balance formatting.
 *
 * Some pallets like Assets handle tokens with their own decimals and symbols
 * that are stored on-chain and not available in the transaction metadata.
 * For these pallets, we should display raw values instead of applying
 * the native token's formatting.
 *
 * @param printItem Pointer to the print item containing the pallet context.
 * @return bool True if balance formatting should be skipped.
 */
static bool shouldSkipBalanceFormatting(const PrintItem_t *printItem) {
    if (printItem == NULL || printItem->palletName.ptr == NULL || printItem->palletName.len == 0) {
        return false;
    }

    for (size_t i = 0; i < rawBalancePalletsLen; i++) {
        const char *pallet = PIC(rawBalancePallets[i]);
        if (printItem->palletName.len == strlen(pallet) &&
            strncmp((const char *)printItem->palletName.ptr, pallet, printItem->palletName.len) == 0) {
            return true;
        }
    }

    return false;
}

/**
 * @brief Check and update the balance encoding for a given field.
 *
 * @param field Pointer to the field to check.
 * @param printItem Pointer to the print item to update.
 * @return parser_error_t Error code indicating the result of the operation.
 */
static parser_error_t checkBalanceEncoding(Field_t *field, PrintItem_t *printItem) {
    // Array of balance type strings
    const char *balanceTypes[] = {"Balance",         "BalanceOf<T>",       "BalanceOf<T, I>", "DepositBalance",
                                  "ExtendedBalance", "PalletBalanceOf<T>", "T::Balance"};

    if (field == NULL) {
        return parser_error_dummy;
    }

    if (!field->typeName.hasBytes) {
        return parser_ok;
    }

    // Check if we should skip balance formatting for pallets that handle non-native tokens
    // These tokens have their own decimals/symbols stored on-chain
    const bool skipFormatting = shouldSkipBalanceFormatting(printItem);

    // If the typeName matches, and it's an uint/compact integer ==> parse as balance
    // At least typeName len needs to be 7
    for (size_t i = 0; i < sizeof(balanceTypes) / sizeof(PIC(balanceTypes[0])); i++) {
        if (field->typeName.bytes.len == strlen(PIC(balanceTypes[i])) &&
            strncmp((char *)field->typeName.bytes.ptr, PIC(balanceTypes[i]), field->typeName.bytes.len) == 0) {
            if (skipFormatting) {
                // Mark as raw balance so the UI shows "[raw]" indicator
                if (printItem->item.valEnc == EncCompact) {
                    printItem->item.valEnc = EncCompactRawBalance;
                } else if (printItem->item.valEnc == EncUnsigned) {
                    printItem->item.valEnc = EncRawBalance;
                }
            } else {
                if (printItem->item.valEnc == EncCompact) {
                    printItem->item.valEnc = EncCompactBalance;
                } else if (printItem->item.valEnc == EncUnsigned) {
                    printItem->item.valEnc = EncBalance;
                }
            }
            break;
        }
    }

    return parser_ok;
}

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
                            PrintItem_t *printItem) {
    if (blob == NULL || metadata == NULL || tmpEntry == NULL || type == NULL || printItem == NULL) {
        return parser_no_data;
    }

    if (type->index != Void && type->index != ById) {
        printItem->itemCount++;
    }

    if (printItem->printing && printItem->target == printItem->itemCount) {
        printItem->item.val.ptr = blob->buffer + blob->offset;

        switch (type->index) {
            case U8:
            case U16:
            case U32:
            case U64:
            case U128:
            case U256:
                printItem->item.valEnc = EncUnsigned;
                break;
            case I8:
            case I16:
            case I32:
            case I64:
            case I128:
            case I256:
                printItem->item.valEnc = EncSigned;
                break;
            case Char:
            case String:
                printItem->item.valEnc = EncString;
                break;
            case Bool:
                printItem->item.valEnc = EncBool;
                break;
            default:
                // Handle unexpected type index if necessary
                break;
        }
    }

    switch (type->index) {
        case Void:
            // Nothing to read here
            break;
        case Bool:
        case Char:
        case U8:
        case I8:
            CTX_CHECK_AND_ADVANCE(blob, 1);
            printItem->item.val.len = 1;
            break;
        case U16:
        case I16:
            CTX_CHECK_AND_ADVANCE(blob, 2);
            printItem->item.val.len = 2;
            break;
        case U32:
        case I32:
            CTX_CHECK_AND_ADVANCE(blob, 4);
            printItem->item.val.len = 4;
            break;
        case U64:
        case I64:
            CTX_CHECK_AND_ADVANCE(blob, 8);
            printItem->item.val.len = 8;
            break;
        case U128:
        case I128:
            CTX_CHECK_AND_ADVANCE(blob, 16);
            printItem->item.val.len = 16;
            break;
        case U256:
        case I256:
            CTX_CHECK_AND_ADVANCE(blob, 32);
            printItem->item.val.len = 32;
            break;
        case CompactU8:
        case CompactU16:
        case CompactU32:
        case CompactU64:
        case CompactU128:
        case CompactU256: {
            CompactInt_t tmpCompact = {0};
            CHECK_ERROR(readCompactInt(blob, &tmpCompact));
            if (printItem->printing && printItem->target == printItem->itemCount) {
                printItem->item.val.ptr = tmpCompact.ptr;
                printItem->item.val.len = tmpCompact.len;
                printItem->item.valEnc = EncCompact;
            }
            break;
        }
        case ById:
            CHECK_ERROR(parseMetadataEntry(blob, metadata, type->byId, tmpEntry, printItem));
            break;
        case String:
        default:
            // At the moment, the app doesn't support these types
            return parser_unexpected_value;
    }

    return parser_ok;
}

/**
 * @brief Parse a composite type and update the print item accordingly.
 *
 * @param blob Pointer to the parser context for the blob.
 * @param metadata Pointer to the parser context for the metadata.
 * @param tmpEntry Pointer to the temporary registry entry.
 * @param printItem Pointer to the print item to update.
 * @return parser_error_t Error code indicating the result of the operation.
 */
static parser_error_t parseCompositeType(parser_context_t *blob,
                                         parser_context_t *metadata,
                                         RegistryEntry_t *tmpEntry,
                                         PrintItem_t *printItem) {
    if (metadata == NULL || blob == NULL || tmpEntry == NULL || printItem == NULL) {
        return parser_no_data;
    }

    if (tmpEntry->kind != Composite) {
        return parser_unexpected_value;
    }

    const uint32_t fieldsLen = tmpEntry->composite.len;
    parser_context_t fields = {.buffer = tmpEntry->composite.ctx.buffer,
                               .bufferLen = tmpEntry->composite.ctx.bufferLen,
                               .offset = 0};

    Field_t entry = {0};
    bool isAccountId = false;
    CHECK_ERROR(checkPathKeyword(&tmpEntry->path, ACCOUNTID32_ID_STR, &isAccountId));
    bool isVote = false;
    CHECK_ERROR(checkPathKeyword(&tmpEntry->path, VOTE_ID_STR, &isVote));

    for (uint32_t i = 0; i < fieldsLen; i++) {
        CHECK_ERROR(readField(&fields, &entry));
        CHECK_ERROR(parseTypeRef(blob, metadata, tmpEntry, &entry.type, printItem))

        if (printItem->printing && printItem->target == printItem->itemCount) {
            // Given this case we know it's an address, and not a regular hexstring
            if (isAccountId && printItem->item.valEnc == EncHexString && printItem->item.val.len == 32) {
                printItem->item.valEnc = EncAddress;
                return parser_ok;
            }
            if (isVote && printItem->item.valEnc == EncUnsigned && printItem->item.val.len == 1) {
                printItem->item.valEnc = EncVote;
                return parser_ok;
            }
            CHECK_ERROR(checkBalanceEncoding(&entry, printItem));
            return parser_ok;
        }
    }

    return parser_ok;
}

/**
 * @brief Parse an enumeration variant type and update the print item accordingly.
 *
 * @param blob Pointer to the parser context for the blob.
 * @param metadata Pointer to the parser context for the metadata.
 * @param tmpEntry Pointer to the temporary registry entry.
 * @param printItem Pointer to the print item to update.
 * @return parser_error_t Error code indicating the result of the operation.
 */
static parser_error_t parseEnumerationVariantType(parser_context_t *blob,
                                                  parser_context_t *metadata,
                                                  RegistryEntry_t *tmpEntry,
                                                  PrintItem_t *printItem) {
    if (metadata == NULL || blob == NULL || tmpEntry == NULL || printItem == NULL) {
        return parser_no_data;
    }

    if (tmpEntry->kind != Enumeration) {
        return parser_value_out_of_range;
    }

    uint8_t variantIdx = 0;
    CHECK_ERROR(_readUInt8(blob, &variantIdx));
    if (tmpEntry->enumeration.index != variantIdx) {
        // Get the typeID with the correct variant index
        CHECK_ERROR(getVariant(metadata, tmpEntry, tmpEntry->typeId, variantIdx));
    }

    // RuntimeCall stands for pallet
    bool isPalletEntry = false;
    CHECK_ERROR(checkPathKeyword(&tmpEntry->path, PALLET_ID_STR, &isPalletEntry));

    // Some and Option won't be displayed to reduce screens
    // On the other hand, if the it's None, it will be displayed
    const bool isOption =
        (tmpEntry->enumeration.name.len == strlen(OPTION_ID_STR) &&
         strncmp((const char *)tmpEntry->enumeration.name.ptr, OPTION_ID_STR, tmpEntry->enumeration.name.len) == 0);
    const bool isSome =
        (tmpEntry->enumeration.name.len == strlen(SOME_ID_STR) &&
         strncmp((const char *)tmpEntry->enumeration.name.ptr, SOME_ID_STR, tmpEntry->enumeration.name.len) == 0);

    if (isPalletEntry) {
        // Store pallet name for context-aware formatting (e.g., skip balance formatting for Assets pallet)
        printItem->palletName = tmpEntry->enumeration.name;

        // We'll add the count in next iteration, in method
        if (printItem->printing && printItem->target == printItem->itemCount + 1) {
            printItem->item.key = tmpEntry->enumeration.name;
        }
    } else {
        if (!isOption && !isSome) {
            printItem->itemCount++;
            if (printItem->printing && printItem->target == printItem->itemCount) {
                printItem->item.val = tmpEntry->enumeration.name;
                printItem->item.valEnc = EncString;
                return parser_ok;
            }
        }
    }

    Field_t entry = {0};
    const uint32_t fieldsLen = tmpEntry->enumeration.fields.len;
    parser_context_t fieldsCtx = {.buffer = tmpEntry->enumeration.fields.ctx.buffer,
                                  .bufferLen = tmpEntry->enumeration.fields.ctx.bufferLen,
                                  .offset = 0};

    bool isCallEntry = false;
    CHECK_ERROR(checkPathKeyword(&tmpEntry->path, CALL_ID_STR, &isCallEntry));

    for (uint32_t i = 0; i < fieldsLen; i++) {
        CHECK_ERROR(readField(&fieldsCtx, &entry));

        // Add key for inner elements
        if (isCallEntry && entry.name.hasBytes) {
            printItem->item.key = entry.name.bytes;
        }

        CHECK_ERROR(parseTypeRef(blob, metadata, tmpEntry, &entry.type, printItem))

        if (printItem->printing && printItem->target == printItem->itemCount) {
            CHECK_ERROR(checkBalanceEncoding(&entry, printItem));
            return parser_ok;
        }
    }

    return parser_ok;
}

/**
 * @brief Parse a sequence type and update the print item accordingly.
 *
 * @param blob Pointer to the parser context for the blob.
 * @param metadata Pointer to the parser context for the metadata.
 * @param tmpEntry Pointer to the temporary registry entry.
 * @param printItem Pointer to the print item to update.
 * @return parser_error_t Error code indicating the result of the operation.
 */
static parser_error_t parseSequenceType(parser_context_t *blob,
                                        parser_context_t *metadata,
                                        RegistryEntry_t *tmpEntry,
                                        PrintItem_t *printItem) {
    if (blob == NULL || metadata == NULL || tmpEntry == NULL || printItem == NULL) {
        return parser_no_data;
    }

    if (tmpEntry->kind != Sequence) {
        return parser_value_out_of_range;
    }

    uint32_t sequenceLen = 0;
    CHECK_ERROR(readCompactU32(blob, &sequenceLen));
    TypeRef_t sequenceType = tmpEntry->sequence;
    if (sequenceLen == 0) {
        printItem->itemCount++;
        if (printItem->printing && printItem->target == printItem->itemCount) {
            printItem->item.valEnc = EncEmptyVec;
        }
        return parser_ok;
    }

    if (sequenceType.index == U8) {
        printItem->itemCount++;
        if (printItem->printing && printItem->target == printItem->itemCount) {
            printItem->item.valEnc = EncHexString;
            printItem->item.val.ptr = blob->buffer + blob->offset;
            printItem->item.val.len = (uint16_t)sequenceLen;
        }
        CTX_CHECK_AND_ADVANCE(blob, sequenceLen)
        return parser_ok;
    }

    for (uint32_t i = 0; i < sequenceLen; i++) {
        CHECK_ERROR(parseTypeRef(blob, metadata, tmpEntry, &sequenceType, printItem));
        if (printItem->printing && printItem->target == printItem->itemCount) {
            return parser_ok;
        }
    }

    return parser_ok;
}

/**
 * @brief Parse an array type and update the print item accordingly.
 *
 * @param blob Pointer to the parser context for the blob.
 * @param metadata Pointer to the parser context for the metadata.
 * @param tmpEntry Pointer to the temporary registry entry.
 * @param printItem Pointer to the print item to update.
 * @return parser_error_t Error code indicating the result of the operation.
 */
static parser_error_t parseArrayType(parser_context_t *blob,
                                     parser_context_t *metadata,
                                     RegistryEntry_t *tmpEntry,
                                     PrintItem_t *printItem) {
    if (blob == NULL || metadata == NULL || tmpEntry == NULL || printItem == NULL) {
        return parser_no_data;
    }

    if (tmpEntry->kind != Array) {
        return parser_value_out_of_range;
    }

    if (tmpEntry->array.len == 0) {
        return parser_ok;
    }

    const uint32_t arrLen = tmpEntry->array.len;
    const TypeRef_t arrType = tmpEntry->array.typeParam;
    if (arrType.index == U8) {
        printItem->itemCount++;
        if (printItem->printing && printItem->target == printItem->itemCount) {
            printItem->item.valEnc = EncHexString;
            printItem->item.val.ptr = blob->buffer + blob->offset;
            printItem->item.val.len = (uint16_t)arrLen;
        }
        CTX_CHECK_AND_ADVANCE(blob, arrLen)
        return parser_ok;
    }

    for (uint32_t i = 0; i < arrLen; i++) {
        CHECK_ERROR(parseTypeRef(blob, metadata, tmpEntry, &arrType, printItem));
        if (printItem->printing && printItem->target == printItem->itemCount) {
            return parser_ok;
        }
    }

    return parser_ok;
}

/**
 * @brief Parse a tuple type and update the print item accordingly.
 *
 * @param blob Pointer to the parser context for the blob.
 * @param metadata Pointer to the parser context for the metadata.
 * @param tmpEntry Pointer to the temporary registry entry.
 * @param printItem Pointer to the print item to update.
 * @return parser_error_t Error code indicating the result of the operation.
 */
static parser_error_t parseTupleType(parser_context_t *blob,
                                     parser_context_t *metadata,
                                     RegistryEntry_t *tmpEntry,
                                     PrintItem_t *printItem) {
    if (blob == NULL || metadata == NULL || tmpEntry == NULL || printItem == NULL) {
        return parser_no_data;
    }

    if (tmpEntry->kind != Tuple) {
        return parser_unexpected_value;
    }

    const uint32_t tupleLen = tmpEntry->tuple.len;
    parser_context_t tupleCtx = {.buffer = tmpEntry->tuple.ctx.buffer,
                                 .bufferLen = tmpEntry->tuple.ctx.bufferLen,
                                 .offset = 0};

    TypeRef_t type = {0};
    for (uint32_t i = 0; i < tupleLen; i++) {
        CHECK_ERROR(readTypeRef(&tupleCtx, &type));
        CHECK_ERROR(parseTypeRef(blob, metadata, tmpEntry, &type, printItem));

        if (printItem->printing && printItem->target == printItem->itemCount) {
            return parser_ok;
        }
    }

    return parser_ok;
}

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
    parser_context_t *blob, parser_context_t *metadata, uint32_t typeId, RegistryEntry_t *tmpEntry, PrintItem_t *printItem) {
    if (metadata == NULL || blob == NULL || tmpEntry == NULL || printItem == NULL) {
        return parser_no_data;
    }

    CHECK_ERROR(checkStack());
    MEMZERO(tmpEntry, sizeof(*tmpEntry));

    // Get the requested entry corresponding to typeId
    CHECK_ERROR(getType(metadata, tmpEntry, typeId));

    switch (tmpEntry->kind) {
        case Composite:
            CHECK_ERROR(parseCompositeType(blob, metadata, tmpEntry, printItem));
            break;
        case Enumeration:
            CHECK_ERROR(parseEnumerationVariantType(blob, metadata, tmpEntry, printItem));
            break;
        case Sequence:
            CHECK_ERROR(parseSequenceType(blob, metadata, tmpEntry, printItem));
            break;
        case Array:
            CHECK_ERROR(parseArrayType(blob, metadata, tmpEntry, printItem));
            break;
        case Tuple:
            CHECK_ERROR(parseTupleType(blob, metadata, tmpEntry, printItem));
            break;
        case BitSequenceType:
            // TODO: implement BitSequence
            return parser_value_out_of_range;

        default:
            return parser_value_out_of_range;
    }

    return freeStack();
}
