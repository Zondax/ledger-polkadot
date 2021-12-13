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
#include "substrate_types_V9.h"
#include <stddef.h>
#include <stdint.h>

#define PD_CALL_SYSTEM_V9 0
#define PD_CALL_TIMESTAMP_V9 3
#define PD_CALL_INDICES_V9 4
#define PD_CALL_BALANCES_V9 5
#define PD_CALL_STAKING_V9 7
#define PD_CALL_SESSION_V9 9
#define PD_CALL_GRANDPA_V9 11
#define PD_CALL_DEMOCRACY_V9 14
#define PD_CALL_COUNCIL_V9 15
#define PD_CALL_TECHNICALCOMMITTEE_V9 16
#define PD_CALL_PHRAGMENELECTION_V9 17
#define PD_CALL_TECHNICALMEMBERSHIP_V9 18
#define PD_CALL_TREASURY_V9 19
#define PD_CALL_CLAIMS_V9 24
#define PD_CALL_VESTING_V9 25
#define PD_CALL_UTILITY_V9 26
#define PD_CALL_IDENTITY_V9 28
#define PD_CALL_PROXY_V9 29
#define PD_CALL_MULTISIG_V9 30
#define PD_CALL_BOUNTIES_V9 34
#define PD_CALL_TIPS_V9 35
#define PD_CALL_BAGSLIST_V9 37
#define PD_CALL_CONFIGURATION_V9 51
#define PD_CALL_INITIALIZER_V9 57
#define PD_CALL_HRMP_V9 60
#define PD_CALL_REGISTRAR_V9 70
#define PD_CALL_AUCTIONS_V9 72

#define PD_CALL_BALANCES_TRANSFER_ALL_V9 4
typedef struct {
    pd_LookupasStaticLookupSource_V9_t dest;
    pd_bool_t keep_alive;
} pd_balances_transfer_all_V9_t;

#define PD_CALL_STAKING_BOND_V9 0
typedef struct {
    pd_LookupasStaticLookupSource_V9_t controller;
    pd_CompactBalance_t amount;
    pd_RewardDestination_V9_t payee;
} pd_staking_bond_V9_t;

#define PD_CALL_STAKING_BOND_EXTRA_V9 1
typedef struct {
    pd_CompactBalance_t amount;
} pd_staking_bond_extra_V9_t;

#define PD_CALL_STAKING_UNBOND_V9 2
typedef struct {
    pd_CompactBalance_t amount;
} pd_staking_unbond_V9_t;

#define PD_CALL_STAKING_WITHDRAW_UNBONDED_V9 3
typedef struct {
    pd_u32_t num_slashing_spans;
} pd_staking_withdraw_unbonded_V9_t;

#define PD_CALL_STAKING_VALIDATE_V9 4
typedef struct {
    pd_ValidatorPrefs_V9_t prefs;
} pd_staking_validate_V9_t;

#define PD_CALL_STAKING_NOMINATE_V9 5
typedef struct {
    pd_VecLookupasStaticLookupSource_V9_t targets;
} pd_staking_nominate_V9_t;

#define PD_CALL_STAKING_CHILL_V9 6
typedef struct {
} pd_staking_chill_V9_t;

#define PD_CALL_STAKING_SET_PAYEE_V9 7
typedef struct {
    pd_RewardDestination_V9_t payee;
} pd_staking_set_payee_V9_t;

#define PD_CALL_STAKING_SET_CONTROLLER_V9 8
typedef struct {
    pd_LookupasStaticLookupSource_V9_t controller;
} pd_staking_set_controller_V9_t;

#define PD_CALL_STAKING_PAYOUT_STAKERS_V9 18
typedef struct {
    pd_AccountId_V9_t validator_stash;
    pd_EraIndex_V9_t era;
} pd_staking_payout_stakers_V9_t;

#define PD_CALL_STAKING_REBOND_V9 19
typedef struct {
    pd_CompactBalance_t amount;
} pd_staking_rebond_V9_t;

#define PD_CALL_SESSION_SET_KEYS_V9 0
typedef struct {
    pd_Keys_V9_t keys;
    pd_Bytes_t proof;
} pd_session_set_keys_V9_t;

#define PD_CALL_SESSION_PURGE_KEYS_V9 1
typedef struct {
} pd_session_purge_keys_V9_t;

#define PD_CALL_UTILITY_BATCH_V9 0
typedef struct {
    pd_VecCall_t calls;
} pd_utility_batch_V9_t;

#define PD_CALL_UTILITY_BATCH_ALL_V9 2
typedef struct {
    pd_VecCall_t calls;
} pd_utility_batch_all_V9_t;

#ifdef SUBSTRATE_PARSER_FULL

#define PD_CALL_TIMESTAMP_SET_V9 0
typedef struct {
    pd_Compactu64_t now;
} pd_timestamp_set_V9_t;

#define PD_CALL_INDICES_CLAIM_V9 0
typedef struct {
    pd_AccountIndex_V9_t index;
} pd_indices_claim_V9_t;

#define PD_CALL_INDICES_FREE_V9 2
typedef struct {
    pd_AccountIndex_V9_t index;
} pd_indices_free_V9_t;

#define PD_CALL_INDICES_FORCE_TRANSFER_V9 3
typedef struct {
    pd_AccountId_V9_t new_;
    pd_AccountIndex_V9_t index;
    pd_bool_t freeze;
} pd_indices_force_transfer_V9_t;

#define PD_CALL_INDICES_FREEZE_V9 4
typedef struct {
    pd_AccountIndex_V9_t index;
} pd_indices_freeze_V9_t;

#define PD_CALL_BALANCES_FORCE_UNRESERVE_V9 5
typedef struct {
    pd_LookupasStaticLookupSource_V9_t who;
    pd_Balance_t amount;
} pd_balances_force_unreserve_V9_t;

#define PD_CALL_STAKING_SET_VALIDATOR_COUNT_V9 9
typedef struct {
    pd_Compactu32_t new_;
} pd_staking_set_validator_count_V9_t;

#define PD_CALL_STAKING_INCREASE_VALIDATOR_COUNT_V9 10
typedef struct {
    pd_Compactu32_t additional;
} pd_staking_increase_validator_count_V9_t;

#define PD_CALL_STAKING_FORCE_NO_ERAS_V9 12
typedef struct {
} pd_staking_force_no_eras_V9_t;

#define PD_CALL_STAKING_FORCE_NEW_ERA_V9 13
typedef struct {
} pd_staking_force_new_era_V9_t;

#define PD_CALL_STAKING_FORCE_UNSTAKE_V9 15
typedef struct {
    pd_AccountId_V9_t stash;
    pd_u32_t num_slashing_spans;
} pd_staking_force_unstake_V9_t;

