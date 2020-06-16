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
#include <crypto.h>

using ::testing::TestWithParam;
using ::testing::Values;

extern const char *crypto_testPubKey;

/// Test that we can generate the address from a known mnemonic
TEST(CRYPTO, fillAddress) {
    uint8_t buffer[100];

//    wage retreat alpha skull cactus inform device despair finish enforce chief young
//    Public key (hex): 0x7419797202bb88ddc319a5eaebb3dcd8115352eabee7b5dbc2f402da7c8efea7
//    Address (SS58): 5EgvykVVtK94Rbr2A29tscrbYqA6PH21p9CCR5jNZn3Jhd9D

    crypto_testPubKey = "7419797202bb88ddc319a5eaebb3dcd8115352eabee7b5dbc2f402da7c8efea7";

    uint16_t addrLen = crypto_fillAddress(buffer, 100);

    EXPECT_THAT(addrLen, ::testing::Eq(79));

    std::cout << std::endl;

    char pk[100];
    EXPECT_THAT(array_to_hexstr(pk, sizeof(pk), buffer, 32), ::testing::Eq(64));
    char *addr = (char *) (buffer + 32);

    EXPECT_THAT(std::string(pk),
        ::testing::Eq(crypto_testPubKey));

    EXPECT_THAT(std::string(addr),
                ::testing::Eq("FCYe4qNWg9zBFfTvixwmaDbhRSLBwqCGX2wok1L3aFoSaJ5"));

    std::cout << pk << std::endl;
    std::cout << addr << std::endl;
}

/// Test that we can generate the address from a known mnemonic (use default = test mnemonic)
TEST(CRYPTO, fillAddressTestMnemonic) {
    uint8_t buffer[100];

    crypto_testPubKey = nullptr;   // Use default test mnemonic

    uint16_t addrLen = crypto_fillAddress(buffer, 100);

    EXPECT_THAT(addrLen, ::testing::Eq(79));

    std::cout << std::endl;

    char pk[100];
    array_to_hexstr(pk, sizeof(pk), buffer, 32);
    char *addr = (char *) (buffer + 32);

    EXPECT_THAT(std::string(pk),
                ::testing::Eq("8d16d62802ca55326ec52bf76a8543b90e2aba5bcf6cd195c0d6fc1ef38fa1b3"));

    EXPECT_THAT(std::string(addr),
                ::testing::Eq("FmK43tjzFGT9F68Sj9EvW6rwBQUAVuA9wNQaYxGLvfcCAxS"));

    std::cout << pk << std::endl;
    std::cout << addr << std::endl;
}
