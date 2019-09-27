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
#include <fstream>
#include <nlohmann/json.hpp>
#include <lib/parser_txdef.h>
#include "lib/parser.h"
#include "common.h"

using ::testing::TestWithParam;
using ::testing::Values;
using json = nlohmann::json;

typedef struct {
    uint64_t index;
    std::string name;
    std::string blob;
    std::vector<std::string> expected;
} testcase_t;

class ManualTests : public ::testing::TestWithParam<testcase_t> {
public:
    struct PrintToStringParamName {
        template<class ParamType>
        std::string operator()(const testing::TestParamInfo<ParamType> &info) const {
            auto p = static_cast<testcase_t>(info.param);
            std::stringstream ss;
            ss << p.index << "_" << p.name;
            return ss.str();
        }
    };
};

class JsonTests : public ::testing::TestWithParam<testcase_t> {
public:
    struct PrintToStringParamName {
        template<class ParamType>
        std::string operator()(const testing::TestParamInfo<ParamType> &info) const {
            auto p = static_cast<testcase_t>(info.param);
            std::stringstream ss;
            ss << p.index << "_" << p.name;
            return ss.str();
        }
    };
};

std::vector<testcase_t> GetManualTestCases() {
    return std::vector<testcase_t>({
                                       testcase_t{
                                           0,
                                           "",
                                           "0400ff8d16d62802ca55326ec52bf76a8543b90e2aba5bcf6cd195c0d6fc1ef38fa1b"
                                           "3000600ae11030000c80100003fd7b9eb6a00376e5be61f01abb429ffb0b104be05eaff4d45"
                                           "8da48fcd425baf3fd7b9eb6a00376e5be61f01abb429ffb0b104be05eaff4d458da48fcd425"
                                           "baf",
                                           {
                                               "0 1/1 Balances : Transfer",
                                               "1 1/2 Dest : FmK43tjzFGT9F68Sj9EvW6rwBQUAVuA9wNQaYxG",
                                               "1 2/2 Dest : LvfcCAxS",
                                               "2 1/1 Value : 0.000000000000",
                                               "3 1/1 Chain : KUSAMA",
                                               "4 1/1 Nonce : 50283",
                                               "5 1/1 Tip : 0.000000000000",
                                               "6 1/1 Era Phase : 0",
                                               "7 1/1 Era Period : 128",
                                               "8 1/2 Block : 3FD7B9EB6A00376E5BE61F01ABB429FFB0B104B",
                                               "8 2/2 Block : E05EAFF4D458DA48FCD425BAF"
                                           }
                                       },
////////////
                                       testcase_t{
                                           1,
                                           "",
                                           "060387070400c80100003fd7b9eb6a00376e5be61f01abb429ffb0b104be05eaff4d4"
                                           "58da48fcd425bafec7afaf1cca720ce88c1d1b689d81f0583cc15a97d621cf046dd9abf605e"
                                           "f22f",
                                           {
                                               "0 1/1 Staking : Withdraw unbonded",
                                               "1 1/1 Chain : KUSAMA",
                                               "2 1/1 Nonce : 1",
                                               "3 1/1 Tip : 0.000000000000",
                                               "4 1/1 Era Phase : 120",
                                               "5 1/1 Era Period : 256",
                                               "6 1/2 Block : EC7AFAF1CCA720CE88C1D1B689D81F0583CC15A",
                                               "6 2/2 Block : 97D621CF046DD9ABF605EF22F"
                                           }
                                       },
////////////
                                       testcase_t{
                                           2,
                                           "",
                                           "0400ff8eaf04151687736326c9fea17e25fc5287613693"
                                           "c912909cb226aa4794f26a4833158139ae28a3dfaac5fe1560a5"
                                           "e9e05c1100ae11030000c8010000ec7afaf1cca720ce88c1d1b6"
                                           "89d81f0583cc15a97d621cf046dd9abf605ef22fec7afaf1cca7"
                                           "20ce88c1d1b689d81f0583cc15a97d621cf046dd9abf605ef22f",
                                           {
                                               "0 1/1 Balances : Transfer",
                                               "1 1/2 Dest : 5FHneW46xGXgs5mUiveU4sbTyGBzmstUspZC92U",
                                               "1 2/2 Dest : hjJM694ty",
                                               "2 1/2 Value : 123456789012345678901234567.89012345678",
                                               "2 2/2 Value : 9",
                                               "3 1/2 Genesis Hash : EC7AFAF1CCA720CE88C1D1B689D81F0583CC15A",
                                               "3 2/2 Genesis Hash : 97D621CF046DD9ABF605EF22F",
                                               "4 1/1 Nonce : 50283",
                                               "5 1/1 Tip : 0.000000000000",
                                               "6 1/1 Era Phase : 1",
                                               "7 1/1 Era Period : 4",
                                               "8 1/2 Block : EC7AFAF1CCA720CE88C1D1B689D81F0583CC15A",
                                               "8 2/2 Block : 97D621CF046DD9ABF605EF22F",
                                           }
                                       },
////////////
                                       testcase_t{
                                           3,
                                           "",
                                           "0600ff8eaf04151687736326c9fea17e25fc5287613693c912909cb226aa479"
                                           "4f26a4833158139ae28a3dfaac5fe1560a5e9e05c000100ae11030000c80"
                                           "10000ec7afaf1cca720ce88c1d1b689d81f0583cc15a97d621cf046dd9ab"
                                           "f605ef22fec7afaf1cca720ce88c1d1b689d81f0583cc15a97d621cf046dd9abf605ef22f",
                                           {
                                               "0 1/1 Balances : Transfer",
                                               "1 1/2 Dest : 5FHneW46xGXgs5mUiveU4sbTyGBzmstUspZC92U",
                                               "1 2/2 Dest : hjJM694ty",
                                               "2 1/1 Value : 123456789012345678901234567890123456789",
                                               "3 1/2 Genesis Hash : EC7AFAF1CCA720CE88C1D1B689D81F0583CC15A",
                                               "3 2/2 Genesis Hash : 97D621CF046DD9ABF605EF22F",
                                               "4 1/1 Nonce : 50283",
                                               "5 1/1 Tip : 0",
                                               "6 1/1 Era Phase : 1",
                                               "7 1/1 Era Period : 4",
                                               "8 1/2 Block : EC7AFAF1CCA720CE88C1D1B689D81F0583CC15A",
                                               "8 2/2 Block : 97D621CF046DD9ABF605EF22F",
                                           }
                                       },
                                   });
}

