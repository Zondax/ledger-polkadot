/*******************************************************************************
 *   (c) 2019 Zondax AG
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

#include "parser_impl.h"

#include <hexutils.h>
#include <parser.h>
#include <parser_txdef.h>

#include <iostream>

#include "gmock/gmock.h"
#define TEST_BUFFER_SIZE 100

// Test that we can parse SCALE-encoded unsigned integers correctly (uint8_t, uint16_t, uint32_t, uint64_t}
TEST(SCALE, UIntX) {
    parser_error_t err = parser_unexpected_error;
    uint8_t buffer[TEST_BUFFER_SIZE] = {0};
    const uint16_t bufferLen = parseHexString(buffer, sizeof(buffer),
                                              "45"
                                              "1234"
                                              "12345678"
                                              "1234567812345678");

    parser_context_t ctx = {.buffer = buffer, .bufferLen = bufferLen, .offset = 0};

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
    EXPECT_EQ(v64, 8671175386481439762);
}

// Parse SCALE-encoded booleans
TEST(SCALE, Bool) {
    uint8_t buffer[TEST_BUFFER_SIZE];
    uint16_t bufferLen = parseHexString(buffer, sizeof(buffer), "000102");

    parser_context_t ctx = {.buffer = buffer, .bufferLen = bufferLen, .offset = 0};

    bool value = false;
    parser_error_t err = parser_unexpected_value;

    err = readBool(&ctx, &value);
    EXPECT_EQ(err, parser_ok) << parser_getErrorDescription(err);
    EXPECT_EQ(value, false);

    err = readBool(&ctx, &value);
    EXPECT_EQ(err, parser_ok) << parser_getErrorDescription(err);
    EXPECT_EQ(value, true);

    err = readBool(&ctx, &value);
    EXPECT_EQ(err, parser_unexpected_value);
}

// Parse SCALE-encoded Compact numbers
TEST(SCALE, Compact) {
    parser_error_t err = parser_unexpected_error;

    uint8_t buffer[TEST_BUFFER_SIZE] = {0};
    uint16_t bufferLen = parseHexString(buffer, sizeof(buffer), "0004a815010100");
    parser_context_t ctx = {.buffer = buffer, .bufferLen = bufferLen, .offset = 0};

    CompactInt_t cvalue;
    uint64_t value;

    err = readCompactInt(&ctx, &cvalue);
    EXPECT_EQ(err, parser_ok) << parser_getErrorDescription(err);
    EXPECT_EQ(cvalue.len, 1);
    err = _getValue(&cvalue, &value);
    EXPECT_EQ(err, parser_ok) << parser_getErrorDescription(err);
    EXPECT_EQ(value, 0);

    err = readCompactInt(&ctx, &cvalue);
    EXPECT_EQ(err, parser_ok) << parser_getErrorDescription(err);
    EXPECT_EQ(cvalue.len, 1);
    err = _getValue(&cvalue, &value);
    EXPECT_EQ(err, parser_ok) << parser_getErrorDescription(err);
    EXPECT_EQ(value, 1);

    err = readCompactInt(&ctx, &cvalue);
    EXPECT_EQ(err, parser_ok) << parser_getErrorDescription(err);
    EXPECT_EQ(cvalue.len, 1);
    err = _getValue(&cvalue, &value);
    EXPECT_EQ(err, parser_ok) << parser_getErrorDescription(err);
    EXPECT_EQ(value, 42);

    err = readCompactInt(&ctx, &cvalue);
    EXPECT_EQ(err, parser_ok) << parser_getErrorDescription(err);
    EXPECT_EQ(cvalue.len, 2);
    err = _getValue(&cvalue, &value);
    EXPECT_EQ(err, parser_ok) << parser_getErrorDescription(err);
    EXPECT_EQ(value, 69);

    err = readCompactInt(&ctx, &cvalue);
    EXPECT_EQ(err, parser_ok) << parser_getErrorDescription(err);
    EXPECT_EQ(cvalue.len, 2);
    err = _getValue(&cvalue, &value);
    EXPECT_EQ(err, parser_value_out_of_range);
}

// Parse SCALE-encoded Compact numbers. Reproducing old known bug
TEST(SCALE, Compact2) {
    parser_error_t err = parser_unexpected_error;

    uint8_t buffer[TEST_BUFFER_SIZE];
    uint16_t bufferLen = parseHexString(buffer, sizeof(buffer), "e5c0");
    parser_context_t ctx = {.buffer = buffer, .bufferLen = bufferLen, .offset = 0};

    CompactInt_t cvalue;
    uint64_t value;

    err = readCompactInt(&ctx, &cvalue);
    EXPECT_EQ(err, parser_ok) << parser_getErrorDescription(err);
    EXPECT_EQ(cvalue.len, 2);
    err = _getValue(&cvalue, &value);
    EXPECT_EQ(err, parser_ok) << parser_getErrorDescription(err);
    EXPECT_EQ(value, 12345);
}

// Parse SCALE-encoded mortal era objects
TEST(SCALE, MortalEra) {
    parser_error_t err = parser_unexpected_error;

    uint8_t buffer[TEST_BUFFER_SIZE] = {0};
    uint16_t bufferLen = parseHexString(buffer, sizeof(buffer), "0100");
    parser_context_t ctx = {.buffer = buffer, .bufferLen = bufferLen, .offset = 0};

    pd_ExtrinsicEra_t v = {0};
    err = _readEra(&ctx, &v);
    EXPECT_EQ(err, parser_ok) << parser_getErrorDescription(err);
    EXPECT_EQ(v.isMortal, 1);
    EXPECT_EQ(v.phase, 0);
    EXPECT_EQ(v.period, 4);
}