#define PD_CALL_STAKING_FORCE_NEW_ERA_ALWAYS_V9 16
typedef struct {
} pd_staking_force_new_era_always_V9_t;

#define PD_CALL_STAKING_SET_HISTORY_DEPTH_V9 20
typedef struct {
    pd_Compactu32_t new_history_depth;
    pd_Compactu32_t era_items_deleted;
} pd_staking_set_history_depth_V9_t;

#define PD_CALL_STAKING_REAP_STASH_V9 21
typedef struct {
    pd_AccountId_V9_t stash;
    pd_u32_t num_slashing_spans;
} pd_staking_reap_stash_V9_t;

#define PD_CALL_STAKING_KICK_V9 22
typedef struct {
    pd_VecLookupasStaticLookupSource_V9_t who;
} pd_staking_kick_V9_t;

#define PD_CALL_STAKING_CHILL_OTHER_V9 24
typedef struct {
    pd_AccountId_V9_t controller;
} pd_staking_chill_other_V9_t;

#define PD_CALL_GRANDPA_NOTE_STALLED_V9 2
typedef struct {
    pd_BlockNumber_t delay;
    pd_BlockNumber_t best_finalized_block_number;
} pd_grandpa_note_stalled_V9_t;

#define PD_CALL_DEMOCRACY_SECOND_V9 1
typedef struct {
    pd_Compactu32_t proposal;
    pd_Compactu32_t seconds_upper_bound;
} pd_democracy_second_V9_t;

#define PD_CALL_DEMOCRACY_EMERGENCY_CANCEL_V9 3
typedef struct {
    pd_ReferendumIndex_V9_t ref_index;
} pd_democracy_emergency_cancel_V9_t;

#define PD_CALL_DEMOCRACY_EXTERNAL_PROPOSE_V9 4
typedef struct {
    pd_Hash_t proposal_hash;
} pd_democracy_external_propose_V9_t;

#define PD_CALL_DEMOCRACY_EXTERNAL_PROPOSE_MAJORITY_V9 5
typedef struct {
    pd_Hash_t proposal_hash;
} pd_democracy_external_propose_majority_V9_t;

#define PD_CALL_DEMOCRACY_EXTERNAL_PROPOSE_DEFAULT_V9 6
typedef struct {
    pd_Hash_t proposal_hash;
} pd_democracy_external_propose_default_V9_t;

#define PD_CALL_DEMOCRACY_FAST_TRACK_V9 7
typedef struct {
    pd_Hash_t proposal_hash;
    pd_BlockNumber_t voting_period;
    pd_BlockNumber_t delay;
} pd_democracy_fast_track_V9_t;

#define PD_CALL_DEMOCRACY_VETO_EXTERNAL_V9 8
typedef struct {
    pd_Hash_t proposal_hash;
} pd_democracy_veto_external_V9_t;

#define PD_CALL_DEMOCRACY_CANCEL_REFERENDUM_V9 9
typedef struct {
    pd_Compactu32_t ref_index;
} pd_democracy_cancel_referendum_V9_t;

#define PD_CALL_DEMOCRACY_CANCEL_QUEUED_V9 10
typedef struct {
    pd_ReferendumIndex_V9_t which;
} pd_democracy_cancel_queued_V9_t;

#define PD_CALL_DEMOCRACY_DELEGATE_V9 11
typedef struct {
    pd_AccountId_V9_t to;
    pd_Conviction_V9_t conviction;
    pd_Balance_t balance;
} pd_democracy_delegate_V9_t;

#define PD_CALL_DEMOCRACY_UNDELEGATE_V9 12
typedef struct {
} pd_democracy_undelegate_V9_t;

#define PD_CALL_DEMOCRACY_CLEAR_PUBLIC_PROPOSALS_V9 13
typedef struct {
} pd_democracy_clear_public_proposals_V9_t;

#define PD_CALL_DEMOCRACY_NOTE_PREIMAGE_V9 14
typedef struct {
    pd_Bytes_t encoded_proposal;
} pd_democracy_note_preimage_V9_t;

#define PD_CALL_DEMOCRACY_NOTE_PREIMAGE_OPERATIONAL_V9 15
typedef struct {
    pd_Bytes_t encoded_proposal;
} pd_democracy_note_preimage_operational_V9_t;

#define PD_CALL_DEMOCRACY_NOTE_IMMINENT_PREIMAGE_V9 16
typedef struct {
    pd_Bytes_t encoded_proposal;
} pd_democracy_note_imminent_preimage_V9_t;

#define PD_CALL_DEMOCRACY_NOTE_IMMINENT_PREIMAGE_OPERATIONAL_V9 17
typedef struct {
    pd_Bytes_t encoded_proposal;
} pd_democracy_note_imminent_preimage_operational_V9_t;

#define PD_CALL_DEMOCRACY_REAP_PREIMAGE_V9 18
typedef struct {
    pd_Hash_t proposal_hash;
    pd_Compactu32_t proposal_len_upper_bound;
} pd_democracy_reap_preimage_V9_t;

#define PD_CALL_DEMOCRACY_UNLOCK_V9 19
typedef struct {
    pd_AccountId_V9_t target;
} pd_democracy_unlock_V9_t;

#define PD_CALL_DEMOCRACY_REMOVE_VOTE_V9 20
typedef struct {
    pd_ReferendumIndex_V9_t index;
} pd_democracy_remove_vote_V9_t;

#define PD_CALL_DEMOCRACY_REMOVE_OTHER_VOTE_V9 21
typedef struct {
    pd_AccountId_V9_t target;
    pd_ReferendumIndex_V9_t index;
} pd_democracy_remove_other_vote_V9_t;

#define PD_CALL_DEMOCRACY_ENACT_PROPOSAL_V9 22
typedef struct {
    pd_Hash_t proposal_hash;
    pd_ReferendumIndex_V9_t index;
} pd_democracy_enact_proposal_V9_t;

#define PD_CALL_DEMOCRACY_CANCEL_PROPOSAL_V9 24
typedef struct {
    pd_Compactu32_t prop_index;
} pd_democracy_cancel_proposal_V9_t;

#define PD_CALL_COUNCIL_VOTE_V9 3
typedef struct {
    pd_Hash_t proposal;
    pd_Compactu32_t index;
    pd_bool_t approve;
} pd_council_vote_V9_t;

#define PD_CALL_COUNCIL_CLOSE_V9 4
typedef struct {
    pd_Hash_t proposal_hash;
    pd_Compactu32_t index;
    pd_Compactu64_t proposal_weight_bound;
    pd_Compactu32_t length_bound;
} pd_council_close_V9_t;

