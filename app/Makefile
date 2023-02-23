#*******************************************************************************
#  Ledger App
#  (c) 2019 - 2023 Zondax AG
#  (c) 2017 Ledger
#
#  Licensed under the Apache License, Version 2.0 (the "License");
#  you may not use this file except in compliance with the License.
#  You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
#  Unless required by applicable law or agreed to in writing, software
#  distributed under the License is distributed on an "AS IS" BASIS,
#  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
#  See the License for the specific language governing permissions and
#  limitations under the License.
#*******************************************************************************

ifeq ($(BOLOS_SDK),)
$(error BOLOS_SDK is not set)
endif

MY_DIR := $(dir $(lastword $(MAKEFILE_LIST)))

include $(CURDIR)/../deps/ledger-zxlib/makefiles/Makefile.installer_script

include $(BOLOS_SDK)/Makefile.defines

DEFINES += HAVE_SWAP

DEFINES += APP_SECRET_MODE_ENABLED

$(info ************ TARGET_NAME  = [$(TARGET_NAME)])

include $(CURDIR)/../deps/ledger-zxlib/makefiles/Makefile.app_testing

ifeq ($(SUPPORT_SR25519),1)
DEFINES += SUPPORT_SR25519
OUTPUT_ELF ?= $(CURDIR)/output/app_sr25519.elf
$(info ************  SR25519 ENABLED ************)
endif

ifeq ($(SUBSTRATE_PARSER_FULL),1)
DEFINES += SUBSTRATE_PARSER_FULL
$(info ************ FULL PARSER ENABLED ************)
endif

ifndef COIN
COIN=DOT
endif

include $(CURDIR)/Makefile.version

$(info COIN  = [$(COIN)])

ifeq ($(COIN),DOT)
# Main app configuration
DEFINES += APP_STANDARD
ifneq ($(TARGET_NAME),TARGET_NANOS)
DEFINES += SUBSTRATE_PARSER_FULL
endif
APPNAME = "Polkadot"
APPPATH = "44'/354'" --path "44'/434'"

else ifeq ($(COIN),DOT_XL)
# XL app configuration
DEFINES += APP_STANDARD SUBSTRATE_PARSER_FULL
APPNAME = "Polkadot XL"
APPPATH = "44'/354'" --path "44'/434'"

else
define error_message

COIN value not supported: [$(COIN)]

endef
$(error "$(error_message)")
endif

APP_LOAD_PARAMS = --curve ed25519 $(COMMON_LOAD_PARAMS) --path $(APPPATH)

NANOS_STACK_SIZE := 3160

include $(CURDIR)/../deps/ledger-zxlib/makefiles/Makefile.devices

$(info TARGET_NAME  = [$(TARGET_NAME)])
$(info ICONNAME  = [$(ICONNAME)])

ifndef ICONNAME
$(error ICONNAME is not set)
endif

include $(CURDIR)/../deps/ledger-zxlib/makefiles/Makefile.platform
LDFLAGS += -z muldefs
LDLIBS += -Lrust/target/thumbv6m-none-eabi/release -lrslib
CFLAGS += -Wvla
APP_SOURCE_PATH += $(CURDIR)/rust/include

.PHONY: rust
rust:
	cd rust && CARGO_HOME="$(CURDIR)/rust/.cargo" cargo build --target thumbv6m-none-eabi --release

# Before linking, we need to be sure rust lib is there
bin/app.elf: rust

.PHONY: rust_clean
rust_clean:
	cd rust && CARGO_HOME="$(CURDIR)/rust/.cargo" cargo clean

clean: rust_clean

include $(CURDIR)/../deps/ledger-zxlib/makefiles/Makefile.side_loading

# Import generic rules from the SDK
include $(BOLOS_SDK)/Makefile.rules

#add dependency on custom makefile filename
dep/%.d: %.c Makefile

.PHONY: listvariants
listvariants:
ifeq ($(TARGET_NAME),TARGET_NANOS)
	@echo VARIANTS COIN DOT DOT_XL
else
	@echo VARIANTS COIN DOT
endif

.PHONY: version
version:
	@echo "v$(APPVERSION)" > app.version
