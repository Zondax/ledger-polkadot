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
#include "substrate_types_V7.h"
#include <stddef.h>
#include <stdint.h>

#define PD_CALL_SYSTEM_V7 0
#define PD_CALL_SCHEDULER_V7 1
#define PD_CALL_BABE_V7 2
#define PD_CALL_TIMESTAMP_V7 3
#define PD_CALL_INDICES_V7 4
#define PD_CALL_BALANCES_V7 5
#define PD_CALL_AUTHORSHIP_V7 6
#define PD_CALL_STAKING_V7 7
#define PD_CALL_OFFENCES_V7 8
#define PD_CALL_SESSION_V7 9
#define PD_CALL_GRANDPA_V7 11
#define PD_CALL_IMONLINE_V7 12
#define PD_CALL_AUTHORITYDISCOVERY_V7 13
#define PD_CALL_DEMOCRACY_V7 14
#define PD_CALL_COUNCIL_V7 15
#define PD_CALL_TECHNICALCOMMITTEE_V7 16
#define PD_CALL_ELECTIONSPHRAGMEN_V7 17
#define PD_CALL_TECHNICALMEMBERSHIP_V7 18
#define PD_CALL_TREASURY_V7 19
#define PD_CALL_CLAIMS_V7 24
#define PD_CALL_VESTING_V7 25
#define PD_CALL_UTILITY_V7 26
#define PD_CALL_IDENTITY_V7 28
#define PD_CALL_PROXY_V7 29
#define PD_CALL_MULTISIG_V7 30
#define PD_CALL_BOUNTIES_V7 34
#define PD_CALL_TIPS_V7 35
#define PD_CALL_ELECTIONPROVIDERMULTIPHASE_V7 36

#define PD_CALL_STAKING_BOND_V7 0
typedef struct {
    pd_LookupSource_V7_t controller;
    pd_CompactBalanceOf_t value;
    pd_RewardDestination_V7_t payee;
} pd_staking_bond_V7_t;

#define PD_CALL_STAKING_BOND_EXTRA_V7 1
typedef struct {
    pd_CompactBalanceOf_t max_additional;
} pd_staking_bond_extra_V7_t;

#define PD_CALL_STAKING_UNBOND_V7 2
typedef struct {
    pd_CompactBalanceOf_t value;
} pd_staking_unbond_V7_t;

#define PD_CALL_STAKING_WITHDRAW_UNBONDED_V7 3
typedef struct {
    pd_u32_t num_slashing_spans;
} pd_staking_withdraw_unbonded_V7_t;

#define PD_CALL_STAKING_VALIDATE_V7 4
typedef struct {
    pd_ValidatorPrefs_V7_t prefs;
} pd_staking_validate_V7_t;

#define PD_CALL_STAKING_NOMINATE_V7 5
typedef struct {
    pd_VecLookupSource_V7_t targets;
} pd_staking_nominate_V7_t;

#define PD_CALL_STAKING_CHILL_V7 6
typedef struct {
} pd_staking_chill_V7_t;

#define PD_CALL_STAKING_SET_PAYEE_V7 7
typedef struct {
    pd_RewardDestination_V7_t payee;
} pd_staking_set_payee_V7_t;

#define PD_CALL_STAKING_PAYOUT_STAKERS_V7 18
typedef struct {
    pd_AccountId_V7_t validator_stash;
    pd_EraIndex_V7_t era;
} pd_staking_payout_stakers_V7_t;

#define PD_CALL_STAKING_REBOND_V7 19
typedef struct {
    pd_CompactBalanceOf_t value;
} pd_staking_rebond_V7_t;

#define PD_CALL_SESSION_SET_KEYS_V7 0
typedef struct {
    pd_Keys_V7_t keys;
    pd_Bytes_t proof;
} pd_session_set_keys_V7_t;

#define PD_CALL_SESSION_PURGE_KEYS_V7 1
typedef struct {
} pd_session_purge_keys_V7_t;

#define PD_CALL_UTILITY_BATCH_V7 0
typedef struct {
    pd_VecCall_t calls;
} pd_utility_batch_V7_t;

#define PD_CALL_UTILITY_BATCH_ALL_V7 2
typedef struct {
    pd_VecCall_t calls;
} pd_utility_batch_all_V7_t;

#ifdef SUBSTRATE_PARSER_FULL
#define PD_CALL_SYSTEM_REMARK_WITH_EVENT_V7 9
typedef struct {
    pd_Bytes_t remark;
} pd_system_remark_with_event_V7_t;

#define PD_CALL_SCHEDULER_SCHEDULE_V7 0
typedef struct {
    pd_BlockNumber_t when;
    pd_OptionPeriod_V7_t maybe_periodic;
    pd_Priority_V7_t priority;
    pd_Call_t call;
} pd_scheduler_schedule_V7_t;

#define PD_CALL_SCHEDULER_CANCEL_V7 1
typedef struct {
    pd_BlockNumber_t when;
    pd_u32_t index;
} pd_scheduler_cancel_V7_t;

#define PD_CALL_SCHEDULER_SCHEDULE_NAMED_V7 2
typedef struct {
    pd_Bytes_t id;
    pd_BlockNumber_t when;
    pd_OptionPeriod_V7_t maybe_periodic;
    pd_Priority_V7_t priority;
    pd_Call_t call;
} pd_scheduler_schedule_named_V7_t;

#define PD_CALL_SCHEDULER_CANCEL_NAMED_V7 3
typedef struct {
    pd_Bytes_t id;
} pd_scheduler_cancel_named_V7_t;

#define PD_CALL_SCHEDULER_SCHEDULE_AFTER_V7 4
typedef struct {
    pd_BlockNumber_t after;
    pd_OptionPeriod_V7_t maybe_periodic;
    pd_Priority_V7_t priority;
    pd_Call_t call;
} pd_scheduler_schedule_after_V7_t;

#define PD_CALL_SCHEDULER_SCHEDULE_NAMED_AFTER_V7 5
typedef struct {
    pd_Bytes_t id;
    pd_BlockNumber_t after;
    pd_OptionPeriod_V7_t maybe_periodic;
    pd_Priority_V7_t priority;
    pd_Call_t call;
} pd_scheduler_schedule_named_after_V7_t;

#define PD_CALL_BABE_REPORT_EQUIVOCATION_V7 0
typedef struct {
    pd_BabeEquivocationProof_V7_t equivocation_proof;
    pd_KeyOwnerProof_V7_t key_owner_proof;
} pd_babe_report_equivocation_V7_t;

#define PD_CALL_BABE_REPORT_EQUIVOCATION_UNSIGNED_V7 1
typedef struct {
    pd_BabeEquivocationProof_V7_t equivocation_proof;
    pd_KeyOwnerProof_V7_t key_owner_proof;
} pd_babe_report_equivocation_unsigned_V7_t;

