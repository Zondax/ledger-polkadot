#*******************************************************************************
#*   (c) 2019 ZondaX GmbH
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

.PHONY: all deps build clean load delete

MAKEFILE_DIR := $(dir $(abspath $(lastword $(MAKEFILE_LIST))))

build:
	${MAKEFILE_DIR}/scripts/build.sh

run:
	${MAKEFILE_DIR}/scripts/run.sh

run_slaves:
	${MAKEFILE_DIR}/scripts/run_slaves.sh

plot:
	${MAKEFILE_DIR}/scripts/plot.sh

login:
	${MAKEFILE_DIR}/scripts/login.sh
