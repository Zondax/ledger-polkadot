#!/usr/bin/env bash
#*******************************************************************************
#  (c) 2018 Zondax GmbH
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

if [ -z "$APPNAME" ]
then
  echo "This script has not been configured correctly"
  exit 1
fi

# check python 3 has been installed
if ! command -v python3 &>/dev/null; then
    echo Python 3 is not installed
    exit
fi

python3 -m ledgerblue.loadApp -h &>/dev/null;
if [ $? -ne 0 ]; then
    echo
    echo "ERR: ledgerblue pip package not found."
    echo "please install using 'pip install ledgerblue'"
    echo
    exit
fi

TMP_HEX_DIR=$(mktemp -d -t ci-XXXXXXXXXX)
mkdir -p ${TMP_HEX_DIR}/bin
BIN_HEX_FILE=${TMP_HEX_DIR}/bin/app.hex
echo -e "${APPHEX}" > ${BIN_HEX_FILE}

case "$1" in
  'load')
  cd "$TMP_HEX_DIR" || exit
  python3 -m ledgerblue.loadApp --appFlags 0x200 --delete ${LOAD_PARAMS} --path ${APPPATH} --path "44'/1'"
  ;;
  'delete')
  python3 -m ledgerblue.deleteApp ${DELETE_PARAMS}
  ;;
  'version')
  echo "v${APPVERSION}"
  ;;
  *)
    echo "Zondax Installer [$APPNAME-$APPVERSION] [Warning: use only for test/demo apps]"
    echo "  load    - Load $APPNAME app"
    echo "  delete  - Delete $APPNAME app"
    echo "  version - Show $APPNAME app version"
esac