#define PD_CALL_BABE_PLAN_CONFIG_CHANGE_V7 2
typedef struct {
    pd_NextConfigDescriptor_V7_t config;
} pd_babe_plan_config_change_V7_t;

#define PD_CALL_TIMESTAMP_SET_V7 0
typedef struct {
    pd_CompactMoment_V7_t now;
} pd_timestamp_set_V7_t;

#define PD_CALL_INDICES_CLAIM_V7 0
typedef struct {
    pd_AccountIndex_V7_t index;
} pd_indices_claim_V7_t;

#define PD_CALL_INDICES_TRANSFER_V7 1
typedef struct {
    pd_AccountId_V7_t new_;
    pd_AccountIndex_V7_t index;
} pd_indices_transfer_V7_t;

#define PD_CALL_INDICES_FREE_V7 2
typedef struct {
    pd_AccountIndex_V7_t index;
} pd_indices_free_V7_t;

#define PD_CALL_INDICES_FORCE_TRANSFER_V7 3
typedef struct {
    pd_AccountId_V7_t new_;
    pd_AccountIndex_V7_t index;
    pd_bool_t freeze;
} pd_indices_force_transfer_V7_t;

#define PD_CALL_INDICES_FREEZE_V7 4
typedef struct {
    pd_AccountIndex_V7_t index;
} pd_indices_freeze_V7_t;

#define PD_CALL_AUTHORSHIP_SET_UNCLES_V7 0
typedef struct {
    pd_VecHeader_t new_uncles;
} pd_authorship_set_uncles_V7_t;

#define PD_CALL_STAKING_SET_CONTROLLER_V7 8
typedef struct {
    pd_LookupSource_V7_t controller;
} pd_staking_set_controller_V7_t;

#define PD_CALL_STAKING_SET_VALIDATOR_COUNT_V7 9
typedef struct {
    pd_Compactu32_t new_;
} pd_staking_set_validator_count_V7_t;

#define PD_CALL_STAKING_INCREASE_VALIDATOR_COUNT_V7 10
typedef struct {
    pd_Compactu32_t additional;
} pd_staking_increase_validator_count_V7_t;

#define PD_CALL_STAKING_SCALE_VALIDATOR_COUNT_V7 11
typedef struct {
    pd_Percent_V7_t factor;
} pd_staking_scale_validator_count_V7_t;

#define PD_CALL_STAKING_FORCE_NO_ERAS_V7 12
typedef struct {
} pd_staking_force_no_eras_V7_t;

#define PD_CALL_STAKING_FORCE_NEW_ERA_V7 13
typedef struct {
} pd_staking_force_new_era_V7_t;

#define PD_CALL_STAKING_SET_INVULNERABLES_V7 14
typedef struct {
    pd_VecAccountId_V7_t invulnerables;
} pd_staking_set_invulnerables_V7_t;

#define PD_CALL_STAKING_FORCE_UNSTAKE_V7 15
typedef struct {
    pd_AccountId_V7_t stash;
    pd_u32_t num_slashing_spans;
} pd_staking_force_unstake_V7_t;

#define PD_CALL_STAKING_FORCE_NEW_ERA_ALWAYS_V7 16
typedef struct {
} pd_staking_force_new_era_always_V7_t;

#define PD_CALL_STAKING_CANCEL_DEFERRED_SLASH_V7 17
typedef struct {
    pd_EraIndex_V7_t era;
    pd_Vecu32_t slash_indices;
} pd_staking_cancel_deferred_slash_V7_t;

#define PD_CALL_STAKING_SET_HISTORY_DEPTH_V7 20
typedef struct {
    pd_CompactEraIndex_V7_t new_history_depth;
    pd_Compactu32_t _era_items_deleted;
} pd_staking_set_history_depth_V7_t;

#define PD_CALL_STAKING_REAP_STASH_V7 21
typedef struct {
    pd_AccountId_V7_t stash;
    pd_u32_t num_slashing_spans;
} pd_staking_reap_stash_V7_t;

#define PD_CALL_STAKING_KICK_V7 22
typedef struct {
    pd_VecLookupSource_V7_t who;
} pd_staking_kick_V7_t;

#define PD_CALL_GRANDPA_REPORT_EQUIVOCATION_V7 0
typedef struct {
    pd_GrandpaEquivocationProof_V7_t equivocation_proof;
    pd_KeyOwnerProof_V7_t key_owner_proof;
} pd_grandpa_report_equivocation_V7_t;

#define PD_CALL_GRANDPA_REPORT_EQUIVOCATION_UNSIGNED_V7 1
typedef struct {
    pd_GrandpaEquivocationProof_V7_t equivocation_proof;
    pd_KeyOwnerProof_V7_t key_owner_proof;
} pd_grandpa_report_equivocation_unsigned_V7_t;

#define PD_CALL_GRANDPA_NOTE_STALLED_V7 2
typedef struct {
    pd_BlockNumber_t delay;
    pd_BlockNumber_t best_finalized_block_number;
} pd_grandpa_note_stalled_V7_t;

#define PD_CALL_IMONLINE_HEARTBEAT_V7 0
typedef struct {
    pd_Heartbeat_t heartbeat;
    pd_Signature_V7_t _signature;
} pd_imonline_heartbeat_V7_t;

#define PD_CALL_DEMOCRACY_PROPOSE_V7 0
typedef struct {
    pd_Hash_t proposal_hash;
    pd_CompactBalanceOf_t value;
} pd_democracy_propose_V7_t;

#define PD_CALL_DEMOCRACY_SECOND_V7 1
typedef struct {
    pd_CompactPropIndex_V7_t proposal;
    pd_Compactu32_t seconds_upper_bound;
} pd_democracy_second_V7_t;

#define PD_CALL_DEMOCRACY_VOTE_V7 2
typedef struct {
    pd_CompactReferendumIndex_V7_t ref_index;
    pd_AccountVote_V7_t vote;
} pd_democracy_vote_V7_t;

#define PD_CALL_DEMOCRACY_EMERGENCY_CANCEL_V7 3
typedef struct {
    pd_ReferendumIndex_V7_t ref_index;
} pd_democracy_emergency_cancel_V7_t;

#define PD_CALL_DEMOCRACY_EXTERNAL_PROPOSE_V7 4
typedef struct {
    pd_Hash_t proposal_hash;
} pd_democracy_external_propose_V7_t;

#define PD_CALL_DEMOCRACY_EXTERNAL_PROPOSE_MAJORITY_V7 5
typedef struct {
    pd_Hash_t proposal_hash;
} pd_democracy_external_propose_majority_V7_t;

#define PD_CALL_DEMOCRACY_EXTERNAL_PROPOSE_DEFAULT_V7 6
typedef struct {
    pd_Hash_t proposal_hash;
} pd_democracy_external_propose_default_V7_t;

