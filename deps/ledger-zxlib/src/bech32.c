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

#include <stdint.h>
#include <stddef.h>
#include <zxmacros.h>
#include "bech32.h"
#include "segwit_addr.h"
#include "bittools.h"

zxerr_t bech32EncodeFromBytes(char *out,
                              size_t out_len,
                              const char *hrp,
                              const uint8_t *in,
                              size_t in_len,
                              uint8_t pad) {
    MEMZERO(out, out_len);

    if (in_len > MAX_INPUT_SIZE) {
        return zxerr_out_of_bounds;
    }

    size_t hrplen = strlen(hrp);
    // We set a lower bound to ensure this is safe
    if (out_len < hrplen + (in_len * 2) + 7) {
        return zxerr_buffer_too_small;
    }

    // Overestimate required size *2==(8/4) instead of *(8/5)
    uint8_t tmp_data[MAX_INPUT_SIZE * 2];
    size_t tmp_size = 0;
    MEMZERO(tmp_data, sizeof(tmp_data));

    convert_bits(tmp_data, &tmp_size, 5, in, in_len, 8, pad);
    if (tmp_size >= out_len) {
        return zxerr_out_of_bounds;
    }

    int err = bech32_encode(out, hrp, tmp_data, tmp_size);
    if (err == 0) {
        return zxerr_encoding_failed;
    }

    return zxerr_ok;
}
