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
#define PD_CALL_TIMESTAMP_V8 3
#define PD_CALL_INDICES_V8 4
#define PD_CALL_BALANCES_V8 5
#define PD_CALL_STAKING_V8 7
#define PD_CALL_SESSION_V8 9
#define PD_CALL_GRANDPA_V8 11
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
#define PD_CALL_CONFIGURATION_V8 51
#define PD_CALL_INITIALIZER_V8 57
#define PD_CALL_HRMP_V8 60
#define PD_CALL_REGISTRAR_V8 70
#define PD_CALL_AUCTIONS_V8 72

#define PD_CALL_BALANCES_TRANSFER_ALL_V8 4
typedef struct {
    pd_LookupasStaticLookupSource_V8_t dest;
    pd_bool_t keep_alive;
} pd_balances_transfer_all_V8_t;

#define PD_CALL_STAKING_BOND_V8 0
typedef struct {
    pd_LookupasStaticLookupSource_V8_t controller;
    pd_CompactBalance_t amount;
    pd_RewardDestination_V8_t payee;
} pd_staking_bond_V8_t;

#define PD_CALL_STAKING_BOND_EXTRA_V8 1
typedef struct {
    pd_CompactBalance_t amount;
} pd_staking_bond_extra_V8_t;

#define PD_CALL_STAKING_UNBOND_V8 2
typedef struct {
    pd_CompactBalance_t amount;
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
    pd_VecLookupasStaticLookupSource_V8_t targets;
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
    pd_LookupasStaticLookupSource_V8_t controller;
} pd_staking_set_controller_V8_t;

#define PD_CALL_STAKING_PAYOUT_STAKERS_V8 18
typedef struct {
    pd_AccountId_V8_t validator_stash;
    pd_EraIndex_V8_t era;
} pd_staking_payout_stakers_V8_t;

#define PD_CALL_STAKING_REBOND_V8 19
typedef struct {
    pd_CompactBalance_t amount;
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

#define PD_CALL_TIMESTAMP_SET_V8 0
typedef struct {
    pd_Compactu64_t now;
} pd_timestamp_set_V8_t;

#define PD_CALL_INDICES_CLAIM_V8 0
typedef struct {
    pd_AccountIndex_V8_t index;
} pd_indices_claim_V8_t;

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

#define PD_CALL_BALANCES_FORCE_UNRESERVE_V8 5
typedef struct {
    pd_LookupasStaticLookupSource_V8_t who;
    pd_Balance_t amount;
} pd_balances_force_unreserve_V8_t;

#define PD_CALL_STAKING_SET_VALIDATOR_COUNT_V8 9
typedef struct {
    pd_Compactu32_t new_;
} pd_staking_set_validator_count_V8_t;

#define PD_CALL_STAKING_INCREASE_VALIDATOR_COUNT_V8 10
typedef struct {
    pd_Compactu32_t additional;
} pd_staking_increase_validator_count_V8_t;

#define PD_CALL_STAKING_FORCE_NO_ERAS_V8 12
typedef struct {
} pd_staking_force_no_eras_V8_t;

#define PD_CALL_STAKING_FORCE_NEW_ERA_V8 13
typedef struct {
} pd_staking_force_new_era_V8_t;

#define PD_CALL_STAKING_FORCE_UNSTAKE_V8 15
typedef struct {
    pd_AccountId_V8_t stash;
    pd_u32_t num_slashing_spans;
} pd_staking_force_unstake_V8_t;

#define PD_CALL_STAKING_FORCE_NEW_ERA_ALWAYS_V8 16
typedef struct {
} pd_staking_force_new_era_always_V8_t;

#define PD_CALL_STAKING_SET_HISTORY_DEPTH_V8 20
typedef struct {
    pd_Compactu32_t new_history_depth;
    pd_Compactu32_t era_items_deleted;
} pd_staking_set_history_depth_V8_t;

#define PD_CALL_STAKING_REAP_STASH_V8 21
typedef struct {
    pd_AccountId_V8_t stash;
    pd_u32_t num_slashing_spans;
} pd_staking_reap_stash_V8_t;

#define PD_CALL_STAKING_KICK_V8 22
typedef struct {
    pd_VecLookupasStaticLookupSource_V8_t who;
} pd_staking_kick_V8_t;

#define PD_CALL_STAKING_CHILL_OTHER_V8 24
typedef struct {
    pd_AccountId_V8_t controller;
} pd_staking_chill_other_V8_t;

#define PD_CALL_GRANDPA_NOTE_STALLED_V8 2
typedef struct {
    pd_BlockNumber_t delay;
    pd_BlockNumber_t best_finalized_block_number;
} pd_grandpa_note_stalled_V8_t;

#define PD_CALL_DEMOCRACY_SECOND_V8 1
typedef struct {
    pd_Compactu32_t proposal;
    pd_Compactu32_t seconds_upper_bound;
} pd_democracy_second_V8_t;

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
    pd_Compactu32_t ref_index;
} pd_democracy_cancel_referendum_V8_t;