#define PD_CALL_DEMOCRACY_FAST_TRACK_V7 7
typedef struct {
    pd_Hash_t proposal_hash;
    pd_BlockNumber_t voting_period;
    pd_BlockNumber_t delay;
} pd_democracy_fast_track_V7_t;

#define PD_CALL_DEMOCRACY_VETO_EXTERNAL_V7 8
typedef struct {
    pd_Hash_t proposal_hash;
} pd_democracy_veto_external_V7_t;

#define PD_CALL_DEMOCRACY_CANCEL_REFERENDUM_V7 9
typedef struct {
    pd_CompactReferendumIndex_V7_t ref_index;
} pd_democracy_cancel_referendum_V7_t;

#define PD_CALL_DEMOCRACY_CANCEL_QUEUED_V7 10
typedef struct {
    pd_ReferendumIndex_V7_t which;
} pd_democracy_cancel_queued_V7_t;

#define PD_CALL_DEMOCRACY_DELEGATE_V7 11
typedef struct {
    pd_AccountId_V7_t to;
    pd_Conviction_V7_t conviction;
    pd_BalanceOf_t balance;
} pd_democracy_delegate_V7_t;

#define PD_CALL_DEMOCRACY_UNDELEGATE_V7 12
typedef struct {
} pd_democracy_undelegate_V7_t;

#define PD_CALL_DEMOCRACY_CLEAR_PUBLIC_PROPOSALS_V7 13
typedef struct {
} pd_democracy_clear_public_proposals_V7_t;

#define PD_CALL_DEMOCRACY_NOTE_PREIMAGE_V7 14
typedef struct {
    pd_Bytes_t encoded_proposal;
} pd_democracy_note_preimage_V7_t;

#define PD_CALL_DEMOCRACY_NOTE_PREIMAGE_OPERATIONAL_V7 15
typedef struct {
    pd_Bytes_t encoded_proposal;
} pd_democracy_note_preimage_operational_V7_t;

#define PD_CALL_DEMOCRACY_NOTE_IMMINENT_PREIMAGE_V7 16
typedef struct {
    pd_Bytes_t encoded_proposal;
} pd_democracy_note_imminent_preimage_V7_t;

#define PD_CALL_DEMOCRACY_NOTE_IMMINENT_PREIMAGE_OPERATIONAL_V7 17
typedef struct {
    pd_Bytes_t encoded_proposal;
} pd_democracy_note_imminent_preimage_operational_V7_t;

#define PD_CALL_DEMOCRACY_REAP_PREIMAGE_V7 18
typedef struct {
    pd_Hash_t proposal_hash;
    pd_Compactu32_t proposal_len_upper_bound;
} pd_democracy_reap_preimage_V7_t;

#define PD_CALL_DEMOCRACY_UNLOCK_V7 19
typedef struct {
    pd_AccountId_V7_t target;
} pd_democracy_unlock_V7_t;

#define PD_CALL_DEMOCRACY_REMOVE_VOTE_V7 20
typedef struct {
    pd_ReferendumIndex_V7_t index;
} pd_democracy_remove_vote_V7_t;

#define PD_CALL_DEMOCRACY_REMOVE_OTHER_VOTE_V7 21
typedef struct {
    pd_AccountId_V7_t target;
    pd_ReferendumIndex_V7_t index;
} pd_democracy_remove_other_vote_V7_t;

#define PD_CALL_DEMOCRACY_ENACT_PROPOSAL_V7 22
typedef struct {
    pd_Hash_t proposal_hash;
    pd_ReferendumIndex_V7_t index;
} pd_democracy_enact_proposal_V7_t;

#define PD_CALL_DEMOCRACY_BLACKLIST_V7 23
typedef struct {
    pd_Hash_t proposal_hash;
    pd_OptionReferendumIndex_V7_t maybe_ref_index;
} pd_democracy_blacklist_V7_t;

#define PD_CALL_DEMOCRACY_CANCEL_PROPOSAL_V7 24
typedef struct {
    pd_CompactPropIndex_V7_t prop_index;
} pd_democracy_cancel_proposal_V7_t;

#define PD_CALL_COUNCIL_SET_MEMBERS_V7 0
typedef struct {
    pd_VecAccountId_V7_t new_members;
    pd_OptionAccountId_V7_t prime;
    pd_MemberCount_V7_t old_count;
} pd_council_set_members_V7_t;

#define PD_CALL_COUNCIL_EXECUTE_V7 1
typedef struct {
    pd_Proposal_t proposal;
    pd_Compactu32_t length_bound;
} pd_council_execute_V7_t;

#define PD_CALL_COUNCIL_PROPOSE_V7 2
typedef struct {
    pd_CompactMemberCount_V7_t threshold;
    pd_Proposal_t proposal;
    pd_Compactu32_t length_bound;
} pd_council_propose_V7_t;

#define PD_CALL_COUNCIL_VOTE_V7 3
typedef struct {
    pd_Hash_t proposal;
    pd_CompactProposalIndex_V7_t index;
    pd_bool_t approve;
} pd_council_vote_V7_t;

#define PD_CALL_COUNCIL_CLOSE_V7 4
typedef struct {
    pd_Hash_t proposal_hash;
    pd_CompactProposalIndex_V7_t index;
    pd_CompactWeight_V7_t proposal_weight_bound;
    pd_Compactu32_t length_bound;
} pd_council_close_V7_t;

#define PD_CALL_COUNCIL_DISAPPROVE_PROPOSAL_V7 5
typedef struct {
    pd_Hash_t proposal_hash;
} pd_council_disapprove_proposal_V7_t;

#define PD_CALL_TECHNICALCOMMITTEE_SET_MEMBERS_V7 0
typedef struct {
    pd_VecAccountId_V7_t new_members;
    pd_OptionAccountId_V7_t prime;
    pd_MemberCount_V7_t old_count;
} pd_technicalcommittee_set_members_V7_t;

#define PD_CALL_TECHNICALCOMMITTEE_EXECUTE_V7 1
typedef struct {
    pd_Proposal_t proposal;
    pd_Compactu32_t length_bound;
} pd_technicalcommittee_execute_V7_t;

#define PD_CALL_TECHNICALCOMMITTEE_PROPOSE_V7 2
typedef struct {
    pd_CompactMemberCount_V7_t threshold;
    pd_Proposal_t proposal;
    pd_Compactu32_t length_bound;
} pd_technicalcommittee_propose_V7_t;

#define PD_CALL_TECHNICALCOMMITTEE_VOTE_V7 3
typedef struct {
    pd_Hash_t proposal;
    pd_CompactProposalIndex_V7_t index;
    pd_bool_t approve;
} pd_technicalcommittee_vote_V7_t;

