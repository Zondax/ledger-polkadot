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
#include "substrate_types_V14.h"
#include <stddef.h>
#include <stdint.h>

#define PD_CALL_SYSTEM_V14 0
#define PD_CALL_PREIMAGE_V14 10
#define PD_CALL_TIMESTAMP_V14 3
#define PD_CALL_INDICES_V14 4
#define PD_CALL_BALANCES_V14 5
#define PD_CALL_STAKING_V14 7
#define PD_CALL_SESSION_V14 9
#define PD_CALL_GRANDPA_V14 11
#define PD_CALL_DEMOCRACY_V14 14
#define PD_CALL_COUNCIL_V14 15
#define PD_CALL_TECHNICALCOMMITTEE_V14 16
#define PD_CALL_PHRAGMENELECTION_V14 17
#define PD_CALL_TECHNICALMEMBERSHIP_V14 18
#define PD_CALL_TREASURY_V14 19
#define PD_CALL_CLAIMS_V14 24
#define PD_CALL_VESTING_V14 25
#define PD_CALL_UTILITY_V14 26
#define PD_CALL_IDENTITY_V14 28
#define PD_CALL_PROXY_V14 29
#define PD_CALL_MULTISIG_V14 30
#define PD_CALL_BOUNTIES_V14 34
#define PD_CALL_CHILDBOUNTIES_V14 38
#define PD_CALL_TIPS_V14 35
#define PD_CALL_ELECTIONPROVIDERMULTIPHASE_V14 36
#define PD_CALL_VOTERLIST_V14 37
#define PD_CALL_NOMINATIONPOOLS_V14 39
#define PD_CALL_CONFIGURATION_V14 51
#define PD_CALL_INITIALIZER_V14 57
#define PD_CALL_UMP_V14 59
#define PD_CALL_HRMP_V14 60
#define PD_CALL_PARASDISPUTES_V14 62
#define PD_CALL_REGISTRAR_V14 70
#define PD_CALL_AUCTIONS_V14 72
#define PD_CALL_CROWDLOAN_V14 73

#define PD_CALL_BALANCES_TRANSFER_ALL_V14 4
typedef struct {
    pd_AccountIdLookupOfT_V14_t dest;
    pd_bool_t keep_alive;
} pd_balances_transfer_all_V14_t;

#define PD_CALL_STAKING_BOND_V14 0
typedef struct {
    pd_AccountIdLookupOfT_V14_t controller;
    pd_CompactBalance_t amount;
    pd_RewardDestination_V14_t payee;
} pd_staking_bond_V14_t;

#define PD_CALL_STAKING_BOND_EXTRA_V14 1
typedef struct {
    pd_CompactBalance_t amount;
} pd_staking_bond_extra_V14_t;

#define PD_CALL_STAKING_UNBOND_V14 2
typedef struct {
    pd_CompactBalance_t amount;
} pd_staking_unbond_V14_t;

#define PD_CALL_STAKING_WITHDRAW_UNBONDED_V14 3
typedef struct {
    pd_u32_t num_slashing_spans;
} pd_staking_withdraw_unbonded_V14_t;

#define PD_CALL_STAKING_VALIDATE_V14 4
typedef struct {
    pd_ValidatorPrefs_V14_t prefs;
} pd_staking_validate_V14_t;

#define PD_CALL_STAKING_NOMINATE_V14 5
typedef struct {
    pd_VecAccountIdLookupOfT_V14_t targets;
} pd_staking_nominate_V14_t;

#define PD_CALL_STAKING_CHILL_V14 6
typedef struct {
} pd_staking_chill_V14_t;

#define PD_CALL_STAKING_SET_PAYEE_V14 7
typedef struct {
    pd_RewardDestination_V14_t payee;
} pd_staking_set_payee_V14_t;

#define PD_CALL_STAKING_SET_CONTROLLER_V14 8
typedef struct {
    pd_AccountIdLookupOfT_V14_t controller;
} pd_staking_set_controller_V14_t;

#define PD_CALL_STAKING_PAYOUT_STAKERS_V14 18
typedef struct {
    pd_AccountId_V14_t validator_stash;
    pd_EraIndex_V14_t era;
} pd_staking_payout_stakers_V14_t;

#define PD_CALL_STAKING_REBOND_V14 19
typedef struct {
    pd_CompactBalance_t amount;
} pd_staking_rebond_V14_t;

#define PD_CALL_SESSION_SET_KEYS_V14 0
typedef struct {
    pd_Keys_V14_t keys;
    pd_Bytes_t proof;
} pd_session_set_keys_V14_t;

#define PD_CALL_SESSION_PURGE_KEYS_V14 1
typedef struct {
} pd_session_purge_keys_V14_t;

#define PD_CALL_UTILITY_BATCH_V14 0
typedef struct {
    pd_VecCall_t calls;
} pd_utility_batch_V14_t;

#define PD_CALL_UTILITY_BATCH_ALL_V14 2
typedef struct {
    pd_VecCall_t calls;
} pd_utility_batch_all_V14_t;

#define PD_CALL_UTILITY_FORCE_BATCH_V14 4
typedef struct {
    pd_VecCall_t calls;
} pd_utility_force_batch_V14_t;

#define PD_CALL_CROWDLOAN_CREATE_V14 0
typedef struct {
    pd_Compactu32_t index;
    pd_Compactu128_t cap;
    pd_Compactu32_t first_period;
    pd_Compactu32_t last_period;
    pd_Compactu32_t end;
    pd_OptionMultiSigner_V14_t verifier;
} pd_crowdloan_create_V14_t;

#define PD_CALL_CROWDLOAN_CONTRIBUTE_V14 1
typedef struct {
    pd_Compactu32_t index;
    pd_Compactu128_t amount;
    pd_OptionMultiSignature_V14_t signature;
} pd_crowdloan_contribute_V14_t;

#define PD_CALL_CROWDLOAN_WITHDRAW_V14 2
typedef struct {
    pd_AccountId_V14_t who;
    pd_Compactu32_t index;
} pd_crowdloan_withdraw_V14_t;

#define PD_CALL_CROWDLOAN_REFUND_V14 3
typedef struct {
    pd_Compactu32_t index;
} pd_crowdloan_refund_V14_t;

#define PD_CALL_CROWDLOAN_DISSOLVE_V14 4
typedef struct {
    pd_Compactu32_t index;
} pd_crowdloan_dissolve_V14_t;

#define PD_CALL_CROWDLOAN_EDIT_V14 5
typedef struct {
    pd_Compactu32_t index;
    pd_Compactu128_t cap;
    pd_Compactu32_t first_period;
    pd_Compactu32_t last_period;
    pd_Compactu32_t end;
    pd_OptionMultiSigner_V14_t verifier;
} pd_crowdloan_edit_V14_t;

#define PD_CALL_CROWDLOAN_ADD_MEMO_V14 6
typedef struct {
    pd_ParaId_V14_t index;
    pd_Vecu8_t memo;
} pd_crowdloan_add_memo_V14_t;

#define PD_CALL_CROWDLOAN_POKE_V14 7
typedef struct {
    pd_ParaId_V14_t index;
} pd_crowdloan_poke_V14_t;

#define PD_CALL_CROWDLOAN_CONTRIBUTE_ALL_V14 8
typedef struct {
    pd_Compactu32_t index;
    pd_OptionMultiSignature_V14_t signature;
} pd_crowdloan_contribute_all_V14_t;

#ifdef SUBSTRATE_PARSER_FULL

#define PD_CALL_PREIMAGE_NOTE_PREIMAGE_V14 0
typedef struct {
    pd_Vecu8_t bytes;
} pd_preimage_note_preimage_V14_t;

#define PD_CALL_PREIMAGE_UNNOTE_PREIMAGE_V14 1
typedef struct {
    pd_Hash_t hash;
} pd_preimage_unnote_preimage_V14_t;

#define PD_CALL_PREIMAGE_REQUEST_PREIMAGE_V14 2
typedef struct {
    pd_Hash_t hash;
} pd_preimage_request_preimage_V14_t;

#define PD_CALL_PREIMAGE_UNREQUEST_PREIMAGE_V14 3
typedef struct {
    pd_Hash_t hash;
} pd_preimage_unrequest_preimage_V14_t;

#define PD_CALL_TIMESTAMP_SET_V14 0
typedef struct {
    pd_Compactu64_t now;
} pd_timestamp_set_V14_t;

#define PD_CALL_INDICES_CLAIM_V14 0
typedef struct {
    pd_AccountIndex_V14_t index;
} pd_indices_claim_V14_t;

#define PD_CALL_INDICES_TRANSFER_V14 1
typedef struct {
    pd_AccountIdLookupOfT_V14_t new_;
    pd_AccountIndex_V14_t index;
} pd_indices_transfer_V14_t;

#define PD_CALL_INDICES_FREE_V14 2
typedef struct {
    pd_AccountIndex_V14_t index;
} pd_indices_free_V14_t;

#define PD_CALL_INDICES_FORCE_TRANSFER_V14 3
typedef struct {
    pd_AccountIdLookupOfT_V14_t new_;
    pd_AccountIndex_V14_t index;
    pd_bool_t freeze;
} pd_indices_force_transfer_V14_t;

#define PD_CALL_INDICES_FREEZE_V14 4
typedef struct {
    pd_AccountIndex_V14_t index;
} pd_indices_freeze_V14_t;

