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
#include <gmock/gmock.h>
#include <zxmacros.h>
#include <bech32.h>
#include <hexutils.h>

namespace {
    TEST(BECH32, hex_to_address) {
        char addr_out[100];
        const char *hrp = "zx";

        uint8_t data1[] = {1, 3, 5};
        uint8_t data2[] = {1, 3, 5, 7, 9, 11, 13};

        auto err = bech32EncodeFromBytes(addr_out, sizeof(addr_out), hrp, data1, sizeof(data1), 0);
        ASSERT_EQ(err, zxerr_ok);
        std::cout << addr_out << std::endl;
        ASSERT_STREQ("zx1qypse825ac", addr_out);

        err = bech32EncodeFromBytes(addr_out, sizeof(addr_out), hrp, data2, sizeof(data2), 0);
        ASSERT_EQ(err, zxerr_ok);
        std::cout << addr_out << std::endl;
        ASSERT_STREQ("zx1qyps2pcfpvx20dk22", addr_out);

        ///
        err = bech32EncodeFromBytes(addr_out, sizeof(addr_out), hrp, data1, sizeof(data1), 1);
        ASSERT_EQ(err, zxerr_ok);
        std::cout << addr_out << std::endl;
        ASSERT_STREQ("zx1qyps2ucfnzd", addr_out);

        err = bech32EncodeFromBytes(addr_out, sizeof(addr_out), hrp, data2, sizeof(data2), 1);
        ASSERT_EQ(err, zxerr_ok);
        std::cout << addr_out << std::endl;
        ASSERT_STREQ("zx1qyps2pcfpvxshamanz", addr_out);
    }

    TEST(BECH32, huge_input) {
        char addr_out[200];
        const char *hrp = "zx";

        auto data = std::vector<uint8_t>(1000, 0x55);

        auto err = bech32EncodeFromBytes(addr_out, sizeof(addr_out), hrp, data.data(), data.size(),0);
        ASSERT_EQ(err, zxerr_out_of_bounds);

        std::cout << addr_out << std::endl;
    }

    TEST(BECH32, small_output) {
        char addr_out[1000];
        const char *hrp = "zx";

        auto data = std::vector<uint8_t>(32, 0x55);

        MEMZERO(addr_out, sizeof(addr_out));

        // declare size to be smaller
        const size_t declared_size = 52;

        auto err = bech32EncodeFromBytes(addr_out, declared_size, hrp, data.data(), data.size(), 0);
        ASSERT_EQ(err, zxerr_buffer_too_small);

        for (int i = declared_size; i < sizeof(addr_out); i++) {
            ASSERT_EQ(addr_out[i], 0);
        }

        std::cout << addr_out << std::endl;
    }
}
