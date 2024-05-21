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
#include <gtest/gtest.h>

#include <filesystem>
#include <string>
#include <vector>

#include "utils/common.h"

using namespace std;
using namespace std::filesystem;

vector<string> FindJSONFilesInFolder(const string &folder) {
    vector<string> json_files;
    const string fullPath = string(TESTVECTORS_DIR) + folder;
    for (const auto &entry : directory_iterator(fullPath)) {
        if (entry.path().extension() == ".json") {
            json_files.push_back(entry.path().string());
        }
    }
    return json_files;
}

INSTANTIATE_TEST_SUITE_P(PolkadotGeneric,
                         JsonTests,
                         ::testing::ValuesIn(GetJsonTestCasesGeneric("supported_chains")),
                         JsonTests::PrintToStringParamName());

TEST_P(JsonTests, TransactionsNormal) {
    check_testcase_generic(GetParam(), false);
}

TEST_P(JsonTests, TransactionsExpert) {
    check_testcase_generic(GetParam(), true);
}