#define PD_CALL_BALANCES_FORCE_UNRESERVE_V14 5
typedef struct {
    pd_AccountIdLookupOfT_V14_t who;
    pd_Balance_t amount;
} pd_balances_force_unreserve_V14_t;

#define PD_CALL_STAKING_SET_VALIDATOR_COUNT_V14 9
typedef struct {
    pd_Compactu32_t new_;
} pd_staking_set_validator_count_V14_t;

#define PD_CALL_STAKING_INCREASE_VALIDATOR_COUNT_V14 10
typedef struct {
    pd_Compactu32_t additional;
} pd_staking_increase_validator_count_V14_t;

#define PD_CALL_STAKING_FORCE_NO_ERAS_V14 12
typedef struct {
} pd_staking_force_no_eras_V14_t;

#define PD_CALL_STAKING_FORCE_NEW_ERA_V14 13
typedef struct {
} pd_staking_force_new_era_V14_t;

#define PD_CALL_STAKING_SET_INVULNERABLES_V14 14
typedef struct {
    pd_VecAccountId_V14_t invulnerables;
} pd_staking_set_invulnerables_V14_t;

#define PD_CALL_STAKING_FORCE_UNSTAKE_V14 15
typedef struct {
    pd_AccountId_V14_t stash;
    pd_u32_t num_slashing_spans;
} pd_staking_force_unstake_V14_t;

#define PD_CALL_STAKING_FORCE_NEW_ERA_ALWAYS_V14 16
typedef struct {
} pd_staking_force_new_era_always_V14_t;

#define PD_CALL_STAKING_CANCEL_DEFERRED_SLASH_V14 17
typedef struct {
    pd_EraIndex_V14_t era;
    pd_Vecu32_t slash_indices;
} pd_staking_cancel_deferred_slash_V14_t;

#define PD_CALL_STAKING_SET_HISTORY_DEPTH_V14 20
typedef struct {
    pd_Compactu32_t new_history_depth;
    pd_Compactu32_t era_items_deleted;
} pd_staking_set_history_depth_V14_t;

#define PD_CALL_STAKING_REAP_STASH_V14 21
typedef struct {
    pd_AccountId_V14_t stash;
    pd_u32_t num_slashing_spans;
} pd_staking_reap_stash_V14_t;

#define PD_CALL_STAKING_KICK_V14 22
typedef struct {
    pd_VecAccountIdLookupOfT_V14_t who;
} pd_staking_kick_V14_t;

#define PD_CALL_STAKING_CHILL_OTHER_V14 24
typedef struct {
    pd_AccountId_V14_t controller;
} pd_staking_chill_other_V14_t;

#define PD_CALL_STAKING_FORCE_APPLY_MIN_COMMISSION_V14 25
typedef struct {
    pd_AccountId_V14_t validator_stash;
} pd_staking_force_apply_min_commission_V14_t;

#define PD_CALL_GRANDPA_NOTE_STALLED_V14 2
typedef struct {
    pd_BlockNumber_t delay;
    pd_BlockNumber_t best_finalized_block_number;
} pd_grandpa_note_stalled_V14_t;

#define PD_CALL_DEMOCRACY_NOTE_PREIMAGE_V14 14
typedef struct {
    pd_Bytes_t encoded_proposal;
} pd_democracy_note_preimage_V14_t;

#define PD_CALL_DEMOCRACY_NOTE_PREIMAGE_OPERATIONAL_V14 15
typedef struct {
    pd_Bytes_t encoded_proposal;
} pd_democracy_note_preimage_operational_V14_t;

#define PD_CALL_DEMOCRACY_NOTE_IMMINENT_PREIMAGE_V14 16
typedef struct {
    pd_Bytes_t encoded_proposal;
} pd_democracy_note_imminent_preimage_V14_t;

#define PD_CALL_DEMOCRACY_NOTE_IMMINENT_PREIMAGE_OPERATIONAL_V14 17
typedef struct {
    pd_Bytes_t encoded_proposal;
} pd_democracy_note_imminent_preimage_operational_V14_t;

#define PD_CALL_COUNCIL_SET_MEMBERS_V14 0
typedef struct {
    pd_VecAccountId_V14_t new_members;
    pd_OptionAccountId_V14_t prime;
    pd_MemberCount_V14_t old_count;
} pd_council_set_members_V14_t;

#define PD_CALL_COUNCIL_EXECUTE_V14 1
typedef struct {
    pd_Proposal_t proposal;
    pd_Compactu32_t length_bound;
} pd_council_execute_V14_t;

#define PD_CALL_COUNCIL_PROPOSE_V14 2
typedef struct {
    pd_Compactu32_t threshold;
    pd_Proposal_t proposal;
    pd_Compactu32_t length_bound;
} pd_council_propose_V14_t;

#define PD_CALL_COUNCIL_VOTE_V14 3
typedef struct {
    pd_Hash_t proposal;
    pd_Compactu32_t index;
    pd_bool_t approve;
} pd_council_vote_V14_t;

#define PD_CALL_COUNCIL_CLOSE_V14 4
typedef struct {
    pd_Hash_t proposal_hash;
    pd_Compactu32_t index;
    pd_Compactu64_t proposal_weight_bound;
    pd_Compactu32_t length_bound;
} pd_council_close_V14_t;

#define PD_CALL_COUNCIL_DISAPPROVE_PROPOSAL_V14 5
typedef struct {
    pd_Hash_t proposal_hash;
} pd_council_disapprove_proposal_V14_t;

#define PD_CALL_TECHNICALCOMMITTEE_SET_MEMBERS_V14 0
typedef struct {
    pd_VecAccountId_V14_t new_members;
    pd_OptionAccountId_V14_t prime;
    pd_MemberCount_V14_t old_count;
} pd_technicalcommittee_set_members_V14_t;

#define PD_CALL_TECHNICALCOMMITTEE_EXECUTE_V14 1
typedef struct {
    pd_Proposal_t proposal;
    pd_Compactu32_t length_bound;
} pd_technicalcommittee_execute_V14_t;

#define PD_CALL_TECHNICALCOMMITTEE_PROPOSE_V14 2
typedef struct {
    pd_Compactu32_t threshold;
    pd_Proposal_t proposal;
    pd_Compactu32_t length_bound;
} pd_technicalcommittee_propose_V14_t;

#define PD_CALL_TECHNICALCOMMITTEE_VOTE_V14 3
typedef struct {
    pd_Hash_t proposal;
    pd_Compactu32_t index;
    pd_bool_t approve;
} pd_technicalcommittee_vote_V14_t;

#define PD_CALL_TECHNICALCOMMITTEE_CLOSE_V14 4
typedef struct {
    pd_Hash_t proposal_hash;
    pd_Compactu32_t index;
    pd_Compactu64_t proposal_weight_bound;
    pd_Compactu32_t length_bound;
} pd_technicalcommittee_close_V14_t;

#define PD_CALL_TECHNICALCOMMITTEE_DISAPPROVE_PROPOSAL_V14 5
typedef struct {
    pd_Hash_t proposal_hash;
} pd_technicalcommittee_disapprove_proposal_V14_t;

#define PD_CALL_PHRAGMENELECTION_VOTE_V14 0
typedef struct {
    pd_VecAccountId_V14_t votes;
    pd_Compactu128_t amount;
} pd_phragmenelection_vote_V14_t;

#define PD_CALL_PHRAGMENELECTION_REMOVE_VOTER_V14 1
typedef struct {
} pd_phragmenelection_remove_voter_V14_t;

#define PD_CALL_PHRAGMENELECTION_SUBMIT_CANDIDACY_V14 2
typedef struct {
    pd_Compactu32_t candidate_count;
} pd_phragmenelection_submit_candidacy_V14_t;

#define PD_CALL_PHRAGMENELECTION_REMOVE_MEMBER_V14 4
typedef struct {
    pd_AccountIdLookupOfT_V14_t who;
    pd_bool_t slash_bond;
    pd_bool_t rerun_election;
} pd_phragmenelection_remove_member_V14_t;

#define PD_CALL_PHRAGMENELECTION_CLEAN_DEFUNCT_VOTERS_V14 5
typedef struct {
    pd_u32_t num_voters;
    pd_u32_t num_defunct;
} pd_phragmenelection_clean_defunct_voters_V14_t;

#define PD_CALL_TECHNICALMEMBERSHIP_ADD_MEMBER_V14 0
typedef struct {
    pd_AccountIdLookupOfT_V14_t who;
} pd_technicalmembership_add_member_V14_t;

#define PD_CALL_TECHNICALMEMBERSHIP_REMOVE_MEMBER_V14 1
typedef struct {
    pd_AccountIdLookupOfT_V14_t who;
} pd_technicalmembership_remove_member_V14_t;

#define PD_CALL_TECHNICALMEMBERSHIP_SWAP_MEMBER_V14 2
typedef struct {
    pd_AccountIdLookupOfT_V14_t remove;
    pd_AccountIdLookupOfT_V14_t add;
} pd_technicalmembership_swap_member_V14_t;

#define PD_CALL_TECHNICALMEMBERSHIP_RESET_MEMBERS_V14 3
typedef struct {
    pd_VecAccountId_V14_t members;
} pd_technicalmembership_reset_members_V14_t;

#define PD_CALL_TECHNICALMEMBERSHIP_CHANGE_KEY_V14 4
typedef struct {
    pd_AccountIdLookupOfT_V14_t new_;
} pd_technicalmembership_change_key_V14_t;

