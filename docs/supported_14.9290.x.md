# Polkadot  14.9290.x

## System

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Fill block |    | :heavy_check_mark: | :heavy_check_mark: | `Perbill` ratio <br/> |
|Remark |    | :heavy_check_mark: | :heavy_check_mark: | `Vecu8` remark <br/> |
|Set heap pages |    | :heavy_check_mark: | :heavy_check_mark: | `u64` pages <br/> |
|Set code |    | :heavy_check_mark: | :heavy_check_mark: | `Vecu8` code <br/> |
|Set code without checks |    | :heavy_check_mark: | :heavy_check_mark: | `Vecu8` code <br/> |
|Set storage |    |   |   | `VecKeyValue` items <br/> |
|Kill storage |    |   |   | `VecKey` keys <br/> |
|Kill prefix |    |   |   | `Key` prefix <br/>`u32` subkeys <br/> |
|Remark with event |    | :heavy_check_mark: | :heavy_check_mark: | `Vecu8` remark <br/> |

## Scheduler

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Schedule |    |   |   | `BlockNumber` when <br/>`OptionschedulePeriodBlockNumber` maybe_periodic <br/>`schedulePriority` priority <br/>`BoxCallOrHashOfT` call <br/> |
|Cancel |    |   |   | `BlockNumber` when <br/>`u32` index <br/> |
|Schedule named |    |   |   | `Vecu8` id <br/>`BlockNumber` when <br/>`OptionschedulePeriodBlockNumber` maybe_periodic <br/>`schedulePriority` priority <br/>`BoxCallOrHashOfT` call <br/> |
|Cancel named |    |   |   | `Vecu8` id <br/> |
|Schedule after |    |   |   | `BlockNumber` after <br/>`OptionschedulePeriodBlockNumber` maybe_periodic <br/>`schedulePriority` priority <br/>`BoxCallOrHashOfT` call <br/> |
|Schedule named after |    |   |   | `Vecu8` id <br/>`BlockNumber` after <br/>`OptionschedulePeriodBlockNumber` maybe_periodic <br/>`schedulePriority` priority <br/>`BoxCallOrHashOfT` call <br/> |

## Preimage

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Note preimage |    | :heavy_check_mark: |   | `Vecu8` bytes <br/> |
|Unnote preimage |    | :heavy_check_mark: |   | `Hash` hash <br/> |
|Request preimage |    | :heavy_check_mark: |   | `Hash` hash <br/> |
|Unrequest preimage |    | :heavy_check_mark: |   | `Hash` hash <br/> |

## Babe

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Report equivocation |    |   |   | `BoxEquivocationProofHeader` equivocation_proof <br/>`KeyOwnerProof` key_owner_proof <br/> |
|Report equivocation unsigned |    |   |   | `BoxEquivocationProofHeader` equivocation_proof <br/>`KeyOwnerProof` key_owner_proof <br/> |
|Plan config change |    |   |   | `NextConfigDescriptor` config <br/> |

## Timestamp

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Set |    | :heavy_check_mark: |   | `Compactu64` now <br/> |

## Indices

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Claim |    | :heavy_check_mark: |   | `AccountIndex` index <br/> |
|Transfer |    | :heavy_check_mark: |   | `AccountIdLookupOfT` new_ <br/>`AccountIndex` index <br/> |
|Free |    | :heavy_check_mark: |   | `AccountIndex` index <br/> |
|Force transfer |    | :heavy_check_mark: |   | `AccountIdLookupOfT` new_ <br/>`AccountIndex` index <br/>`bool` freeze <br/> |
|Freeze |    | :heavy_check_mark: |   | `AccountIndex` index <br/> |

## Balances

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Transfer | :heavy_check_mark:  | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT` dest <br/>`CompactBalance` amount <br/> |
|Set balance |    | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT` who <br/>`CompactBalance` new_free <br/>`CompactBalance` new_reserved <br/> |
|Force transfer | :heavy_check_mark:  | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT` source <br/>`AccountIdLookupOfT` dest <br/>`CompactBalance` amount <br/> |
|Transfer keep alive | :heavy_check_mark:  | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT` dest <br/>`CompactBalance` amount <br/> |
|Transfer all | :heavy_check_mark:  | :heavy_check_mark: |   | `AccountIdLookupOfT` dest <br/>`bool` keep_alive <br/> |
|Force unreserve |    | :heavy_check_mark: |   | `AccountIdLookupOfT` who <br/>`Balance` amount <br/> |

## Authorship

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Set uncles |    |   |   | `VecHeader` new_uncles <br/> |

