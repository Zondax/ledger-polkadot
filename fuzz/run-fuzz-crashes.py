#!/usr/bin/env python3
"""
Local convenience wrapper for analyzing fuzzer crashes
"""

import os
import sys

# Add the common fuzzing module to path
current_dir = os.path.dirname(os.path.abspath(__file__))
project_root = os.path.dirname(current_dir)
common_fuzzing_path = os.path.join(project_root, "deps", "ledger-zxlib", "fuzzing")

sys.path.insert(0, common_fuzzing_path)

try:
    from analyze_crashes import main

    # Override default arguments to point to this project root
    if "--fuzz-dir" not in sys.argv:
        sys.argv.extend(["--fuzz-dir", current_dir])
    
    # Set a shorter timeout to avoid infinite loops during crash analysis
    if "--timeout" not in sys.argv:
        sys.argv.extend(["--timeout", "10"])

    # Run the common crash analyzer
    sys.exit(main())

except ImportError as e:
    print(f"Error: Cannot import common fuzzing module: {e}")
    print("Make sure deps/ledger-zxlib/fuzzing/analyze_crashes.py exists")
    sys.exit(1)
