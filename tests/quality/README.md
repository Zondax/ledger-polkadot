# Relative-price vectors

`relative-price-v478.json` contains direct `swap_stake_limit`, direct
`move_stake_limit`, and a `Utility.batch` of those two calls, with
`limit_price = 950000000` and `alpha_amount = 2000000000`.

The vectors were generated using the unmodified core API at
`eafe84e8a97376e7902118ebb204b9c53e3df55e` and recorded finney V15 metadata at
spec 478. The metadata SHA256 is
`17cdbed812cb59a833cc64d2764d734aee5d08174385868167a1cf284d6ff502`.
The generator uses `Runtime::compose_call`, `signature_payload_parts`,
`metadata_digest`, and `generate_extrinsic_proof`; the native test checks
that the app computes the same digest and renders both price fields as exact
raw integers in normal and expert modes.

These are deterministic parser fixtures, with immortal era, nonce 7, zero tip,
enabled metadata hash, mock account bytes `0x11` repeated 32 times, and mock
genesis/era block hashes `0x22` repeated 32 times. They are not signed
extrinsics or evidence of chain acceptance. The version, token and display
constants are `node-subtensor`, transaction version 1, SS58 prefix 42, 9
decimals, and `TAO`.
