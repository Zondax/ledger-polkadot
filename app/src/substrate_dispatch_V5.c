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
#include "substrate_dispatch_V5.h"

#include "zxmacros.h"
#include <stdint.h>

__Z_INLINE parser_error_t _readMethod_system_fill_block_V5(
    parser_context_t* c, pd_system_fill_block_V5_t* m)
{
    CHECK_ERROR(_readPerbill_V5(c, &m->_ratio))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_remark_V5(
    parser_context_t* c, pd_system_remark_V5_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->_remark))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_heap_pages_V5(
    parser_context_t* c, pd_system_set_heap_pages_V5_t* m)
{
    CHECK_ERROR(_readu64(c, &m->pages))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_code_V5(
    parser_context_t* c, pd_system_set_code_V5_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->code))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_code_without_checks_V5(
    parser_context_t* c, pd_system_set_code_without_checks_V5_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->code))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_changes_trie_config_V5(
    parser_context_t* c, pd_system_set_changes_trie_config_V5_t* m)
{
    CHECK_ERROR(_readOptionChangesTrieConfiguration_V5(c, &m->changes_trie_config))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_storage_V5(
    parser_context_t* c, pd_system_set_storage_V5_t* m)
{
    CHECK_ERROR(_readVecKeyValue_V5(c, &m->items))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_kill_storage_V5(
    parser_context_t* c, pd_system_kill_storage_V5_t* m)
{
    CHECK_ERROR(_readVecKey_V5(c, &m->keys))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_kill_prefix_V5(
    parser_context_t* c, pd_system_kill_prefix_V5_t* m)
{
    CHECK_ERROR(_readKey_V5(c, &m->prefix))
    CHECK_ERROR(_readu32(c, &m->_subkeys))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_suicide_V5(
    parser_context_t* c, pd_system_suicide_V5_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_scheduler_schedule_V5(
    parser_context_t* c, pd_scheduler_schedule_V5_t* m)
{
    CHECK_ERROR(_readBlockNumber(c, &m->when))
    CHECK_ERROR(_readOptionPeriod_V5(c, &m->maybe_periodic))
    CHECK_ERROR(_readPriority_V5(c, &m->priority))
    CHECK_ERROR(_readCall_V5(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_scheduler_cancel_V5(
    parser_context_t* c, pd_scheduler_cancel_V5_t* m)
{
    CHECK_ERROR(_readBlockNumber(c, &m->when))
    CHECK_ERROR(_readu32(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_scheduler_schedule_named_V5(
    parser_context_t* c, pd_scheduler_schedule_named_V5_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->id))
    CHECK_ERROR(_readBlockNumber(c, &m->when))
    CHECK_ERROR(_readOptionPeriod_V5(c, &m->maybe_periodic))
    CHECK_ERROR(_readPriority_V5(c, &m->priority))
    CHECK_ERROR(_readCall_V5(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_scheduler_cancel_named_V5(
    parser_context_t* c, pd_scheduler_cancel_named_V5_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_scheduler_schedule_after_V5(
    parser_context_t* c, pd_scheduler_schedule_after_V5_t* m)
{
    CHECK_ERROR(_readBlockNumber(c, &m->after))
    CHECK_ERROR(_readOptionPeriod_V5(c, &m->maybe_periodic))
    CHECK_ERROR(_readPriority_V5(c, &m->priority))
    CHECK_ERROR(_readCall_V5(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_scheduler_schedule_named_after_V5(
    parser_context_t* c, pd_scheduler_schedule_named_after_V5_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->id))
    CHECK_ERROR(_readBlockNumber(c, &m->after))
    CHECK_ERROR(_readOptionPeriod_V5(c, &m->maybe_periodic))
    CHECK_ERROR(_readPriority_V5(c, &m->priority))
    CHECK_ERROR(_readCall_V5(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_babe_report_equivocation_V5(
    parser_context_t* c, pd_babe_report_equivocation_V5_t* m)
{
    CHECK_ERROR(_readEquivocationProof_V5(c, &m->equivocation_proof))
    CHECK_ERROR(_readKeyOwnerProof_V5(c, &m->key_owner_proof))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_babe_report_equivocation_unsigned_V5(
    parser_context_t* c, pd_babe_report_equivocation_unsigned_V5_t* m)
{
    CHECK_ERROR(_readEquivocationProof_V5(c, &m->equivocation_proof))
    CHECK_ERROR(_readKeyOwnerProof_V5(c, &m->key_owner_proof))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_timestamp_set_V5(
    parser_context_t* c, pd_timestamp_set_V5_t* m)
{
    CHECK_ERROR(_readCompactMoment_V5(c, &m->now))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_indices_claim_V5(
    parser_context_t* c, pd_indices_claim_V5_t* m)
{
    CHECK_ERROR(_readAccountIndex_V5(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_indices_transfer_V5(
    parser_context_t* c, pd_indices_transfer_V5_t* m)
{
    CHECK_ERROR(_readAccountId_V5(c, &m->new_))
    CHECK_ERROR(_readAccountIndex_V5(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_indices_free_V5(
    parser_context_t* c, pd_indices_free_V5_t* m)
{
    CHECK_ERROR(_readAccountIndex_V5(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_indices_force_transfer_V5(
    parser_context_t* c, pd_indices_force_transfer_V5_t* m)
{
    CHECK_ERROR(_readAccountId_V5(c, &m->new_))
    CHECK_ERROR(_readAccountIndex_V5(c, &m->index))
    CHECK_ERROR(_readbool(c, &m->freeze))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_indices_freeze_V5(
    parser_context_t* c, pd_indices_freeze_V5_t* m)
{
    CHECK_ERROR(_readAccountIndex_V5(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_transfer_V5(
    parser_context_t* c, pd_balances_transfer_V5_t* m)
{
    CHECK_ERROR(_readLookupSource(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_set_balance_V5(
    parser_context_t* c, pd_balances_set_balance_V5_t* m)
{
    CHECK_ERROR(_readLookupSource(c, &m->who))
    CHECK_ERROR(_readCompactBalance(c, &m->new_free))
    CHECK_ERROR(_readCompactBalance(c, &m->new_reserved))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_force_transfer_V5(
    parser_context_t* c, pd_balances_force_transfer_V5_t* m)
{
    CHECK_ERROR(_readLookupSource(c, &m->source))
    CHECK_ERROR(_readLookupSource(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_transfer_keep_alive_V5(
    parser_context_t* c, pd_balances_transfer_keep_alive_V5_t* m)
{
    CHECK_ERROR(_readLookupSource(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_authorship_set_uncles_V5(
    parser_context_t* c, pd_authorship_set_uncles_V5_t* m)
{
    CHECK_ERROR(_readVecHeader(c, &m->new_uncles))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_bond_V5(
    parser_context_t* c, pd_staking_bond_V5_t* m)
{
    CHECK_ERROR(_readLookupSource(c, &m->controller))
    CHECK_ERROR(_readCompactBalanceOf(c, &m->value))
    CHECK_ERROR(_readRewardDestination_V5(c, &m->payee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_bond_extra_V5(
    parser_context_t* c, pd_staking_bond_extra_V5_t* m)
{
    CHECK_ERROR(_readCompactBalanceOf(c, &m->max_additional))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_unbond_V5(
    parser_context_t* c, pd_staking_unbond_V5_t* m)
{
    CHECK_ERROR(_readCompactBalanceOf(c, &m->value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_withdraw_unbonded_V5(
    parser_context_t* c, pd_staking_withdraw_unbonded_V5_t* m)
{
    CHECK_ERROR(_readu32(c, &m->num_slashing_spans))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_validate_V5(
    parser_context_t* c, pd_staking_validate_V5_t* m)
{
    CHECK_ERROR(_readValidatorPrefs_V5(c, &m->prefs))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_nominate_V5(
    parser_context_t* c, pd_staking_nominate_V5_t* m)
{
    CHECK_ERROR(_readVecLookupSource(c, &m->targets))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_chill_V5(
    parser_context_t* c, pd_staking_chill_V5_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_payee_V5(
    parser_context_t* c, pd_staking_set_payee_V5_t* m)
{
    CHECK_ERROR(_readRewardDestination_V5(c, &m->payee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_controller_V5(
    parser_context_t* c, pd_staking_set_controller_V5_t* m)
{
    CHECK_ERROR(_readLookupSource(c, &m->controller))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_validator_count_V5(
    parser_context_t* c, pd_staking_set_validator_count_V5_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_increase_validator_count_V5(
    parser_context_t* c, pd_staking_increase_validator_count_V5_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->additional))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_scale_validator_count_V5(
    parser_context_t* c, pd_staking_scale_validator_count_V5_t* m)
{
    CHECK_ERROR(_readPercent_V5(c, &m->factor))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_no_eras_V5(
    parser_context_t* c, pd_staking_force_no_eras_V5_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_new_era_V5(
    parser_context_t* c, pd_staking_force_new_era_V5_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_invulnerables_V5(
    parser_context_t* c, pd_staking_set_invulnerables_V5_t* m)
{
    CHECK_ERROR(_readVecAccountId_V5(c, &m->invulnerables))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_unstake_V5(
    parser_context_t* c, pd_staking_force_unstake_V5_t* m)
{
    CHECK_ERROR(_readAccountId_V5(c, &m->stash))
    CHECK_ERROR(_readu32(c, &m->num_slashing_spans))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_new_era_always_V5(
    parser_context_t* c, pd_staking_force_new_era_always_V5_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_cancel_deferred_slash_V5(
    parser_context_t* c, pd_staking_cancel_deferred_slash_V5_t* m)
{
    CHECK_ERROR(_readEraIndex_V5(c, &m->era))
    CHECK_ERROR(_readVecu32(c, &m->slash_indices))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_payout_stakers_V5(
    parser_context_t* c, pd_staking_payout_stakers_V5_t* m)
{
    CHECK_ERROR(_readAccountId_V5(c, &m->validator_stash))
    CHECK_ERROR(_readEraIndex_V5(c, &m->era))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_rebond_V5(
    parser_context_t* c, pd_staking_rebond_V5_t* m)
{
    CHECK_ERROR(_readCompactBalanceOf(c, &m->value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_history_depth_V5(
    parser_context_t* c, pd_staking_set_history_depth_V5_t* m)
{
    CHECK_ERROR(_readCompactEraIndex_V5(c, &m->new_history_depth))
    CHECK_ERROR(_readCompactu32(c, &m->_era_items_deleted))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_reap_stash_V5(
    parser_context_t* c, pd_staking_reap_stash_V5_t* m)
{
    CHECK_ERROR(_readAccountId_V5(c, &m->stash))
    CHECK_ERROR(_readu32(c, &m->num_slashing_spans))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_submit_election_solution_V5(
    parser_context_t* c, pd_staking_submit_election_solution_V5_t* m)
{
    CHECK_ERROR(_readVecValidatorIndex_V5(c, &m->winners))
    CHECK_ERROR(_readCompactAssignments_V5(c, &m->compact))
    CHECK_ERROR(_readElectionScore_V5(c, &m->score))
    CHECK_ERROR(_readEraIndex_V5(c, &m->era))
    CHECK_ERROR(_readElectionSize_V5(c, &m->size))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_submit_election_solution_unsigned_V5(
    parser_context_t* c, pd_staking_submit_election_solution_unsigned_V5_t* m)
{
    CHECK_ERROR(_readVecValidatorIndex_V5(c, &m->winners))
    CHECK_ERROR(_readCompactAssignments_V5(c, &m->compact))
    CHECK_ERROR(_readElectionScore_V5(c, &m->score))
    CHECK_ERROR(_readEraIndex_V5(c, &m->era))
    CHECK_ERROR(_readElectionSize_V5(c, &m->size))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_session_set_keys_V5(
    parser_context_t* c, pd_session_set_keys_V5_t* m)
{
    CHECK_ERROR(_readKeys_V5(c, &m->keys))
    CHECK_ERROR(_readBytes(c, &m->proof))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_session_purge_keys_V5(
    parser_context_t* c, pd_session_purge_keys_V5_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_grandpa_report_equivocation_V5(
    parser_context_t* c, pd_grandpa_report_equivocation_V5_t* m)
{
    CHECK_ERROR(_readEquivocationProof_V5(c, &m->equivocation_proof))
    CHECK_ERROR(_readKeyOwnerProof_V5(c, &m->key_owner_proof))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_grandpa_report_equivocation_unsigned_V5(
    parser_context_t* c, pd_grandpa_report_equivocation_unsigned_V5_t* m)
{
    CHECK_ERROR(_readEquivocationProof_V5(c, &m->equivocation_proof))
    CHECK_ERROR(_readKeyOwnerProof_V5(c, &m->key_owner_proof))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_grandpa_note_stalled_V5(
    parser_context_t* c, pd_grandpa_note_stalled_V5_t* m)
{
    CHECK_ERROR(_readBlockNumber(c, &m->delay))
    CHECK_ERROR(_readBlockNumber(c, &m->best_finalized_block_number))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_imonline_heartbeat_V5(
    parser_context_t* c, pd_imonline_heartbeat_V5_t* m)
{
    CHECK_ERROR(_readHeartbeat(c, &m->heartbeat))
    CHECK_ERROR(_readSignature_V5(c, &m->_signature))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_propose_V5(
    parser_context_t* c, pd_democracy_propose_V5_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    CHECK_ERROR(_readCompactBalanceOf(c, &m->value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_second_V5(
    parser_context_t* c, pd_democracy_second_V5_t* m)
{
    CHECK_ERROR(_readCompactPropIndex_V5(c, &m->proposal))
    CHECK_ERROR(_readCompactu32(c, &m->seconds_upper_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_vote_V5(
    parser_context_t* c, pd_democracy_vote_V5_t* m)
{
    CHECK_ERROR(_readCompactReferendumIndex_V5(c, &m->ref_index))
    CHECK_ERROR(_readAccountVote_V5(c, &m->vote))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_emergency_cancel_V5(
    parser_context_t* c, pd_democracy_emergency_cancel_V5_t* m)
{
    CHECK_ERROR(_readReferendumIndex_V5(c, &m->ref_index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_external_propose_V5(
    parser_context_t* c, pd_democracy_external_propose_V5_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_external_propose_majority_V5(
    parser_context_t* c, pd_democracy_external_propose_majority_V5_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_external_propose_default_V5(
    parser_context_t* c, pd_democracy_external_propose_default_V5_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_fast_track_V5(
    parser_context_t* c, pd_democracy_fast_track_V5_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    CHECK_ERROR(_readBlockNumber(c, &m->voting_period))
    CHECK_ERROR(_readBlockNumber(c, &m->delay))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_veto_external_V5(
    parser_context_t* c, pd_democracy_veto_external_V5_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_cancel_referendum_V5(
    parser_context_t* c, pd_democracy_cancel_referendum_V5_t* m)
{
    CHECK_ERROR(_readCompactReferendumIndex_V5(c, &m->ref_index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_cancel_queued_V5(
    parser_context_t* c, pd_democracy_cancel_queued_V5_t* m)
{
    CHECK_ERROR(_readReferendumIndex_V5(c, &m->which))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_delegate_V5(
    parser_context_t* c, pd_democracy_delegate_V5_t* m)
{
    CHECK_ERROR(_readAccountId_V5(c, &m->to))
    CHECK_ERROR(_readConviction_V5(c, &m->conviction))
    CHECK_ERROR(_readBalanceOf_V5(c, &m->balance))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_undelegate_V5(
    parser_context_t* c, pd_democracy_undelegate_V5_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_clear_public_proposals_V5(
    parser_context_t* c, pd_democracy_clear_public_proposals_V5_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_note_preimage_V5(
    parser_context_t* c, pd_democracy_note_preimage_V5_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->encoded_proposal))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_note_preimage_operational_V5(
    parser_context_t* c, pd_democracy_note_preimage_operational_V5_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->encoded_proposal))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_note_imminent_preimage_V5(
    parser_context_t* c, pd_democracy_note_imminent_preimage_V5_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->encoded_proposal))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_note_imminent_preimage_operational_V5(
    parser_context_t* c, pd_democracy_note_imminent_preimage_operational_V5_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->encoded_proposal))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_reap_preimage_V5(
    parser_context_t* c, pd_democracy_reap_preimage_V5_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    CHECK_ERROR(_readCompactu32(c, &m->proposal_len_upper_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_unlock_V5(
    parser_context_t* c, pd_democracy_unlock_V5_t* m)
{
    CHECK_ERROR(_readAccountId_V5(c, &m->target))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_remove_vote_V5(
    parser_context_t* c, pd_democracy_remove_vote_V5_t* m)
{
    CHECK_ERROR(_readReferendumIndex_V5(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_remove_other_vote_V5(
    parser_context_t* c, pd_democracy_remove_other_vote_V5_t* m)
{
    CHECK_ERROR(_readAccountId_V5(c, &m->target))
    CHECK_ERROR(_readReferendumIndex_V5(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_enact_proposal_V5(
    parser_context_t* c, pd_democracy_enact_proposal_V5_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    CHECK_ERROR(_readReferendumIndex_V5(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_blacklist_V5(
    parser_context_t* c, pd_democracy_blacklist_V5_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    CHECK_ERROR(_readOptionReferendumIndex_V5(c, &m->maybe_ref_index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_cancel_proposal_V5(
    parser_context_t* c, pd_democracy_cancel_proposal_V5_t* m)
{
    CHECK_ERROR(_readCompactPropIndex_V5(c, &m->prop_index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_council_set_members_V5(
    parser_context_t* c, pd_council_set_members_V5_t* m)
{
    CHECK_ERROR(_readVecAccountId_V5(c, &m->new_members))
    CHECK_ERROR(_readOptionAccountId_V5(c, &m->prime))
    CHECK_ERROR(_readMemberCount_V5(c, &m->old_count))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_council_execute_V5(
    parser_context_t* c, pd_council_execute_V5_t* m)
{
    CHECK_ERROR(_readProposal_V5(c, &m->proposal))
    CHECK_ERROR(_readCompactu32(c, &m->length_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_council_propose_V5(
    parser_context_t* c, pd_council_propose_V5_t* m)
{
    CHECK_ERROR(_readCompactMemberCount_V5(c, &m->threshold))
    CHECK_ERROR(_readProposal_V5(c, &m->proposal))
    CHECK_ERROR(_readCompactu32(c, &m->length_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_council_vote_V5(
    parser_context_t* c, pd_council_vote_V5_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal))
    CHECK_ERROR(_readCompactProposalIndex_V5(c, &m->index))
    CHECK_ERROR(_readbool(c, &m->approve))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_council_close_V5(
    parser_context_t* c, pd_council_close_V5_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    CHECK_ERROR(_readCompactProposalIndex_V5(c, &m->index))
    CHECK_ERROR(_readCompactWeight_V5(c, &m->proposal_weight_bound))
    CHECK_ERROR(_readCompactu32(c, &m->length_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_council_disapprove_proposal_V5(
    parser_context_t* c, pd_council_disapprove_proposal_V5_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_set_members_V5(
    parser_context_t* c, pd_technicalcommittee_set_members_V5_t* m)
{
    CHECK_ERROR(_readVecAccountId_V5(c, &m->new_members))
    CHECK_ERROR(_readOptionAccountId_V5(c, &m->prime))
    CHECK_ERROR(_readMemberCount_V5(c, &m->old_count))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_execute_V5(
    parser_context_t* c, pd_technicalcommittee_execute_V5_t* m)
{
    CHECK_ERROR(_readProposal_V5(c, &m->proposal))
    CHECK_ERROR(_readCompactu32(c, &m->length_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_propose_V5(
    parser_context_t* c, pd_technicalcommittee_propose_V5_t* m)
{
    CHECK_ERROR(_readCompactMemberCount_V5(c, &m->threshold))
    CHECK_ERROR(_readProposal_V5(c, &m->proposal))
    CHECK_ERROR(_readCompactu32(c, &m->length_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_vote_V5(
    parser_context_t* c, pd_technicalcommittee_vote_V5_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal))
    CHECK_ERROR(_readCompactProposalIndex_V5(c, &m->index))
    CHECK_ERROR(_readbool(c, &m->approve))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_close_V5(
    parser_context_t* c, pd_technicalcommittee_close_V5_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    CHECK_ERROR(_readCompactProposalIndex_V5(c, &m->index))
    CHECK_ERROR(_readCompactWeight_V5(c, &m->proposal_weight_bound))
    CHECK_ERROR(_readCompactu32(c, &m->length_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_disapprove_proposal_V5(
    parser_context_t* c, pd_technicalcommittee_disapprove_proposal_V5_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_electionsphragmen_vote_V5(
    parser_context_t* c, pd_electionsphragmen_vote_V5_t* m)
{
    CHECK_ERROR(_readVecAccountId_V5(c, &m->votes))
    CHECK_ERROR(_readCompactBalanceOf(c, &m->value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_electionsphragmen_remove_voter_V5(
    parser_context_t* c, pd_electionsphragmen_remove_voter_V5_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_electionsphragmen_report_defunct_voter_V5(
    parser_context_t* c, pd_electionsphragmen_report_defunct_voter_V5_t* m)
{
    CHECK_ERROR(_readDefunctVoter_V5(c, &m->defunct))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_electionsphragmen_submit_candidacy_V5(
    parser_context_t* c, pd_electionsphragmen_submit_candidacy_V5_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->candidate_count))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_electionsphragmen_renounce_candidacy_V5(
    parser_context_t* c, pd_electionsphragmen_renounce_candidacy_V5_t* m)
{
    CHECK_ERROR(_readRenouncing_V5(c, &m->renouncing))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_electionsphragmen_remove_member_V5(
    parser_context_t* c, pd_electionsphragmen_remove_member_V5_t* m)
{
    CHECK_ERROR(_readLookupSource(c, &m->who))
    CHECK_ERROR(_readbool(c, &m->has_replacement))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalmembership_add_member_V5(
    parser_context_t* c, pd_technicalmembership_add_member_V5_t* m)
{
    CHECK_ERROR(_readAccountId_V5(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalmembership_remove_member_V5(
    parser_context_t* c, pd_technicalmembership_remove_member_V5_t* m)
{
    CHECK_ERROR(_readAccountId_V5(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalmembership_swap_member_V5(
    parser_context_t* c, pd_technicalmembership_swap_member_V5_t* m)
{
    CHECK_ERROR(_readAccountId_V5(c, &m->remove))
    CHECK_ERROR(_readAccountId_V5(c, &m->add))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalmembership_reset_members_V5(
    parser_context_t* c, pd_technicalmembership_reset_members_V5_t* m)
{
    CHECK_ERROR(_readVecAccountId_V5(c, &m->members))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalmembership_change_key_V5(
    parser_context_t* c, pd_technicalmembership_change_key_V5_t* m)
{
    CHECK_ERROR(_readAccountId_V5(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalmembership_set_prime_V5(
    parser_context_t* c, pd_technicalmembership_set_prime_V5_t* m)
{
    CHECK_ERROR(_readAccountId_V5(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalmembership_clear_prime_V5(
    parser_context_t* c, pd_technicalmembership_clear_prime_V5_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_propose_spend_V5(
    parser_context_t* c, pd_treasury_propose_spend_V5_t* m)
{
    CHECK_ERROR(_readCompactBalanceOf(c, &m->value))
    CHECK_ERROR(_readLookupSource(c, &m->beneficiary))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_reject_proposal_V5(
    parser_context_t* c, pd_treasury_reject_proposal_V5_t* m)
{
    CHECK_ERROR(_readCompactProposalIndex_V5(c, &m->proposal_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_approve_proposal_V5(
    parser_context_t* c, pd_treasury_approve_proposal_V5_t* m)
{
    CHECK_ERROR(_readCompactProposalIndex_V5(c, &m->proposal_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_report_awesome_V5(
    parser_context_t* c, pd_treasury_report_awesome_V5_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->reason))
    CHECK_ERROR(_readAccountId_V5(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_retract_tip_V5(
    parser_context_t* c, pd_treasury_retract_tip_V5_t* m)
{
    CHECK_ERROR(_readHash(c, &m->hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_tip_new_V5(
    parser_context_t* c, pd_treasury_tip_new_V5_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->reason))
    CHECK_ERROR(_readAccountId_V5(c, &m->who))
    CHECK_ERROR(_readCompactBalanceOf(c, &m->tip_value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_tip_V5(
    parser_context_t* c, pd_treasury_tip_V5_t* m)
{
    CHECK_ERROR(_readHash(c, &m->hash))
    CHECK_ERROR(_readCompactBalanceOf(c, &m->tip_value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_close_tip_V5(
    parser_context_t* c, pd_treasury_close_tip_V5_t* m)
{
    CHECK_ERROR(_readHash(c, &m->hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_propose_bounty_V5(
    parser_context_t* c, pd_treasury_propose_bounty_V5_t* m)
{
    CHECK_ERROR(_readCompactBalanceOf(c, &m->value))
    CHECK_ERROR(_readBytes(c, &m->description))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_approve_bounty_V5(
    parser_context_t* c, pd_treasury_approve_bounty_V5_t* m)
{
    CHECK_ERROR(_readCompactProposalIndex_V5(c, &m->bounty_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_propose_curator_V5(
    parser_context_t* c, pd_treasury_propose_curator_V5_t* m)
{
    CHECK_ERROR(_readCompactProposalIndex_V5(c, &m->bounty_id))
    CHECK_ERROR(_readLookupSource(c, &m->curator))
    CHECK_ERROR(_readCompactBalanceOf(c, &m->fee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_unassign_curator_V5(
    parser_context_t* c, pd_treasury_unassign_curator_V5_t* m)
{
    CHECK_ERROR(_readCompactProposalIndex_V5(c, &m->bounty_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_accept_curator_V5(
    parser_context_t* c, pd_treasury_accept_curator_V5_t* m)
{
    CHECK_ERROR(_readCompactProposalIndex_V5(c, &m->bounty_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_award_bounty_V5(
    parser_context_t* c, pd_treasury_award_bounty_V5_t* m)
{
    CHECK_ERROR(_readCompactProposalIndex_V5(c, &m->bounty_id))
    CHECK_ERROR(_readLookupSource(c, &m->beneficiary))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_claim_bounty_V5(
    parser_context_t* c, pd_treasury_claim_bounty_V5_t* m)
{
    CHECK_ERROR(_readCompactBountyIndex_V5(c, &m->bounty_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_close_bounty_V5(
    parser_context_t* c, pd_treasury_close_bounty_V5_t* m)
{
    CHECK_ERROR(_readCompactBountyIndex_V5(c, &m->bounty_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_extend_bounty_expiry_V5(
    parser_context_t* c, pd_treasury_extend_bounty_expiry_V5_t* m)
{
    CHECK_ERROR(_readCompactBountyIndex_V5(c, &m->bounty_id))
    CHECK_ERROR(_readBytes(c, &m->_remark))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_claims_claim_V5(
    parser_context_t* c, pd_claims_claim_V5_t* m)
{
    CHECK_ERROR(_readAccountId_V5(c, &m->dest))
    CHECK_ERROR(_readEcdsaSignature_V5(c, &m->ethereum_signature))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_claims_mint_claim_V5(
    parser_context_t* c, pd_claims_mint_claim_V5_t* m)
{
    CHECK_ERROR(_readEthereumAddress_V5(c, &m->who))
    CHECK_ERROR(_readBalanceOf_V5(c, &m->value))
    CHECK_ERROR(_readOptionTupleBalanceOfBalanceOfBlockNumber_V5(c, &m->vesting_schedule))
    CHECK_ERROR(_readOptionStatementKind_V5(c, &m->statement))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_claims_claim_attest_V5(
    parser_context_t* c, pd_claims_claim_attest_V5_t* m)
{
    CHECK_ERROR(_readAccountId_V5(c, &m->dest))
    CHECK_ERROR(_readEcdsaSignature_V5(c, &m->ethereum_signature))
    CHECK_ERROR(_readBytes(c, &m->statement))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_claims_attest_V5(
    parser_context_t* c, pd_claims_attest_V5_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->statement))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_claims_move_claim_V5(
    parser_context_t* c, pd_claims_move_claim_V5_t* m)
{
    CHECK_ERROR(_readEthereumAddress_V5(c, &m->old))
    CHECK_ERROR(_readEthereumAddress_V5(c, &m->new_))
    CHECK_ERROR(_readOptionAccountId_V5(c, &m->maybe_preclaim))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_vesting_vest_V5(
    parser_context_t* c, pd_vesting_vest_V5_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_vesting_vest_other_V5(
    parser_context_t* c, pd_vesting_vest_other_V5_t* m)
{
    CHECK_ERROR(_readLookupSource(c, &m->target))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_vesting_vested_transfer_V5(
    parser_context_t* c, pd_vesting_vested_transfer_V5_t* m)
{
    CHECK_ERROR(_readLookupSource(c, &m->target))
    CHECK_ERROR(_readVestingInfo_V5(c, &m->schedule))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_vesting_force_vested_transfer_V5(
    parser_context_t* c, pd_vesting_force_vested_transfer_V5_t* m)
{
    CHECK_ERROR(_readLookupSource(c, &m->source))
    CHECK_ERROR(_readLookupSource(c, &m->target))
    CHECK_ERROR(_readVestingInfo_V5(c, &m->schedule))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_batch_V5(
    parser_context_t* c, pd_utility_batch_V5_t* m)
{
    CHECK_ERROR(_readVecCall_V5(c, &m->calls))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_as_derivative_V5(
    parser_context_t* c, pd_utility_as_derivative_V5_t* m)
{
    CHECK_ERROR(_readu16(c, &m->index))
    CHECK_ERROR(_readCall_V5(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_batch_all_V5(
    parser_context_t* c, pd_utility_batch_all_V5_t* m)
{
    CHECK_ERROR(_readVecCall_V5(c, &m->calls))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_add_registrar_V5(
    parser_context_t* c, pd_identity_add_registrar_V5_t* m)
{
    CHECK_ERROR(_readAccountId_V5(c, &m->account))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_set_identity_V5(
    parser_context_t* c, pd_identity_set_identity_V5_t* m)
{
    CHECK_ERROR(_readIdentityInfo_V5(c, &m->info))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_set_subs_V5(
    parser_context_t* c, pd_identity_set_subs_V5_t* m)
{
    CHECK_ERROR(_readVecTupleAccountIdData_V5(c, &m->subs))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_clear_identity_V5(
    parser_context_t* c, pd_identity_clear_identity_V5_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_request_judgement_V5(
    parser_context_t* c, pd_identity_request_judgement_V5_t* m)
{
    CHECK_ERROR(_readCompactRegistrarIndex_V5(c, &m->reg_index))
    CHECK_ERROR(_readCompactBalanceOf(c, &m->max_fee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_cancel_request_V5(
    parser_context_t* c, pd_identity_cancel_request_V5_t* m)
{
    CHECK_ERROR(_readRegistrarIndex_V5(c, &m->reg_index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_set_fee_V5(
    parser_context_t* c, pd_identity_set_fee_V5_t* m)
{
    CHECK_ERROR(_readCompactRegistrarIndex_V5(c, &m->index))
    CHECK_ERROR(_readCompactBalanceOf(c, &m->fee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_set_account_id_V5(
    parser_context_t* c, pd_identity_set_account_id_V5_t* m)
{
    CHECK_ERROR(_readCompactRegistrarIndex_V5(c, &m->index))
    CHECK_ERROR(_readAccountId_V5(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_set_fields_V5(
    parser_context_t* c, pd_identity_set_fields_V5_t* m)
{
    CHECK_ERROR(_readCompactRegistrarIndex_V5(c, &m->index))
    CHECK_ERROR(_readIdentityFields_V5(c, &m->fields))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_provide_judgement_V5(
    parser_context_t* c, pd_identity_provide_judgement_V5_t* m)
{
    CHECK_ERROR(_readCompactRegistrarIndex_V5(c, &m->reg_index))
    CHECK_ERROR(_readLookupSource(c, &m->target))
    CHECK_ERROR(_readJudgement_V5(c, &m->judgement))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_kill_identity_V5(
    parser_context_t* c, pd_identity_kill_identity_V5_t* m)
{
    CHECK_ERROR(_readLookupSource(c, &m->target))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_add_sub_V5(
    parser_context_t* c, pd_identity_add_sub_V5_t* m)
{
    CHECK_ERROR(_readLookupSource(c, &m->sub))
    CHECK_ERROR(_readData(c, &m->data))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_rename_sub_V5(
    parser_context_t* c, pd_identity_rename_sub_V5_t* m)
{
    CHECK_ERROR(_readLookupSource(c, &m->sub))
    CHECK_ERROR(_readData(c, &m->data))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_remove_sub_V5(
    parser_context_t* c, pd_identity_remove_sub_V5_t* m)
{
    CHECK_ERROR(_readLookupSource(c, &m->sub))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_quit_sub_V5(
    parser_context_t* c, pd_identity_quit_sub_V5_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_proxy_V5(
    parser_context_t* c, pd_proxy_proxy_V5_t* m)
{
    CHECK_ERROR(_readAccountId_V5(c, &m->real))
    CHECK_ERROR(_readOptionProxyType_V5(c, &m->force_proxy_type))
    CHECK_ERROR(_readCall_V5(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_add_proxy_V5(
    parser_context_t* c, pd_proxy_add_proxy_V5_t* m)
{
    CHECK_ERROR(_readAccountId_V5(c, &m->delegate))
    CHECK_ERROR(_readProxyType_V5(c, &m->proxy_type))
    CHECK_ERROR(_readBlockNumber(c, &m->delay))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_remove_proxy_V5(
    parser_context_t* c, pd_proxy_remove_proxy_V5_t* m)
{
    CHECK_ERROR(_readAccountId_V5(c, &m->delegate))
    CHECK_ERROR(_readProxyType_V5(c, &m->proxy_type))
    CHECK_ERROR(_readBlockNumber(c, &m->delay))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_remove_proxies_V5(
    parser_context_t* c, pd_proxy_remove_proxies_V5_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_anonymous_V5(
    parser_context_t* c, pd_proxy_anonymous_V5_t* m)
{
    CHECK_ERROR(_readProxyType_V5(c, &m->proxy_type))
    CHECK_ERROR(_readBlockNumber(c, &m->delay))
    CHECK_ERROR(_readu16(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_kill_anonymous_V5(
    parser_context_t* c, pd_proxy_kill_anonymous_V5_t* m)
{
    CHECK_ERROR(_readAccountId_V5(c, &m->spawner))
    CHECK_ERROR(_readProxyType_V5(c, &m->proxy_type))
    CHECK_ERROR(_readu16(c, &m->index))
    CHECK_ERROR(_readCompactBlockNumber(c, &m->height))
    CHECK_ERROR(_readCompactu32(c, &m->ext_index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_announce_V5(
    parser_context_t* c, pd_proxy_announce_V5_t* m)
{
    CHECK_ERROR(_readAccountId_V5(c, &m->real))
    CHECK_ERROR(_readCallHashOf_V5(c, &m->call_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_remove_announcement_V5(
    parser_context_t* c, pd_proxy_remove_announcement_V5_t* m)
{
    CHECK_ERROR(_readAccountId_V5(c, &m->real))
    CHECK_ERROR(_readCallHashOf_V5(c, &m->call_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_reject_announcement_V5(
    parser_context_t* c, pd_proxy_reject_announcement_V5_t* m)
{
    CHECK_ERROR(_readAccountId_V5(c, &m->delegate))
    CHECK_ERROR(_readCallHashOf_V5(c, &m->call_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_proxy_announced_V5(
    parser_context_t* c, pd_proxy_proxy_announced_V5_t* m)
{
    CHECK_ERROR(_readAccountId_V5(c, &m->delegate))
    CHECK_ERROR(_readAccountId_V5(c, &m->real))
    CHECK_ERROR(_readOptionProxyType_V5(c, &m->force_proxy_type))
    CHECK_ERROR(_readCall_V5(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_as_multi_threshold_1_V5(
    parser_context_t* c, pd_multisig_as_multi_threshold_1_V5_t* m)
{
    CHECK_ERROR(_readVecAccountId_V5(c, &m->other_signatories))
    CHECK_ERROR(_readCall_V5(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_as_multi_V5(
    parser_context_t* c, pd_multisig_as_multi_V5_t* m)
{
    CHECK_ERROR(_readu16(c, &m->threshold))
    CHECK_ERROR(_readVecAccountId_V5(c, &m->other_signatories))
    CHECK_ERROR(_readOptionTimepoint_V5(c, &m->maybe_timepoint))
    CHECK_ERROR(_readOpaqueCall_V5(c, &m->call))
    CHECK_ERROR(_readbool(c, &m->store_call))
    CHECK_ERROR(_readWeight_V5(c, &m->max_weight))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_approve_as_multi_V5(
    parser_context_t* c, pd_multisig_approve_as_multi_V5_t* m)
{
    CHECK_ERROR(_readu16(c, &m->threshold))
    CHECK_ERROR(_readVecAccountId_V5(c, &m->other_signatories))
    CHECK_ERROR(_readOptionTimepoint_V5(c, &m->maybe_timepoint))
    CHECK_ERROR(_readu8_array_32_V5(c, &m->call_hash))
    CHECK_ERROR(_readWeight_V5(c, &m->max_weight))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_cancel_as_multi_V5(
    parser_context_t* c, pd_multisig_cancel_as_multi_V5_t* m)
{
    CHECK_ERROR(_readu16(c, &m->threshold))
    CHECK_ERROR(_readVecAccountId_V5(c, &m->other_signatories))
    CHECK_ERROR(_readTimepoint_V5(c, &m->timepoint))
    CHECK_ERROR(_readu8_array_32_V5(c, &m->call_hash))
    return parser_ok;
}

parser_error_t _readMethodBasic_V5(
    parser_context_t* c,
    uint8_t moduleIdx,
    uint8_t callIdx,
    pd_MethodBasic_V5_t* method)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 0: /* module 0 call 0 */
        CHECK_ERROR(_readMethod_system_fill_block_V5(c, &method->system_fill_block_V5))
        break;
    case 1: /* module 0 call 1 */
        CHECK_ERROR(_readMethod_system_remark_V5(c, &method->system_remark_V5))
        break;
    case 2: /* module 0 call 2 */
        CHECK_ERROR(_readMethod_system_set_heap_pages_V5(c, &method->system_set_heap_pages_V5))
        break;
    case 3: /* module 0 call 3 */
        CHECK_ERROR(_readMethod_system_set_code_V5(c, &method->system_set_code_V5))
        break;
    case 4: /* module 0 call 4 */
        CHECK_ERROR(_readMethod_system_set_code_without_checks_V5(c, &method->system_set_code_without_checks_V5))
        break;
    case 5: /* module 0 call 5 */
        CHECK_ERROR(_readMethod_system_set_changes_trie_config_V5(c, &method->system_set_changes_trie_config_V5))
        break;
    case 6: /* module 0 call 6 */
        CHECK_ERROR(_readMethod_system_set_storage_V5(c, &method->system_set_storage_V5))
        break;
    case 7: /* module 0 call 7 */
        CHECK_ERROR(_readMethod_system_kill_storage_V5(c, &method->system_kill_storage_V5))
        break;
    case 8: /* module 0 call 8 */
        CHECK_ERROR(_readMethod_system_kill_prefix_V5(c, &method->system_kill_prefix_V5))
        break;
    case 9: /* module 0 call 9 */
        CHECK_ERROR(_readMethod_system_suicide_V5(c, &method->system_suicide_V5))
        break;
    case 256: /* module 1 call 0 */
        CHECK_ERROR(_readMethod_scheduler_schedule_V5(c, &method->scheduler_schedule_V5))
        break;
    case 257: /* module 1 call 1 */
        CHECK_ERROR(_readMethod_scheduler_cancel_V5(c, &method->scheduler_cancel_V5))
        break;
    case 258: /* module 1 call 2 */
        CHECK_ERROR(_readMethod_scheduler_schedule_named_V5(c, &method->scheduler_schedule_named_V5))
        break;
    case 259: /* module 1 call 3 */
        CHECK_ERROR(_readMethod_scheduler_cancel_named_V5(c, &method->scheduler_cancel_named_V5))
        break;
    case 260: /* module 1 call 4 */
        CHECK_ERROR(_readMethod_scheduler_schedule_after_V5(c, &method->scheduler_schedule_after_V5))
        break;
    case 261: /* module 1 call 5 */
        CHECK_ERROR(_readMethod_scheduler_schedule_named_after_V5(c, &method->scheduler_schedule_named_after_V5))
        break;
    case 512: /* module 2 call 0 */
        CHECK_ERROR(_readMethod_babe_report_equivocation_V5(c, &method->babe_report_equivocation_V5))
        break;
    case 513: /* module 2 call 1 */
        CHECK_ERROR(_readMethod_babe_report_equivocation_unsigned_V5(c, &method->babe_report_equivocation_unsigned_V5))
        break;
    case 768: /* module 3 call 0 */
        CHECK_ERROR(_readMethod_timestamp_set_V5(c, &method->timestamp_set_V5))
        break;
    case 1024: /* module 4 call 0 */
        CHECK_ERROR(_readMethod_indices_claim_V5(c, &method->indices_claim_V5))
        break;
    case 1025: /* module 4 call 1 */
        CHECK_ERROR(_readMethod_indices_transfer_V5(c, &method->indices_transfer_V5))
        break;
    case 1026: /* module 4 call 2 */
        CHECK_ERROR(_readMethod_indices_free_V5(c, &method->indices_free_V5))
        break;
    case 1027: /* module 4 call 3 */
        CHECK_ERROR(_readMethod_indices_force_transfer_V5(c, &method->indices_force_transfer_V5))
        break;
    case 1028: /* module 4 call 4 */
        CHECK_ERROR(_readMethod_indices_freeze_V5(c, &method->indices_freeze_V5))
        break;
    case 1280: /* module 5 call 0 */
        CHECK_ERROR(_readMethod_balances_transfer_V5(c, &method->balances_transfer_V5))
        break;
    case 1281: /* module 5 call 1 */
        CHECK_ERROR(_readMethod_balances_set_balance_V5(c, &method->balances_set_balance_V5))
        break;
    case 1282: /* module 5 call 2 */
        CHECK_ERROR(_readMethod_balances_force_transfer_V5(c, &method->balances_force_transfer_V5))
        break;
    case 1283: /* module 5 call 3 */
        CHECK_ERROR(_readMethod_balances_transfer_keep_alive_V5(c, &method->balances_transfer_keep_alive_V5))
        break;
    case 1536: /* module 6 call 0 */
        CHECK_ERROR(_readMethod_authorship_set_uncles_V5(c, &method->authorship_set_uncles_V5))
        break;
    case 1792: /* module 7 call 0 */
        CHECK_ERROR(_readMethod_staking_bond_V5(c, &method->staking_bond_V5))
        break;
    case 1793: /* module 7 call 1 */
        CHECK_ERROR(_readMethod_staking_bond_extra_V5(c, &method->staking_bond_extra_V5))
        break;
    case 1794: /* module 7 call 2 */
        CHECK_ERROR(_readMethod_staking_unbond_V5(c, &method->staking_unbond_V5))
        break;
    case 1795: /* module 7 call 3 */
        CHECK_ERROR(_readMethod_staking_withdraw_unbonded_V5(c, &method->staking_withdraw_unbonded_V5))
        break;
    case 1796: /* module 7 call 4 */
        CHECK_ERROR(_readMethod_staking_validate_V5(c, &method->staking_validate_V5))
        break;
    case 1797: /* module 7 call 5 */
        CHECK_ERROR(_readMethod_staking_nominate_V5(c, &method->staking_nominate_V5))
        break;
    case 1798: /* module 7 call 6 */
        CHECK_ERROR(_readMethod_staking_chill_V5(c, &method->staking_chill_V5))
        break;
    case 1799: /* module 7 call 7 */
        CHECK_ERROR(_readMethod_staking_set_payee_V5(c, &method->staking_set_payee_V5))
        break;
    case 1800: /* module 7 call 8 */
        CHECK_ERROR(_readMethod_staking_set_controller_V5(c, &method->staking_set_controller_V5))
        break;
    case 1801: /* module 7 call 9 */
        CHECK_ERROR(_readMethod_staking_set_validator_count_V5(c, &method->staking_set_validator_count_V5))
        break;
    case 1802: /* module 7 call 10 */
        CHECK_ERROR(_readMethod_staking_increase_validator_count_V5(c, &method->staking_increase_validator_count_V5))
        break;
    case 1803: /* module 7 call 11 */
        CHECK_ERROR(_readMethod_staking_scale_validator_count_V5(c, &method->staking_scale_validator_count_V5))
        break;
    case 1804: /* module 7 call 12 */
        CHECK_ERROR(_readMethod_staking_force_no_eras_V5(c, &method->staking_force_no_eras_V5))
        break;
    case 1805: /* module 7 call 13 */
        CHECK_ERROR(_readMethod_staking_force_new_era_V5(c, &method->staking_force_new_era_V5))
        break;
    case 1806: /* module 7 call 14 */
        CHECK_ERROR(_readMethod_staking_set_invulnerables_V5(c, &method->staking_set_invulnerables_V5))
        break;
    case 1807: /* module 7 call 15 */
        CHECK_ERROR(_readMethod_staking_force_unstake_V5(c, &method->staking_force_unstake_V5))
        break;
    case 1808: /* module 7 call 16 */
        CHECK_ERROR(_readMethod_staking_force_new_era_always_V5(c, &method->staking_force_new_era_always_V5))
        break;
    case 1809: /* module 7 call 17 */
        CHECK_ERROR(_readMethod_staking_cancel_deferred_slash_V5(c, &method->staking_cancel_deferred_slash_V5))
        break;
    case 1810: /* module 7 call 18 */
        CHECK_ERROR(_readMethod_staking_payout_stakers_V5(c, &method->staking_payout_stakers_V5))
        break;
    case 1811: /* module 7 call 19 */
        CHECK_ERROR(_readMethod_staking_rebond_V5(c, &method->staking_rebond_V5))
        break;
    case 1812: /* module 7 call 20 */
        CHECK_ERROR(_readMethod_staking_set_history_depth_V5(c, &method->staking_set_history_depth_V5))
        break;
    case 1813: /* module 7 call 21 */
        CHECK_ERROR(_readMethod_staking_reap_stash_V5(c, &method->staking_reap_stash_V5))
        break;
    case 1814: /* module 7 call 22 */
        CHECK_ERROR(_readMethod_staking_submit_election_solution_V5(c, &method->staking_submit_election_solution_V5))
        break;
    case 1815: /* module 7 call 23 */
        CHECK_ERROR(_readMethod_staking_submit_election_solution_unsigned_V5(c, &method->staking_submit_election_solution_unsigned_V5))
        break;
    case 2304: /* module 9 call 0 */
        CHECK_ERROR(_readMethod_session_set_keys_V5(c, &method->session_set_keys_V5))
        break;
    case 2305: /* module 9 call 1 */
        CHECK_ERROR(_readMethod_session_purge_keys_V5(c, &method->session_purge_keys_V5))
        break;
    case 2816: /* module 11 call 0 */
        CHECK_ERROR(_readMethod_grandpa_report_equivocation_V5(c, &method->grandpa_report_equivocation_V5))
        break;
    case 2817: /* module 11 call 1 */
        CHECK_ERROR(_readMethod_grandpa_report_equivocation_unsigned_V5(c, &method->grandpa_report_equivocation_unsigned_V5))
        break;
    case 2818: /* module 11 call 2 */
        CHECK_ERROR(_readMethod_grandpa_note_stalled_V5(c, &method->grandpa_note_stalled_V5))
        break;
    case 3072: /* module 12 call 0 */
        CHECK_ERROR(_readMethod_imonline_heartbeat_V5(c, &method->imonline_heartbeat_V5))
        break;
    case 3584: /* module 14 call 0 */
        CHECK_ERROR(_readMethod_democracy_propose_V5(c, &method->democracy_propose_V5))
        break;
    case 3585: /* module 14 call 1 */
        CHECK_ERROR(_readMethod_democracy_second_V5(c, &method->democracy_second_V5))
        break;
    case 3586: /* module 14 call 2 */
        CHECK_ERROR(_readMethod_democracy_vote_V5(c, &method->democracy_vote_V5))
        break;
    case 3587: /* module 14 call 3 */
        CHECK_ERROR(_readMethod_democracy_emergency_cancel_V5(c, &method->democracy_emergency_cancel_V5))
        break;
    case 3588: /* module 14 call 4 */
        CHECK_ERROR(_readMethod_democracy_external_propose_V5(c, &method->democracy_external_propose_V5))
        break;
    case 3589: /* module 14 call 5 */
        CHECK_ERROR(_readMethod_democracy_external_propose_majority_V5(c, &method->democracy_external_propose_majority_V5))
        break;
    case 3590: /* module 14 call 6 */
        CHECK_ERROR(_readMethod_democracy_external_propose_default_V5(c, &method->democracy_external_propose_default_V5))
        break;
    case 3591: /* module 14 call 7 */
        CHECK_ERROR(_readMethod_democracy_fast_track_V5(c, &method->democracy_fast_track_V5))
        break;
    case 3592: /* module 14 call 8 */
        CHECK_ERROR(_readMethod_democracy_veto_external_V5(c, &method->democracy_veto_external_V5))
        break;
    case 3593: /* module 14 call 9 */
        CHECK_ERROR(_readMethod_democracy_cancel_referendum_V5(c, &method->democracy_cancel_referendum_V5))
        break;
    case 3594: /* module 14 call 10 */
        CHECK_ERROR(_readMethod_democracy_cancel_queued_V5(c, &method->democracy_cancel_queued_V5))
        break;
    case 3595: /* module 14 call 11 */
        CHECK_ERROR(_readMethod_democracy_delegate_V5(c, &method->democracy_delegate_V5))
        break;
    case 3596: /* module 14 call 12 */
        CHECK_ERROR(_readMethod_democracy_undelegate_V5(c, &method->democracy_undelegate_V5))
        break;
    case 3597: /* module 14 call 13 */
        CHECK_ERROR(_readMethod_democracy_clear_public_proposals_V5(c, &method->democracy_clear_public_proposals_V5))
        break;
    case 3598: /* module 14 call 14 */
        CHECK_ERROR(_readMethod_democracy_note_preimage_V5(c, &method->democracy_note_preimage_V5))
        break;
    case 3599: /* module 14 call 15 */
        CHECK_ERROR(_readMethod_democracy_note_preimage_operational_V5(c, &method->democracy_note_preimage_operational_V5))
        break;
    case 3600: /* module 14 call 16 */
        CHECK_ERROR(_readMethod_democracy_note_imminent_preimage_V5(c, &method->democracy_note_imminent_preimage_V5))
        break;
    case 3601: /* module 14 call 17 */
        CHECK_ERROR(_readMethod_democracy_note_imminent_preimage_operational_V5(c, &method->democracy_note_imminent_preimage_operational_V5))
        break;
    case 3602: /* module 14 call 18 */
        CHECK_ERROR(_readMethod_democracy_reap_preimage_V5(c, &method->democracy_reap_preimage_V5))
        break;
    case 3603: /* module 14 call 19 */
        CHECK_ERROR(_readMethod_democracy_unlock_V5(c, &method->democracy_unlock_V5))
        break;
    case 3604: /* module 14 call 20 */
        CHECK_ERROR(_readMethod_democracy_remove_vote_V5(c, &method->democracy_remove_vote_V5))
        break;
    case 3605: /* module 14 call 21 */
        CHECK_ERROR(_readMethod_democracy_remove_other_vote_V5(c, &method->democracy_remove_other_vote_V5))
        break;
    case 3606: /* module 14 call 22 */
        CHECK_ERROR(_readMethod_democracy_enact_proposal_V5(c, &method->democracy_enact_proposal_V5))
        break;
    case 3607: /* module 14 call 23 */
        CHECK_ERROR(_readMethod_democracy_blacklist_V5(c, &method->democracy_blacklist_V5))
        break;
    case 3608: /* module 14 call 24 */
        CHECK_ERROR(_readMethod_democracy_cancel_proposal_V5(c, &method->democracy_cancel_proposal_V5))
        break;
    case 3840: /* module 15 call 0 */
        CHECK_ERROR(_readMethod_council_set_members_V5(c, &method->council_set_members_V5))
        break;
    case 3843: /* module 15 call 3 */
        CHECK_ERROR(_readMethod_council_vote_V5(c, &method->council_vote_V5))
        break;
    case 3844: /* module 15 call 4 */
        CHECK_ERROR(_readMethod_council_close_V5(c, &method->council_close_V5))
        break;
    case 3845: /* module 15 call 5 */
        CHECK_ERROR(_readMethod_council_disapprove_proposal_V5(c, &method->council_disapprove_proposal_V5))
        break;
    case 4096: /* module 16 call 0 */
        CHECK_ERROR(_readMethod_technicalcommittee_set_members_V5(c, &method->technicalcommittee_set_members_V5))
        break;
    case 4099: /* module 16 call 3 */
        CHECK_ERROR(_readMethod_technicalcommittee_vote_V5(c, &method->technicalcommittee_vote_V5))
        break;
    case 4100: /* module 16 call 4 */
        CHECK_ERROR(_readMethod_technicalcommittee_close_V5(c, &method->technicalcommittee_close_V5))
        break;
    case 4101: /* module 16 call 5 */
        CHECK_ERROR(_readMethod_technicalcommittee_disapprove_proposal_V5(c, &method->technicalcommittee_disapprove_proposal_V5))
        break;
    case 4352: /* module 17 call 0 */
        CHECK_ERROR(_readMethod_electionsphragmen_vote_V5(c, &method->electionsphragmen_vote_V5))
        break;
    case 4353: /* module 17 call 1 */
        CHECK_ERROR(_readMethod_electionsphragmen_remove_voter_V5(c, &method->electionsphragmen_remove_voter_V5))
        break;
    case 4354: /* module 17 call 2 */
        CHECK_ERROR(_readMethod_electionsphragmen_report_defunct_voter_V5(c, &method->electionsphragmen_report_defunct_voter_V5))
        break;
    case 4355: /* module 17 call 3 */
        CHECK_ERROR(_readMethod_electionsphragmen_submit_candidacy_V5(c, &method->electionsphragmen_submit_candidacy_V5))
        break;
    case 4356: /* module 17 call 4 */
        CHECK_ERROR(_readMethod_electionsphragmen_renounce_candidacy_V5(c, &method->electionsphragmen_renounce_candidacy_V5))
        break;
    case 4357: /* module 17 call 5 */
        CHECK_ERROR(_readMethod_electionsphragmen_remove_member_V5(c, &method->electionsphragmen_remove_member_V5))
        break;
    case 4608: /* module 18 call 0 */
        CHECK_ERROR(_readMethod_technicalmembership_add_member_V5(c, &method->technicalmembership_add_member_V5))
        break;
    case 4609: /* module 18 call 1 */
        CHECK_ERROR(_readMethod_technicalmembership_remove_member_V5(c, &method->technicalmembership_remove_member_V5))
        break;
    case 4610: /* module 18 call 2 */
        CHECK_ERROR(_readMethod_technicalmembership_swap_member_V5(c, &method->technicalmembership_swap_member_V5))
        break;
    case 4611: /* module 18 call 3 */
        CHECK_ERROR(_readMethod_technicalmembership_reset_members_V5(c, &method->technicalmembership_reset_members_V5))
        break;
    case 4612: /* module 18 call 4 */
        CHECK_ERROR(_readMethod_technicalmembership_change_key_V5(c, &method->technicalmembership_change_key_V5))
        break;
    case 4613: /* module 18 call 5 */
        CHECK_ERROR(_readMethod_technicalmembership_set_prime_V5(c, &method->technicalmembership_set_prime_V5))
        break;
    case 4614: /* module 18 call 6 */
        CHECK_ERROR(_readMethod_technicalmembership_clear_prime_V5(c, &method->technicalmembership_clear_prime_V5))
        break;
    case 4864: /* module 19 call 0 */
        CHECK_ERROR(_readMethod_treasury_propose_spend_V5(c, &method->treasury_propose_spend_V5))
        break;
    case 4865: /* module 19 call 1 */
        CHECK_ERROR(_readMethod_treasury_reject_proposal_V5(c, &method->treasury_reject_proposal_V5))
        break;
    case 4866: /* module 19 call 2 */
        CHECK_ERROR(_readMethod_treasury_approve_proposal_V5(c, &method->treasury_approve_proposal_V5))
        break;
    case 4867: /* module 19 call 3 */
        CHECK_ERROR(_readMethod_treasury_report_awesome_V5(c, &method->treasury_report_awesome_V5))
        break;
    case 4868: /* module 19 call 4 */
        CHECK_ERROR(_readMethod_treasury_retract_tip_V5(c, &method->treasury_retract_tip_V5))
        break;
    case 4869: /* module 19 call 5 */
        CHECK_ERROR(_readMethod_treasury_tip_new_V5(c, &method->treasury_tip_new_V5))
        break;
    case 4870: /* module 19 call 6 */
        CHECK_ERROR(_readMethod_treasury_tip_V5(c, &method->treasury_tip_V5))
        break;
    case 4871: /* module 19 call 7 */
        CHECK_ERROR(_readMethod_treasury_close_tip_V5(c, &method->treasury_close_tip_V5))
        break;
    case 4872: /* module 19 call 8 */
        CHECK_ERROR(_readMethod_treasury_propose_bounty_V5(c, &method->treasury_propose_bounty_V5))
        break;
    case 4873: /* module 19 call 9 */
        CHECK_ERROR(_readMethod_treasury_approve_bounty_V5(c, &method->treasury_approve_bounty_V5))
        break;
    case 4874: /* module 19 call 10 */
        CHECK_ERROR(_readMethod_treasury_propose_curator_V5(c, &method->treasury_propose_curator_V5))
        break;
    case 4875: /* module 19 call 11 */
        CHECK_ERROR(_readMethod_treasury_unassign_curator_V5(c, &method->treasury_unassign_curator_V5))
        break;
    case 4876: /* module 19 call 12 */
        CHECK_ERROR(_readMethod_treasury_accept_curator_V5(c, &method->treasury_accept_curator_V5))
        break;
    case 4877: /* module 19 call 13 */
        CHECK_ERROR(_readMethod_treasury_award_bounty_V5(c, &method->treasury_award_bounty_V5))
        break;
    case 4878: /* module 19 call 14 */
        CHECK_ERROR(_readMethod_treasury_claim_bounty_V5(c, &method->treasury_claim_bounty_V5))
        break;
    case 4879: /* module 19 call 15 */
        CHECK_ERROR(_readMethod_treasury_close_bounty_V5(c, &method->treasury_close_bounty_V5))
        break;
    case 4880: /* module 19 call 16 */
        CHECK_ERROR(_readMethod_treasury_extend_bounty_expiry_V5(c, &method->treasury_extend_bounty_expiry_V5))
        break;
    case 6144: /* module 24 call 0 */
        CHECK_ERROR(_readMethod_claims_claim_V5(c, &method->claims_claim_V5))
        break;
    case 6145: /* module 24 call 1 */
        CHECK_ERROR(_readMethod_claims_mint_claim_V5(c, &method->claims_mint_claim_V5))
        break;
    case 6146: /* module 24 call 2 */
        CHECK_ERROR(_readMethod_claims_claim_attest_V5(c, &method->claims_claim_attest_V5))
        break;
    case 6147: /* module 24 call 3 */
        CHECK_ERROR(_readMethod_claims_attest_V5(c, &method->claims_attest_V5))
        break;
    case 6148: /* module 24 call 4 */
        CHECK_ERROR(_readMethod_claims_move_claim_V5(c, &method->claims_move_claim_V5))
        break;
    case 6400: /* module 25 call 0 */
        CHECK_ERROR(_readMethod_vesting_vest_V5(c, &method->vesting_vest_V5))
        break;
    case 6401: /* module 25 call 1 */
        CHECK_ERROR(_readMethod_vesting_vest_other_V5(c, &method->vesting_vest_other_V5))
        break;
    case 6402: /* module 25 call 2 */
        CHECK_ERROR(_readMethod_vesting_vested_transfer_V5(c, &method->vesting_vested_transfer_V5))
        break;
    case 6403: /* module 25 call 3 */
        CHECK_ERROR(_readMethod_vesting_force_vested_transfer_V5(c, &method->vesting_force_vested_transfer_V5))
        break;
    case 6656: /* module 26 call 0 */
        CHECK_ERROR(_readMethod_utility_batch_V5(c, &method->utility_batch_V5))
        break;
    case 6657: /* module 26 call 1 */
        CHECK_ERROR(_readMethod_utility_as_derivative_V5(c, &method->utility_as_derivative_V5))
        break;
    case 6658: /* module 26 call 2 */
        CHECK_ERROR(_readMethod_utility_batch_all_V5(c, &method->utility_batch_all_V5))
        break;
    case 7168: /* module 28 call 0 */
        CHECK_ERROR(_readMethod_identity_add_registrar_V5(c, &method->identity_add_registrar_V5))
        break;
    case 7169: /* module 28 call 1 */
        CHECK_ERROR(_readMethod_identity_set_identity_V5(c, &method->identity_set_identity_V5))
        break;
    case 7170: /* module 28 call 2 */
        CHECK_ERROR(_readMethod_identity_set_subs_V5(c, &method->identity_set_subs_V5))
        break;
    case 7171: /* module 28 call 3 */
        CHECK_ERROR(_readMethod_identity_clear_identity_V5(c, &method->identity_clear_identity_V5))
        break;
    case 7172: /* module 28 call 4 */
        CHECK_ERROR(_readMethod_identity_request_judgement_V5(c, &method->identity_request_judgement_V5))
        break;
    case 7173: /* module 28 call 5 */
        CHECK_ERROR(_readMethod_identity_cancel_request_V5(c, &method->identity_cancel_request_V5))
        break;
    case 7174: /* module 28 call 6 */
        CHECK_ERROR(_readMethod_identity_set_fee_V5(c, &method->identity_set_fee_V5))
        break;
    case 7175: /* module 28 call 7 */
        CHECK_ERROR(_readMethod_identity_set_account_id_V5(c, &method->identity_set_account_id_V5))
        break;
    case 7176: /* module 28 call 8 */
        CHECK_ERROR(_readMethod_identity_set_fields_V5(c, &method->identity_set_fields_V5))
        break;
    case 7177: /* module 28 call 9 */
        CHECK_ERROR(_readMethod_identity_provide_judgement_V5(c, &method->identity_provide_judgement_V5))
        break;
    case 7178: /* module 28 call 10 */
        CHECK_ERROR(_readMethod_identity_kill_identity_V5(c, &method->identity_kill_identity_V5))
        break;
    case 7179: /* module 28 call 11 */
        CHECK_ERROR(_readMethod_identity_add_sub_V5(c, &method->identity_add_sub_V5))
        break;
    case 7180: /* module 28 call 12 */
        CHECK_ERROR(_readMethod_identity_rename_sub_V5(c, &method->identity_rename_sub_V5))
        break;
    case 7181: /* module 28 call 13 */
        CHECK_ERROR(_readMethod_identity_remove_sub_V5(c, &method->identity_remove_sub_V5))
        break;
    case 7182: /* module 28 call 14 */
        CHECK_ERROR(_readMethod_identity_quit_sub_V5(c, &method->identity_quit_sub_V5))
        break;
    case 7424: /* module 29 call 0 */
        CHECK_ERROR(_readMethod_proxy_proxy_V5(c, &method->proxy_proxy_V5))
        break;
    case 7425: /* module 29 call 1 */
        CHECK_ERROR(_readMethod_proxy_add_proxy_V5(c, &method->proxy_add_proxy_V5))
        break;
    case 7426: /* module 29 call 2 */
        CHECK_ERROR(_readMethod_proxy_remove_proxy_V5(c, &method->proxy_remove_proxy_V5))
        break;
    case 7427: /* module 29 call 3 */
        CHECK_ERROR(_readMethod_proxy_remove_proxies_V5(c, &method->proxy_remove_proxies_V5))
        break;
    case 7428: /* module 29 call 4 */
        CHECK_ERROR(_readMethod_proxy_anonymous_V5(c, &method->proxy_anonymous_V5))
        break;
    case 7429: /* module 29 call 5 */
        CHECK_ERROR(_readMethod_proxy_kill_anonymous_V5(c, &method->proxy_kill_anonymous_V5))
        break;
    case 7430: /* module 29 call 6 */
        CHECK_ERROR(_readMethod_proxy_announce_V5(c, &method->proxy_announce_V5))
        break;
    case 7431: /* module 29 call 7 */
        CHECK_ERROR(_readMethod_proxy_remove_announcement_V5(c, &method->proxy_remove_announcement_V5))
        break;
    case 7432: /* module 29 call 8 */
        CHECK_ERROR(_readMethod_proxy_reject_announcement_V5(c, &method->proxy_reject_announcement_V5))
        break;
    case 7433: /* module 29 call 9 */
        CHECK_ERROR(_readMethod_proxy_proxy_announced_V5(c, &method->proxy_proxy_announced_V5))
        break;
    case 7680: /* module 30 call 0 */
        CHECK_ERROR(_readMethod_multisig_as_multi_threshold_1_V5(c, &method->multisig_as_multi_threshold_1_V5))
        break;
    case 7681: /* module 30 call 1 */
        CHECK_ERROR(_readMethod_multisig_as_multi_V5(c, &method->multisig_as_multi_V5))
        break;
    case 7682: /* module 30 call 2 */
        CHECK_ERROR(_readMethod_multisig_approve_as_multi_V5(c, &method->multisig_approve_as_multi_V5))
        break;
    case 7683: /* module 30 call 3 */
        CHECK_ERROR(_readMethod_multisig_cancel_as_multi_V5(c, &method->multisig_cancel_as_multi_V5))
        break;
    default:
        return parser_unexpected_callIndex;
    }

    return parser_ok;
}

parser_error_t _readMethod_V5(
    parser_context_t* c,
    uint8_t moduleIdx,
    uint8_t callIdx,
    pd_Method_V5_t* method)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 0: /* module 0 call 0 */
        CHECK_ERROR(_readMethod_system_fill_block_V5(c, &method->basic.system_fill_block_V5))
        break;
    case 1: /* module 0 call 1 */
        CHECK_ERROR(_readMethod_system_remark_V5(c, &method->basic.system_remark_V5))
        break;
    case 2: /* module 0 call 2 */
        CHECK_ERROR(_readMethod_system_set_heap_pages_V5(c, &method->basic.system_set_heap_pages_V5))
        break;
    case 3: /* module 0 call 3 */
        CHECK_ERROR(_readMethod_system_set_code_V5(c, &method->basic.system_set_code_V5))
        break;
    case 4: /* module 0 call 4 */
        CHECK_ERROR(_readMethod_system_set_code_without_checks_V5(c, &method->basic.system_set_code_without_checks_V5))
        break;
    case 5: /* module 0 call 5 */
        CHECK_ERROR(_readMethod_system_set_changes_trie_config_V5(c, &method->basic.system_set_changes_trie_config_V5))
        break;
    case 6: /* module 0 call 6 */
        CHECK_ERROR(_readMethod_system_set_storage_V5(c, &method->basic.system_set_storage_V5))
        break;
    case 7: /* module 0 call 7 */
        CHECK_ERROR(_readMethod_system_kill_storage_V5(c, &method->basic.system_kill_storage_V5))
        break;
    case 8: /* module 0 call 8 */
        CHECK_ERROR(_readMethod_system_kill_prefix_V5(c, &method->basic.system_kill_prefix_V5))
        break;
    case 9: /* module 0 call 9 */
        CHECK_ERROR(_readMethod_system_suicide_V5(c, &method->basic.system_suicide_V5))
        break;
    case 256: /* module 1 call 0 */
        CHECK_ERROR(_readMethod_scheduler_schedule_V5(c, &method->basic.scheduler_schedule_V5))
        break;
    case 257: /* module 1 call 1 */
        CHECK_ERROR(_readMethod_scheduler_cancel_V5(c, &method->basic.scheduler_cancel_V5))
        break;
    case 258: /* module 1 call 2 */
        CHECK_ERROR(_readMethod_scheduler_schedule_named_V5(c, &method->basic.scheduler_schedule_named_V5))
        break;
    case 259: /* module 1 call 3 */
        CHECK_ERROR(_readMethod_scheduler_cancel_named_V5(c, &method->basic.scheduler_cancel_named_V5))
        break;
    case 260: /* module 1 call 4 */
        CHECK_ERROR(_readMethod_scheduler_schedule_after_V5(c, &method->basic.scheduler_schedule_after_V5))
        break;
    case 261: /* module 1 call 5 */
        CHECK_ERROR(_readMethod_scheduler_schedule_named_after_V5(c, &method->basic.scheduler_schedule_named_after_V5))
        break;
    case 512: /* module 2 call 0 */
        CHECK_ERROR(_readMethod_babe_report_equivocation_V5(c, &method->basic.babe_report_equivocation_V5))
        break;
    case 513: /* module 2 call 1 */
        CHECK_ERROR(_readMethod_babe_report_equivocation_unsigned_V5(c, &method->basic.babe_report_equivocation_unsigned_V5))
        break;
    case 768: /* module 3 call 0 */
        CHECK_ERROR(_readMethod_timestamp_set_V5(c, &method->basic.timestamp_set_V5))
        break;
    case 1024: /* module 4 call 0 */
        CHECK_ERROR(_readMethod_indices_claim_V5(c, &method->basic.indices_claim_V5))
        break;
    case 1025: /* module 4 call 1 */
        CHECK_ERROR(_readMethod_indices_transfer_V5(c, &method->basic.indices_transfer_V5))
        break;
    case 1026: /* module 4 call 2 */
        CHECK_ERROR(_readMethod_indices_free_V5(c, &method->basic.indices_free_V5))
        break;
    case 1027: /* module 4 call 3 */
        CHECK_ERROR(_readMethod_indices_force_transfer_V5(c, &method->basic.indices_force_transfer_V5))
        break;
    case 1028: /* module 4 call 4 */
        CHECK_ERROR(_readMethod_indices_freeze_V5(c, &method->basic.indices_freeze_V5))
        break;
    case 1280: /* module 5 call 0 */
        CHECK_ERROR(_readMethod_balances_transfer_V5(c, &method->basic.balances_transfer_V5))
        break;
    case 1281: /* module 5 call 1 */
        CHECK_ERROR(_readMethod_balances_set_balance_V5(c, &method->basic.balances_set_balance_V5))
        break;
    case 1282: /* module 5 call 2 */
        CHECK_ERROR(_readMethod_balances_force_transfer_V5(c, &method->basic.balances_force_transfer_V5))
        break;
    case 1283: /* module 5 call 3 */
        CHECK_ERROR(_readMethod_balances_transfer_keep_alive_V5(c, &method->basic.balances_transfer_keep_alive_V5))
        break;
    case 1536: /* module 6 call 0 */
        CHECK_ERROR(_readMethod_authorship_set_uncles_V5(c, &method->basic.authorship_set_uncles_V5))
        break;
    case 1792: /* module 7 call 0 */
        CHECK_ERROR(_readMethod_staking_bond_V5(c, &method->basic.staking_bond_V5))
        break;
    case 1793: /* module 7 call 1 */
        CHECK_ERROR(_readMethod_staking_bond_extra_V5(c, &method->basic.staking_bond_extra_V5))
        break;
    case 1794: /* module 7 call 2 */
        CHECK_ERROR(_readMethod_staking_unbond_V5(c, &method->basic.staking_unbond_V5))
        break;
    case 1795: /* module 7 call 3 */
        CHECK_ERROR(_readMethod_staking_withdraw_unbonded_V5(c, &method->basic.staking_withdraw_unbonded_V5))
        break;
    case 1796: /* module 7 call 4 */
        CHECK_ERROR(_readMethod_staking_validate_V5(c, &method->basic.staking_validate_V5))
        break;
    case 1797: /* module 7 call 5 */
        CHECK_ERROR(_readMethod_staking_nominate_V5(c, &method->basic.staking_nominate_V5))
        break;
    case 1798: /* module 7 call 6 */
        CHECK_ERROR(_readMethod_staking_chill_V5(c, &method->basic.staking_chill_V5))
        break;
    case 1799: /* module 7 call 7 */
        CHECK_ERROR(_readMethod_staking_set_payee_V5(c, &method->basic.staking_set_payee_V5))
        break;
    case 1800: /* module 7 call 8 */
        CHECK_ERROR(_readMethod_staking_set_controller_V5(c, &method->basic.staking_set_controller_V5))
        break;
    case 1801: /* module 7 call 9 */
        CHECK_ERROR(_readMethod_staking_set_validator_count_V5(c, &method->basic.staking_set_validator_count_V5))
        break;
    case 1802: /* module 7 call 10 */
        CHECK_ERROR(_readMethod_staking_increase_validator_count_V5(c, &method->basic.staking_increase_validator_count_V5))
        break;
    case 1803: /* module 7 call 11 */
        CHECK_ERROR(_readMethod_staking_scale_validator_count_V5(c, &method->basic.staking_scale_validator_count_V5))
        break;
    case 1804: /* module 7 call 12 */
        CHECK_ERROR(_readMethod_staking_force_no_eras_V5(c, &method->basic.staking_force_no_eras_V5))
        break;
    case 1805: /* module 7 call 13 */
        CHECK_ERROR(_readMethod_staking_force_new_era_V5(c, &method->basic.staking_force_new_era_V5))
        break;
    case 1806: /* module 7 call 14 */
        CHECK_ERROR(_readMethod_staking_set_invulnerables_V5(c, &method->basic.staking_set_invulnerables_V5))
        break;
    case 1807: /* module 7 call 15 */
        CHECK_ERROR(_readMethod_staking_force_unstake_V5(c, &method->basic.staking_force_unstake_V5))
        break;
    case 1808: /* module 7 call 16 */
        CHECK_ERROR(_readMethod_staking_force_new_era_always_V5(c, &method->basic.staking_force_new_era_always_V5))
        break;
    case 1809: /* module 7 call 17 */
        CHECK_ERROR(_readMethod_staking_cancel_deferred_slash_V5(c, &method->basic.staking_cancel_deferred_slash_V5))
        break;
    case 1810: /* module 7 call 18 */
        CHECK_ERROR(_readMethod_staking_payout_stakers_V5(c, &method->basic.staking_payout_stakers_V5))
        break;
    case 1811: /* module 7 call 19 */
        CHECK_ERROR(_readMethod_staking_rebond_V5(c, &method->basic.staking_rebond_V5))
        break;
    case 1812: /* module 7 call 20 */
        CHECK_ERROR(_readMethod_staking_set_history_depth_V5(c, &method->basic.staking_set_history_depth_V5))
        break;
    case 1813: /* module 7 call 21 */
        CHECK_ERROR(_readMethod_staking_reap_stash_V5(c, &method->basic.staking_reap_stash_V5))
        break;
    case 1814: /* module 7 call 22 */
        CHECK_ERROR(_readMethod_staking_submit_election_solution_V5(c, &method->basic.staking_submit_election_solution_V5))
        break;
    case 1815: /* module 7 call 23 */
        CHECK_ERROR(_readMethod_staking_submit_election_solution_unsigned_V5(c, &method->basic.staking_submit_election_solution_unsigned_V5))
        break;
    case 2304: /* module 9 call 0 */
        CHECK_ERROR(_readMethod_session_set_keys_V5(c, &method->basic.session_set_keys_V5))
        break;
    case 2305: /* module 9 call 1 */
        CHECK_ERROR(_readMethod_session_purge_keys_V5(c, &method->basic.session_purge_keys_V5))
        break;
    case 2816: /* module 11 call 0 */
        CHECK_ERROR(_readMethod_grandpa_report_equivocation_V5(c, &method->basic.grandpa_report_equivocation_V5))
        break;
    case 2817: /* module 11 call 1 */
        CHECK_ERROR(_readMethod_grandpa_report_equivocation_unsigned_V5(c, &method->basic.grandpa_report_equivocation_unsigned_V5))
        break;
    case 2818: /* module 11 call 2 */
        CHECK_ERROR(_readMethod_grandpa_note_stalled_V5(c, &method->basic.grandpa_note_stalled_V5))
        break;
    case 3072: /* module 12 call 0 */
        CHECK_ERROR(_readMethod_imonline_heartbeat_V5(c, &method->basic.imonline_heartbeat_V5))
        break;
    case 3584: /* module 14 call 0 */
        CHECK_ERROR(_readMethod_democracy_propose_V5(c, &method->basic.democracy_propose_V5))
        break;
    case 3585: /* module 14 call 1 */
        CHECK_ERROR(_readMethod_democracy_second_V5(c, &method->basic.democracy_second_V5))
        break;
    case 3586: /* module 14 call 2 */
        CHECK_ERROR(_readMethod_democracy_vote_V5(c, &method->basic.democracy_vote_V5))
        break;
    case 3587: /* module 14 call 3 */
        CHECK_ERROR(_readMethod_democracy_emergency_cancel_V5(c, &method->basic.democracy_emergency_cancel_V5))
        break;
    case 3588: /* module 14 call 4 */
        CHECK_ERROR(_readMethod_democracy_external_propose_V5(c, &method->basic.democracy_external_propose_V5))
        break;
    case 3589: /* module 14 call 5 */
        CHECK_ERROR(_readMethod_democracy_external_propose_majority_V5(c, &method->basic.democracy_external_propose_majority_V5))
        break;
    case 3590: /* module 14 call 6 */
        CHECK_ERROR(_readMethod_democracy_external_propose_default_V5(c, &method->basic.democracy_external_propose_default_V5))
        break;
    case 3591: /* module 14 call 7 */
        CHECK_ERROR(_readMethod_democracy_fast_track_V5(c, &method->basic.democracy_fast_track_V5))
        break;
    case 3592: /* module 14 call 8 */
        CHECK_ERROR(_readMethod_democracy_veto_external_V5(c, &method->basic.democracy_veto_external_V5))
        break;
    case 3593: /* module 14 call 9 */
        CHECK_ERROR(_readMethod_democracy_cancel_referendum_V5(c, &method->basic.democracy_cancel_referendum_V5))
        break;
    case 3594: /* module 14 call 10 */
        CHECK_ERROR(_readMethod_democracy_cancel_queued_V5(c, &method->basic.democracy_cancel_queued_V5))
        break;
    case 3595: /* module 14 call 11 */
        CHECK_ERROR(_readMethod_democracy_delegate_V5(c, &method->basic.democracy_delegate_V5))
        break;
    case 3596: /* module 14 call 12 */
        CHECK_ERROR(_readMethod_democracy_undelegate_V5(c, &method->basic.democracy_undelegate_V5))
        break;
    case 3597: /* module 14 call 13 */
        CHECK_ERROR(_readMethod_democracy_clear_public_proposals_V5(c, &method->basic.democracy_clear_public_proposals_V5))
        break;
    case 3598: /* module 14 call 14 */
        CHECK_ERROR(_readMethod_democracy_note_preimage_V5(c, &method->basic.democracy_note_preimage_V5))
        break;
    case 3599: /* module 14 call 15 */
        CHECK_ERROR(_readMethod_democracy_note_preimage_operational_V5(c, &method->basic.democracy_note_preimage_operational_V5))
        break;
    case 3600: /* module 14 call 16 */
        CHECK_ERROR(_readMethod_democracy_note_imminent_preimage_V5(c, &method->basic.democracy_note_imminent_preimage_V5))
        break;
    case 3601: /* module 14 call 17 */
        CHECK_ERROR(_readMethod_democracy_note_imminent_preimage_operational_V5(c, &method->basic.democracy_note_imminent_preimage_operational_V5))
        break;
    case 3602: /* module 14 call 18 */
        CHECK_ERROR(_readMethod_democracy_reap_preimage_V5(c, &method->basic.democracy_reap_preimage_V5))
        break;
    case 3603: /* module 14 call 19 */
        CHECK_ERROR(_readMethod_democracy_unlock_V5(c, &method->basic.democracy_unlock_V5))
        break;
    case 3604: /* module 14 call 20 */
        CHECK_ERROR(_readMethod_democracy_remove_vote_V5(c, &method->basic.democracy_remove_vote_V5))
        break;
    case 3605: /* module 14 call 21 */
        CHECK_ERROR(_readMethod_democracy_remove_other_vote_V5(c, &method->basic.democracy_remove_other_vote_V5))
        break;
    case 3606: /* module 14 call 22 */
        CHECK_ERROR(_readMethod_democracy_enact_proposal_V5(c, &method->basic.democracy_enact_proposal_V5))
        break;
    case 3607: /* module 14 call 23 */
        CHECK_ERROR(_readMethod_democracy_blacklist_V5(c, &method->basic.democracy_blacklist_V5))
        break;
    case 3608: /* module 14 call 24 */
        CHECK_ERROR(_readMethod_democracy_cancel_proposal_V5(c, &method->basic.democracy_cancel_proposal_V5))
        break;
    case 3840: /* module 15 call 0 */
        CHECK_ERROR(_readMethod_council_set_members_V5(c, &method->basic.council_set_members_V5))
        break;
    case 3841: /* module 15 call 1 */
        CHECK_ERROR(_readMethod_council_execute_V5(c, &method->nested.council_execute_V5))
        break;
    case 3842: /* module 15 call 2 */
        CHECK_ERROR(_readMethod_council_propose_V5(c, &method->nested.council_propose_V5))
        break;
    case 3843: /* module 15 call 3 */
        CHECK_ERROR(_readMethod_council_vote_V5(c, &method->basic.council_vote_V5))
        break;
    case 3844: /* module 15 call 4 */
        CHECK_ERROR(_readMethod_council_close_V5(c, &method->basic.council_close_V5))
        break;
    case 3845: /* module 15 call 5 */
        CHECK_ERROR(_readMethod_council_disapprove_proposal_V5(c, &method->basic.council_disapprove_proposal_V5))
        break;
    case 4096: /* module 16 call 0 */
        CHECK_ERROR(_readMethod_technicalcommittee_set_members_V5(c, &method->basic.technicalcommittee_set_members_V5))
        break;
    case 4097: /* module 16 call 1 */
        CHECK_ERROR(_readMethod_technicalcommittee_execute_V5(c, &method->nested.technicalcommittee_execute_V5))
        break;
    case 4098: /* module 16 call 2 */
        CHECK_ERROR(_readMethod_technicalcommittee_propose_V5(c, &method->nested.technicalcommittee_propose_V5))
        break;
    case 4099: /* module 16 call 3 */
        CHECK_ERROR(_readMethod_technicalcommittee_vote_V5(c, &method->basic.technicalcommittee_vote_V5))
        break;
    case 4100: /* module 16 call 4 */
        CHECK_ERROR(_readMethod_technicalcommittee_close_V5(c, &method->basic.technicalcommittee_close_V5))
        break;
    case 4101: /* module 16 call 5 */
        CHECK_ERROR(_readMethod_technicalcommittee_disapprove_proposal_V5(c, &method->basic.technicalcommittee_disapprove_proposal_V5))
        break;
    case 4352: /* module 17 call 0 */
        CHECK_ERROR(_readMethod_electionsphragmen_vote_V5(c, &method->basic.electionsphragmen_vote_V5))
        break;
    case 4353: /* module 17 call 1 */
        CHECK_ERROR(_readMethod_electionsphragmen_remove_voter_V5(c, &method->basic.electionsphragmen_remove_voter_V5))
        break;
    case 4354: /* module 17 call 2 */
        CHECK_ERROR(_readMethod_electionsphragmen_report_defunct_voter_V5(c, &method->basic.electionsphragmen_report_defunct_voter_V5))
        break;
    case 4355: /* module 17 call 3 */
        CHECK_ERROR(_readMethod_electionsphragmen_submit_candidacy_V5(c, &method->basic.electionsphragmen_submit_candidacy_V5))
        break;
    case 4356: /* module 17 call 4 */
        CHECK_ERROR(_readMethod_electionsphragmen_renounce_candidacy_V5(c, &method->basic.electionsphragmen_renounce_candidacy_V5))
        break;
    case 4357: /* module 17 call 5 */
        CHECK_ERROR(_readMethod_electionsphragmen_remove_member_V5(c, &method->basic.electionsphragmen_remove_member_V5))
        break;
    case 4608: /* module 18 call 0 */
        CHECK_ERROR(_readMethod_technicalmembership_add_member_V5(c, &method->basic.technicalmembership_add_member_V5))
        break;
    case 4609: /* module 18 call 1 */
        CHECK_ERROR(_readMethod_technicalmembership_remove_member_V5(c, &method->basic.technicalmembership_remove_member_V5))
        break;
    case 4610: /* module 18 call 2 */
        CHECK_ERROR(_readMethod_technicalmembership_swap_member_V5(c, &method->basic.technicalmembership_swap_member_V5))
        break;
    case 4611: /* module 18 call 3 */
        CHECK_ERROR(_readMethod_technicalmembership_reset_members_V5(c, &method->basic.technicalmembership_reset_members_V5))
        break;
    case 4612: /* module 18 call 4 */
        CHECK_ERROR(_readMethod_technicalmembership_change_key_V5(c, &method->basic.technicalmembership_change_key_V5))
        break;
    case 4613: /* module 18 call 5 */
        CHECK_ERROR(_readMethod_technicalmembership_set_prime_V5(c, &method->basic.technicalmembership_set_prime_V5))
        break;
    case 4614: /* module 18 call 6 */
        CHECK_ERROR(_readMethod_technicalmembership_clear_prime_V5(c, &method->basic.technicalmembership_clear_prime_V5))
        break;
    case 4864: /* module 19 call 0 */
        CHECK_ERROR(_readMethod_treasury_propose_spend_V5(c, &method->basic.treasury_propose_spend_V5))
        break;
    case 4865: /* module 19 call 1 */
        CHECK_ERROR(_readMethod_treasury_reject_proposal_V5(c, &method->basic.treasury_reject_proposal_V5))
        break;
    case 4866: /* module 19 call 2 */
        CHECK_ERROR(_readMethod_treasury_approve_proposal_V5(c, &method->basic.treasury_approve_proposal_V5))
        break;
    case 4867: /* module 19 call 3 */
        CHECK_ERROR(_readMethod_treasury_report_awesome_V5(c, &method->basic.treasury_report_awesome_V5))
        break;
    case 4868: /* module 19 call 4 */
        CHECK_ERROR(_readMethod_treasury_retract_tip_V5(c, &method->basic.treasury_retract_tip_V5))
        break;
    case 4869: /* module 19 call 5 */
        CHECK_ERROR(_readMethod_treasury_tip_new_V5(c, &method->basic.treasury_tip_new_V5))
        break;
    case 4870: /* module 19 call 6 */
        CHECK_ERROR(_readMethod_treasury_tip_V5(c, &method->basic.treasury_tip_V5))
        break;
    case 4871: /* module 19 call 7 */
        CHECK_ERROR(_readMethod_treasury_close_tip_V5(c, &method->basic.treasury_close_tip_V5))
        break;
    case 4872: /* module 19 call 8 */
        CHECK_ERROR(_readMethod_treasury_propose_bounty_V5(c, &method->basic.treasury_propose_bounty_V5))
        break;
    case 4873: /* module 19 call 9 */
        CHECK_ERROR(_readMethod_treasury_approve_bounty_V5(c, &method->basic.treasury_approve_bounty_V5))
        break;
    case 4874: /* module 19 call 10 */
        CHECK_ERROR(_readMethod_treasury_propose_curator_V5(c, &method->basic.treasury_propose_curator_V5))
        break;
    case 4875: /* module 19 call 11 */
        CHECK_ERROR(_readMethod_treasury_unassign_curator_V5(c, &method->basic.treasury_unassign_curator_V5))
        break;
    case 4876: /* module 19 call 12 */
        CHECK_ERROR(_readMethod_treasury_accept_curator_V5(c, &method->basic.treasury_accept_curator_V5))
        break;
    case 4877: /* module 19 call 13 */
        CHECK_ERROR(_readMethod_treasury_award_bounty_V5(c, &method->basic.treasury_award_bounty_V5))
        break;
    case 4878: /* module 19 call 14 */
        CHECK_ERROR(_readMethod_treasury_claim_bounty_V5(c, &method->basic.treasury_claim_bounty_V5))
        break;
    case 4879: /* module 19 call 15 */
        CHECK_ERROR(_readMethod_treasury_close_bounty_V5(c, &method->basic.treasury_close_bounty_V5))
        break;
    case 4880: /* module 19 call 16 */
        CHECK_ERROR(_readMethod_treasury_extend_bounty_expiry_V5(c, &method->basic.treasury_extend_bounty_expiry_V5))
        break;
    case 6144: /* module 24 call 0 */
        CHECK_ERROR(_readMethod_claims_claim_V5(c, &method->basic.claims_claim_V5))
        break;
    case 6145: /* module 24 call 1 */
        CHECK_ERROR(_readMethod_claims_mint_claim_V5(c, &method->basic.claims_mint_claim_V5))
        break;
    case 6146: /* module 24 call 2 */
        CHECK_ERROR(_readMethod_claims_claim_attest_V5(c, &method->basic.claims_claim_attest_V5))
        break;
    case 6147: /* module 24 call 3 */
        CHECK_ERROR(_readMethod_claims_attest_V5(c, &method->basic.claims_attest_V5))
        break;
    case 6148: /* module 24 call 4 */
        CHECK_ERROR(_readMethod_claims_move_claim_V5(c, &method->basic.claims_move_claim_V5))
        break;
    case 6400: /* module 25 call 0 */
        CHECK_ERROR(_readMethod_vesting_vest_V5(c, &method->basic.vesting_vest_V5))
        break;
    case 6401: /* module 25 call 1 */
        CHECK_ERROR(_readMethod_vesting_vest_other_V5(c, &method->basic.vesting_vest_other_V5))
        break;
    case 6402: /* module 25 call 2 */
        CHECK_ERROR(_readMethod_vesting_vested_transfer_V5(c, &method->basic.vesting_vested_transfer_V5))
        break;
    case 6403: /* module 25 call 3 */
        CHECK_ERROR(_readMethod_vesting_force_vested_transfer_V5(c, &method->basic.vesting_force_vested_transfer_V5))
        break;
    case 6656: /* module 26 call 0 */
        CHECK_ERROR(_readMethod_utility_batch_V5(c, &method->basic.utility_batch_V5))
        break;
    case 6657: /* module 26 call 1 */
        CHECK_ERROR(_readMethod_utility_as_derivative_V5(c, &method->basic.utility_as_derivative_V5))
        break;
    case 6658: /* module 26 call 2 */
        CHECK_ERROR(_readMethod_utility_batch_all_V5(c, &method->basic.utility_batch_all_V5))
        break;
    case 7168: /* module 28 call 0 */
        CHECK_ERROR(_readMethod_identity_add_registrar_V5(c, &method->basic.identity_add_registrar_V5))
        break;
    case 7169: /* module 28 call 1 */
        CHECK_ERROR(_readMethod_identity_set_identity_V5(c, &method->basic.identity_set_identity_V5))
        break;
    case 7170: /* module 28 call 2 */
        CHECK_ERROR(_readMethod_identity_set_subs_V5(c, &method->basic.identity_set_subs_V5))
        break;
    case 7171: /* module 28 call 3 */
        CHECK_ERROR(_readMethod_identity_clear_identity_V5(c, &method->basic.identity_clear_identity_V5))
        break;
    case 7172: /* module 28 call 4 */
        CHECK_ERROR(_readMethod_identity_request_judgement_V5(c, &method->basic.identity_request_judgement_V5))
        break;
    case 7173: /* module 28 call 5 */
        CHECK_ERROR(_readMethod_identity_cancel_request_V5(c, &method->basic.identity_cancel_request_V5))
        break;
    case 7174: /* module 28 call 6 */
        CHECK_ERROR(_readMethod_identity_set_fee_V5(c, &method->basic.identity_set_fee_V5))
        break;
    case 7175: /* module 28 call 7 */
        CHECK_ERROR(_readMethod_identity_set_account_id_V5(c, &method->basic.identity_set_account_id_V5))
        break;
    case 7176: /* module 28 call 8 */
        CHECK_ERROR(_readMethod_identity_set_fields_V5(c, &method->basic.identity_set_fields_V5))
        break;
    case 7177: /* module 28 call 9 */
        CHECK_ERROR(_readMethod_identity_provide_judgement_V5(c, &method->basic.identity_provide_judgement_V5))
        break;
    case 7178: /* module 28 call 10 */
        CHECK_ERROR(_readMethod_identity_kill_identity_V5(c, &method->basic.identity_kill_identity_V5))
        break;
    case 7179: /* module 28 call 11 */
        CHECK_ERROR(_readMethod_identity_add_sub_V5(c, &method->basic.identity_add_sub_V5))
        break;
    case 7180: /* module 28 call 12 */
        CHECK_ERROR(_readMethod_identity_rename_sub_V5(c, &method->basic.identity_rename_sub_V5))
        break;
    case 7181: /* module 28 call 13 */
        CHECK_ERROR(_readMethod_identity_remove_sub_V5(c, &method->basic.identity_remove_sub_V5))
        break;
    case 7182: /* module 28 call 14 */
        CHECK_ERROR(_readMethod_identity_quit_sub_V5(c, &method->basic.identity_quit_sub_V5))
        break;
    case 7424: /* module 29 call 0 */
        CHECK_ERROR(_readMethod_proxy_proxy_V5(c, &method->basic.proxy_proxy_V5))
        break;
    case 7425: /* module 29 call 1 */
        CHECK_ERROR(_readMethod_proxy_add_proxy_V5(c, &method->basic.proxy_add_proxy_V5))
        break;
    case 7426: /* module 29 call 2 */
        CHECK_ERROR(_readMethod_proxy_remove_proxy_V5(c, &method->basic.proxy_remove_proxy_V5))
        break;
    case 7427: /* module 29 call 3 */
        CHECK_ERROR(_readMethod_proxy_remove_proxies_V5(c, &method->basic.proxy_remove_proxies_V5))
        break;
    case 7428: /* module 29 call 4 */
        CHECK_ERROR(_readMethod_proxy_anonymous_V5(c, &method->basic.proxy_anonymous_V5))
        break;
    case 7429: /* module 29 call 5 */
        CHECK_ERROR(_readMethod_proxy_kill_anonymous_V5(c, &method->basic.proxy_kill_anonymous_V5))
        break;
    case 7430: /* module 29 call 6 */
        CHECK_ERROR(_readMethod_proxy_announce_V5(c, &method->basic.proxy_announce_V5))
        break;
    case 7431: /* module 29 call 7 */
        CHECK_ERROR(_readMethod_proxy_remove_announcement_V5(c, &method->basic.proxy_remove_announcement_V5))
        break;
    case 7432: /* module 29 call 8 */
        CHECK_ERROR(_readMethod_proxy_reject_announcement_V5(c, &method->basic.proxy_reject_announcement_V5))
        break;
    case 7433: /* module 29 call 9 */
        CHECK_ERROR(_readMethod_proxy_proxy_announced_V5(c, &method->basic.proxy_proxy_announced_V5))
        break;
    case 7680: /* module 30 call 0 */
        CHECK_ERROR(_readMethod_multisig_as_multi_threshold_1_V5(c, &method->basic.multisig_as_multi_threshold_1_V5))
        break;
    case 7681: /* module 30 call 1 */
        CHECK_ERROR(_readMethod_multisig_as_multi_V5(c, &method->basic.multisig_as_multi_V5))
        break;
    case 7682: /* module 30 call 2 */
        CHECK_ERROR(_readMethod_multisig_approve_as_multi_V5(c, &method->basic.multisig_approve_as_multi_V5))
        break;
    case 7683: /* module 30 call 3 */
        CHECK_ERROR(_readMethod_multisig_cancel_as_multi_V5(c, &method->basic.multisig_cancel_as_multi_V5))
        break;
    default:
        return parser_unexpected_callIndex;
    }

    return parser_ok;
}

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

const char* _getMethod_ModuleName_V5(uint8_t moduleIdx)
{
    switch (moduleIdx) {
    case 0:
        return "System";
    case 1:
        return "Scheduler";
    case 2:
        return "Babe";
    case 3:
        return "Timestamp";
    case 4:
        return "Indices";
    case 5:
        return "Balances";
    case 6:
        return "Authorship";
    case 7:
        return "Staking";
    case 8:
        return "Offences";
    case 9:
        return "Session";
    case 11:
        return "Grandpa";
    case 12:
        return "Imonline";
    case 13:
        return "Authoritydiscovery";
    case 14:
        return "Democracy";
    case 15:
        return "Council";
    case 16:
        return "Technicalcommittee";
    case 17:
        return "Electionsphragmen";
    case 18:
        return "Technicalmembership";
    case 19:
        return "Treasury";
    case 24:
        return "Claims";
    case 25:
        return "Vesting";
    case 26:
        return "Utility";
    case 28:
        return "Identity";
    case 29:
        return "Proxy";
    case 30:
        return "Multisig";
    default:
        return NULL;
    }

    return NULL;
}

const char* _getMethod_Name_V5(uint8_t moduleIdx, uint8_t callIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 0: /* module 0 call 0 */
        return "Fill block";
    case 1: /* module 0 call 1 */
        return "Remark";
    case 2: /* module 0 call 2 */
        return "Set heap pages";
    case 3: /* module 0 call 3 */
        return "Set code";
    case 4: /* module 0 call 4 */
        return "Set code without checks";
    case 5: /* module 0 call 5 */
        return "Set changes trie config";
    case 6: /* module 0 call 6 */
        return "Set storage";
    case 7: /* module 0 call 7 */
        return "Kill storage";
    case 8: /* module 0 call 8 */
        return "Kill prefix";
    case 9: /* module 0 call 9 */
        return "Suicide";
    case 256: /* module 1 call 0 */
        return "Schedule";
    case 257: /* module 1 call 1 */
        return "Cancel";
    case 258: /* module 1 call 2 */
        return "Schedule named";
    case 259: /* module 1 call 3 */
        return "Cancel named";
    case 260: /* module 1 call 4 */
        return "Schedule after";
    case 261: /* module 1 call 5 */
        return "Schedule named after";
    case 512: /* module 2 call 0 */
        return "Report equivocation";
    case 513: /* module 2 call 1 */
        return "Report equivocation unsigned";
    case 768: /* module 3 call 0 */
        return "Set";
    case 1024: /* module 4 call 0 */
        return "Claim";
    case 1025: /* module 4 call 1 */
        return "Transfer";
    case 1026: /* module 4 call 2 */
        return "Free";
    case 1027: /* module 4 call 3 */
        return "Force transfer";
    case 1028: /* module 4 call 4 */
        return "Freeze";
    case 1280: /* module 5 call 0 */
        return "Transfer";
    case 1281: /* module 5 call 1 */
        return "Set balance";
    case 1282: /* module 5 call 2 */
        return "Force transfer";
    case 1283: /* module 5 call 3 */
        return "Transfer keep alive";
    case 1536: /* module 6 call 0 */
        return "Set uncles";
    case 1792: /* module 7 call 0 */
        return "Bond";
    case 1793: /* module 7 call 1 */
        return "Bond extra";
    case 1794: /* module 7 call 2 */
        return "Unbond";
    case 1795: /* module 7 call 3 */
        return "Withdraw unbonded";
    case 1796: /* module 7 call 4 */
        return "Validate";
    case 1797: /* module 7 call 5 */
        return "Nominate";
    case 1798: /* module 7 call 6 */
        return "Chill";
    case 1799: /* module 7 call 7 */
        return "Set payee";
    case 1800: /* module 7 call 8 */
        return "Set controller";
    case 1801: /* module 7 call 9 */
        return "Set validator count";
    case 1802: /* module 7 call 10 */
        return "Increase validator count";
    case 1803: /* module 7 call 11 */
        return "Scale validator count";
    case 1804: /* module 7 call 12 */
        return "Force no eras";
    case 1805: /* module 7 call 13 */
        return "Force new era";
    case 1806: /* module 7 call 14 */
        return "Set invulnerables";
    case 1807: /* module 7 call 15 */
        return "Force unstake";
    case 1808: /* module 7 call 16 */
        return "Force new era always";
    case 1809: /* module 7 call 17 */
        return "Cancel deferred slash";
    case 1810: /* module 7 call 18 */
        return "Payout stakers";
    case 1811: /* module 7 call 19 */
        return "Rebond";
    case 1812: /* module 7 call 20 */
        return "Set history depth";
    case 1813: /* module 7 call 21 */
        return "Reap stash";
    case 1814: /* module 7 call 22 */
        return "Submit election solution";
    case 1815: /* module 7 call 23 */
        return "Submit election solution unsigned";
    case 2304: /* module 9 call 0 */
        return "Set keys";
    case 2305: /* module 9 call 1 */
        return "Purge keys";
    case 2816: /* module 11 call 0 */
        return "Report equivocation";
    case 2817: /* module 11 call 1 */
        return "Report equivocation unsigned";
    case 2818: /* module 11 call 2 */
        return "Note stalled";
    case 3072: /* module 12 call 0 */
        return "Heartbeat";
    case 3584: /* module 14 call 0 */
        return "Propose";
    case 3585: /* module 14 call 1 */
        return "Second";
    case 3586: /* module 14 call 2 */
        return "Vote";
    case 3587: /* module 14 call 3 */
        return "Emergency cancel";
    case 3588: /* module 14 call 4 */
        return "External propose";
    case 3589: /* module 14 call 5 */
        return "External propose majority";
    case 3590: /* module 14 call 6 */
        return "External propose default";
    case 3591: /* module 14 call 7 */
        return "Fast track";
    case 3592: /* module 14 call 8 */
        return "Veto external";
    case 3593: /* module 14 call 9 */
        return "Cancel referendum";
    case 3594: /* module 14 call 10 */
        return "Cancel queued";
    case 3595: /* module 14 call 11 */
        return "Delegate";
    case 3596: /* module 14 call 12 */
        return "Undelegate";
    case 3597: /* module 14 call 13 */
        return "Clear public proposals";
    case 3598: /* module 14 call 14 */
        return "Note preimage";
    case 3599: /* module 14 call 15 */
        return "Note preimage operational";
    case 3600: /* module 14 call 16 */
        return "Note imminent preimage";
    case 3601: /* module 14 call 17 */
        return "Note imminent preimage operational";
    case 3602: /* module 14 call 18 */
        return "Reap preimage";
    case 3603: /* module 14 call 19 */
        return "Unlock";
    case 3604: /* module 14 call 20 */
        return "Remove vote";
    case 3605: /* module 14 call 21 */
        return "Remove other vote";
    case 3606: /* module 14 call 22 */
        return "Enact proposal";
    case 3607: /* module 14 call 23 */
        return "Blacklist";
    case 3608: /* module 14 call 24 */
        return "Cancel proposal";
    case 3840: /* module 15 call 0 */
        return "Set members";
    case 3841: /* module 15 call 1 */
        return "Execute";
    case 3842: /* module 15 call 2 */
        return "Propose";
    case 3843: /* module 15 call 3 */
        return "Vote";
    case 3844: /* module 15 call 4 */
        return "Close";
    case 3845: /* module 15 call 5 */
        return "Disapprove proposal";
    case 4096: /* module 16 call 0 */
        return "Set members";
    case 4097: /* module 16 call 1 */
        return "Execute";
    case 4098: /* module 16 call 2 */
        return "Propose";
    case 4099: /* module 16 call 3 */
        return "Vote";
    case 4100: /* module 16 call 4 */
        return "Close";
    case 4101: /* module 16 call 5 */
        return "Disapprove proposal";
    case 4352: /* module 17 call 0 */
        return "Vote";
    case 4353: /* module 17 call 1 */
        return "Remove voter";
    case 4354: /* module 17 call 2 */
        return "Report defunct voter";
    case 4355: /* module 17 call 3 */
        return "Submit candidacy";
    case 4356: /* module 17 call 4 */
        return "Renounce candidacy";
    case 4357: /* module 17 call 5 */
        return "Remove member";
    case 4608: /* module 18 call 0 */
        return "Add member";
    case 4609: /* module 18 call 1 */
        return "Remove member";
    case 4610: /* module 18 call 2 */
        return "Swap member";
    case 4611: /* module 18 call 3 */
        return "Reset members";
    case 4612: /* module 18 call 4 */
        return "Change key";
    case 4613: /* module 18 call 5 */
        return "Set prime";
    case 4614: /* module 18 call 6 */
        return "Clear prime";
    case 4864: /* module 19 call 0 */
        return "Propose spend";
    case 4865: /* module 19 call 1 */
        return "Reject proposal";
    case 4866: /* module 19 call 2 */
        return "Approve proposal";
    case 4867: /* module 19 call 3 */
        return "Report awesome";
    case 4868: /* module 19 call 4 */
        return "Retract tip";
    case 4869: /* module 19 call 5 */
        return "Tip new";
    case 4870: /* module 19 call 6 */
        return "Tip";
    case 4871: /* module 19 call 7 */
        return "Close tip";
    case 4872: /* module 19 call 8 */
        return "Propose bounty";
    case 4873: /* module 19 call 9 */
        return "Approve bounty";
    case 4874: /* module 19 call 10 */
        return "Propose curator";
    case 4875: /* module 19 call 11 */
        return "Unassign curator";
    case 4876: /* module 19 call 12 */
        return "Accept curator";
    case 4877: /* module 19 call 13 */
        return "Award bounty";
    case 4878: /* module 19 call 14 */
        return "Claim bounty";
    case 4879: /* module 19 call 15 */
        return "Close bounty";
    case 4880: /* module 19 call 16 */
        return "Extend bounty expiry";
    case 6144: /* module 24 call 0 */
        return "Claim";
    case 6145: /* module 24 call 1 */
        return "Mint claim";
    case 6146: /* module 24 call 2 */
        return "Claim attest";
    case 6147: /* module 24 call 3 */
        return "Attest";
    case 6148: /* module 24 call 4 */
        return "Move claim";
    case 6400: /* module 25 call 0 */
        return "Vest";
    case 6401: /* module 25 call 1 */
        return "Vest other";
    case 6402: /* module 25 call 2 */
        return "Vested transfer";
    case 6403: /* module 25 call 3 */
        return "Force vested transfer";
    case 6656: /* module 26 call 0 */
        return "Batch";
    case 6657: /* module 26 call 1 */
        return "As derivative";
    case 6658: /* module 26 call 2 */
        return "Batch all";
    case 7168: /* module 28 call 0 */
        return "Add registrar";
    case 7169: /* module 28 call 1 */
        return "Set identity";
    case 7170: /* module 28 call 2 */
        return "Set subs";
    case 7171: /* module 28 call 3 */
        return "Clear identity";
    case 7172: /* module 28 call 4 */
        return "Request judgement";
    case 7173: /* module 28 call 5 */
        return "Cancel request";
    case 7174: /* module 28 call 6 */
        return "Set fee";
    case 7175: /* module 28 call 7 */
        return "Set account id";
    case 7176: /* module 28 call 8 */
        return "Set fields";
    case 7177: /* module 28 call 9 */
        return "Provide judgement";
    case 7178: /* module 28 call 10 */
        return "Kill identity";
    case 7179: /* module 28 call 11 */
        return "Add sub";
    case 7180: /* module 28 call 12 */
        return "Rename sub";
    case 7181: /* module 28 call 13 */
        return "Remove sub";
    case 7182: /* module 28 call 14 */
        return "Quit sub";
    case 7424: /* module 29 call 0 */
        return "Proxy";
    case 7425: /* module 29 call 1 */
        return "Add proxy";
    case 7426: /* module 29 call 2 */
        return "Remove proxy";
    case 7427: /* module 29 call 3 */
        return "Remove proxies";
    case 7428: /* module 29 call 4 */
        return "Anonymous";
    case 7429: /* module 29 call 5 */
        return "Kill anonymous";
    case 7430: /* module 29 call 6 */
        return "Announce";
    case 7431: /* module 29 call 7 */
        return "Remove announcement";
    case 7432: /* module 29 call 8 */
        return "Reject announcement";
    case 7433: /* module 29 call 9 */
        return "Proxy announced";
    case 7680: /* module 30 call 0 */
        return "As multi threshold 1";
    case 7681: /* module 30 call 1 */
        return "As multi";
    case 7682: /* module 30 call 2 */
        return "Approve as multi";
    case 7683: /* module 30 call 3 */
        return "Cancel as multi";
    default:
        return NULL;
    }

    return NULL;
}

uint8_t _getMethod_NumItems_V5(uint8_t moduleIdx, uint8_t callIdx, pd_Method_V5_t* method)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
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
    case 9: /* module 0 call 9 */
        return 0;
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
    case 1280: /* module 5 call 0 */
        return 2;
    case 1281: /* module 5 call 1 */
        return 3;
    case 1282: /* module 5 call 2 */
        return 3;
    case 1283: /* module 5 call 3 */
        return 2;
    case 1536: /* module 6 call 0 */
        return 1;
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
    case 1810: /* module 7 call 18 */
        return 2;
    case 1811: /* module 7 call 19 */
        return 1;
    case 1812: /* module 7 call 20 */
        return 2;
    case 1813: /* module 7 call 21 */
        return 2;
    case 1814: /* module 7 call 22 */
        return 5;
    case 1815: /* module 7 call 23 */
        return 5;
    case 2304: /* module 9 call 0 */
        return 2;
    case 2305: /* module 9 call 1 */
        return 0;
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
        return 1;
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
    case 4867: /* module 19 call 3 */
        return 2;
    case 4868: /* module 19 call 4 */
        return 1;
    case 4869: /* module 19 call 5 */
        return 3;
    case 4870: /* module 19 call 6 */
        return 2;
    case 4871: /* module 19 call 7 */
        return 1;
    case 4872: /* module 19 call 8 */
        return 2;
    case 4873: /* module 19 call 9 */
        return 1;
    case 4874: /* module 19 call 10 */
        return 3;
    case 4875: /* module 19 call 11 */
        return 1;
    case 4876: /* module 19 call 12 */
        return 1;
    case 4877: /* module 19 call 13 */
        return 2;
    case 4878: /* module 19 call 14 */
        return 1;
    case 4879: /* module 19 call 15 */
        return 1;
    case 4880: /* module 19 call 16 */
        return 2;
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
    case 6656: /* module 26 call 0 */
        return 1;
    case 6657: /* module 26 call 1 */
        return 2;
    case 6658: /* module 26 call 2 */
        return 1;
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
    default:
        return 0;
    }

    return 0;
}

const char* _getMethod_ItemName_V5(uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 0: /* module 0 call 0 */
        switch (itemIdx) {
        case 0:
            return "Ratio";
        default:
            return NULL;
        }
    case 1: /* module 0 call 1 */
        switch (itemIdx) {
        case 0:
            return "Remark";
        default:
            return NULL;
        }
    case 2: /* module 0 call 2 */
        switch (itemIdx) {
        case 0:
            return "Pages";
        default:
            return NULL;
        }
    case 3: /* module 0 call 3 */
        switch (itemIdx) {
        case 0:
            return "Code";
        default:
            return NULL;
        }
    case 4: /* module 0 call 4 */
        switch (itemIdx) {
        case 0:
            return "Code";
        default:
            return NULL;
        }
    case 5: /* module 0 call 5 */
        switch (itemIdx) {
        case 0:
            return "Changes trie config";
        default:
            return NULL;
        }
    case 6: /* module 0 call 6 */
        switch (itemIdx) {
        case 0:
            return "Items";
        default:
            return NULL;
        }
    case 7: /* module 0 call 7 */
        switch (itemIdx) {
        case 0:
            return "Keys";
        default:
            return NULL;
        }
    case 8: /* module 0 call 8 */
        switch (itemIdx) {
        case 0:
            return "Prefix";
        case 1:
            return "Subkeys";
        default:
            return NULL;
        }
    case 9: /* module 0 call 9 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 256: /* module 1 call 0 */
        switch (itemIdx) {
        case 0:
            return "When";
        case 1:
            return "Maybe periodic";
        case 2:
            return "Priority";
        case 3:
            return "Call";
        default:
            return NULL;
        }
    case 257: /* module 1 call 1 */
        switch (itemIdx) {
        case 0:
            return "When";
        case 1:
            return "Index";
        default:
            return NULL;
        }
    case 258: /* module 1 call 2 */
        switch (itemIdx) {
        case 0:
            return "Id";
        case 1:
            return "When";
        case 2:
            return "Maybe periodic";
        case 3:
            return "Priority";
        case 4:
            return "Call";
        default:
            return NULL;
        }
    case 259: /* module 1 call 3 */
        switch (itemIdx) {
        case 0:
            return "Id";
        default:
            return NULL;
        }
    case 260: /* module 1 call 4 */
        switch (itemIdx) {
        case 0:
            return "After";
        case 1:
            return "Maybe periodic";
        case 2:
            return "Priority";
        case 3:
            return "Call";
        default:
            return NULL;
        }
    case 261: /* module 1 call 5 */
        switch (itemIdx) {
        case 0:
            return "Id";
        case 1:
            return "After";
        case 2:
            return "Maybe periodic";
        case 3:
            return "Priority";
        case 4:
            return "Call";
        default:
            return NULL;
        }
    case 512: /* module 2 call 0 */
        switch (itemIdx) {
        case 0:
            return "Equivocation proof";
        case 1:
            return "Key owner proof";
        default:
            return NULL;
        }
    case 513: /* module 2 call 1 */
        switch (itemIdx) {
        case 0:
            return "Equivocation proof";
        case 1:
            return "Key owner proof";
        default:
            return NULL;
        }
    case 768: /* module 3 call 0 */
        switch (itemIdx) {
        case 0:
            return "Now";
        default:
            return NULL;
        }
    case 1024: /* module 4 call 0 */
        switch (itemIdx) {
        case 0:
            return "Index";
        default:
            return NULL;
        }
    case 1025: /* module 4 call 1 */
        switch (itemIdx) {
        case 0:
            return "New";
        case 1:
            return "Index";
        default:
            return NULL;
        }
    case 1026: /* module 4 call 2 */
        switch (itemIdx) {
        case 0:
            return "Index";
        default:
            return NULL;
        }
    case 1027: /* module 4 call 3 */
        switch (itemIdx) {
        case 0:
            return "New";
        case 1:
            return "Index";
        case 2:
            return "Freeze";
        default:
            return NULL;
        }
    case 1028: /* module 4 call 4 */
        switch (itemIdx) {
        case 0:
            return "Index";
        default:
            return NULL;
        }
    case 1280: /* module 5 call 0 */
        switch (itemIdx) {
        case 0:
            return "Dest";
        case 1:
            return "Amount";
        default:
            return NULL;
        }
    case 1281: /* module 5 call 1 */
        switch (itemIdx) {
        case 0:
            return "Who";
        case 1:
            return "New free";
        case 2:
            return "New reserved";
        default:
            return NULL;
        }
    case 1282: /* module 5 call 2 */
        switch (itemIdx) {
        case 0:
            return "Source";
        case 1:
            return "Dest";
        case 2:
            return "Amount";
        default:
            return NULL;
        }
    case 1283: /* module 5 call 3 */
        switch (itemIdx) {
        case 0:
            return "Dest";
        case 1:
            return "Amount";
        default:
            return NULL;
        }
    case 1536: /* module 6 call 0 */
        switch (itemIdx) {
        case 0:
            return "New uncles";
        default:
            return NULL;
        }
    case 1792: /* module 7 call 0 */
        switch (itemIdx) {
        case 0:
            return "Controller";
        case 1:
            return "Amount";
        case 2:
            return "Payee";
        default:
            return NULL;
        }
    case 1793: /* module 7 call 1 */
        switch (itemIdx) {
        case 0:
            return "Max additional";
        default:
            return NULL;
        }
    case 1794: /* module 7 call 2 */
        switch (itemIdx) {
        case 0:
            return "Amount";
        default:
            return NULL;
        }
    case 1795: /* module 7 call 3 */
        switch (itemIdx) {
        case 0:
            return "Num slashing spans";
        default:
            return NULL;
        }
    case 1796: /* module 7 call 4 */
        switch (itemIdx) {
        case 0:
            return "Prefs";
        default:
            return NULL;
        }
    case 1797: /* module 7 call 5 */
        switch (itemIdx) {
        case 0:
            return "Targets";
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
            return "Payee";
        default:
            return NULL;
        }
    case 1800: /* module 7 call 8 */
        switch (itemIdx) {
        case 0:
            return "Controller";
        default:
            return NULL;
        }
    case 1801: /* module 7 call 9 */
        switch (itemIdx) {
        case 0:
            return "New";
        default:
            return NULL;
        }
    case 1802: /* module 7 call 10 */
        switch (itemIdx) {
        case 0:
            return "Additional";
        default:
            return NULL;
        }
    case 1803: /* module 7 call 11 */
        switch (itemIdx) {
        case 0:
            return "Factor";
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
            return "Invulnerables";
        default:
            return NULL;
        }
    case 1807: /* module 7 call 15 */
        switch (itemIdx) {
        case 0:
            return "Stash";
        case 1:
            return "Num slashing spans";
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
            return "Era";
        case 1:
            return "Slash indices";
        default:
            return NULL;
        }
    case 1810: /* module 7 call 18 */
        switch (itemIdx) {
        case 0:
            return "Validator stash";
        case 1:
            return "Era";
        default:
            return NULL;
        }
    case 1811: /* module 7 call 19 */
        switch (itemIdx) {
        case 0:
            return "Amount";
        default:
            return NULL;
        }
    case 1812: /* module 7 call 20 */
        switch (itemIdx) {
        case 0:
            return "New history depth";
        case 1:
            return "Era items deleted";
        default:
            return NULL;
        }
    case 1813: /* module 7 call 21 */
        switch (itemIdx) {
        case 0:
            return "Stash";
        case 1:
            return "Num slashing spans";
        default:
            return NULL;
        }
    case 1814: /* module 7 call 22 */
        switch (itemIdx) {
        case 0:
            return "Winners";
        case 1:
            return "Compact";
        case 2:
            return "Score";
        case 3:
            return "Era";
        case 4:
            return "Size";
        default:
            return NULL;
        }
    case 1815: /* module 7 call 23 */
        switch (itemIdx) {
        case 0:
            return "Winners";
        case 1:
            return "Compact";
        case 2:
            return "Score";
        case 3:
            return "Era";
        case 4:
            return "Size";
        default:
            return NULL;
        }
    case 2304: /* module 9 call 0 */
        switch (itemIdx) {
        case 0:
            return "Keys";
        case 1:
            return "Proof";
        default:
            return NULL;
        }
    case 2305: /* module 9 call 1 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 2816: /* module 11 call 0 */
        switch (itemIdx) {
        case 0:
            return "Equivocation proof";
        case 1:
            return "Key owner proof";
        default:
            return NULL;
        }
    case 2817: /* module 11 call 1 */
        switch (itemIdx) {
        case 0:
            return "Equivocation proof";
        case 1:
            return "Key owner proof";
        default:
            return NULL;
        }
    case 2818: /* module 11 call 2 */
        switch (itemIdx) {
        case 0:
            return "Delay";
        case 1:
            return "Best finalized block number";
        default:
            return NULL;
        }
    case 3072: /* module 12 call 0 */
        switch (itemIdx) {
        case 0:
            return "Heartbeat";
        case 1:
            return "Signature";
        default:
            return NULL;
        }
    case 3584: /* module 14 call 0 */
        switch (itemIdx) {
        case 0:
            return "Proposal hash";
        case 1:
            return "Amount";
        default:
            return NULL;
        }
    case 3585: /* module 14 call 1 */
        switch (itemIdx) {
        case 0:
            return "Proposal";
        case 1:
            return "Seconds upper bound";
        default:
            return NULL;
        }
    case 3586: /* module 14 call 2 */
        switch (itemIdx) {
        case 0:
            return "Ref index";
        case 1:
            return "Vote";
        default:
            return NULL;
        }
    case 3587: /* module 14 call 3 */
        switch (itemIdx) {
        case 0:
            return "Ref index";
        default:
            return NULL;
        }
    case 3588: /* module 14 call 4 */
        switch (itemIdx) {
        case 0:
            return "Proposal hash";
        default:
            return NULL;
        }
    case 3589: /* module 14 call 5 */
        switch (itemIdx) {
        case 0:
            return "Proposal hash";
        default:
            return NULL;
        }
    case 3590: /* module 14 call 6 */
        switch (itemIdx) {
        case 0:
            return "Proposal hash";
        default:
            return NULL;
        }
    case 3591: /* module 14 call 7 */
        switch (itemIdx) {
        case 0:
            return "Proposal hash";
        case 1:
            return "Voting period";
        case 2:
            return "Delay";
        default:
            return NULL;
        }
    case 3592: /* module 14 call 8 */
        switch (itemIdx) {
        case 0:
            return "Proposal hash";
        default:
            return NULL;
        }
    case 3593: /* module 14 call 9 */
        switch (itemIdx) {
        case 0:
            return "Ref index";
        default:
            return NULL;
        }
    case 3594: /* module 14 call 10 */
        switch (itemIdx) {
        case 0:
            return "Which";
        default:
            return NULL;
        }
    case 3595: /* module 14 call 11 */
        switch (itemIdx) {
        case 0:
            return "To";
        case 1:
            return "Conviction";
        case 2:
            return "Balance";
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
            return "Encoded proposal";
        default:
            return NULL;
        }
    case 3599: /* module 14 call 15 */
        switch (itemIdx) {
        case 0:
            return "Encoded proposal";
        default:
            return NULL;
        }
    case 3600: /* module 14 call 16 */
        switch (itemIdx) {
        case 0:
            return "Encoded proposal";
        default:
            return NULL;
        }
    case 3601: /* module 14 call 17 */
        switch (itemIdx) {
        case 0:
            return "Encoded proposal";
        default:
            return NULL;
        }
    case 3602: /* module 14 call 18 */
        switch (itemIdx) {
        case 0:
            return "Proposal hash";
        case 1:
            return "Proposal len upper bound";
        default:
            return NULL;
        }
    case 3603: /* module 14 call 19 */
        switch (itemIdx) {
        case 0:
            return "Target";
        default:
            return NULL;
        }
    case 3604: /* module 14 call 20 */
        switch (itemIdx) {
        case 0:
            return "Index";
        default:
            return NULL;
        }
    case 3605: /* module 14 call 21 */
        switch (itemIdx) {
        case 0:
            return "Target";
        case 1:
            return "Index";
        default:
            return NULL;
        }
    case 3606: /* module 14 call 22 */
        switch (itemIdx) {
        case 0:
            return "Proposal hash";
        case 1:
            return "Index";
        default:
            return NULL;
        }
    case 3607: /* module 14 call 23 */
        switch (itemIdx) {
        case 0:
            return "Proposal hash";
        case 1:
            return "Maybe ref index";
        default:
            return NULL;
        }
    case 3608: /* module 14 call 24 */
        switch (itemIdx) {
        case 0:
            return "Prop index";
        default:
            return NULL;
        }
    case 3840: /* module 15 call 0 */
        switch (itemIdx) {
        case 0:
            return "New members";
        case 1:
            return "Prime";
        case 2:
            return "Old count";
        default:
            return NULL;
        }
    case 3841: /* module 15 call 1 */
        switch (itemIdx) {
        case 0:
            return "Proposal";
        case 1:
            return "Length bound";
        default:
            return NULL;
        }
    case 3842: /* module 15 call 2 */
        switch (itemIdx) {
        case 0:
            return "Threshold";
        case 1:
            return "Proposal";
        case 2:
            return "Length bound";
        default:
            return NULL;
        }
    case 3843: /* module 15 call 3 */
        switch (itemIdx) {
        case 0:
            return "Proposal";
        case 1:
            return "Index";
        case 2:
            return "Approve";
        default:
            return NULL;
        }
    case 3844: /* module 15 call 4 */
        switch (itemIdx) {
        case 0:
            return "Proposal hash";
        case 1:
            return "Index";
        case 2:
            return "Proposal weight bound";
        case 3:
            return "Length bound";
        default:
            return NULL;
        }
    case 3845: /* module 15 call 5 */
        switch (itemIdx) {
        case 0:
            return "Proposal hash";
        default:
            return NULL;
        }
    case 4096: /* module 16 call 0 */
        switch (itemIdx) {
        case 0:
            return "New members";
        case 1:
            return "Prime";
        case 2:
            return "Old count";
        default:
            return NULL;
        }
    case 4097: /* module 16 call 1 */
        switch (itemIdx) {
        case 0:
            return "Proposal";
        case 1:
            return "Length bound";
        default:
            return NULL;
        }
    case 4098: /* module 16 call 2 */
        switch (itemIdx) {
        case 0:
            return "Threshold";
        case 1:
            return "Proposal";
        case 2:
            return "Length bound";
        default:
            return NULL;
        }
    case 4099: /* module 16 call 3 */
        switch (itemIdx) {
        case 0:
            return "Proposal";
        case 1:
            return "Index";
        case 2:
            return "Approve";
        default:
            return NULL;
        }
    case 4100: /* module 16 call 4 */
        switch (itemIdx) {
        case 0:
            return "Proposal hash";
        case 1:
            return "Index";
        case 2:
            return "Proposal weight bound";
        case 3:
            return "Length bound";
        default:
            return NULL;
        }
    case 4101: /* module 16 call 5 */
        switch (itemIdx) {
        case 0:
            return "Proposal hash";
        default:
            return NULL;
        }
    case 4352: /* module 17 call 0 */
        switch (itemIdx) {
        case 0:
            return "Votes";
        case 1:
            return "Amount";
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
            return "Defunct";
        default:
            return NULL;
        }
    case 4355: /* module 17 call 3 */
        switch (itemIdx) {
        case 0:
            return "Candidate count";
        default:
            return NULL;
        }
    case 4356: /* module 17 call 4 */
        switch (itemIdx) {
        case 0:
            return "Renouncing";
        default:
            return NULL;
        }
    case 4357: /* module 17 call 5 */
        switch (itemIdx) {
        case 0:
            return "Who";
        case 1:
            return "Has replacement";
        default:
            return NULL;
        }
    case 4608: /* module 18 call 0 */
        switch (itemIdx) {
        case 0:
            return "Who";
        default:
            return NULL;
        }
    case 4609: /* module 18 call 1 */
        switch (itemIdx) {
        case 0:
            return "Who";
        default:
            return NULL;
        }
    case 4610: /* module 18 call 2 */
        switch (itemIdx) {
        case 0:
            return "Remove";
        case 1:
            return "Add";
        default:
            return NULL;
        }
    case 4611: /* module 18 call 3 */
        switch (itemIdx) {
        case 0:
            return "Members";
        default:
            return NULL;
        }
    case 4612: /* module 18 call 4 */
        switch (itemIdx) {
        case 0:
            return "New";
        default:
            return NULL;
        }
    case 4613: /* module 18 call 5 */
        switch (itemIdx) {
        case 0:
            return "Who";
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
            return "Amount";
        case 1:
            return "Beneficiary";
        default:
            return NULL;
        }
    case 4865: /* module 19 call 1 */
        switch (itemIdx) {
        case 0:
            return "Proposal id";
        default:
            return NULL;
        }
    case 4866: /* module 19 call 2 */
        switch (itemIdx) {
        case 0:
            return "Proposal id";
        default:
            return NULL;
        }
    case 4867: /* module 19 call 3 */
        switch (itemIdx) {
        case 0:
            return "Reason";
        case 1:
            return "Who";
        default:
            return NULL;
        }
    case 4868: /* module 19 call 4 */
        switch (itemIdx) {
        case 0:
            return "Hash";
        default:
            return NULL;
        }
    case 4869: /* module 19 call 5 */
        switch (itemIdx) {
        case 0:
            return "Reason";
        case 1:
            return "Who";
        case 2:
            return "Tip value";
        default:
            return NULL;
        }
    case 4870: /* module 19 call 6 */
        switch (itemIdx) {
        case 0:
            return "Hash";
        case 1:
            return "Tip value";
        default:
            return NULL;
        }
    case 4871: /* module 19 call 7 */
        switch (itemIdx) {
        case 0:
            return "Hash";
        default:
            return NULL;
        }
    case 4872: /* module 19 call 8 */
        switch (itemIdx) {
        case 0:
            return "Amount";
        case 1:
            return "Description";
        default:
            return NULL;
        }
    case 4873: /* module 19 call 9 */
        switch (itemIdx) {
        case 0:
            return "Bounty id";
        default:
            return NULL;
        }
    case 4874: /* module 19 call 10 */
        switch (itemIdx) {
        case 0:
            return "Bounty id";
        case 1:
            return "Curator";
        case 2:
            return "Fee";
        default:
            return NULL;
        }
    case 4875: /* module 19 call 11 */
        switch (itemIdx) {
        case 0:
            return "Bounty id";
        default:
            return NULL;
        }
    case 4876: /* module 19 call 12 */
        switch (itemIdx) {
        case 0:
            return "Bounty id";
        default:
            return NULL;
        }
    case 4877: /* module 19 call 13 */
        switch (itemIdx) {
        case 0:
            return "Bounty id";
        case 1:
            return "Beneficiary";
        default:
            return NULL;
        }
    case 4878: /* module 19 call 14 */
        switch (itemIdx) {
        case 0:
            return "Bounty id";
        default:
            return NULL;
        }
    case 4879: /* module 19 call 15 */
        switch (itemIdx) {
        case 0:
            return "Bounty id";
        default:
            return NULL;
        }
    case 4880: /* module 19 call 16 */
        switch (itemIdx) {
        case 0:
            return "Bounty id";
        case 1:
            return "Remark";
        default:
            return NULL;
        }
    case 6144: /* module 24 call 0 */
        switch (itemIdx) {
        case 0:
            return "Dest";
        case 1:
            return "Ethereum signature";
        default:
            return NULL;
        }
    case 6145: /* module 24 call 1 */
        switch (itemIdx) {
        case 0:
            return "Who";
        case 1:
            return "Amount";
        case 2:
            return "Vesting schedule";
        case 3:
            return "Statement";
        default:
            return NULL;
        }
    case 6146: /* module 24 call 2 */
        switch (itemIdx) {
        case 0:
            return "Dest";
        case 1:
            return "Ethereum signature";
        case 2:
            return "Statement";
        default:
            return NULL;
        }
    case 6147: /* module 24 call 3 */
        switch (itemIdx) {
        case 0:
            return "Statement";
        default:
            return NULL;
        }
    case 6148: /* module 24 call 4 */
        switch (itemIdx) {
        case 0:
            return "Old";
        case 1:
            return "New";
        case 2:
            return "Maybe preclaim";
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
            return "Target";
        default:
            return NULL;
        }
    case 6402: /* module 25 call 2 */
        switch (itemIdx) {
        case 0:
            return "Target";
        case 1:
            return "Schedule";
        default:
            return NULL;
        }
    case 6403: /* module 25 call 3 */
        switch (itemIdx) {
        case 0:
            return "Source";
        case 1:
            return "Target";
        case 2:
            return "Schedule";
        default:
            return NULL;
        }
    case 6656: /* module 26 call 0 */
        switch (itemIdx) {
        case 0:
            return "Calls";
        default:
            return NULL;
        }
    case 6657: /* module 26 call 1 */
        switch (itemIdx) {
        case 0:
            return "Index";
        case 1:
            return "Call";
        default:
            return NULL;
        }
    case 6658: /* module 26 call 2 */
        switch (itemIdx) {
        case 0:
            return "Calls";
        default:
            return NULL;
        }
    case 7168: /* module 28 call 0 */
        switch (itemIdx) {
        case 0:
            return "Account";
        default:
            return NULL;
        }
    case 7169: /* module 28 call 1 */
        switch (itemIdx) {
        case 0:
            return "Info";
        default:
            return NULL;
        }
    case 7170: /* module 28 call 2 */
        switch (itemIdx) {
        case 0:
            return "Subs";
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
            return "Reg index";
        case 1:
            return "Max fee";
        default:
            return NULL;
        }
    case 7173: /* module 28 call 5 */
        switch (itemIdx) {
        case 0:
            return "Reg index";
        default:
            return NULL;
        }
    case 7174: /* module 28 call 6 */
        switch (itemIdx) {
        case 0:
            return "Index";
        case 1:
            return "Fee";
        default:
            return NULL;
        }
    case 7175: /* module 28 call 7 */
        switch (itemIdx) {
        case 0:
            return "Index";
        case 1:
            return "New";
        default:
            return NULL;
        }
    case 7176: /* module 28 call 8 */
        switch (itemIdx) {
        case 0:
            return "Index";
        case 1:
            return "Fields";
        default:
            return NULL;
        }
    case 7177: /* module 28 call 9 */
        switch (itemIdx) {
        case 0:
            return "Reg index";
        case 1:
            return "Target";
        case 2:
            return "Judgement";
        default:
            return NULL;
        }
    case 7178: /* module 28 call 10 */
        switch (itemIdx) {
        case 0:
            return "Target";
        default:
            return NULL;
        }
    case 7179: /* module 28 call 11 */
        switch (itemIdx) {
        case 0:
            return "Sub";
        case 1:
            return "Data";
        default:
            return NULL;
        }
    case 7180: /* module 28 call 12 */
        switch (itemIdx) {
        case 0:
            return "Sub";
        case 1:
            return "Data";
        default:
            return NULL;
        }
    case 7181: /* module 28 call 13 */
        switch (itemIdx) {
        case 0:
            return "Sub";
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
            return "Real";
        case 1:
            return "Force proxy type";
        case 2:
            return "Call";
        default:
            return NULL;
        }
    case 7425: /* module 29 call 1 */
        switch (itemIdx) {
        case 0:
            return "Delegate";
        case 1:
            return "Proxy type";
        case 2:
            return "Delay";
        default:
            return NULL;
        }
    case 7426: /* module 29 call 2 */
        switch (itemIdx) {
        case 0:
            return "Delegate";
        case 1:
            return "Proxy type";
        case 2:
            return "Delay";
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
            return "Proxy type";
        case 1:
            return "Delay";
        case 2:
            return "Index";
        default:
            return NULL;
        }
    case 7429: /* module 29 call 5 */
        switch (itemIdx) {
        case 0:
            return "Spawner";
        case 1:
            return "Proxy type";
        case 2:
            return "Index";
        case 3:
            return "Height";
        case 4:
            return "Ext index";
        default:
            return NULL;
        }
    case 7430: /* module 29 call 6 */
        switch (itemIdx) {
        case 0:
            return "Real";
        case 1:
            return "Call hash";
        default:
            return NULL;
        }
    case 7431: /* module 29 call 7 */
        switch (itemIdx) {
        case 0:
            return "Real";
        case 1:
            return "Call hash";
        default:
            return NULL;
        }
    case 7432: /* module 29 call 8 */
        switch (itemIdx) {
        case 0:
            return "Delegate";
        case 1:
            return "Call hash";
        default:
            return NULL;
        }
    case 7433: /* module 29 call 9 */
        switch (itemIdx) {
        case 0:
            return "Delegate";
        case 1:
            return "Real";
        case 2:
            return "Force proxy type";
        case 3:
            return "Call";
        default:
            return NULL;
        }
    case 7680: /* module 30 call 0 */
        switch (itemIdx) {
        case 0:
            return "Other signatories";
        case 1:
            return "Call";
        default:
            return NULL;
        }
    case 7681: /* module 30 call 1 */
        switch (itemIdx) {
        case 0:
            return "Threshold";
        case 1:
            return "Other signatories";
        case 2:
            return "Maybe timepoint";
        case 3:
            return "Call";
        case 4:
            return "Store call";
        case 5:
            return "Max weight";
        default:
            return NULL;
        }
    case 7682: /* module 30 call 2 */
        switch (itemIdx) {
        case 0:
            return "Threshold";
        case 1:
            return "Other signatories";
        case 2:
            return "Maybe timepoint";
        case 3:
            return "Call hash";
        case 4:
            return "Max weight";
        default:
            return NULL;
        }
    case 7683: /* module 30 call 3 */
        switch (itemIdx) {
        case 0:
            return "Threshold";
        case 1:
            return "Other signatories";
        case 2:
            return "Timepoint";
        case 3:
            return "Call hash";
        default:
            return NULL;
        }
    default:
        return NULL;
    }

    return NULL;
}

parser_error_t _getMethod_ItemValue_V5(
    pd_Method_V5_t* m,
    uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx,
    char* outValue, uint16_t outValueLen,
    uint8_t pageIdx, uint8_t* pageCount)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 0: /* module 0 call 0 */
        switch (itemIdx) {
        case 0: /* system_fill_block_V5 - _ratio */;
            return _toStringPerbill_V5(
                &m->basic.system_fill_block_V5._ratio,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1: /* module 0 call 1 */
        switch (itemIdx) {
        case 0: /* system_remark_V5 - _remark */;
            return _toStringBytes(
                &m->basic.system_remark_V5._remark,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2: /* module 0 call 2 */
        switch (itemIdx) {
        case 0: /* system_set_heap_pages_V5 - pages */;
            return _toStringu64(
                &m->basic.system_set_heap_pages_V5.pages,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3: /* module 0 call 3 */
        switch (itemIdx) {
        case 0: /* system_set_code_V5 - code */;
            return _toStringBytes(
                &m->basic.system_set_code_V5.code,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4: /* module 0 call 4 */
        switch (itemIdx) {
        case 0: /* system_set_code_without_checks_V5 - code */;
            return _toStringBytes(
                &m->basic.system_set_code_without_checks_V5.code,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5: /* module 0 call 5 */
        switch (itemIdx) {
        case 0: /* system_set_changes_trie_config_V5 - changes_trie_config */;
            return _toStringOptionChangesTrieConfiguration_V5(
                &m->basic.system_set_changes_trie_config_V5.changes_trie_config,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6: /* module 0 call 6 */
        switch (itemIdx) {
        case 0: /* system_set_storage_V5 - items */;
            return _toStringVecKeyValue_V5(
                &m->basic.system_set_storage_V5.items,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7: /* module 0 call 7 */
        switch (itemIdx) {
        case 0: /* system_kill_storage_V5 - keys */;
            return _toStringVecKey_V5(
                &m->basic.system_kill_storage_V5.keys,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8: /* module 0 call 8 */
        switch (itemIdx) {
        case 0: /* system_kill_prefix_V5 - prefix */;
            return _toStringKey_V5(
                &m->basic.system_kill_prefix_V5.prefix,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* system_kill_prefix_V5 - _subkeys */;
            return _toStringu32(
                &m->basic.system_kill_prefix_V5._subkeys,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9: /* module 0 call 9 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 256: /* module 1 call 0 */
        switch (itemIdx) {
        case 0: /* scheduler_schedule_V5 - when */;
            return _toStringBlockNumber(
                &m->basic.scheduler_schedule_V5.when,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* scheduler_schedule_V5 - maybe_periodic */;
            return _toStringOptionPeriod_V5(
                &m->basic.scheduler_schedule_V5.maybe_periodic,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* scheduler_schedule_V5 - priority */;
            return _toStringPriority_V5(
                &m->basic.scheduler_schedule_V5.priority,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* scheduler_schedule_V5 - call */;
            return _toStringCall_V5(
                &m->basic.scheduler_schedule_V5.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 257: /* module 1 call 1 */
        switch (itemIdx) {
        case 0: /* scheduler_cancel_V5 - when */;
            return _toStringBlockNumber(
                &m->basic.scheduler_cancel_V5.when,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* scheduler_cancel_V5 - index */;
            return _toStringu32(
                &m->basic.scheduler_cancel_V5.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 258: /* module 1 call 2 */
        switch (itemIdx) {
        case 0: /* scheduler_schedule_named_V5 - id */;
            return _toStringBytes(
                &m->basic.scheduler_schedule_named_V5.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* scheduler_schedule_named_V5 - when */;
            return _toStringBlockNumber(
                &m->basic.scheduler_schedule_named_V5.when,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* scheduler_schedule_named_V5 - maybe_periodic */;
            return _toStringOptionPeriod_V5(
                &m->basic.scheduler_schedule_named_V5.maybe_periodic,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* scheduler_schedule_named_V5 - priority */;
            return _toStringPriority_V5(
                &m->basic.scheduler_schedule_named_V5.priority,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* scheduler_schedule_named_V5 - call */;
            return _toStringCall_V5(
                &m->basic.scheduler_schedule_named_V5.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 259: /* module 1 call 3 */
        switch (itemIdx) {
        case 0: /* scheduler_cancel_named_V5 - id */;
            return _toStringBytes(
                &m->basic.scheduler_cancel_named_V5.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 260: /* module 1 call 4 */
        switch (itemIdx) {
        case 0: /* scheduler_schedule_after_V5 - after */;
            return _toStringBlockNumber(
                &m->basic.scheduler_schedule_after_V5.after,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* scheduler_schedule_after_V5 - maybe_periodic */;
            return _toStringOptionPeriod_V5(
                &m->basic.scheduler_schedule_after_V5.maybe_periodic,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* scheduler_schedule_after_V5 - priority */;
            return _toStringPriority_V5(
                &m->basic.scheduler_schedule_after_V5.priority,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* scheduler_schedule_after_V5 - call */;
            return _toStringCall_V5(
                &m->basic.scheduler_schedule_after_V5.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 261: /* module 1 call 5 */
        switch (itemIdx) {
        case 0: /* scheduler_schedule_named_after_V5 - id */;
            return _toStringBytes(
                &m->basic.scheduler_schedule_named_after_V5.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* scheduler_schedule_named_after_V5 - after */;
            return _toStringBlockNumber(
                &m->basic.scheduler_schedule_named_after_V5.after,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* scheduler_schedule_named_after_V5 - maybe_periodic */;
            return _toStringOptionPeriod_V5(
                &m->basic.scheduler_schedule_named_after_V5.maybe_periodic,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* scheduler_schedule_named_after_V5 - priority */;
            return _toStringPriority_V5(
                &m->basic.scheduler_schedule_named_after_V5.priority,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* scheduler_schedule_named_after_V5 - call */;
            return _toStringCall_V5(
                &m->basic.scheduler_schedule_named_after_V5.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 512: /* module 2 call 0 */
        switch (itemIdx) {
        case 0: /* babe_report_equivocation_V5 - equivocation_proof */;
            return _toStringEquivocationProof_V5(
                &m->basic.babe_report_equivocation_V5.equivocation_proof,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* babe_report_equivocation_V5 - key_owner_proof */;
            return _toStringKeyOwnerProof_V5(
                &m->basic.babe_report_equivocation_V5.key_owner_proof,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 513: /* module 2 call 1 */
        switch (itemIdx) {
        case 0: /* babe_report_equivocation_unsigned_V5 - equivocation_proof */;
            return _toStringEquivocationProof_V5(
                &m->basic.babe_report_equivocation_unsigned_V5.equivocation_proof,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* babe_report_equivocation_unsigned_V5 - key_owner_proof */;
            return _toStringKeyOwnerProof_V5(
                &m->basic.babe_report_equivocation_unsigned_V5.key_owner_proof,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 768: /* module 3 call 0 */
        switch (itemIdx) {
        case 0: /* timestamp_set_V5 - now */;
            return _toStringCompactMoment_V5(
                &m->basic.timestamp_set_V5.now,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1024: /* module 4 call 0 */
        switch (itemIdx) {
        case 0: /* indices_claim_V5 - index */;
            return _toStringAccountIndex_V5(
                &m->basic.indices_claim_V5.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1025: /* module 4 call 1 */
        switch (itemIdx) {
        case 0: /* indices_transfer_V5 - new_ */;
            return _toStringAccountId_V5(
                &m->basic.indices_transfer_V5.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* indices_transfer_V5 - index */;
            return _toStringAccountIndex_V5(
                &m->basic.indices_transfer_V5.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1026: /* module 4 call 2 */
        switch (itemIdx) {
        case 0: /* indices_free_V5 - index */;
            return _toStringAccountIndex_V5(
                &m->basic.indices_free_V5.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1027: /* module 4 call 3 */
        switch (itemIdx) {
        case 0: /* indices_force_transfer_V5 - new_ */;
            return _toStringAccountId_V5(
                &m->basic.indices_force_transfer_V5.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* indices_force_transfer_V5 - index */;
            return _toStringAccountIndex_V5(
                &m->basic.indices_force_transfer_V5.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* indices_force_transfer_V5 - freeze */;
            return _toStringbool(
                &m->basic.indices_force_transfer_V5.freeze,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1028: /* module 4 call 4 */
        switch (itemIdx) {
        case 0: /* indices_freeze_V5 - index */;
            return _toStringAccountIndex_V5(
                &m->basic.indices_freeze_V5.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1280: /* module 5 call 0 */
        switch (itemIdx) {
        case 0: /* balances_transfer_V5 - dest */;
            return _toStringLookupSource(
                &m->basic.balances_transfer_V5.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_transfer_V5 - value */;
            return _toStringCompactBalance(
                &m->basic.balances_transfer_V5.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1281: /* module 5 call 1 */
        switch (itemIdx) {
        case 0: /* balances_set_balance_V5 - who */;
            return _toStringLookupSource(
                &m->basic.balances_set_balance_V5.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_set_balance_V5 - new_free */;
            return _toStringCompactBalance(
                &m->basic.balances_set_balance_V5.new_free,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* balances_set_balance_V5 - new_reserved */;
            return _toStringCompactBalance(
                &m->basic.balances_set_balance_V5.new_reserved,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1282: /* module 5 call 2 */
        switch (itemIdx) {
        case 0: /* balances_force_transfer_V5 - source */;
            return _toStringLookupSource(
                &m->basic.balances_force_transfer_V5.source,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_force_transfer_V5 - dest */;
            return _toStringLookupSource(
                &m->basic.balances_force_transfer_V5.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* balances_force_transfer_V5 - value */;
            return _toStringCompactBalance(
                &m->basic.balances_force_transfer_V5.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1283: /* module 5 call 3 */
        switch (itemIdx) {
        case 0: /* balances_transfer_keep_alive_V5 - dest */;
            return _toStringLookupSource(
                &m->basic.balances_transfer_keep_alive_V5.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_transfer_keep_alive_V5 - value */;
            return _toStringCompactBalance(
                &m->basic.balances_transfer_keep_alive_V5.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1536: /* module 6 call 0 */
        switch (itemIdx) {
        case 0: /* authorship_set_uncles_V5 - new_uncles */;
            return _toStringVecHeader(
                &m->basic.authorship_set_uncles_V5.new_uncles,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1792: /* module 7 call 0 */
        switch (itemIdx) {
        case 0: /* staking_bond_V5 - controller */;
            return _toStringLookupSource(
                &m->basic.staking_bond_V5.controller,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_bond_V5 - value */;
            return _toStringCompactBalanceOf(
                &m->basic.staking_bond_V5.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* staking_bond_V5 - payee */;
            return _toStringRewardDestination_V5(
                &m->basic.staking_bond_V5.payee,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1793: /* module 7 call 1 */
        switch (itemIdx) {
        case 0: /* staking_bond_extra_V5 - max_additional */;
            return _toStringCompactBalanceOf(
                &m->basic.staking_bond_extra_V5.max_additional,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1794: /* module 7 call 2 */
        switch (itemIdx) {
        case 0: /* staking_unbond_V5 - value */;
            return _toStringCompactBalanceOf(
                &m->basic.staking_unbond_V5.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1795: /* module 7 call 3 */
        switch (itemIdx) {
        case 0: /* staking_withdraw_unbonded_V5 - num_slashing_spans */;
            return _toStringu32(
                &m->basic.staking_withdraw_unbonded_V5.num_slashing_spans,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1796: /* module 7 call 4 */
        switch (itemIdx) {
        case 0: /* staking_validate_V5 - prefs */;
            return _toStringValidatorPrefs_V5(
                &m->basic.staking_validate_V5.prefs,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1797: /* module 7 call 5 */
        switch (itemIdx) {
        case 0: /* staking_nominate_V5 - targets */;
            return _toStringVecLookupSource(
                &m->basic.staking_nominate_V5.targets,
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
        case 0: /* staking_set_payee_V5 - payee */;
            return _toStringRewardDestination_V5(
                &m->basic.staking_set_payee_V5.payee,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1800: /* module 7 call 8 */
        switch (itemIdx) {
        case 0: /* staking_set_controller_V5 - controller */;
            return _toStringLookupSource(
                &m->basic.staking_set_controller_V5.controller,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1801: /* module 7 call 9 */
        switch (itemIdx) {
        case 0: /* staking_set_validator_count_V5 - new_ */;
            return _toStringCompactu32(
                &m->basic.staking_set_validator_count_V5.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1802: /* module 7 call 10 */
        switch (itemIdx) {
        case 0: /* staking_increase_validator_count_V5 - additional */;
            return _toStringCompactu32(
                &m->basic.staking_increase_validator_count_V5.additional,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1803: /* module 7 call 11 */
        switch (itemIdx) {
        case 0: /* staking_scale_validator_count_V5 - factor */;
            return _toStringPercent_V5(
                &m->basic.staking_scale_validator_count_V5.factor,
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
        case 0: /* staking_set_invulnerables_V5 - invulnerables */;
            return _toStringVecAccountId_V5(
                &m->basic.staking_set_invulnerables_V5.invulnerables,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1807: /* module 7 call 15 */
        switch (itemIdx) {
        case 0: /* staking_force_unstake_V5 - stash */;
            return _toStringAccountId_V5(
                &m->basic.staking_force_unstake_V5.stash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_force_unstake_V5 - num_slashing_spans */;
            return _toStringu32(
                &m->basic.staking_force_unstake_V5.num_slashing_spans,
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
        case 0: /* staking_cancel_deferred_slash_V5 - era */;
            return _toStringEraIndex_V5(
                &m->basic.staking_cancel_deferred_slash_V5.era,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_cancel_deferred_slash_V5 - slash_indices */;
            return _toStringVecu32(
                &m->basic.staking_cancel_deferred_slash_V5.slash_indices,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1810: /* module 7 call 18 */
        switch (itemIdx) {
        case 0: /* staking_payout_stakers_V5 - validator_stash */;
            return _toStringAccountId_V5(
                &m->basic.staking_payout_stakers_V5.validator_stash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_payout_stakers_V5 - era */;
            return _toStringEraIndex_V5(
                &m->basic.staking_payout_stakers_V5.era,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1811: /* module 7 call 19 */
        switch (itemIdx) {
        case 0: /* staking_rebond_V5 - value */;
            return _toStringCompactBalanceOf(
                &m->basic.staking_rebond_V5.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1812: /* module 7 call 20 */
        switch (itemIdx) {
        case 0: /* staking_set_history_depth_V5 - new_history_depth */;
            return _toStringCompactEraIndex_V5(
                &m->basic.staking_set_history_depth_V5.new_history_depth,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_set_history_depth_V5 - _era_items_deleted */;
            return _toStringCompactu32(
                &m->basic.staking_set_history_depth_V5._era_items_deleted,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1813: /* module 7 call 21 */
        switch (itemIdx) {
        case 0: /* staking_reap_stash_V5 - stash */;
            return _toStringAccountId_V5(
                &m->basic.staking_reap_stash_V5.stash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_reap_stash_V5 - num_slashing_spans */;
            return _toStringu32(
                &m->basic.staking_reap_stash_V5.num_slashing_spans,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1814: /* module 7 call 22 */
        switch (itemIdx) {
        case 0: /* staking_submit_election_solution_V5 - winners */;
            return _toStringVecValidatorIndex_V5(
                &m->basic.staking_submit_election_solution_V5.winners,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_submit_election_solution_V5 - compact */;
            return _toStringCompactAssignments_V5(
                &m->basic.staking_submit_election_solution_V5.compact,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* staking_submit_election_solution_V5 - score */;
            return _toStringElectionScore_V5(
                &m->basic.staking_submit_election_solution_V5.score,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* staking_submit_election_solution_V5 - era */;
            return _toStringEraIndex_V5(
                &m->basic.staking_submit_election_solution_V5.era,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* staking_submit_election_solution_V5 - size */;
            return _toStringElectionSize_V5(
                &m->basic.staking_submit_election_solution_V5.size,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1815: /* module 7 call 23 */
        switch (itemIdx) {
        case 0: /* staking_submit_election_solution_unsigned_V5 - winners */;
            return _toStringVecValidatorIndex_V5(
                &m->basic.staking_submit_election_solution_unsigned_V5.winners,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_submit_election_solution_unsigned_V5 - compact */;
            return _toStringCompactAssignments_V5(
                &m->basic.staking_submit_election_solution_unsigned_V5.compact,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* staking_submit_election_solution_unsigned_V5 - score */;
            return _toStringElectionScore_V5(
                &m->basic.staking_submit_election_solution_unsigned_V5.score,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* staking_submit_election_solution_unsigned_V5 - era */;
            return _toStringEraIndex_V5(
                &m->basic.staking_submit_election_solution_unsigned_V5.era,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* staking_submit_election_solution_unsigned_V5 - size */;
            return _toStringElectionSize_V5(
                &m->basic.staking_submit_election_solution_unsigned_V5.size,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2304: /* module 9 call 0 */
        switch (itemIdx) {
        case 0: /* session_set_keys_V5 - keys */;
            return _toStringKeys_V5(
                &m->basic.session_set_keys_V5.keys,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* session_set_keys_V5 - proof */;
            return _toStringBytes(
                &m->basic.session_set_keys_V5.proof,
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
    case 2816: /* module 11 call 0 */
        switch (itemIdx) {
        case 0: /* grandpa_report_equivocation_V5 - equivocation_proof */;
            return _toStringEquivocationProof_V5(
                &m->basic.grandpa_report_equivocation_V5.equivocation_proof,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* grandpa_report_equivocation_V5 - key_owner_proof */;
            return _toStringKeyOwnerProof_V5(
                &m->basic.grandpa_report_equivocation_V5.key_owner_proof,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2817: /* module 11 call 1 */
        switch (itemIdx) {
        case 0: /* grandpa_report_equivocation_unsigned_V5 - equivocation_proof */;
            return _toStringEquivocationProof_V5(
                &m->basic.grandpa_report_equivocation_unsigned_V5.equivocation_proof,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* grandpa_report_equivocation_unsigned_V5 - key_owner_proof */;
            return _toStringKeyOwnerProof_V5(
                &m->basic.grandpa_report_equivocation_unsigned_V5.key_owner_proof,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2818: /* module 11 call 2 */
        switch (itemIdx) {
        case 0: /* grandpa_note_stalled_V5 - delay */;
            return _toStringBlockNumber(
                &m->basic.grandpa_note_stalled_V5.delay,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* grandpa_note_stalled_V5 - best_finalized_block_number */;
            return _toStringBlockNumber(
                &m->basic.grandpa_note_stalled_V5.best_finalized_block_number,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3072: /* module 12 call 0 */
        switch (itemIdx) {
        case 0: /* imonline_heartbeat_V5 - heartbeat */;
            return _toStringHeartbeat(
                &m->basic.imonline_heartbeat_V5.heartbeat,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* imonline_heartbeat_V5 - _signature */;
            return _toStringSignature_V5(
                &m->basic.imonline_heartbeat_V5._signature,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3584: /* module 14 call 0 */
        switch (itemIdx) {
        case 0: /* democracy_propose_V5 - proposal_hash */;
            return _toStringHash(
                &m->basic.democracy_propose_V5.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* democracy_propose_V5 - value */;
            return _toStringCompactBalanceOf(
                &m->basic.democracy_propose_V5.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3585: /* module 14 call 1 */
        switch (itemIdx) {
        case 0: /* democracy_second_V5 - proposal */;
            return _toStringCompactPropIndex_V5(
                &m->basic.democracy_second_V5.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* democracy_second_V5 - seconds_upper_bound */;
            return _toStringCompactu32(
                &m->basic.democracy_second_V5.seconds_upper_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3586: /* module 14 call 2 */
        switch (itemIdx) {
        case 0: /* democracy_vote_V5 - ref_index */;
            return _toStringCompactReferendumIndex_V5(
                &m->basic.democracy_vote_V5.ref_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* democracy_vote_V5 - vote */;
            return _toStringAccountVote_V5(
                &m->basic.democracy_vote_V5.vote,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3587: /* module 14 call 3 */
        switch (itemIdx) {
        case 0: /* democracy_emergency_cancel_V5 - ref_index */;
            return _toStringReferendumIndex_V5(
                &m->basic.democracy_emergency_cancel_V5.ref_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3588: /* module 14 call 4 */
        switch (itemIdx) {
        case 0: /* democracy_external_propose_V5 - proposal_hash */;
            return _toStringHash(
                &m->basic.democracy_external_propose_V5.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3589: /* module 14 call 5 */
        switch (itemIdx) {
        case 0: /* democracy_external_propose_majority_V5 - proposal_hash */;
            return _toStringHash(
                &m->basic.democracy_external_propose_majority_V5.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3590: /* module 14 call 6 */
        switch (itemIdx) {
        case 0: /* democracy_external_propose_default_V5 - proposal_hash */;
            return _toStringHash(
                &m->basic.democracy_external_propose_default_V5.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3591: /* module 14 call 7 */
        switch (itemIdx) {
        case 0: /* democracy_fast_track_V5 - proposal_hash */;
            return _toStringHash(
                &m->basic.democracy_fast_track_V5.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* democracy_fast_track_V5 - voting_period */;
            return _toStringBlockNumber(
                &m->basic.democracy_fast_track_V5.voting_period,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* democracy_fast_track_V5 - delay */;
            return _toStringBlockNumber(
                &m->basic.democracy_fast_track_V5.delay,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3592: /* module 14 call 8 */
        switch (itemIdx) {
        case 0: /* democracy_veto_external_V5 - proposal_hash */;
            return _toStringHash(
                &m->basic.democracy_veto_external_V5.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3593: /* module 14 call 9 */
        switch (itemIdx) {
        case 0: /* democracy_cancel_referendum_V5 - ref_index */;
            return _toStringCompactReferendumIndex_V5(
                &m->basic.democracy_cancel_referendum_V5.ref_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3594: /* module 14 call 10 */
        switch (itemIdx) {
        case 0: /* democracy_cancel_queued_V5 - which */;
            return _toStringReferendumIndex_V5(
                &m->basic.democracy_cancel_queued_V5.which,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3595: /* module 14 call 11 */
        switch (itemIdx) {
        case 0: /* democracy_delegate_V5 - to */;
            return _toStringAccountId_V5(
                &m->basic.democracy_delegate_V5.to,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* democracy_delegate_V5 - conviction */;
            return _toStringConviction_V5(
                &m->basic.democracy_delegate_V5.conviction,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* democracy_delegate_V5 - balance */;
            return _toStringBalanceOf_V5(
                &m->basic.democracy_delegate_V5.balance,
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
        case 0: /* democracy_note_preimage_V5 - encoded_proposal */;
            return _toStringBytes(
                &m->basic.democracy_note_preimage_V5.encoded_proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3599: /* module 14 call 15 */
        switch (itemIdx) {
        case 0: /* democracy_note_preimage_operational_V5 - encoded_proposal */;
            return _toStringBytes(
                &m->basic.democracy_note_preimage_operational_V5.encoded_proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3600: /* module 14 call 16 */
        switch (itemIdx) {
        case 0: /* democracy_note_imminent_preimage_V5 - encoded_proposal */;
            return _toStringBytes(
                &m->basic.democracy_note_imminent_preimage_V5.encoded_proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3601: /* module 14 call 17 */
        switch (itemIdx) {
        case 0: /* democracy_note_imminent_preimage_operational_V5 - encoded_proposal */;
            return _toStringBytes(
                &m->basic.democracy_note_imminent_preimage_operational_V5.encoded_proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3602: /* module 14 call 18 */
        switch (itemIdx) {
        case 0: /* democracy_reap_preimage_V5 - proposal_hash */;
            return _toStringHash(
                &m->basic.democracy_reap_preimage_V5.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* democracy_reap_preimage_V5 - proposal_len_upper_bound */;
            return _toStringCompactu32(
                &m->basic.democracy_reap_preimage_V5.proposal_len_upper_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3603: /* module 14 call 19 */
        switch (itemIdx) {
        case 0: /* democracy_unlock_V5 - target */;
            return _toStringAccountId_V5(
                &m->basic.democracy_unlock_V5.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3604: /* module 14 call 20 */
        switch (itemIdx) {
        case 0: /* democracy_remove_vote_V5 - index */;
            return _toStringReferendumIndex_V5(
                &m->basic.democracy_remove_vote_V5.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3605: /* module 14 call 21 */
        switch (itemIdx) {
        case 0: /* democracy_remove_other_vote_V5 - target */;
            return _toStringAccountId_V5(
                &m->basic.democracy_remove_other_vote_V5.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* democracy_remove_other_vote_V5 - index */;
            return _toStringReferendumIndex_V5(
                &m->basic.democracy_remove_other_vote_V5.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3606: /* module 14 call 22 */
        switch (itemIdx) {
        case 0: /* democracy_enact_proposal_V5 - proposal_hash */;
            return _toStringHash(
                &m->basic.democracy_enact_proposal_V5.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* democracy_enact_proposal_V5 - index */;
            return _toStringReferendumIndex_V5(
                &m->basic.democracy_enact_proposal_V5.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3607: /* module 14 call 23 */
        switch (itemIdx) {
        case 0: /* democracy_blacklist_V5 - proposal_hash */;
            return _toStringHash(
                &m->basic.democracy_blacklist_V5.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* democracy_blacklist_V5 - maybe_ref_index */;
            return _toStringOptionReferendumIndex_V5(
                &m->basic.democracy_blacklist_V5.maybe_ref_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3608: /* module 14 call 24 */
        switch (itemIdx) {
        case 0: /* democracy_cancel_proposal_V5 - prop_index */;
            return _toStringCompactPropIndex_V5(
                &m->basic.democracy_cancel_proposal_V5.prop_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3840: /* module 15 call 0 */
        switch (itemIdx) {
        case 0: /* council_set_members_V5 - new_members */;
            return _toStringVecAccountId_V5(
                &m->basic.council_set_members_V5.new_members,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* council_set_members_V5 - prime */;
            return _toStringOptionAccountId_V5(
                &m->basic.council_set_members_V5.prime,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* council_set_members_V5 - old_count */;
            return _toStringMemberCount_V5(
                &m->basic.council_set_members_V5.old_count,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3841: /* module 15 call 1 */
        switch (itemIdx) {
        case 0: /* council_execute_V5 - proposal */;
            return _toStringProposal_V5(
                &m->nested.council_execute_V5.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* council_execute_V5 - length_bound */;
            return _toStringCompactu32(
                &m->nested.council_execute_V5.length_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3842: /* module 15 call 2 */
        switch (itemIdx) {
        case 0: /* council_propose_V5 - threshold */;
            return _toStringCompactMemberCount_V5(
                &m->nested.council_propose_V5.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* council_propose_V5 - proposal */;
            return _toStringProposal_V5(
                &m->nested.council_propose_V5.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* council_propose_V5 - length_bound */;
            return _toStringCompactu32(
                &m->nested.council_propose_V5.length_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3843: /* module 15 call 3 */
        switch (itemIdx) {
        case 0: /* council_vote_V5 - proposal */;
            return _toStringHash(
                &m->basic.council_vote_V5.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* council_vote_V5 - index */;
            return _toStringCompactProposalIndex_V5(
                &m->basic.council_vote_V5.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* council_vote_V5 - approve */;
            return _toStringbool(
                &m->basic.council_vote_V5.approve,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3844: /* module 15 call 4 */
        switch (itemIdx) {
        case 0: /* council_close_V5 - proposal_hash */;
            return _toStringHash(
                &m->basic.council_close_V5.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* council_close_V5 - index */;
            return _toStringCompactProposalIndex_V5(
                &m->basic.council_close_V5.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* council_close_V5 - proposal_weight_bound */;
            return _toStringCompactWeight_V5(
                &m->basic.council_close_V5.proposal_weight_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* council_close_V5 - length_bound */;
            return _toStringCompactu32(
                &m->basic.council_close_V5.length_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3845: /* module 15 call 5 */
        switch (itemIdx) {
        case 0: /* council_disapprove_proposal_V5 - proposal_hash */;
            return _toStringHash(
                &m->basic.council_disapprove_proposal_V5.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4096: /* module 16 call 0 */
        switch (itemIdx) {
        case 0: /* technicalcommittee_set_members_V5 - new_members */;
            return _toStringVecAccountId_V5(
                &m->basic.technicalcommittee_set_members_V5.new_members,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* technicalcommittee_set_members_V5 - prime */;
            return _toStringOptionAccountId_V5(
                &m->basic.technicalcommittee_set_members_V5.prime,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* technicalcommittee_set_members_V5 - old_count */;
            return _toStringMemberCount_V5(
                &m->basic.technicalcommittee_set_members_V5.old_count,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4097: /* module 16 call 1 */
        switch (itemIdx) {
        case 0: /* technicalcommittee_execute_V5 - proposal */;
            return _toStringProposal_V5(
                &m->nested.technicalcommittee_execute_V5.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* technicalcommittee_execute_V5 - length_bound */;
            return _toStringCompactu32(
                &m->nested.technicalcommittee_execute_V5.length_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4098: /* module 16 call 2 */
        switch (itemIdx) {
        case 0: /* technicalcommittee_propose_V5 - threshold */;
            return _toStringCompactMemberCount_V5(
                &m->nested.technicalcommittee_propose_V5.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* technicalcommittee_propose_V5 - proposal */;
            return _toStringProposal_V5(
                &m->nested.technicalcommittee_propose_V5.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* technicalcommittee_propose_V5 - length_bound */;
            return _toStringCompactu32(
                &m->nested.technicalcommittee_propose_V5.length_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4099: /* module 16 call 3 */
        switch (itemIdx) {
        case 0: /* technicalcommittee_vote_V5 - proposal */;
            return _toStringHash(
                &m->basic.technicalcommittee_vote_V5.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* technicalcommittee_vote_V5 - index */;
            return _toStringCompactProposalIndex_V5(
                &m->basic.technicalcommittee_vote_V5.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* technicalcommittee_vote_V5 - approve */;
            return _toStringbool(
                &m->basic.technicalcommittee_vote_V5.approve,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4100: /* module 16 call 4 */
        switch (itemIdx) {
        case 0: /* technicalcommittee_close_V5 - proposal_hash */;
            return _toStringHash(
                &m->basic.technicalcommittee_close_V5.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* technicalcommittee_close_V5 - index */;
            return _toStringCompactProposalIndex_V5(
                &m->basic.technicalcommittee_close_V5.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* technicalcommittee_close_V5 - proposal_weight_bound */;
            return _toStringCompactWeight_V5(
                &m->basic.technicalcommittee_close_V5.proposal_weight_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* technicalcommittee_close_V5 - length_bound */;
            return _toStringCompactu32(
                &m->basic.technicalcommittee_close_V5.length_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4101: /* module 16 call 5 */
        switch (itemIdx) {
        case 0: /* technicalcommittee_disapprove_proposal_V5 - proposal_hash */;
            return _toStringHash(
                &m->basic.technicalcommittee_disapprove_proposal_V5.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4352: /* module 17 call 0 */
        switch (itemIdx) {
        case 0: /* electionsphragmen_vote_V5 - votes */;
            return _toStringVecAccountId_V5(
                &m->basic.electionsphragmen_vote_V5.votes,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* electionsphragmen_vote_V5 - value */;
            return _toStringCompactBalanceOf(
                &m->basic.electionsphragmen_vote_V5.value,
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
        case 0: /* electionsphragmen_report_defunct_voter_V5 - defunct */;
            return _toStringDefunctVoter_V5(
                &m->basic.electionsphragmen_report_defunct_voter_V5.defunct,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4355: /* module 17 call 3 */
        switch (itemIdx) {
        case 0: /* electionsphragmen_submit_candidacy_V5 - candidate_count */;
            return _toStringCompactu32(
                &m->basic.electionsphragmen_submit_candidacy_V5.candidate_count,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4356: /* module 17 call 4 */
        switch (itemIdx) {
        case 0: /* electionsphragmen_renounce_candidacy_V5 - renouncing */;
            return _toStringRenouncing_V5(
                &m->basic.electionsphragmen_renounce_candidacy_V5.renouncing,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4357: /* module 17 call 5 */
        switch (itemIdx) {
        case 0: /* electionsphragmen_remove_member_V5 - who */;
            return _toStringLookupSource(
                &m->basic.electionsphragmen_remove_member_V5.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* electionsphragmen_remove_member_V5 - has_replacement */;
            return _toStringbool(
                &m->basic.electionsphragmen_remove_member_V5.has_replacement,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4608: /* module 18 call 0 */
        switch (itemIdx) {
        case 0: /* technicalmembership_add_member_V5 - who */;
            return _toStringAccountId_V5(
                &m->basic.technicalmembership_add_member_V5.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4609: /* module 18 call 1 */
        switch (itemIdx) {
        case 0: /* technicalmembership_remove_member_V5 - who */;
            return _toStringAccountId_V5(
                &m->basic.technicalmembership_remove_member_V5.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4610: /* module 18 call 2 */
        switch (itemIdx) {
        case 0: /* technicalmembership_swap_member_V5 - remove */;
            return _toStringAccountId_V5(
                &m->basic.technicalmembership_swap_member_V5.remove,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* technicalmembership_swap_member_V5 - add */;
            return _toStringAccountId_V5(
                &m->basic.technicalmembership_swap_member_V5.add,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4611: /* module 18 call 3 */
        switch (itemIdx) {
        case 0: /* technicalmembership_reset_members_V5 - members */;
            return _toStringVecAccountId_V5(
                &m->basic.technicalmembership_reset_members_V5.members,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4612: /* module 18 call 4 */
        switch (itemIdx) {
        case 0: /* technicalmembership_change_key_V5 - new_ */;
            return _toStringAccountId_V5(
                &m->basic.technicalmembership_change_key_V5.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4613: /* module 18 call 5 */
        switch (itemIdx) {
        case 0: /* technicalmembership_set_prime_V5 - who */;
            return _toStringAccountId_V5(
                &m->basic.technicalmembership_set_prime_V5.who,
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
        case 0: /* treasury_propose_spend_V5 - value */;
            return _toStringCompactBalanceOf(
                &m->basic.treasury_propose_spend_V5.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* treasury_propose_spend_V5 - beneficiary */;
            return _toStringLookupSource(
                &m->basic.treasury_propose_spend_V5.beneficiary,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4865: /* module 19 call 1 */
        switch (itemIdx) {
        case 0: /* treasury_reject_proposal_V5 - proposal_id */;
            return _toStringCompactProposalIndex_V5(
                &m->basic.treasury_reject_proposal_V5.proposal_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4866: /* module 19 call 2 */
        switch (itemIdx) {
        case 0: /* treasury_approve_proposal_V5 - proposal_id */;
            return _toStringCompactProposalIndex_V5(
                &m->basic.treasury_approve_proposal_V5.proposal_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4867: /* module 19 call 3 */
        switch (itemIdx) {
        case 0: /* treasury_report_awesome_V5 - reason */;
            return _toStringBytes(
                &m->basic.treasury_report_awesome_V5.reason,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* treasury_report_awesome_V5 - who */;
            return _toStringAccountId_V5(
                &m->basic.treasury_report_awesome_V5.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4868: /* module 19 call 4 */
        switch (itemIdx) {
        case 0: /* treasury_retract_tip_V5 - hash */;
            return _toStringHash(
                &m->basic.treasury_retract_tip_V5.hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4869: /* module 19 call 5 */
        switch (itemIdx) {
        case 0: /* treasury_tip_new_V5 - reason */;
            return _toStringBytes(
                &m->basic.treasury_tip_new_V5.reason,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* treasury_tip_new_V5 - who */;
            return _toStringAccountId_V5(
                &m->basic.treasury_tip_new_V5.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* treasury_tip_new_V5 - tip_value */;
            return _toStringCompactBalanceOf(
                &m->basic.treasury_tip_new_V5.tip_value,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4870: /* module 19 call 6 */
        switch (itemIdx) {
        case 0: /* treasury_tip_V5 - hash */;
            return _toStringHash(
                &m->basic.treasury_tip_V5.hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* treasury_tip_V5 - tip_value */;
            return _toStringCompactBalanceOf(
                &m->basic.treasury_tip_V5.tip_value,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4871: /* module 19 call 7 */
        switch (itemIdx) {
        case 0: /* treasury_close_tip_V5 - hash */;
            return _toStringHash(
                &m->basic.treasury_close_tip_V5.hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4872: /* module 19 call 8 */
        switch (itemIdx) {
        case 0: /* treasury_propose_bounty_V5 - value */;
            return _toStringCompactBalanceOf(
                &m->basic.treasury_propose_bounty_V5.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* treasury_propose_bounty_V5 - description */;
            return _toStringBytes(
                &m->basic.treasury_propose_bounty_V5.description,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4873: /* module 19 call 9 */
        switch (itemIdx) {
        case 0: /* treasury_approve_bounty_V5 - bounty_id */;
            return _toStringCompactProposalIndex_V5(
                &m->basic.treasury_approve_bounty_V5.bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4874: /* module 19 call 10 */
        switch (itemIdx) {
        case 0: /* treasury_propose_curator_V5 - bounty_id */;
            return _toStringCompactProposalIndex_V5(
                &m->basic.treasury_propose_curator_V5.bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* treasury_propose_curator_V5 - curator */;
            return _toStringLookupSource(
                &m->basic.treasury_propose_curator_V5.curator,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* treasury_propose_curator_V5 - fee */;
            return _toStringCompactBalanceOf(
                &m->basic.treasury_propose_curator_V5.fee,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4875: /* module 19 call 11 */
        switch (itemIdx) {
        case 0: /* treasury_unassign_curator_V5 - bounty_id */;
            return _toStringCompactProposalIndex_V5(
                &m->basic.treasury_unassign_curator_V5.bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4876: /* module 19 call 12 */
        switch (itemIdx) {
        case 0: /* treasury_accept_curator_V5 - bounty_id */;
            return _toStringCompactProposalIndex_V5(
                &m->basic.treasury_accept_curator_V5.bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4877: /* module 19 call 13 */
        switch (itemIdx) {
        case 0: /* treasury_award_bounty_V5 - bounty_id */;
            return _toStringCompactProposalIndex_V5(
                &m->basic.treasury_award_bounty_V5.bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* treasury_award_bounty_V5 - beneficiary */;
            return _toStringLookupSource(
                &m->basic.treasury_award_bounty_V5.beneficiary,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4878: /* module 19 call 14 */
        switch (itemIdx) {
        case 0: /* treasury_claim_bounty_V5 - bounty_id */;
            return _toStringCompactBountyIndex_V5(
                &m->basic.treasury_claim_bounty_V5.bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4879: /* module 19 call 15 */
        switch (itemIdx) {
        case 0: /* treasury_close_bounty_V5 - bounty_id */;
            return _toStringCompactBountyIndex_V5(
                &m->basic.treasury_close_bounty_V5.bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4880: /* module 19 call 16 */
        switch (itemIdx) {
        case 0: /* treasury_extend_bounty_expiry_V5 - bounty_id */;
            return _toStringCompactBountyIndex_V5(
                &m->basic.treasury_extend_bounty_expiry_V5.bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* treasury_extend_bounty_expiry_V5 - _remark */;
            return _toStringBytes(
                &m->basic.treasury_extend_bounty_expiry_V5._remark,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6144: /* module 24 call 0 */
        switch (itemIdx) {
        case 0: /* claims_claim_V5 - dest */;
            return _toStringAccountId_V5(
                &m->basic.claims_claim_V5.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* claims_claim_V5 - ethereum_signature */;
            return _toStringEcdsaSignature_V5(
                &m->basic.claims_claim_V5.ethereum_signature,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6145: /* module 24 call 1 */
        switch (itemIdx) {
        case 0: /* claims_mint_claim_V5 - who */;
            return _toStringEthereumAddress_V5(
                &m->basic.claims_mint_claim_V5.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* claims_mint_claim_V5 - value */;
            return _toStringBalanceOf_V5(
                &m->basic.claims_mint_claim_V5.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* claims_mint_claim_V5 - vesting_schedule */;
            return _toStringOptionTupleBalanceOfBalanceOfBlockNumber_V5(
                &m->basic.claims_mint_claim_V5.vesting_schedule,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* claims_mint_claim_V5 - statement */;
            return _toStringOptionStatementKind_V5(
                &m->basic.claims_mint_claim_V5.statement,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6146: /* module 24 call 2 */
        switch (itemIdx) {
        case 0: /* claims_claim_attest_V5 - dest */;
            return _toStringAccountId_V5(
                &m->basic.claims_claim_attest_V5.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* claims_claim_attest_V5 - ethereum_signature */;
            return _toStringEcdsaSignature_V5(
                &m->basic.claims_claim_attest_V5.ethereum_signature,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* claims_claim_attest_V5 - statement */;
            return _toStringBytes(
                &m->basic.claims_claim_attest_V5.statement,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6147: /* module 24 call 3 */
        switch (itemIdx) {
        case 0: /* claims_attest_V5 - statement */;
            return _toStringBytes(
                &m->basic.claims_attest_V5.statement,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6148: /* module 24 call 4 */
        switch (itemIdx) {
        case 0: /* claims_move_claim_V5 - old */;
            return _toStringEthereumAddress_V5(
                &m->basic.claims_move_claim_V5.old,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* claims_move_claim_V5 - new_ */;
            return _toStringEthereumAddress_V5(
                &m->basic.claims_move_claim_V5.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* claims_move_claim_V5 - maybe_preclaim */;
            return _toStringOptionAccountId_V5(
                &m->basic.claims_move_claim_V5.maybe_preclaim,
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
        case 0: /* vesting_vest_other_V5 - target */;
            return _toStringLookupSource(
                &m->basic.vesting_vest_other_V5.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6402: /* module 25 call 2 */
        switch (itemIdx) {
        case 0: /* vesting_vested_transfer_V5 - target */;
            return _toStringLookupSource(
                &m->basic.vesting_vested_transfer_V5.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* vesting_vested_transfer_V5 - schedule */;
            return _toStringVestingInfo_V5(
                &m->basic.vesting_vested_transfer_V5.schedule,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6403: /* module 25 call 3 */
        switch (itemIdx) {
        case 0: /* vesting_force_vested_transfer_V5 - source */;
            return _toStringLookupSource(
                &m->basic.vesting_force_vested_transfer_V5.source,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* vesting_force_vested_transfer_V5 - target */;
            return _toStringLookupSource(
                &m->basic.vesting_force_vested_transfer_V5.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* vesting_force_vested_transfer_V5 - schedule */;
            return _toStringVestingInfo_V5(
                &m->basic.vesting_force_vested_transfer_V5.schedule,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6656: /* module 26 call 0 */
        switch (itemIdx) {
        case 0: /* utility_batch_V5 - calls */;
            return _toStringVecCall_V5(
                &m->basic.utility_batch_V5.calls,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6657: /* module 26 call 1 */
        switch (itemIdx) {
        case 0: /* utility_as_derivative_V5 - index */;
            return _toStringu16(
                &m->basic.utility_as_derivative_V5.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* utility_as_derivative_V5 - call */;
            return _toStringCall_V5(
                &m->basic.utility_as_derivative_V5.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6658: /* module 26 call 2 */
        switch (itemIdx) {
        case 0: /* utility_batch_all_V5 - calls */;
            return _toStringVecCall_V5(
                &m->basic.utility_batch_all_V5.calls,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7168: /* module 28 call 0 */
        switch (itemIdx) {
        case 0: /* identity_add_registrar_V5 - account */;
            return _toStringAccountId_V5(
                &m->basic.identity_add_registrar_V5.account,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7169: /* module 28 call 1 */
        switch (itemIdx) {
        case 0: /* identity_set_identity_V5 - info */;
            return _toStringIdentityInfo_V5(
                &m->basic.identity_set_identity_V5.info,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7170: /* module 28 call 2 */
        switch (itemIdx) {
        case 0: /* identity_set_subs_V5 - subs */;
            return _toStringVecTupleAccountIdData_V5(
                &m->basic.identity_set_subs_V5.subs,
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
        case 0: /* identity_request_judgement_V5 - reg_index */;
            return _toStringCompactRegistrarIndex_V5(
                &m->basic.identity_request_judgement_V5.reg_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_request_judgement_V5 - max_fee */;
            return _toStringCompactBalanceOf(
                &m->basic.identity_request_judgement_V5.max_fee,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7173: /* module 28 call 5 */
        switch (itemIdx) {
        case 0: /* identity_cancel_request_V5 - reg_index */;
            return _toStringRegistrarIndex_V5(
                &m->basic.identity_cancel_request_V5.reg_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7174: /* module 28 call 6 */
        switch (itemIdx) {
        case 0: /* identity_set_fee_V5 - index */;
            return _toStringCompactRegistrarIndex_V5(
                &m->basic.identity_set_fee_V5.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_set_fee_V5 - fee */;
            return _toStringCompactBalanceOf(
                &m->basic.identity_set_fee_V5.fee,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7175: /* module 28 call 7 */
        switch (itemIdx) {
        case 0: /* identity_set_account_id_V5 - index */;
            return _toStringCompactRegistrarIndex_V5(
                &m->basic.identity_set_account_id_V5.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_set_account_id_V5 - new_ */;
            return _toStringAccountId_V5(
                &m->basic.identity_set_account_id_V5.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7176: /* module 28 call 8 */
        switch (itemIdx) {
        case 0: /* identity_set_fields_V5 - index */;
            return _toStringCompactRegistrarIndex_V5(
                &m->basic.identity_set_fields_V5.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_set_fields_V5 - fields */;
            return _toStringIdentityFields_V5(
                &m->basic.identity_set_fields_V5.fields,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7177: /* module 28 call 9 */
        switch (itemIdx) {
        case 0: /* identity_provide_judgement_V5 - reg_index */;
            return _toStringCompactRegistrarIndex_V5(
                &m->basic.identity_provide_judgement_V5.reg_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_provide_judgement_V5 - target */;
            return _toStringLookupSource(
                &m->basic.identity_provide_judgement_V5.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* identity_provide_judgement_V5 - judgement */;
            return _toStringJudgement_V5(
                &m->basic.identity_provide_judgement_V5.judgement,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7178: /* module 28 call 10 */
        switch (itemIdx) {
        case 0: /* identity_kill_identity_V5 - target */;
            return _toStringLookupSource(
                &m->basic.identity_kill_identity_V5.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7179: /* module 28 call 11 */
        switch (itemIdx) {
        case 0: /* identity_add_sub_V5 - sub */;
            return _toStringLookupSource(
                &m->basic.identity_add_sub_V5.sub,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_add_sub_V5 - data */;
            return _toStringData(
                &m->basic.identity_add_sub_V5.data,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7180: /* module 28 call 12 */
        switch (itemIdx) {
        case 0: /* identity_rename_sub_V5 - sub */;
            return _toStringLookupSource(
                &m->basic.identity_rename_sub_V5.sub,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_rename_sub_V5 - data */;
            return _toStringData(
                &m->basic.identity_rename_sub_V5.data,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7181: /* module 28 call 13 */
        switch (itemIdx) {
        case 0: /* identity_remove_sub_V5 - sub */;
            return _toStringLookupSource(
                &m->basic.identity_remove_sub_V5.sub,
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
        case 0: /* proxy_proxy_V5 - real */;
            return _toStringAccountId_V5(
                &m->basic.proxy_proxy_V5.real,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_proxy_V5 - force_proxy_type */;
            return _toStringOptionProxyType_V5(
                &m->basic.proxy_proxy_V5.force_proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* proxy_proxy_V5 - call */;
            return _toStringCall_V5(
                &m->basic.proxy_proxy_V5.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7425: /* module 29 call 1 */
        switch (itemIdx) {
        case 0: /* proxy_add_proxy_V5 - delegate */;
            return _toStringAccountId_V5(
                &m->basic.proxy_add_proxy_V5.delegate,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_add_proxy_V5 - proxy_type */;
            return _toStringProxyType_V5(
                &m->basic.proxy_add_proxy_V5.proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* proxy_add_proxy_V5 - delay */;
            return _toStringBlockNumber(
                &m->basic.proxy_add_proxy_V5.delay,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7426: /* module 29 call 2 */
        switch (itemIdx) {
        case 0: /* proxy_remove_proxy_V5 - delegate */;
            return _toStringAccountId_V5(
                &m->basic.proxy_remove_proxy_V5.delegate,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_remove_proxy_V5 - proxy_type */;
            return _toStringProxyType_V5(
                &m->basic.proxy_remove_proxy_V5.proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* proxy_remove_proxy_V5 - delay */;
            return _toStringBlockNumber(
                &m->basic.proxy_remove_proxy_V5.delay,
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
        case 0: /* proxy_anonymous_V5 - proxy_type */;
            return _toStringProxyType_V5(
                &m->basic.proxy_anonymous_V5.proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_anonymous_V5 - delay */;
            return _toStringBlockNumber(
                &m->basic.proxy_anonymous_V5.delay,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* proxy_anonymous_V5 - index */;
            return _toStringu16(
                &m->basic.proxy_anonymous_V5.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7429: /* module 29 call 5 */
        switch (itemIdx) {
        case 0: /* proxy_kill_anonymous_V5 - spawner */;
            return _toStringAccountId_V5(
                &m->basic.proxy_kill_anonymous_V5.spawner,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_kill_anonymous_V5 - proxy_type */;
            return _toStringProxyType_V5(
                &m->basic.proxy_kill_anonymous_V5.proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* proxy_kill_anonymous_V5 - index */;
            return _toStringu16(
                &m->basic.proxy_kill_anonymous_V5.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* proxy_kill_anonymous_V5 - height */;
            return _toStringCompactBlockNumber(
                &m->basic.proxy_kill_anonymous_V5.height,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* proxy_kill_anonymous_V5 - ext_index */;
            return _toStringCompactu32(
                &m->basic.proxy_kill_anonymous_V5.ext_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7430: /* module 29 call 6 */
        switch (itemIdx) {
        case 0: /* proxy_announce_V5 - real */;
            return _toStringAccountId_V5(
                &m->basic.proxy_announce_V5.real,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_announce_V5 - call_hash */;
            return _toStringCallHashOf_V5(
                &m->basic.proxy_announce_V5.call_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7431: /* module 29 call 7 */
        switch (itemIdx) {
        case 0: /* proxy_remove_announcement_V5 - real */;
            return _toStringAccountId_V5(
                &m->basic.proxy_remove_announcement_V5.real,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_remove_announcement_V5 - call_hash */;
            return _toStringCallHashOf_V5(
                &m->basic.proxy_remove_announcement_V5.call_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7432: /* module 29 call 8 */
        switch (itemIdx) {
        case 0: /* proxy_reject_announcement_V5 - delegate */;
            return _toStringAccountId_V5(
                &m->basic.proxy_reject_announcement_V5.delegate,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_reject_announcement_V5 - call_hash */;
            return _toStringCallHashOf_V5(
                &m->basic.proxy_reject_announcement_V5.call_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7433: /* module 29 call 9 */
        switch (itemIdx) {
        case 0: /* proxy_proxy_announced_V5 - delegate */;
            return _toStringAccountId_V5(
                &m->basic.proxy_proxy_announced_V5.delegate,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_proxy_announced_V5 - real */;
            return _toStringAccountId_V5(
                &m->basic.proxy_proxy_announced_V5.real,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* proxy_proxy_announced_V5 - force_proxy_type */;
            return _toStringOptionProxyType_V5(
                &m->basic.proxy_proxy_announced_V5.force_proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* proxy_proxy_announced_V5 - call */;
            return _toStringCall_V5(
                &m->basic.proxy_proxy_announced_V5.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7680: /* module 30 call 0 */
        switch (itemIdx) {
        case 0: /* multisig_as_multi_threshold_1_V5 - other_signatories */;
            return _toStringVecAccountId_V5(
                &m->basic.multisig_as_multi_threshold_1_V5.other_signatories,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_as_multi_threshold_1_V5 - call */;
            return _toStringCall_V5(
                &m->basic.multisig_as_multi_threshold_1_V5.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7681: /* module 30 call 1 */
        switch (itemIdx) {
        case 0: /* multisig_as_multi_V5 - threshold */;
            return _toStringu16(
                &m->basic.multisig_as_multi_V5.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_as_multi_V5 - other_signatories */;
            return _toStringVecAccountId_V5(
                &m->basic.multisig_as_multi_V5.other_signatories,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* multisig_as_multi_V5 - maybe_timepoint */;
            return _toStringOptionTimepoint_V5(
                &m->basic.multisig_as_multi_V5.maybe_timepoint,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* multisig_as_multi_V5 - call */;
            return _toStringOpaqueCall_V5(
                &m->basic.multisig_as_multi_V5.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* multisig_as_multi_V5 - store_call */;
            return _toStringbool(
                &m->basic.multisig_as_multi_V5.store_call,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* multisig_as_multi_V5 - max_weight */;
            return _toStringWeight_V5(
                &m->basic.multisig_as_multi_V5.max_weight,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7682: /* module 30 call 2 */
        switch (itemIdx) {
        case 0: /* multisig_approve_as_multi_V5 - threshold */;
            return _toStringu16(
                &m->basic.multisig_approve_as_multi_V5.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_approve_as_multi_V5 - other_signatories */;
            return _toStringVecAccountId_V5(
                &m->basic.multisig_approve_as_multi_V5.other_signatories,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* multisig_approve_as_multi_V5 - maybe_timepoint */;
            return _toStringOptionTimepoint_V5(
                &m->basic.multisig_approve_as_multi_V5.maybe_timepoint,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* multisig_approve_as_multi_V5 - call_hash */;
            return _toStringu8_array_32_V5(
                &m->basic.multisig_approve_as_multi_V5.call_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* multisig_approve_as_multi_V5 - max_weight */;
            return _toStringWeight_V5(
                &m->basic.multisig_approve_as_multi_V5.max_weight,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7683: /* module 30 call 3 */
        switch (itemIdx) {
        case 0: /* multisig_cancel_as_multi_V5 - threshold */;
            return _toStringu16(
                &m->basic.multisig_cancel_as_multi_V5.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_cancel_as_multi_V5 - other_signatories */;
            return _toStringVecAccountId_V5(
                &m->basic.multisig_cancel_as_multi_V5.other_signatories,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* multisig_cancel_as_multi_V5 - timepoint */;
            return _toStringTimepoint_V5(
                &m->basic.multisig_cancel_as_multi_V5.timepoint,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* multisig_cancel_as_multi_V5 - call_hash */;
            return _toStringu8_array_32_V5(
                &m->basic.multisig_cancel_as_multi_V5.call_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    default:
        return parser_ok;
    }

    return parser_ok;
}
