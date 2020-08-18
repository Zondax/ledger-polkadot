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
#include <parser.h>
#include <sstream>
#include <string>
#include "common.h"

std::vector<std::string> dumpUI(parser_context_t *ctx,
                                uint16_t maxKeyLen,
                                uint16_t maxValueLen) {
    auto answer = std::vector<std::string>();

    uint8_t numItems;
    parser_error_t err = parser_getNumItems(ctx, &numItems);
    if (err != parser_ok) {
        return answer;
    }

    for (uint16_t idx = 0; idx < numItems; idx++) {
        char keyBuffer[1000];
        char valueBuffer[1000];
        uint8_t pageIdx = 0;
        uint8_t pageCount = 1;

        while (pageIdx < pageCount) {
            std::stringstream ss;

            err = parser_getItem(ctx,
                                 idx,
                                 keyBuffer, maxKeyLen,
                                 valueBuffer, maxValueLen,
                                 pageIdx, &pageCount);

            ss << idx << " | " << keyBuffer;
            if (pageCount > 1) {
                ss << " [" << (int) pageIdx + 1 << "/" << (int) pageCount << "]";
            }
            ss << " : ";

            if (err == parser_ok) {
                ss << valueBuffer;
            } else {
                ss << parser_getErrorDescription(err);
            }

            answer.push_back(ss.str());

            pageIdx++;
        }
    }

    return answer;
}
