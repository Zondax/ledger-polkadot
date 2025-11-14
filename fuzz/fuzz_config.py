#!/usr/bin/env python3
"""
Project-specific fuzzing configuration
"""

import sys
import os

# Configuration constants
MAX_SECONDS = 3600  # 1 hour for quick test
FUZZER_JOBS = 8  # Number of parallel jobs for fuzzing

# Add the common fuzzing module to path
sys.path.append(os.path.join(os.path.dirname(__file__), "..", "deps", "ledger-zxlib", "fuzzing"))

try:
    from run_fuzzers import FuzzConfig
except ImportError:
    # Fallback if common module is not available
    class FuzzConfig:
        def __init__(self, name: str, max_len: int = 17000):
            self.name = name
            self.max_len = max_len


def get_fuzzer_configs():
    """Get project-specific fuzzer configurations"""
    return [
        FuzzConfig(name="metadata_parser_array", max_len=17000),  # Tests metadata_parser_array functionality
        FuzzConfig(name="metadata_parser_composite", max_len=17000),  # Tests metadata_parser_composite functionality
        FuzzConfig(name="metadata_parser_primitives", max_len=17000),  # Tests metadata_parser_primitives functionality
        FuzzConfig(name="metadata_parser_sequence", max_len=17000),  # Tests metadata_parser_sequence functionality
        FuzzConfig(name="metadata_parser_variant", max_len=17000),  # Tests metadata_parser_variant functionality
        FuzzConfig(name="parser_parse", max_len=17000),  # Tests parser_parse functionality
        # Add more fuzzers here as needed
    ]


if __name__ == "__main__":
    # Show available configurations
    configs = get_fuzzer_configs()
    print("Available fuzzer configurations:")
    for config in configs:
        print(f"  - {config.name}: max_len={config.max_len}")