#define PD_CALL_TECHNICALMEMBERSHIP_SET_PRIME_V14 5
typedef struct {
    pd_AccountIdLookupOfT_V14_t who;
} pd_technicalmembership_set_prime_V14_t;

#define PD_CALL_TECHNICALMEMBERSHIP_CLEAR_PRIME_V14 6
typedef struct {
} pd_technicalmembership_clear_prime_V14_t;

#define PD_CALL_TREASURY_PROPOSE_SPEND_V14 0
typedef struct {
    pd_CompactBalance_t amount;
    pd_AccountIdLookupOfT_V14_t beneficiary;
} pd_treasury_propose_spend_V14_t;

#define PD_CALL_TREASURY_REJECT_PROPOSAL_V14 1
typedef struct {
    pd_Compactu32_t proposal_id;
} pd_treasury_reject_proposal_V14_t;

#define PD_CALL_TREASURY_APPROVE_PROPOSAL_V14 2
typedef struct {
    pd_Compactu32_t proposal_id;
} pd_treasury_approve_proposal_V14_t;

#define PD_CALL_TREASURY_SPEND_V14 3
typedef struct {
    pd_CompactBalance_t amount;
    pd_AccountIdLookupOfT_V14_t beneficiary;
} pd_treasury_spend_V14_t;

#define PD_CALL_TREASURY_REMOVE_APPROVAL_V14 4
typedef struct {
    pd_Compactu32_t proposal_id;
} pd_treasury_remove_approval_V14_t;

#define PD_CALL_CLAIMS_CLAIM_V14 0
typedef struct {
    pd_AccountId_V14_t dest;
    pd_EcdsaSignature_V14_t ethereum_signature;
} pd_claims_claim_V14_t;

#define PD_CALL_CLAIMS_CLAIM_ATTEST_V14 2
typedef struct {
    pd_AccountId_V14_t dest;
    pd_EcdsaSignature_V14_t ethereum_signature;
    pd_Bytes_t statement;
} pd_claims_claim_attest_V14_t;

#define PD_CALL_CLAIMS_ATTEST_V14 3
typedef struct {
    pd_Bytes_t statement;
} pd_claims_attest_V14_t;

#define PD_CALL_CLAIMS_MOVE_CLAIM_V14 4
typedef struct {
    pd_EthereumAddress_V14_t old;
    pd_EthereumAddress_V14_t new_;
    pd_OptionAccountId_V14_t maybe_preclaim;
} pd_claims_move_claim_V14_t;

#define PD_CALL_VESTING_VEST_V14 0
typedef struct {
} pd_vesting_vest_V14_t;

#define PD_CALL_VESTING_VEST_OTHER_V14 1
typedef struct {
    pd_AccountIdLookupOfT_V14_t target;
} pd_vesting_vest_other_V14_t;

#define PD_CALL_VESTING_VESTED_TRANSFER_V14 2
typedef struct {
    pd_AccountIdLookupOfT_V14_t target;
    pd_VestingInfo_V14_t schedule;
} pd_vesting_vested_transfer_V14_t;

#define PD_CALL_VESTING_FORCE_VESTED_TRANSFER_V14 3
typedef struct {
    pd_AccountIdLookupOfT_V14_t source;
    pd_AccountIdLookupOfT_V14_t target;
    pd_VestingInfo_V14_t schedule;
} pd_vesting_force_vested_transfer_V14_t;

#define PD_CALL_VESTING_MERGE_SCHEDULES_V14 4
typedef struct {
    pd_u32_t schedule1_index;
    pd_u32_t schedule2_index;
} pd_vesting_merge_schedules_V14_t;

#define PD_CALL_IDENTITY_ADD_REGISTRAR_V14 0
typedef struct {
    pd_AccountIdLookupOfT_V14_t account;
} pd_identity_add_registrar_V14_t;

#define PD_CALL_IDENTITY_CLEAR_IDENTITY_V14 3
typedef struct {
} pd_identity_clear_identity_V14_t;

#define PD_CALL_IDENTITY_REQUEST_JUDGEMENT_V14 4
typedef struct {
    pd_Compactu32_t reg_index;
    pd_Compactu128_t max_fee;
} pd_identity_request_judgement_V14_t;

#define PD_CALL_IDENTITY_CANCEL_REQUEST_V14 5
typedef struct {
    pd_RegistrarIndex_V14_t reg_index;
} pd_identity_cancel_request_V14_t;

#define PD_CALL_IDENTITY_SET_FEE_V14 6
typedef struct {
    pd_Compactu32_t index;
    pd_Compactu128_t fee;
} pd_identity_set_fee_V14_t;

#define PD_CALL_IDENTITY_SET_ACCOUNT_ID_V14 7
typedef struct {
    pd_Compactu32_t index;
    pd_AccountIdLookupOfT_V14_t new_;
} pd_identity_set_account_id_V14_t;

#define PD_CALL_IDENTITY_KILL_IDENTITY_V14 10
typedef struct {
    pd_AccountIdLookupOfT_V14_t target;
} pd_identity_kill_identity_V14_t;

#define PD_CALL_IDENTITY_REMOVE_SUB_V14 13
typedef struct {
    pd_AccountIdLookupOfT_V14_t sub;
} pd_identity_remove_sub_V14_t;

#define PD_CALL_IDENTITY_QUIT_SUB_V14 14
typedef struct {
} pd_identity_quit_sub_V14_t;

#define PD_CALL_PROXY_ADD_PROXY_V14 1
typedef struct {
    pd_AccountIdLookupOfT_V14_t delegate;
    pd_ProxyType_V14_t proxy_type;
    pd_BlockNumber_t delay;
} pd_proxy_add_proxy_V14_t;

#define PD_CALL_PROXY_REMOVE_PROXY_V14 2
typedef struct {
    pd_AccountIdLookupOfT_V14_t delegate;
    pd_ProxyType_V14_t proxy_type;
    pd_BlockNumber_t delay;
} pd_proxy_remove_proxy_V14_t;

#define PD_CALL_PROXY_REMOVE_PROXIES_V14 3
typedef struct {
} pd_proxy_remove_proxies_V14_t;

#define PD_CALL_PROXY_ANONYMOUS_V14 4
typedef struct {
    pd_ProxyType_V14_t proxy_type;
    pd_BlockNumber_t delay;
    pd_u16_t index;
} pd_proxy_anonymous_V14_t;

#define PD_CALL_PROXY_KILL_ANONYMOUS_V14 5
typedef struct {
    pd_AccountIdLookupOfT_V14_t spawner;
    pd_ProxyType_V14_t proxy_type;
    pd_u16_t index;
    pd_Compactu32_t height;
    pd_Compactu32_t ext_index;
} pd_proxy_kill_anonymous_V14_t;

#define PD_CALL_PROXY_PROXY_ANNOUNCED_V14 9
typedef struct {
    pd_AccountIdLookupOfT_V14_t delegate;
    pd_AccountIdLookupOfT_V14_t real;
    pd_OptionProxyType_V14_t force_proxy_type;
    pd_Call_t call;
} pd_proxy_proxy_announced_V14_t;

#define PD_CALL_BOUNTIES_PROPOSE_BOUNTY_V14 0
typedef struct {
    pd_CompactBalance_t amount;
    pd_Bytes_t description;
} pd_bounties_propose_bounty_V14_t;

#define PD_CALL_BOUNTIES_APPROVE_BOUNTY_V14 1
typedef struct {
    pd_Compactu32_t bounty_id;
} pd_bounties_approve_bounty_V14_t;

#define PD_CALL_BOUNTIES_PROPOSE_CURATOR_V14 2
typedef struct {
    pd_Compactu32_t bounty_id;
    pd_AccountIdLookupOfT_V14_t curator;
    pd_CompactBalance_t fee;
} pd_bounties_propose_curator_V14_t;

#define PD_CALL_BOUNTIES_UNASSIGN_CURATOR_V14 3
typedef struct {
    pd_Compactu32_t bounty_id;
} pd_bounties_unassign_curator_V14_t;

#define PD_CALL_BOUNTIES_ACCEPT_CURATOR_V14 4
typedef struct {
    pd_Compactu32_t bounty_id;
} pd_bounties_accept_curator_V14_t;

#define PD_CALL_BOUNTIES_AWARD_BOUNTY_V14 5
typedef struct {
    pd_Compactu32_t bounty_id;
    pd_AccountIdLookupOfT_V14_t beneficiary;
} pd_bounties_award_bounty_V14_t;

#define PD_CALL_BOUNTIES_CLAIM_BOUNTY_V14 6
typedef struct {
    pd_Compactu32_t bounty_id;
} pd_bounties_claim_bounty_V14_t;

#define PD_CALL_BOUNTIES_CLOSE_BOUNTY_V14 7
typedef struct {
    pd_Compactu32_t bounty_id;
} pd_bounties_close_bounty_V14_t;

#define PD_CALL_BOUNTIES_EXTEND_BOUNTY_EXPIRY_V14 8
typedef struct {
    pd_Compactu32_t bounty_id;
    pd_Bytes_t remark;
} pd_bounties_extend_bounty_expiry_V14_t;