## Staking

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Bond | :heavy_check_mark:  | :heavy_check_mark: |   | `AccountIdLookupOfT` controller <br/>`CompactBalance` amount <br/>`RewardDestination` payee <br/> |
|Bond extra | :heavy_check_mark:  | :heavy_check_mark: |   | `CompactBalance` amount <br/> |
|Unbond | :heavy_check_mark:  | :heavy_check_mark: |   | `CompactBalance` amount <br/> |
|Withdraw Unbonded | :heavy_check_mark:  | :heavy_check_mark: |   | `u32` num_slashing_spans <br/> |
|Validate | :heavy_check_mark:  | :heavy_check_mark: |   | `ValidatorPrefs` prefs <br/> |
|Nominate | :heavy_check_mark:  | :heavy_check_mark: |   | `VecAccountIdLookupOfT` targets <br/> |
|Chill | :heavy_check_mark:  | :heavy_check_mark: |   |  |
|Set payee | :heavy_check_mark:  | :heavy_check_mark: |   | `RewardDestination` payee <br/> |
|Set controller | :heavy_check_mark:  | :heavy_check_mark: |   | `AccountIdLookupOfT` controller <br/> |
|Set validator count |    | :heavy_check_mark: |   | `Compactu32` new_ <br/> |
|Increase validator count |    | :heavy_check_mark: |   | `Compactu32` additional <br/> |
|Scale validator count |    |   |   | `Percent` factor <br/> |
|Force no eras |    | :heavy_check_mark: |   |  |
|Force new era |    | :heavy_check_mark: |   |  |
|Set invulnerables |    | :heavy_check_mark: |   | `VecAccountId` invulnerables <br/> |
|Force unstake |    | :heavy_check_mark: |   | `AccountId` stash <br/>`u32` num_slashing_spans <br/> |
|Force new era always |    | :heavy_check_mark: |   |  |
|Cancel deferred slash |    | :heavy_check_mark: |   | `EraIndex` era <br/>`Vecu32` slash_indices <br/> |
|Payout stakers | :heavy_check_mark:  | :heavy_check_mark: |   | `AccountId` validator_stash <br/>`EraIndex` era <br/> |
|Rebond | :heavy_check_mark:  | :heavy_check_mark: |   | `CompactBalance` amount <br/> |
|Set history depth |    | :heavy_check_mark: |   | `Compactu32` new_history_depth <br/>`Compactu32` era_items_deleted <br/> |
|Reap stash |    | :heavy_check_mark: |   | `AccountId` stash <br/>`u32` num_slashing_spans <br/> |
|Kick |    | :heavy_check_mark: |   | `VecAccountIdLookupOfT` who <br/> |
|Set staking configs |    |   |   | `ConfigOpBalanceOfT` min_nominator_bond <br/>`ConfigOpBalanceOfT` min_validator_bond <br/>`ConfigOpu32` max_nominator_count <br/>`ConfigOpu32` max_validator_count <br/>`ConfigOpPercent` chill_threshold <br/>`ConfigOpPerbill` min_commission <br/> |
|Chill other |    | :heavy_check_mark: |   | `AccountId` controller <br/> |
|Force apply min commission |    | :heavy_check_mark: |   | `AccountId` validator_stash <br/> |

## Session

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Set keys | :heavy_check_mark:  | :heavy_check_mark: |   | `Keys` keys <br/>`Bytes` proof <br/> |
|Purge keys | :heavy_check_mark:  | :heavy_check_mark: |   |  |

## Grandpa

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Report equivocation |    |   |   | `BoxEquivocationProofHashBlockNumber` equivocation_proof <br/>`KeyOwnerProof` key_owner_proof <br/> |
|Report equivocation unsigned |    |   |   | `BoxEquivocationProofHashBlockNumber` equivocation_proof <br/>`KeyOwnerProof` key_owner_proof <br/> |
|Note stalled |    | :heavy_check_mark: |   | `BlockNumber` delay <br/>`BlockNumber` best_finalized_block_number <br/> |

## ImOnline

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Heartbeat |    |   |   | `HeartbeatBlockNumber` heartbeat <br/>`AuthorityIdasRuntimeAppPublicSignature` signature <br/> |

