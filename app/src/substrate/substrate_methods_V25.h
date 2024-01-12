/*******************************************************************************
 *  (c) 2019 - 2024 Zondax AG
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 ********************************************************************************/
#pragma once

#ifdef __cplusplus
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wextern-c-compat"

extern "C" {
#endif

#include "substrate_types.h"
#include "substrate_types_V25.h"
#include <stddef.h>
#include <stdint.h>
#ifdef LEDGER_SPECIFIC
#include "bolos_target.h"
#endif

#define PD_CALL_SYSTEM_V25 0
#define PD_CALL_PREIMAGE_V25 10
#define PD_CALL_TIMESTAMP_V25 3
#define PD_CALL_INDICES_V25 4
#define PD_CALL_BALANCES_V25 5
#define PD_CALL_STAKING_V25 7
#define PD_CALL_SESSION_V25 9
#define PD_CALL_TREASURY_V25 19
#define PD_CALL_CONVICTIONVOTING_V25 20
#define PD_CALL_REFERENDA_V25 21
#define PD_CALL_WHITELIST_V25 23
#define PD_CALL_CLAIMS_V25 24
#define PD_CALL_VESTING_V25 25
#define PD_CALL_UTILITY_V25 26
#define PD_CALL_IDENTITY_V25 28
#define PD_CALL_PROXY_V25 29
#define PD_CALL_MULTISIG_V25 30
#define PD_CALL_BOUNTIES_V25 34
#define PD_CALL_CHILDBOUNTIES_V25 38
#define PD_CALL_VOTERLIST_V25 37
#define PD_CALL_NOMINATIONPOOLS_V25 39
#define PD_CALL_FASTUNSTAKE_V25 40
#define PD_CALL_CONFIGURATION_V25 51
#define PD_CALL_INITIALIZER_V25 57
#define PD_CALL_PARASDISPUTES_V25 62
#define PD_CALL_AUCTIONS_V25 72
#define PD_CALL_CROWDLOAN_V25 73
#define PD_CALL_XCMPALLET_V25 99

#define PD_CALL_UTILITY_BATCH_V25 0
typedef struct {
    pd_VecCall_t calls;
} pd_utility_batch_V25_t;

#define PD_CALL_UTILITY_BATCH_ALL_V25 2
typedef struct {
    pd_VecCall_t calls;
} pd_utility_batch_all_V25_t;

#define PD_CALL_UTILITY_FORCE_BATCH_V25 4
typedef struct {
    pd_VecCall_t calls;
} pd_utility_force_batch_V25_t;

#define PD_CALL_CROWDLOAN_CREATE_V25 0
typedef struct {
    pd_Compactu32_t index;
    pd_Compactu128_t cap;
    pd_Compactu32_t first_period;
    pd_Compactu32_t last_period;
    pd_Compactu32_t end;
    pd_OptionMultiSigner_t verifier;
} pd_crowdloan_create_V25_t;

#define PD_CALL_CROWDLOAN_CONTRIBUTE_V25 1
typedef struct {
    pd_Compactu32_t index;
    pd_Compactu128_t amount;
    pd_OptionMultiSignature_t signature;
} pd_crowdloan_contribute_V25_t;

#define PD_CALL_CROWDLOAN_WITHDRAW_V25 2
typedef struct {
    pd_AccountId_t who;
    pd_Compactu32_t index;
} pd_crowdloan_withdraw_V25_t;

#define PD_CALL_CROWDLOAN_REFUND_V25 3
typedef struct {
    pd_Compactu32_t index;
} pd_crowdloan_refund_V25_t;

#define PD_CALL_CROWDLOAN_DISSOLVE_V25 4
typedef struct {
    pd_Compactu32_t index;
} pd_crowdloan_dissolve_V25_t;

#define PD_CALL_CROWDLOAN_EDIT_V25 5
typedef struct {
    pd_Compactu32_t index;
    pd_Compactu128_t cap;
    pd_Compactu32_t first_period;
    pd_Compactu32_t last_period;
    pd_Compactu32_t end;
    pd_OptionMultiSigner_t verifier;
} pd_crowdloan_edit_V25_t;

#define PD_CALL_CROWDLOAN_ADD_MEMO_V25 6
typedef struct {
    pd_ParaId_t index;
    pd_Vecu8_t memo;
} pd_crowdloan_add_memo_V25_t;

#define PD_CALL_CROWDLOAN_POKE_V25 7
typedef struct {
    pd_ParaId_t index;
} pd_crowdloan_poke_V25_t;

#define PD_CALL_CROWDLOAN_CONTRIBUTE_ALL_V25 8
typedef struct {
    pd_Compactu32_t index;
    pd_OptionMultiSignature_t signature;
} pd_crowdloan_contribute_all_V25_t;

#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
#define PD_CALL_XCMPALLET_TELEPORT_ASSETS_V25 1
typedef struct {
    pd_BoxVersionedMultiLocation_t dest;
    pd_BoxVersionedMultiLocation_t beneficiary;
    pd_BoxVersionedMultiAssets_t assets;
    pd_u32_t fee_asset_item;
} pd_xcmpallet_teleport_assets_V25_t;
#define PD_CALL_XCMPALLET_RESERVE_TRANSFER_ASSETS_V25 2
typedef struct {
    pd_BoxVersionedMultiLocation_t dest;
    pd_BoxVersionedMultiLocation_t beneficiary;
    pd_BoxVersionedMultiAssets_t assets;
    pd_u32_t fee_asset_item;
} pd_xcmpallet_reserve_transfer_assets_V25_t;
#define PD_CALL_XCMPALLET_LIMITED_RESERVE_TRANSFER_ASSETS_V25 8
typedef struct {
    pd_BoxVersionedMultiLocation_t dest;
    pd_BoxVersionedMultiLocation_t beneficiary;
    pd_BoxVersionedMultiAssets_t assets;
    pd_u32_t fee_asset_item;
    pd_WeightLimit_t weight_limit;
} pd_xcmpallet_limited_reserve_transfer_assets_V25_t;
#define PD_CALL_XCMPALLET_LIMITED_TELEPORT_ASSETS_V25 9
typedef struct {
    pd_BoxVersionedMultiLocation_t dest;
    pd_BoxVersionedMultiLocation_t beneficiary;
    pd_BoxVersionedMultiAssets_t assets;
    pd_u32_t fee_asset_item;
    pd_WeightLimit_t weight_limit;
} pd_xcmpallet_limited_teleport_assets_V25_t;
#endif

#define PD_CALL_PREIMAGE_NOTE_PREIMAGE_V25 0
typedef struct {
    pd_Vecu8_t bytes;
} pd_preimage_note_preimage_V25_t;

#define PD_CALL_PREIMAGE_UNNOTE_PREIMAGE_V25 1
typedef struct {
    pd_Hash_t hash;
} pd_preimage_unnote_preimage_V25_t;

#define PD_CALL_PREIMAGE_REQUEST_PREIMAGE_V25 2
typedef struct {
    pd_Hash_t hash;
} pd_preimage_request_preimage_V25_t;

#define PD_CALL_PREIMAGE_UNREQUEST_PREIMAGE_V25 3
typedef struct {
    pd_Hash_t hash;
} pd_preimage_unrequest_preimage_V25_t;

#define PD_CALL_PREIMAGE_ENSURE_UPDATED_V25 4
typedef struct {
    pd_VecHash_t hashes;
} pd_preimage_ensure_updated_V25_t;

#define PD_CALL_TIMESTAMP_SET_V25 0
typedef struct {
    pd_Compactu64_t now;
} pd_timestamp_set_V25_t;

#define PD_CALL_INDICES_CLAIM_V25 0
typedef struct {
    pd_AccountIndex_t index;
} pd_indices_claim_V25_t;

#define PD_CALL_INDICES_TRANSFER_V25 1
typedef struct {
    pd_AccountIdLookupOfT_t new_;
    pd_AccountIndex_t index;
} pd_indices_transfer_V25_t;

#define PD_CALL_INDICES_FREE_V25 2
typedef struct {
    pd_AccountIndex_t index;
} pd_indices_free_V25_t;

#define PD_CALL_INDICES_FORCE_TRANSFER_V25 3
typedef struct {
    pd_AccountIdLookupOfT_t new_;
    pd_AccountIndex_t index;
    pd_bool_t freeze;
} pd_indices_force_transfer_V25_t;

#define PD_CALL_INDICES_FREEZE_V25 4
typedef struct {
    pd_AccountIndex_t index;
} pd_indices_freeze_V25_t;

#define PD_CALL_BALANCES_FORCE_UNRESERVE_V25 5
typedef struct {
    pd_AccountIdLookupOfT_t who;
    pd_Balance_t amount;
} pd_balances_force_unreserve_V25_t;

#define PD_CALL_BALANCES_UPGRADE_ACCOUNTS_V25 6
typedef struct {
    pd_VecAccountId_t who;
} pd_balances_upgrade_accounts_V25_t;

#define PD_CALL_BALANCES_FORCE_SET_BALANCE_V25 8
typedef struct {
    pd_AccountIdLookupOfT_t who;
    pd_CompactBalance_t new_free;
} pd_balances_force_set_balance_V25_t;

#define PD_CALL_STAKING_SET_VALIDATOR_COUNT_V25 9
typedef struct {
    pd_Compactu32_t new_;
} pd_staking_set_validator_count_V25_t;

#define PD_CALL_STAKING_INCREASE_VALIDATOR_COUNT_V25 10
typedef struct {
    pd_Compactu32_t additional;
} pd_staking_increase_validator_count_V25_t;

#define PD_CALL_STAKING_SCALE_VALIDATOR_COUNT_V25 11
typedef struct {
    pd_Percent_t factor;
} pd_staking_scale_validator_count_V25_t;

#define PD_CALL_STAKING_FORCE_NO_ERAS_V25 12
typedef struct {
} pd_staking_force_no_eras_V25_t;

#define PD_CALL_STAKING_FORCE_NEW_ERA_V25 13
typedef struct {
} pd_staking_force_new_era_V25_t;

#define PD_CALL_STAKING_SET_INVULNERABLES_V25 14
typedef struct {
    pd_VecAccountId_t invulnerables;
} pd_staking_set_invulnerables_V25_t;

#define PD_CALL_STAKING_FORCE_UNSTAKE_V25 15
typedef struct {
    pd_AccountId_t stash;
    pd_u32_t num_slashing_spans;
} pd_staking_force_unstake_V25_t;

#define PD_CALL_STAKING_FORCE_NEW_ERA_ALWAYS_V25 16
typedef struct {
} pd_staking_force_new_era_always_V25_t;

#define PD_CALL_STAKING_CANCEL_DEFERRED_SLASH_V25 17
typedef struct {
    pd_EraIndex_t era;
    pd_Vecu32_t slash_indices;
} pd_staking_cancel_deferred_slash_V25_t;

#define PD_CALL_STAKING_REAP_STASH_V25 20
typedef struct {
    pd_AccountId_t stash;
    pd_u32_t num_slashing_spans;
} pd_staking_reap_stash_V25_t;

#define PD_CALL_STAKING_KICK_V25 21
typedef struct {
    pd_VecAccountIdLookupOfT_t who;
} pd_staking_kick_V25_t;

#define PD_CALL_STAKING_SET_STAKING_CONFIGS_V25 22
typedef struct {
    pd_ConfigOpBalanceOfT_t min_nominator_bond;
    pd_ConfigOpBalanceOfT_t min_validator_bond;
    pd_ConfigOpu32_t max_nominator_count;
    pd_ConfigOpu32_t max_validator_count;
    pd_ConfigOpPercent_t chill_threshold;
    pd_ConfigOpPerbill_t min_commission;
} pd_staking_set_staking_configs_V25_t;

#define PD_CALL_STAKING_CHILL_OTHER_V25 23
typedef struct {
    pd_AccountId_t controller;
} pd_staking_chill_other_V25_t;

#define PD_CALL_STAKING_FORCE_APPLY_MIN_COMMISSION_V25 24
typedef struct {
    pd_AccountId_t validator_stash;
} pd_staking_force_apply_min_commission_V25_t;

#define PD_CALL_STAKING_SET_MIN_COMMISSION_V25 25
typedef struct {
    pd_Perbill_t new_;
} pd_staking_set_min_commission_V25_t;

#define PD_CALL_TREASURY_PROPOSE_SPEND_V25 0
typedef struct {
    pd_CompactBalance_t amount;
    pd_AccountIdLookupOfT_t beneficiary;
} pd_treasury_propose_spend_V25_t;

#define PD_CALL_TREASURY_REJECT_PROPOSAL_V25 1
typedef struct {
    pd_Compactu32_t proposal_id;
} pd_treasury_reject_proposal_V25_t;

#define PD_CALL_TREASURY_APPROVE_PROPOSAL_V25 2
typedef struct {
    pd_Compactu32_t proposal_id;
} pd_treasury_approve_proposal_V25_t;

#define PD_CALL_TREASURY_SPEND_LOCAL_V25 3
typedef struct {
    pd_CompactBalance_t amount;
    pd_AccountIdLookupOfT_t beneficiary;
} pd_treasury_spend_local_V25_t;

#define PD_CALL_TREASURY_REMOVE_APPROVAL_V25 4
typedef struct {
    pd_Compactu32_t proposal_id;
} pd_treasury_remove_approval_V25_t;

#define PD_CALL_TREASURY_PAYOUT_V25 6
typedef struct {
    pd_SpendIndex_t index;
} pd_treasury_payout_V25_t;

#define PD_CALL_TREASURY_CHECK_STATUS_V25 7
typedef struct {
    pd_SpendIndex_t index;
} pd_treasury_check_status_V25_t;

#define PD_CALL_TREASURY_VOID_SPEND_V25 8
typedef struct {
    pd_SpendIndex_t index;
} pd_treasury_void_spend_V25_t;

#define PD_CALL_REFERENDA_SUBMIT_V25 0
typedef struct {
    pd_BoxPalletsOrigin_t proposal_origin;
    pd_BoundedCallOfT_t proposal;
    pd_DispatchTimeBlockNumber_t enactment_moment;
} pd_referenda_submit_V25_t;

#define PD_CALL_REFERENDA_PLACE_DECISION_DEPOSIT_V25 1
typedef struct {
    pd_ReferendumIndex_t index;
} pd_referenda_place_decision_deposit_V25_t;

#define PD_CALL_REFERENDA_REFUND_DECISION_DEPOSIT_V25 2
typedef struct {
    pd_ReferendumIndex_t index;
} pd_referenda_refund_decision_deposit_V25_t;

#define PD_CALL_REFERENDA_CANCEL_V25 3
typedef struct {
    pd_ReferendumIndex_t index;
} pd_referenda_cancel_V25_t;

#define PD_CALL_REFERENDA_KILL_V25 4
typedef struct {
    pd_ReferendumIndex_t index;
} pd_referenda_kill_V25_t;

#define PD_CALL_REFERENDA_NUDGE_REFERENDUM_V25 5
typedef struct {
    pd_ReferendumIndex_t index;
} pd_referenda_nudge_referendum_V25_t;

#define PD_CALL_REFERENDA_ONE_FEWER_DECIDING_V25 6
typedef struct {
    pd_TrackIdOf_t track;
} pd_referenda_one_fewer_deciding_V25_t;

#define PD_CALL_REFERENDA_REFUND_SUBMISSION_DEPOSIT_V25 7
typedef struct {
    pd_ReferendumIndex_t index;
} pd_referenda_refund_submission_deposit_V25_t;

#define PD_CALL_REFERENDA_SET_METADATA_V25 8
typedef struct {
    pd_ReferendumIndex_t index;
    pd_OptionHash_t maybe_hash;
} pd_referenda_set_metadata_V25_t;

#define PD_CALL_WHITELIST_WHITELIST_CALL_V25 0
typedef struct {
    pd_Hash_t call_hash;
} pd_whitelist_whitelist_call_V25_t;

#define PD_CALL_WHITELIST_REMOVE_WHITELISTED_CALL_V25 1
typedef struct {
    pd_Hash_t call_hash;
} pd_whitelist_remove_whitelisted_call_V25_t;

#define PD_CALL_WHITELIST_DISPATCH_WHITELISTED_CALL_V25 2
typedef struct {
    pd_Hash_t call_hash;
    pd_u32_t call_encoded_len;
    pd_Weight_t call_weight_witness;
} pd_whitelist_dispatch_whitelisted_call_V25_t;

#define PD_CALL_WHITELIST_DISPATCH_WHITELISTED_CALL_WITH_PREIMAGE_V25 3
typedef struct {
    pd_Call_t call;
} pd_whitelist_dispatch_whitelisted_call_with_preimage_V25_t;

#define PD_CALL_CLAIMS_CLAIM_V25 0
typedef struct {
    pd_AccountId_t dest;
    pd_EcdsaSignature_t ethereum_signature;
} pd_claims_claim_V25_t;

#define PD_CALL_CLAIMS_CLAIM_ATTEST_V25 2
typedef struct {
    pd_AccountId_t dest;
    pd_EcdsaSignature_t ethereum_signature;
    pd_Bytes_t statement;
} pd_claims_claim_attest_V25_t;

#define PD_CALL_CLAIMS_ATTEST_V25 3
typedef struct {
    pd_Bytes_t statement;
} pd_claims_attest_V25_t;

#define PD_CALL_CLAIMS_MOVE_CLAIM_V25 4
typedef struct {
    pd_EthereumAddress_t old;
    pd_EthereumAddress_t new_;
    pd_OptionAccountId_t maybe_preclaim;
} pd_claims_move_claim_V25_t;

#define PD_CALL_VESTING_VEST_V25 0
typedef struct {
} pd_vesting_vest_V25_t;

#define PD_CALL_VESTING_VEST_OTHER_V25 1
typedef struct {
    pd_AccountIdLookupOfT_t target;
} pd_vesting_vest_other_V25_t;

#define PD_CALL_VESTING_VESTED_TRANSFER_V25 2
typedef struct {
    pd_AccountIdLookupOfT_t target;
    pd_VestingInfo_t schedule;
} pd_vesting_vested_transfer_V25_t;

#define PD_CALL_VESTING_FORCE_VESTED_TRANSFER_V25 3
typedef struct {
    pd_AccountIdLookupOfT_t source;
    pd_AccountIdLookupOfT_t target;
    pd_VestingInfo_t schedule;
} pd_vesting_force_vested_transfer_V25_t;

#define PD_CALL_VESTING_MERGE_SCHEDULES_V25 4
typedef struct {
    pd_u32_t schedule1_index;
    pd_u32_t schedule2_index;
} pd_vesting_merge_schedules_V25_t;

#define PD_CALL_UTILITY_DISPATCH_AS_V25 3
typedef struct {
    pd_BoxPalletsOrigin_t as_origin;
    pd_Call_t call;
} pd_utility_dispatch_as_V25_t;

#define PD_CALL_UTILITY_WITH_WEIGHT_V25 5
typedef struct {
    pd_Call_t call;
    pd_Weight_t weight;
} pd_utility_with_weight_V25_t;

#define PD_CALL_IDENTITY_ADD_REGISTRAR_V25 0
typedef struct {
    pd_AccountIdLookupOfT_t account;
} pd_identity_add_registrar_V25_t;

#define PD_CALL_IDENTITY_SET_IDENTITY_V25 1
typedef struct {
    pd_IdentityInfo_t info;
} pd_identity_set_identity_V25_t;

#define PD_CALL_IDENTITY_SET_SUBS_V25 2
typedef struct {
    pd_VecTupleAccountIdData_t subs;
} pd_identity_set_subs_V25_t;

#define PD_CALL_IDENTITY_CLEAR_IDENTITY_V25 3
typedef struct {
} pd_identity_clear_identity_V25_t;

#define PD_CALL_IDENTITY_REQUEST_JUDGEMENT_V25 4
typedef struct {
    pd_Compactu32_t reg_index;
    pd_Compactu128_t max_fee;
} pd_identity_request_judgement_V25_t;

#define PD_CALL_IDENTITY_CANCEL_REQUEST_V25 5
typedef struct {
    pd_RegistrarIndex_t reg_index;
} pd_identity_cancel_request_V25_t;

#define PD_CALL_IDENTITY_SET_FEE_V25 6
typedef struct {
    pd_Compactu32_t index;
    pd_Compactu128_t fee;
} pd_identity_set_fee_V25_t;

#define PD_CALL_IDENTITY_SET_ACCOUNT_ID_V25 7
typedef struct {
    pd_Compactu32_t index;
    pd_AccountIdLookupOfT_t new_;
} pd_identity_set_account_id_V25_t;

#define PD_CALL_IDENTITY_PROVIDE_JUDGEMENT_V25 9
typedef struct {
    pd_Compactu32_t reg_index;
    pd_AccountIdLookupOfT_t target;
    pd_JudgementBalanceOfT_t judgement;
    pd_Hash_t identity;
} pd_identity_provide_judgement_V25_t;

#define PD_CALL_IDENTITY_KILL_IDENTITY_V25 10
typedef struct {
    pd_AccountIdLookupOfT_t target;
} pd_identity_kill_identity_V25_t;

#define PD_CALL_IDENTITY_ADD_SUB_V25 11
typedef struct {
    pd_AccountIdLookupOfT_t sub;
    pd_Data_t data;
} pd_identity_add_sub_V25_t;

#define PD_CALL_IDENTITY_RENAME_SUB_V25 12
typedef struct {
    pd_AccountIdLookupOfT_t sub;
    pd_Data_t data;
} pd_identity_rename_sub_V25_t;

#define PD_CALL_IDENTITY_REMOVE_SUB_V25 13
typedef struct {
    pd_AccountIdLookupOfT_t sub;
} pd_identity_remove_sub_V25_t;

#define PD_CALL_IDENTITY_QUIT_SUB_V25 14
typedef struct {
} pd_identity_quit_sub_V25_t;

#define PD_CALL_PROXY_REMOVE_PROXIES_V25 3
typedef struct {
} pd_proxy_remove_proxies_V25_t;

#define PD_CALL_PROXY_PROXY_ANNOUNCED_V25 9
typedef struct {
    pd_AccountIdLookupOfT_t delegate;
    pd_AccountIdLookupOfT_t real;
    pd_OptionProxyType_t force_proxy_type;
    pd_Call_t call;
} pd_proxy_proxy_announced_V25_t;

#define PD_CALL_BOUNTIES_PROPOSE_BOUNTY_V25 0
typedef struct {
    pd_CompactBalance_t amount;
    pd_Bytes_t description;
} pd_bounties_propose_bounty_V25_t;

#define PD_CALL_BOUNTIES_APPROVE_BOUNTY_V25 1
typedef struct {
    pd_Compactu32_t bounty_id;
} pd_bounties_approve_bounty_V25_t;

#define PD_CALL_BOUNTIES_PROPOSE_CURATOR_V25 2
typedef struct {
    pd_Compactu32_t bounty_id;
    pd_AccountIdLookupOfT_t curator;
    pd_CompactBalance_t fee;
} pd_bounties_propose_curator_V25_t;

#define PD_CALL_BOUNTIES_UNASSIGN_CURATOR_V25 3
typedef struct {
    pd_Compactu32_t bounty_id;
} pd_bounties_unassign_curator_V25_t;

#define PD_CALL_BOUNTIES_ACCEPT_CURATOR_V25 4
typedef struct {
    pd_Compactu32_t bounty_id;
} pd_bounties_accept_curator_V25_t;

#define PD_CALL_BOUNTIES_AWARD_BOUNTY_V25 5
typedef struct {
    pd_Compactu32_t bounty_id;
    pd_AccountIdLookupOfT_t beneficiary;
} pd_bounties_award_bounty_V25_t;

#define PD_CALL_BOUNTIES_CLAIM_BOUNTY_V25 6
typedef struct {
    pd_Compactu32_t bounty_id;
} pd_bounties_claim_bounty_V25_t;

#define PD_CALL_BOUNTIES_CLOSE_BOUNTY_V25 7
typedef struct {
    pd_Compactu32_t bounty_id;
} pd_bounties_close_bounty_V25_t;

#define PD_CALL_BOUNTIES_EXTEND_BOUNTY_EXPIRY_V25 8
typedef struct {
    pd_Compactu32_t bounty_id;
    pd_Bytes_t remark;
} pd_bounties_extend_bounty_expiry_V25_t;

#define PD_CALL_CHILDBOUNTIES_ADD_CHILD_BOUNTY_V25 0
typedef struct {
    pd_Compactu32_t parent_bounty_id;
    pd_CompactBalance_t amount;
    pd_Vecu8_t description;
} pd_childbounties_add_child_bounty_V25_t;

#define PD_CALL_CHILDBOUNTIES_PROPOSE_CURATOR_V25 1
typedef struct {
    pd_Compactu32_t parent_bounty_id;
    pd_Compactu32_t child_bounty_id;
    pd_AccountIdLookupOfT_t curator;
    pd_CompactBalance_t fee;
} pd_childbounties_propose_curator_V25_t;

#define PD_CALL_CHILDBOUNTIES_ACCEPT_CURATOR_V25 2
typedef struct {
    pd_Compactu32_t parent_bounty_id;
    pd_Compactu32_t child_bounty_id;
} pd_childbounties_accept_curator_V25_t;

#define PD_CALL_CHILDBOUNTIES_UNASSIGN_CURATOR_V25 3
typedef struct {
    pd_Compactu32_t parent_bounty_id;
    pd_Compactu32_t child_bounty_id;
} pd_childbounties_unassign_curator_V25_t;

#define PD_CALL_CHILDBOUNTIES_AWARD_CHILD_BOUNTY_V25 4
typedef struct {
    pd_Compactu32_t parent_bounty_id;
    pd_Compactu32_t child_bounty_id;
    pd_AccountIdLookupOfT_t beneficiary;
} pd_childbounties_award_child_bounty_V25_t;

#define PD_CALL_CHILDBOUNTIES_CLAIM_CHILD_BOUNTY_V25 5
typedef struct {
    pd_Compactu32_t parent_bounty_id;
    pd_Compactu32_t child_bounty_id;
} pd_childbounties_claim_child_bounty_V25_t;

#define PD_CALL_CHILDBOUNTIES_CLOSE_CHILD_BOUNTY_V25 6
typedef struct {
    pd_Compactu32_t parent_bounty_id;
    pd_Compactu32_t child_bounty_id;
} pd_childbounties_close_child_bounty_V25_t;

#define PD_CALL_VOTERLIST_REBAG_V25 0
typedef struct {
    pd_AccountIdLookupOfT_t dislocated;
} pd_voterlist_rebag_V25_t;

#define PD_CALL_VOTERLIST_PUT_IN_FRONT_OF_V25 1
typedef struct {
    pd_AccountIdLookupOfT_t lighter;
} pd_voterlist_put_in_front_of_V25_t;

#define PD_CALL_VOTERLIST_PUT_IN_FRONT_OF_OTHER_V25 2
typedef struct {
    pd_AccountIdLookupOfT_t heavier;
    pd_AccountIdLookupOfT_t lighter;
} pd_voterlist_put_in_front_of_other_V25_t;

#define PD_CALL_NOMINATIONPOOLS_POOL_WITHDRAW_UNBONDED_V25 4
typedef struct {
    pd_PoolId_t pool_id;
    pd_u32_t num_slashing_spans;
} pd_nominationpools_pool_withdraw_unbonded_V25_t;

#define PD_CALL_NOMINATIONPOOLS_CREATE_WITH_POOL_ID_V25 7
typedef struct {
    pd_CompactBalance_t amount;
    pd_AccountIdLookupOfT_t root;
    pd_AccountIdLookupOfT_t nominator;
    pd_AccountIdLookupOfT_t bouncer;
    pd_PoolId_t pool_id;
} pd_nominationpools_create_with_pool_id_V25_t;

#define PD_CALL_NOMINATIONPOOLS_SET_CONFIGS_V25 11
typedef struct {
    pd_ConfigOpBalanceOfT_t min_join_bond;
    pd_ConfigOpBalanceOfT_t min_create_bond;
    pd_ConfigOpu32_t max_pools;
    pd_ConfigOpu32_t max_members;
    pd_ConfigOpu32_t max_members_per_pool;
    pd_ConfigOpPerbill_t global_max_commission;
} pd_nominationpools_set_configs_V25_t;

#define PD_CALL_NOMINATIONPOOLS_BOND_EXTRA_OTHER_V25 14
typedef struct {
    pd_AccountIdLookupOfT_t member;
    pd_BondExtraBalanceOfT_t extra;
} pd_nominationpools_bond_extra_other_V25_t;

#define PD_CALL_NOMINATIONPOOLS_ADJUST_POOL_DEPOSIT_V25 21
typedef struct {
    pd_PoolId_t pool_id;
} pd_nominationpools_adjust_pool_deposit_V25_t;

#define PD_CALL_FASTUNSTAKE_CONTROL_V25 2
typedef struct {
    pd_EraIndex_t eras_to_check;
} pd_fastunstake_control_V25_t;

#define PD_CALL_CONFIGURATION_SET_VALIDATION_UPGRADE_COOLDOWN_V25 0
typedef struct {
    pd_BlockNumber_t new_;
} pd_configuration_set_validation_upgrade_cooldown_V25_t;

#define PD_CALL_CONFIGURATION_SET_VALIDATION_UPGRADE_DELAY_V25 1
typedef struct {
    pd_BlockNumber_t new_;
} pd_configuration_set_validation_upgrade_delay_V25_t;

#define PD_CALL_CONFIGURATION_SET_CODE_RETENTION_PERIOD_V25 2
typedef struct {
    pd_BlockNumber_t new_;
} pd_configuration_set_code_retention_period_V25_t;

#define PD_CALL_CONFIGURATION_SET_MAX_CODE_SIZE_V25 3
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_max_code_size_V25_t;

#define PD_CALL_CONFIGURATION_SET_MAX_POV_SIZE_V25 4
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_max_pov_size_V25_t;

#define PD_CALL_CONFIGURATION_SET_MAX_HEAD_DATA_SIZE_V25 5
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_max_head_data_size_V25_t;

#define PD_CALL_CONFIGURATION_SET_ON_DEMAND_CORES_V25 6
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_on_demand_cores_V25_t;

#define PD_CALL_CONFIGURATION_SET_ON_DEMAND_RETRIES_V25 7
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_on_demand_retries_V25_t;

#define PD_CALL_CONFIGURATION_SET_GROUP_ROTATION_FREQUENCY_V25 8
typedef struct {
    pd_BlockNumber_t new_;
} pd_configuration_set_group_rotation_frequency_V25_t;

#define PD_CALL_CONFIGURATION_SET_PARAS_AVAILABILITY_PERIOD_V25 9
typedef struct {
    pd_BlockNumber_t new_;
} pd_configuration_set_paras_availability_period_V25_t;

#define PD_CALL_CONFIGURATION_SET_SCHEDULING_LOOKAHEAD_V25 11
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_scheduling_lookahead_V25_t;

#define PD_CALL_CONFIGURATION_SET_MAX_VALIDATORS_PER_CORE_V25 12
typedef struct {
    pd_Optionu32_t new_;
} pd_configuration_set_max_validators_per_core_V25_t;

#define PD_CALL_CONFIGURATION_SET_MAX_VALIDATORS_V25 13
typedef struct {
    pd_Optionu32_t new_;
} pd_configuration_set_max_validators_V25_t;

#define PD_CALL_CONFIGURATION_SET_DISPUTE_POST_CONCLUSION_ACCEPTANCE_PERIOD_V25 15
typedef struct {
    pd_BlockNumber_t new_;
} pd_configuration_set_dispute_post_conclusion_acceptance_period_V25_t;

#define PD_CALL_CONFIGURATION_SET_NO_SHOW_SLOTS_V25 18
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_no_show_slots_V25_t;

#define PD_CALL_CONFIGURATION_SET_N_DELAY_TRANCHES_V25 19
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_n_delay_tranches_V25_t;

#define PD_CALL_CONFIGURATION_SET_ZEROTH_DELAY_TRANCHE_WIDTH_V25 20
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_zeroth_delay_tranche_width_V25_t;

#define PD_CALL_CONFIGURATION_SET_NEEDED_APPROVALS_V25 21
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_needed_approvals_V25_t;

#define PD_CALL_CONFIGURATION_SET_RELAY_VRF_MODULO_SAMPLES_V25 22
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_relay_vrf_modulo_samples_V25_t;

#define PD_CALL_CONFIGURATION_SET_MAX_UPWARD_QUEUE_COUNT_V25 23
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_max_upward_queue_count_V25_t;

#define PD_CALL_CONFIGURATION_SET_MAX_UPWARD_QUEUE_SIZE_V25 24
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_max_upward_queue_size_V25_t;

#define PD_CALL_CONFIGURATION_SET_MAX_DOWNWARD_MESSAGE_SIZE_V25 25
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_max_downward_message_size_V25_t;

#define PD_CALL_CONFIGURATION_SET_MAX_UPWARD_MESSAGE_SIZE_V25 27
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_max_upward_message_size_V25_t;

#define PD_CALL_CONFIGURATION_SET_MAX_UPWARD_MESSAGE_NUM_PER_CANDIDATE_V25 28
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_max_upward_message_num_per_candidate_V25_t;

#define PD_CALL_CONFIGURATION_SET_HRMP_OPEN_REQUEST_TTL_V25 29
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_hrmp_open_request_ttl_V25_t;

#define PD_CALL_CONFIGURATION_SET_HRMP_SENDER_DEPOSIT_V25 30
typedef struct {
    pd_Balance_t new_;
} pd_configuration_set_hrmp_sender_deposit_V25_t;

#define PD_CALL_CONFIGURATION_SET_HRMP_RECIPIENT_DEPOSIT_V25 31
typedef struct {
    pd_Balance_t new_;
} pd_configuration_set_hrmp_recipient_deposit_V25_t;

#define PD_CALL_CONFIGURATION_SET_HRMP_CHANNEL_MAX_CAPACITY_V25 32
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_hrmp_channel_max_capacity_V25_t;

#define PD_CALL_CONFIGURATION_SET_HRMP_CHANNEL_MAX_TOTAL_SIZE_V25 33
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_hrmp_channel_max_total_size_V25_t;

#define PD_CALL_CONFIGURATION_SET_HRMP_MAX_PARACHAIN_INBOUND_CHANNELS_V25 34
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_hrmp_max_parachain_inbound_channels_V25_t;

#define PD_CALL_CONFIGURATION_SET_HRMP_CHANNEL_MAX_MESSAGE_SIZE_V25 36
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_hrmp_channel_max_message_size_V25_t;

#define PD_CALL_CONFIGURATION_SET_HRMP_MAX_PARACHAIN_OUTBOUND_CHANNELS_V25 37
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_hrmp_max_parachain_outbound_channels_V25_t;

#define PD_CALL_CONFIGURATION_SET_HRMP_MAX_MESSAGE_NUM_PER_CANDIDATE_V25 39
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_hrmp_max_message_num_per_candidate_V25_t;

#define PD_CALL_CONFIGURATION_SET_PVF_VOTING_TTL_V25 42
typedef struct {
    pd_SessionIndex_t new_;
} pd_configuration_set_pvf_voting_ttl_V25_t;

#define PD_CALL_CONFIGURATION_SET_MINIMUM_VALIDATION_UPGRADE_DELAY_V25 43
typedef struct {
    pd_BlockNumber_t new_;
} pd_configuration_set_minimum_validation_upgrade_delay_V25_t;

#define PD_CALL_CONFIGURATION_SET_BYPASS_CONSISTENCY_CHECK_V25 44
typedef struct {
    pd_bool_t new_;
} pd_configuration_set_bypass_consistency_check_V25_t;

#define PD_CALL_CONFIGURATION_SET_ON_DEMAND_BASE_FEE_V25 47
typedef struct {
    pd_Balance_t new_;
} pd_configuration_set_on_demand_base_fee_V25_t;

#define PD_CALL_CONFIGURATION_SET_ON_DEMAND_FEE_VARIABILITY_V25 48
typedef struct {
    pd_Perbill_t new_;
} pd_configuration_set_on_demand_fee_variability_V25_t;

#define PD_CALL_CONFIGURATION_SET_ON_DEMAND_QUEUE_MAX_SIZE_V25 49
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_on_demand_queue_max_size_V25_t;

#define PD_CALL_CONFIGURATION_SET_ON_DEMAND_TARGET_QUEUE_UTILIZATION_V25 50
typedef struct {
    pd_Perbill_t new_;
} pd_configuration_set_on_demand_target_queue_utilization_V25_t;

#define PD_CALL_CONFIGURATION_SET_ON_DEMAND_TTL_V25 51
typedef struct {
    pd_BlockNumber_t new_;
} pd_configuration_set_on_demand_ttl_V25_t;

#define PD_CALL_CONFIGURATION_SET_MINIMUM_BACKING_VOTES_V25 52
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_minimum_backing_votes_V25_t;

#define PD_CALL_INITIALIZER_FORCE_APPROVE_V25 0
typedef struct {
    pd_BlockNumber_t up_to;
} pd_initializer_force_approve_V25_t;

#define PD_CALL_PARASDISPUTES_FORCE_UNFREEZE_V25 0
typedef struct {
} pd_parasdisputes_force_unfreeze_V25_t;

#define PD_CALL_AUCTIONS_NEW_AUCTION_V25 0
typedef struct {
    pd_Compactu32_t duration;
    pd_Compactu32_t lease_period_index;
} pd_auctions_new_auction_V25_t;

#define PD_CALL_AUCTIONS_BID_V25 1
typedef struct {
    pd_Compactu32_t para;
    pd_Compactu32_t auction_index;
    pd_Compactu32_t first_slot;
    pd_Compactu32_t last_slot;
    pd_CompactBalance_t amount;
} pd_auctions_bid_V25_t;

#define PD_CALL_AUCTIONS_CANCEL_AUCTION_V25 2
typedef struct {
} pd_auctions_cancel_auction_V25_t;

#endif

typedef union {
    pd_utility_batch_V25_t utility_batch_V25;
    pd_utility_batch_all_V25_t utility_batch_all_V25;
    pd_utility_force_batch_V25_t utility_force_batch_V25;
    pd_crowdloan_create_V25_t crowdloan_create_V25;
    pd_crowdloan_contribute_V25_t crowdloan_contribute_V25;
    pd_crowdloan_withdraw_V25_t crowdloan_withdraw_V25;
    pd_crowdloan_refund_V25_t crowdloan_refund_V25;
    pd_crowdloan_dissolve_V25_t crowdloan_dissolve_V25;
    pd_crowdloan_edit_V25_t crowdloan_edit_V25;
    pd_crowdloan_add_memo_V25_t crowdloan_add_memo_V25;
    pd_crowdloan_poke_V25_t crowdloan_poke_V25;
    pd_crowdloan_contribute_all_V25_t crowdloan_contribute_all_V25;
#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
    pd_xcmpallet_teleport_assets_V25_t xcmpallet_teleport_assets_V25;
    pd_xcmpallet_reserve_transfer_assets_V25_t xcmpallet_reserve_transfer_assets_V25;
    pd_xcmpallet_limited_reserve_transfer_assets_V25_t xcmpallet_limited_reserve_transfer_assets_V25;
    pd_xcmpallet_limited_teleport_assets_V25_t xcmpallet_limited_teleport_assets_V25;
#endif
    pd_preimage_note_preimage_V25_t preimage_note_preimage_V25;
    pd_preimage_unnote_preimage_V25_t preimage_unnote_preimage_V25;
    pd_preimage_request_preimage_V25_t preimage_request_preimage_V25;
    pd_preimage_unrequest_preimage_V25_t preimage_unrequest_preimage_V25;
    pd_preimage_ensure_updated_V25_t preimage_ensure_updated_V25;
    pd_timestamp_set_V25_t timestamp_set_V25;
    pd_indices_claim_V25_t indices_claim_V25;
    pd_indices_transfer_V25_t indices_transfer_V25;
    pd_indices_free_V25_t indices_free_V25;
    pd_indices_force_transfer_V25_t indices_force_transfer_V25;
    pd_indices_freeze_V25_t indices_freeze_V25;
    pd_balances_force_unreserve_V25_t balances_force_unreserve_V25;
    pd_balances_upgrade_accounts_V25_t balances_upgrade_accounts_V25;
    pd_balances_force_set_balance_V25_t balances_force_set_balance_V25;
    pd_staking_set_validator_count_V25_t staking_set_validator_count_V25;
    pd_staking_increase_validator_count_V25_t staking_increase_validator_count_V25;
    pd_staking_scale_validator_count_V25_t staking_scale_validator_count_V25;
    pd_staking_force_no_eras_V25_t staking_force_no_eras_V25;
    pd_staking_force_new_era_V25_t staking_force_new_era_V25;
    pd_staking_set_invulnerables_V25_t staking_set_invulnerables_V25;
    pd_staking_force_unstake_V25_t staking_force_unstake_V25;
    pd_staking_force_new_era_always_V25_t staking_force_new_era_always_V25;
    pd_staking_cancel_deferred_slash_V25_t staking_cancel_deferred_slash_V25;
    pd_staking_reap_stash_V25_t staking_reap_stash_V25;
    pd_staking_kick_V25_t staking_kick_V25;
    pd_staking_set_staking_configs_V25_t staking_set_staking_configs_V25;
    pd_staking_chill_other_V25_t staking_chill_other_V25;
    pd_staking_force_apply_min_commission_V25_t staking_force_apply_min_commission_V25;
    pd_staking_set_min_commission_V25_t staking_set_min_commission_V25;
    pd_treasury_propose_spend_V25_t treasury_propose_spend_V25;
    pd_treasury_reject_proposal_V25_t treasury_reject_proposal_V25;
    pd_treasury_approve_proposal_V25_t treasury_approve_proposal_V25;
    pd_treasury_spend_local_V25_t treasury_spend_local_V25;
    pd_treasury_remove_approval_V25_t treasury_remove_approval_V25;
    pd_treasury_payout_V25_t treasury_payout_V25;
    pd_treasury_check_status_V25_t treasury_check_status_V25;
    pd_treasury_void_spend_V25_t treasury_void_spend_V25;
    pd_referenda_submit_V25_t referenda_submit_V25;
    pd_referenda_place_decision_deposit_V25_t referenda_place_decision_deposit_V25;
    pd_referenda_refund_decision_deposit_V25_t referenda_refund_decision_deposit_V25;
    pd_referenda_cancel_V25_t referenda_cancel_V25;
    pd_referenda_kill_V25_t referenda_kill_V25;
    pd_referenda_nudge_referendum_V25_t referenda_nudge_referendum_V25;
    pd_referenda_one_fewer_deciding_V25_t referenda_one_fewer_deciding_V25;
    pd_referenda_refund_submission_deposit_V25_t referenda_refund_submission_deposit_V25;
    pd_referenda_set_metadata_V25_t referenda_set_metadata_V25;
    pd_whitelist_whitelist_call_V25_t whitelist_whitelist_call_V25;
    pd_whitelist_remove_whitelisted_call_V25_t whitelist_remove_whitelisted_call_V25;
    pd_whitelist_dispatch_whitelisted_call_V25_t whitelist_dispatch_whitelisted_call_V25;
    pd_whitelist_dispatch_whitelisted_call_with_preimage_V25_t whitelist_dispatch_whitelisted_call_with_preimage_V25;
    pd_claims_claim_V25_t claims_claim_V25;
    pd_claims_claim_attest_V25_t claims_claim_attest_V25;
    pd_claims_attest_V25_t claims_attest_V25;
    pd_claims_move_claim_V25_t claims_move_claim_V25;
    pd_vesting_vest_V25_t vesting_vest_V25;
    pd_vesting_vest_other_V25_t vesting_vest_other_V25;
    pd_vesting_vested_transfer_V25_t vesting_vested_transfer_V25;
    pd_vesting_force_vested_transfer_V25_t vesting_force_vested_transfer_V25;
    pd_vesting_merge_schedules_V25_t vesting_merge_schedules_V25;
    pd_utility_dispatch_as_V25_t utility_dispatch_as_V25;
    pd_utility_with_weight_V25_t utility_with_weight_V25;
    pd_identity_add_registrar_V25_t identity_add_registrar_V25;
    pd_identity_set_identity_V25_t identity_set_identity_V25;
    pd_identity_set_subs_V25_t identity_set_subs_V25;
    pd_identity_clear_identity_V25_t identity_clear_identity_V25;
    pd_identity_request_judgement_V25_t identity_request_judgement_V25;
    pd_identity_cancel_request_V25_t identity_cancel_request_V25;
    pd_identity_set_fee_V25_t identity_set_fee_V25;
    pd_identity_set_account_id_V25_t identity_set_account_id_V25;
    pd_identity_provide_judgement_V25_t identity_provide_judgement_V25;
    pd_identity_kill_identity_V25_t identity_kill_identity_V25;
    pd_identity_add_sub_V25_t identity_add_sub_V25;
    pd_identity_rename_sub_V25_t identity_rename_sub_V25;
    pd_identity_remove_sub_V25_t identity_remove_sub_V25;
    pd_identity_quit_sub_V25_t identity_quit_sub_V25;
    pd_proxy_remove_proxies_V25_t proxy_remove_proxies_V25;
    pd_proxy_proxy_announced_V25_t proxy_proxy_announced_V25;
    pd_bounties_propose_bounty_V25_t bounties_propose_bounty_V25;
    pd_bounties_approve_bounty_V25_t bounties_approve_bounty_V25;
    pd_bounties_propose_curator_V25_t bounties_propose_curator_V25;
    pd_bounties_unassign_curator_V25_t bounties_unassign_curator_V25;
    pd_bounties_accept_curator_V25_t bounties_accept_curator_V25;
    pd_bounties_award_bounty_V25_t bounties_award_bounty_V25;
    pd_bounties_claim_bounty_V25_t bounties_claim_bounty_V25;
    pd_bounties_close_bounty_V25_t bounties_close_bounty_V25;
    pd_bounties_extend_bounty_expiry_V25_t bounties_extend_bounty_expiry_V25;
    pd_childbounties_add_child_bounty_V25_t childbounties_add_child_bounty_V25;
    pd_childbounties_propose_curator_V25_t childbounties_propose_curator_V25;
    pd_childbounties_accept_curator_V25_t childbounties_accept_curator_V25;
    pd_childbounties_unassign_curator_V25_t childbounties_unassign_curator_V25;
    pd_childbounties_award_child_bounty_V25_t childbounties_award_child_bounty_V25;
    pd_childbounties_claim_child_bounty_V25_t childbounties_claim_child_bounty_V25;
    pd_childbounties_close_child_bounty_V25_t childbounties_close_child_bounty_V25;
    pd_voterlist_rebag_V25_t voterlist_rebag_V25;
    pd_voterlist_put_in_front_of_V25_t voterlist_put_in_front_of_V25;
    pd_voterlist_put_in_front_of_other_V25_t voterlist_put_in_front_of_other_V25;
    pd_nominationpools_pool_withdraw_unbonded_V25_t nominationpools_pool_withdraw_unbonded_V25;
    pd_nominationpools_create_with_pool_id_V25_t nominationpools_create_with_pool_id_V25;
    pd_nominationpools_set_configs_V25_t nominationpools_set_configs_V25;
    pd_nominationpools_bond_extra_other_V25_t nominationpools_bond_extra_other_V25;
    pd_nominationpools_adjust_pool_deposit_V25_t nominationpools_adjust_pool_deposit_V25;
    pd_fastunstake_control_V25_t fastunstake_control_V25;
    pd_configuration_set_validation_upgrade_cooldown_V25_t configuration_set_validation_upgrade_cooldown_V25;
    pd_configuration_set_validation_upgrade_delay_V25_t configuration_set_validation_upgrade_delay_V25;
    pd_configuration_set_code_retention_period_V25_t configuration_set_code_retention_period_V25;
    pd_configuration_set_max_code_size_V25_t configuration_set_max_code_size_V25;
    pd_configuration_set_max_pov_size_V25_t configuration_set_max_pov_size_V25;
    pd_configuration_set_max_head_data_size_V25_t configuration_set_max_head_data_size_V25;
    pd_configuration_set_on_demand_cores_V25_t configuration_set_on_demand_cores_V25;
    pd_configuration_set_on_demand_retries_V25_t configuration_set_on_demand_retries_V25;
    pd_configuration_set_group_rotation_frequency_V25_t configuration_set_group_rotation_frequency_V25;
    pd_configuration_set_paras_availability_period_V25_t configuration_set_paras_availability_period_V25;
    pd_configuration_set_scheduling_lookahead_V25_t configuration_set_scheduling_lookahead_V25;
    pd_configuration_set_max_validators_per_core_V25_t configuration_set_max_validators_per_core_V25;
    pd_configuration_set_max_validators_V25_t configuration_set_max_validators_V25;
    pd_configuration_set_dispute_post_conclusion_acceptance_period_V25_t configuration_set_dispute_post_conclusion_acceptance_period_V25;
    pd_configuration_set_no_show_slots_V25_t configuration_set_no_show_slots_V25;
    pd_configuration_set_n_delay_tranches_V25_t configuration_set_n_delay_tranches_V25;
    pd_configuration_set_zeroth_delay_tranche_width_V25_t configuration_set_zeroth_delay_tranche_width_V25;
    pd_configuration_set_needed_approvals_V25_t configuration_set_needed_approvals_V25;
    pd_configuration_set_relay_vrf_modulo_samples_V25_t configuration_set_relay_vrf_modulo_samples_V25;
    pd_configuration_set_max_upward_queue_count_V25_t configuration_set_max_upward_queue_count_V25;
    pd_configuration_set_max_upward_queue_size_V25_t configuration_set_max_upward_queue_size_V25;
    pd_configuration_set_max_downward_message_size_V25_t configuration_set_max_downward_message_size_V25;
    pd_configuration_set_max_upward_message_size_V25_t configuration_set_max_upward_message_size_V25;
    pd_configuration_set_max_upward_message_num_per_candidate_V25_t configuration_set_max_upward_message_num_per_candidate_V25;
    pd_configuration_set_hrmp_open_request_ttl_V25_t configuration_set_hrmp_open_request_ttl_V25;
    pd_configuration_set_hrmp_sender_deposit_V25_t configuration_set_hrmp_sender_deposit_V25;
    pd_configuration_set_hrmp_recipient_deposit_V25_t configuration_set_hrmp_recipient_deposit_V25;
    pd_configuration_set_hrmp_channel_max_capacity_V25_t configuration_set_hrmp_channel_max_capacity_V25;
    pd_configuration_set_hrmp_channel_max_total_size_V25_t configuration_set_hrmp_channel_max_total_size_V25;
    pd_configuration_set_hrmp_max_parachain_inbound_channels_V25_t configuration_set_hrmp_max_parachain_inbound_channels_V25;
    pd_configuration_set_hrmp_channel_max_message_size_V25_t configuration_set_hrmp_channel_max_message_size_V25;
    pd_configuration_set_hrmp_max_parachain_outbound_channels_V25_t configuration_set_hrmp_max_parachain_outbound_channels_V25;
    pd_configuration_set_hrmp_max_message_num_per_candidate_V25_t configuration_set_hrmp_max_message_num_per_candidate_V25;
    pd_configuration_set_pvf_voting_ttl_V25_t configuration_set_pvf_voting_ttl_V25;
    pd_configuration_set_minimum_validation_upgrade_delay_V25_t configuration_set_minimum_validation_upgrade_delay_V25;
    pd_configuration_set_bypass_consistency_check_V25_t configuration_set_bypass_consistency_check_V25;
    pd_configuration_set_on_demand_base_fee_V25_t configuration_set_on_demand_base_fee_V25;
    pd_configuration_set_on_demand_fee_variability_V25_t configuration_set_on_demand_fee_variability_V25;
    pd_configuration_set_on_demand_queue_max_size_V25_t configuration_set_on_demand_queue_max_size_V25;
    pd_configuration_set_on_demand_target_queue_utilization_V25_t configuration_set_on_demand_target_queue_utilization_V25;
    pd_configuration_set_on_demand_ttl_V25_t configuration_set_on_demand_ttl_V25;
    pd_configuration_set_minimum_backing_votes_V25_t configuration_set_minimum_backing_votes_V25;
    pd_initializer_force_approve_V25_t initializer_force_approve_V25;
    pd_parasdisputes_force_unfreeze_V25_t parasdisputes_force_unfreeze_V25;
    pd_auctions_new_auction_V25_t auctions_new_auction_V25;
    pd_auctions_bid_V25_t auctions_bid_V25;
    pd_auctions_cancel_auction_V25_t auctions_cancel_auction_V25;
#endif
} pd_MethodBasic_V25_t;

#define PD_CALL_BALANCES_TRANSFER_ALLOW_DEATH_V25 0
typedef struct {
    pd_AccountIdLookupOfT_t dest;
    pd_CompactBalance_t amount;
} pd_balances_transfer_allow_death_V25_t;

#define PD_CALL_BALANCES_FORCE_TRANSFER_V25 2
typedef struct {
    pd_AccountIdLookupOfT_t source;
    pd_AccountIdLookupOfT_t dest;
    pd_CompactBalance_t amount;
} pd_balances_force_transfer_V25_t;

#define PD_CALL_BALANCES_TRANSFER_KEEP_ALIVE_V25 3
typedef struct {
    pd_AccountIdLookupOfT_t dest;
    pd_CompactBalance_t amount;
} pd_balances_transfer_keep_alive_V25_t;

#define PD_CALL_BALANCES_TRANSFER_ALL_V25 4
typedef struct {
    pd_AccountIdLookupOfT_t dest;
    pd_bool_t keep_alive;
} pd_balances_transfer_all_V25_t;

#define PD_CALL_STAKING_BOND_V25 0
typedef struct {
    pd_CompactBalance_t amount;
    pd_RewardDestination_t payee;
} pd_staking_bond_V25_t;

#define PD_CALL_STAKING_BOND_EXTRA_V25 1
typedef struct {
    pd_CompactBalance_t amount;
} pd_staking_bond_extra_V25_t;

#define PD_CALL_STAKING_UNBOND_V25 2
typedef struct {
    pd_CompactBalance_t amount;
} pd_staking_unbond_V25_t;

#define PD_CALL_STAKING_WITHDRAW_UNBONDED_V25 3
typedef struct {
    pd_u32_t num_slashing_spans;
} pd_staking_withdraw_unbonded_V25_t;

#define PD_CALL_STAKING_VALIDATE_V25 4
typedef struct {
    pd_ValidatorPrefs_t prefs;
} pd_staking_validate_V25_t;

#define PD_CALL_STAKING_NOMINATE_V25 5
typedef struct {
    pd_VecAccountIdLookupOfT_t targets;
} pd_staking_nominate_V25_t;

#define PD_CALL_STAKING_CHILL_V25 6
typedef struct {
} pd_staking_chill_V25_t;

#define PD_CALL_STAKING_SET_PAYEE_V25 7
typedef struct {
    pd_RewardDestination_t payee;
} pd_staking_set_payee_V25_t;

#define PD_CALL_STAKING_SET_CONTROLLER_V25 8
typedef struct {
} pd_staking_set_controller_V25_t;

#define PD_CALL_STAKING_PAYOUT_STAKERS_V25 18
typedef struct {
    pd_AccountId_t validator_stash;
    pd_EraIndex_t era;
} pd_staking_payout_stakers_V25_t;

#define PD_CALL_STAKING_REBOND_V25 19
typedef struct {
    pd_CompactBalance_t amount;
} pd_staking_rebond_V25_t;

#define PD_CALL_SESSION_SET_KEYS_V25 0
typedef struct {
    pd_Keys_t keys;
    pd_Bytes_t proof;
} pd_session_set_keys_V25_t;

#define PD_CALL_SESSION_PURGE_KEYS_V25 1
typedef struct {
} pd_session_purge_keys_V25_t;

#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
#endif
#define PD_CALL_SYSTEM_REMARK_V25 0
typedef struct {
    pd_Bytes_t remark;
} pd_system_remark_V25_t;

#define PD_CALL_SYSTEM_SET_HEAP_PAGES_V25 1
typedef struct {
    pd_u64_t pages;
} pd_system_set_heap_pages_V25_t;

#define PD_CALL_SYSTEM_SET_CODE_V25 2
typedef struct {
    pd_Vecu8_t code;
} pd_system_set_code_V25_t;

#define PD_CALL_SYSTEM_SET_CODE_WITHOUT_CHECKS_V25 3
typedef struct {
    pd_Vecu8_t code;
} pd_system_set_code_without_checks_V25_t;

#define PD_CALL_SYSTEM_REMARK_WITH_EVENT_V25 7
typedef struct {
    pd_Bytes_t remark;
} pd_system_remark_with_event_V25_t;

#define PD_CALL_CONVICTIONVOTING_VOTE_V25 0
typedef struct {
    pd_Compactu32_t poll_index;
    pd_AccountVote_t vote;
} pd_convictionvoting_vote_V25_t;

#define PD_CALL_CONVICTIONVOTING_DELEGATE_V25 1
typedef struct {
    pd_ClassOf_t class_;
    pd_AccountIdLookupOfT_t to;
    pd_Conviction_t conviction;
    pd_BalanceOf_t balance;
} pd_convictionvoting_delegate_V25_t;

#define PD_CALL_CONVICTIONVOTING_UNDELEGATE_V25 2
typedef struct {
    pd_ClassOf_t class_;
} pd_convictionvoting_undelegate_V25_t;

#define PD_CALL_CONVICTIONVOTING_UNLOCK_V25 3
typedef struct {
    pd_ClassOf_t class_;
    pd_AccountIdLookupOfT_t target;
} pd_convictionvoting_unlock_V25_t;

#define PD_CALL_CONVICTIONVOTING_REMOVE_VOTE_V25 4
typedef struct {
    pd_OptionClassOf_t class_;
    pd_PollIndexOf_t index;
} pd_convictionvoting_remove_vote_V25_t;

#define PD_CALL_CONVICTIONVOTING_REMOVE_OTHER_VOTE_V25 5
typedef struct {
    pd_AccountIdLookupOfT_t target;
    pd_ClassOf_t class_;
    pd_PollIndexOf_t index;
} pd_convictionvoting_remove_other_vote_V25_t;

#define PD_CALL_PROXY_PROXY_V25 0
typedef struct {
    pd_AccountIdLookupOfT_t real;
    pd_OptionProxyType_t force_proxy_type;
    pd_Call_t call;
} pd_proxy_proxy_V25_t;

#define PD_CALL_PROXY_ADD_PROXY_V25 1
typedef struct {
    pd_AccountIdLookupOfT_t delegate;
    pd_ProxyType_t proxy_type;
    pd_BlockNumber_t delay;
} pd_proxy_add_proxy_V25_t;

#define PD_CALL_PROXY_REMOVE_PROXY_V25 2
typedef struct {
    pd_AccountIdLookupOfT_t delegate;
    pd_ProxyType_t proxy_type;
    pd_BlockNumber_t delay;
} pd_proxy_remove_proxy_V25_t;

#define PD_CALL_PROXY_CREATE_PURE_V25 4
typedef struct {
    pd_ProxyType_t proxy_type;
    pd_BlockNumber_t delay;
    pd_u16_t index;
} pd_proxy_create_pure_V25_t;

#define PD_CALL_PROXY_KILL_PURE_V25 5
typedef struct {
    pd_AccountIdLookupOfT_t spawner;
    pd_ProxyType_t proxy_type;
    pd_u16_t index;
    pd_Compactu32_t height;
    pd_Compactu32_t ext_index;
} pd_proxy_kill_pure_V25_t;

#define PD_CALL_MULTISIG_AS_MULTI_THRESHOLD_1_V25 0
typedef struct {
    pd_VecAccountId_t other_signatories;
    pd_Call_t call;
} pd_multisig_as_multi_threshold_1_V25_t;

#define PD_CALL_MULTISIG_AS_MULTI_V25 1
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_t other_signatories;
    pd_OptionTimepoint_t maybe_timepoint;
    pd_Call_t call;
    pd_Weight_t max_weight;
} pd_multisig_as_multi_V25_t;

