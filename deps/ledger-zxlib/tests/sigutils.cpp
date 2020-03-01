/*******************************************************************************
*   (c) 2020 Zondax GmbH
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
#include <string>
#include <hexutils.h>

#include "sigutils.h"

TEST(SIGUTILS, convertBasic) {
    char inSignatureDERStr[] = "304402206878b5690514437a2342405029426cc2b25b4a03fc396fef845d656cf62bad2c022018610a8d37e3384245176ab49ddbdbe8da4133f661bf5ea7ad4e3d2b912d856f01";
    auto inSignatureDER = std::vector<uint8_t>(71);

    auto length = parseHexString(inSignatureDER.data(), inSignatureDER.size(), inSignatureDERStr);
    EXPECT_EQ(length, sizeof(inSignatureDERStr) / 2);

    uint8_t R[32];
    uint8_t S[32];
    uint8_t V;

    auto ret = convertDERtoRSV(inSignatureDER.data(), 0, R, S, &V);
    EXPECT_EQ(ret, 0);

    char inSignatureDERStr_R[] = "6878b5690514437a2342405029426cc2b25b4a03fc396fef845d656cf62bad2c";
    char inSignatureDERStr_S[] = "18610a8d37e3384245176ab49ddbdbe8da4133f661bf5ea7ad4e3d2b912d856f";
    auto inSignatureDER_R = std::vector<uint8_t>(32);
    auto inSignatureDER_S = std::vector<uint8_t>(32);
    parseHexString(inSignatureDER_R.data(), inSignatureDER_R.size(), inSignatureDERStr_R);
    parseHexString(inSignatureDER_S.data(), inSignatureDER_S.size(), inSignatureDERStr_S);

    EXPECT_THAT(R, ::testing::ElementsAreArray(inSignatureDER_R));
    EXPECT_THAT(S, ::testing::ElementsAreArray(inSignatureDER_S));
}
