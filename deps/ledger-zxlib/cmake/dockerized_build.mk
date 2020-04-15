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

.PHONY: all deps build clean load delete check_python show_info_recovery_mode

LEDGER_SRC=$(CURDIR)/app
DOCKER_APP_SRC=/project
DOCKER_APP_BIN=$(DOCKER_APP_SRC)/app/bin/app.elf

DOCKER_IMAGE=zondax/ledger-docker-bolos:latest
DOCKER_BOLOS_SDK=/project/deps/nanos-secure-sdk
DOCKER_BOLOS_SDKX=/project/deps/nano2-sdk

SCP_PUBKEY=049bc79d139c70c83a4b19e8922e5ee3e0080bb14a2e8b0752aa42cda90a1463f689b0fa68c1c0246845c2074787b649d0d8a6c0b97d4607065eee3057bdf16b83
SCP_PRIVKEY=ff701d781f43ce106f72dc26a46b6a83e053b5d07bb3d4ceab79c91ca822a66b

INTERACTIVE:=$(shell [ -t 0 ] && echo 1)

ifdef INTERACTIVE
INTERACTIVE_SETTING:="-i"
TTY_SETTING:="-t"
else
INTERACTIVE_SETTING:=
TTY_SETTING:=
endif

define run_docker
	docker run $(TTY_SETTING) $(INTERACTIVE_SETTING) --rm \
	--privileged \
	-e SCP_PRIVKEY=$(SCP_PRIVKEY) \
	-e BOLOS_SDK=$(1) \
	-e BOLOS_ENV=/opt/bolos \
	-p 1234:1234 \
	-p 8001:8001 \
	-p 9998-9999:9998-9999 \
	-u $(shell id -u) \
	-v $(shell pwd):/project \
	-e DISPLAY=$(shell echo ${DISPLAY}) \
	-v /tmp/.X11-unix:/tmp/.X11-unix:ro \
	$(DOCKER_IMAGE) \
	"$(2)"
endef

all: build

check_python:
	@python -c 'import sys; sys.exit(3-sys.version_info.major)' || (echo "The python command does not point to Python 3"; exit 1)

deps: check_python
	@echo "Install dependencies"
	$(CURDIR)/deps/ledger-zxlib/install_deps.sh

pull:
	docker pull $(DOCKER_IMAGE)

build_rust:
	$(call run_docker,$(DOCKER_BOLOS_SDK),make -C $(DOCKER_APP_SRC) rust)

build: build_rust
	$(info Replacing app icon)
	@cp $(LEDGER_SRC)/nanos_icon.gif $(LEDGER_SRC)/glyphs/icon_app.gif
	$(info calling make inside docker)
	$(call run_docker,$(DOCKER_BOLOS_SDK),make -C $(DOCKER_APP_SRC))

buildX: build_rust
	@cp $(LEDGER_SRC)/nanos_icon.gif $(LEDGER_SRC)/glyphs/icon_app.gif
	@convert $(LEDGER_SRC)/nanos_icon.gif -crop 14x14+1+1 +repage -negate $(LEDGER_SRC)/nanox_icon.gif
	$(call run_docker,$(DOCKER_BOLOS_SDKX),make -C $(DOCKER_APP_SRC))

clean:
	$(call run_docker,$(DOCKER_BOLOS_SDK),make -C $(DOCKER_APP_SRC) clean)

shell:
	$(call run_docker,$(DOCKER_BOLOS_SDK) -t,bash)

debug: build
	$(call run_docker,$(DOCKER_BOLOS_SDK),/home/zondax/speculos/speculos.py --debug --display headless -t $(DOCKER_APP_BIN))

emu: build
	$(call run_docker,$(DOCKER_BOLOS_SDK),/home/zondax/speculos/speculos.py --ontop --zoom 3 --vnc-port 8001 $(DOCKER_APP_BIN))


load:
	${LEDGER_SRC}/pkg/zxtool.sh load

delete:
	${LEDGER_SRC}/pkg/zxtool.sh delete

show_info_recovery_mode:
	@echo "This command requires a Ledger Nano S in recovery mode. To go into recovery mode, follow:"
	@echo " 1. Settings -> Device -> Reset all and confirm"
	@echo " 2. Unplug device, press and hold the right button, plug-in again"
	@echo " 3. Navigate to the main menu"
	@echo "If everything was correct, no PIN needs to be entered."

# This target will initialize the device with the integration testing mnemonic
dev_init: show_info_recovery_mode
	@echo "Initializing device with test mnemonic! WARNING TAKES 2 MINUTES AND REQUIRES RECOVERY MODE"
	@python -m ledgerblue.hostOnboard --apdu --id 0 --prefix "" --passphrase "" --pin 5555 --words "equip will roof matter pink blind book anxiety banner elbow sun young"

# This target will initialize the device with the secondary integration testing mnemonic (Bob)
dev_init_secondary: check_python show_info_recovery_mode
	@echo "Initializing device with secondary test mnemonic! WARNING TAKES 2 MINUTES AND REQUIRES RECOVERY MODE"
	@python -m ledgerblue.hostOnboard --apdu --id 0 --prefix "" --passphrase "" --pin 5555 --words "elite vote proof agree february step sibling sand grocery axis false cup"

# This target will setup a custom developer certificate
dev_ca: check_python
	@python -m ledgerblue.setupCustomCA --targetId 0x31100004 --public $(SCP_PUBKEY) --name zondax

dev_ca_delete: check_python
	@python -m ledgerblue.resetCustomCA --targetId 0x31100004

# This target will setup a custom developer certificate
dev_ca2: check_python
	@python -m ledgerblue.setupCustomCA --targetId 0x33000004 --public $(SCP_PUBKEY) --name zondax

dev_ca_delete2: check_python
	@python -m ledgerblue.resetCustomCA --targetId 0x33000004
