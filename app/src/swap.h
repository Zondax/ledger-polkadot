/*******************************************************************************
*   (c) 2016 Ledger
*   (c) 2018 - 2023 Zondax AG
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
#pragma once

#include "stdbool.h"
#include "stdint.h"
#include "parser_common.h"

#define RUN_APPLICATION         1
#define SIGN_TRANSACTION        2
#define CHECK_ADDRESS           3
#define GET_PRINTABLE_AMOUNT    4

typedef enum {
    run_application = 1,
    sign_transaction,
    check_address,
    get_printable_amount,
} swap_options_e;

// structure that should be send to specific coin application to get address
typedef struct {
    // IN
    unsigned char* coin_configuration;
    unsigned char coin_configuration_length;
    // serialized path, segwit, version prefix, hash used, dictionary etc.
    // fields and serialization format depends on spesific coin app
    unsigned char* address_parameters;
    unsigned char address_parameters_length;
    char *address_to_check;
    char *extra_id_to_check;
    // OUT
    int result;
} check_address_parameters_t;

// structure that should be send to specific coin application to get printable amount
typedef struct {
    // IN
    unsigned char* coin_configuration;
    unsigned char coin_configuration_length;
    unsigned char* amount;
    unsigned char amount_length;
    bool is_fee;
    // OUT
    char printable_amount[30];
    // int result;
} get_printable_amount_parameters_t;

typedef struct {
    unsigned char* coin_configuration;
    unsigned char coin_configuration_length;
    unsigned char* amount;
    unsigned char amount_length;
    unsigned char* fee_amount;
    unsigned char fee_amount_length;
    char *destination_address;
    char *destination_address_extra_id;
} create_transaction_parameters_t;


typedef struct {
    uint8_t amount[16];
    uint8_t amount_length;
    uint64_t fees;
    char destination_address[65];
    /*Is swap mode*/
    unsigned char called_from_swap;
    unsigned char should_exit;
} swap_globals_t;


typedef struct {
    unsigned int id;
    unsigned int command;
    void *coin_config_legacy; // This is unused but kept for compatibility
    union {
        check_address_parameters_t *check_address;
        create_transaction_parameters_t *create_transaction;
        get_printable_amount_parameters_t *get_printable_amount;
    };
} libargs_s;


extern swap_globals_t G_swap_state;
void swap_handle_command(libargs_s *args);
parser_error_t check_swap_conditions(const parser_context_t *ctx);
