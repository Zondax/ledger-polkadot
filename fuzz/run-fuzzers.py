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

    cmd = [fuzz_path, f'-max_total_time={max_time}',
           f'-jobs=16'
           f'-max_len={max_len}',
           f'-mutate_depth={MUTATE_DEPTH}',
           f'-artifact_prefix={artifact_dir}/',
           corpus_dir]
    print(' '.join(shlex.quote(c) for c in cmd))
    subprocess.call(cmd, env=env)