## Democracy

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Propose |    | :heavy_check_mark: | :heavy_check_mark: | `Hash` proposal_hash <br/>`CompactBalance` amount <br/> |
|Second |    | :heavy_check_mark: | :heavy_check_mark: | `Compactu32` proposal <br/>`Compactu32` seconds_upper_bound <br/> |
|Vote |    | :heavy_check_mark: | :heavy_check_mark: | `Compactu32` ref_index <br/>`AccountVote` vote <br/> |
|Emergency cancel |    | :heavy_check_mark: | :heavy_check_mark: | `ReferendumIndex` ref_index <br/> |
|External propose |    | :heavy_check_mark: | :heavy_check_mark: | `Hash` proposal_hash <br/> |
|External propose majority |    | :heavy_check_mark: | :heavy_check_mark: | `Hash` proposal_hash <br/> |
|External propose default |    | :heavy_check_mark: | :heavy_check_mark: | `Hash` proposal_hash <br/> |
|Fast track |    | :heavy_check_mark: | :heavy_check_mark: | `Hash` proposal_hash <br/>`BlockNumber` voting_period <br/>`BlockNumber` delay <br/> |
|Veto external |    | :heavy_check_mark: | :heavy_check_mark: | `Hash` proposal_hash <br/> |
|Cancel referendum |    | :heavy_check_mark: | :heavy_check_mark: | `Compactu32` ref_index <br/> |
|Cancel queued |    | :heavy_check_mark: | :heavy_check_mark: | `ReferendumIndex` which <br/> |
|Delegate |    | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT` to <br/>`Conviction` conviction <br/>`Balance` balance <br/> |
|Undelegate |    | :heavy_check_mark: | :heavy_check_mark: |  |
|Clear public proposals |    | :heavy_check_mark: | :heavy_check_mark: |  |
|Note preimage |    | :heavy_check_mark: |   | `Bytes` encoded_proposal <br/> |
|Note preimage operational |    | :heavy_check_mark: |   | `Bytes` encoded_proposal <br/> |
|Note imminent preimage |    | :heavy_check_mark: |   | `Bytes` encoded_proposal <br/> |
|Note imminent preimage operational |    | :heavy_check_mark: |   | `Bytes` encoded_proposal <br/> |
|Reap preimage |    | :heavy_check_mark: | :heavy_check_mark: | `Hash` proposal_hash <br/>`Compactu32` proposal_len_upper_bound <br/> |
|Unlock |    | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT` target <br/> |
|Remove vote |    | :heavy_check_mark: | :heavy_check_mark: | `ReferendumIndex` index <br/> |
|Remove other vote |    | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT` target <br/>`ReferendumIndex` index <br/> |
|Enact proposal |    | :heavy_check_mark: | :heavy_check_mark: | `Hash` proposal_hash <br/>`ReferendumIndex` index <br/> |
|Blacklist |    |   |   | `Hash` proposal_hash <br/>`OptionReferendumIndex` maybe_ref_index <br/> |
|Cancel proposal |    | :heavy_check_mark: | :heavy_check_mark: | `Compactu32` prop_index <br/> |

## Council

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Set members |    | :heavy_check_mark: |   | `VecAccountId` new_members <br/>`OptionAccountId` prime <br/>`MemberCount` old_count <br/> |
|Execute |    | :heavy_check_mark: |   | `Proposal` proposal <br/>`Compactu32` length_bound <br/> |
|Propose |    | :heavy_check_mark: |   | `Compactu32` threshold <br/>`Proposal` proposal <br/>`Compactu32` length_bound <br/> |
|Vote |    | :heavy_check_mark: |   | `Hash` proposal <br/>`Compactu32` index <br/>`bool` approve <br/> |
|Close |    | :heavy_check_mark: |   | `Hash` proposal_hash <br/>`Compactu32` index <br/>`Compactu64` proposal_weight_bound <br/>`Compactu32` length_bound <br/> |
|Disapprove proposal |    | :heavy_check_mark: |   | `Hash` proposal_hash <br/> |

## TechnicalCommittee

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Set members |    | :heavy_check_mark: |   | `VecAccountId` new_members <br/>`OptionAccountId` prime <br/>`MemberCount` old_count <br/> |
|Execute |    | :heavy_check_mark: |   | `Proposal` proposal <br/>`Compactu32` length_bound <br/> |
|Propose |    | :heavy_check_mark: |   | `Compactu32` threshold <br/>`Proposal` proposal <br/>`Compactu32` length_bound <br/> |
|Vote |    | :heavy_check_mark: |   | `Hash` proposal <br/>`Compactu32` index <br/>`bool` approve <br/> |
|Close |    | :heavy_check_mark: |   | `Hash` proposal_hash <br/>`Compactu32` index <br/>`Compactu64` proposal_weight_bound <br/>`Compactu32` length_bound <br/> |
|Disapprove proposal |    | :heavy_check_mark: |   | `Hash` proposal_hash <br/> |

## PhragmenElection

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Vote |    | :heavy_check_mark: |   | `VecAccountId` votes <br/>`Compactu128` amount <br/> |
|Remove voter |    | :heavy_check_mark: |   |  |
|Submit candidacy |    | :heavy_check_mark: |   | `Compactu32` candidate_count <br/> |
|Renounce candidacy |    |   |   | `Renouncing` renouncing <br/> |
|Remove member |    | :heavy_check_mark: |   | `AccountIdLookupOfT` who <br/>`bool` slash_bond <br/>`bool` rerun_election <br/> |
|Clean defunct voters |    | :heavy_check_mark: |   | `u32` num_voters <br/>`u32` num_defunct <br/> |

## TechnicalMembership

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Add member |    | :heavy_check_mark: |   | `AccountIdLookupOfT` who <br/> |
|Remove member |    | :heavy_check_mark: |   | `AccountIdLookupOfT` who <br/> |
|Swap member |    | :heavy_check_mark: |   | `AccountIdLookupOfT` remove <br/>`AccountIdLookupOfT` add <br/> |
|Reset members |    | :heavy_check_mark: |   | `VecAccountId` members <br/> |
|Change key |    | :heavy_check_mark: |   | `AccountIdLookupOfT` new_ <br/> |
|Set prime |    | :heavy_check_mark: |   | `AccountIdLookupOfT` who <br/> |
|Clear prime |    | :heavy_check_mark: |   |  |

## Treasury

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Propose spend |    | :heavy_check_mark: |   | `CompactBalance` amount <br/>`AccountIdLookupOfT` beneficiary <br/> |
|Reject proposal |    | :heavy_check_mark: |   | `Compactu32` proposal_id <br/> |
|Approve proposal |    | :heavy_check_mark: |   | `Compactu32` proposal_id <br/> |
|Spend |    | :heavy_check_mark: |   | `CompactBalance` amount <br/>`AccountIdLookupOfT` beneficiary <br/> |
|Remove approval |    | :heavy_check_mark: |   | `Compactu32` proposal_id <br/> |

## Claims

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Claim |    | :heavy_check_mark: |   | `AccountId` dest <br/>`EcdsaSignature` ethereum_signature <br/> |
|Mint claim |    |   |   | `EthereumAddress` who <br/>`Balance` amount <br/>`OptionTupleBalanceOfTBalanceOfTBlockNumber` vesting_schedule <br/>`OptionStatementKind` statement <br/> |
|Claim attest |    | :heavy_check_mark: |   | `AccountId` dest <br/>`EcdsaSignature` ethereum_signature <br/>`Bytes` statement <br/> |
|Attest |    | :heavy_check_mark: |   | `Bytes` statement <br/> |
|Move claim |    | :heavy_check_mark: |   | `EthereumAddress` old <br/>`EthereumAddress` new_ <br/>`OptionAccountId` maybe_preclaim <br/> |

## Vesting

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Vest |    | :heavy_check_mark: |   |  |
|Vest other |    | :heavy_check_mark: |   | `AccountIdLookupOfT` target <br/> |
|Vested transfer |    | :heavy_check_mark: |   | `AccountIdLookupOfT` target <br/>`VestingInfo` schedule <br/> |
|Force vested transfer |    | :heavy_check_mark: |   | `AccountIdLookupOfT` source <br/>`AccountIdLookupOfT` target <br/>`VestingInfo` schedule <br/> |
|Merge schedules |    | :heavy_check_mark: |   | `u32` schedule1_index <br/>`u32` schedule2_index <br/> |

## Utility

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Batch | :heavy_check_mark:  | :heavy_check_mark: |   | `VecCall` calls <br/> |
|As derivative |    |   |   | `u16` index <br/>`Call` call <br/> |
|Batch all | :heavy_check_mark:  | :heavy_check_mark: |   | `VecCall` calls <br/> |
|Dispatch as |    |   |   | `BoxPalletsOrigin` as_origin <br/>`Call` call <br/> |
|Force batch | :heavy_check_mark:  | :heavy_check_mark: |   | `VecCall` calls <br/> |

## Identity

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Add registrar |    | :heavy_check_mark: |   | `AccountIdLookupOfT` account <br/> |
|Set identity |    |   |   | `BoxIdentityInfoMaxAdditionalFields` info <br/> |
|Set subs |    |   |   | `VecTupleAccountIdData` subs <br/> |
|Clear identity |    | :heavy_check_mark: |   |  |
|Request judgement |    | :heavy_check_mark: |   | `Compactu32` reg_index <br/>`Compactu128` max_fee <br/> |
|Cancel request |    | :heavy_check_mark: |   | `RegistrarIndex` reg_index <br/> |
|Set fee |    | :heavy_check_mark: |   | `Compactu32` index <br/>`Compactu128` fee <br/> |
|Set account id |    | :heavy_check_mark: |   | `Compactu32` index <br/>`AccountIdLookupOfT` new_ <br/> |
|Set fields |    |   |   | `Compactu32` index <br/>`IdentityFields` fields <br/> |
|Provide judgement |    |   |   | `Compactu32` reg_index <br/>`AccountIdLookupOfT` target <br/>`JudgementBalanceOfT` judgement <br/> |
|Kill identity |    | :heavy_check_mark: |   | `AccountIdLookupOfT` target <br/> |
|Add sub |    |   |   | `AccountIdLookupOfT` sub <br/>`Data` data <br/> |
|Rename sub |    |   |   | `AccountIdLookupOfT` sub <br/>`Data` data <br/> |
|Remove sub |    | :heavy_check_mark: |   | `AccountIdLookupOfT` sub <br/> |
|Quit sub |    | :heavy_check_mark: |   |  |

## Proxy

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Proxy |    | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT` real <br/>`OptionProxyType` force_proxy_type <br/>`Call` call <br/> |
|Add proxy |    | :heavy_check_mark: |   | `AccountIdLookupOfT` delegate <br/>`ProxyType` proxy_type <br/>`BlockNumber` delay <br/> |
|Remove proxy |    | :heavy_check_mark: |   | `AccountIdLookupOfT` delegate <br/>`ProxyType` proxy_type <br/>`BlockNumber` delay <br/> |
|Remove proxies |    | :heavy_check_mark: |   |  |
|Anonymous |    | :heavy_check_mark: |   | `ProxyType` proxy_type <br/>`BlockNumber` delay <br/>`u16` index <br/> |
|Kill anonymous |    | :heavy_check_mark: |   | `AccountIdLookupOfT` spawner <br/>`ProxyType` proxy_type <br/>`u16` index <br/>`Compactu32` height <br/>`Compactu32` ext_index <br/> |
|Announce |    |   |   | `AccountIdLookupOfT` real <br/>`CallHashOf` call_hash <br/> |
|Remove announcement |    |   |   | `AccountIdLookupOfT` real <br/>`CallHashOf` call_hash <br/> |
|Reject announcement |    |   |   | `AccountIdLookupOfT` delegate <br/>`CallHashOf` call_hash <br/> |
|Proxy announced |    | :heavy_check_mark: |   | `AccountIdLookupOfT` delegate <br/>`AccountIdLookupOfT` real <br/>`OptionProxyType` force_proxy_type <br/>`Call` call <br/> |

