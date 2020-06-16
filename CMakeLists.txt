#*******************************************************************************
#*   (c) 2018 ZondaX GmbH
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
project(ledger-kusama VERSION 0.0.0)
enable_testing()

cmake_policy(SET CMP0025 NEW)
set(CMAKE_CXX_STANDARD 11)

include(cmake/conan/CMakeLists.txt)
add_subdirectory(cmake/gtest)

string(APPEND CMAKE_C_FLAGS " -fsanitize=address -fno-omit-frame-pointer -Wno-extern-c-compat")
string(APPEND CMAKE_CXX_FLAGS " -fsanitize=address -fno-omit-frame-pointer -Wno-extern-c-compat")
string(APPEND CMAKE_LINKER_FLAGS " -fsanitize=address -fno-omit-frame-pointer")

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
    -DAPP_STANDARD
    -DLEDGER_MAJOR_VERSION=${MAJOR_VERSION}
    -DLEDGER_MINOR_VERSION=${MINOR_VERSION}
)

##############################################################
##############################################################
#  static libs
file(GLOB_RECURSE LIB_SRC
        ${CMAKE_CURRENT_SOURCE_DIR}/deps/BLAKE2/ref/blake2b-ref.c
        ${CMAKE_CURRENT_SOURCE_DIR}/deps/ledger-zxlib/src/bignum.c
        ${CMAKE_CURRENT_SOURCE_DIR}/deps/ledger-zxlib/src/hexutils.c
        ${CMAKE_CURRENT_SOURCE_DIR}/deps/ledger-zxlib/src/zxmacros.c
        ####
        ${CMAKE_CURRENT_SOURCE_DIR}/app/src/crypto.c
        ${CMAKE_CURRENT_SOURCE_DIR}/app/src/parser.c
        ${CMAKE_CURRENT_SOURCE_DIR}/app/src/parser_impl.c
        ${CMAKE_CURRENT_SOURCE_DIR}/app/src/parser_txdef.c
        ${CMAKE_CURRENT_SOURCE_DIR}/app/src/polkadot_types.c
        ${CMAKE_CURRENT_SOURCE_DIR}/app/src/polkadot_dispatch.c
        ${CMAKE_CURRENT_SOURCE_DIR}/app/src/lib/base58.c
        ${CMAKE_CURRENT_SOURCE_DIR}/app/src/lib/uint256.c
        )

add_library(app_lib STATIC ${LIB_SRC})
target_include_directories(app_lib PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/deps/BLAKE2/ref
        ${CMAKE_CURRENT_SOURCE_DIR}/deps/ledger-zxlib/include
        ${CMAKE_CURRENT_SOURCE_DIR}/app/src
        ${CMAKE_CURRENT_SOURCE_DIR}/app/src/common
        ${CMAKE_CURRENT_SOURCE_DIR}/app/src/lib
        )

##############################################################
##############################################################
#  Tests
file(GLOB_RECURSE TESTS_SRC
        ${CMAKE_CURRENT_SOURCE_DIR}/tests/*.cpp)

add_executable(unittests ${TESTS_SRC})
target_include_directories(unittests PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/app/src
        ${CMAKE_CURRENT_SOURCE_DIR}/app/src/lib
        ${gtest_SOURCE_DIR}/include
        ${gmock_SOURCE_DIR}/include
        ${CONAN_INCLUDE_DIRS_FMT}
        ${CONAN_INCLUDE_DIRS_JSONCPP}
        )

target_link_libraries(unittests PRIVATE
        gtest_main
        app_lib
        CONAN_PKG::fmt
        CONAN_PKG::jsoncpp)

add_test(unittests ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/unittests)
set_tests_properties(unittests PROPERTIES WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests)

##############################################################
##############################################################
#  Fuzzing
file(GLOB FUZZING_SRC
        ${CMAKE_CURRENT_SOURCE_DIR}/fuzzing/fuzzingMain.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/tests/utils/common.cpp)

add_executable(fuzzing_stub ${FUZZING_SRC})
target_include_directories(fuzzing_stub PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/app/src
        ${CMAKE_CURRENT_SOURCE_DIR}/app/src/lib
        ${CMAKE_CURRENT_SOURCE_DIR}/tests
        )

add_library(app_lib32 STATIC ${LIB_SRC})
target_include_directories(app_lib32 PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/deps/BLAKE2/ref
        ${CMAKE_CURRENT_SOURCE_DIR}/deps/ledger-zxlib/include
        ${CMAKE_CURRENT_SOURCE_DIR}/app/src
        ${CMAKE_CURRENT_SOURCE_DIR}/app/src/common
        ${CMAKE_CURRENT_SOURCE_DIR}/app/src/lib
        )
#set_target_properties(app_lib32 PROPERTIES COMPILE_FLAGS "-m32" LINK_FLAGS "-m32")

target_link_libraries(fuzzing_stub app_lib32)
#set_target_properties(fuzzing_stub PROPERTIES COMPILE_FLAGS "-m32" LINK_FLAGS "-m32")
