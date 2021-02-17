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

#include "gmock/gmock.h"

#include <iostream>
#include <hexutils.h>
#include <parser_txdef.h>
#include <parser.h>
#include <substrate_functions.h>
#include "parser_impl.h"

using ::testing::TestWithParam;

typedef struct {
    uint16_t pageSize;
    uint16_t pageIndex;
    std::string input;
    std::string expected;
    uint16_t expectedPageCount;
} testcase_bytestPrint_t;

class BytesPrintTests : public ::testing::TestWithParam<testcase_bytestPrint_t> {
};

INSTANTIATE_TEST_SUITE_P

(
    BytesPrintTestcases,
    BytesPrintTests,
    ::testing::ValuesIn(
        {
            // pageSize, pageIndex, input, expected
            testcase_bytestPrint_t{20, 0, "1234567890", "1234567890", 1},
            testcase_bytestPrint_t{6, 0, "1234567890", "1234", 3},
            testcase_bytestPrint_t{6, 1, "1234567890", "5678", 3},
            testcase_bytestPrint_t{6, 2, "1234567890", "90", 3},
            testcase_bytestPrint_t{5, 0, "1234567890", "1234", 3},
            testcase_bytestPrint_t{5, 1, "1234567890", "5678", 3},
            testcase_bytestPrint_t{5, 2, "1234567890", "90", 3},
            testcase_bytestPrint_t{4, 0, "1234567890", "12", 5},
            testcase_bytestPrint_t{4, 1, "1234567890", "34", 5},
            testcase_bytestPrint_t{4, 2, "1234567890", "56", 5},
            testcase_bytestPrint_t{4, 3, "1234567890", "78", 5},
            testcase_bytestPrint_t{4, 4, "1234567890", "90", 5},
        })
);

// Parametric Test. Printing long numbers + paging
TEST_P(BytesPrintTests, BytesPrinting) {
    parser_context_t ctx;
    parser_error_t err;

    uint8_t buffer[100];
    auto bufferLen = parseHexString(buffer, sizeof(buffer), GetParam().input.c_str());

    pd_Bytes_t b = {bufferLen, buffer};

    char tmpOut[100];
    uint8_t pageCount;
    err = _toStringBytes(&b, tmpOut, GetParam().pageSize, GetParam().pageIndex, &pageCount);
    EXPECT_EQ(err, parser_ok) << parser_getErrorDescription(err);

    EXPECT_EQ(std::string(tmpOut), GetParam().expected);
    EXPECT_EQ(pageCount, GetParam().expectedPageCount);
}
