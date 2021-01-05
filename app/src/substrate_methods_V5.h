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
#include "substrate_types_V5.h"
#include <stddef.h>
#include <stdint.h>

#define PD_CALL_SYSTEM 0
#define PD_CALL_SCHEDULER 1
#define PD_CALL_BABE 2
#define PD_CALL_TIMESTAMP 3
#define PD_CALL_INDICES 4
#define PD_CALL_BALANCES 5
#define PD_CALL_AUTHORSHIP 6
#define PD_CALL_STAKING 7
#define PD_CALL_OFFENCES 8
#define PD_CALL_SESSION 9
#define PD_CALL_GRANDPA 11
#define PD_CALL_IMONLINE 12
#define PD_CALL_AUTHORITYDISCOVERY 13
#define PD_CALL_DEMOCRACY 14
#define PD_CALL_COUNCIL 15
#define PD_CALL_TECHNICALCOMMITTEE 16
#define PD_CALL_ELECTIONSPHRAGMEN 17
#define PD_CALL_TECHNICALMEMBERSHIP 18
#define PD_CALL_TREASURY 19
#define PD_CALL_CLAIMS 24
#define PD_CALL_VESTING 25
#define PD_CALL_UTILITY 26
#define PD_CALL_IDENTITY 28
#define PD_CALL_PROXY 29
#define PD_CALL_MULTISIG 30

#define PD_CALL_SYSTEM_FILL_BLOCK 0
typedef struct {
    pd_Perbill_V5_t _ratio;
} pd_system_fill_block_V5_t;

#define PD_CALL_SYSTEM_REMARK 1
typedef struct {
    pd_Bytes_t _remark;
} pd_system_remark_V5_t;

#define PD_CALL_SYSTEM_SET_HEAP_PAGES 2
typedef struct {
    pd_u64_t pages;
} pd_system_set_heap_pages_V5_t;

#define PD_CALL_SYSTEM_SET_CODE 3
typedef struct {
    pd_Bytes_t code;
} pd_system_set_code_V5_t;

#define PD_CALL_SYSTEM_SET_CODE_WITHOUT_CHECKS 4
typedef struct {
    pd_Bytes_t code;
} pd_system_set_code_without_checks_V5_t;

#define PD_CALL_SYSTEM_SET_CHANGES_TRIE_CONFIG 5
typedef struct {
    pd_OptionChangesTrieConfiguration_V5_t changes_trie_config;
} pd_system_set_changes_trie_config_V5_t;

#define PD_CALL_SYSTEM_SET_STORAGE 6
typedef struct {
    pd_VecKeyValue_V5_t items;
} pd_system_set_storage_V5_t;

#define PD_CALL_SYSTEM_KILL_STORAGE 7
typedef struct {
    pd_VecKey_V5_t keys;
} pd_system_kill_storage_V5_t;

#define PD_CALL_SYSTEM_KILL_PREFIX 8
typedef struct {
    pd_Key_V5_t prefix;
    pd_u32_t _subkeys;
} pd_system_kill_prefix_V5_t;

#define PD_CALL_SYSTEM_SUICIDE 9
typedef struct {
} pd_system_suicide_V5_t;

#define PD_CALL_SCHEDULER_SCHEDULE 0
typedef struct {
    pd_BlockNumber_t when;
    pd_OptionPeriod_V5_t maybe_periodic;
    pd_Priority_V5_t priority;
    pd_Call_V5_t call;
} pd_scheduler_schedule_V5_t;

#define PD_CALL_SCHEDULER_CANCEL 1
typedef struct {
    pd_BlockNumber_t when;
    pd_u32_t index;
} pd_scheduler_cancel_V5_t;

#define PD_CALL_SCHEDULER_SCHEDULE_NAMED 2
typedef struct {
    pd_Bytes_t id;
    pd_BlockNumber_t when;
    pd_OptionPeriod_V5_t maybe_periodic;
    pd_Priority_V5_t priority;
    pd_Call_V5_t call;
} pd_scheduler_schedule_named_V5_t;

#define PD_CALL_SCHEDULER_CANCEL_NAMED 3
typedef struct {
    pd_Bytes_t id;
} pd_scheduler_cancel_named_V5_t;

#define PD_CALL_SCHEDULER_SCHEDULE_AFTER 4
typedef struct {
    pd_BlockNumber_t after;
    pd_OptionPeriod_V5_t maybe_periodic;
    pd_Priority_V5_t priority;
    pd_Call_V5_t call;
} pd_scheduler_schedule_after_V5_t;

#define PD_CALL_SCHEDULER_SCHEDULE_NAMED_AFTER 5
typedef struct {
    pd_Bytes_t id;
    pd_BlockNumber_t after;
    pd_OptionPeriod_V5_t maybe_periodic;
    pd_Priority_V5_t priority;
    pd_Call_V5_t call;
} pd_scheduler_schedule_named_after_V5_t;

#define PD_CALL_BABE_REPORT_EQUIVOCATION 0
typedef struct {
    pd_EquivocationProof_V5_t equivocation_proof;
    pd_KeyOwnerProof_V5_t key_owner_proof;
} pd_babe_report_equivocation_V5_t;

#define PD_CALL_BABE_REPORT_EQUIVOCATION_UNSIGNED 1
typedef struct {
    pd_EquivocationProof_V5_t equivocation_proof;
    pd_KeyOwnerProof_V5_t key_owner_proof;
} pd_babe_report_equivocation_unsigned_V5_t;

#define PD_CALL_TIMESTAMP_SET 0
typedef struct {
    pd_CompactMoment_V5_t now;
} pd_timestamp_set_V5_t;

#define PD_CALL_INDICES_CLAIM 0
typedef struct {
    pd_AccountIndex_V5_t index;
} pd_indices_claim_V5_t;

#define PD_CALL_INDICES_TRANSFER 1
typedef struct {
    pd_AccountId_V5_t new_;
    pd_AccountIndex_V5_t index;
} pd_indices_transfer_V5_t;

#define PD_CALL_INDICES_FREE 2
typedef struct {
    pd_AccountIndex_V5_t index;
} pd_indices_free_V5_t;

#define PD_CALL_INDICES_FORCE_TRANSFER 3
typedef struct {
    pd_AccountId_V5_t new_;
    pd_AccountIndex_V5_t index;
    pd_bool_t freeze;
} pd_indices_force_transfer_V5_t;

#define PD_CALL_INDICES_FREEZE 4
typedef struct {
    pd_AccountIndex_V5_t index;
} pd_indices_freeze_V5_t;

