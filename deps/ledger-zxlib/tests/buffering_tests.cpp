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

#include "gtest/gtest.h"
#include "buffering.h"

namespace {

    TEST(Buffering, SmallBuffer) {
        uint8_t ram_buffer[100];
        uint8_t flash_buffer[1000];

        buffering_init(ram_buffer,
                       sizeof(ram_buffer),
                       flash_buffer,
                       sizeof(flash_buffer));

        // Data is small enough to fit into ram buffer
        uint8_t small[50];
        auto num_bytes = buffering_append(small, sizeof(small));
        EXPECT_EQ(sizeof(small), num_bytes) << "Append should not return error";

        EXPECT_TRUE(buffering_get_ram_buffer()->in_use) << "Writing small buffer should only write to RAM";
        EXPECT_FALSE(buffering_get_flash_buffer()->in_use) << "Writing big buffer should write data to FLASH";
        EXPECT_EQ(50, buffering_get_ram_buffer()->pos) << "Wrong position of the written data in the ram buffer";
        EXPECT_EQ(100, buffering_get_ram_buffer()->size) << "Wrong size of the ram buffer";
        EXPECT_EQ(0, buffering_get_flash_buffer()->pos) << "Wrong position of the written data in the flash buffer";
        EXPECT_EQ(1000, buffering_get_flash_buffer()->size) << "Wrong size of the flash buffer";
    }

    TEST(Buffering, BigBuffer) {
        uint8_t ram_buffer[100];
        uint8_t flash_buffer[1000];

        buffering_init(ram_buffer,
                       sizeof(ram_buffer),
                       flash_buffer,
                       sizeof(flash_buffer));

        // Data is too big to fit into ram buffer, it will be written directly to flash
        uint8_t big[500];
        auto num_bytes = buffering_append(big, sizeof(big));
        EXPECT_EQ(sizeof(big), num_bytes) << "Append should not return error";

        EXPECT_FALSE(buffering_get_ram_buffer()->in_use) << "Writing big buffer should write data to FLASH";
        EXPECT_TRUE(buffering_get_flash_buffer()->in_use) << "Writing big buffer should write data to FLASH";
        EXPECT_EQ(0, buffering_get_ram_buffer()->pos) << "Wrong position of the written data in the ram buffer";
        EXPECT_EQ(100, buffering_get_ram_buffer()->size) << "Wrong size of the ram buffer";
        EXPECT_EQ(500, buffering_get_flash_buffer()->pos) << "Wrong position of the written data in the flash buffer";
        EXPECT_EQ(1000, buffering_get_flash_buffer()->size) << "Wrong size of the flash buffer";
    }

    TEST(Buffering, SmallBufferMultipleTimesWithinRam) {
        uint8_t ram_buffer[100];
        uint8_t flash_buffer[1000];

        buffering_init(ram_buffer,
                       sizeof(ram_buffer),
                       flash_buffer,
                       sizeof(flash_buffer));

        uint8_t small[40];
        auto num_bytes = buffering_append(small, sizeof(small));
        EXPECT_EQ(sizeof(small), num_bytes) << "Append should not return error";
        EXPECT_TRUE(buffering_get_ram_buffer()->in_use) << "Writing small buffer should only write to RAM";
        EXPECT_FALSE(buffering_get_flash_buffer()->in_use) << "Writing big buffer should write data to FLASH";

        // Here we write another chunk which should not top over the ram buffer
        buffering_append(small, sizeof(small));
        EXPECT_TRUE(buffering_get_ram_buffer()->in_use) << "Writing small buffer should only write to RAM";
        EXPECT_FALSE(buffering_get_flash_buffer()->in_use) << "Writing big buffer should write data to FLASH";

        EXPECT_EQ(sizeof(small) * 2, buffering_get_ram_buffer()->pos) << "Data should be written to RAM";
        EXPECT_EQ(100, buffering_get_ram_buffer()->size) << "Wrong size of the ram buffer";
        EXPECT_EQ(0, buffering_get_flash_buffer()->pos) << "Data should be written to RAM";
        EXPECT_EQ(1000, buffering_get_flash_buffer()->size) << "Wrong size of the flash buffer";
    }

    TEST(Buffering, SmallBufferMultipleTimesToFlash) {
        uint8_t ram_buffer[100];
        uint8_t flash_buffer[1000];

        buffering_init(ram_buffer,
                       sizeof(ram_buffer),
                       flash_buffer,
                       sizeof(flash_buffer));

        uint8_t small[100];
        buffering_append(small, sizeof(small));
        EXPECT_TRUE(buffering_get_ram_buffer()->in_use) << "Writing small buffer should only write to RAM";
        EXPECT_FALSE(buffering_get_flash_buffer()->in_use) << "Writing big buffer should write data to FLASH";

        // Here we append another small buffer, this time we're going to exceed ram's size
        // data will be copied to nvram
        buffering_append(small, sizeof(small));
        EXPECT_FALSE(buffering_get_ram_buffer()->in_use) << "Data should be now in FLASH";
        EXPECT_TRUE(buffering_get_flash_buffer()->in_use) << "Data should be now in FLASH";

        EXPECT_EQ(0, buffering_get_ram_buffer()->pos) << "RAM buffer should be reset";
        EXPECT_EQ(100, buffering_get_ram_buffer()->size) << "Wrong size of the ram buffer";
        EXPECT_EQ(200, buffering_get_flash_buffer()->pos) << "Wrong position of the written data in the flash buffer";
        EXPECT_EQ(1000, buffering_get_flash_buffer()->size) << "Wrong size of the flash buffer";
    }