#define PD_CALL_CHILDBOUNTIES_ADD_CHILD_BOUNTY_V14 0
typedef struct {
    pd_Compactu32_t parent_bounty_id;
    pd_CompactBalance_t amount;
    pd_Vecu8_t description;
} pd_childbounties_add_child_bounty_V14_t;

#define PD_CALL_CHILDBOUNTIES_PROPOSE_CURATOR_V14 1
typedef struct {
    pd_Compactu32_t parent_bounty_id;
    pd_Compactu32_t child_bounty_id;
    pd_AccountIdLookupOfT_V14_t curator;
    pd_CompactBalance_t fee;
} pd_childbounties_propose_curator_V14_t;

#define PD_CALL_CHILDBOUNTIES_ACCEPT_CURATOR_V14 2
typedef struct {
    pd_Compactu32_t parent_bounty_id;
    pd_Compactu32_t child_bounty_id;
} pd_childbounties_accept_curator_V14_t;

#define PD_CALL_CHILDBOUNTIES_UNASSIGN_CURATOR_V14 3
typedef struct {
    pd_Compactu32_t parent_bounty_id;
    pd_Compactu32_t child_bounty_id;
} pd_childbounties_unassign_curator_V14_t;

#define PD_CALL_CHILDBOUNTIES_AWARD_CHILD_BOUNTY_V14 4
typedef struct {
    pd_Compactu32_t parent_bounty_id;
    pd_Compactu32_t child_bounty_id;
    pd_AccountIdLookupOfT_V14_t beneficiary;
} pd_childbounties_award_child_bounty_V14_t;

#define PD_CALL_CHILDBOUNTIES_CLAIM_CHILD_BOUNTY_V14 5
typedef struct {
    pd_Compactu32_t parent_bounty_id;
    pd_Compactu32_t child_bounty_id;
} pd_childbounties_claim_child_bounty_V14_t;

#define PD_CALL_CHILDBOUNTIES_CLOSE_CHILD_BOUNTY_V14 6
typedef struct {
    pd_Compactu32_t parent_bounty_id;
    pd_Compactu32_t child_bounty_id;
} pd_childbounties_close_child_bounty_V14_t;

#define PD_CALL_TIPS_REPORT_AWESOME_V14 0
typedef struct {
    pd_Bytes_t reason;
    pd_AccountIdLookupOfT_V14_t who;
} pd_tips_report_awesome_V14_t;

#define PD_CALL_TIPS_RETRACT_TIP_V14 1
typedef struct {
    pd_Hash_t hash;
} pd_tips_retract_tip_V14_t;

#define PD_CALL_TIPS_TIP_NEW_V14 2
typedef struct {
    pd_Bytes_t reason;
    pd_AccountIdLookupOfT_V14_t who;
    pd_Compactu128_t tip_value;
} pd_tips_tip_new_V14_t;

#define PD_CALL_TIPS_TIP_V14 3
typedef struct {
    pd_Hash_t hash;
    pd_Compactu128_t tip_value;
} pd_tips_tip_V14_t;

#define PD_CALL_TIPS_CLOSE_TIP_V14 4
typedef struct {
    pd_Hash_t hash;
} pd_tips_close_tip_V14_t;

#define PD_CALL_TIPS_SLASH_TIP_V14 5
typedef struct {
    pd_Hash_t hash;
} pd_tips_slash_tip_V14_t;

#define PD_CALL_ELECTIONPROVIDERMULTIPHASE_GOVERNANCE_FALLBACK_V14 4
typedef struct {
    pd_Optionu32_t maybe_max_voters;
    pd_Optionu32_t maybe_max_targets;
} pd_electionprovidermultiphase_governance_fallback_V14_t;

#define PD_CALL_VOTERLIST_REBAG_V14 0
typedef struct {
    pd_AccountIdLookupOfT_V14_t dislocated;
} pd_voterlist_rebag_V14_t;

#define PD_CALL_VOTERLIST_PUT_IN_FRONT_OF_V14 1
typedef struct {
    pd_AccountIdLookupOfT_V14_t lighter;
} pd_voterlist_put_in_front_of_V14_t;

#define PD_CALL_NOMINATIONPOOLS_JOIN_V14 0
typedef struct {
    pd_Compactu128_t amount;
    pd_PoolId_V14_t pool_id;
} pd_nominationpools_join_V14_t;

#define PD_CALL_NOMINATIONPOOLS_BOND_EXTRA_V14 1
typedef struct {
    pd_BondExtraBalanceOfT_V14_t extra;
} pd_nominationpools_bond_extra_V14_t;

#define PD_CALL_NOMINATIONPOOLS_CLAIM_PAYOUT_V14 2
typedef struct {
} pd_nominationpools_claim_payout_V14_t;

#define PD_CALL_NOMINATIONPOOLS_UNBOND_V14 3
typedef struct {
    pd_AccountIdLookupOfT_V14_t member_account;
    pd_Compactu128_t unbonding_points;
} pd_nominationpools_unbond_V14_t;

#define PD_CALL_NOMINATIONPOOLS_POOL_WITHDRAW_UNBONDED_V14 4
typedef struct {
    pd_PoolId_V14_t pool_id;
    pd_u32_t num_slashing_spans;
} pd_nominationpools_pool_withdraw_unbonded_V14_t;

#define PD_CALL_NOMINATIONPOOLS_WITHDRAW_UNBONDED_V14 5
typedef struct {
    pd_AccountIdLookupOfT_V14_t member_account;
    pd_u32_t num_slashing_spans;
} pd_nominationpools_withdraw_unbonded_V14_t;

#define PD_CALL_NOMINATIONPOOLS_CREATE_V14 6
typedef struct {
    pd_Compactu128_t amount;
    pd_AccountIdLookupOfT_V14_t root;
    pd_AccountIdLookupOfT_V14_t nominator;
    pd_AccountIdLookupOfT_V14_t state_toggler;
} pd_nominationpools_create_V14_t;

#define PD_CALL_NOMINATIONPOOLS_NOMINATE_V14 7
typedef struct {
    pd_PoolId_V14_t pool_id;
    pd_VecAccountId_V14_t validators;
} pd_nominationpools_nominate_V14_t;

#define PD_CALL_NOMINATIONPOOLS_SET_STATE_V14 8
typedef struct {
    pd_PoolId_V14_t pool_id;
    pd_PoolState_V14_t state;
} pd_nominationpools_set_state_V14_t;

#define PD_CALL_NOMINATIONPOOLS_SET_METADATA_V14 9
typedef struct {
    pd_PoolId_V14_t pool_id;
    pd_Vecu8_t metadata;
} pd_nominationpools_set_metadata_V14_t;

#define PD_CALL_NOMINATIONPOOLS_SET_CONFIGS_V14 10
typedef struct {
    pd_ConfigOpBalanceOfT_V14_t min_join_bond;
    pd_ConfigOpBalanceOfT_V14_t min_create_bond;
    pd_ConfigOpu32_V14_t max_pools;
    pd_ConfigOpu32_V14_t max_members;
    pd_ConfigOpu32_V14_t max_members_per_pool;
} pd_nominationpools_set_configs_V14_t;

#define PD_CALL_NOMINATIONPOOLS_UPDATE_ROLES_V14 11
typedef struct {
    pd_PoolId_V14_t pool_id;
    pd_ConfigOpAccountId_V14_t new_root;
    pd_ConfigOpAccountId_V14_t new_nominator;
    pd_ConfigOpAccountId_V14_t new_state_toggler;
} pd_nominationpools_update_roles_V14_t;

#define PD_CALL_NOMINATIONPOOLS_CHILL_V14 12
typedef struct {
    pd_PoolId_V14_t pool_id;
} pd_nominationpools_chill_V14_t;

#define PD_CALL_CONFIGURATION_SET_VALIDATION_UPGRADE_COOLDOWN_V14 0
typedef struct {
    pd_BlockNumber_t new_;
} pd_configuration_set_validation_upgrade_cooldown_V14_t;

#define PD_CALL_CONFIGURATION_SET_VALIDATION_UPGRADE_DELAY_V14 1
typedef struct {
    pd_BlockNumber_t new_;
} pd_configuration_set_validation_upgrade_delay_V14_t;

#define PD_CALL_CONFIGURATION_SET_CODE_RETENTION_PERIOD_V14 2
typedef struct {
    pd_BlockNumber_t new_;
} pd_configuration_set_code_retention_period_V14_t;

#define PD_CALL_CONFIGURATION_SET_MAX_CODE_SIZE_V14 3
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_max_code_size_V14_t;

#define PD_CALL_CONFIGURATION_SET_MAX_POV_SIZE_V14 4
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_max_pov_size_V14_t;

#define PD_CALL_CONFIGURATION_SET_MAX_HEAD_DATA_SIZE_V14 5
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_max_head_data_size_V14_t;

#define PD_CALL_CONFIGURATION_SET_PARATHREAD_CORES_V14 6
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_parathread_cores_V14_t;

#define PD_CALL_CONFIGURATION_SET_PARATHREAD_RETRIES_V14 7
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_parathread_retries_V14_t;

#define PD_CALL_CONFIGURATION_SET_GROUP_ROTATION_FREQUENCY_V14 8
typedef struct {
    pd_BlockNumber_t new_;
} pd_configuration_set_group_rotation_frequency_V14_t;

#define PD_CALL_CONFIGURATION_SET_CHAIN_AVAILABILITY_PERIOD_V14 9
typedef struct {
    pd_BlockNumber_t new_;
} pd_configuration_set_chain_availability_period_V14_t;

