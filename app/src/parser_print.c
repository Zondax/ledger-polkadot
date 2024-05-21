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

#include "parser_print.h"

#include "bignum.h"
#include "crypto_helper.h"
#include "parser_strings.h"
#include "zxformat.h"

/**
 * @brief Prints an unsigned item.
 *
 * @param uiFields Pointer to the UI fields.
 * @param printItem Pointer to the print item.
 * @return parser_error_t Error code.
 */
static parser_error_t printUnsignedItem(ui_field_t *uiFields, PrintItem_t *printItem) {
    if (uiFields == NULL || printItem == NULL) {
        return parser_error_dummy;
    }

    char bufUi[100] = {0};

    // it's u8, u16, u32 or u64
    if (printItem->item.val.len <= 8) {
        uint64_t value = 0;
        for (uint8_t i = 0; i < (uint8_t)printItem->item.val.len; i++) {
            value += (uint64_t) * (printItem->item.val.ptr + i) << (8 * i);
        }
        const char *printReturn = uint64_to_str(bufUi, sizeof(bufUi), value);
        if (printReturn != NULL) {
            return parser_error_dummy;
        }
    } else {
        // it's u128 or u256, up to 78 chars in decimal
        uint8_t bcdOut[40] = {0};
        bignumLittleEndian_to_bcd(bcdOut, sizeof(bcdOut), printItem->item.val.ptr, printItem->item.val.len);
        if (!bignumLittleEndian_bcdprint(bufUi, sizeof(bufUi), bcdOut, sizeof(bcdOut))) {
            return parser_unexpected_buffer_end;
        }
    }

    if (printItem->item.valEnc == EncBalance) {
        if (intstr_to_fpstr_inplace(bufUi, sizeof(bufUi), printItem->decimals) == 0) {
            return parser_unexpected_value;
        }

        // remove trailing zeros
        number_inplace_trimming(bufUi, 1);

        // we add 2 for a ' ' between unit and number and null terminator
        if (sizeof(bufUi) < strnlen(bufUi, sizeof(bufUi)) + printItem->unit.len + 2) {
            return parser_error_dummy;
        }

        // using memmove in the same memory region is safe!
        // we already checked that we have space for it
        memmove(bufUi + printItem->unit.len + 1, bufUi, strnlen(bufUi, sizeof(bufUi)));
        memmove(bufUi, printItem->unit.ptr, printItem->unit.len);
        bufUi[printItem->unit.len] = ' ';
    }

    const uint16_t numLen = strnlen(bufUi, sizeof(bufUi));
    pageStringExt(uiFields->outVal, uiFields->outValLen, bufUi, numLen, uiFields->pageIdx, uiFields->pageCount);

    return parser_ok;
}

/**
 * @brief Prints a signed item.
 *
 * @param uiFields Pointer to the UI fields.
 * @param printItem Pointer to the print item.
 * @return parser_error_t Error code.
 */
static parser_error_t printSignedItem(ui_field_t *uiFields, PrintItem_t *printItem) {
    if (uiFields == NULL || printItem == NULL) {
        return parser_error_dummy;
    }

    // it's up to i256, up to 79 chars in decimal
    if (printItem->item.val.len > 32) {
        return parser_unexpected_value;
    }

    bool isNegative = false;
    uint8_t intAbsVal[32] = {0};
    const uint8_t ptrLen = (uint8_t)printItem->item.val.len;

    // check most significant bit (bit sign), if set ==> negative
    // note that is little endian!
    if (printItem->item.val.ptr[ptrLen - 1] & 0x80) {
        isNegative = true;

        // to do absolute value we perform two's complement (flip all bits and add 1)
        uint8_t carry = 1;
        for (uint8_t i = 0; i < ptrLen; i++) {
            intAbsVal[i] = (uint8_t)(~printItem->item.val.ptr[i] + carry);
            if (intAbsVal[i] != 0) {
                carry = 0;
            }
        }
    } else {
        memmove(intAbsVal, printItem->item.val.ptr, ptrLen);
    }

    // it's i128 or i256, up to 79 chars in decimal
    uint8_t bcdOut[40] = {0};
    char bufUi[100] = {0};
    bignumLittleEndian_to_bcd(bcdOut, sizeof(bcdOut), intAbsVal, ptrLen);

    // we leave the first char for negative sign!
    if (!bignumLittleEndian_bcdprint(bufUi + (isNegative ? 1 : 0), sizeof(bufUi) - (isNegative ? 1 : 0), bcdOut,
                                     sizeof(bcdOut))) {
        return parser_unexpected_buffer_end;
    }

    if (isNegative) {
        bufUi[0] = '-';
    }

    // up to 79 chars
    const uint16_t numLen = strnlen(bufUi, sizeof(bufUi));
    pageStringExt(uiFields->outVal, uiFields->outValLen, bufUi, numLen, uiFields->pageIdx, uiFields->pageCount);

    return parser_ok;
}

