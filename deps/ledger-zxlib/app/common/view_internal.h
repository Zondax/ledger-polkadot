/*******************************************************************************
*   (c) 2019 Zondax GmbH
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
#pragma once

#include <stdint.h>
#include "coin.h"
#include "zxerror.h"
#include "view.h"

#define CUR_FLOW G_ux.flow_stack[G_ux.stack_count-1]

#if defined(TARGET_NANOX)
#define MAX_CHARS_PER_KEY_LINE      64
#define MAX_CHARS_PER_VALUE1_LINE   4096
#define MAX_CHARS_HEXMESSAGE        160
#else
#define MAX_CHARS_PER_KEY_LINE      (17+1)
#define MAX_CHARS_PER_VALUE_LINE    (17)
#define MAX_CHARS_PER_VALUE1_LINE   (2*MAX_CHARS_PER_VALUE_LINE+1)
#define MAX_CHARS_PER_VALUE2_LINE   (MAX_CHARS_PER_VALUE_LINE+1)
#define MAX_CHARS_HEXMESSAGE        40
#endif

// This takes data from G_io_apdu_buffer that is prefilled with the address

typedef struct {
    struct {
        char key[MAX_CHARS_PER_KEY_LINE];
        char value[MAX_CHARS_PER_VALUE1_LINE];
#if defined(TARGET_NANOS)
        char value2[MAX_CHARS_PER_VALUE2_LINE];
#endif
    };
    viewfunc_getItem_t viewfuncGetItem;
    viewfunc_getNumItems_t viewfuncGetNumItems;
    viewfunc_accept_t viewfuncAccept;

    uint8_t itemIdx;
    uint8_t itemCount;
    uint8_t pageIdx;
    uint8_t pageCount;
} view_t;

extern view_t viewdata;

#define print_title(...) snprintf(viewdata.title, sizeof(viewdata.title), __VA_ARGS__)
#define print_key(...) snprintf(viewdata.key, sizeof(viewdata.key), __VA_ARGS__);
#define print_value(...) snprintf(viewdata.value, sizeof(viewdata.value), __VA_ARGS__);

#if defined(TARGET_NANOS)
#define print_value2(...) snprintf(viewdata.value2, sizeof(viewdata.value2), __VA_ARGS__);
#endif

void splitValueField();

///////////////////////////////////////////////
///////////////////////////////////////////////
///////////////////////////////////////////////
///////////////////////////////////////////////
///////////////////////////////////////////////
///////////////////////////////////////////////
///////////////////////////////////////////////
///////////////////////////////////////////////

void view_idle_show_impl(uint8_t item_idx);


void view_error_show_impl();

void h_paging_init();

uint8_t h_paging_can_increase();

void h_paging_increase();

uint8_t h_paging_can_decrease();

void h_paging_decrease();

void view_review_show_impl();

void h_approve(unsigned int _);

void h_reject(unsigned int _);

void h_error_accept(unsigned int _);

zxerr_t h_review_update_data();