#define PD_CALL_DEMOCRACY_CANCEL_QUEUED_V8 10
typedef struct {
    pd_ReferendumIndex_V8_t which;
} pd_democracy_cancel_queued_V8_t;

#define PD_CALL_DEMOCRACY_DELEGATE_V8 11
typedef struct {
    pd_AccountId_V8_t to;
    pd_Conviction_V8_t conviction;
    pd_Balance_t balance;
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

#define PD_CALL_DEMOCRACY_CANCEL_PROPOSAL_V8 24
typedef struct {
    pd_Compactu32_t prop_index;
} pd_democracy_cancel_proposal_V8_t;

#define PD_CALL_COUNCIL_VOTE_V8 3
typedef struct {
    pd_Hash_t proposal;
    pd_Compactu32_t index;
    pd_bool_t approve;
} pd_council_vote_V8_t;

#define PD_CALL_COUNCIL_CLOSE_V8 4
typedef struct {
    pd_Hash_t proposal_hash;
    pd_Compactu32_t index;
    pd_Compactu64_t proposal_weight_bound;
    pd_Compactu32_t length_bound;
} pd_council_close_V8_t;

#define PD_CALL_COUNCIL_DISAPPROVE_PROPOSAL_V8 5
typedef struct {
    pd_Hash_t proposal_hash;
} pd_council_disapprove_proposal_V8_t;

#define PD_CALL_TECHNICALCOMMITTEE_VOTE_V8 3
typedef struct {
    pd_Hash_t proposal;
    pd_Compactu32_t index;
    pd_bool_t approve;
} pd_technicalcommittee_vote_V8_t;

#define PD_CALL_TECHNICALCOMMITTEE_CLOSE_V8 4
typedef struct {
    pd_Hash_t proposal_hash;
    pd_Compactu32_t index;
    pd_Compactu64_t proposal_weight_bound;
    pd_Compactu32_t length_bound;
} pd_technicalcommittee_close_V8_t;

#define PD_CALL_TECHNICALCOMMITTEE_DISAPPROVE_PROPOSAL_V8 5
typedef struct {
    pd_Hash_t proposal_hash;
} pd_technicalcommittee_disapprove_proposal_V8_t;

#define PD_CALL_PHRAGMENELECTION_REMOVE_VOTER_V8 1
typedef struct {
} pd_phragmenelection_remove_voter_V8_t;

#define PD_CALL_PHRAGMENELECTION_SUBMIT_CANDIDACY_V8 2
typedef struct {
    pd_Compactu32_t candidate_count;
} pd_phragmenelection_submit_candidacy_V8_t;

#define PD_CALL_PHRAGMENELECTION_REMOVE_MEMBER_V8 4
typedef struct {
    pd_LookupasStaticLookupSource_V8_t who;
    pd_bool_t has_replacement;
} pd_phragmenelection_remove_member_V8_t;

#define PD_CALL_PHRAGMENELECTION_CLEAN_DEFUNCT_VOTERS_V8 5
typedef struct {
    pd_u32_t num_voters;
    pd_u32_t num_defunct;
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
    pd_CompactBalance_t amount;
    pd_LookupasStaticLookupSource_V8_t beneficiary;
} pd_treasury_propose_spend_V8_t;

#define PD_CALL_TREASURY_REJECT_PROPOSAL_V8 1
typedef struct {
    pd_Compactu32_t proposal_id;
} pd_treasury_reject_proposal_V8_t;

#define PD_CALL_TREASURY_APPROVE_PROPOSAL_V8 2
typedef struct {
    pd_Compactu32_t proposal_id;
} pd_treasury_approve_proposal_V8_t;

#define PD_CALL_CLAIMS_CLAIM_V8 0
typedef struct {
    pd_AccountId_V8_t dest;
    pd_EcdsaSignature_V8_t ethereum_signature;
} pd_claims_claim_V8_t;

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
    pd_LookupasStaticLookupSource_V8_t target;
} pd_vesting_vest_other_V8_t;

