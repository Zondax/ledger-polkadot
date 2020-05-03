/*******************************************************************************
*   (c) 2018, 2019 Zondax GmbH
*   (c) 2016 Ledger
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

#include "view.h"
#include "coin.h"
#include "view_internal.h"
#include "crypto.h"

#include "actions.h"
#include "apdu_codes.h"
#include "glyphs.h"
#include "bagl.h"
#include "zxmacros.h"
#include "view_templates.h"
#include "tx.h"

#include <string.h>
#include <stdio.h>

view_t viewdata;

void h_address_accept(unsigned int _) {
    UNUSED(_);
    view_idle_show(0);
    UX_WAIT();
    app_reply_address(viewdata.addrKind);
}

void h_error_accept(unsigned int _) {
    UNUSED(_);
    view_idle_show(0);
    UX_WAIT();
    app_reply_error();
}

void h_sign_accept(unsigned int _) {
    UNUSED(_);

    const uint8_t replyLen = app_sign();

    view_idle_show(0);
    UX_WAIT();

    if (replyLen > 0) {
        set_code(G_io_apdu_buffer, replyLen, APDU_CODE_OK);
        io_exchange(CHANNEL_APDU | IO_RETURN_AFTER_TX, replyLen + 2);
    } else {
        set_code(G_io_apdu_buffer, 0, APDU_CODE_SIGN_VERIFY_ERROR);
        io_exchange(CHANNEL_APDU | IO_RETURN_AFTER_TX, 2);
    }
}

void h_sign_reject(unsigned int _) {
    UNUSED(_);
    view_idle_show(0);
    UX_WAIT();

    set_code(G_io_apdu_buffer, 0, APDU_CODE_COMMAND_NOT_ALLOWED);
    io_exchange(CHANNEL_APDU | IO_RETURN_AFTER_TX, 2);
}

void h_paging_init() {
    viewdata.itemIdx = 0;
    viewdata.pageIdx = 0;
    viewdata.pageCount = 1;
}

void h_paging_increase() {
    if (viewdata.pageIdx + 1 < viewdata.pageCount) {
        // increase page
        viewdata.pageIdx++;
    } else {
        // passed page count, go to next index
        if (viewdata.itemIdx + 1 < viewdata.itemCount) {
            viewdata.itemIdx++;
            viewdata.pageIdx = 0;
        }
    }
}

void h_paging_decrease() {
    if (viewdata.pageIdx != 0) {
        viewdata.pageIdx--;
    } else {
        if (viewdata.itemIdx > 0) {
            viewdata.itemIdx--;
            // jump to last page. update will cap this value
            viewdata.pageIdx = VIEW_ADDRESS_LAST_PAGE_DEFAULT;
        }
    }
}

void h_paging_set_page_count(uint8_t pageCount) {
    viewdata.pageCount = pageCount;
    if (viewdata.pageIdx > viewdata.pageCount) {
        viewdata.pageIdx = viewdata.pageCount - 1;
    }
}

view_error_t h_review_update_data() {
    tx_error_t err = tx_no_error;

    do {
        err = tx_getItem(viewdata.itemIdx,
                         viewdata.key, MAX_CHARS_PER_KEY_LINE,
                         viewdata.value, MAX_CHARS_PER_VALUE1_LINE,
                         viewdata.pageIdx, &viewdata.pageCount);

        if (err == tx_no_data) {
            return view_no_data;
        }

        if (viewdata.pageCount == 0) {
            h_paging_increase();
        }
    } while (viewdata.pageCount == 0);

    if (err != tx_no_error) {
        return view_error_detected;
    }

    splitValueField();
    return view_no_error;
}

view_error_t h_addr_update_item(uint8_t idx) {
    MEMZERO(viewdata.value, MAX_CHARS_PER_VALUE1_LINE);

    switch (idx) {
        case 0: return view_printAddr();
        case 1: return view_printPath();
        default:
            return view_error_detected;
    }
}

void io_seproxyhal_display(const bagl_element_t *element) {
    io_seproxyhal_display_default((bagl_element_t *) element);
}

void view_init(void) {
    UX_INIT();
}

void view_idle_show(unsigned int ignored) {
    view_idle_show_impl();
}

void view_address_show(address_kind_e addressKind) {
    viewdata.addrKind = addressKind;
    viewdata.itemCount = VIEW_ADDRESS_ITEM_COUNT;          // Address, path, etc.
    view_address_show_impl();
}

void view_error_show() {
    snprintf(viewdata.key, MAX_CHARS_PER_KEY_LINE, "ERROR");
    snprintf(viewdata.value, MAX_CHARS_PER_VALUE1_LINE, "SHOWING DATA");
    splitValueField();
    view_error_show_impl();
}

void view_sign_show() {
    view_sign_show_impl();
}