#define PD_CALL_COUNCIL_DISAPPROVE_PROPOSAL_V9 5
typedef struct {
    pd_Hash_t proposal_hash;
} pd_council_disapprove_proposal_V9_t;

#define PD_CALL_TECHNICALCOMMITTEE_VOTE_V9 3
typedef struct {
    pd_Hash_t proposal;
    pd_Compactu32_t index;
    pd_bool_t approve;
} pd_technicalcommittee_vote_V9_t;

#define PD_CALL_TECHNICALCOMMITTEE_CLOSE_V9 4
typedef struct {
    pd_Hash_t proposal_hash;
    pd_Compactu32_t index;
    pd_Compactu64_t proposal_weight_bound;
    pd_Compactu32_t length_bound;
} pd_technicalcommittee_close_V9_t;

#define PD_CALL_TECHNICALCOMMITTEE_DISAPPROVE_PROPOSAL_V9 5
typedef struct {
    pd_Hash_t proposal_hash;
} pd_technicalcommittee_disapprove_proposal_V9_t;

#define PD_CALL_PHRAGMENELECTION_REMOVE_VOTER_V9 1
typedef struct {
} pd_phragmenelection_remove_voter_V9_t;

#define PD_CALL_PHRAGMENELECTION_SUBMIT_CANDIDACY_V9 2
typedef struct {
    pd_Compactu32_t candidate_count;
} pd_phragmenelection_submit_candidacy_V9_t;

#define PD_CALL_PHRAGMENELECTION_REMOVE_MEMBER_V9 4
typedef struct {
    pd_LookupasStaticLookupSource_V9_t who;
    pd_bool_t has_replacement;
} pd_phragmenelection_remove_member_V9_t;

#define PD_CALL_PHRAGMENELECTION_CLEAN_DEFUNCT_VOTERS_V9 5
typedef struct {
    pd_u32_t num_voters;
    pd_u32_t num_defunct;
} pd_phragmenelection_clean_defunct_voters_V9_t;

#define PD_CALL_TECHNICALMEMBERSHIP_ADD_MEMBER_V9 0
typedef struct {
    pd_AccountId_V9_t who;
} pd_technicalmembership_add_member_V9_t;

#define PD_CALL_TECHNICALMEMBERSHIP_REMOVE_MEMBER_V9 1
typedef struct {
    pd_AccountId_V9_t who;
} pd_technicalmembership_remove_member_V9_t;

#define PD_CALL_TECHNICALMEMBERSHIP_SWAP_MEMBER_V9 2
typedef struct {
    pd_AccountId_V9_t remove;
    pd_AccountId_V9_t add;
} pd_technicalmembership_swap_member_V9_t;

#define PD_CALL_TECHNICALMEMBERSHIP_RESET_MEMBERS_V9 3
typedef struct {
    pd_VecAccountId_V9_t members;
} pd_technicalmembership_reset_members_V9_t;

#define PD_CALL_TECHNICALMEMBERSHIP_CHANGE_KEY_V9 4
typedef struct {
    pd_AccountId_V9_t new_;
} pd_technicalmembership_change_key_V9_t;

#define PD_CALL_TECHNICALMEMBERSHIP_SET_PRIME_V9 5
typedef struct {
    pd_AccountId_V9_t who;
} pd_technicalmembership_set_prime_V9_t;

#define PD_CALL_TECHNICALMEMBERSHIP_CLEAR_PRIME_V9 6
typedef struct {
} pd_technicalmembership_clear_prime_V9_t;

#define PD_CALL_TREASURY_PROPOSE_SPEND_V9 0
typedef struct {
    pd_CompactBalance_t amount;
    pd_LookupasStaticLookupSource_V9_t beneficiary;
} pd_treasury_propose_spend_V9_t;

#define PD_CALL_TREASURY_REJECT_PROPOSAL_V9 1
typedef struct {
    pd_Compactu32_t proposal_id;
} pd_treasury_reject_proposal_V9_t;

#define PD_CALL_TREASURY_APPROVE_PROPOSAL_V9 2
typedef struct {
    pd_Compactu32_t proposal_id;
} pd_treasury_approve_proposal_V9_t;

#define PD_CALL_CLAIMS_CLAIM_V9 0
typedef struct {
    pd_AccountId_V9_t dest;
    pd_EcdsaSignature_V9_t ethereum_signature;
} pd_claims_claim_V9_t;

#define PD_CALL_CLAIMS_CLAIM_ATTEST_V9 2
typedef struct {
    pd_AccountId_V9_t dest;
    pd_EcdsaSignature_V9_t ethereum_signature;
    pd_Bytes_t statement;
} pd_claims_claim_attest_V9_t;

#define PD_CALL_CLAIMS_ATTEST_V9 3
typedef struct {
    pd_Bytes_t statement;
} pd_claims_attest_V9_t;

#define PD_CALL_VESTING_VEST_V9 0
typedef struct {
} pd_vesting_vest_V9_t;

#define PD_CALL_VESTING_VEST_OTHER_V9 1
typedef struct {
    pd_LookupasStaticLookupSource_V9_t target;
} pd_vesting_vest_other_V9_t;

#define PD_CALL_VESTING_MERGE_SCHEDULES_V9 4
typedef struct {
    pd_u32_t schedule1_index;
    pd_u32_t schedule2_index;
} pd_vesting_merge_schedules_V9_t;

#define PD_CALL_IDENTITY_ADD_REGISTRAR_V9 0
typedef struct {
    pd_AccountId_V9_t account;
} pd_identity_add_registrar_V9_t;

#define PD_CALL_IDENTITY_CLEAR_IDENTITY_V9 3
typedef struct {
} pd_identity_clear_identity_V9_t;

#define PD_CALL_IDENTITY_REQUEST_JUDGEMENT_V9 4
typedef struct {
    pd_Compactu32_t reg_index;
    pd_Compactu128_t max_fee;
} pd_identity_request_judgement_V9_t;

#define PD_CALL_IDENTITY_CANCEL_REQUEST_V9 5
typedef struct {
    pd_RegistrarIndex_V9_t reg_index;
} pd_identity_cancel_request_V9_t;

#define PD_CALL_IDENTITY_SET_FEE_V9 6
typedef struct {
    pd_Compactu32_t index;
    pd_Compactu128_t fee;
} pd_identity_set_fee_V9_t;

#define PD_CALL_IDENTITY_SET_ACCOUNT_ID_V9 7
typedef struct {
    pd_Compactu32_t index;
    pd_AccountId_V9_t new_;
} pd_identity_set_account_id_V9_t;

