#!/usr/bin/env python3

import os
import random
import shlex
import subprocess

MAX_SECONDS_PER_RUN = 600
MUTATE_DEPTH = random.randint(1, 20)

# (fuzzer name, max length, max time scale factor)
CONFIGS = [
    ('parser_parse', 17000, 4),
]

for config in CONFIGS:
    fuzzer, max_len, scale_factor = config
    max_time = MAX_SECONDS_PER_RUN * scale_factor
    print(f'######## {fuzzer} ########')

    artifact_dir = os.path.join('fuzz', 'corpora', f'{fuzzer}-artifacts')
    corpus_dir = os.path.join('fuzz', 'corpora', f'{fuzzer}')
    fuzz_path = os.path.join(f'build/bin/fuzz-{fuzzer}')

    os.makedirs(artifact_dir, exist_ok=True)
    os.makedirs(corpus_dir, exist_ok=True)

    env = os.environ.copy()
    env['ASAN_OPTIONS'] = 'halt_on_error=1:print_stacktrace=1'
    env['UBSAN_OPTIONS'] = 'halt_on_error=1:print_stacktrace=1'

    crash_files = os.listdir(artifact_dir)
    for c in crash_files:
        c_full_path = os.path.join(artifact_dir, c)
        cmd = [fuzz_path, f'{c_full_path}']
        print(' '.join(shlex.quote(c) for c in cmd))
        error_code = subprocess.call(cmd, env=env)
        if error_code != 0:
            exit(error_code)


