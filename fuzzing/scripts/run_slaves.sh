#!/usr/bin/env bash

SCRIPTDIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"
BUILDDIR=$SCRIPTDIR/../../cmake-build-fuzz
INPUTS=$SCRIPTDIR/../inputs

AFL_I_DONT_CARE_ABOUT_MISSING_CRASHES=1 afl-fuzz -t 50 -i $INPUTS -o $BUILDDIR/syncdir -S fuzzer1 -- $BUILDDIR/fuzzing_stub &
AFL_I_DONT_CARE_ABOUT_MISSING_CRASHES=1 afl-fuzz -t 50 -i $INPUTS -o $BUILDDIR/syncdir -S fuzzer2 -- $BUILDDIR/fuzzing_stub &
AFL_I_DONT_CARE_ABOUT_MISSING_CRASHES=1 afl-fuzz -t 50 -i $INPUTS -o $BUILDDIR/syncdir -S fuzzer3 -- $BUILDDIR/fuzzing_stub &
AFL_I_DONT_CARE_ABOUT_MISSING_CRASHES=1 afl-fuzz -t 50 -i $INPUTS -o $BUILDDIR/syncdir -S fuzzer4 -- $BUILDDIR/fuzzing_stub &