## Multisig

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|As multi threshold 1 |    | :heavy_check_mark: | :heavy_check_mark: | `VecAccountId` other_signatories <br/>`Call` call <br/> |
|As multi |    | :heavy_check_mark: | :heavy_check_mark: | `u16` threshold <br/>`VecAccountId` other_signatories <br/>`OptionTimepoint` maybe_timepoint <br/>`OpaqueCall` call <br/>`bool` store_call <br/>`Weight` max_weight <br/> |
|Approve as multi |    | :heavy_check_mark: | :heavy_check_mark: | `u16` threshold <br/>`VecAccountId` other_signatories <br/>`OptionTimepoint` maybe_timepoint <br/>`H256` call_hash <br/>`Weight` max_weight <br/> |
|Cancel as multi |    | :heavy_check_mark: | :heavy_check_mark: | `u16` threshold <br/>`VecAccountId` other_signatories <br/>`Timepoint` timepoint <br/>`H256` call_hash <br/> |

## Bounties

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Propose bounty |    | :heavy_check_mark: |   | `CompactBalance` amount <br/>`Bytes` description <br/> |
|Approve bounty |    | :heavy_check_mark: |   | `Compactu32` bounty_id <br/> |
|Propose curator |    | :heavy_check_mark: |   | `Compactu32` bounty_id <br/>`AccountIdLookupOfT` curator <br/>`CompactBalance` fee <br/> |
|Unassign curator |    | :heavy_check_mark: |   | `Compactu32` bounty_id <br/> |
|Accept curator |    | :heavy_check_mark: |   | `Compactu32` bounty_id <br/> |
|Award bounty |    | :heavy_check_mark: |   | `Compactu32` bounty_id <br/>`AccountIdLookupOfT` beneficiary <br/> |
|Claim bounty |    | :heavy_check_mark: |   | `Compactu32` bounty_id <br/> |
|Close bounty |    | :heavy_check_mark: |   | `Compactu32` bounty_id <br/> |
|Extend bounty expiry |    | :heavy_check_mark: |   | `Compactu32` bounty_id <br/>`Bytes` remark <br/> |

