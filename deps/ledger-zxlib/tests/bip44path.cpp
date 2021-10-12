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
#include <gmock/gmock.h>
#include <zxmacros.h>
#include <zxformat.h>

namespace {
    TEST(MACROS, bip32empty) {
        char buffer[100];
        uint32_t path[] = {44, 60, 0, 0, 1};
        bip32_to_str(buffer, sizeof(buffer), path, 0);
        EXPECT_EQ("EMPTY PATH", std::string(buffer));
    }

    TEST(MACROS, bip32tooManyChildren) {
        char buffer[100];
        uint32_t path[] = {44, 60, 0, 0, 1};
        bip32_to_str(buffer, sizeof(buffer), path, 200);
        EXPECT_EQ("ERROR", std::string(buffer));
    }

    TEST(MACROS, bip32notEnoughSpaceInBuffer1) {
        char buffer[6];
        uint32_t path[] = {1234, 60, 0, 0, 1};
        bip32_to_str(buffer, sizeof(buffer), path, 5);
        EXPECT_EQ("ERROR", std::string(buffer));
    }

    TEST(MACROS, bip32notEnoughSpaceInBuffer2) {
        char buffer[9];
        uint32_t path[] = {1, 1, 1, 1, 1};
        bip32_to_str(buffer, sizeof(buffer), path, 5);
        EXPECT_EQ("ERROR", std::string(buffer));
    }

    TEST(MACROS, bip32notEnoughSpaceInBuffer3) {
        char buffer[10];
        uint32_t path[] = {1, 1, 1, 1, 0x80000001 };
        bip32_to_str(buffer, sizeof(buffer), path, 5);
        EXPECT_EQ("ERROR", std::string(buffer));
    }

    TEST(MACROS, bip32justEnoughSpaceInBuffer3) {
        char buffer[10];
        uint32_t path[] = {1, 1, 1, 1, 1};
        bip32_to_str(buffer, sizeof(buffer), path, 5);
        EXPECT_EQ("1/1/1/1/1", std::string(buffer));
    }

    TEST(MACROS, bip44path1) {
        uint32_t path[] = {44, 60, 0, 0, 1};

        char buffer[100];
        bip44_to_str(buffer, sizeof(buffer), path);

        EXPECT_EQ("44/60/0/0/1", std::string(buffer));
    }

    TEST(MACROS, bip44path2) {
        uint32_t path[] = {0x8000002c, 60, 0, 0, 1};

        char buffer[100];
        bip44_to_str(buffer, sizeof(buffer), path);

        EXPECT_EQ("44'/60/0/0/1", std::string(buffer));
    }

    TEST(MACROS, bip44path3) {
        uint32_t path[] = {0x8000002c, 60, 0, 0, 0x80000001};

        char buffer[100];
        bip44_to_str(buffer, sizeof(buffer), path);

        EXPECT_EQ("44'/60/0/0/1'", std::string(buffer));
    }
}
