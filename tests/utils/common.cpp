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
#include "common.h"

#include <app_mode.h>
#include <hexutils.h>
#include <json/json.h>

#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "gmock/gmock.h"
#include "parser.h"

#define MAX_KEY_LEN 39U
#define MAX_VAL_LEN 39U

using namespace std;

vector<string> genericDumpUI(parser_tx_t *txObj) {
    auto answer = vector<string>();

    uint8_t numItems = 0;
    parser_error_t err = parser_getNumItems(txObj, &numItems);
    if (err != parser_ok) {
        return answer;
    }

    for (uint8_t idx = 0; idx < numItems; idx++) {
        char keyBuffer[MAX_KEY_LEN] = {0};
        char valueBuffer[MAX_VAL_LEN] = {0};
        uint8_t pageCount = 1;

        ui_field_t uiFields = {.displayIdx = idx,
                               .outKey = keyBuffer,
                               .outKeyLen = sizeof(keyBuffer),
                               .outVal = valueBuffer,
                               .outValLen = sizeof(valueBuffer),
                               .pageIdx = 0,
                               .pageCount = &pageCount};

        while (uiFields.pageIdx < *uiFields.pageCount) {
            stringstream ss;

            err = parser_getItem(txObj, &uiFields);

            ss << (int)idx << " | " << keyBuffer;
            if (pageCount > 1) {
                ss << " [" << (int)uiFields.pageIdx + 1 << "/" << (int)*uiFields.pageCount << "]";
            }
            ss << " : ";

            if (err == parser_ok) {
                ss << valueBuffer;
            } else {
                ss << parser_getErrorDescription(err);
            }

            answer.push_back(ss.str());

            uiFields.pageIdx++;
        }
    }

    return answer;
}

vector<TestcaseGeneric_t> GetJsonTestCasesGeneric(const string &dir) {
    vector<string> json_files;
    const string fullPath = string(TESTVECTORS_DIR) + dir;
    for (const auto &entry : filesystem::directory_iterator(fullPath)) {
        if (entry.path().extension() == ".json") {
            json_files.push_back(entry.path().string());
        }
    }
    auto answer = vector<TestcaseGeneric_t>();

    for (const auto &filename : json_files) {
        ifstream inFile(filename);

        // for filename we want the last entry of the path without `.json`
        const size_t slashPos = filename.find_last_of('/');
        string filenameShort = filename.substr(slashPos + 1, filename.length() - slashPos - 6);
        replace(filenameShort.begin(), filenameShort.end(), '-', '_');
        replace(filenameShort.begin(), filenameShort.end(), '.', '_');
        if (inFile.is_open()) {
            const Json::CharReaderBuilder builder;
            Json::Value entries;
            JSONCPP_STRING errs;

            if (Json::parseFromStream(builder, inFile, &entries, &errs)) {
                cout << "Number of testcases: " << entries.size() << endl;
                // TestcaseGeneric_t chainTests;
                auto tests = TestcaseGeneric_t();
                for (const auto &entry : entries) {
                    auto outputs = vector<string>();
                    for (const auto &s : entry["output"]) {
                        outputs.push_back(s.asString());
                    }

                    auto outputs_expert = vector<string>();
                    for (const auto &s : entry["output_expert"]) {
                        outputs_expert.push_back(s.asString());
                    }
                    answer.push_back(TestcaseGeneric_t{filenameShort, entry["index"].asUInt64(), entry["name"].asString(),
                                                       entry["blob"].asString(), entry["metadata"].asString(),
                                                       entry["digest"].asString(), outputs, outputs_expert});
                }
            } else {
                cerr << "Failed to parse JSON: " << errs << endl;
            }
            inFile.close();
        }
    }

    return answer;
}

void check_testcase_generic(const TestcaseGeneric_t &testcase, bool expertMode) {
    app_mode_set_expert(static_cast<uint8_t>(expertMode));

    uint8_t inputBuffer[16384] = {0};

    // Parse blob
    const uint16_t blobLen = parseHexString(inputBuffer, sizeof(inputBuffer), testcase.blob.c_str());
    ASSERT_NE(blobLen, 0);

    // Parse short metadata
    const uint16_t metadataLen =
        parseHexString(inputBuffer + blobLen, sizeof(inputBuffer) - blobLen, testcase.metadata.c_str());
    ASSERT_NE(metadataLen, 0);

    parser_tx_t txObj = {0};
    const parser_error_t err = parser_parse(&txObj, inputBuffer, (blobLen + metadataLen), blobLen);
    ASSERT_EQ(err, parser_ok) << parser_getErrorDescription(err);

    uint8_t digest[32 + 1] = {0};
    parseHexString(digest, sizeof(digest), testcase.digest.c_str());
    EXPECT_EQ(memcmp(digest, txObj.metadataDigest, sizeof(txObj.metadataDigest)), 0);

    auto output = genericDumpUI(&txObj);

    cout << endl;
    for (const auto &i : output) {
        cout << i << endl;
    }
    cout << endl << endl;

    const vector<string> expected = app_mode_expert() ? testcase.expected_expert : testcase.expected;
    EXPECT_EQ(expected.empty(), false) << "Expected values are empty";
    EXPECT_EQ(output.size(), expected.size());

    auto expectedLine = expected.begin();
    for (const auto &outputLine : output) {
        if (expectedLine != expected.end()) {
            EXPECT_THAT(outputLine, testing::Eq(*expectedLine));
            expectedLine++;
        }
    }
}
