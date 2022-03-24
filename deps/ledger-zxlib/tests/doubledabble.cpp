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

#include <hexutils.h>
#include "bignum.h"

using ::testing::TestWithParam;
using ::testing::Values;

typedef struct {
    std::string hex;
    std::string expectedOutput;
} bignum_testcase_t;

class BignumLittleEndianTests : public ::testing::TestWithParam<bignum_testcase_t> {
};

class BignumBigEndianTests : public ::testing::TestWithParam<bignum_testcase_t> {
};

INSTANTIATE_TEST_SUITE_P

(
        BignumTestCases, BignumLittleEndianTests, testing::Values(
        bignum_testcase_t{"00", "0"},
        bignum_testcase_t{"01", "1"},
        bignum_testcase_t{"0001", "256"},
        bignum_testcase_t{"03E8", "59395"},
        bignum_testcase_t{"E803", "1000"},
        bignum_testcase_t{"10", "16"},
        bignum_testcase_t{"FF01", "511"},
        bignum_testcase_t{"0102", "513"},
        bignum_testcase_t{"FFFF01", "131071"},
        bignum_testcase_t{"a08601", "100000"},
        bignum_testcase_t{"40420f", "1000000"},
        bignum_testcase_t{"809698", "10000000"},
        bignum_testcase_t{"002d3101", "20000000"},
        bignum_testcase_t{"00e1f505", "100000000"},
        bignum_testcase_t{"00407a10f35a", "100000000000000"},
        bignum_testcase_t{"d2029649", "1234567890"},
        bignum_testcase_t{"d20a3fce96f1cf8c9cb4378c37a4873f17621ebce404f5aa13",
                          "123456789012345678901234567890123456789012345678901234567890"}
));

// Check that bignums are printed properly (parametric tests)
TEST_P(BignumLittleEndianTests, print) {
    auto testcase = GetParam();

    uint8_t inBuffer[100];
    auto inBufferLen = parseHexString(inBuffer, sizeof(inBuffer), testcase.hex.c_str());

    uint8_t bcdOut[100];
    uint16_t bcdOutLen = sizeof(bcdOut);

    bignumLittleEndian_to_bcd(bcdOut, bcdOutLen, inBuffer, static_cast<uint16_t>(inBufferLen));

    char bufferUI[300];
    bignumLittleEndian_bcdprint(bufferUI, sizeof(bufferUI), bcdOut, bcdOutLen);
    EXPECT_THAT(std::string(bufferUI), testing::Eq(testcase.expectedOutput));
}

// Check that bignums are printed properly (range tests)
TEST(BignumLittleEndianTests, range) {
    uint8_t inBuffer[100];

    for (uint64_t i = 0; i < 10000; i++) {
        std::stringstream s;
        uint64_t tmp = i;
        while (tmp != 0) {
            s << std::setfill('0') << std::setw(2) << std::hex << tmp % 256;
            tmp /= 256;
        }
        auto inBufferLen = parseHexString(inBuffer, sizeof(inBuffer), s.str().c_str());

        uint8_t bcdOut[100];
        uint16_t bcdOutLen = sizeof(bcdOut);
        bignumLittleEndian_to_bcd(bcdOut, bcdOutLen, inBuffer, static_cast<uint16_t>(inBufferLen));
        char bufferUI[300];
        bignumLittleEndian_bcdprint(bufferUI, sizeof(bufferUI), bcdOut, bcdOutLen);

        std::stringstream expected;
        expected << i;
        EXPECT_THAT(std::string(bufferUI), testing::Eq(expected.str())) << s.str();
    }
}

INSTANTIATE_TEST_SUITE_P

(
        BignumTestCases, BignumBigEndianTests, testing::Values(
        bignum_testcase_t{"00", "0"},
        bignum_testcase_t{"01", "1"},
        bignum_testcase_t{"0001", "1"},
        bignum_testcase_t{"000001", "1"},
        bignum_testcase_t{"03E8", "1000"},
        bignum_testcase_t{"E803", "59395"},
        bignum_testcase_t{"10", "16"},
        bignum_testcase_t{"FF01", "65281"},
        bignum_testcase_t{"01FF", "511"},
        bignum_testcase_t{"0102", "258"},
        bignum_testcase_t{"FFFF01", "16776961"},
        bignum_testcase_t{"a08601", "10520065"},
        bignum_testcase_t{"40420f", "4211215"},
        bignum_testcase_t{"809698", "8427160"},
        bignum_testcase_t{"002d3101", "2961665"},
        bignum_testcase_t{"00e1f505", "14808325"},
        bignum_testcase_t{"00407a10f35a", "276925838170"},
        bignum_testcase_t{"d2029649", "3523384905"},
        bignum_testcase_t{"d20a3fce96f1cf8c9cb4378c37a4873f17621ebce404f5aa13",
                          "1318442675213289749221432902819395197389189473307425559128595"}
));

// Check that bignums are printed properly (parametric tests)
TEST_P(BignumBigEndianTests, print) {
    auto testcase = GetParam();

    uint8_t inBuffer[100];
    auto inBufferLen = parseHexString(inBuffer, sizeof(inBuffer), testcase.hex.c_str());

    uint8_t bcdOut[100];
    uint16_t bcdOutLen = sizeof(bcdOut);
    bignumBigEndian_to_bcd(bcdOut, bcdOutLen, inBuffer, static_cast<uint16_t>(inBufferLen));

    char bufferUI[300];
    bignumBigEndian_bcdprint(bufferUI, sizeof(bufferUI), bcdOut, bcdOutLen);
    EXPECT_THAT(std::string(bufferUI), testing::Eq(testcase.expectedOutput));
}

// Check that bignums are printed properly (range tests)
TEST(BignumBigEndianTests, range) {
    uint8_t inBuffer[100];

    for (uint64_t i = 0; i < 2500; i += 7) {
        std::stringstream s;
        s << std::setfill('0') << std::setw(10) << std::hex << i;
        std::cout << s.str() << std::endl;
        auto inBufferLen = parseHexString(inBuffer, sizeof(inBuffer), s.str().c_str());

        uint8_t bcdOut[100];
        uint16_t bcdOutLen = sizeof(bcdOut);
        bignumBigEndian_to_bcd(bcdOut, bcdOutLen, inBuffer, static_cast<uint16_t>(inBufferLen));
        char bufferUI[300];
        bignumBigEndian_bcdprint(bufferUI, sizeof(bufferUI), bcdOut, bcdOutLen);

        std::stringstream expected;
        expected << i;
        EXPECT_THAT(std::string(bufferUI), testing::Eq(expected.str())) << s.str();
    }
}
