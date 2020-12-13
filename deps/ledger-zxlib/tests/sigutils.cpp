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
#include <zxmacros.h>

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

TEST(SIGUTILS, convertBasic2) {
    char inSignatureDERStr[] = "30430220035942178e9e8d447cf9e6886f99c41bf942fb2880fd79aa2d4626489ec7821b021f6b3277dea0355c161d20a120ec9165500b5c9a2cd0fce1c4b8a5260bf6831f";
    auto inSignatureDER = std::vector<uint8_t>(71);

    auto length = parseHexString(inSignatureDER.data(), inSignatureDER.size(), inSignatureDERStr);
    EXPECT_EQ(length, sizeof(inSignatureDERStr) / 2);

    uint8_t R[32];
    uint8_t S[32];
    uint8_t V;

    auto ret = convertDERtoRSV(inSignatureDER.data(), 0, R, S, &V);
    EXPECT_EQ(ret, 0);

    char inSignatureDERStr_R[] = "035942178e9e8d447cf9e6886f99c41bf942fb2880fd79aa2d4626489ec7821b";
    char inSignatureDERStr_S[] = "006b3277dea0355c161d20a120ec9165500b5c9a2cd0fce1c4b8a5260bf6831f";
    auto inSignatureDER_R = std::vector<uint8_t>(32);
    auto inSignatureDER_S = std::vector<uint8_t>(32);
    parseHexString(inSignatureDER_R.data(), inSignatureDER_R.size(), inSignatureDERStr_R);
    parseHexString(inSignatureDER_S.data(), inSignatureDER_S.size(), inSignatureDERStr_S);

    char buffer[100];
    array_to_hexstr(buffer, sizeof(buffer), R, (int16_t) sizeof(R));
    std::cout << buffer << std::endl;
    array_to_hexstr(buffer, sizeof(buffer), S, (int16_t) sizeof(S));
    std::cout << buffer << std::endl;

    EXPECT_THAT(R, ::testing::ElementsAreArray(inSignatureDER_R));
    EXPECT_THAT(S, ::testing::ElementsAreArray(inSignatureDER_S));
}

TEST(SIGUTILS, convertBasic3) {
    char inSignatureDERStr[] = "3045022100e9b508a9cd66410b43992c01622cf9e1a6aa1353d836d7f428a6d1317f96f27d02200ca01cee5480388bad3802c08e0bcf357c091f3a5921e1e5d1e0e115dd14ff23";
    auto inSignatureDER = std::vector<uint8_t>(71);

    auto length = parseHexString(inSignatureDER.data(), inSignatureDER.size(), inSignatureDERStr);
    EXPECT_EQ(length, sizeof(inSignatureDERStr) / 2);

    uint8_t R[32];
    uint8_t S[32];
    uint8_t V;

    auto ret = convertDERtoRSV(inSignatureDER.data(), 0, R, S, &V);
    EXPECT_EQ(ret, 0);

    char inSignatureDERStr_R[] = "e9b508a9cd66410b43992c01622cf9e1a6aa1353d836d7f428a6d1317f96f27d";
    char inSignatureDERStr_S[] = "0ca01cee5480388bad3802c08e0bcf357c091f3a5921e1e5d1e0e115dd14ff23";
    auto inSignatureDER_R = std::vector<uint8_t>(32);
    auto inSignatureDER_S = std::vector<uint8_t>(32);
    parseHexString(inSignatureDER_R.data(), inSignatureDER_R.size(), inSignatureDERStr_R);
    parseHexString(inSignatureDER_S.data(), inSignatureDER_S.size(), inSignatureDERStr_S);

    EXPECT_THAT(R, ::testing::ElementsAreArray(inSignatureDER_R));
    EXPECT_THAT(S, ::testing::ElementsAreArray(inSignatureDER_S));
}

TEST(SIGUTILS, convertShort1) {
    char inSignatureDERStr[] = "3041021e544670fe5627f2d483484582284f627d9cfd1e0ab123984e81611a8da4fc021f6d99f9afd3c4fa62cee8dff21786f9c23c8d2f524d8fd363acc6c6567dc380";
    char inSignatureDERStr_R[] = "0000544670fe5627f2d483484582284f627d9cfd1e0ab123984e81611a8da4fc";
    char inSignatureDERStr_S[] = "006d99f9afd3c4fa62cee8dff21786f9c23c8d2f524d8fd363acc6c6567dc380";

    auto inSignatureDER = std::vector<uint8_t>(sizeof(inSignatureDERStr));

    auto length = parseHexString(inSignatureDER.data(), inSignatureDER.size(), inSignatureDERStr);
    EXPECT_EQ(length, sizeof(inSignatureDERStr) / 2);

    uint8_t R[32];
    uint8_t S[32];
    uint8_t V;

    auto ret = convertDERtoRSV(inSignatureDER.data(), 0, R, S, &V);
    EXPECT_EQ(ret, 0);


    char R_str[200];
    char S_str[200];
    array_to_hexstr(R_str, sizeof(R_str), R, 32);
    std::cout << R_str << std::endl;
    array_to_hexstr(S_str, sizeof(S_str), S, 32);
    std::cout << S_str << std::endl;

    EXPECT_STREQ(R_str, inSignatureDERStr_R);
    EXPECT_STREQ(S_str, inSignatureDERStr_S);
}
