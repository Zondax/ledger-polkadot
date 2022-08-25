/*******************************************************************************
 *  (c) 2019 - 2022 Zondax AG
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
#include "substrate_types_V13.h"
#include <stddef.h>
#include <stdint.h>

#define PD_CALL_SYSTEM_V13 0
#define PD_CALL_PREIMAGE_V13 10
#define PD_CALL_TIMESTAMP_V13 3
#define PD_CALL_INDICES_V13 4
#define PD_CALL_BALANCES_V13 5
#define PD_CALL_STAKING_V13 7
#define PD_CALL_SESSION_V13 9
#define PD_CALL_GRANDPA_V13 11
#define PD_CALL_DEMOCRACY_V13 14
#define PD_CALL_COUNCIL_V13 15
#define PD_CALL_TECHNICALCOMMITTEE_V13 16
#define PD_CALL_PHRAGMENELECTION_V13 17
#define PD_CALL_TECHNICALMEMBERSHIP_V13 18
#define PD_CALL_TREASURY_V13 19
#define PD_CALL_CLAIMS_V13 24
#define PD_CALL_VESTING_V13 25
#define PD_CALL_UTILITY_V13 26
#define PD_CALL_IDENTITY_V13 28
#define PD_CALL_PROXY_V13 29
#define PD_CALL_MULTISIG_V13 30
#define PD_CALL_BOUNTIES_V13 34
#define PD_CALL_CHILDBOUNTIES_V13 38
#define PD_CALL_TIPS_V13 35
#define PD_CALL_ELECTIONPROVIDERMULTIPHASE_V13 36
#define PD_CALL_VOTERLIST_V13 37
#define PD_CALL_NOMINATIONPOOLS_V13 39
#define PD_CALL_CONFIGURATION_V13 51
#define PD_CALL_INITIALIZER_V13 57
#define PD_CALL_UMP_V13 59
#define PD_CALL_HRMP_V13 60
#define PD_CALL_PARASDISPUTES_V13 62
#define PD_CALL_REGISTRAR_V13 70
#define PD_CALL_AUCTIONS_V13 72
#define PD_CALL_CROWDLOAN_V13 73

#define PD_CALL_BALANCES_TRANSFER_ALL_V13 4
typedef struct {
    pd_LookupasStaticLookupSource_V13_t dest;
    pd_bool_t keep_alive;
} pd_balances_transfer_all_V13_t;

#define PD_CALL_STAKING_BOND_V13 0
typedef struct {
    pd_LookupasStaticLookupSource_V13_t controller;
    pd_CompactBalance_t amount;
    pd_RewardDestination_V13_t payee;
} pd_staking_bond_V13_t;

#define PD_CALL_STAKING_BOND_EXTRA_V13 1
typedef struct {
    pd_CompactBalance_t amount;
} pd_staking_bond_extra_V13_t;

#define PD_CALL_STAKING_UNBOND_V13 2
typedef struct {
    pd_CompactBalance_t amount;
} pd_staking_unbond_V13_t;

#define PD_CALL_STAKING_WITHDRAW_UNBONDED_V13 3
typedef struct {
    pd_u32_t num_slashing_spans;
} pd_staking_withdraw_unbonded_V13_t;

#define PD_CALL_STAKING_VALIDATE_V13 4
typedef struct {
    pd_ValidatorPrefs_V13_t prefs;
} pd_staking_validate_V13_t;

#define PD_CALL_STAKING_NOMINATE_V13 5
typedef struct {
    pd_VecLookupasStaticLookupSource_V13_t targets;
} pd_staking_nominate_V13_t;

#define PD_CALL_STAKING_CHILL_V13 6
typedef struct {
} pd_staking_chill_V13_t;

#define PD_CALL_STAKING_SET_PAYEE_V13 7
typedef struct {
    pd_RewardDestination_V13_t payee;
} pd_staking_set_payee_V13_t;

#define PD_CALL_STAKING_SET_CONTROLLER_V13 8
typedef struct {
    pd_LookupasStaticLookupSource_V13_t controller;
} pd_staking_set_controller_V13_t;

#define PD_CALL_STAKING_PAYOUT_STAKERS_V13 18
typedef struct {
    pd_AccountId_V13_t validator_stash;
    pd_EraIndex_V13_t era;
} pd_staking_payout_stakers_V13_t;

#define PD_CALL_STAKING_REBOND_V13 19
typedef struct {
    pd_CompactBalance_t amount;
} pd_staking_rebond_V13_t;

#define PD_CALL_SESSION_SET_KEYS_V13 0
typedef struct {
    pd_Keys_V13_t keys;
    pd_Bytes_t proof;
} pd_session_set_keys_V13_t;

#define PD_CALL_SESSION_PURGE_KEYS_V13 1
typedef struct {
} pd_session_purge_keys_V13_t;

#define PD_CALL_UTILITY_BATCH_V13 0
typedef struct {
    pd_VecCall_t calls;
} pd_utility_batch_V13_t;

#define PD_CALL_UTILITY_BATCH_ALL_V13 2
typedef struct {
    pd_VecCall_t calls;
} pd_utility_batch_all_V13_t;

#define PD_CALL_UTILITY_FORCE_BATCH_V13 4
typedef struct {
    pd_VecCall_t calls;
} pd_utility_force_batch_V13_t;

#define PD_CALL_CROWDLOAN_CREATE_V13 0
typedef struct {
    pd_Compactu32_t index;
    pd_Compactu128_t cap;
    pd_Compactu32_t first_period;
    pd_Compactu32_t last_period;
    pd_Compactu32_t end;
    pd_OptionMultiSigner_V13_t verifier;
} pd_crowdloan_create_V13_t;

#define PD_CALL_CROWDLOAN_CONTRIBUTE_V13 1
typedef struct {
    pd_Compactu32_t index;
    pd_Compactu128_t amount;
    pd_OptionMultiSignature_V13_t signature;
} pd_crowdloan_contribute_V13_t;

#define PD_CALL_CROWDLOAN_WITHDRAW_V13 2
typedef struct {
    pd_AccountId_V13_t who;
    pd_Compactu32_t index;
} pd_crowdloan_withdraw_V13_t;

#define PD_CALL_CROWDLOAN_REFUND_V13 3
typedef struct {
    pd_Compactu32_t index;
} pd_crowdloan_refund_V13_t;

#define PD_CALL_CROWDLOAN_DISSOLVE_V13 4
typedef struct {
    pd_Compactu32_t index;
} pd_crowdloan_dissolve_V13_t;

#define PD_CALL_CROWDLOAN_EDIT_V13 5
typedef struct {
    pd_Compactu32_t index;
    pd_Compactu128_t cap;
    pd_Compactu32_t first_period;
    pd_Compactu32_t last_period;
    pd_Compactu32_t end;
    pd_OptionMultiSigner_V13_t verifier;
} pd_crowdloan_edit_V13_t;

#define PD_CALL_CROWDLOAN_ADD_MEMO_V13 6
typedef struct {
    pd_ParaId_V13_t index;
    pd_Vecu8_t memo;
} pd_crowdloan_add_memo_V13_t;

#define PD_CALL_CROWDLOAN_POKE_V13 7
typedef struct {
    pd_ParaId_V13_t index;
} pd_crowdloan_poke_V13_t;

#define PD_CALL_CROWDLOAN_CONTRIBUTE_ALL_V13 8
typedef struct {
    pd_Compactu32_t index;
    pd_OptionMultiSignature_V13_t signature;
} pd_crowdloan_contribute_all_V13_t;

#ifdef SUBSTRATE_PARSER_FULL

#define PD_CALL_PREIMAGE_NOTE_PREIMAGE_V13 0
typedef struct {
    pd_Vecu8_t bytes;
} pd_preimage_note_preimage_V13_t;

#define PD_CALL_PREIMAGE_UNNOTE_PREIMAGE_V13 1
typedef struct {
    pd_Hash_t hash;
} pd_preimage_unnote_preimage_V13_t;

#define PD_CALL_PREIMAGE_REQUEST_PREIMAGE_V13 2
typedef struct {
    pd_Hash_t hash;
} pd_preimage_request_preimage_V13_t;

#define PD_CALL_PREIMAGE_UNREQUEST_PREIMAGE_V13 3
typedef struct {
    pd_Hash_t hash;
} pd_preimage_unrequest_preimage_V13_t;

#define PD_CALL_TIMESTAMP_SET_V13 0
typedef struct {
    pd_Compactu64_t now;
} pd_timestamp_set_V13_t;

#define PD_CALL_INDICES_CLAIM_V13 0
typedef struct {
    pd_AccountIndex_V13_t index;
} pd_indices_claim_V13_t;

#define PD_CALL_INDICES_TRANSFER_V13 1
typedef struct {
    pd_AccountId_V13_t new_;
    pd_AccountIndex_V13_t index;
} pd_indices_transfer_V13_t;

#define PD_CALL_INDICES_FREE_V13 2
typedef struct {
    pd_AccountIndex_V13_t index;
} pd_indices_free_V13_t;

#define PD_CALL_INDICES_FORCE_TRANSFER_V13 3
typedef struct {
    pd_AccountId_V13_t new_;
    pd_AccountIndex_V13_t index;
    pd_bool_t freeze;
} pd_indices_force_transfer_V13_t;

#define PD_CALL_INDICES_FREEZE_V13 4
typedef struct {
    pd_AccountIndex_V13_t index;
} pd_indices_freeze_V13_t;

#define PD_CALL_BALANCES_FORCE_UNRESERVE_V13 5
typedef struct {
    pd_LookupasStaticLookupSource_V13_t who;
    pd_Balance_t amount;
} pd_balances_force_unreserve_V13_t;

#define PD_CALL_STAKING_SET_VALIDATOR_COUNT_V13 9
typedef struct {
    pd_Compactu32_t new_;
} pd_staking_set_validator_count_V13_t;

#define PD_CALL_STAKING_INCREASE_VALIDATOR_COUNT_V13 10
typedef struct {
    pd_Compactu32_t additional;
} pd_staking_increase_validator_count_V13_t;

#define PD_CALL_STAKING_FORCE_NO_ERAS_V13 12
typedef struct {
} pd_staking_force_no_eras_V13_t;

#define PD_CALL_STAKING_FORCE_NEW_ERA_V13 13
typedef struct {
} pd_staking_force_new_era_V13_t;

#define PD_CALL_STAKING_SET_INVULNERABLES_V13 14
typedef struct {
    pd_VecAccountId_V13_t invulnerables;
} pd_staking_set_invulnerables_V13_t;

#define PD_CALL_STAKING_FORCE_UNSTAKE_V13 15
typedef struct {
    pd_AccountId_V13_t stash;
    pd_u32_t num_slashing_spans;
} pd_staking_force_unstake_V13_t;

#define PD_CALL_STAKING_FORCE_NEW_ERA_ALWAYS_V13 16
typedef struct {
} pd_staking_force_new_era_always_V13_t;

#define PD_CALL_STAKING_CANCEL_DEFERRED_SLASH_V13 17
typedef struct {
    pd_EraIndex_V13_t era;
    pd_Vecu32_t slash_indices;
} pd_staking_cancel_deferred_slash_V13_t;

#define PD_CALL_STAKING_SET_HISTORY_DEPTH_V13 20
typedef struct {
    pd_Compactu32_t new_history_depth;
    pd_Compactu32_t era_items_deleted;
} pd_staking_set_history_depth_V13_t;

#define PD_CALL_STAKING_REAP_STASH_V13 21
typedef struct {
    pd_AccountId_V13_t stash;
    pd_u32_t num_slashing_spans;
} pd_staking_reap_stash_V13_t;

#define PD_CALL_STAKING_KICK_V13 22
typedef struct {
    pd_VecLookupasStaticLookupSource_V13_t who;
} pd_staking_kick_V13_t;

#define PD_CALL_STAKING_CHILL_OTHER_V13 24
typedef struct {
    pd_AccountId_V13_t controller;
} pd_staking_chill_other_V13_t;

#define PD_CALL_STAKING_FORCE_APPLY_MIN_COMMISSION_V13 25
typedef struct {
    pd_AccountId_V13_t validator_stash;
} pd_staking_force_apply_min_commission_V13_t;

#define PD_CALL_GRANDPA_NOTE_STALLED_V13 2
typedef struct {
    pd_BlockNumber_t delay;
    pd_BlockNumber_t best_finalized_block_number;
} pd_grandpa_note_stalled_V13_t;

#define PD_CALL_DEMOCRACY_NOTE_PREIMAGE_V13 14
typedef struct {
    pd_Bytes_t encoded_proposal;
} pd_democracy_note_preimage_V13_t;

#define PD_CALL_DEMOCRACY_NOTE_PREIMAGE_OPERATIONAL_V13 15
typedef struct {
    pd_Bytes_t encoded_proposal;
} pd_democracy_note_preimage_operational_V13_t;

#define PD_CALL_DEMOCRACY_NOTE_IMMINENT_PREIMAGE_V13 16
typedef struct {
    pd_Bytes_t encoded_proposal;
} pd_democracy_note_imminent_preimage_V13_t;

#define PD_CALL_DEMOCRACY_NOTE_IMMINENT_PREIMAGE_OPERATIONAL_V13 17
typedef struct {
    pd_Bytes_t encoded_proposal;
} pd_democracy_note_imminent_preimage_operational_V13_t;

#define PD_CALL_COUNCIL_SET_MEMBERS_V13 0
typedef struct {
    pd_VecAccountId_V13_t new_members;
    pd_OptionAccountId_V13_t prime;
    pd_MemberCount_V13_t old_count;
} pd_council_set_members_V13_t;

#define PD_CALL_COUNCIL_EXECUTE_V13 1
typedef struct {
    pd_Proposal_t proposal;
    pd_Compactu32_t length_bound;
} pd_council_execute_V13_t;

#define PD_CALL_COUNCIL_PROPOSE_V13 2
typedef struct {
    pd_Compactu32_t threshold;
    pd_Proposal_t proposal;
    pd_Compactu32_t length_bound;
} pd_council_propose_V13_t;

#define PD_CALL_COUNCIL_VOTE_V13 3
typedef struct {
    pd_Hash_t proposal;
    pd_Compactu32_t index;
    pd_bool_t approve;
} pd_council_vote_V13_t;

#define PD_CALL_COUNCIL_CLOSE_V13 4
typedef struct {
    pd_Hash_t proposal_hash;
    pd_Compactu32_t index;
    pd_Compactu64_t proposal_weight_bound;
    pd_Compactu32_t length_bound;
} pd_council_close_V13_t;

#define PD_CALL_COUNCIL_DISAPPROVE_PROPOSAL_V13 5
typedef struct {
    pd_Hash_t proposal_hash;
} pd_council_disapprove_proposal_V13_t;

#define PD_CALL_TECHNICALCOMMITTEE_SET_MEMBERS_V13 0
typedef struct {
    pd_VecAccountId_V13_t new_members;
    pd_OptionAccountId_V13_t prime;
    pd_MemberCount_V13_t old_count;
} pd_technicalcommittee_set_members_V13_t;

#define PD_CALL_TECHNICALCOMMITTEE_EXECUTE_V13 1
typedef struct {
    pd_Proposal_t proposal;
    pd_Compactu32_t length_bound;
} pd_technicalcommittee_execute_V13_t;

#define PD_CALL_TECHNICALCOMMITTEE_PROPOSE_V13 2
typedef struct {
    pd_Compactu32_t threshold;
    pd_Proposal_t proposal;
    pd_Compactu32_t length_bound;
} pd_technicalcommittee_propose_V13_t;

#define PD_CALL_TECHNICALCOMMITTEE_VOTE_V13 3
typedef struct {
    pd_Hash_t proposal;
    pd_Compactu32_t index;
    pd_bool_t approve;
} pd_technicalcommittee_vote_V13_t;

#define PD_CALL_TECHNICALCOMMITTEE_CLOSE_V13 4
typedef struct {
    pd_Hash_t proposal_hash;
    pd_Compactu32_t index;
    pd_Compactu64_t proposal_weight_bound;
    pd_Compactu32_t length_bound;
} pd_technicalcommittee_close_V13_t;

#define PD_CALL_TECHNICALCOMMITTEE_DISAPPROVE_PROPOSAL_V13 5
typedef struct {
    pd_Hash_t proposal_hash;
} pd_technicalcommittee_disapprove_proposal_V13_t;

#define PD_CALL_PHRAGMENELECTION_VOTE_V13 0
typedef struct {
    pd_VecAccountId_V13_t votes;
    pd_Compactu128_t amount;
} pd_phragmenelection_vote_V13_t;

#define PD_CALL_PHRAGMENELECTION_REMOVE_VOTER_V13 1
typedef struct {
} pd_phragmenelection_remove_voter_V13_t;

#define PD_CALL_PHRAGMENELECTION_SUBMIT_CANDIDACY_V13 2
typedef struct {
    pd_Compactu32_t candidate_count;
} pd_phragmenelection_submit_candidacy_V13_t;

#define PD_CALL_PHRAGMENELECTION_REMOVE_MEMBER_V13 4
typedef struct {
    pd_LookupasStaticLookupSource_V13_t who;
    pd_bool_t slash_bond;
    pd_bool_t rerun_election;
} pd_phragmenelection_remove_member_V13_t;

#define PD_CALL_PHRAGMENELECTION_CLEAN_DEFUNCT_VOTERS_V13 5
typedef struct {
    pd_u32_t num_voters;
    pd_u32_t num_defunct;
} pd_phragmenelection_clean_defunct_voters_V13_t;

#define PD_CALL_TECHNICALMEMBERSHIP_ADD_MEMBER_V13 0
typedef struct {
    pd_AccountId_V13_t who;
} pd_technicalmembership_add_member_V13_t;

#define PD_CALL_TECHNICALMEMBERSHIP_REMOVE_MEMBER_V13 1
typedef struct {
    pd_AccountId_V13_t who;
} pd_technicalmembership_remove_member_V13_t;

#define PD_CALL_TECHNICALMEMBERSHIP_SWAP_MEMBER_V13 2
typedef struct {
    pd_AccountId_V13_t remove;
    pd_AccountId_V13_t add;
} pd_technicalmembership_swap_member_V13_t;

#define PD_CALL_TECHNICALMEMBERSHIP_RESET_MEMBERS_V13 3
typedef struct {
    pd_VecAccountId_V13_t members;
} pd_technicalmembership_reset_members_V13_t;

#define PD_CALL_TECHNICALMEMBERSHIP_CHANGE_KEY_V13 4
typedef struct {
    pd_AccountId_V13_t new_;
} pd_technicalmembership_change_key_V13_t;

#define PD_CALL_TECHNICALMEMBERSHIP_SET_PRIME_V13 5
typedef struct {
    pd_AccountId_V13_t who;
} pd_technicalmembership_set_prime_V13_t;

#define PD_CALL_TECHNICALMEMBERSHIP_CLEAR_PRIME_V13 6
typedef struct {
} pd_technicalmembership_clear_prime_V13_t;

#define PD_CALL_TREASURY_PROPOSE_SPEND_V13 0
typedef struct {
    pd_CompactBalance_t amount;
    pd_LookupasStaticLookupSource_V13_t beneficiary;
} pd_treasury_propose_spend_V13_t;

#define PD_CALL_TREASURY_REJECT_PROPOSAL_V13 1
typedef struct {
    pd_Compactu32_t proposal_id;
} pd_treasury_reject_proposal_V13_t;

#define PD_CALL_TREASURY_APPROVE_PROPOSAL_V13 2
typedef struct {
    pd_Compactu32_t proposal_id;
} pd_treasury_approve_proposal_V13_t;

#define PD_CALL_TREASURY_SPEND_V13 3
typedef struct {
    pd_CompactBalance_t amount;
    pd_LookupasStaticLookupSource_V13_t beneficiary;
} pd_treasury_spend_V13_t;

#define PD_CALL_TREASURY_REMOVE_APPROVAL_V13 4
typedef struct {
    pd_Compactu32_t proposal_id;
} pd_treasury_remove_approval_V13_t;

#define PD_CALL_CLAIMS_CLAIM_V13 0
typedef struct {
    pd_AccountId_V13_t dest;
    pd_EcdsaSignature_V13_t ethereum_signature;
} pd_claims_claim_V13_t;

#define PD_CALL_CLAIMS_CLAIM_ATTEST_V13 2
typedef struct {
    pd_AccountId_V13_t dest;
    pd_EcdsaSignature_V13_t ethereum_signature;
    pd_Bytes_t statement;
} pd_claims_claim_attest_V13_t;

#define PD_CALL_CLAIMS_ATTEST_V13 3
typedef struct {
    pd_Bytes_t statement;
} pd_claims_attest_V13_t;

#define PD_CALL_CLAIMS_MOVE_CLAIM_V13 4
typedef struct {
    pd_EthereumAddress_V13_t old;
    pd_EthereumAddress_V13_t new_;
    pd_OptionAccountId_V13_t maybe_preclaim;
} pd_claims_move_claim_V13_t;

#define PD_CALL_VESTING_VEST_V13 0
typedef struct {
} pd_vesting_vest_V13_t;

#define PD_CALL_VESTING_VEST_OTHER_V13 1
typedef struct {
    pd_LookupasStaticLookupSource_V13_t target;
} pd_vesting_vest_other_V13_t;

#define PD_CALL_VESTING_VESTED_TRANSFER_V13 2
typedef struct {
    pd_LookupasStaticLookupSource_V13_t target;
    pd_VestingInfo_V13_t schedule;
} pd_vesting_vested_transfer_V13_t;

#define PD_CALL_VESTING_FORCE_VESTED_TRANSFER_V13 3
typedef struct {
    pd_LookupasStaticLookupSource_V13_t source;
    pd_LookupasStaticLookupSource_V13_t target;
    pd_VestingInfo_V13_t schedule;
} pd_vesting_force_vested_transfer_V13_t;

#define PD_CALL_VESTING_MERGE_SCHEDULES_V13 4
typedef struct {
    pd_u32_t schedule1_index;
    pd_u32_t schedule2_index;
} pd_vesting_merge_schedules_V13_t;

#define PD_CALL_IDENTITY_ADD_REGISTRAR_V13 0
typedef struct {
    pd_AccountId_V13_t account;
} pd_identity_add_registrar_V13_t;

#define PD_CALL_IDENTITY_CLEAR_IDENTITY_V13 3
typedef struct {
} pd_identity_clear_identity_V13_t;

#define PD_CALL_IDENTITY_REQUEST_JUDGEMENT_V13 4
typedef struct {
    pd_Compactu32_t reg_index;
    pd_Compactu128_t max_fee;
} pd_identity_request_judgement_V13_t;

#define PD_CALL_IDENTITY_CANCEL_REQUEST_V13 5
typedef struct {
    pd_RegistrarIndex_V13_t reg_index;
} pd_identity_cancel_request_V13_t;

#define PD_CALL_IDENTITY_SET_FEE_V13 6
typedef struct {
    pd_Compactu32_t index;
    pd_Compactu128_t fee;
} pd_identity_set_fee_V13_t;

#define PD_CALL_IDENTITY_SET_ACCOUNT_ID_V13 7
typedef struct {
    pd_Compactu32_t index;
    pd_AccountId_V13_t new_;
} pd_identity_set_account_id_V13_t;

#define PD_CALL_IDENTITY_KILL_IDENTITY_V13 10
typedef struct {
    pd_LookupasStaticLookupSource_V13_t target;
} pd_identity_kill_identity_V13_t;

#define PD_CALL_IDENTITY_REMOVE_SUB_V13 13
typedef struct {
    pd_LookupasStaticLookupSource_V13_t sub;
} pd_identity_remove_sub_V13_t;

#define PD_CALL_IDENTITY_QUIT_SUB_V13 14
typedef struct {
} pd_identity_quit_sub_V13_t;

#define PD_CALL_PROXY_ADD_PROXY_V13 1
typedef struct {
    pd_AccountId_V13_t delegate;
    pd_ProxyType_V13_t proxy_type;
    pd_BlockNumber_t delay;
} pd_proxy_add_proxy_V13_t;

#define PD_CALL_PROXY_REMOVE_PROXY_V13 2
typedef struct {
    pd_AccountId_V13_t delegate;
    pd_ProxyType_V13_t proxy_type;
    pd_BlockNumber_t delay;
} pd_proxy_remove_proxy_V13_t;

#define PD_CALL_PROXY_REMOVE_PROXIES_V13 3
typedef struct {
} pd_proxy_remove_proxies_V13_t;

#define PD_CALL_PROXY_ANONYMOUS_V13 4
typedef struct {
    pd_ProxyType_V13_t proxy_type;
    pd_BlockNumber_t delay;
    pd_u16_t index;
} pd_proxy_anonymous_V13_t;

#define PD_CALL_PROXY_KILL_ANONYMOUS_V13 5
typedef struct {
    pd_AccountId_V13_t spawner;
    pd_ProxyType_V13_t proxy_type;
    pd_u16_t index;
    pd_Compactu32_t height;
    pd_Compactu32_t ext_index;
} pd_proxy_kill_anonymous_V13_t;

#define PD_CALL_PROXY_PROXY_ANNOUNCED_V13 9
typedef struct {
    pd_AccountId_V13_t delegate;
    pd_AccountId_V13_t real;
    pd_OptionProxyType_V13_t force_proxy_type;
    pd_Call_t call;
} pd_proxy_proxy_announced_V13_t;

#define PD_CALL_BOUNTIES_PROPOSE_BOUNTY_V13 0
typedef struct {
    pd_CompactBalance_t amount;
    pd_Bytes_t description;
} pd_bounties_propose_bounty_V13_t;

#define PD_CALL_BOUNTIES_APPROVE_BOUNTY_V13 1
typedef struct {
    pd_Compactu32_t bounty_id;
} pd_bounties_approve_bounty_V13_t;

#define PD_CALL_BOUNTIES_PROPOSE_CURATOR_V13 2
typedef struct {
    pd_Compactu32_t bounty_id;
    pd_LookupasStaticLookupSource_V13_t curator;
    pd_CompactBalance_t fee;
} pd_bounties_propose_curator_V13_t;

#define PD_CALL_BOUNTIES_UNASSIGN_CURATOR_V13 3
typedef struct {
    pd_Compactu32_t bounty_id;
} pd_bounties_unassign_curator_V13_t;

#define PD_CALL_BOUNTIES_ACCEPT_CURATOR_V13 4
typedef struct {
    pd_Compactu32_t bounty_id;
} pd_bounties_accept_curator_V13_t;

#define PD_CALL_BOUNTIES_AWARD_BOUNTY_V13 5
typedef struct {
    pd_Compactu32_t bounty_id;
    pd_LookupasStaticLookupSource_V13_t beneficiary;
} pd_bounties_award_bounty_V13_t;

#define PD_CALL_BOUNTIES_CLAIM_BOUNTY_V13 6
typedef struct {
    pd_Compactu32_t bounty_id;
} pd_bounties_claim_bounty_V13_t;

#define PD_CALL_BOUNTIES_CLOSE_BOUNTY_V13 7
typedef struct {
    pd_Compactu32_t bounty_id;
} pd_bounties_close_bounty_V13_t;

#define PD_CALL_BOUNTIES_EXTEND_BOUNTY_EXPIRY_V13 8
typedef struct {
    pd_Compactu32_t bounty_id;
    pd_Bytes_t remark;
} pd_bounties_extend_bounty_expiry_V13_t;

#define PD_CALL_CHILDBOUNTIES_ADD_CHILD_BOUNTY_V13 0
typedef struct {
    pd_Compactu32_t parent_bounty_id;
    pd_CompactBalance_t amount;
    pd_Vecu8_t description;
} pd_childbounties_add_child_bounty_V13_t;

#define PD_CALL_CHILDBOUNTIES_PROPOSE_CURATOR_V13 1
typedef struct {
    pd_Compactu32_t parent_bounty_id;
    pd_Compactu32_t child_bounty_id;
    pd_LookupasStaticLookupSource_V13_t curator;
    pd_CompactBalance_t fee;
} pd_childbounties_propose_curator_V13_t;

#define PD_CALL_CHILDBOUNTIES_ACCEPT_CURATOR_V13 2
typedef struct {
    pd_Compactu32_t parent_bounty_id;
    pd_Compactu32_t child_bounty_id;
} pd_childbounties_accept_curator_V13_t;

#define PD_CALL_CHILDBOUNTIES_UNASSIGN_CURATOR_V13 3
typedef struct {
    pd_Compactu32_t parent_bounty_id;
    pd_Compactu32_t child_bounty_id;
} pd_childbounties_unassign_curator_V13_t;

#define PD_CALL_CHILDBOUNTIES_AWARD_CHILD_BOUNTY_V13 4
typedef struct {
    pd_Compactu32_t parent_bounty_id;
    pd_Compactu32_t child_bounty_id;
    pd_LookupasStaticLookupSource_V13_t beneficiary;
} pd_childbounties_award_child_bounty_V13_t;

#define PD_CALL_CHILDBOUNTIES_CLAIM_CHILD_BOUNTY_V13 5
typedef struct {
    pd_Compactu32_t parent_bounty_id;
    pd_Compactu32_t child_bounty_id;
} pd_childbounties_claim_child_bounty_V13_t;

#define PD_CALL_CHILDBOUNTIES_CLOSE_CHILD_BOUNTY_V13 6
typedef struct {
    pd_Compactu32_t parent_bounty_id;
    pd_Compactu32_t child_bounty_id;
} pd_childbounties_close_child_bounty_V13_t;

#define PD_CALL_TIPS_REPORT_AWESOME_V13 0
typedef struct {
    pd_Bytes_t reason;
    pd_AccountId_V13_t who;
} pd_tips_report_awesome_V13_t;

#define PD_CALL_TIPS_RETRACT_TIP_V13 1
typedef struct {
    pd_Hash_t hash;
} pd_tips_retract_tip_V13_t;

#define PD_CALL_TIPS_TIP_NEW_V13 2
typedef struct {
    pd_Bytes_t reason;
    pd_AccountId_V13_t who;
    pd_Compactu128_t tip_value;
} pd_tips_tip_new_V13_t;

#define PD_CALL_TIPS_TIP_V13 3
typedef struct {
    pd_Hash_t hash;
    pd_Compactu128_t tip_value;
} pd_tips_tip_V13_t;

#define PD_CALL_TIPS_CLOSE_TIP_V13 4
typedef struct {
    pd_Hash_t hash;
} pd_tips_close_tip_V13_t;

#define PD_CALL_TIPS_SLASH_TIP_V13 5
typedef struct {
    pd_Hash_t hash;
} pd_tips_slash_tip_V13_t;

#define PD_CALL_ELECTIONPROVIDERMULTIPHASE_GOVERNANCE_FALLBACK_V13 4
typedef struct {
    pd_Optionu32_t maybe_max_voters;
    pd_Optionu32_t maybe_max_targets;
} pd_electionprovidermultiphase_governance_fallback_V13_t;

#define PD_CALL_VOTERLIST_REBAG_V13 0
typedef struct {
    pd_AccountId_V13_t dislocated;
} pd_voterlist_rebag_V13_t;

#define PD_CALL_VOTERLIST_PUT_IN_FRONT_OF_V13 1
typedef struct {
    pd_AccountId_V13_t lighter;
} pd_voterlist_put_in_front_of_V13_t;

#define PD_CALL_NOMINATIONPOOLS_JOIN_V13 0
typedef struct {
    pd_Compactu128_t amount;
    pd_PoolId_V13_t pool_id;
} pd_nominationpools_join_V13_t;

#define PD_CALL_NOMINATIONPOOLS_BOND_EXTRA_V13 1
typedef struct {
    pd_BondExtraBalanceOfT_V13_t extra;
} pd_nominationpools_bond_extra_V13_t;

#define PD_CALL_NOMINATIONPOOLS_CLAIM_PAYOUT_V13 2
typedef struct {
} pd_nominationpools_claim_payout_V13_t;

#define PD_CALL_NOMINATIONPOOLS_UNBOND_V13 3
typedef struct {
    pd_AccountId_V13_t member_account;
    pd_Compactu128_t unbonding_points;
} pd_nominationpools_unbond_V13_t;

#define PD_CALL_NOMINATIONPOOLS_POOL_WITHDRAW_UNBONDED_V13 4
typedef struct {
    pd_PoolId_V13_t pool_id;
    pd_u32_t num_slashing_spans;
} pd_nominationpools_pool_withdraw_unbonded_V13_t;

#define PD_CALL_NOMINATIONPOOLS_WITHDRAW_UNBONDED_V13 5
typedef struct {
    pd_AccountId_V13_t member_account;
    pd_u32_t num_slashing_spans;
} pd_nominationpools_withdraw_unbonded_V13_t;

#define PD_CALL_NOMINATIONPOOLS_CREATE_V13 6
typedef struct {
    pd_Compactu128_t amount;
    pd_AccountId_V13_t root;
    pd_AccountId_V13_t nominator;
    pd_AccountId_V13_t state_toggler;
} pd_nominationpools_create_V13_t;

#define PD_CALL_NOMINATIONPOOLS_NOMINATE_V13 7
typedef struct {
    pd_PoolId_V13_t pool_id;
    pd_VecAccountId_V13_t validators;
} pd_nominationpools_nominate_V13_t;

#define PD_CALL_NOMINATIONPOOLS_SET_STATE_V13 8
typedef struct {
    pd_PoolId_V13_t pool_id;
    pd_PoolState_V13_t state;
} pd_nominationpools_set_state_V13_t;

#define PD_CALL_NOMINATIONPOOLS_SET_METADATA_V13 9
typedef struct {
    pd_PoolId_V13_t pool_id;
    pd_Vecu8_t metadata;
} pd_nominationpools_set_metadata_V13_t;

#define PD_CALL_NOMINATIONPOOLS_SET_CONFIGS_V13 10
typedef struct {
    pd_ConfigOpBalanceOfT_V13_t min_join_bond;
    pd_ConfigOpBalanceOfT_V13_t min_create_bond;
    pd_ConfigOpu32_V13_t max_pools;
    pd_ConfigOpu32_V13_t max_members;
    pd_ConfigOpu32_V13_t max_members_per_pool;
} pd_nominationpools_set_configs_V13_t;

#define PD_CALL_NOMINATIONPOOLS_UPDATE_ROLES_V13 11
typedef struct {
    pd_PoolId_V13_t pool_id;
    pd_ConfigOpAccountId_V13_t new_root;
    pd_ConfigOpAccountId_V13_t new_nominator;
    pd_ConfigOpAccountId_V13_t new_state_toggler;
} pd_nominationpools_update_roles_V13_t;

#define PD_CALL_NOMINATIONPOOLS_CHILL_V13 12
typedef struct {
    pd_PoolId_V13_t pool_id;
} pd_nominationpools_chill_V13_t;

#define PD_CALL_CONFIGURATION_SET_VALIDATION_UPGRADE_COOLDOWN_V13 0
typedef struct {
    pd_BlockNumber_t new_;
} pd_configuration_set_validation_upgrade_cooldown_V13_t;

#define PD_CALL_CONFIGURATION_SET_VALIDATION_UPGRADE_DELAY_V13 1
typedef struct {
    pd_BlockNumber_t new_;
} pd_configuration_set_validation_upgrade_delay_V13_t;

#define PD_CALL_CONFIGURATION_SET_CODE_RETENTION_PERIOD_V13 2
typedef struct {
    pd_BlockNumber_t new_;
} pd_configuration_set_code_retention_period_V13_t;

#define PD_CALL_CONFIGURATION_SET_MAX_CODE_SIZE_V13 3
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_max_code_size_V13_t;

#define PD_CALL_CONFIGURATION_SET_MAX_POV_SIZE_V13 4
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_max_pov_size_V13_t;

#define PD_CALL_CONFIGURATION_SET_MAX_HEAD_DATA_SIZE_V13 5
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_max_head_data_size_V13_t;

#define PD_CALL_CONFIGURATION_SET_PARATHREAD_CORES_V13 6
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_parathread_cores_V13_t;

#define PD_CALL_CONFIGURATION_SET_PARATHREAD_RETRIES_V13 7
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_parathread_retries_V13_t;

#define PD_CALL_CONFIGURATION_SET_GROUP_ROTATION_FREQUENCY_V13 8
typedef struct {
    pd_BlockNumber_t new_;
} pd_configuration_set_group_rotation_frequency_V13_t;

#define PD_CALL_CONFIGURATION_SET_CHAIN_AVAILABILITY_PERIOD_V13 9
typedef struct {
    pd_BlockNumber_t new_;
} pd_configuration_set_chain_availability_period_V13_t;

#define PD_CALL_CONFIGURATION_SET_THREAD_AVAILABILITY_PERIOD_V13 10
typedef struct {
    pd_BlockNumber_t new_;
} pd_configuration_set_thread_availability_period_V13_t;

#define PD_CALL_CONFIGURATION_SET_SCHEDULING_LOOKAHEAD_V13 11
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_scheduling_lookahead_V13_t;

#define PD_CALL_CONFIGURATION_SET_MAX_VALIDATORS_PER_CORE_V13 12
typedef struct {
    pd_Optionu32_t new_;
} pd_configuration_set_max_validators_per_core_V13_t;

#define PD_CALL_CONFIGURATION_SET_MAX_VALIDATORS_V13 13
typedef struct {
    pd_Optionu32_t new_;
} pd_configuration_set_max_validators_V13_t;

#define PD_CALL_CONFIGURATION_SET_DISPUTE_POST_CONCLUSION_ACCEPTANCE_PERIOD_V13 15
typedef struct {
    pd_BlockNumber_t new_;
} pd_configuration_set_dispute_post_conclusion_acceptance_period_V13_t;

#define PD_CALL_CONFIGURATION_SET_DISPUTE_MAX_SPAM_SLOTS_V13 16
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_dispute_max_spam_slots_V13_t;

#define PD_CALL_CONFIGURATION_SET_DISPUTE_CONCLUSION_BY_TIME_OUT_PERIOD_V13 17
typedef struct {
    pd_BlockNumber_t new_;
} pd_configuration_set_dispute_conclusion_by_time_out_period_V13_t;

#define PD_CALL_CONFIGURATION_SET_NO_SHOW_SLOTS_V13 18
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_no_show_slots_V13_t;

#define PD_CALL_CONFIGURATION_SET_N_DELAY_TRANCHES_V13 19
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_n_delay_tranches_V13_t;

#define PD_CALL_CONFIGURATION_SET_ZEROTH_DELAY_TRANCHE_WIDTH_V13 20
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_zeroth_delay_tranche_width_V13_t;

#define PD_CALL_CONFIGURATION_SET_NEEDED_APPROVALS_V13 21
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_needed_approvals_V13_t;

#define PD_CALL_CONFIGURATION_SET_RELAY_VRF_MODULO_SAMPLES_V13 22
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_relay_vrf_modulo_samples_V13_t;

#define PD_CALL_CONFIGURATION_SET_MAX_UPWARD_QUEUE_COUNT_V13 23
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_max_upward_queue_count_V13_t;

#define PD_CALL_CONFIGURATION_SET_MAX_UPWARD_QUEUE_SIZE_V13 24
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_max_upward_queue_size_V13_t;

#define PD_CALL_CONFIGURATION_SET_MAX_DOWNWARD_MESSAGE_SIZE_V13 25
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_max_downward_message_size_V13_t;

#define PD_CALL_CONFIGURATION_SET_UMP_SERVICE_TOTAL_WEIGHT_V13 26
typedef struct {
    pd_Weight_V13_t new_;
} pd_configuration_set_ump_service_total_weight_V13_t;

#define PD_CALL_CONFIGURATION_SET_MAX_UPWARD_MESSAGE_SIZE_V13 27
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_max_upward_message_size_V13_t;

#define PD_CALL_CONFIGURATION_SET_MAX_UPWARD_MESSAGE_NUM_PER_CANDIDATE_V13 28
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_max_upward_message_num_per_candidate_V13_t;

#define PD_CALL_CONFIGURATION_SET_HRMP_OPEN_REQUEST_TTL_V13 29
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_hrmp_open_request_ttl_V13_t;

#define PD_CALL_CONFIGURATION_SET_HRMP_SENDER_DEPOSIT_V13 30
typedef struct {
    pd_Balance_t new_;
} pd_configuration_set_hrmp_sender_deposit_V13_t;

#define PD_CALL_CONFIGURATION_SET_HRMP_RECIPIENT_DEPOSIT_V13 31
typedef struct {
    pd_Balance_t new_;
} pd_configuration_set_hrmp_recipient_deposit_V13_t;

#define PD_CALL_CONFIGURATION_SET_HRMP_CHANNEL_MAX_CAPACITY_V13 32
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_hrmp_channel_max_capacity_V13_t;

#define PD_CALL_CONFIGURATION_SET_HRMP_CHANNEL_MAX_TOTAL_SIZE_V13 33
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_hrmp_channel_max_total_size_V13_t;

#define PD_CALL_CONFIGURATION_SET_HRMP_MAX_PARACHAIN_INBOUND_CHANNELS_V13 34
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_hrmp_max_parachain_inbound_channels_V13_t;

#define PD_CALL_CONFIGURATION_SET_HRMP_MAX_PARATHREAD_INBOUND_CHANNELS_V13 35
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_hrmp_max_parathread_inbound_channels_V13_t;

#define PD_CALL_CONFIGURATION_SET_HRMP_CHANNEL_MAX_MESSAGE_SIZE_V13 36
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_hrmp_channel_max_message_size_V13_t;

#define PD_CALL_CONFIGURATION_SET_HRMP_MAX_PARACHAIN_OUTBOUND_CHANNELS_V13 37
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_hrmp_max_parachain_outbound_channels_V13_t;

#define PD_CALL_CONFIGURATION_SET_HRMP_MAX_PARATHREAD_OUTBOUND_CHANNELS_V13 38
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_hrmp_max_parathread_outbound_channels_V13_t;

#define PD_CALL_CONFIGURATION_SET_HRMP_MAX_MESSAGE_NUM_PER_CANDIDATE_V13 39
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_hrmp_max_message_num_per_candidate_V13_t;

#define PD_CALL_CONFIGURATION_SET_UMP_MAX_INDIVIDUAL_WEIGHT_V13 40
typedef struct {
    pd_Weight_V13_t new_;
} pd_configuration_set_ump_max_individual_weight_V13_t;

#define PD_CALL_CONFIGURATION_SET_PVF_CHECKING_ENABLED_V13 41
typedef struct {
    pd_bool_t new_;
} pd_configuration_set_pvf_checking_enabled_V13_t;

#define PD_CALL_CONFIGURATION_SET_PVF_VOTING_TTL_V13 42
typedef struct {
    pd_SessionIndex_V13_t new_;
} pd_configuration_set_pvf_voting_ttl_V13_t;

#define PD_CALL_CONFIGURATION_SET_MINIMUM_VALIDATION_UPGRADE_DELAY_V13 43
typedef struct {
    pd_BlockNumber_t new_;
} pd_configuration_set_minimum_validation_upgrade_delay_V13_t;

#define PD_CALL_CONFIGURATION_SET_BYPASS_CONSISTENCY_CHECK_V13 44
typedef struct {
    pd_bool_t new_;
} pd_configuration_set_bypass_consistency_check_V13_t;

#define PD_CALL_INITIALIZER_FORCE_APPROVE_V13 0
typedef struct {
    pd_BlockNumber_t up_to;
} pd_initializer_force_approve_V13_t;

#define PD_CALL_UMP_SERVICE_OVERWEIGHT_V13 0
typedef struct {
    pd_OverweightIndex_V13_t index;
    pd_Weight_V13_t weight_limit;
} pd_ump_service_overweight_V13_t;

#define PD_CALL_HRMP_FORCE_PROCESS_HRMP_OPEN_V13 4
typedef struct {
    pd_u32_t channels;
} pd_hrmp_force_process_hrmp_open_V13_t;

#define PD_CALL_HRMP_FORCE_PROCESS_HRMP_CLOSE_V13 5
typedef struct {
    pd_u32_t channels;
} pd_hrmp_force_process_hrmp_close_V13_t;

#define PD_CALL_PARASDISPUTES_FORCE_UNFREEZE_V13 0
typedef struct {
} pd_parasdisputes_force_unfreeze_V13_t;

#define PD_CALL_REGISTRAR_RESERVE_V13 5
typedef struct {
} pd_registrar_reserve_V13_t;

#define PD_CALL_AUCTIONS_NEW_AUCTION_V13 0
typedef struct {
    pd_Compactu32_t duration;
    pd_Compactu32_t lease_period_index;
} pd_auctions_new_auction_V13_t;

#define PD_CALL_AUCTIONS_BID_V13 1
typedef struct {
    pd_Compactu32_t para;
    pd_Compactu32_t auction_index;
    pd_Compactu32_t first_slot;
    pd_Compactu32_t last_slot;
    pd_CompactBalance_t amount;
} pd_auctions_bid_V13_t;

#define PD_CALL_AUCTIONS_CANCEL_AUCTION_V13 2
typedef struct {
} pd_auctions_cancel_auction_V13_t;

#endif

typedef union {
    pd_balances_transfer_all_V13_t balances_transfer_all_V13;
    pd_staking_bond_V13_t staking_bond_V13;
    pd_staking_bond_extra_V13_t staking_bond_extra_V13;
    pd_staking_unbond_V13_t staking_unbond_V13;
    pd_staking_withdraw_unbonded_V13_t staking_withdraw_unbonded_V13;
    pd_staking_validate_V13_t staking_validate_V13;
    pd_staking_nominate_V13_t staking_nominate_V13;
    pd_staking_chill_V13_t staking_chill_V13;
    pd_staking_set_payee_V13_t staking_set_payee_V13;
    pd_staking_set_controller_V13_t staking_set_controller_V13;
    pd_staking_payout_stakers_V13_t staking_payout_stakers_V13;
    pd_staking_rebond_V13_t staking_rebond_V13;
    pd_session_set_keys_V13_t session_set_keys_V13;
    pd_session_purge_keys_V13_t session_purge_keys_V13;
    pd_utility_batch_V13_t utility_batch_V13;
    pd_utility_batch_all_V13_t utility_batch_all_V13;
    pd_utility_force_batch_V13_t utility_force_batch_V13;
    pd_crowdloan_create_V13_t crowdloan_create_V13;
    pd_crowdloan_contribute_V13_t crowdloan_contribute_V13;
    pd_crowdloan_withdraw_V13_t crowdloan_withdraw_V13;
    pd_crowdloan_refund_V13_t crowdloan_refund_V13;
    pd_crowdloan_dissolve_V13_t crowdloan_dissolve_V13;
    pd_crowdloan_edit_V13_t crowdloan_edit_V13;
    pd_crowdloan_add_memo_V13_t crowdloan_add_memo_V13;
    pd_crowdloan_poke_V13_t crowdloan_poke_V13;
    pd_crowdloan_contribute_all_V13_t crowdloan_contribute_all_V13;
#ifdef SUBSTRATE_PARSER_FULL
    pd_preimage_note_preimage_V13_t preimage_note_preimage_V13;
    pd_preimage_unnote_preimage_V13_t preimage_unnote_preimage_V13;
    pd_preimage_request_preimage_V13_t preimage_request_preimage_V13;
    pd_preimage_unrequest_preimage_V13_t preimage_unrequest_preimage_V13;
    pd_timestamp_set_V13_t timestamp_set_V13;
    pd_indices_claim_V13_t indices_claim_V13;
    pd_indices_transfer_V13_t indices_transfer_V13;
    pd_indices_free_V13_t indices_free_V13;
    pd_indices_force_transfer_V13_t indices_force_transfer_V13;
    pd_indices_freeze_V13_t indices_freeze_V13;
    pd_balances_force_unreserve_V13_t balances_force_unreserve_V13;
    pd_staking_set_validator_count_V13_t staking_set_validator_count_V13;
    pd_staking_increase_validator_count_V13_t staking_increase_validator_count_V13;
    pd_staking_force_no_eras_V13_t staking_force_no_eras_V13;
    pd_staking_force_new_era_V13_t staking_force_new_era_V13;
    pd_staking_set_invulnerables_V13_t staking_set_invulnerables_V13;
    pd_staking_force_unstake_V13_t staking_force_unstake_V13;
    pd_staking_force_new_era_always_V13_t staking_force_new_era_always_V13;
    pd_staking_cancel_deferred_slash_V13_t staking_cancel_deferred_slash_V13;
    pd_staking_set_history_depth_V13_t staking_set_history_depth_V13;
    pd_staking_reap_stash_V13_t staking_reap_stash_V13;
    pd_staking_kick_V13_t staking_kick_V13;
    pd_staking_chill_other_V13_t staking_chill_other_V13;
    pd_staking_force_apply_min_commission_V13_t staking_force_apply_min_commission_V13;
    pd_grandpa_note_stalled_V13_t grandpa_note_stalled_V13;
    pd_democracy_note_preimage_V13_t democracy_note_preimage_V13;
    pd_democracy_note_preimage_operational_V13_t democracy_note_preimage_operational_V13;
    pd_democracy_note_imminent_preimage_V13_t democracy_note_imminent_preimage_V13;
    pd_democracy_note_imminent_preimage_operational_V13_t democracy_note_imminent_preimage_operational_V13;
    pd_council_set_members_V13_t council_set_members_V13;
    pd_council_execute_V13_t council_execute_V13;
    pd_council_propose_V13_t council_propose_V13;
    pd_council_vote_V13_t council_vote_V13;
    pd_council_close_V13_t council_close_V13;
    pd_council_disapprove_proposal_V13_t council_disapprove_proposal_V13;
    pd_technicalcommittee_set_members_V13_t technicalcommittee_set_members_V13;
    pd_technicalcommittee_execute_V13_t technicalcommittee_execute_V13;
    pd_technicalcommittee_propose_V13_t technicalcommittee_propose_V13;
    pd_technicalcommittee_vote_V13_t technicalcommittee_vote_V13;
    pd_technicalcommittee_close_V13_t technicalcommittee_close_V13;
    pd_technicalcommittee_disapprove_proposal_V13_t technicalcommittee_disapprove_proposal_V13;
    pd_phragmenelection_vote_V13_t phragmenelection_vote_V13;
    pd_phragmenelection_remove_voter_V13_t phragmenelection_remove_voter_V13;
    pd_phragmenelection_submit_candidacy_V13_t phragmenelection_submit_candidacy_V13;
    pd_phragmenelection_remove_member_V13_t phragmenelection_remove_member_V13;
    pd_phragmenelection_clean_defunct_voters_V13_t phragmenelection_clean_defunct_voters_V13;
    pd_technicalmembership_add_member_V13_t technicalmembership_add_member_V13;
    pd_technicalmembership_remove_member_V13_t technicalmembership_remove_member_V13;
    pd_technicalmembership_swap_member_V13_t technicalmembership_swap_member_V13;
    pd_technicalmembership_reset_members_V13_t technicalmembership_reset_members_V13;
    pd_technicalmembership_change_key_V13_t technicalmembership_change_key_V13;
    pd_technicalmembership_set_prime_V13_t technicalmembership_set_prime_V13;
    pd_technicalmembership_clear_prime_V13_t technicalmembership_clear_prime_V13;
    pd_treasury_propose_spend_V13_t treasury_propose_spend_V13;
    pd_treasury_reject_proposal_V13_t treasury_reject_proposal_V13;
    pd_treasury_approve_proposal_V13_t treasury_approve_proposal_V13;
    pd_treasury_spend_V13_t treasury_spend_V13;
    pd_treasury_remove_approval_V13_t treasury_remove_approval_V13;
    pd_claims_claim_V13_t claims_claim_V13;
    pd_claims_claim_attest_V13_t claims_claim_attest_V13;
    pd_claims_attest_V13_t claims_attest_V13;
    pd_claims_move_claim_V13_t claims_move_claim_V13;
    pd_vesting_vest_V13_t vesting_vest_V13;
    pd_vesting_vest_other_V13_t vesting_vest_other_V13;
    pd_vesting_vested_transfer_V13_t vesting_vested_transfer_V13;
    pd_vesting_force_vested_transfer_V13_t vesting_force_vested_transfer_V13;
    pd_vesting_merge_schedules_V13_t vesting_merge_schedules_V13;
    pd_identity_add_registrar_V13_t identity_add_registrar_V13;
    pd_identity_clear_identity_V13_t identity_clear_identity_V13;
    pd_identity_request_judgement_V13_t identity_request_judgement_V13;
    pd_identity_cancel_request_V13_t identity_cancel_request_V13;
    pd_identity_set_fee_V13_t identity_set_fee_V13;
    pd_identity_set_account_id_V13_t identity_set_account_id_V13;
    pd_identity_kill_identity_V13_t identity_kill_identity_V13;
    pd_identity_remove_sub_V13_t identity_remove_sub_V13;
    pd_identity_quit_sub_V13_t identity_quit_sub_V13;
    pd_proxy_add_proxy_V13_t proxy_add_proxy_V13;
    pd_proxy_remove_proxy_V13_t proxy_remove_proxy_V13;
    pd_proxy_remove_proxies_V13_t proxy_remove_proxies_V13;
    pd_proxy_anonymous_V13_t proxy_anonymous_V13;
    pd_proxy_kill_anonymous_V13_t proxy_kill_anonymous_V13;
    pd_proxy_proxy_announced_V13_t proxy_proxy_announced_V13;
    pd_bounties_propose_bounty_V13_t bounties_propose_bounty_V13;
    pd_bounties_approve_bounty_V13_t bounties_approve_bounty_V13;
    pd_bounties_propose_curator_V13_t bounties_propose_curator_V13;
    pd_bounties_unassign_curator_V13_t bounties_unassign_curator_V13;
    pd_bounties_accept_curator_V13_t bounties_accept_curator_V13;
    pd_bounties_award_bounty_V13_t bounties_award_bounty_V13;
    pd_bounties_claim_bounty_V13_t bounties_claim_bounty_V13;
    pd_bounties_close_bounty_V13_t bounties_close_bounty_V13;
    pd_bounties_extend_bounty_expiry_V13_t bounties_extend_bounty_expiry_V13;
    pd_childbounties_add_child_bounty_V13_t childbounties_add_child_bounty_V13;
    pd_childbounties_propose_curator_V13_t childbounties_propose_curator_V13;
    pd_childbounties_accept_curator_V13_t childbounties_accept_curator_V13;
    pd_childbounties_unassign_curator_V13_t childbounties_unassign_curator_V13;
    pd_childbounties_award_child_bounty_V13_t childbounties_award_child_bounty_V13;
    pd_childbounties_claim_child_bounty_V13_t childbounties_claim_child_bounty_V13;
    pd_childbounties_close_child_bounty_V13_t childbounties_close_child_bounty_V13;
    pd_tips_report_awesome_V13_t tips_report_awesome_V13;
    pd_tips_retract_tip_V13_t tips_retract_tip_V13;
    pd_tips_tip_new_V13_t tips_tip_new_V13;
    pd_tips_tip_V13_t tips_tip_V13;
    pd_tips_close_tip_V13_t tips_close_tip_V13;
    pd_tips_slash_tip_V13_t tips_slash_tip_V13;
    pd_electionprovidermultiphase_governance_fallback_V13_t electionprovidermultiphase_governance_fallback_V13;
    pd_voterlist_rebag_V13_t voterlist_rebag_V13;
    pd_voterlist_put_in_front_of_V13_t voterlist_put_in_front_of_V13;
    pd_nominationpools_join_V13_t nominationpools_join_V13;
    pd_nominationpools_bond_extra_V13_t nominationpools_bond_extra_V13;
    pd_nominationpools_claim_payout_V13_t nominationpools_claim_payout_V13;
    pd_nominationpools_unbond_V13_t nominationpools_unbond_V13;
    pd_nominationpools_pool_withdraw_unbonded_V13_t nominationpools_pool_withdraw_unbonded_V13;
    pd_nominationpools_withdraw_unbonded_V13_t nominationpools_withdraw_unbonded_V13;
    pd_nominationpools_create_V13_t nominationpools_create_V13;
    pd_nominationpools_nominate_V13_t nominationpools_nominate_V13;
    pd_nominationpools_set_state_V13_t nominationpools_set_state_V13;
    pd_nominationpools_set_metadata_V13_t nominationpools_set_metadata_V13;
    pd_nominationpools_set_configs_V13_t nominationpools_set_configs_V13;
    pd_nominationpools_update_roles_V13_t nominationpools_update_roles_V13;
    pd_nominationpools_chill_V13_t nominationpools_chill_V13;
    pd_configuration_set_validation_upgrade_cooldown_V13_t configuration_set_validation_upgrade_cooldown_V13;
    pd_configuration_set_validation_upgrade_delay_V13_t configuration_set_validation_upgrade_delay_V13;
    pd_configuration_set_code_retention_period_V13_t configuration_set_code_retention_period_V13;
    pd_configuration_set_max_code_size_V13_t configuration_set_max_code_size_V13;
    pd_configuration_set_max_pov_size_V13_t configuration_set_max_pov_size_V13;
    pd_configuration_set_max_head_data_size_V13_t configuration_set_max_head_data_size_V13;
    pd_configuration_set_parathread_cores_V13_t configuration_set_parathread_cores_V13;
    pd_configuration_set_parathread_retries_V13_t configuration_set_parathread_retries_V13;
    pd_configuration_set_group_rotation_frequency_V13_t configuration_set_group_rotation_frequency_V13;
    pd_configuration_set_chain_availability_period_V13_t configuration_set_chain_availability_period_V13;
    pd_configuration_set_thread_availability_period_V13_t configuration_set_thread_availability_period_V13;
    pd_configuration_set_scheduling_lookahead_V13_t configuration_set_scheduling_lookahead_V13;
    pd_configuration_set_max_validators_per_core_V13_t configuration_set_max_validators_per_core_V13;
    pd_configuration_set_max_validators_V13_t configuration_set_max_validators_V13;
    pd_configuration_set_dispute_post_conclusion_acceptance_period_V13_t configuration_set_dispute_post_conclusion_acceptance_period_V13;
    pd_configuration_set_dispute_max_spam_slots_V13_t configuration_set_dispute_max_spam_slots_V13;
    pd_configuration_set_dispute_conclusion_by_time_out_period_V13_t configuration_set_dispute_conclusion_by_time_out_period_V13;
    pd_configuration_set_no_show_slots_V13_t configuration_set_no_show_slots_V13;
    pd_configuration_set_n_delay_tranches_V13_t configuration_set_n_delay_tranches_V13;
    pd_configuration_set_zeroth_delay_tranche_width_V13_t configuration_set_zeroth_delay_tranche_width_V13;
    pd_configuration_set_needed_approvals_V13_t configuration_set_needed_approvals_V13;
    pd_configuration_set_relay_vrf_modulo_samples_V13_t configuration_set_relay_vrf_modulo_samples_V13;
    pd_configuration_set_max_upward_queue_count_V13_t configuration_set_max_upward_queue_count_V13;
    pd_configuration_set_max_upward_queue_size_V13_t configuration_set_max_upward_queue_size_V13;
    pd_configuration_set_max_downward_message_size_V13_t configuration_set_max_downward_message_size_V13;
    pd_configuration_set_ump_service_total_weight_V13_t configuration_set_ump_service_total_weight_V13;
    pd_configuration_set_max_upward_message_size_V13_t configuration_set_max_upward_message_size_V13;
    pd_configuration_set_max_upward_message_num_per_candidate_V13_t configuration_set_max_upward_message_num_per_candidate_V13;
    pd_configuration_set_hrmp_open_request_ttl_V13_t configuration_set_hrmp_open_request_ttl_V13;
    pd_configuration_set_hrmp_sender_deposit_V13_t configuration_set_hrmp_sender_deposit_V13;
    pd_configuration_set_hrmp_recipient_deposit_V13_t configuration_set_hrmp_recipient_deposit_V13;
    pd_configuration_set_hrmp_channel_max_capacity_V13_t configuration_set_hrmp_channel_max_capacity_V13;
    pd_configuration_set_hrmp_channel_max_total_size_V13_t configuration_set_hrmp_channel_max_total_size_V13;
    pd_configuration_set_hrmp_max_parachain_inbound_channels_V13_t configuration_set_hrmp_max_parachain_inbound_channels_V13;
    pd_configuration_set_hrmp_max_parathread_inbound_channels_V13_t configuration_set_hrmp_max_parathread_inbound_channels_V13;
    pd_configuration_set_hrmp_channel_max_message_size_V13_t configuration_set_hrmp_channel_max_message_size_V13;
    pd_configuration_set_hrmp_max_parachain_outbound_channels_V13_t configuration_set_hrmp_max_parachain_outbound_channels_V13;
    pd_configuration_set_hrmp_max_parathread_outbound_channels_V13_t configuration_set_hrmp_max_parathread_outbound_channels_V13;
    pd_configuration_set_hrmp_max_message_num_per_candidate_V13_t configuration_set_hrmp_max_message_num_per_candidate_V13;
    pd_configuration_set_ump_max_individual_weight_V13_t configuration_set_ump_max_individual_weight_V13;
    pd_configuration_set_pvf_checking_enabled_V13_t configuration_set_pvf_checking_enabled_V13;
    pd_configuration_set_pvf_voting_ttl_V13_t configuration_set_pvf_voting_ttl_V13;
    pd_configuration_set_minimum_validation_upgrade_delay_V13_t configuration_set_minimum_validation_upgrade_delay_V13;
    pd_configuration_set_bypass_consistency_check_V13_t configuration_set_bypass_consistency_check_V13;
    pd_initializer_force_approve_V13_t initializer_force_approve_V13;
    pd_ump_service_overweight_V13_t ump_service_overweight_V13;
    pd_hrmp_force_process_hrmp_open_V13_t hrmp_force_process_hrmp_open_V13;
    pd_hrmp_force_process_hrmp_close_V13_t hrmp_force_process_hrmp_close_V13;
    pd_parasdisputes_force_unfreeze_V13_t parasdisputes_force_unfreeze_V13;
    pd_registrar_reserve_V13_t registrar_reserve_V13;
    pd_auctions_new_auction_V13_t auctions_new_auction_V13;
    pd_auctions_bid_V13_t auctions_bid_V13;
    pd_auctions_cancel_auction_V13_t auctions_cancel_auction_V13;
#endif
} pd_MethodBasic_V13_t;

#define PD_CALL_BALANCES_TRANSFER_V13 0
typedef struct {
    pd_LookupasStaticLookupSource_V13_t dest;
    pd_CompactBalance_t amount;
} pd_balances_transfer_V13_t;

#define PD_CALL_BALANCES_FORCE_TRANSFER_V13 2
typedef struct {
    pd_LookupasStaticLookupSource_V13_t source;
    pd_LookupasStaticLookupSource_V13_t dest;
    pd_CompactBalance_t amount;
} pd_balances_force_transfer_V13_t;

#define PD_CALL_BALANCES_TRANSFER_KEEP_ALIVE_V13 3
typedef struct {
    pd_LookupasStaticLookupSource_V13_t dest;
    pd_CompactBalance_t amount;
} pd_balances_transfer_keep_alive_V13_t;

#ifdef SUBSTRATE_PARSER_FULL
#define PD_CALL_SYSTEM_FILL_BLOCK_V13 0
typedef struct {
    pd_Perbill_V13_t ratio;
} pd_system_fill_block_V13_t;

#define PD_CALL_SYSTEM_REMARK_V13 1
typedef struct {
    pd_Vecu8_t remark;
} pd_system_remark_V13_t;

#define PD_CALL_SYSTEM_SET_HEAP_PAGES_V13 2
typedef struct {
    pd_u64_t pages;
} pd_system_set_heap_pages_V13_t;

#define PD_CALL_SYSTEM_SET_CODE_V13 3
typedef struct {
    pd_Vecu8_t code;
} pd_system_set_code_V13_t;

#define PD_CALL_SYSTEM_SET_CODE_WITHOUT_CHECKS_V13 4
typedef struct {
    pd_Vecu8_t code;
} pd_system_set_code_without_checks_V13_t;

#define PD_CALL_SYSTEM_REMARK_WITH_EVENT_V13 8
typedef struct {
    pd_Vecu8_t remark;
} pd_system_remark_with_event_V13_t;

#define PD_CALL_BALANCES_SET_BALANCE_V13 1
typedef struct {
    pd_LookupasStaticLookupSource_V13_t who;
    pd_CompactBalance_t new_free;
    pd_CompactBalance_t new_reserved;
} pd_balances_set_balance_V13_t;

#define PD_CALL_DEMOCRACY_PROPOSE_V13 0
typedef struct {
    pd_Hash_t proposal_hash;
    pd_CompactBalance_t amount;
} pd_democracy_propose_V13_t;

#define PD_CALL_DEMOCRACY_SECOND_V13 1
typedef struct {
    pd_Compactu32_t proposal;
    pd_Compactu32_t seconds_upper_bound;
} pd_democracy_second_V13_t;

#define PD_CALL_DEMOCRACY_VOTE_V13 2
typedef struct {
    pd_Compactu32_t ref_index;
    pd_AccountVote_V13_t vote;
} pd_democracy_vote_V13_t;

#define PD_CALL_DEMOCRACY_EMERGENCY_CANCEL_V13 3
typedef struct {
    pd_ReferendumIndex_V13_t ref_index;
} pd_democracy_emergency_cancel_V13_t;

#define PD_CALL_DEMOCRACY_EXTERNAL_PROPOSE_V13 4
typedef struct {
    pd_Hash_t proposal_hash;
} pd_democracy_external_propose_V13_t;

#define PD_CALL_DEMOCRACY_EXTERNAL_PROPOSE_MAJORITY_V13 5
typedef struct {
    pd_Hash_t proposal_hash;
} pd_democracy_external_propose_majority_V13_t;

#define PD_CALL_DEMOCRACY_EXTERNAL_PROPOSE_DEFAULT_V13 6
typedef struct {
    pd_Hash_t proposal_hash;
} pd_democracy_external_propose_default_V13_t;

#define PD_CALL_DEMOCRACY_FAST_TRACK_V13 7
typedef struct {
    pd_Hash_t proposal_hash;
    pd_BlockNumber_t voting_period;
    pd_BlockNumber_t delay;
} pd_democracy_fast_track_V13_t;

#define PD_CALL_DEMOCRACY_VETO_EXTERNAL_V13 8
typedef struct {
    pd_Hash_t proposal_hash;
} pd_democracy_veto_external_V13_t;

#define PD_CALL_DEMOCRACY_CANCEL_REFERENDUM_V13 9
typedef struct {
    pd_Compactu32_t ref_index;
} pd_democracy_cancel_referendum_V13_t;

#define PD_CALL_DEMOCRACY_CANCEL_QUEUED_V13 10
typedef struct {
    pd_ReferendumIndex_V13_t which;
} pd_democracy_cancel_queued_V13_t;

#define PD_CALL_DEMOCRACY_DELEGATE_V13 11
typedef struct {
    pd_AccountId_V13_t to;
    pd_Conviction_V13_t conviction;
    pd_Balance_t balance;
} pd_democracy_delegate_V13_t;

#define PD_CALL_DEMOCRACY_UNDELEGATE_V13 12
typedef struct {
} pd_democracy_undelegate_V13_t;

#define PD_CALL_DEMOCRACY_CLEAR_PUBLIC_PROPOSALS_V13 13
typedef struct {
} pd_democracy_clear_public_proposals_V13_t;

#define PD_CALL_DEMOCRACY_REAP_PREIMAGE_V13 18
typedef struct {
    pd_Hash_t proposal_hash;
    pd_Compactu32_t proposal_len_upper_bound;
} pd_democracy_reap_preimage_V13_t;

#define PD_CALL_DEMOCRACY_UNLOCK_V13 19
typedef struct {
    pd_AccountId_V13_t target;
} pd_democracy_unlock_V13_t;

#define PD_CALL_DEMOCRACY_REMOVE_VOTE_V13 20
typedef struct {
    pd_ReferendumIndex_V13_t index;
} pd_democracy_remove_vote_V13_t;

#define PD_CALL_DEMOCRACY_REMOVE_OTHER_VOTE_V13 21
typedef struct {
    pd_AccountId_V13_t target;
    pd_ReferendumIndex_V13_t index;
} pd_democracy_remove_other_vote_V13_t;

#define PD_CALL_DEMOCRACY_ENACT_PROPOSAL_V13 22
typedef struct {
    pd_Hash_t proposal_hash;
    pd_ReferendumIndex_V13_t index;
} pd_democracy_enact_proposal_V13_t;

#define PD_CALL_DEMOCRACY_CANCEL_PROPOSAL_V13 24
typedef struct {
    pd_Compactu32_t prop_index;
} pd_democracy_cancel_proposal_V13_t;

#define PD_CALL_PROXY_PROXY_V13 0
typedef struct {
    pd_AccountId_V13_t real;
    pd_OptionProxyType_V13_t force_proxy_type;
    pd_Call_t call;
} pd_proxy_proxy_V13_t;

#define PD_CALL_MULTISIG_AS_MULTI_THRESHOLD_1_V13 0
typedef struct {
    pd_VecAccountId_V13_t other_signatories;
    pd_Call_t call;
} pd_multisig_as_multi_threshold_1_V13_t;

#define PD_CALL_MULTISIG_AS_MULTI_V13 1
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_V13_t other_signatories;
    pd_OptionTimepoint_V13_t maybe_timepoint;
    pd_OpaqueCall_V13_t call;
    pd_bool_t store_call;
    pd_Weight_V13_t max_weight;
} pd_multisig_as_multi_V13_t;

#define PD_CALL_MULTISIG_APPROVE_AS_MULTI_V13 2
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_V13_t other_signatories;
    pd_OptionTimepoint_V13_t maybe_timepoint;
    pd_H256_t call_hash;
    pd_Weight_V13_t max_weight;
} pd_multisig_approve_as_multi_V13_t;

#define PD_CALL_MULTISIG_CANCEL_AS_MULTI_V13 3
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_V13_t other_signatories;
    pd_Timepoint_V13_t timepoint;
    pd_H256_t call_hash;
} pd_multisig_cancel_as_multi_V13_t;

#endif

typedef union {
    pd_balances_transfer_V13_t balances_transfer_V13;
    pd_balances_force_transfer_V13_t balances_force_transfer_V13;
    pd_balances_transfer_keep_alive_V13_t balances_transfer_keep_alive_V13;
#ifdef SUBSTRATE_PARSER_FULL
    pd_system_fill_block_V13_t system_fill_block_V13;
    pd_system_remark_V13_t system_remark_V13;
    pd_system_set_heap_pages_V13_t system_set_heap_pages_V13;
    pd_system_set_code_V13_t system_set_code_V13;
    pd_system_set_code_without_checks_V13_t system_set_code_without_checks_V13;
    pd_system_remark_with_event_V13_t system_remark_with_event_V13;
    pd_balances_set_balance_V13_t balances_set_balance_V13;
    pd_democracy_propose_V13_t democracy_propose_V13;
    pd_democracy_second_V13_t democracy_second_V13;
    pd_democracy_vote_V13_t democracy_vote_V13;
    pd_democracy_emergency_cancel_V13_t democracy_emergency_cancel_V13;
    pd_democracy_external_propose_V13_t democracy_external_propose_V13;
    pd_democracy_external_propose_majority_V13_t democracy_external_propose_majority_V13;
    pd_democracy_external_propose_default_V13_t democracy_external_propose_default_V13;
    pd_democracy_fast_track_V13_t democracy_fast_track_V13;
    pd_democracy_veto_external_V13_t democracy_veto_external_V13;
    pd_democracy_cancel_referendum_V13_t democracy_cancel_referendum_V13;
    pd_democracy_cancel_queued_V13_t democracy_cancel_queued_V13;
    pd_democracy_delegate_V13_t democracy_delegate_V13;
    pd_democracy_undelegate_V13_t democracy_undelegate_V13;
    pd_democracy_clear_public_proposals_V13_t democracy_clear_public_proposals_V13;
    pd_democracy_reap_preimage_V13_t democracy_reap_preimage_V13;
    pd_democracy_unlock_V13_t democracy_unlock_V13;
    pd_democracy_remove_vote_V13_t democracy_remove_vote_V13;
    pd_democracy_remove_other_vote_V13_t democracy_remove_other_vote_V13;
    pd_democracy_enact_proposal_V13_t democracy_enact_proposal_V13;
    pd_democracy_cancel_proposal_V13_t democracy_cancel_proposal_V13;
    pd_proxy_proxy_V13_t proxy_proxy_V13;
    pd_multisig_as_multi_threshold_1_V13_t multisig_as_multi_threshold_1_V13;
    pd_multisig_as_multi_V13_t multisig_as_multi_V13;
    pd_multisig_approve_as_multi_V13_t multisig_approve_as_multi_V13;
    pd_multisig_cancel_as_multi_V13_t multisig_cancel_as_multi_V13;
#endif
} pd_MethodNested_V13_t;

typedef union {
    pd_MethodBasic_V13_t basic;
    pd_MethodNested_V13_t nested;
} pd_Method_V13_t;

#ifdef __cplusplus
}
#endif

#pragma clang diagnostic pop