#define PD_CALL_VESTING_MERGE_SCHEDULES_V8 4
typedef struct {
    pd_u32_t schedule1_index;
    pd_u32_t schedule2_index;
} pd_vesting_merge_schedules_V8_t;

#define PD_CALL_IDENTITY_ADD_REGISTRAR_V8 0
typedef struct {
    pd_AccountId_V8_t account;
} pd_identity_add_registrar_V8_t;

#define PD_CALL_IDENTITY_CLEAR_IDENTITY_V8 3
typedef struct {
} pd_identity_clear_identity_V8_t;

#define PD_CALL_IDENTITY_REQUEST_JUDGEMENT_V8 4
typedef struct {
    pd_Compactu32_t reg_index;
    pd_Compactu128_t max_fee;
} pd_identity_request_judgement_V8_t;

#define PD_CALL_IDENTITY_CANCEL_REQUEST_V8 5
typedef struct {
    pd_RegistrarIndex_V8_t reg_index;
} pd_identity_cancel_request_V8_t;

#define PD_CALL_IDENTITY_SET_FEE_V8 6
typedef struct {
    pd_Compactu32_t index;
    pd_Compactu128_t fee;
} pd_identity_set_fee_V8_t;

#define PD_CALL_IDENTITY_SET_ACCOUNT_ID_V8 7
typedef struct {
    pd_Compactu32_t index;
    pd_AccountId_V8_t new_;
} pd_identity_set_account_id_V8_t;

#define PD_CALL_IDENTITY_KILL_IDENTITY_V8 10
typedef struct {
    pd_LookupasStaticLookupSource_V8_t target;
} pd_identity_kill_identity_V8_t;

#define PD_CALL_IDENTITY_REMOVE_SUB_V8 13
typedef struct {
    pd_LookupasStaticLookupSource_V8_t sub;
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
    pd_Compactu32_t height;
    pd_Compactu32_t ext_index;
} pd_proxy_kill_anonymous_V8_t;

#define PD_CALL_PROXY_PROXY_ANNOUNCED_V8 9
typedef struct {
    pd_AccountId_V8_t delegate;
    pd_AccountId_V8_t real;
    pd_OptionProxyType_V8_t force_proxy_type;
    pd_Call_t call;
} pd_proxy_proxy_announced_V8_t;

#define PD_CALL_BOUNTIES_PROPOSE_BOUNTY_V8 0
typedef struct {
    pd_CompactBalance_t amount;
    pd_Bytes_t description;
} pd_bounties_propose_bounty_V8_t;

#define PD_CALL_BOUNTIES_APPROVE_BOUNTY_V8 1
typedef struct {
    pd_Compactu32_t bounty_id;
} pd_bounties_approve_bounty_V8_t;

#define PD_CALL_BOUNTIES_PROPOSE_CURATOR_V8 2
typedef struct {
    pd_Compactu32_t bounty_id;
    pd_LookupasStaticLookupSource_V8_t curator;
    pd_CompactBalance_t fee;
} pd_bounties_propose_curator_V8_t;

#define PD_CALL_BOUNTIES_UNASSIGN_CURATOR_V8 3
typedef struct {
    pd_Compactu32_t bounty_id;
} pd_bounties_unassign_curator_V8_t;

#define PD_CALL_BOUNTIES_ACCEPT_CURATOR_V8 4
typedef struct {
    pd_Compactu32_t bounty_id;
} pd_bounties_accept_curator_V8_t;

#define PD_CALL_BOUNTIES_AWARD_BOUNTY_V8 5
typedef struct {
    pd_Compactu32_t bounty_id;
    pd_LookupasStaticLookupSource_V8_t beneficiary;
} pd_bounties_award_bounty_V8_t;

#define PD_CALL_BOUNTIES_CLAIM_BOUNTY_V8 6
typedef struct {
    pd_Compactu32_t bounty_id;
} pd_bounties_claim_bounty_V8_t;

#define PD_CALL_BOUNTIES_CLOSE_BOUNTY_V8 7
typedef struct {
    pd_Compactu32_t bounty_id;
} pd_bounties_close_bounty_V8_t;

#define PD_CALL_BOUNTIES_EXTEND_BOUNTY_EXPIRY_V8 8
typedef struct {
    pd_Compactu32_t bounty_id;
    pd_Bytes_t remark;
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
    pd_Compactu128_t tip_value;
} pd_tips_tip_new_V8_t;

#define PD_CALL_TIPS_TIP_V8 3
typedef struct {
    pd_Hash_t hash;
    pd_Compactu128_t tip_value;
} pd_tips_tip_V8_t;

