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

#include "tx.h"

#include <string.h>

#include "apdu_codes.h"
#include "app_main.h"
#include "buffering.h"
#include "parser.h"
#include "view.h"
#include "zxformat.h"
#include "zxmacros.h"

#ifdef HAVE_SWAP
#include "swap.h"
#endif

extern uint16_t blobLen;

#if defined(TARGET_NANOX) || defined(TARGET_NANOS2) || defined(TARGET_STAX) || defined(TARGET_FLEX)
#define RAM_BUFFER_SIZE   16384  // 16 KiB
#define FLASH_BUFFER_SIZE 16384  // 16 KiB
#elif defined(TARGET_NANOS)
#define RAM_BUFFER_SIZE   0
#define FLASH_BUFFER_SIZE 16384  // 16 KiB
#endif

// Ram
uint8_t ram_buffer[RAM_BUFFER_SIZE];

// Flash
typedef struct {
    uint8_t buffer[FLASH_BUFFER_SIZE];
} storage_t;

#if defined(TARGET_NANOS) || defined(TARGET_NANOX) || defined(TARGET_NANOS2) || defined(TARGET_STAX) || defined(TARGET_FLEX)
storage_t NV_CONST N_appdata_impl __attribute__((aligned(64)));
#define N_appdata (*(NV_VOLATILE storage_t *)PIC(&N_appdata_impl))
#endif

static parser_tx_t tx_obj;

void tx_initialize() {
    buffering_init(ram_buffer, sizeof(ram_buffer), (uint8_t *)N_appdata.buffer, sizeof(N_appdata.buffer));
}

void tx_reset() {
    buffering_reset();
}

uint32_t tx_append(unsigned char *buffer, uint32_t length) {
    return buffering_append(buffer, length);
}

uint16_t tx_get_buffer_length() {
    return buffering_get_buffer()->pos;
}

uint8_t *tx_get_buffer() {
    return buffering_get_buffer()->data;
}

const char *tx_raw_parse() {
    const char prefix[] = "<Bytes>";
    const uint8_t prefixLen = strlen(prefix);
    const char postfix[] = "</Bytes>";
    const uint8_t postfixLen = strlen(postfix);

    const uint8_t *data = tx_get_buffer();
    const size_t dataLen = tx_get_buffer_length();
    if (data == NULL) {
        return parser_getErrorDescription(parser_no_data);
    }

    // we need to have, at least, prefix and postfix
    if (dataLen < prefixLen + postfixLen) {
        return parser_getErrorDescription(parser_unexpected_value);
    }

    // check if both prefix and postfix are correct
    if (strncmp((const char *)data, prefix, prefixLen) != 0 ||
        strncmp((const char *)data + dataLen - postfixLen, postfix, postfixLen) != 0) {
        return parser_getErrorDescription(parser_unexpected_value);
    }

    return NULL;
}

const char *tx_parse() {
    parser_error_t err = parser_parse(&tx_obj, tx_get_buffer(), tx_get_buffer_length(), blobLen);

    if (err != parser_ok) {
        return parser_getErrorDescription(err);
    }

    err = parser_validate(&tx_obj);
    CHECK_APP_CANARY()

    if (err != parser_ok) {
        return parser_getErrorDescription(err);
    }

#ifdef HAVE_SWAP
    // If in swap mode, compare swap tx parameters with stored info.
    if (G_swap_state.called_from_swap) {
        if (G_swap_state.should_exit == 1) {
            // Safety against trying to make the app sign multiple TX
            // This panic quit is a failsafe that should never trigger, as the app is supposed to
            // exit after the first send when started in swap mode
            os_sched_exit(-1);
        } else {
            // We will quit the app after this transaction, whether it succeeds or fails
            G_swap_state.should_exit = 1;
        }
        err = check_swap_conditions(&tx_obj);
        CHECK_APP_CANARY()
        if (err != parser_ok) {
            return parser_getErrorDescription(err);
        }
    }
#endif

    return NULL;
}

zxerr_t tx_getNumItems(uint8_t *num_items) {
    parser_error_t err = parser_getNumItems(&tx_obj, num_items);

    if (err != parser_ok) {
        return zxerr_no_data;
    }
    return zxerr_ok;
}

// NOLINTNEXTLINE(readability-non-const-parameter): it can't be const, clang-tidy bug
zxerr_t tx_getItem(int8_t displayIdx,
                   char *outKey,
                   uint16_t outKeyLen,
                   char *outVal,
                   uint16_t outValLen,
                   uint8_t pageIdx,
                   // NOLINTNEXTLINE(readability-non-const-parameter)
                   uint8_t *pageCount) {
    uint8_t numItems = 0;

    CHECK_ZXERR(tx_getNumItems(&numItems))

    if (displayIdx < 0 || displayIdx >= numItems) {
        return zxerr_no_data;
    }

    ui_field_t uiFields = {.displayIdx = displayIdx,
                           .outKey = outKey,
                           .outKeyLen = outKeyLen,
                           .outVal = outVal,
                           .outValLen = outValLen,
                           .pageIdx = pageIdx,
                           .pageCount = pageCount};

    const parser_error_t err = parser_getItem(&tx_obj, &uiFields);

    // Convert error codes
    if (err == parser_no_data || err == parser_display_idx_out_of_range || err == parser_display_page_out_of_range) {
        return zxerr_no_data;
    }

    if (err != parser_ok) {
        return zxerr_unknown;
    }

    return zxerr_ok;
}

zxerr_t tx_raw_getNumItems(uint8_t *num_items) {
    *num_items = 2;
    return zxerr_ok;
}

zxerr_t tx_raw_getItem(int8_t displayIdx,
                       char *outKey,
                       uint16_t outKeyLen,
                       char *outVal,
                       uint16_t outValLen,
                       uint8_t pageIdx,
                       uint8_t *pageCount) {
    MEMZERO(outKey, outKeyLen);
    MEMZERO(outVal, outValLen);

    uint8_t numItems = 0;
    CHECK_ZXERR(tx_raw_getNumItems(&numItems))
    if (displayIdx < 0 || displayIdx >= numItems) {
        return zxerr_no_data;
    }

    if (displayIdx == 0) {
        *pageCount = 1;
        snprintf(outKey, outKeyLen, "Sign and Verify");
        snprintf(outVal, outValLen, "Arbitrary text");
        return zxerr_ok;
    }
    const uint8_t *buf = tx_get_buffer();
    const uint16_t bufLen = tx_get_buffer_length();
    if (buf == NULL) {
        return zxerr_no_data;
    }

    bool allPrintable = true;
    for (uint16_t i = 0; i < bufLen; i++) {
        allPrintable &= IS_PRINTABLE(buf[i]);
    }
    if (allPrintable) {
        snprintf(outKey, outKeyLen, "Payload");
        pageStringExt(outVal, outValLen, (const char *)buf, bufLen, pageIdx, pageCount);
    } else {
        snprintf(outKey, outKeyLen, "Payload (hex)");
        pageStringHex(outVal, outValLen, (const char *)buf, bufLen, pageIdx, pageCount);
    }

    return zxerr_ok;
}
