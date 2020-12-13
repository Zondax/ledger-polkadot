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

#include "app_main.h"

#include <string.h>
#include <os_io_seproxyhal.h>
#include <os.h>

#include "view.h"
#include "actions.h"
#include "tx.h"
#include "addr.h"
#include "crypto.h"
#include "coin.h"
#include "zxmacros.h"

#if defined(APP_RESTRICTED)
#include "allowlist.h"
#endif

void extractHDPath(uint32_t rx, uint32_t offset) {
    if ((rx - offset) < sizeof(uint32_t) * HDPATH_LEN_DEFAULT) {
        THROW(APDU_CODE_WRONG_LENGTH);
    }

    MEMCPY(hdPath, G_io_apdu_buffer + offset, sizeof(uint32_t) * HDPATH_LEN_DEFAULT);

    const bool mainnet = hdPath[0] == HDPATH_0_DEFAULT &&
                         hdPath[1] == HDPATH_1_DEFAULT;

    if (!mainnet) {
        THROW(APDU_CODE_DATA_INVALID);
    }

#if defined(APP_RESTRICTED)
    if (hdPath[2] != HDPATH_2_STASH && hdPath[2] != HDPATH_2_VALIDATOR ) {
        THROW(APDU_CODE_DATA_INVALID);
    }
    if (hdPath[3] != HDPATH_3_DEFAULT ) {
        THROW(APDU_CODE_DATA_INVALID);
    }
    if (hdPath[4] < 0x80000000 ) {
        THROW(APDU_CODE_DATA_INVALID);
    }
#endif

}

__Z_INLINE bool process_chunk(volatile uint32_t *tx, uint32_t rx) {
    zemu_log("process_chunk\n");
    const uint8_t payloadType = G_io_apdu_buffer[OFFSET_PAYLOAD_TYPE];

    if (G_io_apdu_buffer[OFFSET_P2] != 0) {
        THROW(APDU_CODE_INVALIDP1P2);
    }

    if (rx < OFFSET_DATA) {
        THROW(APDU_CODE_WRONG_LENGTH);
    }

    uint32_t added;
    switch (payloadType) {
        case 0:
            zemu_log("process_chunk - init\n");
            tx_initialize();
            tx_reset();
            extractHDPath(rx, OFFSET_DATA);
            return false;
        case 1:
            zemu_log("process_chunk - add \n");
            added = tx_append(&(G_io_apdu_buffer[OFFSET_DATA]), rx - OFFSET_DATA);
            if (added != rx - OFFSET_DATA) {
                THROW(APDU_CODE_OUTPUT_BUFFER_TOO_SMALL);
            }
            return false;
        case 2:
            zemu_log("process_chunk - end \n");
            added = tx_append(&(G_io_apdu_buffer[OFFSET_DATA]), rx - OFFSET_DATA);
            if (added != rx - OFFSET_DATA) {
                THROW(APDU_CODE_OUTPUT_BUFFER_TOO_SMALL);
            }
            return true;
    }

    THROW(APDU_CODE_INVALIDP1P2);
}

#if defined(APP_RESTRICTED)
__Z_INLINE bool process_chunk_update(volatile uint32_t *tx, uint32_t rx) {
    const uint8_t payloadType = G_io_apdu_buffer[OFFSET_PAYLOAD_TYPE];

    if (G_io_apdu_buffer[OFFSET_P2] != 0) {
        THROW(APDU_CODE_INVALIDP1P2);
    }

    if (rx < OFFSET_DATA) {
        THROW(APDU_CODE_WRONG_LENGTH);
    }

    if (payloadType > 2) {
        THROW(APDU_CODE_INVALIDP1P2);
    }

    if (payloadType == 0) {
        tx_initialize();
        tx_reset();
        return false;
    }

    uint32_t added = tx_append(&(G_io_apdu_buffer[OFFSET_DATA]), rx - OFFSET_DATA);
    if (added != rx - OFFSET_DATA) {
        THROW(APDU_CODE_OUTPUT_BUFFER_TOO_SMALL);
    }

    return payloadType == 2;
}
#endif