#define PD_CALL_TECHNICALCOMMITTEE_CLOSE_V7 4
typedef struct {
    pd_Hash_t proposal_hash;
    pd_CompactProposalIndex_V7_t index;
    pd_CompactWeight_V7_t proposal_weight_bound;
    pd_Compactu32_t length_bound;
} pd_technicalcommittee_close_V7_t;

#define PD_CALL_TECHNICALCOMMITTEE_DISAPPROVE_PROPOSAL_V7 5
typedef struct {
    pd_Hash_t proposal_hash;
} pd_technicalcommittee_disapprove_proposal_V7_t;

#define PD_CALL_ELECTIONSPHRAGMEN_VOTE_V7 0
typedef struct {
    pd_VecAccountId_V7_t votes;
    pd_CompactBalanceOf_t value;
} pd_electionsphragmen_vote_V7_t;

#define PD_CALL_ELECTIONSPHRAGMEN_REMOVE_VOTER_V7 1
typedef struct {
} pd_electionsphragmen_remove_voter_V7_t;

#define PD_CALL_ELECTIONSPHRAGMEN_SUBMIT_CANDIDACY_V7 2
typedef struct {
    pd_Compactu32_t candidate_count;
} pd_electionsphragmen_submit_candidacy_V7_t;

#define PD_CALL_ELECTIONSPHRAGMEN_RENOUNCE_CANDIDACY_V7 3
typedef struct {
    pd_Renouncing_V7_t renouncing;
} pd_electionsphragmen_renounce_candidacy_V7_t;

#define PD_CALL_ELECTIONSPHRAGMEN_REMOVE_MEMBER_V7 4
typedef struct {
    pd_LookupSource_V7_t who;
    pd_bool_t has_replacement;
} pd_electionsphragmen_remove_member_V7_t;

#define PD_CALL_ELECTIONSPHRAGMEN_CLEAN_DEFUNCT_VOTERS_V7 5
typedef struct {
    pd_u32_t _num_voters;
    pd_u32_t _num_defunct;
} pd_electionsphragmen_clean_defunct_voters_V7_t;

#define PD_CALL_TECHNICALMEMBERSHIP_ADD_MEMBER_V7 0
typedef struct {
    pd_AccountId_V7_t who;
} pd_technicalmembership_add_member_V7_t;

#define PD_CALL_TECHNICALMEMBERSHIP_REMOVE_MEMBER_V7 1
typedef struct {
    pd_AccountId_V7_t who;
} pd_technicalmembership_remove_member_V7_t;

#define PD_CALL_TECHNICALMEMBERSHIP_SWAP_MEMBER_V7 2
typedef struct {
    pd_AccountId_V7_t remove;
    pd_AccountId_V7_t add;
} pd_technicalmembership_swap_member_V7_t;

#define PD_CALL_TECHNICALMEMBERSHIP_RESET_MEMBERS_V7 3
typedef struct {
    pd_VecAccountId_V7_t members;
} pd_technicalmembership_reset_members_V7_t;

#define PD_CALL_TECHNICALMEMBERSHIP_CHANGE_KEY_V7 4
typedef struct {
    pd_AccountId_V7_t new_;
} pd_technicalmembership_change_key_V7_t;

#define PD_CALL_TECHNICALMEMBERSHIP_SET_PRIME_V7 5
typedef struct {
    pd_AccountId_V7_t who;
} pd_technicalmembership_set_prime_V7_t;

#define PD_CALL_TECHNICALMEMBERSHIP_CLEAR_PRIME_V7 6
typedef struct {
} pd_technicalmembership_clear_prime_V7_t;

#define PD_CALL_TREASURY_PROPOSE_SPEND_V7 0
typedef struct {
    pd_CompactBalanceOf_t value;
    pd_LookupSource_V7_t beneficiary;
} pd_treasury_propose_spend_V7_t;

#define PD_CALL_TREASURY_REJECT_PROPOSAL_V7 1
typedef struct {
    pd_CompactProposalIndex_V7_t proposal_id;
} pd_treasury_reject_proposal_V7_t;

#define PD_CALL_TREASURY_APPROVE_PROPOSAL_V7 2
typedef struct {
    pd_CompactProposalIndex_V7_t proposal_id;
} pd_treasury_approve_proposal_V7_t;

#define PD_CALL_CLAIMS_CLAIM_V7 0
typedef struct {
    pd_AccountId_V7_t dest;
    pd_EcdsaSignature_V7_t ethereum_signature;
} pd_claims_claim_V7_t;

#define PD_CALL_CLAIMS_MINT_CLAIM_V7 1
typedef struct {
    pd_EthereumAddress_V7_t who;
    pd_BalanceOf_t value;
    pd_OptionTupleBalanceOfBalanceOfBlockNumber_V7_t vesting_schedule;
    pd_OptionStatementKind_V7_t statement;
} pd_claims_mint_claim_V7_t;

#define PD_CALL_CLAIMS_CLAIM_ATTEST_V7 2
typedef struct {
    pd_AccountId_V7_t dest;
    pd_EcdsaSignature_V7_t ethereum_signature;
    pd_Bytes_t statement;
} pd_claims_claim_attest_V7_t;

#define PD_CALL_CLAIMS_ATTEST_V7 3
typedef struct {
    pd_Bytes_t statement;
} pd_claims_attest_V7_t;

#define PD_CALL_CLAIMS_MOVE_CLAIM_V7 4
typedef struct {
    pd_EthereumAddress_V7_t old;
    pd_EthereumAddress_V7_t new_;
    pd_OptionAccountId_V7_t maybe_preclaim;
} pd_claims_move_claim_V7_t;

#define PD_CALL_VESTING_VEST_V7 0
typedef struct {
} pd_vesting_vest_V7_t;

#define PD_CALL_VESTING_VEST_OTHER_V7 1
typedef struct {
    pd_LookupSource_V7_t target;
} pd_vesting_vest_other_V7_t;

#define PD_CALL_VESTING_VESTED_TRANSFER_V7 2
typedef struct {
    pd_LookupSource_V7_t target;
    pd_VestingInfo_V7_t schedule;
} pd_vesting_vested_transfer_V7_t;

#define PD_CALL_VESTING_FORCE_VESTED_TRANSFER_V7 3
typedef struct {
    pd_LookupSource_V7_t source;
    pd_LookupSource_V7_t target;
    pd_VestingInfo_V7_t schedule;
} pd_vesting_force_vested_transfer_V7_t;

#define PD_CALL_UTILITY_AS_DERIVATIVE_V7 1
typedef struct {
    pd_u16_t index;
    pd_Call_t call;
} pd_utility_as_derivative_V7_t;

#define PD_CALL_IDENTITY_ADD_REGISTRAR_V7 0
typedef struct {
    pd_AccountId_V7_t account;
} pd_identity_add_registrar_V7_t;

