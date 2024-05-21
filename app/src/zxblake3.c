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

#include "zxblake3.h"

#include "blake3.h"
#include "parser_common.h"
#include "zxmacros.h"

static blake3_hasher zxblake3;
static uint16_t accumInLen = 0;

#define MAX_INPUT_LEN 4095  // (2^12 - 1)

/**
 * @brief Computes the BLAKE3 hash of the input data.
 *
 * @param in Pointer to the input data.
 * @param inLen Length of the input data.
 * @param out Pointer to the output buffer.
 * @param outLen Length of the output buffer.
 * @return parser_error_t Returns parser_ok on success, or an error code on failure.
 */
parser_error_t zxblake3_hash(const uint8_t *in, const uint16_t inLen, uint8_t *out, uint16_t outLen) {
    if (in == NULL || inLen == 0 || out == NULL || outLen < BLAKE3_OUT_LEN) {
        return parser_unexpected_error;
    }

    if (inLen > MAX_INPUT_LEN) {
        return parser_unexpected_value;
    }

    MEMZERO(&zxblake3, sizeof(zxblake3));
    blake3_hasher_init(&zxblake3);
    blake3_hasher_update(&zxblake3, in, inLen);
    blake3_hasher_finalize(&zxblake3, out, outLen);

    return parser_ok;
}

/**
 * @brief Initializes the BLAKE3 hasher.
 *
 * @return parser_error_t Returns parser_ok on success, or an error code on failure.
 */
parser_error_t zxblake3_hash_init() {
    MEMZERO(&zxblake3, sizeof(zxblake3));
    blake3_hasher_init(&zxblake3);
    accumInLen = 0;

    return parser_ok;
}

/**
 * @brief Updates the BLAKE3 hasher with additional input data.
 *
 * @param in Pointer to the input data.
 * @param inLen Length of the input data.
 * @return parser_error_t Returns parser_ok on success, or an error code on failure.
 */
parser_error_t zxblake3_hash_update(const uint8_t *in, const uint16_t inLen) {
    if (in == NULL || inLen == 0) {
        return parser_unexpected_error;
    }

    if (accumInLen + inLen > MAX_INPUT_LEN) {
        return parser_unexpected_value;
    }

    accumInLen += inLen;
    blake3_hasher_update(&zxblake3, in, inLen);

    return parser_ok;
}

/**
 * @brief Finalizes the BLAKE3 hash computation and produces the output hash.
 *
 * @param out Pointer to the output buffer.
 * @param outLen Length of the output buffer.
 * @return parser_error_t Returns parser_ok on success, or an error code on failure.
 */
parser_error_t zxblake3_hash_finalize(uint8_t *out, uint16_t outLen) {
    if (out == NULL || outLen < BLAKE3_OUT_LEN) {
        return parser_unexpected_error;
    }

    blake3_hasher_finalize(&zxblake3, out, outLen);

    return parser_ok;
}