#define PD_CALL_MULTISIG_APPROVE_AS_MULTI_V25 2
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_t other_signatories;
    pd_OptionTimepoint_t maybe_timepoint;
    pd_H256_t call_hash;
    pd_Weight_t max_weight;
} pd_multisig_approve_as_multi_V25_t;

#define PD_CALL_MULTISIG_CANCEL_AS_MULTI_V25 3
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_t other_signatories;
    pd_Timepoint_t timepoint;
    pd_H256_t call_hash;
} pd_multisig_cancel_as_multi_V25_t;

#define PD_CALL_NOMINATIONPOOLS_JOIN_V25 0
typedef struct {
    pd_CompactBalance_t amount;
    pd_PoolId_t pool_id;
} pd_nominationpools_join_V25_t;

#define PD_CALL_NOMINATIONPOOLS_BOND_EXTRA_V25 1
typedef struct {
    pd_BondExtraBalanceOfT_t extra;
} pd_nominationpools_bond_extra_V25_t;

#define PD_CALL_NOMINATIONPOOLS_CLAIM_PAYOUT_V25 2
typedef struct {
} pd_nominationpools_claim_payout_V25_t;

#define PD_CALL_NOMINATIONPOOLS_UNBOND_V25 3
typedef struct {
    pd_AccountIdLookupOfT_t member_account;
    pd_CompactBalance_t unbonding_points;
} pd_nominationpools_unbond_V25_t;