/**
 * @brief Prints a boolean item.
 *
 * @param uiFields Pointer to the UI fields.
 * @param printItem Pointer to the print item.
 * @return parser_error_t Error code.
 */
static parser_error_t printBoolItem(ui_field_t *uiFields, PrintItem_t *printItem) {
    if (uiFields == NULL || printItem == NULL) {
        return parser_error_dummy;
    }

    if (printItem->item.val.len != 1) {
        return parser_error_dummy;
    }

    snprintf(uiFields->outVal, uiFields->outValLen, *printItem->item.val.ptr ? "True" : "False");

    return parser_ok;
}

/**
 * @brief Prints a compact item.
 *
 * @param uiFields Pointer to the UI fields.
 * @param printItem Pointer to the print item.
 * @return parser_error_t Error code.
 */
static parser_error_t printCompactItem(ui_field_t *uiFields, PrintItem_t *printItem) {
    if (uiFields == NULL || printItem == NULL) {
        return parser_error_dummy;
    }

    // we can't parse anything larger than 256 bits
    // it's theoretically possible to have a number larger, but not happening in practice
    if (printItem->item.val.len > 32) {
        return parser_value_out_of_range;
    }

    const CompactInt_t cmpInt = {.ptr = printItem->item.val.ptr, .len = (uint8_t)printItem->item.val.len};
    char bufUi[100] = {0};

    if (cmpInt.len <= 4) {
        uint64_t value = 0;
        CHECK_ERROR(_getValue(&cmpInt, &value));
        const char *printReturn = uint64_to_str(bufUi, sizeof(bufUi), value);
        if (printReturn != NULL) {
            return parser_error_dummy;
        }
    } else {
        // is bigint, up to 256 bytes, up to 77 chars in decimal
        uint8_t bcdOut[40] = {0};
        bignumLittleEndian_to_bcd(bcdOut, sizeof(bcdOut), cmpInt.ptr + 1, cmpInt.len - 1);
        if (!bignumLittleEndian_bcdprint(bufUi, sizeof(bufUi), bcdOut, sizeof(bcdOut))) {
            return parser_unexpected_buffer_end;
        }
    }

    if (printItem->item.valEnc == EncCompactBalance) {
        if (intstr_to_fpstr_inplace(bufUi, sizeof(bufUi), printItem->decimals) == 0) {
            return parser_unexpected_value;
        }

        // remove trailing zeros
        number_inplace_trimming(bufUi, 1);

        // we add 2 for a ' ' between unit and number and null terminator
        if (sizeof(bufUi) < strnlen(bufUi, sizeof(bufUi)) + printItem->unit.len + 2) {
            return parser_error_dummy;
        }

        // using memmove in the same memory region is safe!
        // we already checked that we have space for it
        memmove(bufUi + printItem->unit.len + 1, bufUi, strnlen(bufUi, sizeof(bufUi)));
        memmove(bufUi, printItem->unit.ptr, printItem->unit.len);
        bufUi[printItem->unit.len] = ' ';
    }

    const uint16_t numLen = strnlen(bufUi, sizeof(bufUi));
    pageStringExt(uiFields->outVal, uiFields->outValLen, bufUi, numLen, uiFields->pageIdx, uiFields->pageCount);

    return parser_ok;
}

/**
 * @brief Prints a string item.
 *
 * @param uiFields Pointer to the UI fields.
 * @param printItem Pointer to the print item.
 * @return parser_error_t Error code.
 */
static parser_error_t printStringItem(ui_field_t *uiFields, PrintItem_t *printItem) {
    if (uiFields == NULL || printItem == NULL) {
        return parser_error_dummy;
    }

    bool allPrintable = true;
    for (uint64_t i = 0; i < printItem->item.val.len; i++) {
        allPrintable &= IS_PRINTABLE(printItem->item.val.ptr[i]);
    }

    if (allPrintable) {
        pageStringExt(uiFields->outVal, uiFields->outValLen, (const char *)printItem->item.val.ptr, printItem->item.val.len,
                      uiFields->pageIdx, uiFields->pageCount);
    } else {
        const uint16_t keyStrLen = strnlen(uiFields->outKey, uiFields->outKeyLen);
        snprintf(uiFields->outKey + keyStrLen, uiFields->outKeyLen - keyStrLen, " (hex)");
        pageStringHex(uiFields->outVal, uiFields->outValLen, (const char *)printItem->item.val.ptr, printItem->item.val.len,
                      uiFields->pageIdx, uiFields->pageCount);
    }

    return parser_ok;
}