    TEST(Buffering, SmallBufferMultipleTimes_CheckData) {
        uint8_t ram_buffer[100];
        uint8_t flash_buffer[1000];

        buffering_init(ram_buffer,
                       sizeof(ram_buffer),
                       flash_buffer,
                       sizeof(flash_buffer));

        uint8_t small1[100];
        for (int i = 0; i < sizeof(small1); i++) {
            small1[i] = i;
        }
        buffering_append(small1, sizeof(small1));

        uint8_t small2[200];
        for (int i = 0; i < sizeof(small2); i++) {
            small2[i] = 100 - i;
        }
        auto num_bytes = buffering_append(small2, sizeof(small2));
        EXPECT_EQ(sizeof(small2), num_bytes) << "Append should not return error";

        // In this test we want to make sure that data is not compromised.
        uint8_t *dst = buffering_get_flash_buffer()->data;
        for (int i = 0; i < sizeof(small1) + sizeof(small2); i++) {
            if (i < sizeof(small1)) {
                EXPECT_EQ(dst[i], small1[i]) << "Wrong data written to FLASH";
            } else {
                EXPECT_EQ(dst[i], small2[i - sizeof(small1)]) << "Wrong data written to FLASH";
            }
        }
    }

    TEST(Buffering, Reset) {
        uint8_t ram_buffer[100];
        uint8_t flash_buffer[1000];

        buffering_init(ram_buffer,
                       sizeof(ram_buffer),
                       flash_buffer,
                       sizeof(flash_buffer));

        uint8_t big[1000];
        auto num_bytes = buffering_append(big, sizeof(big));
        EXPECT_EQ(sizeof(big), num_bytes) << "Append should not return error";

        EXPECT_FALSE(buffering_get_ram_buffer()->in_use) << "Writing big buffer should only write to FLASH";
        EXPECT_TRUE(buffering_get_flash_buffer()->in_use) << "Writing big buffer should only write to FLASH";

        buffering_reset();

        EXPECT_TRUE(buffering_get_ram_buffer()->in_use) << "After reset RAM should be enabled by default";
        EXPECT_FALSE(buffering_get_flash_buffer()->in_use) << "After reset RAM should be enabled by default";
    }

    TEST(Buffering, NotEnoughRoomInFlash) {
        uint8_t ram_buffer[100];
        uint8_t flash_buffer[1000];

        buffering_init(ram_buffer,
                       sizeof(ram_buffer),
                       flash_buffer,
                       sizeof(flash_buffer));

        uint8_t big[1101];
        auto num_bytes = buffering_append(big, sizeof(big));
        EXPECT_EQ(0, num_bytes) << "Appending outside the bounds of the buffer should return error";
    }

    TEST(Buffering, NoFlashOnlyRAM) {
        uint8_t ram_buffer[100];

        buffering_init(ram_buffer,
                       sizeof(ram_buffer),
                       nullptr, 0);

        uint8_t small[10];
        auto num_bytes = buffering_append(small, sizeof(small));
        EXPECT_EQ(10, num_bytes) << "Could not add to RAM";

        num_bytes = buffering_append(small, sizeof(small));
        EXPECT_EQ(10, num_bytes) << "Could not add to RAM";

        num_bytes = buffering_append(small, sizeof(small));
        EXPECT_EQ(10, num_bytes) << "Could not add to RAM";

        auto state = buffering_get_buffer();
        EXPECT_EQ(30, state->pos) << "Invalid buffer size";

        uint8_t small2[70];
        num_bytes = buffering_append(small2, sizeof(small2));
        EXPECT_EQ(70, num_bytes);

        state = buffering_get_buffer();
        EXPECT_EQ(100, state->pos) << "Invalid buffer size";

        num_bytes = buffering_append(small, sizeof(small));
        EXPECT_EQ(0, num_bytes) << "Could add to RAM when it should have been impossible";
    }

    TEST(Buffering, NoFlash) {
        uint8_t ram_buffer[100];

        buffering_init(ram_buffer,
                       sizeof(ram_buffer),
                       nullptr, 0);

        uint8_t big[1101];
        auto num_bytes = buffering_append(big, sizeof(big));
        EXPECT_EQ(0, num_bytes) << "Appending outside the bounds of the buffer should return error";
    }
}