#define PD_CALL_IDENTITY_KILL_IDENTITY_V9 10
typedef struct {
    pd_LookupasStaticLookupSource_V9_t target;
} pd_identity_kill_identity_V9_t;

#define PD_CALL_IDENTITY_REMOVE_SUB_V9 13
typedef struct {
    pd_LookupasStaticLookupSource_V9_t sub;
} pd_identity_remove_sub_V9_t;

#define PD_CALL_IDENTITY_QUIT_SUB_V9 14
typedef struct {
} pd_identity_quit_sub_V9_t;

#define PD_CALL_PROXY_ADD_PROXY_V9 1
typedef struct {
    pd_AccountId_V9_t delegate;
    pd_ProxyType_V9_t proxy_type;
    pd_BlockNumber_t delay;
} pd_proxy_add_proxy_V9_t;

#define PD_CALL_PROXY_REMOVE_PROXY_V9 2
typedef struct {
    pd_AccountId_V9_t delegate;
    pd_ProxyType_V9_t proxy_type;
    pd_BlockNumber_t delay;
} pd_proxy_remove_proxy_V9_t;

#define PD_CALL_PROXY_REMOVE_PROXIES_V9 3
typedef struct {
} pd_proxy_remove_proxies_V9_t;

#define PD_CALL_PROXY_ANONYMOUS_V9 4
typedef struct {
    pd_ProxyType_V9_t proxy_type;
    pd_BlockNumber_t delay;
    pd_u16_t index;
} pd_proxy_anonymous_V9_t;

#define PD_CALL_PROXY_KILL_ANONYMOUS_V9 5
typedef struct {
    pd_AccountId_V9_t spawner;
    pd_ProxyType_V9_t proxy_type;
    pd_u16_t index;
    pd_Compactu32_t height;
    pd_Compactu32_t ext_index;
} pd_proxy_kill_anonymous_V9_t;

#define PD_CALL_PROXY_PROXY_ANNOUNCED_V9 9
typedef struct {
    pd_AccountId_V9_t delegate;
    pd_AccountId_V9_t real;
    pd_OptionProxyType_V9_t force_proxy_type;
    pd_Call_t call;
} pd_proxy_proxy_announced_V9_t;

#define PD_CALL_BOUNTIES_PROPOSE_BOUNTY_V9 0
typedef struct {
    pd_CompactBalance_t amount;
    pd_Bytes_t description;
} pd_bounties_propose_bounty_V9_t;

#define PD_CALL_BOUNTIES_APPROVE_BOUNTY_V9 1
typedef struct {
    pd_Compactu32_t bounty_id;
} pd_bounties_approve_bounty_V9_t;

#define PD_CALL_BOUNTIES_PROPOSE_CURATOR_V9 2
typedef struct {
    pd_Compactu32_t bounty_id;
    pd_LookupasStaticLookupSource_V9_t curator;
    pd_CompactBalance_t fee;
} pd_bounties_propose_curator_V9_t;

#define PD_CALL_BOUNTIES_UNASSIGN_CURATOR_V9 3
typedef struct {
    pd_Compactu32_t bounty_id;
} pd_bounties_unassign_curator_V9_t;

#define PD_CALL_BOUNTIES_ACCEPT_CURATOR_V9 4
typedef struct {
    pd_Compactu32_t bounty_id;
} pd_bounties_accept_curator_V9_t;

#define PD_CALL_BOUNTIES_AWARD_BOUNTY_V9 5
typedef struct {
    pd_Compactu32_t bounty_id;
    pd_LookupasStaticLookupSource_V9_t beneficiary;
} pd_bounties_award_bounty_V9_t;

#define PD_CALL_BOUNTIES_CLAIM_BOUNTY_V9 6
typedef struct {
    pd_Compactu32_t bounty_id;
} pd_bounties_claim_bounty_V9_t;

#define PD_CALL_BOUNTIES_CLOSE_BOUNTY_V9 7
typedef struct {
    pd_Compactu32_t bounty_id;
} pd_bounties_close_bounty_V9_t;

#define PD_CALL_BOUNTIES_EXTEND_BOUNTY_EXPIRY_V9 8
typedef struct {
    pd_Compactu32_t bounty_id;
    pd_Bytes_t remark;
} pd_bounties_extend_bounty_expiry_V9_t;

#define PD_CALL_TIPS_REPORT_AWESOME_V9 0
typedef struct {
    pd_Bytes_t reason;
    pd_AccountId_V9_t who;
} pd_tips_report_awesome_V9_t;

#define PD_CALL_TIPS_RETRACT_TIP_V9 1
typedef struct {
    pd_Hash_t hash;
} pd_tips_retract_tip_V9_t;

#define PD_CALL_TIPS_TIP_NEW_V9 2
typedef struct {
    pd_Bytes_t reason;
    pd_AccountId_V9_t who;
    pd_Compactu128_t tip_value;
} pd_tips_tip_new_V9_t;

#define PD_CALL_TIPS_TIP_V9 3
typedef struct {
    pd_Hash_t hash;
    pd_Compactu128_t tip_value;
} pd_tips_tip_V9_t;

#define PD_CALL_TIPS_CLOSE_TIP_V9 4
typedef struct {
    pd_Hash_t hash;
} pd_tips_close_tip_V9_t;

#define PD_CALL_TIPS_SLASH_TIP_V9 5
typedef struct {
    pd_Hash_t hash;
} pd_tips_slash_tip_V9_t;

#define PD_CALL_BAGSLIST_REBAG_V9 0
typedef struct {
    pd_AccountId_V9_t dislocated;
} pd_bagslist_rebag_V9_t;

#define PD_CALL_CONFIGURATION_SET_VALIDATION_UPGRADE_FREQUENCY_V9 0
typedef struct {
    pd_BlockNumber_t new_;
} pd_configuration_set_validation_upgrade_frequency_V9_t;

#define PD_CALL_CONFIGURATION_SET_VALIDATION_UPGRADE_DELAY_V9 1
typedef struct {
    pd_BlockNumber_t new_;
} pd_configuration_set_validation_upgrade_delay_V9_t;

#define PD_CALL_CONFIGURATION_SET_CODE_RETENTION_PERIOD_V9 2
typedef struct {
    pd_BlockNumber_t new_;
} pd_configuration_set_code_retention_period_V9_t;

#define PD_CALL_CONFIGURATION_SET_MAX_CODE_SIZE_V9 3
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_max_code_size_V9_t;

#define PD_CALL_CONFIGURATION_SET_MAX_POV_SIZE_V9 4
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_max_pov_size_V9_t;

#define PD_CALL_CONFIGURATION_SET_MAX_HEAD_DATA_SIZE_V9 5
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_max_head_data_size_V9_t;

