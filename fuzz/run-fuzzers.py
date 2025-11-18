#!/usr/bin/env python3
"""
Local convenience wrapper for running fuzzers
"""

import os
import sys

# Add the common fuzzing module to path
current_dir = os.path.dirname(os.path.abspath(__file__))
project_root = os.path.dirname(current_dir)
common_fuzzing_path = os.path.join(project_root, "deps", "ledger-zxlib", "fuzzing")

sys.path.insert(0, common_fuzzing_path)

try:
    from run_fuzzers import main
    from fuzz_config import MAX_SECONDS, FUZZER_JOBS

    # Override default arguments to point to this project root
    if "--fuzz-dir" not in sys.argv:
        sys.argv.extend(["--fuzz-dir", current_dir])

    # Override max-seconds if not provided
    if "--max-seconds" not in sys.argv:
        sys.argv.extend(["--max-seconds", str(MAX_SECONDS)])

    # Override jobs if not provided
    if "--jobs" not in sys.argv:
        sys.argv.extend(["--jobs", str(FUZZER_JOBS)])

    # Run the common fuzzer
    sys.exit(main())

except ImportError as e:
    print(f"Error: Cannot import common fuzzing module: {e}")
    print("Make sure deps/ledger-zxlib/fuzzing/run_fuzzers.py exists")
    sys.exit(1)
