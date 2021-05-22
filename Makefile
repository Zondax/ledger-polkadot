#*******************************************************************************
#*   (c) 2019 Zondax GmbH
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

# We use BOLOS_SDK to determine the development environment that is being used
# BOLOS_SDK IS  DEFINED	 	We use the plain Makefile for Ledger
# BOLOS_SDK NOT DEFINED		We use a containerized build approach

#TESTS_JS_PACKAGE = "@zondax/ledger-polkadot"
#TESTS_JS_DIR = $(CURDIR)/../ledger-polkadot-js

ifeq ($(BOLOS_SDK),)
# In this case, there is not predefined SDK and we run dockerized
include $(CURDIR)/deps/ledger-zxlib/dockerized_build.mk

else
default:
	$(MAKE) -C app
%:
	$(info "Calling app Makefile for target $@")
	COIN=$(COIN) $(MAKE) -C app $@
endif

build_sr25519: SUPPORT_SR25519=1       # Alternative app purpose
build_sr25519: SUBSTRATE_PARSER_FULL=1 # Use full parser
build_sr25519: buildS
	cp $(CURDIR)/app/bin/app.elf $(CURDIR)/app/output/app_sr25519.elf
	cp $(CURDIR)/app/bin/app.elf $(CURDIR)/app/bin/app_sr25519.elf

build_full_parser_s: SUBSTRATE_PARSER_FULL=1
build_full_parser_s: buildS

build_full_parser_x: SUBSTRATE_PARSER_FULL=1
build_full_parser_x: buildX

tests_tools_build:
	cd tests_tools/neon && yarn install

tests_tools_test: tests_tools_build
	cd tests_tools/neon && yarn test

zemu_install: tests_tools_build