#define PD_CALL_NOMINATIONPOOLS_WITHDRAW_UNBONDED_V25 5
typedef struct {
    pd_AccountIdLookupOfT_t member_account;
    pd_u32_t num_slashing_spans;
} pd_nominationpools_withdraw_unbonded_V25_t;

#define PD_CALL_NOMINATIONPOOLS_CREATE_V25 6
typedef struct {
    pd_CompactBalance_t amount;
    pd_AccountIdLookupOfT_t root;
    pd_AccountIdLookupOfT_t nominator;
    pd_AccountIdLookupOfT_t bouncer;
} pd_nominationpools_create_V25_t;

#define PD_CALL_NOMINATIONPOOLS_NOMINATE_V25 8
typedef struct {
    pd_PoolId_t pool_id;
    pd_VecAccountId_t validators;
} pd_nominationpools_nominate_V25_t;

#define PD_CALL_NOMINATIONPOOLS_SET_STATE_V25 9
typedef struct {
    pd_PoolId_t pool_id;
    pd_PoolState_t state;
} pd_nominationpools_set_state_V25_t;

#define PD_CALL_NOMINATIONPOOLS_SET_METADATA_V25 10
typedef struct {
    pd_PoolId_t pool_id;
    pd_Vecu8_t metadata;
} pd_nominationpools_set_metadata_V25_t;

