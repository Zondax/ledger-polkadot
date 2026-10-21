// Native amount and relative-price unit regression.
#include <app_mode.h>
#include <gtest/gtest.h>
#include <hexutils.h>

#include <cstring>
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>

#include "parser.h"
#include "utils/common.h"

TEST(BalanceFormatting, RelativePricesRemainRawInDirectAndNestedCalls) {
    std::ifstream file(std::string(TESTVECTORS_DIR) + "quality/relative-price-v478.json");
    ASSERT_TRUE(file.is_open());
    nlohmann::json vectors;
    file >> vectors;
    ASSERT_EQ(vectors.size(), 3);
    for (const auto &entry : vectors) {
        for (bool expert : {false, true}) {
            SCOPED_TRACE(entry["name"].get<std::string>() + (expert ? " expert" : " normal"));
            app_mode_set_expert(expert);
            uint8_t buffer[16384] = {0};
            const auto blob = entry["blob"].get<std::string>();
            const auto proof = entry["metadata"].get<std::string>();
            const auto digestHex = entry["digest"].get<std::string>();
            const auto blobLen = parseHexString(buffer, sizeof(buffer), blob.c_str());
            const auto proofLen = parseHexString(buffer + blobLen, sizeof(buffer) - blobLen, proof.c_str());
            ASSERT_NE(blobLen, 0);
            ASSERT_NE(proofLen, 0);
            parser_tx_t transaction = {0};
            ASSERT_EQ(parser_parse(&transaction, buffer, blobLen + proofLen, blobLen), parser_ok);
            uint8_t digest[32] = {0};
            ASSERT_EQ(parseHexString(digest, sizeof(digest), digestHex.c_str()), 32);
            ASSERT_EQ(memcmp(digest, transaction.metadataDigest, sizeof(digest)), 0);
            auto lines = genericDumpUI(&transaction);
            ASSERT_FALSE(lines.empty());
            unsigned ratios = 0;
            unsigned amounts = 0;
            for (const auto &line : lines) {
                if (line.find("limit_price") != std::string::npos) {
                    std::cout << entry["name"].get<std::string>() << (expert ? " expert " : " normal ") << line << '\n';
                    EXPECT_NE(line.find("limit_price : 950000000"), std::string::npos);
                    EXPECT_EQ(line.find("TAO"), std::string::npos);
                    ratios++;
                }
                if (line.find("alpha_amount") != std::string::npos) {
                    EXPECT_NE(line.find("alpha_amount : 2000000000"), std::string::npos);
                    EXPECT_EQ(line.find("TAO"), std::string::npos);
                    amounts++;
                }
            }
            const unsigned expected = entry["name"] == "batch_swap_move" ? 2 : 1;
            EXPECT_EQ(ratios, expected);
            EXPECT_EQ(amounts, expected);
        }
    }
}
