# Ledger Polkadot App

[![License](https://img.shields.io/badge/License-Apache%202.0-blue.svg)](https://opensource.org/licenses/Apache-2.0)
[![GithubActions](https://github.com/zondax/ledger-polkadot/actions/workflows/main.yml/badge.svg)](https://github.com/Zondax/ledger-polkadot/blob/main/.github/workflows/main.yaml)

---

![zondax_light](docs/zondax_light.png#gh-light-mode-only)
![zondax_dark](docs/zondax_dark.png#gh-dark-mode-only)

_Please visit our website at [zondax.ch](https://www.zondax.ch)_

---

This project contains the Polkadot Generic app (<https://polkadot.network/>) for Ledger devices.

It provides support for both parachains and relay chains. This app aims to deliver a **unified solution for the entire Polkadot ecosystem**, ensuring top security standards.

**All calls from any Polkadot SDK** chain, including nested ones, will be supported. However, while all methods will function in a nested call, the transaction may be rejected if there is insufficient RAM. 
This situation might arise with the Ledger Nano S, which provides limited memory in comparison to the Ledger Nano S+, Nano X, Flex, Stax, and Apex P.

If you were using one of the parachains applications (see the list below), you’ll have to migrate your funds to the Polkadot derivation path. This will enable you to manage your coins directly from the new Polkadot application.

Here is the list of parachains applications:
- Acala
- Ajuna
- Aleph Zero
- Astar
- Bifrost
- Centrifuge
- Darwinia
- Edgeware
- Hydradx
- Karura
- Khala
- Kusama
- Nodle
- Parallel
- Phala
- Pendulum
- Polkadex
- Polymesh
- Statemine
- Statemint
- Unique
- xx network

For testing purposes you can easily install the application via (<https://hub.zondax.ch/polkadot-new>)

This repository contains:

- Ledger (BOLOS) app
- Specs / Documentation
- C++ unit tests
- Zemu tests

For more information:

- [How to build](docs/build.md)
- :warning:[Formatting Limitations](docs/format.md)

## ATTENTION

Please:

- **Do not use in production**
- **Do not use a Ledger device with funds for development purposes.**
- **Have a separate and marked device that is used ONLY for development and testing**