#define PD_CALL_NOMINATIONPOOLS_UPDATE_ROLES_V25 12
typedef struct {
    pd_PoolId_t pool_id;
    pd_ConfigOpAccountId_t new_root;
    pd_ConfigOpAccountId_t new_nominator;
    pd_ConfigOpAccountId_t new_bouncer;
} pd_nominationpools_update_roles_V25_t;

#define PD_CALL_NOMINATIONPOOLS_CHILL_V25 13
typedef struct {
    pd_PoolId_t pool_id;
} pd_nominationpools_chill_V25_t;

#define PD_CALL_NOMINATIONPOOLS_SET_CLAIM_PERMISSION_V25 15
typedef struct {
    pd_ClaimPermission_t permission;
} pd_nominationpools_set_claim_permission_V25_t;

#define PD_CALL_NOMINATIONPOOLS_CLAIM_PAYOUT_OTHER_V25 16
typedef struct {
    pd_AccountId_t other;
} pd_nominationpools_claim_payout_other_V25_t;

#define PD_CALL_NOMINATIONPOOLS_SET_COMMISSION_V25 17
typedef struct {
    pd_PoolId_t pool_id;
    pd_OptionTuplePerbillAccountId_t new_commission;
} pd_nominationpools_set_commission_V25_t;

#define PD_CALL_NOMINATIONPOOLS_SET_COMMISSION_MAX_V25 18
typedef struct {
    pd_PoolId_t pool_id;
    pd_Perbill_t max_commission;
} pd_nominationpools_set_commission_max_V25_t;

