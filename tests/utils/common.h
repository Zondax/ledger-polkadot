/*******************************************************************************
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
#pragma once

#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "parser_common.h"

using namespace std;

typedef struct {
    string filename;
    uint64_t index;
    string name;
    string blob;
    string metadata;
    string digest;
    vector<string> expected;
    vector<string> expected_expert;
} TestcaseGeneric_t;

class JsonTests : public ::testing::TestWithParam<TestcaseGeneric_t> {
   public:
    struct PrintToStringParamName {
        template <class ParamType>
        string operator()(const testing::TestParamInfo<ParamType> &info) const {
            auto p = static_cast<TestcaseGeneric_t>(info.param);
            stringstream ss;
            ss << p.filename << "_" << p.index << "_" << p.name;
            return ss.str();
        }
    };
};

vector<string> genericDumpUI(parser_tx_t *txObj);

vector<TestcaseGeneric_t> GetJsonTestCasesGeneric(const string &dir);

void check_testcase_generic(const TestcaseGeneric_t &testcase, bool expertMode);
