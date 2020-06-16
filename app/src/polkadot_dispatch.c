/*******************************************************************************
*  (c) 2019 ZondaX GmbH
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
#include "polkadot_dispatch.h"

#include <stdint.h>
#include "zxmacros.h"

__Z_INLINE parser_error_t _readMethod_system_fill_block(
    parser_context_t *c, pd_system_fill_block_t *m) {
    CHECK_ERROR(_readPerbill(c, &m->_ratio))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_remark(
    parser_context_t *c, pd_system_remark_t *m) {
    CHECK_ERROR(_readBytes(c, &m->_remark))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_heap_pages(
    parser_context_t *c, pd_system_set_heap_pages_t *m) {
    CHECK_ERROR(_readu64(c, &m->pages))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_code(
    parser_context_t *c, pd_system_set_code_t *m) {
    CHECK_ERROR(_readBytes(c, &m->code))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_code_without_checks(
    parser_context_t *c, pd_system_set_code_without_checks_t *m) {
    CHECK_ERROR(_readBytes(c, &m->code))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_changes_trie_config(
    parser_context_t *c, pd_system_set_changes_trie_config_t *m) {
    CHECK_ERROR(_readOptionChangesTrieConfiguration(c, &m->changes_trie_config))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_storage(
    parser_context_t *c, pd_system_set_storage_t *m) {
    CHECK_ERROR(_readVecKeyValue(c, &m->items))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_kill_storage(
    parser_context_t *c, pd_system_kill_storage_t *m) {
    CHECK_ERROR(_readVecKey(c, &m->keys))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_kill_prefix(
    parser_context_t *c, pd_system_kill_prefix_t *m) {
    CHECK_ERROR(_readKey(c, &m->prefix))
    CHECK_ERROR(_readu32(c, &m->_subkeys))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_suicide(
    parser_context_t *c, pd_system_suicide_t *m) {
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_timestamp_set(
    parser_context_t *c, pd_timestamp_set_t *m) {
    CHECK_ERROR(_readCompactMoment(c, &m->now))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_indices_claim(
    parser_context_t *c, pd_indices_claim_t *m) {
    CHECK_ERROR(_readAccountIndex(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_indices_transfer(
    parser_context_t *c, pd_indices_transfer_t *m) {
    CHECK_ERROR(_readAccountId(c, &m->new_))
    CHECK_ERROR(_readAccountIndex(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_indices_free(
    parser_context_t *c, pd_indices_free_t *m) {
    CHECK_ERROR(_readAccountIndex(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_indices_force_transfer(
    parser_context_t *c, pd_indices_force_transfer_t *m) {
    CHECK_ERROR(_readAccountId(c, &m->new_))
    CHECK_ERROR(_readAccountIndex(c, &m->index))
    CHECK_ERROR(_readbool(c, &m->freeze))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_indices_freeze(
    parser_context_t *c, pd_indices_freeze_t *m) {
    CHECK_ERROR(_readAccountIndex(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_transfer(
    parser_context_t *c, pd_balances_transfer_t *m) {
    CHECK_ERROR(_readLookupSource(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_set_balance(
    parser_context_t *c, pd_balances_set_balance_t *m) {
    CHECK_ERROR(_readLookupSource(c, &m->who))
    CHECK_ERROR(_readCompactBalance(c, &m->new_free))
    CHECK_ERROR(_readCompactBalance(c, &m->new_reserved))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_force_transfer(
    parser_context_t *c, pd_balances_force_transfer_t *m) {
    CHECK_ERROR(_readLookupSource(c, &m->source))
    CHECK_ERROR(_readLookupSource(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_transfer_keep_alive(
    parser_context_t *c, pd_balances_transfer_keep_alive_t *m) {
    CHECK_ERROR(_readLookupSource(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_authorship_set_uncles(
    parser_context_t *c, pd_authorship_set_uncles_t *m) {
    CHECK_ERROR(_readVecHeader(c, &m->new_uncles))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_bond(
    parser_context_t *c, pd_staking_bond_t *m) {
    CHECK_ERROR(_readLookupSource(c, &m->controller))
    CHECK_ERROR(_readCompactBalanceOf(c, &m->value))
    CHECK_ERROR(_readRewardDestination(c, &m->payee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_bond_extra(
    parser_context_t *c, pd_staking_bond_extra_t *m) {
    CHECK_ERROR(_readCompactBalanceOf(c, &m->max_additional))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_unbond(
    parser_context_t *c, pd_staking_unbond_t *m) {
    CHECK_ERROR(_readCompactBalanceOf(c, &m->value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_withdraw_unbonded(
    parser_context_t *c, pd_staking_withdraw_unbonded_t *m) {
    CHECK_ERROR(_readu32(c, &m->num_slashing_spans))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_validate(
    parser_context_t *c, pd_staking_validate_t *m) {
    CHECK_ERROR(_readValidatorPrefs(c, &m->prefs))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_nominate(
    parser_context_t *c, pd_staking_nominate_t *m) {
    CHECK_ERROR(_readVecLookupSource(c, &m->targets))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_chill(
    parser_context_t *c, pd_staking_chill_t *m) {
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_payee(
    parser_context_t *c, pd_staking_set_payee_t *m) {
    CHECK_ERROR(_readRewardDestination(c, &m->payee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_controller(
    parser_context_t *c, pd_staking_set_controller_t *m) {
    CHECK_ERROR(_readLookupSource(c, &m->controller))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_validator_count(
    parser_context_t *c, pd_staking_set_validator_count_t *m) {
    CHECK_ERROR(_readCompactu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_no_eras(
    parser_context_t *c, pd_staking_force_no_eras_t *m) {
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_new_era(
    parser_context_t *c, pd_staking_force_new_era_t *m) {
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_invulnerables(
    parser_context_t *c, pd_staking_set_invulnerables_t *m) {
    CHECK_ERROR(_readVecAccountId(c, &m->validators))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_unstake(
    parser_context_t *c, pd_staking_force_unstake_t *m) {
    CHECK_ERROR(_readAccountId(c, &m->stash))
    CHECK_ERROR(_readu32(c, &m->num_slashing_spans))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_new_era_always(
    parser_context_t *c, pd_staking_force_new_era_always_t *m) {
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_cancel_deferred_slash(
    parser_context_t *c, pd_staking_cancel_deferred_slash_t *m) {
    CHECK_ERROR(_readEraIndex(c, &m->era))
    CHECK_ERROR(_readVecu32(c, &m->slash_indices))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_payout_stakers(
    parser_context_t *c, pd_staking_payout_stakers_t *m) {
    CHECK_ERROR(_readAccountId(c, &m->validator_stash))
    CHECK_ERROR(_readEraIndex(c, &m->era))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_rebond(
    parser_context_t *c, pd_staking_rebond_t *m) {
    CHECK_ERROR(_readCompactBalanceOf(c, &m->value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_history_depth(
    parser_context_t *c, pd_staking_set_history_depth_t *m) {
    CHECK_ERROR(_readCompactEraIndex(c, &m->new_history_depth))
    CHECK_ERROR(_readCompactu32(c, &m->_era_items_deleted))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_reap_stash(
    parser_context_t *c, pd_staking_reap_stash_t *m) {
    CHECK_ERROR(_readAccountId(c, &m->stash))
    CHECK_ERROR(_readu32(c, &m->num_slashing_spans))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_submit_election_solution(
    parser_context_t *c, pd_staking_submit_election_solution_t *m) {
    CHECK_ERROR(_readVecValidatorIndex(c, &m->winners))
    CHECK_ERROR(_readCompactAssignments(c, &m->compact))
    CHECK_ERROR(_readElectionScore(c, &m->score))
    CHECK_ERROR(_readEraIndex(c, &m->era))
    CHECK_ERROR(_readElectionSize(c, &m->size))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_submit_election_solution_unsigned(
    parser_context_t *c, pd_staking_submit_election_solution_unsigned_t *m) {
    CHECK_ERROR(_readVecValidatorIndex(c, &m->winners))
    CHECK_ERROR(_readCompactAssignments(c, &m->compact))
    CHECK_ERROR(_readElectionScore(c, &m->score))
    CHECK_ERROR(_readEraIndex(c, &m->era))
    CHECK_ERROR(_readElectionSize(c, &m->size))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_session_set_keys(
    parser_context_t *c, pd_session_set_keys_t *m) {
    CHECK_ERROR(_readKeys(c, &m->keys))
    CHECK_ERROR(_readBytes(c, &m->proof))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_session_purge_keys(
    parser_context_t *c, pd_session_purge_keys_t *m) {
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_finalitytracker_final_hint(
    parser_context_t *c, pd_finalitytracker_final_hint_t *m) {
    CHECK_ERROR(_readCompactBlockNumber(c, &m->hint))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_grandpa_report_equivocation(
    parser_context_t *c, pd_grandpa_report_equivocation_t *m) {
    CHECK_ERROR(_readEquivocationProof(c, &m->equivocation_proof))
    CHECK_ERROR(_readKeyOwnerProof(c, &m->key_owner_proof))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_imonline_heartbeat(
    parser_context_t *c, pd_imonline_heartbeat_t *m) {
    CHECK_ERROR(_readHeartbeat(c, &m->heartbeat))
    CHECK_ERROR(_readSignature(c, &m->_signature))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_propose(
    parser_context_t *c, pd_democracy_propose_t *m) {
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    CHECK_ERROR(_readCompactBalanceOf(c, &m->value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_second(
    parser_context_t *c, pd_democracy_second_t *m) {
    CHECK_ERROR(_readCompactPropIndex(c, &m->proposal))
    CHECK_ERROR(_readCompactu32(c, &m->seconds_upper_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_vote(
    parser_context_t *c, pd_democracy_vote_t *m) {
    CHECK_ERROR(_readCompactReferendumIndex(c, &m->ref_index))
    CHECK_ERROR(_readAccountVote(c, &m->vote))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_emergency_cancel(
    parser_context_t *c, pd_democracy_emergency_cancel_t *m) {
    CHECK_ERROR(_readReferendumIndex(c, &m->ref_index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_external_propose(
    parser_context_t *c, pd_democracy_external_propose_t *m) {
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_external_propose_majority(
    parser_context_t *c, pd_democracy_external_propose_majority_t *m) {
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_external_propose_default(
    parser_context_t *c, pd_democracy_external_propose_default_t *m) {
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_fast_track(
    parser_context_t *c, pd_democracy_fast_track_t *m) {
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    CHECK_ERROR(_readBlockNumber(c, &m->voting_period))
    CHECK_ERROR(_readBlockNumber(c, &m->delay))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_veto_external(
    parser_context_t *c, pd_democracy_veto_external_t *m) {
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_cancel_referendum(
    parser_context_t *c, pd_democracy_cancel_referendum_t *m) {
    CHECK_ERROR(_readCompactReferendumIndex(c, &m->ref_index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_cancel_queued(
    parser_context_t *c, pd_democracy_cancel_queued_t *m) {
    CHECK_ERROR(_readReferendumIndex(c, &m->which))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_delegate(
    parser_context_t *c, pd_democracy_delegate_t *m) {
    CHECK_ERROR(_readAccountId(c, &m->to))
    CHECK_ERROR(_readConviction(c, &m->conviction))
    CHECK_ERROR(_readBalanceOf(c, &m->balance))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_undelegate(
    parser_context_t *c, pd_democracy_undelegate_t *m) {
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_clear_public_proposals(
    parser_context_t *c, pd_democracy_clear_public_proposals_t *m) {
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_note_preimage(
    parser_context_t *c, pd_democracy_note_preimage_t *m) {
    CHECK_ERROR(_readBytes(c, &m->encoded_proposal))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_note_preimage_operational(
    parser_context_t *c, pd_democracy_note_preimage_operational_t *m) {
    CHECK_ERROR(_readBytes(c, &m->encoded_proposal))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_note_imminent_preimage(
    parser_context_t *c, pd_democracy_note_imminent_preimage_t *m) {
    CHECK_ERROR(_readBytes(c, &m->encoded_proposal))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_note_imminent_preimage_operational(
    parser_context_t *c, pd_democracy_note_imminent_preimage_operational_t *m) {
    CHECK_ERROR(_readBytes(c, &m->encoded_proposal))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_reap_preimage(
    parser_context_t *c, pd_democracy_reap_preimage_t *m) {
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    CHECK_ERROR(_readCompactu32(c, &m->proposal_len_upper_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_unlock(
    parser_context_t *c, pd_democracy_unlock_t *m) {
    CHECK_ERROR(_readAccountId(c, &m->target))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_remove_vote(
    parser_context_t *c, pd_democracy_remove_vote_t *m) {
    CHECK_ERROR(_readReferendumIndex(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_remove_other_vote(
    parser_context_t *c, pd_democracy_remove_other_vote_t *m) {
    CHECK_ERROR(_readAccountId(c, &m->target))
    CHECK_ERROR(_readReferendumIndex(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_enact_proposal(
    parser_context_t *c, pd_democracy_enact_proposal_t *m) {
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    CHECK_ERROR(_readReferendumIndex(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_council_set_members(
    parser_context_t *c, pd_council_set_members_t *m) {
    CHECK_ERROR(_readVecAccountId(c, &m->new_members))
    CHECK_ERROR(_readOptionAccountId(c, &m->prime))
    CHECK_ERROR(_readMemberCount(c, &m->old_count))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_council_execute(
    parser_context_t *c, pd_council_execute_t *m) {
    CHECK_ERROR(_readProposal(c, &m->proposal))
    CHECK_ERROR(_readCompactu32(c, &m->length_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_council_propose(
    parser_context_t *c, pd_council_propose_t *m) {
    CHECK_ERROR(_readCompactMemberCount(c, &m->threshold))
    CHECK_ERROR(_readProposal(c, &m->proposal))
    CHECK_ERROR(_readCompactu32(c, &m->length_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_council_vote(
    parser_context_t *c, pd_council_vote_t *m) {
    CHECK_ERROR(_readHash(c, &m->proposal))
    CHECK_ERROR(_readCompactProposalIndex(c, &m->index))
    CHECK_ERROR(_readbool(c, &m->approve))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_council_close(
    parser_context_t *c, pd_council_close_t *m) {
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    CHECK_ERROR(_readCompactProposalIndex(c, &m->index))
    CHECK_ERROR(_readCompactWeight(c, &m->proposal_weight_bound))
    CHECK_ERROR(_readCompactu32(c, &m->length_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_council_disapprove_proposal(
    parser_context_t *c, pd_council_disapprove_proposal_t *m) {
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_set_members(
    parser_context_t *c, pd_technicalcommittee_set_members_t *m) {
    CHECK_ERROR(_readVecAccountId(c, &m->new_members))
    CHECK_ERROR(_readOptionAccountId(c, &m->prime))
    CHECK_ERROR(_readMemberCount(c, &m->old_count))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_execute(
    parser_context_t *c, pd_technicalcommittee_execute_t *m) {
    CHECK_ERROR(_readProposal(c, &m->proposal))
    CHECK_ERROR(_readCompactu32(c, &m->length_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_propose(
    parser_context_t *c, pd_technicalcommittee_propose_t *m) {
    CHECK_ERROR(_readCompactMemberCount(c, &m->threshold))
    CHECK_ERROR(_readProposal(c, &m->proposal))
    CHECK_ERROR(_readCompactu32(c, &m->length_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_vote(
    parser_context_t *c, pd_technicalcommittee_vote_t *m) {
    CHECK_ERROR(_readHash(c, &m->proposal))
    CHECK_ERROR(_readCompactProposalIndex(c, &m->index))
    CHECK_ERROR(_readbool(c, &m->approve))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_close(
    parser_context_t *c, pd_technicalcommittee_close_t *m) {
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    CHECK_ERROR(_readCompactProposalIndex(c, &m->index))
    CHECK_ERROR(_readCompactWeight(c, &m->proposal_weight_bound))
    CHECK_ERROR(_readCompactu32(c, &m->length_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_disapprove_proposal(
    parser_context_t *c, pd_technicalcommittee_disapprove_proposal_t *m) {
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_electionsphragmen_vote(
    parser_context_t *c, pd_electionsphragmen_vote_t *m) {
    CHECK_ERROR(_readVecAccountId(c, &m->votes))
    CHECK_ERROR(_readCompactBalanceOf(c, &m->value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_electionsphragmen_remove_voter(
    parser_context_t *c, pd_electionsphragmen_remove_voter_t *m) {
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_electionsphragmen_report_defunct_voter(
    parser_context_t *c, pd_electionsphragmen_report_defunct_voter_t *m) {
    CHECK_ERROR(_readDefunctVoter(c, &m->defunct))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_electionsphragmen_submit_candidacy(
    parser_context_t *c, pd_electionsphragmen_submit_candidacy_t *m) {
    CHECK_ERROR(_readCompactu32(c, &m->candidate_count))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_electionsphragmen_renounce_candidacy(
    parser_context_t *c, pd_electionsphragmen_renounce_candidacy_t *m) {
    CHECK_ERROR(_readRenouncing(c, &m->renouncing))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_electionsphragmen_remove_member(
    parser_context_t *c, pd_electionsphragmen_remove_member_t *m) {
    CHECK_ERROR(_readLookupSource(c, &m->who))
    CHECK_ERROR(_readbool(c, &m->has_replacement))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalmembership_add_member(
    parser_context_t *c, pd_technicalmembership_add_member_t *m) {
    CHECK_ERROR(_readAccountId(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalmembership_remove_member(
    parser_context_t *c, pd_technicalmembership_remove_member_t *m) {
    CHECK_ERROR(_readAccountId(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalmembership_swap_member(
    parser_context_t *c, pd_technicalmembership_swap_member_t *m) {
    CHECK_ERROR(_readAccountId(c, &m->remove))
    CHECK_ERROR(_readAccountId(c, &m->add))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalmembership_reset_members(
    parser_context_t *c, pd_technicalmembership_reset_members_t *m) {
    CHECK_ERROR(_readVecAccountId(c, &m->members))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalmembership_change_key(
    parser_context_t *c, pd_technicalmembership_change_key_t *m) {
    CHECK_ERROR(_readAccountId(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalmembership_set_prime(
    parser_context_t *c, pd_technicalmembership_set_prime_t *m) {
    CHECK_ERROR(_readAccountId(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalmembership_clear_prime(
    parser_context_t *c, pd_technicalmembership_clear_prime_t *m) {
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_propose_spend(
    parser_context_t *c, pd_treasury_propose_spend_t *m) {
    CHECK_ERROR(_readCompactBalanceOf(c, &m->value))
    CHECK_ERROR(_readLookupSource(c, &m->beneficiary))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_reject_proposal(
    parser_context_t *c, pd_treasury_reject_proposal_t *m) {
    CHECK_ERROR(_readCompactProposalIndex(c, &m->proposal_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_approve_proposal(
    parser_context_t *c, pd_treasury_approve_proposal_t *m) {
    CHECK_ERROR(_readCompactProposalIndex(c, &m->proposal_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_report_awesome(
    parser_context_t *c, pd_treasury_report_awesome_t *m) {
    CHECK_ERROR(_readBytes(c, &m->reason))
    CHECK_ERROR(_readAccountId(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_retract_tip(
    parser_context_t *c, pd_treasury_retract_tip_t *m) {
    CHECK_ERROR(_readHash(c, &m->hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_tip_new(
    parser_context_t *c, pd_treasury_tip_new_t *m) {
    CHECK_ERROR(_readBytes(c, &m->reason))
    CHECK_ERROR(_readAccountId(c, &m->who))
    CHECK_ERROR(_readBalanceOf(c, &m->tip_value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_tip(
    parser_context_t *c, pd_treasury_tip_t *m) {
    CHECK_ERROR(_readHash(c, &m->hash))
    CHECK_ERROR(_readBalanceOf(c, &m->tip_value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_close_tip(
    parser_context_t *c, pd_treasury_close_tip_t *m) {
    CHECK_ERROR(_readHash(c, &m->hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_claims_claim(
    parser_context_t *c, pd_claims_claim_t *m) {
    CHECK_ERROR(_readAccountId(c, &m->dest))
    CHECK_ERROR(_readEcdsaSignature(c, &m->ethereum_signature))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_claims_mint_claim(
    parser_context_t *c, pd_claims_mint_claim_t *m) {
    CHECK_ERROR(_readEthereumAddress(c, &m->who))
    CHECK_ERROR(_readBalanceOf(c, &m->value))
    CHECK_ERROR(_readOptionTupleBalanceOfBalanceOfBlockNumber(c, &m->vesting_schedule))
    CHECK_ERROR(_readOptionStatementKind(c, &m->statement))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_claims_claim_attest(
    parser_context_t *c, pd_claims_claim_attest_t *m) {
    CHECK_ERROR(_readAccountId(c, &m->dest))
    CHECK_ERROR(_readEcdsaSignature(c, &m->ethereum_signature))
    CHECK_ERROR(_readBytes(c, &m->statement))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_claims_attest(
    parser_context_t *c, pd_claims_attest_t *m) {
    CHECK_ERROR(_readBytes(c, &m->statement))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_claims_move_claim(
    parser_context_t *c, pd_claims_move_claim_t *m) {
    CHECK_ERROR(_readEthereumAddress(c, &m->old))
    CHECK_ERROR(_readEthereumAddress(c, &m->new_))
    CHECK_ERROR(_readOptionAccountId(c, &m->maybe_preclaim))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_parachains_set_heads(
    parser_context_t *c, pd_parachains_set_heads_t *m) {
    CHECK_ERROR(_readVecAttestedCandidate(c, &m->heads))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_parachains_report_double_vote(
    parser_context_t *c, pd_parachains_report_double_vote_t *m) {
    CHECK_ERROR(_readDoubleVoteReport(c, &m->report))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_attestations_more_attestations(
    parser_context_t *c, pd_attestations_more_attestations_t *m) {
    CHECK_ERROR(_readMoreAttestations(c, &m->_more))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_slots_new_auction(
    parser_context_t *c, pd_slots_new_auction_t *m) {
    CHECK_ERROR(_readCompactBlockNumber(c, &m->duration))
    CHECK_ERROR(_readCompactLeasePeriodOf(c, &m->lease_period_index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_slots_bid(
    parser_context_t *c, pd_slots_bid_t *m) {
    CHECK_ERROR(_readCompactSubId(c, &m->sub))
    CHECK_ERROR(_readCompactAuctionIndex(c, &m->auction_index))
    CHECK_ERROR(_readCompactLeasePeriodOf(c, &m->first_slot))
    CHECK_ERROR(_readCompactLeasePeriodOf(c, &m->last_slot))
    CHECK_ERROR(_readCompactBalanceOf(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_slots_bid_renew(
    parser_context_t *c, pd_slots_bid_renew_t *m) {
    CHECK_ERROR(_readCompactAuctionIndex(c, &m->auction_index))
    CHECK_ERROR(_readCompactLeasePeriodOf(c, &m->first_slot))
    CHECK_ERROR(_readCompactLeasePeriodOf(c, &m->last_slot))
    CHECK_ERROR(_readCompactBalanceOf(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_slots_set_offboarding(
    parser_context_t *c, pd_slots_set_offboarding_t *m) {
    CHECK_ERROR(_readLookupSource(c, &m->dest))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_slots_fix_deploy_data(
    parser_context_t *c, pd_slots_fix_deploy_data_t *m) {
    CHECK_ERROR(_readCompactSubId(c, &m->sub))
    CHECK_ERROR(_readCompactParaId(c, &m->para_id))
    CHECK_ERROR(_readHash(c, &m->code_hash))
    CHECK_ERROR(_readu32(c, &m->code_size))
    CHECK_ERROR(_readHeadData(c, &m->initial_head_data))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_slots_elaborate_deploy_data(
    parser_context_t *c, pd_slots_elaborate_deploy_data_t *m) {
    CHECK_ERROR(_readCompactParaId(c, &m->para_id))
    CHECK_ERROR(_readValidationCode(c, &m->code))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_registrar_register_para(
    parser_context_t *c, pd_registrar_register_para_t *m) {
    CHECK_ERROR(_readCompactParaId(c, &m->id))
    CHECK_ERROR(_readParaInfo(c, &m->info))
    CHECK_ERROR(_readValidationCode(c, &m->code))
    CHECK_ERROR(_readHeadData(c, &m->initial_head_data))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_registrar_deregister_para(
    parser_context_t *c, pd_registrar_deregister_para_t *m) {
    CHECK_ERROR(_readCompactParaId(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_registrar_set_thread_count(
    parser_context_t *c, pd_registrar_set_thread_count_t *m) {
    CHECK_ERROR(_readu32(c, &m->count))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_registrar_register_parathread(
    parser_context_t *c, pd_registrar_register_parathread_t *m) {
    CHECK_ERROR(_readValidationCode(c, &m->code))
    CHECK_ERROR(_readHeadData(c, &m->initial_head_data))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_registrar_select_parathread(
    parser_context_t *c, pd_registrar_select_parathread_t *m) {
    CHECK_ERROR(_readCompactParaId(c, &m->_id))
    CHECK_ERROR(_readCollatorId(c, &m->_collator))
    CHECK_ERROR(_readHash(c, &m->_head_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_registrar_deregister_parathread(
    parser_context_t *c, pd_registrar_deregister_parathread_t *m) {
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_registrar_swap(
    parser_context_t *c, pd_registrar_swap_t *m) {
    CHECK_ERROR(_readCompactParaId(c, &m->other))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_batch(
    parser_context_t *c, pd_utility_batch_t *m) {
    CHECK_ERROR(_readVecCall(c, &m->calls))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_as_sub(
    parser_context_t *c, pd_utility_as_sub_t *m) {
    CHECK_ERROR(_readu16(c, &m->index))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_as_limited_sub(
    parser_context_t *c, pd_utility_as_limited_sub_t *m) {
    CHECK_ERROR(_readu16(c, &m->index))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_add_registrar(
    parser_context_t *c, pd_identity_add_registrar_t *m) {
    CHECK_ERROR(_readAccountId(c, &m->account))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_set_identity(
    parser_context_t *c, pd_identity_set_identity_t *m) {
    CHECK_ERROR(_readIdentityInfo(c, &m->info))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_set_subs(
    parser_context_t *c, pd_identity_set_subs_t *m) {
    CHECK_ERROR(_readVecTupleAccountIdData(c, &m->subs))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_clear_identity(
    parser_context_t *c, pd_identity_clear_identity_t *m) {
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_request_judgement(
    parser_context_t *c, pd_identity_request_judgement_t *m) {
    CHECK_ERROR(_readCompactRegistrarIndex(c, &m->reg_index))
    CHECK_ERROR(_readCompactBalanceOf(c, &m->max_fee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_cancel_request(
    parser_context_t *c, pd_identity_cancel_request_t *m) {
    CHECK_ERROR(_readRegistrarIndex(c, &m->reg_index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_set_fee(
    parser_context_t *c, pd_identity_set_fee_t *m) {
    CHECK_ERROR(_readCompactRegistrarIndex(c, &m->index))
    CHECK_ERROR(_readCompactBalanceOf(c, &m->fee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_set_account_id(
    parser_context_t *c, pd_identity_set_account_id_t *m) {
    CHECK_ERROR(_readCompactRegistrarIndex(c, &m->index))
    CHECK_ERROR(_readAccountId(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_set_fields(
    parser_context_t *c, pd_identity_set_fields_t *m) {
    CHECK_ERROR(_readCompactRegistrarIndex(c, &m->index))
    CHECK_ERROR(_readIdentityFields(c, &m->fields))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_provide_judgement(
    parser_context_t *c, pd_identity_provide_judgement_t *m) {
    CHECK_ERROR(_readCompactRegistrarIndex(c, &m->reg_index))
    CHECK_ERROR(_readLookupSource(c, &m->target))
    CHECK_ERROR(_readIdentityJudgement(c, &m->judgement))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_kill_identity(
    parser_context_t *c, pd_identity_kill_identity_t *m) {
    CHECK_ERROR(_readLookupSource(c, &m->target))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_society_bid(
    parser_context_t *c, pd_society_bid_t *m) {
    CHECK_ERROR(_readBalanceOf(c, &m->value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_society_unbid(
    parser_context_t *c, pd_society_unbid_t *m) {
    CHECK_ERROR(_readu32(c, &m->pos))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_society_vouch(
    parser_context_t *c, pd_society_vouch_t *m) {
    CHECK_ERROR(_readAccountId(c, &m->who))
    CHECK_ERROR(_readBalanceOf(c, &m->value))
    CHECK_ERROR(_readBalanceOf(c, &m->tip))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_society_unvouch(
    parser_context_t *c, pd_society_unvouch_t *m) {
    CHECK_ERROR(_readu32(c, &m->pos))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_society_vote(
    parser_context_t *c, pd_society_vote_t *m) {
    CHECK_ERROR(_readLookupSource(c, &m->candidate))
    CHECK_ERROR(_readbool(c, &m->approve))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_society_defender_vote(
    parser_context_t *c, pd_society_defender_vote_t *m) {
    CHECK_ERROR(_readbool(c, &m->approve))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_society_payout(
    parser_context_t *c, pd_society_payout_t *m) {
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_society_found(
    parser_context_t *c, pd_society_found_t *m) {
    CHECK_ERROR(_readAccountId(c, &m->founder))
    CHECK_ERROR(_readu32(c, &m->max_members))
    CHECK_ERROR(_readBytes(c, &m->rules))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_society_unfound(
    parser_context_t *c, pd_society_unfound_t *m) {
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_society_judge_suspended_member(
    parser_context_t *c, pd_society_judge_suspended_member_t *m) {
    CHECK_ERROR(_readAccountId(c, &m->who))
    CHECK_ERROR(_readbool(c, &m->forgive))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_society_judge_suspended_candidate(
    parser_context_t *c, pd_society_judge_suspended_candidate_t *m) {
    CHECK_ERROR(_readAccountId(c, &m->who))
    CHECK_ERROR(_readSocietyJudgement(c, &m->judgement))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_society_set_max_members(
    parser_context_t *c, pd_society_set_max_members_t *m) {
    CHECK_ERROR(_readu32(c, &m->max))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_recovery_as_recovered(
    parser_context_t *c, pd_recovery_as_recovered_t *m) {
    CHECK_ERROR(_readAccountId(c, &m->account))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_recovery_set_recovered(
    parser_context_t *c, pd_recovery_set_recovered_t *m) {
    CHECK_ERROR(_readAccountId(c, &m->lost))
    CHECK_ERROR(_readAccountId(c, &m->rescuer))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_recovery_create_recovery(
    parser_context_t *c, pd_recovery_create_recovery_t *m) {
    CHECK_ERROR(_readVecAccountId(c, &m->friends))
    CHECK_ERROR(_readu16(c, &m->threshold))
    CHECK_ERROR(_readBlockNumber(c, &m->delay_period))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_recovery_initiate_recovery(
    parser_context_t *c, pd_recovery_initiate_recovery_t *m) {
    CHECK_ERROR(_readAccountId(c, &m->account))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_recovery_vouch_recovery(
    parser_context_t *c, pd_recovery_vouch_recovery_t *m) {
    CHECK_ERROR(_readAccountId(c, &m->lost))
    CHECK_ERROR(_readAccountId(c, &m->rescuer))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_recovery_claim_recovery(
    parser_context_t *c, pd_recovery_claim_recovery_t *m) {
    CHECK_ERROR(_readAccountId(c, &m->account))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_recovery_close_recovery(
    parser_context_t *c, pd_recovery_close_recovery_t *m) {
    CHECK_ERROR(_readAccountId(c, &m->rescuer))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_recovery_remove_recovery(
    parser_context_t *c, pd_recovery_remove_recovery_t *m) {
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_recovery_cancel_recovered(
    parser_context_t *c, pd_recovery_cancel_recovered_t *m) {
    CHECK_ERROR(_readAccountId(c, &m->account))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_vesting_vest(
    parser_context_t *c, pd_vesting_vest_t *m) {
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_vesting_vest_other(
    parser_context_t *c, pd_vesting_vest_other_t *m) {
    CHECK_ERROR(_readLookupSource(c, &m->target))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_vesting_vested_transfer(
    parser_context_t *c, pd_vesting_vested_transfer_t *m) {
    CHECK_ERROR(_readLookupSource(c, &m->target))
    CHECK_ERROR(_readVestingInfo(c, &m->schedule))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_scheduler_schedule(
    parser_context_t *c, pd_scheduler_schedule_t *m) {
    CHECK_ERROR(_readBlockNumber(c, &m->when))
    CHECK_ERROR(_readOptionPeriod(c, &m->maybe_periodic))
    CHECK_ERROR(_readPriority(c, &m->priority))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_scheduler_cancel(
    parser_context_t *c, pd_scheduler_cancel_t *m) {
    CHECK_ERROR(_readBlockNumber(c, &m->when))
    CHECK_ERROR(_readu32(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_scheduler_schedule_named(
    parser_context_t *c, pd_scheduler_schedule_named_t *m) {
    CHECK_ERROR(_readBytes(c, &m->id))
    CHECK_ERROR(_readBlockNumber(c, &m->when))
    CHECK_ERROR(_readOptionPeriod(c, &m->maybe_periodic))
    CHECK_ERROR(_readPriority(c, &m->priority))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_scheduler_cancel_named(
    parser_context_t *c, pd_scheduler_cancel_named_t *m) {
    CHECK_ERROR(_readBytes(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_proxy(
    parser_context_t *c, pd_proxy_proxy_t *m) {
    CHECK_ERROR(_readAccountId(c, &m->real))
    CHECK_ERROR(_readOptionProxyType(c, &m->force_proxy_type))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_add_proxy(
    parser_context_t *c, pd_proxy_add_proxy_t *m) {
    CHECK_ERROR(_readAccountId(c, &m->proxy))
    CHECK_ERROR(_readProxyType(c, &m->proxy_type))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_remove_proxy(
    parser_context_t *c, pd_proxy_remove_proxy_t *m) {
    CHECK_ERROR(_readAccountId(c, &m->proxy))
    CHECK_ERROR(_readProxyType(c, &m->proxy_type))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_remove_proxies(
    parser_context_t *c, pd_proxy_remove_proxies_t *m) {
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_anonymous(
    parser_context_t *c, pd_proxy_anonymous_t *m) {
    CHECK_ERROR(_readProxyType(c, &m->proxy_type))
    CHECK_ERROR(_readu16(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_kill_anonymous(
    parser_context_t *c, pd_proxy_kill_anonymous_t *m) {
    CHECK_ERROR(_readAccountId(c, &m->spawner))
    CHECK_ERROR(_readProxyType(c, &m->proxy_type))
    CHECK_ERROR(_readu16(c, &m->index))
    CHECK_ERROR(_readCompactBlockNumber(c, &m->height))
    CHECK_ERROR(_readCompactu32(c, &m->ext_index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_as_multi(
    parser_context_t *c, pd_multisig_as_multi_t *m) {
    CHECK_ERROR(_readu16(c, &m->threshold))
    CHECK_ERROR(_readVecAccountId(c, &m->other_signatories))
    CHECK_ERROR(_readOptionTimepoint(c, &m->maybe_timepoint))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_approve_as_multi(
    parser_context_t *c, pd_multisig_approve_as_multi_t *m) {
    CHECK_ERROR(_readu16(c, &m->threshold))
    CHECK_ERROR(_readVecAccountId(c, &m->other_signatories))
    CHECK_ERROR(_readOptionTimepoint(c, &m->maybe_timepoint))
    CHECK_ERROR(_readu8_array_32(c, &m->call_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_cancel_as_multi(
    parser_context_t *c, pd_multisig_cancel_as_multi_t *m) {
    CHECK_ERROR(_readu16(c, &m->threshold))
    CHECK_ERROR(_readVecAccountId(c, &m->other_signatories))
    CHECK_ERROR(_readTimepoint(c, &m->timepoint))
    CHECK_ERROR(_readu8_array_32(c, &m->call_hash))
    return parser_ok;
}


parser_error_t _readMethodBasic(
    parser_context_t *c,
    uint8_t moduleIdx,
    uint8_t callIdx,
    pd_MethodBasic_t *method) {
    uint16_t callPrivIdx = ( (uint16_t) moduleIdx << 8u) + callIdx;

    switch(callPrivIdx) {
        case 0: /* module 0 call 0 */
            CHECK_ERROR(_readMethod_system_fill_block(c, &method->system_fill_block))
            break;
        case 1: /* module 0 call 1 */
            CHECK_ERROR(_readMethod_system_remark(c, &method->system_remark))
            break;
        case 2: /* module 0 call 2 */
            CHECK_ERROR(_readMethod_system_set_heap_pages(c, &method->system_set_heap_pages))
            break;
        case 3: /* module 0 call 3 */
            CHECK_ERROR(_readMethod_system_set_code(c, &method->system_set_code))
            break;
        case 4: /* module 0 call 4 */
            CHECK_ERROR(_readMethod_system_set_code_without_checks(c, &method->system_set_code_without_checks))
            break;
        case 5: /* module 0 call 5 */
            CHECK_ERROR(_readMethod_system_set_changes_trie_config(c, &method->system_set_changes_trie_config))
            break;
        case 6: /* module 0 call 6 */
            CHECK_ERROR(_readMethod_system_set_storage(c, &method->system_set_storage))
            break;
        case 7: /* module 0 call 7 */
            CHECK_ERROR(_readMethod_system_kill_storage(c, &method->system_kill_storage))
            break;
        case 8: /* module 0 call 8 */
            CHECK_ERROR(_readMethod_system_kill_prefix(c, &method->system_kill_prefix))
            break;
        case 9: /* module 0 call 9 */
            CHECK_ERROR(_readMethod_system_suicide(c, &method->system_suicide))
            break;
        case 512: /* module 2 call 0 */
            CHECK_ERROR(_readMethod_timestamp_set(c, &method->timestamp_set))
            break;
        case 768: /* module 3 call 0 */
            CHECK_ERROR(_readMethod_indices_claim(c, &method->indices_claim))
            break;
        case 769: /* module 3 call 1 */
            CHECK_ERROR(_readMethod_indices_transfer(c, &method->indices_transfer))
            break;
        case 770: /* module 3 call 2 */
            CHECK_ERROR(_readMethod_indices_free(c, &method->indices_free))
            break;
        case 771: /* module 3 call 3 */
            CHECK_ERROR(_readMethod_indices_force_transfer(c, &method->indices_force_transfer))
            break;
        case 772: /* module 3 call 4 */
            CHECK_ERROR(_readMethod_indices_freeze(c, &method->indices_freeze))
            break;
        case 1024: /* module 4 call 0 */
            CHECK_ERROR(_readMethod_balances_transfer(c, &method->balances_transfer))
            break;
        case 1025: /* module 4 call 1 */
            CHECK_ERROR(_readMethod_balances_set_balance(c, &method->balances_set_balance))
            break;
        case 1026: /* module 4 call 2 */
            CHECK_ERROR(_readMethod_balances_force_transfer(c, &method->balances_force_transfer))
            break;
        case 1027: /* module 4 call 3 */
            CHECK_ERROR(_readMethod_balances_transfer_keep_alive(c, &method->balances_transfer_keep_alive))
            break;
        case 1280: /* module 5 call 0 */
            CHECK_ERROR(_readMethod_authorship_set_uncles(c, &method->authorship_set_uncles))
            break;
        case 1536: /* module 6 call 0 */
            CHECK_ERROR(_readMethod_staking_bond(c, &method->staking_bond))
            break;
        case 1537: /* module 6 call 1 */
            CHECK_ERROR(_readMethod_staking_bond_extra(c, &method->staking_bond_extra))
            break;
        case 1538: /* module 6 call 2 */
            CHECK_ERROR(_readMethod_staking_unbond(c, &method->staking_unbond))
            break;
        case 1539: /* module 6 call 3 */
            CHECK_ERROR(_readMethod_staking_withdraw_unbonded(c, &method->staking_withdraw_unbonded))
            break;
        case 1540: /* module 6 call 4 */
            CHECK_ERROR(_readMethod_staking_validate(c, &method->staking_validate))
            break;
        case 1541: /* module 6 call 5 */
            CHECK_ERROR(_readMethod_staking_nominate(c, &method->staking_nominate))
            break;
        case 1542: /* module 6 call 6 */
            CHECK_ERROR(_readMethod_staking_chill(c, &method->staking_chill))
            break;
        case 1543: /* module 6 call 7 */
            CHECK_ERROR(_readMethod_staking_set_payee(c, &method->staking_set_payee))
            break;
        case 1544: /* module 6 call 8 */
            CHECK_ERROR(_readMethod_staking_set_controller(c, &method->staking_set_controller))
            break;
        case 1545: /* module 6 call 9 */
            CHECK_ERROR(_readMethod_staking_set_validator_count(c, &method->staking_set_validator_count))
            break;
        case 1546: /* module 6 call 10 */
            CHECK_ERROR(_readMethod_staking_force_no_eras(c, &method->staking_force_no_eras))
            break;
        case 1547: /* module 6 call 11 */
            CHECK_ERROR(_readMethod_staking_force_new_era(c, &method->staking_force_new_era))
            break;
        case 1548: /* module 6 call 12 */
            CHECK_ERROR(_readMethod_staking_set_invulnerables(c, &method->staking_set_invulnerables))
            break;
        case 1549: /* module 6 call 13 */
            CHECK_ERROR(_readMethod_staking_force_unstake(c, &method->staking_force_unstake))
            break;
        case 1550: /* module 6 call 14 */
            CHECK_ERROR(_readMethod_staking_force_new_era_always(c, &method->staking_force_new_era_always))
            break;
        case 1551: /* module 6 call 15 */
            CHECK_ERROR(_readMethod_staking_cancel_deferred_slash(c, &method->staking_cancel_deferred_slash))
            break;
        case 1552: /* module 6 call 16 */
            CHECK_ERROR(_readMethod_staking_payout_stakers(c, &method->staking_payout_stakers))
            break;
        case 1553: /* module 6 call 17 */
            CHECK_ERROR(_readMethod_staking_rebond(c, &method->staking_rebond))
            break;
        case 1554: /* module 6 call 18 */
            CHECK_ERROR(_readMethod_staking_set_history_depth(c, &method->staking_set_history_depth))
            break;
        case 1555: /* module 6 call 19 */
            CHECK_ERROR(_readMethod_staking_reap_stash(c, &method->staking_reap_stash))
            break;
        case 1556: /* module 6 call 20 */
            CHECK_ERROR(_readMethod_staking_submit_election_solution(c, &method->staking_submit_election_solution))
            break;
        case 1557: /* module 6 call 21 */
            CHECK_ERROR(_readMethod_staking_submit_election_solution_unsigned(c, &method->staking_submit_election_solution_unsigned))
            break;
        case 2048: /* module 8 call 0 */
            CHECK_ERROR(_readMethod_session_set_keys(c, &method->session_set_keys))
            break;
        case 2049: /* module 8 call 1 */
            CHECK_ERROR(_readMethod_session_purge_keys(c, &method->session_purge_keys))
            break;
        case 2304: /* module 9 call 0 */
            CHECK_ERROR(_readMethod_finalitytracker_final_hint(c, &method->finalitytracker_final_hint))
            break;
        case 2560: /* module 10 call 0 */
            CHECK_ERROR(_readMethod_grandpa_report_equivocation(c, &method->grandpa_report_equivocation))
            break;
        case 2816: /* module 11 call 0 */
            CHECK_ERROR(_readMethod_imonline_heartbeat(c, &method->imonline_heartbeat))
            break;
        case 3328: /* module 13 call 0 */
            CHECK_ERROR(_readMethod_democracy_propose(c, &method->democracy_propose))
            break;
        case 3329: /* module 13 call 1 */
            CHECK_ERROR(_readMethod_democracy_second(c, &method->democracy_second))
            break;
        case 3330: /* module 13 call 2 */
            CHECK_ERROR(_readMethod_democracy_vote(c, &method->democracy_vote))
            break;
        case 3331: /* module 13 call 3 */
            CHECK_ERROR(_readMethod_democracy_emergency_cancel(c, &method->democracy_emergency_cancel))
            break;
        case 3332: /* module 13 call 4 */
            CHECK_ERROR(_readMethod_democracy_external_propose(c, &method->democracy_external_propose))
            break;
        case 3333: /* module 13 call 5 */
            CHECK_ERROR(_readMethod_democracy_external_propose_majority(c, &method->democracy_external_propose_majority))
            break;
        case 3334: /* module 13 call 6 */
            CHECK_ERROR(_readMethod_democracy_external_propose_default(c, &method->democracy_external_propose_default))
            break;
        case 3335: /* module 13 call 7 */
            CHECK_ERROR(_readMethod_democracy_fast_track(c, &method->democracy_fast_track))
            break;
        case 3336: /* module 13 call 8 */
            CHECK_ERROR(_readMethod_democracy_veto_external(c, &method->democracy_veto_external))
            break;
        case 3337: /* module 13 call 9 */
            CHECK_ERROR(_readMethod_democracy_cancel_referendum(c, &method->democracy_cancel_referendum))
            break;
        case 3338: /* module 13 call 10 */
            CHECK_ERROR(_readMethod_democracy_cancel_queued(c, &method->democracy_cancel_queued))
            break;
        case 3339: /* module 13 call 11 */
            CHECK_ERROR(_readMethod_democracy_delegate(c, &method->democracy_delegate))
            break;
        case 3340: /* module 13 call 12 */
            CHECK_ERROR(_readMethod_democracy_undelegate(c, &method->democracy_undelegate))
            break;
        case 3341: /* module 13 call 13 */
            CHECK_ERROR(_readMethod_democracy_clear_public_proposals(c, &method->democracy_clear_public_proposals))
            break;
        case 3342: /* module 13 call 14 */
            CHECK_ERROR(_readMethod_democracy_note_preimage(c, &method->democracy_note_preimage))
            break;
        case 3343: /* module 13 call 15 */
            CHECK_ERROR(_readMethod_democracy_note_preimage_operational(c, &method->democracy_note_preimage_operational))
            break;
        case 3344: /* module 13 call 16 */
            CHECK_ERROR(_readMethod_democracy_note_imminent_preimage(c, &method->democracy_note_imminent_preimage))
            break;
        case 3345: /* module 13 call 17 */
            CHECK_ERROR(_readMethod_democracy_note_imminent_preimage_operational(c, &method->democracy_note_imminent_preimage_operational))
            break;
        case 3346: /* module 13 call 18 */
            CHECK_ERROR(_readMethod_democracy_reap_preimage(c, &method->democracy_reap_preimage))
            break;
        case 3347: /* module 13 call 19 */
            CHECK_ERROR(_readMethod_democracy_unlock(c, &method->democracy_unlock))
            break;
        case 3348: /* module 13 call 20 */
            CHECK_ERROR(_readMethod_democracy_remove_vote(c, &method->democracy_remove_vote))
            break;
        case 3349: /* module 13 call 21 */
            CHECK_ERROR(_readMethod_democracy_remove_other_vote(c, &method->democracy_remove_other_vote))
            break;
        case 3350: /* module 13 call 22 */
            CHECK_ERROR(_readMethod_democracy_enact_proposal(c, &method->democracy_enact_proposal))
            break;
        case 3584: /* module 14 call 0 */
            CHECK_ERROR(_readMethod_council_set_members(c, &method->council_set_members))
            break;
        case 3587: /* module 14 call 3 */
            CHECK_ERROR(_readMethod_council_vote(c, &method->council_vote))
            break;
        case 3588: /* module 14 call 4 */
            CHECK_ERROR(_readMethod_council_close(c, &method->council_close))
            break;
        case 3589: /* module 14 call 5 */
            CHECK_ERROR(_readMethod_council_disapprove_proposal(c, &method->council_disapprove_proposal))
            break;
        case 3840: /* module 15 call 0 */
            CHECK_ERROR(_readMethod_technicalcommittee_set_members(c, &method->technicalcommittee_set_members))
            break;
        case 3843: /* module 15 call 3 */
            CHECK_ERROR(_readMethod_technicalcommittee_vote(c, &method->technicalcommittee_vote))
            break;
        case 3844: /* module 15 call 4 */
            CHECK_ERROR(_readMethod_technicalcommittee_close(c, &method->technicalcommittee_close))
            break;
        case 3845: /* module 15 call 5 */
            CHECK_ERROR(_readMethod_technicalcommittee_disapprove_proposal(c, &method->technicalcommittee_disapprove_proposal))
            break;
        case 4096: /* module 16 call 0 */
            CHECK_ERROR(_readMethod_electionsphragmen_vote(c, &method->electionsphragmen_vote))
            break;
        case 4097: /* module 16 call 1 */
            CHECK_ERROR(_readMethod_electionsphragmen_remove_voter(c, &method->electionsphragmen_remove_voter))
            break;
        case 4098: /* module 16 call 2 */
            CHECK_ERROR(_readMethod_electionsphragmen_report_defunct_voter(c, &method->electionsphragmen_report_defunct_voter))
            break;
        case 4099: /* module 16 call 3 */
            CHECK_ERROR(_readMethod_electionsphragmen_submit_candidacy(c, &method->electionsphragmen_submit_candidacy))
            break;
        case 4100: /* module 16 call 4 */
            CHECK_ERROR(_readMethod_electionsphragmen_renounce_candidacy(c, &method->electionsphragmen_renounce_candidacy))
            break;
        case 4101: /* module 16 call 5 */
            CHECK_ERROR(_readMethod_electionsphragmen_remove_member(c, &method->electionsphragmen_remove_member))
            break;
        case 4352: /* module 17 call 0 */
            CHECK_ERROR(_readMethod_technicalmembership_add_member(c, &method->technicalmembership_add_member))
            break;
        case 4353: /* module 17 call 1 */
            CHECK_ERROR(_readMethod_technicalmembership_remove_member(c, &method->technicalmembership_remove_member))
            break;
        case 4354: /* module 17 call 2 */
            CHECK_ERROR(_readMethod_technicalmembership_swap_member(c, &method->technicalmembership_swap_member))
            break;
        case 4355: /* module 17 call 3 */
            CHECK_ERROR(_readMethod_technicalmembership_reset_members(c, &method->technicalmembership_reset_members))
            break;
        case 4356: /* module 17 call 4 */
            CHECK_ERROR(_readMethod_technicalmembership_change_key(c, &method->technicalmembership_change_key))
            break;
        case 4357: /* module 17 call 5 */
            CHECK_ERROR(_readMethod_technicalmembership_set_prime(c, &method->technicalmembership_set_prime))
            break;
        case 4358: /* module 17 call 6 */
            CHECK_ERROR(_readMethod_technicalmembership_clear_prime(c, &method->technicalmembership_clear_prime))
            break;
        case 4608: /* module 18 call 0 */
            CHECK_ERROR(_readMethod_treasury_propose_spend(c, &method->treasury_propose_spend))
            break;
        case 4609: /* module 18 call 1 */
            CHECK_ERROR(_readMethod_treasury_reject_proposal(c, &method->treasury_reject_proposal))
            break;
        case 4610: /* module 18 call 2 */
            CHECK_ERROR(_readMethod_treasury_approve_proposal(c, &method->treasury_approve_proposal))
            break;
        case 4611: /* module 18 call 3 */
            CHECK_ERROR(_readMethod_treasury_report_awesome(c, &method->treasury_report_awesome))
            break;
        case 4612: /* module 18 call 4 */
            CHECK_ERROR(_readMethod_treasury_retract_tip(c, &method->treasury_retract_tip))
            break;
        case 4613: /* module 18 call 5 */
            CHECK_ERROR(_readMethod_treasury_tip_new(c, &method->treasury_tip_new))
            break;
        case 4614: /* module 18 call 6 */
            CHECK_ERROR(_readMethod_treasury_tip(c, &method->treasury_tip))
            break;
        case 4615: /* module 18 call 7 */
            CHECK_ERROR(_readMethod_treasury_close_tip(c, &method->treasury_close_tip))
            break;
        case 4864: /* module 19 call 0 */
            CHECK_ERROR(_readMethod_claims_claim(c, &method->claims_claim))
            break;
        case 4865: /* module 19 call 1 */
            CHECK_ERROR(_readMethod_claims_mint_claim(c, &method->claims_mint_claim))
            break;
        case 4866: /* module 19 call 2 */
            CHECK_ERROR(_readMethod_claims_claim_attest(c, &method->claims_claim_attest))
            break;
        case 4867: /* module 19 call 3 */
            CHECK_ERROR(_readMethod_claims_attest(c, &method->claims_attest))
            break;
        case 4868: /* module 19 call 4 */
            CHECK_ERROR(_readMethod_claims_move_claim(c, &method->claims_move_claim))
            break;
        case 5120: /* module 20 call 0 */
            CHECK_ERROR(_readMethod_parachains_set_heads(c, &method->parachains_set_heads))
            break;
        case 5121: /* module 20 call 1 */
            CHECK_ERROR(_readMethod_parachains_report_double_vote(c, &method->parachains_report_double_vote))
            break;
        case 5376: /* module 21 call 0 */
            CHECK_ERROR(_readMethod_attestations_more_attestations(c, &method->attestations_more_attestations))
            break;
        case 5632: /* module 22 call 0 */
            CHECK_ERROR(_readMethod_slots_new_auction(c, &method->slots_new_auction))
            break;
        case 5633: /* module 22 call 1 */
            CHECK_ERROR(_readMethod_slots_bid(c, &method->slots_bid))
            break;
        case 5634: /* module 22 call 2 */
            CHECK_ERROR(_readMethod_slots_bid_renew(c, &method->slots_bid_renew))
            break;
        case 5635: /* module 22 call 3 */
            CHECK_ERROR(_readMethod_slots_set_offboarding(c, &method->slots_set_offboarding))
            break;
        case 5636: /* module 22 call 4 */
            CHECK_ERROR(_readMethod_slots_fix_deploy_data(c, &method->slots_fix_deploy_data))
            break;
        case 5637: /* module 22 call 5 */
            CHECK_ERROR(_readMethod_slots_elaborate_deploy_data(c, &method->slots_elaborate_deploy_data))
            break;
        case 5888: /* module 23 call 0 */
            CHECK_ERROR(_readMethod_registrar_register_para(c, &method->registrar_register_para))
            break;
        case 5889: /* module 23 call 1 */
            CHECK_ERROR(_readMethod_registrar_deregister_para(c, &method->registrar_deregister_para))
            break;
        case 5890: /* module 23 call 2 */
            CHECK_ERROR(_readMethod_registrar_set_thread_count(c, &method->registrar_set_thread_count))
            break;
        case 5891: /* module 23 call 3 */
            CHECK_ERROR(_readMethod_registrar_register_parathread(c, &method->registrar_register_parathread))
            break;
        case 5892: /* module 23 call 4 */
            CHECK_ERROR(_readMethod_registrar_select_parathread(c, &method->registrar_select_parathread))
            break;
        case 5893: /* module 23 call 5 */
            CHECK_ERROR(_readMethod_registrar_deregister_parathread(c, &method->registrar_deregister_parathread))
            break;
        case 5894: /* module 23 call 6 */
            CHECK_ERROR(_readMethod_registrar_swap(c, &method->registrar_swap))
            break;
        case 6144: /* module 24 call 0 */
            CHECK_ERROR(_readMethod_utility_batch(c, &method->utility_batch))
            break;
        case 6145: /* module 24 call 1 */
            CHECK_ERROR(_readMethod_utility_as_sub(c, &method->utility_as_sub))
            break;
        case 6146: /* module 24 call 2 */
            CHECK_ERROR(_readMethod_utility_as_limited_sub(c, &method->utility_as_limited_sub))
            break;
        case 6400: /* module 25 call 0 */
            CHECK_ERROR(_readMethod_identity_add_registrar(c, &method->identity_add_registrar))
            break;
        case 6401: /* module 25 call 1 */
            CHECK_ERROR(_readMethod_identity_set_identity(c, &method->identity_set_identity))
            break;
        case 6402: /* module 25 call 2 */
            CHECK_ERROR(_readMethod_identity_set_subs(c, &method->identity_set_subs))
            break;
        case 6403: /* module 25 call 3 */
            CHECK_ERROR(_readMethod_identity_clear_identity(c, &method->identity_clear_identity))
            break;
        case 6404: /* module 25 call 4 */
            CHECK_ERROR(_readMethod_identity_request_judgement(c, &method->identity_request_judgement))
            break;
        case 6405: /* module 25 call 5 */
            CHECK_ERROR(_readMethod_identity_cancel_request(c, &method->identity_cancel_request))
            break;
        case 6406: /* module 25 call 6 */
            CHECK_ERROR(_readMethod_identity_set_fee(c, &method->identity_set_fee))
            break;
        case 6407: /* module 25 call 7 */
            CHECK_ERROR(_readMethod_identity_set_account_id(c, &method->identity_set_account_id))
            break;
        case 6408: /* module 25 call 8 */
            CHECK_ERROR(_readMethod_identity_set_fields(c, &method->identity_set_fields))
            break;
        case 6409: /* module 25 call 9 */
            CHECK_ERROR(_readMethod_identity_provide_judgement(c, &method->identity_provide_judgement))
            break;
        case 6410: /* module 25 call 10 */
            CHECK_ERROR(_readMethod_identity_kill_identity(c, &method->identity_kill_identity))
            break;
        case 6656: /* module 26 call 0 */
            CHECK_ERROR(_readMethod_society_bid(c, &method->society_bid))
            break;
        case 6657: /* module 26 call 1 */
            CHECK_ERROR(_readMethod_society_unbid(c, &method->society_unbid))
            break;
        case 6658: /* module 26 call 2 */
            CHECK_ERROR(_readMethod_society_vouch(c, &method->society_vouch))
            break;
        case 6659: /* module 26 call 3 */
            CHECK_ERROR(_readMethod_society_unvouch(c, &method->society_unvouch))
            break;
        case 6660: /* module 26 call 4 */
            CHECK_ERROR(_readMethod_society_vote(c, &method->society_vote))
            break;
        case 6661: /* module 26 call 5 */
            CHECK_ERROR(_readMethod_society_defender_vote(c, &method->society_defender_vote))
            break;
        case 6662: /* module 26 call 6 */
            CHECK_ERROR(_readMethod_society_payout(c, &method->society_payout))
            break;
        case 6663: /* module 26 call 7 */
            CHECK_ERROR(_readMethod_society_found(c, &method->society_found))
            break;
        case 6664: /* module 26 call 8 */
            CHECK_ERROR(_readMethod_society_unfound(c, &method->society_unfound))
            break;
        case 6665: /* module 26 call 9 */
            CHECK_ERROR(_readMethod_society_judge_suspended_member(c, &method->society_judge_suspended_member))
            break;
        case 6666: /* module 26 call 10 */
            CHECK_ERROR(_readMethod_society_judge_suspended_candidate(c, &method->society_judge_suspended_candidate))
            break;
        case 6667: /* module 26 call 11 */
            CHECK_ERROR(_readMethod_society_set_max_members(c, &method->society_set_max_members))
            break;
        case 6912: /* module 27 call 0 */
            CHECK_ERROR(_readMethod_recovery_as_recovered(c, &method->recovery_as_recovered))
            break;
        case 6913: /* module 27 call 1 */
            CHECK_ERROR(_readMethod_recovery_set_recovered(c, &method->recovery_set_recovered))
            break;
        case 6914: /* module 27 call 2 */
            CHECK_ERROR(_readMethod_recovery_create_recovery(c, &method->recovery_create_recovery))
            break;
        case 6915: /* module 27 call 3 */
            CHECK_ERROR(_readMethod_recovery_initiate_recovery(c, &method->recovery_initiate_recovery))
            break;
        case 6916: /* module 27 call 4 */
            CHECK_ERROR(_readMethod_recovery_vouch_recovery(c, &method->recovery_vouch_recovery))
            break;
        case 6917: /* module 27 call 5 */
            CHECK_ERROR(_readMethod_recovery_claim_recovery(c, &method->recovery_claim_recovery))
            break;
        case 6918: /* module 27 call 6 */
            CHECK_ERROR(_readMethod_recovery_close_recovery(c, &method->recovery_close_recovery))
            break;
        case 6919: /* module 27 call 7 */
            CHECK_ERROR(_readMethod_recovery_remove_recovery(c, &method->recovery_remove_recovery))
            break;
        case 6920: /* module 27 call 8 */
            CHECK_ERROR(_readMethod_recovery_cancel_recovered(c, &method->recovery_cancel_recovered))
            break;
        case 7168: /* module 28 call 0 */
            CHECK_ERROR(_readMethod_vesting_vest(c, &method->vesting_vest))
            break;
        case 7169: /* module 28 call 1 */
            CHECK_ERROR(_readMethod_vesting_vest_other(c, &method->vesting_vest_other))
            break;
        case 7170: /* module 28 call 2 */
            CHECK_ERROR(_readMethod_vesting_vested_transfer(c, &method->vesting_vested_transfer))
            break;
        case 7424: /* module 29 call 0 */
            CHECK_ERROR(_readMethod_scheduler_schedule(c, &method->scheduler_schedule))
            break;
        case 7425: /* module 29 call 1 */
            CHECK_ERROR(_readMethod_scheduler_cancel(c, &method->scheduler_cancel))
            break;
        case 7426: /* module 29 call 2 */
            CHECK_ERROR(_readMethod_scheduler_schedule_named(c, &method->scheduler_schedule_named))
            break;
        case 7427: /* module 29 call 3 */
            CHECK_ERROR(_readMethod_scheduler_cancel_named(c, &method->scheduler_cancel_named))
            break;
        case 7680: /* module 30 call 0 */
            CHECK_ERROR(_readMethod_proxy_proxy(c, &method->proxy_proxy))
            break;
        case 7681: /* module 30 call 1 */
            CHECK_ERROR(_readMethod_proxy_add_proxy(c, &method->proxy_add_proxy))
            break;
        case 7682: /* module 30 call 2 */
            CHECK_ERROR(_readMethod_proxy_remove_proxy(c, &method->proxy_remove_proxy))
            break;
        case 7683: /* module 30 call 3 */
            CHECK_ERROR(_readMethod_proxy_remove_proxies(c, &method->proxy_remove_proxies))
            break;
        case 7684: /* module 30 call 4 */
            CHECK_ERROR(_readMethod_proxy_anonymous(c, &method->proxy_anonymous))
            break;
        case 7685: /* module 30 call 5 */
            CHECK_ERROR(_readMethod_proxy_kill_anonymous(c, &method->proxy_kill_anonymous))
            break;
        case 7936: /* module 31 call 0 */
            CHECK_ERROR(_readMethod_multisig_as_multi(c, &method->multisig_as_multi))
            break;
        case 7937: /* module 31 call 1 */
            CHECK_ERROR(_readMethod_multisig_approve_as_multi(c, &method->multisig_approve_as_multi))
            break;
        case 7938: /* module 31 call 2 */
            CHECK_ERROR(_readMethod_multisig_cancel_as_multi(c, &method->multisig_cancel_as_multi))
            break;
    default:
    return parser_unexpected_callIndex;
    }

    return parser_ok;
}