#define PD_CALL_IDENTITY_SET_IDENTITY_V7 1
typedef struct {
    pd_IdentityInfo_V7_t info;
} pd_identity_set_identity_V7_t;

#define PD_CALL_IDENTITY_SET_SUBS_V7 2
typedef struct {
    pd_VecTupleAccountIdData_V7_t subs;
} pd_identity_set_subs_V7_t;

#define PD_CALL_IDENTITY_CLEAR_IDENTITY_V7 3
typedef struct {
} pd_identity_clear_identity_V7_t;

#define PD_CALL_IDENTITY_REQUEST_JUDGEMENT_V7 4
typedef struct {
    pd_CompactRegistrarIndex_V7_t reg_index;
    pd_CompactBalanceOf_t max_fee;
} pd_identity_request_judgement_V7_t;

#define PD_CALL_IDENTITY_CANCEL_REQUEST_V7 5
typedef struct {
    pd_RegistrarIndex_V7_t reg_index;
} pd_identity_cancel_request_V7_t;

#define PD_CALL_IDENTITY_SET_FEE_V7 6
typedef struct {
    pd_CompactRegistrarIndex_V7_t index;
    pd_CompactBalanceOf_t fee;
} pd_identity_set_fee_V7_t;

#define PD_CALL_IDENTITY_SET_ACCOUNT_ID_V7 7
typedef struct {
    pd_CompactRegistrarIndex_V7_t index;
    pd_AccountId_V7_t new_;
} pd_identity_set_account_id_V7_t;

#define PD_CALL_IDENTITY_SET_FIELDS_V7 8
typedef struct {
    pd_CompactRegistrarIndex_V7_t index;
    pd_IdentityFields_V7_t fields;
} pd_identity_set_fields_V7_t;

#define PD_CALL_IDENTITY_PROVIDE_JUDGEMENT_V7 9
typedef struct {
    pd_CompactRegistrarIndex_V7_t reg_index;
    pd_LookupSource_V7_t target;
    pd_IdentityJudgement_V7_t judgement;
} pd_identity_provide_judgement_V7_t;

#define PD_CALL_IDENTITY_KILL_IDENTITY_V7 10
typedef struct {
    pd_LookupSource_V7_t target;
} pd_identity_kill_identity_V7_t;

#define PD_CALL_IDENTITY_ADD_SUB_V7 11
typedef struct {
    pd_LookupSource_V7_t sub;
    pd_Data_t data;
} pd_identity_add_sub_V7_t;

#define PD_CALL_IDENTITY_RENAME_SUB_V7 12
typedef struct {
    pd_LookupSource_V7_t sub;
    pd_Data_t data;
} pd_identity_rename_sub_V7_t;

#define PD_CALL_IDENTITY_REMOVE_SUB_V7 13
typedef struct {
    pd_LookupSource_V7_t sub;
} pd_identity_remove_sub_V7_t;

#define PD_CALL_IDENTITY_QUIT_SUB_V7 14
typedef struct {
} pd_identity_quit_sub_V7_t;

#define PD_CALL_PROXY_ADD_PROXY_V7 1
typedef struct {
    pd_AccountId_V7_t delegate;
    pd_ProxyType_V7_t proxy_type;
    pd_BlockNumber_t delay;
} pd_proxy_add_proxy_V7_t;

#define PD_CALL_PROXY_REMOVE_PROXY_V7 2
typedef struct {
    pd_AccountId_V7_t delegate;
    pd_ProxyType_V7_t proxy_type;
    pd_BlockNumber_t delay;
} pd_proxy_remove_proxy_V7_t;

#define PD_CALL_PROXY_REMOVE_PROXIES_V7 3
typedef struct {
} pd_proxy_remove_proxies_V7_t;

#define PD_CALL_PROXY_ANONYMOUS_V7 4
typedef struct {
    pd_ProxyType_V7_t proxy_type;
    pd_BlockNumber_t delay;
    pd_u16_t index;
} pd_proxy_anonymous_V7_t;

#define PD_CALL_PROXY_KILL_ANONYMOUS_V7 5
typedef struct {
    pd_AccountId_V7_t spawner;
    pd_ProxyType_V7_t proxy_type;
    pd_u16_t index;
    pd_CompactBlockNumber_t height;
    pd_Compactu32_t ext_index;
} pd_proxy_kill_anonymous_V7_t;

#define PD_CALL_PROXY_ANNOUNCE_V7 6
typedef struct {
    pd_AccountId_V7_t real;
    pd_CallHashOf_V7_t call_hash;
} pd_proxy_announce_V7_t;

#define PD_CALL_PROXY_REMOVE_ANNOUNCEMENT_V7 7
typedef struct {
    pd_AccountId_V7_t real;
    pd_CallHashOf_V7_t call_hash;
} pd_proxy_remove_announcement_V7_t;

#define PD_CALL_PROXY_REJECT_ANNOUNCEMENT_V7 8
typedef struct {
    pd_AccountId_V7_t delegate;
    pd_CallHashOf_V7_t call_hash;
} pd_proxy_reject_announcement_V7_t;

#define PD_CALL_PROXY_PROXY_ANNOUNCED_V7 9
typedef struct {
    pd_AccountId_V7_t delegate;
    pd_AccountId_V7_t real;
    pd_OptionProxyType_V7_t force_proxy_type;
    pd_Call_t call;
} pd_proxy_proxy_announced_V7_t;

#define PD_CALL_BOUNTIES_PROPOSE_BOUNTY_V7 0
typedef struct {
    pd_CompactBalanceOf_t value;
    pd_Bytes_t description;
} pd_bounties_propose_bounty_V7_t;

#define PD_CALL_BOUNTIES_APPROVE_BOUNTY_V7 1
typedef struct {
    pd_CompactBountyIndex_V7_t bounty_id;
} pd_bounties_approve_bounty_V7_t;

#define PD_CALL_BOUNTIES_PROPOSE_CURATOR_V7 2
typedef struct {
    pd_CompactBountyIndex_V7_t bounty_id;
    pd_LookupSource_V7_t curator;
    pd_CompactBalanceOf_t fee;
} pd_bounties_propose_curator_V7_t;

#define PD_CALL_BOUNTIES_UNASSIGN_CURATOR_V7 3
typedef struct {
    pd_CompactBountyIndex_V7_t bounty_id;
} pd_bounties_unassign_curator_V7_t;

#define PD_CALL_BOUNTIES_ACCEPT_CURATOR_V7 4
typedef struct {
    pd_CompactBountyIndex_V7_t bounty_id;
} pd_bounties_accept_curator_V7_t;

#define PD_CALL_BOUNTIES_AWARD_BOUNTY_V7 5
typedef struct {
    pd_CompactBountyIndex_V7_t bounty_id;
    pd_LookupSource_V7_t beneficiary;
} pd_bounties_award_bounty_V7_t;