#define PD_CALL_TIPS_CLOSE_TIP_V8 4
typedef struct {
    pd_Hash_t hash;
} pd_tips_close_tip_V8_t;

#define PD_CALL_TIPS_SLASH_TIP_V8 5
typedef struct {
    pd_Hash_t hash;
} pd_tips_slash_tip_V8_t;

#define PD_CALL_CONFIGURATION_SET_VALIDATION_UPGRADE_FREQUENCY_V8 0
typedef struct {
    pd_BlockNumber_t new_;
} pd_configuration_set_validation_upgrade_frequency_V8_t;

#define PD_CALL_CONFIGURATION_SET_VALIDATION_UPGRADE_DELAY_V8 1
typedef struct {
    pd_BlockNumber_t new_;
} pd_configuration_set_validation_upgrade_delay_V8_t;

#define PD_CALL_CONFIGURATION_SET_CODE_RETENTION_PERIOD_V8 2
typedef struct {
    pd_BlockNumber_t new_;
} pd_configuration_set_code_retention_period_V8_t;

#define PD_CALL_CONFIGURATION_SET_MAX_CODE_SIZE_V8 3
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_max_code_size_V8_t;

#define PD_CALL_CONFIGURATION_SET_MAX_POV_SIZE_V8 4
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_max_pov_size_V8_t;

#define PD_CALL_CONFIGURATION_SET_MAX_HEAD_DATA_SIZE_V8 5
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_max_head_data_size_V8_t;

#define PD_CALL_CONFIGURATION_SET_PARATHREAD_CORES_V8 6
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_parathread_cores_V8_t;

#define PD_CALL_CONFIGURATION_SET_PARATHREAD_RETRIES_V8 7
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_parathread_retries_V8_t;

#define PD_CALL_CONFIGURATION_SET_GROUP_ROTATION_FREQUENCY_V8 8
typedef struct {
    pd_BlockNumber_t new_;
} pd_configuration_set_group_rotation_frequency_V8_t;

#define PD_CALL_CONFIGURATION_SET_CHAIN_AVAILABILITY_PERIOD_V8 9
typedef struct {
    pd_BlockNumber_t new_;
} pd_configuration_set_chain_availability_period_V8_t;

#define PD_CALL_CONFIGURATION_SET_THREAD_AVAILABILITY_PERIOD_V8 10
typedef struct {
    pd_BlockNumber_t new_;
} pd_configuration_set_thread_availability_period_V8_t;

#define PD_CALL_CONFIGURATION_SET_SCHEDULING_LOOKAHEAD_V8 11
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_scheduling_lookahead_V8_t;

#define PD_CALL_CONFIGURATION_SET_MAX_VALIDATORS_PER_CORE_V8 12
typedef struct {
    pd_Optionu32_t new_;
} pd_configuration_set_max_validators_per_core_V8_t;

#define PD_CALL_CONFIGURATION_SET_MAX_VALIDATORS_V8 13
typedef struct {
    pd_Optionu32_t new_;
} pd_configuration_set_max_validators_V8_t;

#define PD_CALL_CONFIGURATION_SET_DISPUTE_POST_CONCLUSION_ACCEPTANCE_PERIOD_V8 15
typedef struct {
    pd_BlockNumber_t new_;
} pd_configuration_set_dispute_post_conclusion_acceptance_period_V8_t;

#define PD_CALL_CONFIGURATION_SET_DISPUTE_MAX_SPAM_SLOTS_V8 16
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_dispute_max_spam_slots_V8_t;

#define PD_CALL_CONFIGURATION_SET_DISPUTE_CONCLUSION_BY_TIME_OUT_PERIOD_V8 17
typedef struct {
    pd_BlockNumber_t new_;
} pd_configuration_set_dispute_conclusion_by_time_out_period_V8_t;

#define PD_CALL_CONFIGURATION_SET_NO_SHOW_SLOTS_V8 18
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_no_show_slots_V8_t;

#define PD_CALL_CONFIGURATION_SET_N_DELAY_TRANCHES_V8 19
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_n_delay_tranches_V8_t;

#define PD_CALL_CONFIGURATION_SET_ZEROTH_DELAY_TRANCHE_WIDTH_V8 20
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_zeroth_delay_tranche_width_V8_t;

#define PD_CALL_CONFIGURATION_SET_NEEDED_APPROVALS_V8 21
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_needed_approvals_V8_t;