__Z_INLINE void handle_getversion(volatile uint32_t *flags, volatile uint32_t *tx, uint32_t rx) {
    G_io_apdu_buffer[0] = 0;

#if defined(APP_TESTING)
    G_io_apdu_buffer[0] = 0x01;
#endif

#if defined(APP_RESTRICTED)
    G_io_apdu_buffer[0] = 0x02;
#endif

    G_io_apdu_buffer[1] = (LEDGER_MAJOR_VERSION >> 8) & 0xFF;;
    G_io_apdu_buffer[2] = (LEDGER_MAJOR_VERSION >> 0) & 0xFF;;

    G_io_apdu_buffer[3] = (LEDGER_MINOR_VERSION >> 8) & 0xFF;;
    G_io_apdu_buffer[4] = (LEDGER_MINOR_VERSION >> 0) & 0xFF;;

    G_io_apdu_buffer[5] = (LEDGER_PATCH_VERSION >> 8) & 0xFF;;
    G_io_apdu_buffer[6] = (LEDGER_PATCH_VERSION >> 0) & 0xFF;;

    G_io_apdu_buffer[7] = !IS_UX_ALLOWED;

    G_io_apdu_buffer[8] = (TARGET_ID >> 24) & 0xFF;
    G_io_apdu_buffer[9] = (TARGET_ID >> 16) & 0xFF;
    G_io_apdu_buffer[10] = (TARGET_ID >> 8) & 0xFF;
    G_io_apdu_buffer[11] = (TARGET_ID >> 0) & 0xFF;

    *tx += 12;
    THROW(APDU_CODE_OK);
}

__Z_INLINE void handleGetAddr(volatile uint32_t *flags, volatile uint32_t *tx, uint32_t rx) {
    extractHDPath(rx, OFFSET_DATA);

    uint8_t requireConfirmation = G_io_apdu_buffer[OFFSET_P1];

    if (requireConfirmation) {
        app_fill_address();

        view_review_init(addr_getItem, addr_getNumItems, app_reply_address);
        view_review_show();

        *flags |= IO_ASYNCH_REPLY;
        return;
    }

    *tx = app_fill_address();
    THROW(APDU_CODE_OK);
}

__Z_INLINE void handleSign(volatile uint32_t *flags, volatile uint32_t *tx, uint32_t rx) {
    zemu_log("handleSign\n");
    if (!process_chunk(tx, rx)) {
        THROW(APDU_CODE_OK);
    }

    CHECK_APP_CANARY()

    const char *error_msg = tx_parse();
    CHECK_APP_CANARY()

    if (error_msg != NULL) {
        int error_msg_length = strlen(error_msg);
        MEMCPY(G_io_apdu_buffer, error_msg, error_msg_length);
        *tx += (error_msg_length);
        THROW(APDU_CODE_DATA_INVALID);
    }

    CHECK_APP_CANARY()
    view_review_init(tx_getItem, tx_getNumItems, app_sign);
    view_review_show();
    *flags |= IO_ASYNCH_REPLY;
}

#if defined(APP_RESTRICTED)
__Z_INLINE void handleAllowlistGetMasterkey(volatile uint32_t *flags, volatile uint32_t *tx, uint32_t rx) {
    if (!allowlist_pubkey_is_set()) {
        // has not been set yet
        THROW(APDU_CODE_COMMAND_NOT_ALLOWED);
    }

    if (!allowlist_pubkey_get(G_io_apdu_buffer, 32)) {
        THROW(APDU_CODE_EXECUTION_ERROR);
    }

    *tx = 32;
    THROW(APDU_CODE_OK);
}

void app_allowlist_SetPublicKey() {
    if (!allowlist_pubkey_set(G_io_apdu_buffer + OFFSET_DATA, 32)) {
        set_code(G_io_apdu_buffer, 0, APDU_CODE_EXECUTION_ERROR);
        io_exchange(CHANNEL_APDU | IO_RETURN_AFTER_TX, 2);
    }
    zemu_log_stack("allowlist: pubkey updated");

    set_code(G_io_apdu_buffer, 0, APDU_CODE_OK);
    io_exchange(CHANNEL_APDU | IO_RETURN_AFTER_TX, 2);
}

__Z_INLINE void handleAllowlistSetPublicKey(volatile uint32_t *flags, volatile uint32_t *tx, uint32_t rx) {
    if (allowlist_pubkey_is_set()) {
        // Can only be set once
        THROW(APDU_CODE_COMMAND_NOT_ALLOWED);  // 0x6986
    }

    if (rx != OFFSET_DATA + 32) {
        THROW(APDU_CODE_WRONG_LENGTH);  // 0x6700
    }

    zemu_log_stack("allowlist: try update pubkey");

    view_review_init(allowlist_getItem, allowlist_getNumItems, app_allowlist_SetPublicKey);
    view_review_show();
    *flags |= IO_ASYNCH_REPLY;
}

__Z_INLINE void handleAllowlistGetHash(volatile uint32_t *flags, volatile uint32_t *tx, uint32_t rx) {
    if (!allowlist_is_active()) {
        THROW(APDU_CODE_COMMAND_NOT_ALLOWED);
    }

    allowlist_hash(G_io_apdu_buffer);
    *tx = 32;
    THROW(APDU_CODE_OK);
}

