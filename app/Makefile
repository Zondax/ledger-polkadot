#*******************************************************************************
#  Ledger App
#  (c) 2019 - 2022 Zondax GmbH
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

all: bin/app.elf
	@echo "#!/usr/bin/env bash" > $(OUTPUT_INSTALLER)
	@echo "APPNAME=\"${APPNAME}\"" >> $(OUTPUT_INSTALLER)
	@echo "APPVERSION=\"${APPVERSION}\"" >> $(OUTPUT_INSTALLER)
	@echo "APPPATH=\""${APPPATH}"\"" >> $(OUTPUT_INSTALLER)
	@echo "LOAD_PARAMS=\"${COMMON_LOAD_PARAMS}\"" >> $(OUTPUT_INSTALLER)
	@echo "DELETE_PARAMS=\"${COMMON_DELETE_PARAMS}\"" >> $(OUTPUT_INSTALLER)
	@echo "APPHEX=\"" >> $(OUTPUT_INSTALLER)
	@cat $(CURDIR)/bin/app.hex >> $(OUTPUT_INSTALLER)
	@echo "\"" >> $(OUTPUT_INSTALLER)
	@cat $(CURDIR)/../deps/ledger-zxlib/scripts/template.sh >> $(OUTPUT_INSTALLER)
	@chmod +x $(OUTPUT_INSTALLER)
	@cp $(CURDIR)/bin/* $(CURDIR)/output
	@cp $(CURDIR)/output/app.elf ${OUTPUT_ELF}
	@rm $(CURDIR)/output/app.elf

include $(BOLOS_SDK)/Makefile.defines

DEFINES += APP_SECRET_MODE_ENABLED

$(info ************ TARGET_NAME  = [$(TARGET_NAME)])

ifeq ($(APP_TESTING),1)
DEFINES += APP_TESTING
DEFINES += ZEMU_LOGGING
$(info ************ LOGGING ENABLED ************)
endif

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
APPPATH = "44'/354'"  --path "44'/434'"

else ifeq ($(COIN),DOT_XL)
# XL app configuration
DEFINES += APP_STANDARD SUBSTRATE_PARSER_FULL
APPNAME = "Polkadot XL"
APPPATH = "44'/354'"  --path "44'/434'"

else
define error_message


COIN value not supported: [$(COIN)]


endef
$(error "$(error_message)")
endif

APP_LOAD_PARAMS = --curve ed25519 --delete $(COMMON_LOAD_PARAMS) --path $(APPPATH)

ifeq ($(TARGET_NAME),TARGET_NANOS)
APP_LOAD_PARAMS += --appFlags 0x000
APP_STACK_SIZE:=3216
ICONNAME:=$(CURDIR)/nanos_icon.gif
OUTPUT_ELF ?= $(CURDIR)/output/app_s.elf
OUTPUT_INSTALLER := $(CURDIR)/pkg/installer_s.sh
endif

ifeq ($(TARGET_NAME),TARGET_NANOX)
APP_LOAD_PARAMS += --appFlags 0x200
SCRIPT_LD:=$(CURDIR)/script_x.ld
ICONNAME:=$(CURDIR)/nanox_icon.gif
OUTPUT_ELF ?= $(CURDIR)/output/app_x.elf
OUTPUT_INSTALLER:= $(CURDIR)/pkg/installer_x.sh
endif

ifeq ($(TARGET_NAME),TARGET_NANOS2)
APP_LOAD_PARAMS += --appFlags 0x200
SCRIPT_LD:=$(CURDIR)/script_s2.ld
ICONNAME:=$(CURDIR)/nanox_icon.gif
OUTPUT_ELF ?= $(CURDIR)/output/app_s2.elf
OUTPUT_INSTALLER:= $(CURDIR)/pkg/installer_s2.sh
endif

$(info TARGET_NAME  = [$(TARGET_NAME)])
$(info ICONNAME  = [$(ICONNAME)])

ifndef ICONNAME
$(error ICONNAME is not set)
endif

############
# Platform

DEFINES       += PRINTF\(...\)=

APPVERSION=$(APPVERSION_M).$(APPVERSION_N).$(APPVERSION_P)
DEFINES       += APPVERSION=\"$(APPVERSION)\"

DEFINES       += OS_IO_SEPROXYHAL
DEFINES       += HAVE_BAGL HAVE_SPRINTF
DEFINES       += HAVE_IO_USB HAVE_L4_USBLIB IO_USB_MAX_ENDPOINTS=7 IO_HID_EP_LENGTH=64 HAVE_USB_APDU

DEFINES       += LEDGER_MAJOR_VERSION=$(APPVERSION_M) LEDGER_MINOR_VERSION=$(APPVERSION_N) LEDGER_PATCH_VERSION=$(APPVERSION_P)

DEFINES       += USB_SEGMENT_SIZE=64
DEFINES       += HAVE_BOLOS_APP_STACK_CANARY

DEFINES       += HAVE_WEBUSB WEBUSB_URL_SIZE_B=0 WEBUSB_URL=""

ifeq ($(TARGET_NAME),TARGET_NANOS)
DEFINES       += IO_SEPROXYHAL_BUFFER_SIZE_B=128
else
# Assume Nano X/S+
DEFINES       += IO_SEPROXYHAL_BUFFER_SIZE_B=300

DEFINES       += HAVE_GLO096
DEFINES       += HAVE_BAGL BAGL_WIDTH=128 BAGL_HEIGHT=64
DEFINES       += HAVE_BAGL_ELLIPSIS # long label truncation feature
DEFINES       += HAVE_BAGL_FONT_OPEN_SANS_REGULAR_11PX
DEFINES       += HAVE_BAGL_FONT_OPEN_SANS_EXTRABOLD_11PX
DEFINES       += HAVE_BAGL_FONT_OPEN_SANS_LIGHT_16PX

DEFINES       += HAVE_UX_FLOW
endif

ifeq ($(TARGET_NAME),TARGET_NANOX)
# X specific
DEFINES       += HAVE_BLE
DEFINES       += HAVE_BLE_APDU BLE_COMMAND_TIMEOUT_MS=2000

SDK_SOURCE_PATH  += lib_blewbxx lib_blewbxx_impl
endif

# App specific

#Feature temporarily disabled
DEFINES   += LEDGER_SPECIFIC

# Compiler, assembler, and linker

ifneq ($(BOLOS_ENV),)
$(info BOLOS_ENV is $(BOLOS_ENV))
CLANGPATH := /usr/bin/
GCCPATH := /usr/bin/
else
$(info BOLOS_ENV is not set: falling back to CLANGPATH and GCCPATH)
endif

ifeq ($(CLANGPATH),)
$(info CLANGPATH is not set: clang will be used from PATH)
endif

ifeq ($(GCCPATH),)
$(info GCCPATH is not set: arm-none-eabi-* will be used from PATH)
endif

#########################

CC := $(CLANGPATH)clang
CFLAGS += -O3 -Os -Wno-unknown-pragmas -Wno-unused-parameter -Wvla

AS := $(GCCPATH)arm-none-eabi-gcc
AFLAGS +=

LD       := $(GCCPATH)arm-none-eabi-gcc
LDFLAGS  += -O3 -Os
LDFLAGS  += -z muldefs
LDLIBS   += -lm -lgcc -lc
LDLIBS   += -Lrust/target/thumbv6m-none-eabi/release -lrslib

##########################
GLYPH_SRC_DIR = glyphs
INCLUDES_PATH += $(MY_DIR)/glyphs
include $(BOLOS_SDK)/Makefile.glyphs

APP_SOURCE_PATH += $(MY_DIR)/src
APP_SOURCE_PATH += $(MY_DIR)/glyphs
APP_SOURCE_PATH += $(MY_DIR)/rust/include
APP_SOURCE_PATH += $(MY_DIR)/../deps/ledger-zxlib/include
APP_SOURCE_PATH += $(MY_DIR)/../deps/ledger-zxlib/src
APP_SOURCE_PATH += $(MY_DIR)/../deps/ledger-zxlib/app/common

SDK_SOURCE_PATH += lib_stusb lib_stusb_impl
SDK_SOURCE_PATH  += lib_ux

.PHONY: rust
rust:
	cd rust && CARGO_HOME="$(CURDIR)/rust/.cargo" cargo build --target thumbv6m-none-eabi --release

# Before linking, we need to be sure rust lib is there
bin/app.elf: rust

.PHONY: rust_clean
rust_clean:
	cd rust && CARGO_HOME="$(CURDIR)/rust/.cargo" cargo clean

clean: rust_clean

# load, delete and listvariants are provided to comply with Ledger requirements
.PHONY: load
load:
	python3 -m ledgerblue.loadApp $(APP_LOAD_PARAMS)

.PHONY: delete
delete:
	python3 -m ledgerblue.deleteApp $(COMMON_DELETE_PARAMS)

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