#define PD_CALL_CONFIGURATION_SET_RELAY_VRF_MODULO_SAMPLES_V8 22
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_relay_vrf_modulo_samples_V8_t;

#define PD_CALL_CONFIGURATION_SET_MAX_UPWARD_QUEUE_COUNT_V8 23
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_max_upward_queue_count_V8_t;

#define PD_CALL_CONFIGURATION_SET_MAX_UPWARD_QUEUE_SIZE_V8 24
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_max_upward_queue_size_V8_t;

#define PD_CALL_CONFIGURATION_SET_MAX_DOWNWARD_MESSAGE_SIZE_V8 25
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_max_downward_message_size_V8_t;

#define PD_CALL_CONFIGURATION_SET_UMP_SERVICE_TOTAL_WEIGHT_V8 26
typedef struct {
    pd_Weight_V8_t new_;
} pd_configuration_set_ump_service_total_weight_V8_t;

#define PD_CALL_CONFIGURATION_SET_MAX_UPWARD_MESSAGE_SIZE_V8 27
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_max_upward_message_size_V8_t;

#define PD_CALL_CONFIGURATION_SET_MAX_UPWARD_MESSAGE_NUM_PER_CANDIDATE_V8 28
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_max_upward_message_num_per_candidate_V8_t;

#define PD_CALL_CONFIGURATION_SET_HRMP_OPEN_REQUEST_TTL_V8 29
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_hrmp_open_request_ttl_V8_t;

#define PD_CALL_CONFIGURATION_SET_HRMP_SENDER_DEPOSIT_V8 30
typedef struct {
    pd_Balance_t new_;
} pd_configuration_set_hrmp_sender_deposit_V8_t;

#define PD_CALL_CONFIGURATION_SET_HRMP_RECIPIENT_DEPOSIT_V8 31
typedef struct {
    pd_Balance_t new_;
} pd_configuration_set_hrmp_recipient_deposit_V8_t;

#define PD_CALL_CONFIGURATION_SET_HRMP_CHANNEL_MAX_CAPACITY_V8 32
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_hrmp_channel_max_capacity_V8_t;

#define PD_CALL_CONFIGURATION_SET_HRMP_CHANNEL_MAX_TOTAL_SIZE_V8 33
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_hrmp_channel_max_total_size_V8_t;

#define PD_CALL_CONFIGURATION_SET_HRMP_MAX_PARACHAIN_INBOUND_CHANNELS_V8 34
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_hrmp_max_parachain_inbound_channels_V8_t;

#define PD_CALL_CONFIGURATION_SET_HRMP_MAX_PARATHREAD_INBOUND_CHANNELS_V8 35
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_hrmp_max_parathread_inbound_channels_V8_t;

#define PD_CALL_CONFIGURATION_SET_HRMP_CHANNEL_MAX_MESSAGE_SIZE_V8 36
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_hrmp_channel_max_message_size_V8_t;

#define PD_CALL_CONFIGURATION_SET_HRMP_MAX_PARACHAIN_OUTBOUND_CHANNELS_V8 37
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_hrmp_max_parachain_outbound_channels_V8_t;

#define PD_CALL_CONFIGURATION_SET_HRMP_MAX_PARATHREAD_OUTBOUND_CHANNELS_V8 38
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_hrmp_max_parathread_outbound_channels_V8_t;

#define PD_CALL_CONFIGURATION_SET_HRMP_MAX_MESSAGE_NUM_PER_CANDIDATE_V8 39
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_hrmp_max_message_num_per_candidate_V8_t;

#define PD_CALL_CONFIGURATION_SET_UMP_MAX_INDIVIDUAL_WEIGHT_V8 40
typedef struct {
    pd_Weight_V8_t new_;
} pd_configuration_set_ump_max_individual_weight_V8_t;

#define PD_CALL_INITIALIZER_FORCE_APPROVE_V8 0
typedef struct {
    pd_BlockNumber_t up_to;
} pd_initializer_force_approve_V8_t;

#define PD_CALL_HRMP_FORCE_PROCESS_HRMP_OPEN_V8 4
typedef struct {
} pd_hrmp_force_process_hrmp_open_V8_t;

#define PD_CALL_HRMP_FORCE_PROCESS_HRMP_CLOSE_V8 5
typedef struct {
} pd_hrmp_force_process_hrmp_close_V8_t;

#define PD_CALL_REGISTRAR_RESERVE_V8 5
typedef struct {
} pd_registrar_reserve_V8_t;

