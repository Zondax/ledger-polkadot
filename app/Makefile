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

########################################
#        Mandatory configuration       #
########################################
# Upload targets to configure the devices 
include $(BOLOS_SDK)/Makefile.defines

ifndef COIN
COIN=DOT
endif
$(info COIN  = [$(COIN)])
VARIANT_PARAM=COIN
VARIANT_VALUES=$(COIN)

# Application allowed derivation paths.
# You should request a specific path for your app.
# This serve as an isolation mechanism.
# Most application will have to request a path according to the BIP-0044
# and SLIP-0044 standards.
# If your app needs it, you can specify multiple path by using:
# `PATH_APP_LOAD_PARAMS = "44'/1'" "45'/1'"`
APPPATH = "44'/354'"


ifeq ($(COIN),DOT)
# Main app configuration
APPNAME = "Polkadot"
ICON_NAME = icon
HAVE_SWAP ?= 1

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

$(info PATHS LIST = $(APPPATH))
PATH_APP_LOAD_PARAMS = $(APPPATH)

# Application version
include $(CURDIR)/Makefile.version
APPVERSION = "$(APPVERSION_M).$(APPVERSION_N).$(APPVERSION_P)"

# Application source files
APP_SOURCE_PATH += src
DEFINES += BLAKE3_NO_SSE2 BLAKE3_NO_SSE41 BLAKE3_NO_AVX2 BLAKE3_NO_AVX512 BLAKE3_USE_NEON=0
BLAKE3_DIR := ../deps/BLAKE3/c
INCLUDES_PATH += $(BLAKE3_DIR)
APP_SOURCE_FILES += $(BLAKE3_DIR)/blake3.c $(BLAKE3_DIR)/blake3_dispatch.c $(BLAKE3_DIR)/blake3_portable.c

# Application icons following guidelines:
# https://developers.ledger.com/docs/embedded-app/design-requirements/#device-icon

DEFAULT_NANOS_ICON = nanos_$(ICON_NAME).gif
DEFAULT_NBGL_ICON_32 = stax_$(ICON_NAME).gif
DEFAULT_NBGL_ICON_64 = stax_$(ICON_NAME)_64.gif
DEFAULT_NBGL_ICON_48 = apex_p_$(ICON_NAME)_48.png

copy_icon:
	cp $(DEFAULT_NANOS_ICON) glyphs/icon_app.gif
	cp $(DEFAULT_NBGL_ICON_32) glyphs/icon_stax_32.gif
	cp $(DEFAULT_NBGL_ICON_64) glyphs/icon_stax_64.gif
	cp $(DEFAULT_NBGL_ICON_48) glyphs/icon_apex_p_48.png

all: copy_icon


ICON_NANOS = nanos_icon.gif
ICON_NANOX = nanox_icon.gif
ICON_NANOSP = nanox_icon.gif
ICON_STAX = stax_icon.gif
ICON_FLEX = flex_icon.gif
ICON_APEX_P = apex_p_icon.png

# Application allowed derivation curves.
# Possibles curves are: secp256k1, secp256r1, ed25519 and bls12381g1
# If your app needs it, you can specify multiple curves by using:
# `CURVE_APP_LOAD_PARAMS = <curve1> <curve2>`
ifeq ($(COIN),DOT)
CURVE_APP_LOAD_PARAMS = ed25519 secp256k1
else ifeq ($(COIN),DOT_MIGRATION)
CURVE_APP_LOAD_PARAMS = ed25519
endif

INCLUDES_PATH += $(CURDIR)/src/common
INCLUDES_PATH += $(CURDIR)/src/swap
INCLUDES_PATH += ../deps/ledger-zxlib/include

########################################
# Application communication interfaces #
########################################
ENABLE_BLUETOOTH = 1
#ENABLE_NFC = 1

########################################
#         NBGL custom features         #
########################################
ENABLE_NBGL_QRCODE = 1
#ENABLE_NBGL_KEYBOARD = 1
#ENABLE_NBGL_KEYPAD = 1

########################################
#          Features disablers          #
########################################
# These advanced settings allow to disable some feature that are by
# default enabled in the SDK `Makefile.standard_app`.
#DISABLE_STANDARD_APP_FILES = 1
#DISABLE_DEFAULT_IO_SEPROXY_BUFFER_SIZE = 1 # To allow custom size declaration
#DISABLE_STANDARD_APP_DEFINES = 1 # Will set all the following disablers
#DISABLE_STANDARD_SNPRINTF = 1
#DISABLE_STANDARD_USB = 1
#DISABLE_STANDARD_WEBUSB = 1
#DISABLE_DEBUG_LEDGER_ASSERT = 1
#DISABLE_DEBUG_THROW = 1

########################################
#        Other configurations          #
########################################
# Set the default value for PRODUCTION_BUILD to 0 if not already defined
PRODUCTION_BUILD ?= 1

# Display whether this is a production build or for internal use
ifeq ($(PRODUCTION_BUILD), 1)
    $(info ************ PRODUCTION_BUILD  = [PRODUCTION BUILD])
else
    $(info ************ PRODUCTION_BUILD  = [INTERNAL USE])
endif

# Add the PRODUCTION_BUILD definition to the compiler flags
DEFINES += PRODUCTION_BUILD=$(PRODUCTION_BUILD)

# Display whether swap functionality is enabled or not
ifdef HAVE_SWAP
    $(info ************ HAVE_SWAP  = [ENABLED])
    DEFINES += HAVE_SWAP=$(HAVE_SWAP)
else
    $(info ************ HAVE_SWAP  = [DISABLED])
endif

########################################
# Configure devices and permissions
include $(CURDIR)/../deps/ledger-zxlib/makefiles/Makefile.devices
# Create installer script
include $(CURDIR)/../deps/ledger-zxlib/makefiles/Makefile.installer_script
# Enable logging
include $(CURDIR)/../deps/ledger-zxlib/makefiles/Makefile.app_testing
# Call standard app flags
include $(CURDIR)/../deps/ledger-zxlib/makefiles/Makefile.platform

# Use small buffers for NanoX
ifeq ($(TARGET_NAME), TARGET_NANOX)
CFLAGS += -DZXLIB_LIGHT_MODE
endif

$(info TARGET_NAME  = [$(TARGET_NAME)])
$(info ICONNAME  = [$(ICONNAME)])
ifeq ($(ICONNAME),)
$(error ICONNAME is not set)
endif

.PHONY: listvariants
listvariants:
	@echo VARIANTS COIN DOT DOT_MIGRATION

.PHONY: version
version:
	@echo "v$(APPVERSION)" > app.version