std::vector<testcase_t> GetJsonTestCases() {
    auto answer = std::vector<testcase_t>();

    json j;
    std::ifstream inFile("testcases.json");
    EXPECT_TRUE(inFile.is_open()) << "Check that your working directory is pointing to the tests directory";
    inFile >> j;

    std::cout << "Number of testcases: " << j.size() << std::endl;

    for (auto &item : j) {
        answer.push_back(testcase_t{
            item["index"],
            item["name"],
            item["blob"],
            item["output"]
        });
    }

    return answer;
}

void check_testcase(const testcase_t &tc) {
    parser_context_t ctx;
    parser_error_t err;

    uint8_t buffer[5000];

    uint16_t bufferLen = parseHexString(tc.blob.c_str(), buffer);

    err = parser_parse(&ctx, buffer, bufferLen);
    ASSERT_EQ(err, parser_ok) << parser_getErrorDescription(err);

    auto output = dumpUI(&ctx);

    for (size_t i = 0; i < tc.expected.size(); i++) {
        std::cout << output[i] << std::endl;
    }
    std::cout << std::endl << std::endl;

    EXPECT_EQ(output.size(), tc.expected.size());
    for (size_t i = 0; i < tc.expected.size(); i++) {
        if (i < output.size()) {
            EXPECT_THAT(output[i], testing::Eq(tc.expected[i]));
        }
    }
}

INSTANTIATE_TEST_CASE_P

(
    JsonTestCases,
    ManualTests,
    ::testing::ValuesIn(GetManualTestCases()),
    ManualTests::PrintToStringParamName()
);

TEST_P(ManualTests, CheckUIOutput) { check_testcase(GetParam()); }

INSTANTIATE_TEST_CASE_P

(
    JsonTestCases,
    JsonTests,
    ::testing::ValuesIn(GetJsonTestCases()),
    JsonTests::PrintToStringParamName()
);

TEST_P(JsonTests, CheckUIOutput) { check_testcase(GetParam()); }
