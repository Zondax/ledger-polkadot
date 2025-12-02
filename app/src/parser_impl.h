/*******************************************************************************
 *  (c) 2018 - 2024  Zondax AG
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

#include "parser_common.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @enum UiEncoding_e
 * @brief Enumeration of possible UI encodings.
 */
typedef enum {
    EncNoEncoding = 0,     ///< No encoding
    EncUnsigned,           ///< Unsigned integer encoding
    EncSigned,             ///< Signed integer encoding
    EncBool,               ///< Boolean encoding
    EncCompact,            ///< Compact encoding
    EncString,             ///< String encoding
    EncHexString,          ///< Hexadecimal string encoding
    EncAddress,            ///< Address encoding
    EncBalance,            ///< Balance encoding
    EncCompactBalance,     ///< Compact balance encoding
    EncVote,               ///< Vote encoding
    EncEmptyVec,           ///< Empty vector encoding
    EncRawBalance,         ///< Raw balance encoding (no decimal formatting)
    EncCompactRawBalance,  ///< Compact raw balance encoding (no decimal formatting)
} UiEncoding_e;

/**
 * @struct UiItem_t
 * @brief Structure representing a UI item.
 */
typedef struct {
    Bytes_t key;          ///< Key of the UI item
    Bytes_t val;          ///< Value of the UI item
    UiEncoding_e valEnc;  ///< Encoding of the value
} UiItem_t;

/**
 * @struct PrintItem_t
 * @brief Structure representing a print item.
 */
typedef struct {
    uint8_t itemCount;      ///< Number of items
    bool printing;          ///< Printing flag
    uint8_t target;         ///< Target identifier
    UiItem_t item;          ///< UI item
    uint16_t base58prefix;  ///< Base58 prefix
    uint8_t decimals;       ///< Number of decimals
    Bytes_t unit;           ///< Unit of measurement
    Bytes_t palletName;     ///< Current pallet name (for context-aware formatting)
} PrintItem_t;

/**
 * @struct pd_ExtrinsicEra_t
 * @brief Structure representing an extrinsic era.
 */
typedef struct {
    uint8_t isMortal;  ///< Mortality flag
    uint32_t period;   ///< Period of the era
    uint16_t phase;    ///< Phase of the era
} pd_ExtrinsicEra_t;

/**
 * @brief Checks that there are at least SIZE bytes available in the buffer.
 * @param CTX Context
 * @param SIZE Size to check
 * @return parser_error_t Error code
 */
#define CTX_CHECK_AVAIL(CTX, SIZE)                                      \
    if ((CTX) == NULL || ((CTX)->offset + (SIZE)) > (CTX)->bufferLen) { \
        return parser_unexpected_buffer_end;                            \
    }

/**
 * @brief Checks availability and advances the context offset.
 * @param CTX Context
 * @param SIZE Size to advance
 */
#define CTX_CHECK_AND_ADVANCE(CTX, SIZE) \
    CTX_CHECK_AVAIL((CTX), (SIZE))       \
    (CTX)->offset += (SIZE);

/**
 * @brief Checks function input is valid.
 * @param INPUT Input to check
 * @return parser_error_t Error code
 */
#define CHECK_INPUT(INPUT)     \
    if (INPUT == NULL) {       \
        return parser_no_data; \
    }                          \
    CTX_CHECK_AVAIL(ctx, 1)  // Checks that there is something available in the buffer

/**
 * @brief Generates a function declaration for reading fixed-size unsigned integers.
 * @param BITS Number of bits
 */
#define GEN_DEC_READFIX_UNSIGNED(BITS) parser_error_t _readUInt##BITS(parser_context_t *ctx, uint##BITS##_t *value)

/**
 * @brief Generates a function definition for reading fixed-size unsigned integers.
 * @param BITS Number of bits
 * @return parser_error_t Error code
 */
#define GEN_DEF_READFIX_UNSIGNED(BITS)                                              \
    parser_error_t _readUInt##BITS(parser_context_t *ctx, uint##BITS##_t *value) {  \
        if (value == NULL) return parser_no_data;                                   \
        *value = 0u;                                                                \
        for (uint8_t i = 0u; i < (BITS##u >> 3u); i++, ctx->offset++) {             \
            if (ctx->offset >= ctx->bufferLen) return parser_unexpected_buffer_end; \
            *value += (uint##BITS##_t) * (ctx->buffer + ctx->offset) << (8u * i);   \
        }                                                                           \
        return parser_ok;                                                           \
    }

GEN_DEC_READFIX_UNSIGNED(8);
GEN_DEC_READFIX_UNSIGNED(16);
GEN_DEC_READFIX_UNSIGNED(32);
GEN_DEC_READFIX_UNSIGNED(64);

/**
 * @brief Reads a boolean value from the context.
 * @param ctx Parser context
 * @param val Pointer to store the boolean value
 * @return parser_error_t Error code
 */
parser_error_t readBool(parser_context_t *ctx, bool *val);

/**
 * @brief Reads a compact integer from the context.
 * @param ctx Parser context
 * @param val Pointer to store the compact integer
 * @return parser_error_t Error code
 */
parser_error_t readCompactInt(parser_context_t *ctx, CompactInt_t *val);

/**
 * @brief Gets the value from a compact integer.
 * @param compact Pointer to the compact integer
 * @param value Pointer to store the value
 * @return parser_error_t Error code
 */
parser_error_t _getValue(const CompactInt_t *compact, uint64_t *value);

/**
 * @brief Parses a transaction.
 * @param txObj Pointer to the transaction object
 * @return parser_error_t Error code
 */
parser_error_t transaction_parse(parser_tx_t *txObj);

/**
 * @brief Verifies the metadata of a transaction.
 * @param txObj Pointer to the transaction object
 * @return parser_error_t Error code
 */
parser_error_t verifyMetadata(parser_tx_t *txObj);

/**
 * @brief Reads an extrinsic era from the context.
 * @param ctx Parser context
 * @param era Pointer to store the extrinsic era
 * @return parser_error_t Error code
 */
parser_error_t _readEra(parser_context_t *ctx, pd_ExtrinsicEra_t *era);

#ifdef __cplusplus
}
#endif