#define PD_CALL_CONFIGURATION_SET_PARATHREAD_CORES_V9 6
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_parathread_cores_V9_t;

#define PD_CALL_CONFIGURATION_SET_PARATHREAD_RETRIES_V9 7
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_parathread_retries_V9_t;

#define PD_CALL_CONFIGURATION_SET_GROUP_ROTATION_FREQUENCY_V9 8
typedef struct {
    pd_BlockNumber_t new_;
} pd_configuration_set_group_rotation_frequency_V9_t;

#define PD_CALL_CONFIGURATION_SET_CHAIN_AVAILABILITY_PERIOD_V9 9
typedef struct {
    pd_BlockNumber_t new_;
} pd_configuration_set_chain_availability_period_V9_t;

#define PD_CALL_CONFIGURATION_SET_THREAD_AVAILABILITY_PERIOD_V9 10
typedef struct {
    pd_BlockNumber_t new_;
} pd_configuration_set_thread_availability_period_V9_t;

#define PD_CALL_CONFIGURATION_SET_SCHEDULING_LOOKAHEAD_V9 11
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_scheduling_lookahead_V9_t;

#define PD_CALL_CONFIGURATION_SET_MAX_VALIDATORS_PER_CORE_V9 12
typedef struct {
    pd_Optionu32_t new_;
} pd_configuration_set_max_validators_per_core_V9_t;

#define PD_CALL_CONFIGURATION_SET_MAX_VALIDATORS_V9 13
typedef struct {
    pd_Optionu32_t new_;
} pd_configuration_set_max_validators_V9_t;

#define PD_CALL_CONFIGURATION_SET_DISPUTE_POST_CONCLUSION_ACCEPTANCE_PERIOD_V9 15
typedef struct {
    pd_BlockNumber_t new_;
} pd_configuration_set_dispute_post_conclusion_acceptance_period_V9_t;

#define PD_CALL_CONFIGURATION_SET_DISPUTE_MAX_SPAM_SLOTS_V9 16
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_dispute_max_spam_slots_V9_t;

#define PD_CALL_CONFIGURATION_SET_DISPUTE_CONCLUSION_BY_TIME_OUT_PERIOD_V9 17
typedef struct {
    pd_BlockNumber_t new_;
} pd_configuration_set_dispute_conclusion_by_time_out_period_V9_t;

#define PD_CALL_CONFIGURATION_SET_NO_SHOW_SLOTS_V9 18
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_no_show_slots_V9_t;

#define PD_CALL_CONFIGURATION_SET_N_DELAY_TRANCHES_V9 19
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_n_delay_tranches_V9_t;

#define PD_CALL_CONFIGURATION_SET_ZEROTH_DELAY_TRANCHE_WIDTH_V9 20
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_zeroth_delay_tranche_width_V9_t;

#define PD_CALL_CONFIGURATION_SET_NEEDED_APPROVALS_V9 21
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_needed_approvals_V9_t;

#define PD_CALL_CONFIGURATION_SET_RELAY_VRF_MODULO_SAMPLES_V9 22
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_relay_vrf_modulo_samples_V9_t;

#define PD_CALL_CONFIGURATION_SET_MAX_UPWARD_QUEUE_COUNT_V9 23
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_max_upward_queue_count_V9_t;

#define PD_CALL_CONFIGURATION_SET_MAX_UPWARD_QUEUE_SIZE_V9 24
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_max_upward_queue_size_V9_t;

#define PD_CALL_CONFIGURATION_SET_MAX_DOWNWARD_MESSAGE_SIZE_V9 25
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_max_downward_message_size_V9_t;

#define PD_CALL_CONFIGURATION_SET_UMP_SERVICE_TOTAL_WEIGHT_V9 26
typedef struct {
    pd_Weight_V9_t new_;
} pd_configuration_set_ump_service_total_weight_V9_t;

#define PD_CALL_CONFIGURATION_SET_MAX_UPWARD_MESSAGE_SIZE_V9 27
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_max_upward_message_size_V9_t;

#define PD_CALL_CONFIGURATION_SET_MAX_UPWARD_MESSAGE_NUM_PER_CANDIDATE_V9 28
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_max_upward_message_num_per_candidate_V9_t;

#define PD_CALL_CONFIGURATION_SET_HRMP_OPEN_REQUEST_TTL_V9 29
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_hrmp_open_request_ttl_V9_t;

#define PD_CALL_CONFIGURATION_SET_HRMP_SENDER_DEPOSIT_V9 30
typedef struct {
    pd_Balance_t new_;
} pd_configuration_set_hrmp_sender_deposit_V9_t;

#define PD_CALL_CONFIGURATION_SET_HRMP_RECIPIENT_DEPOSIT_V9 31
typedef struct {
    pd_Balance_t new_;
} pd_configuration_set_hrmp_recipient_deposit_V9_t;

#define PD_CALL_CONFIGURATION_SET_HRMP_CHANNEL_MAX_CAPACITY_V9 32
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_hrmp_channel_max_capacity_V9_t;

#define PD_CALL_CONFIGURATION_SET_HRMP_CHANNEL_MAX_TOTAL_SIZE_V9 33
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_hrmp_channel_max_total_size_V9_t;

#define PD_CALL_CONFIGURATION_SET_HRMP_MAX_PARACHAIN_INBOUND_CHANNELS_V9 34
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_hrmp_max_parachain_inbound_channels_V9_t;

#define PD_CALL_CONFIGURATION_SET_HRMP_MAX_PARATHREAD_INBOUND_CHANNELS_V9 35
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_hrmp_max_parathread_inbound_channels_V9_t;

#define PD_CALL_CONFIGURATION_SET_HRMP_CHANNEL_MAX_MESSAGE_SIZE_V9 36
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_hrmp_channel_max_message_size_V9_t;

#define PD_CALL_CONFIGURATION_SET_HRMP_MAX_PARACHAIN_OUTBOUND_CHANNELS_V9 37
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_hrmp_max_parachain_outbound_channels_V9_t;

#define PD_CALL_CONFIGURATION_SET_HRMP_MAX_PARATHREAD_OUTBOUND_CHANNELS_V9 38
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_hrmp_max_parathread_outbound_channels_V9_t;

#define PD_CALL_CONFIGURATION_SET_HRMP_MAX_MESSAGE_NUM_PER_CANDIDATE_V9 39
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_hrmp_max_message_num_per_candidate_V9_t;

#define PD_CALL_CONFIGURATION_SET_UMP_MAX_INDIVIDUAL_WEIGHT_V9 40
typedef struct {
    pd_Weight_V9_t new_;
} pd_configuration_set_ump_max_individual_weight_V9_t;