## ChildBounties

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Add child bounty |    | :heavy_check_mark: |   | `Compactu32` parent_bounty_id <br/>`CompactBalance` amount <br/>`Vecu8` description <br/> |
|Propose curator |    | :heavy_check_mark: |   | `Compactu32` parent_bounty_id <br/>`Compactu32` child_bounty_id <br/>`AccountIdLookupOfT` curator <br/>`CompactBalance` fee <br/> |
|Accept curator |    | :heavy_check_mark: |   | `Compactu32` parent_bounty_id <br/>`Compactu32` child_bounty_id <br/> |
|Unassign curator |    | :heavy_check_mark: |   | `Compactu32` parent_bounty_id <br/>`Compactu32` child_bounty_id <br/> |
|Award child bounty |    | :heavy_check_mark: |   | `Compactu32` parent_bounty_id <br/>`Compactu32` child_bounty_id <br/>`AccountIdLookupOfT` beneficiary <br/> |
|Claim child bounty |    | :heavy_check_mark: |   | `Compactu32` parent_bounty_id <br/>`Compactu32` child_bounty_id <br/> |
|Close child bounty |    | :heavy_check_mark: |   | `Compactu32` parent_bounty_id <br/>`Compactu32` child_bounty_id <br/> |

## Tips

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Report awesome |    | :heavy_check_mark: |   | `Bytes` reason <br/>`AccountIdLookupOfT` who <br/> |
|Retract tip |    | :heavy_check_mark: |   | `Hash` hash <br/> |
|Tip new |    | :heavy_check_mark: |   | `Bytes` reason <br/>`AccountIdLookupOfT` who <br/>`Compactu128` tip_value <br/> |
|Tip |    | :heavy_check_mark: |   | `Hash` hash <br/>`Compactu128` tip_value <br/> |
|Close tip |    | :heavy_check_mark: |   | `Hash` hash <br/> |
|Slash tip |    | :heavy_check_mark: |   | `Hash` hash <br/> |

