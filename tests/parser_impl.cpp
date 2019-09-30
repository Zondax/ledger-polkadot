/*******************************************************************************
*   (c) 2019 ZondaX GmbH
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

#include "gmock/gmock.h"

#include <iostream>
#include <hexutils.h>
#include <lib/parser_txdef.h>
#include <lib/parser.h>
#include "lib/parser_impl.h"

using ::testing::TestWithParam;
using ::testing::Values;

// Test that we can parse uintxx_t correctly (uint8_t, uint16_t, uint32_t, uint64_t}
TEST(SCALE, UIntX) {
    parser_context_t ctx;
    parser_error_t err;
    uint8_t buffer[100];
    auto bufferLen = parseHexString(
        "45"
        "1234"
        "12345678"
        "1234567812345678",
        buffer);

    parser_init(&ctx, buffer, bufferLen);

    uint8_t v8 = 0;
    err = _readUInt8(&ctx, &v8);
    EXPECT_EQ(err, parser_ok) << parser_getErrorDescription(err);
    EXPECT_EQ(v8, 69);

    uint16_t v16 = 0;
    err = _readUInt16(&ctx, &v16);
    EXPECT_EQ(err, parser_ok) << parser_getErrorDescription(err);
    EXPECT_EQ(v16, 13330);

    uint32_t v32 = 0;
    err = _readUInt32(&ctx, &v32);
    EXPECT_EQ(err, parser_ok) << parser_getErrorDescription(err);
    EXPECT_EQ(v32, 2018915346);

    uint64_t v64 = 0;
    err = _readUInt64(&ctx, &v64);
    EXPECT_EQ(err, parser_ok) << parser_getErrorDescription(err);
    EXPECT_EQ(v64, 4037830692);
}

// Parse SCALE booleans
TEST(SCALE, Bool) {
    uint8_t buffer[100];
    auto bufferLen = parseHexString("000102", buffer);
    parser_context_t ctx;

    parser_init(&ctx, buffer, bufferLen);

    pd_bool_t value = bool_true;
    parser_error_t err;

    err = _readBool(&ctx, &value);
    EXPECT_EQ(err, parser_ok) << parser_getErrorDescription(err);
    EXPECT_EQ(value, bool_false);

    err = _readBool(&ctx, &value);
    EXPECT_EQ(err, parser_ok) << parser_getErrorDescription(err);
    EXPECT_EQ(value, bool_true);

    err = _readBool(&ctx, &value);
    EXPECT_EQ(err, parser_unexpected_value);
}

// Parse Compact numbers
TEST(SCALE, Compact) {
    parser_context_t ctx;
    parser_error_t err;

    uint8_t buffer[100];
    auto bufferLen = parseHexString("0004a815010100", buffer);
    parser_init(&ctx, buffer, bufferLen);

    compactInt_t cvalue;
    uint64_t value;

    err = _readCompactInt(&ctx, &cvalue);
    EXPECT_EQ(err, parser_ok) << parser_getErrorDescription(err);
    EXPECT_EQ(cvalue.len, 1);
    err = _getValue(&cvalue, &value);
    EXPECT_EQ(err, parser_ok) << parser_getErrorDescription(err);
    EXPECT_EQ(value, 0);

    err = _readCompactInt(&ctx, &cvalue);
    EXPECT_EQ(err, parser_ok) << parser_getErrorDescription(err);
    EXPECT_EQ(cvalue.len, 1);
    err = _getValue(&cvalue, &value);
    EXPECT_EQ(err, parser_ok) << parser_getErrorDescription(err);
    EXPECT_EQ(value, 1);

    err = _readCompactInt(&ctx, &cvalue);
    EXPECT_EQ(err, parser_ok) << parser_getErrorDescription(err);
    EXPECT_EQ(cvalue.len, 1);
    err = _getValue(&cvalue, &value);
    EXPECT_EQ(err, parser_ok) << parser_getErrorDescription(err);
    EXPECT_EQ(value, 42);

    err = _readCompactInt(&ctx, &cvalue);
    EXPECT_EQ(err, parser_ok) << parser_getErrorDescription(err);
    EXPECT_EQ(cvalue.len, 2);
    err = _getValue(&cvalue, &value);
    EXPECT_EQ(err, parser_ok) << parser_getErrorDescription(err);
    EXPECT_EQ(value, 69);

    err = _readCompactInt(&ctx, &cvalue);
    EXPECT_EQ(err, parser_ok) << parser_getErrorDescription(err);
    EXPECT_EQ(cvalue.len, 2);
    err = _getValue(&cvalue, &value);
    EXPECT_EQ(err, parser_value_out_of_range);
}

// Parse Compact numbers, reproduce/fix known bug
TEST(SCALE, Compact2) {
    parser_context_t ctx;
    parser_error_t err;

    uint8_t buffer[100];
    auto bufferLen = parseHexString("e5c0", buffer);
    parser_init(&ctx, buffer, bufferLen);

    compactInt_t cvalue;
    uint64_t value;

    err = _readCompactInt(&ctx, &cvalue);
    EXPECT_EQ(err, parser_ok) << parser_getErrorDescription(err);
    EXPECT_EQ(cvalue.len, 2);
    err = _getValue(&cvalue, &value);
    EXPECT_EQ(err, parser_ok) << parser_getErrorDescription(err);
    EXPECT_EQ(value, 12345);
}

TEST(SCALE, MortalEra) {
    parser_context_t ctx;
    parser_error_t err;

    uint8_t buffer[100];
    auto bufferLen = parseHexString("0100", buffer);
    parser_init(&ctx, buffer, bufferLen);

    pd_ExtrinsicEra_t v;
    err = _readEra(&ctx, &v);
    EXPECT_EQ(err, parser_ok) << parser_getErrorDescription(err);
    EXPECT_EQ(v.phase, 0);
    EXPECT_EQ(v.period, 4);
}

TEST(SCALE, BadTX) {
    parser_context_t ctx;
    parser_error_t err;

    uint8_t buffer[100];
    auto bufferLen = parseHexString("0102030405060708091011", buffer);

    parser_init(&ctx, buffer, bufferLen);

    parser_tx_t tx;

    err = _readTx(&ctx, &tx);
    EXPECT_EQ(err, parser_unexpected_callIndex) << parser_getErrorDescription(err);;
}

TEST(SCALE, FullTransferTX) {
    parser_context_t ctx;
    parser_error_t err;

    const auto testTx = "0400ff8d16d62802ca55326ec52bf76a8543b90e2aba5bcf6cd195c0d6fc1ef38fa1b3000600ae11030000c801"
                        "00003fd7b9eb6a00376e5be61f01abb429ffb0b104be05eaff4d458da48fcd425baf3fd7b9eb6a00376e5be61f"
                        "01abb429ffb0b104be05eaff4d458da48fcd425baf";

    uint8_t buffer[100];
    auto bufferLen = parseHexString(testTx, buffer);

    parser_init(&ctx, buffer, bufferLen);

    parser_tx_t tx;
    uint64_t tmp;
    char tmpBuffer[100];
    uint8_t pageCount = 0;

    err = _readTx(&ctx, &tx);
    EXPECT_EQ(err, parser_ok) << parser_getErrorDescription(err);

    /* CHECK FIXED FIELDS */

    EXPECT_EQ(tx.era.type, eEraMortal);
    EXPECT_EQ(tx.era.period, 128);
    EXPECT_EQ(tx.era.phase, 0);

    err = _getValue(&tx.nonce.index, &tmp);
    EXPECT_EQ(err, parser_ok) << parser_getErrorDescription(err);
    EXPECT_EQ(tmp, 50283);

    err = _getValue(&tx.tip.value, &tmp);
    EXPECT_EQ(err, parser_ok) << parser_getErrorDescription(err);
    EXPECT_EQ(tmp, 0);

    EXPECT_EQ(tx.specVersion, 456);

    err = _toStringHash(&tx.genesisHash, tmpBuffer, 100, 0, &pageCount);
    EXPECT_EQ(err, parser_ok) << parser_getErrorDescription(err);
    EXPECT_STREQ(tmpBuffer, "3FD7B9EB6A00376E5BE61F01ABB429FFB0B104BE05EAFF4D458DA48FCD425BAF");

    err = _toStringHash(&tx.blockHash, tmpBuffer, 100, 0, &pageCount);
    EXPECT_EQ(err, parser_ok) << parser_getErrorDescription(err);
    EXPECT_STREQ(tmpBuffer, "3FD7B9EB6A00376E5BE61F01ABB429FFB0B104BE05EAFF4D458DA48FCD425BAF");

    /* CHECK METHOD + ARGUMENTS */

    EXPECT_EQ(tx.callIndex.moduleIdx, 4);
    EXPECT_EQ(tx.callIndex.idx, 0);

    err = _getValue(&tx.method.balances_transfer.value.value, &tmp);
    EXPECT_EQ(err, parser_ok) << parser_getErrorDescription(err);
    EXPECT_EQ(tmp, 0);

    err = _toStringAddress(&tx.method.balances_transfer.dest, tmpBuffer, 100, 0, &pageCount);
    EXPECT_EQ(err, parser_ok) << parser_getErrorDescription(err);
    EXPECT_STREQ(tmpBuffer, "5FFhPjYsMtFXPbGgg2LC2Yjrnb8EMq5yhZXfBtgJs8T7TL3H");
}