#define PD_CALL_INITIALIZER_FORCE_APPROVE_V9 0
typedef struct {
    pd_BlockNumber_t up_to;
} pd_initializer_force_approve_V9_t;

#define PD_CALL_HRMP_FORCE_PROCESS_HRMP_OPEN_V9 4
typedef struct {
} pd_hrmp_force_process_hrmp_open_V9_t;

#define PD_CALL_HRMP_FORCE_PROCESS_HRMP_CLOSE_V9 5
typedef struct {
} pd_hrmp_force_process_hrmp_close_V9_t;

#define PD_CALL_REGISTRAR_RESERVE_V9 5
typedef struct {
} pd_registrar_reserve_V9_t;

#define PD_CALL_AUCTIONS_NEW_AUCTION_V9 0
typedef struct {
    pd_Compactu32_t duration;
    pd_Compactu32_t lease_period_index;
} pd_auctions_new_auction_V9_t;

#define PD_CALL_AUCTIONS_BID_V9 1
typedef struct {
    pd_Compactu32_t para;
    pd_Compactu32_t auction_index;
    pd_Compactu32_t first_slot;
    pd_Compactu32_t last_slot;
    pd_CompactBalance_t amount;
} pd_auctions_bid_V9_t;

#define PD_CALL_AUCTIONS_CANCEL_AUCTION_V9 2
typedef struct {
} pd_auctions_cancel_auction_V9_t;

#endif