## ElectionProviderMultiPhase

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Submit unsigned |    |   |   | `BoxRawSolutionSolutionOfMinerConfig` raw_solution <br/>`SolutionOrSnapshotSize` witness <br/> |
|Set minimum untrusted score |    |   |   | `OptionElectionScore` maybe_next_score <br/> |
|Set emergency election result |    |   |   | `SupportsAccountId` supports <br/> |
|Submit |    |   |   | `BoxRawSolutionSolutionOfMinerConfig` raw_solution <br/> |
|Governance fallback |    | :heavy_check_mark: |   | `Optionu32` maybe_max_voters <br/>`Optionu32` maybe_max_targets <br/> |

## VoterList

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Rebag |    | :heavy_check_mark: |   | `AccountIdLookupOfT` dislocated <br/> |
|Put in front of |    | :heavy_check_mark: |   | `AccountIdLookupOfT` lighter <br/> |

## NominationPools

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Join |    | :heavy_check_mark: |   | `Compactu128` amount <br/>`PoolId` pool_id <br/> |
|Bond extra |    | :heavy_check_mark: |   | `BondExtraBalanceOfT` extra <br/> |
|Claim payout |    | :heavy_check_mark: |   |  |
|Unbond |    | :heavy_check_mark: |   | `AccountIdLookupOfT` member_account <br/>`Compactu128` unbonding_points <br/> |
|Pool withdraw unbonded |    | :heavy_check_mark: |   | `PoolId` pool_id <br/>`u32` num_slashing_spans <br/> |
|Withdraw Unbonded |    | :heavy_check_mark: |   | `AccountIdLookupOfT` member_account <br/>`u32` num_slashing_spans <br/> |
|Create |    | :heavy_check_mark: |   | `Compactu128` amount <br/>`AccountIdLookupOfT` root <br/>`AccountIdLookupOfT` nominator <br/>`AccountIdLookupOfT` state_toggler <br/> |
|Nominate |    | :heavy_check_mark: |   | `PoolId` pool_id <br/>`VecAccountId` validators <br/> |
|Set state |    | :heavy_check_mark: |   | `PoolId` pool_id <br/>`PoolState` state <br/> |
|Set metadata |    | :heavy_check_mark: |   | `PoolId` pool_id <br/>`Vecu8` metadata <br/> |
|Set configs |    | :heavy_check_mark: |   | `ConfigOpBalanceOfT` min_join_bond <br/>`ConfigOpBalanceOfT` min_create_bond <br/>`ConfigOpu32` max_pools <br/>`ConfigOpu32` max_members <br/>`ConfigOpu32` max_members_per_pool <br/> |
|Update roles |    | :heavy_check_mark: |   | `PoolId` pool_id <br/>`ConfigOpAccountId` new_root <br/>`ConfigOpAccountId` new_nominator <br/>`ConfigOpAccountId` new_state_toggler <br/> |
|Chill |    | :heavy_check_mark: |   | `PoolId` pool_id <br/> |

