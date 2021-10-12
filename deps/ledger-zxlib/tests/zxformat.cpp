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
    TEST(FORMAT, nothingAdded) {
        char buffer[10];

        snprintf(buffer, sizeof(buffer), "TEST");
        auto prefix = std::string("");

        EXPECT_EQ(zxerr_ok, z_str3join(buffer, sizeof(buffer), prefix.c_str(), ""));
        EXPECT_STREQ(buffer, "TEST");
    }

    TEST(FORMAT, noPrefix) {
        char buffer[10];

        snprintf(buffer, sizeof(buffer), "TEST");
        auto prefix = std::string("");
        auto suffix = std::string("1");

        EXPECT_EQ(zxerr_ok, z_str3join(buffer, sizeof(buffer), prefix.c_str(), suffix.c_str()));
        EXPECT_STREQ(buffer, "TEST1");
    }

    TEST(FORMAT, prefixSimple) {
        char buffer[10];

        snprintf(buffer, sizeof(buffer), "TEST");
        auto prefix = std::string("xyz ");
        auto suffix = std::string("1");

        EXPECT_EQ(zxerr_ok, z_str3join(buffer, sizeof(buffer), prefix.c_str(), suffix.c_str()));
        EXPECT_STREQ(buffer, "xyz TEST1");
    }

    TEST(FORMAT, limitBuffer0) {
        char buffer[10];

        snprintf(buffer, sizeof(buffer), "TEST");
        auto prefix = std::string("xyz");
        auto suffix = std::string("4");

        EXPECT_EQ(zxerr_ok, z_str3join(buffer, sizeof(buffer), prefix.c_str(), suffix.c_str()));
        EXPECT_STREQ(buffer, "xyzTEST4");
    }

    TEST(FORMAT, limitBuffer1) {
        char buffer[9];

        snprintf(buffer, sizeof(buffer), "TEST");
        auto prefix = std::string("xyz");
        auto suffix = std::string("4");

        EXPECT_EQ(zxerr_ok, z_str3join(buffer, sizeof(buffer), prefix.c_str(), suffix.c_str()));
        EXPECT_STREQ(buffer, "xyzTEST4");
    }

    TEST(FORMAT, limitBuffer2) {
        char buffer[8];

        snprintf(buffer, sizeof(buffer), "TEST");
        auto prefix = std::string("xyz");
        auto suffix = std::string("4");

        EXPECT_EQ(zxerr_buffer_too_small, z_str3join(buffer, sizeof(buffer), prefix.c_str(), suffix.c_str()));
        EXPECT_STREQ(buffer, "ERR???");
    }

    TEST(FORMAT, smallBuffer) {
        char buffer[7];

        snprintf(buffer, sizeof(buffer), "TEST");
        auto prefix = std::string("xyz");
        auto suffix = std::string("4");

        EXPECT_EQ(zxerr_buffer_too_small, z_str3join(buffer, sizeof(buffer), prefix.c_str(), suffix.c_str()));
        EXPECT_STREQ(buffer, "ERR???");
    }

}
