#!/usr/bin/env bash

SCRIPTDIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"

afl-plot $SCRIPTDIR/cmake-build-fuzz/syncdir/fuzzerMaster/ $SCRIPTDIR/cmake-build-fuzz/plots || exit