#define PD_CALL_BALANCES_TRANSFER 0
typedef struct {
    pd_LookupSource_t dest;
    pd_CompactBalance_t value;
} pd_balances_transfer_V5_t;

#define PD_CALL_BALANCES_SET_BALANCE 1
typedef struct {
    pd_LookupSource_t who;
    pd_CompactBalance_t new_free;
    pd_CompactBalance_t new_reserved;
} pd_balances_set_balance_V5_t;

#define PD_CALL_BALANCES_FORCE_TRANSFER 2
typedef struct {
    pd_LookupSource_t source;
    pd_LookupSource_t dest;
    pd_CompactBalance_t value;
} pd_balances_force_transfer_V5_t;

#define PD_CALL_BALANCES_TRANSFER_KEEP_ALIVE 3
typedef struct {
    pd_LookupSource_t dest;
    pd_CompactBalance_t value;
} pd_balances_transfer_keep_alive_V5_t;

#define PD_CALL_AUTHORSHIP_SET_UNCLES 0
typedef struct {
    pd_VecHeader_t new_uncles;
} pd_authorship_set_uncles_V5_t;

#define PD_CALL_STAKING_BOND 0
typedef struct {
    pd_LookupSource_t controller;
    pd_CompactBalanceOf_t value;
    pd_RewardDestination_V5_t payee;
} pd_staking_bond_V5_t;

#define PD_CALL_STAKING_BOND_EXTRA 1
typedef struct {
    pd_CompactBalanceOf_t max_additional;
} pd_staking_bond_extra_V5_t;

#define PD_CALL_STAKING_UNBOND 2
typedef struct {
    pd_CompactBalanceOf_t value;
} pd_staking_unbond_V5_t;

#define PD_CALL_STAKING_WITHDRAW_UNBONDED 3
typedef struct {
    pd_u32_t num_slashing_spans;
} pd_staking_withdraw_unbonded_V5_t;

#define PD_CALL_STAKING_VALIDATE 4
typedef struct {
    pd_ValidatorPrefs_V5_t prefs;
} pd_staking_validate_V5_t;

#define PD_CALL_STAKING_NOMINATE 5
typedef struct {
    pd_VecLookupSource_t targets;
} pd_staking_nominate_V5_t;

#define PD_CALL_STAKING_CHILL 6
typedef struct {
} pd_staking_chill_V5_t;

#define PD_CALL_STAKING_SET_PAYEE 7
typedef struct {
    pd_RewardDestination_V5_t payee;
} pd_staking_set_payee_V5_t;

#define PD_CALL_STAKING_SET_CONTROLLER 8
typedef struct {
    pd_LookupSource_t controller;
} pd_staking_set_controller_V5_t;

#define PD_CALL_STAKING_SET_VALIDATOR_COUNT 9
typedef struct {
    pd_Compactu32_t new_;
} pd_staking_set_validator_count_V5_t;

#define PD_CALL_STAKING_INCREASE_VALIDATOR_COUNT 10
typedef struct {
    pd_Compactu32_t additional;
} pd_staking_increase_validator_count_V5_t;

#define PD_CALL_STAKING_SCALE_VALIDATOR_COUNT 11
typedef struct {
    pd_Percent_V5_t factor;
} pd_staking_scale_validator_count_V5_t;

#define PD_CALL_STAKING_FORCE_NO_ERAS 12
typedef struct {
} pd_staking_force_no_eras_V5_t;

#define PD_CALL_STAKING_FORCE_NEW_ERA 13
typedef struct {
} pd_staking_force_new_era_V5_t;

#define PD_CALL_STAKING_SET_INVULNERABLES 14
typedef struct {
    pd_VecAccountId_V5_t invulnerables;
} pd_staking_set_invulnerables_V5_t;

#define PD_CALL_STAKING_FORCE_UNSTAKE 15
typedef struct {
    pd_AccountId_V5_t stash;
    pd_u32_t num_slashing_spans;
} pd_staking_force_unstake_V5_t;

#define PD_CALL_STAKING_FORCE_NEW_ERA_ALWAYS 16
typedef struct {
} pd_staking_force_new_era_always_V5_t;

#define PD_CALL_STAKING_CANCEL_DEFERRED_SLASH 17
typedef struct {
    pd_EraIndex_V5_t era;
    pd_Vecu32_t slash_indices;
} pd_staking_cancel_deferred_slash_V5_t;

#define PD_CALL_STAKING_PAYOUT_STAKERS 18
typedef struct {
    pd_AccountId_V5_t validator_stash;
    pd_EraIndex_V5_t era;
} pd_staking_payout_stakers_V5_t;

#define PD_CALL_STAKING_REBOND 19
typedef struct {
    pd_CompactBalanceOf_t value;
} pd_staking_rebond_V5_t;

#define PD_CALL_STAKING_SET_HISTORY_DEPTH 20
typedef struct {
    pd_CompactEraIndex_V5_t new_history_depth;
    pd_Compactu32_t _era_items_deleted;
} pd_staking_set_history_depth_V5_t;

#define PD_CALL_STAKING_REAP_STASH 21
typedef struct {
    pd_AccountId_V5_t stash;
    pd_u32_t num_slashing_spans;
} pd_staking_reap_stash_V5_t;

#define PD_CALL_STAKING_SUBMIT_ELECTION_SOLUTION 22
typedef struct {
    pd_VecValidatorIndex_V5_t winners;
    pd_CompactAssignments_V5_t compact;
    pd_ElectionScore_V5_t score;
    pd_EraIndex_V5_t era;
    pd_ElectionSize_V5_t size;
} pd_staking_submit_election_solution_V5_t;

#define PD_CALL_STAKING_SUBMIT_ELECTION_SOLUTION_UNSIGNED 23
typedef struct {
    pd_VecValidatorIndex_V5_t winners;
    pd_CompactAssignments_V5_t compact;
    pd_ElectionScore_V5_t score;
    pd_EraIndex_V5_t era;
    pd_ElectionSize_V5_t size;
} pd_staking_submit_election_solution_unsigned_V5_t;

#define PD_CALL_SESSION_SET_KEYS 0
typedef struct {
    pd_Keys_V5_t keys;
    pd_Bytes_t proof;
} pd_session_set_keys_V5_t;

#define PD_CALL_SESSION_PURGE_KEYS 1
typedef struct {
} pd_session_purge_keys_V5_t;

#define PD_CALL_GRANDPA_REPORT_EQUIVOCATION 0
typedef struct {
    pd_EquivocationProof_V5_t equivocation_proof;
    pd_KeyOwnerProof_V5_t key_owner_proof;
} pd_grandpa_report_equivocation_V5_t;