## Configuration

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Set validation upgrade cooldown |    | :heavy_check_mark: |   | `BlockNumber` new_ <br/> |
|Set validation upgrade delay |    | :heavy_check_mark: |   | `BlockNumber` new_ <br/> |
|Set code retention period |    | :heavy_check_mark: |   | `BlockNumber` new_ <br/> |
|Set max code size |    | :heavy_check_mark: |   | `u32` new_ <br/> |
|Set max pov size |    | :heavy_check_mark: |   | `u32` new_ <br/> |
|Set max head data size |    | :heavy_check_mark: |   | `u32` new_ <br/> |
|Set parathread cores |    | :heavy_check_mark: |   | `u32` new_ <br/> |
|Set parathread retries |    | :heavy_check_mark: |   | `u32` new_ <br/> |
|Set group rotation frequency |    | :heavy_check_mark: |   | `BlockNumber` new_ <br/> |
|Set chain availability period |    | :heavy_check_mark: |   | `BlockNumber` new_ <br/> |
|Set thread availability period |    | :heavy_check_mark: |   | `BlockNumber` new_ <br/> |
|Set scheduling lookahead |    | :heavy_check_mark: |   | `u32` new_ <br/> |
|Set max validators per core |    | :heavy_check_mark: |   | `Optionu32` new_ <br/> |
|Set max validators |    | :heavy_check_mark: |   | `Optionu32` new_ <br/> |
|Set dispute period |    |   |   | `SessionIndex` new_ <br/> |
|Set dispute post conclusion acceptance period |    | :heavy_check_mark: |   | `BlockNumber` new_ <br/> |
|Set dispute max spam slots |    | :heavy_check_mark: |   | `u32` new_ <br/> |
|Set dispute conclusion by time out period |    | :heavy_check_mark: |   | `BlockNumber` new_ <br/> |
|Set no show slots |    | :heavy_check_mark: |   | `u32` new_ <br/> |
|Set n delay tranches |    | :heavy_check_mark: |   | `u32` new_ <br/> |
|Set zeroth delay tranche width |    | :heavy_check_mark: |   | `u32` new_ <br/> |
|Set needed approvals |    | :heavy_check_mark: |   | `u32` new_ <br/> |
|Set relay vrf modulo samples |    | :heavy_check_mark: |   | `u32` new_ <br/> |
|Set max upward queue count |    | :heavy_check_mark: |   | `u32` new_ <br/> |
|Set max upward queue size |    | :heavy_check_mark: |   | `u32` new_ <br/> |
|Set max downward message size |    | :heavy_check_mark: |   | `u32` new_ <br/> |
|Set ump service total weight |    | :heavy_check_mark: |   | `Weight` new_ <br/> |
|Set max upward message size |    | :heavy_check_mark: |   | `u32` new_ <br/> |
|Set max upward message num per candidate |    | :heavy_check_mark: |   | `u32` new_ <br/> |
|Set hrmp open request ttl |    | :heavy_check_mark: |   | `u32` new_ <br/> |
|Set hrmp sender deposit |    | :heavy_check_mark: |   | `Balance` new_ <br/> |
|Set hrmp recipient deposit |    | :heavy_check_mark: |   | `Balance` new_ <br/> |
|Set hrmp channel max capacity |    | :heavy_check_mark: |   | `u32` new_ <br/> |
|Set hrmp channel max total size |    | :heavy_check_mark: |   | `u32` new_ <br/> |
|Set hrmp max parachain inbound channels |    | :heavy_check_mark: |   | `u32` new_ <br/> |
|Set hrmp max parathread inbound channels |    | :heavy_check_mark: |   | `u32` new_ <br/> |
|Set hrmp channel max message size |    | :heavy_check_mark: |   | `u32` new_ <br/> |
|Set hrmp max parachain outbound channels |    | :heavy_check_mark: |   | `u32` new_ <br/> |
|Set hrmp max parathread outbound channels |    | :heavy_check_mark: |   | `u32` new_ <br/> |
|Set hrmp max message num per candidate |    | :heavy_check_mark: |   | `u32` new_ <br/> |
|Set ump max individual weight |    | :heavy_check_mark: |   | `Weight` new_ <br/> |
|Set pvf checking enabled |    | :heavy_check_mark: |   | `bool` new_ <br/> |
|Set pvf voting ttl |    | :heavy_check_mark: |   | `SessionIndex` new_ <br/> |
|Set minimum validation upgrade delay |    | :heavy_check_mark: |   | `BlockNumber` new_ <br/> |
|Set bypass consistency check |    | :heavy_check_mark: |   | `bool` new_ <br/> |

## ParasShared

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|

## ParaInclusion

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|

## ParaInherent

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Enter |    |   |   | `ParachainsInherentDataHeader` data <br/> |

## Paras

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Force set current code |    |   |   | `ParaId` para <br/>`ValidationCode` new_code <br/> |
|Force set current head |    |   |   | `ParaId` para <br/>`HeadData` new_head <br/> |
|Force schedule code upgrade |    |   |   | `ParaId` para <br/>`ValidationCode` new_code <br/>`BlockNumber` relay_parent_number <br/> |
|Force note new head |    |   |   | `ParaId` para <br/>`HeadData` new_head <br/> |
|Force queue action |    |   |   | `ParaId` para <br/> |
|Add trusted validation code |    |   |   | `ValidationCode` validation_code <br/> |
|Poke unused validation code |    |   |   | `ValidationCodeHash` validation_code_hash <br/> |
|Include pvf check statement |    |   |   | `PvfCheckStatement` stmt <br/>`ValidatorSignature` signature <br/> |

## Initializer

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Force approve |    | :heavy_check_mark: |   | `BlockNumber` up_to <br/> |

## Dmp

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|

## Ump

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Service overweight |    | :heavy_check_mark: |   | `OverweightIndex` index <br/>`Weight` weight_limit <br/> |

## Hrmp

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Hrmp init open channel |    |   |   | `ParaId` recipient <br/>`u32` proposed_max_capacity <br/>`u32` proposed_max_message_size <br/> |
|Hrmp accept open channel |    |   |   | `ParaId` sender <br/> |
|Hrmp close channel |    |   |   | `HrmpChannelId` channel_id <br/> |
|Force clean hrmp |    |   |   | `ParaId` para <br/>`u32` inbound <br/>`u32` outbound <br/> |
|Force process hrmp open |    | :heavy_check_mark: |   | `u32` channels <br/> |
|Force process hrmp close |    | :heavy_check_mark: |   | `u32` channels <br/> |
|Hrmp cancel open request |    |   |   | `HrmpChannelId` channel_id <br/>`u32` open_requests <br/> |

