/*******************************************************************************
 *  (c) 2019 - 2022 Zondax GmbH
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
#include "substrate_types_V12.h"
#include <stddef.h>
#include <stdint.h>

#define PD_CALL_SYSTEM_V12 0
#define PD_CALL_PREIMAGE_V12 10
#define PD_CALL_TIMESTAMP_V12 3
#define PD_CALL_INDICES_V12 4
#define PD_CALL_BALANCES_V12 5
#define PD_CALL_STAKING_V12 7
#define PD_CALL_SESSION_V12 9
#define PD_CALL_GRANDPA_V12 11
#define PD_CALL_DEMOCRACY_V12 14
#define PD_CALL_COUNCIL_V12 15
#define PD_CALL_TECHNICALCOMMITTEE_V12 16
#define PD_CALL_PHRAGMENELECTION_V12 17
#define PD_CALL_TECHNICALMEMBERSHIP_V12 18
#define PD_CALL_TREASURY_V12 19
#define PD_CALL_CLAIMS_V12 24
#define PD_CALL_VESTING_V12 25
#define PD_CALL_UTILITY_V12 26
#define PD_CALL_IDENTITY_V12 28
#define PD_CALL_PROXY_V12 29
#define PD_CALL_MULTISIG_V12 30
#define PD_CALL_BOUNTIES_V12 34
#define PD_CALL_CHILDBOUNTIES_V12 38
#define PD_CALL_TIPS_V12 35
#define PD_CALL_ELECTIONPROVIDERMULTIPHASE_V12 36
#define PD_CALL_BAGSLIST_V12 37
#define PD_CALL_CONFIGURATION_V12 51
#define PD_CALL_INITIALIZER_V12 57
#define PD_CALL_HRMP_V12 60
#define PD_CALL_PARASDISPUTES_V12 62
#define PD_CALL_REGISTRAR_V12 70
#define PD_CALL_AUCTIONS_V12 72

#define PD_CALL_BALANCES_TRANSFER_ALL_V12 4
typedef struct {
    pd_LookupasStaticLookupSource_V12_t dest;
    pd_bool_t keep_alive;
} pd_balances_transfer_all_V12_t;

#define PD_CALL_STAKING_BOND_V12 0
typedef struct {
    pd_LookupasStaticLookupSource_V12_t controller;
    pd_CompactBalance_t amount;
    pd_RewardDestination_V12_t payee;
} pd_staking_bond_V12_t;

#define PD_CALL_STAKING_BOND_EXTRA_V12 1
typedef struct {
    pd_CompactBalance_t amount;
} pd_staking_bond_extra_V12_t;

#define PD_CALL_STAKING_UNBOND_V12 2
typedef struct {
    pd_CompactBalance_t amount;
} pd_staking_unbond_V12_t;

#define PD_CALL_STAKING_WITHDRAW_UNBONDED_V12 3
typedef struct {
    pd_u32_t num_slashing_spans;
} pd_staking_withdraw_unbonded_V12_t;

#define PD_CALL_STAKING_VALIDATE_V12 4
typedef struct {
    pd_ValidatorPrefs_V12_t prefs;
} pd_staking_validate_V12_t;

#define PD_CALL_STAKING_NOMINATE_V12 5
typedef struct {
    pd_VecLookupasStaticLookupSource_V12_t targets;
} pd_staking_nominate_V12_t;

#define PD_CALL_STAKING_CHILL_V12 6
typedef struct {
} pd_staking_chill_V12_t;

#define PD_CALL_STAKING_SET_PAYEE_V12 7
typedef struct {
    pd_RewardDestination_V12_t payee;
} pd_staking_set_payee_V12_t;

#define PD_CALL_STAKING_SET_CONTROLLER_V12 8
typedef struct {
    pd_LookupasStaticLookupSource_V12_t controller;
} pd_staking_set_controller_V12_t;

#define PD_CALL_STAKING_PAYOUT_STAKERS_V12 18
typedef struct {
    pd_AccountId_V12_t validator_stash;
    pd_EraIndex_V12_t era;
} pd_staking_payout_stakers_V12_t;

#define PD_CALL_STAKING_REBOND_V12 19
typedef struct {
    pd_CompactBalance_t amount;
} pd_staking_rebond_V12_t;

#define PD_CALL_SESSION_SET_KEYS_V12 0
typedef struct {
    pd_Keys_V12_t keys;
    pd_Bytes_t proof;
} pd_session_set_keys_V12_t;

#define PD_CALL_SESSION_PURGE_KEYS_V12 1
typedef struct {
} pd_session_purge_keys_V12_t;

#define PD_CALL_UTILITY_BATCH_V12 0
typedef struct {
    pd_VecCall_t calls;
} pd_utility_batch_V12_t;

#define PD_CALL_UTILITY_BATCH_ALL_V12 2
typedef struct {
    pd_VecCall_t calls;
} pd_utility_batch_all_V12_t;

#ifdef SUBSTRATE_PARSER_FULL

#define PD_CALL_PREIMAGE_NOTE_PREIMAGE_V12 0
typedef struct {
    pd_Vecu8_t bytes;
} pd_preimage_note_preimage_V12_t;

#define PD_CALL_PREIMAGE_UNNOTE_PREIMAGE_V12 1
typedef struct {
    pd_Hash_t hash;
} pd_preimage_unnote_preimage_V12_t;

#define PD_CALL_PREIMAGE_REQUEST_PREIMAGE_V12 2
typedef struct {
    pd_Hash_t hash;
} pd_preimage_request_preimage_V12_t;

#define PD_CALL_PREIMAGE_UNREQUEST_PREIMAGE_V12 3
typedef struct {
    pd_Hash_t hash;
} pd_preimage_unrequest_preimage_V12_t;

#define PD_CALL_TIMESTAMP_SET_V12 0
typedef struct {
    pd_Compactu64_t now;
} pd_timestamp_set_V12_t;

#define PD_CALL_INDICES_CLAIM_V12 0
typedef struct {
    pd_AccountIndex_V12_t index;
} pd_indices_claim_V12_t;

#define PD_CALL_INDICES_FREE_V12 2
typedef struct {
    pd_AccountIndex_V12_t index;
} pd_indices_free_V12_t;

#define PD_CALL_INDICES_FORCE_TRANSFER_V12 3
typedef struct {
    pd_AccountId_V12_t new_;
    pd_AccountIndex_V12_t index;
    pd_bool_t freeze;
} pd_indices_force_transfer_V12_t;

#define PD_CALL_INDICES_FREEZE_V12 4
typedef struct {
    pd_AccountIndex_V12_t index;
} pd_indices_freeze_V12_t;

#define PD_CALL_BALANCES_FORCE_UNRESERVE_V12 5
typedef struct {
    pd_LookupasStaticLookupSource_V12_t who;
    pd_Balance_t amount;
} pd_balances_force_unreserve_V12_t;

#define PD_CALL_STAKING_SET_VALIDATOR_COUNT_V12 9
typedef struct {
    pd_Compactu32_t new_;
} pd_staking_set_validator_count_V12_t;

#define PD_CALL_STAKING_INCREASE_VALIDATOR_COUNT_V12 10
typedef struct {
    pd_Compactu32_t additional;
} pd_staking_increase_validator_count_V12_t;

#define PD_CALL_STAKING_FORCE_NO_ERAS_V12 12
typedef struct {
} pd_staking_force_no_eras_V12_t;

#define PD_CALL_STAKING_FORCE_NEW_ERA_V12 13
typedef struct {
} pd_staking_force_new_era_V12_t;

#define PD_CALL_STAKING_FORCE_UNSTAKE_V12 15
typedef struct {
    pd_AccountId_V12_t stash;
    pd_u32_t num_slashing_spans;
} pd_staking_force_unstake_V12_t;

#define PD_CALL_STAKING_FORCE_NEW_ERA_ALWAYS_V12 16
typedef struct {
} pd_staking_force_new_era_always_V12_t;

#define PD_CALL_STAKING_SET_HISTORY_DEPTH_V12 20
typedef struct {
    pd_Compactu32_t new_history_depth;
    pd_Compactu32_t era_items_deleted;
} pd_staking_set_history_depth_V12_t;

#define PD_CALL_STAKING_REAP_STASH_V12 21
typedef struct {
    pd_AccountId_V12_t stash;
    pd_u32_t num_slashing_spans;
} pd_staking_reap_stash_V12_t;

#define PD_CALL_STAKING_KICK_V12 22
typedef struct {
    pd_VecLookupasStaticLookupSource_V12_t who;
} pd_staking_kick_V12_t;

#define PD_CALL_STAKING_CHILL_OTHER_V12 24
typedef struct {
    pd_AccountId_V12_t controller;
} pd_staking_chill_other_V12_t;

#define PD_CALL_STAKING_FORCE_APPLY_MIN_COMMISSION_V12 25
typedef struct {
    pd_AccountId_V12_t validator_stash;
} pd_staking_force_apply_min_commission_V12_t;

#define PD_CALL_GRANDPA_NOTE_STALLED_V12 2
typedef struct {
    pd_BlockNumber_t delay;
    pd_BlockNumber_t best_finalized_block_number;
} pd_grandpa_note_stalled_V12_t;

#define PD_CALL_DEMOCRACY_PROPOSE_V12 0
typedef struct {
    pd_Hash_t proposal_hash;
    pd_CompactBalance_t amount;
} pd_democracy_propose_V12_t;

#define PD_CALL_DEMOCRACY_SECOND_V12 1
typedef struct {
    pd_Compactu32_t proposal;
    pd_Compactu32_t seconds_upper_bound;
} pd_democracy_second_V12_t;

#define PD_CALL_DEMOCRACY_VOTE_V12 2
typedef struct {
    pd_Compactu32_t ref_index;
    pd_AccountVote_V12_t vote;
} pd_democracy_vote_V12_t;

#define PD_CALL_DEMOCRACY_EMERGENCY_CANCEL_V12 3
typedef struct {
    pd_ReferendumIndex_V12_t ref_index;
} pd_democracy_emergency_cancel_V12_t;

#define PD_CALL_DEMOCRACY_EXTERNAL_PROPOSE_V12 4
typedef struct {
    pd_Hash_t proposal_hash;
} pd_democracy_external_propose_V12_t;

#define PD_CALL_DEMOCRACY_EXTERNAL_PROPOSE_MAJORITY_V12 5
typedef struct {
    pd_Hash_t proposal_hash;
} pd_democracy_external_propose_majority_V12_t;

#define PD_CALL_DEMOCRACY_EXTERNAL_PROPOSE_DEFAULT_V12 6
typedef struct {
    pd_Hash_t proposal_hash;
} pd_democracy_external_propose_default_V12_t;

#define PD_CALL_DEMOCRACY_FAST_TRACK_V12 7
typedef struct {
    pd_Hash_t proposal_hash;
    pd_BlockNumber_t voting_period;
    pd_BlockNumber_t delay;
} pd_democracy_fast_track_V12_t;

#define PD_CALL_DEMOCRACY_VETO_EXTERNAL_V12 8
typedef struct {
    pd_Hash_t proposal_hash;
} pd_democracy_veto_external_V12_t;

#define PD_CALL_DEMOCRACY_CANCEL_REFERENDUM_V12 9
typedef struct {
    pd_Compactu32_t ref_index;
} pd_democracy_cancel_referendum_V12_t;

#define PD_CALL_DEMOCRACY_CANCEL_QUEUED_V12 10
typedef struct {
    pd_ReferendumIndex_V12_t which;
} pd_democracy_cancel_queued_V12_t;

#define PD_CALL_DEMOCRACY_DELEGATE_V12 11
typedef struct {
    pd_AccountId_V12_t to;
    pd_Conviction_V12_t conviction;
    pd_Balance_t balance;
} pd_democracy_delegate_V12_t;

#define PD_CALL_DEMOCRACY_UNDELEGATE_V12 12
typedef struct {
} pd_democracy_undelegate_V12_t;

#define PD_CALL_DEMOCRACY_CLEAR_PUBLIC_PROPOSALS_V12 13
typedef struct {
} pd_democracy_clear_public_proposals_V12_t;

#define PD_CALL_DEMOCRACY_NOTE_PREIMAGE_V12 14
typedef struct {
    pd_Bytes_t encoded_proposal;
} pd_democracy_note_preimage_V12_t;

#define PD_CALL_DEMOCRACY_NOTE_PREIMAGE_OPERATIONAL_V12 15
typedef struct {
    pd_Bytes_t encoded_proposal;
} pd_democracy_note_preimage_operational_V12_t;

#define PD_CALL_DEMOCRACY_NOTE_IMMINENT_PREIMAGE_V12 16
typedef struct {
    pd_Bytes_t encoded_proposal;
} pd_democracy_note_imminent_preimage_V12_t;

#define PD_CALL_DEMOCRACY_NOTE_IMMINENT_PREIMAGE_OPERATIONAL_V12 17
typedef struct {
    pd_Bytes_t encoded_proposal;
} pd_democracy_note_imminent_preimage_operational_V12_t;

#define PD_CALL_DEMOCRACY_REAP_PREIMAGE_V12 18
typedef struct {
    pd_Hash_t proposal_hash;
    pd_Compactu32_t proposal_len_upper_bound;
} pd_democracy_reap_preimage_V12_t;

#define PD_CALL_DEMOCRACY_UNLOCK_V12 19
typedef struct {
    pd_AccountId_V12_t target;
} pd_democracy_unlock_V12_t;

#define PD_CALL_DEMOCRACY_REMOVE_VOTE_V12 20
typedef struct {
    pd_ReferendumIndex_V12_t index;
} pd_democracy_remove_vote_V12_t;

#define PD_CALL_DEMOCRACY_REMOVE_OTHER_VOTE_V12 21
typedef struct {
    pd_AccountId_V12_t target;
    pd_ReferendumIndex_V12_t index;
} pd_democracy_remove_other_vote_V12_t;

#define PD_CALL_DEMOCRACY_ENACT_PROPOSAL_V12 22
typedef struct {
    pd_Hash_t proposal_hash;
    pd_ReferendumIndex_V12_t index;
} pd_democracy_enact_proposal_V12_t;

#define PD_CALL_DEMOCRACY_CANCEL_PROPOSAL_V12 24
typedef struct {
    pd_Compactu32_t prop_index;
} pd_democracy_cancel_proposal_V12_t;

#define PD_CALL_COUNCIL_VOTE_V12 3
typedef struct {
    pd_Hash_t proposal;
    pd_Compactu32_t index;
    pd_bool_t approve;
} pd_council_vote_V12_t;

#define PD_CALL_COUNCIL_CLOSE_V12 4
typedef struct {
    pd_Hash_t proposal_hash;
    pd_Compactu32_t index;
    pd_Compactu64_t proposal_weight_bound;
    pd_Compactu32_t length_bound;
} pd_council_close_V12_t;

#define PD_CALL_COUNCIL_DISAPPROVE_PROPOSAL_V12 5
typedef struct {
    pd_Hash_t proposal_hash;
} pd_council_disapprove_proposal_V12_t;

#define PD_CALL_TECHNICALCOMMITTEE_VOTE_V12 3
typedef struct {
    pd_Hash_t proposal;
    pd_Compactu32_t index;
    pd_bool_t approve;
} pd_technicalcommittee_vote_V12_t;

#define PD_CALL_TECHNICALCOMMITTEE_CLOSE_V12 4
typedef struct {
    pd_Hash_t proposal_hash;
    pd_Compactu32_t index;
    pd_Compactu64_t proposal_weight_bound;
    pd_Compactu32_t length_bound;
} pd_technicalcommittee_close_V12_t;

#define PD_CALL_TECHNICALCOMMITTEE_DISAPPROVE_PROPOSAL_V12 5
typedef struct {
    pd_Hash_t proposal_hash;
} pd_technicalcommittee_disapprove_proposal_V12_t;

#define PD_CALL_PHRAGMENELECTION_REMOVE_VOTER_V12 1
typedef struct {
} pd_phragmenelection_remove_voter_V12_t;

#define PD_CALL_PHRAGMENELECTION_SUBMIT_CANDIDACY_V12 2
typedef struct {
    pd_Compactu32_t candidate_count;
} pd_phragmenelection_submit_candidacy_V12_t;

#define PD_CALL_PHRAGMENELECTION_REMOVE_MEMBER_V12 4
typedef struct {
    pd_LookupasStaticLookupSource_V12_t who;
    pd_bool_t has_replacement;
} pd_phragmenelection_remove_member_V12_t;

#define PD_CALL_PHRAGMENELECTION_CLEAN_DEFUNCT_VOTERS_V12 5
typedef struct {
    pd_u32_t num_voters;
    pd_u32_t num_defunct;
} pd_phragmenelection_clean_defunct_voters_V12_t;

#define PD_CALL_TECHNICALMEMBERSHIP_ADD_MEMBER_V12 0
typedef struct {
    pd_AccountId_V12_t who;
} pd_technicalmembership_add_member_V12_t;

#define PD_CALL_TECHNICALMEMBERSHIP_REMOVE_MEMBER_V12 1
typedef struct {
    pd_AccountId_V12_t who;
} pd_technicalmembership_remove_member_V12_t;

#define PD_CALL_TECHNICALMEMBERSHIP_SWAP_MEMBER_V12 2
typedef struct {
    pd_AccountId_V12_t remove;
    pd_AccountId_V12_t add;
} pd_technicalmembership_swap_member_V12_t;

#define PD_CALL_TECHNICALMEMBERSHIP_RESET_MEMBERS_V12 3
typedef struct {
    pd_VecAccountId_V12_t members;
} pd_technicalmembership_reset_members_V12_t;

#define PD_CALL_TECHNICALMEMBERSHIP_CHANGE_KEY_V12 4
typedef struct {
    pd_AccountId_V12_t new_;
} pd_technicalmembership_change_key_V12_t;

#define PD_CALL_TECHNICALMEMBERSHIP_SET_PRIME_V12 5
typedef struct {
    pd_AccountId_V12_t who;
} pd_technicalmembership_set_prime_V12_t;

#define PD_CALL_TECHNICALMEMBERSHIP_CLEAR_PRIME_V12 6
typedef struct {
} pd_technicalmembership_clear_prime_V12_t;

#define PD_CALL_TREASURY_PROPOSE_SPEND_V12 0
typedef struct {
    pd_CompactBalance_t amount;
    pd_LookupasStaticLookupSource_V12_t beneficiary;
} pd_treasury_propose_spend_V12_t;

#define PD_CALL_TREASURY_REJECT_PROPOSAL_V12 1
typedef struct {
    pd_Compactu32_t proposal_id;
} pd_treasury_reject_proposal_V12_t;

#define PD_CALL_TREASURY_APPROVE_PROPOSAL_V12 2
typedef struct {
    pd_Compactu32_t proposal_id;
} pd_treasury_approve_proposal_V12_t;

#define PD_CALL_CLAIMS_CLAIM_V12 0
typedef struct {
    pd_AccountId_V12_t dest;
    pd_EcdsaSignature_V12_t ethereum_signature;
} pd_claims_claim_V12_t;

#define PD_CALL_CLAIMS_CLAIM_ATTEST_V12 2
typedef struct {
    pd_AccountId_V12_t dest;
    pd_EcdsaSignature_V12_t ethereum_signature;
    pd_Bytes_t statement;
} pd_claims_claim_attest_V12_t;

#define PD_CALL_CLAIMS_ATTEST_V12 3
typedef struct {
    pd_Bytes_t statement;
} pd_claims_attest_V12_t;

#define PD_CALL_CLAIMS_MOVE_CLAIM_V12 4
typedef struct {
    pd_EthereumAddress_V12_t old;
    pd_EthereumAddress_V12_t new_;
    pd_OptionAccountId_V12_t maybe_preclaim;
} pd_claims_move_claim_V12_t;

#define PD_CALL_VESTING_VEST_V12 0
typedef struct {
} pd_vesting_vest_V12_t;

#define PD_CALL_VESTING_VEST_OTHER_V12 1
typedef struct {
    pd_LookupasStaticLookupSource_V12_t target;
} pd_vesting_vest_other_V12_t;

#define PD_CALL_VESTING_MERGE_SCHEDULES_V12 4
typedef struct {
    pd_u32_t schedule1_index;
    pd_u32_t schedule2_index;
} pd_vesting_merge_schedules_V12_t;

#define PD_CALL_IDENTITY_ADD_REGISTRAR_V12 0
typedef struct {
    pd_AccountId_V12_t account;
} pd_identity_add_registrar_V12_t;

#define PD_CALL_IDENTITY_CLEAR_IDENTITY_V12 3
typedef struct {
} pd_identity_clear_identity_V12_t;

#define PD_CALL_IDENTITY_REQUEST_JUDGEMENT_V12 4
typedef struct {
    pd_Compactu32_t reg_index;
    pd_Compactu128_t max_fee;
} pd_identity_request_judgement_V12_t;

#define PD_CALL_IDENTITY_CANCEL_REQUEST_V12 5
typedef struct {
    pd_RegistrarIndex_V12_t reg_index;
} pd_identity_cancel_request_V12_t;

#define PD_CALL_IDENTITY_SET_FEE_V12 6
typedef struct {
    pd_Compactu32_t index;
    pd_Compactu128_t fee;
} pd_identity_set_fee_V12_t;

#define PD_CALL_IDENTITY_SET_ACCOUNT_ID_V12 7
typedef struct {
    pd_Compactu32_t index;
    pd_AccountId_V12_t new_;
} pd_identity_set_account_id_V12_t;

#define PD_CALL_IDENTITY_KILL_IDENTITY_V12 10
typedef struct {
    pd_LookupasStaticLookupSource_V12_t target;
} pd_identity_kill_identity_V12_t;

#define PD_CALL_IDENTITY_REMOVE_SUB_V12 13
typedef struct {
    pd_LookupasStaticLookupSource_V12_t sub;
} pd_identity_remove_sub_V12_t;

#define PD_CALL_IDENTITY_QUIT_SUB_V12 14
typedef struct {
} pd_identity_quit_sub_V12_t;

#define PD_CALL_PROXY_ADD_PROXY_V12 1
typedef struct {
    pd_AccountId_V12_t delegate;
    pd_ProxyType_V12_t proxy_type;
    pd_BlockNumber_t delay;
} pd_proxy_add_proxy_V12_t;

#define PD_CALL_PROXY_REMOVE_PROXY_V12 2
typedef struct {
    pd_AccountId_V12_t delegate;
    pd_ProxyType_V12_t proxy_type;
    pd_BlockNumber_t delay;
} pd_proxy_remove_proxy_V12_t;

#define PD_CALL_PROXY_REMOVE_PROXIES_V12 3
typedef struct {
} pd_proxy_remove_proxies_V12_t;

#define PD_CALL_PROXY_ANONYMOUS_V12 4
typedef struct {
    pd_ProxyType_V12_t proxy_type;
    pd_BlockNumber_t delay;
    pd_u16_t index;
} pd_proxy_anonymous_V12_t;

#define PD_CALL_PROXY_KILL_ANONYMOUS_V12 5
typedef struct {
    pd_AccountId_V12_t spawner;
    pd_ProxyType_V12_t proxy_type;
    pd_u16_t index;
    pd_Compactu32_t height;
    pd_Compactu32_t ext_index;
} pd_proxy_kill_anonymous_V12_t;

#define PD_CALL_PROXY_PROXY_ANNOUNCED_V12 9
typedef struct {
    pd_AccountId_V12_t delegate;
    pd_AccountId_V12_t real;
    pd_OptionProxyType_V12_t force_proxy_type;
    pd_Call_t call;
} pd_proxy_proxy_announced_V12_t;

#define PD_CALL_BOUNTIES_PROPOSE_BOUNTY_V12 0
typedef struct {
    pd_CompactBalance_t amount;
    pd_Bytes_t description;
} pd_bounties_propose_bounty_V12_t;

#define PD_CALL_BOUNTIES_APPROVE_BOUNTY_V12 1
typedef struct {
    pd_Compactu32_t bounty_id;
} pd_bounties_approve_bounty_V12_t;

#define PD_CALL_BOUNTIES_PROPOSE_CURATOR_V12 2
typedef struct {
    pd_Compactu32_t bounty_id;
    pd_LookupasStaticLookupSource_V12_t curator;
    pd_CompactBalance_t fee;
} pd_bounties_propose_curator_V12_t;

#define PD_CALL_BOUNTIES_UNASSIGN_CURATOR_V12 3
typedef struct {
    pd_Compactu32_t bounty_id;
} pd_bounties_unassign_curator_V12_t;

#define PD_CALL_BOUNTIES_ACCEPT_CURATOR_V12 4
typedef struct {
    pd_Compactu32_t bounty_id;
} pd_bounties_accept_curator_V12_t;

#define PD_CALL_BOUNTIES_AWARD_BOUNTY_V12 5
typedef struct {
    pd_Compactu32_t bounty_id;
    pd_LookupasStaticLookupSource_V12_t beneficiary;
} pd_bounties_award_bounty_V12_t;

#define PD_CALL_BOUNTIES_CLAIM_BOUNTY_V12 6
typedef struct {
    pd_Compactu32_t bounty_id;
} pd_bounties_claim_bounty_V12_t;

#define PD_CALL_BOUNTIES_CLOSE_BOUNTY_V12 7
typedef struct {
    pd_Compactu32_t bounty_id;
} pd_bounties_close_bounty_V12_t;

#define PD_CALL_BOUNTIES_EXTEND_BOUNTY_EXPIRY_V12 8
typedef struct {
    pd_Compactu32_t bounty_id;
    pd_Bytes_t remark;
} pd_bounties_extend_bounty_expiry_V12_t;

#define PD_CALL_CHILDBOUNTIES_ADD_CHILD_BOUNTY_V12 0
typedef struct {
    pd_Compactu32_t parent_bounty_id;
    pd_CompactBalance_t amount;
    pd_Vecu8_t description;
} pd_childbounties_add_child_bounty_V12_t;

#define PD_CALL_CHILDBOUNTIES_PROPOSE_CURATOR_V12 1
typedef struct {
    pd_Compactu32_t parent_bounty_id;
    pd_Compactu32_t child_bounty_id;
    pd_LookupasStaticLookupSource_V12_t curator;
    pd_CompactBalance_t fee;
} pd_childbounties_propose_curator_V12_t;

#define PD_CALL_CHILDBOUNTIES_ACCEPT_CURATOR_V12 2
typedef struct {
    pd_Compactu32_t parent_bounty_id;
    pd_Compactu32_t child_bounty_id;
} pd_childbounties_accept_curator_V12_t;

#define PD_CALL_CHILDBOUNTIES_UNASSIGN_CURATOR_V12 3
typedef struct {
    pd_Compactu32_t parent_bounty_id;
    pd_Compactu32_t child_bounty_id;
} pd_childbounties_unassign_curator_V12_t;

#define PD_CALL_CHILDBOUNTIES_AWARD_CHILD_BOUNTY_V12 4
typedef struct {
    pd_Compactu32_t parent_bounty_id;
    pd_Compactu32_t child_bounty_id;
    pd_LookupasStaticLookupSource_V12_t beneficiary;
} pd_childbounties_award_child_bounty_V12_t;

#define PD_CALL_CHILDBOUNTIES_CLAIM_CHILD_BOUNTY_V12 5
typedef struct {
    pd_Compactu32_t parent_bounty_id;
    pd_Compactu32_t child_bounty_id;
} pd_childbounties_claim_child_bounty_V12_t;

#define PD_CALL_CHILDBOUNTIES_CLOSE_CHILD_BOUNTY_V12 6
typedef struct {
    pd_Compactu32_t parent_bounty_id;
    pd_Compactu32_t child_bounty_id;
} pd_childbounties_close_child_bounty_V12_t;

#define PD_CALL_TIPS_REPORT_AWESOME_V12 0
typedef struct {
    pd_Bytes_t reason;
    pd_AccountId_V12_t who;
} pd_tips_report_awesome_V12_t;

#define PD_CALL_TIPS_RETRACT_TIP_V12 1
typedef struct {
    pd_Hash_t hash;
} pd_tips_retract_tip_V12_t;

#define PD_CALL_TIPS_TIP_NEW_V12 2
typedef struct {
    pd_Bytes_t reason;
    pd_AccountId_V12_t who;
    pd_Compactu128_t tip_value;
} pd_tips_tip_new_V12_t;

#define PD_CALL_TIPS_TIP_V12 3
typedef struct {
    pd_Hash_t hash;
    pd_Compactu128_t tip_value;
} pd_tips_tip_V12_t;

#define PD_CALL_TIPS_CLOSE_TIP_V12 4
typedef struct {
    pd_Hash_t hash;
} pd_tips_close_tip_V12_t;

#define PD_CALL_TIPS_SLASH_TIP_V12 5
typedef struct {
    pd_Hash_t hash;
} pd_tips_slash_tip_V12_t;

#define PD_CALL_ELECTIONPROVIDERMULTIPHASE_GOVERNANCE_FALLBACK_V12 4
typedef struct {
    pd_Optionu32_t maybe_max_voters;
    pd_Optionu32_t maybe_max_targets;
} pd_electionprovidermultiphase_governance_fallback_V12_t;

#define PD_CALL_BAGSLIST_REBAG_V12 0
typedef struct {
    pd_AccountId_V12_t dislocated;
} pd_bagslist_rebag_V12_t;

#define PD_CALL_BAGSLIST_PUT_IN_FRONT_OF_V12 1
typedef struct {
    pd_AccountId_V12_t lighter;
} pd_bagslist_put_in_front_of_V12_t;

#define PD_CALL_CONFIGURATION_SET_VALIDATION_UPGRADE_COOLDOWN_V12 0
typedef struct {
    pd_BlockNumber_t new_;
} pd_configuration_set_validation_upgrade_cooldown_V12_t;

#define PD_CALL_CONFIGURATION_SET_VALIDATION_UPGRADE_DELAY_V12 1
typedef struct {
    pd_BlockNumber_t new_;
} pd_configuration_set_validation_upgrade_delay_V12_t;

#define PD_CALL_CONFIGURATION_SET_CODE_RETENTION_PERIOD_V12 2
typedef struct {
    pd_BlockNumber_t new_;
} pd_configuration_set_code_retention_period_V12_t;

#define PD_CALL_CONFIGURATION_SET_MAX_CODE_SIZE_V12 3
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_max_code_size_V12_t;

#define PD_CALL_CONFIGURATION_SET_MAX_POV_SIZE_V12 4
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_max_pov_size_V12_t;

#define PD_CALL_CONFIGURATION_SET_MAX_HEAD_DATA_SIZE_V12 5
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_max_head_data_size_V12_t;

#define PD_CALL_CONFIGURATION_SET_PARATHREAD_CORES_V12 6
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_parathread_cores_V12_t;

#define PD_CALL_CONFIGURATION_SET_PARATHREAD_RETRIES_V12 7
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_parathread_retries_V12_t;

#define PD_CALL_CONFIGURATION_SET_GROUP_ROTATION_FREQUENCY_V12 8
typedef struct {
    pd_BlockNumber_t new_;
} pd_configuration_set_group_rotation_frequency_V12_t;

#define PD_CALL_CONFIGURATION_SET_CHAIN_AVAILABILITY_PERIOD_V12 9
typedef struct {
    pd_BlockNumber_t new_;
} pd_configuration_set_chain_availability_period_V12_t;

#define PD_CALL_CONFIGURATION_SET_THREAD_AVAILABILITY_PERIOD_V12 10
typedef struct {
    pd_BlockNumber_t new_;
} pd_configuration_set_thread_availability_period_V12_t;

#define PD_CALL_CONFIGURATION_SET_SCHEDULING_LOOKAHEAD_V12 11
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_scheduling_lookahead_V12_t;

#define PD_CALL_CONFIGURATION_SET_MAX_VALIDATORS_PER_CORE_V12 12
typedef struct {
    pd_Optionu32_t new_;
} pd_configuration_set_max_validators_per_core_V12_t;

#define PD_CALL_CONFIGURATION_SET_MAX_VALIDATORS_V12 13
typedef struct {
    pd_Optionu32_t new_;
} pd_configuration_set_max_validators_V12_t;

#define PD_CALL_CONFIGURATION_SET_DISPUTE_POST_CONCLUSION_ACCEPTANCE_PERIOD_V12 15
typedef struct {
    pd_BlockNumber_t new_;
} pd_configuration_set_dispute_post_conclusion_acceptance_period_V12_t;

#define PD_CALL_CONFIGURATION_SET_DISPUTE_MAX_SPAM_SLOTS_V12 16
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_dispute_max_spam_slots_V12_t;

#define PD_CALL_CONFIGURATION_SET_DISPUTE_CONCLUSION_BY_TIME_OUT_PERIOD_V12 17
typedef struct {
    pd_BlockNumber_t new_;
} pd_configuration_set_dispute_conclusion_by_time_out_period_V12_t;

#define PD_CALL_CONFIGURATION_SET_NO_SHOW_SLOTS_V12 18
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_no_show_slots_V12_t;

#define PD_CALL_CONFIGURATION_SET_N_DELAY_TRANCHES_V12 19
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_n_delay_tranches_V12_t;

#define PD_CALL_CONFIGURATION_SET_ZEROTH_DELAY_TRANCHE_WIDTH_V12 20
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_zeroth_delay_tranche_width_V12_t;

#define PD_CALL_CONFIGURATION_SET_NEEDED_APPROVALS_V12 21
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_needed_approvals_V12_t;

#define PD_CALL_CONFIGURATION_SET_RELAY_VRF_MODULO_SAMPLES_V12 22
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_relay_vrf_modulo_samples_V12_t;

#define PD_CALL_CONFIGURATION_SET_MAX_UPWARD_QUEUE_COUNT_V12 23
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_max_upward_queue_count_V12_t;

#define PD_CALL_CONFIGURATION_SET_MAX_UPWARD_QUEUE_SIZE_V12 24
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_max_upward_queue_size_V12_t;

#define PD_CALL_CONFIGURATION_SET_MAX_DOWNWARD_MESSAGE_SIZE_V12 25
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_max_downward_message_size_V12_t;

#define PD_CALL_CONFIGURATION_SET_UMP_SERVICE_TOTAL_WEIGHT_V12 26
typedef struct {
    pd_Weight_V12_t new_;
} pd_configuration_set_ump_service_total_weight_V12_t;

#define PD_CALL_CONFIGURATION_SET_MAX_UPWARD_MESSAGE_SIZE_V12 27
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_max_upward_message_size_V12_t;

#define PD_CALL_CONFIGURATION_SET_MAX_UPWARD_MESSAGE_NUM_PER_CANDIDATE_V12 28
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_max_upward_message_num_per_candidate_V12_t;

#define PD_CALL_CONFIGURATION_SET_HRMP_OPEN_REQUEST_TTL_V12 29
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_hrmp_open_request_ttl_V12_t;

#define PD_CALL_CONFIGURATION_SET_HRMP_SENDER_DEPOSIT_V12 30
typedef struct {
    pd_Balance_t new_;
} pd_configuration_set_hrmp_sender_deposit_V12_t;

#define PD_CALL_CONFIGURATION_SET_HRMP_RECIPIENT_DEPOSIT_V12 31
typedef struct {
    pd_Balance_t new_;
} pd_configuration_set_hrmp_recipient_deposit_V12_t;

#define PD_CALL_CONFIGURATION_SET_HRMP_CHANNEL_MAX_CAPACITY_V12 32
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_hrmp_channel_max_capacity_V12_t;

#define PD_CALL_CONFIGURATION_SET_HRMP_CHANNEL_MAX_TOTAL_SIZE_V12 33
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_hrmp_channel_max_total_size_V12_t;

#define PD_CALL_CONFIGURATION_SET_HRMP_MAX_PARACHAIN_INBOUND_CHANNELS_V12 34
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_hrmp_max_parachain_inbound_channels_V12_t;

#define PD_CALL_CONFIGURATION_SET_HRMP_MAX_PARATHREAD_INBOUND_CHANNELS_V12 35
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_hrmp_max_parathread_inbound_channels_V12_t;

#define PD_CALL_CONFIGURATION_SET_HRMP_CHANNEL_MAX_MESSAGE_SIZE_V12 36
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_hrmp_channel_max_message_size_V12_t;

#define PD_CALL_CONFIGURATION_SET_HRMP_MAX_PARACHAIN_OUTBOUND_CHANNELS_V12 37
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_hrmp_max_parachain_outbound_channels_V12_t;

#define PD_CALL_CONFIGURATION_SET_HRMP_MAX_PARATHREAD_OUTBOUND_CHANNELS_V12 38
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_hrmp_max_parathread_outbound_channels_V12_t;

#define PD_CALL_CONFIGURATION_SET_HRMP_MAX_MESSAGE_NUM_PER_CANDIDATE_V12 39
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_hrmp_max_message_num_per_candidate_V12_t;

#define PD_CALL_CONFIGURATION_SET_UMP_MAX_INDIVIDUAL_WEIGHT_V12 40
typedef struct {
    pd_Weight_V12_t new_;
} pd_configuration_set_ump_max_individual_weight_V12_t;

#define PD_CALL_CONFIGURATION_SET_PVF_CHECKING_ENABLED_V12 41
typedef struct {
    pd_bool_t new_;
} pd_configuration_set_pvf_checking_enabled_V12_t;

#define PD_CALL_CONFIGURATION_SET_PVF_VOTING_TTL_V12 42
typedef struct {
    pd_SessionIndex_V12_t new_;
} pd_configuration_set_pvf_voting_ttl_V12_t;

#define PD_CALL_CONFIGURATION_SET_MINIMUM_VALIDATION_UPGRADE_DELAY_V12 43
typedef struct {
    pd_BlockNumber_t new_;
} pd_configuration_set_minimum_validation_upgrade_delay_V12_t;

#define PD_CALL_CONFIGURATION_SET_BYPASS_CONSISTENCY_CHECK_V12 44
typedef struct {
    pd_bool_t new_;
} pd_configuration_set_bypass_consistency_check_V12_t;

#define PD_CALL_INITIALIZER_FORCE_APPROVE_V12 0
typedef struct {
    pd_BlockNumber_t up_to;
} pd_initializer_force_approve_V12_t;

#define PD_CALL_HRMP_FORCE_PROCESS_HRMP_OPEN_V12 4
typedef struct {
    pd_u32_t channels;
} pd_hrmp_force_process_hrmp_open_V12_t;

#define PD_CALL_HRMP_FORCE_PROCESS_HRMP_CLOSE_V12 5
typedef struct {
    pd_u32_t channels;
} pd_hrmp_force_process_hrmp_close_V12_t;

#define PD_CALL_PARASDISPUTES_FORCE_UNFREEZE_V12 0
typedef struct {
} pd_parasdisputes_force_unfreeze_V12_t;

#define PD_CALL_REGISTRAR_RESERVE_V12 5
typedef struct {
} pd_registrar_reserve_V12_t;

#define PD_CALL_AUCTIONS_NEW_AUCTION_V12 0
typedef struct {
    pd_Compactu32_t duration;
    pd_Compactu32_t lease_period_index;
} pd_auctions_new_auction_V12_t;

#define PD_CALL_AUCTIONS_BID_V12 1
typedef struct {
    pd_Compactu32_t para;
    pd_Compactu32_t auction_index;
    pd_Compactu32_t first_slot;
    pd_Compactu32_t last_slot;
    pd_CompactBalance_t amount;
} pd_auctions_bid_V12_t;

#define PD_CALL_AUCTIONS_CANCEL_AUCTION_V12 2
typedef struct {
} pd_auctions_cancel_auction_V12_t;

#endif

typedef union {
    pd_balances_transfer_all_V12_t balances_transfer_all_V12;
    pd_staking_bond_V12_t staking_bond_V12;
    pd_staking_bond_extra_V12_t staking_bond_extra_V12;
    pd_staking_unbond_V12_t staking_unbond_V12;
    pd_staking_withdraw_unbonded_V12_t staking_withdraw_unbonded_V12;
    pd_staking_validate_V12_t staking_validate_V12;
    pd_staking_nominate_V12_t staking_nominate_V12;
    pd_staking_chill_V12_t staking_chill_V12;
    pd_staking_set_payee_V12_t staking_set_payee_V12;
    pd_staking_set_controller_V12_t staking_set_controller_V12;
    pd_staking_payout_stakers_V12_t staking_payout_stakers_V12;
    pd_staking_rebond_V12_t staking_rebond_V12;
    pd_session_set_keys_V12_t session_set_keys_V12;
    pd_session_purge_keys_V12_t session_purge_keys_V12;
    pd_utility_batch_V12_t utility_batch_V12;
    pd_utility_batch_all_V12_t utility_batch_all_V12;
#ifdef SUBSTRATE_PARSER_FULL
    pd_preimage_note_preimage_V12_t preimage_note_preimage_V12;
    pd_preimage_unnote_preimage_V12_t preimage_unnote_preimage_V12;
    pd_preimage_request_preimage_V12_t preimage_request_preimage_V12;
    pd_preimage_unrequest_preimage_V12_t preimage_unrequest_preimage_V12;
    pd_timestamp_set_V12_t timestamp_set_V12;
    pd_indices_claim_V12_t indices_claim_V12;
    pd_indices_free_V12_t indices_free_V12;
    pd_indices_force_transfer_V12_t indices_force_transfer_V12;
    pd_indices_freeze_V12_t indices_freeze_V12;
    pd_balances_force_unreserve_V12_t balances_force_unreserve_V12;
    pd_staking_set_validator_count_V12_t staking_set_validator_count_V12;
    pd_staking_increase_validator_count_V12_t staking_increase_validator_count_V12;
    pd_staking_force_no_eras_V12_t staking_force_no_eras_V12;
    pd_staking_force_new_era_V12_t staking_force_new_era_V12;
    pd_staking_force_unstake_V12_t staking_force_unstake_V12;
    pd_staking_force_new_era_always_V12_t staking_force_new_era_always_V12;
    pd_staking_set_history_depth_V12_t staking_set_history_depth_V12;
    pd_staking_reap_stash_V12_t staking_reap_stash_V12;
    pd_staking_kick_V12_t staking_kick_V12;
    pd_staking_chill_other_V12_t staking_chill_other_V12;
    pd_staking_force_apply_min_commission_V12_t staking_force_apply_min_commission_V12;
    pd_grandpa_note_stalled_V12_t grandpa_note_stalled_V12;
    pd_democracy_propose_V12_t democracy_propose_V12;
    pd_democracy_second_V12_t democracy_second_V12;
    pd_democracy_vote_V12_t democracy_vote_V12;
    pd_democracy_emergency_cancel_V12_t democracy_emergency_cancel_V12;
    pd_democracy_external_propose_V12_t democracy_external_propose_V12;
    pd_democracy_external_propose_majority_V12_t democracy_external_propose_majority_V12;
    pd_democracy_external_propose_default_V12_t democracy_external_propose_default_V12;
    pd_democracy_fast_track_V12_t democracy_fast_track_V12;
    pd_democracy_veto_external_V12_t democracy_veto_external_V12;
    pd_democracy_cancel_referendum_V12_t democracy_cancel_referendum_V12;
    pd_democracy_cancel_queued_V12_t democracy_cancel_queued_V12;
    pd_democracy_delegate_V12_t democracy_delegate_V12;
    pd_democracy_undelegate_V12_t democracy_undelegate_V12;
    pd_democracy_clear_public_proposals_V12_t democracy_clear_public_proposals_V12;
    pd_democracy_note_preimage_V12_t democracy_note_preimage_V12;
    pd_democracy_note_preimage_operational_V12_t democracy_note_preimage_operational_V12;
    pd_democracy_note_imminent_preimage_V12_t democracy_note_imminent_preimage_V12;
    pd_democracy_note_imminent_preimage_operational_V12_t democracy_note_imminent_preimage_operational_V12;
    pd_democracy_reap_preimage_V12_t democracy_reap_preimage_V12;
    pd_democracy_unlock_V12_t democracy_unlock_V12;
    pd_democracy_remove_vote_V12_t democracy_remove_vote_V12;
    pd_democracy_remove_other_vote_V12_t democracy_remove_other_vote_V12;
    pd_democracy_enact_proposal_V12_t democracy_enact_proposal_V12;
    pd_democracy_cancel_proposal_V12_t democracy_cancel_proposal_V12;
    pd_council_vote_V12_t council_vote_V12;
    pd_council_close_V12_t council_close_V12;
    pd_council_disapprove_proposal_V12_t council_disapprove_proposal_V12;
    pd_technicalcommittee_vote_V12_t technicalcommittee_vote_V12;
    pd_technicalcommittee_close_V12_t technicalcommittee_close_V12;
    pd_technicalcommittee_disapprove_proposal_V12_t technicalcommittee_disapprove_proposal_V12;
    pd_phragmenelection_remove_voter_V12_t phragmenelection_remove_voter_V12;
    pd_phragmenelection_submit_candidacy_V12_t phragmenelection_submit_candidacy_V12;
    pd_phragmenelection_remove_member_V12_t phragmenelection_remove_member_V12;
    pd_phragmenelection_clean_defunct_voters_V12_t phragmenelection_clean_defunct_voters_V12;
    pd_technicalmembership_add_member_V12_t technicalmembership_add_member_V12;
    pd_technicalmembership_remove_member_V12_t technicalmembership_remove_member_V12;
    pd_technicalmembership_swap_member_V12_t technicalmembership_swap_member_V12;
    pd_technicalmembership_reset_members_V12_t technicalmembership_reset_members_V12;
    pd_technicalmembership_change_key_V12_t technicalmembership_change_key_V12;
    pd_technicalmembership_set_prime_V12_t technicalmembership_set_prime_V12;
    pd_technicalmembership_clear_prime_V12_t technicalmembership_clear_prime_V12;
    pd_treasury_propose_spend_V12_t treasury_propose_spend_V12;
    pd_treasury_reject_proposal_V12_t treasury_reject_proposal_V12;
    pd_treasury_approve_proposal_V12_t treasury_approve_proposal_V12;
    pd_claims_claim_V12_t claims_claim_V12;
    pd_claims_claim_attest_V12_t claims_claim_attest_V12;
    pd_claims_attest_V12_t claims_attest_V12;
    pd_claims_move_claim_V12_t claims_move_claim_V12;
    pd_vesting_vest_V12_t vesting_vest_V12;
    pd_vesting_vest_other_V12_t vesting_vest_other_V12;
    pd_vesting_merge_schedules_V12_t vesting_merge_schedules_V12;
    pd_identity_add_registrar_V12_t identity_add_registrar_V12;
    pd_identity_clear_identity_V12_t identity_clear_identity_V12;
    pd_identity_request_judgement_V12_t identity_request_judgement_V12;
    pd_identity_cancel_request_V12_t identity_cancel_request_V12;
    pd_identity_set_fee_V12_t identity_set_fee_V12;
    pd_identity_set_account_id_V12_t identity_set_account_id_V12;
    pd_identity_kill_identity_V12_t identity_kill_identity_V12;
    pd_identity_remove_sub_V12_t identity_remove_sub_V12;
    pd_identity_quit_sub_V12_t identity_quit_sub_V12;
    pd_proxy_add_proxy_V12_t proxy_add_proxy_V12;
    pd_proxy_remove_proxy_V12_t proxy_remove_proxy_V12;
    pd_proxy_remove_proxies_V12_t proxy_remove_proxies_V12;
    pd_proxy_anonymous_V12_t proxy_anonymous_V12;
    pd_proxy_kill_anonymous_V12_t proxy_kill_anonymous_V12;
    pd_proxy_proxy_announced_V12_t proxy_proxy_announced_V12;
    pd_bounties_propose_bounty_V12_t bounties_propose_bounty_V12;
    pd_bounties_approve_bounty_V12_t bounties_approve_bounty_V12;
    pd_bounties_propose_curator_V12_t bounties_propose_curator_V12;
    pd_bounties_unassign_curator_V12_t bounties_unassign_curator_V12;
    pd_bounties_accept_curator_V12_t bounties_accept_curator_V12;
    pd_bounties_award_bounty_V12_t bounties_award_bounty_V12;
    pd_bounties_claim_bounty_V12_t bounties_claim_bounty_V12;
    pd_bounties_close_bounty_V12_t bounties_close_bounty_V12;
    pd_bounties_extend_bounty_expiry_V12_t bounties_extend_bounty_expiry_V12;
    pd_childbounties_add_child_bounty_V12_t childbounties_add_child_bounty_V12;
    pd_childbounties_propose_curator_V12_t childbounties_propose_curator_V12;
    pd_childbounties_accept_curator_V12_t childbounties_accept_curator_V12;
    pd_childbounties_unassign_curator_V12_t childbounties_unassign_curator_V12;
    pd_childbounties_award_child_bounty_V12_t childbounties_award_child_bounty_V12;
    pd_childbounties_claim_child_bounty_V12_t childbounties_claim_child_bounty_V12;
    pd_childbounties_close_child_bounty_V12_t childbounties_close_child_bounty_V12;
    pd_tips_report_awesome_V12_t tips_report_awesome_V12;
    pd_tips_retract_tip_V12_t tips_retract_tip_V12;
    pd_tips_tip_new_V12_t tips_tip_new_V12;
    pd_tips_tip_V12_t tips_tip_V12;
    pd_tips_close_tip_V12_t tips_close_tip_V12;
    pd_tips_slash_tip_V12_t tips_slash_tip_V12;
    pd_electionprovidermultiphase_governance_fallback_V12_t electionprovidermultiphase_governance_fallback_V12;
    pd_bagslist_rebag_V12_t bagslist_rebag_V12;
    pd_bagslist_put_in_front_of_V12_t bagslist_put_in_front_of_V12;
    pd_configuration_set_validation_upgrade_cooldown_V12_t configuration_set_validation_upgrade_cooldown_V12;
    pd_configuration_set_validation_upgrade_delay_V12_t configuration_set_validation_upgrade_delay_V12;
    pd_configuration_set_code_retention_period_V12_t configuration_set_code_retention_period_V12;
    pd_configuration_set_max_code_size_V12_t configuration_set_max_code_size_V12;
    pd_configuration_set_max_pov_size_V12_t configuration_set_max_pov_size_V12;
    pd_configuration_set_max_head_data_size_V12_t configuration_set_max_head_data_size_V12;
    pd_configuration_set_parathread_cores_V12_t configuration_set_parathread_cores_V12;
    pd_configuration_set_parathread_retries_V12_t configuration_set_parathread_retries_V12;
    pd_configuration_set_group_rotation_frequency_V12_t configuration_set_group_rotation_frequency_V12;
    pd_configuration_set_chain_availability_period_V12_t configuration_set_chain_availability_period_V12;
    pd_configuration_set_thread_availability_period_V12_t configuration_set_thread_availability_period_V12;
    pd_configuration_set_scheduling_lookahead_V12_t configuration_set_scheduling_lookahead_V12;
    pd_configuration_set_max_validators_per_core_V12_t configuration_set_max_validators_per_core_V12;
    pd_configuration_set_max_validators_V12_t configuration_set_max_validators_V12;
    pd_configuration_set_dispute_post_conclusion_acceptance_period_V12_t configuration_set_dispute_post_conclusion_acceptance_period_V12;
    pd_configuration_set_dispute_max_spam_slots_V12_t configuration_set_dispute_max_spam_slots_V12;
    pd_configuration_set_dispute_conclusion_by_time_out_period_V12_t configuration_set_dispute_conclusion_by_time_out_period_V12;
    pd_configuration_set_no_show_slots_V12_t configuration_set_no_show_slots_V12;
    pd_configuration_set_n_delay_tranches_V12_t configuration_set_n_delay_tranches_V12;
    pd_configuration_set_zeroth_delay_tranche_width_V12_t configuration_set_zeroth_delay_tranche_width_V12;
    pd_configuration_set_needed_approvals_V12_t configuration_set_needed_approvals_V12;
    pd_configuration_set_relay_vrf_modulo_samples_V12_t configuration_set_relay_vrf_modulo_samples_V12;
    pd_configuration_set_max_upward_queue_count_V12_t configuration_set_max_upward_queue_count_V12;
    pd_configuration_set_max_upward_queue_size_V12_t configuration_set_max_upward_queue_size_V12;
    pd_configuration_set_max_downward_message_size_V12_t configuration_set_max_downward_message_size_V12;
    pd_configuration_set_ump_service_total_weight_V12_t configuration_set_ump_service_total_weight_V12;
    pd_configuration_set_max_upward_message_size_V12_t configuration_set_max_upward_message_size_V12;
    pd_configuration_set_max_upward_message_num_per_candidate_V12_t configuration_set_max_upward_message_num_per_candidate_V12;
    pd_configuration_set_hrmp_open_request_ttl_V12_t configuration_set_hrmp_open_request_ttl_V12;
    pd_configuration_set_hrmp_sender_deposit_V12_t configuration_set_hrmp_sender_deposit_V12;
    pd_configuration_set_hrmp_recipient_deposit_V12_t configuration_set_hrmp_recipient_deposit_V12;
    pd_configuration_set_hrmp_channel_max_capacity_V12_t configuration_set_hrmp_channel_max_capacity_V12;
    pd_configuration_set_hrmp_channel_max_total_size_V12_t configuration_set_hrmp_channel_max_total_size_V12;
    pd_configuration_set_hrmp_max_parachain_inbound_channels_V12_t configuration_set_hrmp_max_parachain_inbound_channels_V12;
    pd_configuration_set_hrmp_max_parathread_inbound_channels_V12_t configuration_set_hrmp_max_parathread_inbound_channels_V12;
    pd_configuration_set_hrmp_channel_max_message_size_V12_t configuration_set_hrmp_channel_max_message_size_V12;
    pd_configuration_set_hrmp_max_parachain_outbound_channels_V12_t configuration_set_hrmp_max_parachain_outbound_channels_V12;
    pd_configuration_set_hrmp_max_parathread_outbound_channels_V12_t configuration_set_hrmp_max_parathread_outbound_channels_V12;
    pd_configuration_set_hrmp_max_message_num_per_candidate_V12_t configuration_set_hrmp_max_message_num_per_candidate_V12;
    pd_configuration_set_ump_max_individual_weight_V12_t configuration_set_ump_max_individual_weight_V12;
    pd_configuration_set_pvf_checking_enabled_V12_t configuration_set_pvf_checking_enabled_V12;
    pd_configuration_set_pvf_voting_ttl_V12_t configuration_set_pvf_voting_ttl_V12;
    pd_configuration_set_minimum_validation_upgrade_delay_V12_t configuration_set_minimum_validation_upgrade_delay_V12;
    pd_configuration_set_bypass_consistency_check_V12_t configuration_set_bypass_consistency_check_V12;
    pd_initializer_force_approve_V12_t initializer_force_approve_V12;
    pd_hrmp_force_process_hrmp_open_V12_t hrmp_force_process_hrmp_open_V12;
    pd_hrmp_force_process_hrmp_close_V12_t hrmp_force_process_hrmp_close_V12;
    pd_parasdisputes_force_unfreeze_V12_t parasdisputes_force_unfreeze_V12;
    pd_registrar_reserve_V12_t registrar_reserve_V12;
    pd_auctions_new_auction_V12_t auctions_new_auction_V12;
    pd_auctions_bid_V12_t auctions_bid_V12;
    pd_auctions_cancel_auction_V12_t auctions_cancel_auction_V12;
#endif
} pd_MethodBasic_V12_t;

#define PD_CALL_BALANCES_TRANSFER_V12 0
typedef struct {
    pd_LookupasStaticLookupSource_V12_t dest;
    pd_CompactBalance_t amount;
} pd_balances_transfer_V12_t;

#define PD_CALL_BALANCES_FORCE_TRANSFER_V12 2
typedef struct {
    pd_LookupasStaticLookupSource_V12_t source;
    pd_LookupasStaticLookupSource_V12_t dest;
    pd_CompactBalance_t amount;
} pd_balances_force_transfer_V12_t;

#define PD_CALL_BALANCES_TRANSFER_KEEP_ALIVE_V12 3
typedef struct {
    pd_LookupasStaticLookupSource_V12_t dest;
    pd_CompactBalance_t amount;
} pd_balances_transfer_keep_alive_V12_t;

#ifdef SUBSTRATE_PARSER_FULL
#define PD_CALL_SYSTEM_FILL_BLOCK_V12 0
typedef struct {
    pd_Perbill_V12_t ratio;
} pd_system_fill_block_V12_t;

#define PD_CALL_SYSTEM_REMARK_V12 1
typedef struct {
    pd_Vecu8_t remark;
} pd_system_remark_V12_t;

#define PD_CALL_SYSTEM_SET_HEAP_PAGES_V12 2
typedef struct {
    pd_u64_t pages;
} pd_system_set_heap_pages_V12_t;

#define PD_CALL_SYSTEM_SET_CODE_V12 3
typedef struct {
    pd_Vecu8_t code;
} pd_system_set_code_V12_t;

#define PD_CALL_SYSTEM_SET_CODE_WITHOUT_CHECKS_V12 4
typedef struct {
    pd_Vecu8_t code;
} pd_system_set_code_without_checks_V12_t;

#define PD_CALL_SYSTEM_REMARK_WITH_EVENT_V12 8
typedef struct {
    pd_Vecu8_t remark;
} pd_system_remark_with_event_V12_t;

#define PD_CALL_BALANCES_SET_BALANCE_V12 1
typedef struct {
    pd_LookupasStaticLookupSource_V12_t who;
    pd_CompactBalance_t new_free;
    pd_CompactBalance_t new_reserved;
} pd_balances_set_balance_V12_t;

#define PD_CALL_PROXY_PROXY_V12 0
typedef struct {
    pd_AccountId_V12_t real;
    pd_OptionProxyType_V12_t force_proxy_type;
    pd_Call_t call;
} pd_proxy_proxy_V12_t;

#define PD_CALL_MULTISIG_AS_MULTI_THRESHOLD_1_V12 0
typedef struct {
    pd_VecAccountId_V12_t other_signatories;
    pd_Call_t call;
} pd_multisig_as_multi_threshold_1_V12_t;

#define PD_CALL_MULTISIG_AS_MULTI_V12 1
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_V12_t other_signatories;
    pd_OptionTimepoint_V12_t maybe_timepoint;
    pd_OpaqueCall_V12_t call;
    pd_bool_t store_call;
    pd_Weight_V12_t max_weight;
} pd_multisig_as_multi_V12_t;

#define PD_CALL_MULTISIG_APPROVE_AS_MULTI_V12 2
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_V12_t other_signatories;
    pd_OptionTimepoint_V12_t maybe_timepoint;
    pd_H256_t call_hash;
    pd_Weight_V12_t max_weight;
} pd_multisig_approve_as_multi_V12_t;

#define PD_CALL_MULTISIG_CANCEL_AS_MULTI_V12 3
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_V12_t other_signatories;
    pd_Timepoint_V12_t timepoint;
    pd_H256_t call_hash;
} pd_multisig_cancel_as_multi_V12_t;

#endif

typedef union {
    pd_balances_transfer_V12_t balances_transfer_V12;
    pd_balances_force_transfer_V12_t balances_force_transfer_V12;
    pd_balances_transfer_keep_alive_V12_t balances_transfer_keep_alive_V12;
#ifdef SUBSTRATE_PARSER_FULL
    pd_system_fill_block_V12_t system_fill_block_V12;
    pd_system_remark_V12_t system_remark_V12;
    pd_system_set_heap_pages_V12_t system_set_heap_pages_V12;
    pd_system_set_code_V12_t system_set_code_V12;
    pd_system_set_code_without_checks_V12_t system_set_code_without_checks_V12;
    pd_system_remark_with_event_V12_t system_remark_with_event_V12;
    pd_balances_set_balance_V12_t balances_set_balance_V12;
    pd_proxy_proxy_V12_t proxy_proxy_V12;
    pd_multisig_as_multi_threshold_1_V12_t multisig_as_multi_threshold_1_V12;
    pd_multisig_as_multi_V12_t multisig_as_multi_V12;
    pd_multisig_approve_as_multi_V12_t multisig_approve_as_multi_V12;
    pd_multisig_cancel_as_multi_V12_t multisig_cancel_as_multi_V12;
#endif
} pd_MethodNested_V12_t;

typedef union {
    pd_MethodBasic_V12_t basic;
    pd_MethodNested_V12_t nested;
} pd_Method_V12_t;

#ifdef __cplusplus
}
#endif

#pragma clang diagnostic pop