#define PD_CALL_BOUNTIES_CLAIM_BOUNTY_V7 6
typedef struct {
    pd_CompactBountyIndex_V7_t bounty_id;
} pd_bounties_claim_bounty_V7_t;

#define PD_CALL_BOUNTIES_CLOSE_BOUNTY_V7 7
typedef struct {
    pd_CompactBountyIndex_V7_t bounty_id;
} pd_bounties_close_bounty_V7_t;

#define PD_CALL_BOUNTIES_EXTEND_BOUNTY_EXPIRY_V7 8
typedef struct {
    pd_CompactBountyIndex_V7_t bounty_id;
    pd_Bytes_t _remark;
} pd_bounties_extend_bounty_expiry_V7_t;

#define PD_CALL_TIPS_REPORT_AWESOME_V7 0
typedef struct {
    pd_Bytes_t reason;
    pd_AccountId_V7_t who;
} pd_tips_report_awesome_V7_t;

#define PD_CALL_TIPS_RETRACT_TIP_V7 1
typedef struct {
    pd_Hash_t hash;
} pd_tips_retract_tip_V7_t;

#define PD_CALL_TIPS_TIP_NEW_V7 2
typedef struct {
    pd_Bytes_t reason;
    pd_AccountId_V7_t who;
    pd_CompactBalanceOf_t tip_value;
} pd_tips_tip_new_V7_t;

#define PD_CALL_TIPS_TIP_V7 3
typedef struct {
    pd_Hash_t hash;
    pd_CompactBalanceOf_t tip_value;
} pd_tips_tip_V7_t;

#define PD_CALL_TIPS_CLOSE_TIP_V7 4
typedef struct {
    pd_Hash_t hash;
} pd_tips_close_tip_V7_t;

#define PD_CALL_TIPS_SLASH_TIP_V7 5
typedef struct {
    pd_Hash_t hash;
} pd_tips_slash_tip_V7_t;

#define PD_CALL_ELECTIONPROVIDERMULTIPHASE_SUBMIT_UNSIGNED_V7 0
typedef struct {
    pd_RawSolution_V7_t solution;
    pd_SolutionOrSnapshotSize_V7_t witness;
} pd_electionprovidermultiphase_submit_unsigned_V7_t;

#endif

