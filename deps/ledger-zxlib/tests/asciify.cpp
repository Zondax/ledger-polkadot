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

namespace {
    TEST(ASCIIFY, pure) {
        char input[] = "This is only ascii";
        char have[50];

        asciify_ext(input, have);

        EXPECT_STREQ(input, have);
    }

    TEST(ASCIIFY, ascii_below_32) {
        char input[] = "\05test";
        char want[] = ".test";
        char have[50];

        EXPECT_EQ(5, strlen(input));

        size_t ascii_len = asciify_ext(input, have);
        std::cout << have << std::endl;

        EXPECT_EQ(strlen(want), ascii_len);
        EXPECT_STREQ(want, have);
    }

    TEST(ASCIIFY, extended) {
        char input[] = "cumpleaños";
        char want[] = "cumplea.os";
        char have[50];

        EXPECT_EQ(11, strlen(input));

        size_t ascii_len = asciify_ext(input, have);
        std::cout << have << std::endl;

        EXPECT_EQ(strlen(want), ascii_len);
        EXPECT_STREQ(want, have);
    }

    TEST(ASCIIFY, utf8) {
        char input[] = "哈Something哈";
        char want[] = ".Something.";
        char have[50];

        EXPECT_EQ(15, strlen(input));

        size_t ascii_len = asciify_ext(input, have);
        std::cout << have << std::endl;

        EXPECT_EQ(strlen(want), ascii_len);
        EXPECT_STREQ(want, have);
    }

    TEST(ASCIIFY, inplace_pure) {
        char data[] = "This is only ascii";
        char want[] = "This is only ascii";

        asciify(data);
        EXPECT_STREQ(want, data);
    }

    TEST(ASCIIFY, inplace_ascii_below_32) {
        char data[] = "\05test";
        char want[] = ".test";

        EXPECT_EQ(5, strlen(data));

        size_t ascii_len = asciify(data);
        std::cout << data << std::endl;

        EXPECT_EQ(strlen(want), ascii_len);
        EXPECT_STREQ(want, data);
    }

    TEST(ASCIIFY, inplace_extended) {
        char data[] = "cumpleaños";
        char want[] = "cumplea.os";

        EXPECT_EQ(11, strlen(data));

        size_t ascii_len = asciify(data);
        std::cout << data << std::endl;

        EXPECT_EQ(strlen(want), ascii_len);
        EXPECT_STREQ(want, data);
    }

    TEST(ASCIIFY, inplace_utf8) {
        char data[] = "哈Something哈";
        char want[] = ".Something.";

        EXPECT_EQ(15, strlen(data));

        size_t ascii_len = asciify(data);
        std::cout << data << std::endl;

        EXPECT_EQ(strlen(want), ascii_len);
        EXPECT_STREQ(want, data);
    }

}