#define PD_CALL_NOMINATIONPOOLS_SET_COMMISSION_CHANGE_RATE_V25 19
typedef struct {
    pd_PoolId_t pool_id;
    pd_CommissionChangeRateBlockNumber_t change_rate;
} pd_nominationpools_set_commission_change_rate_V25_t;

#define PD_CALL_NOMINATIONPOOLS_CLAIM_COMMISSION_V25 20
typedef struct {
    pd_PoolId_t pool_id;
} pd_nominationpools_claim_commission_V25_t;

#define PD_CALL_FASTUNSTAKE_REGISTER_FAST_UNSTAKE_V25 0
typedef struct {
} pd_fastunstake_register_fast_unstake_V25_t;

#define PD_CALL_FASTUNSTAKE_DEREGISTER_V25 1
typedef struct {
} pd_fastunstake_deregister_V25_t;

#endif

typedef union {
    pd_balances_transfer_allow_death_V25_t balances_transfer_allow_death_V25;
    pd_balances_force_transfer_V25_t balances_force_transfer_V25;
    pd_balances_transfer_keep_alive_V25_t balances_transfer_keep_alive_V25;
    pd_balances_transfer_all_V25_t balances_transfer_all_V25;
    pd_staking_bond_V25_t staking_bond_V25;
    pd_staking_bond_extra_V25_t staking_bond_extra_V25;
    pd_staking_unbond_V25_t staking_unbond_V25;
    pd_staking_withdraw_unbonded_V25_t staking_withdraw_unbonded_V25;
    pd_staking_validate_V25_t staking_validate_V25;
    pd_staking_nominate_V25_t staking_nominate_V25;
    pd_staking_chill_V25_t staking_chill_V25;
    pd_staking_set_payee_V25_t staking_set_payee_V25;
    pd_staking_set_controller_V25_t staking_set_controller_V25;
    pd_staking_payout_stakers_V25_t staking_payout_stakers_V25;
    pd_staking_rebond_V25_t staking_rebond_V25;
    pd_session_set_keys_V25_t session_set_keys_V25;
    pd_session_purge_keys_V25_t session_purge_keys_V25;
#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
#endif
    pd_system_remark_V25_t system_remark_V25;
    pd_system_set_heap_pages_V25_t system_set_heap_pages_V25;
    pd_system_set_code_V25_t system_set_code_V25;
    pd_system_set_code_without_checks_V25_t system_set_code_without_checks_V25;
    pd_system_remark_with_event_V25_t system_remark_with_event_V25;
    pd_convictionvoting_vote_V25_t convictionvoting_vote_V25;
    pd_convictionvoting_delegate_V25_t convictionvoting_delegate_V25;
    pd_convictionvoting_undelegate_V25_t convictionvoting_undelegate_V25;
    pd_convictionvoting_unlock_V25_t convictionvoting_unlock_V25;
    pd_convictionvoting_remove_vote_V25_t convictionvoting_remove_vote_V25;
    pd_convictionvoting_remove_other_vote_V25_t convictionvoting_remove_other_vote_V25;
    pd_proxy_proxy_V25_t proxy_proxy_V25;
    pd_proxy_add_proxy_V25_t proxy_add_proxy_V25;
    pd_proxy_remove_proxy_V25_t proxy_remove_proxy_V25;
    pd_proxy_create_pure_V25_t proxy_create_pure_V25;
    pd_proxy_kill_pure_V25_t proxy_kill_pure_V25;
    pd_multisig_as_multi_threshold_1_V25_t multisig_as_multi_threshold_1_V25;
    pd_multisig_as_multi_V25_t multisig_as_multi_V25;
    pd_multisig_approve_as_multi_V25_t multisig_approve_as_multi_V25;
    pd_multisig_cancel_as_multi_V25_t multisig_cancel_as_multi_V25;
    pd_nominationpools_join_V25_t nominationpools_join_V25;
    pd_nominationpools_bond_extra_V25_t nominationpools_bond_extra_V25;
    pd_nominationpools_claim_payout_V25_t nominationpools_claim_payout_V25;
    pd_nominationpools_unbond_V25_t nominationpools_unbond_V25;
    pd_nominationpools_withdraw_unbonded_V25_t nominationpools_withdraw_unbonded_V25;
    pd_nominationpools_create_V25_t nominationpools_create_V25;
    pd_nominationpools_nominate_V25_t nominationpools_nominate_V25;
    pd_nominationpools_set_state_V25_t nominationpools_set_state_V25;
    pd_nominationpools_set_metadata_V25_t nominationpools_set_metadata_V25;
    pd_nominationpools_update_roles_V25_t nominationpools_update_roles_V25;
    pd_nominationpools_chill_V25_t nominationpools_chill_V25;
    pd_nominationpools_set_claim_permission_V25_t nominationpools_set_claim_permission_V25;
    pd_nominationpools_claim_payout_other_V25_t nominationpools_claim_payout_other_V25;
    pd_nominationpools_set_commission_V25_t nominationpools_set_commission_V25;
    pd_nominationpools_set_commission_max_V25_t nominationpools_set_commission_max_V25;
    pd_nominationpools_set_commission_change_rate_V25_t nominationpools_set_commission_change_rate_V25;
    pd_nominationpools_claim_commission_V25_t nominationpools_claim_commission_V25;
    pd_fastunstake_register_fast_unstake_V25_t fastunstake_register_fast_unstake_V25;
    pd_fastunstake_deregister_V25_t fastunstake_deregister_V25;
#endif
} pd_MethodNested_V25_t;

typedef union {
    pd_MethodBasic_V25_t basic;
    pd_MethodNested_V25_t nested;
} pd_Method_V25_t;

#ifdef __cplusplus
}
#pragma clang diagnostic pop
#endif
