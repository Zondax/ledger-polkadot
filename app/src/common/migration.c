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

#include "migration.h"

#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

#include "view.h"
#include "zxerror.h"
#include "zxformat.h"

zxerr_t migrationGetNumItems(uint8_t *numItems) {
    if (numItems == NULL) {
        return zxerr_no_data;
    }

    *numItems = 1;
    return zxerr_ok;
}
zxerr_t migrationGetItem(int8_t displayIdx,
                         char *outKey,
                         uint16_t outKeyLen,
                         char *outVal,
                         uint16_t outValLen,
                         uint8_t pageIdx,
                         uint8_t *pageCount) {
    if (outKey == NULL || outVal == NULL || pageCount == NULL || displayIdx != 0) {
        return zxerr_no_data;
    }

    snprintf(outKey, outKeyLen, "Migration");
    const char instructions[] =
        "This app is only meant for performing the migration to Polkadot Generic App; DO NOT use this app frequently.";
    pageStringExt(outVal, outValLen, instructions, sizeof(instructions), pageIdx, pageCount);
    return zxerr_ok;
}

void migrationOk() {
    view_idle_show(0, NULL);
}

void migrationStartMessage() {
#ifdef MIGRATION_APP
#if defined(TARGET_STAX) || defined(TARGET_FLEX) || defined(TARGET_APEX_P)
    const review_type_e reviewType = REVIEW_UI;
#else
    const review_type_e reviewType = REVIEW_MSG;
#endif
    view_review_init(migrationGetItem, migrationGetNumItems, migrationOk);
    view_review_show(reviewType);
#endif
}
