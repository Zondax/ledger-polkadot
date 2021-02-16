/*******************************************************************************
*   (c) 2019 Zondax GmbH
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
#include "crypto.h"
#include "tx.h"
#include "apdu_codes.h"
#include <os_io_seproxyhal.h>
#include "coin.h"
#include "zxerror.h"

extern uint16_t action_addrResponseLen;
extern uint16_t action_signResponseLen;

#ifdef SUPPORT_SR25519
__Z_INLINE zxerr_t app_sign_sr25519() {
    const uint8_t *message = tx_get_buffer();
    const uint16_t messageLength = tx_get_buffer_length();
    uint16_t replyLen = 0;
    zxerr_t zxerr;
    zxerr = crypto_sign_sr25519_prephase(G_io_apdu_buffer, IO_APDU_BUFFER_SIZE - 3, message, messageLength);
    if (zxerr != zxerr_ok) {
        MEMZERO(G_io_apdu_buffer, IO_APDU_BUFFER_SIZE);
        return zxerr;
    }
    zxerr = crypto_sign_sr25519(G_io_apdu_buffer, IO_APDU_BUFFER_SIZE - 3, &replyLen);
    return zxerr;
}
#endif

__Z_INLINE void app_sign_ed25519() {
    const uint8_t *message = tx_get_buffer();
    const uint16_t messageLength = tx_get_buffer_length();
    uint16_t replyLen = 0;
    zxerr_t err = crypto_sign_ed25519(G_io_apdu_buffer, IO_APDU_BUFFER_SIZE - 3,
                                      message, messageLength, &replyLen);
    if (err != zxerr_ok) {
        set_code(G_io_apdu_buffer, 0, APDU_CODE_SIGN_VERIFY_ERROR);
        io_exchange(CHANNEL_APDU | IO_RETURN_AFTER_TX, 2);
    } else {
        set_code(G_io_apdu_buffer, SIG_PLUS_TYPE_LEN, APDU_CODE_OK);
        io_exchange(CHANNEL_APDU | IO_RETURN_AFTER_TX, SIG_PLUS_TYPE_LEN + 2);
    }
}

#ifdef SUPPORT_SR25519
__Z_INLINE void app_return_sr25519() {
    MEMCPY(G_io_apdu_buffer, (void *) &N_sr25519_signdata.signature, SIG_PLUS_TYPE_LEN);
    zxerr_t zxerr = zeroize_sr25519_signdata();

    if (zxerr != zxerr_ok) {
        set_code(G_io_apdu_buffer, 0, APDU_CODE_SIGN_VERIFY_ERROR);
        io_exchange(CHANNEL_APDU | IO_RETURN_AFTER_TX, 2);
    } else {
        set_code(G_io_apdu_buffer, SIG_PLUS_TYPE_LEN, APDU_CODE_OK);
        io_exchange(CHANNEL_APDU | IO_RETURN_AFTER_TX, SIG_PLUS_TYPE_LEN + 2);
    }
}
#endif

__Z_INLINE void app_reject() {
    zeroize_sr25519_signdata();
    set_code(G_io_apdu_buffer, 0, APDU_CODE_COMMAND_NOT_ALLOWED);
    io_exchange(CHANNEL_APDU | IO_RETURN_AFTER_TX, 2);
}

__Z_INLINE zxerr_t app_fill_address(key_kind_e addressKind) {
    // Put data directly in the apdu buffer
    MEMZERO(G_io_apdu_buffer, IO_APDU_BUFFER_SIZE);
    CHECK_ZXERR(crypto_fillAddress(addressKind,
                                   G_io_apdu_buffer, IO_APDU_BUFFER_SIZE - 2,
                                   &action_addrResponseLen));
    return zxerr_ok;
}

__Z_INLINE key_kind_e get_key_type(uint8_t num) {
#ifdef SUPPORT_SR25519
    switch (num) {
        case 0x00:
            return key_ed25519;
        case 0x01:
            return key_sr25519;
    }
    return 0xff;
#else
    return key_ed25519;
#endif
}

__Z_INLINE void app_reply_error() {
    zeroize_sr25519_signdata();
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
