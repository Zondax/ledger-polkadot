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
#include "addr.h"
#include "app_mode.h"
#include "zxerror.h"

#include <string.h>
#include <stdio.h>

view_t viewdata;

void h_address_accept(unsigned int _) {
    UNUSED(_);
    view_idle_show(0);
    UX_WAIT();
    app_reply_address();
}

void h_error_accept(unsigned int _) {
    UNUSED(_);
    view_idle_show(0);
    UX_WAIT();
    app_reply_error();
}

void h_sign_accept(unsigned int _) {
    UNUSED(_);
    app_sign();
    view_idle_show(0);
    UX_WAIT();
}

void h_sign_reject(unsigned int _) {
    UNUSED(_);
    view_idle_show(0);
    UX_WAIT();

    set_code(G_io_apdu_buffer, 0, APDU_CODE_COMMAND_NOT_ALLOWED);
    io_exchange(CHANNEL_APDU | IO_RETURN_AFTER_TX, 2);
}

///////////////////////////////////
// Paging related

void h_paging_init() {
    viewdata.itemIdx = 0;
    viewdata.pageIdx = 0;
    viewdata.pageCount = 1;
}

uint8_t h_paging_can_increase() {
    if (viewdata.pageIdx + 1 < viewdata.pageCount) {
        return 1;
    } else {
        // passed page count, go to next index
        if (viewdata.itemIdx + 1 < viewdata.itemCount) {
            return 1;
        }
    }
    return 0;
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

uint8_t h_paging_can_decrease() {
    if (viewdata.pageIdx != 0) {
        return 1;
    } else {
        if (viewdata.itemIdx > 0) {
            return 1;
        }
    }
    return 0;
}

void h_paging_decrease() {
    if (viewdata.pageIdx != 0) {
        viewdata.pageIdx--;
    } else {
        if (viewdata.itemIdx > 0) {
            viewdata.itemIdx--;
            // jump to last page. update will cap this value
            viewdata.pageIdx = 255;
        }
    }
}

void h_paging_set_page_count(uint8_t pageCount) {
    viewdata.pageCount = pageCount;
    if (viewdata.pageIdx > viewdata.pageCount) {
        viewdata.pageIdx = viewdata.pageCount - 1;
    }
}

///////////////////////////////////
// Paging related

zxerr_t h_review_update_data() {
    do {
        viewdata.pageCount = 1;
        switch (viewdata.mode) {
            case review_tx: {
                CHECK_ZXERR(tx_getNumItems(&viewdata.itemCount))
                CHECK_ZXERR(
                        tx_getItem(viewdata.itemIdx,
                                   viewdata.key, MAX_CHARS_PER_KEY_LINE,
                                   viewdata.value, MAX_CHARS_PER_VALUE1_LINE,
                                   viewdata.pageIdx, &viewdata.pageCount))
                if (viewdata.pageIdx > viewdata.pageCount) {
                    // try again and get last page
                    viewdata.pageIdx = viewdata.pageCount - 1;
                    CHECK_ZXERR(
                            tx_getItem(viewdata.itemIdx,
                                       viewdata.key, MAX_CHARS_PER_KEY_LINE,
                                       viewdata.value, MAX_CHARS_PER_VALUE1_LINE,
                                       viewdata.pageIdx, &viewdata.pageCount))
                }
                break;
            }
            case review_address: {
                CHECK_ZXERR(addr_getNumItems(&viewdata.itemCount))
                CHECK_ZXERR(addr_getItem(viewdata.itemIdx,
                                         viewdata.key, MAX_CHARS_PER_KEY_LINE,
                                         viewdata.value, MAX_CHARS_PER_VALUE1_LINE,
                                         viewdata.pageIdx, &viewdata.pageCount))
                if (viewdata.pageIdx > viewdata.pageCount) {
                    // try again and get last page
                    viewdata.pageIdx = viewdata.pageCount - 1;
                    CHECK_ZXERR(
                            addr_getItem(viewdata.itemIdx,
                                         viewdata.key, MAX_CHARS_PER_KEY_LINE,
                                         viewdata.value, MAX_CHARS_PER_VALUE1_LINE,
                                         viewdata.pageIdx, &viewdata.pageCount))
                }
                break;
            }
            default:
                return zxerr_unknown;
        }
        viewdata.itemCount++;

        if (viewdata.pageCount > 1) {
            uint8_t keyLen = strlen(viewdata.key);
            if (keyLen < MAX_CHARS_PER_KEY_LINE) {
                snprintf(viewdata.key + keyLen, MAX_CHARS_PER_KEY_LINE - keyLen, " [%d/%d]", viewdata.pageIdx + 1, viewdata.pageCount);
            }
        }

        if (viewdata.pageCount == 0) {
            h_paging_increase();
        }
    } while (viewdata.pageCount == 0);

    splitValueField();
    return zxerr_ok;
}

///////////////////////////////////
// General

void io_seproxyhal_display(const bagl_element_t *element) {
    io_seproxyhal_display_default((bagl_element_t *) element);
}

void view_init(void) {
    UX_INIT();
}

void view_idle_show(uint8_t item_idx) {
    view_idle_show_impl(item_idx);
}

void view_address_show() {
    viewdata.mode = review_address;
    view_address_show_impl();
}

void view_sign_show() {
    viewdata.mode = review_tx;
    view_sign_show_impl();
}

void view_error_show() {
    snprintf(viewdata.key, MAX_CHARS_PER_KEY_LINE, "ERROR");
    snprintf(viewdata.value, MAX_CHARS_PER_VALUE1_LINE, "SHOWING DATA");
    splitValueField();
    view_error_show_impl();
}
