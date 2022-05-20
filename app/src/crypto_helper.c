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

#include "crypto_helper.h"
#include "base58.h"

#if defined(TARGET_NANOS) || defined(TARGET_NANOX) || defined(TARGET_NANOS2)
#include "cx.h"

int ss58hash(const unsigned char *in, unsigned int inLen,
                   unsigned char *out, unsigned int outLen) {

    cx_blake2b_t ctx;
    cx_blake2b_init(&ctx, 512);
    cx_hash(&ctx.header, 0, SS58_BLAKE_PREFIX, SS58_BLAKE_PREFIX_LEN, NULL, 0);
    cx_hash(&ctx.header, CX_LAST, in, inLen, out, outLen);

    return 0;
}
#else

#include <hexutils.h>
#include "blake2.h"

int ss58hash(const unsigned char *in, unsigned int inLen,
             unsigned char *out, unsigned int outLen) {
    blake2b_state s;
    blake2b_init(&s, 64);
    blake2b_update(&s, SS58_BLAKE_PREFIX, SS58_BLAKE_PREFIX_LEN);
    blake2b_update(&s, in, inLen);
    blake2b_final(&s, out, outLen);
    return 0;
}

#endif

uint8_t crypto_SS58CalculatePrefix(uint16_t addressType, uint8_t *prefixBytes) {
    if (addressType > 16383) {
        return 0;
    }

    if (addressType > 63) {
        prefixBytes[0] = 0x40 | ((addressType >> 2) & 0x3F);
        prefixBytes[1] = ((addressType & 0x3) << 6) + ((addressType >> 8) & 0x3F);
        return 2;
    }

    prefixBytes[0] = addressType & 0x3F; // address type
    return 1;
}

uint8_t crypto_SS58EncodePubkey(uint8_t *buffer, uint16_t buffer_len,
                                uint16_t addressType, const uint8_t *pubkey) {
    // based on https://docs.substrate.io/v3/advanced/ss58/
    if (buffer == NULL || buffer_len < SS58_ADDRESS_MAX_LEN) {
        return 0;
    }
    if (pubkey == NULL) {
        return 0;
    }
    MEMZERO(buffer, buffer_len);

    uint8_t hash[64];
    uint8_t unencoded[36];

    const uint8_t prefixSize = crypto_SS58CalculatePrefix(addressType, unencoded);
    if (prefixSize == 0) {
        return 0;
    }

    memcpy(unencoded + prefixSize, pubkey, 32);           // account id
    ss58hash((uint8_t *) unencoded, 32 + prefixSize, hash, 64);
    unencoded[32 + prefixSize] = hash[0];
    unencoded[33 + prefixSize] = hash[1];

    size_t outLen = buffer_len;
    encode_base58(unencoded, 34 + prefixSize, buffer, &outLen);

    return outLen;
}
