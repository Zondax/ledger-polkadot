#!/usr/bin/env bash
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
#********************************************************************************/
CONTAINER_NAME='zx-fuzzer-container'
SCRIPTDIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"
DOCKER_IMAGE=zondax/docker-fuzzing:latest
CID=$(docker ps -q -f status=running -f name=^/${CONTAINER_NAME}$)

echo $SCRIPTDIR

if [ ! "${CID}" ]; then
  docker run -it --rm --name ${CONTAINER_NAME} \
  -u $(id -u) -v ${SCRIPTDIR}/../../:/project \
  ${DOCKER_IMAGE}
else
  docker exec -it ${CONTAINER_NAME} /bin/bash
fi