#define PD_CALL_GRANDPA_REPORT_EQUIVOCATION_UNSIGNED 1
typedef struct {
    pd_EquivocationProof_V5_t equivocation_proof;
    pd_KeyOwnerProof_V5_t key_owner_proof;
} pd_grandpa_report_equivocation_unsigned_V5_t;

#define PD_CALL_GRANDPA_NOTE_STALLED 2
typedef struct {
    pd_BlockNumber_t delay;
    pd_BlockNumber_t best_finalized_block_number;
} pd_grandpa_note_stalled_V5_t;

#define PD_CALL_IMONLINE_HEARTBEAT 0
typedef struct {
    pd_Heartbeat_t heartbeat;
    pd_Signature_V5_t _signature;
} pd_imonline_heartbeat_V5_t;

#define PD_CALL_DEMOCRACY_PROPOSE 0
typedef struct {
    pd_Hash_t proposal_hash;
    pd_CompactBalanceOf_t value;
} pd_democracy_propose_V5_t;

#define PD_CALL_DEMOCRACY_SECOND 1
typedef struct {
    pd_CompactPropIndex_V5_t proposal;
    pd_Compactu32_t seconds_upper_bound;
} pd_democracy_second_V5_t;

#define PD_CALL_DEMOCRACY_VOTE 2
typedef struct {
    pd_CompactReferendumIndex_V5_t ref_index;
    pd_AccountVote_V5_t vote;
} pd_democracy_vote_V5_t;

#define PD_CALL_DEMOCRACY_EMERGENCY_CANCEL 3
typedef struct {
    pd_ReferendumIndex_V5_t ref_index;
} pd_democracy_emergency_cancel_V5_t;

#define PD_CALL_DEMOCRACY_EXTERNAL_PROPOSE 4
typedef struct {
    pd_Hash_t proposal_hash;
} pd_democracy_external_propose_V5_t;

#define PD_CALL_DEMOCRACY_EXTERNAL_PROPOSE_MAJORITY 5
typedef struct {
    pd_Hash_t proposal_hash;
} pd_democracy_external_propose_majority_V5_t;

#define PD_CALL_DEMOCRACY_EXTERNAL_PROPOSE_DEFAULT 6
typedef struct {
    pd_Hash_t proposal_hash;
} pd_democracy_external_propose_default_V5_t;

#define PD_CALL_DEMOCRACY_FAST_TRACK 7
typedef struct {
    pd_Hash_t proposal_hash;
    pd_BlockNumber_t voting_period;
    pd_BlockNumber_t delay;
} pd_democracy_fast_track_V5_t;

#define PD_CALL_DEMOCRACY_VETO_EXTERNAL 8
typedef struct {
    pd_Hash_t proposal_hash;
} pd_democracy_veto_external_V5_t;

#define PD_CALL_DEMOCRACY_CANCEL_REFERENDUM 9
typedef struct {
    pd_CompactReferendumIndex_V5_t ref_index;
} pd_democracy_cancel_referendum_V5_t;

#define PD_CALL_DEMOCRACY_CANCEL_QUEUED 10
typedef struct {
    pd_ReferendumIndex_V5_t which;
} pd_democracy_cancel_queued_V5_t;

#define PD_CALL_DEMOCRACY_DELEGATE 11
typedef struct {
    pd_AccountId_V5_t to;
    pd_Conviction_V5_t conviction;
    pd_BalanceOf_V5_t balance;
} pd_democracy_delegate_V5_t;

#define PD_CALL_DEMOCRACY_UNDELEGATE 12
typedef struct {
} pd_democracy_undelegate_V5_t;

#define PD_CALL_DEMOCRACY_CLEAR_PUBLIC_PROPOSALS 13
typedef struct {
} pd_democracy_clear_public_proposals_V5_t;

#define PD_CALL_DEMOCRACY_NOTE_PREIMAGE 14
typedef struct {
    pd_Bytes_t encoded_proposal;
} pd_democracy_note_preimage_V5_t;

#define PD_CALL_DEMOCRACY_NOTE_PREIMAGE_OPERATIONAL 15
typedef struct {
    pd_Bytes_t encoded_proposal;
} pd_democracy_note_preimage_operational_V5_t;

#define PD_CALL_DEMOCRACY_NOTE_IMMINENT_PREIMAGE 16
typedef struct {
    pd_Bytes_t encoded_proposal;
} pd_democracy_note_imminent_preimage_V5_t;

#define PD_CALL_DEMOCRACY_NOTE_IMMINENT_PREIMAGE_OPERATIONAL 17
typedef struct {
    pd_Bytes_t encoded_proposal;
} pd_democracy_note_imminent_preimage_operational_V5_t;

#define PD_CALL_DEMOCRACY_REAP_PREIMAGE 18
typedef struct {
    pd_Hash_t proposal_hash;
    pd_Compactu32_t proposal_len_upper_bound;
} pd_democracy_reap_preimage_V5_t;

#define PD_CALL_DEMOCRACY_UNLOCK 19
typedef struct {
    pd_AccountId_V5_t target;
} pd_democracy_unlock_V5_t;

#define PD_CALL_DEMOCRACY_REMOVE_VOTE 20
typedef struct {
    pd_ReferendumIndex_V5_t index;
} pd_democracy_remove_vote_V5_t;

#define PD_CALL_DEMOCRACY_REMOVE_OTHER_VOTE 21
typedef struct {
    pd_AccountId_V5_t target;
    pd_ReferendumIndex_V5_t index;
} pd_democracy_remove_other_vote_V5_t;

#define PD_CALL_DEMOCRACY_ENACT_PROPOSAL 22
typedef struct {
    pd_Hash_t proposal_hash;
    pd_ReferendumIndex_V5_t index;
} pd_democracy_enact_proposal_V5_t;

#define PD_CALL_DEMOCRACY_BLACKLIST 23
typedef struct {
    pd_Hash_t proposal_hash;
    pd_OptionReferendumIndex_V5_t maybe_ref_index;
} pd_democracy_blacklist_V5_t;

#define PD_CALL_DEMOCRACY_CANCEL_PROPOSAL 24
typedef struct {
    pd_CompactPropIndex_V5_t prop_index;
} pd_democracy_cancel_proposal_V5_t;

#define PD_CALL_COUNCIL_SET_MEMBERS 0
typedef struct {
    pd_VecAccountId_V5_t new_members;
    pd_OptionAccountId_V5_t prime;
    pd_MemberCount_V5_t old_count;
} pd_council_set_members_V5_t;