#define PD_CALL_CONFIGURATION_SET_THREAD_AVAILABILITY_PERIOD_V14 10
typedef struct {
    pd_BlockNumber_t new_;
} pd_configuration_set_thread_availability_period_V14_t;

#define PD_CALL_CONFIGURATION_SET_SCHEDULING_LOOKAHEAD_V14 11
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_scheduling_lookahead_V14_t;

#define PD_CALL_CONFIGURATION_SET_MAX_VALIDATORS_PER_CORE_V14 12
typedef struct {
    pd_Optionu32_t new_;
} pd_configuration_set_max_validators_per_core_V14_t;

#define PD_CALL_CONFIGURATION_SET_MAX_VALIDATORS_V14 13
typedef struct {
    pd_Optionu32_t new_;
} pd_configuration_set_max_validators_V14_t;

#define PD_CALL_CONFIGURATION_SET_DISPUTE_POST_CONCLUSION_ACCEPTANCE_PERIOD_V14 15
typedef struct {
    pd_BlockNumber_t new_;
} pd_configuration_set_dispute_post_conclusion_acceptance_period_V14_t;

#define PD_CALL_CONFIGURATION_SET_DISPUTE_MAX_SPAM_SLOTS_V14 16
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_dispute_max_spam_slots_V14_t;

#define PD_CALL_CONFIGURATION_SET_DISPUTE_CONCLUSION_BY_TIME_OUT_PERIOD_V14 17
typedef struct {
    pd_BlockNumber_t new_;
} pd_configuration_set_dispute_conclusion_by_time_out_period_V14_t;

#define PD_CALL_CONFIGURATION_SET_NO_SHOW_SLOTS_V14 18
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_no_show_slots_V14_t;

#define PD_CALL_CONFIGURATION_SET_N_DELAY_TRANCHES_V14 19
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_n_delay_tranches_V14_t;

#define PD_CALL_CONFIGURATION_SET_ZEROTH_DELAY_TRANCHE_WIDTH_V14 20
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_zeroth_delay_tranche_width_V14_t;

#define PD_CALL_CONFIGURATION_SET_NEEDED_APPROVALS_V14 21
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_needed_approvals_V14_t;

#define PD_CALL_CONFIGURATION_SET_RELAY_VRF_MODULO_SAMPLES_V14 22
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_relay_vrf_modulo_samples_V14_t;

#define PD_CALL_CONFIGURATION_SET_MAX_UPWARD_QUEUE_COUNT_V14 23
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_max_upward_queue_count_V14_t;

#define PD_CALL_CONFIGURATION_SET_MAX_UPWARD_QUEUE_SIZE_V14 24
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_max_upward_queue_size_V14_t;

#define PD_CALL_CONFIGURATION_SET_MAX_DOWNWARD_MESSAGE_SIZE_V14 25
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_max_downward_message_size_V14_t;

#define PD_CALL_CONFIGURATION_SET_UMP_SERVICE_TOTAL_WEIGHT_V14 26
typedef struct {
    pd_Weight_V14_t new_;
} pd_configuration_set_ump_service_total_weight_V14_t;

#define PD_CALL_CONFIGURATION_SET_MAX_UPWARD_MESSAGE_SIZE_V14 27
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_max_upward_message_size_V14_t;

#define PD_CALL_CONFIGURATION_SET_MAX_UPWARD_MESSAGE_NUM_PER_CANDIDATE_V14 28
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_max_upward_message_num_per_candidate_V14_t;

#define PD_CALL_CONFIGURATION_SET_HRMP_OPEN_REQUEST_TTL_V14 29
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_hrmp_open_request_ttl_V14_t;

#define PD_CALL_CONFIGURATION_SET_HRMP_SENDER_DEPOSIT_V14 30
typedef struct {
    pd_Balance_t new_;
} pd_configuration_set_hrmp_sender_deposit_V14_t;

#define PD_CALL_CONFIGURATION_SET_HRMP_RECIPIENT_DEPOSIT_V14 31
typedef struct {
    pd_Balance_t new_;
} pd_configuration_set_hrmp_recipient_deposit_V14_t;

#define PD_CALL_CONFIGURATION_SET_HRMP_CHANNEL_MAX_CAPACITY_V14 32
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_hrmp_channel_max_capacity_V14_t;

#define PD_CALL_CONFIGURATION_SET_HRMP_CHANNEL_MAX_TOTAL_SIZE_V14 33
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_hrmp_channel_max_total_size_V14_t;

#define PD_CALL_CONFIGURATION_SET_HRMP_MAX_PARACHAIN_INBOUND_CHANNELS_V14 34
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_hrmp_max_parachain_inbound_channels_V14_t;

#define PD_CALL_CONFIGURATION_SET_HRMP_MAX_PARATHREAD_INBOUND_CHANNELS_V14 35
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_hrmp_max_parathread_inbound_channels_V14_t;

#define PD_CALL_CONFIGURATION_SET_HRMP_CHANNEL_MAX_MESSAGE_SIZE_V14 36
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_hrmp_channel_max_message_size_V14_t;

#define PD_CALL_CONFIGURATION_SET_HRMP_MAX_PARACHAIN_OUTBOUND_CHANNELS_V14 37
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_hrmp_max_parachain_outbound_channels_V14_t;

#define PD_CALL_CONFIGURATION_SET_HRMP_MAX_PARATHREAD_OUTBOUND_CHANNELS_V14 38
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_hrmp_max_parathread_outbound_channels_V14_t;

#define PD_CALL_CONFIGURATION_SET_HRMP_MAX_MESSAGE_NUM_PER_CANDIDATE_V14 39
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_hrmp_max_message_num_per_candidate_V14_t;

#define PD_CALL_CONFIGURATION_SET_UMP_MAX_INDIVIDUAL_WEIGHT_V14 40
typedef struct {
    pd_Weight_V14_t new_;
} pd_configuration_set_ump_max_individual_weight_V14_t;

#define PD_CALL_CONFIGURATION_SET_PVF_CHECKING_ENABLED_V14 41
typedef struct {
    pd_bool_t new_;
} pd_configuration_set_pvf_checking_enabled_V14_t;

#define PD_CALL_CONFIGURATION_SET_PVF_VOTING_TTL_V14 42
typedef struct {
    pd_SessionIndex_V14_t new_;
} pd_configuration_set_pvf_voting_ttl_V14_t;

#define PD_CALL_CONFIGURATION_SET_MINIMUM_VALIDATION_UPGRADE_DELAY_V14 43
typedef struct {
    pd_BlockNumber_t new_;
} pd_configuration_set_minimum_validation_upgrade_delay_V14_t;

#define PD_CALL_CONFIGURATION_SET_BYPASS_CONSISTENCY_CHECK_V14 44
typedef struct {
    pd_bool_t new_;
} pd_configuration_set_bypass_consistency_check_V14_t;

#define PD_CALL_INITIALIZER_FORCE_APPROVE_V14 0
typedef struct {
    pd_BlockNumber_t up_to;
} pd_initializer_force_approve_V14_t;

#define PD_CALL_UMP_SERVICE_OVERWEIGHT_V14 0
typedef struct {
    pd_OverweightIndex_V14_t index;
    pd_Weight_V14_t weight_limit;
} pd_ump_service_overweight_V14_t;

#define PD_CALL_HRMP_FORCE_PROCESS_HRMP_OPEN_V14 4
typedef struct {
    pd_u32_t channels;
} pd_hrmp_force_process_hrmp_open_V14_t;

#define PD_CALL_HRMP_FORCE_PROCESS_HRMP_CLOSE_V14 5
typedef struct {
    pd_u32_t channels;
} pd_hrmp_force_process_hrmp_close_V14_t;

#define PD_CALL_PARASDISPUTES_FORCE_UNFREEZE_V14 0
typedef struct {
} pd_parasdisputes_force_unfreeze_V14_t;

#define PD_CALL_REGISTRAR_RESERVE_V14 5
typedef struct {
} pd_registrar_reserve_V14_t;

#define PD_CALL_AUCTIONS_NEW_AUCTION_V14 0
typedef struct {
    pd_Compactu32_t duration;
    pd_Compactu32_t lease_period_index;
} pd_auctions_new_auction_V14_t;

#define PD_CALL_AUCTIONS_BID_V14 1
typedef struct {
    pd_Compactu32_t para;
    pd_Compactu32_t auction_index;
    pd_Compactu32_t first_slot;
    pd_Compactu32_t last_slot;
    pd_CompactBalance_t amount;
} pd_auctions_bid_V14_t;

#define PD_CALL_AUCTIONS_CANCEL_AUCTION_V14 2
typedef struct {
} pd_auctions_cancel_auction_V14_t;

#endif

