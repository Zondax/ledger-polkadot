#*******************************************************************************
#*   (c) 2020 Zondax GmbH
#*
#*  Licensed under the Apache License, Version 2.0 (the "License");
#*  you may not use this file except in compliance with the License.
#*  You may obtain a copy of the License at
#*
#*      http://www.apache.org/licenses/LICENSE-2.0
#*
#*  Unless required by applicable law or agreed to in writing, software
#*  distributed under the License is distributed on an "AS IS" BASIS,
#*  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
#*  See the License for the specific language governing permissions and
#*  limitations under the License.
#********************************************************************************
cmake_minimum_required(VERSION 3.0)
project(ledger-polkadot VERSION 0.0.0)
enable_testing()

cmake_policy(SET CMP0025 NEW)
set(CMAKE_CXX_STANDARD 11)

option(ENABLE_FUZZING "Build with fuzzing instrumentation and build fuzz targets" OFF)
option(ENABLE_COVERAGE "Build with source code coverage instrumentation" OFF)
option(ENABLE_SANITIZERS "Build with ASAN and UBSAN" OFF)

string(APPEND CMAKE_C_FLAGS " -fno-omit-frame-pointer -g")
string(APPEND CMAKE_CXX_FLAGS " -fno-omit-frame-pointer -g")
string(APPEND CMAKE_LINKER_FLAGS " -fno-omit-frame-pointer -g")

add_definitions(-DAPP_STANDARD)
add_definitions(-DSUBSTRATE_PARSER_FULL)

if(ENABLE_FUZZING)
    add_definitions(-DFUZZING_BUILD_MODE_UNSAFE_FOR_PRODUCTION=1)
    SET(ENABLE_SANITIZERS ON CACHE BOOL "Sanitizer automatically enabled" FORCE)
    SET(CMAKE_BUILD_TYPE Debug)

    if (DEFINED ENV{FUZZ_LOGGING})
        add_definitions(-DFUZZING_LOGGING)
        message(FATAL_ERROR "Fuzz logging enabled")
    endif()

    set(CMAKE_CXX_CLANG_TIDY clang-tidy -checks=-*,bugprone-*,cert-*,clang-analyzer-*,-cert-err58-cpp,misc-*)

    if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
        # require at least clang 3.2
        if (CMAKE_CXX_COMPILER_VERSION VERSION_LESS 10.0)
            message(FATAL_ERROR "Clang version must be at least 10.0!")
        endif()
    else()
        message(FATAL_ERROR
                "You are using an unsupported compiler! Fuzzing only works with Clang 10.\n"
                "1. Install clang-10 \n"
                "2. Pass -DCMAKE_C_COMPILER=clang-10 -DCMAKE_CXX_COMPILER=clang++-10")
    endif()

    string(APPEND CMAKE_C_FLAGS " -fsanitize=fuzzer-no-link")
    string(APPEND CMAKE_CXX_FLAGS " -fsanitize=fuzzer-no-link")
    string(APPEND CMAKE_LINKER_FLAGS " -fsanitize=fuzzer-no-link")
endif()

if(ENABLE_COVERAGE)
    string(APPEND CMAKE_C_FLAGS " -fprofile-instr-generate -fcoverage-mapping")
    string(APPEND CMAKE_CXX_FLAGS " -fprofile-instr-generate -fcoverage-mapping")
    string(APPEND CMAKE_LINKER_FLAGS " -fprofile-instr-generate -fcoverage-mapping")
endif()

if(ENABLE_SANITIZERS)
    string(APPEND CMAKE_C_FLAGS " -fsanitize=address,undefined -fsanitize-recover=address,undefined")
    string(APPEND CMAKE_CXX_FLAGS " -fsanitize=address,undefined -fsanitize-recover=address,undefined")
    string(APPEND CMAKE_LINKER_FLAGS " -fsanitize=address,undefined -fsanitize-recover=address,undefined")
endif()

include(cmake/conan/CMakeLists.txt)
add_subdirectory(cmake/gtest)

set (RETRIEVE_MAJOR_CMD
        "cat ${CMAKE_CURRENT_SOURCE_DIR}/app/Makefile.version | grep APPVERSION_M | cut -b 14- | tr -d '\n'"
)
set (RETRIEVE_MINOR_CMD
        "cat ${CMAKE_CURRENT_SOURCE_DIR}/app/Makefile.version | grep APPVERSION_N | cut -b 14- | tr -d '\n'"
)
execute_process(
        COMMAND bash "-c" ${RETRIEVE_MAJOR_CMD}
        RESULT_VARIABLE MAJOR_RESULT
        OUTPUT_VARIABLE MAJOR_VERSION
)
execute_process(
        COMMAND bash "-c" ${RETRIEVE_MINOR_CMD}
        RESULT_VARIABLE MINOR_RESULT
        OUTPUT_VARIABLE MINOR_VERSION
)

