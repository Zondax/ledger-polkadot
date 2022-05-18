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
#include <hexutils.h>
#include "crypto_helper.h"

TEST(SS58, PrefixEncodingSingleByte) {
    uint8_t prefixBytes[2];

    for (uint16_t addressType = 0; addressType < 64; addressType++) {
        const uint8_t prefixSize = crypto_SS58CalculatePrefix(addressType, prefixBytes);
        EXPECT_EQ(prefixSize, 1);
        EXPECT_EQ(prefixBytes[0], addressType);
    }
}

TEST(SS58, PrefixEncodingDualByte1) {
    uint8_t prefixBytes[2];

    const uint16_t addressType = 64;
    const uint8_t expected0 = 80;
    const uint8_t expected1 = 0;

    const uint8_t prefixSize = crypto_SS58CalculatePrefix(addressType, prefixBytes);
    EXPECT_EQ(prefixSize, 2);
    EXPECT_EQ(prefixBytes[0], expected0);
    EXPECT_EQ(prefixBytes[1], expected1);
}

TEST(SS58, PrefixEncodingDualByte2) {
    uint8_t prefixBytes[2];

    const uint16_t addressType = 10041;
    const uint8_t expected0 = 78;
    const uint8_t expected1 = 103;

    const uint8_t prefixSize = crypto_SS58CalculatePrefix(addressType, prefixBytes);
    EXPECT_EQ(prefixSize, 2);
    EXPECT_EQ(prefixBytes[0], expected0);
    EXPECT_EQ(prefixBytes[1], expected1);
}

TEST(SS58, PrefixEncodingDualByte3) {
    uint8_t prefixBytes[2];

    const uint16_t addressType = 16002;
    const uint8_t expected0 = 96;
    const uint8_t expected1 = 190;

    const uint8_t prefixSize = crypto_SS58CalculatePrefix(addressType, prefixBytes);
    EXPECT_EQ(prefixSize, 2);
    EXPECT_EQ(prefixBytes[0], expected0);
    EXPECT_EQ(prefixBytes[1], expected1);
}