#define PD_CALL_COUNCIL_VOTE 3
typedef struct {
    pd_Hash_t proposal;
    pd_CompactProposalIndex_V5_t index;
    pd_bool_t approve;
} pd_council_vote_V5_t;

#define PD_CALL_COUNCIL_CLOSE 4
typedef struct {
    pd_Hash_t proposal_hash;
    pd_CompactProposalIndex_V5_t index;
    pd_CompactWeight_V5_t proposal_weight_bound;
    pd_Compactu32_t length_bound;
} pd_council_close_V5_t;

#define PD_CALL_COUNCIL_DISAPPROVE_PROPOSAL 5
typedef struct {
    pd_Hash_t proposal_hash;
} pd_council_disapprove_proposal_V5_t;

#define PD_CALL_TECHNICALCOMMITTEE_SET_MEMBERS 0
typedef struct {
    pd_VecAccountId_V5_t new_members;
    pd_OptionAccountId_V5_t prime;
    pd_MemberCount_V5_t old_count;
} pd_technicalcommittee_set_members_V5_t;

#define PD_CALL_TECHNICALCOMMITTEE_VOTE 3
typedef struct {
    pd_Hash_t proposal;
    pd_CompactProposalIndex_V5_t index;
    pd_bool_t approve;
} pd_technicalcommittee_vote_V5_t;

#define PD_CALL_TECHNICALCOMMITTEE_CLOSE 4
typedef struct {
    pd_Hash_t proposal_hash;
    pd_CompactProposalIndex_V5_t index;
    pd_CompactWeight_V5_t proposal_weight_bound;
    pd_Compactu32_t length_bound;
} pd_technicalcommittee_close_V5_t;

#define PD_CALL_TECHNICALCOMMITTEE_DISAPPROVE_PROPOSAL 5
typedef struct {
    pd_Hash_t proposal_hash;
} pd_technicalcommittee_disapprove_proposal_V5_t;

#define PD_CALL_ELECTIONSPHRAGMEN_VOTE 0
typedef struct {
    pd_VecAccountId_V5_t votes;
    pd_CompactBalanceOf_t value;
} pd_electionsphragmen_vote_V5_t;

#define PD_CALL_ELECTIONSPHRAGMEN_REMOVE_VOTER 1
typedef struct {
} pd_electionsphragmen_remove_voter_V5_t;

#define PD_CALL_ELECTIONSPHRAGMEN_REPORT_DEFUNCT_VOTER 2
typedef struct {
    pd_DefunctVoter_V5_t defunct;
} pd_electionsphragmen_report_defunct_voter_V5_t;

#define PD_CALL_ELECTIONSPHRAGMEN_SUBMIT_CANDIDACY 3
typedef struct {
    pd_Compactu32_t candidate_count;
} pd_electionsphragmen_submit_candidacy_V5_t;

#define PD_CALL_ELECTIONSPHRAGMEN_RENOUNCE_CANDIDACY 4
typedef struct {
    pd_Renouncing_V5_t renouncing;
} pd_electionsphragmen_renounce_candidacy_V5_t;

#define PD_CALL_ELECTIONSPHRAGMEN_REMOVE_MEMBER 5
typedef struct {
    pd_LookupSource_t who;
    pd_bool_t has_replacement;
} pd_electionsphragmen_remove_member_V5_t;

#define PD_CALL_TECHNICALMEMBERSHIP_ADD_MEMBER 0
typedef struct {
    pd_AccountId_V5_t who;
} pd_technicalmembership_add_member_V5_t;

#define PD_CALL_TECHNICALMEMBERSHIP_REMOVE_MEMBER 1
typedef struct {
    pd_AccountId_V5_t who;
} pd_technicalmembership_remove_member_V5_t;

#define PD_CALL_TECHNICALMEMBERSHIP_SWAP_MEMBER 2
typedef struct {
    pd_AccountId_V5_t remove;
    pd_AccountId_V5_t add;
} pd_technicalmembership_swap_member_V5_t;

#define PD_CALL_TECHNICALMEMBERSHIP_RESET_MEMBERS 3
typedef struct {
    pd_VecAccountId_V5_t members;
} pd_technicalmembership_reset_members_V5_t;

#define PD_CALL_TECHNICALMEMBERSHIP_CHANGE_KEY 4
typedef struct {
    pd_AccountId_V5_t new_;
} pd_technicalmembership_change_key_V5_t;

#define PD_CALL_TECHNICALMEMBERSHIP_SET_PRIME 5
typedef struct {
    pd_AccountId_V5_t who;
} pd_technicalmembership_set_prime_V5_t;

#define PD_CALL_TECHNICALMEMBERSHIP_CLEAR_PRIME 6
typedef struct {
} pd_technicalmembership_clear_prime_V5_t;

#define PD_CALL_TREASURY_PROPOSE_SPEND 0
typedef struct {
    pd_CompactBalanceOf_t value;
    pd_LookupSource_t beneficiary;
} pd_treasury_propose_spend_V5_t;

#define PD_CALL_TREASURY_REJECT_PROPOSAL 1
typedef struct {
    pd_CompactProposalIndex_V5_t proposal_id;
} pd_treasury_reject_proposal_V5_t;

#define PD_CALL_TREASURY_APPROVE_PROPOSAL 2
typedef struct {
    pd_CompactProposalIndex_V5_t proposal_id;
} pd_treasury_approve_proposal_V5_t;

#define PD_CALL_TREASURY_REPORT_AWESOME 3
typedef struct {
    pd_Bytes_t reason;
    pd_AccountId_V5_t who;
} pd_treasury_report_awesome_V5_t;

#define PD_CALL_TREASURY_RETRACT_TIP 4
typedef struct {
    pd_Hash_t hash;
} pd_treasury_retract_tip_V5_t;

#define PD_CALL_TREASURY_TIP_NEW 5
typedef struct {
    pd_Bytes_t reason;
    pd_AccountId_V5_t who;
    pd_CompactBalanceOf_t tip_value;
} pd_treasury_tip_new_V5_t;

#define PD_CALL_TREASURY_TIP 6
typedef struct {
    pd_Hash_t hash;
    pd_CompactBalanceOf_t tip_value;
} pd_treasury_tip_V5_t;

#define PD_CALL_TREASURY_CLOSE_TIP 7
typedef struct {
    pd_Hash_t hash;
} pd_treasury_close_tip_V5_t;

#define PD_CALL_TREASURY_PROPOSE_BOUNTY 8
typedef struct {
    pd_CompactBalanceOf_t value;
    pd_Bytes_t description;
} pd_treasury_propose_bounty_V5_t;

