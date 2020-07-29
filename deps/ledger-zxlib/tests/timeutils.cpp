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
#include <timeutils.h>
#include <chrono>

namespace {
    TEST(TIMEUTILS, basic) {
        uint64_t t = 1104937465;
        char output[50];

        zxerr_t err = printTime(output, sizeof(output), t);

        EXPECT_EQ(err, zxerr_ok);
        EXPECT_STREQ(output, "05Jan2005 15:04:25UTC");
    }

    TEST(TIMEUTILS, yearlookup) {
        struct tm t = {0};  // Initalize to all 0's
        for (uint64_t year = 70; year < 470; year++) {
            t.tm_year = year;  // This is year-1900, so 112 = 2012
            t.tm_mon = 0;
            t.tm_mday = 1;
            t.tm_hour = 0;
            t.tm_min = 0;
            t.tm_sec = 0;
            setenv("TZ", "UTC", 1);
            time_t timeSinceEpoch = mktime(&t);

            const uint32_t day = 60*60*24;
            uint64_t daysSinceStart = timeSinceEpoch / day;

            std::cout << "  " << daysSinceStart << ", " << std::endl;
        }
    }

    TEST(TIMEUTILS, loop) {
        char output[50];
        char expected_output[50];

        for (uint64_t t = 0; t < 8640000000; t += 1234567) {
            zxerr_t err = printTime(output, sizeof(output), t);
            EXPECT_EQ(err, zxerr_ok);
            time_t tmp = t;
            auto expected = gmtime(&tmp);
            snprintf(expected_output, sizeof(expected_output), "%02d%s%d %02d:%02d:%02dUTC",
                     expected->tm_mday,
                     getMonth(expected->tm_mon + 1),
                     expected->tm_year + 1900,
                     expected->tm_hour,
                     expected->tm_min,
                     expected->tm_sec
            );

            std::cout << t << "  " << output << "   " << expected_output << std::endl;

            EXPECT_STREQ(output, expected_output);
        }
    }

    TEST(TIMEUTILS, zero) {
        uint64_t t = 0;
        char output[50];

        zxerr_t err = printTime(output, sizeof(output), t);

        EXPECT_EQ(err, zxerr_ok);
        EXPECT_STREQ(output, "01Jan1970 00:00:00UTC");
    }

    TEST(TIMEUTILS, huge) {
        uint64_t t = 86400ULL * 365ULL * 5000ULL;
        char output[50];

        zxerr_t err = printTime(output, sizeof(output), t);

        EXPECT_EQ(err, zxerr_out_of_bounds);
    }
}
