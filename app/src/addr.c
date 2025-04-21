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

#include <stdio.h>

#include "app_mode.h"
#include "coin.h"
#include "crypto.h"
#include "zxerror.h"
#include "zxformat.h"
#include "zxmacros.h"

zxerr_t addr_getNumItems(uint8_t *num_items) {
    zemu_log_stack("addr_getNumItems");
    *num_items = 2;
    if (app_mode_expert()) {
        (*num_items)++;
    }
    return zxerr_ok;
}

zxerr_t addr_getItem(int8_t displayIdx,
                     char *outKey,
                     uint16_t outKeyLen,
                     char *outVal,
                     uint16_t outValLen,
                     uint8_t pageIdx,
                     uint8_t *pageCount) {
    ZEMU_LOGF(50, "addr_getItem %d/%d", displayIdx, pageIdx)

    switch (displayIdx) {
        case 0:
            snprintf(outKey, outKeyLen, "Address");
            if (scheme == secp256k1) {
                // Size to comply with array_to_hexstr size check plus the 0x prefix
                char tmp[SECP256K1_ADDRESS_LEN * 2 + 3] = {0};
                tmp[0] = '0';
                tmp[1] = 'x';
                array_to_hexstr(tmp + 2, sizeof(tmp) - 2, G_io_apdu_buffer + SECP256K1_PK_LEN, SECP256K1_ADDRESS_LEN);
                pageString(outVal, outValLen, tmp, pageIdx, pageCount);
            } else {
                pageString(outVal, outValLen, (char *)(G_io_apdu_buffer + PK_LEN_25519), pageIdx, pageCount);
            }
            return zxerr_ok;
        case 1:
            snprintf(outKey, outKeyLen, "Public key");
            pageStringHex(outVal, outValLen, (char *)G_io_apdu_buffer, PK_LEN_25519, pageIdx, pageCount);
            return zxerr_ok;
        case 2: {
            if (!app_mode_expert()) {
                return zxerr_no_data;
            }

            snprintf(outKey, outKeyLen, "Your Path");
            char buffer[50];
            bip32_to_str(buffer, sizeof(buffer), hdPath, HDPATH_LEN_DEFAULT);
            pageString(outVal, outValLen, buffer, pageIdx, pageCount);
            return zxerr_ok;
        }
        default:
            return zxerr_no_data;
    }
}