#define PD_CALL_TREASURY_APPROVE_BOUNTY 9
typedef struct {
    pd_CompactProposalIndex_V5_t bounty_id;
} pd_treasury_approve_bounty_V5_t;

#define PD_CALL_TREASURY_PROPOSE_CURATOR 10
typedef struct {
    pd_CompactProposalIndex_V5_t bounty_id;
    pd_LookupSource_t curator;
    pd_CompactBalanceOf_t fee;
} pd_treasury_propose_curator_V5_t;

#define PD_CALL_TREASURY_UNASSIGN_CURATOR 11
typedef struct {
    pd_CompactProposalIndex_V5_t bounty_id;
} pd_treasury_unassign_curator_V5_t;

#define PD_CALL_TREASURY_ACCEPT_CURATOR 12
typedef struct {
    pd_CompactProposalIndex_V5_t bounty_id;
} pd_treasury_accept_curator_V5_t;

#define PD_CALL_TREASURY_AWARD_BOUNTY 13
typedef struct {
    pd_CompactProposalIndex_V5_t bounty_id;
    pd_LookupSource_t beneficiary;
} pd_treasury_award_bounty_V5_t;

#define PD_CALL_TREASURY_CLAIM_BOUNTY 14
typedef struct {
    pd_CompactBountyIndex_V5_t bounty_id;
} pd_treasury_claim_bounty_V5_t;

#define PD_CALL_TREASURY_CLOSE_BOUNTY 15
typedef struct {
    pd_CompactBountyIndex_V5_t bounty_id;
} pd_treasury_close_bounty_V5_t;

#define PD_CALL_TREASURY_EXTEND_BOUNTY_EXPIRY 16
typedef struct {
    pd_CompactBountyIndex_V5_t bounty_id;
    pd_Bytes_t _remark;
} pd_treasury_extend_bounty_expiry_V5_t;

#define PD_CALL_CLAIMS_CLAIM 0
typedef struct {
    pd_AccountId_V5_t dest;
    pd_EcdsaSignature_V5_t ethereum_signature;
} pd_claims_claim_V5_t;

#define PD_CALL_CLAIMS_MINT_CLAIM 1
typedef struct {
    pd_EthereumAddress_V5_t who;
    pd_BalanceOf_V5_t value;
    pd_OptionTupleBalanceOfBalanceOfBlockNumber_V5_t vesting_schedule;
    pd_OptionStatementKind_V5_t statement;
} pd_claims_mint_claim_V5_t;

#define PD_CALL_CLAIMS_CLAIM_ATTEST 2
typedef struct {
    pd_AccountId_V5_t dest;
    pd_EcdsaSignature_V5_t ethereum_signature;
    pd_Bytes_t statement;
} pd_claims_claim_attest_V5_t;

#define PD_CALL_CLAIMS_ATTEST 3
typedef struct {
    pd_Bytes_t statement;
} pd_claims_attest_V5_t;

#define PD_CALL_CLAIMS_MOVE_CLAIM 4
typedef struct {
    pd_EthereumAddress_V5_t old;
    pd_EthereumAddress_V5_t new_;
    pd_OptionAccountId_V5_t maybe_preclaim;
} pd_claims_move_claim_V5_t;

#define PD_CALL_VESTING_VEST 0
typedef struct {
} pd_vesting_vest_V5_t;

#define PD_CALL_VESTING_VEST_OTHER 1
typedef struct {
    pd_LookupSource_t target;
} pd_vesting_vest_other_V5_t;

#define PD_CALL_VESTING_VESTED_TRANSFER 2
typedef struct {
    pd_LookupSource_t target;
    pd_VestingInfo_V5_t schedule;
} pd_vesting_vested_transfer_V5_t;

#define PD_CALL_VESTING_FORCE_VESTED_TRANSFER 3
typedef struct {
    pd_LookupSource_t source;
    pd_LookupSource_t target;
    pd_VestingInfo_V5_t schedule;
} pd_vesting_force_vested_transfer_V5_t;

#define PD_CALL_UTILITY_BATCH 0
typedef struct {
    pd_VecCall_V5_t calls;
} pd_utility_batch_V5_t;

#define PD_CALL_UTILITY_AS_DERIVATIVE 1
typedef struct {
    pd_u16_t index;
    pd_Call_V5_t call;
} pd_utility_as_derivative_V5_t;

#define PD_CALL_UTILITY_BATCH_ALL 2
typedef struct {
    pd_VecCall_V5_t calls;
} pd_utility_batch_all_V5_t;

#define PD_CALL_IDENTITY_ADD_REGISTRAR 0
typedef struct {
    pd_AccountId_V5_t account;
} pd_identity_add_registrar_V5_t;

#define PD_CALL_IDENTITY_SET_IDENTITY 1
typedef struct {
    pd_IdentityInfo_V5_t info;
} pd_identity_set_identity_V5_t;

#define PD_CALL_IDENTITY_SET_SUBS 2
typedef struct {
    pd_VecTupleAccountIdData_V5_t subs;
} pd_identity_set_subs_V5_t;

#define PD_CALL_IDENTITY_CLEAR_IDENTITY 3
typedef struct {
} pd_identity_clear_identity_V5_t;

#define PD_CALL_IDENTITY_REQUEST_JUDGEMENT 4
typedef struct {
    pd_CompactRegistrarIndex_V5_t reg_index;
    pd_CompactBalanceOf_t max_fee;
} pd_identity_request_judgement_V5_t;

#define PD_CALL_IDENTITY_CANCEL_REQUEST 5
typedef struct {
    pd_RegistrarIndex_V5_t reg_index;
} pd_identity_cancel_request_V5_t;

#define PD_CALL_IDENTITY_SET_FEE 6
typedef struct {
    pd_CompactRegistrarIndex_V5_t index;
    pd_CompactBalanceOf_t fee;
} pd_identity_set_fee_V5_t;

#define PD_CALL_IDENTITY_SET_ACCOUNT_ID 7
typedef struct {
    pd_CompactRegistrarIndex_V5_t index;
    pd_AccountId_V5_t new_;
} pd_identity_set_account_id_V5_t;

#define PD_CALL_IDENTITY_SET_FIELDS 8
typedef struct {
    pd_CompactRegistrarIndex_V5_t index;
    pd_IdentityFields_V5_t fields;
} pd_identity_set_fields_V5_t;