#define PD_CALL_AUCTIONS_NEW_AUCTION_V8 0
typedef struct {
    pd_Compactu32_t duration;
    pd_Compactu32_t lease_period_index;
} pd_auctions_new_auction_V8_t;

#define PD_CALL_AUCTIONS_BID_V8 1
typedef struct {
    pd_Compactu32_t para;
    pd_Compactu32_t auction_index;
    pd_Compactu32_t first_slot;
    pd_Compactu32_t last_slot;
    pd_CompactBalance_t amount;
} pd_auctions_bid_V8_t;

#define PD_CALL_AUCTIONS_CANCEL_AUCTION_V8 2
typedef struct {
} pd_auctions_cancel_auction_V8_t;

#endif

typedef union {
    pd_balances_transfer_all_V8_t balances_transfer_all_V8;
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
    pd_timestamp_set_V8_t timestamp_set_V8;
    pd_indices_claim_V8_t indices_claim_V8;
    pd_indices_free_V8_t indices_free_V8;
    pd_indices_force_transfer_V8_t indices_force_transfer_V8;
    pd_indices_freeze_V8_t indices_freeze_V8;
    pd_balances_force_unreserve_V8_t balances_force_unreserve_V8;
    pd_staking_set_validator_count_V8_t staking_set_validator_count_V8;
    pd_staking_increase_validator_count_V8_t staking_increase_validator_count_V8;
    pd_staking_force_no_eras_V8_t staking_force_no_eras_V8;
    pd_staking_force_new_era_V8_t staking_force_new_era_V8;
    pd_staking_force_unstake_V8_t staking_force_unstake_V8;
    pd_staking_force_new_era_always_V8_t staking_force_new_era_always_V8;
    pd_staking_set_history_depth_V8_t staking_set_history_depth_V8;
    pd_staking_reap_stash_V8_t staking_reap_stash_V8;
    pd_staking_kick_V8_t staking_kick_V8;
    pd_staking_chill_other_V8_t staking_chill_other_V8;
    pd_grandpa_note_stalled_V8_t grandpa_note_stalled_V8;
    pd_democracy_second_V8_t democracy_second_V8;
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
    pd_democracy_cancel_proposal_V8_t democracy_cancel_proposal_V8;
    pd_council_vote_V8_t council_vote_V8;
    pd_council_close_V8_t council_close_V8;
    pd_council_disapprove_proposal_V8_t council_disapprove_proposal_V8;
    pd_technicalcommittee_vote_V8_t technicalcommittee_vote_V8;
    pd_technicalcommittee_close_V8_t technicalcommittee_close_V8;
    pd_technicalcommittee_disapprove_proposal_V8_t technicalcommittee_disapprove_proposal_V8;
    pd_phragmenelection_remove_voter_V8_t phragmenelection_remove_voter_V8;
    pd_phragmenelection_submit_candidacy_V8_t phragmenelection_submit_candidacy_V8;
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
    pd_claims_claim_attest_V8_t claims_claim_attest_V8;
    pd_claims_attest_V8_t claims_attest_V8;
    pd_claims_move_claim_V8_t claims_move_claim_V8;
    pd_vesting_vest_V8_t vesting_vest_V8;
    pd_vesting_vest_other_V8_t vesting_vest_other_V8;
    pd_vesting_merge_schedules_V8_t vesting_merge_schedules_V8;
    pd_identity_add_registrar_V8_t identity_add_registrar_V8;
    pd_identity_clear_identity_V8_t identity_clear_identity_V8;
    pd_identity_request_judgement_V8_t identity_request_judgement_V8;
    pd_identity_cancel_request_V8_t identity_cancel_request_V8;
    pd_identity_set_fee_V8_t identity_set_fee_V8;
    pd_identity_set_account_id_V8_t identity_set_account_id_V8;
    pd_identity_kill_identity_V8_t identity_kill_identity_V8;
    pd_identity_remove_sub_V8_t identity_remove_sub_V8;
    pd_identity_quit_sub_V8_t identity_quit_sub_V8;
    pd_proxy_add_proxy_V8_t proxy_add_proxy_V8;
    pd_proxy_remove_proxy_V8_t proxy_remove_proxy_V8;
    pd_proxy_remove_proxies_V8_t proxy_remove_proxies_V8;
    pd_proxy_anonymous_V8_t proxy_anonymous_V8;
    pd_proxy_kill_anonymous_V8_t proxy_kill_anonymous_V8;
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
    pd_configuration_set_validation_upgrade_frequency_V8_t configuration_set_validation_upgrade_frequency_V8;
    pd_configuration_set_validation_upgrade_delay_V8_t configuration_set_validation_upgrade_delay_V8;
    pd_configuration_set_code_retention_period_V8_t configuration_set_code_retention_period_V8;
    pd_configuration_set_max_code_size_V8_t configuration_set_max_code_size_V8;
    pd_configuration_set_max_pov_size_V8_t configuration_set_max_pov_size_V8;
    pd_configuration_set_max_head_data_size_V8_t configuration_set_max_head_data_size_V8;
    pd_configuration_set_parathread_cores_V8_t configuration_set_parathread_cores_V8;
    pd_configuration_set_parathread_retries_V8_t configuration_set_parathread_retries_V8;
    pd_configuration_set_group_rotation_frequency_V8_t configuration_set_group_rotation_frequency_V8;
    pd_configuration_set_chain_availability_period_V8_t configuration_set_chain_availability_period_V8;
    pd_configuration_set_thread_availability_period_V8_t configuration_set_thread_availability_period_V8;
    pd_configuration_set_scheduling_lookahead_V8_t configuration_set_scheduling_lookahead_V8;
    pd_configuration_set_max_validators_per_core_V8_t configuration_set_max_validators_per_core_V8;
    pd_configuration_set_max_validators_V8_t configuration_set_max_validators_V8;
    pd_configuration_set_dispute_post_conclusion_acceptance_period_V8_t configuration_set_dispute_post_conclusion_acceptance_period_V8;
    pd_configuration_set_dispute_max_spam_slots_V8_t configuration_set_dispute_max_spam_slots_V8;
    pd_configuration_set_dispute_conclusion_by_time_out_period_V8_t configuration_set_dispute_conclusion_by_time_out_period_V8;
    pd_configuration_set_no_show_slots_V8_t configuration_set_no_show_slots_V8;
    pd_configuration_set_n_delay_tranches_V8_t configuration_set_n_delay_tranches_V8;
    pd_configuration_set_zeroth_delay_tranche_width_V8_t configuration_set_zeroth_delay_tranche_width_V8;
    pd_configuration_set_needed_approvals_V8_t configuration_set_needed_approvals_V8;
    pd_configuration_set_relay_vrf_modulo_samples_V8_t configuration_set_relay_vrf_modulo_samples_V8;
    pd_configuration_set_max_upward_queue_count_V8_t configuration_set_max_upward_queue_count_V8;
    pd_configuration_set_max_upward_queue_size_V8_t configuration_set_max_upward_queue_size_V8;
    pd_configuration_set_max_downward_message_size_V8_t configuration_set_max_downward_message_size_V8;
    pd_configuration_set_ump_service_total_weight_V8_t configuration_set_ump_service_total_weight_V8;
    pd_configuration_set_max_upward_message_size_V8_t configuration_set_max_upward_message_size_V8;
    pd_configuration_set_max_upward_message_num_per_candidate_V8_t configuration_set_max_upward_message_num_per_candidate_V8;
    pd_configuration_set_hrmp_open_request_ttl_V8_t configuration_set_hrmp_open_request_ttl_V8;
    pd_configuration_set_hrmp_sender_deposit_V8_t configuration_set_hrmp_sender_deposit_V8;
    pd_configuration_set_hrmp_recipient_deposit_V8_t configuration_set_hrmp_recipient_deposit_V8;
    pd_configuration_set_hrmp_channel_max_capacity_V8_t configuration_set_hrmp_channel_max_capacity_V8;
    pd_configuration_set_hrmp_channel_max_total_size_V8_t configuration_set_hrmp_channel_max_total_size_V8;
    pd_configuration_set_hrmp_max_parachain_inbound_channels_V8_t configuration_set_hrmp_max_parachain_inbound_channels_V8;
    pd_configuration_set_hrmp_max_parathread_inbound_channels_V8_t configuration_set_hrmp_max_parathread_inbound_channels_V8;
    pd_configuration_set_hrmp_channel_max_message_size_V8_t configuration_set_hrmp_channel_max_message_size_V8;
    pd_configuration_set_hrmp_max_parachain_outbound_channels_V8_t configuration_set_hrmp_max_parachain_outbound_channels_V8;
    pd_configuration_set_hrmp_max_parathread_outbound_channels_V8_t configuration_set_hrmp_max_parathread_outbound_channels_V8;
    pd_configuration_set_hrmp_max_message_num_per_candidate_V8_t configuration_set_hrmp_max_message_num_per_candidate_V8;
    pd_configuration_set_ump_max_individual_weight_V8_t configuration_set_ump_max_individual_weight_V8;
    pd_initializer_force_approve_V8_t initializer_force_approve_V8;
    pd_hrmp_force_process_hrmp_open_V8_t hrmp_force_process_hrmp_open_V8;
    pd_hrmp_force_process_hrmp_close_V8_t hrmp_force_process_hrmp_close_V8;
    pd_registrar_reserve_V8_t registrar_reserve_V8;
    pd_auctions_new_auction_V8_t auctions_new_auction_V8;
    pd_auctions_bid_V8_t auctions_bid_V8;
    pd_auctions_cancel_auction_V8_t auctions_cancel_auction_V8;
#endif
} pd_MethodBasic_V8_t;