typedef union {
    pd_balances_transfer_all_V14_t balances_transfer_all_V14;
    pd_staking_bond_V14_t staking_bond_V14;
    pd_staking_bond_extra_V14_t staking_bond_extra_V14;
    pd_staking_unbond_V14_t staking_unbond_V14;
    pd_staking_withdraw_unbonded_V14_t staking_withdraw_unbonded_V14;
    pd_staking_validate_V14_t staking_validate_V14;
    pd_staking_nominate_V14_t staking_nominate_V14;
    pd_staking_chill_V14_t staking_chill_V14;
    pd_staking_set_payee_V14_t staking_set_payee_V14;
    pd_staking_set_controller_V14_t staking_set_controller_V14;
    pd_staking_payout_stakers_V14_t staking_payout_stakers_V14;
    pd_staking_rebond_V14_t staking_rebond_V14;
    pd_session_set_keys_V14_t session_set_keys_V14;
    pd_session_purge_keys_V14_t session_purge_keys_V14;
    pd_utility_batch_V14_t utility_batch_V14;
    pd_utility_batch_all_V14_t utility_batch_all_V14;
    pd_utility_force_batch_V14_t utility_force_batch_V14;
    pd_crowdloan_create_V14_t crowdloan_create_V14;
    pd_crowdloan_contribute_V14_t crowdloan_contribute_V14;
    pd_crowdloan_withdraw_V14_t crowdloan_withdraw_V14;
    pd_crowdloan_refund_V14_t crowdloan_refund_V14;
    pd_crowdloan_dissolve_V14_t crowdloan_dissolve_V14;
    pd_crowdloan_edit_V14_t crowdloan_edit_V14;
    pd_crowdloan_add_memo_V14_t crowdloan_add_memo_V14;
    pd_crowdloan_poke_V14_t crowdloan_poke_V14;
    pd_crowdloan_contribute_all_V14_t crowdloan_contribute_all_V14;
#ifdef SUBSTRATE_PARSER_FULL
    pd_preimage_note_preimage_V14_t preimage_note_preimage_V14;
    pd_preimage_unnote_preimage_V14_t preimage_unnote_preimage_V14;
    pd_preimage_request_preimage_V14_t preimage_request_preimage_V14;
    pd_preimage_unrequest_preimage_V14_t preimage_unrequest_preimage_V14;
    pd_timestamp_set_V14_t timestamp_set_V14;
    pd_indices_claim_V14_t indices_claim_V14;
    pd_indices_transfer_V14_t indices_transfer_V14;
    pd_indices_free_V14_t indices_free_V14;
    pd_indices_force_transfer_V14_t indices_force_transfer_V14;
    pd_indices_freeze_V14_t indices_freeze_V14;
    pd_balances_force_unreserve_V14_t balances_force_unreserve_V14;
    pd_staking_set_validator_count_V14_t staking_set_validator_count_V14;
    pd_staking_increase_validator_count_V14_t staking_increase_validator_count_V14;
    pd_staking_force_no_eras_V14_t staking_force_no_eras_V14;
    pd_staking_force_new_era_V14_t staking_force_new_era_V14;
    pd_staking_set_invulnerables_V14_t staking_set_invulnerables_V14;
    pd_staking_force_unstake_V14_t staking_force_unstake_V14;
    pd_staking_force_new_era_always_V14_t staking_force_new_era_always_V14;
    pd_staking_cancel_deferred_slash_V14_t staking_cancel_deferred_slash_V14;
    pd_staking_set_history_depth_V14_t staking_set_history_depth_V14;
    pd_staking_reap_stash_V14_t staking_reap_stash_V14;
    pd_staking_kick_V14_t staking_kick_V14;
    pd_staking_chill_other_V14_t staking_chill_other_V14;
    pd_staking_force_apply_min_commission_V14_t staking_force_apply_min_commission_V14;
    pd_grandpa_note_stalled_V14_t grandpa_note_stalled_V14;
    pd_democracy_note_preimage_V14_t democracy_note_preimage_V14;
    pd_democracy_note_preimage_operational_V14_t democracy_note_preimage_operational_V14;
    pd_democracy_note_imminent_preimage_V14_t democracy_note_imminent_preimage_V14;
    pd_democracy_note_imminent_preimage_operational_V14_t democracy_note_imminent_preimage_operational_V14;
    pd_council_set_members_V14_t council_set_members_V14;
    pd_council_execute_V14_t council_execute_V14;
    pd_council_propose_V14_t council_propose_V14;
    pd_council_vote_V14_t council_vote_V14;
    pd_council_close_V14_t council_close_V14;
    pd_council_disapprove_proposal_V14_t council_disapprove_proposal_V14;
    pd_technicalcommittee_set_members_V14_t technicalcommittee_set_members_V14;
    pd_technicalcommittee_execute_V14_t technicalcommittee_execute_V14;
    pd_technicalcommittee_propose_V14_t technicalcommittee_propose_V14;
    pd_technicalcommittee_vote_V14_t technicalcommittee_vote_V14;
    pd_technicalcommittee_close_V14_t technicalcommittee_close_V14;
    pd_technicalcommittee_disapprove_proposal_V14_t technicalcommittee_disapprove_proposal_V14;
    pd_phragmenelection_vote_V14_t phragmenelection_vote_V14;
    pd_phragmenelection_remove_voter_V14_t phragmenelection_remove_voter_V14;
    pd_phragmenelection_submit_candidacy_V14_t phragmenelection_submit_candidacy_V14;
    pd_phragmenelection_remove_member_V14_t phragmenelection_remove_member_V14;
    pd_phragmenelection_clean_defunct_voters_V14_t phragmenelection_clean_defunct_voters_V14;
    pd_technicalmembership_add_member_V14_t technicalmembership_add_member_V14;
    pd_technicalmembership_remove_member_V14_t technicalmembership_remove_member_V14;
    pd_technicalmembership_swap_member_V14_t technicalmembership_swap_member_V14;
    pd_technicalmembership_reset_members_V14_t technicalmembership_reset_members_V14;
    pd_technicalmembership_change_key_V14_t technicalmembership_change_key_V14;
    pd_technicalmembership_set_prime_V14_t technicalmembership_set_prime_V14;
    pd_technicalmembership_clear_prime_V14_t technicalmembership_clear_prime_V14;
    pd_treasury_propose_spend_V14_t treasury_propose_spend_V14;
    pd_treasury_reject_proposal_V14_t treasury_reject_proposal_V14;
    pd_treasury_approve_proposal_V14_t treasury_approve_proposal_V14;
    pd_treasury_spend_V14_t treasury_spend_V14;
    pd_treasury_remove_approval_V14_t treasury_remove_approval_V14;
    pd_claims_claim_V14_t claims_claim_V14;
    pd_claims_claim_attest_V14_t claims_claim_attest_V14;
    pd_claims_attest_V14_t claims_attest_V14;
    pd_claims_move_claim_V14_t claims_move_claim_V14;
    pd_vesting_vest_V14_t vesting_vest_V14;
    pd_vesting_vest_other_V14_t vesting_vest_other_V14;
    pd_vesting_vested_transfer_V14_t vesting_vested_transfer_V14;
    pd_vesting_force_vested_transfer_V14_t vesting_force_vested_transfer_V14;
    pd_vesting_merge_schedules_V14_t vesting_merge_schedules_V14;
    pd_identity_add_registrar_V14_t identity_add_registrar_V14;
    pd_identity_clear_identity_V14_t identity_clear_identity_V14;
    pd_identity_request_judgement_V14_t identity_request_judgement_V14;
    pd_identity_cancel_request_V14_t identity_cancel_request_V14;
    pd_identity_set_fee_V14_t identity_set_fee_V14;
    pd_identity_set_account_id_V14_t identity_set_account_id_V14;
    pd_identity_kill_identity_V14_t identity_kill_identity_V14;
    pd_identity_remove_sub_V14_t identity_remove_sub_V14;
    pd_identity_quit_sub_V14_t identity_quit_sub_V14;
    pd_proxy_add_proxy_V14_t proxy_add_proxy_V14;
    pd_proxy_remove_proxy_V14_t proxy_remove_proxy_V14;
    pd_proxy_remove_proxies_V14_t proxy_remove_proxies_V14;
    pd_proxy_anonymous_V14_t proxy_anonymous_V14;
    pd_proxy_kill_anonymous_V14_t proxy_kill_anonymous_V14;
    pd_proxy_proxy_announced_V14_t proxy_proxy_announced_V14;
    pd_bounties_propose_bounty_V14_t bounties_propose_bounty_V14;
    pd_bounties_approve_bounty_V14_t bounties_approve_bounty_V14;
    pd_bounties_propose_curator_V14_t bounties_propose_curator_V14;
    pd_bounties_unassign_curator_V14_t bounties_unassign_curator_V14;
    pd_bounties_accept_curator_V14_t bounties_accept_curator_V14;
    pd_bounties_award_bounty_V14_t bounties_award_bounty_V14;
    pd_bounties_claim_bounty_V14_t bounties_claim_bounty_V14;
    pd_bounties_close_bounty_V14_t bounties_close_bounty_V14;
    pd_bounties_extend_bounty_expiry_V14_t bounties_extend_bounty_expiry_V14;
    pd_childbounties_add_child_bounty_V14_t childbounties_add_child_bounty_V14;
    pd_childbounties_propose_curator_V14_t childbounties_propose_curator_V14;
    pd_childbounties_accept_curator_V14_t childbounties_accept_curator_V14;
    pd_childbounties_unassign_curator_V14_t childbounties_unassign_curator_V14;
    pd_childbounties_award_child_bounty_V14_t childbounties_award_child_bounty_V14;
    pd_childbounties_claim_child_bounty_V14_t childbounties_claim_child_bounty_V14;
    pd_childbounties_close_child_bounty_V14_t childbounties_close_child_bounty_V14;
    pd_tips_report_awesome_V14_t tips_report_awesome_V14;
    pd_tips_retract_tip_V14_t tips_retract_tip_V14;
    pd_tips_tip_new_V14_t tips_tip_new_V14;
    pd_tips_tip_V14_t tips_tip_V14;
    pd_tips_close_tip_V14_t tips_close_tip_V14;
    pd_tips_slash_tip_V14_t tips_slash_tip_V14;
    pd_electionprovidermultiphase_governance_fallback_V14_t electionprovidermultiphase_governance_fallback_V14;
    pd_voterlist_rebag_V14_t voterlist_rebag_V14;
    pd_voterlist_put_in_front_of_V14_t voterlist_put_in_front_of_V14;
    pd_nominationpools_join_V14_t nominationpools_join_V14;
    pd_nominationpools_bond_extra_V14_t nominationpools_bond_extra_V14;
    pd_nominationpools_claim_payout_V14_t nominationpools_claim_payout_V14;
    pd_nominationpools_unbond_V14_t nominationpools_unbond_V14;
    pd_nominationpools_pool_withdraw_unbonded_V14_t nominationpools_pool_withdraw_unbonded_V14;
    pd_nominationpools_withdraw_unbonded_V14_t nominationpools_withdraw_unbonded_V14;
    pd_nominationpools_create_V14_t nominationpools_create_V14;
    pd_nominationpools_nominate_V14_t nominationpools_nominate_V14;
    pd_nominationpools_set_state_V14_t nominationpools_set_state_V14;
    pd_nominationpools_set_metadata_V14_t nominationpools_set_metadata_V14;
    pd_nominationpools_set_configs_V14_t nominationpools_set_configs_V14;
    pd_nominationpools_update_roles_V14_t nominationpools_update_roles_V14;
    pd_nominationpools_chill_V14_t nominationpools_chill_V14;
    pd_configuration_set_validation_upgrade_cooldown_V14_t configuration_set_validation_upgrade_cooldown_V14;
    pd_configuration_set_validation_upgrade_delay_V14_t configuration_set_validation_upgrade_delay_V14;
    pd_configuration_set_code_retention_period_V14_t configuration_set_code_retention_period_V14;
    pd_configuration_set_max_code_size_V14_t configuration_set_max_code_size_V14;
    pd_configuration_set_max_pov_size_V14_t configuration_set_max_pov_size_V14;
    pd_configuration_set_max_head_data_size_V14_t configuration_set_max_head_data_size_V14;
    pd_configuration_set_parathread_cores_V14_t configuration_set_parathread_cores_V14;
    pd_configuration_set_parathread_retries_V14_t configuration_set_parathread_retries_V14;
    pd_configuration_set_group_rotation_frequency_V14_t configuration_set_group_rotation_frequency_V14;
    pd_configuration_set_chain_availability_period_V14_t configuration_set_chain_availability_period_V14;
    pd_configuration_set_thread_availability_period_V14_t configuration_set_thread_availability_period_V14;
    pd_configuration_set_scheduling_lookahead_V14_t configuration_set_scheduling_lookahead_V14;
    pd_configuration_set_max_validators_per_core_V14_t configuration_set_max_validators_per_core_V14;
    pd_configuration_set_max_validators_V14_t configuration_set_max_validators_V14;
    pd_configuration_set_dispute_post_conclusion_acceptance_period_V14_t configuration_set_dispute_post_conclusion_acceptance_period_V14;
    pd_configuration_set_dispute_max_spam_slots_V14_t configuration_set_dispute_max_spam_slots_V14;
    pd_configuration_set_dispute_conclusion_by_time_out_period_V14_t configuration_set_dispute_conclusion_by_time_out_period_V14;
    pd_configuration_set_no_show_slots_V14_t configuration_set_no_show_slots_V14;
    pd_configuration_set_n_delay_tranches_V14_t configuration_set_n_delay_tranches_V14;
    pd_configuration_set_zeroth_delay_tranche_width_V14_t configuration_set_zeroth_delay_tranche_width_V14;
    pd_configuration_set_needed_approvals_V14_t configuration_set_needed_approvals_V14;
    pd_configuration_set_relay_vrf_modulo_samples_V14_t configuration_set_relay_vrf_modulo_samples_V14;
    pd_configuration_set_max_upward_queue_count_V14_t configuration_set_max_upward_queue_count_V14;
    pd_configuration_set_max_upward_queue_size_V14_t configuration_set_max_upward_queue_size_V14;
    pd_configuration_set_max_downward_message_size_V14_t configuration_set_max_downward_message_size_V14;
    pd_configuration_set_ump_service_total_weight_V14_t configuration_set_ump_service_total_weight_V14;
    pd_configuration_set_max_upward_message_size_V14_t configuration_set_max_upward_message_size_V14;
    pd_configuration_set_max_upward_message_num_per_candidate_V14_t configuration_set_max_upward_message_num_per_candidate_V14;
    pd_configuration_set_hrmp_open_request_ttl_V14_t configuration_set_hrmp_open_request_ttl_V14;
    pd_configuration_set_hrmp_sender_deposit_V14_t configuration_set_hrmp_sender_deposit_V14;
    pd_configuration_set_hrmp_recipient_deposit_V14_t configuration_set_hrmp_recipient_deposit_V14;
    pd_configuration_set_hrmp_channel_max_capacity_V14_t configuration_set_hrmp_channel_max_capacity_V14;
    pd_configuration_set_hrmp_channel_max_total_size_V14_t configuration_set_hrmp_channel_max_total_size_V14;
    pd_configuration_set_hrmp_max_parachain_inbound_channels_V14_t configuration_set_hrmp_max_parachain_inbound_channels_V14;
    pd_configuration_set_hrmp_max_parathread_inbound_channels_V14_t configuration_set_hrmp_max_parathread_inbound_channels_V14;
    pd_configuration_set_hrmp_channel_max_message_size_V14_t configuration_set_hrmp_channel_max_message_size_V14;
    pd_configuration_set_hrmp_max_parachain_outbound_channels_V14_t configuration_set_hrmp_max_parachain_outbound_channels_V14;
    pd_configuration_set_hrmp_max_parathread_outbound_channels_V14_t configuration_set_hrmp_max_parathread_outbound_channels_V14;
    pd_configuration_set_hrmp_max_message_num_per_candidate_V14_t configuration_set_hrmp_max_message_num_per_candidate_V14;
    pd_configuration_set_ump_max_individual_weight_V14_t configuration_set_ump_max_individual_weight_V14;
    pd_configuration_set_pvf_checking_enabled_V14_t configuration_set_pvf_checking_enabled_V14;
    pd_configuration_set_pvf_voting_ttl_V14_t configuration_set_pvf_voting_ttl_V14;
    pd_configuration_set_minimum_validation_upgrade_delay_V14_t configuration_set_minimum_validation_upgrade_delay_V14;
    pd_configuration_set_bypass_consistency_check_V14_t configuration_set_bypass_consistency_check_V14;
    pd_initializer_force_approve_V14_t initializer_force_approve_V14;
    pd_ump_service_overweight_V14_t ump_service_overweight_V14;
    pd_hrmp_force_process_hrmp_open_V14_t hrmp_force_process_hrmp_open_V14;
    pd_hrmp_force_process_hrmp_close_V14_t hrmp_force_process_hrmp_close_V14;
    pd_parasdisputes_force_unfreeze_V14_t parasdisputes_force_unfreeze_V14;
    pd_registrar_reserve_V14_t registrar_reserve_V14;
    pd_auctions_new_auction_V14_t auctions_new_auction_V14;
    pd_auctions_bid_V14_t auctions_bid_V14;
    pd_auctions_cancel_auction_V14_t auctions_cancel_auction_V14;
#endif
} pd_MethodBasic_V14_t;

