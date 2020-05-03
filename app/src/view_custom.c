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

#include "view.h"
#include "coin.h"
#include "crypto.h"
#include "view_internal.h"
#include <os_io_seproxyhal.h>

#include <string.h>
#include <stdio.h>

view_error_t view_printAddr() {
    snprintf(viewdata.addr, MAX_CHARS_ADDR, "%s", (char *) (G_io_apdu_buffer + VIEW_ADDRESS_OFFSET_ED25519));
    splitValueField();
    return view_no_error;
}

view_error_t view_printPath() {
    bip32_to_str(viewdata.addr, MAX_CHARS_ADDR, hdPath, HDPATH_LEN_DEFAULT);
    splitValueField();
    return view_no_error;
}