typedef union {
    pd_staking_bond_V7_t staking_bond_V7;
    pd_staking_bond_extra_V7_t staking_bond_extra_V7;
    pd_staking_unbond_V7_t staking_unbond_V7;
    pd_staking_withdraw_unbonded_V7_t staking_withdraw_unbonded_V7;
    pd_staking_validate_V7_t staking_validate_V7;
    pd_staking_nominate_V7_t staking_nominate_V7;
    pd_staking_chill_V7_t staking_chill_V7;
    pd_staking_set_payee_V7_t staking_set_payee_V7;
    pd_staking_payout_stakers_V7_t staking_payout_stakers_V7;
    pd_staking_rebond_V7_t staking_rebond_V7;
    pd_session_set_keys_V7_t session_set_keys_V7;
    pd_session_purge_keys_V7_t session_purge_keys_V7;
    pd_utility_batch_V7_t utility_batch_V7;
    pd_utility_batch_all_V7_t utility_batch_all_V7;
#ifdef SUBSTRATE_PARSER_FULL
    pd_system_remark_with_event_V7_t system_remark_with_event_V7;
    pd_scheduler_schedule_V7_t scheduler_schedule_V7;
    pd_scheduler_cancel_V7_t scheduler_cancel_V7;
    pd_scheduler_schedule_named_V7_t scheduler_schedule_named_V7;
    pd_scheduler_cancel_named_V7_t scheduler_cancel_named_V7;
    pd_scheduler_schedule_after_V7_t scheduler_schedule_after_V7;
    pd_scheduler_schedule_named_after_V7_t scheduler_schedule_named_after_V7;
    pd_babe_report_equivocation_V7_t babe_report_equivocation_V7;
    pd_babe_report_equivocation_unsigned_V7_t babe_report_equivocation_unsigned_V7;
    pd_babe_plan_config_change_V7_t babe_plan_config_change_V7;
    pd_timestamp_set_V7_t timestamp_set_V7;
    pd_indices_claim_V7_t indices_claim_V7;
    pd_indices_transfer_V7_t indices_transfer_V7;
    pd_indices_free_V7_t indices_free_V7;
    pd_indices_force_transfer_V7_t indices_force_transfer_V7;
    pd_indices_freeze_V7_t indices_freeze_V7;
    pd_authorship_set_uncles_V7_t authorship_set_uncles_V7;
    pd_staking_set_controller_V7_t staking_set_controller_V7;
    pd_staking_set_validator_count_V7_t staking_set_validator_count_V7;
    pd_staking_increase_validator_count_V7_t staking_increase_validator_count_V7;
    pd_staking_scale_validator_count_V7_t staking_scale_validator_count_V7;
    pd_staking_force_no_eras_V7_t staking_force_no_eras_V7;
    pd_staking_force_new_era_V7_t staking_force_new_era_V7;
    pd_staking_set_invulnerables_V7_t staking_set_invulnerables_V7;
    pd_staking_force_unstake_V7_t staking_force_unstake_V7;
    pd_staking_force_new_era_always_V7_t staking_force_new_era_always_V7;
    pd_staking_cancel_deferred_slash_V7_t staking_cancel_deferred_slash_V7;
    pd_staking_set_history_depth_V7_t staking_set_history_depth_V7;
    pd_staking_reap_stash_V7_t staking_reap_stash_V7;
    pd_staking_kick_V7_t staking_kick_V7;
    pd_grandpa_report_equivocation_V7_t grandpa_report_equivocation_V7;
    pd_grandpa_report_equivocation_unsigned_V7_t grandpa_report_equivocation_unsigned_V7;
    pd_grandpa_note_stalled_V7_t grandpa_note_stalled_V7;
    pd_imonline_heartbeat_V7_t imonline_heartbeat_V7;
    pd_democracy_propose_V7_t democracy_propose_V7;
    pd_democracy_second_V7_t democracy_second_V7;
    pd_democracy_vote_V7_t democracy_vote_V7;
    pd_democracy_emergency_cancel_V7_t democracy_emergency_cancel_V7;
    pd_democracy_external_propose_V7_t democracy_external_propose_V7;
    pd_democracy_external_propose_majority_V7_t democracy_external_propose_majority_V7;
    pd_democracy_external_propose_default_V7_t democracy_external_propose_default_V7;
    pd_democracy_fast_track_V7_t democracy_fast_track_V7;
    pd_democracy_veto_external_V7_t democracy_veto_external_V7;
    pd_democracy_cancel_referendum_V7_t democracy_cancel_referendum_V7;
    pd_democracy_cancel_queued_V7_t democracy_cancel_queued_V7;
    pd_democracy_delegate_V7_t democracy_delegate_V7;
    pd_democracy_undelegate_V7_t democracy_undelegate_V7;
    pd_democracy_clear_public_proposals_V7_t democracy_clear_public_proposals_V7;
    pd_democracy_note_preimage_V7_t democracy_note_preimage_V7;
    pd_democracy_note_preimage_operational_V7_t democracy_note_preimage_operational_V7;
    pd_democracy_note_imminent_preimage_V7_t democracy_note_imminent_preimage_V7;
    pd_democracy_note_imminent_preimage_operational_V7_t democracy_note_imminent_preimage_operational_V7;
    pd_democracy_reap_preimage_V7_t democracy_reap_preimage_V7;
    pd_democracy_unlock_V7_t democracy_unlock_V7;
    pd_democracy_remove_vote_V7_t democracy_remove_vote_V7;
    pd_democracy_remove_other_vote_V7_t democracy_remove_other_vote_V7;
    pd_democracy_enact_proposal_V7_t democracy_enact_proposal_V7;
    pd_democracy_blacklist_V7_t democracy_blacklist_V7;
    pd_democracy_cancel_proposal_V7_t democracy_cancel_proposal_V7;
    pd_council_set_members_V7_t council_set_members_V7;
    pd_council_execute_V7_t council_execute_V7;
    pd_council_propose_V7_t council_propose_V7;
    pd_council_vote_V7_t council_vote_V7;
    pd_council_close_V7_t council_close_V7;
    pd_council_disapprove_proposal_V7_t council_disapprove_proposal_V7;
    pd_technicalcommittee_set_members_V7_t technicalcommittee_set_members_V7;
    pd_technicalcommittee_execute_V7_t technicalcommittee_execute_V7;
    pd_technicalcommittee_propose_V7_t technicalcommittee_propose_V7;
    pd_technicalcommittee_vote_V7_t technicalcommittee_vote_V7;
    pd_technicalcommittee_close_V7_t technicalcommittee_close_V7;
    pd_technicalcommittee_disapprove_proposal_V7_t technicalcommittee_disapprove_proposal_V7;
    pd_electionsphragmen_vote_V7_t electionsphragmen_vote_V7;
    pd_electionsphragmen_remove_voter_V7_t electionsphragmen_remove_voter_V7;
    pd_electionsphragmen_submit_candidacy_V7_t electionsphragmen_submit_candidacy_V7;
    pd_electionsphragmen_renounce_candidacy_V7_t electionsphragmen_renounce_candidacy_V7;
    pd_electionsphragmen_remove_member_V7_t electionsphragmen_remove_member_V7;
    pd_electionsphragmen_clean_defunct_voters_V7_t electionsphragmen_clean_defunct_voters_V7;
    pd_technicalmembership_add_member_V7_t technicalmembership_add_member_V7;
    pd_technicalmembership_remove_member_V7_t technicalmembership_remove_member_V7;
    pd_technicalmembership_swap_member_V7_t technicalmembership_swap_member_V7;
    pd_technicalmembership_reset_members_V7_t technicalmembership_reset_members_V7;
    pd_technicalmembership_change_key_V7_t technicalmembership_change_key_V7;
    pd_technicalmembership_set_prime_V7_t technicalmembership_set_prime_V7;
    pd_technicalmembership_clear_prime_V7_t technicalmembership_clear_prime_V7;
    pd_treasury_propose_spend_V7_t treasury_propose_spend_V7;
    pd_treasury_reject_proposal_V7_t treasury_reject_proposal_V7;
    pd_treasury_approve_proposal_V7_t treasury_approve_proposal_V7;
    pd_claims_claim_V7_t claims_claim_V7;
    pd_claims_mint_claim_V7_t claims_mint_claim_V7;
    pd_claims_claim_attest_V7_t claims_claim_attest_V7;
    pd_claims_attest_V7_t claims_attest_V7;
    pd_claims_move_claim_V7_t claims_move_claim_V7;
    pd_vesting_vest_V7_t vesting_vest_V7;
    pd_vesting_vest_other_V7_t vesting_vest_other_V7;
    pd_vesting_vested_transfer_V7_t vesting_vested_transfer_V7;
    pd_vesting_force_vested_transfer_V7_t vesting_force_vested_transfer_V7;
    pd_utility_as_derivative_V7_t utility_as_derivative_V7;
    pd_identity_add_registrar_V7_t identity_add_registrar_V7;
    pd_identity_set_identity_V7_t identity_set_identity_V7;
    pd_identity_set_subs_V7_t identity_set_subs_V7;
    pd_identity_clear_identity_V7_t identity_clear_identity_V7;
    pd_identity_request_judgement_V7_t identity_request_judgement_V7;
    pd_identity_cancel_request_V7_t identity_cancel_request_V7;
    pd_identity_set_fee_V7_t identity_set_fee_V7;
    pd_identity_set_account_id_V7_t identity_set_account_id_V7;
    pd_identity_set_fields_V7_t identity_set_fields_V7;
    pd_identity_provide_judgement_V7_t identity_provide_judgement_V7;
    pd_identity_kill_identity_V7_t identity_kill_identity_V7;
    pd_identity_add_sub_V7_t identity_add_sub_V7;
    pd_identity_rename_sub_V7_t identity_rename_sub_V7;
    pd_identity_remove_sub_V7_t identity_remove_sub_V7;
    pd_identity_quit_sub_V7_t identity_quit_sub_V7;
    pd_proxy_add_proxy_V7_t proxy_add_proxy_V7;
    pd_proxy_remove_proxy_V7_t proxy_remove_proxy_V7;
    pd_proxy_remove_proxies_V7_t proxy_remove_proxies_V7;
    pd_proxy_anonymous_V7_t proxy_anonymous_V7;
    pd_proxy_kill_anonymous_V7_t proxy_kill_anonymous_V7;
    pd_proxy_announce_V7_t proxy_announce_V7;
    pd_proxy_remove_announcement_V7_t proxy_remove_announcement_V7;
    pd_proxy_reject_announcement_V7_t proxy_reject_announcement_V7;
    pd_proxy_proxy_announced_V7_t proxy_proxy_announced_V7;
    pd_bounties_propose_bounty_V7_t bounties_propose_bounty_V7;
    pd_bounties_approve_bounty_V7_t bounties_approve_bounty_V7;
    pd_bounties_propose_curator_V7_t bounties_propose_curator_V7;
    pd_bounties_unassign_curator_V7_t bounties_unassign_curator_V7;
    pd_bounties_accept_curator_V7_t bounties_accept_curator_V7;
    pd_bounties_award_bounty_V7_t bounties_award_bounty_V7;
    pd_bounties_claim_bounty_V7_t bounties_claim_bounty_V7;
    pd_bounties_close_bounty_V7_t bounties_close_bounty_V7;
    pd_bounties_extend_bounty_expiry_V7_t bounties_extend_bounty_expiry_V7;
    pd_tips_report_awesome_V7_t tips_report_awesome_V7;
    pd_tips_retract_tip_V7_t tips_retract_tip_V7;
    pd_tips_tip_new_V7_t tips_tip_new_V7;
    pd_tips_tip_V7_t tips_tip_V7;
    pd_tips_close_tip_V7_t tips_close_tip_V7;
    pd_tips_slash_tip_V7_t tips_slash_tip_V7;
    pd_electionprovidermultiphase_submit_unsigned_V7_t electionprovidermultiphase_submit_unsigned_V7;
#endif
} pd_MethodBasic_V7_t;

