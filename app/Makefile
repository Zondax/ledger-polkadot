#*******************************************************************************
#   Ledger App
#   (c) 2018-2020 Zondax GmbH
#   (c) 2017 Ledger
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

ifeq ($(APP_TESTING),1)
DEFINES += APP_TESTING
DEFINES += ZEMU_LOGGING
endif

all: bin/app.elf
	@echo "#!/usr/bin/env bash" > $(CURDIR)/pkg/zxtool.sh
	@echo "APPNAME=\"${APPNAME}\"" >> $(CURDIR)/pkg/zxtool.sh
	@echo "APPVERSION=\"${APPVERSION}\"" >> $(CURDIR)/pkg/zxtool.sh
	@echo "APPPATH=\""${APPPATH}"\"" >> $(CURDIR)/pkg/zxtool.sh
	@echo "LOAD_PARAMS=\"${COMMON_LOAD_PARAMS}\"" >> $(CURDIR)/pkg/zxtool.sh
	@echo "DELETE_PARAMS=\"${COMMON_DELETE_PARAMS}\"" >> $(CURDIR)/pkg/zxtool.sh
	@echo "APPHEX=\"" >> $(CURDIR)/pkg/zxtool.sh
	@cat $(CURDIR)/bin/app.hex >> $(CURDIR)/pkg/zxtool.sh
	@echo "\"" >> $(CURDIR)/pkg/zxtool.sh
	@cat $(CURDIR)/../deps/ledger-zxlib/scripts/template.sh >> $(CURDIR)/pkg/zxtool.sh
	@chmod +x $(CURDIR)/pkg/zxtool.sh
	@cp $(CURDIR)/bin/app.elf ${OUTPUT_ELF}


include $(BOLOS_SDK)/Makefile.defines

ifndef COIN
COIN=DOT
endif

include $(CURDIR)/Makefile.version

$(info COIN  = [$(COIN)])
ifeq ($(COIN),DOT)
# Main app configuration
DEFINES += APP_STANDARD
APPNAME = "Polkadot"
APPPATH = "44'/354'"

else ifeq ($(COIN),Ledgeracio)
DEFINES += APP_RESTRICTED
APPNAME = "Polkadot_sec"
APPPATH = "44'/354'"

else
define error_message


COIN value not supported: [$(COIN)]


endef
$(error "$(error_message)")
endif

APP_LOAD_PARAMS = --appFlags 0x200 --delete $(COMMON_LOAD_PARAMS) --path $(APPPATH)

ifeq ($(TARGET_NAME),TARGET_NANOS)
SCRIPT_LD:=$(CURDIR)/script.ld
OUTPUT_ELF:= $(CURDIR)/bin/app_s.elf
ICONNAME:=$(CURDIR)/nanos_icon.gif
endif

ifeq ($(TARGET_NAME),TARGET_NANOX)
OUTPUT_ELF:= $(CURDIR)/bin/app_x.elf
ICONNAME:=$(CURDIR)/nanox_icon.gif
endif

ifndef ICONNAME
$(error ICONNAME is not set)
endif

############
# Platform

DEFINES       += UNUSED\(x\)=\(void\)x
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

ifeq ($(TARGET_NAME),TARGET_NANOX)
DEFINES       += IO_SEPROXYHAL_BUFFER_SIZE_B=300

DEFINES       += HAVE_GLO096
DEFINES       += HAVE_BAGL BAGL_WIDTH=128 BAGL_HEIGHT=64
DEFINES       += HAVE_BAGL_ELLIPSIS # long label truncation feature
DEFINES       += HAVE_BAGL_FONT_OPEN_SANS_REGULAR_11PX
DEFINES       += HAVE_BAGL_FONT_OPEN_SANS_EXTRABOLD_11PX
DEFINES       += HAVE_BAGL_FONT_OPEN_SANS_LIGHT_16PX

DEFINES       += HAVE_UX_FLOW

DEFINES       += HAVE_BLE
DEFINES       += HAVE_BLE_APDU BLE_COMMAND_TIMEOUT_MS=2000

SDK_SOURCE_PATH  += lib_blewbxx lib_blewbxx_impl
else
# Assume Nano S
DEFINES       += IO_SEPROXYHAL_BUFFER_SIZE_B=128
DEFINES       += HAVE_BOLOS_UX COMPLIANCE_UX_160 HAVE_UX_LEGACY
endif

# X specific

#Feature temporarily disabled
DEFINES   += LEDGER_SPECIFIC

# Compiler, assembler, and linker

ifneq ($(BOLOS_ENV),)
$(info BOLOS_ENV is $(BOLOS_ENV))
CLANGPATH := $(BOLOS_ENV)/clang-arm-fropi/bin/
GCCPATH := $(BOLOS_ENV)/gcc-arm-none-eabi-5_3-2016q1/bin/
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
CFLAGS += -O3 -Os -Wno-unknown-pragmas

AS := $(GCCPATH)arm-none-eabi-gcc
AFLAGS +=

LD       := $(GCCPATH)arm-none-eabi-gcc
LDFLAGS  += -O3 -Os
LDLIBS   += -lm -lgcc -lc
#LDLIBS   += -Lrust/target/thumbv6m-none-eabi/release -lrslib

##########################
include $(BOLOS_SDK)/Makefile.glyphs

APP_SOURCE_PATH += $(MY_DIR)/src
#APP_SOURCE_PATH += $(MY_DIR)/rust/include
APP_SOURCE_PATH += $(MY_DIR)/../deps/ledger-zxlib/include
APP_SOURCE_PATH += $(MY_DIR)/../deps/ledger-zxlib/src
APP_SOURCE_PATH += $(MY_DIR)/../deps/ledger-zxlib/app/common

SDK_SOURCE_PATH += lib_stusb lib_stusb_impl
SDK_SOURCE_PATH  += lib_ux

.PHONY: rust
rust:
# DISABLED
#	cd rust && CARGO_HOME="$(CURDIR)/rust/.cargo" cargo build --target thumbv6m-none-eabi --release

# Before linking, we need to be sure rust lib is there
bin/app.elf: rust

.PHONY: rust_clean
rust_clean:
# DISABLED
#	cd rust && CARGO_HOME="$(CURDIR)/rust/.cargo" cargo clean

clean: rust_clean

# load, delete and listvariants are provided to comply with Ledger requirements
.PHONY: load
load:
	python -m ledgerblue.loadApp $(APP_LOAD_PARAMS)

.PHONY: delete
delete:
	python -m ledgerblue.deleteApp $(COMMON_DELETE_PARAMS)

# Import generic rules from the SDK
include $(BOLOS_SDK)/Makefile.rules

#add dependency on custom makefile filename
dep/%.d: %.c Makefile

.PHONY: listvariants
listvariants:
	@echo VARIANTS COIN DOT