#define PD_CALL_IDENTITY_PROVIDE_JUDGEMENT 9
typedef struct {
    pd_CompactRegistrarIndex_V5_t reg_index;
    pd_LookupSource_t target;
    pd_Judgement_V5_t judgement;
} pd_identity_provide_judgement_V5_t;

#define PD_CALL_IDENTITY_KILL_IDENTITY 10
typedef struct {
    pd_LookupSource_t target;
} pd_identity_kill_identity_V5_t;

#define PD_CALL_IDENTITY_ADD_SUB 11
typedef struct {
    pd_LookupSource_t sub;
    pd_Data_t data;
} pd_identity_add_sub_V5_t;

#define PD_CALL_IDENTITY_RENAME_SUB 12
typedef struct {
    pd_LookupSource_t sub;
    pd_Data_t data;
} pd_identity_rename_sub_V5_t;

#define PD_CALL_IDENTITY_REMOVE_SUB 13
typedef struct {
    pd_LookupSource_t sub;
} pd_identity_remove_sub_V5_t;

#define PD_CALL_IDENTITY_QUIT_SUB 14
typedef struct {
} pd_identity_quit_sub_V5_t;

#define PD_CALL_PROXY_PROXY 0
typedef struct {
    pd_AccountId_V5_t real;
    pd_OptionProxyType_V5_t force_proxy_type;
    pd_Call_V5_t call;
} pd_proxy_proxy_V5_t;

#define PD_CALL_PROXY_ADD_PROXY 1
typedef struct {
    pd_AccountId_V5_t delegate;
    pd_ProxyType_V5_t proxy_type;
    pd_BlockNumber_t delay;
} pd_proxy_add_proxy_V5_t;

#define PD_CALL_PROXY_REMOVE_PROXY 2
typedef struct {
    pd_AccountId_V5_t delegate;
    pd_ProxyType_V5_t proxy_type;
    pd_BlockNumber_t delay;
} pd_proxy_remove_proxy_V5_t;

#define PD_CALL_PROXY_REMOVE_PROXIES 3
typedef struct {
} pd_proxy_remove_proxies_V5_t;

#define PD_CALL_PROXY_ANONYMOUS 4
typedef struct {
    pd_ProxyType_V5_t proxy_type;
    pd_BlockNumber_t delay;
    pd_u16_t index;
} pd_proxy_anonymous_V5_t;

#define PD_CALL_PROXY_KILL_ANONYMOUS 5
typedef struct {
    pd_AccountId_V5_t spawner;
    pd_ProxyType_V5_t proxy_type;
    pd_u16_t index;
    pd_CompactBlockNumber_t height;
    pd_Compactu32_t ext_index;
} pd_proxy_kill_anonymous_V5_t;

#define PD_CALL_PROXY_ANNOUNCE 6
typedef struct {
    pd_AccountId_V5_t real;
    pd_CallHashOf_V5_t call_hash;
} pd_proxy_announce_V5_t;

#define PD_CALL_PROXY_REMOVE_ANNOUNCEMENT 7
typedef struct {
    pd_AccountId_V5_t real;
    pd_CallHashOf_V5_t call_hash;
} pd_proxy_remove_announcement_V5_t;

#define PD_CALL_PROXY_REJECT_ANNOUNCEMENT 8
typedef struct {
    pd_AccountId_V5_t delegate;
    pd_CallHashOf_V5_t call_hash;
} pd_proxy_reject_announcement_V5_t;

#define PD_CALL_PROXY_PROXY_ANNOUNCED 9
typedef struct {
    pd_AccountId_V5_t delegate;
    pd_AccountId_V5_t real;
    pd_OptionProxyType_V5_t force_proxy_type;
    pd_Call_V5_t call;
} pd_proxy_proxy_announced_V5_t;

#define PD_CALL_MULTISIG_AS_MULTI_THRESHOLD_1 0
typedef struct {
    pd_VecAccountId_V5_t other_signatories;
    pd_Call_V5_t call;
} pd_multisig_as_multi_threshold_1_V5_t;

#define PD_CALL_MULTISIG_AS_MULTI 1
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_V5_t other_signatories;
    pd_OptionTimepoint_V5_t maybe_timepoint;
    pd_OpaqueCall_V5_t call;
    pd_bool_t store_call;
    pd_Weight_V5_t max_weight;
} pd_multisig_as_multi_V5_t;

#define PD_CALL_MULTISIG_APPROVE_AS_MULTI 2
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_V5_t other_signatories;
    pd_OptionTimepoint_V5_t maybe_timepoint;
    pd_u8_array_32_V5_t call_hash;
    pd_Weight_V5_t max_weight;
} pd_multisig_approve_as_multi_V5_t;

#define PD_CALL_MULTISIG_CANCEL_AS_MULTI 3
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_V5_t other_signatories;
    pd_Timepoint_V5_t timepoint;
    pd_u8_array_32_V5_t call_hash;
} pd_multisig_cancel_as_multi_V5_t;