#define PD_CALL_BALANCES_TRANSFER_V7 0
typedef struct {
    pd_LookupSource_V7_t dest;
    pd_CompactBalance_t value;
} pd_balances_transfer_V7_t;

#define PD_CALL_BALANCES_TRANSFER_KEEP_ALIVE_V7 3
typedef struct {
    pd_LookupSource_V7_t dest;
    pd_CompactBalance_t value;
} pd_balances_transfer_keep_alive_V7_t;

#ifdef SUBSTRATE_PARSER_FULL
#define PD_CALL_SYSTEM_FILL_BLOCK_V7 0
typedef struct {
    pd_Perbill_V7_t _ratio;
} pd_system_fill_block_V7_t;

#define PD_CALL_SYSTEM_REMARK_V7 1
typedef struct {
    pd_Bytes_t _remark;
} pd_system_remark_V7_t;

#define PD_CALL_SYSTEM_SET_HEAP_PAGES_V7 2
typedef struct {
    pd_u64_t pages;
} pd_system_set_heap_pages_V7_t;

#define PD_CALL_SYSTEM_SET_CODE_V7 3
typedef struct {
    pd_Bytes_t code;
} pd_system_set_code_V7_t;

#define PD_CALL_SYSTEM_SET_CODE_WITHOUT_CHECKS_V7 4
typedef struct {
    pd_Bytes_t code;
} pd_system_set_code_without_checks_V7_t;

#define PD_CALL_SYSTEM_SET_CHANGES_TRIE_CONFIG_V7 5
typedef struct {
    pd_OptionChangesTrieConfiguration_V7_t changes_trie_config;
} pd_system_set_changes_trie_config_V7_t;

#define PD_CALL_SYSTEM_SET_STORAGE_V7 6
typedef struct {
    pd_VecKeyValue_V7_t items;
} pd_system_set_storage_V7_t;

#define PD_CALL_SYSTEM_KILL_STORAGE_V7 7
typedef struct {
    pd_VecKey_V7_t keys;
} pd_system_kill_storage_V7_t;

#define PD_CALL_SYSTEM_KILL_PREFIX_V7 8
typedef struct {
    pd_Key_V7_t prefix;
    pd_u32_t _subkeys;
} pd_system_kill_prefix_V7_t;

#define PD_CALL_BALANCES_SET_BALANCE_V7 1
typedef struct {
    pd_LookupSource_V7_t who;
    pd_CompactBalance_t new_free;
    pd_CompactBalance_t new_reserved;
} pd_balances_set_balance_V7_t;

#define PD_CALL_BALANCES_FORCE_TRANSFER_V7 2
typedef struct {
    pd_LookupSource_V7_t source;
    pd_LookupSource_V7_t dest;
    pd_CompactBalance_t value;
} pd_balances_force_transfer_V7_t;

#define PD_CALL_PROXY_PROXY_V7 0
typedef struct {
    pd_AccountId_V7_t real;
    pd_OptionProxyType_V7_t force_proxy_type;
    pd_Call_t call;
} pd_proxy_proxy_V7_t;

#define PD_CALL_MULTISIG_AS_MULTI_THRESHOLD_1_V7 0
typedef struct {
    pd_VecAccountId_V7_t other_signatories;
    pd_Call_t call;
} pd_multisig_as_multi_threshold_1_V7_t;

#define PD_CALL_MULTISIG_AS_MULTI_V7 1
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_V7_t other_signatories;
    pd_OptionTimepoint_V7_t maybe_timepoint;
    pd_OpaqueCall_V7_t call;
    pd_bool_t store_call;
    pd_Weight_V7_t max_weight;
} pd_multisig_as_multi_V7_t;

#define PD_CALL_MULTISIG_APPROVE_AS_MULTI_V7 2
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_V7_t other_signatories;
    pd_OptionTimepoint_V7_t maybe_timepoint;
    pd_u8_array_32_V7_t call_hash;
    pd_Weight_V7_t max_weight;
} pd_multisig_approve_as_multi_V7_t;

#define PD_CALL_MULTISIG_CANCEL_AS_MULTI_V7 3
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_V7_t other_signatories;
    pd_Timepoint_V7_t timepoint;
    pd_u8_array_32_V7_t call_hash;
} pd_multisig_cancel_as_multi_V7_t;

#endif

typedef union {
    pd_balances_transfer_V7_t balances_transfer_V7;
    pd_balances_transfer_keep_alive_V7_t balances_transfer_keep_alive_V7;
#ifdef SUBSTRATE_PARSER_FULL
    pd_system_fill_block_V7_t system_fill_block_V7;
    pd_system_remark_V7_t system_remark_V7;
    pd_system_set_heap_pages_V7_t system_set_heap_pages_V7;
    pd_system_set_code_V7_t system_set_code_V7;
    pd_system_set_code_without_checks_V7_t system_set_code_without_checks_V7;
    pd_system_set_changes_trie_config_V7_t system_set_changes_trie_config_V7;
    pd_system_set_storage_V7_t system_set_storage_V7;
    pd_system_kill_storage_V7_t system_kill_storage_V7;
    pd_system_kill_prefix_V7_t system_kill_prefix_V7;
    pd_balances_set_balance_V7_t balances_set_balance_V7;
    pd_balances_force_transfer_V7_t balances_force_transfer_V7;
    pd_proxy_proxy_V7_t proxy_proxy_V7;
    pd_multisig_as_multi_threshold_1_V7_t multisig_as_multi_threshold_1_V7;
    pd_multisig_as_multi_V7_t multisig_as_multi_V7;
    pd_multisig_approve_as_multi_V7_t multisig_approve_as_multi_V7;
    pd_multisig_cancel_as_multi_V7_t multisig_cancel_as_multi_V7;
#endif
} pd_MethodNested_V7_t;

typedef union {
    pd_MethodBasic_V7_t basic;
    pd_MethodNested_V7_t nested;
} pd_Method_V7_t;

#ifdef __cplusplus
}
#endif

#pragma clang diagnostic pop
