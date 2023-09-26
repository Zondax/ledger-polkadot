/*******************************************************************************
*   (c) 2016 Ledger
*   (c) 2018 - 2023 Zondax AG
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
#include "swap.h"
#include "crypto.h"
#include "bignum.h"
#include "zxformat.h"
#include "substrate_dispatch.h"
#include "lib_standard_app/swap_lib_calls.h"

////////////////////////////////////////////////////////////////

zxerr_t bytesAmountToStringBalance(uint8_t *amount, uint8_t amount_len, char *out, uint8_t out_len) {
    uint8_t tmpBuf[50] = {0};

    //Convert byte array (up to 128bits/16bytes) to decimal string
    bignumBigEndian_to_bcd(tmpBuf, sizeof(tmpBuf), amount, amount_len);
    bignumBigEndian_bcdprint(out, out_len, tmpBuf, sizeof(tmpBuf));

    // Format number.
    if (!intstr_to_fpstr_inplace(out, out_len, COIN_AMOUNT_DECIMAL_PLACES)) {
        return zxerr_encoding_failed;
    }

    // Add ticker prefix.
    CHECK_ZXERR(z_str3join(out, out_len, COIN_TICKER, ""))

    // Trim trailing zeros
    number_inplace_trimming(out, 1);

    return zxerr_ok;
}

zxerr_t readU32BE(uint8_t* input, uint32_t *output) {
    if (input == NULL || output == NULL) {
        return zxerr_no_data;
    }

    *output = 0;
    for(uint8_t i = 0; i < 4; i++) {
        *output += (uint32_t) *(input + i) << (32 - (8*(i+1)));
    }
    return zxerr_ok;
}

zxerr_t readU64BE(uint8_t* input, uint64_t *output) {
    if (input == NULL || output == NULL) {
        return zxerr_no_data;
    }

    *output = 0;
    for(uint8_t i = 0; i < 8; i++) {
        *output += (uint64_t) *(input + i) << (64 - (8*(i+1)));
    }
    return zxerr_ok;
}
