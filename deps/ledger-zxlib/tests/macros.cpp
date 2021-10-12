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
    TEST(FORMAT, array_to_hexstr) {
        uint8_t array1[] = {1, 3, 5};

        char output[20];
        memset(output, 1, 20);

        array_to_hexstr(output, sizeof(output), array1, sizeof(array1));
        EXPECT_EQ(memcmp(output, "010305", 2 * sizeof(array1)), 0);
        EXPECT_EQ(output[2 * sizeof(array1)], 0);
    }

    TEST(FORMAT, fpuint64_to_str) {
        char output[100];
        printf("\n");

        fpuint64_to_str(output, sizeof(output), 123, 5);
        printf("%10s\n", output);
        EXPECT_EQ(std::string(output), "0.00123");

        fpuint64_to_str(output, sizeof(output), 1234, 5);
        printf("%10s\n", output);
        EXPECT_EQ(std::string(output), "0.01234");

        fpuint64_to_str(output, sizeof(output), 12345, 5);
        printf("%10s\n", output);
        EXPECT_EQ(std::string(output), "0.12345");

        fpuint64_to_str(output, sizeof(output), 123456, 5);
        printf("%10s\n", output);
        EXPECT_EQ(std::string(output), "1.23456");

        fpuint64_to_str(output, sizeof(output), 1234567, 5);
        printf("%10s\n", output);
        EXPECT_EQ(std::string(output), "12.34567");
    }

    TEST(FORMAT, fpstr_to_str) {
        char output[100];
        printf("\n");

        fpstr_to_str(output, sizeof(output), "", 0);
        printf("%10s\n", output);
        EXPECT_EQ(std::string(output), "0");

        fpstr_to_str(output, sizeof(output), "1", 0);
        printf("%10s\n", output);
        EXPECT_EQ(std::string(output), "1");

        fpstr_to_str(output, sizeof(output), "123", 0);
        printf("%10s\n", output);
        EXPECT_EQ(std::string(output), "123");

        fpstr_to_str(output, sizeof(output), "", 5);
        printf("%10s\n", output);
        EXPECT_EQ(std::string(output), "0.00000");

        fpstr_to_str(output, sizeof(output), "0", 5);
        printf("%10s\n", output);
        EXPECT_EQ(std::string(output), "0.00000");

        fpstr_to_str(output, sizeof(output), "123", 5);
        printf("%10s\n", output);
        EXPECT_EQ(std::string(output), "0.00123");

        fpstr_to_str(output, sizeof(output), "1234", 5);
        printf("%10s\n", output);
        EXPECT_EQ(std::string(output), "0.01234");

        fpstr_to_str(output, sizeof(output), "12345", 5);
        printf("%10s\n", output);
        EXPECT_EQ(std::string(output), "0.12345");

        fpstr_to_str(output, sizeof(output), "123456", 5);
        printf("%10s\n", output);
        EXPECT_EQ(std::string(output), "1.23456");

        fpstr_to_str(output, sizeof(output), "1234567", 5);
        printf("%10s\n", output);
        EXPECT_EQ(std::string(output), "12.34567");
    }

    TEST(FORMAT, fpstr_to_str_BAD_zeros) {
        char output[8];
        printf("\n");

        fpstr_to_str(output, sizeof(output), "", 5);
        printf("%10s\n", output);
        EXPECT_EQ(std::string(output), "0.00000");

        fpstr_to_str(output, sizeof(output), "", 6);
        printf("%10s\n", output);
        EXPECT_EQ(std::string(output), "ERR");

        fpstr_to_str(output, sizeof(output), "", 7);
        printf("%10s\n", output);
        EXPECT_EQ(std::string(output), "ERR");

        fpstr_to_str(output, sizeof(output), "", 8);
        printf("%10s\n", output);
        EXPECT_EQ(std::string(output), "ERR");
    }

    TEST(FORMAT, fpstr_to_str_BAD_short) {
        char output[8];
        printf("\n");

        fpstr_to_str(output, sizeof(output), "123", 5);
        printf("%10s\n", output);
        EXPECT_EQ(std::string(output), "0.00123");

        fpstr_to_str(output, sizeof(output), "123", 6);
        printf("%10s\n", output);
        EXPECT_EQ(std::string(output), "ERR");

        fpstr_to_str(output, sizeof(output), "123", 7);
        printf("%10s\n", output);
        EXPECT_EQ(std::string(output), "ERR");

        fpstr_to_str(output, sizeof(output), "123", 8);
        printf("%10s\n", output);
        EXPECT_EQ(std::string(output), "ERR");
    }

    TEST(FORMAT, fpstr_to_str_BAD_long) {
        char output[8];
        printf("\n");

        fpstr_to_str(output, sizeof(output), "123456", 5);
        printf("%10s\n", output);
        EXPECT_EQ(std::string(output), "1.23456");

        fpstr_to_str(output, sizeof(output), "123456", 6);
        printf("%10s\n", output);
        EXPECT_EQ(std::string(output), "ERR");

        fpstr_to_str(output, sizeof(output), "123456", 7);
        printf("%10s\n", output);
        EXPECT_EQ(std::string(output), "ERR");

        fpstr_to_str(output, sizeof(output), "12345", 7);
        printf("%10s\n", output);
        EXPECT_EQ(std::string(output), "ERR");

        fpstr_to_str(output, sizeof(output), "12345", 2);
        printf("%10s\n", output);
        EXPECT_EQ(std::string(output), "123.45");

        fpstr_to_str(output, sizeof(output), "123456", 2);
        printf("%10s\n", output);
        EXPECT_EQ(std::string(output), "1234.56");

        fpstr_to_str(output, sizeof(output), "1234567", 2);
        printf("%10s\n", output);
        EXPECT_EQ(std::string(output), "ERR");

        fpstr_to_str(output, sizeof(output), "12345678", 2);
        printf("%10s\n", output);
        EXPECT_EQ(std::string(output), "ERR");

        fpstr_to_str(output, sizeof(output), "1234567890", 0);
        EXPECT_EQ(std::string(output), "ERR");

        fpstr_to_str(output, sizeof(output), "123456", 0);
        EXPECT_EQ(std::string(output), "123456");
    }

    TEST(FORMAT, fpuint64_to_str_zeros) {
        char output[100];
        printf("\n");

        fpuint64_to_str(output, sizeof(output), 0, 9);
        printf("%11s\n", output);
        EXPECT_EQ(std::string(output), "0.000000000");

        fpuint64_to_str(output, sizeof(output), 0, 1);
        printf("%11s\n", output);
        EXPECT_EQ(std::string(output), "0.0");

        fpuint64_to_str(output, sizeof(output), 1, 1);
        printf("%11s\n", output);
        EXPECT_EQ(std::string(output), "0.1");

        fpuint64_to_str(output, sizeof(output), 10, 1);
        printf("%11s\n", output);
        EXPECT_EQ(std::string(output), "1.0");
    }

    TEST(FORMAT, number_trimming) {
        char output[100];

        snprintf(output, sizeof(output), "0");
        number_inplace_trimming(output, 1);
        EXPECT_EQ(std::string(output), "0");

        snprintf(output, sizeof(output), "10");
        number_inplace_trimming(output, 1);
        EXPECT_EQ(std::string(output), "10");

        snprintf(output, sizeof(output), "10.10");
        number_inplace_trimming(output, 1);
        EXPECT_EQ(std::string(output), "10.1");

        snprintf(output, sizeof(output), "0.0");
        number_inplace_trimming(output, 1);
        EXPECT_EQ(std::string(output), "0.0");

        snprintf(output, sizeof(output), "0.00");
        number_inplace_trimming(output, 1);
        EXPECT_EQ(std::string(output), "0.0");

        snprintf(output, sizeof(output), "0.01");
        number_inplace_trimming(output, 1);
        EXPECT_EQ(std::string(output), "0.01");

        snprintf(output, sizeof(output), "0.010");
        number_inplace_trimming(output, 1);
        EXPECT_EQ(std::string(output), "0.01");

        snprintf(output, sizeof(output), "0.010000");
        number_inplace_trimming(output, 1);
        EXPECT_EQ(std::string(output), "0.01");
    }

    TEST(FORMAT, intstr_to_fpstr_inplace_trimming_leading) {
        char number[100];
        printf("\n");

        snprintf(number, sizeof(number), "0");
        intstr_to_fpstr_inplace(number, sizeof(number), 0);
        EXPECT_EQ(std::string(number), "0");

        snprintf(number, sizeof(number), "00");
        intstr_to_fpstr_inplace(number, sizeof(number), 0);
        EXPECT_EQ(std::string(number), "0");

        snprintf(number, sizeof(number), "0000");
        intstr_to_fpstr_inplace(number, sizeof(number), 0);
        EXPECT_EQ(std::string(number), "0");

        snprintf(number, sizeof(number), "00001");
        intstr_to_fpstr_inplace(number, sizeof(number), 0);
        EXPECT_EQ(std::string(number), "1");

        snprintf(number, sizeof(number), "000011");
        intstr_to_fpstr_inplace(number, sizeof(number), 0);
        EXPECT_EQ(std::string(number), "11");

        snprintf(number, sizeof(number), "10000");
        intstr_to_fpstr_inplace(number, sizeof(number), 0);
        EXPECT_EQ(std::string(number), "10000");
    }

    TEST(FORMAT, intstr_to_fpstr_inplace_empty) {
        char number[100];
        printf("\n");

        MEMZERO(number, sizeof(number));
        intstr_to_fpstr_inplace(number, sizeof(number), 0);
        EXPECT_EQ(std::string(number), "0");

        MEMZERO(number, sizeof(number));
        intstr_to_fpstr_inplace(number, sizeof(number), 5);
        EXPECT_EQ(std::string(number), "0.00000");

        MEMZERO(number, sizeof(number));
        intstr_to_fpstr_inplace(number, sizeof(number), 10);
        EXPECT_EQ(std::string(number), "0.0000000000");
    }

    TEST(FORMAT, intstr_to_fpstr_inplace) {
        char number[100];
        printf("\n");

        snprintf(number, sizeof(number), "1");
        intstr_to_fpstr_inplace(number, sizeof(number), 0);
        EXPECT_EQ(std::string(number), "1");

        snprintf(number, sizeof(number), "123");
        intstr_to_fpstr_inplace(number, sizeof(number), 0);
        EXPECT_EQ(std::string(number), "123");

        snprintf(number, sizeof(number), "0");
        intstr_to_fpstr_inplace(number, sizeof(number), 5);
        EXPECT_EQ(std::string(number), "0.00000");

        snprintf(number, sizeof(number), "123");
        intstr_to_fpstr_inplace(number, sizeof(number), 5);
        EXPECT_EQ(std::string(number), "0.00123");

        snprintf(number, sizeof(number), "1234");
        intstr_to_fpstr_inplace(number, sizeof(number), 5);
        EXPECT_EQ(std::string(number), "0.01234");

        snprintf(number, sizeof(number), "12345");
        intstr_to_fpstr_inplace(number, sizeof(number), 5);
        EXPECT_EQ(std::string(number), "0.12345");

        snprintf(number, sizeof(number), "123456");
        intstr_to_fpstr_inplace(number, sizeof(number), 5);
        EXPECT_EQ(std::string(number), "1.23456");

        snprintf(number, sizeof(number), "1234567");
        intstr_to_fpstr_inplace(number, sizeof(number), 5);
        EXPECT_EQ(std::string(number), "12.34567");
    }

    TEST(INT64_TO_STR, Zero) {
        char temp[10];
        const char *error = int64_to_str(temp, sizeof(temp), int64_t(0));
        EXPECT_STREQ(temp, "0");
        EXPECT_TRUE(error == nullptr);
    }

    TEST(INT64_TO_STR, Positive_1234) {
        char temp[10];
        const char *error = int64_to_str(temp, sizeof(temp), int64_t(1234));
        EXPECT_STREQ(temp, "1234");
        EXPECT_TRUE(error == nullptr);
    }

    TEST(INT64_TO_STR, Negative_1234) {
        char temp[10];
        const char *error = int64_to_str(temp, sizeof(temp), int64_t(-1234));
        EXPECT_STREQ(temp, "-1234");
        EXPECT_TRUE(error == nullptr);
    }

    TEST(INT64_TO_STR, TooSmall_0) {
        char temp[1];
        const char *error = int64_to_str(temp, sizeof(temp), int64_t(0));
        EXPECT_STREQ("Buffer too small", error);
    }

    TEST(INT64_TO_STR, FitsJust) {
        char temp[4];
        const char *error = int64_to_str(temp, sizeof(temp), int64_t(999));
        EXPECT_STREQ(temp, "999");
        EXPECT_TRUE(error == nullptr);
    }

    TEST(INT64_TO_STR, TooSmall_10) {
        char temp[2];
        const char *error = int64_to_str(temp, sizeof(temp), int64_t(10));
        EXPECT_STREQ("Buffer too small", error);
    }

    TEST(INT64_TO_STR, Max) {
        char temp[20];
        const char *error = int64_to_str(temp, sizeof(temp), std::numeric_limits<int64_t>::max());
        EXPECT_STREQ(temp, "9223372036854775807");
        EXPECT_TRUE(error == nullptr);
    }

    TEST(INT64_TO_STR, Min) {
        char temp[21];
        const char *error = int64_to_str(temp, sizeof(temp), std::numeric_limits<int64_t>::min());
        EXPECT_STREQ(temp, "-9223372036854775808");
        EXPECT_TRUE(error == nullptr);
    }

    TEST(STR_TO_INT8, Min) {
        char numberStr[] = "-128";
        char error = 0;
        int8_t number = str_to_int8(numberStr, numberStr + strlen(numberStr), &error);
        EXPECT_EQ(-128, number);
        EXPECT_EQ(0, error);
    }

    TEST(STR_TO_INT8, Max) {
        char numberStr[] = "127";
        char error = 0;
        int8_t number = str_to_int8(numberStr, numberStr + strlen(numberStr), &error);
        EXPECT_EQ(127, number);
        EXPECT_EQ(0, error);
    }

    TEST(STR_TO_INT8, Zero) {
        char numberStr[] = "0";
        char error = 0;
        int8_t number = str_to_int8(numberStr, numberStr + strlen(numberStr), &error);
        EXPECT_EQ(0, number);
        EXPECT_EQ(0, error);
    }

    TEST(STR_TO_INT8, Hundred) {
        char numberStr[] = "100";
        char error = 0;
        int8_t number = str_to_int8(numberStr, numberStr + strlen(numberStr), &error);
        EXPECT_EQ(100, number);
        EXPECT_EQ(0, error);
    }

    TEST(STR_TO_INT8, NegHundred) {
        char numberStr[] = "-100";
        char error = 0;
        int8_t number = str_to_int8(numberStr, numberStr + strlen(numberStr), &error);
        EXPECT_EQ(-100, number);
        EXPECT_EQ(0, error);
    }

    TEST(STR_TO_INT8, OutsideBoundsPositive) {
        char numberStr[] = "128";
        char error = 0;
        str_to_int8(numberStr, numberStr + strlen(numberStr), &error);
        EXPECT_EQ(1, error);
    }

    TEST(STR_TO_INT8, OutsideBoundsNegative) {
        char numberStr[] = "-129";
        char error = 0;
        str_to_int8(numberStr, numberStr + strlen(numberStr), &error);
        EXPECT_EQ(1, error);
    }

    TEST(STR_TO_INT8, DummyData_Positive) {
        char numberStr[] = "100b0";
        char error = 0;
        str_to_int8(numberStr, numberStr + strlen(numberStr), &error);
        EXPECT_EQ(1, error);
    }

    TEST(STR_TO_INT8, DummyData_Negative) {
        char numberStr[] = "-1002xx";
        char error = 0;
        str_to_int8(numberStr, numberStr + strlen(numberStr), &error);
        EXPECT_EQ(1, error);
    }

    TEST(STR_TO_INT64, Min) {
        char numberStr[] = "-9223372036854775807";
        char error = 0;
        int64_t number = str_to_int64(numberStr, numberStr + strlen(numberStr), &error);
        EXPECT_EQ(-9223372036854775807, number);
        EXPECT_EQ(0, error);
    }

    TEST(STR_TO_INT64, Max) {
        char numberStr[] = "9223372036854775807";
        char error = 0;
        int64_t number = str_to_int64(numberStr, numberStr + strlen(numberStr), &error);
        EXPECT_EQ(9223372036854775807, number);
        EXPECT_EQ(0, error);
    }

    TEST(STR_TO_INT64, Zero) {
        char numberStr[] = "0";
        char error = 0;
        int64_t number = str_to_int64(numberStr, numberStr + strlen(numberStr), &error);
        EXPECT_EQ(0, number);
        EXPECT_EQ(0, error);
    }

    TEST(STR_TO_INT64, Hundred) {
        char numberStr[] = "100";
        char error = 0;
        int64_t number = str_to_int64(numberStr, numberStr + strlen(numberStr), &error);
        EXPECT_EQ(100, number);
        EXPECT_EQ(0, error);
    }

    TEST(STR_TO_INT64, NegHundred) {
        char numberStr[] = "-100";
        char error = 0;
        int64_t number = str_to_int64(numberStr, numberStr + strlen(numberStr), &error);
        EXPECT_EQ(-100, number);
        EXPECT_EQ(0, error);
    }

    TEST(STR_TO_INT64, DummyData_Positive) {
        char numberStr[] = "100b0";
        char error = 0;
        str_to_int64(numberStr, numberStr + strlen(numberStr), &error);
        EXPECT_EQ(1, error);
    }

    TEST(STR_TO_INT64, DummyData_Negative) {
        char numberStr[] = "-1002xx";
        char error = 0;
        str_to_int64(numberStr, numberStr + strlen(numberStr), &error);
        EXPECT_EQ(1, error);
    }
}
