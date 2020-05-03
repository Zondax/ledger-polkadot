/*******************************************************************************
*   (c) 2018 Zondax GmbH
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

#include "hexutils.h"

TEST(HEXUTILS, parseHexString) {
    char s[] = "1234567890";
    uint8_t data[100];

    auto length = parseHexString(data, sizeof(data), s);

    ASSERT_THAT(length, testing::Eq(5));

    ASSERT_THAT(data[0], testing::Eq(0x12));
    ASSERT_THAT(data[1], testing::Eq(0x34));
    ASSERT_THAT(data[2], testing::Eq(0x56));
    ASSERT_THAT(data[3], testing::Eq(0x78));
    ASSERT_THAT(data[4], testing::Eq(0x90));
}

TEST(HEXUTILS, parseHexString2) {
    char s[] = "be333be7ee";
    uint8_t data[100];

    auto length = parseHexString(data, sizeof(data), s);

    ASSERT_THAT(length, testing::Eq(5));

    ASSERT_THAT(data[0], testing::Eq(0xbe));
    ASSERT_THAT(data[1], testing::Eq(0x33));
    ASSERT_THAT(data[2], testing::Eq(0x3b));
    ASSERT_THAT(data[3], testing::Eq(0xe7));
    ASSERT_THAT(data[4], testing::Eq(0xee));
}
