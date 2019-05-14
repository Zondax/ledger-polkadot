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
project(ledger-polkadot VERSION 0.0.0)
enable_testing()

set(CMAKE_CXX_STANDARD 11)
add_subdirectory(cmake/gtest)

string(APPEND CMAKE_CXX_FLAGS_DEBUG " -fsanitize=address -fno-omit-frame-pointer")
string(APPEND CMAKE_LINKER_FLAGS_DEBUG " -fsanitize=address -fno-omit-frame-pointer")
#string(APPEND CMAKE_CXX_FLAGS_DEBUG " -fsanitize=undefined")
#string(APPEND CMAKE_LINKER_FLAGS_DEBUG " -fsanitize=undefined")

##############################################################
##############################################################
#  static libs
file(GLOB_RECURSE LIB_SRC
        deps/BLAKE/ref/blake2b-ref.c
        src/ledger/deps/ledger-zxlib/src/hexutils.c
        src/ledger/deps/ledger-zxlib/src/zxmacros.c
        src/ledger/src/lib/crypto.c
        src/ledger/src/lib/parser.c
        src/ledger/src/lib/parser_impl.c
        src/ledger/src/lib/parser_txdef.c
        src/ledger/src/lib/polkadot_types.c
        src/ledger/src/lib/polkadot_dispatch.c
        src/ledger/src/lib/base58.c
        src/ledger/src/lib/uint256.c
        )

add_library(app_lib STATIC ${LIB_SRC})
target_include_directories(app_lib PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src/ledger/deps/ledger-zxlib/include
        ${CMAKE_CURRENT_SOURCE_DIR}/src/ledger/lib
        ${CMAKE_CURRENT_SOURCE_DIR}/deps/BLAKE/ref
        )

##############################################################
##############################################################
#  Tests
file(GLOB TESTS_SRC ${CMAKE_CURRENT_SOURCE_DIR}/tests/*.cpp)
add_executable(unittests ${TESTS_SRC})
target_include_directories(unittests PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src/ledger/src
        ${gtest_SOURCE_DIR}/include
        ${gmock_SOURCE_DIR}/include
        )

target_link_libraries(unittests gtest_main app_lib)
add_test(gtest ${PROJECT_BINARY_DIR}/unittests)
set_tests_properties(gtest PROPERTIES WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests)

###############################################################
# Force tests to depend from app compiling
###############################################################

set(DISABLE_DOCKER_BUILDS OFF CACHE BOOL "Disables Docker Builds")

if (NOT DISABLE_DOCKER_BUILDS)
    add_custom_target(ledger_app
            COMMAND make build
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
            )
    add_dependencies(unittests ledger_app)
endif()
