#!/usr/bin/env bash

SCRIPTDIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"

echo $SCRIPTDIR

# Compile fuzzing stub
cd $SCRIPTDIR || exit
mkdir -p cmake-build-fuzz/syncdir
cd cmake-build-fuzz || exit
cmake -DCMAKE_CXX_COMPILER=afl-clang-fast++ ..
make fuzzing_stub

cd $SCRIPTDIR || exit
screen -dmS fuzzerMaster afl-fuzz -i $SCRIPTDIR/tests/inputs/ -o $SCRIPTDIR/cmake-build-fuzz/syncdir/ -M fuzzerMaster -- $SCRIPTDIR/cmake-build-fuzz/fuzzing_stub
screen -dmS fuzzerSlave1 afl-fuzz -i $SCRIPTDIR/tests/inputs/ -o $SCRIPTDIR/cmake-build-fuzz/syncdir/ -S fuzzer1 -- $SCRIPTDIR/cmake-build-fuzz/fuzzing_stub
screen -dmS fuzzerSlave2 afl-fuzz -i $SCRIPTDIR/tests/inputs/ -o $SCRIPTDIR/cmake-build-fuzz/syncdir/ -S fuzzer2 -- $SCRIPTDIR/cmake-build-fuzz/fuzzing_stub
screen -dmS fuzzerSlave3 afl-fuzz -i $SCRIPTDIR/tests/inputs/ -o $SCRIPTDIR/cmake-build-fuzz/syncdir/ -S fuzzer3 -- $SCRIPTDIR/cmake-build-fuzz/fuzzing_stub
screen -dmS fuzzerSlave4 afl-fuzz -i $SCRIPTDIR/tests/inputs/ -o $SCRIPTDIR/cmake-build-fuzz/syncdir/ -S fuzzer4 -- $SCRIPTDIR/cmake-build-fuzz/fuzzing_stub
screen -r fuzzerMaster

#afl-plot ./cmake-build-fuzz/syncdir/fuzzerMaster/ ./cmake-build-fuzz/plots