typedef union {
    pd_system_fill_block_V5_t system_fill_block_V5;
    pd_system_remark_V5_t system_remark_V5;
    pd_system_set_heap_pages_V5_t system_set_heap_pages_V5;
    pd_system_set_code_V5_t system_set_code_V5;
    pd_system_set_code_without_checks_V5_t system_set_code_without_checks_V5;
    pd_system_set_changes_trie_config_V5_t system_set_changes_trie_config_V5;
    pd_system_set_storage_V5_t system_set_storage_V5;
    pd_system_kill_storage_V5_t system_kill_storage_V5;
    pd_system_kill_prefix_V5_t system_kill_prefix_V5;
    pd_system_suicide_V5_t system_suicide_V5;
    pd_scheduler_schedule_V5_t scheduler_schedule_V5;
    pd_scheduler_cancel_V5_t scheduler_cancel_V5;
    pd_scheduler_schedule_named_V5_t scheduler_schedule_named_V5;
    pd_scheduler_cancel_named_V5_t scheduler_cancel_named_V5;
    pd_scheduler_schedule_after_V5_t scheduler_schedule_after_V5;
    pd_scheduler_schedule_named_after_V5_t scheduler_schedule_named_after_V5;
    pd_babe_report_equivocation_V5_t babe_report_equivocation_V5;
    pd_babe_report_equivocation_unsigned_V5_t babe_report_equivocation_unsigned_V5;
    pd_timestamp_set_V5_t timestamp_set_V5;
    pd_indices_claim_V5_t indices_claim_V5;
    pd_indices_transfer_V5_t indices_transfer_V5;
    pd_indices_free_V5_t indices_free_V5;
    pd_indices_force_transfer_V5_t indices_force_transfer_V5;
    pd_indices_freeze_V5_t indices_freeze_V5;
    pd_balances_transfer_V5_t balances_transfer_V5;
    pd_balances_set_balance_V5_t balances_set_balance_V5;
    pd_balances_force_transfer_V5_t balances_force_transfer_V5;
    pd_balances_transfer_keep_alive_V5_t balances_transfer_keep_alive_V5;
    pd_authorship_set_uncles_V5_t authorship_set_uncles_V5;
    pd_staking_bond_V5_t staking_bond_V5;
    pd_staking_bond_extra_V5_t staking_bond_extra_V5;
    pd_staking_unbond_V5_t staking_unbond_V5;
    pd_staking_withdraw_unbonded_V5_t staking_withdraw_unbonded_V5;
    pd_staking_validate_V5_t staking_validate_V5;
    pd_staking_nominate_V5_t staking_nominate_V5;
    pd_staking_chill_V5_t staking_chill_V5;
    pd_staking_set_payee_V5_t staking_set_payee_V5;
    pd_staking_set_controller_V5_t staking_set_controller_V5;
    pd_staking_set_validator_count_V5_t staking_set_validator_count_V5;
    pd_staking_increase_validator_count_V5_t staking_increase_validator_count_V5;
    pd_staking_scale_validator_count_V5_t staking_scale_validator_count_V5;
    pd_staking_force_no_eras_V5_t staking_force_no_eras_V5;
    pd_staking_force_new_era_V5_t staking_force_new_era_V5;
    pd_staking_set_invulnerables_V5_t staking_set_invulnerables_V5;
    pd_staking_force_unstake_V5_t staking_force_unstake_V5;
    pd_staking_force_new_era_always_V5_t staking_force_new_era_always_V5;
    pd_staking_cancel_deferred_slash_V5_t staking_cancel_deferred_slash_V5;
    pd_staking_payout_stakers_V5_t staking_payout_stakers_V5;
    pd_staking_rebond_V5_t staking_rebond_V5;
    pd_staking_set_history_depth_V5_t staking_set_history_depth_V5;
    pd_staking_reap_stash_V5_t staking_reap_stash_V5;
    pd_staking_submit_election_solution_V5_t staking_submit_election_solution_V5;
    pd_staking_submit_election_solution_unsigned_V5_t staking_submit_election_solution_unsigned_V5;
    pd_session_set_keys_V5_t session_set_keys_V5;
    pd_session_purge_keys_V5_t session_purge_keys_V5;
    pd_grandpa_report_equivocation_V5_t grandpa_report_equivocation_V5;
    pd_grandpa_report_equivocation_unsigned_V5_t grandpa_report_equivocation_unsigned_V5;
    pd_grandpa_note_stalled_V5_t grandpa_note_stalled_V5;
    pd_imonline_heartbeat_V5_t imonline_heartbeat_V5;
    pd_democracy_propose_V5_t democracy_propose_V5;
    pd_democracy_second_V5_t democracy_second_V5;
    pd_democracy_vote_V5_t democracy_vote_V5;
    pd_democracy_emergency_cancel_V5_t democracy_emergency_cancel_V5;
    pd_democracy_external_propose_V5_t democracy_external_propose_V5;
    pd_democracy_external_propose_majority_V5_t democracy_external_propose_majority_V5;
    pd_democracy_external_propose_default_V5_t democracy_external_propose_default_V5;
    pd_democracy_fast_track_V5_t democracy_fast_track_V5;
    pd_democracy_veto_external_V5_t democracy_veto_external_V5;
    pd_democracy_cancel_referendum_V5_t democracy_cancel_referendum_V5;
    pd_democracy_cancel_queued_V5_t democracy_cancel_queued_V5;
    pd_democracy_delegate_V5_t democracy_delegate_V5;
    pd_democracy_undelegate_V5_t democracy_undelegate_V5;
    pd_democracy_clear_public_proposals_V5_t democracy_clear_public_proposals_V5;
    pd_democracy_note_preimage_V5_t democracy_note_preimage_V5;
    pd_democracy_note_preimage_operational_V5_t democracy_note_preimage_operational_V5;
    pd_democracy_note_imminent_preimage_V5_t democracy_note_imminent_preimage_V5;
    pd_democracy_note_imminent_preimage_operational_V5_t democracy_note_imminent_preimage_operational_V5;
    pd_democracy_reap_preimage_V5_t democracy_reap_preimage_V5;
    pd_democracy_unlock_V5_t democracy_unlock_V5;
    pd_democracy_remove_vote_V5_t democracy_remove_vote_V5;
    pd_democracy_remove_other_vote_V5_t democracy_remove_other_vote_V5;
    pd_democracy_enact_proposal_V5_t democracy_enact_proposal_V5;
    pd_democracy_blacklist_V5_t democracy_blacklist_V5;
    pd_democracy_cancel_proposal_V5_t democracy_cancel_proposal_V5;
    pd_council_set_members_V5_t council_set_members_V5;
    pd_council_vote_V5_t council_vote_V5;
    pd_council_close_V5_t council_close_V5;
    pd_council_disapprove_proposal_V5_t council_disapprove_proposal_V5;
    pd_technicalcommittee_set_members_V5_t technicalcommittee_set_members_V5;
    pd_technicalcommittee_vote_V5_t technicalcommittee_vote_V5;
    pd_technicalcommittee_close_V5_t technicalcommittee_close_V5;
    pd_technicalcommittee_disapprove_proposal_V5_t technicalcommittee_disapprove_proposal_V5;
    pd_electionsphragmen_vote_V5_t electionsphragmen_vote_V5;
    pd_electionsphragmen_remove_voter_V5_t electionsphragmen_remove_voter_V5;
    pd_electionsphragmen_report_defunct_voter_V5_t electionsphragmen_report_defunct_voter_V5;
    pd_electionsphragmen_submit_candidacy_V5_t electionsphragmen_submit_candidacy_V5;
    pd_electionsphragmen_renounce_candidacy_V5_t electionsphragmen_renounce_candidacy_V5;
    pd_electionsphragmen_remove_member_V5_t electionsphragmen_remove_member_V5;
    pd_technicalmembership_add_member_V5_t technicalmembership_add_member_V5;
    pd_technicalmembership_remove_member_V5_t technicalmembership_remove_member_V5;
    pd_technicalmembership_swap_member_V5_t technicalmembership_swap_member_V5;
    pd_technicalmembership_reset_members_V5_t technicalmembership_reset_members_V5;
    pd_technicalmembership_change_key_V5_t technicalmembership_change_key_V5;
    pd_technicalmembership_set_prime_V5_t technicalmembership_set_prime_V5;
    pd_technicalmembership_clear_prime_V5_t technicalmembership_clear_prime_V5;
    pd_treasury_propose_spend_V5_t treasury_propose_spend_V5;
    pd_treasury_reject_proposal_V5_t treasury_reject_proposal_V5;
    pd_treasury_approve_proposal_V5_t treasury_approve_proposal_V5;
    pd_treasury_report_awesome_V5_t treasury_report_awesome_V5;
    pd_treasury_retract_tip_V5_t treasury_retract_tip_V5;
    pd_treasury_tip_new_V5_t treasury_tip_new_V5;
    pd_treasury_tip_V5_t treasury_tip_V5;
    pd_treasury_close_tip_V5_t treasury_close_tip_V5;
    pd_treasury_propose_bounty_V5_t treasury_propose_bounty_V5;
    pd_treasury_approve_bounty_V5_t treasury_approve_bounty_V5;
    pd_treasury_propose_curator_V5_t treasury_propose_curator_V5;
    pd_treasury_unassign_curator_V5_t treasury_unassign_curator_V5;
    pd_treasury_accept_curator_V5_t treasury_accept_curator_V5;
    pd_treasury_award_bounty_V5_t treasury_award_bounty_V5;
    pd_treasury_claim_bounty_V5_t treasury_claim_bounty_V5;
    pd_treasury_close_bounty_V5_t treasury_close_bounty_V5;
    pd_treasury_extend_bounty_expiry_V5_t treasury_extend_bounty_expiry_V5;
    pd_claims_claim_V5_t claims_claim_V5;
    pd_claims_mint_claim_V5_t claims_mint_claim_V5;
    pd_claims_claim_attest_V5_t claims_claim_attest_V5;
    pd_claims_attest_V5_t claims_attest_V5;
    pd_claims_move_claim_V5_t claims_move_claim_V5;
    pd_vesting_vest_V5_t vesting_vest_V5;
    pd_vesting_vest_other_V5_t vesting_vest_other_V5;
    pd_vesting_vested_transfer_V5_t vesting_vested_transfer_V5;
    pd_vesting_force_vested_transfer_V5_t vesting_force_vested_transfer_V5;
    pd_utility_batch_V5_t utility_batch_V5;
    pd_utility_as_derivative_V5_t utility_as_derivative_V5;
    pd_utility_batch_all_V5_t utility_batch_all_V5;
    pd_identity_add_registrar_V5_t identity_add_registrar_V5;
    pd_identity_set_identity_V5_t identity_set_identity_V5;
    pd_identity_set_subs_V5_t identity_set_subs_V5;
    pd_identity_clear_identity_V5_t identity_clear_identity_V5;
    pd_identity_request_judgement_V5_t identity_request_judgement_V5;
    pd_identity_cancel_request_V5_t identity_cancel_request_V5;
    pd_identity_set_fee_V5_t identity_set_fee_V5;
    pd_identity_set_account_id_V5_t identity_set_account_id_V5;
    pd_identity_set_fields_V5_t identity_set_fields_V5;
    pd_identity_provide_judgement_V5_t identity_provide_judgement_V5;
    pd_identity_kill_identity_V5_t identity_kill_identity_V5;
    pd_identity_add_sub_V5_t identity_add_sub_V5;
    pd_identity_rename_sub_V5_t identity_rename_sub_V5;
    pd_identity_remove_sub_V5_t identity_remove_sub_V5;
    pd_identity_quit_sub_V5_t identity_quit_sub_V5;
    pd_proxy_proxy_V5_t proxy_proxy_V5;
    pd_proxy_add_proxy_V5_t proxy_add_proxy_V5;
    pd_proxy_remove_proxy_V5_t proxy_remove_proxy_V5;
    pd_proxy_remove_proxies_V5_t proxy_remove_proxies_V5;
    pd_proxy_anonymous_V5_t proxy_anonymous_V5;
    pd_proxy_kill_anonymous_V5_t proxy_kill_anonymous_V5;
    pd_proxy_announce_V5_t proxy_announce_V5;
    pd_proxy_remove_announcement_V5_t proxy_remove_announcement_V5;
    pd_proxy_reject_announcement_V5_t proxy_reject_announcement_V5;
    pd_proxy_proxy_announced_V5_t proxy_proxy_announced_V5;
    pd_multisig_as_multi_threshold_1_V5_t multisig_as_multi_threshold_1_V5;
    pd_multisig_as_multi_V5_t multisig_as_multi_V5;
    pd_multisig_approve_as_multi_V5_t multisig_approve_as_multi_V5;
    pd_multisig_cancel_as_multi_V5_t multisig_cancel_as_multi_V5;
} pd_MethodBasic_V5_t;

