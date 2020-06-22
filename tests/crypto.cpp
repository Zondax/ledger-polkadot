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
#include <crypto.h>

using ::testing::TestWithParam;
using ::testing::Values;

extern const char *crypto_testPubKey;

/// Test that we can generate the address from a known mnemonic
TEST(CRYPTO, fillAddress) {
    uint8_t buffer[100];

    crypto_testPubKey = "7419797202bb88ddc319a5eaebb3dcd8115352eabee7b5dbc2f402da7c8efea7";

    uint16_t addrLen = crypto_fillAddress(buffer, 100);

    EXPECT_THAT(addrLen, ::testing::Eq(80));

    std::cout << std::endl;

    char pk[100];
    EXPECT_THAT(array_to_hexstr(pk, sizeof(pk), buffer, 32), ::testing::Eq(64));
    char *addr = (char *) (buffer + 32);

    EXPECT_THAT(std::string(pk),
        ::testing::Eq(crypto_testPubKey));

    EXPECT_THAT(std::string(addr),
                ::testing::Eq("13dE85kZk6QXs8rY7fCu1mgkQT9k5aa9tdvgaNij7s4pt91H"));

    std::cout << pk << std::endl;
    std::cout << addr << std::endl;
}

/// Test that we can generate the address from a known mnemonic (use default = test mnemonic)
TEST(CRYPTO, fillAddressTestMnemonic) {
    uint8_t buffer[100];

    crypto_testPubKey = nullptr;   // Use default test mnemonic

    uint16_t addrLen = crypto_fillAddress(buffer, 100);

    EXPECT_THAT(addrLen, ::testing::Eq(80));

    std::cout << std::endl;

    char pk[100];
    array_to_hexstr(pk, sizeof(pk), buffer, 32);
    char *addr = (char *) (buffer + 32);

    EXPECT_THAT(std::string(pk),
                ::testing::Eq("8d16d62802ca55326ec52bf76a8543b90e2aba5bcf6cd195c0d6fc1ef38fa1b3"));

    EXPECT_THAT(std::string(addr),
                ::testing::Eq("14BzY4owDfWzq8HCdfPCAha1eD7t48e7n4G9MBffRDUdda6Y"));

    std::cout << pk << std::endl;
    std::cout << addr << std::endl;
}
