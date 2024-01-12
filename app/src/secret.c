/*******************************************************************************
*   (c) 2020 Zondax GmbH
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

#include "os.h"
#include "cx.h"
#include "coin.h"
#include "app_main.h"
#include "tx.h"
#include "view.h"
#include "app_mode.h"
#include "zxformat.h"

void secret_accept() {
#ifdef APP_SECRET_MODE_ENABLED
    app_mode_set_secret(true);
    view_idle_show(0, NULL);
#endif
}

#if defined(TARGET_STAX)
static const char *secret_message =
        "You are about to enable DOT\n"
        "recovery mode. Activating this\n"
        "mode will temporarily allow\n"
        "you to sign transactions\n"
        "using Kusama keys.";
#else
static const char *secret_message =
        "USE AT YOUR OWN RISK!! "
        "You are about to enable the DOT recovery mode."
        "If you are not sure why you are here, reject or unplug your device immediately."
        "Activating this mode will temporarily allow you to sign transactions using Kusama keys";
#endif

zxerr_t secret_getNumItems(uint8_t *num_items) {
    zemu_log_stack("secret_getNumItems");
    *num_items = 1;
    return zxerr_ok;
}

zxerr_t secret_getItem(int8_t displayIdx,
                       char *outKey, uint16_t outKeyLen,
                       char *outVal, uint16_t outValLen,
                       uint8_t pageIdx, uint8_t *pageCount) {
    if (displayIdx != 0) {
        return zxerr_no_data;
    }

    snprintf(outKey, outKeyLen, "WARNING!");
    pageString(outVal, outValLen, (char *) PIC(secret_message), pageIdx, pageCount);
    return zxerr_ok;
}

zxerr_t secret_enabled() {
#ifdef APP_SECRET_MODE_ENABLED
    if (app_mode_secret()) {
        zemu_log("DISABLE RECOVERY");
        app_mode_set_secret(false);
#if !defined(TARGET_STAX)
        view_idle_show(0, NULL);
#endif
    } else {
        zemu_log("RECOVERY TRIGGERED");
        view_review_init(secret_getItem, secret_getNumItems, secret_accept);
        view_review_show(REVIEW_UI);
    }
#endif
    return zxerr_ok;
}