#define PD_CALL_BALANCES_TRANSFER_V14 0
typedef struct {
    pd_AccountIdLookupOfT_V14_t dest;
    pd_CompactBalance_t amount;
} pd_balances_transfer_V14_t;

#define PD_CALL_BALANCES_FORCE_TRANSFER_V14 2
typedef struct {
    pd_AccountIdLookupOfT_V14_t source;
    pd_AccountIdLookupOfT_V14_t dest;
    pd_CompactBalance_t amount;
} pd_balances_force_transfer_V14_t;

#define PD_CALL_BALANCES_TRANSFER_KEEP_ALIVE_V14 3
typedef struct {
    pd_AccountIdLookupOfT_V14_t dest;
    pd_CompactBalance_t amount;
} pd_balances_transfer_keep_alive_V14_t;

#ifdef SUBSTRATE_PARSER_FULL
#define PD_CALL_SYSTEM_FILL_BLOCK_V14 0
typedef struct {
    pd_Perbill_V14_t ratio;
} pd_system_fill_block_V14_t;

#define PD_CALL_SYSTEM_REMARK_V14 1
typedef struct {
    pd_Vecu8_t remark;
} pd_system_remark_V14_t;

#define PD_CALL_SYSTEM_SET_HEAP_PAGES_V14 2
typedef struct {
    pd_u64_t pages;
} pd_system_set_heap_pages_V14_t;

#define PD_CALL_SYSTEM_SET_CODE_V14 3
typedef struct {
    pd_Vecu8_t code;
} pd_system_set_code_V14_t;

#define PD_CALL_SYSTEM_SET_CODE_WITHOUT_CHECKS_V14 4
typedef struct {
    pd_Vecu8_t code;
} pd_system_set_code_without_checks_V14_t;

