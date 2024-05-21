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

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "parser_impl.h"
// TODO: move ui_field_t to zxlib/include --> view depends on SDK
#include "view.h"

const char *parser_getErrorDescription(parser_error_t err);

// parses a tx buffer
parser_error_t parser_parse(parser_tx_t *txObj, const uint8_t *inputBuffer, uint16_t bufferLen, uint16_t blobLen);

// verifies tx fields
parser_error_t parser_validate(parser_tx_t *txObj);

// returns the number of items in the current parsing context
parser_error_t parser_getNumItems(parser_tx_t *txObj, uint8_t *numItems);

// retrieves a readable output for each field / page
parser_error_t parser_getItem(parser_tx_t *txObj, ui_field_t *uiFields);

#ifdef __cplusplus
}
#endif