## ParasDisputes

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Force unfreeze |    | :heavy_check_mark: |   |  |

## Registrar

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Register |    |   |   | `ParaId` id <br/>`HeadData` genesis_head <br/>`ValidationCode` validation_code <br/> |
|Force register |    |   |   | `AccountId` who <br/>`Balance` deposit <br/>`ParaId` id <br/>`HeadData` genesis_head <br/>`ValidationCode` validation_code <br/> |
|Deregister |    |   |   | `ParaId` id <br/> |
|Swap |    |   |   | `ParaId` id <br/>`ParaId` other <br/> |
|Force remove lock |    |   |   | `ParaId` para <br/> |
|Reserve |    | :heavy_check_mark: |   |  |

## Slots

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Force lease |    |   |   | `ParaId` para <br/>`AccountId` leaser <br/>`Balance` amount <br/>`LeasePeriodOfT` period_begin <br/>`LeasePeriodOfT` period_count <br/> |
|Clear all leases |    |   |   | `ParaId` para <br/> |
|Trigger onboard |    |   |   | `ParaId` para <br/> |

## Auctions

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|New auction |    | :heavy_check_mark: |   | `Compactu32` duration <br/>`Compactu32` lease_period_index <br/> |
|Bid |    | :heavy_check_mark: |   | `Compactu32` para <br/>`Compactu32` auction_index <br/>`Compactu32` first_slot <br/>`Compactu32` last_slot <br/>`CompactBalance` amount <br/> |
|Cancel auction |    | :heavy_check_mark: |   |  |

## Crowdloan

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Create | :heavy_check_mark:  | :heavy_check_mark: |   | `Compactu32` index <br/>`Compactu128` cap <br/>`Compactu32` first_period <br/>`Compactu32` last_period <br/>`Compactu32` end <br/>`OptionMultiSigner` verifier <br/> |
|Contribute | :heavy_check_mark:  | :heavy_check_mark: |   | `Compactu32` index <br/>`Compactu128` amount <br/>`OptionMultiSignature` signature <br/> |
|Withdraw | :heavy_check_mark:  | :heavy_check_mark: |   | `AccountId` who <br/>`Compactu32` index <br/> |
|Refund | :heavy_check_mark:  | :heavy_check_mark: |   | `Compactu32` index <br/> |
|Dissolve | :heavy_check_mark:  | :heavy_check_mark: |   | `Compactu32` index <br/> |
|Edit | :heavy_check_mark:  | :heavy_check_mark: |   | `Compactu32` index <br/>`Compactu128` cap <br/>`Compactu32` first_period <br/>`Compactu32` last_period <br/>`Compactu32` end <br/>`OptionMultiSigner` verifier <br/> |
|Add memo | :heavy_check_mark:  | :heavy_check_mark: |   | `ParaId` index <br/>`Vecu8` memo <br/> |
|Poke | :heavy_check_mark:  | :heavy_check_mark: |   | `ParaId` index <br/> |
|Contribute all | :heavy_check_mark:  | :heavy_check_mark: |   | `Compactu32` index <br/>`OptionMultiSignature` signature <br/> |

## XcmPallet

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Send |    |   |   | `BoxVersionedMultiLocation` dest <br/>`BoxVersionedXcmTuple` message <br/> |
|Teleport assets |    |   |   | `BoxVersionedMultiLocation` dest <br/>`BoxVersionedMultiLocation` beneficiary <br/>`BoxVersionedMultiAssets` assets <br/>`u32` fee_asset_item <br/> |
|Reserve transfer assets |    |   |   | `BoxVersionedMultiLocation` dest <br/>`BoxVersionedMultiLocation` beneficiary <br/>`BoxVersionedMultiAssets` assets <br/>`u32` fee_asset_item <br/> |
|Execute |    |   |   | `BoxVersionedXcmTasSysConfigCall` message <br/>`Weight` max_weight <br/> |
|Force xcm version |    |   |   | `BoxMultiLocation` location <br/>`XcmVersion` xcm_version <br/> |
|Force default xcm version |    |   |   | `OptionXcmVersion` maybe_xcm_version <br/> |
|Force subscribe version notify |    |   |   | `BoxVersionedMultiLocation` location <br/> |
|Force unsubscribe version notify |    |   |   | `BoxVersionedMultiLocation` location <br/> |
|Limited reserve transfer assets |    |   |   | `BoxVersionedMultiLocation` dest <br/>`BoxVersionedMultiLocation` beneficiary <br/>`BoxVersionedMultiAssets` assets <br/>`u32` fee_asset_item <br/>`WeightLimit` weight_limit <br/> |
|Limited teleport assets |    |   |   | `BoxVersionedMultiLocation` dest <br/>`BoxVersionedMultiLocation` beneficiary <br/>`BoxVersionedMultiAssets` assets <br/>`u32` fee_asset_item <br/>`WeightLimit` weight_limit <br/> |

