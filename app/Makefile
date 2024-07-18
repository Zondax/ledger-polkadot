#*******************************************************************************
#  Ledger App
#  (c) 2019 - 2024 Zondax AG
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

include $(BOLOS_SDK)/Makefile.defines

# # Set the default value for HAVE_SWAP to undefined if not already defined
# HAVE_SWAP ?=

# Set the default value for PRODUCTION_BUILD to 0 if not already defined
PRODUCTION_BUILD ?= 1

# Display the target name
$(info ************ TARGET_NAME  = [$(TARGET_NAME)])

# Display whether this is a production build or for internal use
ifeq ($(PRODUCTION_BUILD), 1)
    $(info ************ PRODUCTION_BUILD  = [PRODUCTION BUILD])
else
    $(info ************ PRODUCTION_BUILD  = [INTERNAL USE])
endif

# Display whether swap functionality is enabled or not
ifdef HAVE_SWAP
    $(info ************ HAVE_SWAP  = [ENABLED])
    DEFINES += HAVE_SWAP=$(HAVE_SWAP)
else
    $(info ************ HAVE_SWAP  = [DISABLED])
endif

# Add the PRODUCTION_BUILD definition to the compiler flags
DEFINES += PRODUCTION_BUILD=$(PRODUCTION_BUILD)
include $(CURDIR)/../deps/ledger-zxlib/makefiles/Makefile.app_testing

ifndef COIN
COIN=DOT
endif

include $(CURDIR)/Makefile.version
$(info COIN  = [$(COIN)])

APPPATH = "44'/354'"

ifeq ($(COIN),DOT)
# Main app configuration
APPNAME = "Polkadot"

else ifeq ($(COIN),DOT_MIGRATION)
# Migration app configuration
APPNAME = "Polkadot Migration"
DEFINES += POSTPONE_MAIN_SCREEN_INIT
DEFINES += MIGRATION_APP
include $(CURDIR)/Makefile.migration

INSTALLER_NAME = migration
ICON_NAME = migration
ELF_NAME = migration

else
define error_message
COIN value not supported: [$(COIN)]
endef
$(error "$(error_message)")
endif

include $(CURDIR)/../deps/ledger-zxlib/makefiles/Makefile.installer_script

$(info PATHS LIST = $(APPPATH))

APP_LOAD_PARAMS = --curve ed25519 $(COMMON_LOAD_PARAMS) --path $(APPPATH)

ifeq ($(TARGET_NAME),TARGET_NANOS)
	APP_STACK_MIN_SIZE := 1600
else
	APP_STACK_MIN_SIZE := 1752
endif

include $(CURDIR)/../deps/ledger-zxlib/makefiles/Makefile.devices

DEFAULT_NANOS_ICON = nanos_$(ICON_NAME).gif
DEFAULT_NBGL_ICON_32 = stax_$(ICON_NAME).gif
DEFAULT_NBGL_ICON_64 = stax_$(ICON_NAME)_64.gif

copy_icon:
	cp $(DEFAULT_NANOS_ICON) glyphs/icon_app.gif
	cp $(DEFAULT_NBGL_ICON_32) glyphs/icon_stax_32.gif
	cp $(DEFAULT_NBGL_ICON_64) glyphs/icon_stax_64.gif

all: copy_icon

$(info TARGET_NAME  = [$(TARGET_NAME)])
$(info ICONNAME  = [$(ICONNAME)])

ifndef ICONNAME
$(error ICONNAME is not set)
endif

include $(CURDIR)/../deps/ledger-zxlib/makefiles/Makefile.platform
LDFLAGS += -z muldefs

DEFINES += BLAKE3_NO_SSE2 BLAKE3_NO_SSE41 BLAKE3_NO_AVX2 BLAKE3_NO_AVX512 BLAKE3_USE_NEON=0
BLAKE3_DIR := $(CURDIR)/../deps/BLAKE3-c
INCLUDES_PATH += $(BLAKE3_DIR)
APP_SOURCE_FILES += $(BLAKE3_DIR)/blake3.c $(BLAKE3_DIR)/blake3_dispatch.c $(BLAKE3_DIR)/blake3_portable.c

.PHONY: rust
rust:
	@echo "No rust code"

.PHONY: rust_clean
rust_clean:
	@echo "No rust code"

clean: rust_clean

include $(CURDIR)/../deps/ledger-zxlib/makefiles/Makefile.side_loading

# Import generic rules from the SDK
include $(BOLOS_SDK)/Makefile.rules

#add dependency on custom makefile filename
dep/%.d: %.c Makefile

.PHONY: listvariants
listvariants:
	@echo VARIANTS COIN DOT DOT_MIGRATION

.PHONY: version
version:
	@echo "v$(APPVERSION)" > app.version
