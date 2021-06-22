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
#include <ux.h>

#include "view.h"
#include "actions.h"
#include "tx.h"
#include "addr.h"
#include "crypto.h"
#include "coin.h"
#include "zxmacros.h"
#include "secret.h"
#include "app_mode.h"

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

#ifdef APP_SECRET_MODE_ENABLED
    if (app_mode_secret()) {
        hdPath[1] = HDPATH_1_RECOVERY;
    }
#endif
}

__Z_INLINE bool process_chunk(volatile uint32_t *tx, uint32_t rx) {
    zemu_log("process_chunk\n");
    const uint8_t payloadType = G_io_apdu_buffer[OFFSET_PAYLOAD_TYPE];
#ifndef SUPPORT_SR25519
    if (G_io_apdu_buffer[OFFSET_P2] != 0) {
        THROW(APDU_CODE_INVALIDP1P2);
    }
#endif
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

__Z_INLINE void handle_getversion(volatile uint32_t *flags, volatile uint32_t *tx, uint32_t rx) {
    G_io_apdu_buffer[0] = 0;

#if defined(APP_TESTING)
    G_io_apdu_buffer[0] = 0x01;
#endif

    G_io_apdu_buffer[1] = (LEDGER_MAJOR_VERSION >> 8) & 0xFF;
    G_io_apdu_buffer[2] = (LEDGER_MAJOR_VERSION >> 0) & 0xFF;

    G_io_apdu_buffer[3] = (LEDGER_MINOR_VERSION >> 8) & 0xFF;
    G_io_apdu_buffer[4] = (LEDGER_MINOR_VERSION >> 0) & 0xFF;

    G_io_apdu_buffer[5] = (LEDGER_PATCH_VERSION >> 8) & 0xFF;
    G_io_apdu_buffer[6] = (LEDGER_PATCH_VERSION >> 0) & 0xFF;

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

    const uint8_t requireConfirmation = G_io_apdu_buffer[OFFSET_P1];
    const uint8_t addr_type = G_io_apdu_buffer[OFFSET_P2];
    const key_kind_e key_type = get_key_type(addr_type);

    zxerr_t zxerr = app_fill_address(key_type);
    if(zxerr != zxerr_ok){
        *tx = 0;
        THROW(APDU_CODE_DATA_INVALID);
    }
    if (requireConfirmation) {
        view_review_init(addr_getItem, addr_getNumItems, app_reply_address);
        view_review_show();
        *flags |= IO_ASYNCH_REPLY;
        return;
    }
    *tx = action_addrResponseLen;
    THROW(APDU_CODE_OK);
}

#ifdef SUPPORT_SR25519
__Z_INLINE void handleSignSr25519(volatile uint32_t *flags, volatile uint32_t *tx, uint32_t rx) {
    zxerr_t err = app_sign_sr25519();
    if(err != zxerr_ok){
        *tx = 0;
        THROW(APDU_CODE_DATA_INVALID);
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

    view_review_init(tx_getItem, tx_getNumItems, app_return_sr25519);
    view_review_show();
    *flags |= IO_ASYNCH_REPLY;
}
#endif

__Z_INLINE void handleSignEd25519(volatile uint32_t *flags, volatile uint32_t *tx, uint32_t rx) {
    const char *error_msg = tx_parse();
    CHECK_APP_CANARY()
    if (error_msg != NULL) {
        int error_msg_length = strlen(error_msg);
        MEMCPY(G_io_apdu_buffer, error_msg, error_msg_length);
        *tx += (error_msg_length);
        THROW(APDU_CODE_DATA_INVALID);
    }

    view_review_init(tx_getItem, tx_getNumItems, app_sign_ed25519);
    view_review_show();
    *flags |= IO_ASYNCH_REPLY;
}

__Z_INLINE void handleSign(volatile uint32_t *flags, volatile uint32_t *tx, uint32_t rx) {
    zemu_log("handleSign\n");
    if (!process_chunk(tx, rx)) {
        THROW(APDU_CODE_OK);
    }
    if (app_mode_secret()) {
        app_mode_set_secret(false);
    }
    const uint8_t addr_type = G_io_apdu_buffer[OFFSET_P2];
    const key_kind_e key_type = get_key_type(addr_type);

    *tx = 0;
    switch (key_type) {
        case key_ed25519:
            handleSignEd25519(flags, tx, rx);
            break;
#ifdef SUPPORT_SR25519
        case key_sr25519:
            handleSignSr25519(flags, tx, rx);
            break;
#endif
        default: {
            THROW(APDU_CODE_DATA_INVALID);
        }
    }
}

#if defined(APP_TESTING)
void handleTest(volatile uint32_t *flags, volatile uint32_t *tx, uint32_t rx) {
    THROW(APDU_CODE_OK);
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

                case INS_GET_ADDR: {
                    if( os_global_pin_is_validated() != BOLOS_UX_OK ) {
                        THROW(APDU_CODE_COMMAND_NOT_ALLOWED);
                    }
                    handleGetAddr(flags, tx, rx);
                    break;
                }

                case INS_SIGN: {
                    if( os_global_pin_is_validated() != BOLOS_UX_OK ) {
                        THROW(APDU_CODE_COMMAND_NOT_ALLOWED);
                    }
                    handleSign(flags, tx, rx);
                    break;
                }

#if defined(APP_TESTING)
                    case INS_TEST: {
                    handleTest(flags, tx, rx);
                    THROW(APDU_CODE_OK);
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
