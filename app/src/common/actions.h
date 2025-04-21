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

#include <os_io_seproxyhal.h>
#include <stdint.h>

#include "addr.h"
#include "apdu_codes.h"
#include "coin.h"
#include "crypto.h"
#include "tx.h"
#include "zxerror.h"

extern uint16_t action_addrResponseLen;
extern uint16_t blobLen;

__Z_INLINE void app_sign_ed25519() {
    const uint8_t *message = tx_get_buffer();

    zxerr_t err = crypto_sign_ed25519(G_io_apdu_buffer, IO_APDU_BUFFER_SIZE - 3, message, blobLen);

    if (err != zxerr_ok) {
        set_code(G_io_apdu_buffer, 0, APDU_CODE_SIGN_VERIFY_ERROR);
        io_exchange(CHANNEL_APDU | IO_RETURN_AFTER_TX, 2);
    } else {
        set_code(G_io_apdu_buffer, SIG_PLUS_TYPE_LEN, APDU_CODE_OK);
        io_exchange(CHANNEL_APDU | IO_RETURN_AFTER_TX, SIG_PLUS_TYPE_LEN + 2);
    }
}

__Z_INLINE void app_sign_secp256k1() {
    const uint8_t *message = tx_get_buffer();

    uint16_t sigLen = 0;
    zxerr_t err = crypto_sign_secp256k1(G_io_apdu_buffer, IO_APDU_BUFFER_SIZE - 3, message, blobLen, &sigLen);
    if (err != zxerr_ok) {
        set_code(G_io_apdu_buffer, 0, APDU_CODE_SIGN_VERIFY_ERROR);
        io_exchange(CHANNEL_APDU | IO_RETURN_AFTER_TX, 2);
    } else {
        set_code(G_io_apdu_buffer, sigLen, APDU_CODE_OK);
        io_exchange(CHANNEL_APDU | IO_RETURN_AFTER_TX, sigLen + 2);
    }
}

__Z_INLINE void app_reject() {
    set_code(G_io_apdu_buffer, 0, APDU_CODE_COMMAND_NOT_ALLOWED);
    io_exchange(CHANNEL_APDU | IO_RETURN_AFTER_TX, 2);
}

__Z_INLINE zxerr_t app_fill_address(const uint16_t ss58prefix, const scheme_type_e address_scheme) {
    // Put data directly in the apdu buffer
    return crypto_fillAddress(G_io_apdu_buffer, IO_APDU_BUFFER_SIZE - 2, &action_addrResponseLen, ss58prefix,
                              address_scheme);
}

__Z_INLINE void app_reply_error() {
    set_code(G_io_apdu_buffer, 0, APDU_CODE_DATA_INVALID);
    io_exchange(CHANNEL_APDU | IO_RETURN_AFTER_TX, 2);
}

__Z_INLINE void app_reply_address() {
    if (action_addrResponseLen == 0) {
        app_reply_error();
        return;
    }
    set_code(G_io_apdu_buffer, action_addrResponseLen, APDU_CODE_OK);
    io_exchange(CHANNEL_APDU | IO_RETURN_AFTER_TX, action_addrResponseLen + 2);
}
