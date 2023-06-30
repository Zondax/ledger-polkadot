# Ledger Polkadot App

[![License](https://img.shields.io/badge/License-Apache%202.0-blue.svg)](https://opensource.org/licenses/Apache-2.0)
[![GithubActions](https://github.com/zondax/ledger-polkadot/actions/workflows/main.yml/badge.svg)](https://github.com/Zondax/ledger-polkadot/blob/main/.github/workflows/main.yaml)

---

![zondax_light](docs/zondax_light.png#gh-light-mode-only)
![zondax_dark](docs/zondax_dark.png#gh-dark-mode-only)

_Please visit our website at [zondax.ch](https://www.zondax.ch)_

---

This project contains the Polkadot app (https://polkadot.network/) for Ledger Nano S and X.

- Ledger Nano S/X BOLOS app
- Specs / Documentation
- C++ unit tests
- Zemu tests

For more information: [How to build](docs/build.md)

## ATTENTION

Please:

- **Do not use in production**
- **Do not use a Ledger device with funds for development purposes.**
- **Have a separate and marked device that is used ONLY for development and testing**
# Polkadot 24.9430.x

## System

| Name                    | Nano S | Nano S XL          | Nano SP/X - Stax   | Nesting            | Arguments                         |
| ----------------------- | ------ | ------------------ | ------------------ | ------------------ | --------------------------------- |
| Remark                  |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Bytes`remark<br/>                |
| Set heap pages          |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `u64`pages<br/>                   |
| Set code                |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Vecu8`code<br/>                  |
| Set code without checks |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Vecu8`code<br/>                  |
| Set storage             |        |                    |                    |                    | `VecKeyValue`items<br/>           |
| Kill storage            |        |                    |                    |                    | `VecKey`keys<br/>                 |
| Kill prefix             |        |                    |                    |                    | `Key`prefix<br/>`u32`subkeys<br/> |
| Remark with event       |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Bytes`remark<br/>                |

## Scheduler

| Name                 | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                                                                                                  |
| -------------------- | ------ | --------- | ---------------- | ------- | ------------------------------------------------------------------------------------------------------------------------------------------ |
| Schedule             |        |           |                  |         | `BlockNumber`when<br/>`OptionschedulePeriodBlockNumber`maybe_periodic<br/>`schedulePriority`priority<br/>`Call`call<br/>                   |
| Cancel               |        |           |                  |         | `BlockNumber`when<br/>`u32`index<br/>                                                                                                      |
| Schedule named       |        |           |                  |         | `TaskName`id<br/>`BlockNumber`when<br/>`OptionschedulePeriodBlockNumber`maybe_periodic<br/>`schedulePriority`priority<br/>`Call`call<br/>  |
| Cancel named         |        |           |                  |         | `TaskName`id<br/>                                                                                                                          |
| Schedule after       |        |           |                  |         | `BlockNumber`after<br/>`OptionschedulePeriodBlockNumber`maybe_periodic<br/>`schedulePriority`priority<br/>`Call`call<br/>                  |
| Schedule named after |        |           |                  |         | `TaskName`id<br/>`BlockNumber`after<br/>`OptionschedulePeriodBlockNumber`maybe_periodic<br/>`schedulePriority`priority<br/>`Call`call<br/> |

## Preimage

| Name               | Nano S | Nano S XL          | Nano SP/X - Stax   | Nesting | Arguments         |
| ------------------ | ------ | ------------------ | ------------------ | ------- | ----------------- |
| Note preimage      |        | :heavy_check_mark: | :heavy_check_mark: |         | `Vecu8`bytes<br/> |
| Unnote preimage    |        | :heavy_check_mark: | :heavy_check_mark: |         | `Hash`hash<br/>   |
| Request preimage   |        | :heavy_check_mark: | :heavy_check_mark: |         | `Hash`hash<br/>   |
| Unrequest preimage |        | :heavy_check_mark: | :heavy_check_mark: |         | `Hash`hash<br/>   |

## Babe

| Name                         | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                                              |
| ---------------------------- | ------ | --------- | ---------------- | ------- | -------------------------------------------------------------------------------------- |
| Report equivocation          |        |           |                  |         | `BoxEquivocationProofHeader`equivocation_proof<br/>`KeyOwnerProof`key_owner_proof<br/> |
| Report equivocation unsigned |        |           |                  |         | `BoxEquivocationProofHeader`equivocation_proof<br/>`KeyOwnerProof`key_owner_proof<br/> |
| Plan config change           |        |           |                  |         | `NextConfigDescriptor`config<br/>                                                      |

## Timestamp

| Name | Nano S | Nano S XL          | Nano SP/X - Stax   | Nesting | Arguments            |
| ---- | ------ | ------------------ | ------------------ | ------- | -------------------- |
| Set  |        | :heavy_check_mark: | :heavy_check_mark: |         | `Compactu64`now<br/> |

## Indices

| Name           | Nano S | Nano S XL          | Nano SP/X - Stax   | Nesting | Arguments                                                               |
| -------------- | ------ | ------------------ | ------------------ | ------- | ----------------------------------------------------------------------- |
| Claim          |        | :heavy_check_mark: | :heavy_check_mark: |         | `AccountIndex`index<br/>                                                |
| Transfer       |        | :heavy_check_mark: | :heavy_check_mark: |         | `AccountIdLookupOfT`new\_<br/>`AccountIndex`index<br/>                  |
| Free           |        | :heavy_check_mark: | :heavy_check_mark: |         | `AccountIndex`index<br/>                                                |
| Force transfer |        | :heavy_check_mark: | :heavy_check_mark: |         | `AccountIdLookupOfT`new\_<br/>`AccountIndex`index<br/>`bool`freeze<br/> |
| Freeze         |        | :heavy_check_mark: | :heavy_check_mark: |         | `AccountIndex`index<br/>                                                |

## Balances

| Name                   | Nano S             | Nano S XL          | Nano SP/X - Stax   | Nesting            | Arguments                                                                                  |
| ---------------------- | ------------------ | ------------------ | ------------------ | ------------------ | ------------------------------------------------------------------------------------------ |
| Transfer allow death   | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT`dest<br/>`CompactBalance`amount<br/>                                   |
| Set balance deprecated |                    | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT`who<br/>`CompactBalance`new_free<br/>`CompactBalance`old_reserved<br/> |
| Force transfer         | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT`source<br/>`AccountIdLookupOfT`dest<br/>`CompactBalance`amount<br/>    |
| Transfer keep alive    | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT`dest<br/>`CompactBalance`amount<br/>                                   |
| Transfer all           | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |                    | `AccountIdLookupOfT`dest<br/>`bool`keep_alive<br/>                                         |
| Force unreserve        |                    | :heavy_check_mark: | :heavy_check_mark: |                    | `AccountIdLookupOfT`who<br/>`Balance`amount<br/>                                           |
| Upgrade accounts       |                    | :heavy_check_mark: | :heavy_check_mark: |                    | `VecAccountId`who<br/>                                                                     |
| Transfer               | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT`dest<br/>`CompactBalance`amount<br/>                                   |
| Force set balance      |                    | :heavy_check_mark: | :heavy_check_mark: |                    | `AccountIdLookupOfT`who<br/>`CompactBalance`new_free<br/>                                  |

## Staking

| Name                       | Nano S             | Nano S XL          | Nano SP/X - Stax   | Nesting            | Arguments                                                                                                                                                                                                                                 |
| -------------------------- | ------------------ | ------------------ | ------------------ | ------------------ | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Bond                       | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `CompactBalance`amount<br/>`RewardDestination`payee<br/>                                                                                                                                                                                  |
| Bond extra                 | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `CompactBalance`amount<br/>                                                                                                                                                                                                               |
| Unbond                     | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `CompactBalance`amount<br/>                                                                                                                                                                                                               |
| Withdraw Unbonded          | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `u32`num_slashing_spans<br/>                                                                                                                                                                                                              |
| Validate                   | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |                    | `ValidatorPrefs`prefs<br/>                                                                                                                                                                                                                |
| Nominate                   | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `VecAccountIdLookupOfT`targets<br/>                                                                                                                                                                                                       |
| Chill                      | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |                                                                                                                                                                                                                                           |
| Set payee                  | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `RewardDestination`payee<br/>                                                                                                                                                                                                             |
| Set controller             | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |                                                                                                                                                                                                                                           |
| Set validator count        |                    | :heavy_check_mark: | :heavy_check_mark: |                    | `Compactu32`new\_<br/>                                                                                                                                                                                                                    |
| Increase validator count   |                    | :heavy_check_mark: | :heavy_check_mark: |                    | `Compactu32`additional<br/>                                                                                                                                                                                                               |
| Scale validator count      |                    | :heavy_check_mark: | :heavy_check_mark: |                    | `Percent`factor<br/>                                                                                                                                                                                                                      |
| Force no eras              |                    | :heavy_check_mark: | :heavy_check_mark: |                    |                                                                                                                                                                                                                                           |
| Force new era              |                    | :heavy_check_mark: | :heavy_check_mark: |                    |                                                                                                                                                                                                                                           |
| Set invulnerables          |                    | :heavy_check_mark: | :heavy_check_mark: |                    | `VecAccountId`invulnerables<br/>                                                                                                                                                                                                          |
| Force unstake              |                    | :heavy_check_mark: | :heavy_check_mark: |                    | `AccountId`stash<br/>`u32`num_slashing_spans<br/>                                                                                                                                                                                         |
| Force new era always       |                    | :heavy_check_mark: | :heavy_check_mark: |                    |                                                                                                                                                                                                                                           |
| Cancel deferred slash      |                    | :heavy_check_mark: | :heavy_check_mark: |                    | `EraIndex`era<br/>`Vecu32`slash_indices<br/>                                                                                                                                                                                              |
| Payout stakers             | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |                    | `AccountId`validator_stash<br/>`EraIndex`era<br/>                                                                                                                                                                                         |
| Rebond                     | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `CompactBalance`amount<br/>                                                                                                                                                                                                               |
| Reap stash                 |                    | :heavy_check_mark: | :heavy_check_mark: |                    | `AccountId`stash<br/>`u32`num_slashing_spans<br/>                                                                                                                                                                                         |
| Kick                       |                    | :heavy_check_mark: | :heavy_check_mark: |                    | `VecAccountIdLookupOfT`who<br/>                                                                                                                                                                                                           |
| Set staking configs        |                    | :heavy_check_mark: | :heavy_check_mark: |                    | `ConfigOpBalanceOfT`min_nominator_bond<br/>`ConfigOpBalanceOfT`min_validator_bond<br/>`ConfigOpu32`max_nominator_count<br/>`ConfigOpu32`max_validator_count<br/>`ConfigOpPercent`chill_threshold<br/>`ConfigOpPerbill`min_commission<br/> |
| Chill other                |                    | :heavy_check_mark: | :heavy_check_mark: |                    | `AccountId`controller<br/>                                                                                                                                                                                                                |
| Force apply min commission |                    | :heavy_check_mark: | :heavy_check_mark: |                    | `AccountId`validator_stash<br/>                                                                                                                                                                                                           |
| Set min commission         |                    | :heavy_check_mark: | :heavy_check_mark: |                    | `Perbill`new\_<br/>                                                                                                                                                                                                                       |

## Session

| Name       | Nano S             | Nano S XL          | Nano SP/X - Stax   | Nesting | Arguments                        |
| ---------- | ------------------ | ------------------ | ------------------ | ------- | -------------------------------- |
| Set keys   | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `Keys`keys<br/>`Bytes`proof<br/> |
| Purge keys | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         |                                  |

## Grandpa

| Name                         | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                                                       |
| ---------------------------- | ------ | --------- | ---------------- | ------- | ----------------------------------------------------------------------------------------------- |
| Report equivocation          |        |           |                  |         | `BoxEquivocationProofHashBlockNumber`equivocation_proof<br/>`KeyOwnerProof`key_owner_proof<br/> |
| Report equivocation unsigned |        |           |                  |         | `BoxEquivocationProofHashBlockNumber`equivocation_proof<br/>`KeyOwnerProof`key_owner_proof<br/> |
| Note stalled                 |        |           |                  |         | `BlockNumber`delay<br/>`BlockNumber`best_finalized_block_number<br/>                            |

## ImOnline

| Name      | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                                                  |
| --------- | ------ | --------- | ---------------- | ------- | ------------------------------------------------------------------------------------------ |
| Heartbeat |        |           |                  |         | `HeartbeatBlockNumber`heartbeat<br/>`AuthorityIdasRuntimeAppPublicSignature`signature<br/> |

## Democracy

| Name                      | Nano S | Nano S XL          | Nano SP/X - Stax   | Nesting            | Arguments                                                                      |
| ------------------------- | ------ | ------------------ | ------------------ | ------------------ | ------------------------------------------------------------------------------ |
| Propose                   |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `BoundedCallOfT`proposal<br/>`CompactBalance`amount<br/>                       |
| Second                    |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Compactu32`proposal<br/>                                                      |
| Vote                      |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Compactu32`ref_index<br/>`AccountVote`vote<br/>                               |
| Emergency cancel          |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `ReferendumIndex`ref_index<br/>                                                |
| External propose          |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `BoundedCallOfT`proposal<br/>                                                  |
| External propose majority |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `BoundedCallOfT`proposal<br/>                                                  |
| External propose default  |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `BoundedCallOfT`proposal<br/>                                                  |
| Fast track                |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `H256`proposal_hash<br/>`BlockNumber`voting_period<br/>`BlockNumber`delay<br/> |
| Veto external             |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `H256`proposal_hash<br/>                                                       |
| Cancel referendum         |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Compactu32`ref_index<br/>                                                     |
| Delegate                  |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT`to<br/>`Conviction`conviction<br/>`Balance`balance<br/>    |
| Undelegate                |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |                                                                                |
| Clear public proposals    |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |                                                                                |
| Unlock                    |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT`target<br/>                                                |
| Remove vote               |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `ReferendumIndex`index<br/>                                                    |
| Remove other vote         |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT`target<br/>`ReferendumIndex`index<br/>                     |
| Blacklist                 |        | :heavy_check_mark: | :heavy_check_mark: |                    | `H256`proposal_hash<br/>`OptionReferendumIndex`maybe_ref_index<br/>            |
| Cancel proposal           |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Compactu32`prop_index<br/>                                                    |
| Set metadata              |        | :heavy_check_mark: | :heavy_check_mark: |                    | `MetadataOwner`owner<br/>`OptionPreimageHash`maybe_hash<br/>                   |

## Council

| Name                | Nano S | Nano S XL          | Nano SP/X - Stax   | Nesting | Arguments                                                                                                     |
| ------------------- | ------ | ------------------ | ------------------ | ------- | ------------------------------------------------------------------------------------------------------------- |
| Set members         |        | :heavy_check_mark: | :heavy_check_mark: |         | `VecAccountId`new_members<br/>`OptionAccountId`prime<br/>`MemberCount`old_count<br/>                          |
| Execute             |        | :heavy_check_mark: | :heavy_check_mark: |         | `Proposal`proposal<br/>`Compactu32`length_bound<br/>                                                          |
| Propose             |        | :heavy_check_mark: | :heavy_check_mark: |         | `Compactu32`threshold<br/>`Proposal`proposal<br/>`Compactu32`length_bound<br/>                                |
| Vote                |        | :heavy_check_mark: | :heavy_check_mark: |         | `Hash`proposal<br/>`Compactu32`index<br/>`bool`approve<br/>                                                   |
| Disapprove proposal |        | :heavy_check_mark: | :heavy_check_mark: |         | `Hash`proposal_hash<br/>                                                                                      |
| Close               |        | :heavy_check_mark: | :heavy_check_mark: |         | `Hash`proposal_hash<br/>`Compactu32`index<br/>`Weight`proposal_weight_bound<br/>`Compactu32`length_bound<br/> |

## TechnicalCommittee

| Name                | Nano S | Nano S XL          | Nano SP/X - Stax   | Nesting | Arguments                                                                                                     |
| ------------------- | ------ | ------------------ | ------------------ | ------- | ------------------------------------------------------------------------------------------------------------- |
| Set members         |        | :heavy_check_mark: | :heavy_check_mark: |         | `VecAccountId`new_members<br/>`OptionAccountId`prime<br/>`MemberCount`old_count<br/>                          |
| Execute             |        | :heavy_check_mark: | :heavy_check_mark: |         | `Proposal`proposal<br/>`Compactu32`length_bound<br/>                                                          |
| Propose             |        | :heavy_check_mark: | :heavy_check_mark: |         | `Compactu32`threshold<br/>`Proposal`proposal<br/>`Compactu32`length_bound<br/>                                |
| Vote                |        | :heavy_check_mark: | :heavy_check_mark: |         | `Hash`proposal<br/>`Compactu32`index<br/>`bool`approve<br/>                                                   |
| Disapprove proposal |        | :heavy_check_mark: | :heavy_check_mark: |         | `Hash`proposal_hash<br/>                                                                                      |
| Close               |        | :heavy_check_mark: | :heavy_check_mark: |         | `Hash`proposal_hash<br/>`Compactu32`index<br/>`Weight`proposal_weight_bound<br/>`Compactu32`length_bound<br/> |

## PhragmenElection

| Name                 | Nano S | Nano S XL          | Nano SP/X - Stax   | Nesting | Arguments                                                                  |
| -------------------- | ------ | ------------------ | ------------------ | ------- | -------------------------------------------------------------------------- |
| Vote                 |        | :heavy_check_mark: | :heavy_check_mark: |         | `VecAccountId`votes<br/>`CompactBalance`amount<br/>                        |
| Remove voter         |        | :heavy_check_mark: | :heavy_check_mark: |         |                                                                            |
| Submit candidacy     |        | :heavy_check_mark: | :heavy_check_mark: |         | `Compactu32`candidate_count<br/>                                           |
| Renounce candidacy   |        |                    |                    |         | `Renouncing`renouncing<br/>                                                |
| Remove member        |        | :heavy_check_mark: | :heavy_check_mark: |         | `AccountIdLookupOfT`who<br/>`bool`slash_bond<br/>`bool`rerun_election<br/> |
| Clean defunct voters |        | :heavy_check_mark: | :heavy_check_mark: |         | `u32`num_voters<br/>`u32`num_defunct<br/>                                  |

## TechnicalMembership

| Name          | Nano S | Nano S XL          | Nano SP/X - Stax   | Nesting | Arguments                                                   |
| ------------- | ------ | ------------------ | ------------------ | ------- | ----------------------------------------------------------- |
| Add member    |        | :heavy_check_mark: | :heavy_check_mark: |         | `AccountIdLookupOfT`who<br/>                                |
| Remove member |        | :heavy_check_mark: | :heavy_check_mark: |         | `AccountIdLookupOfT`who<br/>                                |
| Swap member   |        | :heavy_check_mark: | :heavy_check_mark: |         | `AccountIdLookupOfT`remove<br/>`AccountIdLookupOfT`add<br/> |
| Reset members |        | :heavy_check_mark: | :heavy_check_mark: |         | `VecAccountId`members<br/>                                  |
| Change key    |        | :heavy_check_mark: | :heavy_check_mark: |         | `AccountIdLookupOfT`new\_<br/>                              |
| Set prime     |        | :heavy_check_mark: | :heavy_check_mark: |         | `AccountIdLookupOfT`who<br/>                                |
| Clear prime   |        | :heavy_check_mark: | :heavy_check_mark: |         |                                                             |

## Treasury

| Name             | Nano S | Nano S XL          | Nano SP/X - Stax   | Nesting | Arguments                                                       |
| ---------------- | ------ | ------------------ | ------------------ | ------- | --------------------------------------------------------------- |
| Propose spend    |        | :heavy_check_mark: | :heavy_check_mark: |         | `CompactBalance`amount<br/>`AccountIdLookupOfT`beneficiary<br/> |
| Reject proposal  |        | :heavy_check_mark: | :heavy_check_mark: |         | `Compactu32`proposal_id<br/>                                    |
| Approve proposal |        | :heavy_check_mark: | :heavy_check_mark: |         | `Compactu32`proposal_id<br/>                                    |
| Spend            |        | :heavy_check_mark: | :heavy_check_mark: |         | `CompactBalance`amount<br/>`AccountIdLookupOfT`beneficiary<br/> |
| Remove approval  |        | :heavy_check_mark: | :heavy_check_mark: |         | `Compactu32`proposal_id<br/>                                    |

## ConvictionVoting

| Name              | Nano S | Nano S XL          | Nano SP/X - Stax   | Nesting            | Arguments                                                                                          |
| ----------------- | ------ | ------------------ | ------------------ | ------------------ | -------------------------------------------------------------------------------------------------- |
| Vote              |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Compactu32`poll_index<br/>`AccountVote`vote<br/>                                                  |
| Delegate          |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `ClassOf`class\_<br/>`AccountIdLookupOfT`to<br/>`Conviction`conviction<br/>`BalanceOf`balance<br/> |
| Undelegate        |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `ClassOf`class\_<br/>                                                                              |
| Unlock            |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `ClassOf`class\_<br/>`AccountIdLookupOfT`target<br/>                                               |
| Remove vote       |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `OptionClassOf`class\_<br/>`PollIndexOf`index<br/>                                                 |
| Remove other vote |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT`target<br/>`ClassOf`class\_<br/>`PollIndexOf`index<br/>                        |

## Referenda

| Name                      | Nano S | Nano S XL          | Nano SP/X - Stax   | Nesting | Arguments                                                                                                            |
| ------------------------- | ------ | ------------------ | ------------------ | ------- | -------------------------------------------------------------------------------------------------------------------- |
| Submit                    |        | :heavy_check_mark: | :heavy_check_mark: |         | `BoxPalletsOriginOfT`proposal_origin<br/>`BoundedCallOfT`proposal<br/>`DispatchTimeBlockNumber`enactment_moment<br/> |
| Place decision deposit    |        | :heavy_check_mark: | :heavy_check_mark: |         | `ReferendumIndex`index<br/>                                                                                          |
| Refund decision deposit   |        | :heavy_check_mark: | :heavy_check_mark: |         | `ReferendumIndex`index<br/>                                                                                          |
| Cancel                    |        | :heavy_check_mark: | :heavy_check_mark: |         | `ReferendumIndex`index<br/>                                                                                          |
| Kill                      |        | :heavy_check_mark: | :heavy_check_mark: |         | `ReferendumIndex`index<br/>                                                                                          |
| Nudge referendum          |        | :heavy_check_mark: | :heavy_check_mark: |         | `ReferendumIndex`index<br/>                                                                                          |
| One fewer deciding        |        | :heavy_check_mark: | :heavy_check_mark: |         | `TrackIdOf`track<br/>                                                                                                |
| Refund submission deposit |        | :heavy_check_mark: | :heavy_check_mark: |         | `ReferendumIndex`index<br/>                                                                                          |
| Set metadata              |        | :heavy_check_mark: | :heavy_check_mark: |         | `ReferendumIndex`index<br/>`OptionPreimageHash`maybe_hash<br/>                                                       |

## Whitelist

| Name                                    | Nano S | Nano S XL          | Nano SP/X - Stax   | Nesting | Arguments                                                                              |
| --------------------------------------- | ------ | ------------------ | ------------------ | ------- | -------------------------------------------------------------------------------------- |
| Whitelist call                          |        | :heavy_check_mark: | :heavy_check_mark: |         | `PreimageHash`call_hash<br/>                                                           |
| Remove whitelisted call                 |        | :heavy_check_mark: | :heavy_check_mark: |         | `PreimageHash`call_hash<br/>                                                           |
| Dispatch whitelisted call               |        | :heavy_check_mark: | :heavy_check_mark: |         | `PreimageHash`call_hash<br/>`u32`call_encoded_len<br/>`Weight`call_weight_witness<br/> |
| Dispatch whitelisted call with preimage |        | :heavy_check_mark: | :heavy_check_mark: |         | `Call`call<br/>                                                                        |

## Claims

| Name         | Nano S | Nano S XL          | Nano SP/X - Stax   | Nesting | Arguments                                                                                                                                         |
| ------------ | ------ | ------------------ | ------------------ | ------- | ------------------------------------------------------------------------------------------------------------------------------------------------- |
| Claim        |        | :heavy_check_mark: | :heavy_check_mark: |         | `AccountId`dest<br/>`EcdsaSignature`ethereum_signature<br/>                                                                                       |
| Mint claim   |        |                    |                    |         | `EthereumAddress`who<br/>`Balance`amount<br/>`OptionTupleBalanceOfTBalanceOfTBlockNumber`vesting_schedule<br/>`OptionStatementKind`statement<br/> |
| Claim attest |        | :heavy_check_mark: | :heavy_check_mark: |         | `AccountId`dest<br/>`EcdsaSignature`ethereum_signature<br/>`Bytes`statement<br/>                                                                  |
| Attest       |        | :heavy_check_mark: | :heavy_check_mark: |         | `Bytes`statement<br/>                                                                                                                             |
| Move claim   |        | :heavy_check_mark: | :heavy_check_mark: |         | `EthereumAddress`old<br/>`EthereumAddress`new\_<br/>`OptionAccountId`maybe_preclaim<br/>                                                          |

## Vesting

| Name                  | Nano S | Nano S XL          | Nano SP/X - Stax   | Nesting | Arguments                                                                                |
| --------------------- | ------ | ------------------ | ------------------ | ------- | ---------------------------------------------------------------------------------------- |
| Vest                  |        | :heavy_check_mark: | :heavy_check_mark: |         |                                                                                          |
| Vest other            |        | :heavy_check_mark: | :heavy_check_mark: |         | `AccountIdLookupOfT`target<br/>                                                          |
| Vested transfer       |        | :heavy_check_mark: | :heavy_check_mark: |         | `AccountIdLookupOfT`target<br/>`VestingInfo`schedule<br/>                                |
| Force vested transfer |        | :heavy_check_mark: | :heavy_check_mark: |         | `AccountIdLookupOfT`source<br/>`AccountIdLookupOfT`target<br/>`VestingInfo`schedule<br/> |
| Merge schedules       |        | :heavy_check_mark: | :heavy_check_mark: |         | `u32`schedule1_index<br/>`u32`schedule2_index<br/>                                       |

## Utility

| Name          | Nano S             | Nano S XL          | Nano SP/X - Stax   | Nesting | Arguments                                       |
| ------------- | ------------------ | ------------------ | ------------------ | ------- | ----------------------------------------------- |
| Batch         | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `VecCall`calls<br/>                             |
| As derivative |                    |                    |                    |         | `u16`index<br/>`Call`call<br/>                  |
| Batch all     | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `VecCall`calls<br/>                             |
| Dispatch as   |                    |                    |                    |         | `BoxPalletsOrigin`as_origin<br/>`Call`call<br/> |
| Force batch   | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `VecCall`calls<br/>                             |
| With weight   |                    | :heavy_check_mark: | :heavy_check_mark: |         | `Call`call<br/>`Weight`weight<br/>              |

## Identity

| Name              | Nano S | Nano S XL          | Nano SP/X - Stax   | Nesting | Arguments                                                                                                       |
| ----------------- | ------ | ------------------ | ------------------ | ------- | --------------------------------------------------------------------------------------------------------------- |
| Add registrar     |        | :heavy_check_mark: | :heavy_check_mark: |         | `AccountIdLookupOfT`account<br/>                                                                                |
| Set identity      |        | :heavy_check_mark: | :heavy_check_mark: |         | `IdentityInfo`info<br/>                                                                                         |
| Set subs          |        | :heavy_check_mark: | :heavy_check_mark: |         | `VecTupleAccountIdData`subs<br/>                                                                                |
| Clear identity    |        | :heavy_check_mark: | :heavy_check_mark: |         |                                                                                                                 |
| Request judgement |        | :heavy_check_mark: | :heavy_check_mark: |         | `Compactu32`reg_index<br/>`Compactu128`max_fee<br/>                                                             |
| Cancel request    |        | :heavy_check_mark: | :heavy_check_mark: |         | `RegistrarIndex`reg_index<br/>                                                                                  |
| Set fee           |        | :heavy_check_mark: | :heavy_check_mark: |         | `Compactu32`index<br/>`Compactu128`fee<br/>                                                                     |
| Set account id    |        | :heavy_check_mark: | :heavy_check_mark: |         | `Compactu32`index<br/>`AccountIdLookupOfT`new\_<br/>                                                            |
| Set fields        |        |                    |                    |         | `Compactu32`index<br/>`IdentityFields`fields<br/>                                                               |
| Provide judgement |        | :heavy_check_mark: | :heavy_check_mark: |         | `Compactu32`reg_index<br/>`AccountIdLookupOfT`target<br/>`JudgementBalanceOfT`judgement<br/>`Hash`identity<br/> |
| Kill identity     |        | :heavy_check_mark: | :heavy_check_mark: |         | `AccountIdLookupOfT`target<br/>                                                                                 |
| Add sub           |        | :heavy_check_mark: | :heavy_check_mark: |         | `AccountIdLookupOfT`sub<br/>`Data`data<br/>                                                                     |
| Rename sub        |        | :heavy_check_mark: | :heavy_check_mark: |         | `AccountIdLookupOfT`sub<br/>`Data`data<br/>                                                                     |
| Remove sub        |        | :heavy_check_mark: | :heavy_check_mark: |         | `AccountIdLookupOfT`sub<br/>                                                                                    |
| Quit sub          |        | :heavy_check_mark: | :heavy_check_mark: |         |                                                                                                                 |

## Proxy

| Name                | Nano S | Nano S XL          | Nano SP/X - Stax   | Nesting            | Arguments                                                                                                                  |
| ------------------- | ------ | ------------------ | ------------------ | ------------------ | -------------------------------------------------------------------------------------------------------------------------- |
| Proxy               |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT`real<br/>`OptionProxyType`force_proxy_type<br/>`Call`call<br/>                                         |
| Add proxy           |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT`delegate<br/>`ProxyType`proxy_type<br/>`BlockNumber`delay<br/>                                         |
| Remove proxy        |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT`delegate<br/>`ProxyType`proxy_type<br/>`BlockNumber`delay<br/>                                         |
| Remove proxies      |        | :heavy_check_mark: | :heavy_check_mark: |                    |                                                                                                                            |
| Create pure         |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `ProxyType`proxy_type<br/>`BlockNumber`delay<br/>`u16`index<br/>                                                           |
| Kill pure           |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT`spawner<br/>`ProxyType`proxy_type<br/>`u16`index<br/>`Compactu32`height<br/>`Compactu32`ext_index<br/> |
| Announce            |        |                    |                    |                    | `AccountIdLookupOfT`real<br/>`CallHashOf`call_hash<br/>                                                                    |
| Remove announcement |        |                    |                    |                    | `AccountIdLookupOfT`real<br/>`CallHashOf`call_hash<br/>                                                                    |
| Reject announcement |        |                    |                    |                    | `AccountIdLookupOfT`delegate<br/>`CallHashOf`call_hash<br/>                                                                |
| Proxy announced     |        | :heavy_check_mark: | :heavy_check_mark: |                    | `AccountIdLookupOfT`delegate<br/>`AccountIdLookupOfT`real<br/>`OptionProxyType`force_proxy_type<br/>`Call`call<br/>        |

## Multisig

| Name                 | Nano S | Nano S XL          | Nano SP/X - Stax   | Nesting            | Arguments                                                                                                                               |
| -------------------- | ------ | ------------------ | ------------------ | ------------------ | --------------------------------------------------------------------------------------------------------------------------------------- |
| As multi threshold 1 |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `VecAccountId`other_signatories<br/>`Call`call<br/>                                                                                     |
| As multi             |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `u16`threshold<br/>`VecAccountId`other_signatories<br/>`OptionTimepoint`maybe_timepoint<br/>`Call`call<br/>`Weight`max_weight<br/>      |
| Approve as multi     |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `u16`threshold<br/>`VecAccountId`other_signatories<br/>`OptionTimepoint`maybe_timepoint<br/>`H256`call_hash<br/>`Weight`max_weight<br/> |
| Cancel as multi      |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `u16`threshold<br/>`VecAccountId`other_signatories<br/>`Timepoint`timepoint<br/>`H256`call_hash<br/>                                    |

## Bounties

| Name                 | Nano S | Nano S XL          | Nano SP/X - Stax   | Nesting | Arguments                                                                          |
| -------------------- | ------ | ------------------ | ------------------ | ------- | ---------------------------------------------------------------------------------- |
| Propose bounty       |        | :heavy_check_mark: | :heavy_check_mark: |         | `CompactBalance`amount<br/>`Bytes`description<br/>                                 |
| Approve bounty       |        | :heavy_check_mark: | :heavy_check_mark: |         | `Compactu32`bounty_id<br/>                                                         |
| Propose curator      |        | :heavy_check_mark: | :heavy_check_mark: |         | `Compactu32`bounty_id<br/>`AccountIdLookupOfT`curator<br/>`CompactBalance`fee<br/> |
| Unassign curator     |        | :heavy_check_mark: | :heavy_check_mark: |         | `Compactu32`bounty_id<br/>                                                         |
| Accept curator       |        | :heavy_check_mark: | :heavy_check_mark: |         | `Compactu32`bounty_id<br/>                                                         |
| Award bounty         |        | :heavy_check_mark: | :heavy_check_mark: |         | `Compactu32`bounty_id<br/>`AccountIdLookupOfT`beneficiary<br/>                     |
| Claim bounty         |        | :heavy_check_mark: | :heavy_check_mark: |         | `Compactu32`bounty_id<br/>                                                         |
| Close bounty         |        | :heavy_check_mark: | :heavy_check_mark: |         | `Compactu32`bounty_id<br/>                                                         |
| Extend bounty expiry |        | :heavy_check_mark: | :heavy_check_mark: |         | `Compactu32`bounty_id<br/>`Bytes`remark<br/>                                       |

## ChildBounties

| Name               | Nano S | Nano S XL          | Nano SP/X - Stax   | Nesting | Arguments                                                                                                                 |
| ------------------ | ------ | ------------------ | ------------------ | ------- | ------------------------------------------------------------------------------------------------------------------------- |
| Add child bounty   |        | :heavy_check_mark: | :heavy_check_mark: |         | `Compactu32`parent_bounty_id<br/>`CompactBalance`amount<br/>`Vecu8`description<br/>                                       |
| Propose curator    |        | :heavy_check_mark: | :heavy_check_mark: |         | `Compactu32`parent_bounty_id<br/>`Compactu32`child_bounty_id<br/>`AccountIdLookupOfT`curator<br/>`CompactBalance`fee<br/> |
| Accept curator     |        | :heavy_check_mark: | :heavy_check_mark: |         | `Compactu32`parent_bounty_id<br/>`Compactu32`child_bounty_id<br/>                                                         |
| Unassign curator   |        | :heavy_check_mark: | :heavy_check_mark: |         | `Compactu32`parent_bounty_id<br/>`Compactu32`child_bounty_id<br/>                                                         |
| Award child bounty |        | :heavy_check_mark: | :heavy_check_mark: |         | `Compactu32`parent_bounty_id<br/>`Compactu32`child_bounty_id<br/>`AccountIdLookupOfT`beneficiary<br/>                     |
| Claim child bounty |        | :heavy_check_mark: | :heavy_check_mark: |         | `Compactu32`parent_bounty_id<br/>`Compactu32`child_bounty_id<br/>                                                         |
| Close child bounty |        | :heavy_check_mark: | :heavy_check_mark: |         | `Compactu32`parent_bounty_id<br/>`Compactu32`child_bounty_id<br/>                                                         |

## Tips

| Name           | Nano S | Nano S XL          | Nano SP/X - Stax   | Nesting | Arguments                                                                 |
| -------------- | ------ | ------------------ | ------------------ | ------- | ------------------------------------------------------------------------- |
| Report awesome |        | :heavy_check_mark: | :heavy_check_mark: |         | `Bytes`reason<br/>`AccountIdLookupOfT`who<br/>                            |
| Retract tip    |        | :heavy_check_mark: | :heavy_check_mark: |         | `Hash`hash<br/>                                                           |
| Tip new        |        | :heavy_check_mark: | :heavy_check_mark: |         | `Bytes`reason<br/>`AccountIdLookupOfT`who<br/>`Compactu128`tip_value<br/> |
| Tip            |        | :heavy_check_mark: | :heavy_check_mark: |         | `Hash`hash<br/>`Compactu128`tip_value<br/>                                |
| Close tip      |        | :heavy_check_mark: | :heavy_check_mark: |         | `Hash`hash<br/>                                                           |
| Slash tip      |        | :heavy_check_mark: | :heavy_check_mark: |         | `Hash`hash<br/>                                                           |

## ElectionProviderMultiPhase

| Name                          | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                                                  |
| ----------------------------- | ------ | --------- | ---------------- | ------- | ------------------------------------------------------------------------------------------ |
| Submit unsigned               |        |           |                  |         | `BoxRawSolutionSolutionOfMinerConfig`raw_solution<br/>`SolutionOrSnapshotSize`witness<br/> |
| Set minimum untrusted score   |        |           |                  |         | `OptionElectionScore`maybe_next_score<br/>                                                 |
| Set emergency election result |        |           |                  |         | `SupportsAccountId`supports<br/>                                                           |
| Submit                        |        |           |                  |         | `BoxRawSolutionSolutionOfMinerConfig`raw_solution<br/>                                     |
| Governance fallback           |        |           |                  |         | `Optionu32`maybe_max_voters<br/>`Optionu32`maybe_max_targets<br/>                          |

## VoterList

| Name            | Nano S | Nano S XL          | Nano SP/X - Stax   | Nesting | Arguments                           |
| --------------- | ------ | ------------------ | ------------------ | ------- | ----------------------------------- |
| Rebag           |        | :heavy_check_mark: | :heavy_check_mark: |         | `AccountIdLookupOfT`dislocated<br/> |
| Put in front of |        | :heavy_check_mark: | :heavy_check_mark: |         | `AccountIdLookupOfT`lighter<br/>    |

## NominationPools

| Name                       | Nano S | Nano S XL          | Nano SP/X - Stax   | Nesting            | Arguments                                                                                                                                                                                                               |
| -------------------------- | ------ | ------------------ | ------------------ | ------------------ | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Join                       |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `CompactBalance`amount<br/>`PoolId`pool_id<br/>                                                                                                                                                                         |
| Bond extra                 |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `BondExtraBalanceOfT`extra<br/>                                                                                                                                                                                         |
| Claim payout               |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |                                                                                                                                                                                                                         |
| Unbond                     |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT`member_account<br/>`CompactBalance`unbonding_points<br/>                                                                                                                                            |
| Pool withdraw unbonded     |        | :heavy_check_mark: | :heavy_check_mark: |                    | `PoolId`pool_id<br/>`u32`num_slashing_spans<br/>                                                                                                                                                                        |
| Withdraw Unbonded          |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT`member_account<br/>`u32`num_slashing_spans<br/>                                                                                                                                                     |
| Create                     |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `CompactBalance`amount<br/>`AccountIdLookupOfT`root<br/>`AccountIdLookupOfT`nominator<br/>`AccountIdLookupOfT`bouncer<br/>                                                                                              |
| Create with pool id        |        | :heavy_check_mark: | :heavy_check_mark: |                    | `CompactBalance`amount<br/>`AccountIdLookupOfT`root<br/>`AccountIdLookupOfT`nominator<br/>`AccountIdLookupOfT`bouncer<br/>`PoolId`pool_id<br/>                                                                          |
| Nominate                   |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `PoolId`pool_id<br/>`VecAccountId`validators<br/>                                                                                                                                                                       |
| Set state                  |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `PoolId`pool_id<br/>`PoolState`state<br/>                                                                                                                                                                               |
| Set metadata               |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `PoolId`pool_id<br/>`Vecu8`metadata<br/>                                                                                                                                                                                |
| Set configs                |        | :heavy_check_mark: | :heavy_check_mark: |                    | `ConfigOpBalanceOfT`min_join_bond<br/>`ConfigOpBalanceOfT`min_create_bond<br/>`ConfigOpu32`max_pools<br/>`ConfigOpu32`max_members<br/>`ConfigOpu32`max_members_per_pool<br/>`ConfigOpPerbill`global_max_commission<br/> |
| Update roles               |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `PoolId`pool_id<br/>`ConfigOpAccountId`new_root<br/>`ConfigOpAccountId`new_nominator<br/>`ConfigOpAccountId`new_bouncer<br/>                                                                                            |
| Chill                      |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `PoolId`pool_id<br/>                                                                                                                                                                                                    |
| Bond extra other           |        | :heavy_check_mark: | :heavy_check_mark: |                    | `AccountIdLookupOfT`member<br/>`BondExtraBalanceOfT`extra<br/>                                                                                                                                                          |
| Set claim permission       |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `ClaimPermission`permission<br/>                                                                                                                                                                                        |
| Claim payout other         |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountId`other<br/>                                                                                                                                                                                                   |
| Set commission             |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `PoolId`pool_id<br/>`OptionTuplePerbillAccountId`new_commission<br/>                                                                                                                                                    |
| Set commission max         |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `PoolId`pool_id<br/>`Perbill`max_commission<br/>                                                                                                                                                                        |
| Set commission change rate |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `PoolId`pool_id<br/>`CommissionChangeRateBlockNumber`change_rate<br/>                                                                                                                                                   |
| Claim commission           |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `PoolId`pool_id<br/>                                                                                                                                                                                                    |

## FastUnstake

| Name                  | Nano S | Nano S XL          | Nano SP/X - Stax   | Nesting            | Arguments                    |
| --------------------- | ------ | ------------------ | ------------------ | ------------------ | ---------------------------- |
| Register fast unstake |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |                              |
| Deregister            |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |                              |
| Control               |        | :heavy_check_mark: | :heavy_check_mark: |                    | `EraIndex`eras_to_check<br/> |

## Configuration

| Name                                          | Nano S | Nano S XL          | Nano SP/X - Stax   | Nesting | Arguments                      |
| --------------------------------------------- | ------ | ------------------ | ------------------ | ------- | ------------------------------ |
| Set validation upgrade cooldown               |        | :heavy_check_mark: | :heavy_check_mark: |         | `BlockNumber`new\_<br/>        |
| Set validation upgrade delay                  |        | :heavy_check_mark: | :heavy_check_mark: |         | `BlockNumber`new\_<br/>        |
| Set code retention period                     |        | :heavy_check_mark: | :heavy_check_mark: |         | `BlockNumber`new\_<br/>        |
| Set max code size                             |        | :heavy_check_mark: | :heavy_check_mark: |         | `u32`new\_<br/>                |
| Set max pov size                              |        | :heavy_check_mark: | :heavy_check_mark: |         | `u32`new\_<br/>                |
| Set max head data size                        |        | :heavy_check_mark: | :heavy_check_mark: |         | `u32`new\_<br/>                |
| Set parathread cores                          |        | :heavy_check_mark: | :heavy_check_mark: |         | `u32`new\_<br/>                |
| Set parathread retries                        |        | :heavy_check_mark: | :heavy_check_mark: |         | `u32`new\_<br/>                |
| Set group rotation frequency                  |        | :heavy_check_mark: | :heavy_check_mark: |         | `BlockNumber`new\_<br/>        |
| Set chain availability period                 |        | :heavy_check_mark: | :heavy_check_mark: |         | `BlockNumber`new\_<br/>        |
| Set thread availability period                |        | :heavy_check_mark: | :heavy_check_mark: |         | `BlockNumber`new\_<br/>        |
| Set scheduling lookahead                      |        | :heavy_check_mark: | :heavy_check_mark: |         | `u32`new\_<br/>                |
| Set max validators per core                   |        | :heavy_check_mark: | :heavy_check_mark: |         | `Optionu32`new\_<br/>          |
| Set max validators                            |        | :heavy_check_mark: | :heavy_check_mark: |         | `Optionu32`new\_<br/>          |
| Set dispute period                            |        |                    |                    |         | `SessionIndex`new\_<br/>       |
| Set dispute post conclusion acceptance period |        | :heavy_check_mark: | :heavy_check_mark: |         | `BlockNumber`new\_<br/>        |
| Set no show slots                             |        | :heavy_check_mark: | :heavy_check_mark: |         | `u32`new\_<br/>                |
| Set n delay tranches                          |        | :heavy_check_mark: | :heavy_check_mark: |         | `u32`new\_<br/>                |
| Set zeroth delay tranche width                |        | :heavy_check_mark: | :heavy_check_mark: |         | `u32`new\_<br/>                |
| Set needed approvals                          |        | :heavy_check_mark: | :heavy_check_mark: |         | `u32`new\_<br/>                |
| Set relay vrf modulo samples                  |        | :heavy_check_mark: | :heavy_check_mark: |         | `u32`new\_<br/>                |
| Set max upward queue count                    |        | :heavy_check_mark: | :heavy_check_mark: |         | `u32`new\_<br/>                |
| Set max upward queue size                     |        | :heavy_check_mark: | :heavy_check_mark: |         | `u32`new\_<br/>                |
| Set max downward message size                 |        | :heavy_check_mark: | :heavy_check_mark: |         | `u32`new\_<br/>                |
| Set max upward message size                   |        | :heavy_check_mark: | :heavy_check_mark: |         | `u32`new\_<br/>                |
| Set max upward message num per candidate      |        | :heavy_check_mark: | :heavy_check_mark: |         | `u32`new\_<br/>                |
| Set hrmp open request ttl                     |        | :heavy_check_mark: | :heavy_check_mark: |         | `u32`new\_<br/>                |
| Set hrmp sender deposit                       |        | :heavy_check_mark: | :heavy_check_mark: |         | `Balance`new\_<br/>            |
| Set hrmp recipient deposit                    |        | :heavy_check_mark: | :heavy_check_mark: |         | `Balance`new\_<br/>            |
| Set hrmp channel max capacity                 |        | :heavy_check_mark: | :heavy_check_mark: |         | `u32`new\_<br/>                |
| Set hrmp channel max total size               |        | :heavy_check_mark: | :heavy_check_mark: |         | `u32`new\_<br/>                |
| Set hrmp max parachain inbound channels       |        | :heavy_check_mark: | :heavy_check_mark: |         | `u32`new\_<br/>                |
| Set hrmp max parathread inbound channels      |        | :heavy_check_mark: | :heavy_check_mark: |         | `u32`new\_<br/>                |
| Set hrmp channel max message size             |        | :heavy_check_mark: | :heavy_check_mark: |         | `u32`new\_<br/>                |
| Set hrmp max parachain outbound channels      |        | :heavy_check_mark: | :heavy_check_mark: |         | `u32`new\_<br/>                |
| Set hrmp max parathread outbound channels     |        | :heavy_check_mark: | :heavy_check_mark: |         | `u32`new\_<br/>                |
| Set hrmp max message num per candidate        |        | :heavy_check_mark: | :heavy_check_mark: |         | `u32`new\_<br/>                |
| Set pvf checking enabled                      |        | :heavy_check_mark: | :heavy_check_mark: |         | `bool`new\_<br/>               |
| Set pvf voting ttl                            |        | :heavy_check_mark: | :heavy_check_mark: |         | `SessionIndex`new\_<br/>       |
| Set minimum validation upgrade delay          |        | :heavy_check_mark: | :heavy_check_mark: |         | `BlockNumber`new\_<br/>        |
| Set bypass consistency check                  |        | :heavy_check_mark: | :heavy_check_mark: |         | `bool`new\_<br/>               |
| Set async backing params                      |        |                    |                    |         | `AsyncBackingParams`new\_<br/> |
| Set executor params                           |        |                    |                    |         | `ExecutorParams`new\_<br/>     |

## ParasShared

| Name | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments |
| ---- | ------ | --------- | ---------------- | ------- | --------- |

## ParaInclusion

| Name | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments |
| ---- | ------ | --------- | ---------------- | ------- | --------- |

## ParaInherent

| Name  | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                               |
| ----- | ------ | --------- | ---------------- | ------- | --------------------------------------- |
| Enter |        |           |                  |         | `ParachainsInherentDataHeader`data<br/> |

## Paras

| Name                        | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                                           |
| --------------------------- | ------ | --------- | ---------------- | ------- | ----------------------------------------------------------------------------------- |
| Force set current code      |        |           |                  |         | `ParaId`para<br/>`ValidationCode`new_code<br/>                                      |
| Force set current head      |        |           |                  |         | `ParaId`para<br/>`HeadData`new_head<br/>                                            |
| Force schedule code upgrade |        |           |                  |         | `ParaId`para<br/>`ValidationCode`new_code<br/>`BlockNumber`relay_parent_number<br/> |
| Force note new head         |        |           |                  |         | `ParaId`para<br/>`HeadData`new_head<br/>                                            |
| Force queue action          |        |           |                  |         | `ParaId`para<br/>                                                                   |
| Add trusted validation code |        |           |                  |         | `ValidationCode`validation_code<br/>                                                |
| Poke unused validation code |        |           |                  |         | `ValidationCodeHash`validation_code_hash<br/>                                       |
| Include pvf check statement |        |           |                  |         | `PvfCheckStatement`stmt<br/>`ValidatorSignature`signature<br/>                      |

## Initializer

| Name          | Nano S | Nano S XL          | Nano SP/X - Stax   | Nesting | Arguments               |
| ------------- | ------ | ------------------ | ------------------ | ------- | ----------------------- |
| Force approve |        | :heavy_check_mark: | :heavy_check_mark: |         | `BlockNumber`up_to<br/> |

## Hrmp

| Name                     | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                                                 |
| ------------------------ | ------ | --------- | ---------------- | ------- | ----------------------------------------------------------------------------------------- |
| Hrmp init open channel   |        |           |                  |         | `ParaId`recipient<br/>`u32`proposed_max_capacity<br/>`u32`proposed_max_message_size<br/>  |
| Hrmp accept open channel |        |           |                  |         | `ParaId`sender<br/>                                                                       |
| Hrmp close channel       |        |           |                  |         | `HrmpChannelId`channel_id<br/>                                                            |
| Force clean hrmp         |        |           |                  |         | `ParaId`para<br/>`u32`inbound<br/>`u32`outbound<br/>                                      |
| Force process hrmp open  |        |           |                  |         | `u32`channels<br/>                                                                        |
| Force process hrmp close |        |           |                  |         | `u32`channels<br/>                                                                        |
| Hrmp cancel open request |        |           |                  |         | `HrmpChannelId`channel_id<br/>`u32`open_requests<br/>                                     |
| Force open hrmp channel  |        |           |                  |         | `ParaId`sender<br/>`ParaId`recipient<br/>`u32`max_capacity<br/>`u32`max_message_size<br/> |

## ParasDisputes

| Name           | Nano S | Nano S XL          | Nano SP/X - Stax   | Nesting | Arguments |
| -------------- | ------ | ------------------ | ------------------ | ------- | --------- |
| Force unfreeze |        | :heavy_check_mark: | :heavy_check_mark: |         |           |

## ParasSlashing

| Name                         | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                              |
| ---------------------------- | ------ | --------- | ---------------- | ------- | ---------------------------------------------------------------------- |
| Report dispute lost unsigned |        |           |                  |         | `BoxDisputeProof`dispute_proof<br/>`KeyOwnerProof`key_owner_proof<br/> |

## Registrar

| Name                  | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                                                                              |
| --------------------- | ------ | --------- | ---------------- | ------- | ---------------------------------------------------------------------------------------------------------------------- |
| Register              |        |           |                  |         | `ParaId`id<br/>`HeadData`genesis_head<br/>`ValidationCode`validation_code<br/>                                         |
| Force register        |        |           |                  |         | `AccountId`who<br/>`Balance`deposit<br/>`ParaId`id<br/>`HeadData`genesis_head<br/>`ValidationCode`validation_code<br/> |
| Deregister            |        |           |                  |         | `ParaId`id<br/>                                                                                                        |
| Swap                  |        |           |                  |         | `ParaId`id<br/>`ParaId`other<br/>                                                                                      |
| Remove lock           |        |           |                  |         | `ParaId`para<br/>                                                                                                      |
| Reserve               |        |           |                  |         |                                                                                                                        |
| Add lock              |        |           |                  |         | `ParaId`para<br/>                                                                                                      |
| Schedule code upgrade |        |           |                  |         | `ParaId`para<br/>`ValidationCode`new_code<br/>                                                                         |
| Set current head      |        |           |                  |         | `ParaId`para<br/>`HeadData`new_head<br/>                                                                               |

## Slots

| Name             | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                                                                                     |
| ---------------- | ------ | --------- | ---------------- | ------- | ----------------------------------------------------------------------------------------------------------------------------- |
| Force lease      |        |           |                  |         | `ParaId`para<br/>`AccountId`leaser<br/>`Balance`amount<br/>`LeasePeriodOfT`period_begin<br/>`LeasePeriodOfT`period_count<br/> |
| Clear all leases |        |           |                  |         | `ParaId`para<br/>                                                                                                             |
| Trigger onboard  |        |           |                  |         | `ParaId`para<br/>                                                                                                             |

## Auctions

| Name           | Nano S | Nano S XL          | Nano SP/X - Stax   | Nesting | Arguments                                                                                                                           |
| -------------- | ------ | ------------------ | ------------------ | ------- | ----------------------------------------------------------------------------------------------------------------------------------- |
| New auction    |        | :heavy_check_mark: | :heavy_check_mark: |         | `Compactu32`duration<br/>`Compactu32`lease_period_index<br/>                                                                        |
| Bid            |        | :heavy_check_mark: | :heavy_check_mark: |         | `Compactu32`para<br/>`Compactu32`auction_index<br/>`Compactu32`first_slot<br/>`Compactu32`last_slot<br/>`CompactBalance`amount<br/> |
| Cancel auction |        | :heavy_check_mark: | :heavy_check_mark: |         |                                                                                                                                     |

## Crowdloan

| Name           | Nano S             | Nano S XL          | Nano SP/X - Stax   | Nesting | Arguments                                                                                                                                                |
| -------------- | ------------------ | ------------------ | ------------------ | ------- | -------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Create         | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `Compactu32`index<br/>`Compactu128`cap<br/>`Compactu32`first_period<br/>`Compactu32`last_period<br/>`Compactu32`end<br/>`OptionMultiSigner`verifier<br/> |
| Contribute     | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `Compactu32`index<br/>`Compactu128`amount<br/>`OptionMultiSignature`signature<br/>                                                                       |
| Withdraw       | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `AccountId`who<br/>`Compactu32`index<br/>                                                                                                                |
| Refund         | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `Compactu32`index<br/>                                                                                                                                   |
| Dissolve       | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `Compactu32`index<br/>                                                                                                                                   |
| Edit           | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `Compactu32`index<br/>`Compactu128`cap<br/>`Compactu32`first_period<br/>`Compactu32`last_period<br/>`Compactu32`end<br/>`OptionMultiSigner`verifier<br/> |
| Add memo       | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `ParaId`index<br/>`Vecu8`memo<br/>                                                                                                                       |
| Poke           | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `ParaId`index<br/>                                                                                                                                       |
| Contribute all | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `Compactu32`index<br/>`OptionMultiSignature`signature<br/>                                                                                               |

## XcmPallet

| Name                             | Nano S | Nano S XL | Nano SP/X - Stax   | Nesting | Arguments                                                                                                                                                                 |
| -------------------------------- | ------ | --------- | ------------------ | ------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Send                             |        |           |                    |         | `BoxVersionedMultiLocation`dest<br/>`BoxVersionedXcmTuple`message<br/>                                                                                                    |
| Teleport assets                  |        |           | :heavy_check_mark: |         | `BoxVersionedMultiLocation`dest<br/>`BoxVersionedMultiLocation`beneficiary<br/>`BoxVersionedMultiAssets`assets<br/>`u32`fee_asset_item<br/>                               |
| Reserve transfer assets          |        |           | :heavy_check_mark: |         | `BoxVersionedMultiLocation`dest<br/>`BoxVersionedMultiLocation`beneficiary<br/>`BoxVersionedMultiAssets`assets<br/>`u32`fee_asset_item<br/>                               |
| Execute                          |        |           |                    |         | `BoxVersionedXcmTasSysConfigRuntimeCall`message<br/>`Weight`max_weight<br/>                                                                                               |
| Force xcm version                |        |           |                    |         | `BoxMultiLocation`location<br/>`XcmVersion`xcm_version<br/>                                                                                                               |
| Force default xcm version        |        |           |                    |         | `OptionXcmVersion`maybe_xcm_version<br/>                                                                                                                                  |
| Force subscribe version notify   |        |           |                    |         | `BoxVersionedMultiLocation`location<br/>                                                                                                                                  |
| Force unsubscribe version notify |        |           |                    |         | `BoxVersionedMultiLocation`location<br/>                                                                                                                                  |
| Limited reserve transfer assets  |        |           | :heavy_check_mark: |         | `BoxVersionedMultiLocation`dest<br/>`BoxVersionedMultiLocation`beneficiary<br/>`BoxVersionedMultiAssets`assets<br/>`u32`fee_asset_item<br/>`WeightLimit`weight_limit<br/> |
| Limited teleport assets          |        |           | :heavy_check_mark: |         | `BoxVersionedMultiLocation`dest<br/>`BoxVersionedMultiLocation`beneficiary<br/>`BoxVersionedMultiAssets`assets<br/>`u32`fee_asset_item<br/>`WeightLimit`weight_limit<br/> |
| Force suspension                 |        |           |                    |         | `bool`suspended<br/>                                                                                                                                                      |

## MessageQueue

| Name               | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                                                          |
| ------------------ | ------ | --------- | ---------------- | ------- | -------------------------------------------------------------------------------------------------- |
| Reap page          |        |           |                  |         | `MessageOriginOfT`message_origin<br/>`PageIndex`page_index<br/>                                    |
| Execute overweight |        |           |                  |         | `MessageOriginOfT`message_origin<br/>`PageIndex`page<br/>`Size`index<br/>`Weight`weight_limit<br/> |