message(STATUS "LEDGER_MAJOR_VERSION [${MAJOR_RESULT}]: ${MAJOR_VERSION}" )
message(STATUS "LEDGER_MINOR_VERSION [${MINOR_RESULT}]: ${MINOR_VERSION}" )

add_definitions(
    -DLEDGER_MAJOR_VERSION=${MAJOR_VERSION}
    -DLEDGER_MINOR_VERSION=${MINOR_VERSION}
)

##############################################################
##############################################################
#  static libs
file(GLOB_RECURSE LIB_SRC
        ${CMAKE_CURRENT_SOURCE_DIR}/deps/BLAKE2/ref/blake2b-ref.c
        ${CMAKE_CURRENT_SOURCE_DIR}/deps/ledger-zxlib/src/app_mode.c
        ${CMAKE_CURRENT_SOURCE_DIR}/deps/ledger-zxlib/src/base58.c
        ${CMAKE_CURRENT_SOURCE_DIR}/deps/ledger-zxlib/src/bignum.c
        ${CMAKE_CURRENT_SOURCE_DIR}/deps/ledger-zxlib/src/hexutils.c
        ${CMAKE_CURRENT_SOURCE_DIR}/deps/ledger-zxlib/src/zxmacros.c
        ${CMAKE_CURRENT_SOURCE_DIR}/deps/ledger-zxlib/src/zbuffer.c
        ${CMAKE_CURRENT_SOURCE_DIR}/deps/ledger-zxlib/src/zxformat.c
        ####
        ${CMAKE_CURRENT_SOURCE_DIR}/app/src/crypto_helper.c
        ${CMAKE_CURRENT_SOURCE_DIR}/app/src/parser.c
        ${CMAKE_CURRENT_SOURCE_DIR}/app/src/parser_impl_common.c
        ${CMAKE_CURRENT_SOURCE_DIR}/app/src/parser_impl.c
        ${CMAKE_CURRENT_SOURCE_DIR}/app/src/parser_txdef.c
        ${CMAKE_CURRENT_SOURCE_DIR}/app/src/substrate/substrate*.c
        )

add_library(app_lib STATIC ${LIB_SRC})
target_include_directories(app_lib PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/deps/BLAKE2/ref
        ${CMAKE_CURRENT_SOURCE_DIR}/deps/ledger-zxlib/include
        ${CMAKE_CURRENT_SOURCE_DIR}/app/src
        ${CMAKE_CURRENT_SOURCE_DIR}/app/src/lib
        ${CMAKE_CURRENT_SOURCE_DIR}/app/src/common
        ${CMAKE_CURRENT_SOURCE_DIR}/app/src/substrate
        )

##############################################################
##############################################################
#  Tests
file(GLOB_RECURSE TESTS_SRC
        ${CMAKE_CURRENT_SOURCE_DIR}/tests/*.cpp)

add_executable(unittests ${TESTS_SRC})
target_include_directories(unittests PRIVATE
        ${gtest_SOURCE_DIR}/include
        ${gmock_SOURCE_DIR}/include
        ${CONAN_INCLUDE_DIRS_FMT}
        ${CONAN_INCLUDE_DIRS_JSONCPP}
        ${CMAKE_CURRENT_SOURCE_DIR}/app/src
        ${CMAKE_CURRENT_SOURCE_DIR}/app/src/lib
        )

target_link_libraries(unittests PRIVATE
        gtest_main
        app_lib
        CONAN_PKG::fmt
        CONAN_PKG::jsoncpp)

add_compile_definitions(TESTVECTORS_DIR="${CMAKE_CURRENT_SOURCE_DIR}/tests/")
add_test(unittests ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/unittests)
set_tests_properties(unittests PROPERTIES WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests)

##############################################################
##############################################################
#  Fuzz Targets
if(ENABLE_FUZZING)
    set(FUZZ_TARGETS
        parser_parse
        )

    foreach(target ${FUZZ_TARGETS})
        add_executable(fuzz-${target} ${CMAKE_CURRENT_SOURCE_DIR}/fuzz/${target}.cpp)
        target_link_libraries(fuzz-${target} PRIVATE app_lib)
        target_link_options(fuzz-${target} PRIVATE "-fsanitize=fuzzer")
    endforeach()
endif()