typedef union {
    pd_balances_transfer_all_V9_t balances_transfer_all_V9;
    pd_staking_bond_V9_t staking_bond_V9;
    pd_staking_bond_extra_V9_t staking_bond_extra_V9;
    pd_staking_unbond_V9_t staking_unbond_V9;
    pd_staking_withdraw_unbonded_V9_t staking_withdraw_unbonded_V9;
    pd_staking_validate_V9_t staking_validate_V9;
    pd_staking_nominate_V9_t staking_nominate_V9;
    pd_staking_chill_V9_t staking_chill_V9;
    pd_staking_set_payee_V9_t staking_set_payee_V9;
    pd_staking_set_controller_V9_t staking_set_controller_V9;
    pd_staking_payout_stakers_V9_t staking_payout_stakers_V9;
    pd_staking_rebond_V9_t staking_rebond_V9;
    pd_session_set_keys_V9_t session_set_keys_V9;
    pd_session_purge_keys_V9_t session_purge_keys_V9;
    pd_utility_batch_V9_t utility_batch_V9;
    pd_utility_batch_all_V9_t utility_batch_all_V9;
#ifdef SUBSTRATE_PARSER_FULL
    pd_timestamp_set_V9_t timestamp_set_V9;
    pd_indices_claim_V9_t indices_claim_V9;
    pd_indices_free_V9_t indices_free_V9;
    pd_indices_force_transfer_V9_t indices_force_transfer_V9;
    pd_indices_freeze_V9_t indices_freeze_V9;
    pd_balances_force_unreserve_V9_t balances_force_unreserve_V9;
    pd_staking_set_validator_count_V9_t staking_set_validator_count_V9;
    pd_staking_increase_validator_count_V9_t staking_increase_validator_count_V9;
    pd_staking_force_no_eras_V9_t staking_force_no_eras_V9;
    pd_staking_force_new_era_V9_t staking_force_new_era_V9;
    pd_staking_force_unstake_V9_t staking_force_unstake_V9;
    pd_staking_force_new_era_always_V9_t staking_force_new_era_always_V9;
    pd_staking_set_history_depth_V9_t staking_set_history_depth_V9;
    pd_staking_reap_stash_V9_t staking_reap_stash_V9;
    pd_staking_kick_V9_t staking_kick_V9;
    pd_staking_chill_other_V9_t staking_chill_other_V9;
    pd_grandpa_note_stalled_V9_t grandpa_note_stalled_V9;
    pd_democracy_second_V9_t democracy_second_V9;
    pd_democracy_emergency_cancel_V9_t democracy_emergency_cancel_V9;
    pd_democracy_external_propose_V9_t democracy_external_propose_V9;
    pd_democracy_external_propose_majority_V9_t democracy_external_propose_majority_V9;
    pd_democracy_external_propose_default_V9_t democracy_external_propose_default_V9;
    pd_democracy_fast_track_V9_t democracy_fast_track_V9;
    pd_democracy_veto_external_V9_t democracy_veto_external_V9;
    pd_democracy_cancel_referendum_V9_t democracy_cancel_referendum_V9;
    pd_democracy_cancel_queued_V9_t democracy_cancel_queued_V9;
    pd_democracy_delegate_V9_t democracy_delegate_V9;
    pd_democracy_undelegate_V9_t democracy_undelegate_V9;
    pd_democracy_clear_public_proposals_V9_t democracy_clear_public_proposals_V9;
    pd_democracy_note_preimage_V9_t democracy_note_preimage_V9;
    pd_democracy_note_preimage_operational_V9_t democracy_note_preimage_operational_V9;
    pd_democracy_note_imminent_preimage_V9_t democracy_note_imminent_preimage_V9;
    pd_democracy_note_imminent_preimage_operational_V9_t democracy_note_imminent_preimage_operational_V9;
    pd_democracy_reap_preimage_V9_t democracy_reap_preimage_V9;
    pd_democracy_unlock_V9_t democracy_unlock_V9;
    pd_democracy_remove_vote_V9_t democracy_remove_vote_V9;
    pd_democracy_remove_other_vote_V9_t democracy_remove_other_vote_V9;
    pd_democracy_enact_proposal_V9_t democracy_enact_proposal_V9;
    pd_democracy_cancel_proposal_V9_t democracy_cancel_proposal_V9;
    pd_council_vote_V9_t council_vote_V9;
    pd_council_close_V9_t council_close_V9;
    pd_council_disapprove_proposal_V9_t council_disapprove_proposal_V9;
    pd_technicalcommittee_vote_V9_t technicalcommittee_vote_V9;
    pd_technicalcommittee_close_V9_t technicalcommittee_close_V9;
    pd_technicalcommittee_disapprove_proposal_V9_t technicalcommittee_disapprove_proposal_V9;
    pd_phragmenelection_remove_voter_V9_t phragmenelection_remove_voter_V9;
    pd_phragmenelection_submit_candidacy_V9_t phragmenelection_submit_candidacy_V9;
    pd_phragmenelection_remove_member_V9_t phragmenelection_remove_member_V9;
    pd_phragmenelection_clean_defunct_voters_V9_t phragmenelection_clean_defunct_voters_V9;
    pd_technicalmembership_add_member_V9_t technicalmembership_add_member_V9;
    pd_technicalmembership_remove_member_V9_t technicalmembership_remove_member_V9;
    pd_technicalmembership_swap_member_V9_t technicalmembership_swap_member_V9;
    pd_technicalmembership_reset_members_V9_t technicalmembership_reset_members_V9;
    pd_technicalmembership_change_key_V9_t technicalmembership_change_key_V9;
    pd_technicalmembership_set_prime_V9_t technicalmembership_set_prime_V9;
    pd_technicalmembership_clear_prime_V9_t technicalmembership_clear_prime_V9;
    pd_treasury_propose_spend_V9_t treasury_propose_spend_V9;
    pd_treasury_reject_proposal_V9_t treasury_reject_proposal_V9;
    pd_treasury_approve_proposal_V9_t treasury_approve_proposal_V9;
    pd_claims_claim_V9_t claims_claim_V9;
    pd_claims_claim_attest_V9_t claims_claim_attest_V9;
    pd_claims_attest_V9_t claims_attest_V9;
    pd_vesting_vest_V9_t vesting_vest_V9;
    pd_vesting_vest_other_V9_t vesting_vest_other_V9;
    pd_vesting_merge_schedules_V9_t vesting_merge_schedules_V9;
    pd_identity_add_registrar_V9_t identity_add_registrar_V9;
    pd_identity_clear_identity_V9_t identity_clear_identity_V9;
    pd_identity_request_judgement_V9_t identity_request_judgement_V9;
    pd_identity_cancel_request_V9_t identity_cancel_request_V9;
    pd_identity_set_fee_V9_t identity_set_fee_V9;
    pd_identity_set_account_id_V9_t identity_set_account_id_V9;
    pd_identity_kill_identity_V9_t identity_kill_identity_V9;
    pd_identity_remove_sub_V9_t identity_remove_sub_V9;
    pd_identity_quit_sub_V9_t identity_quit_sub_V9;
    pd_proxy_add_proxy_V9_t proxy_add_proxy_V9;
    pd_proxy_remove_proxy_V9_t proxy_remove_proxy_V9;
    pd_proxy_remove_proxies_V9_t proxy_remove_proxies_V9;
    pd_proxy_anonymous_V9_t proxy_anonymous_V9;
    pd_proxy_kill_anonymous_V9_t proxy_kill_anonymous_V9;
    pd_proxy_proxy_announced_V9_t proxy_proxy_announced_V9;
    pd_bounties_propose_bounty_V9_t bounties_propose_bounty_V9;
    pd_bounties_approve_bounty_V9_t bounties_approve_bounty_V9;
    pd_bounties_propose_curator_V9_t bounties_propose_curator_V9;
    pd_bounties_unassign_curator_V9_t bounties_unassign_curator_V9;
    pd_bounties_accept_curator_V9_t bounties_accept_curator_V9;
    pd_bounties_award_bounty_V9_t bounties_award_bounty_V9;
    pd_bounties_claim_bounty_V9_t bounties_claim_bounty_V9;
    pd_bounties_close_bounty_V9_t bounties_close_bounty_V9;
    pd_bounties_extend_bounty_expiry_V9_t bounties_extend_bounty_expiry_V9;
    pd_tips_report_awesome_V9_t tips_report_awesome_V9;
    pd_tips_retract_tip_V9_t tips_retract_tip_V9;
    pd_tips_tip_new_V9_t tips_tip_new_V9;
    pd_tips_tip_V9_t tips_tip_V9;
    pd_tips_close_tip_V9_t tips_close_tip_V9;
    pd_tips_slash_tip_V9_t tips_slash_tip_V9;
    pd_bagslist_rebag_V9_t bagslist_rebag_V9;
    pd_configuration_set_validation_upgrade_frequency_V9_t configuration_set_validation_upgrade_frequency_V9;
    pd_configuration_set_validation_upgrade_delay_V9_t configuration_set_validation_upgrade_delay_V9;
    pd_configuration_set_code_retention_period_V9_t configuration_set_code_retention_period_V9;
    pd_configuration_set_max_code_size_V9_t configuration_set_max_code_size_V9;
    pd_configuration_set_max_pov_size_V9_t configuration_set_max_pov_size_V9;
    pd_configuration_set_max_head_data_size_V9_t configuration_set_max_head_data_size_V9;
    pd_configuration_set_parathread_cores_V9_t configuration_set_parathread_cores_V9;
    pd_configuration_set_parathread_retries_V9_t configuration_set_parathread_retries_V9;
    pd_configuration_set_group_rotation_frequency_V9_t configuration_set_group_rotation_frequency_V9;
    pd_configuration_set_chain_availability_period_V9_t configuration_set_chain_availability_period_V9;
    pd_configuration_set_thread_availability_period_V9_t configuration_set_thread_availability_period_V9;
    pd_configuration_set_scheduling_lookahead_V9_t configuration_set_scheduling_lookahead_V9;
    pd_configuration_set_max_validators_per_core_V9_t configuration_set_max_validators_per_core_V9;
    pd_configuration_set_max_validators_V9_t configuration_set_max_validators_V9;
    pd_configuration_set_dispute_post_conclusion_acceptance_period_V9_t configuration_set_dispute_post_conclusion_acceptance_period_V9;
    pd_configuration_set_dispute_max_spam_slots_V9_t configuration_set_dispute_max_spam_slots_V9;
    pd_configuration_set_dispute_conclusion_by_time_out_period_V9_t configuration_set_dispute_conclusion_by_time_out_period_V9;
    pd_configuration_set_no_show_slots_V9_t configuration_set_no_show_slots_V9;
    pd_configuration_set_n_delay_tranches_V9_t configuration_set_n_delay_tranches_V9;
    pd_configuration_set_zeroth_delay_tranche_width_V9_t configuration_set_zeroth_delay_tranche_width_V9;
    pd_configuration_set_needed_approvals_V9_t configuration_set_needed_approvals_V9;
    pd_configuration_set_relay_vrf_modulo_samples_V9_t configuration_set_relay_vrf_modulo_samples_V9;
    pd_configuration_set_max_upward_queue_count_V9_t configuration_set_max_upward_queue_count_V9;
    pd_configuration_set_max_upward_queue_size_V9_t configuration_set_max_upward_queue_size_V9;
    pd_configuration_set_max_downward_message_size_V9_t configuration_set_max_downward_message_size_V9;
    pd_configuration_set_ump_service_total_weight_V9_t configuration_set_ump_service_total_weight_V9;
    pd_configuration_set_max_upward_message_size_V9_t configuration_set_max_upward_message_size_V9;
    pd_configuration_set_max_upward_message_num_per_candidate_V9_t configuration_set_max_upward_message_num_per_candidate_V9;
    pd_configuration_set_hrmp_open_request_ttl_V9_t configuration_set_hrmp_open_request_ttl_V9;
    pd_configuration_set_hrmp_sender_deposit_V9_t configuration_set_hrmp_sender_deposit_V9;
    pd_configuration_set_hrmp_recipient_deposit_V9_t configuration_set_hrmp_recipient_deposit_V9;
    pd_configuration_set_hrmp_channel_max_capacity_V9_t configuration_set_hrmp_channel_max_capacity_V9;
    pd_configuration_set_hrmp_channel_max_total_size_V9_t configuration_set_hrmp_channel_max_total_size_V9;
    pd_configuration_set_hrmp_max_parachain_inbound_channels_V9_t configuration_set_hrmp_max_parachain_inbound_channels_V9;
    pd_configuration_set_hrmp_max_parathread_inbound_channels_V9_t configuration_set_hrmp_max_parathread_inbound_channels_V9;
    pd_configuration_set_hrmp_channel_max_message_size_V9_t configuration_set_hrmp_channel_max_message_size_V9;
    pd_configuration_set_hrmp_max_parachain_outbound_channels_V9_t configuration_set_hrmp_max_parachain_outbound_channels_V9;
    pd_configuration_set_hrmp_max_parathread_outbound_channels_V9_t configuration_set_hrmp_max_parathread_outbound_channels_V9;
    pd_configuration_set_hrmp_max_message_num_per_candidate_V9_t configuration_set_hrmp_max_message_num_per_candidate_V9;
    pd_configuration_set_ump_max_individual_weight_V9_t configuration_set_ump_max_individual_weight_V9;
    pd_initializer_force_approve_V9_t initializer_force_approve_V9;
    pd_hrmp_force_process_hrmp_open_V9_t hrmp_force_process_hrmp_open_V9;
    pd_hrmp_force_process_hrmp_close_V9_t hrmp_force_process_hrmp_close_V9;
    pd_registrar_reserve_V9_t registrar_reserve_V9;
    pd_auctions_new_auction_V9_t auctions_new_auction_V9;
    pd_auctions_bid_V9_t auctions_bid_V9;
    pd_auctions_cancel_auction_V9_t auctions_cancel_auction_V9;
#endif
} pd_MethodBasic_V9_t;

