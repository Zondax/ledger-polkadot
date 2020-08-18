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

#include "app_mode.h"
#include "view.h"
#include "view_internal.h"
#include "actions.h"
#include "apdu_codes.h"
#include "glyphs.h"
#include "bagl.h"
#include "zxmacros.h"
#include "view_templates.h"
#include "tx.h"
#include "addr.h"

#include <string.h>
#include <stdio.h>

#if defined(TARGET_NANOS)

void h_expert_toggle();
void h_expert_update();
void h_review_button_left();
void h_review_button_right();
void view_review_decision_s();

ux_state_t ux;

void os_exit(uint32_t id) {
    os_sched_exit(0);
}

const ux_menu_entry_t menu_main[] = {
    {NULL, NULL, 0, &C_icon_app, MENU_MAIN_APP_LINE1, MENU_MAIN_APP_LINE2, 33, 12},
    {NULL, h_expert_toggle, 0, &C_icon_app, "Expert mode:", viewdata.value, 33, 12},
    {NULL, NULL, 0, &C_icon_app, APPVERSION_LINE1, APPVERSION_LINE2, 33, 12},
    {NULL, NULL, 0, &C_icon_app, "Developed by:", "Zondax.ch", 33, 12},
    {NULL, NULL, 0, &C_icon_app, "License: ", "Apache 2.0", 33, 12},
    {NULL, os_exit, 0, &C_icon_dashboard, "Quit", NULL, 50, 29},
    UX_MENU_END
};

const ux_menu_entry_t menu_decision_review[] = {
    {NULL, h_approve, 0, NULL, "Approve", NULL, 0, 0},
    {NULL, h_reject, 0, NULL, "Reject", NULL, 0, 0},
    UX_MENU_END
};

static const bagl_element_t view_review[] = {
    UI_BACKGROUND_LEFT_RIGHT_ICONS,
    UI_LabelLine(UIID_LABEL + 0, 0, 8, UI_SCREEN_WIDTH, UI_11PX, UI_WHITE, UI_BLACK, viewdata.key),
    UI_LabelLine(UIID_LABEL + 1, 0, 19, UI_SCREEN_WIDTH, UI_11PX, UI_WHITE, UI_BLACK, viewdata.value),
    UI_LabelLine(UIID_LABEL + 2, 0, 30, UI_SCREEN_WIDTH, UI_11PX, UI_WHITE, UI_BLACK, viewdata.value2),
};

static const bagl_element_t view_error[] = {
    UI_FillRectangle(0, 0, 0, UI_SCREEN_WIDTH, UI_SCREEN_HEIGHT, 0x000000, 0xFFFFFF),
    UI_Icon(0, 128 - 7, 0, 7, 7, BAGL_GLYPH_ICON_CHECK),
    UI_LabelLine(UIID_LABEL + 0, 0, 8, UI_SCREEN_WIDTH, UI_11PX, UI_WHITE, UI_BLACK, viewdata.key),
    UI_LabelLine(UIID_LABEL + 0, 0, 19, UI_SCREEN_WIDTH, UI_11PX, UI_WHITE, UI_BLACK, viewdata.value),
    UI_LabelLineScrolling(UIID_LABELSCROLL, 0, 30, 128, UI_11PX, UI_WHITE, UI_BLACK, viewdata.value2),
};

static unsigned int view_error_button(unsigned int button_mask, unsigned int button_mask_counter) {
    switch (button_mask) {
        case BUTTON_EVT_RELEASED | BUTTON_LEFT | BUTTON_RIGHT:
        case BUTTON_EVT_RELEASED | BUTTON_LEFT:
            break;
        case BUTTON_EVT_RELEASED | BUTTON_RIGHT:
            h_error_accept(0);
            break;
    }
    return 0;
}

static unsigned int view_review_button(unsigned int button_mask, unsigned int button_mask_counter) {
    switch (button_mask) {
        case BUTTON_EVT_RELEASED | BUTTON_LEFT | BUTTON_RIGHT:
            if (app_mode_expert()) {
                // Press both left and right buttons to quit
                view_review_decision_s();
            }
            break;
        case BUTTON_EVT_RELEASED | BUTTON_LEFT:
            // Press left to progress to the previous element
            h_review_button_left();
            break;

        case BUTTON_EVT_RELEASED | BUTTON_RIGHT:
            // Press right to progress to the next element
            h_review_button_right();
            break;
    }
    return 0;
}

const bagl_element_t *view_prepro(const bagl_element_t *element) {
    switch (element->component.userid) {
        case UIID_ICONLEFT:
            if (!h_paging_can_decrease()){
                return NULL;
            }
            UX_CALLBACK_SET_INTERVAL(2000);
            break;
        case UIID_ICONRIGHT:
            if (!h_paging_can_increase()){
                return NULL;
            }
            UX_CALLBACK_SET_INTERVAL(2000);
            break;
        case UIID_LABELSCROLL:
            UX_CALLBACK_SET_INTERVAL(
                MAX(3000, 1000 + bagl_label_roundtrip_duration_ms(element, 7))
            );
            break;
    }
    return element;
}

void h_review_button_left() {
    h_paging_decrease();

    zxerr_t err = h_review_update_data();
    switch(err) {
        case zxerr_ok:
            UX_DISPLAY(view_review, view_prepro);
            break;
        case zxerr_no_data:
            view_review_decision_s();
            break;
        default:
            view_error_show();
            UX_WAIT();
            break;
    }
}

void h_review_button_right() {
    h_paging_increase();

    zxerr_t err = h_review_update_data();

    switch(err) {
        case zxerr_ok:
            UX_DISPLAY(view_review, view_prepro);
            break;
        case zxerr_no_data:
            view_review_decision_s();
            break;
        default:
            view_error_show();
            UX_WAIT();
            break;
    }
}

void splitValueField() {
    print_value2("");
    uint16_t vlen = strlen(viewdata.value);
    if (vlen > MAX_CHARS_PER_VALUE2_LINE - 1) {
        strcpy(viewdata.value2, viewdata.value + MAX_CHARS_PER_VALUE_LINE);
        viewdata.value[MAX_CHARS_PER_VALUE_LINE] = 0;
    }
}

//////////////////////////
//////////////////////////
//////////////////////////
//////////////////////////
//////////////////////////

void view_idle_show_impl(uint8_t item_idx) {
    h_expert_update();
    UX_MENU_DISPLAY(item_idx, menu_main, NULL);
}

void view_error_show_impl() {
    UX_DISPLAY(view_error, view_prepro);
}

void view_review_decision_s(void){
    UX_MENU_DISPLAY(0, menu_decision_review, NULL);
}

void h_expert_toggle() {
    app_mode_set_expert(!app_mode_expert());
    view_idle_show(1);
}

void h_expert_update() {
    snprintf(viewdata.value, MAX_CHARS_PER_VALUE_LINE, "disabled");
    if (app_mode_expert()) {
        snprintf(viewdata.value, MAX_CHARS_PER_VALUE_LINE, "enabled");
    }
}

void view_review_show_impl() {
    zemu_log_stack("-- view_review_show_impl");

    h_paging_init();

    zxerr_t err = h_review_update_data();
    switch(err) {
        case zxerr_ok:
            UX_DISPLAY(view_review, view_prepro);
            break;
        case zxerr_no_data:
            view_review_decision_s();
            break;
        default:
            view_error_show();
            break;
    }
}
#endif
