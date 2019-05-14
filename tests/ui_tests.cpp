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
#include <lib/parser_txdef.h>
#include "lib/parser.h"

using ::testing::TestWithParam;
using ::testing::Values;

std::string dumpUI(parser_context_t *ctx) {
    std::stringstream ss;

    uint16_t numItems = parser_getNumItems(ctx);

    for (uint16_t idx = 0; idx < numItems; idx++) {
        char keyBuffer[40];
        char valueBuffer[40];
        uint8_t pageIdx = 0;
        uint8_t pageCount = 1;

        while (pageIdx < pageCount) {
            parser_getItem(ctx, idx, keyBuffer, 40, valueBuffer, 40, pageIdx, &pageCount);
            ss << idx << " ";
            ss << (int) pageIdx + 1 << "/" << (int) pageCount << " ";
            ss << keyBuffer << " : ";
            ss << valueBuffer;
            ss << std::endl;

            pageIdx++;
        }
    }

    std::cout << std::endl;
    std::cout << ss.str() << std::endl;

    return ss.str();
}

TEST(UI, FullTransferKusama) {
    parser_context_t ctx;
    parser_error_t err;

    const auto testTx = "0400ff8d16d62802ca55326ec52bf76a8543b90e2aba5bcf6cd195c0d6fc1ef38fa1b3000600ae11030000c801"
                        "00003fd7b9eb6a00376e5be61f01abb429ffb0b104be05eaff4d458da48fcd425baf3fd7b9eb6a00376e5be61f"
                        "01abb429ffb0b104be05eaff4d458da48fcd425baf";

    uint8_t buffer[200];
    auto bufferLen = parseHexString(testTx, buffer);

    err = parser_parse(&ctx, buffer, bufferLen);
    EXPECT_EQ(err, parser_ok);

    std::string expected = "0 1/1 Balances : Transfer\n"
                           "1 1/2 Dest : FmK43tjzFGT9F68Sj9EvW6rwBQUAVuA9wNQaYxG\n"
                           "1 2/2 Dest : LvfcCAxS\n"
                           "2 1/1 Value : 0\n"
                           "3 1/1 Chain : KUSAMA\n"
                           "4 1/1 Nonce : 50283\n"
                           "5 1/1 Tip : 0\n"
                           "6 1/1 Era Phase : 0\n"
                           "7 1/1 Era Period : 128\n"
                           "8 1/2 Block : 3FD7B9EB6A00376E5BE61F01ABB429FFB0B104B\n"
                           "8 2/2 Block : E05EAFF4D458DA48FCD425BAF\n";
    auto output = dumpUI(&ctx);

    EXPECT_EQ(output, expected);
}

TEST(UI, KusamaOtherTx) {
    parser_context_t ctx;
    parser_error_t err;

    const auto testTx = "060387070400c80100003fd7b9eb6a00376e5be61f01abb429ffb0b104be05eaff4d458da48fcd425bafec7af"
                        "af1cca720ce88c1d1b689d81f0583cc15a97d621cf046dd9abf605ef22f";

    uint8_t buffer[200];
    auto bufferLen = parseHexString(testTx, buffer);

    err = parser_parse(&ctx, buffer, bufferLen);
    EXPECT_EQ(err, parser_ok) << parser_getErrorDescription(err);

    std::string expected = "0 1/1 Staking : Withdraw unbonded\n"
                           "1 1/1 Chain : KUSAMA\n"
                           "2 1/1 Nonce : 1\n"
                           "3 1/1 Tip : 0\n"
                           "4 1/1 Era Phase : 120\n"
                           "5 1/1 Era Period : 256\n"
                           "6 1/2 Block : EC7AFAF1CCA720CE88C1D1B689D81F0583CC15A\n"
                           "6 2/2 Block : 97D621CF046DD9ABF605EF22F\n";

    auto output = dumpUI(&ctx);

    EXPECT_EQ(output, expected);
}