#define PD_CALL_BALANCES_TRANSFER_V8 0
typedef struct {
    pd_LookupasStaticLookupSource_V8_t dest;
    pd_CompactBalance_t amount;
} pd_balances_transfer_V8_t;

#define PD_CALL_BALANCES_FORCE_TRANSFER_V8 2
typedef struct {
    pd_LookupasStaticLookupSource_V8_t source;
    pd_LookupasStaticLookupSource_V8_t dest;
    pd_CompactBalance_t amount;
} pd_balances_force_transfer_V8_t;

#define PD_CALL_BALANCES_TRANSFER_KEEP_ALIVE_V8 3
typedef struct {
    pd_LookupasStaticLookupSource_V8_t dest;
    pd_CompactBalance_t amount;
} pd_balances_transfer_keep_alive_V8_t;

#ifdef SUBSTRATE_PARSER_FULL
#define PD_CALL_SYSTEM_FILL_BLOCK_V8 0
typedef struct {
    pd_Perbill_V8_t ratio;
} pd_system_fill_block_V8_t;

#define PD_CALL_SYSTEM_REMARK_V8 1
typedef struct {
    pd_Vecu8_t remark;
} pd_system_remark_V8_t;

#define PD_CALL_SYSTEM_SET_HEAP_PAGES_V8 2
typedef struct {
    pd_u64_t pages;
} pd_system_set_heap_pages_V8_t;

