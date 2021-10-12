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
#include "crypto.h"
#include "coin.h"
#include "zxmacros.h"
#include "app_mode.h"

unsigned char G_io_seproxyhal_spi_buffer[IO_SEPROXYHAL_BUFFER_SIZE_B];

unsigned char io_event(__Z_UNUSED unsigned char channel) {
    switch (G_io_seproxyhal_spi_buffer[0]) {
        case SEPROXYHAL_TAG_FINGER_EVENT: //
            UX_FINGER_EVENT(G_io_seproxyhal_spi_buffer);
            break;

        case SEPROXYHAL_TAG_BUTTON_PUSH_EVENT: // for Nano S
            UX_BUTTON_PUSH_EVENT(G_io_seproxyhal_spi_buffer);
            break;

        case SEPROXYHAL_TAG_DISPLAY_PROCESSED_EVENT:
            if (!UX_DISPLAYED())
                UX_DISPLAYED_EVENT();
            break;

        case SEPROXYHAL_TAG_TICKER_EVENT: { //
            UX_TICKER_EVENT(G_io_seproxyhal_spi_buffer, {
                    if (UX_ALLOWED) {
                        UX_REDISPLAY();
                    }
            });
            break;
        }

            // unknown events are acknowledged
        default:
            UX_DEFAULT_EVENT();
            break;
    }
    if (!io_seproxyhal_spi_is_status_sent()) {
        io_seproxyhal_general_status();
    }
    return 1; // DO NOT reset the current APDU transport
}

unsigned short io_exchange_al(unsigned char channel, unsigned short tx_len) {
    switch (channel & ~(IO_FLAGS)) {
        case CHANNEL_KEYBOARD:
            break;

            // multiplexed io exchange over a SPI channel and TLV encapsulated protocol
        case CHANNEL_SPI:
            if (tx_len) {
                io_seproxyhal_spi_send(G_io_apdu_buffer, tx_len);

                if (channel & IO_RESET_AFTER_REPLIED) {
                    reset();
                }
                return 0; // nothing received from the master so far (it's a tx
                // transaction)
            } else {
                return io_seproxyhal_spi_recv(G_io_apdu_buffer, sizeof(G_io_apdu_buffer), 0);
            }

        default:
            THROW(INVALID_PARAMETER);
    }
    return 0;
}

void handle_generic_apdu(__Z_UNUSED volatile uint32_t *flags, volatile uint32_t *tx, uint32_t rx) {
    if (rx > 4 && memcmp(G_io_apdu_buffer, "\xE0\x01\x00\x00", 4) == 0) {
        // Respond to get device info command
        uint8_t * p = G_io_apdu_buffer;
        // Target ID        4 bytes
        p[0] = (TARGET_ID >> 24) & 0xFF;
        p[1] = (TARGET_ID >> 16) & 0xFF;
        p[2] = (TARGET_ID >> 8) & 0xFF;
        p[3] = (TARGET_ID >> 0) & 0xFF;
        p += 4;
        // SE Version       [length][non-terminated string]
        *p = os_version(p + 1, 64);
        p = p + 1 + *p;
        // Flags            [length][flags]
        *p = 0;
        p++;
        // MCU Version      [length][non-terminated string]
        *p = os_seph_version(p + 1, 64);
        p = p + 1 + *p;

        *tx = p - G_io_apdu_buffer;
        THROW(APDU_CODE_OK);
    }
}

void app_init() {
    io_seproxyhal_init();

#ifdef TARGET_NANOX
    // grab the current plane mode setting
    G_io_app.plane_mode = os_setting_get(OS_SETTING_PLANEMODE, NULL, 0);
#endif // TARGET_NANOX

    USB_power(0);
    USB_power(1);
    app_mode_reset();
#ifdef SUPPORT_SR25519
    zeroize_sr25519_signdata();
#endif
    view_idle_show(0, NULL);

#ifdef HAVE_BLE
    // Enable Bluetooth
    BLE_power(0, NULL);
    BLE_power(1, "Nano X");
#endif // HAVE_BLE

}

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"

void app_main() {
    volatile uint32_t rx = 0, tx = 0, flags = 0;

    for (;;) {
        volatile uint16_t sw = 0;

        BEGIN_TRY;
        {
            TRY;
            {
                rx = tx;
                tx = 0;

                rx = io_exchange(CHANNEL_APDU | flags, rx);
                flags = 0;
                CHECK_APP_CANARY()

                if (rx == 0)
                    THROW(APDU_CODE_EMPTY_BUFFER);

                handle_generic_apdu(&flags, &tx, rx);
                CHECK_APP_CANARY()

                handleApdu(&flags, &tx, rx);
                CHECK_APP_CANARY()
            }
            CATCH(EXCEPTION_IO_RESET)
            {
                // reset IO and UX before continuing
                app_init();
                continue;
            }
            CATCH_OTHER(e);
            {
                switch (e & 0xF000) {
                    case 0x6000:
                    case 0x9000:
                        sw = e;
                        break;
                    default:
                        sw = 0x6800 | (e & 0x7FF);
                        break;
                }
                G_io_apdu_buffer[tx] = sw >> 8;
                G_io_apdu_buffer[tx + 1] = sw;
                tx += 2;
            }
            FINALLY;
            {}
        }
        END_TRY;
    }
}

#pragma clang diagnostic pop