#define PD_CALL_BALANCES_TRANSFER_V9 0
typedef struct {
    pd_LookupasStaticLookupSource_V9_t dest;
    pd_CompactBalance_t amount;
} pd_balances_transfer_V9_t;

#define PD_CALL_BALANCES_FORCE_TRANSFER_V9 2
typedef struct {
    pd_LookupasStaticLookupSource_V9_t source;
    pd_LookupasStaticLookupSource_V9_t dest;
    pd_CompactBalance_t amount;
} pd_balances_force_transfer_V9_t;

#define PD_CALL_BALANCES_TRANSFER_KEEP_ALIVE_V9 3
typedef struct {
    pd_LookupasStaticLookupSource_V9_t dest;
    pd_CompactBalance_t amount;
} pd_balances_transfer_keep_alive_V9_t;

#ifdef SUBSTRATE_PARSER_FULL
#define PD_CALL_SYSTEM_FILL_BLOCK_V9 0
typedef struct {
    pd_Perbill_V9_t ratio;
} pd_system_fill_block_V9_t;

#define PD_CALL_SYSTEM_REMARK_V9 1
typedef struct {
    pd_Vecu8_t remark;
} pd_system_remark_V9_t;

#define PD_CALL_SYSTEM_SET_HEAP_PAGES_V9 2
typedef struct {
    pd_u64_t pages;
} pd_system_set_heap_pages_V9_t;

#define PD_CALL_SYSTEM_SET_CODE_V9 3
typedef struct {
    pd_Vecu8_t code;
} pd_system_set_code_V9_t;

#define PD_CALL_SYSTEM_SET_CODE_WITHOUT_CHECKS_V9 4
typedef struct {
    pd_Vecu8_t code;
} pd_system_set_code_without_checks_V9_t;

#define PD_CALL_SYSTEM_REMARK_WITH_EVENT_V9 8
typedef struct {
    pd_Vecu8_t remark;
} pd_system_remark_with_event_V9_t;

#define PD_CALL_BALANCES_SET_BALANCE_V9 1
typedef struct {
    pd_LookupasStaticLookupSource_V9_t who;
    pd_CompactBalance_t new_free;
    pd_CompactBalance_t new_reserved;
} pd_balances_set_balance_V9_t;

#define PD_CALL_PROXY_PROXY_V9 0
typedef struct {
    pd_AccountId_V9_t real;
    pd_OptionProxyType_V9_t force_proxy_type;
    pd_Call_t call;
} pd_proxy_proxy_V9_t;

#define PD_CALL_MULTISIG_APPROVE_AS_MULTI_V9 2
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_V9_t other_signatories;
    pd_OptionTimepoint_V9_t maybe_timepoint;
    pd_H256_t call_hash;
    pd_Weight_V9_t max_weight;
} pd_multisig_approve_as_multi_V9_t;

#define PD_CALL_MULTISIG_CANCEL_AS_MULTI_V9 3
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_V9_t other_signatories;
    pd_Timepoint_V9_t timepoint;
    pd_H256_t call_hash;
} pd_multisig_cancel_as_multi_V9_t;

#endif

typedef union {
    pd_balances_transfer_V9_t balances_transfer_V9;
    pd_balances_force_transfer_V9_t balances_force_transfer_V9;
    pd_balances_transfer_keep_alive_V9_t balances_transfer_keep_alive_V9;
#ifdef SUBSTRATE_PARSER_FULL
    pd_system_fill_block_V9_t system_fill_block_V9;
    pd_system_remark_V9_t system_remark_V9;
    pd_system_set_heap_pages_V9_t system_set_heap_pages_V9;
    pd_system_set_code_V9_t system_set_code_V9;
    pd_system_set_code_without_checks_V9_t system_set_code_without_checks_V9;
    pd_system_remark_with_event_V9_t system_remark_with_event_V9;
    pd_balances_set_balance_V9_t balances_set_balance_V9;
    pd_proxy_proxy_V9_t proxy_proxy_V9;
    pd_multisig_approve_as_multi_V9_t multisig_approve_as_multi_V9;
    pd_multisig_cancel_as_multi_V9_t multisig_cancel_as_multi_V9;
#endif
} pd_MethodNested_V9_t;

typedef union {
    pd_MethodBasic_V9_t basic;
    pd_MethodNested_V9_t nested;
} pd_Method_V9_t;

#ifdef __cplusplus
}
#endif

#pragma clang diagnostic pop