void app_allowlist_Upload() {
    zemu_log_stack("allowlist: try update");
    if (!allowlist_upgrade(tx_get_buffer(), tx_get_buffer_length())) {
        set_code(G_io_apdu_buffer, 0, APDU_CODE_EXECUTION_ERROR);
        io_exchange(CHANNEL_APDU | IO_RETURN_AFTER_TX, 2);
    }

    zemu_log_stack("allowlist: updated");
    set_code(G_io_apdu_buffer, 0, APDU_CODE_OK);
    io_exchange(CHANNEL_APDU | IO_RETURN_AFTER_TX, 2);
}

__Z_INLINE void handleAllowlistUpload(volatile uint32_t *flags, volatile uint32_t *tx, uint32_t rx) {
    if (!allowlist_pubkey_is_set()) {
        zemu_log_stack("allowlist: pubkey has not been set");
        THROW(APDU_CODE_COMMAND_NOT_ALLOWED);
    }

    zemu_log_stack("allowlist: update chunk");
    if (!process_chunk_update(tx, rx)) {
        THROW(APDU_CODE_OK);
    }
    CHECK_APP_CANARY()

    if (!allowlist_list_validate(tx_get_buffer(), tx_get_buffer_length())) {
        // conditions to update allowlist are not satisfied
        THROW(APDU_CODE_EXECUTION_ERROR);
    }

    view_review_init(allowlist_getItem, allowlist_getNumItems, app_allowlist_Upload);
    view_review_show();
    *flags |= IO_ASYNCH_REPLY;
}
#endif

void handleApdu(volatile uint32_t *flags, volatile uint32_t *tx, uint32_t rx) {
    uint16_t sw = 0;

    BEGIN_TRY
    {
        TRY
        {
            if (G_io_apdu_buffer[OFFSET_CLA] != CLA) {
                THROW(APDU_CODE_CLA_NOT_SUPPORTED);
            }

            if (rx < APDU_MIN_LENGTH) {
                THROW(APDU_CODE_WRONG_LENGTH);
            }

            switch (G_io_apdu_buffer[OFFSET_INS]) {
                case INS_GET_VERSION: {
                    handle_getversion(flags, tx, rx);
                    break;
                }

                case INS_GET_ADDR_ED25519: {
                    if( os_global_pin_is_validated() != BOLOS_UX_OK ) {
                        THROW(APDU_CODE_COMMAND_NOT_ALLOWED);
                    }
                    handleGetAddr(flags, tx, rx);
                    break;
                }

                case INS_SIGN_ED25519: {
                    if( os_global_pin_is_validated() != BOLOS_UX_OK ) {
                        THROW(APDU_CODE_COMMAND_NOT_ALLOWED);
                    }
                    handleSign(flags, tx, rx);
                    break;
                }

#if defined(APP_RESTRICTED)
                    // Allow list commands
                    case INS_ALLOWLIST_GET_PUBKEY: {
                        if( os_global_pin_is_validated() != BOLOS_UX_OK ) {
                            THROW(APDU_CODE_COMMAND_NOT_ALLOWED);
                        }
                        handleAllowlistGetMasterkey(flags, tx, rx);
                        break;
                    }

                    case INS_ALLOWLIST_SET_PUBKEY: {
                        if( os_global_pin_is_validated() != BOLOS_UX_OK ) {
                            THROW(APDU_CODE_COMMAND_NOT_ALLOWED);
                        }
                        handleAllowlistSetPublicKey(flags, tx, rx);
                        break;
                    }

                    case INS_ALLOWLIST_GET_HASH: {
                        if( os_global_pin_is_validated() != BOLOS_UX_OK ) {
                            THROW(APDU_CODE_COMMAND_NOT_ALLOWED);
                        }
                        handleAllowlistGetHash(flags, tx, rx);
                        break;
                    }

                    case INS_ALLOWLIST_UPLOAD: {
                        if( os_global_pin_is_validated() != BOLOS_UX_OK ) {
                            THROW(APDU_CODE_COMMAND_NOT_ALLOWED);
                        }
                        handleAllowlistUpload(flags, tx, rx);
                        break;
                    }
#endif

                default:
                    THROW(APDU_CODE_INS_NOT_SUPPORTED);
            }
        }
        CATCH(EXCEPTION_IO_RESET)
        {
            THROW(EXCEPTION_IO_RESET);
        }
        CATCH_OTHER(e)
        {
            switch (e & 0xF000) {
                case 0x6000:
                case APDU_CODE_OK:
                    sw = e;
                    break;
                default:
                    sw = 0x6800 | (e & 0x7FF);
                    break;
            }
            G_io_apdu_buffer[*tx] = sw >> 8;
            G_io_apdu_buffer[*tx + 1] = sw;
            *tx += 2;
        }
        FINALLY
        {
        }
    }
    END_TRY;
}
