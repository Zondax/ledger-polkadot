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

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <hexutils.h>
#include <parser_txdef.h>
#include "common/parser.h"
#include "common.h"

std::vector<std::string> dumpUI(parser_context_t *ctx,
                                uint16_t maxKeyLen,
                                uint16_t maxValueLen) {
    uint8_t numItems;

    parser_getNumItems(ctx, &numItems);

    auto answer = std::vector<std::string>();

    char keyBuffer[40];
    char valueBuffer[40];
    for (uint16_t idx = 0; idx < numItems; idx++) {
        uint8_t pageIdx = 0;
        uint8_t pageCount = 1;

        while (pageIdx < pageCount) {
            std::stringstream ss;

            auto err = parser_getItem(ctx,
                                      idx,
                                      keyBuffer, maxKeyLen,
                                      valueBuffer, maxValueLen,
                                      pageIdx, &pageCount);

            ss << idx << " | " << keyBuffer << " : ";

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