#define PD_CALL_SYSTEM_SET_CODE_V8 3
typedef struct {
    pd_Vecu8_t code;
} pd_system_set_code_V8_t;

#define PD_CALL_SYSTEM_SET_CODE_WITHOUT_CHECKS_V8 4
typedef struct {
    pd_Vecu8_t code;
} pd_system_set_code_without_checks_V8_t;

#define PD_CALL_SYSTEM_REMARK_WITH_EVENT_V8 9
typedef struct {
    pd_Vecu8_t remark;
} pd_system_remark_with_event_V8_t;

#define PD_CALL_BALANCES_SET_BALANCE_V8 1
typedef struct {
    pd_LookupasStaticLookupSource_V8_t who;
    pd_CompactBalance_t new_free;
    pd_CompactBalance_t new_reserved;
} pd_balances_set_balance_V8_t;

#define PD_CALL_PROXY_PROXY_V8 0
typedef struct {
    pd_AccountId_V8_t real;
    pd_OptionProxyType_V8_t force_proxy_type;
    pd_Call_t call;
} pd_proxy_proxy_V8_t;

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
    pd_H256_t call_hash;
    pd_Weight_V8_t max_weight;
} pd_multisig_approve_as_multi_V8_t;

#define PD_CALL_MULTISIG_CANCEL_AS_MULTI_V8 3
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_V8_t other_signatories;
    pd_Timepoint_V8_t timepoint;
    pd_H256_t call_hash;
} pd_multisig_cancel_as_multi_V8_t;

#endif

typedef union {
    pd_balances_transfer_V8_t balances_transfer_V8;
    pd_balances_force_transfer_V8_t balances_force_transfer_V8;
    pd_balances_transfer_keep_alive_V8_t balances_transfer_keep_alive_V8;
#ifdef SUBSTRATE_PARSER_FULL
    pd_system_fill_block_V8_t system_fill_block_V8;
    pd_system_remark_V8_t system_remark_V8;
    pd_system_set_heap_pages_V8_t system_set_heap_pages_V8;
    pd_system_set_code_V8_t system_set_code_V8;
    pd_system_set_code_without_checks_V8_t system_set_code_without_checks_V8;
    pd_system_remark_with_event_V8_t system_remark_with_event_V8;
    pd_balances_set_balance_V8_t balances_set_balance_V8;
    pd_proxy_proxy_V8_t proxy_proxy_V8;
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
