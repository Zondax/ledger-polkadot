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

#include "substrate_dispatch_V6.h"
#include "substrate_strings.h"
#include "zxmacros.h"
#include <stdint.h>

__Z_INLINE parser_error_t _readMethod_balances_transfer_V6(
    parser_context_t* c, pd_balances_transfer_V6_t* m)
{
    CHECK_ERROR(_readLookupSource_V6(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_transfer_keep_alive_V6(
    parser_context_t* c, pd_balances_transfer_keep_alive_V6_t* m)
{
    CHECK_ERROR(_readLookupSource_V6(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_bond_V6(
    parser_context_t* c, pd_staking_bond_V6_t* m)
{
    CHECK_ERROR(_readLookupSource_V6(c, &m->controller))
    CHECK_ERROR(_readCompactBalanceOf(c, &m->value))
    CHECK_ERROR(_readRewardDestination_V6(c, &m->payee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_bond_extra_V6(
    parser_context_t* c, pd_staking_bond_extra_V6_t* m)
{
    CHECK_ERROR(_readCompactBalanceOf(c, &m->max_additional))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_unbond_V6(
    parser_context_t* c, pd_staking_unbond_V6_t* m)
{
    CHECK_ERROR(_readCompactBalanceOf(c, &m->value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_withdraw_unbonded_V6(
    parser_context_t* c, pd_staking_withdraw_unbonded_V6_t* m)
{
    CHECK_ERROR(_readu32(c, &m->num_slashing_spans))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_validate_V6(
    parser_context_t* c, pd_staking_validate_V6_t* m)
{
    CHECK_ERROR(_readValidatorPrefs_V6(c, &m->prefs))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_nominate_V6(
    parser_context_t* c, pd_staking_nominate_V6_t* m)
{
    CHECK_ERROR(_readVecLookupSource_V6(c, &m->targets))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_chill_V6(
    parser_context_t* c, pd_staking_chill_V6_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_payee_V6(
    parser_context_t* c, pd_staking_set_payee_V6_t* m)
{
    CHECK_ERROR(_readRewardDestination_V6(c, &m->payee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_payout_stakers_V6(
    parser_context_t* c, pd_staking_payout_stakers_V6_t* m)
{
    CHECK_ERROR(_readAccountId_V6(c, &m->validator_stash))
    CHECK_ERROR(_readEraIndex_V6(c, &m->era))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_rebond_V6(
    parser_context_t* c, pd_staking_rebond_V6_t* m)
{
    CHECK_ERROR(_readCompactBalanceOf(c, &m->value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_session_set_keys_V6(
    parser_context_t* c, pd_session_set_keys_V6_t* m)
{
    CHECK_ERROR(_readKeys_V6(c, &m->keys))
    CHECK_ERROR(_readBytes(c, &m->proof))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_session_purge_keys_V6(
    parser_context_t* c, pd_session_purge_keys_V6_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_batch_V6(
    parser_context_t* c, pd_utility_batch_V6_t* m)
{
    CHECK_ERROR(_readVecCall(c, &m->calls))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_batch_all_V6(
    parser_context_t* c, pd_utility_batch_all_V6_t* m)
{
    CHECK_ERROR(_readVecCall(c, &m->calls))
    return parser_ok;
}

#ifdef SUBSTRATE_PARSER_FULL
__Z_INLINE parser_error_t _readMethod_system_fill_block_V6(
    parser_context_t* c, pd_system_fill_block_V6_t* m)
{
    CHECK_ERROR(_readPerbill_V6(c, &m->_ratio))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_remark_V6(
    parser_context_t* c, pd_system_remark_V6_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->_remark))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_heap_pages_V6(
    parser_context_t* c, pd_system_set_heap_pages_V6_t* m)
{
    CHECK_ERROR(_readu64(c, &m->pages))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_code_V6(
    parser_context_t* c, pd_system_set_code_V6_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->code))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_code_without_checks_V6(
    parser_context_t* c, pd_system_set_code_without_checks_V6_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->code))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_changes_trie_config_V6(
    parser_context_t* c, pd_system_set_changes_trie_config_V6_t* m)
{
    CHECK_ERROR(_readOptionChangesTrieConfiguration_V6(c, &m->changes_trie_config))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_storage_V6(
    parser_context_t* c, pd_system_set_storage_V6_t* m)
{
    CHECK_ERROR(_readVecKeyValue_V6(c, &m->items))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_kill_storage_V6(
    parser_context_t* c, pd_system_kill_storage_V6_t* m)
{
    CHECK_ERROR(_readVecKey_V6(c, &m->keys))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_kill_prefix_V6(
    parser_context_t* c, pd_system_kill_prefix_V6_t* m)
{
    CHECK_ERROR(_readKey_V6(c, &m->prefix))
    CHECK_ERROR(_readu32(c, &m->_subkeys))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_scheduler_schedule_V6(
    parser_context_t* c, pd_scheduler_schedule_V6_t* m)
{
    CHECK_ERROR(_readBlockNumber(c, &m->when))
    CHECK_ERROR(_readOptionPeriod_V6(c, &m->maybe_periodic))
    CHECK_ERROR(_readPriority_V6(c, &m->priority))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_scheduler_cancel_V6(
    parser_context_t* c, pd_scheduler_cancel_V6_t* m)
{
    CHECK_ERROR(_readBlockNumber(c, &m->when))
    CHECK_ERROR(_readu32(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_scheduler_schedule_named_V6(
    parser_context_t* c, pd_scheduler_schedule_named_V6_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->id))
    CHECK_ERROR(_readBlockNumber(c, &m->when))
    CHECK_ERROR(_readOptionPeriod_V6(c, &m->maybe_periodic))
    CHECK_ERROR(_readPriority_V6(c, &m->priority))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_scheduler_cancel_named_V6(
    parser_context_t* c, pd_scheduler_cancel_named_V6_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_scheduler_schedule_after_V6(
    parser_context_t* c, pd_scheduler_schedule_after_V6_t* m)
{
    CHECK_ERROR(_readBlockNumber(c, &m->after))
    CHECK_ERROR(_readOptionPeriod_V6(c, &m->maybe_periodic))
    CHECK_ERROR(_readPriority_V6(c, &m->priority))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_scheduler_schedule_named_after_V6(
    parser_context_t* c, pd_scheduler_schedule_named_after_V6_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->id))
    CHECK_ERROR(_readBlockNumber(c, &m->after))
    CHECK_ERROR(_readOptionPeriod_V6(c, &m->maybe_periodic))
    CHECK_ERROR(_readPriority_V6(c, &m->priority))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_babe_report_equivocation_V6(
    parser_context_t* c, pd_babe_report_equivocation_V6_t* m)
{
    CHECK_ERROR(_readBabeEquivocationProof_V6(c, &m->equivocation_proof))
    CHECK_ERROR(_readKeyOwnerProof_V6(c, &m->key_owner_proof))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_babe_report_equivocation_unsigned_V6(
    parser_context_t* c, pd_babe_report_equivocation_unsigned_V6_t* m)
{
    CHECK_ERROR(_readBabeEquivocationProof_V6(c, &m->equivocation_proof))
    CHECK_ERROR(_readKeyOwnerProof_V6(c, &m->key_owner_proof))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_timestamp_set_V6(
    parser_context_t* c, pd_timestamp_set_V6_t* m)
{
    CHECK_ERROR(_readCompactMoment_V6(c, &m->now))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_indices_claim_V6(
    parser_context_t* c, pd_indices_claim_V6_t* m)
{
    CHECK_ERROR(_readAccountIndex_V6(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_indices_transfer_V6(
    parser_context_t* c, pd_indices_transfer_V6_t* m)
{
    CHECK_ERROR(_readAccountId_V6(c, &m->new_))
    CHECK_ERROR(_readAccountIndex_V6(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_indices_free_V6(
    parser_context_t* c, pd_indices_free_V6_t* m)
{
    CHECK_ERROR(_readAccountIndex_V6(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_indices_force_transfer_V6(
    parser_context_t* c, pd_indices_force_transfer_V6_t* m)
{
    CHECK_ERROR(_readAccountId_V6(c, &m->new_))
    CHECK_ERROR(_readAccountIndex_V6(c, &m->index))
    CHECK_ERROR(_readbool(c, &m->freeze))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_indices_freeze_V6(
    parser_context_t* c, pd_indices_freeze_V6_t* m)
{
    CHECK_ERROR(_readAccountIndex_V6(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_set_balance_V6(
    parser_context_t* c, pd_balances_set_balance_V6_t* m)
{
    CHECK_ERROR(_readLookupSource_V6(c, &m->who))
    CHECK_ERROR(_readCompactBalance(c, &m->new_free))
    CHECK_ERROR(_readCompactBalance(c, &m->new_reserved))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_force_transfer_V6(
    parser_context_t* c, pd_balances_force_transfer_V6_t* m)
{
    CHECK_ERROR(_readLookupSource_V6(c, &m->source))
    CHECK_ERROR(_readLookupSource_V6(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_authorship_set_uncles_V6(
    parser_context_t* c, pd_authorship_set_uncles_V6_t* m)
{
    CHECK_ERROR(_readVecHeader(c, &m->new_uncles))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_controller_V6(
    parser_context_t* c, pd_staking_set_controller_V6_t* m)
{
    CHECK_ERROR(_readLookupSource_V6(c, &m->controller))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_validator_count_V6(
    parser_context_t* c, pd_staking_set_validator_count_V6_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_increase_validator_count_V6(
    parser_context_t* c, pd_staking_increase_validator_count_V6_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->additional))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_scale_validator_count_V6(
    parser_context_t* c, pd_staking_scale_validator_count_V6_t* m)
{
    CHECK_ERROR(_readPercent_V6(c, &m->factor))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_no_eras_V6(
    parser_context_t* c, pd_staking_force_no_eras_V6_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_new_era_V6(
    parser_context_t* c, pd_staking_force_new_era_V6_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_invulnerables_V6(
    parser_context_t* c, pd_staking_set_invulnerables_V6_t* m)
{
    CHECK_ERROR(_readVecAccountId_V6(c, &m->invulnerables))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_unstake_V6(
    parser_context_t* c, pd_staking_force_unstake_V6_t* m)
{
    CHECK_ERROR(_readAccountId_V6(c, &m->stash))
    CHECK_ERROR(_readu32(c, &m->num_slashing_spans))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_new_era_always_V6(
    parser_context_t* c, pd_staking_force_new_era_always_V6_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_cancel_deferred_slash_V6(
    parser_context_t* c, pd_staking_cancel_deferred_slash_V6_t* m)
{
    CHECK_ERROR(_readEraIndex_V6(c, &m->era))
    CHECK_ERROR(_readVecu32(c, &m->slash_indices))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_history_depth_V6(
    parser_context_t* c, pd_staking_set_history_depth_V6_t* m)
{
    CHECK_ERROR(_readCompactEraIndex_V6(c, &m->new_history_depth))
    CHECK_ERROR(_readCompactu32(c, &m->_era_items_deleted))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_reap_stash_V6(
    parser_context_t* c, pd_staking_reap_stash_V6_t* m)
{
    CHECK_ERROR(_readAccountId_V6(c, &m->stash))
    CHECK_ERROR(_readu32(c, &m->num_slashing_spans))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_submit_election_solution_V6(
    parser_context_t* c, pd_staking_submit_election_solution_V6_t* m)
{
    CHECK_ERROR(_readVecValidatorIndex_V6(c, &m->winners))
    CHECK_ERROR(_readCompactAssignments_V6(c, &m->compact))
    CHECK_ERROR(_readElectionScore_V6(c, &m->score))
    CHECK_ERROR(_readEraIndex_V6(c, &m->era))
    CHECK_ERROR(_readElectionSize_V6(c, &m->size))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_submit_election_solution_unsigned_V6(
    parser_context_t* c, pd_staking_submit_election_solution_unsigned_V6_t* m)
{
    CHECK_ERROR(_readVecValidatorIndex_V6(c, &m->winners))
    CHECK_ERROR(_readCompactAssignments_V6(c, &m->compact))
    CHECK_ERROR(_readElectionScore_V6(c, &m->score))
    CHECK_ERROR(_readEraIndex_V6(c, &m->era))
    CHECK_ERROR(_readElectionSize_V6(c, &m->size))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_kick_V6(
    parser_context_t* c, pd_staking_kick_V6_t* m)
{
    CHECK_ERROR(_readVecLookupSource_V6(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_grandpa_report_equivocation_V6(
    parser_context_t* c, pd_grandpa_report_equivocation_V6_t* m)
{
    CHECK_ERROR(_readGrandpaEquivocationProof_V6(c, &m->equivocation_proof))
    CHECK_ERROR(_readKeyOwnerProof_V6(c, &m->key_owner_proof))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_grandpa_report_equivocation_unsigned_V6(
    parser_context_t* c, pd_grandpa_report_equivocation_unsigned_V6_t* m)
{
    CHECK_ERROR(_readGrandpaEquivocationProof_V6(c, &m->equivocation_proof))
    CHECK_ERROR(_readKeyOwnerProof_V6(c, &m->key_owner_proof))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_grandpa_note_stalled_V6(
    parser_context_t* c, pd_grandpa_note_stalled_V6_t* m)
{
    CHECK_ERROR(_readBlockNumber(c, &m->delay))
    CHECK_ERROR(_readBlockNumber(c, &m->best_finalized_block_number))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_imonline_heartbeat_V6(
    parser_context_t* c, pd_imonline_heartbeat_V6_t* m)
{
    CHECK_ERROR(_readHeartbeat(c, &m->heartbeat))
    CHECK_ERROR(_readSignature_V6(c, &m->_signature))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_propose_V6(
    parser_context_t* c, pd_democracy_propose_V6_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    CHECK_ERROR(_readCompactBalanceOf(c, &m->value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_second_V6(
    parser_context_t* c, pd_democracy_second_V6_t* m)
{
    CHECK_ERROR(_readCompactPropIndex_V6(c, &m->proposal))
    CHECK_ERROR(_readCompactu32(c, &m->seconds_upper_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_vote_V6(
    parser_context_t* c, pd_democracy_vote_V6_t* m)
{
    CHECK_ERROR(_readCompactReferendumIndex_V6(c, &m->ref_index))
    CHECK_ERROR(_readAccountVote_V6(c, &m->vote))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_emergency_cancel_V6(
    parser_context_t* c, pd_democracy_emergency_cancel_V6_t* m)
{
    CHECK_ERROR(_readReferendumIndex_V6(c, &m->ref_index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_external_propose_V6(
    parser_context_t* c, pd_democracy_external_propose_V6_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_external_propose_majority_V6(
    parser_context_t* c, pd_democracy_external_propose_majority_V6_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_external_propose_default_V6(
    parser_context_t* c, pd_democracy_external_propose_default_V6_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_fast_track_V6(
    parser_context_t* c, pd_democracy_fast_track_V6_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    CHECK_ERROR(_readBlockNumber(c, &m->voting_period))
    CHECK_ERROR(_readBlockNumber(c, &m->delay))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_veto_external_V6(
    parser_context_t* c, pd_democracy_veto_external_V6_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_cancel_referendum_V6(
    parser_context_t* c, pd_democracy_cancel_referendum_V6_t* m)
{
    CHECK_ERROR(_readCompactReferendumIndex_V6(c, &m->ref_index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_cancel_queued_V6(
    parser_context_t* c, pd_democracy_cancel_queued_V6_t* m)
{
    CHECK_ERROR(_readReferendumIndex_V6(c, &m->which))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_delegate_V6(
    parser_context_t* c, pd_democracy_delegate_V6_t* m)
{
    CHECK_ERROR(_readAccountId_V6(c, &m->to))
    CHECK_ERROR(_readConviction_V6(c, &m->conviction))
    CHECK_ERROR(_readBalanceOf(c, &m->balance))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_undelegate_V6(
    parser_context_t* c, pd_democracy_undelegate_V6_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_clear_public_proposals_V6(
    parser_context_t* c, pd_democracy_clear_public_proposals_V6_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_note_preimage_V6(
    parser_context_t* c, pd_democracy_note_preimage_V6_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->encoded_proposal))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_note_preimage_operational_V6(
    parser_context_t* c, pd_democracy_note_preimage_operational_V6_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->encoded_proposal))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_note_imminent_preimage_V6(
    parser_context_t* c, pd_democracy_note_imminent_preimage_V6_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->encoded_proposal))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_note_imminent_preimage_operational_V6(
    parser_context_t* c, pd_democracy_note_imminent_preimage_operational_V6_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->encoded_proposal))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_reap_preimage_V6(
    parser_context_t* c, pd_democracy_reap_preimage_V6_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    CHECK_ERROR(_readCompactu32(c, &m->proposal_len_upper_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_unlock_V6(
    parser_context_t* c, pd_democracy_unlock_V6_t* m)
{
    CHECK_ERROR(_readAccountId_V6(c, &m->target))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_remove_vote_V6(
    parser_context_t* c, pd_democracy_remove_vote_V6_t* m)
{
    CHECK_ERROR(_readReferendumIndex_V6(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_remove_other_vote_V6(
    parser_context_t* c, pd_democracy_remove_other_vote_V6_t* m)
{
    CHECK_ERROR(_readAccountId_V6(c, &m->target))
    CHECK_ERROR(_readReferendumIndex_V6(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_enact_proposal_V6(
    parser_context_t* c, pd_democracy_enact_proposal_V6_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    CHECK_ERROR(_readReferendumIndex_V6(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_blacklist_V6(
    parser_context_t* c, pd_democracy_blacklist_V6_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    CHECK_ERROR(_readOptionReferendumIndex_V6(c, &m->maybe_ref_index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_cancel_proposal_V6(
    parser_context_t* c, pd_democracy_cancel_proposal_V6_t* m)
{
    CHECK_ERROR(_readCompactPropIndex_V6(c, &m->prop_index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_council_set_members_V6(
    parser_context_t* c, pd_council_set_members_V6_t* m)
{
    CHECK_ERROR(_readVecAccountId_V6(c, &m->new_members))
    CHECK_ERROR(_readOptionAccountId_V6(c, &m->prime))
    CHECK_ERROR(_readMemberCount_V6(c, &m->old_count))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_council_execute_V6(
    parser_context_t* c, pd_council_execute_V6_t* m)
{
    CHECK_ERROR(_readProposal(c, &m->proposal))
    CHECK_ERROR(_readCompactu32(c, &m->length_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_council_propose_V6(
    parser_context_t* c, pd_council_propose_V6_t* m)
{
    CHECK_ERROR(_readCompactMemberCount_V6(c, &m->threshold))
    CHECK_ERROR(_readProposal(c, &m->proposal))
    CHECK_ERROR(_readCompactu32(c, &m->length_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_council_vote_V6(
    parser_context_t* c, pd_council_vote_V6_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal))
    CHECK_ERROR(_readCompactProposalIndex_V6(c, &m->index))
    CHECK_ERROR(_readbool(c, &m->approve))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_council_close_V6(
    parser_context_t* c, pd_council_close_V6_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    CHECK_ERROR(_readCompactProposalIndex_V6(c, &m->index))
    CHECK_ERROR(_readCompactWeight_V6(c, &m->proposal_weight_bound))
    CHECK_ERROR(_readCompactu32(c, &m->length_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_council_disapprove_proposal_V6(
    parser_context_t* c, pd_council_disapprove_proposal_V6_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_set_members_V6(
    parser_context_t* c, pd_technicalcommittee_set_members_V6_t* m)
{
    CHECK_ERROR(_readVecAccountId_V6(c, &m->new_members))
    CHECK_ERROR(_readOptionAccountId_V6(c, &m->prime))
    CHECK_ERROR(_readMemberCount_V6(c, &m->old_count))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_execute_V6(
    parser_context_t* c, pd_technicalcommittee_execute_V6_t* m)
{
    CHECK_ERROR(_readProposal(c, &m->proposal))
    CHECK_ERROR(_readCompactu32(c, &m->length_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_propose_V6(
    parser_context_t* c, pd_technicalcommittee_propose_V6_t* m)
{
    CHECK_ERROR(_readCompactMemberCount_V6(c, &m->threshold))
    CHECK_ERROR(_readProposal(c, &m->proposal))
    CHECK_ERROR(_readCompactu32(c, &m->length_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_vote_V6(
    parser_context_t* c, pd_technicalcommittee_vote_V6_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal))
    CHECK_ERROR(_readCompactProposalIndex_V6(c, &m->index))
    CHECK_ERROR(_readbool(c, &m->approve))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_close_V6(
    parser_context_t* c, pd_technicalcommittee_close_V6_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    CHECK_ERROR(_readCompactProposalIndex_V6(c, &m->index))
    CHECK_ERROR(_readCompactWeight_V6(c, &m->proposal_weight_bound))
    CHECK_ERROR(_readCompactu32(c, &m->length_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_disapprove_proposal_V6(
    parser_context_t* c, pd_technicalcommittee_disapprove_proposal_V6_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_electionsphragmen_vote_V6(
    parser_context_t* c, pd_electionsphragmen_vote_V6_t* m)
{
    CHECK_ERROR(_readVecAccountId_V6(c, &m->votes))
    CHECK_ERROR(_readCompactBalanceOf(c, &m->value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_electionsphragmen_remove_voter_V6(
    parser_context_t* c, pd_electionsphragmen_remove_voter_V6_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_electionsphragmen_submit_candidacy_V6(
    parser_context_t* c, pd_electionsphragmen_submit_candidacy_V6_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->candidate_count))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_electionsphragmen_renounce_candidacy_V6(
    parser_context_t* c, pd_electionsphragmen_renounce_candidacy_V6_t* m)
{
    CHECK_ERROR(_readRenouncing_V6(c, &m->renouncing))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_electionsphragmen_remove_member_V6(
    parser_context_t* c, pd_electionsphragmen_remove_member_V6_t* m)
{
    CHECK_ERROR(_readLookupSource_V6(c, &m->who))
    CHECK_ERROR(_readbool(c, &m->has_replacement))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_electionsphragmen_clean_defunct_voters_V6(
    parser_context_t* c, pd_electionsphragmen_clean_defunct_voters_V6_t* m)
{
    CHECK_ERROR(_readu32(c, &m->_num_voters))
    CHECK_ERROR(_readu32(c, &m->_num_defunct))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalmembership_add_member_V6(
    parser_context_t* c, pd_technicalmembership_add_member_V6_t* m)
{
    CHECK_ERROR(_readAccountId_V6(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalmembership_remove_member_V6(
    parser_context_t* c, pd_technicalmembership_remove_member_V6_t* m)
{
    CHECK_ERROR(_readAccountId_V6(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalmembership_swap_member_V6(
    parser_context_t* c, pd_technicalmembership_swap_member_V6_t* m)
{
    CHECK_ERROR(_readAccountId_V6(c, &m->remove))
    CHECK_ERROR(_readAccountId_V6(c, &m->add))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalmembership_reset_members_V6(
    parser_context_t* c, pd_technicalmembership_reset_members_V6_t* m)
{
    CHECK_ERROR(_readVecAccountId_V6(c, &m->members))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalmembership_change_key_V6(
    parser_context_t* c, pd_technicalmembership_change_key_V6_t* m)
{
    CHECK_ERROR(_readAccountId_V6(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalmembership_set_prime_V6(
    parser_context_t* c, pd_technicalmembership_set_prime_V6_t* m)
{
    CHECK_ERROR(_readAccountId_V6(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalmembership_clear_prime_V6(
    parser_context_t* c, pd_technicalmembership_clear_prime_V6_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_propose_spend_V6(
    parser_context_t* c, pd_treasury_propose_spend_V6_t* m)
{
    CHECK_ERROR(_readCompactBalanceOf(c, &m->value))
    CHECK_ERROR(_readLookupSource_V6(c, &m->beneficiary))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_reject_proposal_V6(
    parser_context_t* c, pd_treasury_reject_proposal_V6_t* m)
{
    CHECK_ERROR(_readCompactProposalIndex_V6(c, &m->proposal_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_approve_proposal_V6(
    parser_context_t* c, pd_treasury_approve_proposal_V6_t* m)
{
    CHECK_ERROR(_readCompactProposalIndex_V6(c, &m->proposal_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_claims_claim_V6(
    parser_context_t* c, pd_claims_claim_V6_t* m)
{
    CHECK_ERROR(_readAccountId_V6(c, &m->dest))
    CHECK_ERROR(_readEcdsaSignature_V6(c, &m->ethereum_signature))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_claims_mint_claim_V6(
    parser_context_t* c, pd_claims_mint_claim_V6_t* m)
{
    CHECK_ERROR(_readEthereumAddress_V6(c, &m->who))
    CHECK_ERROR(_readBalanceOf(c, &m->value))
    CHECK_ERROR(_readOptionTupleBalanceOfBalanceOfBlockNumber_V6(c, &m->vesting_schedule))
    CHECK_ERROR(_readOptionStatementKind_V6(c, &m->statement))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_claims_claim_attest_V6(
    parser_context_t* c, pd_claims_claim_attest_V6_t* m)
{
    CHECK_ERROR(_readAccountId_V6(c, &m->dest))
    CHECK_ERROR(_readEcdsaSignature_V6(c, &m->ethereum_signature))
    CHECK_ERROR(_readBytes(c, &m->statement))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_claims_attest_V6(
    parser_context_t* c, pd_claims_attest_V6_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->statement))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_claims_move_claim_V6(
    parser_context_t* c, pd_claims_move_claim_V6_t* m)
{
    CHECK_ERROR(_readEthereumAddress_V6(c, &m->old))
    CHECK_ERROR(_readEthereumAddress_V6(c, &m->new_))
    CHECK_ERROR(_readOptionAccountId_V6(c, &m->maybe_preclaim))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_vesting_vest_V6(
    parser_context_t* c, pd_vesting_vest_V6_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_vesting_vest_other_V6(
    parser_context_t* c, pd_vesting_vest_other_V6_t* m)
{
    CHECK_ERROR(_readLookupSource_V6(c, &m->target))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_vesting_vested_transfer_V6(
    parser_context_t* c, pd_vesting_vested_transfer_V6_t* m)
{
    CHECK_ERROR(_readLookupSource_V6(c, &m->target))
    CHECK_ERROR(_readVestingInfo_V6(c, &m->schedule))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_vesting_force_vested_transfer_V6(
    parser_context_t* c, pd_vesting_force_vested_transfer_V6_t* m)
{
    CHECK_ERROR(_readLookupSource_V6(c, &m->source))
    CHECK_ERROR(_readLookupSource_V6(c, &m->target))
    CHECK_ERROR(_readVestingInfo_V6(c, &m->schedule))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_as_derivative_V6(
    parser_context_t* c, pd_utility_as_derivative_V6_t* m)
{
    CHECK_ERROR(_readu16(c, &m->index))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_add_registrar_V6(
    parser_context_t* c, pd_identity_add_registrar_V6_t* m)
{
    CHECK_ERROR(_readAccountId_V6(c, &m->account))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_set_identity_V6(
    parser_context_t* c, pd_identity_set_identity_V6_t* m)
{
    CHECK_ERROR(_readIdentityInfo_V6(c, &m->info))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_set_subs_V6(
    parser_context_t* c, pd_identity_set_subs_V6_t* m)
{
    CHECK_ERROR(_readVecTupleAccountIdData_V6(c, &m->subs))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_clear_identity_V6(
    parser_context_t* c, pd_identity_clear_identity_V6_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_request_judgement_V6(
    parser_context_t* c, pd_identity_request_judgement_V6_t* m)
{
    CHECK_ERROR(_readCompactRegistrarIndex_V6(c, &m->reg_index))
    CHECK_ERROR(_readCompactBalanceOf(c, &m->max_fee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_cancel_request_V6(
    parser_context_t* c, pd_identity_cancel_request_V6_t* m)
{
    CHECK_ERROR(_readRegistrarIndex_V6(c, &m->reg_index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_set_fee_V6(
    parser_context_t* c, pd_identity_set_fee_V6_t* m)
{
    CHECK_ERROR(_readCompactRegistrarIndex_V6(c, &m->index))
    CHECK_ERROR(_readCompactBalanceOf(c, &m->fee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_set_account_id_V6(
    parser_context_t* c, pd_identity_set_account_id_V6_t* m)
{
    CHECK_ERROR(_readCompactRegistrarIndex_V6(c, &m->index))
    CHECK_ERROR(_readAccountId_V6(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_set_fields_V6(
    parser_context_t* c, pd_identity_set_fields_V6_t* m)
{
    CHECK_ERROR(_readCompactRegistrarIndex_V6(c, &m->index))
    CHECK_ERROR(_readIdentityFields_V6(c, &m->fields))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_provide_judgement_V6(
    parser_context_t* c, pd_identity_provide_judgement_V6_t* m)
{
    CHECK_ERROR(_readCompactRegistrarIndex_V6(c, &m->reg_index))
    CHECK_ERROR(_readLookupSource_V6(c, &m->target))
    CHECK_ERROR(_readIdentityJudgement_V6(c, &m->judgement))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_kill_identity_V6(
    parser_context_t* c, pd_identity_kill_identity_V6_t* m)
{
    CHECK_ERROR(_readLookupSource_V6(c, &m->target))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_add_sub_V6(
    parser_context_t* c, pd_identity_add_sub_V6_t* m)
{
    CHECK_ERROR(_readLookupSource_V6(c, &m->sub))
    CHECK_ERROR(_readData(c, &m->data))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_rename_sub_V6(
    parser_context_t* c, pd_identity_rename_sub_V6_t* m)
{
    CHECK_ERROR(_readLookupSource_V6(c, &m->sub))
    CHECK_ERROR(_readData(c, &m->data))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_remove_sub_V6(
    parser_context_t* c, pd_identity_remove_sub_V6_t* m)
{
    CHECK_ERROR(_readLookupSource_V6(c, &m->sub))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_quit_sub_V6(
    parser_context_t* c, pd_identity_quit_sub_V6_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_proxy_V6(
    parser_context_t* c, pd_proxy_proxy_V6_t* m)
{
    CHECK_ERROR(_readAccountId_V6(c, &m->real))
    CHECK_ERROR(_readOptionProxyType_V6(c, &m->force_proxy_type))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_add_proxy_V6(
    parser_context_t* c, pd_proxy_add_proxy_V6_t* m)
{
    CHECK_ERROR(_readAccountId_V6(c, &m->delegate))
    CHECK_ERROR(_readProxyType_V6(c, &m->proxy_type))
    CHECK_ERROR(_readBlockNumber(c, &m->delay))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_remove_proxy_V6(
    parser_context_t* c, pd_proxy_remove_proxy_V6_t* m)
{
    CHECK_ERROR(_readAccountId_V6(c, &m->delegate))
    CHECK_ERROR(_readProxyType_V6(c, &m->proxy_type))
    CHECK_ERROR(_readBlockNumber(c, &m->delay))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_remove_proxies_V6(
    parser_context_t* c, pd_proxy_remove_proxies_V6_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_anonymous_V6(
    parser_context_t* c, pd_proxy_anonymous_V6_t* m)
{
    CHECK_ERROR(_readProxyType_V6(c, &m->proxy_type))
    CHECK_ERROR(_readBlockNumber(c, &m->delay))
    CHECK_ERROR(_readu16(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_kill_anonymous_V6(
    parser_context_t* c, pd_proxy_kill_anonymous_V6_t* m)
{
    CHECK_ERROR(_readAccountId_V6(c, &m->spawner))
    CHECK_ERROR(_readProxyType_V6(c, &m->proxy_type))
    CHECK_ERROR(_readu16(c, &m->index))
    CHECK_ERROR(_readCompactBlockNumber(c, &m->height))
    CHECK_ERROR(_readCompactu32(c, &m->ext_index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_announce_V6(
    parser_context_t* c, pd_proxy_announce_V6_t* m)
{
    CHECK_ERROR(_readAccountId_V6(c, &m->real))
    CHECK_ERROR(_readCallHashOf_V6(c, &m->call_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_remove_announcement_V6(
    parser_context_t* c, pd_proxy_remove_announcement_V6_t* m)
{
    CHECK_ERROR(_readAccountId_V6(c, &m->real))
    CHECK_ERROR(_readCallHashOf_V6(c, &m->call_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_reject_announcement_V6(
    parser_context_t* c, pd_proxy_reject_announcement_V6_t* m)
{
    CHECK_ERROR(_readAccountId_V6(c, &m->delegate))
    CHECK_ERROR(_readCallHashOf_V6(c, &m->call_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_proxy_announced_V6(
    parser_context_t* c, pd_proxy_proxy_announced_V6_t* m)
{
    CHECK_ERROR(_readAccountId_V6(c, &m->delegate))
    CHECK_ERROR(_readAccountId_V6(c, &m->real))
    CHECK_ERROR(_readOptionProxyType_V6(c, &m->force_proxy_type))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_as_multi_threshold_1_V6(
    parser_context_t* c, pd_multisig_as_multi_threshold_1_V6_t* m)
{
    CHECK_ERROR(_readVecAccountId_V6(c, &m->other_signatories))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_as_multi_V6(
    parser_context_t* c, pd_multisig_as_multi_V6_t* m)
{
    CHECK_ERROR(_readu16(c, &m->threshold))
    CHECK_ERROR(_readVecAccountId_V6(c, &m->other_signatories))
    CHECK_ERROR(_readOptionTimepoint_V6(c, &m->maybe_timepoint))
    CHECK_ERROR(_readOpaqueCall_V6(c, &m->call))
    CHECK_ERROR(_readbool(c, &m->store_call))
    CHECK_ERROR(_readWeight_V6(c, &m->max_weight))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_approve_as_multi_V6(
    parser_context_t* c, pd_multisig_approve_as_multi_V6_t* m)
{
    CHECK_ERROR(_readu16(c, &m->threshold))
    CHECK_ERROR(_readVecAccountId_V6(c, &m->other_signatories))
    CHECK_ERROR(_readOptionTimepoint_V6(c, &m->maybe_timepoint))
    CHECK_ERROR(_readu8_array_32_V6(c, &m->call_hash))
    CHECK_ERROR(_readWeight_V6(c, &m->max_weight))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_cancel_as_multi_V6(
    parser_context_t* c, pd_multisig_cancel_as_multi_V6_t* m)
{
    CHECK_ERROR(_readu16(c, &m->threshold))
    CHECK_ERROR(_readVecAccountId_V6(c, &m->other_signatories))
    CHECK_ERROR(_readTimepoint_V6(c, &m->timepoint))
    CHECK_ERROR(_readu8_array_32_V6(c, &m->call_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bounties_propose_bounty_V6(
    parser_context_t* c, pd_bounties_propose_bounty_V6_t* m)
{
    CHECK_ERROR(_readCompactBalanceOf(c, &m->value))
    CHECK_ERROR(_readBytes(c, &m->description))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bounties_approve_bounty_V6(
    parser_context_t* c, pd_bounties_approve_bounty_V6_t* m)
{
    CHECK_ERROR(_readCompactBountyIndex_V6(c, &m->bounty_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bounties_propose_curator_V6(
    parser_context_t* c, pd_bounties_propose_curator_V6_t* m)
{
    CHECK_ERROR(_readCompactBountyIndex_V6(c, &m->bounty_id))
    CHECK_ERROR(_readLookupSource_V6(c, &m->curator))
    CHECK_ERROR(_readCompactBalanceOf(c, &m->fee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bounties_unassign_curator_V6(
    parser_context_t* c, pd_bounties_unassign_curator_V6_t* m)
{
    CHECK_ERROR(_readCompactBountyIndex_V6(c, &m->bounty_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bounties_accept_curator_V6(
    parser_context_t* c, pd_bounties_accept_curator_V6_t* m)
{
    CHECK_ERROR(_readCompactBountyIndex_V6(c, &m->bounty_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bounties_award_bounty_V6(
    parser_context_t* c, pd_bounties_award_bounty_V6_t* m)
{
    CHECK_ERROR(_readCompactBountyIndex_V6(c, &m->bounty_id))
    CHECK_ERROR(_readLookupSource_V6(c, &m->beneficiary))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bounties_claim_bounty_V6(
    parser_context_t* c, pd_bounties_claim_bounty_V6_t* m)
{
    CHECK_ERROR(_readCompactBountyIndex_V6(c, &m->bounty_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bounties_close_bounty_V6(
    parser_context_t* c, pd_bounties_close_bounty_V6_t* m)
{
    CHECK_ERROR(_readCompactBountyIndex_V6(c, &m->bounty_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bounties_extend_bounty_expiry_V6(
    parser_context_t* c, pd_bounties_extend_bounty_expiry_V6_t* m)
{
    CHECK_ERROR(_readCompactBountyIndex_V6(c, &m->bounty_id))
    CHECK_ERROR(_readBytes(c, &m->_remark))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_tips_report_awesome_V6(
    parser_context_t* c, pd_tips_report_awesome_V6_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->reason))
    CHECK_ERROR(_readAccountId_V6(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_tips_retract_tip_V6(
    parser_context_t* c, pd_tips_retract_tip_V6_t* m)
{
    CHECK_ERROR(_readHash(c, &m->hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_tips_tip_new_V6(
    parser_context_t* c, pd_tips_tip_new_V6_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->reason))
    CHECK_ERROR(_readAccountId_V6(c, &m->who))
    CHECK_ERROR(_readCompactBalanceOf(c, &m->tip_value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_tips_tip_V6(
    parser_context_t* c, pd_tips_tip_V6_t* m)
{
    CHECK_ERROR(_readHash(c, &m->hash))
    CHECK_ERROR(_readCompactBalanceOf(c, &m->tip_value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_tips_close_tip_V6(
    parser_context_t* c, pd_tips_close_tip_V6_t* m)
{
    CHECK_ERROR(_readHash(c, &m->hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_tips_slash_tip_V6(
    parser_context_t* c, pd_tips_slash_tip_V6_t* m)
{
    CHECK_ERROR(_readHash(c, &m->hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_electionprovidermultiphase_submit_unsigned_V6(
    parser_context_t* c, pd_electionprovidermultiphase_submit_unsigned_V6_t* m)
{
    CHECK_ERROR(_readRawSolution_V6(c, &m->solution))
    CHECK_ERROR(_readSolutionOrSnapshotSize_V6(c, &m->witness))
    return parser_ok;
}

#endif

parser_error_t _readMethod_V6(
    parser_context_t* c,
    uint8_t moduleIdx,
    uint8_t callIdx,
    pd_Method_V6_t* method)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {

    case 1280: /* module 5 call 0 */
        CHECK_ERROR(_readMethod_balances_transfer_V6(c, &method->basic.balances_transfer_V6))
        break;
    case 1283: /* module 5 call 3 */
        CHECK_ERROR(_readMethod_balances_transfer_keep_alive_V6(c, &method->basic.balances_transfer_keep_alive_V6))
        break;
    case 1792: /* module 7 call 0 */
        CHECK_ERROR(_readMethod_staking_bond_V6(c, &method->basic.staking_bond_V6))
        break;
    case 1793: /* module 7 call 1 */
        CHECK_ERROR(_readMethod_staking_bond_extra_V6(c, &method->basic.staking_bond_extra_V6))
        break;
    case 1794: /* module 7 call 2 */
        CHECK_ERROR(_readMethod_staking_unbond_V6(c, &method->basic.staking_unbond_V6))
        break;
    case 1795: /* module 7 call 3 */
        CHECK_ERROR(_readMethod_staking_withdraw_unbonded_V6(c, &method->basic.staking_withdraw_unbonded_V6))
        break;
    case 1796: /* module 7 call 4 */
        CHECK_ERROR(_readMethod_staking_validate_V6(c, &method->basic.staking_validate_V6))
        break;
    case 1797: /* module 7 call 5 */
        CHECK_ERROR(_readMethod_staking_nominate_V6(c, &method->basic.staking_nominate_V6))
        break;
    case 1798: /* module 7 call 6 */
        CHECK_ERROR(_readMethod_staking_chill_V6(c, &method->basic.staking_chill_V6))
        break;
    case 1799: /* module 7 call 7 */
        CHECK_ERROR(_readMethod_staking_set_payee_V6(c, &method->basic.staking_set_payee_V6))
        break;
    case 1810: /* module 7 call 18 */
        CHECK_ERROR(_readMethod_staking_payout_stakers_V6(c, &method->basic.staking_payout_stakers_V6))
        break;
    case 1811: /* module 7 call 19 */
        CHECK_ERROR(_readMethod_staking_rebond_V6(c, &method->basic.staking_rebond_V6))
        break;
    case 2304: /* module 9 call 0 */
        CHECK_ERROR(_readMethod_session_set_keys_V6(c, &method->basic.session_set_keys_V6))
        break;
    case 2305: /* module 9 call 1 */
        CHECK_ERROR(_readMethod_session_purge_keys_V6(c, &method->basic.session_purge_keys_V6))
        break;
    case 6656: /* module 26 call 0 */
        CHECK_ERROR(_readMethod_utility_batch_V6(c, &method->basic.utility_batch_V6))
        break;
    case 6658: /* module 26 call 2 */
        CHECK_ERROR(_readMethod_utility_batch_all_V6(c, &method->basic.utility_batch_all_V6))
        break;

#ifdef SUBSTRATE_PARSER_FULL
    case 0: /* module 0 call 0 */
        CHECK_ERROR(_readMethod_system_fill_block_V6(c, &method->basic.system_fill_block_V6))
        break;
    case 1: /* module 0 call 1 */
        CHECK_ERROR(_readMethod_system_remark_V6(c, &method->basic.system_remark_V6))
        break;
    case 2: /* module 0 call 2 */
        CHECK_ERROR(_readMethod_system_set_heap_pages_V6(c, &method->basic.system_set_heap_pages_V6))
        break;
    case 3: /* module 0 call 3 */
        CHECK_ERROR(_readMethod_system_set_code_V6(c, &method->basic.system_set_code_V6))
        break;
    case 4: /* module 0 call 4 */
        CHECK_ERROR(_readMethod_system_set_code_without_checks_V6(c, &method->basic.system_set_code_without_checks_V6))
        break;
    case 5: /* module 0 call 5 */
        CHECK_ERROR(_readMethod_system_set_changes_trie_config_V6(c, &method->basic.system_set_changes_trie_config_V6))
        break;
    case 6: /* module 0 call 6 */
        CHECK_ERROR(_readMethod_system_set_storage_V6(c, &method->basic.system_set_storage_V6))
        break;
    case 7: /* module 0 call 7 */
        CHECK_ERROR(_readMethod_system_kill_storage_V6(c, &method->basic.system_kill_storage_V6))
        break;
    case 8: /* module 0 call 8 */
        CHECK_ERROR(_readMethod_system_kill_prefix_V6(c, &method->basic.system_kill_prefix_V6))
        break;
    case 256: /* module 1 call 0 */
        CHECK_ERROR(_readMethod_scheduler_schedule_V6(c, &method->basic.scheduler_schedule_V6))
        break;
    case 257: /* module 1 call 1 */
        CHECK_ERROR(_readMethod_scheduler_cancel_V6(c, &method->basic.scheduler_cancel_V6))
        break;
    case 258: /* module 1 call 2 */
        CHECK_ERROR(_readMethod_scheduler_schedule_named_V6(c, &method->basic.scheduler_schedule_named_V6))
        break;
    case 259: /* module 1 call 3 */
        CHECK_ERROR(_readMethod_scheduler_cancel_named_V6(c, &method->basic.scheduler_cancel_named_V6))
        break;
    case 260: /* module 1 call 4 */
        CHECK_ERROR(_readMethod_scheduler_schedule_after_V6(c, &method->basic.scheduler_schedule_after_V6))
        break;
    case 261: /* module 1 call 5 */
        CHECK_ERROR(_readMethod_scheduler_schedule_named_after_V6(c, &method->basic.scheduler_schedule_named_after_V6))
        break;
    case 512: /* module 2 call 0 */
        CHECK_ERROR(_readMethod_babe_report_equivocation_V6(c, &method->basic.babe_report_equivocation_V6))
        break;
    case 513: /* module 2 call 1 */
        CHECK_ERROR(_readMethod_babe_report_equivocation_unsigned_V6(c, &method->basic.babe_report_equivocation_unsigned_V6))
        break;
    case 768: /* module 3 call 0 */
        CHECK_ERROR(_readMethod_timestamp_set_V6(c, &method->basic.timestamp_set_V6))
        break;
    case 1024: /* module 4 call 0 */
        CHECK_ERROR(_readMethod_indices_claim_V6(c, &method->basic.indices_claim_V6))
        break;
    case 1025: /* module 4 call 1 */
        CHECK_ERROR(_readMethod_indices_transfer_V6(c, &method->basic.indices_transfer_V6))
        break;
    case 1026: /* module 4 call 2 */
        CHECK_ERROR(_readMethod_indices_free_V6(c, &method->basic.indices_free_V6))
        break;
    case 1027: /* module 4 call 3 */
        CHECK_ERROR(_readMethod_indices_force_transfer_V6(c, &method->basic.indices_force_transfer_V6))
        break;
    case 1028: /* module 4 call 4 */
        CHECK_ERROR(_readMethod_indices_freeze_V6(c, &method->basic.indices_freeze_V6))
        break;
    case 1281: /* module 5 call 1 */
        CHECK_ERROR(_readMethod_balances_set_balance_V6(c, &method->basic.balances_set_balance_V6))
        break;
    case 1282: /* module 5 call 2 */
        CHECK_ERROR(_readMethod_balances_force_transfer_V6(c, &method->basic.balances_force_transfer_V6))
        break;
    case 1536: /* module 6 call 0 */
        CHECK_ERROR(_readMethod_authorship_set_uncles_V6(c, &method->basic.authorship_set_uncles_V6))
        break;
    case 1800: /* module 7 call 8 */
        CHECK_ERROR(_readMethod_staking_set_controller_V6(c, &method->basic.staking_set_controller_V6))
        break;
    case 1801: /* module 7 call 9 */
        CHECK_ERROR(_readMethod_staking_set_validator_count_V6(c, &method->basic.staking_set_validator_count_V6))
        break;
    case 1802: /* module 7 call 10 */
        CHECK_ERROR(_readMethod_staking_increase_validator_count_V6(c, &method->basic.staking_increase_validator_count_V6))
        break;
    case 1803: /* module 7 call 11 */
        CHECK_ERROR(_readMethod_staking_scale_validator_count_V6(c, &method->basic.staking_scale_validator_count_V6))
        break;
    case 1804: /* module 7 call 12 */
        CHECK_ERROR(_readMethod_staking_force_no_eras_V6(c, &method->basic.staking_force_no_eras_V6))
        break;
    case 1805: /* module 7 call 13 */
        CHECK_ERROR(_readMethod_staking_force_new_era_V6(c, &method->basic.staking_force_new_era_V6))
        break;
    case 1806: /* module 7 call 14 */
        CHECK_ERROR(_readMethod_staking_set_invulnerables_V6(c, &method->basic.staking_set_invulnerables_V6))
        break;
    case 1807: /* module 7 call 15 */
        CHECK_ERROR(_readMethod_staking_force_unstake_V6(c, &method->basic.staking_force_unstake_V6))
        break;
    case 1808: /* module 7 call 16 */
        CHECK_ERROR(_readMethod_staking_force_new_era_always_V6(c, &method->basic.staking_force_new_era_always_V6))
        break;
    case 1809: /* module 7 call 17 */
        CHECK_ERROR(_readMethod_staking_cancel_deferred_slash_V6(c, &method->basic.staking_cancel_deferred_slash_V6))
        break;
    case 1812: /* module 7 call 20 */
        CHECK_ERROR(_readMethod_staking_set_history_depth_V6(c, &method->basic.staking_set_history_depth_V6))
        break;
    case 1813: /* module 7 call 21 */
        CHECK_ERROR(_readMethod_staking_reap_stash_V6(c, &method->basic.staking_reap_stash_V6))
        break;
    case 1814: /* module 7 call 22 */
        CHECK_ERROR(_readMethod_staking_submit_election_solution_V6(c, &method->basic.staking_submit_election_solution_V6))
        break;
    case 1815: /* module 7 call 23 */
        CHECK_ERROR(_readMethod_staking_submit_election_solution_unsigned_V6(c, &method->basic.staking_submit_election_solution_unsigned_V6))
        break;
    case 1816: /* module 7 call 24 */
        CHECK_ERROR(_readMethod_staking_kick_V6(c, &method->basic.staking_kick_V6))
        break;
    case 2816: /* module 11 call 0 */
        CHECK_ERROR(_readMethod_grandpa_report_equivocation_V6(c, &method->basic.grandpa_report_equivocation_V6))
        break;
    case 2817: /* module 11 call 1 */
        CHECK_ERROR(_readMethod_grandpa_report_equivocation_unsigned_V6(c, &method->basic.grandpa_report_equivocation_unsigned_V6))
        break;
    case 2818: /* module 11 call 2 */
        CHECK_ERROR(_readMethod_grandpa_note_stalled_V6(c, &method->basic.grandpa_note_stalled_V6))
        break;
    case 3072: /* module 12 call 0 */
        CHECK_ERROR(_readMethod_imonline_heartbeat_V6(c, &method->basic.imonline_heartbeat_V6))
        break;
    case 3584: /* module 14 call 0 */
        CHECK_ERROR(_readMethod_democracy_propose_V6(c, &method->basic.democracy_propose_V6))
        break;
    case 3585: /* module 14 call 1 */
        CHECK_ERROR(_readMethod_democracy_second_V6(c, &method->basic.democracy_second_V6))
        break;
    case 3586: /* module 14 call 2 */
        CHECK_ERROR(_readMethod_democracy_vote_V6(c, &method->basic.democracy_vote_V6))
        break;
    case 3587: /* module 14 call 3 */
        CHECK_ERROR(_readMethod_democracy_emergency_cancel_V6(c, &method->basic.democracy_emergency_cancel_V6))
        break;
    case 3588: /* module 14 call 4 */
        CHECK_ERROR(_readMethod_democracy_external_propose_V6(c, &method->basic.democracy_external_propose_V6))
        break;
    case 3589: /* module 14 call 5 */
        CHECK_ERROR(_readMethod_democracy_external_propose_majority_V6(c, &method->basic.democracy_external_propose_majority_V6))
        break;
    case 3590: /* module 14 call 6 */
        CHECK_ERROR(_readMethod_democracy_external_propose_default_V6(c, &method->basic.democracy_external_propose_default_V6))
        break;
    case 3591: /* module 14 call 7 */
        CHECK_ERROR(_readMethod_democracy_fast_track_V6(c, &method->basic.democracy_fast_track_V6))
        break;
    case 3592: /* module 14 call 8 */
        CHECK_ERROR(_readMethod_democracy_veto_external_V6(c, &method->basic.democracy_veto_external_V6))
        break;
    case 3593: /* module 14 call 9 */
        CHECK_ERROR(_readMethod_democracy_cancel_referendum_V6(c, &method->basic.democracy_cancel_referendum_V6))
        break;
    case 3594: /* module 14 call 10 */
        CHECK_ERROR(_readMethod_democracy_cancel_queued_V6(c, &method->basic.democracy_cancel_queued_V6))
        break;
    case 3595: /* module 14 call 11 */
        CHECK_ERROR(_readMethod_democracy_delegate_V6(c, &method->basic.democracy_delegate_V6))
        break;
    case 3596: /* module 14 call 12 */
        CHECK_ERROR(_readMethod_democracy_undelegate_V6(c, &method->basic.democracy_undelegate_V6))
        break;
    case 3597: /* module 14 call 13 */
        CHECK_ERROR(_readMethod_democracy_clear_public_proposals_V6(c, &method->basic.democracy_clear_public_proposals_V6))
        break;
    case 3598: /* module 14 call 14 */
        CHECK_ERROR(_readMethod_democracy_note_preimage_V6(c, &method->basic.democracy_note_preimage_V6))
        break;
    case 3599: /* module 14 call 15 */
        CHECK_ERROR(_readMethod_democracy_note_preimage_operational_V6(c, &method->basic.democracy_note_preimage_operational_V6))
        break;
    case 3600: /* module 14 call 16 */
        CHECK_ERROR(_readMethod_democracy_note_imminent_preimage_V6(c, &method->basic.democracy_note_imminent_preimage_V6))
        break;
    case 3601: /* module 14 call 17 */
        CHECK_ERROR(_readMethod_democracy_note_imminent_preimage_operational_V6(c, &method->basic.democracy_note_imminent_preimage_operational_V6))
        break;
    case 3602: /* module 14 call 18 */
        CHECK_ERROR(_readMethod_democracy_reap_preimage_V6(c, &method->basic.democracy_reap_preimage_V6))
        break;
    case 3603: /* module 14 call 19 */
        CHECK_ERROR(_readMethod_democracy_unlock_V6(c, &method->basic.democracy_unlock_V6))
        break;
    case 3604: /* module 14 call 20 */
        CHECK_ERROR(_readMethod_democracy_remove_vote_V6(c, &method->basic.democracy_remove_vote_V6))
        break;
    case 3605: /* module 14 call 21 */
        CHECK_ERROR(_readMethod_democracy_remove_other_vote_V6(c, &method->basic.democracy_remove_other_vote_V6))
        break;
    case 3606: /* module 14 call 22 */
        CHECK_ERROR(_readMethod_democracy_enact_proposal_V6(c, &method->basic.democracy_enact_proposal_V6))
        break;
    case 3607: /* module 14 call 23 */
        CHECK_ERROR(_readMethod_democracy_blacklist_V6(c, &method->basic.democracy_blacklist_V6))
        break;
    case 3608: /* module 14 call 24 */
        CHECK_ERROR(_readMethod_democracy_cancel_proposal_V6(c, &method->basic.democracy_cancel_proposal_V6))
        break;
    case 3840: /* module 15 call 0 */
        CHECK_ERROR(_readMethod_council_set_members_V6(c, &method->basic.council_set_members_V6))
        break;
    case 3841: /* module 15 call 1 */
        CHECK_ERROR(_readMethod_council_execute_V6(c, &method->basic.council_execute_V6))
        break;
    case 3842: /* module 15 call 2 */
        CHECK_ERROR(_readMethod_council_propose_V6(c, &method->basic.council_propose_V6))
        break;
    case 3843: /* module 15 call 3 */
        CHECK_ERROR(_readMethod_council_vote_V6(c, &method->basic.council_vote_V6))
        break;
    case 3844: /* module 15 call 4 */
        CHECK_ERROR(_readMethod_council_close_V6(c, &method->basic.council_close_V6))
        break;
    case 3845: /* module 15 call 5 */
        CHECK_ERROR(_readMethod_council_disapprove_proposal_V6(c, &method->basic.council_disapprove_proposal_V6))
        break;
    case 4096: /* module 16 call 0 */
        CHECK_ERROR(_readMethod_technicalcommittee_set_members_V6(c, &method->basic.technicalcommittee_set_members_V6))
        break;
    case 4097: /* module 16 call 1 */
        CHECK_ERROR(_readMethod_technicalcommittee_execute_V6(c, &method->basic.technicalcommittee_execute_V6))
        break;
    case 4098: /* module 16 call 2 */
        CHECK_ERROR(_readMethod_technicalcommittee_propose_V6(c, &method->basic.technicalcommittee_propose_V6))
        break;
    case 4099: /* module 16 call 3 */
        CHECK_ERROR(_readMethod_technicalcommittee_vote_V6(c, &method->basic.technicalcommittee_vote_V6))
        break;
    case 4100: /* module 16 call 4 */
        CHECK_ERROR(_readMethod_technicalcommittee_close_V6(c, &method->basic.technicalcommittee_close_V6))
        break;
    case 4101: /* module 16 call 5 */
        CHECK_ERROR(_readMethod_technicalcommittee_disapprove_proposal_V6(c, &method->basic.technicalcommittee_disapprove_proposal_V6))
        break;
    case 4352: /* module 17 call 0 */
        CHECK_ERROR(_readMethod_electionsphragmen_vote_V6(c, &method->basic.electionsphragmen_vote_V6))
        break;
    case 4353: /* module 17 call 1 */
        CHECK_ERROR(_readMethod_electionsphragmen_remove_voter_V6(c, &method->basic.electionsphragmen_remove_voter_V6))
        break;
    case 4354: /* module 17 call 2 */
        CHECK_ERROR(_readMethod_electionsphragmen_submit_candidacy_V6(c, &method->basic.electionsphragmen_submit_candidacy_V6))
        break;
    case 4355: /* module 17 call 3 */
        CHECK_ERROR(_readMethod_electionsphragmen_renounce_candidacy_V6(c, &method->basic.electionsphragmen_renounce_candidacy_V6))
        break;
    case 4356: /* module 17 call 4 */
        CHECK_ERROR(_readMethod_electionsphragmen_remove_member_V6(c, &method->basic.electionsphragmen_remove_member_V6))
        break;
    case 4357: /* module 17 call 5 */
        CHECK_ERROR(_readMethod_electionsphragmen_clean_defunct_voters_V6(c, &method->basic.electionsphragmen_clean_defunct_voters_V6))
        break;
    case 4608: /* module 18 call 0 */
        CHECK_ERROR(_readMethod_technicalmembership_add_member_V6(c, &method->basic.technicalmembership_add_member_V6))
        break;
    case 4609: /* module 18 call 1 */
        CHECK_ERROR(_readMethod_technicalmembership_remove_member_V6(c, &method->basic.technicalmembership_remove_member_V6))
        break;
    case 4610: /* module 18 call 2 */
        CHECK_ERROR(_readMethod_technicalmembership_swap_member_V6(c, &method->basic.technicalmembership_swap_member_V6))
        break;
    case 4611: /* module 18 call 3 */
        CHECK_ERROR(_readMethod_technicalmembership_reset_members_V6(c, &method->basic.technicalmembership_reset_members_V6))
        break;
    case 4612: /* module 18 call 4 */
        CHECK_ERROR(_readMethod_technicalmembership_change_key_V6(c, &method->basic.technicalmembership_change_key_V6))
        break;
    case 4613: /* module 18 call 5 */
        CHECK_ERROR(_readMethod_technicalmembership_set_prime_V6(c, &method->basic.technicalmembership_set_prime_V6))
        break;
    case 4614: /* module 18 call 6 */
        CHECK_ERROR(_readMethod_technicalmembership_clear_prime_V6(c, &method->basic.technicalmembership_clear_prime_V6))
        break;
    case 4864: /* module 19 call 0 */
        CHECK_ERROR(_readMethod_treasury_propose_spend_V6(c, &method->basic.treasury_propose_spend_V6))
        break;
    case 4865: /* module 19 call 1 */
        CHECK_ERROR(_readMethod_treasury_reject_proposal_V6(c, &method->basic.treasury_reject_proposal_V6))
        break;
    case 4866: /* module 19 call 2 */
        CHECK_ERROR(_readMethod_treasury_approve_proposal_V6(c, &method->basic.treasury_approve_proposal_V6))
        break;
    case 6144: /* module 24 call 0 */
        CHECK_ERROR(_readMethod_claims_claim_V6(c, &method->basic.claims_claim_V6))
        break;
    case 6145: /* module 24 call 1 */
        CHECK_ERROR(_readMethod_claims_mint_claim_V6(c, &method->basic.claims_mint_claim_V6))
        break;
    case 6146: /* module 24 call 2 */
        CHECK_ERROR(_readMethod_claims_claim_attest_V6(c, &method->basic.claims_claim_attest_V6))
        break;
    case 6147: /* module 24 call 3 */
        CHECK_ERROR(_readMethod_claims_attest_V6(c, &method->basic.claims_attest_V6))
        break;
    case 6148: /* module 24 call 4 */
        CHECK_ERROR(_readMethod_claims_move_claim_V6(c, &method->basic.claims_move_claim_V6))
        break;
    case 6400: /* module 25 call 0 */
        CHECK_ERROR(_readMethod_vesting_vest_V6(c, &method->basic.vesting_vest_V6))
        break;
    case 6401: /* module 25 call 1 */
        CHECK_ERROR(_readMethod_vesting_vest_other_V6(c, &method->basic.vesting_vest_other_V6))
        break;
    case 6402: /* module 25 call 2 */
        CHECK_ERROR(_readMethod_vesting_vested_transfer_V6(c, &method->basic.vesting_vested_transfer_V6))
        break;
    case 6403: /* module 25 call 3 */
        CHECK_ERROR(_readMethod_vesting_force_vested_transfer_V6(c, &method->basic.vesting_force_vested_transfer_V6))
        break;
    case 6657: /* module 26 call 1 */
        CHECK_ERROR(_readMethod_utility_as_derivative_V6(c, &method->basic.utility_as_derivative_V6))
        break;
    case 7168: /* module 28 call 0 */
        CHECK_ERROR(_readMethod_identity_add_registrar_V6(c, &method->basic.identity_add_registrar_V6))
        break;
    case 7169: /* module 28 call 1 */
        CHECK_ERROR(_readMethod_identity_set_identity_V6(c, &method->basic.identity_set_identity_V6))
        break;
    case 7170: /* module 28 call 2 */
        CHECK_ERROR(_readMethod_identity_set_subs_V6(c, &method->basic.identity_set_subs_V6))
        break;
    case 7171: /* module 28 call 3 */
        CHECK_ERROR(_readMethod_identity_clear_identity_V6(c, &method->basic.identity_clear_identity_V6))
        break;
    case 7172: /* module 28 call 4 */
        CHECK_ERROR(_readMethod_identity_request_judgement_V6(c, &method->basic.identity_request_judgement_V6))
        break;
    case 7173: /* module 28 call 5 */
        CHECK_ERROR(_readMethod_identity_cancel_request_V6(c, &method->basic.identity_cancel_request_V6))
        break;
    case 7174: /* module 28 call 6 */
        CHECK_ERROR(_readMethod_identity_set_fee_V6(c, &method->basic.identity_set_fee_V6))
        break;
    case 7175: /* module 28 call 7 */
        CHECK_ERROR(_readMethod_identity_set_account_id_V6(c, &method->basic.identity_set_account_id_V6))
        break;
    case 7176: /* module 28 call 8 */
        CHECK_ERROR(_readMethod_identity_set_fields_V6(c, &method->basic.identity_set_fields_V6))
        break;
    case 7177: /* module 28 call 9 */
        CHECK_ERROR(_readMethod_identity_provide_judgement_V6(c, &method->basic.identity_provide_judgement_V6))
        break;
    case 7178: /* module 28 call 10 */
        CHECK_ERROR(_readMethod_identity_kill_identity_V6(c, &method->basic.identity_kill_identity_V6))
        break;
    case 7179: /* module 28 call 11 */
        CHECK_ERROR(_readMethod_identity_add_sub_V6(c, &method->basic.identity_add_sub_V6))
        break;
    case 7180: /* module 28 call 12 */
        CHECK_ERROR(_readMethod_identity_rename_sub_V6(c, &method->basic.identity_rename_sub_V6))
        break;
    case 7181: /* module 28 call 13 */
        CHECK_ERROR(_readMethod_identity_remove_sub_V6(c, &method->basic.identity_remove_sub_V6))
        break;
    case 7182: /* module 28 call 14 */
        CHECK_ERROR(_readMethod_identity_quit_sub_V6(c, &method->basic.identity_quit_sub_V6))
        break;
    case 7424: /* module 29 call 0 */
        CHECK_ERROR(_readMethod_proxy_proxy_V6(c, &method->basic.proxy_proxy_V6))
        break;
    case 7425: /* module 29 call 1 */
        CHECK_ERROR(_readMethod_proxy_add_proxy_V6(c, &method->basic.proxy_add_proxy_V6))
        break;
    case 7426: /* module 29 call 2 */
        CHECK_ERROR(_readMethod_proxy_remove_proxy_V6(c, &method->basic.proxy_remove_proxy_V6))
        break;
    case 7427: /* module 29 call 3 */
        CHECK_ERROR(_readMethod_proxy_remove_proxies_V6(c, &method->basic.proxy_remove_proxies_V6))
        break;
    case 7428: /* module 29 call 4 */
        CHECK_ERROR(_readMethod_proxy_anonymous_V6(c, &method->basic.proxy_anonymous_V6))
        break;
    case 7429: /* module 29 call 5 */
        CHECK_ERROR(_readMethod_proxy_kill_anonymous_V6(c, &method->basic.proxy_kill_anonymous_V6))
        break;
    case 7430: /* module 29 call 6 */
        CHECK_ERROR(_readMethod_proxy_announce_V6(c, &method->basic.proxy_announce_V6))
        break;
    case 7431: /* module 29 call 7 */
        CHECK_ERROR(_readMethod_proxy_remove_announcement_V6(c, &method->basic.proxy_remove_announcement_V6))
        break;
    case 7432: /* module 29 call 8 */
        CHECK_ERROR(_readMethod_proxy_reject_announcement_V6(c, &method->basic.proxy_reject_announcement_V6))
        break;
    case 7433: /* module 29 call 9 */
        CHECK_ERROR(_readMethod_proxy_proxy_announced_V6(c, &method->basic.proxy_proxy_announced_V6))
        break;
    case 7680: /* module 30 call 0 */
        CHECK_ERROR(_readMethod_multisig_as_multi_threshold_1_V6(c, &method->basic.multisig_as_multi_threshold_1_V6))
        break;
    case 7681: /* module 30 call 1 */
        CHECK_ERROR(_readMethod_multisig_as_multi_V6(c, &method->basic.multisig_as_multi_V6))
        break;
    case 7682: /* module 30 call 2 */
        CHECK_ERROR(_readMethod_multisig_approve_as_multi_V6(c, &method->basic.multisig_approve_as_multi_V6))
        break;
    case 7683: /* module 30 call 3 */
        CHECK_ERROR(_readMethod_multisig_cancel_as_multi_V6(c, &method->basic.multisig_cancel_as_multi_V6))
        break;
    case 8704: /* module 34 call 0 */
        CHECK_ERROR(_readMethod_bounties_propose_bounty_V6(c, &method->basic.bounties_propose_bounty_V6))
        break;
    case 8705: /* module 34 call 1 */
        CHECK_ERROR(_readMethod_bounties_approve_bounty_V6(c, &method->basic.bounties_approve_bounty_V6))
        break;
    case 8706: /* module 34 call 2 */
        CHECK_ERROR(_readMethod_bounties_propose_curator_V6(c, &method->basic.bounties_propose_curator_V6))
        break;
    case 8707: /* module 34 call 3 */
        CHECK_ERROR(_readMethod_bounties_unassign_curator_V6(c, &method->basic.bounties_unassign_curator_V6))
        break;
    case 8708: /* module 34 call 4 */
        CHECK_ERROR(_readMethod_bounties_accept_curator_V6(c, &method->basic.bounties_accept_curator_V6))
        break;
    case 8709: /* module 34 call 5 */
        CHECK_ERROR(_readMethod_bounties_award_bounty_V6(c, &method->basic.bounties_award_bounty_V6))
        break;
    case 8710: /* module 34 call 6 */
        CHECK_ERROR(_readMethod_bounties_claim_bounty_V6(c, &method->basic.bounties_claim_bounty_V6))
        break;
    case 8711: /* module 34 call 7 */
        CHECK_ERROR(_readMethod_bounties_close_bounty_V6(c, &method->basic.bounties_close_bounty_V6))
        break;
    case 8712: /* module 34 call 8 */
        CHECK_ERROR(_readMethod_bounties_extend_bounty_expiry_V6(c, &method->basic.bounties_extend_bounty_expiry_V6))
        break;
    case 8960: /* module 35 call 0 */
        CHECK_ERROR(_readMethod_tips_report_awesome_V6(c, &method->basic.tips_report_awesome_V6))
        break;
    case 8961: /* module 35 call 1 */
        CHECK_ERROR(_readMethod_tips_retract_tip_V6(c, &method->basic.tips_retract_tip_V6))
        break;
    case 8962: /* module 35 call 2 */
        CHECK_ERROR(_readMethod_tips_tip_new_V6(c, &method->basic.tips_tip_new_V6))
        break;
    case 8963: /* module 35 call 3 */
        CHECK_ERROR(_readMethod_tips_tip_V6(c, &method->basic.tips_tip_V6))
        break;
    case 8964: /* module 35 call 4 */
        CHECK_ERROR(_readMethod_tips_close_tip_V6(c, &method->basic.tips_close_tip_V6))
        break;
    case 8965: /* module 35 call 5 */
        CHECK_ERROR(_readMethod_tips_slash_tip_V6(c, &method->basic.tips_slash_tip_V6))
        break;
    case 9216: /* module 36 call 0 */
        CHECK_ERROR(_readMethod_electionprovidermultiphase_submit_unsigned_V6(c, &method->basic.electionprovidermultiphase_submit_unsigned_V6))
        break;
#endif
    default:
        return parser_unexpected_callIndex;
    }

    return parser_ok;
}

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

const char* _getMethod_ModuleName_V6(uint8_t moduleIdx)
{
    switch (moduleIdx) {
    case 5:
        return STR_MO_BALANCES;
    case 7:
        return STR_MO_STAKING;
    case 9:
        return STR_MO_SESSION;
    case 26:
        return STR_MO_UTILITY;
#ifdef SUBSTRATE_PARSER_FULL
    case 0:
        return STR_MO_SYSTEM;
    case 1:
        return STR_MO_SCHEDULER;
    case 2:
        return STR_MO_BABE;
    case 3:
        return STR_MO_TIMESTAMP;
    case 4:
        return STR_MO_INDICES;
    case 6:
        return STR_MO_AUTHORSHIP;
    case 8:
        return STR_MO_OFFENCES;
    case 11:
        return STR_MO_GRANDPA;
    case 12:
        return STR_MO_IMONLINE;
    case 13:
        return STR_MO_AUTHORITYDISCOVERY;
    case 14:
        return STR_MO_DEMOCRACY;
    case 15:
        return STR_MO_COUNCIL;
    case 16:
        return STR_MO_TECHNICALCOMMITTEE;
    case 17:
        return STR_MO_ELECTIONSPHRAGMEN;
    case 18:
        return STR_MO_TECHNICALMEMBERSHIP;
    case 19:
        return STR_MO_TREASURY;
    case 24:
        return STR_MO_CLAIMS;
    case 25:
        return STR_MO_VESTING;
    case 28:
        return STR_MO_IDENTITY;
    case 29:
        return STR_MO_PROXY;
    case 30:
        return STR_MO_MULTISIG;
    case 34:
        return STR_MO_BOUNTIES;
    case 35:
        return STR_MO_TIPS;
    case 36:
        return STR_MO_ELECTIONPROVIDERMULTIPHASE;
#endif
    default:
        return NULL;
    }

    return NULL;
}

const char* _getMethod_Name_V6(uint8_t moduleIdx, uint8_t callIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 1280: /* module 5 call 0 */
        return STR_ME_TRANSFER;
    case 1283: /* module 5 call 3 */
        return STR_ME_TRANSFER_KEEP_ALIVE;
    case 1792: /* module 7 call 0 */
        return STR_ME_BOND;
    case 1793: /* module 7 call 1 */
        return STR_ME_BOND_EXTRA;
    case 1794: /* module 7 call 2 */
        return STR_ME_UNBOND;
    case 1795: /* module 7 call 3 */
        return STR_ME_WITHDRAW_UNBONDED;
    case 1796: /* module 7 call 4 */
        return STR_ME_VALIDATE;
    case 1797: /* module 7 call 5 */
        return STR_ME_NOMINATE;
    case 1798: /* module 7 call 6 */
        return STR_ME_CHILL;
    case 1799: /* module 7 call 7 */
        return STR_ME_SET_PAYEE;
    case 1810: /* module 7 call 18 */
        return STR_ME_PAYOUT_STAKERS;
    case 1811: /* module 7 call 19 */
        return STR_ME_REBOND;
    case 2304: /* module 9 call 0 */
        return STR_ME_SET_KEYS;
    case 2305: /* module 9 call 1 */
        return STR_ME_PURGE_KEYS;
    case 6656: /* module 26 call 0 */
        return STR_ME_BATCH;
    case 6658: /* module 26 call 2 */
        return STR_ME_BATCH_ALL;
#ifdef SUBSTRATE_PARSER_FULL
    case 0: /* module 0 call 0 */
        return STR_ME_FILL_BLOCK;
    case 1: /* module 0 call 1 */
        return STR_ME_REMARK;
    case 2: /* module 0 call 2 */
        return STR_ME_SET_HEAP_PAGES;
    case 3: /* module 0 call 3 */
        return STR_ME_SET_CODE;
    case 4: /* module 0 call 4 */
        return STR_ME_SET_CODE_WITHOUT_CHECKS;
    case 5: /* module 0 call 5 */
        return STR_ME_SET_CHANGES_TRIE_CONFIG;
    case 6: /* module 0 call 6 */
        return STR_ME_SET_STORAGE;
    case 7: /* module 0 call 7 */
        return STR_ME_KILL_STORAGE;
    case 8: /* module 0 call 8 */
        return STR_ME_KILL_PREFIX;
    case 256: /* module 1 call 0 */
        return STR_ME_SCHEDULE;
    case 257: /* module 1 call 1 */
        return STR_ME_CANCEL;
    case 258: /* module 1 call 2 */
        return STR_ME_SCHEDULE_NAMED;
    case 259: /* module 1 call 3 */
        return STR_ME_CANCEL_NAMED;
    case 260: /* module 1 call 4 */
        return STR_ME_SCHEDULE_AFTER;
    case 261: /* module 1 call 5 */
        return STR_ME_SCHEDULE_NAMED_AFTER;
    case 512: /* module 2 call 0 */
        return STR_ME_REPORT_EQUIVOCATION;
    case 513: /* module 2 call 1 */
        return STR_ME_REPORT_EQUIVOCATION_UNSIGNED;
    case 768: /* module 3 call 0 */
        return STR_ME_SET;
    case 1024: /* module 4 call 0 */
        return STR_ME_CLAIM;
    case 1025: /* module 4 call 1 */
        return STR_ME_TRANSFER;
    case 1026: /* module 4 call 2 */
        return STR_ME_FREE;
    case 1027: /* module 4 call 3 */
        return STR_ME_FORCE_TRANSFER;
    case 1028: /* module 4 call 4 */
        return STR_ME_FREEZE;
    case 1281: /* module 5 call 1 */
        return STR_ME_SET_BALANCE;
    case 1282: /* module 5 call 2 */
        return STR_ME_FORCE_TRANSFER;
    case 1536: /* module 6 call 0 */
        return STR_ME_SET_UNCLES;
    case 1800: /* module 7 call 8 */
        return STR_ME_SET_CONTROLLER;
    case 1801: /* module 7 call 9 */
        return STR_ME_SET_VALIDATOR_COUNT;
    case 1802: /* module 7 call 10 */
        return STR_ME_INCREASE_VALIDATOR_COUNT;
    case 1803: /* module 7 call 11 */
        return STR_ME_SCALE_VALIDATOR_COUNT;
    case 1804: /* module 7 call 12 */
        return STR_ME_FORCE_NO_ERAS;
    case 1805: /* module 7 call 13 */
        return STR_ME_FORCE_NEW_ERA;
    case 1806: /* module 7 call 14 */
        return STR_ME_SET_INVULNERABLES;
    case 1807: /* module 7 call 15 */
        return STR_ME_FORCE_UNSTAKE;
    case 1808: /* module 7 call 16 */
        return STR_ME_FORCE_NEW_ERA_ALWAYS;
    case 1809: /* module 7 call 17 */
        return STR_ME_CANCEL_DEFERRED_SLASH;
    case 1812: /* module 7 call 20 */
        return STR_ME_SET_HISTORY_DEPTH;
    case 1813: /* module 7 call 21 */
        return STR_ME_REAP_STASH;
    case 1814: /* module 7 call 22 */
        return STR_ME_SUBMIT_ELECTION_SOLUTION;
    case 1815: /* module 7 call 23 */
        return STR_ME_SUBMIT_ELECTION_SOLUTION_UNSIGNED;
    case 1816: /* module 7 call 24 */
        return STR_ME_KICK;
    case 2816: /* module 11 call 0 */
        return STR_ME_REPORT_EQUIVOCATION;
    case 2817: /* module 11 call 1 */
        return STR_ME_REPORT_EQUIVOCATION_UNSIGNED;
    case 2818: /* module 11 call 2 */
        return STR_ME_NOTE_STALLED;
    case 3072: /* module 12 call 0 */
        return STR_ME_HEARTBEAT;
    case 3584: /* module 14 call 0 */
        return STR_ME_PROPOSE;
    case 3585: /* module 14 call 1 */
        return STR_ME_SECOND;
    case 3586: /* module 14 call 2 */
        return STR_ME_VOTE;
    case 3587: /* module 14 call 3 */
        return STR_ME_EMERGENCY_CANCEL;
    case 3588: /* module 14 call 4 */
        return STR_ME_EXTERNAL_PROPOSE;
    case 3589: /* module 14 call 5 */
        return STR_ME_EXTERNAL_PROPOSE_MAJORITY;
    case 3590: /* module 14 call 6 */
        return STR_ME_EXTERNAL_PROPOSE_DEFAULT;
    case 3591: /* module 14 call 7 */
        return STR_ME_FAST_TRACK;
    case 3592: /* module 14 call 8 */
        return STR_ME_VETO_EXTERNAL;
    case 3593: /* module 14 call 9 */
        return STR_ME_CANCEL_REFERENDUM;
    case 3594: /* module 14 call 10 */
        return STR_ME_CANCEL_QUEUED;
    case 3595: /* module 14 call 11 */
        return STR_ME_DELEGATE;
    case 3596: /* module 14 call 12 */
        return STR_ME_UNDELEGATE;
    case 3597: /* module 14 call 13 */
        return STR_ME_CLEAR_PUBLIC_PROPOSALS;
    case 3598: /* module 14 call 14 */
        return STR_ME_NOTE_PREIMAGE;
    case 3599: /* module 14 call 15 */
        return STR_ME_NOTE_PREIMAGE_OPERATIONAL;
    case 3600: /* module 14 call 16 */
        return STR_ME_NOTE_IMMINENT_PREIMAGE;
    case 3601: /* module 14 call 17 */
        return STR_ME_NOTE_IMMINENT_PREIMAGE_OPERATIONAL;
    case 3602: /* module 14 call 18 */
        return STR_ME_REAP_PREIMAGE;
    case 3603: /* module 14 call 19 */
        return STR_ME_UNLOCK;
    case 3604: /* module 14 call 20 */
        return STR_ME_REMOVE_VOTE;
    case 3605: /* module 14 call 21 */
        return STR_ME_REMOVE_OTHER_VOTE;
    case 3606: /* module 14 call 22 */
        return STR_ME_ENACT_PROPOSAL;
    case 3607: /* module 14 call 23 */
        return STR_ME_BLACKLIST;
    case 3608: /* module 14 call 24 */
        return STR_ME_CANCEL_PROPOSAL;
    case 3840: /* module 15 call 0 */
        return STR_ME_SET_MEMBERS;
    case 3841: /* module 15 call 1 */
        return STR_ME_EXECUTE;
    case 3842: /* module 15 call 2 */
        return STR_ME_PROPOSE;
    case 3843: /* module 15 call 3 */
        return STR_ME_VOTE;
    case 3844: /* module 15 call 4 */
        return STR_ME_CLOSE;
    case 3845: /* module 15 call 5 */
        return STR_ME_DISAPPROVE_PROPOSAL;
    case 4096: /* module 16 call 0 */
        return STR_ME_SET_MEMBERS;
    case 4097: /* module 16 call 1 */
        return STR_ME_EXECUTE;
    case 4098: /* module 16 call 2 */
        return STR_ME_PROPOSE;
    case 4099: /* module 16 call 3 */
        return STR_ME_VOTE;
    case 4100: /* module 16 call 4 */
        return STR_ME_CLOSE;
    case 4101: /* module 16 call 5 */
        return STR_ME_DISAPPROVE_PROPOSAL;
    case 4352: /* module 17 call 0 */
        return STR_ME_VOTE;
    case 4353: /* module 17 call 1 */
        return STR_ME_REMOVE_VOTER;
    case 4354: /* module 17 call 2 */
        return STR_ME_SUBMIT_CANDIDACY;
    case 4355: /* module 17 call 3 */
        return STR_ME_RENOUNCE_CANDIDACY;
    case 4356: /* module 17 call 4 */
        return STR_ME_REMOVE_MEMBER;
    case 4357: /* module 17 call 5 */
        return STR_ME_CLEAN_DEFUNCT_VOTERS;
    case 4608: /* module 18 call 0 */
        return STR_ME_ADD_MEMBER;
    case 4609: /* module 18 call 1 */
        return STR_ME_REMOVE_MEMBER;
    case 4610: /* module 18 call 2 */
        return STR_ME_SWAP_MEMBER;
    case 4611: /* module 18 call 3 */
        return STR_ME_RESET_MEMBERS;
    case 4612: /* module 18 call 4 */
        return STR_ME_CHANGE_KEY;
    case 4613: /* module 18 call 5 */
        return STR_ME_SET_PRIME;
    case 4614: /* module 18 call 6 */
        return STR_ME_CLEAR_PRIME;
    case 4864: /* module 19 call 0 */
        return STR_ME_PROPOSE_SPEND;
    case 4865: /* module 19 call 1 */
        return STR_ME_REJECT_PROPOSAL;
    case 4866: /* module 19 call 2 */
        return STR_ME_APPROVE_PROPOSAL;
    case 6144: /* module 24 call 0 */
        return STR_ME_CLAIM;
    case 6145: /* module 24 call 1 */
        return STR_ME_MINT_CLAIM;
    case 6146: /* module 24 call 2 */
        return STR_ME_CLAIM_ATTEST;
    case 6147: /* module 24 call 3 */
        return STR_ME_ATTEST;
    case 6148: /* module 24 call 4 */
        return STR_ME_MOVE_CLAIM;
    case 6400: /* module 25 call 0 */
        return STR_ME_VEST;
    case 6401: /* module 25 call 1 */
        return STR_ME_VEST_OTHER;
    case 6402: /* module 25 call 2 */
        return STR_ME_VESTED_TRANSFER;
    case 6403: /* module 25 call 3 */
        return STR_ME_FORCE_VESTED_TRANSFER;
    case 6657: /* module 26 call 1 */
        return STR_ME_AS_DERIVATIVE;
    case 7168: /* module 28 call 0 */
        return STR_ME_ADD_REGISTRAR;
    case 7169: /* module 28 call 1 */
        return STR_ME_SET_IDENTITY;
    case 7170: /* module 28 call 2 */
        return STR_ME_SET_SUBS;
    case 7171: /* module 28 call 3 */
        return STR_ME_CLEAR_IDENTITY;
    case 7172: /* module 28 call 4 */
        return STR_ME_REQUEST_JUDGEMENT;
    case 7173: /* module 28 call 5 */
        return STR_ME_CANCEL_REQUEST;
    case 7174: /* module 28 call 6 */
        return STR_ME_SET_FEE;
    case 7175: /* module 28 call 7 */
        return STR_ME_SET_ACCOUNT_ID;
    case 7176: /* module 28 call 8 */
        return STR_ME_SET_FIELDS;
    case 7177: /* module 28 call 9 */
        return STR_ME_PROVIDE_JUDGEMENT;
    case 7178: /* module 28 call 10 */
        return STR_ME_KILL_IDENTITY;
    case 7179: /* module 28 call 11 */
        return STR_ME_ADD_SUB;
    case 7180: /* module 28 call 12 */
        return STR_ME_RENAME_SUB;
    case 7181: /* module 28 call 13 */
        return STR_ME_REMOVE_SUB;
    case 7182: /* module 28 call 14 */
        return STR_ME_QUIT_SUB;
    case 7424: /* module 29 call 0 */
        return STR_ME_PROXY;
    case 7425: /* module 29 call 1 */
        return STR_ME_ADD_PROXY;
    case 7426: /* module 29 call 2 */
        return STR_ME_REMOVE_PROXY;
    case 7427: /* module 29 call 3 */
        return STR_ME_REMOVE_PROXIES;
    case 7428: /* module 29 call 4 */
        return STR_ME_ANONYMOUS;
    case 7429: /* module 29 call 5 */
        return STR_ME_KILL_ANONYMOUS;
    case 7430: /* module 29 call 6 */
        return STR_ME_ANNOUNCE;
    case 7431: /* module 29 call 7 */
        return STR_ME_REMOVE_ANNOUNCEMENT;
    case 7432: /* module 29 call 8 */
        return STR_ME_REJECT_ANNOUNCEMENT;
    case 7433: /* module 29 call 9 */
        return STR_ME_PROXY_ANNOUNCED;
    case 7680: /* module 30 call 0 */
        return STR_ME_AS_MULTI_THRESHOLD_1;
    case 7681: /* module 30 call 1 */
        return STR_ME_AS_MULTI;
    case 7682: /* module 30 call 2 */
        return STR_ME_APPROVE_AS_MULTI;
    case 7683: /* module 30 call 3 */
        return STR_ME_CANCEL_AS_MULTI;
    case 8704: /* module 34 call 0 */
        return STR_ME_PROPOSE_BOUNTY;
    case 8705: /* module 34 call 1 */
        return STR_ME_APPROVE_BOUNTY;
    case 8706: /* module 34 call 2 */
        return STR_ME_PROPOSE_CURATOR;
    case 8707: /* module 34 call 3 */
        return STR_ME_UNASSIGN_CURATOR;
    case 8708: /* module 34 call 4 */
        return STR_ME_ACCEPT_CURATOR;
    case 8709: /* module 34 call 5 */
        return STR_ME_AWARD_BOUNTY;
    case 8710: /* module 34 call 6 */
        return STR_ME_CLAIM_BOUNTY;
    case 8711: /* module 34 call 7 */
        return STR_ME_CLOSE_BOUNTY;
    case 8712: /* module 34 call 8 */
        return STR_ME_EXTEND_BOUNTY_EXPIRY;
    case 8960: /* module 35 call 0 */
        return STR_ME_REPORT_AWESOME;
    case 8961: /* module 35 call 1 */
        return STR_ME_RETRACT_TIP;
    case 8962: /* module 35 call 2 */
        return STR_ME_TIP_NEW;
    case 8963: /* module 35 call 3 */
        return STR_ME_TIP;
    case 8964: /* module 35 call 4 */
        return STR_ME_CLOSE_TIP;
    case 8965: /* module 35 call 5 */
        return STR_ME_SLASH_TIP;
    case 9216: /* module 36 call 0 */
        return STR_ME_SUBMIT_UNSIGNED;
#endif
    default:
        return NULL;
    }

    return NULL;
}

uint8_t _getMethod_NumItems_V6(uint8_t moduleIdx, uint8_t callIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 1280: /* module 5 call 0 */
        return 2;
    case 1283: /* module 5 call 3 */
        return 2;
    case 1792: /* module 7 call 0 */
        return 3;
    case 1793: /* module 7 call 1 */
        return 1;
    case 1794: /* module 7 call 2 */
        return 1;
    case 1795: /* module 7 call 3 */
        return 1;
    case 1796: /* module 7 call 4 */
        return 1;
    case 1797: /* module 7 call 5 */
        return 1;
    case 1798: /* module 7 call 6 */
        return 0;
    case 1799: /* module 7 call 7 */
        return 1;
    case 1810: /* module 7 call 18 */
        return 2;
    case 1811: /* module 7 call 19 */
        return 1;
    case 2304: /* module 9 call 0 */
        return 2;
    case 2305: /* module 9 call 1 */
        return 0;
    case 6656: /* module 26 call 0 */
        return 1;
    case 6658: /* module 26 call 2 */
        return 1;
#ifdef SUBSTRATE_PARSER_FULL
    case 0: /* module 0 call 0 */
        return 1;
    case 1: /* module 0 call 1 */
        return 1;
    case 2: /* module 0 call 2 */
        return 1;
    case 3: /* module 0 call 3 */
        return 1;
    case 4: /* module 0 call 4 */
        return 1;
    case 5: /* module 0 call 5 */
        return 1;
    case 6: /* module 0 call 6 */
        return 1;
    case 7: /* module 0 call 7 */
        return 1;
    case 8: /* module 0 call 8 */
        return 2;
    case 256: /* module 1 call 0 */
        return 4;
    case 257: /* module 1 call 1 */
        return 2;
    case 258: /* module 1 call 2 */
        return 5;
    case 259: /* module 1 call 3 */
        return 1;
    case 260: /* module 1 call 4 */
        return 4;
    case 261: /* module 1 call 5 */
        return 5;
    case 512: /* module 2 call 0 */
        return 2;
    case 513: /* module 2 call 1 */
        return 2;
    case 768: /* module 3 call 0 */
        return 1;
    case 1024: /* module 4 call 0 */
        return 1;
    case 1025: /* module 4 call 1 */
        return 2;
    case 1026: /* module 4 call 2 */
        return 1;
    case 1027: /* module 4 call 3 */
        return 3;
    case 1028: /* module 4 call 4 */
        return 1;
    case 1281: /* module 5 call 1 */
        return 3;
    case 1282: /* module 5 call 2 */
        return 3;
    case 1536: /* module 6 call 0 */
        return 1;
    case 1800: /* module 7 call 8 */
        return 1;
    case 1801: /* module 7 call 9 */
        return 1;
    case 1802: /* module 7 call 10 */
        return 1;
    case 1803: /* module 7 call 11 */
        return 1;
    case 1804: /* module 7 call 12 */
        return 0;
    case 1805: /* module 7 call 13 */
        return 0;
    case 1806: /* module 7 call 14 */
        return 1;
    case 1807: /* module 7 call 15 */
        return 2;
    case 1808: /* module 7 call 16 */
        return 0;
    case 1809: /* module 7 call 17 */
        return 2;
    case 1812: /* module 7 call 20 */
        return 2;
    case 1813: /* module 7 call 21 */
        return 2;
    case 1814: /* module 7 call 22 */
        return 5;
    case 1815: /* module 7 call 23 */
        return 5;
    case 1816: /* module 7 call 24 */
        return 1;
    case 2816: /* module 11 call 0 */
        return 2;
    case 2817: /* module 11 call 1 */
        return 2;
    case 2818: /* module 11 call 2 */
        return 2;
    case 3072: /* module 12 call 0 */
        return 2;
    case 3584: /* module 14 call 0 */
        return 2;
    case 3585: /* module 14 call 1 */
        return 2;
    case 3586: /* module 14 call 2 */
        return 2;
    case 3587: /* module 14 call 3 */
        return 1;
    case 3588: /* module 14 call 4 */
        return 1;
    case 3589: /* module 14 call 5 */
        return 1;
    case 3590: /* module 14 call 6 */
        return 1;
    case 3591: /* module 14 call 7 */
        return 3;
    case 3592: /* module 14 call 8 */
        return 1;
    case 3593: /* module 14 call 9 */
        return 1;
    case 3594: /* module 14 call 10 */
        return 1;
    case 3595: /* module 14 call 11 */
        return 3;
    case 3596: /* module 14 call 12 */
        return 0;
    case 3597: /* module 14 call 13 */
        return 0;
    case 3598: /* module 14 call 14 */
        return 1;
    case 3599: /* module 14 call 15 */
        return 1;
    case 3600: /* module 14 call 16 */
        return 1;
    case 3601: /* module 14 call 17 */
        return 1;
    case 3602: /* module 14 call 18 */
        return 2;
    case 3603: /* module 14 call 19 */
        return 1;
    case 3604: /* module 14 call 20 */
        return 1;
    case 3605: /* module 14 call 21 */
        return 2;
    case 3606: /* module 14 call 22 */
        return 2;
    case 3607: /* module 14 call 23 */
        return 2;
    case 3608: /* module 14 call 24 */
        return 1;
    case 3840: /* module 15 call 0 */
        return 3;
    case 3841: /* module 15 call 1 */
        return 2;
    case 3842: /* module 15 call 2 */
        return 3;
    case 3843: /* module 15 call 3 */
        return 3;
    case 3844: /* module 15 call 4 */
        return 4;
    case 3845: /* module 15 call 5 */
        return 1;
    case 4096: /* module 16 call 0 */
        return 3;
    case 4097: /* module 16 call 1 */
        return 2;
    case 4098: /* module 16 call 2 */
        return 3;
    case 4099: /* module 16 call 3 */
        return 3;
    case 4100: /* module 16 call 4 */
        return 4;
    case 4101: /* module 16 call 5 */
        return 1;
    case 4352: /* module 17 call 0 */
        return 2;
    case 4353: /* module 17 call 1 */
        return 0;
    case 4354: /* module 17 call 2 */
        return 1;
    case 4355: /* module 17 call 3 */
        return 1;
    case 4356: /* module 17 call 4 */
        return 2;
    case 4357: /* module 17 call 5 */
        return 2;
    case 4608: /* module 18 call 0 */
        return 1;
    case 4609: /* module 18 call 1 */
        return 1;
    case 4610: /* module 18 call 2 */
        return 2;
    case 4611: /* module 18 call 3 */
        return 1;
    case 4612: /* module 18 call 4 */
        return 1;
    case 4613: /* module 18 call 5 */
        return 1;
    case 4614: /* module 18 call 6 */
        return 0;
    case 4864: /* module 19 call 0 */
        return 2;
    case 4865: /* module 19 call 1 */
        return 1;
    case 4866: /* module 19 call 2 */
        return 1;
    case 6144: /* module 24 call 0 */
        return 2;
    case 6145: /* module 24 call 1 */
        return 4;
    case 6146: /* module 24 call 2 */
        return 3;
    case 6147: /* module 24 call 3 */
        return 1;
    case 6148: /* module 24 call 4 */
        return 3;
    case 6400: /* module 25 call 0 */
        return 0;
    case 6401: /* module 25 call 1 */
        return 1;
    case 6402: /* module 25 call 2 */
        return 2;
    case 6403: /* module 25 call 3 */
        return 3;
    case 6657: /* module 26 call 1 */
        return 2;
    case 7168: /* module 28 call 0 */
        return 1;
    case 7169: /* module 28 call 1 */
        return 1;
    case 7170: /* module 28 call 2 */
        return 1;
    case 7171: /* module 28 call 3 */
        return 0;
    case 7172: /* module 28 call 4 */
        return 2;
    case 7173: /* module 28 call 5 */
        return 1;
    case 7174: /* module 28 call 6 */
        return 2;
    case 7175: /* module 28 call 7 */
        return 2;
    case 7176: /* module 28 call 8 */
        return 2;
    case 7177: /* module 28 call 9 */
        return 3;
    case 7178: /* module 28 call 10 */
        return 1;
    case 7179: /* module 28 call 11 */
        return 2;
    case 7180: /* module 28 call 12 */
        return 2;
    case 7181: /* module 28 call 13 */
        return 1;
    case 7182: /* module 28 call 14 */
        return 0;
    case 7424: /* module 29 call 0 */
        return 3;
    case 7425: /* module 29 call 1 */
        return 3;
    case 7426: /* module 29 call 2 */
        return 3;
    case 7427: /* module 29 call 3 */
        return 0;
    case 7428: /* module 29 call 4 */
        return 3;
    case 7429: /* module 29 call 5 */
        return 5;
    case 7430: /* module 29 call 6 */
        return 2;
    case 7431: /* module 29 call 7 */
        return 2;
    case 7432: /* module 29 call 8 */
        return 2;
    case 7433: /* module 29 call 9 */
        return 4;
    case 7680: /* module 30 call 0 */
        return 2;
    case 7681: /* module 30 call 1 */
        return 6;
    case 7682: /* module 30 call 2 */
        return 5;
    case 7683: /* module 30 call 3 */
        return 4;
    case 8704: /* module 34 call 0 */
        return 2;
    case 8705: /* module 34 call 1 */
        return 1;
    case 8706: /* module 34 call 2 */
        return 3;
    case 8707: /* module 34 call 3 */
        return 1;
    case 8708: /* module 34 call 4 */
        return 1;
    case 8709: /* module 34 call 5 */
        return 2;
    case 8710: /* module 34 call 6 */
        return 1;
    case 8711: /* module 34 call 7 */
        return 1;
    case 8712: /* module 34 call 8 */
        return 2;
    case 8960: /* module 35 call 0 */
        return 2;
    case 8961: /* module 35 call 1 */
        return 1;
    case 8962: /* module 35 call 2 */
        return 3;
    case 8963: /* module 35 call 3 */
        return 2;
    case 8964: /* module 35 call 4 */
        return 1;
    case 8965: /* module 35 call 5 */
        return 1;
    case 9216: /* module 36 call 0 */
        return 2;
#endif
    default:
        return 0;
    }

    return 0;
}

const char* _getMethod_ItemName_V6(uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 1280: /* module 5 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_value;
        default:
            return NULL;
        }
    case 1283: /* module 5 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_value;
        default:
            return NULL;
        }
    case 1792: /* module 7 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_controller;
        case 1:
            return STR_IT_value;
        case 2:
            return STR_IT_payee;
        default:
            return NULL;
        }
    case 1793: /* module 7 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_max_additional;
        default:
            return NULL;
        }
    case 1794: /* module 7 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_value;
        default:
            return NULL;
        }
    case 1795: /* module 7 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_num_slashing_spans;
        default:
            return NULL;
        }
    case 1796: /* module 7 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_prefs;
        default:
            return NULL;
        }
    case 1797: /* module 7 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_targets;
        default:
            return NULL;
        }
    case 1798: /* module 7 call 6 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 1799: /* module 7 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_payee;
        default:
            return NULL;
        }
    case 1810: /* module 7 call 18 */
        switch (itemIdx) {
        case 0:
            return STR_IT_validator_stash;
        case 1:
            return STR_IT_era;
        default:
            return NULL;
        }
    case 1811: /* module 7 call 19 */
        switch (itemIdx) {
        case 0:
            return STR_IT_value;
        default:
            return NULL;
        }
    case 2304: /* module 9 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_keys;
        case 1:
            return STR_IT_proof;
        default:
            return NULL;
        }
    case 2305: /* module 9 call 1 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 6656: /* module 26 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_calls;
        default:
            return NULL;
        }
    case 6658: /* module 26 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_calls;
        default:
            return NULL;
        }
#ifdef SUBSTRATE_PARSER_FULL
    case 0: /* module 0 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT__ratio;
        default:
            return NULL;
        }
    case 1: /* module 0 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT__remark;
        default:
            return NULL;
        }
    case 2: /* module 0 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_pages;
        default:
            return NULL;
        }
    case 3: /* module 0 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_code;
        default:
            return NULL;
        }
    case 4: /* module 0 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_code;
        default:
            return NULL;
        }
    case 5: /* module 0 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_changes_trie_config;
        default:
            return NULL;
        }
    case 6: /* module 0 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_items;
        default:
            return NULL;
        }
    case 7: /* module 0 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_keys;
        default:
            return NULL;
        }
    case 8: /* module 0 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_prefix;
        case 1:
            return STR_IT__subkeys;
        default:
            return NULL;
        }
    case 256: /* module 1 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_when;
        case 1:
            return STR_IT_maybe_periodic;
        case 2:
            return STR_IT_priority;
        case 3:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 257: /* module 1 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_when;
        case 1:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 258: /* module 1 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_when;
        case 2:
            return STR_IT_maybe_periodic;
        case 3:
            return STR_IT_priority;
        case 4:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 259: /* module 1 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        default:
            return NULL;
        }
    case 260: /* module 1 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_after;
        case 1:
            return STR_IT_maybe_periodic;
        case 2:
            return STR_IT_priority;
        case 3:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 261: /* module 1 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_after;
        case 2:
            return STR_IT_maybe_periodic;
        case 3:
            return STR_IT_priority;
        case 4:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 512: /* module 2 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_equivocation_proof;
        case 1:
            return STR_IT_key_owner_proof;
        default:
            return NULL;
        }
    case 513: /* module 2 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_equivocation_proof;
        case 1:
            return STR_IT_key_owner_proof;
        default:
            return NULL;
        }
    case 768: /* module 3 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_now;
        default:
            return NULL;
        }
    case 1024: /* module 4 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 1025: /* module 4 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        case 1:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 1026: /* module 4 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 1027: /* module 4 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        case 1:
            return STR_IT_index;
        case 2:
            return STR_IT_freeze;
        default:
            return NULL;
        }
    case 1028: /* module 4 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 1281: /* module 5 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        case 1:
            return STR_IT_new_free;
        case 2:
            return STR_IT_new_reserved;
        default:
            return NULL;
        }
    case 1282: /* module 5 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_source;
        case 1:
            return STR_IT_dest;
        case 2:
            return STR_IT_value;
        default:
            return NULL;
        }
    case 1536: /* module 6 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_uncles;
        default:
            return NULL;
        }
    case 1800: /* module 7 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_controller;
        default:
            return NULL;
        }
    case 1801: /* module 7 call 9 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 1802: /* module 7 call 10 */
        switch (itemIdx) {
        case 0:
            return STR_IT_additional;
        default:
            return NULL;
        }
    case 1803: /* module 7 call 11 */
        switch (itemIdx) {
        case 0:
            return STR_IT_factor;
        default:
            return NULL;
        }
    case 1804: /* module 7 call 12 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 1805: /* module 7 call 13 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 1806: /* module 7 call 14 */
        switch (itemIdx) {
        case 0:
            return STR_IT_invulnerables;
        default:
            return NULL;
        }
    case 1807: /* module 7 call 15 */
        switch (itemIdx) {
        case 0:
            return STR_IT_stash;
        case 1:
            return STR_IT_num_slashing_spans;
        default:
            return NULL;
        }
    case 1808: /* module 7 call 16 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 1809: /* module 7 call 17 */
        switch (itemIdx) {
        case 0:
            return STR_IT_era;
        case 1:
            return STR_IT_slash_indices;
        default:
            return NULL;
        }
    case 1812: /* module 7 call 20 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_history_depth;
        case 1:
            return STR_IT__era_items_deleted;
        default:
            return NULL;
        }
    case 1813: /* module 7 call 21 */
        switch (itemIdx) {
        case 0:
            return STR_IT_stash;
        case 1:
            return STR_IT_num_slashing_spans;
        default:
            return NULL;
        }
    case 1814: /* module 7 call 22 */
        switch (itemIdx) {
        case 0:
            return STR_IT_winners;
        case 1:
            return STR_IT_compact;
        case 2:
            return STR_IT_score;
        case 3:
            return STR_IT_era;
        case 4:
            return STR_IT_size;
        default:
            return NULL;
        }
    case 1815: /* module 7 call 23 */
        switch (itemIdx) {
        case 0:
            return STR_IT_winners;
        case 1:
            return STR_IT_compact;
        case 2:
            return STR_IT_score;
        case 3:
            return STR_IT_era;
        case 4:
            return STR_IT_size;
        default:
            return NULL;
        }
    case 1816: /* module 7 call 24 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 2816: /* module 11 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_equivocation_proof;
        case 1:
            return STR_IT_key_owner_proof;
        default:
            return NULL;
        }
    case 2817: /* module 11 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_equivocation_proof;
        case 1:
            return STR_IT_key_owner_proof;
        default:
            return NULL;
        }
    case 2818: /* module 11 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_delay;
        case 1:
            return STR_IT_best_finalized_block_number;
        default:
            return NULL;
        }
    case 3072: /* module 12 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_heartbeat;
        case 1:
            return STR_IT__signature;
        default:
            return NULL;
        }
    case 3584: /* module 14 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        case 1:
            return STR_IT_value;
        default:
            return NULL;
        }
    case 3585: /* module 14 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal;
        case 1:
            return STR_IT_seconds_upper_bound;
        default:
            return NULL;
        }
    case 3586: /* module 14 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ref_index;
        case 1:
            return STR_IT_vote;
        default:
            return NULL;
        }
    case 3587: /* module 14 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ref_index;
        default:
            return NULL;
        }
    case 3588: /* module 14 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        default:
            return NULL;
        }
    case 3589: /* module 14 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        default:
            return NULL;
        }
    case 3590: /* module 14 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        default:
            return NULL;
        }
    case 3591: /* module 14 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        case 1:
            return STR_IT_voting_period;
        case 2:
            return STR_IT_delay;
        default:
            return NULL;
        }
    case 3592: /* module 14 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        default:
            return NULL;
        }
    case 3593: /* module 14 call 9 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ref_index;
        default:
            return NULL;
        }
    case 3594: /* module 14 call 10 */
        switch (itemIdx) {
        case 0:
            return STR_IT_which;
        default:
            return NULL;
        }
    case 3595: /* module 14 call 11 */
        switch (itemIdx) {
        case 0:
            return STR_IT_to;
        case 1:
            return STR_IT_conviction;
        case 2:
            return STR_IT_balance;
        default:
            return NULL;
        }
    case 3596: /* module 14 call 12 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 3597: /* module 14 call 13 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 3598: /* module 14 call 14 */
        switch (itemIdx) {
        case 0:
            return STR_IT_encoded_proposal;
        default:
            return NULL;
        }
    case 3599: /* module 14 call 15 */
        switch (itemIdx) {
        case 0:
            return STR_IT_encoded_proposal;
        default:
            return NULL;
        }
    case 3600: /* module 14 call 16 */
        switch (itemIdx) {
        case 0:
            return STR_IT_encoded_proposal;
        default:
            return NULL;
        }
    case 3601: /* module 14 call 17 */
        switch (itemIdx) {
        case 0:
            return STR_IT_encoded_proposal;
        default:
            return NULL;
        }
    case 3602: /* module 14 call 18 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        case 1:
            return STR_IT_proposal_len_upper_bound;
        default:
            return NULL;
        }
    case 3603: /* module 14 call 19 */
        switch (itemIdx) {
        case 0:
            return STR_IT_target;
        default:
            return NULL;
        }
    case 3604: /* module 14 call 20 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 3605: /* module 14 call 21 */
        switch (itemIdx) {
        case 0:
            return STR_IT_target;
        case 1:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 3606: /* module 14 call 22 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        case 1:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 3607: /* module 14 call 23 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        case 1:
            return STR_IT_maybe_ref_index;
        default:
            return NULL;
        }
    case 3608: /* module 14 call 24 */
        switch (itemIdx) {
        case 0:
            return STR_IT_prop_index;
        default:
            return NULL;
        }
    case 3840: /* module 15 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_members;
        case 1:
            return STR_IT_prime;
        case 2:
            return STR_IT_old_count;
        default:
            return NULL;
        }
    case 3841: /* module 15 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal;
        case 1:
            return STR_IT_length_bound;
        default:
            return NULL;
        }
    case 3842: /* module 15 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_threshold;
        case 1:
            return STR_IT_proposal;
        case 2:
            return STR_IT_length_bound;
        default:
            return NULL;
        }
    case 3843: /* module 15 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal;
        case 1:
            return STR_IT_index;
        case 2:
            return STR_IT_approve;
        default:
            return NULL;
        }
    case 3844: /* module 15 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        case 1:
            return STR_IT_index;
        case 2:
            return STR_IT_proposal_weight_bound;
        case 3:
            return STR_IT_length_bound;
        default:
            return NULL;
        }
    case 3845: /* module 15 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        default:
            return NULL;
        }
    case 4096: /* module 16 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_members;
        case 1:
            return STR_IT_prime;
        case 2:
            return STR_IT_old_count;
        default:
            return NULL;
        }
    case 4097: /* module 16 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal;
        case 1:
            return STR_IT_length_bound;
        default:
            return NULL;
        }
    case 4098: /* module 16 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_threshold;
        case 1:
            return STR_IT_proposal;
        case 2:
            return STR_IT_length_bound;
        default:
            return NULL;
        }
    case 4099: /* module 16 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal;
        case 1:
            return STR_IT_index;
        case 2:
            return STR_IT_approve;
        default:
            return NULL;
        }
    case 4100: /* module 16 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        case 1:
            return STR_IT_index;
        case 2:
            return STR_IT_proposal_weight_bound;
        case 3:
            return STR_IT_length_bound;
        default:
            return NULL;
        }
    case 4101: /* module 16 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        default:
            return NULL;
        }
    case 4352: /* module 17 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_votes;
        case 1:
            return STR_IT_value;
        default:
            return NULL;
        }
    case 4353: /* module 17 call 1 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 4354: /* module 17 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_candidate_count;
        default:
            return NULL;
        }
    case 4355: /* module 17 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_renouncing;
        default:
            return NULL;
        }
    case 4356: /* module 17 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        case 1:
            return STR_IT_has_replacement;
        default:
            return NULL;
        }
    case 4357: /* module 17 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT__num_voters;
        case 1:
            return STR_IT__num_defunct;
        default:
            return NULL;
        }
    case 4608: /* module 18 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 4609: /* module 18 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 4610: /* module 18 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_remove;
        case 1:
            return STR_IT_add;
        default:
            return NULL;
        }
    case 4611: /* module 18 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_members;
        default:
            return NULL;
        }
    case 4612: /* module 18 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 4613: /* module 18 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 4614: /* module 18 call 6 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 4864: /* module 19 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_value;
        case 1:
            return STR_IT_beneficiary;
        default:
            return NULL;
        }
    case 4865: /* module 19 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_id;
        default:
            return NULL;
        }
    case 4866: /* module 19 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_id;
        default:
            return NULL;
        }
    case 6144: /* module 24 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_ethereum_signature;
        default:
            return NULL;
        }
    case 6145: /* module 24 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        case 1:
            return STR_IT_value;
        case 2:
            return STR_IT_vesting_schedule;
        case 3:
            return STR_IT_statement;
        default:
            return NULL;
        }
    case 6146: /* module 24 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_ethereum_signature;
        case 2:
            return STR_IT_statement;
        default:
            return NULL;
        }
    case 6147: /* module 24 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_statement;
        default:
            return NULL;
        }
    case 6148: /* module 24 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_old;
        case 1:
            return STR_IT_new_;
        case 2:
            return STR_IT_maybe_preclaim;
        default:
            return NULL;
        }
    case 6400: /* module 25 call 0 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 6401: /* module 25 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_target;
        default:
            return NULL;
        }
    case 6402: /* module 25 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_target;
        case 1:
            return STR_IT_schedule;
        default:
            return NULL;
        }
    case 6403: /* module 25 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_source;
        case 1:
            return STR_IT_target;
        case 2:
            return STR_IT_schedule;
        default:
            return NULL;
        }
    case 6657: /* module 26 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        case 1:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 7168: /* module 28 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_account;
        default:
            return NULL;
        }
    case 7169: /* module 28 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_info;
        default:
            return NULL;
        }
    case 7170: /* module 28 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_subs;
        default:
            return NULL;
        }
    case 7171: /* module 28 call 3 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 7172: /* module 28 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_reg_index;
        case 1:
            return STR_IT_max_fee;
        default:
            return NULL;
        }
    case 7173: /* module 28 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_reg_index;
        default:
            return NULL;
        }
    case 7174: /* module 28 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        case 1:
            return STR_IT_fee;
        default:
            return NULL;
        }
    case 7175: /* module 28 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        case 1:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 7176: /* module 28 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        case 1:
            return STR_IT_fields;
        default:
            return NULL;
        }
    case 7177: /* module 28 call 9 */
        switch (itemIdx) {
        case 0:
            return STR_IT_reg_index;
        case 1:
            return STR_IT_target;
        case 2:
            return STR_IT_judgement;
        default:
            return NULL;
        }
    case 7178: /* module 28 call 10 */
        switch (itemIdx) {
        case 0:
            return STR_IT_target;
        default:
            return NULL;
        }
    case 7179: /* module 28 call 11 */
        switch (itemIdx) {
        case 0:
            return STR_IT_sub;
        case 1:
            return STR_IT_data;
        default:
            return NULL;
        }
    case 7180: /* module 28 call 12 */
        switch (itemIdx) {
        case 0:
            return STR_IT_sub;
        case 1:
            return STR_IT_data;
        default:
            return NULL;
        }
    case 7181: /* module 28 call 13 */
        switch (itemIdx) {
        case 0:
            return STR_IT_sub;
        default:
            return NULL;
        }
    case 7182: /* module 28 call 14 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 7424: /* module 29 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_real;
        case 1:
            return STR_IT_force_proxy_type;
        case 2:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 7425: /* module 29 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_delegate;
        case 1:
            return STR_IT_proxy_type;
        case 2:
            return STR_IT_delay;
        default:
            return NULL;
        }
    case 7426: /* module 29 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_delegate;
        case 1:
            return STR_IT_proxy_type;
        case 2:
            return STR_IT_delay;
        default:
            return NULL;
        }
    case 7427: /* module 29 call 3 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 7428: /* module 29 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proxy_type;
        case 1:
            return STR_IT_delay;
        case 2:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 7429: /* module 29 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_spawner;
        case 1:
            return STR_IT_proxy_type;
        case 2:
            return STR_IT_index;
        case 3:
            return STR_IT_height;
        case 4:
            return STR_IT_ext_index;
        default:
            return NULL;
        }
    case 7430: /* module 29 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_real;
        case 1:
            return STR_IT_call_hash;
        default:
            return NULL;
        }
    case 7431: /* module 29 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_real;
        case 1:
            return STR_IT_call_hash;
        default:
            return NULL;
        }
    case 7432: /* module 29 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_delegate;
        case 1:
            return STR_IT_call_hash;
        default:
            return NULL;
        }
    case 7433: /* module 29 call 9 */
        switch (itemIdx) {
        case 0:
            return STR_IT_delegate;
        case 1:
            return STR_IT_real;
        case 2:
            return STR_IT_force_proxy_type;
        case 3:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 7680: /* module 30 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_other_signatories;
        case 1:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 7681: /* module 30 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_threshold;
        case 1:
            return STR_IT_other_signatories;
        case 2:
            return STR_IT_maybe_timepoint;
        case 3:
            return STR_IT_call;
        case 4:
            return STR_IT_store_call;
        case 5:
            return STR_IT_max_weight;
        default:
            return NULL;
        }
    case 7682: /* module 30 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_threshold;
        case 1:
            return STR_IT_other_signatories;
        case 2:
            return STR_IT_maybe_timepoint;
        case 3:
            return STR_IT_call_hash;
        case 4:
            return STR_IT_max_weight;
        default:
            return NULL;
        }
    case 7683: /* module 30 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_threshold;
        case 1:
            return STR_IT_other_signatories;
        case 2:
            return STR_IT_timepoint;
        case 3:
            return STR_IT_call_hash;
        default:
            return NULL;
        }
    case 8704: /* module 34 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_value;
        case 1:
            return STR_IT_description;
        default:
            return NULL;
        }
    case 8705: /* module 34 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bounty_id;
        default:
            return NULL;
        }
    case 8706: /* module 34 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bounty_id;
        case 1:
            return STR_IT_curator;
        case 2:
            return STR_IT_fee;
        default:
            return NULL;
        }
    case 8707: /* module 34 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bounty_id;
        default:
            return NULL;
        }
    case 8708: /* module 34 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bounty_id;
        default:
            return NULL;
        }
    case 8709: /* module 34 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bounty_id;
        case 1:
            return STR_IT_beneficiary;
        default:
            return NULL;
        }
    case 8710: /* module 34 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bounty_id;
        default:
            return NULL;
        }
    case 8711: /* module 34 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bounty_id;
        default:
            return NULL;
        }
    case 8712: /* module 34 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bounty_id;
        case 1:
            return STR_IT__remark;
        default:
            return NULL;
        }
    case 8960: /* module 35 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_reason;
        case 1:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 8961: /* module 35 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_hash;
        default:
            return NULL;
        }
    case 8962: /* module 35 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_reason;
        case 1:
            return STR_IT_who;
        case 2:
            return STR_IT_tip_value;
        default:
            return NULL;
        }
    case 8963: /* module 35 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_hash;
        case 1:
            return STR_IT_tip_value;
        default:
            return NULL;
        }
    case 8964: /* module 35 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_hash;
        default:
            return NULL;
        }
    case 8965: /* module 35 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_hash;
        default:
            return NULL;
        }
    case 9216: /* module 36 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_solution;
        case 1:
            return STR_IT_witness;
        default:
            return NULL;
        }
#endif
    default:
        return NULL;
    }

    return NULL;
}

parser_error_t _getMethod_ItemValue_V6(
    pd_Method_V6_t* m,
    uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx,
    char* outValue, uint16_t outValueLen,
    uint8_t pageIdx, uint8_t* pageCount)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 1280: /* module 5 call 0 */
        switch (itemIdx) {
        case 0: /* balances_transfer_V6 - dest */;
            return _toStringLookupSource_V6(
                &m->basic.balances_transfer_V6.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_transfer_V6 - value */;
            return _toStringCompactBalance(
                &m->basic.balances_transfer_V6.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1283: /* module 5 call 3 */
        switch (itemIdx) {
        case 0: /* balances_transfer_keep_alive_V6 - dest */;
            return _toStringLookupSource_V6(
                &m->basic.balances_transfer_keep_alive_V6.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_transfer_keep_alive_V6 - value */;
            return _toStringCompactBalance(
                &m->basic.balances_transfer_keep_alive_V6.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1792: /* module 7 call 0 */
        switch (itemIdx) {
        case 0: /* staking_bond_V6 - controller */;
            return _toStringLookupSource_V6(
                &m->basic.staking_bond_V6.controller,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_bond_V6 - value */;
            return _toStringCompactBalanceOf(
                &m->basic.staking_bond_V6.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* staking_bond_V6 - payee */;
            return _toStringRewardDestination_V6(
                &m->basic.staking_bond_V6.payee,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1793: /* module 7 call 1 */
        switch (itemIdx) {
        case 0: /* staking_bond_extra_V6 - max_additional */;
            return _toStringCompactBalanceOf(
                &m->basic.staking_bond_extra_V6.max_additional,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1794: /* module 7 call 2 */
        switch (itemIdx) {
        case 0: /* staking_unbond_V6 - value */;
            return _toStringCompactBalanceOf(
                &m->basic.staking_unbond_V6.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1795: /* module 7 call 3 */
        switch (itemIdx) {
        case 0: /* staking_withdraw_unbonded_V6 - num_slashing_spans */;
            return _toStringu32(
                &m->basic.staking_withdraw_unbonded_V6.num_slashing_spans,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1796: /* module 7 call 4 */
        switch (itemIdx) {
        case 0: /* staking_validate_V6 - prefs */;
            return _toStringValidatorPrefs_V6(
                &m->basic.staking_validate_V6.prefs,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1797: /* module 7 call 5 */
        switch (itemIdx) {
        case 0: /* staking_nominate_V6 - targets */;
            return _toStringVecLookupSource_V6(
                &m->basic.staking_nominate_V6.targets,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1798: /* module 7 call 6 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 1799: /* module 7 call 7 */
        switch (itemIdx) {
        case 0: /* staking_set_payee_V6 - payee */;
            return _toStringRewardDestination_V6(
                &m->basic.staking_set_payee_V6.payee,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1810: /* module 7 call 18 */
        switch (itemIdx) {
        case 0: /* staking_payout_stakers_V6 - validator_stash */;
            return _toStringAccountId_V6(
                &m->basic.staking_payout_stakers_V6.validator_stash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_payout_stakers_V6 - era */;
            return _toStringEraIndex_V6(
                &m->basic.staking_payout_stakers_V6.era,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1811: /* module 7 call 19 */
        switch (itemIdx) {
        case 0: /* staking_rebond_V6 - value */;
            return _toStringCompactBalanceOf(
                &m->basic.staking_rebond_V6.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2304: /* module 9 call 0 */
        switch (itemIdx) {
        case 0: /* session_set_keys_V6 - keys */;
            return _toStringKeys_V6(
                &m->basic.session_set_keys_V6.keys,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* session_set_keys_V6 - proof */;
            return _toStringBytes(
                &m->basic.session_set_keys_V6.proof,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2305: /* module 9 call 1 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 6656: /* module 26 call 0 */
        switch (itemIdx) {
        case 0: /* utility_batch_V6 - calls */;
            return _toStringVecCall(
                &m->basic.utility_batch_V6.calls,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6658: /* module 26 call 2 */
        switch (itemIdx) {
        case 0: /* utility_batch_all_V6 - calls */;
            return _toStringVecCall(
                &m->basic.utility_batch_all_V6.calls,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
#ifdef SUBSTRATE_PARSER_FULL
    case 0: /* module 0 call 0 */
        switch (itemIdx) {
        case 0: /* system_fill_block_V6 - _ratio */;
            return _toStringPerbill_V6(
                &m->basic.system_fill_block_V6._ratio,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1: /* module 0 call 1 */
        switch (itemIdx) {
        case 0: /* system_remark_V6 - _remark */;
            return _toStringBytes(
                &m->basic.system_remark_V6._remark,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2: /* module 0 call 2 */
        switch (itemIdx) {
        case 0: /* system_set_heap_pages_V6 - pages */;
            return _toStringu64(
                &m->basic.system_set_heap_pages_V6.pages,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3: /* module 0 call 3 */
        switch (itemIdx) {
        case 0: /* system_set_code_V6 - code */;
            return _toStringBytes(
                &m->basic.system_set_code_V6.code,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4: /* module 0 call 4 */
        switch (itemIdx) {
        case 0: /* system_set_code_without_checks_V6 - code */;
            return _toStringBytes(
                &m->basic.system_set_code_without_checks_V6.code,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5: /* module 0 call 5 */
        switch (itemIdx) {
        case 0: /* system_set_changes_trie_config_V6 - changes_trie_config */;
            return _toStringOptionChangesTrieConfiguration_V6(
                &m->basic.system_set_changes_trie_config_V6.changes_trie_config,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6: /* module 0 call 6 */
        switch (itemIdx) {
        case 0: /* system_set_storage_V6 - items */;
            return _toStringVecKeyValue_V6(
                &m->basic.system_set_storage_V6.items,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7: /* module 0 call 7 */
        switch (itemIdx) {
        case 0: /* system_kill_storage_V6 - keys */;
            return _toStringVecKey_V6(
                &m->basic.system_kill_storage_V6.keys,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8: /* module 0 call 8 */
        switch (itemIdx) {
        case 0: /* system_kill_prefix_V6 - prefix */;
            return _toStringKey_V6(
                &m->basic.system_kill_prefix_V6.prefix,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* system_kill_prefix_V6 - _subkeys */;
            return _toStringu32(
                &m->basic.system_kill_prefix_V6._subkeys,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 256: /* module 1 call 0 */
        switch (itemIdx) {
        case 0: /* scheduler_schedule_V6 - when */;
            return _toStringBlockNumber(
                &m->basic.scheduler_schedule_V6.when,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* scheduler_schedule_V6 - maybe_periodic */;
            return _toStringOptionPeriod_V6(
                &m->basic.scheduler_schedule_V6.maybe_periodic,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* scheduler_schedule_V6 - priority */;
            return _toStringPriority_V6(
                &m->basic.scheduler_schedule_V6.priority,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* scheduler_schedule_V6 - call */;
            return _toStringCall(
                &m->basic.scheduler_schedule_V6.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 257: /* module 1 call 1 */
        switch (itemIdx) {
        case 0: /* scheduler_cancel_V6 - when */;
            return _toStringBlockNumber(
                &m->basic.scheduler_cancel_V6.when,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* scheduler_cancel_V6 - index */;
            return _toStringu32(
                &m->basic.scheduler_cancel_V6.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 258: /* module 1 call 2 */
        switch (itemIdx) {
        case 0: /* scheduler_schedule_named_V6 - id */;
            return _toStringBytes(
                &m->basic.scheduler_schedule_named_V6.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* scheduler_schedule_named_V6 - when */;
            return _toStringBlockNumber(
                &m->basic.scheduler_schedule_named_V6.when,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* scheduler_schedule_named_V6 - maybe_periodic */;
            return _toStringOptionPeriod_V6(
                &m->basic.scheduler_schedule_named_V6.maybe_periodic,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* scheduler_schedule_named_V6 - priority */;
            return _toStringPriority_V6(
                &m->basic.scheduler_schedule_named_V6.priority,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* scheduler_schedule_named_V6 - call */;
            return _toStringCall(
                &m->basic.scheduler_schedule_named_V6.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 259: /* module 1 call 3 */
        switch (itemIdx) {
        case 0: /* scheduler_cancel_named_V6 - id */;
            return _toStringBytes(
                &m->basic.scheduler_cancel_named_V6.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 260: /* module 1 call 4 */
        switch (itemIdx) {
        case 0: /* scheduler_schedule_after_V6 - after */;
            return _toStringBlockNumber(
                &m->basic.scheduler_schedule_after_V6.after,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* scheduler_schedule_after_V6 - maybe_periodic */;
            return _toStringOptionPeriod_V6(
                &m->basic.scheduler_schedule_after_V6.maybe_periodic,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* scheduler_schedule_after_V6 - priority */;
            return _toStringPriority_V6(
                &m->basic.scheduler_schedule_after_V6.priority,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* scheduler_schedule_after_V6 - call */;
            return _toStringCall(
                &m->basic.scheduler_schedule_after_V6.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 261: /* module 1 call 5 */
        switch (itemIdx) {
        case 0: /* scheduler_schedule_named_after_V6 - id */;
            return _toStringBytes(
                &m->basic.scheduler_schedule_named_after_V6.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* scheduler_schedule_named_after_V6 - after */;
            return _toStringBlockNumber(
                &m->basic.scheduler_schedule_named_after_V6.after,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* scheduler_schedule_named_after_V6 - maybe_periodic */;
            return _toStringOptionPeriod_V6(
                &m->basic.scheduler_schedule_named_after_V6.maybe_periodic,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* scheduler_schedule_named_after_V6 - priority */;
            return _toStringPriority_V6(
                &m->basic.scheduler_schedule_named_after_V6.priority,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* scheduler_schedule_named_after_V6 - call */;
            return _toStringCall(
                &m->basic.scheduler_schedule_named_after_V6.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 512: /* module 2 call 0 */
        switch (itemIdx) {
        case 0: /* babe_report_equivocation_V6 - equivocation_proof */;
            return _toStringBabeEquivocationProof_V6(
                &m->basic.babe_report_equivocation_V6.equivocation_proof,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* babe_report_equivocation_V6 - key_owner_proof */;
            return _toStringKeyOwnerProof_V6(
                &m->basic.babe_report_equivocation_V6.key_owner_proof,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 513: /* module 2 call 1 */
        switch (itemIdx) {
        case 0: /* babe_report_equivocation_unsigned_V6 - equivocation_proof */;
            return _toStringBabeEquivocationProof_V6(
                &m->basic.babe_report_equivocation_unsigned_V6.equivocation_proof,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* babe_report_equivocation_unsigned_V6 - key_owner_proof */;
            return _toStringKeyOwnerProof_V6(
                &m->basic.babe_report_equivocation_unsigned_V6.key_owner_proof,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 768: /* module 3 call 0 */
        switch (itemIdx) {
        case 0: /* timestamp_set_V6 - now */;
            return _toStringCompactMoment_V6(
                &m->basic.timestamp_set_V6.now,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1024: /* module 4 call 0 */
        switch (itemIdx) {
        case 0: /* indices_claim_V6 - index */;
            return _toStringAccountIndex_V6(
                &m->basic.indices_claim_V6.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1025: /* module 4 call 1 */
        switch (itemIdx) {
        case 0: /* indices_transfer_V6 - new_ */;
            return _toStringAccountId_V6(
                &m->basic.indices_transfer_V6.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* indices_transfer_V6 - index */;
            return _toStringAccountIndex_V6(
                &m->basic.indices_transfer_V6.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1026: /* module 4 call 2 */
        switch (itemIdx) {
        case 0: /* indices_free_V6 - index */;
            return _toStringAccountIndex_V6(
                &m->basic.indices_free_V6.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1027: /* module 4 call 3 */
        switch (itemIdx) {
        case 0: /* indices_force_transfer_V6 - new_ */;
            return _toStringAccountId_V6(
                &m->basic.indices_force_transfer_V6.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* indices_force_transfer_V6 - index */;
            return _toStringAccountIndex_V6(
                &m->basic.indices_force_transfer_V6.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* indices_force_transfer_V6 - freeze */;
            return _toStringbool(
                &m->basic.indices_force_transfer_V6.freeze,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1028: /* module 4 call 4 */
        switch (itemIdx) {
        case 0: /* indices_freeze_V6 - index */;
            return _toStringAccountIndex_V6(
                &m->basic.indices_freeze_V6.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1281: /* module 5 call 1 */
        switch (itemIdx) {
        case 0: /* balances_set_balance_V6 - who */;
            return _toStringLookupSource_V6(
                &m->basic.balances_set_balance_V6.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_set_balance_V6 - new_free */;
            return _toStringCompactBalance(
                &m->basic.balances_set_balance_V6.new_free,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* balances_set_balance_V6 - new_reserved */;
            return _toStringCompactBalance(
                &m->basic.balances_set_balance_V6.new_reserved,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1282: /* module 5 call 2 */
        switch (itemIdx) {
        case 0: /* balances_force_transfer_V6 - source */;
            return _toStringLookupSource_V6(
                &m->basic.balances_force_transfer_V6.source,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_force_transfer_V6 - dest */;
            return _toStringLookupSource_V6(
                &m->basic.balances_force_transfer_V6.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* balances_force_transfer_V6 - value */;
            return _toStringCompactBalance(
                &m->basic.balances_force_transfer_V6.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1536: /* module 6 call 0 */
        switch (itemIdx) {
        case 0: /* authorship_set_uncles_V6 - new_uncles */;
            return _toStringVecHeader(
                &m->basic.authorship_set_uncles_V6.new_uncles,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1800: /* module 7 call 8 */
        switch (itemIdx) {
        case 0: /* staking_set_controller_V6 - controller */;
            return _toStringLookupSource_V6(
                &m->basic.staking_set_controller_V6.controller,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1801: /* module 7 call 9 */
        switch (itemIdx) {
        case 0: /* staking_set_validator_count_V6 - new_ */;
            return _toStringCompactu32(
                &m->basic.staking_set_validator_count_V6.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1802: /* module 7 call 10 */
        switch (itemIdx) {
        case 0: /* staking_increase_validator_count_V6 - additional */;
            return _toStringCompactu32(
                &m->basic.staking_increase_validator_count_V6.additional,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1803: /* module 7 call 11 */
        switch (itemIdx) {
        case 0: /* staking_scale_validator_count_V6 - factor */;
            return _toStringPercent_V6(
                &m->basic.staking_scale_validator_count_V6.factor,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1804: /* module 7 call 12 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 1805: /* module 7 call 13 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 1806: /* module 7 call 14 */
        switch (itemIdx) {
        case 0: /* staking_set_invulnerables_V6 - invulnerables */;
            return _toStringVecAccountId_V6(
                &m->basic.staking_set_invulnerables_V6.invulnerables,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1807: /* module 7 call 15 */
        switch (itemIdx) {
        case 0: /* staking_force_unstake_V6 - stash */;
            return _toStringAccountId_V6(
                &m->basic.staking_force_unstake_V6.stash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_force_unstake_V6 - num_slashing_spans */;
            return _toStringu32(
                &m->basic.staking_force_unstake_V6.num_slashing_spans,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1808: /* module 7 call 16 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 1809: /* module 7 call 17 */
        switch (itemIdx) {
        case 0: /* staking_cancel_deferred_slash_V6 - era */;
            return _toStringEraIndex_V6(
                &m->basic.staking_cancel_deferred_slash_V6.era,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_cancel_deferred_slash_V6 - slash_indices */;
            return _toStringVecu32(
                &m->basic.staking_cancel_deferred_slash_V6.slash_indices,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1812: /* module 7 call 20 */
        switch (itemIdx) {
        case 0: /* staking_set_history_depth_V6 - new_history_depth */;
            return _toStringCompactEraIndex_V6(
                &m->basic.staking_set_history_depth_V6.new_history_depth,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_set_history_depth_V6 - _era_items_deleted */;
            return _toStringCompactu32(
                &m->basic.staking_set_history_depth_V6._era_items_deleted,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1813: /* module 7 call 21 */
        switch (itemIdx) {
        case 0: /* staking_reap_stash_V6 - stash */;
            return _toStringAccountId_V6(
                &m->basic.staking_reap_stash_V6.stash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_reap_stash_V6 - num_slashing_spans */;
            return _toStringu32(
                &m->basic.staking_reap_stash_V6.num_slashing_spans,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1814: /* module 7 call 22 */
        switch (itemIdx) {
        case 0: /* staking_submit_election_solution_V6 - winners */;
            return _toStringVecValidatorIndex_V6(
                &m->basic.staking_submit_election_solution_V6.winners,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_submit_election_solution_V6 - compact */;
            return _toStringCompactAssignments_V6(
                &m->basic.staking_submit_election_solution_V6.compact,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* staking_submit_election_solution_V6 - score */;
            return _toStringElectionScore_V6(
                &m->basic.staking_submit_election_solution_V6.score,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* staking_submit_election_solution_V6 - era */;
            return _toStringEraIndex_V6(
                &m->basic.staking_submit_election_solution_V6.era,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* staking_submit_election_solution_V6 - size */;
            return _toStringElectionSize_V6(
                &m->basic.staking_submit_election_solution_V6.size,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1815: /* module 7 call 23 */
        switch (itemIdx) {
        case 0: /* staking_submit_election_solution_unsigned_V6 - winners */;
            return _toStringVecValidatorIndex_V6(
                &m->basic.staking_submit_election_solution_unsigned_V6.winners,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_submit_election_solution_unsigned_V6 - compact */;
            return _toStringCompactAssignments_V6(
                &m->basic.staking_submit_election_solution_unsigned_V6.compact,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* staking_submit_election_solution_unsigned_V6 - score */;
            return _toStringElectionScore_V6(
                &m->basic.staking_submit_election_solution_unsigned_V6.score,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* staking_submit_election_solution_unsigned_V6 - era */;
            return _toStringEraIndex_V6(
                &m->basic.staking_submit_election_solution_unsigned_V6.era,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* staking_submit_election_solution_unsigned_V6 - size */;
            return _toStringElectionSize_V6(
                &m->basic.staking_submit_election_solution_unsigned_V6.size,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1816: /* module 7 call 24 */
        switch (itemIdx) {
        case 0: /* staking_kick_V6 - who */;
            return _toStringVecLookupSource_V6(
                &m->basic.staking_kick_V6.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2816: /* module 11 call 0 */
        switch (itemIdx) {
        case 0: /* grandpa_report_equivocation_V6 - equivocation_proof */;
            return _toStringGrandpaEquivocationProof_V6(
                &m->basic.grandpa_report_equivocation_V6.equivocation_proof,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* grandpa_report_equivocation_V6 - key_owner_proof */;
            return _toStringKeyOwnerProof_V6(
                &m->basic.grandpa_report_equivocation_V6.key_owner_proof,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2817: /* module 11 call 1 */
        switch (itemIdx) {
        case 0: /* grandpa_report_equivocation_unsigned_V6 - equivocation_proof */;
            return _toStringGrandpaEquivocationProof_V6(
                &m->basic.grandpa_report_equivocation_unsigned_V6.equivocation_proof,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* grandpa_report_equivocation_unsigned_V6 - key_owner_proof */;
            return _toStringKeyOwnerProof_V6(
                &m->basic.grandpa_report_equivocation_unsigned_V6.key_owner_proof,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2818: /* module 11 call 2 */
        switch (itemIdx) {
        case 0: /* grandpa_note_stalled_V6 - delay */;
            return _toStringBlockNumber(
                &m->basic.grandpa_note_stalled_V6.delay,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* grandpa_note_stalled_V6 - best_finalized_block_number */;
            return _toStringBlockNumber(
                &m->basic.grandpa_note_stalled_V6.best_finalized_block_number,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3072: /* module 12 call 0 */
        switch (itemIdx) {
        case 0: /* imonline_heartbeat_V6 - heartbeat */;
            return _toStringHeartbeat(
                &m->basic.imonline_heartbeat_V6.heartbeat,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* imonline_heartbeat_V6 - _signature */;
            return _toStringSignature_V6(
                &m->basic.imonline_heartbeat_V6._signature,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3584: /* module 14 call 0 */
        switch (itemIdx) {
        case 0: /* democracy_propose_V6 - proposal_hash */;
            return _toStringHash(
                &m->basic.democracy_propose_V6.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* democracy_propose_V6 - value */;
            return _toStringCompactBalanceOf(
                &m->basic.democracy_propose_V6.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3585: /* module 14 call 1 */
        switch (itemIdx) {
        case 0: /* democracy_second_V6 - proposal */;
            return _toStringCompactPropIndex_V6(
                &m->basic.democracy_second_V6.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* democracy_second_V6 - seconds_upper_bound */;
            return _toStringCompactu32(
                &m->basic.democracy_second_V6.seconds_upper_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3586: /* module 14 call 2 */
        switch (itemIdx) {
        case 0: /* democracy_vote_V6 - ref_index */;
            return _toStringCompactReferendumIndex_V6(
                &m->basic.democracy_vote_V6.ref_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* democracy_vote_V6 - vote */;
            return _toStringAccountVote_V6(
                &m->basic.democracy_vote_V6.vote,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3587: /* module 14 call 3 */
        switch (itemIdx) {
        case 0: /* democracy_emergency_cancel_V6 - ref_index */;
            return _toStringReferendumIndex_V6(
                &m->basic.democracy_emergency_cancel_V6.ref_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3588: /* module 14 call 4 */
        switch (itemIdx) {
        case 0: /* democracy_external_propose_V6 - proposal_hash */;
            return _toStringHash(
                &m->basic.democracy_external_propose_V6.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3589: /* module 14 call 5 */
        switch (itemIdx) {
        case 0: /* democracy_external_propose_majority_V6 - proposal_hash */;
            return _toStringHash(
                &m->basic.democracy_external_propose_majority_V6.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3590: /* module 14 call 6 */
        switch (itemIdx) {
        case 0: /* democracy_external_propose_default_V6 - proposal_hash */;
            return _toStringHash(
                &m->basic.democracy_external_propose_default_V6.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3591: /* module 14 call 7 */
        switch (itemIdx) {
        case 0: /* democracy_fast_track_V6 - proposal_hash */;
            return _toStringHash(
                &m->basic.democracy_fast_track_V6.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* democracy_fast_track_V6 - voting_period */;
            return _toStringBlockNumber(
                &m->basic.democracy_fast_track_V6.voting_period,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* democracy_fast_track_V6 - delay */;
            return _toStringBlockNumber(
                &m->basic.democracy_fast_track_V6.delay,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3592: /* module 14 call 8 */
        switch (itemIdx) {
        case 0: /* democracy_veto_external_V6 - proposal_hash */;
            return _toStringHash(
                &m->basic.democracy_veto_external_V6.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3593: /* module 14 call 9 */
        switch (itemIdx) {
        case 0: /* democracy_cancel_referendum_V6 - ref_index */;
            return _toStringCompactReferendumIndex_V6(
                &m->basic.democracy_cancel_referendum_V6.ref_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3594: /* module 14 call 10 */
        switch (itemIdx) {
        case 0: /* democracy_cancel_queued_V6 - which */;
            return _toStringReferendumIndex_V6(
                &m->basic.democracy_cancel_queued_V6.which,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3595: /* module 14 call 11 */
        switch (itemIdx) {
        case 0: /* democracy_delegate_V6 - to */;
            return _toStringAccountId_V6(
                &m->basic.democracy_delegate_V6.to,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* democracy_delegate_V6 - conviction */;
            return _toStringConviction_V6(
                &m->basic.democracy_delegate_V6.conviction,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* democracy_delegate_V6 - balance */;
            return _toStringBalanceOf(
                &m->basic.democracy_delegate_V6.balance,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3596: /* module 14 call 12 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 3597: /* module 14 call 13 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 3598: /* module 14 call 14 */
        switch (itemIdx) {
        case 0: /* democracy_note_preimage_V6 - encoded_proposal */;
            return _toStringBytes(
                &m->basic.democracy_note_preimage_V6.encoded_proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3599: /* module 14 call 15 */
        switch (itemIdx) {
        case 0: /* democracy_note_preimage_operational_V6 - encoded_proposal */;
            return _toStringBytes(
                &m->basic.democracy_note_preimage_operational_V6.encoded_proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3600: /* module 14 call 16 */
        switch (itemIdx) {
        case 0: /* democracy_note_imminent_preimage_V6 - encoded_proposal */;
            return _toStringBytes(
                &m->basic.democracy_note_imminent_preimage_V6.encoded_proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3601: /* module 14 call 17 */
        switch (itemIdx) {
        case 0: /* democracy_note_imminent_preimage_operational_V6 - encoded_proposal */;
            return _toStringBytes(
                &m->basic.democracy_note_imminent_preimage_operational_V6.encoded_proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3602: /* module 14 call 18 */
        switch (itemIdx) {
        case 0: /* democracy_reap_preimage_V6 - proposal_hash */;
            return _toStringHash(
                &m->basic.democracy_reap_preimage_V6.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* democracy_reap_preimage_V6 - proposal_len_upper_bound */;
            return _toStringCompactu32(
                &m->basic.democracy_reap_preimage_V6.proposal_len_upper_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3603: /* module 14 call 19 */
        switch (itemIdx) {
        case 0: /* democracy_unlock_V6 - target */;
            return _toStringAccountId_V6(
                &m->basic.democracy_unlock_V6.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3604: /* module 14 call 20 */
        switch (itemIdx) {
        case 0: /* democracy_remove_vote_V6 - index */;
            return _toStringReferendumIndex_V6(
                &m->basic.democracy_remove_vote_V6.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3605: /* module 14 call 21 */
        switch (itemIdx) {
        case 0: /* democracy_remove_other_vote_V6 - target */;
            return _toStringAccountId_V6(
                &m->basic.democracy_remove_other_vote_V6.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* democracy_remove_other_vote_V6 - index */;
            return _toStringReferendumIndex_V6(
                &m->basic.democracy_remove_other_vote_V6.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3606: /* module 14 call 22 */
        switch (itemIdx) {
        case 0: /* democracy_enact_proposal_V6 - proposal_hash */;
            return _toStringHash(
                &m->basic.democracy_enact_proposal_V6.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* democracy_enact_proposal_V6 - index */;
            return _toStringReferendumIndex_V6(
                &m->basic.democracy_enact_proposal_V6.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3607: /* module 14 call 23 */
        switch (itemIdx) {
        case 0: /* democracy_blacklist_V6 - proposal_hash */;
            return _toStringHash(
                &m->basic.democracy_blacklist_V6.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* democracy_blacklist_V6 - maybe_ref_index */;
            return _toStringOptionReferendumIndex_V6(
                &m->basic.democracy_blacklist_V6.maybe_ref_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3608: /* module 14 call 24 */
        switch (itemIdx) {
        case 0: /* democracy_cancel_proposal_V6 - prop_index */;
            return _toStringCompactPropIndex_V6(
                &m->basic.democracy_cancel_proposal_V6.prop_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3840: /* module 15 call 0 */
        switch (itemIdx) {
        case 0: /* council_set_members_V6 - new_members */;
            return _toStringVecAccountId_V6(
                &m->basic.council_set_members_V6.new_members,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* council_set_members_V6 - prime */;
            return _toStringOptionAccountId_V6(
                &m->basic.council_set_members_V6.prime,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* council_set_members_V6 - old_count */;
            return _toStringMemberCount_V6(
                &m->basic.council_set_members_V6.old_count,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3841: /* module 15 call 1 */
        switch (itemIdx) {
        case 0: /* council_execute_V6 - proposal */;
            return _toStringProposal(
                &m->basic.council_execute_V6.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* council_execute_V6 - length_bound */;
            return _toStringCompactu32(
                &m->basic.council_execute_V6.length_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3842: /* module 15 call 2 */
        switch (itemIdx) {
        case 0: /* council_propose_V6 - threshold */;
            return _toStringCompactMemberCount_V6(
                &m->basic.council_propose_V6.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* council_propose_V6 - proposal */;
            return _toStringProposal(
                &m->basic.council_propose_V6.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* council_propose_V6 - length_bound */;
            return _toStringCompactu32(
                &m->basic.council_propose_V6.length_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3843: /* module 15 call 3 */
        switch (itemIdx) {
        case 0: /* council_vote_V6 - proposal */;
            return _toStringHash(
                &m->basic.council_vote_V6.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* council_vote_V6 - index */;
            return _toStringCompactProposalIndex_V6(
                &m->basic.council_vote_V6.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* council_vote_V6 - approve */;
            return _toStringbool(
                &m->basic.council_vote_V6.approve,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3844: /* module 15 call 4 */
        switch (itemIdx) {
        case 0: /* council_close_V6 - proposal_hash */;
            return _toStringHash(
                &m->basic.council_close_V6.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* council_close_V6 - index */;
            return _toStringCompactProposalIndex_V6(
                &m->basic.council_close_V6.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* council_close_V6 - proposal_weight_bound */;
            return _toStringCompactWeight_V6(
                &m->basic.council_close_V6.proposal_weight_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* council_close_V6 - length_bound */;
            return _toStringCompactu32(
                &m->basic.council_close_V6.length_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3845: /* module 15 call 5 */
        switch (itemIdx) {
        case 0: /* council_disapprove_proposal_V6 - proposal_hash */;
            return _toStringHash(
                &m->basic.council_disapprove_proposal_V6.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4096: /* module 16 call 0 */
        switch (itemIdx) {
        case 0: /* technicalcommittee_set_members_V6 - new_members */;
            return _toStringVecAccountId_V6(
                &m->basic.technicalcommittee_set_members_V6.new_members,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* technicalcommittee_set_members_V6 - prime */;
            return _toStringOptionAccountId_V6(
                &m->basic.technicalcommittee_set_members_V6.prime,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* technicalcommittee_set_members_V6 - old_count */;
            return _toStringMemberCount_V6(
                &m->basic.technicalcommittee_set_members_V6.old_count,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4097: /* module 16 call 1 */
        switch (itemIdx) {
        case 0: /* technicalcommittee_execute_V6 - proposal */;
            return _toStringProposal(
                &m->basic.technicalcommittee_execute_V6.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* technicalcommittee_execute_V6 - length_bound */;
            return _toStringCompactu32(
                &m->basic.technicalcommittee_execute_V6.length_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4098: /* module 16 call 2 */
        switch (itemIdx) {
        case 0: /* technicalcommittee_propose_V6 - threshold */;
            return _toStringCompactMemberCount_V6(
                &m->basic.technicalcommittee_propose_V6.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* technicalcommittee_propose_V6 - proposal */;
            return _toStringProposal(
                &m->basic.technicalcommittee_propose_V6.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* technicalcommittee_propose_V6 - length_bound */;
            return _toStringCompactu32(
                &m->basic.technicalcommittee_propose_V6.length_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4099: /* module 16 call 3 */
        switch (itemIdx) {
        case 0: /* technicalcommittee_vote_V6 - proposal */;
            return _toStringHash(
                &m->basic.technicalcommittee_vote_V6.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* technicalcommittee_vote_V6 - index */;
            return _toStringCompactProposalIndex_V6(
                &m->basic.technicalcommittee_vote_V6.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* technicalcommittee_vote_V6 - approve */;
            return _toStringbool(
                &m->basic.technicalcommittee_vote_V6.approve,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4100: /* module 16 call 4 */
        switch (itemIdx) {
        case 0: /* technicalcommittee_close_V6 - proposal_hash */;
            return _toStringHash(
                &m->basic.technicalcommittee_close_V6.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* technicalcommittee_close_V6 - index */;
            return _toStringCompactProposalIndex_V6(
                &m->basic.technicalcommittee_close_V6.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* technicalcommittee_close_V6 - proposal_weight_bound */;
            return _toStringCompactWeight_V6(
                &m->basic.technicalcommittee_close_V6.proposal_weight_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* technicalcommittee_close_V6 - length_bound */;
            return _toStringCompactu32(
                &m->basic.technicalcommittee_close_V6.length_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4101: /* module 16 call 5 */
        switch (itemIdx) {
        case 0: /* technicalcommittee_disapprove_proposal_V6 - proposal_hash */;
            return _toStringHash(
                &m->basic.technicalcommittee_disapprove_proposal_V6.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4352: /* module 17 call 0 */
        switch (itemIdx) {
        case 0: /* electionsphragmen_vote_V6 - votes */;
            return _toStringVecAccountId_V6(
                &m->basic.electionsphragmen_vote_V6.votes,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* electionsphragmen_vote_V6 - value */;
            return _toStringCompactBalanceOf(
                &m->basic.electionsphragmen_vote_V6.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4353: /* module 17 call 1 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 4354: /* module 17 call 2 */
        switch (itemIdx) {
        case 0: /* electionsphragmen_submit_candidacy_V6 - candidate_count */;
            return _toStringCompactu32(
                &m->basic.electionsphragmen_submit_candidacy_V6.candidate_count,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4355: /* module 17 call 3 */
        switch (itemIdx) {
        case 0: /* electionsphragmen_renounce_candidacy_V6 - renouncing */;
            return _toStringRenouncing_V6(
                &m->basic.electionsphragmen_renounce_candidacy_V6.renouncing,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4356: /* module 17 call 4 */
        switch (itemIdx) {
        case 0: /* electionsphragmen_remove_member_V6 - who */;
            return _toStringLookupSource_V6(
                &m->basic.electionsphragmen_remove_member_V6.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* electionsphragmen_remove_member_V6 - has_replacement */;
            return _toStringbool(
                &m->basic.electionsphragmen_remove_member_V6.has_replacement,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4357: /* module 17 call 5 */
        switch (itemIdx) {
        case 0: /* electionsphragmen_clean_defunct_voters_V6 - _num_voters */;
            return _toStringu32(
                &m->basic.electionsphragmen_clean_defunct_voters_V6._num_voters,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* electionsphragmen_clean_defunct_voters_V6 - _num_defunct */;
            return _toStringu32(
                &m->basic.electionsphragmen_clean_defunct_voters_V6._num_defunct,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4608: /* module 18 call 0 */
        switch (itemIdx) {
        case 0: /* technicalmembership_add_member_V6 - who */;
            return _toStringAccountId_V6(
                &m->basic.technicalmembership_add_member_V6.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4609: /* module 18 call 1 */
        switch (itemIdx) {
        case 0: /* technicalmembership_remove_member_V6 - who */;
            return _toStringAccountId_V6(
                &m->basic.technicalmembership_remove_member_V6.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4610: /* module 18 call 2 */
        switch (itemIdx) {
        case 0: /* technicalmembership_swap_member_V6 - remove */;
            return _toStringAccountId_V6(
                &m->basic.technicalmembership_swap_member_V6.remove,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* technicalmembership_swap_member_V6 - add */;
            return _toStringAccountId_V6(
                &m->basic.technicalmembership_swap_member_V6.add,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4611: /* module 18 call 3 */
        switch (itemIdx) {
        case 0: /* technicalmembership_reset_members_V6 - members */;
            return _toStringVecAccountId_V6(
                &m->basic.technicalmembership_reset_members_V6.members,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4612: /* module 18 call 4 */
        switch (itemIdx) {
        case 0: /* technicalmembership_change_key_V6 - new_ */;
            return _toStringAccountId_V6(
                &m->basic.technicalmembership_change_key_V6.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4613: /* module 18 call 5 */
        switch (itemIdx) {
        case 0: /* technicalmembership_set_prime_V6 - who */;
            return _toStringAccountId_V6(
                &m->basic.technicalmembership_set_prime_V6.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4614: /* module 18 call 6 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 4864: /* module 19 call 0 */
        switch (itemIdx) {
        case 0: /* treasury_propose_spend_V6 - value */;
            return _toStringCompactBalanceOf(
                &m->basic.treasury_propose_spend_V6.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* treasury_propose_spend_V6 - beneficiary */;
            return _toStringLookupSource_V6(
                &m->basic.treasury_propose_spend_V6.beneficiary,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4865: /* module 19 call 1 */
        switch (itemIdx) {
        case 0: /* treasury_reject_proposal_V6 - proposal_id */;
            return _toStringCompactProposalIndex_V6(
                &m->basic.treasury_reject_proposal_V6.proposal_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4866: /* module 19 call 2 */
        switch (itemIdx) {
        case 0: /* treasury_approve_proposal_V6 - proposal_id */;
            return _toStringCompactProposalIndex_V6(
                &m->basic.treasury_approve_proposal_V6.proposal_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6144: /* module 24 call 0 */
        switch (itemIdx) {
        case 0: /* claims_claim_V6 - dest */;
            return _toStringAccountId_V6(
                &m->basic.claims_claim_V6.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* claims_claim_V6 - ethereum_signature */;
            return _toStringEcdsaSignature_V6(
                &m->basic.claims_claim_V6.ethereum_signature,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6145: /* module 24 call 1 */
        switch (itemIdx) {
        case 0: /* claims_mint_claim_V6 - who */;
            return _toStringEthereumAddress_V6(
                &m->basic.claims_mint_claim_V6.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* claims_mint_claim_V6 - value */;
            return _toStringBalanceOf(
                &m->basic.claims_mint_claim_V6.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* claims_mint_claim_V6 - vesting_schedule */;
            return _toStringOptionTupleBalanceOfBalanceOfBlockNumber_V6(
                &m->basic.claims_mint_claim_V6.vesting_schedule,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* claims_mint_claim_V6 - statement */;
            return _toStringOptionStatementKind_V6(
                &m->basic.claims_mint_claim_V6.statement,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6146: /* module 24 call 2 */
        switch (itemIdx) {
        case 0: /* claims_claim_attest_V6 - dest */;
            return _toStringAccountId_V6(
                &m->basic.claims_claim_attest_V6.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* claims_claim_attest_V6 - ethereum_signature */;
            return _toStringEcdsaSignature_V6(
                &m->basic.claims_claim_attest_V6.ethereum_signature,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* claims_claim_attest_V6 - statement */;
            return _toStringBytes(
                &m->basic.claims_claim_attest_V6.statement,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6147: /* module 24 call 3 */
        switch (itemIdx) {
        case 0: /* claims_attest_V6 - statement */;
            return _toStringBytes(
                &m->basic.claims_attest_V6.statement,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6148: /* module 24 call 4 */
        switch (itemIdx) {
        case 0: /* claims_move_claim_V6 - old */;
            return _toStringEthereumAddress_V6(
                &m->basic.claims_move_claim_V6.old,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* claims_move_claim_V6 - new_ */;
            return _toStringEthereumAddress_V6(
                &m->basic.claims_move_claim_V6.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* claims_move_claim_V6 - maybe_preclaim */;
            return _toStringOptionAccountId_V6(
                &m->basic.claims_move_claim_V6.maybe_preclaim,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6400: /* module 25 call 0 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 6401: /* module 25 call 1 */
        switch (itemIdx) {
        case 0: /* vesting_vest_other_V6 - target */;
            return _toStringLookupSource_V6(
                &m->basic.vesting_vest_other_V6.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6402: /* module 25 call 2 */
        switch (itemIdx) {
        case 0: /* vesting_vested_transfer_V6 - target */;
            return _toStringLookupSource_V6(
                &m->basic.vesting_vested_transfer_V6.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* vesting_vested_transfer_V6 - schedule */;
            return _toStringVestingInfo_V6(
                &m->basic.vesting_vested_transfer_V6.schedule,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6403: /* module 25 call 3 */
        switch (itemIdx) {
        case 0: /* vesting_force_vested_transfer_V6 - source */;
            return _toStringLookupSource_V6(
                &m->basic.vesting_force_vested_transfer_V6.source,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* vesting_force_vested_transfer_V6 - target */;
            return _toStringLookupSource_V6(
                &m->basic.vesting_force_vested_transfer_V6.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* vesting_force_vested_transfer_V6 - schedule */;
            return _toStringVestingInfo_V6(
                &m->basic.vesting_force_vested_transfer_V6.schedule,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6657: /* module 26 call 1 */
        switch (itemIdx) {
        case 0: /* utility_as_derivative_V6 - index */;
            return _toStringu16(
                &m->basic.utility_as_derivative_V6.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* utility_as_derivative_V6 - call */;
            return _toStringCall(
                &m->basic.utility_as_derivative_V6.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7168: /* module 28 call 0 */
        switch (itemIdx) {
        case 0: /* identity_add_registrar_V6 - account */;
            return _toStringAccountId_V6(
                &m->basic.identity_add_registrar_V6.account,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7169: /* module 28 call 1 */
        switch (itemIdx) {
        case 0: /* identity_set_identity_V6 - info */;
            return _toStringIdentityInfo_V6(
                &m->basic.identity_set_identity_V6.info,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7170: /* module 28 call 2 */
        switch (itemIdx) {
        case 0: /* identity_set_subs_V6 - subs */;
            return _toStringVecTupleAccountIdData_V6(
                &m->basic.identity_set_subs_V6.subs,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7171: /* module 28 call 3 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 7172: /* module 28 call 4 */
        switch (itemIdx) {
        case 0: /* identity_request_judgement_V6 - reg_index */;
            return _toStringCompactRegistrarIndex_V6(
                &m->basic.identity_request_judgement_V6.reg_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_request_judgement_V6 - max_fee */;
            return _toStringCompactBalanceOf(
                &m->basic.identity_request_judgement_V6.max_fee,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7173: /* module 28 call 5 */
        switch (itemIdx) {
        case 0: /* identity_cancel_request_V6 - reg_index */;
            return _toStringRegistrarIndex_V6(
                &m->basic.identity_cancel_request_V6.reg_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7174: /* module 28 call 6 */
        switch (itemIdx) {
        case 0: /* identity_set_fee_V6 - index */;
            return _toStringCompactRegistrarIndex_V6(
                &m->basic.identity_set_fee_V6.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_set_fee_V6 - fee */;
            return _toStringCompactBalanceOf(
                &m->basic.identity_set_fee_V6.fee,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7175: /* module 28 call 7 */
        switch (itemIdx) {
        case 0: /* identity_set_account_id_V6 - index */;
            return _toStringCompactRegistrarIndex_V6(
                &m->basic.identity_set_account_id_V6.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_set_account_id_V6 - new_ */;
            return _toStringAccountId_V6(
                &m->basic.identity_set_account_id_V6.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7176: /* module 28 call 8 */
        switch (itemIdx) {
        case 0: /* identity_set_fields_V6 - index */;
            return _toStringCompactRegistrarIndex_V6(
                &m->basic.identity_set_fields_V6.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_set_fields_V6 - fields */;
            return _toStringIdentityFields_V6(
                &m->basic.identity_set_fields_V6.fields,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7177: /* module 28 call 9 */
        switch (itemIdx) {
        case 0: /* identity_provide_judgement_V6 - reg_index */;
            return _toStringCompactRegistrarIndex_V6(
                &m->basic.identity_provide_judgement_V6.reg_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_provide_judgement_V6 - target */;
            return _toStringLookupSource_V6(
                &m->basic.identity_provide_judgement_V6.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* identity_provide_judgement_V6 - judgement */;
            return _toStringIdentityJudgement_V6(
                &m->basic.identity_provide_judgement_V6.judgement,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7178: /* module 28 call 10 */
        switch (itemIdx) {
        case 0: /* identity_kill_identity_V6 - target */;
            return _toStringLookupSource_V6(
                &m->basic.identity_kill_identity_V6.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7179: /* module 28 call 11 */
        switch (itemIdx) {
        case 0: /* identity_add_sub_V6 - sub */;
            return _toStringLookupSource_V6(
                &m->basic.identity_add_sub_V6.sub,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_add_sub_V6 - data */;
            return _toStringData(
                &m->basic.identity_add_sub_V6.data,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7180: /* module 28 call 12 */
        switch (itemIdx) {
        case 0: /* identity_rename_sub_V6 - sub */;
            return _toStringLookupSource_V6(
                &m->basic.identity_rename_sub_V6.sub,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_rename_sub_V6 - data */;
            return _toStringData(
                &m->basic.identity_rename_sub_V6.data,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7181: /* module 28 call 13 */
        switch (itemIdx) {
        case 0: /* identity_remove_sub_V6 - sub */;
            return _toStringLookupSource_V6(
                &m->basic.identity_remove_sub_V6.sub,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7182: /* module 28 call 14 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 7424: /* module 29 call 0 */
        switch (itemIdx) {
        case 0: /* proxy_proxy_V6 - real */;
            return _toStringAccountId_V6(
                &m->basic.proxy_proxy_V6.real,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_proxy_V6 - force_proxy_type */;
            return _toStringOptionProxyType_V6(
                &m->basic.proxy_proxy_V6.force_proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* proxy_proxy_V6 - call */;
            return _toStringCall(
                &m->basic.proxy_proxy_V6.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7425: /* module 29 call 1 */
        switch (itemIdx) {
        case 0: /* proxy_add_proxy_V6 - delegate */;
            return _toStringAccountId_V6(
                &m->basic.proxy_add_proxy_V6.delegate,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_add_proxy_V6 - proxy_type */;
            return _toStringProxyType_V6(
                &m->basic.proxy_add_proxy_V6.proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* proxy_add_proxy_V6 - delay */;
            return _toStringBlockNumber(
                &m->basic.proxy_add_proxy_V6.delay,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7426: /* module 29 call 2 */
        switch (itemIdx) {
        case 0: /* proxy_remove_proxy_V6 - delegate */;
            return _toStringAccountId_V6(
                &m->basic.proxy_remove_proxy_V6.delegate,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_remove_proxy_V6 - proxy_type */;
            return _toStringProxyType_V6(
                &m->basic.proxy_remove_proxy_V6.proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* proxy_remove_proxy_V6 - delay */;
            return _toStringBlockNumber(
                &m->basic.proxy_remove_proxy_V6.delay,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7427: /* module 29 call 3 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 7428: /* module 29 call 4 */
        switch (itemIdx) {
        case 0: /* proxy_anonymous_V6 - proxy_type */;
            return _toStringProxyType_V6(
                &m->basic.proxy_anonymous_V6.proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_anonymous_V6 - delay */;
            return _toStringBlockNumber(
                &m->basic.proxy_anonymous_V6.delay,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* proxy_anonymous_V6 - index */;
            return _toStringu16(
                &m->basic.proxy_anonymous_V6.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7429: /* module 29 call 5 */
        switch (itemIdx) {
        case 0: /* proxy_kill_anonymous_V6 - spawner */;
            return _toStringAccountId_V6(
                &m->basic.proxy_kill_anonymous_V6.spawner,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_kill_anonymous_V6 - proxy_type */;
            return _toStringProxyType_V6(
                &m->basic.proxy_kill_anonymous_V6.proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* proxy_kill_anonymous_V6 - index */;
            return _toStringu16(
                &m->basic.proxy_kill_anonymous_V6.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* proxy_kill_anonymous_V6 - height */;
            return _toStringCompactBlockNumber(
                &m->basic.proxy_kill_anonymous_V6.height,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* proxy_kill_anonymous_V6 - ext_index */;
            return _toStringCompactu32(
                &m->basic.proxy_kill_anonymous_V6.ext_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7430: /* module 29 call 6 */
        switch (itemIdx) {
        case 0: /* proxy_announce_V6 - real */;
            return _toStringAccountId_V6(
                &m->basic.proxy_announce_V6.real,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_announce_V6 - call_hash */;
            return _toStringCallHashOf_V6(
                &m->basic.proxy_announce_V6.call_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7431: /* module 29 call 7 */
        switch (itemIdx) {
        case 0: /* proxy_remove_announcement_V6 - real */;
            return _toStringAccountId_V6(
                &m->basic.proxy_remove_announcement_V6.real,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_remove_announcement_V6 - call_hash */;
            return _toStringCallHashOf_V6(
                &m->basic.proxy_remove_announcement_V6.call_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7432: /* module 29 call 8 */
        switch (itemIdx) {
        case 0: /* proxy_reject_announcement_V6 - delegate */;
            return _toStringAccountId_V6(
                &m->basic.proxy_reject_announcement_V6.delegate,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_reject_announcement_V6 - call_hash */;
            return _toStringCallHashOf_V6(
                &m->basic.proxy_reject_announcement_V6.call_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7433: /* module 29 call 9 */
        switch (itemIdx) {
        case 0: /* proxy_proxy_announced_V6 - delegate */;
            return _toStringAccountId_V6(
                &m->basic.proxy_proxy_announced_V6.delegate,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_proxy_announced_V6 - real */;
            return _toStringAccountId_V6(
                &m->basic.proxy_proxy_announced_V6.real,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* proxy_proxy_announced_V6 - force_proxy_type */;
            return _toStringOptionProxyType_V6(
                &m->basic.proxy_proxy_announced_V6.force_proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* proxy_proxy_announced_V6 - call */;
            return _toStringCall(
                &m->basic.proxy_proxy_announced_V6.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7680: /* module 30 call 0 */
        switch (itemIdx) {
        case 0: /* multisig_as_multi_threshold_1_V6 - other_signatories */;
            return _toStringVecAccountId_V6(
                &m->basic.multisig_as_multi_threshold_1_V6.other_signatories,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_as_multi_threshold_1_V6 - call */;
            return _toStringCall(
                &m->basic.multisig_as_multi_threshold_1_V6.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7681: /* module 30 call 1 */
        switch (itemIdx) {
        case 0: /* multisig_as_multi_V6 - threshold */;
            return _toStringu16(
                &m->basic.multisig_as_multi_V6.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_as_multi_V6 - other_signatories */;
            return _toStringVecAccountId_V6(
                &m->basic.multisig_as_multi_V6.other_signatories,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* multisig_as_multi_V6 - maybe_timepoint */;
            return _toStringOptionTimepoint_V6(
                &m->basic.multisig_as_multi_V6.maybe_timepoint,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* multisig_as_multi_V6 - call */;
            return _toStringOpaqueCall_V6(
                &m->basic.multisig_as_multi_V6.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* multisig_as_multi_V6 - store_call */;
            return _toStringbool(
                &m->basic.multisig_as_multi_V6.store_call,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* multisig_as_multi_V6 - max_weight */;
            return _toStringWeight_V6(
                &m->basic.multisig_as_multi_V6.max_weight,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7682: /* module 30 call 2 */
        switch (itemIdx) {
        case 0: /* multisig_approve_as_multi_V6 - threshold */;
            return _toStringu16(
                &m->basic.multisig_approve_as_multi_V6.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_approve_as_multi_V6 - other_signatories */;
            return _toStringVecAccountId_V6(
                &m->basic.multisig_approve_as_multi_V6.other_signatories,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* multisig_approve_as_multi_V6 - maybe_timepoint */;
            return _toStringOptionTimepoint_V6(
                &m->basic.multisig_approve_as_multi_V6.maybe_timepoint,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* multisig_approve_as_multi_V6 - call_hash */;
            return _toStringu8_array_32_V6(
                &m->basic.multisig_approve_as_multi_V6.call_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* multisig_approve_as_multi_V6 - max_weight */;
            return _toStringWeight_V6(
                &m->basic.multisig_approve_as_multi_V6.max_weight,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7683: /* module 30 call 3 */
        switch (itemIdx) {
        case 0: /* multisig_cancel_as_multi_V6 - threshold */;
            return _toStringu16(
                &m->basic.multisig_cancel_as_multi_V6.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_cancel_as_multi_V6 - other_signatories */;
            return _toStringVecAccountId_V6(
                &m->basic.multisig_cancel_as_multi_V6.other_signatories,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* multisig_cancel_as_multi_V6 - timepoint */;
            return _toStringTimepoint_V6(
                &m->basic.multisig_cancel_as_multi_V6.timepoint,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* multisig_cancel_as_multi_V6 - call_hash */;
            return _toStringu8_array_32_V6(
                &m->basic.multisig_cancel_as_multi_V6.call_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8704: /* module 34 call 0 */
        switch (itemIdx) {
        case 0: /* bounties_propose_bounty_V6 - value */;
            return _toStringCompactBalanceOf(
                &m->basic.bounties_propose_bounty_V6.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* bounties_propose_bounty_V6 - description */;
            return _toStringBytes(
                &m->basic.bounties_propose_bounty_V6.description,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8705: /* module 34 call 1 */
        switch (itemIdx) {
        case 0: /* bounties_approve_bounty_V6 - bounty_id */;
            return _toStringCompactBountyIndex_V6(
                &m->basic.bounties_approve_bounty_V6.bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8706: /* module 34 call 2 */
        switch (itemIdx) {
        case 0: /* bounties_propose_curator_V6 - bounty_id */;
            return _toStringCompactBountyIndex_V6(
                &m->basic.bounties_propose_curator_V6.bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* bounties_propose_curator_V6 - curator */;
            return _toStringLookupSource_V6(
                &m->basic.bounties_propose_curator_V6.curator,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* bounties_propose_curator_V6 - fee */;
            return _toStringCompactBalanceOf(
                &m->basic.bounties_propose_curator_V6.fee,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8707: /* module 34 call 3 */
        switch (itemIdx) {
        case 0: /* bounties_unassign_curator_V6 - bounty_id */;
            return _toStringCompactBountyIndex_V6(
                &m->basic.bounties_unassign_curator_V6.bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8708: /* module 34 call 4 */
        switch (itemIdx) {
        case 0: /* bounties_accept_curator_V6 - bounty_id */;
            return _toStringCompactBountyIndex_V6(
                &m->basic.bounties_accept_curator_V6.bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8709: /* module 34 call 5 */
        switch (itemIdx) {
        case 0: /* bounties_award_bounty_V6 - bounty_id */;
            return _toStringCompactBountyIndex_V6(
                &m->basic.bounties_award_bounty_V6.bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* bounties_award_bounty_V6 - beneficiary */;
            return _toStringLookupSource_V6(
                &m->basic.bounties_award_bounty_V6.beneficiary,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8710: /* module 34 call 6 */
        switch (itemIdx) {
        case 0: /* bounties_claim_bounty_V6 - bounty_id */;
            return _toStringCompactBountyIndex_V6(
                &m->basic.bounties_claim_bounty_V6.bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8711: /* module 34 call 7 */
        switch (itemIdx) {
        case 0: /* bounties_close_bounty_V6 - bounty_id */;
            return _toStringCompactBountyIndex_V6(
                &m->basic.bounties_close_bounty_V6.bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8712: /* module 34 call 8 */
        switch (itemIdx) {
        case 0: /* bounties_extend_bounty_expiry_V6 - bounty_id */;
            return _toStringCompactBountyIndex_V6(
                &m->basic.bounties_extend_bounty_expiry_V6.bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* bounties_extend_bounty_expiry_V6 - _remark */;
            return _toStringBytes(
                &m->basic.bounties_extend_bounty_expiry_V6._remark,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8960: /* module 35 call 0 */
        switch (itemIdx) {
        case 0: /* tips_report_awesome_V6 - reason */;
            return _toStringBytes(
                &m->basic.tips_report_awesome_V6.reason,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* tips_report_awesome_V6 - who */;
            return _toStringAccountId_V6(
                &m->basic.tips_report_awesome_V6.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8961: /* module 35 call 1 */
        switch (itemIdx) {
        case 0: /* tips_retract_tip_V6 - hash */;
            return _toStringHash(
                &m->basic.tips_retract_tip_V6.hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8962: /* module 35 call 2 */
        switch (itemIdx) {
        case 0: /* tips_tip_new_V6 - reason */;
            return _toStringBytes(
                &m->basic.tips_tip_new_V6.reason,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* tips_tip_new_V6 - who */;
            return _toStringAccountId_V6(
                &m->basic.tips_tip_new_V6.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* tips_tip_new_V6 - tip_value */;
            return _toStringCompactBalanceOf(
                &m->basic.tips_tip_new_V6.tip_value,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8963: /* module 35 call 3 */
        switch (itemIdx) {
        case 0: /* tips_tip_V6 - hash */;
            return _toStringHash(
                &m->basic.tips_tip_V6.hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* tips_tip_V6 - tip_value */;
            return _toStringCompactBalanceOf(
                &m->basic.tips_tip_V6.tip_value,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8964: /* module 35 call 4 */
        switch (itemIdx) {
        case 0: /* tips_close_tip_V6 - hash */;
            return _toStringHash(
                &m->basic.tips_close_tip_V6.hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8965: /* module 35 call 5 */
        switch (itemIdx) {
        case 0: /* tips_slash_tip_V6 - hash */;
            return _toStringHash(
                &m->basic.tips_slash_tip_V6.hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9216: /* module 36 call 0 */
        switch (itemIdx) {
        case 0: /* electionprovidermultiphase_submit_unsigned_V6 - solution */;
            return _toStringRawSolution_V6(
                &m->basic.electionprovidermultiphase_submit_unsigned_V6.solution,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* electionprovidermultiphase_submit_unsigned_V6 - witness */;
            return _toStringSolutionOrSnapshotSize_V6(
                &m->basic.electionprovidermultiphase_submit_unsigned_V6.witness,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
#endif
    default:
        return parser_ok;
    }

    return parser_ok;
}

bool _getMethod_ItemIsExpert_V6(uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 1795: // Staking:Withdraw Unbonded
        switch (itemIdx) {
        case 0: // Num slashing spans
            return true;
        default:
            return false;
        }
    case 1807: // Staking:Force unstake
        switch (itemIdx) {
        case 1: // Num slashing spans
            return true;
        default:
            return false;
        }
    case 1813: // Staking:Reap stash
        switch (itemIdx) {
        case 1: // Num slashing spans
            return true;
        default:
            return false;
        }

    default:
        return false;
    }
}

bool _getMethod_IsNestingSupported_V6(uint8_t moduleIdx, uint8_t callIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 0: // System:Fill block
    case 1: // System:Remark
    case 2: // System:Set heap pages
    case 3: // System:Set code
    case 4: // System:Set code without checks
    case 5: // System:Set changes trie config
    case 6: // System:Set storage
    case 7: // System:Kill storage
    case 8: // System:Kill prefix
    case 256: // Scheduler:Schedule
    case 257: // Scheduler:Cancel
    case 258: // Scheduler:Schedule named
    case 259: // Scheduler:Cancel named
    case 260: // Scheduler:Schedule after
    case 261: // Scheduler:Schedule named after
    case 512: // Babe:Report equivocation
    case 513: // Babe:Report equivocation unsigned
    case 768: // Timestamp:Set
    case 1024: // Indices:Claim
    case 1025: // Indices:Transfer
    case 1026: // Indices:Free
    case 1027: // Indices:Force transfer
    case 1028: // Indices:Freeze
    case 1280: // Balances:Transfer
    case 1281: // Balances:Set balance
    case 1282: // Balances:Force transfer
    case 1283: // Balances:Transfer keep alive
    case 1536: // Authorship:Set uncles
    case 1792: // Staking:Bond
    case 1793: // Staking:Bond extra
    case 1794: // Staking:Unbond
    case 1795: // Staking:Withdraw Unbonded
    case 1796: // Staking:Validate
    case 1797: // Staking:Nominate
    case 1798: // Staking:Chill
    case 1799: // Staking:Set payee
    case 1800: // Staking:Set controller
    case 1801: // Staking:Set validator count
    case 1802: // Staking:Increase validator count
    case 1803: // Staking:Scale validator count
    case 1804: // Staking:Force no eras
    case 1805: // Staking:Force new era
    case 1806: // Staking:Set invulnerables
    case 1807: // Staking:Force unstake
    case 1808: // Staking:Force new era always
    case 1809: // Staking:Cancel deferred slash
    case 1810: // Staking:Payout stakers
    case 1811: // Staking:Rebond
    case 1812: // Staking:Set history depth
    case 1813: // Staking:Reap stash
    case 1814: // Staking:Submit election solution
    case 1815: // Staking:Submit election solution unsigned
    case 1816: // Staking:Kick
    case 2304: // Session:Set keys
    case 2305: // Session:Purge keys
    case 2816: // Grandpa:Report equivocation
    case 2817: // Grandpa:Report equivocation unsigned
    case 2818: // Grandpa:Note stalled
    case 3072: // ImOnline:Heartbeat
    case 3584: // Democracy:Propose
    case 3585: // Democracy:Second
    case 3586: // Democracy:Vote
    case 3587: // Democracy:Emergency cancel
    case 3588: // Democracy:External propose
    case 3589: // Democracy:External propose majority
    case 3590: // Democracy:External propose default
    case 3591: // Democracy:Fast track
    case 3592: // Democracy:Veto external
    case 3593: // Democracy:Cancel referendum
    case 3594: // Democracy:Cancel queued
    case 3595: // Democracy:Delegate
    case 3596: // Democracy:Undelegate
    case 3597: // Democracy:Clear public proposals
    case 3598: // Democracy:Note preimage
    case 3599: // Democracy:Note preimage operational
    case 3600: // Democracy:Note imminent preimage
    case 3601: // Democracy:Note imminent preimage operational
    case 3602: // Democracy:Reap preimage
    case 3603: // Democracy:Unlock
    case 3604: // Democracy:Remove vote
    case 3605: // Democracy:Remove other vote
    case 3606: // Democracy:Enact proposal
    case 3607: // Democracy:Blacklist
    case 3608: // Democracy:Cancel proposal
    case 3840: // Council:Set members
    case 3841: // Council:Execute
    case 3842: // Council:Propose
    case 3843: // Council:Vote
    case 3844: // Council:Close
    case 3845: // Council:Disapprove proposal
    case 4096: // TechnicalCommittee:Set members
    case 4097: // TechnicalCommittee:Execute
    case 4098: // TechnicalCommittee:Propose
    case 4099: // TechnicalCommittee:Vote
    case 4100: // TechnicalCommittee:Close
    case 4101: // TechnicalCommittee:Disapprove proposal
    case 4352: // ElectionsPhragmen:Vote
    case 4353: // ElectionsPhragmen:Remove voter
    case 4354: // ElectionsPhragmen:Submit candidacy
    case 4355: // ElectionsPhragmen:Renounce candidacy
    case 4356: // ElectionsPhragmen:Remove member
    case 4357: // ElectionsPhragmen:Clean defunct voters
    case 4608: // TechnicalMembership:Add member
    case 4609: // TechnicalMembership:Remove member
    case 4610: // TechnicalMembership:Swap member
    case 4611: // TechnicalMembership:Reset members
    case 4612: // TechnicalMembership:Change key
    case 4613: // TechnicalMembership:Set prime
    case 4614: // TechnicalMembership:Clear prime
    case 4864: // Treasury:Propose spend
    case 4865: // Treasury:Reject proposal
    case 4866: // Treasury:Approve proposal
    case 6144: // Claims:Claim
    case 6145: // Claims:Mint claim
    case 6146: // Claims:Claim attest
    case 6147: // Claims:Attest
    case 6148: // Claims:Move claim
    case 6400: // Vesting:Vest
    case 6401: // Vesting:Vest other
    case 6402: // Vesting:Vested transfer
    case 6403: // Vesting:Force vested transfer
    case 6656: // Utility:Batch
    case 6657: // Utility:As derivative
    case 6658: // Utility:Batch all
    case 7168: // Identity:Add registrar
    case 7169: // Identity:Set identity
    case 7170: // Identity:Set subs
    case 7171: // Identity:Clear identity
    case 7172: // Identity:Request judgement
    case 7173: // Identity:Cancel request
    case 7174: // Identity:Set fee
    case 7175: // Identity:Set account id
    case 7176: // Identity:Set fields
    case 7177: // Identity:Provide judgement
    case 7178: // Identity:Kill identity
    case 7179: // Identity:Add sub
    case 7180: // Identity:Rename sub
    case 7181: // Identity:Remove sub
    case 7182: // Identity:Quit sub
    case 7424: // Proxy:Proxy
    case 7425: // Proxy:Add proxy
    case 7426: // Proxy:Remove proxy
    case 7427: // Proxy:Remove proxies
    case 7428: // Proxy:Anonymous
    case 7429: // Proxy:Kill anonymous
    case 7430: // Proxy:Announce
    case 7431: // Proxy:Remove announcement
    case 7432: // Proxy:Reject announcement
    case 7433: // Proxy:Proxy announced
    case 7680: // Multisig:As multi threshold 1
    case 7681: // Multisig:As multi
    case 7682: // Multisig:Approve as multi
    case 7683: // Multisig:Cancel as multi
    case 8704: // Bounties:Propose bounty
    case 8705: // Bounties:Approve bounty
    case 8706: // Bounties:Propose curator
    case 8707: // Bounties:Unassign curator
    case 8708: // Bounties:Accept curator
    case 8709: // Bounties:Award bounty
    case 8710: // Bounties:Claim bounty
    case 8711: // Bounties:Close bounty
    case 8712: // Bounties:Extend bounty expiry
    case 8960: // Tips:Report awesome
    case 8961: // Tips:Retract tip
    case 8962: // Tips:Tip new
    case 8963: // Tips:Tip
    case 8964: // Tips:Close tip
    case 8965: // Tips:Slash tip
    case 9216: // ElectionProviderMultiPhase:Submit unsigned
        return false;
    default:
        return true;
    }
}