/**
 * @brief Prints a hex string item.
 *
 * @param uiFields Pointer to the UI fields.
 * @param printItem Pointer to the print item.
 * @return parser_error_t Error code.
 */
static parser_error_t printHexStringItem(ui_field_t *uiFields, PrintItem_t *printItem) {
    if (uiFields == NULL || printItem == NULL) {
        return parser_error_dummy;
    }

    const uint16_t keyStrLen = strnlen(uiFields->outKey, uiFields->outKeyLen);
    snprintf(uiFields->outKey + keyStrLen, uiFields->outKeyLen - keyStrLen, " (hex)");
    pageStringHex(uiFields->outVal, uiFields->outValLen, (const char *)printItem->item.val.ptr, printItem->item.val.len,
                  uiFields->pageIdx, uiFields->pageCount);

    return parser_ok;
}

/**
 * @brief Prints an address item.
 *
 * @param uiFields Pointer to the UI fields.
 * @param printItem Pointer to the print item.
 * @return parser_error_t Error code.
 */
static parser_error_t printAddressItem(ui_field_t *uiFields, PrintItem_t *printItem) {
    if (uiFields == NULL || printItem == NULL) {
        return parser_error_dummy;
    }

    if (printItem->item.val.len != 32) {
        return parser_error_dummy;
    }

    // not going to be more than ~50 chars
    char bufUi[80] = {0};
    if (crypto_SS58EncodePubkey((uint8_t *)bufUi, sizeof(bufUi), printItem->base58prefix, printItem->item.val.ptr) == 0) {
        return parser_no_data;
    }

    uint16_t addressLen = strnlen(bufUi, sizeof(bufUi));
    pageStringExt(uiFields->outVal, uiFields->outValLen, bufUi, addressLen, uiFields->pageIdx, uiFields->pageCount);

    return parser_ok;
}

/**
 * @brief Prints a vote item.
 *
 * @param uiFields Pointer to the UI fields.
 * @param printItem Pointer to the print item.
 * @return parser_error_t Error code.
 */
static parser_error_t printVoteItem(ui_field_t *uiFields, PrintItem_t *printItem) {
    if (uiFields == NULL || printItem == NULL) {
        return parser_error_dummy;
    }

    if (printItem->item.val.len != 1) {
        return parser_error_dummy;
    }

    const uint8_t vote = *printItem->item.val.ptr;

    // this is the range of vote that we control, otherwise print as an integer
    if (vote <= 0x06 || (vote >= 0x80 && vote <= 0x86)) {
        snprintf(uiFields->outVal, uiFields->outValLen, "%s Locked%dx", vote >> 7 == 1 ? "Aye" : "Nay", vote & 0x0f);
        return parser_ok;
    }

    CHECK_ERROR(printUnsignedItem(uiFields, printItem));

    return parser_ok;
}

/**
 * @brief Prints a generic item based on its encoding.
 *
 * @param uiFields Pointer to the UI fields.
 * @param printItem Pointer to the print item.
 * @return parser_error_t Error code.
 */
parser_error_t printGenericItem(ui_field_t *uiFields, PrintItem_t *printItem) {
    if (uiFields == NULL || printItem == NULL) {
        return parser_error_dummy;
    }

    switch (printItem->item.valEnc) {
        case EncUnsigned:
        case EncBalance:
            CHECK_ERROR(printUnsignedItem(uiFields, printItem));
            break;

        case EncSigned:
            CHECK_ERROR(printSignedItem(uiFields, printItem));
            break;

        case EncBool:
            CHECK_ERROR(printBoolItem(uiFields, printItem));
            break;

        case EncCompact:
        case EncCompactBalance:
            CHECK_ERROR(printCompactItem(uiFields, printItem));
            break;

        case EncString:
            CHECK_ERROR(printStringItem(uiFields, printItem));
            break;

        case EncHexString:
            CHECK_ERROR(printHexStringItem(uiFields, printItem));
            break;

        case EncAddress:
            CHECK_ERROR(printAddressItem(uiFields, printItem));
            break;

        case EncVote:
            CHECK_ERROR(printVoteItem(uiFields, printItem));
            break;

        case EncEmptyVec:
            pageString(uiFields->outVal, uiFields->outValLen, STR_EMPTY_VEC, uiFields->pageIdx, uiFields->pageCount);
            return parser_ok;

        case EncNoEncoding:
            return parser_error_dummy;
    }

    return parser_ok;
}