typedef struct {
    pd_CallIndex_t callIndex;
    pd_MethodBasic_V5_t method;
    // Track proposal buffer
    const uint8_t* _ptr;
    uint16_t _len;
} pd_Proposal_V5_t;

#define PD_CALL_COUNCIL_EXECUTE 1
typedef struct {
    pd_Proposal_V5_t proposal;
    pd_Compactu32_t length_bound;
} pd_council_execute_V5_t;

#define PD_CALL_COUNCIL_PROPOSE 2
typedef struct {
    pd_CompactMemberCount_V5_t threshold;
    pd_Proposal_V5_t proposal;
    pd_Compactu32_t length_bound;
} pd_council_propose_V5_t;

#define PD_CALL_TECHNICALCOMMITTEE_EXECUTE 1
typedef struct {
    pd_Proposal_V5_t proposal;
    pd_Compactu32_t length_bound;
} pd_technicalcommittee_execute_V5_t;

#define PD_CALL_TECHNICALCOMMITTEE_PROPOSE 2
typedef struct {
    pd_CompactMemberCount_V5_t threshold;
    pd_Proposal_V5_t proposal;
    pd_Compactu32_t length_bound;
} pd_technicalcommittee_propose_V5_t;

typedef union {
    pd_council_execute_V5_t council_execute_V5;
    pd_council_propose_V5_t council_propose_V5;
    pd_technicalcommittee_execute_V5_t technicalcommittee_execute_V5;
    pd_technicalcommittee_propose_V5_t technicalcommittee_propose_V5;
} pd_MethodNested_V5_t;

typedef union {
    pd_MethodBasic_V5_t basic;
    pd_MethodNested_V5_t nested;
} pd_Method_V5_t;

#ifdef __cplusplus
}
#endif

#pragma clang diagnostic pop
