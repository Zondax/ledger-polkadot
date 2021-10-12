/*******************************************************************************
*  (c) 2019 Zondax GmbH
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
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wextern-c-compat"
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "substrate_types.h"
#include "substrate_types_V8.h"
#include <stddef.h>
#include <stdint.h>

#define PD_CALL_SYSTEM_V8 0
#define PD_CALL_SCHEDULER_V8 1
#define PD_CALL_BABE_V8 2
#define PD_CALL_TIMESTAMP_V8 3
#define PD_CALL_INDICES_V8 4
#define PD_CALL_BALANCES_V8 5
#define PD_CALL_AUTHORSHIP_V8 6
#define PD_CALL_STAKING_V8 7
#define PD_CALL_SESSION_V8 9
#define PD_CALL_GRANDPA_V8 11
#define PD_CALL_IMONLINE_V8 12
#define PD_CALL_DEMOCRACY_V8 14
#define PD_CALL_COUNCIL_V8 15
#define PD_CALL_TECHNICALCOMMITTEE_V8 16
#define PD_CALL_PHRAGMENELECTION_V8 17
#define PD_CALL_TECHNICALMEMBERSHIP_V8 18
#define PD_CALL_TREASURY_V8 19
#define PD_CALL_CLAIMS_V8 24
#define PD_CALL_VESTING_V8 25
#define PD_CALL_UTILITY_V8 26
#define PD_CALL_IDENTITY_V8 28
#define PD_CALL_PROXY_V8 29
#define PD_CALL_MULTISIG_V8 30
#define PD_CALL_BOUNTIES_V8 34
#define PD_CALL_TIPS_V8 35
#define PD_CALL_ELECTIONPROVIDERMULTIPHASE_V8 36

#define PD_CALL_STAKING_BOND_V8 0
typedef struct {
    pd_LookupSource_V8_t controller;
    pd_CompactBalanceOf_t value;
    pd_RewardDestination_V8_t payee;
} pd_staking_bond_V8_t;

#define PD_CALL_STAKING_BOND_EXTRA_V8 1
typedef struct {
    pd_CompactBalanceOf_t max_additional;
} pd_staking_bond_extra_V8_t;

#define PD_CALL_STAKING_UNBOND_V8 2
typedef struct {
    pd_CompactBalanceOf_t value;
} pd_staking_unbond_V8_t;

#define PD_CALL_STAKING_WITHDRAW_UNBONDED_V8 3
typedef struct {
    pd_u32_t num_slashing_spans;
} pd_staking_withdraw_unbonded_V8_t;

#define PD_CALL_STAKING_VALIDATE_V8 4
typedef struct {
    pd_ValidatorPrefs_V8_t prefs;
} pd_staking_validate_V8_t;

#define PD_CALL_STAKING_NOMINATE_V8 5
typedef struct {
    pd_VecLookupSource_V8_t targets;
} pd_staking_nominate_V8_t;

#define PD_CALL_STAKING_CHILL_V8 6
typedef struct {
} pd_staking_chill_V8_t;

#define PD_CALL_STAKING_SET_PAYEE_V8 7
typedef struct {
    pd_RewardDestination_V8_t payee;
} pd_staking_set_payee_V8_t;

#define PD_CALL_STAKING_SET_CONTROLLER_V8 8
typedef struct {
    pd_LookupSource_V8_t controller;
} pd_staking_set_controller_V8_t;

#define PD_CALL_STAKING_PAYOUT_STAKERS_V8 18
typedef struct {
    pd_AccountId_V8_t validator_stash;
    pd_EraIndex_V8_t era;
} pd_staking_payout_stakers_V8_t;

#define PD_CALL_STAKING_REBOND_V8 19
typedef struct {
    pd_CompactBalanceOf_t value;
} pd_staking_rebond_V8_t;

#define PD_CALL_SESSION_SET_KEYS_V8 0
typedef struct {
    pd_Keys_V8_t keys;
    pd_Bytes_t proof;
} pd_session_set_keys_V8_t;

#define PD_CALL_SESSION_PURGE_KEYS_V8 1
typedef struct {
} pd_session_purge_keys_V8_t;

#define PD_CALL_UTILITY_BATCH_V8 0
typedef struct {
    pd_VecCall_t calls;
} pd_utility_batch_V8_t;

#define PD_CALL_UTILITY_BATCH_ALL_V8 2
typedef struct {
    pd_VecCall_t calls;
} pd_utility_batch_all_V8_t;

#ifdef SUBSTRATE_PARSER_FULL
#define PD_CALL_SYSTEM_REMARK_WITH_EVENT_V8 9
typedef struct {
    pd_Bytes_t remark;
} pd_system_remark_with_event_V8_t;

#define PD_CALL_SCHEDULER_SCHEDULE_V8 0
typedef struct {
    pd_BlockNumber_t when;
    pd_OptionPeriod_V8_t maybe_periodic;
    pd_Priority_V8_t priority;
    pd_Call_t call;
} pd_scheduler_schedule_V8_t;

#define PD_CALL_SCHEDULER_CANCEL_V8 1
typedef struct {
    pd_BlockNumber_t when;
    pd_u32_t index;
} pd_scheduler_cancel_V8_t;

#define PD_CALL_SCHEDULER_SCHEDULE_NAMED_V8 2
typedef struct {
    pd_Bytes_t id;
    pd_BlockNumber_t when;
    pd_OptionPeriod_V8_t maybe_periodic;
    pd_Priority_V8_t priority;
    pd_Call_t call;
} pd_scheduler_schedule_named_V8_t;

#define PD_CALL_SCHEDULER_CANCEL_NAMED_V8 3
typedef struct {
    pd_Bytes_t id;
} pd_scheduler_cancel_named_V8_t;

#define PD_CALL_SCHEDULER_SCHEDULE_AFTER_V8 4
typedef struct {
    pd_BlockNumber_t after;
    pd_OptionPeriod_V8_t maybe_periodic;
    pd_Priority_V8_t priority;
    pd_Call_t call;
} pd_scheduler_schedule_after_V8_t;

#define PD_CALL_SCHEDULER_SCHEDULE_NAMED_AFTER_V8 5
typedef struct {
    pd_Bytes_t id;
    pd_BlockNumber_t after;
    pd_OptionPeriod_V8_t maybe_periodic;
    pd_Priority_V8_t priority;
    pd_Call_t call;
} pd_scheduler_schedule_named_after_V8_t;

#define PD_CALL_BABE_REPORT_EQUIVOCATION_V8 0
typedef struct {
    pd_BabeEquivocationProof_V8_t equivocation_proof;
    pd_KeyOwnerProof_V8_t key_owner_proof;
} pd_babe_report_equivocation_V8_t;

#define PD_CALL_BABE_REPORT_EQUIVOCATION_UNSIGNED_V8 1
typedef struct {
    pd_BabeEquivocationProof_V8_t equivocation_proof;
    pd_KeyOwnerProof_V8_t key_owner_proof;
} pd_babe_report_equivocation_unsigned_V8_t;

#define PD_CALL_BABE_PLAN_CONFIG_CHANGE_V8 2
typedef struct {
    pd_NextConfigDescriptor_V8_t config;
} pd_babe_plan_config_change_V8_t;

#define PD_CALL_TIMESTAMP_SET_V8 0
typedef struct {
    pd_CompactMoment_V8_t now;
} pd_timestamp_set_V8_t;

#define PD_CALL_INDICES_CLAIM_V8 0
typedef struct {
    pd_AccountIndex_V8_t index;
} pd_indices_claim_V8_t;

#define PD_CALL_INDICES_TRANSFER_V8 1
typedef struct {
    pd_AccountId_V8_t new_;
    pd_AccountIndex_V8_t index;
} pd_indices_transfer_V8_t;

#define PD_CALL_INDICES_FREE_V8 2
typedef struct {
    pd_AccountIndex_V8_t index;
} pd_indices_free_V8_t;

#define PD_CALL_INDICES_FORCE_TRANSFER_V8 3
typedef struct {
    pd_AccountId_V8_t new_;
    pd_AccountIndex_V8_t index;
    pd_bool_t freeze;
} pd_indices_force_transfer_V8_t;

#define PD_CALL_INDICES_FREEZE_V8 4
typedef struct {
    pd_AccountIndex_V8_t index;
} pd_indices_freeze_V8_t;

#define PD_CALL_BALANCES_TRANSFER_ALL_V8 4
typedef struct {
    pd_LookupSource_V8_t dest;
    pd_bool_t keep_alive;
} pd_balances_transfer_all_V8_t;

#define PD_CALL_AUTHORSHIP_SET_UNCLES_V8 0
typedef struct {
    pd_VecHeader_t new_uncles;
} pd_authorship_set_uncles_V8_t;

#define PD_CALL_STAKING_SET_VALIDATOR_COUNT_V8 9
typedef struct {
    pd_Compactu32_t new_;
} pd_staking_set_validator_count_V8_t;

#define PD_CALL_STAKING_INCREASE_VALIDATOR_COUNT_V8 10
typedef struct {
    pd_Compactu32_t additional;
} pd_staking_increase_validator_count_V8_t;

#define PD_CALL_STAKING_SCALE_VALIDATOR_COUNT_V8 11
typedef struct {
    pd_Percent_V8_t factor;
} pd_staking_scale_validator_count_V8_t;

#define PD_CALL_STAKING_FORCE_NO_ERAS_V8 12
typedef struct {
} pd_staking_force_no_eras_V8_t;

#define PD_CALL_STAKING_FORCE_NEW_ERA_V8 13
typedef struct {
} pd_staking_force_new_era_V8_t;

#define PD_CALL_STAKING_SET_INVULNERABLES_V8 14
typedef struct {
    pd_VecAccountId_V8_t invulnerables;
} pd_staking_set_invulnerables_V8_t;

#define PD_CALL_STAKING_FORCE_UNSTAKE_V8 15
typedef struct {
    pd_AccountId_V8_t stash;
    pd_u32_t num_slashing_spans;
} pd_staking_force_unstake_V8_t;

#define PD_CALL_STAKING_FORCE_NEW_ERA_ALWAYS_V8 16
typedef struct {
} pd_staking_force_new_era_always_V8_t;

#define PD_CALL_STAKING_CANCEL_DEFERRED_SLASH_V8 17
typedef struct {
    pd_EraIndex_V8_t era;
    pd_Vecu32_t slash_indices;
} pd_staking_cancel_deferred_slash_V8_t;

#define PD_CALL_STAKING_SET_HISTORY_DEPTH_V8 20
typedef struct {
    pd_CompactEraIndex_V8_t new_history_depth;
    pd_Compactu32_t _era_items_deleted;
} pd_staking_set_history_depth_V8_t;

#define PD_CALL_STAKING_REAP_STASH_V8 21
typedef struct {
    pd_AccountId_V8_t stash;
    pd_u32_t num_slashing_spans;
} pd_staking_reap_stash_V8_t;

#define PD_CALL_STAKING_KICK_V8 22
typedef struct {
    pd_VecLookupSource_V8_t who;
} pd_staking_kick_V8_t;

#define PD_CALL_STAKING_SET_STAKING_LIMITS_V8 23
typedef struct {
    pd_BalanceOf_t min_nominator_bond;
    pd_BalanceOf_t min_validator_bond;
    pd_Optionu32_t max_nominator_count;
    pd_Optionu32_t max_validator_count;
    pd_OptionPercent_V8_t threshold;
} pd_staking_set_staking_limits_V8_t;

#define PD_CALL_STAKING_CHILL_OTHER_V8 24
typedef struct {
    pd_AccountId_V8_t controller;
} pd_staking_chill_other_V8_t;

#define PD_CALL_GRANDPA_REPORT_EQUIVOCATION_V8 0
typedef struct {
    pd_GrandpaEquivocationProof_V8_t equivocation_proof;
    pd_KeyOwnerProof_V8_t key_owner_proof;
} pd_grandpa_report_equivocation_V8_t;

#define PD_CALL_GRANDPA_REPORT_EQUIVOCATION_UNSIGNED_V8 1
typedef struct {
    pd_GrandpaEquivocationProof_V8_t equivocation_proof;
    pd_KeyOwnerProof_V8_t key_owner_proof;
} pd_grandpa_report_equivocation_unsigned_V8_t;

#define PD_CALL_GRANDPA_NOTE_STALLED_V8 2
typedef struct {
    pd_BlockNumber_t delay;
    pd_BlockNumber_t best_finalized_block_number;
} pd_grandpa_note_stalled_V8_t;

#define PD_CALL_IMONLINE_HEARTBEAT_V8 0
typedef struct {
    pd_Heartbeat_t heartbeat;
    pd_Signature_V8_t _signature;
} pd_imonline_heartbeat_V8_t;

#define PD_CALL_DEMOCRACY_PROPOSE_V8 0
typedef struct {
    pd_Hash_t proposal_hash;
    pd_CompactBalanceOf_t value;
} pd_democracy_propose_V8_t;

#define PD_CALL_DEMOCRACY_SECOND_V8 1
typedef struct {
    pd_CompactPropIndex_V8_t proposal;
    pd_Compactu32_t seconds_upper_bound;
} pd_democracy_second_V8_t;

#define PD_CALL_DEMOCRACY_VOTE_V8 2
typedef struct {
    pd_CompactReferendumIndex_V8_t ref_index;
    pd_AccountVote_V8_t vote;
} pd_democracy_vote_V8_t;

#define PD_CALL_DEMOCRACY_EMERGENCY_CANCEL_V8 3
typedef struct {
    pd_ReferendumIndex_V8_t ref_index;
} pd_democracy_emergency_cancel_V8_t;

#define PD_CALL_DEMOCRACY_EXTERNAL_PROPOSE_V8 4
typedef struct {
    pd_Hash_t proposal_hash;
} pd_democracy_external_propose_V8_t;

#define PD_CALL_DEMOCRACY_EXTERNAL_PROPOSE_MAJORITY_V8 5
typedef struct {
    pd_Hash_t proposal_hash;
} pd_democracy_external_propose_majority_V8_t;

#define PD_CALL_DEMOCRACY_EXTERNAL_PROPOSE_DEFAULT_V8 6
typedef struct {
    pd_Hash_t proposal_hash;
} pd_democracy_external_propose_default_V8_t;

#define PD_CALL_DEMOCRACY_FAST_TRACK_V8 7
typedef struct {
    pd_Hash_t proposal_hash;
    pd_BlockNumber_t voting_period;
    pd_BlockNumber_t delay;
} pd_democracy_fast_track_V8_t;

#define PD_CALL_DEMOCRACY_VETO_EXTERNAL_V8 8
typedef struct {
    pd_Hash_t proposal_hash;
} pd_democracy_veto_external_V8_t;

#define PD_CALL_DEMOCRACY_CANCEL_REFERENDUM_V8 9
typedef struct {
    pd_CompactReferendumIndex_V8_t ref_index;
} pd_democracy_cancel_referendum_V8_t;

#define PD_CALL_DEMOCRACY_CANCEL_QUEUED_V8 10
typedef struct {
    pd_ReferendumIndex_V8_t which;
} pd_democracy_cancel_queued_V8_t;

#define PD_CALL_DEMOCRACY_DELEGATE_V8 11
typedef struct {
    pd_AccountId_V8_t to;
    pd_Conviction_V8_t conviction;
    pd_BalanceOf_t balance;
} pd_democracy_delegate_V8_t;

#define PD_CALL_DEMOCRACY_UNDELEGATE_V8 12
typedef struct {
} pd_democracy_undelegate_V8_t;

#define PD_CALL_DEMOCRACY_CLEAR_PUBLIC_PROPOSALS_V8 13
typedef struct {
} pd_democracy_clear_public_proposals_V8_t;

#define PD_CALL_DEMOCRACY_NOTE_PREIMAGE_V8 14
typedef struct {
    pd_Bytes_t encoded_proposal;
} pd_democracy_note_preimage_V8_t;

#define PD_CALL_DEMOCRACY_NOTE_PREIMAGE_OPERATIONAL_V8 15
typedef struct {
    pd_Bytes_t encoded_proposal;
} pd_democracy_note_preimage_operational_V8_t;

#define PD_CALL_DEMOCRACY_NOTE_IMMINENT_PREIMAGE_V8 16
typedef struct {
    pd_Bytes_t encoded_proposal;
} pd_democracy_note_imminent_preimage_V8_t;

#define PD_CALL_DEMOCRACY_NOTE_IMMINENT_PREIMAGE_OPERATIONAL_V8 17
typedef struct {
    pd_Bytes_t encoded_proposal;
} pd_democracy_note_imminent_preimage_operational_V8_t;

#define PD_CALL_DEMOCRACY_REAP_PREIMAGE_V8 18
typedef struct {
    pd_Hash_t proposal_hash;
    pd_Compactu32_t proposal_len_upper_bound;
} pd_democracy_reap_preimage_V8_t;

#define PD_CALL_DEMOCRACY_UNLOCK_V8 19
typedef struct {
    pd_AccountId_V8_t target;
} pd_democracy_unlock_V8_t;

#define PD_CALL_DEMOCRACY_REMOVE_VOTE_V8 20
typedef struct {
    pd_ReferendumIndex_V8_t index;
} pd_democracy_remove_vote_V8_t;

#define PD_CALL_DEMOCRACY_REMOVE_OTHER_VOTE_V8 21
typedef struct {
    pd_AccountId_V8_t target;
    pd_ReferendumIndex_V8_t index;
} pd_democracy_remove_other_vote_V8_t;

#define PD_CALL_DEMOCRACY_ENACT_PROPOSAL_V8 22
typedef struct {
    pd_Hash_t proposal_hash;
    pd_ReferendumIndex_V8_t index;
} pd_democracy_enact_proposal_V8_t;

#define PD_CALL_DEMOCRACY_BLACKLIST_V8 23
typedef struct {
    pd_Hash_t proposal_hash;
    pd_OptionReferendumIndex_V8_t maybe_ref_index;
} pd_democracy_blacklist_V8_t;

#define PD_CALL_DEMOCRACY_CANCEL_PROPOSAL_V8 24
typedef struct {
    pd_CompactPropIndex_V8_t prop_index;
} pd_democracy_cancel_proposal_V8_t;

#define PD_CALL_COUNCIL_SET_MEMBERS_V8 0
typedef struct {
    pd_VecAccountId_V8_t new_members;
    pd_OptionAccountId_V8_t prime;
    pd_MemberCount_V8_t old_count;
} pd_council_set_members_V8_t;

#define PD_CALL_COUNCIL_EXECUTE_V8 1
typedef struct {
    pd_Proposal_t proposal;
    pd_Compactu32_t length_bound;
} pd_council_execute_V8_t;

#define PD_CALL_COUNCIL_PROPOSE_V8 2
typedef struct {
    pd_CompactMemberCount_V8_t threshold;
    pd_Proposal_t proposal;
    pd_Compactu32_t length_bound;
} pd_council_propose_V8_t;

#define PD_CALL_COUNCIL_VOTE_V8 3
typedef struct {
    pd_Hash_t proposal;
    pd_CompactProposalIndex_V8_t index;
    pd_bool_t approve;
} pd_council_vote_V8_t;

#define PD_CALL_COUNCIL_CLOSE_V8 4
typedef struct {
    pd_Hash_t proposal_hash;
    pd_CompactProposalIndex_V8_t index;
    pd_CompactWeight_V8_t proposal_weight_bound;
    pd_Compactu32_t length_bound;
} pd_council_close_V8_t;

#define PD_CALL_COUNCIL_DISAPPROVE_PROPOSAL_V8 5
typedef struct {
    pd_Hash_t proposal_hash;
} pd_council_disapprove_proposal_V8_t;

#define PD_CALL_TECHNICALCOMMITTEE_SET_MEMBERS_V8 0
typedef struct {
    pd_VecAccountId_V8_t new_members;
    pd_OptionAccountId_V8_t prime;
    pd_MemberCount_V8_t old_count;
} pd_technicalcommittee_set_members_V8_t;

#define PD_CALL_TECHNICALCOMMITTEE_EXECUTE_V8 1
typedef struct {
    pd_Proposal_t proposal;
    pd_Compactu32_t length_bound;
} pd_technicalcommittee_execute_V8_t;

#define PD_CALL_TECHNICALCOMMITTEE_PROPOSE_V8 2
typedef struct {
    pd_CompactMemberCount_V8_t threshold;
    pd_Proposal_t proposal;
    pd_Compactu32_t length_bound;
} pd_technicalcommittee_propose_V8_t;

#define PD_CALL_TECHNICALCOMMITTEE_VOTE_V8 3
typedef struct {
    pd_Hash_t proposal;
    pd_CompactProposalIndex_V8_t index;
    pd_bool_t approve;
} pd_technicalcommittee_vote_V8_t;

#define PD_CALL_TECHNICALCOMMITTEE_CLOSE_V8 4
typedef struct {
    pd_Hash_t proposal_hash;
    pd_CompactProposalIndex_V8_t index;
    pd_CompactWeight_V8_t proposal_weight_bound;
    pd_Compactu32_t length_bound;
} pd_technicalcommittee_close_V8_t;

#define PD_CALL_TECHNICALCOMMITTEE_DISAPPROVE_PROPOSAL_V8 5
typedef struct {
    pd_Hash_t proposal_hash;
} pd_technicalcommittee_disapprove_proposal_V8_t;

#define PD_CALL_PHRAGMENELECTION_VOTE_V8 0
typedef struct {
    pd_VecAccountId_V8_t votes;
    pd_CompactBalanceOf_t value;
} pd_phragmenelection_vote_V8_t;

#define PD_CALL_PHRAGMENELECTION_REMOVE_VOTER_V8 1
typedef struct {
} pd_phragmenelection_remove_voter_V8_t;

#define PD_CALL_PHRAGMENELECTION_SUBMIT_CANDIDACY_V8 2
typedef struct {
    pd_Compactu32_t candidate_count;
} pd_phragmenelection_submit_candidacy_V8_t;

#define PD_CALL_PHRAGMENELECTION_RENOUNCE_CANDIDACY_V8 3
typedef struct {
    pd_Renouncing_V8_t renouncing;
} pd_phragmenelection_renounce_candidacy_V8_t;

#define PD_CALL_PHRAGMENELECTION_REMOVE_MEMBER_V8 4
typedef struct {
    pd_LookupSource_V8_t who;
    pd_bool_t has_replacement;
} pd_phragmenelection_remove_member_V8_t;

#define PD_CALL_PHRAGMENELECTION_CLEAN_DEFUNCT_VOTERS_V8 5
typedef struct {
    pd_u32_t _num_voters;
    pd_u32_t _num_defunct;
} pd_phragmenelection_clean_defunct_voters_V8_t;

#define PD_CALL_TECHNICALMEMBERSHIP_ADD_MEMBER_V8 0
typedef struct {
    pd_AccountId_V8_t who;
} pd_technicalmembership_add_member_V8_t;

#define PD_CALL_TECHNICALMEMBERSHIP_REMOVE_MEMBER_V8 1
typedef struct {
    pd_AccountId_V8_t who;
} pd_technicalmembership_remove_member_V8_t;

#define PD_CALL_TECHNICALMEMBERSHIP_SWAP_MEMBER_V8 2
typedef struct {
    pd_AccountId_V8_t remove;
    pd_AccountId_V8_t add;
} pd_technicalmembership_swap_member_V8_t;

#define PD_CALL_TECHNICALMEMBERSHIP_RESET_MEMBERS_V8 3
typedef struct {
    pd_VecAccountId_V8_t members;
} pd_technicalmembership_reset_members_V8_t;

#define PD_CALL_TECHNICALMEMBERSHIP_CHANGE_KEY_V8 4
typedef struct {
    pd_AccountId_V8_t new_;
} pd_technicalmembership_change_key_V8_t;

#define PD_CALL_TECHNICALMEMBERSHIP_SET_PRIME_V8 5
typedef struct {
    pd_AccountId_V8_t who;
} pd_technicalmembership_set_prime_V8_t;

#define PD_CALL_TECHNICALMEMBERSHIP_CLEAR_PRIME_V8 6
typedef struct {
} pd_technicalmembership_clear_prime_V8_t;

#define PD_CALL_TREASURY_PROPOSE_SPEND_V8 0
typedef struct {
    pd_CompactBalanceOf_t value;
    pd_LookupSource_V8_t beneficiary;
} pd_treasury_propose_spend_V8_t;

#define PD_CALL_TREASURY_REJECT_PROPOSAL_V8 1
typedef struct {
    pd_CompactProposalIndex_V8_t proposal_id;
} pd_treasury_reject_proposal_V8_t;

#define PD_CALL_TREASURY_APPROVE_PROPOSAL_V8 2
typedef struct {
    pd_CompactProposalIndex_V8_t proposal_id;
} pd_treasury_approve_proposal_V8_t;

#define PD_CALL_CLAIMS_CLAIM_V8 0
typedef struct {
    pd_AccountId_V8_t dest;
    pd_EcdsaSignature_V8_t ethereum_signature;
} pd_claims_claim_V8_t;

#define PD_CALL_CLAIMS_MINT_CLAIM_V8 1
typedef struct {
    pd_EthereumAddress_V8_t who;
    pd_BalanceOf_t value;
    pd_OptionTupleBalanceOfBalanceOfBlockNumber_V8_t vesting_schedule;
    pd_OptionStatementKind_V8_t statement;
} pd_claims_mint_claim_V8_t;

#define PD_CALL_CLAIMS_CLAIM_ATTEST_V8 2
typedef struct {
    pd_AccountId_V8_t dest;
    pd_EcdsaSignature_V8_t ethereum_signature;
    pd_Bytes_t statement;
} pd_claims_claim_attest_V8_t;

#define PD_CALL_CLAIMS_ATTEST_V8 3
typedef struct {
    pd_Bytes_t statement;
} pd_claims_attest_V8_t;

#define PD_CALL_CLAIMS_MOVE_CLAIM_V8 4
typedef struct {
    pd_EthereumAddress_V8_t old;
    pd_EthereumAddress_V8_t new_;
    pd_OptionAccountId_V8_t maybe_preclaim;
} pd_claims_move_claim_V8_t;

#define PD_CALL_VESTING_VEST_V8 0
typedef struct {
} pd_vesting_vest_V8_t;

#define PD_CALL_VESTING_VEST_OTHER_V8 1
typedef struct {
    pd_LookupSource_V8_t target;
} pd_vesting_vest_other_V8_t;

#define PD_CALL_VESTING_VESTED_TRANSFER_V8 2
typedef struct {
    pd_LookupSource_V8_t target;
    pd_VestingInfo_V8_t schedule;
} pd_vesting_vested_transfer_V8_t;

#define PD_CALL_VESTING_FORCE_VESTED_TRANSFER_V8 3
typedef struct {
    pd_LookupSource_V8_t source;
    pd_LookupSource_V8_t target;
    pd_VestingInfo_V8_t schedule;
} pd_vesting_force_vested_transfer_V8_t;

#define PD_CALL_UTILITY_AS_DERIVATIVE_V8 1
typedef struct {
    pd_u16_t index;
    pd_Call_t call;
} pd_utility_as_derivative_V8_t;

#define PD_CALL_IDENTITY_ADD_REGISTRAR_V8 0
typedef struct {
    pd_AccountId_V8_t account;
} pd_identity_add_registrar_V8_t;

#define PD_CALL_IDENTITY_SET_IDENTITY_V8 1
typedef struct {
    pd_IdentityInfo_V8_t info;
} pd_identity_set_identity_V8_t;

#define PD_CALL_IDENTITY_SET_SUBS_V8 2
typedef struct {
    pd_VecTupleAccountIdData_V8_t subs;
} pd_identity_set_subs_V8_t;

#define PD_CALL_IDENTITY_CLEAR_IDENTITY_V8 3
typedef struct {
} pd_identity_clear_identity_V8_t;

#define PD_CALL_IDENTITY_REQUEST_JUDGEMENT_V8 4
typedef struct {
    pd_CompactRegistrarIndex_V8_t reg_index;
    pd_CompactBalanceOf_t max_fee;
} pd_identity_request_judgement_V8_t;

#define PD_CALL_IDENTITY_CANCEL_REQUEST_V8 5
typedef struct {
    pd_RegistrarIndex_V8_t reg_index;
} pd_identity_cancel_request_V8_t;

#define PD_CALL_IDENTITY_SET_FEE_V8 6
typedef struct {
    pd_CompactRegistrarIndex_V8_t index;
    pd_CompactBalanceOf_t fee;
} pd_identity_set_fee_V8_t;

#define PD_CALL_IDENTITY_SET_ACCOUNT_ID_V8 7
typedef struct {
    pd_CompactRegistrarIndex_V8_t index;
    pd_AccountId_V8_t new_;
} pd_identity_set_account_id_V8_t;

#define PD_CALL_IDENTITY_SET_FIELDS_V8 8
typedef struct {
    pd_CompactRegistrarIndex_V8_t index;
    pd_IdentityFields_V8_t fields;
} pd_identity_set_fields_V8_t;

#define PD_CALL_IDENTITY_PROVIDE_JUDGEMENT_V8 9
typedef struct {
    pd_CompactRegistrarIndex_V8_t reg_index;
    pd_LookupSource_V8_t target;
    pd_IdentityJudgement_V8_t judgement;
} pd_identity_provide_judgement_V8_t;

#define PD_CALL_IDENTITY_KILL_IDENTITY_V8 10
typedef struct {
    pd_LookupSource_V8_t target;
} pd_identity_kill_identity_V8_t;

#define PD_CALL_IDENTITY_ADD_SUB_V8 11
typedef struct {
    pd_LookupSource_V8_t sub;
    pd_Data_t data;
} pd_identity_add_sub_V8_t;

#define PD_CALL_IDENTITY_RENAME_SUB_V8 12
typedef struct {
    pd_LookupSource_V8_t sub;
    pd_Data_t data;
} pd_identity_rename_sub_V8_t;

#define PD_CALL_IDENTITY_REMOVE_SUB_V8 13
typedef struct {
    pd_LookupSource_V8_t sub;
} pd_identity_remove_sub_V8_t;

#define PD_CALL_IDENTITY_QUIT_SUB_V8 14
typedef struct {
} pd_identity_quit_sub_V8_t;

#define PD_CALL_PROXY_ADD_PROXY_V8 1
typedef struct {
    pd_AccountId_V8_t delegate;
    pd_ProxyType_V8_t proxy_type;
    pd_BlockNumber_t delay;
} pd_proxy_add_proxy_V8_t;

#define PD_CALL_PROXY_REMOVE_PROXY_V8 2
typedef struct {
    pd_AccountId_V8_t delegate;
    pd_ProxyType_V8_t proxy_type;
    pd_BlockNumber_t delay;
} pd_proxy_remove_proxy_V8_t;

#define PD_CALL_PROXY_REMOVE_PROXIES_V8 3
typedef struct {
} pd_proxy_remove_proxies_V8_t;

#define PD_CALL_PROXY_ANONYMOUS_V8 4
typedef struct {
    pd_ProxyType_V8_t proxy_type;
    pd_BlockNumber_t delay;
    pd_u16_t index;
} pd_proxy_anonymous_V8_t;

#define PD_CALL_PROXY_KILL_ANONYMOUS_V8 5
typedef struct {
    pd_AccountId_V8_t spawner;
    pd_ProxyType_V8_t proxy_type;
    pd_u16_t index;
    pd_CompactBlockNumber_t height;
    pd_Compactu32_t ext_index;
} pd_proxy_kill_anonymous_V8_t;

#define PD_CALL_PROXY_ANNOUNCE_V8 6
typedef struct {
    pd_AccountId_V8_t real;
    pd_CallHashOf_V8_t call_hash;
} pd_proxy_announce_V8_t;

#define PD_CALL_PROXY_REMOVE_ANNOUNCEMENT_V8 7
typedef struct {
    pd_AccountId_V8_t real;
    pd_CallHashOf_V8_t call_hash;
} pd_proxy_remove_announcement_V8_t;

#define PD_CALL_PROXY_REJECT_ANNOUNCEMENT_V8 8
typedef struct {
    pd_AccountId_V8_t delegate;
    pd_CallHashOf_V8_t call_hash;
} pd_proxy_reject_announcement_V8_t;

#define PD_CALL_PROXY_PROXY_ANNOUNCED_V8 9
typedef struct {
    pd_AccountId_V8_t delegate;
    pd_AccountId_V8_t real;
    pd_OptionProxyType_V8_t force_proxy_type;
    pd_Call_t call;
} pd_proxy_proxy_announced_V8_t;

#define PD_CALL_BOUNTIES_PROPOSE_BOUNTY_V8 0
typedef struct {
    pd_CompactBalanceOf_t value;
    pd_Bytes_t description;
} pd_bounties_propose_bounty_V8_t;

#define PD_CALL_BOUNTIES_APPROVE_BOUNTY_V8 1
typedef struct {
    pd_CompactBountyIndex_V8_t bounty_id;
} pd_bounties_approve_bounty_V8_t;

#define PD_CALL_BOUNTIES_PROPOSE_CURATOR_V8 2
typedef struct {
    pd_CompactBountyIndex_V8_t bounty_id;
    pd_LookupSource_V8_t curator;
    pd_CompactBalanceOf_t fee;
} pd_bounties_propose_curator_V8_t;

#define PD_CALL_BOUNTIES_UNASSIGN_CURATOR_V8 3
typedef struct {
    pd_CompactBountyIndex_V8_t bounty_id;
} pd_bounties_unassign_curator_V8_t;

#define PD_CALL_BOUNTIES_ACCEPT_CURATOR_V8 4
typedef struct {
    pd_CompactBountyIndex_V8_t bounty_id;
} pd_bounties_accept_curator_V8_t;

#define PD_CALL_BOUNTIES_AWARD_BOUNTY_V8 5
typedef struct {
    pd_CompactBountyIndex_V8_t bounty_id;
    pd_LookupSource_V8_t beneficiary;
} pd_bounties_award_bounty_V8_t;

#define PD_CALL_BOUNTIES_CLAIM_BOUNTY_V8 6
typedef struct {
    pd_CompactBountyIndex_V8_t bounty_id;
} pd_bounties_claim_bounty_V8_t;

#define PD_CALL_BOUNTIES_CLOSE_BOUNTY_V8 7
typedef struct {
    pd_CompactBountyIndex_V8_t bounty_id;
} pd_bounties_close_bounty_V8_t;

#define PD_CALL_BOUNTIES_EXTEND_BOUNTY_EXPIRY_V8 8
typedef struct {
    pd_CompactBountyIndex_V8_t bounty_id;
    pd_Bytes_t _remark;
} pd_bounties_extend_bounty_expiry_V8_t;

#define PD_CALL_TIPS_REPORT_AWESOME_V8 0
typedef struct {
    pd_Bytes_t reason;
    pd_AccountId_V8_t who;
} pd_tips_report_awesome_V8_t;

#define PD_CALL_TIPS_RETRACT_TIP_V8 1
typedef struct {
    pd_Hash_t hash;
} pd_tips_retract_tip_V8_t;

#define PD_CALL_TIPS_TIP_NEW_V8 2
typedef struct {
    pd_Bytes_t reason;
    pd_AccountId_V8_t who;
    pd_CompactBalanceOf_t tip_value;
} pd_tips_tip_new_V8_t;

#define PD_CALL_TIPS_TIP_V8 3
typedef struct {
    pd_Hash_t hash;
    pd_CompactBalanceOf_t tip_value;
} pd_tips_tip_V8_t;

#define PD_CALL_TIPS_CLOSE_TIP_V8 4
typedef struct {
    pd_Hash_t hash;
} pd_tips_close_tip_V8_t;

#define PD_CALL_TIPS_SLASH_TIP_V8 5
typedef struct {
    pd_Hash_t hash;
} pd_tips_slash_tip_V8_t;

#define PD_CALL_ELECTIONPROVIDERMULTIPHASE_SUBMIT_UNSIGNED_V8 0
typedef struct {
    pd_RawSolution_V8_t raw_solution;
    pd_SolutionOrSnapshotSize_V8_t witness;
} pd_electionprovidermultiphase_submit_unsigned_V8_t;

#define PD_CALL_ELECTIONPROVIDERMULTIPHASE_SET_MINIMUM_UNTRUSTED_SCORE_V8 1
typedef struct {
    pd_OptionElectionScore_V8_t maybe_next_score;
} pd_electionprovidermultiphase_set_minimum_untrusted_score_V8_t;

#define PD_CALL_ELECTIONPROVIDERMULTIPHASE_SET_EMERGENCY_ELECTION_RESULT_V8 2
typedef struct {
    pd_Supports_V8_t supports;
} pd_electionprovidermultiphase_set_emergency_election_result_V8_t;

#define PD_CALL_ELECTIONPROVIDERMULTIPHASE_SUBMIT_V8 3
typedef struct {
    pd_RawSolution_V8_t raw_solution;
    pd_u32_t num_signed_submissions;
} pd_electionprovidermultiphase_submit_V8_t;

#endif

typedef union {
    pd_staking_bond_V8_t staking_bond_V8;
    pd_staking_bond_extra_V8_t staking_bond_extra_V8;
    pd_staking_unbond_V8_t staking_unbond_V8;
    pd_staking_withdraw_unbonded_V8_t staking_withdraw_unbonded_V8;
    pd_staking_validate_V8_t staking_validate_V8;
    pd_staking_nominate_V8_t staking_nominate_V8;
    pd_staking_chill_V8_t staking_chill_V8;
    pd_staking_set_payee_V8_t staking_set_payee_V8;
    pd_staking_set_controller_V8_t staking_set_controller_V8;
    pd_staking_payout_stakers_V8_t staking_payout_stakers_V8;
    pd_staking_rebond_V8_t staking_rebond_V8;
    pd_session_set_keys_V8_t session_set_keys_V8;
    pd_session_purge_keys_V8_t session_purge_keys_V8;
    pd_utility_batch_V8_t utility_batch_V8;
    pd_utility_batch_all_V8_t utility_batch_all_V8;
#ifdef SUBSTRATE_PARSER_FULL
    pd_system_remark_with_event_V8_t system_remark_with_event_V8;
    pd_scheduler_schedule_V8_t scheduler_schedule_V8;
    pd_scheduler_cancel_V8_t scheduler_cancel_V8;
    pd_scheduler_schedule_named_V8_t scheduler_schedule_named_V8;
    pd_scheduler_cancel_named_V8_t scheduler_cancel_named_V8;
    pd_scheduler_schedule_after_V8_t scheduler_schedule_after_V8;
    pd_scheduler_schedule_named_after_V8_t scheduler_schedule_named_after_V8;
    pd_babe_report_equivocation_V8_t babe_report_equivocation_V8;
    pd_babe_report_equivocation_unsigned_V8_t babe_report_equivocation_unsigned_V8;
    pd_babe_plan_config_change_V8_t babe_plan_config_change_V8;
    pd_timestamp_set_V8_t timestamp_set_V8;
    pd_indices_claim_V8_t indices_claim_V8;
    pd_indices_transfer_V8_t indices_transfer_V8;
    pd_indices_free_V8_t indices_free_V8;
    pd_indices_force_transfer_V8_t indices_force_transfer_V8;
    pd_indices_freeze_V8_t indices_freeze_V8;
    pd_balances_transfer_all_V8_t balances_transfer_all_V8;
    pd_authorship_set_uncles_V8_t authorship_set_uncles_V8;
    pd_staking_set_validator_count_V8_t staking_set_validator_count_V8;
    pd_staking_increase_validator_count_V8_t staking_increase_validator_count_V8;
    pd_staking_scale_validator_count_V8_t staking_scale_validator_count_V8;
    pd_staking_force_no_eras_V8_t staking_force_no_eras_V8;
    pd_staking_force_new_era_V8_t staking_force_new_era_V8;
    pd_staking_set_invulnerables_V8_t staking_set_invulnerables_V8;
    pd_staking_force_unstake_V8_t staking_force_unstake_V8;
    pd_staking_force_new_era_always_V8_t staking_force_new_era_always_V8;
    pd_staking_cancel_deferred_slash_V8_t staking_cancel_deferred_slash_V8;
    pd_staking_set_history_depth_V8_t staking_set_history_depth_V8;
    pd_staking_reap_stash_V8_t staking_reap_stash_V8;
    pd_staking_kick_V8_t staking_kick_V8;
    pd_staking_set_staking_limits_V8_t staking_set_staking_limits_V8;
    pd_staking_chill_other_V8_t staking_chill_other_V8;
    pd_grandpa_report_equivocation_V8_t grandpa_report_equivocation_V8;
    pd_grandpa_report_equivocation_unsigned_V8_t grandpa_report_equivocation_unsigned_V8;
    pd_grandpa_note_stalled_V8_t grandpa_note_stalled_V8;
    pd_imonline_heartbeat_V8_t imonline_heartbeat_V8;
    pd_democracy_propose_V8_t democracy_propose_V8;
    pd_democracy_second_V8_t democracy_second_V8;
    pd_democracy_vote_V8_t democracy_vote_V8;
    pd_democracy_emergency_cancel_V8_t democracy_emergency_cancel_V8;
    pd_democracy_external_propose_V8_t democracy_external_propose_V8;
    pd_democracy_external_propose_majority_V8_t democracy_external_propose_majority_V8;
    pd_democracy_external_propose_default_V8_t democracy_external_propose_default_V8;
    pd_democracy_fast_track_V8_t democracy_fast_track_V8;
    pd_democracy_veto_external_V8_t democracy_veto_external_V8;
    pd_democracy_cancel_referendum_V8_t democracy_cancel_referendum_V8;
    pd_democracy_cancel_queued_V8_t democracy_cancel_queued_V8;
    pd_democracy_delegate_V8_t democracy_delegate_V8;
    pd_democracy_undelegate_V8_t democracy_undelegate_V8;
    pd_democracy_clear_public_proposals_V8_t democracy_clear_public_proposals_V8;
    pd_democracy_note_preimage_V8_t democracy_note_preimage_V8;
    pd_democracy_note_preimage_operational_V8_t democracy_note_preimage_operational_V8;
    pd_democracy_note_imminent_preimage_V8_t democracy_note_imminent_preimage_V8;
    pd_democracy_note_imminent_preimage_operational_V8_t democracy_note_imminent_preimage_operational_V8;
    pd_democracy_reap_preimage_V8_t democracy_reap_preimage_V8;
    pd_democracy_unlock_V8_t democracy_unlock_V8;
    pd_democracy_remove_vote_V8_t democracy_remove_vote_V8;
    pd_democracy_remove_other_vote_V8_t democracy_remove_other_vote_V8;
    pd_democracy_enact_proposal_V8_t democracy_enact_proposal_V8;
    pd_democracy_blacklist_V8_t democracy_blacklist_V8;
    pd_democracy_cancel_proposal_V8_t democracy_cancel_proposal_V8;
    pd_council_set_members_V8_t council_set_members_V8;
    pd_council_execute_V8_t council_execute_V8;
    pd_council_propose_V8_t council_propose_V8;
    pd_council_vote_V8_t council_vote_V8;
    pd_council_close_V8_t council_close_V8;
    pd_council_disapprove_proposal_V8_t council_disapprove_proposal_V8;
    pd_technicalcommittee_set_members_V8_t technicalcommittee_set_members_V8;
    pd_technicalcommittee_execute_V8_t technicalcommittee_execute_V8;
    pd_technicalcommittee_propose_V8_t technicalcommittee_propose_V8;
    pd_technicalcommittee_vote_V8_t technicalcommittee_vote_V8;
    pd_technicalcommittee_close_V8_t technicalcommittee_close_V8;
    pd_technicalcommittee_disapprove_proposal_V8_t technicalcommittee_disapprove_proposal_V8;
    pd_phragmenelection_vote_V8_t phragmenelection_vote_V8;
    pd_phragmenelection_remove_voter_V8_t phragmenelection_remove_voter_V8;
    pd_phragmenelection_submit_candidacy_V8_t phragmenelection_submit_candidacy_V8;
    pd_phragmenelection_renounce_candidacy_V8_t phragmenelection_renounce_candidacy_V8;
    pd_phragmenelection_remove_member_V8_t phragmenelection_remove_member_V8;
    pd_phragmenelection_clean_defunct_voters_V8_t phragmenelection_clean_defunct_voters_V8;
    pd_technicalmembership_add_member_V8_t technicalmembership_add_member_V8;
    pd_technicalmembership_remove_member_V8_t technicalmembership_remove_member_V8;
    pd_technicalmembership_swap_member_V8_t technicalmembership_swap_member_V8;
    pd_technicalmembership_reset_members_V8_t technicalmembership_reset_members_V8;
    pd_technicalmembership_change_key_V8_t technicalmembership_change_key_V8;
    pd_technicalmembership_set_prime_V8_t technicalmembership_set_prime_V8;
    pd_technicalmembership_clear_prime_V8_t technicalmembership_clear_prime_V8;
    pd_treasury_propose_spend_V8_t treasury_propose_spend_V8;
    pd_treasury_reject_proposal_V8_t treasury_reject_proposal_V8;
    pd_treasury_approve_proposal_V8_t treasury_approve_proposal_V8;
    pd_claims_claim_V8_t claims_claim_V8;
    pd_claims_mint_claim_V8_t claims_mint_claim_V8;
    pd_claims_claim_attest_V8_t claims_claim_attest_V8;
    pd_claims_attest_V8_t claims_attest_V8;
    pd_claims_move_claim_V8_t claims_move_claim_V8;
    pd_vesting_vest_V8_t vesting_vest_V8;
    pd_vesting_vest_other_V8_t vesting_vest_other_V8;
    pd_vesting_vested_transfer_V8_t vesting_vested_transfer_V8;
    pd_vesting_force_vested_transfer_V8_t vesting_force_vested_transfer_V8;
    pd_utility_as_derivative_V8_t utility_as_derivative_V8;
    pd_identity_add_registrar_V8_t identity_add_registrar_V8;
    pd_identity_set_identity_V8_t identity_set_identity_V8;
    pd_identity_set_subs_V8_t identity_set_subs_V8;
    pd_identity_clear_identity_V8_t identity_clear_identity_V8;
    pd_identity_request_judgement_V8_t identity_request_judgement_V8;
    pd_identity_cancel_request_V8_t identity_cancel_request_V8;
    pd_identity_set_fee_V8_t identity_set_fee_V8;
    pd_identity_set_account_id_V8_t identity_set_account_id_V8;
    pd_identity_set_fields_V8_t identity_set_fields_V8;
    pd_identity_provide_judgement_V8_t identity_provide_judgement_V8;
    pd_identity_kill_identity_V8_t identity_kill_identity_V8;
    pd_identity_add_sub_V8_t identity_add_sub_V8;
    pd_identity_rename_sub_V8_t identity_rename_sub_V8;
    pd_identity_remove_sub_V8_t identity_remove_sub_V8;
    pd_identity_quit_sub_V8_t identity_quit_sub_V8;
    pd_proxy_add_proxy_V8_t proxy_add_proxy_V8;
    pd_proxy_remove_proxy_V8_t proxy_remove_proxy_V8;
    pd_proxy_remove_proxies_V8_t proxy_remove_proxies_V8;
    pd_proxy_anonymous_V8_t proxy_anonymous_V8;
    pd_proxy_kill_anonymous_V8_t proxy_kill_anonymous_V8;
    pd_proxy_announce_V8_t proxy_announce_V8;
    pd_proxy_remove_announcement_V8_t proxy_remove_announcement_V8;
    pd_proxy_reject_announcement_V8_t proxy_reject_announcement_V8;
    pd_proxy_proxy_announced_V8_t proxy_proxy_announced_V8;
    pd_bounties_propose_bounty_V8_t bounties_propose_bounty_V8;
    pd_bounties_approve_bounty_V8_t bounties_approve_bounty_V8;
    pd_bounties_propose_curator_V8_t bounties_propose_curator_V8;
    pd_bounties_unassign_curator_V8_t bounties_unassign_curator_V8;
    pd_bounties_accept_curator_V8_t bounties_accept_curator_V8;
    pd_bounties_award_bounty_V8_t bounties_award_bounty_V8;
    pd_bounties_claim_bounty_V8_t bounties_claim_bounty_V8;
    pd_bounties_close_bounty_V8_t bounties_close_bounty_V8;
    pd_bounties_extend_bounty_expiry_V8_t bounties_extend_bounty_expiry_V8;
    pd_tips_report_awesome_V8_t tips_report_awesome_V8;
    pd_tips_retract_tip_V8_t tips_retract_tip_V8;
    pd_tips_tip_new_V8_t tips_tip_new_V8;
    pd_tips_tip_V8_t tips_tip_V8;
    pd_tips_close_tip_V8_t tips_close_tip_V8;
    pd_tips_slash_tip_V8_t tips_slash_tip_V8;
    pd_electionprovidermultiphase_submit_unsigned_V8_t electionprovidermultiphase_submit_unsigned_V8;
    pd_electionprovidermultiphase_set_minimum_untrusted_score_V8_t electionprovidermultiphase_set_minimum_untrusted_score_V8;
    pd_electionprovidermultiphase_set_emergency_election_result_V8_t electionprovidermultiphase_set_emergency_election_result_V8;
    pd_electionprovidermultiphase_submit_V8_t electionprovidermultiphase_submit_V8;
#endif
} pd_MethodBasic_V8_t;

#define PD_CALL_BALANCES_TRANSFER_V8 0
typedef struct {
    pd_LookupSource_V8_t dest;
    pd_CompactBalance_t value;
} pd_balances_transfer_V8_t;

#define PD_CALL_BALANCES_TRANSFER_KEEP_ALIVE_V8 3
typedef struct {
    pd_LookupSource_V8_t dest;
    pd_CompactBalance_t value;
} pd_balances_transfer_keep_alive_V8_t;

#ifdef SUBSTRATE_PARSER_FULL
#define PD_CALL_SYSTEM_FILL_BLOCK_V8 0
typedef struct {
    pd_Perbill_V8_t _ratio;
} pd_system_fill_block_V8_t;

#define PD_CALL_SYSTEM_REMARK_V8 1
typedef struct {
    pd_Bytes_t _remark;
} pd_system_remark_V8_t;

#define PD_CALL_SYSTEM_SET_HEAP_PAGES_V8 2
typedef struct {
    pd_u64_t pages;
} pd_system_set_heap_pages_V8_t;

#define PD_CALL_SYSTEM_SET_CODE_V8 3
typedef struct {
    pd_Bytes_t code;
} pd_system_set_code_V8_t;

#define PD_CALL_SYSTEM_SET_CODE_WITHOUT_CHECKS_V8 4
typedef struct {
    pd_Bytes_t code;
} pd_system_set_code_without_checks_V8_t;

#define PD_CALL_SYSTEM_SET_CHANGES_TRIE_CONFIG_V8 5
typedef struct {
    pd_OptionChangesTrieConfiguration_V8_t changes_trie_config;
} pd_system_set_changes_trie_config_V8_t;

#define PD_CALL_SYSTEM_SET_STORAGE_V8 6
typedef struct {
    pd_VecKeyValue_V8_t items;
} pd_system_set_storage_V8_t;

#define PD_CALL_SYSTEM_KILL_STORAGE_V8 7
typedef struct {
    pd_VecKey_V8_t keys;
} pd_system_kill_storage_V8_t;

#define PD_CALL_SYSTEM_KILL_PREFIX_V8 8
typedef struct {
    pd_Key_V8_t prefix;
    pd_u32_t _subkeys;
} pd_system_kill_prefix_V8_t;

#define PD_CALL_BALANCES_SET_BALANCE_V8 1
typedef struct {
    pd_LookupSource_V8_t who;
    pd_CompactBalance_t new_free;
    pd_CompactBalance_t new_reserved;
} pd_balances_set_balance_V8_t;

#define PD_CALL_BALANCES_FORCE_TRANSFER_V8 2
typedef struct {
    pd_LookupSource_V8_t source;
    pd_LookupSource_V8_t dest;
    pd_CompactBalance_t value;
} pd_balances_force_transfer_V8_t;

#define PD_CALL_PROXY_PROXY_V8 0
typedef struct {
    pd_AccountId_V8_t real;
    pd_OptionProxyType_V8_t force_proxy_type;
    pd_Call_t call;
} pd_proxy_proxy_V8_t;

#define PD_CALL_MULTISIG_AS_MULTI_THRESHOLD_1_V8 0
typedef struct {
    pd_VecAccountId_V8_t other_signatories;
    pd_Call_t call;
} pd_multisig_as_multi_threshold_1_V8_t;

#define PD_CALL_MULTISIG_AS_MULTI_V8 1
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_V8_t other_signatories;
    pd_OptionTimepoint_V8_t maybe_timepoint;
    pd_OpaqueCall_V8_t call;
    pd_bool_t store_call;
    pd_Weight_V8_t max_weight;
} pd_multisig_as_multi_V8_t;

#define PD_CALL_MULTISIG_APPROVE_AS_MULTI_V8 2
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_V8_t other_signatories;
    pd_OptionTimepoint_V8_t maybe_timepoint;
    pd_u8_array_32_V8_t call_hash;
    pd_Weight_V8_t max_weight;
} pd_multisig_approve_as_multi_V8_t;

#define PD_CALL_MULTISIG_CANCEL_AS_MULTI_V8 3
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_V8_t other_signatories;
    pd_Timepoint_V8_t timepoint;
    pd_u8_array_32_V8_t call_hash;
} pd_multisig_cancel_as_multi_V8_t;

#endif

typedef union {
    pd_balances_transfer_V8_t balances_transfer_V8;
    pd_balances_transfer_keep_alive_V8_t balances_transfer_keep_alive_V8;
#ifdef SUBSTRATE_PARSER_FULL
    pd_system_fill_block_V8_t system_fill_block_V8;
    pd_system_remark_V8_t system_remark_V8;
    pd_system_set_heap_pages_V8_t system_set_heap_pages_V8;
    pd_system_set_code_V8_t system_set_code_V8;
    pd_system_set_code_without_checks_V8_t system_set_code_without_checks_V8;
    pd_system_set_changes_trie_config_V8_t system_set_changes_trie_config_V8;
    pd_system_set_storage_V8_t system_set_storage_V8;
    pd_system_kill_storage_V8_t system_kill_storage_V8;
    pd_system_kill_prefix_V8_t system_kill_prefix_V8;
    pd_balances_set_balance_V8_t balances_set_balance_V8;
    pd_balances_force_transfer_V8_t balances_force_transfer_V8;
    pd_proxy_proxy_V8_t proxy_proxy_V8;
    pd_multisig_as_multi_threshold_1_V8_t multisig_as_multi_threshold_1_V8;
    pd_multisig_as_multi_V8_t multisig_as_multi_V8;
    pd_multisig_approve_as_multi_V8_t multisig_approve_as_multi_V8;
    pd_multisig_cancel_as_multi_V8_t multisig_cancel_as_multi_V8;
#endif
} pd_MethodNested_V8_t;

typedef union {
    pd_MethodBasic_V8_t basic;
    pd_MethodNested_V8_t nested;
} pd_Method_V8_t;

#ifdef __cplusplus
}
#endif

#pragma clang diagnostic pop