parser_error_t _readMethod(
    parser_context_t *c,
    uint8_t moduleIdx,
    uint8_t callIdx,
    pd_Method_t *method) {
    uint16_t callPrivIdx = ( (uint16_t) moduleIdx << 8u) + callIdx;

    switch(callPrivIdx) {
        case 0: /* module 0 call 0 */
            CHECK_ERROR(_readMethod_system_fill_block(c, &method->basic.system_fill_block))
            break;
        case 1: /* module 0 call 1 */
            CHECK_ERROR(_readMethod_system_remark(c, &method->basic.system_remark))
            break;
        case 2: /* module 0 call 2 */
            CHECK_ERROR(_readMethod_system_set_heap_pages(c, &method->basic.system_set_heap_pages))
            break;
        case 3: /* module 0 call 3 */
            CHECK_ERROR(_readMethod_system_set_code(c, &method->basic.system_set_code))
            break;
        case 4: /* module 0 call 4 */
            CHECK_ERROR(_readMethod_system_set_code_without_checks(c, &method->basic.system_set_code_without_checks))
            break;
        case 5: /* module 0 call 5 */
            CHECK_ERROR(_readMethod_system_set_changes_trie_config(c, &method->basic.system_set_changes_trie_config))
            break;
        case 6: /* module 0 call 6 */
            CHECK_ERROR(_readMethod_system_set_storage(c, &method->basic.system_set_storage))
            break;
        case 7: /* module 0 call 7 */
            CHECK_ERROR(_readMethod_system_kill_storage(c, &method->basic.system_kill_storage))
            break;
        case 8: /* module 0 call 8 */
            CHECK_ERROR(_readMethod_system_kill_prefix(c, &method->basic.system_kill_prefix))
            break;
        case 9: /* module 0 call 9 */
            CHECK_ERROR(_readMethod_system_suicide(c, &method->basic.system_suicide))
            break;
        case 512: /* module 2 call 0 */
            CHECK_ERROR(_readMethod_timestamp_set(c, &method->basic.timestamp_set))
            break;
        case 768: /* module 3 call 0 */
            CHECK_ERROR(_readMethod_indices_claim(c, &method->basic.indices_claim))
            break;
        case 769: /* module 3 call 1 */
            CHECK_ERROR(_readMethod_indices_transfer(c, &method->basic.indices_transfer))
            break;
        case 770: /* module 3 call 2 */
            CHECK_ERROR(_readMethod_indices_free(c, &method->basic.indices_free))
            break;
        case 771: /* module 3 call 3 */
            CHECK_ERROR(_readMethod_indices_force_transfer(c, &method->basic.indices_force_transfer))
            break;
        case 772: /* module 3 call 4 */
            CHECK_ERROR(_readMethod_indices_freeze(c, &method->basic.indices_freeze))
            break;
        case 1024: /* module 4 call 0 */
            CHECK_ERROR(_readMethod_balances_transfer(c, &method->basic.balances_transfer))
            break;
        case 1025: /* module 4 call 1 */
            CHECK_ERROR(_readMethod_balances_set_balance(c, &method->basic.balances_set_balance))
            break;
        case 1026: /* module 4 call 2 */
            CHECK_ERROR(_readMethod_balances_force_transfer(c, &method->basic.balances_force_transfer))
            break;
        case 1027: /* module 4 call 3 */
            CHECK_ERROR(_readMethod_balances_transfer_keep_alive(c, &method->basic.balances_transfer_keep_alive))
            break;
        case 1280: /* module 5 call 0 */
            CHECK_ERROR(_readMethod_authorship_set_uncles(c, &method->basic.authorship_set_uncles))
            break;
        case 1536: /* module 6 call 0 */
            CHECK_ERROR(_readMethod_staking_bond(c, &method->basic.staking_bond))
            break;
        case 1537: /* module 6 call 1 */
            CHECK_ERROR(_readMethod_staking_bond_extra(c, &method->basic.staking_bond_extra))
            break;
        case 1538: /* module 6 call 2 */
            CHECK_ERROR(_readMethod_staking_unbond(c, &method->basic.staking_unbond))
            break;
        case 1539: /* module 6 call 3 */
            CHECK_ERROR(_readMethod_staking_withdraw_unbonded(c, &method->basic.staking_withdraw_unbonded))
            break;
        case 1540: /* module 6 call 4 */
            CHECK_ERROR(_readMethod_staking_validate(c, &method->basic.staking_validate))
            break;
        case 1541: /* module 6 call 5 */
            CHECK_ERROR(_readMethod_staking_nominate(c, &method->basic.staking_nominate))
            break;
        case 1542: /* module 6 call 6 */
            CHECK_ERROR(_readMethod_staking_chill(c, &method->basic.staking_chill))
            break;
        case 1543: /* module 6 call 7 */
            CHECK_ERROR(_readMethod_staking_set_payee(c, &method->basic.staking_set_payee))
            break;
        case 1544: /* module 6 call 8 */
            CHECK_ERROR(_readMethod_staking_set_controller(c, &method->basic.staking_set_controller))
            break;
        case 1545: /* module 6 call 9 */
            CHECK_ERROR(_readMethod_staking_set_validator_count(c, &method->basic.staking_set_validator_count))
            break;
        case 1546: /* module 6 call 10 */
            CHECK_ERROR(_readMethod_staking_force_no_eras(c, &method->basic.staking_force_no_eras))
            break;
        case 1547: /* module 6 call 11 */
            CHECK_ERROR(_readMethod_staking_force_new_era(c, &method->basic.staking_force_new_era))
            break;
        case 1548: /* module 6 call 12 */
            CHECK_ERROR(_readMethod_staking_set_invulnerables(c, &method->basic.staking_set_invulnerables))
            break;
        case 1549: /* module 6 call 13 */
            CHECK_ERROR(_readMethod_staking_force_unstake(c, &method->basic.staking_force_unstake))
            break;
        case 1550: /* module 6 call 14 */
            CHECK_ERROR(_readMethod_staking_force_new_era_always(c, &method->basic.staking_force_new_era_always))
            break;
        case 1551: /* module 6 call 15 */
            CHECK_ERROR(_readMethod_staking_cancel_deferred_slash(c, &method->basic.staking_cancel_deferred_slash))
            break;
        case 1552: /* module 6 call 16 */
            CHECK_ERROR(_readMethod_staking_payout_stakers(c, &method->basic.staking_payout_stakers))
            break;
        case 1553: /* module 6 call 17 */
            CHECK_ERROR(_readMethod_staking_rebond(c, &method->basic.staking_rebond))
            break;
        case 1554: /* module 6 call 18 */
            CHECK_ERROR(_readMethod_staking_set_history_depth(c, &method->basic.staking_set_history_depth))
            break;
        case 1555: /* module 6 call 19 */
            CHECK_ERROR(_readMethod_staking_reap_stash(c, &method->basic.staking_reap_stash))
            break;
        case 1556: /* module 6 call 20 */
            CHECK_ERROR(_readMethod_staking_submit_election_solution(c, &method->basic.staking_submit_election_solution))
            break;
        case 1557: /* module 6 call 21 */
            CHECK_ERROR(_readMethod_staking_submit_election_solution_unsigned(c, &method->basic.staking_submit_election_solution_unsigned))
            break;
        case 2048: /* module 8 call 0 */
            CHECK_ERROR(_readMethod_session_set_keys(c, &method->basic.session_set_keys))
            break;
        case 2049: /* module 8 call 1 */
            CHECK_ERROR(_readMethod_session_purge_keys(c, &method->basic.session_purge_keys))
            break;
        case 2304: /* module 9 call 0 */
            CHECK_ERROR(_readMethod_finalitytracker_final_hint(c, &method->basic.finalitytracker_final_hint))
            break;
        case 2560: /* module 10 call 0 */
            CHECK_ERROR(_readMethod_grandpa_report_equivocation(c, &method->basic.grandpa_report_equivocation))
            break;
        case 2816: /* module 11 call 0 */
            CHECK_ERROR(_readMethod_imonline_heartbeat(c, &method->basic.imonline_heartbeat))
            break;
        case 3328: /* module 13 call 0 */
            CHECK_ERROR(_readMethod_democracy_propose(c, &method->basic.democracy_propose))
            break;
        case 3329: /* module 13 call 1 */
            CHECK_ERROR(_readMethod_democracy_second(c, &method->basic.democracy_second))
            break;
        case 3330: /* module 13 call 2 */
            CHECK_ERROR(_readMethod_democracy_vote(c, &method->basic.democracy_vote))
            break;
        case 3331: /* module 13 call 3 */
            CHECK_ERROR(_readMethod_democracy_emergency_cancel(c, &method->basic.democracy_emergency_cancel))
            break;
        case 3332: /* module 13 call 4 */
            CHECK_ERROR(_readMethod_democracy_external_propose(c, &method->basic.democracy_external_propose))
            break;
        case 3333: /* module 13 call 5 */
            CHECK_ERROR(_readMethod_democracy_external_propose_majority(c, &method->basic.democracy_external_propose_majority))
            break;
        case 3334: /* module 13 call 6 */
            CHECK_ERROR(_readMethod_democracy_external_propose_default(c, &method->basic.democracy_external_propose_default))
            break;
        case 3335: /* module 13 call 7 */
            CHECK_ERROR(_readMethod_democracy_fast_track(c, &method->basic.democracy_fast_track))
            break;
        case 3336: /* module 13 call 8 */
            CHECK_ERROR(_readMethod_democracy_veto_external(c, &method->basic.democracy_veto_external))
            break;
        case 3337: /* module 13 call 9 */
            CHECK_ERROR(_readMethod_democracy_cancel_referendum(c, &method->basic.democracy_cancel_referendum))
            break;
        case 3338: /* module 13 call 10 */
            CHECK_ERROR(_readMethod_democracy_cancel_queued(c, &method->basic.democracy_cancel_queued))
            break;
        case 3339: /* module 13 call 11 */
            CHECK_ERROR(_readMethod_democracy_delegate(c, &method->basic.democracy_delegate))
            break;
        case 3340: /* module 13 call 12 */
            CHECK_ERROR(_readMethod_democracy_undelegate(c, &method->basic.democracy_undelegate))
            break;
        case 3341: /* module 13 call 13 */
            CHECK_ERROR(_readMethod_democracy_clear_public_proposals(c, &method->basic.democracy_clear_public_proposals))
            break;
        case 3342: /* module 13 call 14 */
            CHECK_ERROR(_readMethod_democracy_note_preimage(c, &method->basic.democracy_note_preimage))
            break;
        case 3343: /* module 13 call 15 */
            CHECK_ERROR(_readMethod_democracy_note_preimage_operational(c, &method->basic.democracy_note_preimage_operational))
            break;
        case 3344: /* module 13 call 16 */
            CHECK_ERROR(_readMethod_democracy_note_imminent_preimage(c, &method->basic.democracy_note_imminent_preimage))
            break;
        case 3345: /* module 13 call 17 */
            CHECK_ERROR(_readMethod_democracy_note_imminent_preimage_operational(c, &method->basic.democracy_note_imminent_preimage_operational))
            break;
        case 3346: /* module 13 call 18 */
            CHECK_ERROR(_readMethod_democracy_reap_preimage(c, &method->basic.democracy_reap_preimage))
            break;
        case 3347: /* module 13 call 19 */
            CHECK_ERROR(_readMethod_democracy_unlock(c, &method->basic.democracy_unlock))
            break;
        case 3348: /* module 13 call 20 */
            CHECK_ERROR(_readMethod_democracy_remove_vote(c, &method->basic.democracy_remove_vote))
            break;
        case 3349: /* module 13 call 21 */
            CHECK_ERROR(_readMethod_democracy_remove_other_vote(c, &method->basic.democracy_remove_other_vote))
            break;
        case 3350: /* module 13 call 22 */
            CHECK_ERROR(_readMethod_democracy_enact_proposal(c, &method->basic.democracy_enact_proposal))
            break;
        case 3584: /* module 14 call 0 */
            CHECK_ERROR(_readMethod_council_set_members(c, &method->basic.council_set_members))
            break;
        case 3585: /* module 14 call 1 */
            CHECK_ERROR(_readMethod_council_execute(c, &method->nested.council_execute))
            break;
        case 3586: /* module 14 call 2 */
            CHECK_ERROR(_readMethod_council_propose(c, &method->nested.council_propose))
            break;
        case 3587: /* module 14 call 3 */
            CHECK_ERROR(_readMethod_council_vote(c, &method->basic.council_vote))
            break;
        case 3588: /* module 14 call 4 */
            CHECK_ERROR(_readMethod_council_close(c, &method->basic.council_close))
            break;
        case 3589: /* module 14 call 5 */
            CHECK_ERROR(_readMethod_council_disapprove_proposal(c, &method->basic.council_disapprove_proposal))
            break;
        case 3840: /* module 15 call 0 */
            CHECK_ERROR(_readMethod_technicalcommittee_set_members(c, &method->basic.technicalcommittee_set_members))
            break;
        case 3841: /* module 15 call 1 */
            CHECK_ERROR(_readMethod_technicalcommittee_execute(c, &method->nested.technicalcommittee_execute))
            break;
        case 3842: /* module 15 call 2 */
            CHECK_ERROR(_readMethod_technicalcommittee_propose(c, &method->nested.technicalcommittee_propose))
            break;
        case 3843: /* module 15 call 3 */
            CHECK_ERROR(_readMethod_technicalcommittee_vote(c, &method->basic.technicalcommittee_vote))
            break;
        case 3844: /* module 15 call 4 */
            CHECK_ERROR(_readMethod_technicalcommittee_close(c, &method->basic.technicalcommittee_close))
            break;
        case 3845: /* module 15 call 5 */
            CHECK_ERROR(_readMethod_technicalcommittee_disapprove_proposal(c, &method->basic.technicalcommittee_disapprove_proposal))
            break;
        case 4096: /* module 16 call 0 */
            CHECK_ERROR(_readMethod_electionsphragmen_vote(c, &method->basic.electionsphragmen_vote))
            break;
        case 4097: /* module 16 call 1 */
            CHECK_ERROR(_readMethod_electionsphragmen_remove_voter(c, &method->basic.electionsphragmen_remove_voter))
            break;
        case 4098: /* module 16 call 2 */
            CHECK_ERROR(_readMethod_electionsphragmen_report_defunct_voter(c, &method->basic.electionsphragmen_report_defunct_voter))
            break;
        case 4099: /* module 16 call 3 */
            CHECK_ERROR(_readMethod_electionsphragmen_submit_candidacy(c, &method->basic.electionsphragmen_submit_candidacy))
            break;
        case 4100: /* module 16 call 4 */
            CHECK_ERROR(_readMethod_electionsphragmen_renounce_candidacy(c, &method->basic.electionsphragmen_renounce_candidacy))
            break;
        case 4101: /* module 16 call 5 */
            CHECK_ERROR(_readMethod_electionsphragmen_remove_member(c, &method->basic.electionsphragmen_remove_member))
            break;
        case 4352: /* module 17 call 0 */
            CHECK_ERROR(_readMethod_technicalmembership_add_member(c, &method->basic.technicalmembership_add_member))
            break;
        case 4353: /* module 17 call 1 */
            CHECK_ERROR(_readMethod_technicalmembership_remove_member(c, &method->basic.technicalmembership_remove_member))
            break;
        case 4354: /* module 17 call 2 */
            CHECK_ERROR(_readMethod_technicalmembership_swap_member(c, &method->basic.technicalmembership_swap_member))
            break;
        case 4355: /* module 17 call 3 */
            CHECK_ERROR(_readMethod_technicalmembership_reset_members(c, &method->basic.technicalmembership_reset_members))
            break;
        case 4356: /* module 17 call 4 */
            CHECK_ERROR(_readMethod_technicalmembership_change_key(c, &method->basic.technicalmembership_change_key))
            break;
        case 4357: /* module 17 call 5 */
            CHECK_ERROR(_readMethod_technicalmembership_set_prime(c, &method->basic.technicalmembership_set_prime))
            break;
        case 4358: /* module 17 call 6 */
            CHECK_ERROR(_readMethod_technicalmembership_clear_prime(c, &method->basic.technicalmembership_clear_prime))
            break;
        case 4608: /* module 18 call 0 */
            CHECK_ERROR(_readMethod_treasury_propose_spend(c, &method->basic.treasury_propose_spend))
            break;
        case 4609: /* module 18 call 1 */
            CHECK_ERROR(_readMethod_treasury_reject_proposal(c, &method->basic.treasury_reject_proposal))
            break;
        case 4610: /* module 18 call 2 */
            CHECK_ERROR(_readMethod_treasury_approve_proposal(c, &method->basic.treasury_approve_proposal))
            break;
        case 4611: /* module 18 call 3 */
            CHECK_ERROR(_readMethod_treasury_report_awesome(c, &method->basic.treasury_report_awesome))
            break;
        case 4612: /* module 18 call 4 */
            CHECK_ERROR(_readMethod_treasury_retract_tip(c, &method->basic.treasury_retract_tip))
            break;
        case 4613: /* module 18 call 5 */
            CHECK_ERROR(_readMethod_treasury_tip_new(c, &method->basic.treasury_tip_new))
            break;
        case 4614: /* module 18 call 6 */
            CHECK_ERROR(_readMethod_treasury_tip(c, &method->basic.treasury_tip))
            break;
        case 4615: /* module 18 call 7 */
            CHECK_ERROR(_readMethod_treasury_close_tip(c, &method->basic.treasury_close_tip))
            break;
        case 4864: /* module 19 call 0 */
            CHECK_ERROR(_readMethod_claims_claim(c, &method->basic.claims_claim))
            break;
        case 4865: /* module 19 call 1 */
            CHECK_ERROR(_readMethod_claims_mint_claim(c, &method->basic.claims_mint_claim))
            break;
        case 4866: /* module 19 call 2 */
            CHECK_ERROR(_readMethod_claims_claim_attest(c, &method->basic.claims_claim_attest))
            break;
        case 4867: /* module 19 call 3 */
            CHECK_ERROR(_readMethod_claims_attest(c, &method->basic.claims_attest))
            break;
        case 4868: /* module 19 call 4 */
            CHECK_ERROR(_readMethod_claims_move_claim(c, &method->basic.claims_move_claim))
            break;
        case 5120: /* module 20 call 0 */
            CHECK_ERROR(_readMethod_parachains_set_heads(c, &method->basic.parachains_set_heads))
            break;
        case 5121: /* module 20 call 1 */
            CHECK_ERROR(_readMethod_parachains_report_double_vote(c, &method->basic.parachains_report_double_vote))
            break;
        case 5376: /* module 21 call 0 */
            CHECK_ERROR(_readMethod_attestations_more_attestations(c, &method->basic.attestations_more_attestations))
            break;
        case 5632: /* module 22 call 0 */
            CHECK_ERROR(_readMethod_slots_new_auction(c, &method->basic.slots_new_auction))
            break;
        case 5633: /* module 22 call 1 */
            CHECK_ERROR(_readMethod_slots_bid(c, &method->basic.slots_bid))
            break;
        case 5634: /* module 22 call 2 */
            CHECK_ERROR(_readMethod_slots_bid_renew(c, &method->basic.slots_bid_renew))
            break;
        case 5635: /* module 22 call 3 */
            CHECK_ERROR(_readMethod_slots_set_offboarding(c, &method->basic.slots_set_offboarding))
            break;
        case 5636: /* module 22 call 4 */
            CHECK_ERROR(_readMethod_slots_fix_deploy_data(c, &method->basic.slots_fix_deploy_data))
            break;
        case 5637: /* module 22 call 5 */
            CHECK_ERROR(_readMethod_slots_elaborate_deploy_data(c, &method->basic.slots_elaborate_deploy_data))
            break;
        case 5888: /* module 23 call 0 */
            CHECK_ERROR(_readMethod_registrar_register_para(c, &method->basic.registrar_register_para))
            break;
        case 5889: /* module 23 call 1 */
            CHECK_ERROR(_readMethod_registrar_deregister_para(c, &method->basic.registrar_deregister_para))
            break;
        case 5890: /* module 23 call 2 */
            CHECK_ERROR(_readMethod_registrar_set_thread_count(c, &method->basic.registrar_set_thread_count))
            break;
        case 5891: /* module 23 call 3 */
            CHECK_ERROR(_readMethod_registrar_register_parathread(c, &method->basic.registrar_register_parathread))
            break;
        case 5892: /* module 23 call 4 */
            CHECK_ERROR(_readMethod_registrar_select_parathread(c, &method->basic.registrar_select_parathread))
            break;
        case 5893: /* module 23 call 5 */
            CHECK_ERROR(_readMethod_registrar_deregister_parathread(c, &method->basic.registrar_deregister_parathread))
            break;
        case 5894: /* module 23 call 6 */
            CHECK_ERROR(_readMethod_registrar_swap(c, &method->basic.registrar_swap))
            break;
        case 6144: /* module 24 call 0 */
            CHECK_ERROR(_readMethod_utility_batch(c, &method->basic.utility_batch))
            break;
        case 6145: /* module 24 call 1 */
            CHECK_ERROR(_readMethod_utility_as_sub(c, &method->basic.utility_as_sub))
            break;
        case 6146: /* module 24 call 2 */
            CHECK_ERROR(_readMethod_utility_as_limited_sub(c, &method->basic.utility_as_limited_sub))
            break;
        case 6400: /* module 25 call 0 */
            CHECK_ERROR(_readMethod_identity_add_registrar(c, &method->basic.identity_add_registrar))
            break;
        case 6401: /* module 25 call 1 */
            CHECK_ERROR(_readMethod_identity_set_identity(c, &method->basic.identity_set_identity))
            break;
        case 6402: /* module 25 call 2 */
            CHECK_ERROR(_readMethod_identity_set_subs(c, &method->basic.identity_set_subs))
            break;
        case 6403: /* module 25 call 3 */
            CHECK_ERROR(_readMethod_identity_clear_identity(c, &method->basic.identity_clear_identity))
            break;
        case 6404: /* module 25 call 4 */
            CHECK_ERROR(_readMethod_identity_request_judgement(c, &method->basic.identity_request_judgement))
            break;
        case 6405: /* module 25 call 5 */
            CHECK_ERROR(_readMethod_identity_cancel_request(c, &method->basic.identity_cancel_request))
            break;
        case 6406: /* module 25 call 6 */
            CHECK_ERROR(_readMethod_identity_set_fee(c, &method->basic.identity_set_fee))
            break;
        case 6407: /* module 25 call 7 */
            CHECK_ERROR(_readMethod_identity_set_account_id(c, &method->basic.identity_set_account_id))
            break;
        case 6408: /* module 25 call 8 */
            CHECK_ERROR(_readMethod_identity_set_fields(c, &method->basic.identity_set_fields))
            break;
        case 6409: /* module 25 call 9 */
            CHECK_ERROR(_readMethod_identity_provide_judgement(c, &method->basic.identity_provide_judgement))
            break;
        case 6410: /* module 25 call 10 */
            CHECK_ERROR(_readMethod_identity_kill_identity(c, &method->basic.identity_kill_identity))
            break;
        case 6656: /* module 26 call 0 */
            CHECK_ERROR(_readMethod_society_bid(c, &method->basic.society_bid))
            break;
        case 6657: /* module 26 call 1 */
            CHECK_ERROR(_readMethod_society_unbid(c, &method->basic.society_unbid))
            break;
        case 6658: /* module 26 call 2 */
            CHECK_ERROR(_readMethod_society_vouch(c, &method->basic.society_vouch))
            break;
        case 6659: /* module 26 call 3 */
            CHECK_ERROR(_readMethod_society_unvouch(c, &method->basic.society_unvouch))
            break;
        case 6660: /* module 26 call 4 */
            CHECK_ERROR(_readMethod_society_vote(c, &method->basic.society_vote))
            break;
        case 6661: /* module 26 call 5 */
            CHECK_ERROR(_readMethod_society_defender_vote(c, &method->basic.society_defender_vote))
            break;
        case 6662: /* module 26 call 6 */
            CHECK_ERROR(_readMethod_society_payout(c, &method->basic.society_payout))
            break;
        case 6663: /* module 26 call 7 */
            CHECK_ERROR(_readMethod_society_found(c, &method->basic.society_found))
            break;
        case 6664: /* module 26 call 8 */
            CHECK_ERROR(_readMethod_society_unfound(c, &method->basic.society_unfound))
            break;
        case 6665: /* module 26 call 9 */
            CHECK_ERROR(_readMethod_society_judge_suspended_member(c, &method->basic.society_judge_suspended_member))
            break;
        case 6666: /* module 26 call 10 */
            CHECK_ERROR(_readMethod_society_judge_suspended_candidate(c, &method->basic.society_judge_suspended_candidate))
            break;
        case 6667: /* module 26 call 11 */
            CHECK_ERROR(_readMethod_society_set_max_members(c, &method->basic.society_set_max_members))
            break;
        case 6912: /* module 27 call 0 */
            CHECK_ERROR(_readMethod_recovery_as_recovered(c, &method->basic.recovery_as_recovered))
            break;
        case 6913: /* module 27 call 1 */
            CHECK_ERROR(_readMethod_recovery_set_recovered(c, &method->basic.recovery_set_recovered))
            break;
        case 6914: /* module 27 call 2 */
            CHECK_ERROR(_readMethod_recovery_create_recovery(c, &method->basic.recovery_create_recovery))
            break;
        case 6915: /* module 27 call 3 */
            CHECK_ERROR(_readMethod_recovery_initiate_recovery(c, &method->basic.recovery_initiate_recovery))
            break;
        case 6916: /* module 27 call 4 */
            CHECK_ERROR(_readMethod_recovery_vouch_recovery(c, &method->basic.recovery_vouch_recovery))
            break;
        case 6917: /* module 27 call 5 */
            CHECK_ERROR(_readMethod_recovery_claim_recovery(c, &method->basic.recovery_claim_recovery))
            break;
        case 6918: /* module 27 call 6 */
            CHECK_ERROR(_readMethod_recovery_close_recovery(c, &method->basic.recovery_close_recovery))
            break;
        case 6919: /* module 27 call 7 */
            CHECK_ERROR(_readMethod_recovery_remove_recovery(c, &method->basic.recovery_remove_recovery))
            break;
        case 6920: /* module 27 call 8 */
            CHECK_ERROR(_readMethod_recovery_cancel_recovered(c, &method->basic.recovery_cancel_recovered))
            break;
        case 7168: /* module 28 call 0 */
            CHECK_ERROR(_readMethod_vesting_vest(c, &method->basic.vesting_vest))
            break;
        case 7169: /* module 28 call 1 */
            CHECK_ERROR(_readMethod_vesting_vest_other(c, &method->basic.vesting_vest_other))
            break;
        case 7170: /* module 28 call 2 */
            CHECK_ERROR(_readMethod_vesting_vested_transfer(c, &method->basic.vesting_vested_transfer))
            break;
        case 7424: /* module 29 call 0 */
            CHECK_ERROR(_readMethod_scheduler_schedule(c, &method->basic.scheduler_schedule))
            break;
        case 7425: /* module 29 call 1 */
            CHECK_ERROR(_readMethod_scheduler_cancel(c, &method->basic.scheduler_cancel))
            break;
        case 7426: /* module 29 call 2 */
            CHECK_ERROR(_readMethod_scheduler_schedule_named(c, &method->basic.scheduler_schedule_named))
            break;
        case 7427: /* module 29 call 3 */
            CHECK_ERROR(_readMethod_scheduler_cancel_named(c, &method->basic.scheduler_cancel_named))
            break;
        case 7680: /* module 30 call 0 */
            CHECK_ERROR(_readMethod_proxy_proxy(c, &method->basic.proxy_proxy))
            break;
        case 7681: /* module 30 call 1 */
            CHECK_ERROR(_readMethod_proxy_add_proxy(c, &method->basic.proxy_add_proxy))
            break;
        case 7682: /* module 30 call 2 */
            CHECK_ERROR(_readMethod_proxy_remove_proxy(c, &method->basic.proxy_remove_proxy))
            break;
        case 7683: /* module 30 call 3 */
            CHECK_ERROR(_readMethod_proxy_remove_proxies(c, &method->basic.proxy_remove_proxies))
            break;
        case 7684: /* module 30 call 4 */
            CHECK_ERROR(_readMethod_proxy_anonymous(c, &method->basic.proxy_anonymous))
            break;
        case 7685: /* module 30 call 5 */
            CHECK_ERROR(_readMethod_proxy_kill_anonymous(c, &method->basic.proxy_kill_anonymous))
            break;
        case 7936: /* module 31 call 0 */
            CHECK_ERROR(_readMethod_multisig_as_multi(c, &method->basic.multisig_as_multi))
            break;
        case 7937: /* module 31 call 1 */
            CHECK_ERROR(_readMethod_multisig_approve_as_multi(c, &method->basic.multisig_approve_as_multi))
            break;
        case 7938: /* module 31 call 2 */
            CHECK_ERROR(_readMethod_multisig_cancel_as_multi(c, &method->basic.multisig_cancel_as_multi))
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

const char * _getMethod_ModuleName(uint8_t moduleIdx) {
    switch(moduleIdx) {
        case 0:   return "System";
        case 1:   return "Babe";
        case 2:   return "Timestamp";
        case 3:   return "Indices";
        case 4:   return "Balances";
        case 5:   return "Authorship";
        case 6:   return "Staking";
        case 7:   return "Offences";
        case 8:   return "Session";
        case 9:   return "Finalitytracker";
        case 10:   return "Grandpa";
        case 11:   return "Imonline";
        case 12:   return "Authoritydiscovery";
        case 13:   return "Democracy";
        case 14:   return "Council";
        case 15:   return "Technicalcommittee";
        case 16:   return "Electionsphragmen";
        case 17:   return "Technicalmembership";
        case 18:   return "Treasury";
        case 19:   return "Claims";
        case 20:   return "Parachains";
        case 21:   return "Attestations";
        case 22:   return "Slots";
        case 23:   return "Registrar";
        case 24:   return "Utility";
        case 25:   return "Identity";
        case 26:   return "Society";
        case 27:   return "Recovery";
        case 28:   return "Vesting";
        case 29:   return "Scheduler";
        case 30:   return "Proxy";
        case 31:   return "Multisig";
    default:
    return NULL;
    }

    return NULL;
}


const char * _getMethod_Name(uint8_t moduleIdx, uint8_t callIdx) {
    uint16_t callPrivIdx = ( (uint16_t) moduleIdx << 8u) + callIdx;

    switch(callPrivIdx) {
        case 0: /* module 0 call 0 */   return "Fill block";
        case 1: /* module 0 call 1 */   return "Remark";
        case 2: /* module 0 call 2 */   return "Set heap pages";
        case 3: /* module 0 call 3 */   return "Set code";
        case 4: /* module 0 call 4 */   return "Set code without checks";
        case 5: /* module 0 call 5 */   return "Set changes trie config";
        case 6: /* module 0 call 6 */   return "Set storage";
        case 7: /* module 0 call 7 */   return "Kill storage";
        case 8: /* module 0 call 8 */   return "Kill prefix";
        case 9: /* module 0 call 9 */   return "Suicide";
        case 512: /* module 2 call 0 */   return "Set";
        case 768: /* module 3 call 0 */   return "Claim";
        case 769: /* module 3 call 1 */   return "Transfer";
        case 770: /* module 3 call 2 */   return "Free";
        case 771: /* module 3 call 3 */   return "Force transfer";
        case 772: /* module 3 call 4 */   return "Freeze";
        case 1024: /* module 4 call 0 */   return "Transfer";
        case 1025: /* module 4 call 1 */   return "Set balance";
        case 1026: /* module 4 call 2 */   return "Force transfer";
        case 1027: /* module 4 call 3 */   return "Transfer keep alive";
        case 1280: /* module 5 call 0 */   return "Set uncles";
        case 1536: /* module 6 call 0 */   return "Bond";
        case 1537: /* module 6 call 1 */   return "Bond extra";
        case 1538: /* module 6 call 2 */   return "Unbond";
        case 1539: /* module 6 call 3 */   return "Withdraw unbonded";
        case 1540: /* module 6 call 4 */   return "Validate";
        case 1541: /* module 6 call 5 */   return "Nominate";
        case 1542: /* module 6 call 6 */   return "Chill";
        case 1543: /* module 6 call 7 */   return "Set payee";
        case 1544: /* module 6 call 8 */   return "Set controller";
        case 1545: /* module 6 call 9 */   return "Set validator count";
        case 1546: /* module 6 call 10 */   return "Force no eras";
        case 1547: /* module 6 call 11 */   return "Force new era";
        case 1548: /* module 6 call 12 */   return "Set invulnerables";
        case 1549: /* module 6 call 13 */   return "Force unstake";
        case 1550: /* module 6 call 14 */   return "Force new era always";
        case 1551: /* module 6 call 15 */   return "Cancel deferred slash";
        case 1552: /* module 6 call 16 */   return "Payout stakers";
        case 1553: /* module 6 call 17 */   return "Rebond";
        case 1554: /* module 6 call 18 */   return "Set history depth";
        case 1555: /* module 6 call 19 */   return "Reap stash";
        case 1556: /* module 6 call 20 */   return "Submit election solution";
        case 1557: /* module 6 call 21 */   return "Submit election solution unsigned";
        case 2048: /* module 8 call 0 */   return "Set keys";
        case 2049: /* module 8 call 1 */   return "Purge keys";
        case 2304: /* module 9 call 0 */   return "Final hint";
        case 2560: /* module 10 call 0 */   return "Report equivocation";
        case 2816: /* module 11 call 0 */   return "Heartbeat";
        case 3328: /* module 13 call 0 */   return "Propose";
        case 3329: /* module 13 call 1 */   return "Second";
        case 3330: /* module 13 call 2 */   return "Vote";
        case 3331: /* module 13 call 3 */   return "Emergency cancel";
        case 3332: /* module 13 call 4 */   return "External propose";
        case 3333: /* module 13 call 5 */   return "External propose majority";
        case 3334: /* module 13 call 6 */   return "External propose default";
        case 3335: /* module 13 call 7 */   return "Fast track";
        case 3336: /* module 13 call 8 */   return "Veto external";
        case 3337: /* module 13 call 9 */   return "Cancel referendum";
        case 3338: /* module 13 call 10 */   return "Cancel queued";
        case 3339: /* module 13 call 11 */   return "Delegate";
        case 3340: /* module 13 call 12 */   return "Undelegate";
        case 3341: /* module 13 call 13 */   return "Clear public proposals";
        case 3342: /* module 13 call 14 */   return "Note preimage";
        case 3343: /* module 13 call 15 */   return "Note preimage operational";
        case 3344: /* module 13 call 16 */   return "Note imminent preimage";
        case 3345: /* module 13 call 17 */   return "Note imminent preimage operational";
        case 3346: /* module 13 call 18 */   return "Reap preimage";
        case 3347: /* module 13 call 19 */   return "Unlock";
        case 3348: /* module 13 call 20 */   return "Remove vote";
        case 3349: /* module 13 call 21 */   return "Remove other vote";
        case 3350: /* module 13 call 22 */   return "Enact proposal";
        case 3584: /* module 14 call 0 */   return "Set members";
        case 3585: /* module 14 call 1 */   return "Execute";
        case 3586: /* module 14 call 2 */   return "Propose";
        case 3587: /* module 14 call 3 */   return "Vote";
        case 3588: /* module 14 call 4 */   return "Close";
        case 3589: /* module 14 call 5 */   return "Disapprove proposal";
        case 3840: /* module 15 call 0 */   return "Set members";
        case 3841: /* module 15 call 1 */   return "Execute";
        case 3842: /* module 15 call 2 */   return "Propose";
        case 3843: /* module 15 call 3 */   return "Vote";
        case 3844: /* module 15 call 4 */   return "Close";
        case 3845: /* module 15 call 5 */   return "Disapprove proposal";
        case 4096: /* module 16 call 0 */   return "Vote";
        case 4097: /* module 16 call 1 */   return "Remove voter";
        case 4098: /* module 16 call 2 */   return "Report defunct voter";
        case 4099: /* module 16 call 3 */   return "Submit candidacy";
        case 4100: /* module 16 call 4 */   return "Renounce candidacy";
        case 4101: /* module 16 call 5 */   return "Remove member";
        case 4352: /* module 17 call 0 */   return "Add member";
        case 4353: /* module 17 call 1 */   return "Remove member";
        case 4354: /* module 17 call 2 */   return "Swap member";
        case 4355: /* module 17 call 3 */   return "Reset members";
        case 4356: /* module 17 call 4 */   return "Change key";
        case 4357: /* module 17 call 5 */   return "Set prime";
        case 4358: /* module 17 call 6 */   return "Clear prime";
        case 4608: /* module 18 call 0 */   return "Propose spend";
        case 4609: /* module 18 call 1 */   return "Reject proposal";
        case 4610: /* module 18 call 2 */   return "Approve proposal";
        case 4611: /* module 18 call 3 */   return "Report awesome";
        case 4612: /* module 18 call 4 */   return "Retract tip";
        case 4613: /* module 18 call 5 */   return "Tip new";
        case 4614: /* module 18 call 6 */   return "Tip";
        case 4615: /* module 18 call 7 */   return "Close tip";
        case 4864: /* module 19 call 0 */   return "Claim";
        case 4865: /* module 19 call 1 */   return "Mint claim";
        case 4866: /* module 19 call 2 */   return "Claim attest";
        case 4867: /* module 19 call 3 */   return "Attest";
        case 4868: /* module 19 call 4 */   return "Move claim";
        case 5120: /* module 20 call 0 */   return "Set heads";
        case 5121: /* module 20 call 1 */   return "Report double vote";
        case 5376: /* module 21 call 0 */   return "More attestations";
        case 5632: /* module 22 call 0 */   return "New auction";
        case 5633: /* module 22 call 1 */   return "Bid";
        case 5634: /* module 22 call 2 */   return "Bid renew";
        case 5635: /* module 22 call 3 */   return "Set offboarding";
        case 5636: /* module 22 call 4 */   return "Fix deploy data";
        case 5637: /* module 22 call 5 */   return "Elaborate deploy data";
        case 5888: /* module 23 call 0 */   return "Register para";
        case 5889: /* module 23 call 1 */   return "Deregister para";
        case 5890: /* module 23 call 2 */   return "Set thread count";
        case 5891: /* module 23 call 3 */   return "Register parathread";
        case 5892: /* module 23 call 4 */   return "Select parathread";
        case 5893: /* module 23 call 5 */   return "Deregister parathread";
        case 5894: /* module 23 call 6 */   return "Swap";
        case 6144: /* module 24 call 0 */   return "Batch";
        case 6145: /* module 24 call 1 */   return "As sub";
        case 6146: /* module 24 call 2 */   return "As limited sub";
        case 6400: /* module 25 call 0 */   return "Add registrar";
        case 6401: /* module 25 call 1 */   return "Set identity";
        case 6402: /* module 25 call 2 */   return "Set subs";
        case 6403: /* module 25 call 3 */   return "Clear identity";
        case 6404: /* module 25 call 4 */   return "Request judgement";
        case 6405: /* module 25 call 5 */   return "Cancel request";
        case 6406: /* module 25 call 6 */   return "Set fee";
        case 6407: /* module 25 call 7 */   return "Set account id";
        case 6408: /* module 25 call 8 */   return "Set fields";
        case 6409: /* module 25 call 9 */   return "Provide judgement";
        case 6410: /* module 25 call 10 */   return "Kill identity";
        case 6656: /* module 26 call 0 */   return "Bid";
        case 6657: /* module 26 call 1 */   return "Unbid";
        case 6658: /* module 26 call 2 */   return "Vouch";
        case 6659: /* module 26 call 3 */   return "Unvouch";
        case 6660: /* module 26 call 4 */   return "Vote";
        case 6661: /* module 26 call 5 */   return "Defender vote";
        case 6662: /* module 26 call 6 */   return "Payout";
        case 6663: /* module 26 call 7 */   return "Found";
        case 6664: /* module 26 call 8 */   return "Unfound";
        case 6665: /* module 26 call 9 */   return "Judge suspended member";
        case 6666: /* module 26 call 10 */   return "Judge suspended candidate";
        case 6667: /* module 26 call 11 */   return "Set max members";
        case 6912: /* module 27 call 0 */   return "As recovered";
        case 6913: /* module 27 call 1 */   return "Set recovered";
        case 6914: /* module 27 call 2 */   return "Create recovery";
        case 6915: /* module 27 call 3 */   return "Initiate recovery";
        case 6916: /* module 27 call 4 */   return "Vouch recovery";
        case 6917: /* module 27 call 5 */   return "Claim recovery";
        case 6918: /* module 27 call 6 */   return "Close recovery";
        case 6919: /* module 27 call 7 */   return "Remove recovery";
        case 6920: /* module 27 call 8 */   return "Cancel recovered";
        case 7168: /* module 28 call 0 */   return "Vest";
        case 7169: /* module 28 call 1 */   return "Vest other";
        case 7170: /* module 28 call 2 */   return "Vested transfer";
        case 7424: /* module 29 call 0 */   return "Schedule";
        case 7425: /* module 29 call 1 */   return "Cancel";
        case 7426: /* module 29 call 2 */   return "Schedule named";
        case 7427: /* module 29 call 3 */   return "Cancel named";
        case 7680: /* module 30 call 0 */   return "Proxy";
        case 7681: /* module 30 call 1 */   return "Add proxy";
        case 7682: /* module 30 call 2 */   return "Remove proxy";
        case 7683: /* module 30 call 3 */   return "Remove proxies";
        case 7684: /* module 30 call 4 */   return "Anonymous";
        case 7685: /* module 30 call 5 */   return "Kill anonymous";
        case 7936: /* module 31 call 0 */   return "As multi";
        case 7937: /* module 31 call 1 */   return "Approve as multi";
        case 7938: /* module 31 call 2 */   return "Cancel as multi";
    default:
        return NULL;
    }

    return NULL;
}

uint8_t _getMethod_NumItems(uint8_t moduleIdx, uint8_t callIdx, pd_Method_t *method) {
    uint16_t callPrivIdx = ( (uint16_t) moduleIdx << 8u) + callIdx;

    switch(callPrivIdx) {
        case 0: /* module 0 call 0 */ return 1;
        case 1: /* module 0 call 1 */ return 1;
        case 2: /* module 0 call 2 */ return 1;
        case 3: /* module 0 call 3 */ return 1;
        case 4: /* module 0 call 4 */ return 1;
        case 5: /* module 0 call 5 */ return 1;
        case 6: /* module 0 call 6 */ return 1;
        case 7: /* module 0 call 7 */ return 1;
        case 8: /* module 0 call 8 */ return 2;
        case 9: /* module 0 call 9 */ return 0;
        case 512: /* module 2 call 0 */ return 1;
        case 768: /* module 3 call 0 */ return 1;
        case 769: /* module 3 call 1 */ return 2;
        case 770: /* module 3 call 2 */ return 1;
        case 771: /* module 3 call 3 */ return 3;
        case 772: /* module 3 call 4 */ return 1;
        case 1024: /* module 4 call 0 */ return 2;
        case 1025: /* module 4 call 1 */ return 3;
        case 1026: /* module 4 call 2 */ return 3;
        case 1027: /* module 4 call 3 */ return 2;
        case 1280: /* module 5 call 0 */ return 1;
        case 1536: /* module 6 call 0 */ return 3;
        case 1537: /* module 6 call 1 */ return 1;
        case 1538: /* module 6 call 2 */ return 1;
        case 1539: /* module 6 call 3 */ return 1;
        case 1540: /* module 6 call 4 */ return 1;
        case 1541: /* module 6 call 5 */ return 1;
        case 1542: /* module 6 call 6 */ return 0;
        case 1543: /* module 6 call 7 */ return 1;
        case 1544: /* module 6 call 8 */ return 1;
        case 1545: /* module 6 call 9 */ return 1;
        case 1546: /* module 6 call 10 */ return 0;
        case 1547: /* module 6 call 11 */ return 0;
        case 1548: /* module 6 call 12 */ return 1;
        case 1549: /* module 6 call 13 */ return 2;
        case 1550: /* module 6 call 14 */ return 0;
        case 1551: /* module 6 call 15 */ return 2;
        case 1552: /* module 6 call 16 */ return 2;
        case 1553: /* module 6 call 17 */ return 1;
        case 1554: /* module 6 call 18 */ return 2;
        case 1555: /* module 6 call 19 */ return 2;
        case 1556: /* module 6 call 20 */ return 5;
        case 1557: /* module 6 call 21 */ return 5;
        case 2048: /* module 8 call 0 */ return 2;
        case 2049: /* module 8 call 1 */ return 0;
        case 2304: /* module 9 call 0 */ return 1;
        case 2560: /* module 10 call 0 */ return 2;
        case 2816: /* module 11 call 0 */ return 2;
        case 3328: /* module 13 call 0 */ return 2;
        case 3329: /* module 13 call 1 */ return 2;
        case 3330: /* module 13 call 2 */ return 2;
        case 3331: /* module 13 call 3 */ return 1;
        case 3332: /* module 13 call 4 */ return 1;
        case 3333: /* module 13 call 5 */ return 1;
        case 3334: /* module 13 call 6 */ return 1;
        case 3335: /* module 13 call 7 */ return 3;
        case 3336: /* module 13 call 8 */ return 1;
        case 3337: /* module 13 call 9 */ return 1;
        case 3338: /* module 13 call 10 */ return 1;
        case 3339: /* module 13 call 11 */ return 3;
        case 3340: /* module 13 call 12 */ return 0;
        case 3341: /* module 13 call 13 */ return 0;
        case 3342: /* module 13 call 14 */ return 1;
        case 3343: /* module 13 call 15 */ return 1;
        case 3344: /* module 13 call 16 */ return 1;
        case 3345: /* module 13 call 17 */ return 1;
        case 3346: /* module 13 call 18 */ return 2;
        case 3347: /* module 13 call 19 */ return 1;
        case 3348: /* module 13 call 20 */ return 1;
        case 3349: /* module 13 call 21 */ return 2;
        case 3350: /* module 13 call 22 */ return 2;
        case 3584: /* module 14 call 0 */ return 3;
        case 3585: /* module 14 call 1 */ return 2;
        case 3586: /* module 14 call 2 */ return 3;
        case 3587: /* module 14 call 3 */ return 3;
        case 3588: /* module 14 call 4 */ return 4;
        case 3589: /* module 14 call 5 */ return 1;
        case 3840: /* module 15 call 0 */ return 3;
        case 3841: /* module 15 call 1 */ return 2;
        case 3842: /* module 15 call 2 */ return 3;
        case 3843: /* module 15 call 3 */ return 3;
        case 3844: /* module 15 call 4 */ return 4;
        case 3845: /* module 15 call 5 */ return 1;
        case 4096: /* module 16 call 0 */ return 2;
        case 4097: /* module 16 call 1 */ return 0;
        case 4098: /* module 16 call 2 */ return 1;
        case 4099: /* module 16 call 3 */ return 1;
        case 4100: /* module 16 call 4 */ return 1;
        case 4101: /* module 16 call 5 */ return 2;
        case 4352: /* module 17 call 0 */ return 1;
        case 4353: /* module 17 call 1 */ return 1;
        case 4354: /* module 17 call 2 */ return 2;
        case 4355: /* module 17 call 3 */ return 1;
        case 4356: /* module 17 call 4 */ return 1;
        case 4357: /* module 17 call 5 */ return 1;
        case 4358: /* module 17 call 6 */ return 0;
        case 4608: /* module 18 call 0 */ return 2;
        case 4609: /* module 18 call 1 */ return 1;
        case 4610: /* module 18 call 2 */ return 1;
        case 4611: /* module 18 call 3 */ return 2;
        case 4612: /* module 18 call 4 */ return 1;
        case 4613: /* module 18 call 5 */ return 3;
        case 4614: /* module 18 call 6 */ return 2;
        case 4615: /* module 18 call 7 */ return 1;
        case 4864: /* module 19 call 0 */ return 2;
        case 4865: /* module 19 call 1 */ return 4;
        case 4866: /* module 19 call 2 */ return 3;
        case 4867: /* module 19 call 3 */ return 1;
        case 4868: /* module 19 call 4 */ return 3;
        case 5120: /* module 20 call 0 */ return 1;
        case 5121: /* module 20 call 1 */ return 1;
        case 5376: /* module 21 call 0 */ return 1;
        case 5632: /* module 22 call 0 */ return 2;
        case 5633: /* module 22 call 1 */ return 5;
        case 5634: /* module 22 call 2 */ return 4;
        case 5635: /* module 22 call 3 */ return 1;
        case 5636: /* module 22 call 4 */ return 5;
        case 5637: /* module 22 call 5 */ return 2;
        case 5888: /* module 23 call 0 */ return 4;
        case 5889: /* module 23 call 1 */ return 1;
        case 5890: /* module 23 call 2 */ return 1;
        case 5891: /* module 23 call 3 */ return 2;
        case 5892: /* module 23 call 4 */ return 3;
        case 5893: /* module 23 call 5 */ return 0;
        case 5894: /* module 23 call 6 */ return 1;
        case 6144: /* module 24 call 0 */ return 1;
        case 6145: /* module 24 call 1 */ return 2;
        case 6146: /* module 24 call 2 */ return 2;
        case 6400: /* module 25 call 0 */ return 1;
        case 6401: /* module 25 call 1 */ return 1;
        case 6402: /* module 25 call 2 */ return 1;
        case 6403: /* module 25 call 3 */ return 0;
        case 6404: /* module 25 call 4 */ return 2;
        case 6405: /* module 25 call 5 */ return 1;
        case 6406: /* module 25 call 6 */ return 2;
        case 6407: /* module 25 call 7 */ return 2;
        case 6408: /* module 25 call 8 */ return 2;
        case 6409: /* module 25 call 9 */ return 3;
        case 6410: /* module 25 call 10 */ return 1;
        case 6656: /* module 26 call 0 */ return 1;
        case 6657: /* module 26 call 1 */ return 1;
        case 6658: /* module 26 call 2 */ return 3;
        case 6659: /* module 26 call 3 */ return 1;
        case 6660: /* module 26 call 4 */ return 2;
        case 6661: /* module 26 call 5 */ return 1;
        case 6662: /* module 26 call 6 */ return 0;
        case 6663: /* module 26 call 7 */ return 3;
        case 6664: /* module 26 call 8 */ return 0;
        case 6665: /* module 26 call 9 */ return 2;
        case 6666: /* module 26 call 10 */ return 2;
        case 6667: /* module 26 call 11 */ return 1;
        case 6912: /* module 27 call 0 */ return 2;
        case 6913: /* module 27 call 1 */ return 2;
        case 6914: /* module 27 call 2 */ return 3;
        case 6915: /* module 27 call 3 */ return 1;
        case 6916: /* module 27 call 4 */ return 2;
        case 6917: /* module 27 call 5 */ return 1;
        case 6918: /* module 27 call 6 */ return 1;
        case 6919: /* module 27 call 7 */ return 0;
        case 6920: /* module 27 call 8 */ return 1;
        case 7168: /* module 28 call 0 */ return 0;
        case 7169: /* module 28 call 1 */ return 1;
        case 7170: /* module 28 call 2 */ return 2;
        case 7424: /* module 29 call 0 */ return 4;
        case 7425: /* module 29 call 1 */ return 2;
        case 7426: /* module 29 call 2 */ return 5;
        case 7427: /* module 29 call 3 */ return 1;
        case 7680: /* module 30 call 0 */ return 3;
        case 7681: /* module 30 call 1 */ return 2;
        case 7682: /* module 30 call 2 */ return 2;
        case 7683: /* module 30 call 3 */ return 0;
        case 7684: /* module 30 call 4 */ return 2;
        case 7685: /* module 30 call 5 */ return 5;
        case 7936: /* module 31 call 0 */ return 4;
        case 7937: /* module 31 call 1 */ return 4;
        case 7938: /* module 31 call 2 */ return 4;
    default:
    return 0;
    }

    return 0;
}


const char * _getMethod_ItemName(uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx) {
    uint16_t callPrivIdx = ( (uint16_t) moduleIdx << 8u) + callIdx;

    switch(callPrivIdx) {
        case 0: /* module 0 call 0 */
            switch(itemIdx) {
                case 0: return "Ratio";
                default: return NULL;
            }
        case 1: /* module 0 call 1 */
            switch(itemIdx) {
                case 0: return "Remark";
                default: return NULL;
            }
        case 2: /* module 0 call 2 */
            switch(itemIdx) {
                case 0: return "Pages";
                default: return NULL;
            }
        case 3: /* module 0 call 3 */
            switch(itemIdx) {
                case 0: return "Code";
                default: return NULL;
            }
        case 4: /* module 0 call 4 */
            switch(itemIdx) {
                case 0: return "Code";
                default: return NULL;
            }
        case 5: /* module 0 call 5 */
            switch(itemIdx) {
                case 0: return "Changes trie config";
                default: return NULL;
            }
        case 6: /* module 0 call 6 */
            switch(itemIdx) {
                case 0: return "Items";
                default: return NULL;
            }
        case 7: /* module 0 call 7 */
            switch(itemIdx) {
                case 0: return "Keys";
                default: return NULL;
            }
        case 8: /* module 0 call 8 */
            switch(itemIdx) {
                case 0: return "Prefix";
                case 1: return "Subkeys";
                default: return NULL;
            }
        case 9: /* module 0 call 9 */
            switch(itemIdx) {
                default: return NULL;
            }
        case 512: /* module 2 call 0 */
            switch(itemIdx) {
                case 0: return "Now";
                default: return NULL;
            }
        case 768: /* module 3 call 0 */
            switch(itemIdx) {
                case 0: return "Index";
                default: return NULL;
            }
        case 769: /* module 3 call 1 */
            switch(itemIdx) {
                case 0: return "New";
                case 1: return "Index";
                default: return NULL;
            }
        case 770: /* module 3 call 2 */
            switch(itemIdx) {
                case 0: return "Index";
                default: return NULL;
            }
        case 771: /* module 3 call 3 */
            switch(itemIdx) {
                case 0: return "New";
                case 1: return "Index";
                case 2: return "Freeze";
                default: return NULL;
            }
        case 772: /* module 3 call 4 */
            switch(itemIdx) {
                case 0: return "Index";
                default: return NULL;
            }
        case 1024: /* module 4 call 0 */
            switch(itemIdx) {
                case 0: return "Dest";
                case 1: return "Value";
                default: return NULL;
            }
        case 1025: /* module 4 call 1 */
            switch(itemIdx) {
                case 0: return "Who";
                case 1: return "New free";
                case 2: return "New reserved";
                default: return NULL;
            }
        case 1026: /* module 4 call 2 */
            switch(itemIdx) {
                case 0: return "Source";
                case 1: return "Dest";
                case 2: return "Value";
                default: return NULL;
            }
        case 1027: /* module 4 call 3 */
            switch(itemIdx) {
                case 0: return "Dest";
                case 1: return "Value";
                default: return NULL;
            }
        case 1280: /* module 5 call 0 */
            switch(itemIdx) {
                case 0: return "New uncles";
                default: return NULL;
            }
        case 1536: /* module 6 call 0 */
            switch(itemIdx) {
                case 0: return "Controller";
                case 1: return "Value";
                case 2: return "Payee";
                default: return NULL;
            }
        case 1537: /* module 6 call 1 */
            switch(itemIdx) {
                case 0: return "Max additional";
                default: return NULL;
            }
        case 1538: /* module 6 call 2 */
            switch(itemIdx) {
                case 0: return "Value";
                default: return NULL;
            }
        case 1539: /* module 6 call 3 */
            switch(itemIdx) {
                case 0: return "Num slashing spans";
                default: return NULL;
            }
        case 1540: /* module 6 call 4 */
            switch(itemIdx) {
                case 0: return "Prefs";
                default: return NULL;
            }
        case 1541: /* module 6 call 5 */
            switch(itemIdx) {
                case 0: return "Targets";
                default: return NULL;
            }
        case 1542: /* module 6 call 6 */
            switch(itemIdx) {
                default: return NULL;
            }
        case 1543: /* module 6 call 7 */
            switch(itemIdx) {
                case 0: return "Payee";
                default: return NULL;
            }
        case 1544: /* module 6 call 8 */
            switch(itemIdx) {
                case 0: return "Controller";
                default: return NULL;
            }
        case 1545: /* module 6 call 9 */
            switch(itemIdx) {
                case 0: return "New";
                default: return NULL;
            }
        case 1546: /* module 6 call 10 */
            switch(itemIdx) {
                default: return NULL;
            }
        case 1547: /* module 6 call 11 */
            switch(itemIdx) {
                default: return NULL;
            }
        case 1548: /* module 6 call 12 */
            switch(itemIdx) {
                case 0: return "Validators";
                default: return NULL;
            }
        case 1549: /* module 6 call 13 */
            switch(itemIdx) {
                case 0: return "Stash";
                case 1: return "Num slashing spans";
                default: return NULL;
            }
        case 1550: /* module 6 call 14 */
            switch(itemIdx) {
                default: return NULL;
            }
        case 1551: /* module 6 call 15 */
            switch(itemIdx) {
                case 0: return "Era";
                case 1: return "Slash indices";
                default: return NULL;
            }
        case 1552: /* module 6 call 16 */
            switch(itemIdx) {
                case 0: return "Validator stash";
                case 1: return "Era";
                default: return NULL;
            }
        case 1553: /* module 6 call 17 */
            switch(itemIdx) {
                case 0: return "Value";
                default: return NULL;
            }
        case 1554: /* module 6 call 18 */
            switch(itemIdx) {
                case 0: return "New history depth";
                case 1: return "Era items deleted";
                default: return NULL;
            }
        case 1555: /* module 6 call 19 */
            switch(itemIdx) {
                case 0: return "Stash";
                case 1: return "Num slashing spans";
                default: return NULL;
            }
        case 1556: /* module 6 call 20 */
            switch(itemIdx) {
                case 0: return "Winners";
                case 1: return "Compact";
                case 2: return "Score";
                case 3: return "Era";
                case 4: return "Size";
                default: return NULL;
            }
        case 1557: /* module 6 call 21 */
            switch(itemIdx) {
                case 0: return "Winners";
                case 1: return "Compact";
                case 2: return "Score";
                case 3: return "Era";
                case 4: return "Size";
                default: return NULL;
            }
        case 2048: /* module 8 call 0 */
            switch(itemIdx) {
                case 0: return "Keys";
                case 1: return "Proof";
                default: return NULL;
            }
        case 2049: /* module 8 call 1 */
            switch(itemIdx) {
                default: return NULL;
            }
        case 2304: /* module 9 call 0 */
            switch(itemIdx) {
                case 0: return "Hint";
                default: return NULL;
            }
        case 2560: /* module 10 call 0 */
            switch(itemIdx) {
                case 0: return "Equivocation proof";
                case 1: return "Key owner proof";
                default: return NULL;
            }
        case 2816: /* module 11 call 0 */
            switch(itemIdx) {
                case 0: return "Heartbeat";
                case 1: return "Signature";
                default: return NULL;
            }
        case 3328: /* module 13 call 0 */
            switch(itemIdx) {
                case 0: return "Proposal hash";
                case 1: return "Value";
                default: return NULL;
            }
        case 3329: /* module 13 call 1 */
            switch(itemIdx) {
                case 0: return "Proposal";
                case 1: return "Seconds upper bound";
                default: return NULL;
            }
        case 3330: /* module 13 call 2 */
            switch(itemIdx) {
                case 0: return "Ref index";
                case 1: return "Vote";
                default: return NULL;
            }
        case 3331: /* module 13 call 3 */
            switch(itemIdx) {
                case 0: return "Ref index";
                default: return NULL;
            }
        case 3332: /* module 13 call 4 */
            switch(itemIdx) {
                case 0: return "Proposal hash";
                default: return NULL;
            }
        case 3333: /* module 13 call 5 */
            switch(itemIdx) {
                case 0: return "Proposal hash";
                default: return NULL;
            }
        case 3334: /* module 13 call 6 */
            switch(itemIdx) {
                case 0: return "Proposal hash";
                default: return NULL;
            }
        case 3335: /* module 13 call 7 */
            switch(itemIdx) {
                case 0: return "Proposal hash";
                case 1: return "Voting period";
                case 2: return "Delay";
                default: return NULL;
            }
        case 3336: /* module 13 call 8 */
            switch(itemIdx) {
                case 0: return "Proposal hash";
                default: return NULL;
            }
        case 3337: /* module 13 call 9 */
            switch(itemIdx) {
                case 0: return "Ref index";
                default: return NULL;
            }
        case 3338: /* module 13 call 10 */
            switch(itemIdx) {
                case 0: return "Which";
                default: return NULL;
            }
        case 3339: /* module 13 call 11 */
            switch(itemIdx) {
                case 0: return "To";
                case 1: return "Conviction";
                case 2: return "Balance";
                default: return NULL;
            }
        case 3340: /* module 13 call 12 */
            switch(itemIdx) {
                default: return NULL;
            }
        case 3341: /* module 13 call 13 */
            switch(itemIdx) {
                default: return NULL;
            }
        case 3342: /* module 13 call 14 */
            switch(itemIdx) {
                case 0: return "Encoded proposal";
                default: return NULL;
            }
        case 3343: /* module 13 call 15 */
            switch(itemIdx) {
                case 0: return "Encoded proposal";
                default: return NULL;
            }
        case 3344: /* module 13 call 16 */
            switch(itemIdx) {
                case 0: return "Encoded proposal";
                default: return NULL;
            }
        case 3345: /* module 13 call 17 */
            switch(itemIdx) {
                case 0: return "Encoded proposal";
                default: return NULL;
            }
        case 3346: /* module 13 call 18 */
            switch(itemIdx) {
                case 0: return "Proposal hash";
                case 1: return "Proposal len upper bound";
                default: return NULL;
            }
        case 3347: /* module 13 call 19 */
            switch(itemIdx) {
                case 0: return "Target";
                default: return NULL;
            }
        case 3348: /* module 13 call 20 */
            switch(itemIdx) {
                case 0: return "Index";
                default: return NULL;
            }
        case 3349: /* module 13 call 21 */
            switch(itemIdx) {
                case 0: return "Target";
                case 1: return "Index";
                default: return NULL;
            }
        case 3350: /* module 13 call 22 */
            switch(itemIdx) {
                case 0: return "Proposal hash";
                case 1: return "Index";
                default: return NULL;
            }
        case 3584: /* module 14 call 0 */
            switch(itemIdx) {
                case 0: return "New members";
                case 1: return "Prime";
                case 2: return "Old count";
                default: return NULL;
            }
        case 3585: /* module 14 call 1 */
            switch(itemIdx) {
                case 0: return "Proposal";
                case 1: return "Length bound";
                default: return NULL;
            }
        case 3586: /* module 14 call 2 */
            switch(itemIdx) {
                case 0: return "Threshold";
                case 1: return "Proposal";
                case 2: return "Length bound";
                default: return NULL;
            }
        case 3587: /* module 14 call 3 */
            switch(itemIdx) {
                case 0: return "Proposal";
                case 1: return "Index";
                case 2: return "Approve";
                default: return NULL;
            }
        case 3588: /* module 14 call 4 */
            switch(itemIdx) {
                case 0: return "Proposal hash";
                case 1: return "Index";
                case 2: return "Proposal weight bound";
                case 3: return "Length bound";
                default: return NULL;
            }
        case 3589: /* module 14 call 5 */
            switch(itemIdx) {
                case 0: return "Proposal hash";
                default: return NULL;
            }
        case 3840: /* module 15 call 0 */
            switch(itemIdx) {
                case 0: return "New members";
                case 1: return "Prime";
                case 2: return "Old count";
                default: return NULL;
            }
        case 3841: /* module 15 call 1 */
            switch(itemIdx) {
                case 0: return "Proposal";
                case 1: return "Length bound";
                default: return NULL;
            }
        case 3842: /* module 15 call 2 */
            switch(itemIdx) {
                case 0: return "Threshold";
                case 1: return "Proposal";
                case 2: return "Length bound";
                default: return NULL;
            }
        case 3843: /* module 15 call 3 */
            switch(itemIdx) {
                case 0: return "Proposal";
                case 1: return "Index";
                case 2: return "Approve";
                default: return NULL;
            }
        case 3844: /* module 15 call 4 */
            switch(itemIdx) {
                case 0: return "Proposal hash";
                case 1: return "Index";
                case 2: return "Proposal weight bound";
                case 3: return "Length bound";
                default: return NULL;
            }
        case 3845: /* module 15 call 5 */
            switch(itemIdx) {
                case 0: return "Proposal hash";
                default: return NULL;
            }
        case 4096: /* module 16 call 0 */
            switch(itemIdx) {
                case 0: return "Votes";
                case 1: return "Value";
                default: return NULL;
            }
        case 4097: /* module 16 call 1 */
            switch(itemIdx) {
                default: return NULL;
            }
        case 4098: /* module 16 call 2 */
            switch(itemIdx) {
                case 0: return "Defunct";
                default: return NULL;
            }
        case 4099: /* module 16 call 3 */
            switch(itemIdx) {
                case 0: return "Candidate count";
                default: return NULL;
            }
        case 4100: /* module 16 call 4 */
            switch(itemIdx) {
                case 0: return "Renouncing";
                default: return NULL;
            }
        case 4101: /* module 16 call 5 */
            switch(itemIdx) {
                case 0: return "Who";
                case 1: return "Has replacement";
                default: return NULL;
            }
        case 4352: /* module 17 call 0 */
            switch(itemIdx) {
                case 0: return "Who";
                default: return NULL;
            }
        case 4353: /* module 17 call 1 */
            switch(itemIdx) {
                case 0: return "Who";
                default: return NULL;
            }
        case 4354: /* module 17 call 2 */
            switch(itemIdx) {
                case 0: return "Remove";
                case 1: return "Add";
                default: return NULL;
            }
        case 4355: /* module 17 call 3 */
            switch(itemIdx) {
                case 0: return "Members";
                default: return NULL;
            }
        case 4356: /* module 17 call 4 */
            switch(itemIdx) {
                case 0: return "New";
                default: return NULL;
            }
        case 4357: /* module 17 call 5 */
            switch(itemIdx) {
                case 0: return "Who";
                default: return NULL;
            }
        case 4358: /* module 17 call 6 */
            switch(itemIdx) {
                default: return NULL;
            }
        case 4608: /* module 18 call 0 */
            switch(itemIdx) {
                case 0: return "Value";
                case 1: return "Beneficiary";
                default: return NULL;
            }
        case 4609: /* module 18 call 1 */
            switch(itemIdx) {
                case 0: return "Proposal id";
                default: return NULL;
            }
        case 4610: /* module 18 call 2 */
            switch(itemIdx) {
                case 0: return "Proposal id";
                default: return NULL;
            }
        case 4611: /* module 18 call 3 */
            switch(itemIdx) {
                case 0: return "Reason";
                case 1: return "Who";
                default: return NULL;
            }
        case 4612: /* module 18 call 4 */
            switch(itemIdx) {
                case 0: return "Hash";
                default: return NULL;
            }
        case 4613: /* module 18 call 5 */
            switch(itemIdx) {
                case 0: return "Reason";
                case 1: return "Who";
                case 2: return "Tip value";
                default: return NULL;
            }
        case 4614: /* module 18 call 6 */
            switch(itemIdx) {
                case 0: return "Hash";
                case 1: return "Tip value";
                default: return NULL;
            }
        case 4615: /* module 18 call 7 */
            switch(itemIdx) {
                case 0: return "Hash";
                default: return NULL;
            }
        case 4864: /* module 19 call 0 */
            switch(itemIdx) {
                case 0: return "Dest";
                case 1: return "Ethereum signature";
                default: return NULL;
            }
        case 4865: /* module 19 call 1 */
            switch(itemIdx) {
                case 0: return "Who";
                case 1: return "Value";
                case 2: return "Vesting schedule";
                case 3: return "Statement";
                default: return NULL;
            }
        case 4866: /* module 19 call 2 */
            switch(itemIdx) {
                case 0: return "Dest";
                case 1: return "Ethereum signature";
                case 2: return "Statement";
                default: return NULL;
            }
        case 4867: /* module 19 call 3 */
            switch(itemIdx) {
                case 0: return "Statement";
                default: return NULL;
            }
        case 4868: /* module 19 call 4 */
            switch(itemIdx) {
                case 0: return "Old";
                case 1: return "New";
                case 2: return "Maybe preclaim";
                default: return NULL;
            }
        case 5120: /* module 20 call 0 */
            switch(itemIdx) {
                case 0: return "Heads";
                default: return NULL;
            }
        case 5121: /* module 20 call 1 */
            switch(itemIdx) {
                case 0: return "Report";
                default: return NULL;
            }
        case 5376: /* module 21 call 0 */
            switch(itemIdx) {
                case 0: return "More";
                default: return NULL;
            }
        case 5632: /* module 22 call 0 */
            switch(itemIdx) {
                case 0: return "Duration";
                case 1: return "Lease period index";
                default: return NULL;
            }
        case 5633: /* module 22 call 1 */
            switch(itemIdx) {
                case 0: return "Sub";
                case 1: return "Auction index";
                case 2: return "First slot";
                case 3: return "Last slot";
                case 4: return "Amount";
                default: return NULL;
            }
        case 5634: /* module 22 call 2 */
            switch(itemIdx) {
                case 0: return "Auction index";
                case 1: return "First slot";
                case 2: return "Last slot";
                case 3: return "Amount";
                default: return NULL;
            }
        case 5635: /* module 22 call 3 */
            switch(itemIdx) {
                case 0: return "Dest";
                default: return NULL;
            }
        case 5636: /* module 22 call 4 */
            switch(itemIdx) {
                case 0: return "Sub";
                case 1: return "Para id";
                case 2: return "Code hash";
                case 3: return "Code size";
                case 4: return "Initial head data";
                default: return NULL;
            }
        case 5637: /* module 22 call 5 */
            switch(itemIdx) {
                case 0: return "Para id";
                case 1: return "Code";
                default: return NULL;
            }
        case 5888: /* module 23 call 0 */
            switch(itemIdx) {
                case 0: return "Id";
                case 1: return "Info";
                case 2: return "Code";
                case 3: return "Initial head data";
                default: return NULL;
            }
        case 5889: /* module 23 call 1 */
            switch(itemIdx) {
                case 0: return "Id";
                default: return NULL;
            }
        case 5890: /* module 23 call 2 */
            switch(itemIdx) {
                case 0: return "Count";
                default: return NULL;
            }
        case 5891: /* module 23 call 3 */
            switch(itemIdx) {
                case 0: return "Code";
                case 1: return "Initial head data";
                default: return NULL;
            }
        case 5892: /* module 23 call 4 */
            switch(itemIdx) {
                case 0: return "Id";
                case 1: return "Collator";
                case 2: return "Head hash";
                default: return NULL;
            }
        case 5893: /* module 23 call 5 */
            switch(itemIdx) {
                default: return NULL;
            }
        case 5894: /* module 23 call 6 */
            switch(itemIdx) {
                case 0: return "Other";
                default: return NULL;
            }
        case 6144: /* module 24 call 0 */
            switch(itemIdx) {
                case 0: return "Calls";
                default: return NULL;
            }
        case 6145: /* module 24 call 1 */
            switch(itemIdx) {
                case 0: return "Index";
                case 1: return "Call";
                default: return NULL;
            }
        case 6146: /* module 24 call 2 */
            switch(itemIdx) {
                case 0: return "Index";
                case 1: return "Call";
                default: return NULL;
            }
        case 6400: /* module 25 call 0 */
            switch(itemIdx) {
                case 0: return "Account";
                default: return NULL;
            }
        case 6401: /* module 25 call 1 */
            switch(itemIdx) {
                case 0: return "Info";
                default: return NULL;
            }
        case 6402: /* module 25 call 2 */
            switch(itemIdx) {
                case 0: return "Subs";
                default: return NULL;
            }
        case 6403: /* module 25 call 3 */
            switch(itemIdx) {
                default: return NULL;
            }
        case 6404: /* module 25 call 4 */
            switch(itemIdx) {
                case 0: return "Reg index";
                case 1: return "Max fee";
                default: return NULL;
            }
        case 6405: /* module 25 call 5 */
            switch(itemIdx) {
                case 0: return "Reg index";
                default: return NULL;
            }
        case 6406: /* module 25 call 6 */
            switch(itemIdx) {
                case 0: return "Index";
                case 1: return "Fee";
                default: return NULL;
            }
        case 6407: /* module 25 call 7 */
            switch(itemIdx) {
                case 0: return "Index";
                case 1: return "New";
                default: return NULL;
            }
        case 6408: /* module 25 call 8 */
            switch(itemIdx) {
                case 0: return "Index";
                case 1: return "Fields";
                default: return NULL;
            }
        case 6409: /* module 25 call 9 */
            switch(itemIdx) {
                case 0: return "Reg index";
                case 1: return "Target";
                case 2: return "Judgement";
                default: return NULL;
            }
        case 6410: /* module 25 call 10 */
            switch(itemIdx) {
                case 0: return "Target";
                default: return NULL;
            }
        case 6656: /* module 26 call 0 */
            switch(itemIdx) {
                case 0: return "Value";
                default: return NULL;
            }
        case 6657: /* module 26 call 1 */
            switch(itemIdx) {
                case 0: return "Pos";
                default: return NULL;
            }
        case 6658: /* module 26 call 2 */
            switch(itemIdx) {
                case 0: return "Who";
                case 1: return "Value";
                case 2: return "Tip";
                default: return NULL;
            }
        case 6659: /* module 26 call 3 */
            switch(itemIdx) {
                case 0: return "Pos";
                default: return NULL;
            }
        case 6660: /* module 26 call 4 */
            switch(itemIdx) {
                case 0: return "Candidate";
                case 1: return "Approve";
                default: return NULL;
            }
        case 6661: /* module 26 call 5 */
            switch(itemIdx) {
                case 0: return "Approve";
                default: return NULL;
            }
        case 6662: /* module 26 call 6 */
            switch(itemIdx) {
                default: return NULL;
            }
        case 6663: /* module 26 call 7 */
            switch(itemIdx) {
                case 0: return "Founder";
                case 1: return "Max members";
                case 2: return "Rules";
                default: return NULL;
            }
        case 6664: /* module 26 call 8 */
            switch(itemIdx) {
                default: return NULL;
            }
        case 6665: /* module 26 call 9 */
            switch(itemIdx) {
                case 0: return "Who";
                case 1: return "Forgive";
                default: return NULL;
            }
        case 6666: /* module 26 call 10 */
            switch(itemIdx) {
                case 0: return "Who";
                case 1: return "Judgement";
                default: return NULL;
            }
        case 6667: /* module 26 call 11 */
            switch(itemIdx) {
                case 0: return "Max";
                default: return NULL;
            }
        case 6912: /* module 27 call 0 */
            switch(itemIdx) {
                case 0: return "Account";
                case 1: return "Call";
                default: return NULL;
            }
        case 6913: /* module 27 call 1 */
            switch(itemIdx) {
                case 0: return "Lost";
                case 1: return "Rescuer";
                default: return NULL;
            }
        case 6914: /* module 27 call 2 */
            switch(itemIdx) {
                case 0: return "Friends";
                case 1: return "Threshold";
                case 2: return "Delay period";
                default: return NULL;
            }
        case 6915: /* module 27 call 3 */
            switch(itemIdx) {
                case 0: return "Account";
                default: return NULL;
            }
        case 6916: /* module 27 call 4 */
            switch(itemIdx) {
                case 0: return "Lost";
                case 1: return "Rescuer";
                default: return NULL;
            }
        case 6917: /* module 27 call 5 */
            switch(itemIdx) {
                case 0: return "Account";
                default: return NULL;
            }
        case 6918: /* module 27 call 6 */
            switch(itemIdx) {
                case 0: return "Rescuer";
                default: return NULL;
            }
        case 6919: /* module 27 call 7 */
            switch(itemIdx) {
                default: return NULL;
            }
        case 6920: /* module 27 call 8 */
            switch(itemIdx) {
                case 0: return "Account";
                default: return NULL;
            }
        case 7168: /* module 28 call 0 */
            switch(itemIdx) {
                default: return NULL;
            }
        case 7169: /* module 28 call 1 */
            switch(itemIdx) {
                case 0: return "Target";
                default: return NULL;
            }
        case 7170: /* module 28 call 2 */
            switch(itemIdx) {
                case 0: return "Target";
                case 1: return "Schedule";
                default: return NULL;
            }
        case 7424: /* module 29 call 0 */
            switch(itemIdx) {
                case 0: return "When";
                case 1: return "Maybe periodic";
                case 2: return "Priority";
                case 3: return "Call";
                default: return NULL;
            }
        case 7425: /* module 29 call 1 */
            switch(itemIdx) {
                case 0: return "When";
                case 1: return "Index";
                default: return NULL;
            }
        case 7426: /* module 29 call 2 */
            switch(itemIdx) {
                case 0: return "Id";
                case 1: return "When";
                case 2: return "Maybe periodic";
                case 3: return "Priority";
                case 4: return "Call";
                default: return NULL;
            }
        case 7427: /* module 29 call 3 */
            switch(itemIdx) {
                case 0: return "Id";
                default: return NULL;
            }
        case 7680: /* module 30 call 0 */
            switch(itemIdx) {
                case 0: return "Real";
                case 1: return "Force proxy type";
                case 2: return "Call";
                default: return NULL;
            }
        case 7681: /* module 30 call 1 */
            switch(itemIdx) {
                case 0: return "Proxy";
                case 1: return "Proxy type";
                default: return NULL;
            }
        case 7682: /* module 30 call 2 */
            switch(itemIdx) {
                case 0: return "Proxy";
                case 1: return "Proxy type";
                default: return NULL;
            }
        case 7683: /* module 30 call 3 */
            switch(itemIdx) {
                default: return NULL;
            }
        case 7684: /* module 30 call 4 */
            switch(itemIdx) {
                case 0: return "Proxy type";
                case 1: return "Index";
                default: return NULL;
            }
        case 7685: /* module 30 call 5 */
            switch(itemIdx) {
                case 0: return "Spawner";
                case 1: return "Proxy type";
                case 2: return "Index";
                case 3: return "Height";
                case 4: return "Ext index";
                default: return NULL;
            }
        case 7936: /* module 31 call 0 */
            switch(itemIdx) {
                case 0: return "Threshold";
                case 1: return "Other signatories";
                case 2: return "Maybe timepoint";
                case 3: return "Call";
                default: return NULL;
            }
        case 7937: /* module 31 call 1 */
            switch(itemIdx) {
                case 0: return "Threshold";
                case 1: return "Other signatories";
                case 2: return "Maybe timepoint";
                case 3: return "Call hash";
                default: return NULL;
            }
        case 7938: /* module 31 call 2 */
            switch(itemIdx) {
                case 0: return "Threshold";
                case 1: return "Other signatories";
                case 2: return "Timepoint";
                case 3: return "Call hash";
                default: return NULL;
            }
        default:
            return NULL;
    }

    return NULL;
}

parser_error_t _getMethod_ItemValue(
    pd_Method_t *m,
    uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx,
    char *outValue, uint16_t outValueLen,
    uint8_t pageIdx, uint8_t *pageCount) {
    uint16_t callPrivIdx = ( (uint16_t) moduleIdx << 8u) + callIdx;

    switch(callPrivIdx) {
        case 0: /* module 0 call 0 */
        switch(itemIdx) {
            case 0: /* system_fill_block - _ratio */;
                return _toStringPerbill(
                    &m->basic.system_fill_block._ratio,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 1: /* module 0 call 1 */
        switch(itemIdx) {
            case 0: /* system_remark - _remark */;
                return _toStringBytes(
                    &m->basic.system_remark._remark,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 2: /* module 0 call 2 */
        switch(itemIdx) {
            case 0: /* system_set_heap_pages - pages */;
                return _toStringu64(
                    &m->basic.system_set_heap_pages.pages,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 3: /* module 0 call 3 */
        switch(itemIdx) {
            case 0: /* system_set_code - code */;
                return _toStringBytes(
                    &m->basic.system_set_code.code,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 4: /* module 0 call 4 */
        switch(itemIdx) {
            case 0: /* system_set_code_without_checks - code */;
                return _toStringBytes(
                    &m->basic.system_set_code_without_checks.code,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 5: /* module 0 call 5 */
        switch(itemIdx) {
            case 0: /* system_set_changes_trie_config - changes_trie_config */;
                return _toStringOptionChangesTrieConfiguration(
                    &m->basic.system_set_changes_trie_config.changes_trie_config,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 6: /* module 0 call 6 */
        switch(itemIdx) {
            case 0: /* system_set_storage - items */;
                return _toStringVecKeyValue(
                    &m->basic.system_set_storage.items,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 7: /* module 0 call 7 */
        switch(itemIdx) {
            case 0: /* system_kill_storage - keys */;
                return _toStringVecKey(
                    &m->basic.system_kill_storage.keys,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 8: /* module 0 call 8 */
        switch(itemIdx) {
            case 0: /* system_kill_prefix - prefix */;
                return _toStringKey(
                    &m->basic.system_kill_prefix.prefix,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 1: /* system_kill_prefix - _subkeys */;
                return _toStringu32(
                    &m->basic.system_kill_prefix._subkeys,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 9: /* module 0 call 9 */
        switch(itemIdx) {
            default:
                return parser_no_data;
        }
        case 512: /* module 2 call 0 */
        switch(itemIdx) {
            case 0: /* timestamp_set - now */;
                return _toStringCompactMoment(
                    &m->basic.timestamp_set.now,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 768: /* module 3 call 0 */
        switch(itemIdx) {
            case 0: /* indices_claim - index */;
                return _toStringAccountIndex(
                    &m->basic.indices_claim.index,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 769: /* module 3 call 1 */
        switch(itemIdx) {
            case 0: /* indices_transfer - new_ */;
                return _toStringAccountId(
                    &m->basic.indices_transfer.new_,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 1: /* indices_transfer - index */;
                return _toStringAccountIndex(
                    &m->basic.indices_transfer.index,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 770: /* module 3 call 2 */
        switch(itemIdx) {
            case 0: /* indices_free - index */;
                return _toStringAccountIndex(
                    &m->basic.indices_free.index,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 771: /* module 3 call 3 */
        switch(itemIdx) {
            case 0: /* indices_force_transfer - new_ */;
                return _toStringAccountId(
                    &m->basic.indices_force_transfer.new_,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 1: /* indices_force_transfer - index */;
                return _toStringAccountIndex(
                    &m->basic.indices_force_transfer.index,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 2: /* indices_force_transfer - freeze */;
                return _toStringbool(
                    &m->basic.indices_force_transfer.freeze,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 772: /* module 3 call 4 */
        switch(itemIdx) {
            case 0: /* indices_freeze - index */;
                return _toStringAccountIndex(
                    &m->basic.indices_freeze.index,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 1024: /* module 4 call 0 */
        switch(itemIdx) {
            case 0: /* balances_transfer - dest */;
                return _toStringLookupSource(
                    &m->basic.balances_transfer.dest,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 1: /* balances_transfer - value */;
                return _toStringCompactBalance(
                    &m->basic.balances_transfer.value,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 1025: /* module 4 call 1 */
        switch(itemIdx) {
            case 0: /* balances_set_balance - who */;
                return _toStringLookupSource(
                    &m->basic.balances_set_balance.who,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 1: /* balances_set_balance - new_free */;
                return _toStringCompactBalance(
                    &m->basic.balances_set_balance.new_free,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 2: /* balances_set_balance - new_reserved */;
                return _toStringCompactBalance(
                    &m->basic.balances_set_balance.new_reserved,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 1026: /* module 4 call 2 */
        switch(itemIdx) {
            case 0: /* balances_force_transfer - source */;
                return _toStringLookupSource(
                    &m->basic.balances_force_transfer.source,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 1: /* balances_force_transfer - dest */;
                return _toStringLookupSource(
                    &m->basic.balances_force_transfer.dest,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 2: /* balances_force_transfer - value */;
                return _toStringCompactBalance(
                    &m->basic.balances_force_transfer.value,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 1027: /* module 4 call 3 */
        switch(itemIdx) {
            case 0: /* balances_transfer_keep_alive - dest */;
                return _toStringLookupSource(
                    &m->basic.balances_transfer_keep_alive.dest,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 1: /* balances_transfer_keep_alive - value */;
                return _toStringCompactBalance(
                    &m->basic.balances_transfer_keep_alive.value,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 1280: /* module 5 call 0 */
        switch(itemIdx) {
            case 0: /* authorship_set_uncles - new_uncles */;
                return _toStringVecHeader(
                    &m->basic.authorship_set_uncles.new_uncles,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 1536: /* module 6 call 0 */
        switch(itemIdx) {
            case 0: /* staking_bond - controller */;
                return _toStringLookupSource(
                    &m->basic.staking_bond.controller,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 1: /* staking_bond - value */;
                return _toStringCompactBalanceOf(
                    &m->basic.staking_bond.value,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 2: /* staking_bond - payee */;
                return _toStringRewardDestination(
                    &m->basic.staking_bond.payee,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 1537: /* module 6 call 1 */
        switch(itemIdx) {
            case 0: /* staking_bond_extra - max_additional */;
                return _toStringCompactBalanceOf(
                    &m->basic.staking_bond_extra.max_additional,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 1538: /* module 6 call 2 */
        switch(itemIdx) {
            case 0: /* staking_unbond - value */;
                return _toStringCompactBalanceOf(
                    &m->basic.staking_unbond.value,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 1539: /* module 6 call 3 */
        switch(itemIdx) {
            case 0: /* staking_withdraw_unbonded - num_slashing_spans */;
                return _toStringu32(
                    &m->basic.staking_withdraw_unbonded.num_slashing_spans,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 1540: /* module 6 call 4 */
        switch(itemIdx) {
            case 0: /* staking_validate - prefs */;
                return _toStringValidatorPrefs(
                    &m->basic.staking_validate.prefs,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 1541: /* module 6 call 5 */
        switch(itemIdx) {
            case 0: /* staking_nominate - targets */;
                return _toStringVecLookupSource(
                    &m->basic.staking_nominate.targets,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 1542: /* module 6 call 6 */
        switch(itemIdx) {
            default:
                return parser_no_data;
        }
        case 1543: /* module 6 call 7 */
        switch(itemIdx) {
            case 0: /* staking_set_payee - payee */;
                return _toStringRewardDestination(
                    &m->basic.staking_set_payee.payee,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 1544: /* module 6 call 8 */
        switch(itemIdx) {
            case 0: /* staking_set_controller - controller */;
                return _toStringLookupSource(
                    &m->basic.staking_set_controller.controller,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 1545: /* module 6 call 9 */
        switch(itemIdx) {
            case 0: /* staking_set_validator_count - new_ */;
                return _toStringCompactu32(
                    &m->basic.staking_set_validator_count.new_,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 1546: /* module 6 call 10 */
        switch(itemIdx) {
            default:
                return parser_no_data;
        }
        case 1547: /* module 6 call 11 */
        switch(itemIdx) {
            default:
                return parser_no_data;
        }
        case 1548: /* module 6 call 12 */
        switch(itemIdx) {
            case 0: /* staking_set_invulnerables - validators */;
                return _toStringVecAccountId(
                    &m->basic.staking_set_invulnerables.validators,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 1549: /* module 6 call 13 */
        switch(itemIdx) {
            case 0: /* staking_force_unstake - stash */;
                return _toStringAccountId(
                    &m->basic.staking_force_unstake.stash,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 1: /* staking_force_unstake - num_slashing_spans */;
                return _toStringu32(
                    &m->basic.staking_force_unstake.num_slashing_spans,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 1550: /* module 6 call 14 */
        switch(itemIdx) {
            default:
                return parser_no_data;
        }
        case 1551: /* module 6 call 15 */
        switch(itemIdx) {
            case 0: /* staking_cancel_deferred_slash - era */;
                return _toStringEraIndex(
                    &m->basic.staking_cancel_deferred_slash.era,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 1: /* staking_cancel_deferred_slash - slash_indices */;
                return _toStringVecu32(
                    &m->basic.staking_cancel_deferred_slash.slash_indices,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 1552: /* module 6 call 16 */
        switch(itemIdx) {
            case 0: /* staking_payout_stakers - validator_stash */;
                return _toStringAccountId(
                    &m->basic.staking_payout_stakers.validator_stash,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 1: /* staking_payout_stakers - era */;
                return _toStringEraIndex(
                    &m->basic.staking_payout_stakers.era,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 1553: /* module 6 call 17 */
        switch(itemIdx) {
            case 0: /* staking_rebond - value */;
                return _toStringCompactBalanceOf(
                    &m->basic.staking_rebond.value,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 1554: /* module 6 call 18 */
        switch(itemIdx) {
            case 0: /* staking_set_history_depth - new_history_depth */;
                return _toStringCompactEraIndex(
                    &m->basic.staking_set_history_depth.new_history_depth,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 1: /* staking_set_history_depth - _era_items_deleted */;
                return _toStringCompactu32(
                    &m->basic.staking_set_history_depth._era_items_deleted,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 1555: /* module 6 call 19 */
        switch(itemIdx) {
            case 0: /* staking_reap_stash - stash */;
                return _toStringAccountId(
                    &m->basic.staking_reap_stash.stash,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 1: /* staking_reap_stash - num_slashing_spans */;
                return _toStringu32(
                    &m->basic.staking_reap_stash.num_slashing_spans,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 1556: /* module 6 call 20 */
        switch(itemIdx) {
            case 0: /* staking_submit_election_solution - winners */;
                return _toStringVecValidatorIndex(
                    &m->basic.staking_submit_election_solution.winners,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 1: /* staking_submit_election_solution - compact */;
                return _toStringCompactAssignments(
                    &m->basic.staking_submit_election_solution.compact,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 2: /* staking_submit_election_solution - score */;
                return _toStringElectionScore(
                    &m->basic.staking_submit_election_solution.score,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 3: /* staking_submit_election_solution - era */;
                return _toStringEraIndex(
                    &m->basic.staking_submit_election_solution.era,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 4: /* staking_submit_election_solution - size */;
                return _toStringElectionSize(
                    &m->basic.staking_submit_election_solution.size,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 1557: /* module 6 call 21 */
        switch(itemIdx) {
            case 0: /* staking_submit_election_solution_unsigned - winners */;
                return _toStringVecValidatorIndex(
                    &m->basic.staking_submit_election_solution_unsigned.winners,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 1: /* staking_submit_election_solution_unsigned - compact */;
                return _toStringCompactAssignments(
                    &m->basic.staking_submit_election_solution_unsigned.compact,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 2: /* staking_submit_election_solution_unsigned - score */;
                return _toStringElectionScore(
                    &m->basic.staking_submit_election_solution_unsigned.score,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 3: /* staking_submit_election_solution_unsigned - era */;
                return _toStringEraIndex(
                    &m->basic.staking_submit_election_solution_unsigned.era,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 4: /* staking_submit_election_solution_unsigned - size */;
                return _toStringElectionSize(
                    &m->basic.staking_submit_election_solution_unsigned.size,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 2048: /* module 8 call 0 */
        switch(itemIdx) {
            case 0: /* session_set_keys - keys */;
                return _toStringKeys(
                    &m->basic.session_set_keys.keys,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 1: /* session_set_keys - proof */;
                return _toStringBytes(
                    &m->basic.session_set_keys.proof,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 2049: /* module 8 call 1 */
        switch(itemIdx) {
            default:
                return parser_no_data;
        }
        case 2304: /* module 9 call 0 */
        switch(itemIdx) {
            case 0: /* finalitytracker_final_hint - hint */;
                return _toStringCompactBlockNumber(
                    &m->basic.finalitytracker_final_hint.hint,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 2560: /* module 10 call 0 */
        switch(itemIdx) {
            case 0: /* grandpa_report_equivocation - equivocation_proof */;
                return _toStringEquivocationProof(
                    &m->basic.grandpa_report_equivocation.equivocation_proof,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 1: /* grandpa_report_equivocation - key_owner_proof */;
                return _toStringKeyOwnerProof(
                    &m->basic.grandpa_report_equivocation.key_owner_proof,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 2816: /* module 11 call 0 */
        switch(itemIdx) {
            case 0: /* imonline_heartbeat - heartbeat */;
                return _toStringHeartbeat(
                    &m->basic.imonline_heartbeat.heartbeat,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 1: /* imonline_heartbeat - _signature */;
                return _toStringSignature(
                    &m->basic.imonline_heartbeat._signature,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 3328: /* module 13 call 0 */
        switch(itemIdx) {
            case 0: /* democracy_propose - proposal_hash */;
                return _toStringHash(
                    &m->basic.democracy_propose.proposal_hash,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 1: /* democracy_propose - value */;
                return _toStringCompactBalanceOf(
                    &m->basic.democracy_propose.value,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 3329: /* module 13 call 1 */
        switch(itemIdx) {
            case 0: /* democracy_second - proposal */;
                return _toStringCompactPropIndex(
                    &m->basic.democracy_second.proposal,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 1: /* democracy_second - seconds_upper_bound */;
                return _toStringCompactu32(
                    &m->basic.democracy_second.seconds_upper_bound,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 3330: /* module 13 call 2 */
        switch(itemIdx) {
            case 0: /* democracy_vote - ref_index */;
                return _toStringCompactReferendumIndex(
                    &m->basic.democracy_vote.ref_index,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 1: /* democracy_vote - vote */;
                return _toStringAccountVote(
                    &m->basic.democracy_vote.vote,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 3331: /* module 13 call 3 */
        switch(itemIdx) {
            case 0: /* democracy_emergency_cancel - ref_index */;
                return _toStringReferendumIndex(
                    &m->basic.democracy_emergency_cancel.ref_index,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 3332: /* module 13 call 4 */
        switch(itemIdx) {
            case 0: /* democracy_external_propose - proposal_hash */;
                return _toStringHash(
                    &m->basic.democracy_external_propose.proposal_hash,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 3333: /* module 13 call 5 */
        switch(itemIdx) {
            case 0: /* democracy_external_propose_majority - proposal_hash */;
                return _toStringHash(
                    &m->basic.democracy_external_propose_majority.proposal_hash,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 3334: /* module 13 call 6 */
        switch(itemIdx) {
            case 0: /* democracy_external_propose_default - proposal_hash */;
                return _toStringHash(
                    &m->basic.democracy_external_propose_default.proposal_hash,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 3335: /* module 13 call 7 */
        switch(itemIdx) {
            case 0: /* democracy_fast_track - proposal_hash */;
                return _toStringHash(
                    &m->basic.democracy_fast_track.proposal_hash,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 1: /* democracy_fast_track - voting_period */;
                return _toStringBlockNumber(
                    &m->basic.democracy_fast_track.voting_period,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 2: /* democracy_fast_track - delay */;
                return _toStringBlockNumber(
                    &m->basic.democracy_fast_track.delay,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 3336: /* module 13 call 8 */
        switch(itemIdx) {
            case 0: /* democracy_veto_external - proposal_hash */;
                return _toStringHash(
                    &m->basic.democracy_veto_external.proposal_hash,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 3337: /* module 13 call 9 */
        switch(itemIdx) {
            case 0: /* democracy_cancel_referendum - ref_index */;
                return _toStringCompactReferendumIndex(
                    &m->basic.democracy_cancel_referendum.ref_index,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 3338: /* module 13 call 10 */
        switch(itemIdx) {
            case 0: /* democracy_cancel_queued - which */;
                return _toStringReferendumIndex(
                    &m->basic.democracy_cancel_queued.which,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 3339: /* module 13 call 11 */
        switch(itemIdx) {
            case 0: /* democracy_delegate - to */;
                return _toStringAccountId(
                    &m->basic.democracy_delegate.to,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 1: /* democracy_delegate - conviction */;
                return _toStringConviction(
                    &m->basic.democracy_delegate.conviction,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 2: /* democracy_delegate - balance */;
                return _toStringBalanceOf(
                    &m->basic.democracy_delegate.balance,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 3340: /* module 13 call 12 */
        switch(itemIdx) {
            default:
                return parser_no_data;
        }
        case 3341: /* module 13 call 13 */
        switch(itemIdx) {
            default:
                return parser_no_data;
        }
        case 3342: /* module 13 call 14 */
        switch(itemIdx) {
            case 0: /* democracy_note_preimage - encoded_proposal */;
                return _toStringBytes(
                    &m->basic.democracy_note_preimage.encoded_proposal,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 3343: /* module 13 call 15 */
        switch(itemIdx) {
            case 0: /* democracy_note_preimage_operational - encoded_proposal */;
                return _toStringBytes(
                    &m->basic.democracy_note_preimage_operational.encoded_proposal,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 3344: /* module 13 call 16 */
        switch(itemIdx) {
            case 0: /* democracy_note_imminent_preimage - encoded_proposal */;
                return _toStringBytes(
                    &m->basic.democracy_note_imminent_preimage.encoded_proposal,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 3345: /* module 13 call 17 */
        switch(itemIdx) {
            case 0: /* democracy_note_imminent_preimage_operational - encoded_proposal */;
                return _toStringBytes(
                    &m->basic.democracy_note_imminent_preimage_operational.encoded_proposal,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 3346: /* module 13 call 18 */
        switch(itemIdx) {
            case 0: /* democracy_reap_preimage - proposal_hash */;
                return _toStringHash(
                    &m->basic.democracy_reap_preimage.proposal_hash,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 1: /* democracy_reap_preimage - proposal_len_upper_bound */;
                return _toStringCompactu32(
                    &m->basic.democracy_reap_preimage.proposal_len_upper_bound,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 3347: /* module 13 call 19 */
        switch(itemIdx) {
            case 0: /* democracy_unlock - target */;
                return _toStringAccountId(
                    &m->basic.democracy_unlock.target,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 3348: /* module 13 call 20 */
        switch(itemIdx) {
            case 0: /* democracy_remove_vote - index */;
                return _toStringReferendumIndex(
                    &m->basic.democracy_remove_vote.index,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 3349: /* module 13 call 21 */
        switch(itemIdx) {
            case 0: /* democracy_remove_other_vote - target */;
                return _toStringAccountId(
                    &m->basic.democracy_remove_other_vote.target,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 1: /* democracy_remove_other_vote - index */;
                return _toStringReferendumIndex(
                    &m->basic.democracy_remove_other_vote.index,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 3350: /* module 13 call 22 */
        switch(itemIdx) {
            case 0: /* democracy_enact_proposal - proposal_hash */;
                return _toStringHash(
                    &m->basic.democracy_enact_proposal.proposal_hash,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 1: /* democracy_enact_proposal - index */;
                return _toStringReferendumIndex(
                    &m->basic.democracy_enact_proposal.index,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 3584: /* module 14 call 0 */
        switch(itemIdx) {
            case 0: /* council_set_members - new_members */;
                return _toStringVecAccountId(
                    &m->basic.council_set_members.new_members,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 1: /* council_set_members - prime */;
                return _toStringOptionAccountId(
                    &m->basic.council_set_members.prime,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 2: /* council_set_members - old_count */;
                return _toStringMemberCount(
                    &m->basic.council_set_members.old_count,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 3585: /* module 14 call 1 */
        switch(itemIdx) {
            case 0: /* council_execute - proposal */;
                return _toStringProposal(
                    &m->nested.council_execute.proposal,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 1: /* council_execute - length_bound */;
                return _toStringCompactu32(
                    &m->nested.council_execute.length_bound,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 3586: /* module 14 call 2 */
        switch(itemIdx) {
            case 0: /* council_propose - threshold */;
                return _toStringCompactMemberCount(
                    &m->nested.council_propose.threshold,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 1: /* council_propose - proposal */;
                return _toStringProposal(
                    &m->nested.council_propose.proposal,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 2: /* council_propose - length_bound */;
                return _toStringCompactu32(
                    &m->nested.council_propose.length_bound,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 3587: /* module 14 call 3 */
        switch(itemIdx) {
            case 0: /* council_vote - proposal */;
                return _toStringHash(
                    &m->basic.council_vote.proposal,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 1: /* council_vote - index */;
                return _toStringCompactProposalIndex(
                    &m->basic.council_vote.index,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 2: /* council_vote - approve */;
                return _toStringbool(
                    &m->basic.council_vote.approve,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 3588: /* module 14 call 4 */
        switch(itemIdx) {
            case 0: /* council_close - proposal_hash */;
                return _toStringHash(
                    &m->basic.council_close.proposal_hash,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 1: /* council_close - index */;
                return _toStringCompactProposalIndex(
                    &m->basic.council_close.index,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 2: /* council_close - proposal_weight_bound */;
                return _toStringCompactWeight(
                    &m->basic.council_close.proposal_weight_bound,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 3: /* council_close - length_bound */;
                return _toStringCompactu32(
                    &m->basic.council_close.length_bound,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 3589: /* module 14 call 5 */
        switch(itemIdx) {
            case 0: /* council_disapprove_proposal - proposal_hash */;
                return _toStringHash(
                    &m->basic.council_disapprove_proposal.proposal_hash,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 3840: /* module 15 call 0 */
        switch(itemIdx) {
            case 0: /* technicalcommittee_set_members - new_members */;
                return _toStringVecAccountId(
                    &m->basic.technicalcommittee_set_members.new_members,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 1: /* technicalcommittee_set_members - prime */;
                return _toStringOptionAccountId(
                    &m->basic.technicalcommittee_set_members.prime,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 2: /* technicalcommittee_set_members - old_count */;
                return _toStringMemberCount(
                    &m->basic.technicalcommittee_set_members.old_count,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 3841: /* module 15 call 1 */
        switch(itemIdx) {
            case 0: /* technicalcommittee_execute - proposal */;
                return _toStringProposal(
                    &m->nested.technicalcommittee_execute.proposal,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 1: /* technicalcommittee_execute - length_bound */;
                return _toStringCompactu32(
                    &m->nested.technicalcommittee_execute.length_bound,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 3842: /* module 15 call 2 */
        switch(itemIdx) {
            case 0: /* technicalcommittee_propose - threshold */;
                return _toStringCompactMemberCount(
                    &m->nested.technicalcommittee_propose.threshold,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 1: /* technicalcommittee_propose - proposal */;
                return _toStringProposal(
                    &m->nested.technicalcommittee_propose.proposal,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 2: /* technicalcommittee_propose - length_bound */;
                return _toStringCompactu32(
                    &m->nested.technicalcommittee_propose.length_bound,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 3843: /* module 15 call 3 */
        switch(itemIdx) {
            case 0: /* technicalcommittee_vote - proposal */;
                return _toStringHash(
                    &m->basic.technicalcommittee_vote.proposal,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 1: /* technicalcommittee_vote - index */;
                return _toStringCompactProposalIndex(
                    &m->basic.technicalcommittee_vote.index,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 2: /* technicalcommittee_vote - approve */;
                return _toStringbool(
                    &m->basic.technicalcommittee_vote.approve,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 3844: /* module 15 call 4 */
        switch(itemIdx) {
            case 0: /* technicalcommittee_close - proposal_hash */;
                return _toStringHash(
                    &m->basic.technicalcommittee_close.proposal_hash,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 1: /* technicalcommittee_close - index */;
                return _toStringCompactProposalIndex(
                    &m->basic.technicalcommittee_close.index,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 2: /* technicalcommittee_close - proposal_weight_bound */;
                return _toStringCompactWeight(
                    &m->basic.technicalcommittee_close.proposal_weight_bound,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 3: /* technicalcommittee_close - length_bound */;
                return _toStringCompactu32(
                    &m->basic.technicalcommittee_close.length_bound,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 3845: /* module 15 call 5 */
        switch(itemIdx) {
            case 0: /* technicalcommittee_disapprove_proposal - proposal_hash */;
                return _toStringHash(
                    &m->basic.technicalcommittee_disapprove_proposal.proposal_hash,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 4096: /* module 16 call 0 */
        switch(itemIdx) {
            case 0: /* electionsphragmen_vote - votes */;
                return _toStringVecAccountId(
                    &m->basic.electionsphragmen_vote.votes,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 1: /* electionsphragmen_vote - value */;
                return _toStringCompactBalanceOf(
                    &m->basic.electionsphragmen_vote.value,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 4097: /* module 16 call 1 */
        switch(itemIdx) {
            default:
                return parser_no_data;
        }
        case 4098: /* module 16 call 2 */
        switch(itemIdx) {
            case 0: /* electionsphragmen_report_defunct_voter - defunct */;
                return _toStringDefunctVoter(
                    &m->basic.electionsphragmen_report_defunct_voter.defunct,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 4099: /* module 16 call 3 */
        switch(itemIdx) {
            case 0: /* electionsphragmen_submit_candidacy - candidate_count */;
                return _toStringCompactu32(
                    &m->basic.electionsphragmen_submit_candidacy.candidate_count,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 4100: /* module 16 call 4 */
        switch(itemIdx) {
            case 0: /* electionsphragmen_renounce_candidacy - renouncing */;
                return _toStringRenouncing(
                    &m->basic.electionsphragmen_renounce_candidacy.renouncing,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 4101: /* module 16 call 5 */
        switch(itemIdx) {
            case 0: /* electionsphragmen_remove_member - who */;
                return _toStringLookupSource(
                    &m->basic.electionsphragmen_remove_member.who,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 1: /* electionsphragmen_remove_member - has_replacement */;
                return _toStringbool(
                    &m->basic.electionsphragmen_remove_member.has_replacement,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 4352: /* module 17 call 0 */
        switch(itemIdx) {
            case 0: /* technicalmembership_add_member - who */;
                return _toStringAccountId(
                    &m->basic.technicalmembership_add_member.who,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 4353: /* module 17 call 1 */
        switch(itemIdx) {
            case 0: /* technicalmembership_remove_member - who */;
                return _toStringAccountId(
                    &m->basic.technicalmembership_remove_member.who,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 4354: /* module 17 call 2 */
        switch(itemIdx) {
            case 0: /* technicalmembership_swap_member - remove */;
                return _toStringAccountId(
                    &m->basic.technicalmembership_swap_member.remove,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 1: /* technicalmembership_swap_member - add */;
                return _toStringAccountId(
                    &m->basic.technicalmembership_swap_member.add,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 4355: /* module 17 call 3 */
        switch(itemIdx) {
            case 0: /* technicalmembership_reset_members - members */;
                return _toStringVecAccountId(
                    &m->basic.technicalmembership_reset_members.members,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 4356: /* module 17 call 4 */
        switch(itemIdx) {
            case 0: /* technicalmembership_change_key - new_ */;
                return _toStringAccountId(
                    &m->basic.technicalmembership_change_key.new_,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 4357: /* module 17 call 5 */
        switch(itemIdx) {
            case 0: /* technicalmembership_set_prime - who */;
                return _toStringAccountId(
                    &m->basic.technicalmembership_set_prime.who,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 4358: /* module 17 call 6 */
        switch(itemIdx) {
            default:
                return parser_no_data;
        }
        case 4608: /* module 18 call 0 */
        switch(itemIdx) {
            case 0: /* treasury_propose_spend - value */;
                return _toStringCompactBalanceOf(
                    &m->basic.treasury_propose_spend.value,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 1: /* treasury_propose_spend - beneficiary */;
                return _toStringLookupSource(
                    &m->basic.treasury_propose_spend.beneficiary,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 4609: /* module 18 call 1 */
        switch(itemIdx) {
            case 0: /* treasury_reject_proposal - proposal_id */;
                return _toStringCompactProposalIndex(
                    &m->basic.treasury_reject_proposal.proposal_id,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 4610: /* module 18 call 2 */
        switch(itemIdx) {
            case 0: /* treasury_approve_proposal - proposal_id */;
                return _toStringCompactProposalIndex(
                    &m->basic.treasury_approve_proposal.proposal_id,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 4611: /* module 18 call 3 */
        switch(itemIdx) {
            case 0: /* treasury_report_awesome - reason */;
                return _toStringBytes(
                    &m->basic.treasury_report_awesome.reason,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 1: /* treasury_report_awesome - who */;
                return _toStringAccountId(
                    &m->basic.treasury_report_awesome.who,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 4612: /* module 18 call 4 */
        switch(itemIdx) {
            case 0: /* treasury_retract_tip - hash */;
                return _toStringHash(
                    &m->basic.treasury_retract_tip.hash,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 4613: /* module 18 call 5 */
        switch(itemIdx) {
            case 0: /* treasury_tip_new - reason */;
                return _toStringBytes(
                    &m->basic.treasury_tip_new.reason,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 1: /* treasury_tip_new - who */;
                return _toStringAccountId(
                    &m->basic.treasury_tip_new.who,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 2: /* treasury_tip_new - tip_value */;
                return _toStringBalanceOf(
                    &m->basic.treasury_tip_new.tip_value,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 4614: /* module 18 call 6 */
        switch(itemIdx) {
            case 0: /* treasury_tip - hash */;
                return _toStringHash(
                    &m->basic.treasury_tip.hash,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 1: /* treasury_tip - tip_value */;
                return _toStringBalanceOf(
                    &m->basic.treasury_tip.tip_value,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 4615: /* module 18 call 7 */
        switch(itemIdx) {
            case 0: /* treasury_close_tip - hash */;
                return _toStringHash(
                    &m->basic.treasury_close_tip.hash,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 4864: /* module 19 call 0 */
        switch(itemIdx) {
            case 0: /* claims_claim - dest */;
                return _toStringAccountId(
                    &m->basic.claims_claim.dest,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 1: /* claims_claim - ethereum_signature */;
                return _toStringEcdsaSignature(
                    &m->basic.claims_claim.ethereum_signature,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 4865: /* module 19 call 1 */
        switch(itemIdx) {
            case 0: /* claims_mint_claim - who */;
                return _toStringEthereumAddress(
                    &m->basic.claims_mint_claim.who,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 1: /* claims_mint_claim - value */;
                return _toStringBalanceOf(
                    &m->basic.claims_mint_claim.value,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 2: /* claims_mint_claim - vesting_schedule */;
                return _toStringOptionTupleBalanceOfBalanceOfBlockNumber(
                    &m->basic.claims_mint_claim.vesting_schedule,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 3: /* claims_mint_claim - statement */;
                return _toStringOptionStatementKind(
                    &m->basic.claims_mint_claim.statement,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 4866: /* module 19 call 2 */
        switch(itemIdx) {
            case 0: /* claims_claim_attest - dest */;
                return _toStringAccountId(
                    &m->basic.claims_claim_attest.dest,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 1: /* claims_claim_attest - ethereum_signature */;
                return _toStringEcdsaSignature(
                    &m->basic.claims_claim_attest.ethereum_signature,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 2: /* claims_claim_attest - statement */;
                return _toStringBytes(
                    &m->basic.claims_claim_attest.statement,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 4867: /* module 19 call 3 */
        switch(itemIdx) {
            case 0: /* claims_attest - statement */;
                return _toStringBytes(
                    &m->basic.claims_attest.statement,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 4868: /* module 19 call 4 */
        switch(itemIdx) {
            case 0: /* claims_move_claim - old */;
                return _toStringEthereumAddress(
                    &m->basic.claims_move_claim.old,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 1: /* claims_move_claim - new_ */;
                return _toStringEthereumAddress(
                    &m->basic.claims_move_claim.new_,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 2: /* claims_move_claim - maybe_preclaim */;
                return _toStringOptionAccountId(
                    &m->basic.claims_move_claim.maybe_preclaim,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 5120: /* module 20 call 0 */
        switch(itemIdx) {
            case 0: /* parachains_set_heads - heads */;
                return _toStringVecAttestedCandidate(
                    &m->basic.parachains_set_heads.heads,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 5121: /* module 20 call 1 */
        switch(itemIdx) {
            case 0: /* parachains_report_double_vote - report */;
                return _toStringDoubleVoteReport(
                    &m->basic.parachains_report_double_vote.report,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 5376: /* module 21 call 0 */
        switch(itemIdx) {
            case 0: /* attestations_more_attestations - _more */;
                return _toStringMoreAttestations(
                    &m->basic.attestations_more_attestations._more,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 5632: /* module 22 call 0 */
        switch(itemIdx) {
            case 0: /* slots_new_auction - duration */;
                return _toStringCompactBlockNumber(
                    &m->basic.slots_new_auction.duration,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 1: /* slots_new_auction - lease_period_index */;
                return _toStringCompactLeasePeriodOf(
                    &m->basic.slots_new_auction.lease_period_index,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 5633: /* module 22 call 1 */
        switch(itemIdx) {
            case 0: /* slots_bid - sub */;
                return _toStringCompactSubId(
                    &m->basic.slots_bid.sub,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 1: /* slots_bid - auction_index */;
                return _toStringCompactAuctionIndex(
                    &m->basic.slots_bid.auction_index,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 2: /* slots_bid - first_slot */;
                return _toStringCompactLeasePeriodOf(
                    &m->basic.slots_bid.first_slot,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 3: /* slots_bid - last_slot */;
                return _toStringCompactLeasePeriodOf(
                    &m->basic.slots_bid.last_slot,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 4: /* slots_bid - amount */;
                return _toStringCompactBalanceOf(
                    &m->basic.slots_bid.amount,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 5634: /* module 22 call 2 */
        switch(itemIdx) {
            case 0: /* slots_bid_renew - auction_index */;
                return _toStringCompactAuctionIndex(
                    &m->basic.slots_bid_renew.auction_index,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 1: /* slots_bid_renew - first_slot */;
                return _toStringCompactLeasePeriodOf(
                    &m->basic.slots_bid_renew.first_slot,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 2: /* slots_bid_renew - last_slot */;
                return _toStringCompactLeasePeriodOf(
                    &m->basic.slots_bid_renew.last_slot,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 3: /* slots_bid_renew - amount */;
                return _toStringCompactBalanceOf(
                    &m->basic.slots_bid_renew.amount,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 5635: /* module 22 call 3 */
        switch(itemIdx) {
            case 0: /* slots_set_offboarding - dest */;
                return _toStringLookupSource(
                    &m->basic.slots_set_offboarding.dest,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 5636: /* module 22 call 4 */
        switch(itemIdx) {
            case 0: /* slots_fix_deploy_data - sub */;
                return _toStringCompactSubId(
                    &m->basic.slots_fix_deploy_data.sub,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 1: /* slots_fix_deploy_data - para_id */;
                return _toStringCompactParaId(
                    &m->basic.slots_fix_deploy_data.para_id,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 2: /* slots_fix_deploy_data - code_hash */;
                return _toStringHash(
                    &m->basic.slots_fix_deploy_data.code_hash,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 3: /* slots_fix_deploy_data - code_size */;
                return _toStringu32(
                    &m->basic.slots_fix_deploy_data.code_size,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 4: /* slots_fix_deploy_data - initial_head_data */;
                return _toStringHeadData(
                    &m->basic.slots_fix_deploy_data.initial_head_data,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 5637: /* module 22 call 5 */
        switch(itemIdx) {
            case 0: /* slots_elaborate_deploy_data - para_id */;
                return _toStringCompactParaId(
                    &m->basic.slots_elaborate_deploy_data.para_id,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 1: /* slots_elaborate_deploy_data - code */;
                return _toStringValidationCode(
                    &m->basic.slots_elaborate_deploy_data.code,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 5888: /* module 23 call 0 */
        switch(itemIdx) {
            case 0: /* registrar_register_para - id */;
                return _toStringCompactParaId(
                    &m->basic.registrar_register_para.id,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 1: /* registrar_register_para - info */;
                return _toStringParaInfo(
                    &m->basic.registrar_register_para.info,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 2: /* registrar_register_para - code */;
                return _toStringValidationCode(
                    &m->basic.registrar_register_para.code,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 3: /* registrar_register_para - initial_head_data */;
                return _toStringHeadData(
                    &m->basic.registrar_register_para.initial_head_data,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 5889: /* module 23 call 1 */
        switch(itemIdx) {
            case 0: /* registrar_deregister_para - id */;
                return _toStringCompactParaId(
                    &m->basic.registrar_deregister_para.id,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 5890: /* module 23 call 2 */
        switch(itemIdx) {
            case 0: /* registrar_set_thread_count - count */;
                return _toStringu32(
                    &m->basic.registrar_set_thread_count.count,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 5891: /* module 23 call 3 */
        switch(itemIdx) {
            case 0: /* registrar_register_parathread - code */;
                return _toStringValidationCode(
                    &m->basic.registrar_register_parathread.code,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 1: /* registrar_register_parathread - initial_head_data */;
                return _toStringHeadData(
                    &m->basic.registrar_register_parathread.initial_head_data,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 5892: /* module 23 call 4 */
        switch(itemIdx) {
            case 0: /* registrar_select_parathread - _id */;
                return _toStringCompactParaId(
                    &m->basic.registrar_select_parathread._id,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 1: /* registrar_select_parathread - _collator */;
                return _toStringCollatorId(
                    &m->basic.registrar_select_parathread._collator,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 2: /* registrar_select_parathread - _head_hash */;
                return _toStringHash(
                    &m->basic.registrar_select_parathread._head_hash,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 5893: /* module 23 call 5 */
        switch(itemIdx) {
            default:
                return parser_no_data;
        }
        case 5894: /* module 23 call 6 */
        switch(itemIdx) {
            case 0: /* registrar_swap - other */;
                return _toStringCompactParaId(
                    &m->basic.registrar_swap.other,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 6144: /* module 24 call 0 */
        switch(itemIdx) {
            case 0: /* utility_batch - calls */;
                return _toStringVecCall(
                    &m->basic.utility_batch.calls,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 6145: /* module 24 call 1 */
        switch(itemIdx) {
            case 0: /* utility_as_sub - index */;
                return _toStringu16(
                    &m->basic.utility_as_sub.index,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 1: /* utility_as_sub - call */;
                return _toStringCall(
                    &m->basic.utility_as_sub.call,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 6146: /* module 24 call 2 */
        switch(itemIdx) {
            case 0: /* utility_as_limited_sub - index */;
                return _toStringu16(
                    &m->basic.utility_as_limited_sub.index,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 1: /* utility_as_limited_sub - call */;
                return _toStringCall(
                    &m->basic.utility_as_limited_sub.call,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 6400: /* module 25 call 0 */
        switch(itemIdx) {
            case 0: /* identity_add_registrar - account */;
                return _toStringAccountId(
                    &m->basic.identity_add_registrar.account,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 6401: /* module 25 call 1 */
        switch(itemIdx) {
            case 0: /* identity_set_identity - info */;
                return _toStringIdentityInfo(
                    &m->basic.identity_set_identity.info,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 6402: /* module 25 call 2 */
        switch(itemIdx) {
            case 0: /* identity_set_subs - subs */;
                return _toStringVecTupleAccountIdData(
                    &m->basic.identity_set_subs.subs,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 6403: /* module 25 call 3 */
        switch(itemIdx) {
            default:
                return parser_no_data;
        }
        case 6404: /* module 25 call 4 */
        switch(itemIdx) {
            case 0: /* identity_request_judgement - reg_index */;
                return _toStringCompactRegistrarIndex(
                    &m->basic.identity_request_judgement.reg_index,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 1: /* identity_request_judgement - max_fee */;
                return _toStringCompactBalanceOf(
                    &m->basic.identity_request_judgement.max_fee,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 6405: /* module 25 call 5 */
        switch(itemIdx) {
            case 0: /* identity_cancel_request - reg_index */;
                return _toStringRegistrarIndex(
                    &m->basic.identity_cancel_request.reg_index,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 6406: /* module 25 call 6 */
        switch(itemIdx) {
            case 0: /* identity_set_fee - index */;
                return _toStringCompactRegistrarIndex(
                    &m->basic.identity_set_fee.index,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 1: /* identity_set_fee - fee */;
                return _toStringCompactBalanceOf(
                    &m->basic.identity_set_fee.fee,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 6407: /* module 25 call 7 */
        switch(itemIdx) {
            case 0: /* identity_set_account_id - index */;
                return _toStringCompactRegistrarIndex(
                    &m->basic.identity_set_account_id.index,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 1: /* identity_set_account_id - new_ */;
                return _toStringAccountId(
                    &m->basic.identity_set_account_id.new_,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 6408: /* module 25 call 8 */
        switch(itemIdx) {
            case 0: /* identity_set_fields - index */;
                return _toStringCompactRegistrarIndex(
                    &m->basic.identity_set_fields.index,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 1: /* identity_set_fields - fields */;
                return _toStringIdentityFields(
                    &m->basic.identity_set_fields.fields,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 6409: /* module 25 call 9 */
        switch(itemIdx) {
            case 0: /* identity_provide_judgement - reg_index */;
                return _toStringCompactRegistrarIndex(
                    &m->basic.identity_provide_judgement.reg_index,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 1: /* identity_provide_judgement - target */;
                return _toStringLookupSource(
                    &m->basic.identity_provide_judgement.target,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 2: /* identity_provide_judgement - judgement */;
                return _toStringIdentityJudgement(
                    &m->basic.identity_provide_judgement.judgement,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 6410: /* module 25 call 10 */
        switch(itemIdx) {
            case 0: /* identity_kill_identity - target */;
                return _toStringLookupSource(
                    &m->basic.identity_kill_identity.target,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 6656: /* module 26 call 0 */
        switch(itemIdx) {
            case 0: /* society_bid - value */;
                return _toStringBalanceOf(
                    &m->basic.society_bid.value,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 6657: /* module 26 call 1 */
        switch(itemIdx) {
            case 0: /* society_unbid - pos */;
                return _toStringu32(
                    &m->basic.society_unbid.pos,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 6658: /* module 26 call 2 */
        switch(itemIdx) {
            case 0: /* society_vouch - who */;
                return _toStringAccountId(
                    &m->basic.society_vouch.who,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 1: /* society_vouch - value */;
                return _toStringBalanceOf(
                    &m->basic.society_vouch.value,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 2: /* society_vouch - tip */;
                return _toStringBalanceOf(
                    &m->basic.society_vouch.tip,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 6659: /* module 26 call 3 */
        switch(itemIdx) {
            case 0: /* society_unvouch - pos */;
                return _toStringu32(
                    &m->basic.society_unvouch.pos,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 6660: /* module 26 call 4 */
        switch(itemIdx) {
            case 0: /* society_vote - candidate */;
                return _toStringLookupSource(
                    &m->basic.society_vote.candidate,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 1: /* society_vote - approve */;
                return _toStringbool(
                    &m->basic.society_vote.approve,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 6661: /* module 26 call 5 */
        switch(itemIdx) {
            case 0: /* society_defender_vote - approve */;
                return _toStringbool(
                    &m->basic.society_defender_vote.approve,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 6662: /* module 26 call 6 */
        switch(itemIdx) {
            default:
                return parser_no_data;
        }
        case 6663: /* module 26 call 7 */
        switch(itemIdx) {
            case 0: /* society_found - founder */;
                return _toStringAccountId(
                    &m->basic.society_found.founder,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 1: /* society_found - max_members */;
                return _toStringu32(
                    &m->basic.society_found.max_members,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 2: /* society_found - rules */;
                return _toStringBytes(
                    &m->basic.society_found.rules,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 6664: /* module 26 call 8 */
        switch(itemIdx) {
            default:
                return parser_no_data;
        }
        case 6665: /* module 26 call 9 */
        switch(itemIdx) {
            case 0: /* society_judge_suspended_member - who */;
                return _toStringAccountId(
                    &m->basic.society_judge_suspended_member.who,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 1: /* society_judge_suspended_member - forgive */;
                return _toStringbool(
                    &m->basic.society_judge_suspended_member.forgive,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 6666: /* module 26 call 10 */
        switch(itemIdx) {
            case 0: /* society_judge_suspended_candidate - who */;
                return _toStringAccountId(
                    &m->basic.society_judge_suspended_candidate.who,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 1: /* society_judge_suspended_candidate - judgement */;
                return _toStringSocietyJudgement(
                    &m->basic.society_judge_suspended_candidate.judgement,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 6667: /* module 26 call 11 */
        switch(itemIdx) {
            case 0: /* society_set_max_members - max */;
                return _toStringu32(
                    &m->basic.society_set_max_members.max,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 6912: /* module 27 call 0 */
        switch(itemIdx) {
            case 0: /* recovery_as_recovered - account */;
                return _toStringAccountId(
                    &m->basic.recovery_as_recovered.account,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 1: /* recovery_as_recovered - call */;
                return _toStringCall(
                    &m->basic.recovery_as_recovered.call,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 6913: /* module 27 call 1 */
        switch(itemIdx) {
            case 0: /* recovery_set_recovered - lost */;
                return _toStringAccountId(
                    &m->basic.recovery_set_recovered.lost,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 1: /* recovery_set_recovered - rescuer */;
                return _toStringAccountId(
                    &m->basic.recovery_set_recovered.rescuer,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 6914: /* module 27 call 2 */
        switch(itemIdx) {
            case 0: /* recovery_create_recovery - friends */;
                return _toStringVecAccountId(
                    &m->basic.recovery_create_recovery.friends,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 1: /* recovery_create_recovery - threshold */;
                return _toStringu16(
                    &m->basic.recovery_create_recovery.threshold,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 2: /* recovery_create_recovery - delay_period */;
                return _toStringBlockNumber(
                    &m->basic.recovery_create_recovery.delay_period,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 6915: /* module 27 call 3 */
        switch(itemIdx) {
            case 0: /* recovery_initiate_recovery - account */;
                return _toStringAccountId(
                    &m->basic.recovery_initiate_recovery.account,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 6916: /* module 27 call 4 */
        switch(itemIdx) {
            case 0: /* recovery_vouch_recovery - lost */;
                return _toStringAccountId(
                    &m->basic.recovery_vouch_recovery.lost,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 1: /* recovery_vouch_recovery - rescuer */;
                return _toStringAccountId(
                    &m->basic.recovery_vouch_recovery.rescuer,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 6917: /* module 27 call 5 */
        switch(itemIdx) {
            case 0: /* recovery_claim_recovery - account */;
                return _toStringAccountId(
                    &m->basic.recovery_claim_recovery.account,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 6918: /* module 27 call 6 */
        switch(itemIdx) {
            case 0: /* recovery_close_recovery - rescuer */;
                return _toStringAccountId(
                    &m->basic.recovery_close_recovery.rescuer,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 6919: /* module 27 call 7 */
        switch(itemIdx) {
            default:
                return parser_no_data;
        }
        case 6920: /* module 27 call 8 */
        switch(itemIdx) {
            case 0: /* recovery_cancel_recovered - account */;
                return _toStringAccountId(
                    &m->basic.recovery_cancel_recovered.account,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 7168: /* module 28 call 0 */
        switch(itemIdx) {
            default:
                return parser_no_data;
        }
        case 7169: /* module 28 call 1 */
        switch(itemIdx) {
            case 0: /* vesting_vest_other - target */;
                return _toStringLookupSource(
                    &m->basic.vesting_vest_other.target,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 7170: /* module 28 call 2 */
        switch(itemIdx) {
            case 0: /* vesting_vested_transfer - target */;
                return _toStringLookupSource(
                    &m->basic.vesting_vested_transfer.target,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 1: /* vesting_vested_transfer - schedule */;
                return _toStringVestingInfo(
                    &m->basic.vesting_vested_transfer.schedule,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 7424: /* module 29 call 0 */
        switch(itemIdx) {
            case 0: /* scheduler_schedule - when */;
                return _toStringBlockNumber(
                    &m->basic.scheduler_schedule.when,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 1: /* scheduler_schedule - maybe_periodic */;
                return _toStringOptionPeriod(
                    &m->basic.scheduler_schedule.maybe_periodic,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 2: /* scheduler_schedule - priority */;
                return _toStringPriority(
                    &m->basic.scheduler_schedule.priority,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 3: /* scheduler_schedule - call */;
                return _toStringCall(
                    &m->basic.scheduler_schedule.call,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 7425: /* module 29 call 1 */
        switch(itemIdx) {
            case 0: /* scheduler_cancel - when */;
                return _toStringBlockNumber(
                    &m->basic.scheduler_cancel.when,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 1: /* scheduler_cancel - index */;
                return _toStringu32(
                    &m->basic.scheduler_cancel.index,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 7426: /* module 29 call 2 */
        switch(itemIdx) {
            case 0: /* scheduler_schedule_named - id */;
                return _toStringBytes(
                    &m->basic.scheduler_schedule_named.id,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 1: /* scheduler_schedule_named - when */;
                return _toStringBlockNumber(
                    &m->basic.scheduler_schedule_named.when,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 2: /* scheduler_schedule_named - maybe_periodic */;
                return _toStringOptionPeriod(
                    &m->basic.scheduler_schedule_named.maybe_periodic,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 3: /* scheduler_schedule_named - priority */;
                return _toStringPriority(
                    &m->basic.scheduler_schedule_named.priority,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 4: /* scheduler_schedule_named - call */;
                return _toStringCall(
                    &m->basic.scheduler_schedule_named.call,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 7427: /* module 29 call 3 */
        switch(itemIdx) {
            case 0: /* scheduler_cancel_named - id */;
                return _toStringBytes(
                    &m->basic.scheduler_cancel_named.id,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 7680: /* module 30 call 0 */
        switch(itemIdx) {
            case 0: /* proxy_proxy - real */;
                return _toStringAccountId(
                    &m->basic.proxy_proxy.real,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 1: /* proxy_proxy - force_proxy_type */;
                return _toStringOptionProxyType(
                    &m->basic.proxy_proxy.force_proxy_type,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 2: /* proxy_proxy - call */;
                return _toStringCall(
                    &m->basic.proxy_proxy.call,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 7681: /* module 30 call 1 */
        switch(itemIdx) {
            case 0: /* proxy_add_proxy - proxy */;
                return _toStringAccountId(
                    &m->basic.proxy_add_proxy.proxy,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 1: /* proxy_add_proxy - proxy_type */;
                return _toStringProxyType(
                    &m->basic.proxy_add_proxy.proxy_type,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 7682: /* module 30 call 2 */
        switch(itemIdx) {
            case 0: /* proxy_remove_proxy - proxy */;
                return _toStringAccountId(
                    &m->basic.proxy_remove_proxy.proxy,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 1: /* proxy_remove_proxy - proxy_type */;
                return _toStringProxyType(
                    &m->basic.proxy_remove_proxy.proxy_type,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 7683: /* module 30 call 3 */
        switch(itemIdx) {
            default:
                return parser_no_data;
        }
        case 7684: /* module 30 call 4 */
        switch(itemIdx) {
            case 0: /* proxy_anonymous - proxy_type */;
                return _toStringProxyType(
                    &m->basic.proxy_anonymous.proxy_type,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 1: /* proxy_anonymous - index */;
                return _toStringu16(
                    &m->basic.proxy_anonymous.index,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 7685: /* module 30 call 5 */
        switch(itemIdx) {
            case 0: /* proxy_kill_anonymous - spawner */;
                return _toStringAccountId(
                    &m->basic.proxy_kill_anonymous.spawner,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 1: /* proxy_kill_anonymous - proxy_type */;
                return _toStringProxyType(
                    &m->basic.proxy_kill_anonymous.proxy_type,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 2: /* proxy_kill_anonymous - index */;
                return _toStringu16(
                    &m->basic.proxy_kill_anonymous.index,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 3: /* proxy_kill_anonymous - height */;
                return _toStringCompactBlockNumber(
                    &m->basic.proxy_kill_anonymous.height,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 4: /* proxy_kill_anonymous - ext_index */;
                return _toStringCompactu32(
                    &m->basic.proxy_kill_anonymous.ext_index,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 7936: /* module 31 call 0 */
        switch(itemIdx) {
            case 0: /* multisig_as_multi - threshold */;
                return _toStringu16(
                    &m->basic.multisig_as_multi.threshold,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 1: /* multisig_as_multi - other_signatories */;
                return _toStringVecAccountId(
                    &m->basic.multisig_as_multi.other_signatories,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 2: /* multisig_as_multi - maybe_timepoint */;
                return _toStringOptionTimepoint(
                    &m->basic.multisig_as_multi.maybe_timepoint,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 3: /* multisig_as_multi - call */;
                return _toStringCall(
                    &m->basic.multisig_as_multi.call,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 7937: /* module 31 call 1 */
        switch(itemIdx) {
            case 0: /* multisig_approve_as_multi - threshold */;
                return _toStringu16(
                    &m->basic.multisig_approve_as_multi.threshold,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 1: /* multisig_approve_as_multi - other_signatories */;
                return _toStringVecAccountId(
                    &m->basic.multisig_approve_as_multi.other_signatories,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 2: /* multisig_approve_as_multi - maybe_timepoint */;
                return _toStringOptionTimepoint(
                    &m->basic.multisig_approve_as_multi.maybe_timepoint,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 3: /* multisig_approve_as_multi - call_hash */;
                return _toStringu8_array_32(
                    &m->basic.multisig_approve_as_multi.call_hash,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 7938: /* module 31 call 2 */
        switch(itemIdx) {
            case 0: /* multisig_cancel_as_multi - threshold */;
                return _toStringu16(
                    &m->basic.multisig_cancel_as_multi.threshold,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 1: /* multisig_cancel_as_multi - other_signatories */;
                return _toStringVecAccountId(
                    &m->basic.multisig_cancel_as_multi.other_signatories,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 2: /* multisig_cancel_as_multi - timepoint */;
                return _toStringTimepoint(
                    &m->basic.multisig_cancel_as_multi.timepoint,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 3: /* multisig_cancel_as_multi - call_hash */;
                return _toStringu8_array_32(
                    &m->basic.multisig_cancel_as_multi.call_hash,
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
