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
#include <fstream>
#include <json/json.h>
#include <hexutils.h>
#include <parser_txdef.h>
#include "parser.h"
#include "app_mode.h"
#include "utils/common.h"

using ::testing::TestWithParam;

typedef struct {
    uint64_t index;
    std::string name;
    std::string blob;
    std::vector<std::string> expected;
    std::vector<std::string> expected_expert;
} testcase_t;

class JsonTestsA : public ::testing::TestWithParam<testcase_t> {
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

class JsonTestsB : public ::testing::TestWithParam<testcase_t> {
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

// Retrieve testcases from json file
std::vector<testcase_t> GetJsonTestCases(const std::string &jsonFile) {
    auto answer = std::vector<testcase_t>();

    Json::CharReaderBuilder builder;
    Json::Value obj;

    std::string fullPathJsonFile = std::string(TESTVECTORS_DIR) + jsonFile;

    std::ifstream inFile(fullPathJsonFile);
    if (!inFile.is_open()) {
        return answer;
    }

    // Retrieve all test cases
    JSONCPP_STRING errs;
    Json::parseFromStream(builder, inFile, &obj, &errs);
    std::cout << "Number of testcases: " << obj.size() << std::endl;

    for (int i = 0; i < obj.size(); i++) {

        auto outputs = std::vector<std::string>();
        for (auto s: obj[i]["output"]) {
            outputs.push_back(s.asString());
        }

        auto outputs_expert = std::vector<std::string>();
        for (auto s: obj[i]["output_expert"]) {
            outputs_expert.push_back(s.asString());
        }

        answer.push_back(testcase_t{
                obj[i]["index"].asUInt64(),
                obj[i]["name"].asString(),
                obj[i]["blob"].asString(),
                outputs,
                outputs_expert
        });
    }

    return answer;
}

void check_testcase(const testcase_t &tc, bool expert_mode) {

    app_mode_set_expert(expert_mode);

    parser_context_t ctx;
    parser_error_t err;

    uint8_t buffer[5000];
    uint16_t bufferLen = parseHexString(buffer, sizeof(buffer), tc.blob.c_str());

    parser_tx_t tx_obj;
    err = parser_parse(&ctx, buffer, bufferLen, &tx_obj);
    ASSERT_EQ(err, parser_ok) << parser_getErrorDescription(err);

    auto output = dumpUI(&ctx, 39, 39);

    std::cout << std::endl;
    for (const auto &i: output) {
        std::cout << i << std::endl;
    }
    std::cout << std::endl << std::endl;

    std::vector<std::string> expected = app_mode_expert() ? tc.expected_expert : tc.expected;
    EXPECT_EQ(output.size(), expected.size());
    for (size_t i = 0; i < expected.size(); i++) {
        if (i < output.size()) {
            EXPECT_THAT(output[i], testing::Eq(expected[i]));
        }
    }
}

INSTANTIATE_TEST_SUITE_P

(
    JsonTestCasesCurrentTxVer,
    JsonTestsA,
    ::testing::ValuesIn(GetJsonTestCases("testcases_current.json")),
    JsonTestsA::PrintToStringParamName()
);


INSTANTIATE_TEST_SUITE_P

(
    JsonTestCasesPreviousTxVer,
    JsonTestsB,
    ::testing::ValuesIn(GetJsonTestCases("testcases_previous.json")),
    JsonTestsB::PrintToStringParamName()
);

// Parametric test using current runtime:
TEST_P(JsonTestsA, CheckUIOutput_CurrentTX_Normal) { check_testcase(GetParam(), false); }

TEST_P(JsonTestsA, CheckUIOutput_CurrentTX_Expert) { check_testcase(GetParam(), true); }

// Parametric test using previous runtime:
TEST_P(JsonTestsB, CheckUIOutput_PreviousTX_Normal) { check_testcase(GetParam(), false); }

TEST_P(JsonTestsB, CheckUIOutput_PreviousTX_Expert) { check_testcase(GetParam(), true); }