#define PD_CALL_SYSTEM_REMARK_WITH_EVENT_V14 8
typedef struct {
    pd_Vecu8_t remark;
} pd_system_remark_with_event_V14_t;

#define PD_CALL_BALANCES_SET_BALANCE_V14 1
typedef struct {
    pd_AccountIdLookupOfT_V14_t who;
    pd_CompactBalance_t new_free;
    pd_CompactBalance_t new_reserved;
} pd_balances_set_balance_V14_t;

#define PD_CALL_DEMOCRACY_PROPOSE_V14 0
typedef struct {
    pd_Hash_t proposal_hash;
    pd_CompactBalance_t amount;
} pd_democracy_propose_V14_t;

#define PD_CALL_DEMOCRACY_SECOND_V14 1
typedef struct {
    pd_Compactu32_t proposal;
    pd_Compactu32_t seconds_upper_bound;
} pd_democracy_second_V14_t;

#define PD_CALL_DEMOCRACY_VOTE_V14 2
typedef struct {
    pd_Compactu32_t ref_index;
    pd_AccountVote_V14_t vote;
} pd_democracy_vote_V14_t;

#define PD_CALL_DEMOCRACY_EMERGENCY_CANCEL_V14 3
typedef struct {
    pd_ReferendumIndex_V14_t ref_index;
} pd_democracy_emergency_cancel_V14_t;

#define PD_CALL_DEMOCRACY_EXTERNAL_PROPOSE_V14 4
typedef struct {
    pd_Hash_t proposal_hash;
} pd_democracy_external_propose_V14_t;

#define PD_CALL_DEMOCRACY_EXTERNAL_PROPOSE_MAJORITY_V14 5
typedef struct {
    pd_Hash_t proposal_hash;
} pd_democracy_external_propose_majority_V14_t;

#define PD_CALL_DEMOCRACY_EXTERNAL_PROPOSE_DEFAULT_V14 6
typedef struct {
    pd_Hash_t proposal_hash;
} pd_democracy_external_propose_default_V14_t;

#define PD_CALL_DEMOCRACY_FAST_TRACK_V14 7
typedef struct {
    pd_Hash_t proposal_hash;
    pd_BlockNumber_t voting_period;
    pd_BlockNumber_t delay;
} pd_democracy_fast_track_V14_t;

#define PD_CALL_DEMOCRACY_VETO_EXTERNAL_V14 8
typedef struct {
    pd_Hash_t proposal_hash;
} pd_democracy_veto_external_V14_t;

#define PD_CALL_DEMOCRACY_CANCEL_REFERENDUM_V14 9
typedef struct {
    pd_Compactu32_t ref_index;
} pd_democracy_cancel_referendum_V14_t;

#define PD_CALL_DEMOCRACY_CANCEL_QUEUED_V14 10
typedef struct {
    pd_ReferendumIndex_V14_t which;
} pd_democracy_cancel_queued_V14_t;

#define PD_CALL_DEMOCRACY_DELEGATE_V14 11
typedef struct {
    pd_AccountIdLookupOfT_V14_t to;
    pd_Conviction_V14_t conviction;
    pd_Balance_t balance;
} pd_democracy_delegate_V14_t;

#define PD_CALL_DEMOCRACY_UNDELEGATE_V14 12
typedef struct {
} pd_democracy_undelegate_V14_t;

#define PD_CALL_DEMOCRACY_CLEAR_PUBLIC_PROPOSALS_V14 13
typedef struct {
} pd_democracy_clear_public_proposals_V14_t;

#define PD_CALL_DEMOCRACY_REAP_PREIMAGE_V14 18
typedef struct {
    pd_Hash_t proposal_hash;
    pd_Compactu32_t proposal_len_upper_bound;
} pd_democracy_reap_preimage_V14_t;

#define PD_CALL_DEMOCRACY_UNLOCK_V14 19
typedef struct {
    pd_AccountIdLookupOfT_V14_t target;
} pd_democracy_unlock_V14_t;

#define PD_CALL_DEMOCRACY_REMOVE_VOTE_V14 20
typedef struct {
    pd_ReferendumIndex_V14_t index;
} pd_democracy_remove_vote_V14_t;

#define PD_CALL_DEMOCRACY_REMOVE_OTHER_VOTE_V14 21
typedef struct {
    pd_AccountIdLookupOfT_V14_t target;
    pd_ReferendumIndex_V14_t index;
} pd_democracy_remove_other_vote_V14_t;

#define PD_CALL_DEMOCRACY_ENACT_PROPOSAL_V14 22
typedef struct {
    pd_Hash_t proposal_hash;
    pd_ReferendumIndex_V14_t index;
} pd_democracy_enact_proposal_V14_t;

#define PD_CALL_DEMOCRACY_CANCEL_PROPOSAL_V14 24
typedef struct {
    pd_Compactu32_t prop_index;
} pd_democracy_cancel_proposal_V14_t;

#define PD_CALL_PROXY_PROXY_V14 0
typedef struct {
    pd_AccountIdLookupOfT_V14_t real;
    pd_OptionProxyType_V14_t force_proxy_type;
    pd_Call_t call;
} pd_proxy_proxy_V14_t;

#define PD_CALL_MULTISIG_AS_MULTI_THRESHOLD_1_V14 0
typedef struct {
    pd_VecAccountId_V14_t other_signatories;
    pd_Call_t call;
} pd_multisig_as_multi_threshold_1_V14_t;

#define PD_CALL_MULTISIG_AS_MULTI_V14 1
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_V14_t other_signatories;
    pd_OptionTimepoint_V14_t maybe_timepoint;
    pd_OpaqueCall_V14_t call;
    pd_bool_t store_call;
    pd_Weight_V14_t max_weight;
} pd_multisig_as_multi_V14_t;

#define PD_CALL_MULTISIG_APPROVE_AS_MULTI_V14 2
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_V14_t other_signatories;
    pd_OptionTimepoint_V14_t maybe_timepoint;
    pd_H256_t call_hash;
    pd_Weight_V14_t max_weight;
} pd_multisig_approve_as_multi_V14_t;

#define PD_CALL_MULTISIG_CANCEL_AS_MULTI_V14 3
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_V14_t other_signatories;
    pd_Timepoint_V14_t timepoint;
    pd_H256_t call_hash;
} pd_multisig_cancel_as_multi_V14_t;

#endif

typedef union {
    pd_balances_transfer_V14_t balances_transfer_V14;
    pd_balances_force_transfer_V14_t balances_force_transfer_V14;
    pd_balances_transfer_keep_alive_V14_t balances_transfer_keep_alive_V14;
#ifdef SUBSTRATE_PARSER_FULL
    pd_system_fill_block_V14_t system_fill_block_V14;
    pd_system_remark_V14_t system_remark_V14;
    pd_system_set_heap_pages_V14_t system_set_heap_pages_V14;
    pd_system_set_code_V14_t system_set_code_V14;
    pd_system_set_code_without_checks_V14_t system_set_code_without_checks_V14;
    pd_system_remark_with_event_V14_t system_remark_with_event_V14;
    pd_balances_set_balance_V14_t balances_set_balance_V14;
    pd_democracy_propose_V14_t democracy_propose_V14;
    pd_democracy_second_V14_t democracy_second_V14;
    pd_democracy_vote_V14_t democracy_vote_V14;
    pd_democracy_emergency_cancel_V14_t democracy_emergency_cancel_V14;
    pd_democracy_external_propose_V14_t democracy_external_propose_V14;
    pd_democracy_external_propose_majority_V14_t democracy_external_propose_majority_V14;
    pd_democracy_external_propose_default_V14_t democracy_external_propose_default_V14;
    pd_democracy_fast_track_V14_t democracy_fast_track_V14;
    pd_democracy_veto_external_V14_t democracy_veto_external_V14;
    pd_democracy_cancel_referendum_V14_t democracy_cancel_referendum_V14;
    pd_democracy_cancel_queued_V14_t democracy_cancel_queued_V14;
    pd_democracy_delegate_V14_t democracy_delegate_V14;
    pd_democracy_undelegate_V14_t democracy_undelegate_V14;
    pd_democracy_clear_public_proposals_V14_t democracy_clear_public_proposals_V14;
    pd_democracy_reap_preimage_V14_t democracy_reap_preimage_V14;
    pd_democracy_unlock_V14_t democracy_unlock_V14;
    pd_democracy_remove_vote_V14_t democracy_remove_vote_V14;
    pd_democracy_remove_other_vote_V14_t democracy_remove_other_vote_V14;
    pd_democracy_enact_proposal_V14_t democracy_enact_proposal_V14;
    pd_democracy_cancel_proposal_V14_t democracy_cancel_proposal_V14;
    pd_proxy_proxy_V14_t proxy_proxy_V14;
    pd_multisig_as_multi_threshold_1_V14_t multisig_as_multi_threshold_1_V14;
    pd_multisig_as_multi_V14_t multisig_as_multi_V14;
    pd_multisig_approve_as_multi_V14_t multisig_approve_as_multi_V14;
    pd_multisig_cancel_as_multi_V14_t multisig_cancel_as_multi_V14;
#endif
} pd_MethodNested_V14_t;

typedef union {
    pd_MethodBasic_V14_t basic;
    pd_MethodNested_V14_t nested;
} pd_Method_V14_t;

#ifdef __cplusplus
}
#endif

#pragma clang diagnostic pop
