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

__Z_INLINE parser_error_t _readMethod_staking_payout_nominator(
    parser_context_t *c, pd_staking_payout_nominator_t *m) {
    CHECK_ERROR(_readEraIndex(c, &m->era))
    CHECK_ERROR(_readVecTupleAccountIdu32(c, &m->validators))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_payout_validator(
    parser_context_t *c, pd_staking_payout_validator_t *m) {
    CHECK_ERROR(_readEraIndex(c, &m->era))
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
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_reap_stash(
    parser_context_t *c, pd_staking_reap_stash_t *m) {
    CHECK_ERROR(_readAccountId(c, &m->stash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_submit_election_solution(
    parser_context_t *c, pd_staking_submit_election_solution_t *m) {
    CHECK_ERROR(_readVecValidatorIndex(c, &m->winners))
    CHECK_ERROR(_readCompactAssignments(c, &m->compact_assignments))
    CHECK_ERROR(_readPhragmenScore(c, &m->score))
    CHECK_ERROR(_readEraIndex(c, &m->era))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_submit_election_solution_unsigned(
    parser_context_t *c, pd_staking_submit_election_solution_unsigned_t *m) {
    CHECK_ERROR(_readVecValidatorIndex(c, &m->winners))
    CHECK_ERROR(_readCompactAssignments(c, &m->compact_assignments))
    CHECK_ERROR(_readPhragmenScore(c, &m->score))
    CHECK_ERROR(_readEraIndex(c, &m->era))
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

__Z_INLINE parser_error_t _readMethod_grandpa_report_misbehavior(
    parser_context_t *c, pd_grandpa_report_misbehavior_t *m) {
    CHECK_ERROR(_readBytes(c, &m->_report))
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
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_vote(
    parser_context_t *c, pd_democracy_vote_t *m) {
    CHECK_ERROR(_readCompactReferendumIndex(c, &m->ref_index))
    CHECK_ERROR(_readAccountVote(c, &m->vote))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_proxy_vote(
    parser_context_t *c, pd_democracy_proxy_vote_t *m) {
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

__Z_INLINE parser_error_t _readMethod_democracy_activate_proxy(
    parser_context_t *c, pd_democracy_activate_proxy_t *m) {
    CHECK_ERROR(_readAccountId(c, &m->proxy))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_close_proxy(
    parser_context_t *c, pd_democracy_close_proxy_t *m) {
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_deactivate_proxy(
    parser_context_t *c, pd_democracy_deactivate_proxy_t *m) {
    CHECK_ERROR(_readAccountId(c, &m->proxy))
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

__Z_INLINE parser_error_t _readMethod_democracy_note_imminent_preimage(
    parser_context_t *c, pd_democracy_note_imminent_preimage_t *m) {
    CHECK_ERROR(_readBytes(c, &m->encoded_proposal))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_reap_preimage(
    parser_context_t *c, pd_democracy_reap_preimage_t *m) {
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_unlock(
    parser_context_t *c, pd_democracy_unlock_t *m) {
    CHECK_ERROR(_readAccountId(c, &m->target))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_open_proxy(
    parser_context_t *c, pd_democracy_open_proxy_t *m) {
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

__Z_INLINE parser_error_t _readMethod_democracy_proxy_delegate(
    parser_context_t *c, pd_democracy_proxy_delegate_t *m) {
    CHECK_ERROR(_readAccountId(c, &m->to))
    CHECK_ERROR(_readConviction(c, &m->conviction))
    CHECK_ERROR(_readBalanceOf(c, &m->balance))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_proxy_undelegate(
    parser_context_t *c, pd_democracy_proxy_undelegate_t *m) {
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_proxy_remove_vote(
    parser_context_t *c, pd_democracy_proxy_remove_vote_t *m) {
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
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_council_execute(
    parser_context_t *c, pd_council_execute_t *m) {
    CHECK_ERROR(_readProposal(c, &m->proposal))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_council_propose(
    parser_context_t *c, pd_council_propose_t *m) {
    CHECK_ERROR(_readCompactMemberCount(c, &m->threshold))
    CHECK_ERROR(_readProposal(c, &m->proposal))
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
    CHECK_ERROR(_readHash(c, &m->proposal))
    CHECK_ERROR(_readCompactProposalIndex(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_set_members(
    parser_context_t *c, pd_technicalcommittee_set_members_t *m) {
    CHECK_ERROR(_readVecAccountId(c, &m->new_members))
    CHECK_ERROR(_readOptionAccountId(c, &m->prime))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_execute(
    parser_context_t *c, pd_technicalcommittee_execute_t *m) {
    CHECK_ERROR(_readProposal(c, &m->proposal))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_propose(
    parser_context_t *c, pd_technicalcommittee_propose_t *m) {
    CHECK_ERROR(_readCompactMemberCount(c, &m->threshold))
    CHECK_ERROR(_readProposal(c, &m->proposal))
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
    CHECK_ERROR(_readHash(c, &m->proposal))
    CHECK_ERROR(_readCompactProposalIndex(c, &m->index))
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
    CHECK_ERROR(_readLookupSource(c, &m->target))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_electionsphragmen_submit_candidacy(
    parser_context_t *c, pd_electionsphragmen_submit_candidacy_t *m) {
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_electionsphragmen_renounce_candidacy(
    parser_context_t *c, pd_electionsphragmen_renounce_candidacy_t *m) {
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_electionsphragmen_remove_member(
    parser_context_t *c, pd_electionsphragmen_remove_member_t *m) {
    CHECK_ERROR(_readLookupSource(c, &m->who))
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

__Z_INLINE parser_error_t _readMethod_utility_as_multi(
    parser_context_t *c, pd_utility_as_multi_t *m) {
    CHECK_ERROR(_readu16(c, &m->threshold))
    CHECK_ERROR(_readVecAccountId(c, &m->other_signatories))
    CHECK_ERROR(_readOptionTimepoint(c, &m->maybe_timepoint))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_approve_as_multi(
    parser_context_t *c, pd_utility_approve_as_multi_t *m) {
    CHECK_ERROR(_readu16(c, &m->threshold))
    CHECK_ERROR(_readVecAccountId(c, &m->other_signatories))
    CHECK_ERROR(_readOptionTimepoint(c, &m->maybe_timepoint))
    CHECK_ERROR(_readu8_array_32(c, &m->call_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_cancel_as_multi(
    parser_context_t *c, pd_utility_cancel_as_multi_t *m) {
    CHECK_ERROR(_readu16(c, &m->threshold))
    CHECK_ERROR(_readVecAccountId(c, &m->other_signatories))
    CHECK_ERROR(_readTimepoint(c, &m->timepoint))
    CHECK_ERROR(_readu8_array_32(c, &m->call_hash))
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


parser_error_t _readMethodBasic(
    parser_context_t *c,
    uint8_t moduleIdx,
    uint8_t callIdx,
    pd_MethodBasic_t *method) {
    uint16_t callPrivIdx = (moduleIdx << 8u) + callIdx;

    switch(callPrivIdx) {
        case ((0u << 8u) + 0):
            CHECK_ERROR(_readMethod_system_fill_block(c, &method->system_fill_block))
            break;
        case ((0u << 8u) + 1):
            CHECK_ERROR(_readMethod_system_remark(c, &method->system_remark))
            break;
        case ((0u << 8u) + 2):
            CHECK_ERROR(_readMethod_system_set_heap_pages(c, &method->system_set_heap_pages))
            break;
        case ((0u << 8u) + 3):
            CHECK_ERROR(_readMethod_system_set_code(c, &method->system_set_code))
            break;
        case ((0u << 8u) + 4):
            CHECK_ERROR(_readMethod_system_set_code_without_checks(c, &method->system_set_code_without_checks))
            break;
        case ((0u << 8u) + 5):
            CHECK_ERROR(_readMethod_system_set_changes_trie_config(c, &method->system_set_changes_trie_config))
            break;
        case ((0u << 8u) + 6):
            CHECK_ERROR(_readMethod_system_set_storage(c, &method->system_set_storage))
            break;
        case ((0u << 8u) + 7):
            CHECK_ERROR(_readMethod_system_kill_storage(c, &method->system_kill_storage))
            break;
        case ((0u << 8u) + 8):
            CHECK_ERROR(_readMethod_system_kill_prefix(c, &method->system_kill_prefix))
            break;
        case ((0u << 8u) + 9):
            CHECK_ERROR(_readMethod_system_suicide(c, &method->system_suicide))
            break;
        case ((2u << 8u) + 0):
            CHECK_ERROR(_readMethod_timestamp_set(c, &method->timestamp_set))
            break;
        case ((3u << 8u) + 0):
            CHECK_ERROR(_readMethod_indices_claim(c, &method->indices_claim))
            break;
        case ((3u << 8u) + 1):
            CHECK_ERROR(_readMethod_indices_transfer(c, &method->indices_transfer))
            break;
        case ((3u << 8u) + 2):
            CHECK_ERROR(_readMethod_indices_free(c, &method->indices_free))
            break;
        case ((3u << 8u) + 3):
            CHECK_ERROR(_readMethod_indices_force_transfer(c, &method->indices_force_transfer))
            break;
        case ((4u << 8u) + 0):
            CHECK_ERROR(_readMethod_balances_transfer(c, &method->balances_transfer))
            break;
        case ((4u << 8u) + 1):
            CHECK_ERROR(_readMethod_balances_set_balance(c, &method->balances_set_balance))
            break;
        case ((4u << 8u) + 2):
            CHECK_ERROR(_readMethod_balances_force_transfer(c, &method->balances_force_transfer))
            break;
        case ((4u << 8u) + 3):
            CHECK_ERROR(_readMethod_balances_transfer_keep_alive(c, &method->balances_transfer_keep_alive))
            break;
        case ((5u << 8u) + 0):
            CHECK_ERROR(_readMethod_authorship_set_uncles(c, &method->authorship_set_uncles))
            break;
        case ((6u << 8u) + 0):
            CHECK_ERROR(_readMethod_staking_bond(c, &method->staking_bond))
            break;
        case ((6u << 8u) + 1):
            CHECK_ERROR(_readMethod_staking_bond_extra(c, &method->staking_bond_extra))
            break;
        case ((6u << 8u) + 2):
            CHECK_ERROR(_readMethod_staking_unbond(c, &method->staking_unbond))
            break;
        case ((6u << 8u) + 3):
            CHECK_ERROR(_readMethod_staking_withdraw_unbonded(c, &method->staking_withdraw_unbonded))
            break;
        case ((6u << 8u) + 4):
            CHECK_ERROR(_readMethod_staking_validate(c, &method->staking_validate))
            break;
        case ((6u << 8u) + 5):
            CHECK_ERROR(_readMethod_staking_nominate(c, &method->staking_nominate))
            break;
        case ((6u << 8u) + 6):
            CHECK_ERROR(_readMethod_staking_chill(c, &method->staking_chill))
            break;
        case ((6u << 8u) + 7):
            CHECK_ERROR(_readMethod_staking_set_payee(c, &method->staking_set_payee))
            break;
        case ((6u << 8u) + 8):
            CHECK_ERROR(_readMethod_staking_set_controller(c, &method->staking_set_controller))
            break;
        case ((6u << 8u) + 9):
            CHECK_ERROR(_readMethod_staking_set_validator_count(c, &method->staking_set_validator_count))
            break;
        case ((6u << 8u) + 10):
            CHECK_ERROR(_readMethod_staking_force_no_eras(c, &method->staking_force_no_eras))
            break;
        case ((6u << 8u) + 11):
            CHECK_ERROR(_readMethod_staking_force_new_era(c, &method->staking_force_new_era))
            break;
        case ((6u << 8u) + 12):
            CHECK_ERROR(_readMethod_staking_set_invulnerables(c, &method->staking_set_invulnerables))
            break;
        case ((6u << 8u) + 13):
            CHECK_ERROR(_readMethod_staking_force_unstake(c, &method->staking_force_unstake))
            break;
        case ((6u << 8u) + 14):
            CHECK_ERROR(_readMethod_staking_force_new_era_always(c, &method->staking_force_new_era_always))
            break;
        case ((6u << 8u) + 15):
            CHECK_ERROR(_readMethod_staking_cancel_deferred_slash(c, &method->staking_cancel_deferred_slash))
            break;
        case ((6u << 8u) + 16):
            CHECK_ERROR(_readMethod_staking_payout_nominator(c, &method->staking_payout_nominator))
            break;
        case ((6u << 8u) + 17):
            CHECK_ERROR(_readMethod_staking_payout_validator(c, &method->staking_payout_validator))
            break;
        case ((6u << 8u) + 18):
            CHECK_ERROR(_readMethod_staking_payout_stakers(c, &method->staking_payout_stakers))
            break;
        case ((6u << 8u) + 19):
            CHECK_ERROR(_readMethod_staking_rebond(c, &method->staking_rebond))
            break;
        case ((6u << 8u) + 20):
            CHECK_ERROR(_readMethod_staking_set_history_depth(c, &method->staking_set_history_depth))
            break;
        case ((6u << 8u) + 21):
            CHECK_ERROR(_readMethod_staking_reap_stash(c, &method->staking_reap_stash))
            break;
        case ((6u << 8u) + 22):
            CHECK_ERROR(_readMethod_staking_submit_election_solution(c, &method->staking_submit_election_solution))
            break;
        case ((6u << 8u) + 23):
            CHECK_ERROR(_readMethod_staking_submit_election_solution_unsigned(c, &method->staking_submit_election_solution_unsigned))
            break;
        case ((8u << 8u) + 0):
            CHECK_ERROR(_readMethod_session_set_keys(c, &method->session_set_keys))
            break;
        case ((8u << 8u) + 1):
            CHECK_ERROR(_readMethod_session_purge_keys(c, &method->session_purge_keys))
            break;
        case ((9u << 8u) + 0):
            CHECK_ERROR(_readMethod_finalitytracker_final_hint(c, &method->finalitytracker_final_hint))
            break;
        case ((10u << 8u) + 0):
            CHECK_ERROR(_readMethod_grandpa_report_misbehavior(c, &method->grandpa_report_misbehavior))
            break;
        case ((11u << 8u) + 0):
            CHECK_ERROR(_readMethod_imonline_heartbeat(c, &method->imonline_heartbeat))
            break;
        case ((13u << 8u) + 0):
            CHECK_ERROR(_readMethod_democracy_propose(c, &method->democracy_propose))
            break;
        case ((13u << 8u) + 1):
            CHECK_ERROR(_readMethod_democracy_second(c, &method->democracy_second))
            break;
        case ((13u << 8u) + 2):
            CHECK_ERROR(_readMethod_democracy_vote(c, &method->democracy_vote))
            break;
        case ((13u << 8u) + 3):
            CHECK_ERROR(_readMethod_democracy_proxy_vote(c, &method->democracy_proxy_vote))
            break;
        case ((13u << 8u) + 4):
            CHECK_ERROR(_readMethod_democracy_emergency_cancel(c, &method->democracy_emergency_cancel))
            break;
        case ((13u << 8u) + 5):
            CHECK_ERROR(_readMethod_democracy_external_propose(c, &method->democracy_external_propose))
            break;
        case ((13u << 8u) + 6):
            CHECK_ERROR(_readMethod_democracy_external_propose_majority(c, &method->democracy_external_propose_majority))
            break;
        case ((13u << 8u) + 7):
            CHECK_ERROR(_readMethod_democracy_external_propose_default(c, &method->democracy_external_propose_default))
            break;
        case ((13u << 8u) + 8):
            CHECK_ERROR(_readMethod_democracy_fast_track(c, &method->democracy_fast_track))
            break;
        case ((13u << 8u) + 9):
            CHECK_ERROR(_readMethod_democracy_veto_external(c, &method->democracy_veto_external))
            break;
        case ((13u << 8u) + 10):
            CHECK_ERROR(_readMethod_democracy_cancel_referendum(c, &method->democracy_cancel_referendum))
            break;
        case ((13u << 8u) + 11):
            CHECK_ERROR(_readMethod_democracy_cancel_queued(c, &method->democracy_cancel_queued))
            break;
        case ((13u << 8u) + 12):
            CHECK_ERROR(_readMethod_democracy_activate_proxy(c, &method->democracy_activate_proxy))
            break;
        case ((13u << 8u) + 13):
            CHECK_ERROR(_readMethod_democracy_close_proxy(c, &method->democracy_close_proxy))
            break;
        case ((13u << 8u) + 14):
            CHECK_ERROR(_readMethod_democracy_deactivate_proxy(c, &method->democracy_deactivate_proxy))
            break;
        case ((13u << 8u) + 15):
            CHECK_ERROR(_readMethod_democracy_delegate(c, &method->democracy_delegate))
            break;
        case ((13u << 8u) + 16):
            CHECK_ERROR(_readMethod_democracy_undelegate(c, &method->democracy_undelegate))
            break;
        case ((13u << 8u) + 17):
            CHECK_ERROR(_readMethod_democracy_clear_public_proposals(c, &method->democracy_clear_public_proposals))
            break;
        case ((13u << 8u) + 18):
            CHECK_ERROR(_readMethod_democracy_note_preimage(c, &method->democracy_note_preimage))
            break;
        case ((13u << 8u) + 19):
            CHECK_ERROR(_readMethod_democracy_note_imminent_preimage(c, &method->democracy_note_imminent_preimage))
            break;
        case ((13u << 8u) + 20):
            CHECK_ERROR(_readMethod_democracy_reap_preimage(c, &method->democracy_reap_preimage))
            break;
        case ((13u << 8u) + 21):
            CHECK_ERROR(_readMethod_democracy_unlock(c, &method->democracy_unlock))
            break;
        case ((13u << 8u) + 22):
            CHECK_ERROR(_readMethod_democracy_open_proxy(c, &method->democracy_open_proxy))
            break;
        case ((13u << 8u) + 23):
            CHECK_ERROR(_readMethod_democracy_remove_vote(c, &method->democracy_remove_vote))
            break;
        case ((13u << 8u) + 24):
            CHECK_ERROR(_readMethod_democracy_remove_other_vote(c, &method->democracy_remove_other_vote))
            break;
        case ((13u << 8u) + 25):
            CHECK_ERROR(_readMethod_democracy_proxy_delegate(c, &method->democracy_proxy_delegate))
            break;
        case ((13u << 8u) + 26):
            CHECK_ERROR(_readMethod_democracy_proxy_undelegate(c, &method->democracy_proxy_undelegate))
            break;
        case ((13u << 8u) + 27):
            CHECK_ERROR(_readMethod_democracy_proxy_remove_vote(c, &method->democracy_proxy_remove_vote))
            break;
        case ((13u << 8u) + 28):
            CHECK_ERROR(_readMethod_democracy_enact_proposal(c, &method->democracy_enact_proposal))
            break;
        case ((14u << 8u) + 0):
            CHECK_ERROR(_readMethod_council_set_members(c, &method->council_set_members))
            break;
        case ((14u << 8u) + 3):
            CHECK_ERROR(_readMethod_council_vote(c, &method->council_vote))
            break;
        case ((14u << 8u) + 4):
            CHECK_ERROR(_readMethod_council_close(c, &method->council_close))
            break;
        case ((15u << 8u) + 0):
            CHECK_ERROR(_readMethod_technicalcommittee_set_members(c, &method->technicalcommittee_set_members))
            break;
        case ((15u << 8u) + 3):
            CHECK_ERROR(_readMethod_technicalcommittee_vote(c, &method->technicalcommittee_vote))
            break;
        case ((15u << 8u) + 4):
            CHECK_ERROR(_readMethod_technicalcommittee_close(c, &method->technicalcommittee_close))
            break;
        case ((16u << 8u) + 0):
            CHECK_ERROR(_readMethod_electionsphragmen_vote(c, &method->electionsphragmen_vote))
            break;
        case ((16u << 8u) + 1):
            CHECK_ERROR(_readMethod_electionsphragmen_remove_voter(c, &method->electionsphragmen_remove_voter))
            break;
        case ((16u << 8u) + 2):
            CHECK_ERROR(_readMethod_electionsphragmen_report_defunct_voter(c, &method->electionsphragmen_report_defunct_voter))
            break;
        case ((16u << 8u) + 3):
            CHECK_ERROR(_readMethod_electionsphragmen_submit_candidacy(c, &method->electionsphragmen_submit_candidacy))
            break;
        case ((16u << 8u) + 4):
            CHECK_ERROR(_readMethod_electionsphragmen_renounce_candidacy(c, &method->electionsphragmen_renounce_candidacy))
            break;
        case ((16u << 8u) + 5):
            CHECK_ERROR(_readMethod_electionsphragmen_remove_member(c, &method->electionsphragmen_remove_member))
            break;
        case ((17u << 8u) + 0):
            CHECK_ERROR(_readMethod_technicalmembership_add_member(c, &method->technicalmembership_add_member))
            break;
        case ((17u << 8u) + 1):
            CHECK_ERROR(_readMethod_technicalmembership_remove_member(c, &method->technicalmembership_remove_member))
            break;
        case ((17u << 8u) + 2):
            CHECK_ERROR(_readMethod_technicalmembership_swap_member(c, &method->technicalmembership_swap_member))
            break;
        case ((17u << 8u) + 3):
            CHECK_ERROR(_readMethod_technicalmembership_reset_members(c, &method->technicalmembership_reset_members))
            break;
        case ((17u << 8u) + 4):
            CHECK_ERROR(_readMethod_technicalmembership_change_key(c, &method->technicalmembership_change_key))
            break;
        case ((17u << 8u) + 5):
            CHECK_ERROR(_readMethod_technicalmembership_set_prime(c, &method->technicalmembership_set_prime))
            break;
        case ((17u << 8u) + 6):
            CHECK_ERROR(_readMethod_technicalmembership_clear_prime(c, &method->technicalmembership_clear_prime))
            break;
        case ((18u << 8u) + 0):
            CHECK_ERROR(_readMethod_treasury_propose_spend(c, &method->treasury_propose_spend))
            break;
        case ((18u << 8u) + 1):
            CHECK_ERROR(_readMethod_treasury_reject_proposal(c, &method->treasury_reject_proposal))
            break;
        case ((18u << 8u) + 2):
            CHECK_ERROR(_readMethod_treasury_approve_proposal(c, &method->treasury_approve_proposal))
            break;
        case ((18u << 8u) + 3):
            CHECK_ERROR(_readMethod_treasury_report_awesome(c, &method->treasury_report_awesome))
            break;
        case ((18u << 8u) + 4):
            CHECK_ERROR(_readMethod_treasury_retract_tip(c, &method->treasury_retract_tip))
            break;
        case ((18u << 8u) + 5):
            CHECK_ERROR(_readMethod_treasury_tip_new(c, &method->treasury_tip_new))
            break;
        case ((18u << 8u) + 6):
            CHECK_ERROR(_readMethod_treasury_tip(c, &method->treasury_tip))
            break;
        case ((18u << 8u) + 7):
            CHECK_ERROR(_readMethod_treasury_close_tip(c, &method->treasury_close_tip))
            break;
        case ((19u << 8u) + 0):
            CHECK_ERROR(_readMethod_claims_claim(c, &method->claims_claim))
            break;
        case ((19u << 8u) + 1):
            CHECK_ERROR(_readMethod_claims_mint_claim(c, &method->claims_mint_claim))
            break;
        case ((20u << 8u) + 0):
            CHECK_ERROR(_readMethod_parachains_set_heads(c, &method->parachains_set_heads))
            break;
        case ((20u << 8u) + 1):
            CHECK_ERROR(_readMethod_parachains_report_double_vote(c, &method->parachains_report_double_vote))
            break;
        case ((21u << 8u) + 0):
            CHECK_ERROR(_readMethod_attestations_more_attestations(c, &method->attestations_more_attestations))
            break;
        case ((22u << 8u) + 0):
            CHECK_ERROR(_readMethod_slots_new_auction(c, &method->slots_new_auction))
            break;
        case ((22u << 8u) + 1):
            CHECK_ERROR(_readMethod_slots_bid(c, &method->slots_bid))
            break;
        case ((22u << 8u) + 2):
            CHECK_ERROR(_readMethod_slots_bid_renew(c, &method->slots_bid_renew))
            break;
        case ((22u << 8u) + 3):
            CHECK_ERROR(_readMethod_slots_set_offboarding(c, &method->slots_set_offboarding))
            break;
        case ((22u << 8u) + 4):
            CHECK_ERROR(_readMethod_slots_fix_deploy_data(c, &method->slots_fix_deploy_data))
            break;
        case ((22u << 8u) + 5):
            CHECK_ERROR(_readMethod_slots_elaborate_deploy_data(c, &method->slots_elaborate_deploy_data))
            break;
        case ((23u << 8u) + 0):
            CHECK_ERROR(_readMethod_registrar_register_para(c, &method->registrar_register_para))
            break;
        case ((23u << 8u) + 1):
            CHECK_ERROR(_readMethod_registrar_deregister_para(c, &method->registrar_deregister_para))
            break;
        case ((23u << 8u) + 2):
            CHECK_ERROR(_readMethod_registrar_set_thread_count(c, &method->registrar_set_thread_count))
            break;
        case ((23u << 8u) + 3):
            CHECK_ERROR(_readMethod_registrar_register_parathread(c, &method->registrar_register_parathread))
            break;
        case ((23u << 8u) + 4):
            CHECK_ERROR(_readMethod_registrar_select_parathread(c, &method->registrar_select_parathread))
            break;
        case ((23u << 8u) + 5):
            CHECK_ERROR(_readMethod_registrar_deregister_parathread(c, &method->registrar_deregister_parathread))
            break;
        case ((23u << 8u) + 6):
            CHECK_ERROR(_readMethod_registrar_swap(c, &method->registrar_swap))
            break;
        case ((24u << 8u) + 0):
            CHECK_ERROR(_readMethod_utility_batch(c, &method->utility_batch))
            break;
        case ((24u << 8u) + 1):
            CHECK_ERROR(_readMethod_utility_as_sub(c, &method->utility_as_sub))
            break;
        case ((24u << 8u) + 2):
            CHECK_ERROR(_readMethod_utility_as_multi(c, &method->utility_as_multi))
            break;
        case ((24u << 8u) + 3):
            CHECK_ERROR(_readMethod_utility_approve_as_multi(c, &method->utility_approve_as_multi))
            break;
        case ((24u << 8u) + 4):
            CHECK_ERROR(_readMethod_utility_cancel_as_multi(c, &method->utility_cancel_as_multi))
            break;
        case ((25u << 8u) + 0):
            CHECK_ERROR(_readMethod_identity_add_registrar(c, &method->identity_add_registrar))
            break;
        case ((25u << 8u) + 1):
            CHECK_ERROR(_readMethod_identity_set_identity(c, &method->identity_set_identity))
            break;
        case ((25u << 8u) + 2):
            CHECK_ERROR(_readMethod_identity_set_subs(c, &method->identity_set_subs))
            break;
        case ((25u << 8u) + 3):
            CHECK_ERROR(_readMethod_identity_clear_identity(c, &method->identity_clear_identity))
            break;
        case ((25u << 8u) + 4):
            CHECK_ERROR(_readMethod_identity_request_judgement(c, &method->identity_request_judgement))
            break;
        case ((25u << 8u) + 5):
            CHECK_ERROR(_readMethod_identity_cancel_request(c, &method->identity_cancel_request))
            break;
        case ((25u << 8u) + 6):
            CHECK_ERROR(_readMethod_identity_set_fee(c, &method->identity_set_fee))
            break;
        case ((25u << 8u) + 7):
            CHECK_ERROR(_readMethod_identity_set_account_id(c, &method->identity_set_account_id))
            break;
        case ((25u << 8u) + 8):
            CHECK_ERROR(_readMethod_identity_set_fields(c, &method->identity_set_fields))
            break;
        case ((25u << 8u) + 9):
            CHECK_ERROR(_readMethod_identity_provide_judgement(c, &method->identity_provide_judgement))
            break;
        case ((25u << 8u) + 10):
            CHECK_ERROR(_readMethod_identity_kill_identity(c, &method->identity_kill_identity))
            break;
        case ((26u << 8u) + 0):
            CHECK_ERROR(_readMethod_society_bid(c, &method->society_bid))
            break;
        case ((26u << 8u) + 1):
            CHECK_ERROR(_readMethod_society_unbid(c, &method->society_unbid))
            break;
        case ((26u << 8u) + 2):
            CHECK_ERROR(_readMethod_society_vouch(c, &method->society_vouch))
            break;
        case ((26u << 8u) + 3):
            CHECK_ERROR(_readMethod_society_unvouch(c, &method->society_unvouch))
            break;
        case ((26u << 8u) + 4):
            CHECK_ERROR(_readMethod_society_vote(c, &method->society_vote))
            break;
        case ((26u << 8u) + 5):
            CHECK_ERROR(_readMethod_society_defender_vote(c, &method->society_defender_vote))
            break;
        case ((26u << 8u) + 6):
            CHECK_ERROR(_readMethod_society_payout(c, &method->society_payout))
            break;
        case ((26u << 8u) + 7):
            CHECK_ERROR(_readMethod_society_found(c, &method->society_found))
            break;
        case ((26u << 8u) + 8):
            CHECK_ERROR(_readMethod_society_unfound(c, &method->society_unfound))
            break;
        case ((26u << 8u) + 9):
            CHECK_ERROR(_readMethod_society_judge_suspended_member(c, &method->society_judge_suspended_member))
            break;
        case ((26u << 8u) + 10):
            CHECK_ERROR(_readMethod_society_judge_suspended_candidate(c, &method->society_judge_suspended_candidate))
            break;
        case ((26u << 8u) + 11):
            CHECK_ERROR(_readMethod_society_set_max_members(c, &method->society_set_max_members))
            break;
        case ((27u << 8u) + 0):
            CHECK_ERROR(_readMethod_recovery_as_recovered(c, &method->recovery_as_recovered))
            break;
        case ((27u << 8u) + 1):
            CHECK_ERROR(_readMethod_recovery_set_recovered(c, &method->recovery_set_recovered))
            break;
        case ((27u << 8u) + 2):
            CHECK_ERROR(_readMethod_recovery_create_recovery(c, &method->recovery_create_recovery))
            break;
        case ((27u << 8u) + 3):
            CHECK_ERROR(_readMethod_recovery_initiate_recovery(c, &method->recovery_initiate_recovery))
            break;
        case ((27u << 8u) + 4):
            CHECK_ERROR(_readMethod_recovery_vouch_recovery(c, &method->recovery_vouch_recovery))
            break;
        case ((27u << 8u) + 5):
            CHECK_ERROR(_readMethod_recovery_claim_recovery(c, &method->recovery_claim_recovery))
            break;
        case ((27u << 8u) + 6):
            CHECK_ERROR(_readMethod_recovery_close_recovery(c, &method->recovery_close_recovery))
            break;
        case ((27u << 8u) + 7):
            CHECK_ERROR(_readMethod_recovery_remove_recovery(c, &method->recovery_remove_recovery))
            break;
        case ((27u << 8u) + 8):
            CHECK_ERROR(_readMethod_recovery_cancel_recovered(c, &method->recovery_cancel_recovered))
            break;
        case ((28u << 8u) + 0):
            CHECK_ERROR(_readMethod_vesting_vest(c, &method->vesting_vest))
            break;
        case ((28u << 8u) + 1):
            CHECK_ERROR(_readMethod_vesting_vest_other(c, &method->vesting_vest_other))
            break;
        case ((28u << 8u) + 2):
            CHECK_ERROR(_readMethod_vesting_vested_transfer(c, &method->vesting_vested_transfer))
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
    uint16_t callPrivIdx = (moduleIdx << 8u) + callIdx;

    switch(callPrivIdx) {
        case ((0u << 8u) + 0):
            CHECK_ERROR(_readMethod_system_fill_block(c, &method->basic.system_fill_block))
            break;
        case ((0u << 8u) + 1):
            CHECK_ERROR(_readMethod_system_remark(c, &method->basic.system_remark))
            break;
        case ((0u << 8u) + 2):
            CHECK_ERROR(_readMethod_system_set_heap_pages(c, &method->basic.system_set_heap_pages))
            break;
        case ((0u << 8u) + 3):
            CHECK_ERROR(_readMethod_system_set_code(c, &method->basic.system_set_code))
            break;
        case ((0u << 8u) + 4):
            CHECK_ERROR(_readMethod_system_set_code_without_checks(c, &method->basic.system_set_code_without_checks))
            break;
        case ((0u << 8u) + 5):
            CHECK_ERROR(_readMethod_system_set_changes_trie_config(c, &method->basic.system_set_changes_trie_config))
            break;
        case ((0u << 8u) + 6):
            CHECK_ERROR(_readMethod_system_set_storage(c, &method->basic.system_set_storage))
            break;
        case ((0u << 8u) + 7):
            CHECK_ERROR(_readMethod_system_kill_storage(c, &method->basic.system_kill_storage))
            break;
        case ((0u << 8u) + 8):
            CHECK_ERROR(_readMethod_system_kill_prefix(c, &method->basic.system_kill_prefix))
            break;
        case ((0u << 8u) + 9):
            CHECK_ERROR(_readMethod_system_suicide(c, &method->basic.system_suicide))
            break;
        case ((2u << 8u) + 0):
            CHECK_ERROR(_readMethod_timestamp_set(c, &method->basic.timestamp_set))
            break;
        case ((3u << 8u) + 0):
            CHECK_ERROR(_readMethod_indices_claim(c, &method->basic.indices_claim))
            break;
        case ((3u << 8u) + 1):
            CHECK_ERROR(_readMethod_indices_transfer(c, &method->basic.indices_transfer))
            break;
        case ((3u << 8u) + 2):
            CHECK_ERROR(_readMethod_indices_free(c, &method->basic.indices_free))
            break;
        case ((3u << 8u) + 3):
            CHECK_ERROR(_readMethod_indices_force_transfer(c, &method->basic.indices_force_transfer))
            break;
        case ((4u << 8u) + 0):
            CHECK_ERROR(_readMethod_balances_transfer(c, &method->basic.balances_transfer))
            break;
        case ((4u << 8u) + 1):
            CHECK_ERROR(_readMethod_balances_set_balance(c, &method->basic.balances_set_balance))
            break;
        case ((4u << 8u) + 2):
            CHECK_ERROR(_readMethod_balances_force_transfer(c, &method->basic.balances_force_transfer))
            break;
        case ((4u << 8u) + 3):
            CHECK_ERROR(_readMethod_balances_transfer_keep_alive(c, &method->basic.balances_transfer_keep_alive))
            break;
        case ((5u << 8u) + 0):
            CHECK_ERROR(_readMethod_authorship_set_uncles(c, &method->basic.authorship_set_uncles))
            break;
        case ((6u << 8u) + 0):
            CHECK_ERROR(_readMethod_staking_bond(c, &method->basic.staking_bond))
            break;
        case ((6u << 8u) + 1):
            CHECK_ERROR(_readMethod_staking_bond_extra(c, &method->basic.staking_bond_extra))
            break;
        case ((6u << 8u) + 2):
            CHECK_ERROR(_readMethod_staking_unbond(c, &method->basic.staking_unbond))
            break;
        case ((6u << 8u) + 3):
            CHECK_ERROR(_readMethod_staking_withdraw_unbonded(c, &method->basic.staking_withdraw_unbonded))
            break;
        case ((6u << 8u) + 4):
            CHECK_ERROR(_readMethod_staking_validate(c, &method->basic.staking_validate))
            break;
        case ((6u << 8u) + 5):
            CHECK_ERROR(_readMethod_staking_nominate(c, &method->basic.staking_nominate))
            break;
        case ((6u << 8u) + 6):
            CHECK_ERROR(_readMethod_staking_chill(c, &method->basic.staking_chill))
            break;
        case ((6u << 8u) + 7):
            CHECK_ERROR(_readMethod_staking_set_payee(c, &method->basic.staking_set_payee))
            break;
        case ((6u << 8u) + 8):
            CHECK_ERROR(_readMethod_staking_set_controller(c, &method->basic.staking_set_controller))
            break;
        case ((6u << 8u) + 9):
            CHECK_ERROR(_readMethod_staking_set_validator_count(c, &method->basic.staking_set_validator_count))
            break;
        case ((6u << 8u) + 10):
            CHECK_ERROR(_readMethod_staking_force_no_eras(c, &method->basic.staking_force_no_eras))
            break;
        case ((6u << 8u) + 11):
            CHECK_ERROR(_readMethod_staking_force_new_era(c, &method->basic.staking_force_new_era))
            break;
        case ((6u << 8u) + 12):
            CHECK_ERROR(_readMethod_staking_set_invulnerables(c, &method->basic.staking_set_invulnerables))
            break;
        case ((6u << 8u) + 13):
            CHECK_ERROR(_readMethod_staking_force_unstake(c, &method->basic.staking_force_unstake))
            break;
        case ((6u << 8u) + 14):
            CHECK_ERROR(_readMethod_staking_force_new_era_always(c, &method->basic.staking_force_new_era_always))
            break;
        case ((6u << 8u) + 15):
            CHECK_ERROR(_readMethod_staking_cancel_deferred_slash(c, &method->basic.staking_cancel_deferred_slash))
            break;
        case ((6u << 8u) + 16):
            CHECK_ERROR(_readMethod_staking_payout_nominator(c, &method->basic.staking_payout_nominator))
            break;
        case ((6u << 8u) + 17):
            CHECK_ERROR(_readMethod_staking_payout_validator(c, &method->basic.staking_payout_validator))
            break;
        case ((6u << 8u) + 18):
            CHECK_ERROR(_readMethod_staking_payout_stakers(c, &method->basic.staking_payout_stakers))
            break;
        case ((6u << 8u) + 19):
            CHECK_ERROR(_readMethod_staking_rebond(c, &method->basic.staking_rebond))
            break;
        case ((6u << 8u) + 20):
            CHECK_ERROR(_readMethod_staking_set_history_depth(c, &method->basic.staking_set_history_depth))
            break;
        case ((6u << 8u) + 21):
            CHECK_ERROR(_readMethod_staking_reap_stash(c, &method->basic.staking_reap_stash))
            break;
        case ((6u << 8u) + 22):
            CHECK_ERROR(_readMethod_staking_submit_election_solution(c, &method->basic.staking_submit_election_solution))
            break;
        case ((6u << 8u) + 23):
            CHECK_ERROR(_readMethod_staking_submit_election_solution_unsigned(c, &method->basic.staking_submit_election_solution_unsigned))
            break;
        case ((8u << 8u) + 0):
            CHECK_ERROR(_readMethod_session_set_keys(c, &method->basic.session_set_keys))
            break;
        case ((8u << 8u) + 1):
            CHECK_ERROR(_readMethod_session_purge_keys(c, &method->basic.session_purge_keys))
            break;
        case ((9u << 8u) + 0):
            CHECK_ERROR(_readMethod_finalitytracker_final_hint(c, &method->basic.finalitytracker_final_hint))
            break;
        case ((10u << 8u) + 0):
            CHECK_ERROR(_readMethod_grandpa_report_misbehavior(c, &method->basic.grandpa_report_misbehavior))
            break;
        case ((11u << 8u) + 0):
            CHECK_ERROR(_readMethod_imonline_heartbeat(c, &method->basic.imonline_heartbeat))
            break;
        case ((13u << 8u) + 0):
            CHECK_ERROR(_readMethod_democracy_propose(c, &method->basic.democracy_propose))
            break;
        case ((13u << 8u) + 1):
            CHECK_ERROR(_readMethod_democracy_second(c, &method->basic.democracy_second))
            break;
        case ((13u << 8u) + 2):
            CHECK_ERROR(_readMethod_democracy_vote(c, &method->basic.democracy_vote))
            break;
        case ((13u << 8u) + 3):
            CHECK_ERROR(_readMethod_democracy_proxy_vote(c, &method->basic.democracy_proxy_vote))
            break;
        case ((13u << 8u) + 4):
            CHECK_ERROR(_readMethod_democracy_emergency_cancel(c, &method->basic.democracy_emergency_cancel))
            break;
        case ((13u << 8u) + 5):
            CHECK_ERROR(_readMethod_democracy_external_propose(c, &method->basic.democracy_external_propose))
            break;
        case ((13u << 8u) + 6):
            CHECK_ERROR(_readMethod_democracy_external_propose_majority(c, &method->basic.democracy_external_propose_majority))
            break;
        case ((13u << 8u) + 7):
            CHECK_ERROR(_readMethod_democracy_external_propose_default(c, &method->basic.democracy_external_propose_default))
            break;
        case ((13u << 8u) + 8):
            CHECK_ERROR(_readMethod_democracy_fast_track(c, &method->basic.democracy_fast_track))
            break;
        case ((13u << 8u) + 9):
            CHECK_ERROR(_readMethod_democracy_veto_external(c, &method->basic.democracy_veto_external))
            break;
        case ((13u << 8u) + 10):
            CHECK_ERROR(_readMethod_democracy_cancel_referendum(c, &method->basic.democracy_cancel_referendum))
            break;
        case ((13u << 8u) + 11):
            CHECK_ERROR(_readMethod_democracy_cancel_queued(c, &method->basic.democracy_cancel_queued))
            break;
        case ((13u << 8u) + 12):
            CHECK_ERROR(_readMethod_democracy_activate_proxy(c, &method->basic.democracy_activate_proxy))
            break;
        case ((13u << 8u) + 13):
            CHECK_ERROR(_readMethod_democracy_close_proxy(c, &method->basic.democracy_close_proxy))
            break;
        case ((13u << 8u) + 14):
            CHECK_ERROR(_readMethod_democracy_deactivate_proxy(c, &method->basic.democracy_deactivate_proxy))
            break;
        case ((13u << 8u) + 15):
            CHECK_ERROR(_readMethod_democracy_delegate(c, &method->basic.democracy_delegate))
            break;
        case ((13u << 8u) + 16):
            CHECK_ERROR(_readMethod_democracy_undelegate(c, &method->basic.democracy_undelegate))
            break;
        case ((13u << 8u) + 17):
            CHECK_ERROR(_readMethod_democracy_clear_public_proposals(c, &method->basic.democracy_clear_public_proposals))
            break;
        case ((13u << 8u) + 18):
            CHECK_ERROR(_readMethod_democracy_note_preimage(c, &method->basic.democracy_note_preimage))
            break;
        case ((13u << 8u) + 19):
            CHECK_ERROR(_readMethod_democracy_note_imminent_preimage(c, &method->basic.democracy_note_imminent_preimage))
            break;
        case ((13u << 8u) + 20):
            CHECK_ERROR(_readMethod_democracy_reap_preimage(c, &method->basic.democracy_reap_preimage))
            break;
        case ((13u << 8u) + 21):
            CHECK_ERROR(_readMethod_democracy_unlock(c, &method->basic.democracy_unlock))
            break;
        case ((13u << 8u) + 22):
            CHECK_ERROR(_readMethod_democracy_open_proxy(c, &method->basic.democracy_open_proxy))
            break;
        case ((13u << 8u) + 23):
            CHECK_ERROR(_readMethod_democracy_remove_vote(c, &method->basic.democracy_remove_vote))
            break;
        case ((13u << 8u) + 24):
            CHECK_ERROR(_readMethod_democracy_remove_other_vote(c, &method->basic.democracy_remove_other_vote))
            break;
        case ((13u << 8u) + 25):
            CHECK_ERROR(_readMethod_democracy_proxy_delegate(c, &method->basic.democracy_proxy_delegate))
            break;
        case ((13u << 8u) + 26):
            CHECK_ERROR(_readMethod_democracy_proxy_undelegate(c, &method->basic.democracy_proxy_undelegate))
            break;
        case ((13u << 8u) + 27):
            CHECK_ERROR(_readMethod_democracy_proxy_remove_vote(c, &method->basic.democracy_proxy_remove_vote))
            break;
        case ((13u << 8u) + 28):
            CHECK_ERROR(_readMethod_democracy_enact_proposal(c, &method->basic.democracy_enact_proposal))
            break;
        case ((14u << 8u) + 0):
            CHECK_ERROR(_readMethod_council_set_members(c, &method->basic.council_set_members))
            break;
        case ((14u << 8u) + 1):
            CHECK_ERROR(_readMethod_council_execute(c, &method->nested.council_execute))
            break;
        case ((14u << 8u) + 2):
            CHECK_ERROR(_readMethod_council_propose(c, &method->nested.council_propose))
            break;
        case ((14u << 8u) + 3):
            CHECK_ERROR(_readMethod_council_vote(c, &method->basic.council_vote))
            break;
        case ((14u << 8u) + 4):
            CHECK_ERROR(_readMethod_council_close(c, &method->basic.council_close))
            break;
        case ((15u << 8u) + 0):
            CHECK_ERROR(_readMethod_technicalcommittee_set_members(c, &method->basic.technicalcommittee_set_members))
            break;
        case ((15u << 8u) + 1):
            CHECK_ERROR(_readMethod_technicalcommittee_execute(c, &method->nested.technicalcommittee_execute))
            break;
        case ((15u << 8u) + 2):
            CHECK_ERROR(_readMethod_technicalcommittee_propose(c, &method->nested.technicalcommittee_propose))
            break;
        case ((15u << 8u) + 3):
            CHECK_ERROR(_readMethod_technicalcommittee_vote(c, &method->basic.technicalcommittee_vote))
            break;
        case ((15u << 8u) + 4):
            CHECK_ERROR(_readMethod_technicalcommittee_close(c, &method->basic.technicalcommittee_close))
            break;
        case ((16u << 8u) + 0):
            CHECK_ERROR(_readMethod_electionsphragmen_vote(c, &method->basic.electionsphragmen_vote))
            break;
        case ((16u << 8u) + 1):
            CHECK_ERROR(_readMethod_electionsphragmen_remove_voter(c, &method->basic.electionsphragmen_remove_voter))
            break;
        case ((16u << 8u) + 2):
            CHECK_ERROR(_readMethod_electionsphragmen_report_defunct_voter(c, &method->basic.electionsphragmen_report_defunct_voter))
            break;
        case ((16u << 8u) + 3):
            CHECK_ERROR(_readMethod_electionsphragmen_submit_candidacy(c, &method->basic.electionsphragmen_submit_candidacy))
            break;
        case ((16u << 8u) + 4):
            CHECK_ERROR(_readMethod_electionsphragmen_renounce_candidacy(c, &method->basic.electionsphragmen_renounce_candidacy))
            break;
        case ((16u << 8u) + 5):
            CHECK_ERROR(_readMethod_electionsphragmen_remove_member(c, &method->basic.electionsphragmen_remove_member))
            break;
        case ((17u << 8u) + 0):
            CHECK_ERROR(_readMethod_technicalmembership_add_member(c, &method->basic.technicalmembership_add_member))
            break;
        case ((17u << 8u) + 1):
            CHECK_ERROR(_readMethod_technicalmembership_remove_member(c, &method->basic.technicalmembership_remove_member))
            break;
        case ((17u << 8u) + 2):
            CHECK_ERROR(_readMethod_technicalmembership_swap_member(c, &method->basic.technicalmembership_swap_member))
            break;
        case ((17u << 8u) + 3):
            CHECK_ERROR(_readMethod_technicalmembership_reset_members(c, &method->basic.technicalmembership_reset_members))
            break;
        case ((17u << 8u) + 4):
            CHECK_ERROR(_readMethod_technicalmembership_change_key(c, &method->basic.technicalmembership_change_key))
            break;
        case ((17u << 8u) + 5):
            CHECK_ERROR(_readMethod_technicalmembership_set_prime(c, &method->basic.technicalmembership_set_prime))
            break;
        case ((17u << 8u) + 6):
            CHECK_ERROR(_readMethod_technicalmembership_clear_prime(c, &method->basic.technicalmembership_clear_prime))
            break;
        case ((18u << 8u) + 0):
            CHECK_ERROR(_readMethod_treasury_propose_spend(c, &method->basic.treasury_propose_spend))
            break;
        case ((18u << 8u) + 1):
            CHECK_ERROR(_readMethod_treasury_reject_proposal(c, &method->basic.treasury_reject_proposal))
            break;
        case ((18u << 8u) + 2):
            CHECK_ERROR(_readMethod_treasury_approve_proposal(c, &method->basic.treasury_approve_proposal))
            break;
        case ((18u << 8u) + 3):
            CHECK_ERROR(_readMethod_treasury_report_awesome(c, &method->basic.treasury_report_awesome))
            break;
        case ((18u << 8u) + 4):
            CHECK_ERROR(_readMethod_treasury_retract_tip(c, &method->basic.treasury_retract_tip))
            break;
        case ((18u << 8u) + 5):
            CHECK_ERROR(_readMethod_treasury_tip_new(c, &method->basic.treasury_tip_new))
            break;
        case ((18u << 8u) + 6):
            CHECK_ERROR(_readMethod_treasury_tip(c, &method->basic.treasury_tip))
            break;
        case ((18u << 8u) + 7):
            CHECK_ERROR(_readMethod_treasury_close_tip(c, &method->basic.treasury_close_tip))
            break;
        case ((19u << 8u) + 0):
            CHECK_ERROR(_readMethod_claims_claim(c, &method->basic.claims_claim))
            break;
        case ((19u << 8u) + 1):
            CHECK_ERROR(_readMethod_claims_mint_claim(c, &method->basic.claims_mint_claim))
            break;
        case ((20u << 8u) + 0):
            CHECK_ERROR(_readMethod_parachains_set_heads(c, &method->basic.parachains_set_heads))
            break;
        case ((20u << 8u) + 1):
            CHECK_ERROR(_readMethod_parachains_report_double_vote(c, &method->basic.parachains_report_double_vote))
            break;
        case ((21u << 8u) + 0):
            CHECK_ERROR(_readMethod_attestations_more_attestations(c, &method->basic.attestations_more_attestations))
            break;
        case ((22u << 8u) + 0):
            CHECK_ERROR(_readMethod_slots_new_auction(c, &method->basic.slots_new_auction))
            break;
        case ((22u << 8u) + 1):
            CHECK_ERROR(_readMethod_slots_bid(c, &method->basic.slots_bid))
            break;
        case ((22u << 8u) + 2):
            CHECK_ERROR(_readMethod_slots_bid_renew(c, &method->basic.slots_bid_renew))
            break;
        case ((22u << 8u) + 3):
            CHECK_ERROR(_readMethod_slots_set_offboarding(c, &method->basic.slots_set_offboarding))
            break;
        case ((22u << 8u) + 4):
            CHECK_ERROR(_readMethod_slots_fix_deploy_data(c, &method->basic.slots_fix_deploy_data))
            break;
        case ((22u << 8u) + 5):
            CHECK_ERROR(_readMethod_slots_elaborate_deploy_data(c, &method->basic.slots_elaborate_deploy_data))
            break;
        case ((23u << 8u) + 0):
            CHECK_ERROR(_readMethod_registrar_register_para(c, &method->basic.registrar_register_para))
            break;
        case ((23u << 8u) + 1):
            CHECK_ERROR(_readMethod_registrar_deregister_para(c, &method->basic.registrar_deregister_para))
            break;
        case ((23u << 8u) + 2):
            CHECK_ERROR(_readMethod_registrar_set_thread_count(c, &method->basic.registrar_set_thread_count))
            break;
        case ((23u << 8u) + 3):
            CHECK_ERROR(_readMethod_registrar_register_parathread(c, &method->basic.registrar_register_parathread))
            break;
        case ((23u << 8u) + 4):
            CHECK_ERROR(_readMethod_registrar_select_parathread(c, &method->basic.registrar_select_parathread))
            break;
        case ((23u << 8u) + 5):
            CHECK_ERROR(_readMethod_registrar_deregister_parathread(c, &method->basic.registrar_deregister_parathread))
            break;
        case ((23u << 8u) + 6):
            CHECK_ERROR(_readMethod_registrar_swap(c, &method->basic.registrar_swap))
            break;
        case ((24u << 8u) + 0):
            CHECK_ERROR(_readMethod_utility_batch(c, &method->basic.utility_batch))
            break;
        case ((24u << 8u) + 1):
            CHECK_ERROR(_readMethod_utility_as_sub(c, &method->basic.utility_as_sub))
            break;
        case ((24u << 8u) + 2):
            CHECK_ERROR(_readMethod_utility_as_multi(c, &method->basic.utility_as_multi))
            break;
        case ((24u << 8u) + 3):
            CHECK_ERROR(_readMethod_utility_approve_as_multi(c, &method->basic.utility_approve_as_multi))
            break;
        case ((24u << 8u) + 4):
            CHECK_ERROR(_readMethod_utility_cancel_as_multi(c, &method->basic.utility_cancel_as_multi))
            break;
        case ((25u << 8u) + 0):
            CHECK_ERROR(_readMethod_identity_add_registrar(c, &method->basic.identity_add_registrar))
            break;
        case ((25u << 8u) + 1):
            CHECK_ERROR(_readMethod_identity_set_identity(c, &method->basic.identity_set_identity))
            break;
        case ((25u << 8u) + 2):
            CHECK_ERROR(_readMethod_identity_set_subs(c, &method->basic.identity_set_subs))
            break;
        case ((25u << 8u) + 3):
            CHECK_ERROR(_readMethod_identity_clear_identity(c, &method->basic.identity_clear_identity))
            break;
        case ((25u << 8u) + 4):
            CHECK_ERROR(_readMethod_identity_request_judgement(c, &method->basic.identity_request_judgement))
            break;
        case ((25u << 8u) + 5):
            CHECK_ERROR(_readMethod_identity_cancel_request(c, &method->basic.identity_cancel_request))
            break;
        case ((25u << 8u) + 6):
            CHECK_ERROR(_readMethod_identity_set_fee(c, &method->basic.identity_set_fee))
            break;
        case ((25u << 8u) + 7):
            CHECK_ERROR(_readMethod_identity_set_account_id(c, &method->basic.identity_set_account_id))
            break;
        case ((25u << 8u) + 8):
            CHECK_ERROR(_readMethod_identity_set_fields(c, &method->basic.identity_set_fields))
            break;
        case ((25u << 8u) + 9):
            CHECK_ERROR(_readMethod_identity_provide_judgement(c, &method->basic.identity_provide_judgement))
            break;
        case ((25u << 8u) + 10):
            CHECK_ERROR(_readMethod_identity_kill_identity(c, &method->basic.identity_kill_identity))
            break;
        case ((26u << 8u) + 0):
            CHECK_ERROR(_readMethod_society_bid(c, &method->basic.society_bid))
            break;
        case ((26u << 8u) + 1):
            CHECK_ERROR(_readMethod_society_unbid(c, &method->basic.society_unbid))
            break;
        case ((26u << 8u) + 2):
            CHECK_ERROR(_readMethod_society_vouch(c, &method->basic.society_vouch))
            break;
        case ((26u << 8u) + 3):
            CHECK_ERROR(_readMethod_society_unvouch(c, &method->basic.society_unvouch))
            break;
        case ((26u << 8u) + 4):
            CHECK_ERROR(_readMethod_society_vote(c, &method->basic.society_vote))
            break;
        case ((26u << 8u) + 5):
            CHECK_ERROR(_readMethod_society_defender_vote(c, &method->basic.society_defender_vote))
            break;
        case ((26u << 8u) + 6):
            CHECK_ERROR(_readMethod_society_payout(c, &method->basic.society_payout))
            break;
        case ((26u << 8u) + 7):
            CHECK_ERROR(_readMethod_society_found(c, &method->basic.society_found))
            break;
        case ((26u << 8u) + 8):
            CHECK_ERROR(_readMethod_society_unfound(c, &method->basic.society_unfound))
            break;
        case ((26u << 8u) + 9):
            CHECK_ERROR(_readMethod_society_judge_suspended_member(c, &method->basic.society_judge_suspended_member))
            break;
        case ((26u << 8u) + 10):
            CHECK_ERROR(_readMethod_society_judge_suspended_candidate(c, &method->basic.society_judge_suspended_candidate))
            break;
        case ((26u << 8u) + 11):
            CHECK_ERROR(_readMethod_society_set_max_members(c, &method->basic.society_set_max_members))
            break;
        case ((27u << 8u) + 0):
            CHECK_ERROR(_readMethod_recovery_as_recovered(c, &method->basic.recovery_as_recovered))
            break;
        case ((27u << 8u) + 1):
            CHECK_ERROR(_readMethod_recovery_set_recovered(c, &method->basic.recovery_set_recovered))
            break;
        case ((27u << 8u) + 2):
            CHECK_ERROR(_readMethod_recovery_create_recovery(c, &method->basic.recovery_create_recovery))
            break;
        case ((27u << 8u) + 3):
            CHECK_ERROR(_readMethod_recovery_initiate_recovery(c, &method->basic.recovery_initiate_recovery))
            break;
        case ((27u << 8u) + 4):
            CHECK_ERROR(_readMethod_recovery_vouch_recovery(c, &method->basic.recovery_vouch_recovery))
            break;
        case ((27u << 8u) + 5):
            CHECK_ERROR(_readMethod_recovery_claim_recovery(c, &method->basic.recovery_claim_recovery))
            break;
        case ((27u << 8u) + 6):
            CHECK_ERROR(_readMethod_recovery_close_recovery(c, &method->basic.recovery_close_recovery))
            break;
        case ((27u << 8u) + 7):
            CHECK_ERROR(_readMethod_recovery_remove_recovery(c, &method->basic.recovery_remove_recovery))
            break;
        case ((27u << 8u) + 8):
            CHECK_ERROR(_readMethod_recovery_cancel_recovered(c, &method->basic.recovery_cancel_recovered))
            break;
        case ((28u << 8u) + 0):
            CHECK_ERROR(_readMethod_vesting_vest(c, &method->basic.vesting_vest))
            break;
        case ((28u << 8u) + 1):
            CHECK_ERROR(_readMethod_vesting_vest_other(c, &method->basic.vesting_vest_other))
            break;
        case ((28u << 8u) + 2):
            CHECK_ERROR(_readMethod_vesting_vested_transfer(c, &method->basic.vesting_vested_transfer))
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
    default:
    return NULL;
    }

    return NULL;
}


const char * _getMethod_Name(uint8_t moduleIdx, uint8_t callIdx) {
    uint16_t callPrivIdx = (moduleIdx << 8u) + callIdx;

    switch(callPrivIdx) {
        case ((0u << 8u) + 0):   return "Fill block";
        case ((0u << 8u) + 1):   return "Remark";
        case ((0u << 8u) + 2):   return "Set heap pages";
        case ((0u << 8u) + 3):   return "Set code";
        case ((0u << 8u) + 4):   return "Set code without checks";
        case ((0u << 8u) + 5):   return "Set changes trie config";
        case ((0u << 8u) + 6):   return "Set storage";
        case ((0u << 8u) + 7):   return "Kill storage";
        case ((0u << 8u) + 8):   return "Kill prefix";
        case ((0u << 8u) + 9):   return "Suicide";
        case ((2u << 8u) + 0):   return "Set";
        case ((3u << 8u) + 0):   return "Claim";
        case ((3u << 8u) + 1):   return "Transfer";
        case ((3u << 8u) + 2):   return "Free";
        case ((3u << 8u) + 3):   return "Force transfer";
        case ((4u << 8u) + 0):   return "Transfer";
        case ((4u << 8u) + 1):   return "Set balance";
        case ((4u << 8u) + 2):   return "Force transfer";
        case ((4u << 8u) + 3):   return "Transfer keep alive";
        case ((5u << 8u) + 0):   return "Set uncles";
        case ((6u << 8u) + 0):   return "Bond";
        case ((6u << 8u) + 1):   return "Bond extra";
        case ((6u << 8u) + 2):   return "Unbond";
        case ((6u << 8u) + 3):   return "Withdraw unbonded";
        case ((6u << 8u) + 4):   return "Validate";
        case ((6u << 8u) + 5):   return "Nominate";
        case ((6u << 8u) + 6):   return "Chill";
        case ((6u << 8u) + 7):   return "Set payee";
        case ((6u << 8u) + 8):   return "Set controller";
        case ((6u << 8u) + 9):   return "Set validator count";
        case ((6u << 8u) + 10):   return "Force no eras";
        case ((6u << 8u) + 11):   return "Force new era";
        case ((6u << 8u) + 12):   return "Set invulnerables";
        case ((6u << 8u) + 13):   return "Force unstake";
        case ((6u << 8u) + 14):   return "Force new era always";
        case ((6u << 8u) + 15):   return "Cancel deferred slash";
        case ((6u << 8u) + 16):   return "Payout nominator";
        case ((6u << 8u) + 17):   return "Payout validator";
        case ((6u << 8u) + 18):   return "Payout stakers";
        case ((6u << 8u) + 19):   return "Rebond";
        case ((6u << 8u) + 20):   return "Set history depth";
        case ((6u << 8u) + 21):   return "Reap stash";
        case ((6u << 8u) + 22):   return "Submit election solution";
        case ((6u << 8u) + 23):   return "Submit election solution unsigned";
        case ((8u << 8u) + 0):   return "Set keys";
        case ((8u << 8u) + 1):   return "Purge keys";
        case ((9u << 8u) + 0):   return "Final hint";
        case ((10u << 8u) + 0):   return "Report misbehavior";
        case ((11u << 8u) + 0):   return "Heartbeat";
        case ((13u << 8u) + 0):   return "Propose";
        case ((13u << 8u) + 1):   return "Second";
        case ((13u << 8u) + 2):   return "Vote";
        case ((13u << 8u) + 3):   return "Proxy vote";
        case ((13u << 8u) + 4):   return "Emergency cancel";
        case ((13u << 8u) + 5):   return "External propose";
        case ((13u << 8u) + 6):   return "External propose majority";
        case ((13u << 8u) + 7):   return "External propose default";
        case ((13u << 8u) + 8):   return "Fast track";
        case ((13u << 8u) + 9):   return "Veto external";
        case ((13u << 8u) + 10):   return "Cancel referendum";
        case ((13u << 8u) + 11):   return "Cancel queued";
        case ((13u << 8u) + 12):   return "Activate proxy";
        case ((13u << 8u) + 13):   return "Close proxy";
        case ((13u << 8u) + 14):   return "Deactivate proxy";
        case ((13u << 8u) + 15):   return "Delegate";
        case ((13u << 8u) + 16):   return "Undelegate";
        case ((13u << 8u) + 17):   return "Clear public proposals";
        case ((13u << 8u) + 18):   return "Note preimage";
        case ((13u << 8u) + 19):   return "Note imminent preimage";
        case ((13u << 8u) + 20):   return "Reap preimage";
        case ((13u << 8u) + 21):   return "Unlock";
        case ((13u << 8u) + 22):   return "Open proxy";
        case ((13u << 8u) + 23):   return "Remove vote";
        case ((13u << 8u) + 24):   return "Remove other vote";
        case ((13u << 8u) + 25):   return "Proxy delegate";
        case ((13u << 8u) + 26):   return "Proxy undelegate";
        case ((13u << 8u) + 27):   return "Proxy remove vote";
        case ((13u << 8u) + 28):   return "Enact proposal";
        case ((14u << 8u) + 0):   return "Set members";
        case ((14u << 8u) + 1):   return "Execute";
        case ((14u << 8u) + 2):   return "Propose";
        case ((14u << 8u) + 3):   return "Vote";
        case ((14u << 8u) + 4):   return "Close";
        case ((15u << 8u) + 0):   return "Set members";
        case ((15u << 8u) + 1):   return "Execute";
        case ((15u << 8u) + 2):   return "Propose";
        case ((15u << 8u) + 3):   return "Vote";
        case ((15u << 8u) + 4):   return "Close";
        case ((16u << 8u) + 0):   return "Vote";
        case ((16u << 8u) + 1):   return "Remove voter";
        case ((16u << 8u) + 2):   return "Report defunct voter";
        case ((16u << 8u) + 3):   return "Submit candidacy";
        case ((16u << 8u) + 4):   return "Renounce candidacy";
        case ((16u << 8u) + 5):   return "Remove member";
        case ((17u << 8u) + 0):   return "Add member";
        case ((17u << 8u) + 1):   return "Remove member";
        case ((17u << 8u) + 2):   return "Swap member";
        case ((17u << 8u) + 3):   return "Reset members";
        case ((17u << 8u) + 4):   return "Change key";
        case ((17u << 8u) + 5):   return "Set prime";
        case ((17u << 8u) + 6):   return "Clear prime";
        case ((18u << 8u) + 0):   return "Propose spend";
        case ((18u << 8u) + 1):   return "Reject proposal";
        case ((18u << 8u) + 2):   return "Approve proposal";
        case ((18u << 8u) + 3):   return "Report awesome";
        case ((18u << 8u) + 4):   return "Retract tip";
        case ((18u << 8u) + 5):   return "Tip new";
        case ((18u << 8u) + 6):   return "Tip";
        case ((18u << 8u) + 7):   return "Close tip";
        case ((19u << 8u) + 0):   return "Claim";
        case ((19u << 8u) + 1):   return "Mint claim";
        case ((20u << 8u) + 0):   return "Set heads";
        case ((20u << 8u) + 1):   return "Report double vote";
        case ((21u << 8u) + 0):   return "More attestations";
        case ((22u << 8u) + 0):   return "New auction";
        case ((22u << 8u) + 1):   return "Bid";
        case ((22u << 8u) + 2):   return "Bid renew";
        case ((22u << 8u) + 3):   return "Set offboarding";
        case ((22u << 8u) + 4):   return "Fix deploy data";
        case ((22u << 8u) + 5):   return "Elaborate deploy data";
        case ((23u << 8u) + 0):   return "Register para";
        case ((23u << 8u) + 1):   return "Deregister para";
        case ((23u << 8u) + 2):   return "Set thread count";
        case ((23u << 8u) + 3):   return "Register parathread";
        case ((23u << 8u) + 4):   return "Select parathread";
        case ((23u << 8u) + 5):   return "Deregister parathread";
        case ((23u << 8u) + 6):   return "Swap";
        case ((24u << 8u) + 0):   return "Batch";
        case ((24u << 8u) + 1):   return "As sub";
        case ((24u << 8u) + 2):   return "As multi";
        case ((24u << 8u) + 3):   return "Approve as multi";
        case ((24u << 8u) + 4):   return "Cancel as multi";
        case ((25u << 8u) + 0):   return "Add registrar";
        case ((25u << 8u) + 1):   return "Set identity";
        case ((25u << 8u) + 2):   return "Set subs";
        case ((25u << 8u) + 3):   return "Clear identity";
        case ((25u << 8u) + 4):   return "Request judgement";
        case ((25u << 8u) + 5):   return "Cancel request";
        case ((25u << 8u) + 6):   return "Set fee";
        case ((25u << 8u) + 7):   return "Set account id";
        case ((25u << 8u) + 8):   return "Set fields";
        case ((25u << 8u) + 9):   return "Provide judgement";
        case ((25u << 8u) + 10):   return "Kill identity";
        case ((26u << 8u) + 0):   return "Bid";
        case ((26u << 8u) + 1):   return "Unbid";
        case ((26u << 8u) + 2):   return "Vouch";
        case ((26u << 8u) + 3):   return "Unvouch";
        case ((26u << 8u) + 4):   return "Vote";
        case ((26u << 8u) + 5):   return "Defender vote";
        case ((26u << 8u) + 6):   return "Payout";
        case ((26u << 8u) + 7):   return "Found";
        case ((26u << 8u) + 8):   return "Unfound";
        case ((26u << 8u) + 9):   return "Judge suspended member";
        case ((26u << 8u) + 10):   return "Judge suspended candidate";
        case ((26u << 8u) + 11):   return "Set max members";
        case ((27u << 8u) + 0):   return "As recovered";
        case ((27u << 8u) + 1):   return "Set recovered";
        case ((27u << 8u) + 2):   return "Create recovery";
        case ((27u << 8u) + 3):   return "Initiate recovery";
        case ((27u << 8u) + 4):   return "Vouch recovery";
        case ((27u << 8u) + 5):   return "Claim recovery";
        case ((27u << 8u) + 6):   return "Close recovery";
        case ((27u << 8u) + 7):   return "Remove recovery";
        case ((27u << 8u) + 8):   return "Cancel recovered";
        case ((28u << 8u) + 0):   return "Vest";
        case ((28u << 8u) + 1):   return "Vest other";
        case ((28u << 8u) + 2):   return "Vested transfer";
    default:
        return NULL;
    }

    return NULL;
}

uint8_t _getMethod_NumItems(uint8_t moduleIdx, uint8_t callIdx, pd_Method_t *method) {
    uint16_t callPrivIdx = (moduleIdx << 8u) + callIdx;

    switch(callPrivIdx) {
        case ((0u << 8u) + 0): return 1;
        case ((0u << 8u) + 1): return 1;
        case ((0u << 8u) + 2): return 1;
        case ((0u << 8u) + 3): return 1;
        case ((0u << 8u) + 4): return 1;
        case ((0u << 8u) + 5): return 1;
        case ((0u << 8u) + 6): return 1;
        case ((0u << 8u) + 7): return 1;
        case ((0u << 8u) + 8): return 1;
        case ((0u << 8u) + 9): return 0;
        case ((2u << 8u) + 0): return 1;
        case ((3u << 8u) + 0): return 1;
        case ((3u << 8u) + 1): return 2;
        case ((3u << 8u) + 2): return 1;
        case ((3u << 8u) + 3): return 2;
        case ((4u << 8u) + 0): return 2;
        case ((4u << 8u) + 1): return 3;
        case ((4u << 8u) + 2): return 3;
        case ((4u << 8u) + 3): return 2;
        case ((5u << 8u) + 0): return 1;
        case ((6u << 8u) + 0): return 3;
        case ((6u << 8u) + 1): return 1;
        case ((6u << 8u) + 2): return 1;
        case ((6u << 8u) + 3): return 0;
        case ((6u << 8u) + 4): return 1;
        case ((6u << 8u) + 5): return 1;
        case ((6u << 8u) + 6): return 0;
        case ((6u << 8u) + 7): return 1;
        case ((6u << 8u) + 8): return 1;
        case ((6u << 8u) + 9): return 1;
        case ((6u << 8u) + 10): return 0;
        case ((6u << 8u) + 11): return 0;
        case ((6u << 8u) + 12): return 1;
        case ((6u << 8u) + 13): return 1;
        case ((6u << 8u) + 14): return 0;
        case ((6u << 8u) + 15): return 2;
        case ((6u << 8u) + 16): return 2;
        case ((6u << 8u) + 17): return 1;
        case ((6u << 8u) + 18): return 2;
        case ((6u << 8u) + 19): return 1;
        case ((6u << 8u) + 20): return 1;
        case ((6u << 8u) + 21): return 1;
        case ((6u << 8u) + 22): return 4;
        case ((6u << 8u) + 23): return 4;
        case ((8u << 8u) + 0): return 2;
        case ((8u << 8u) + 1): return 0;
        case ((9u << 8u) + 0): return 1;
        case ((10u << 8u) + 0): return 1;
        case ((11u << 8u) + 0): return 2;
        case ((13u << 8u) + 0): return 2;
        case ((13u << 8u) + 1): return 1;
        case ((13u << 8u) + 2): return 2;
        case ((13u << 8u) + 3): return 2;
        case ((13u << 8u) + 4): return 1;
        case ((13u << 8u) + 5): return 1;
        case ((13u << 8u) + 6): return 1;
        case ((13u << 8u) + 7): return 1;
        case ((13u << 8u) + 8): return 3;
        case ((13u << 8u) + 9): return 1;
        case ((13u << 8u) + 10): return 1;
        case ((13u << 8u) + 11): return 1;
        case ((13u << 8u) + 12): return 1;
        case ((13u << 8u) + 13): return 0;
        case ((13u << 8u) + 14): return 1;
        case ((13u << 8u) + 15): return 3;
        case ((13u << 8u) + 16): return 0;
        case ((13u << 8u) + 17): return 0;
        case ((13u << 8u) + 18): return 1;
        case ((13u << 8u) + 19): return 1;
        case ((13u << 8u) + 20): return 1;
        case ((13u << 8u) + 21): return 1;
        case ((13u << 8u) + 22): return 1;
        case ((13u << 8u) + 23): return 1;
        case ((13u << 8u) + 24): return 2;
        case ((13u << 8u) + 25): return 3;
        case ((13u << 8u) + 26): return 0;
        case ((13u << 8u) + 27): return 1;
        case ((13u << 8u) + 28): return 2;
        case ((14u << 8u) + 0): return 2;
        case ((14u << 8u) + 1): return 1;
        case ((14u << 8u) + 2): return 2;
        case ((14u << 8u) + 3): return 3;
        case ((14u << 8u) + 4): return 2;
        case ((15u << 8u) + 0): return 2;
        case ((15u << 8u) + 1): return 1;
        case ((15u << 8u) + 2): return 2;
        case ((15u << 8u) + 3): return 3;
        case ((15u << 8u) + 4): return 2;
        case ((16u << 8u) + 0): return 2;
        case ((16u << 8u) + 1): return 0;
        case ((16u << 8u) + 2): return 1;
        case ((16u << 8u) + 3): return 0;
        case ((16u << 8u) + 4): return 0;
        case ((16u << 8u) + 5): return 1;
        case ((17u << 8u) + 0): return 1;
        case ((17u << 8u) + 1): return 1;
        case ((17u << 8u) + 2): return 2;
        case ((17u << 8u) + 3): return 1;
        case ((17u << 8u) + 4): return 1;
        case ((17u << 8u) + 5): return 1;
        case ((17u << 8u) + 6): return 0;
        case ((18u << 8u) + 0): return 2;
        case ((18u << 8u) + 1): return 1;
        case ((18u << 8u) + 2): return 1;
        case ((18u << 8u) + 3): return 2;
        case ((18u << 8u) + 4): return 1;
        case ((18u << 8u) + 5): return 3;
        case ((18u << 8u) + 6): return 2;
        case ((18u << 8u) + 7): return 1;
        case ((19u << 8u) + 0): return 2;
        case ((19u << 8u) + 1): return 3;
        case ((20u << 8u) + 0): return 1;
        case ((20u << 8u) + 1): return 1;
        case ((21u << 8u) + 0): return 1;
        case ((22u << 8u) + 0): return 2;
        case ((22u << 8u) + 1): return 5;
        case ((22u << 8u) + 2): return 4;
        case ((22u << 8u) + 3): return 1;
        case ((22u << 8u) + 4): return 5;
        case ((22u << 8u) + 5): return 2;
        case ((23u << 8u) + 0): return 4;
        case ((23u << 8u) + 1): return 1;
        case ((23u << 8u) + 2): return 1;
        case ((23u << 8u) + 3): return 2;
        case ((23u << 8u) + 4): return 3;
        case ((23u << 8u) + 5): return 0;
        case ((23u << 8u) + 6): return 1;
        case ((24u << 8u) + 0): return 1;
        case ((24u << 8u) + 1): return 2;
        case ((24u << 8u) + 2): return 4;
        case ((24u << 8u) + 3): return 4;
        case ((24u << 8u) + 4): return 4;
        case ((25u << 8u) + 0): return 1;
        case ((25u << 8u) + 1): return 1;
        case ((25u << 8u) + 2): return 1;
        case ((25u << 8u) + 3): return 0;
        case ((25u << 8u) + 4): return 2;
        case ((25u << 8u) + 5): return 1;
        case ((25u << 8u) + 6): return 2;
        case ((25u << 8u) + 7): return 2;
        case ((25u << 8u) + 8): return 2;
        case ((25u << 8u) + 9): return 3;
        case ((25u << 8u) + 10): return 1;
        case ((26u << 8u) + 0): return 1;
        case ((26u << 8u) + 1): return 1;
        case ((26u << 8u) + 2): return 3;
        case ((26u << 8u) + 3): return 1;
        case ((26u << 8u) + 4): return 2;
        case ((26u << 8u) + 5): return 1;
        case ((26u << 8u) + 6): return 0;
        case ((26u << 8u) + 7): return 3;
        case ((26u << 8u) + 8): return 0;
        case ((26u << 8u) + 9): return 2;
        case ((26u << 8u) + 10): return 2;
        case ((26u << 8u) + 11): return 1;
        case ((27u << 8u) + 0): return 2;
        case ((27u << 8u) + 1): return 2;
        case ((27u << 8u) + 2): return 3;
        case ((27u << 8u) + 3): return 1;
        case ((27u << 8u) + 4): return 2;
        case ((27u << 8u) + 5): return 1;
        case ((27u << 8u) + 6): return 1;
        case ((27u << 8u) + 7): return 0;
        case ((27u << 8u) + 8): return 1;
        case ((28u << 8u) + 0): return 0;
        case ((28u << 8u) + 1): return 1;
        case ((28u << 8u) + 2): return 2;
    default:
    return 0;
    }

    return 0;
}


const char * _getMethod_ItemName(uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx) {
    uint16_t callPrivIdx = (moduleIdx << 8u) + callIdx;

    switch(callPrivIdx) {
        case ((0u << 8u) + 0):
            switch(itemIdx) {
                case 0: return "Ratio";
                default: return NULL;
            }
        case ((0u << 8u) + 1):
            switch(itemIdx) {
                case 0: return "Remark";
                default: return NULL;
            }
        case ((0u << 8u) + 2):
            switch(itemIdx) {
                case 0: return "Pages";
                default: return NULL;
            }
        case ((0u << 8u) + 3):
            switch(itemIdx) {
                case 0: return "Code";
                default: return NULL;
            }
        case ((0u << 8u) + 4):
            switch(itemIdx) {
                case 0: return "Code";
                default: return NULL;
            }
        case ((0u << 8u) + 5):
            switch(itemIdx) {
                case 0: return "Changes trie config";
                default: return NULL;
            }
        case ((0u << 8u) + 6):
            switch(itemIdx) {
                case 0: return "Items";
                default: return NULL;
            }
        case ((0u << 8u) + 7):
            switch(itemIdx) {
                case 0: return "Keys";
                default: return NULL;
            }
        case ((0u << 8u) + 8):
            switch(itemIdx) {
                case 0: return "Prefix";
                default: return NULL;
            }
        case ((0u << 8u) + 9):
            switch(itemIdx) {
                default: return NULL;
            }
        case ((2u << 8u) + 0):
            switch(itemIdx) {
                case 0: return "Now";
                default: return NULL;
            }
        case ((3u << 8u) + 0):
            switch(itemIdx) {
                case 0: return "Index";
                default: return NULL;
            }
        case ((3u << 8u) + 1):
            switch(itemIdx) {
                case 0: return "New";
                case 1: return "Index";
                default: return NULL;
            }
        case ((3u << 8u) + 2):
            switch(itemIdx) {
                case 0: return "Index";
                default: return NULL;
            }
        case ((3u << 8u) + 3):
            switch(itemIdx) {
                case 0: return "New";
                case 1: return "Index";
                default: return NULL;
            }
        case ((4u << 8u) + 0):
            switch(itemIdx) {
                case 0: return "Dest";
                case 1: return "Value";
                default: return NULL;
            }
        case ((4u << 8u) + 1):
            switch(itemIdx) {
                case 0: return "Who";
                case 1: return "New free";
                case 2: return "New reserved";
                default: return NULL;
            }
        case ((4u << 8u) + 2):
            switch(itemIdx) {
                case 0: return "Source";
                case 1: return "Dest";
                case 2: return "Value";
                default: return NULL;
            }
        case ((4u << 8u) + 3):
            switch(itemIdx) {
                case 0: return "Dest";
                case 1: return "Value";
                default: return NULL;
            }
        case ((5u << 8u) + 0):
            switch(itemIdx) {
                case 0: return "New uncles";
                default: return NULL;
            }
        case ((6u << 8u) + 0):
            switch(itemIdx) {
                case 0: return "Controller";
                case 1: return "Value";
                case 2: return "Payee";
                default: return NULL;
            }
        case ((6u << 8u) + 1):
            switch(itemIdx) {
                case 0: return "Max additional";
                default: return NULL;
            }
        case ((6u << 8u) + 2):
            switch(itemIdx) {
                case 0: return "Value";
                default: return NULL;
            }
        case ((6u << 8u) + 3):
            switch(itemIdx) {
                default: return NULL;
            }
        case ((6u << 8u) + 4):
            switch(itemIdx) {
                case 0: return "Prefs";
                default: return NULL;
            }
        case ((6u << 8u) + 5):
            switch(itemIdx) {
                case 0: return "Targets";
                default: return NULL;
            }
        case ((6u << 8u) + 6):
            switch(itemIdx) {
                default: return NULL;
            }
        case ((6u << 8u) + 7):
            switch(itemIdx) {
                case 0: return "Payee";
                default: return NULL;
            }
        case ((6u << 8u) + 8):
            switch(itemIdx) {
                case 0: return "Controller";
                default: return NULL;
            }
        case ((6u << 8u) + 9):
            switch(itemIdx) {
                case 0: return "New";
                default: return NULL;
            }
        case ((6u << 8u) + 10):
            switch(itemIdx) {
                default: return NULL;
            }
        case ((6u << 8u) + 11):
            switch(itemIdx) {
                default: return NULL;
            }
        case ((6u << 8u) + 12):
            switch(itemIdx) {
                case 0: return "Validators";
                default: return NULL;
            }
        case ((6u << 8u) + 13):
            switch(itemIdx) {
                case 0: return "Stash";
                default: return NULL;
            }
        case ((6u << 8u) + 14):
            switch(itemIdx) {
                default: return NULL;
            }
        case ((6u << 8u) + 15):
            switch(itemIdx) {
                case 0: return "Era";
                case 1: return "Slash indices";
                default: return NULL;
            }
        case ((6u << 8u) + 16):
            switch(itemIdx) {
                case 0: return "Era";
                case 1: return "Validators";
                default: return NULL;
            }
        case ((6u << 8u) + 17):
            switch(itemIdx) {
                case 0: return "Era";
                default: return NULL;
            }
        case ((6u << 8u) + 18):
            switch(itemIdx) {
                case 0: return "Validator stash";
                case 1: return "Era";
                default: return NULL;
            }
        case ((6u << 8u) + 19):
            switch(itemIdx) {
                case 0: return "Value";
                default: return NULL;
            }
        case ((6u << 8u) + 20):
            switch(itemIdx) {
                case 0: return "New history depth";
                default: return NULL;
            }
        case ((6u << 8u) + 21):
            switch(itemIdx) {
                case 0: return "Stash";
                default: return NULL;
            }
        case ((6u << 8u) + 22):
            switch(itemIdx) {
                case 0: return "Winners";
                case 1: return "Compact assignments";
                case 2: return "Score";
                case 3: return "Era";
                default: return NULL;
            }
        case ((6u << 8u) + 23):
            switch(itemIdx) {
                case 0: return "Winners";
                case 1: return "Compact assignments";
                case 2: return "Score";
                case 3: return "Era";
                default: return NULL;
            }
        case ((8u << 8u) + 0):
            switch(itemIdx) {
                case 0: return "Keys";
                case 1: return "Proof";
                default: return NULL;
            }
        case ((8u << 8u) + 1):
            switch(itemIdx) {
                default: return NULL;
            }
        case ((9u << 8u) + 0):
            switch(itemIdx) {
                case 0: return "Hint";
                default: return NULL;
            }
        case ((10u << 8u) + 0):
            switch(itemIdx) {
                case 0: return "Report";
                default: return NULL;
            }
        case ((11u << 8u) + 0):
            switch(itemIdx) {
                case 0: return "Heartbeat";
                case 1: return "Signature";
                default: return NULL;
            }
        case ((13u << 8u) + 0):
            switch(itemIdx) {
                case 0: return "Proposal hash";
                case 1: return "Value";
                default: return NULL;
            }
        case ((13u << 8u) + 1):
            switch(itemIdx) {
                case 0: return "Proposal";
                default: return NULL;
            }
        case ((13u << 8u) + 2):
            switch(itemIdx) {
                case 0: return "Ref index";
                case 1: return "Vote";
                default: return NULL;
            }
        case ((13u << 8u) + 3):
            switch(itemIdx) {
                case 0: return "Ref index";
                case 1: return "Vote";
                default: return NULL;
            }
        case ((13u << 8u) + 4):
            switch(itemIdx) {
                case 0: return "Ref index";
                default: return NULL;
            }
        case ((13u << 8u) + 5):
            switch(itemIdx) {
                case 0: return "Proposal hash";
                default: return NULL;
            }
        case ((13u << 8u) + 6):
            switch(itemIdx) {
                case 0: return "Proposal hash";
                default: return NULL;
            }
        case ((13u << 8u) + 7):
            switch(itemIdx) {
                case 0: return "Proposal hash";
                default: return NULL;
            }
        case ((13u << 8u) + 8):
            switch(itemIdx) {
                case 0: return "Proposal hash";
                case 1: return "Voting period";
                case 2: return "Delay";
                default: return NULL;
            }
        case ((13u << 8u) + 9):
            switch(itemIdx) {
                case 0: return "Proposal hash";
                default: return NULL;
            }
        case ((13u << 8u) + 10):
            switch(itemIdx) {
                case 0: return "Ref index";
                default: return NULL;
            }
        case ((13u << 8u) + 11):
            switch(itemIdx) {
                case 0: return "Which";
                default: return NULL;
            }
        case ((13u << 8u) + 12):
            switch(itemIdx) {
                case 0: return "Proxy";
                default: return NULL;
            }
        case ((13u << 8u) + 13):
            switch(itemIdx) {
                default: return NULL;
            }
        case ((13u << 8u) + 14):
            switch(itemIdx) {
                case 0: return "Proxy";
                default: return NULL;
            }
        case ((13u << 8u) + 15):
            switch(itemIdx) {
                case 0: return "To";
                case 1: return "Conviction";
                case 2: return "Balance";
                default: return NULL;
            }
        case ((13u << 8u) + 16):
            switch(itemIdx) {
                default: return NULL;
            }
        case ((13u << 8u) + 17):
            switch(itemIdx) {
                default: return NULL;
            }
        case ((13u << 8u) + 18):
            switch(itemIdx) {
                case 0: return "Encoded proposal";
                default: return NULL;
            }
        case ((13u << 8u) + 19):
            switch(itemIdx) {
                case 0: return "Encoded proposal";
                default: return NULL;
            }
        case ((13u << 8u) + 20):
            switch(itemIdx) {
                case 0: return "Proposal hash";
                default: return NULL;
            }
        case ((13u << 8u) + 21):
            switch(itemIdx) {
                case 0: return "Target";
                default: return NULL;
            }
        case ((13u << 8u) + 22):
            switch(itemIdx) {
                case 0: return "Target";
                default: return NULL;
            }
        case ((13u << 8u) + 23):
            switch(itemIdx) {
                case 0: return "Index";
                default: return NULL;
            }
        case ((13u << 8u) + 24):
            switch(itemIdx) {
                case 0: return "Target";
                case 1: return "Index";
                default: return NULL;
            }
        case ((13u << 8u) + 25):
            switch(itemIdx) {
                case 0: return "To";
                case 1: return "Conviction";
                case 2: return "Balance";
                default: return NULL;
            }
        case ((13u << 8u) + 26):
            switch(itemIdx) {
                default: return NULL;
            }
        case ((13u << 8u) + 27):
            switch(itemIdx) {
                case 0: return "Index";
                default: return NULL;
            }
        case ((13u << 8u) + 28):
            switch(itemIdx) {
                case 0: return "Proposal hash";
                case 1: return "Index";
                default: return NULL;
            }
        case ((14u << 8u) + 0):
            switch(itemIdx) {
                case 0: return "New members";
                case 1: return "Prime";
                default: return NULL;
            }
        case ((14u << 8u) + 1):
            switch(itemIdx) {
                case 0: return "Proposal";
                default: return NULL;
            }
        case ((14u << 8u) + 2):
            switch(itemIdx) {
                case 0: return "Threshold";
                case 1: return "Proposal";
                default: return NULL;
            }
        case ((14u << 8u) + 3):
            switch(itemIdx) {
                case 0: return "Proposal";
                case 1: return "Index";
                case 2: return "Approve";
                default: return NULL;
            }
        case ((14u << 8u) + 4):
            switch(itemIdx) {
                case 0: return "Proposal";
                case 1: return "Index";
                default: return NULL;
            }
        case ((15u << 8u) + 0):
            switch(itemIdx) {
                case 0: return "New members";
                case 1: return "Prime";
                default: return NULL;
            }
        case ((15u << 8u) + 1):
            switch(itemIdx) {
                case 0: return "Proposal";
                default: return NULL;
            }
        case ((15u << 8u) + 2):
            switch(itemIdx) {
                case 0: return "Threshold";
                case 1: return "Proposal";
                default: return NULL;
            }
        case ((15u << 8u) + 3):
            switch(itemIdx) {
                case 0: return "Proposal";
                case 1: return "Index";
                case 2: return "Approve";
                default: return NULL;
            }
        case ((15u << 8u) + 4):
            switch(itemIdx) {
                case 0: return "Proposal";
                case 1: return "Index";
                default: return NULL;
            }
        case ((16u << 8u) + 0):
            switch(itemIdx) {
                case 0: return "Votes";
                case 1: return "Value";
                default: return NULL;
            }
        case ((16u << 8u) + 1):
            switch(itemIdx) {
                default: return NULL;
            }
        case ((16u << 8u) + 2):
            switch(itemIdx) {
                case 0: return "Target";
                default: return NULL;
            }
        case ((16u << 8u) + 3):
            switch(itemIdx) {
                default: return NULL;
            }
        case ((16u << 8u) + 4):
            switch(itemIdx) {
                default: return NULL;
            }
        case ((16u << 8u) + 5):
            switch(itemIdx) {
                case 0: return "Who";
                default: return NULL;
            }
        case ((17u << 8u) + 0):
            switch(itemIdx) {
                case 0: return "Who";
                default: return NULL;
            }
        case ((17u << 8u) + 1):
            switch(itemIdx) {
                case 0: return "Who";
                default: return NULL;
            }
        case ((17u << 8u) + 2):
            switch(itemIdx) {
                case 0: return "Remove";
                case 1: return "Add";
                default: return NULL;
            }
        case ((17u << 8u) + 3):
            switch(itemIdx) {
                case 0: return "Members";
                default: return NULL;
            }
        case ((17u << 8u) + 4):
            switch(itemIdx) {
                case 0: return "New";
                default: return NULL;
            }
        case ((17u << 8u) + 5):
            switch(itemIdx) {
                case 0: return "Who";
                default: return NULL;
            }
        case ((17u << 8u) + 6):
            switch(itemIdx) {
                default: return NULL;
            }
        case ((18u << 8u) + 0):
            switch(itemIdx) {
                case 0: return "Value";
                case 1: return "Beneficiary";
                default: return NULL;
            }
        case ((18u << 8u) + 1):
            switch(itemIdx) {
                case 0: return "Proposal id";
                default: return NULL;
            }
        case ((18u << 8u) + 2):
            switch(itemIdx) {
                case 0: return "Proposal id";
                default: return NULL;
            }
        case ((18u << 8u) + 3):
            switch(itemIdx) {
                case 0: return "Reason";
                case 1: return "Who";
                default: return NULL;
            }
        case ((18u << 8u) + 4):
            switch(itemIdx) {
                case 0: return "Hash";
                default: return NULL;
            }
        case ((18u << 8u) + 5):
            switch(itemIdx) {
                case 0: return "Reason";
                case 1: return "Who";
                case 2: return "Tip value";
                default: return NULL;
            }
        case ((18u << 8u) + 6):
            switch(itemIdx) {
                case 0: return "Hash";
                case 1: return "Tip value";
                default: return NULL;
            }
        case ((18u << 8u) + 7):
            switch(itemIdx) {
                case 0: return "Hash";
                default: return NULL;
            }
        case ((19u << 8u) + 0):
            switch(itemIdx) {
                case 0: return "Dest";
                case 1: return "Ethereum signature";
                default: return NULL;
            }
        case ((19u << 8u) + 1):
            switch(itemIdx) {
                case 0: return "Who";
                case 1: return "Value";
                case 2: return "Vesting schedule";
                default: return NULL;
            }
        case ((20u << 8u) + 0):
            switch(itemIdx) {
                case 0: return "Heads";
                default: return NULL;
            }
        case ((20u << 8u) + 1):
            switch(itemIdx) {
                case 0: return "Report";
                default: return NULL;
            }
        case ((21u << 8u) + 0):
            switch(itemIdx) {
                case 0: return "More";
                default: return NULL;
            }
        case ((22u << 8u) + 0):
            switch(itemIdx) {
                case 0: return "Duration";
                case 1: return "Lease period index";
                default: return NULL;
            }
        case ((22u << 8u) + 1):
            switch(itemIdx) {
                case 0: return "Sub";
                case 1: return "Auction index";
                case 2: return "First slot";
                case 3: return "Last slot";
                case 4: return "Amount";
                default: return NULL;
            }
        case ((22u << 8u) + 2):
            switch(itemIdx) {
                case 0: return "Auction index";
                case 1: return "First slot";
                case 2: return "Last slot";
                case 3: return "Amount";
                default: return NULL;
            }
        case ((22u << 8u) + 3):
            switch(itemIdx) {
                case 0: return "Dest";
                default: return NULL;
            }
        case ((22u << 8u) + 4):
            switch(itemIdx) {
                case 0: return "Sub";
                case 1: return "Para id";
                case 2: return "Code hash";
                case 3: return "Code size";
                case 4: return "Initial head data";
                default: return NULL;
            }
        case ((22u << 8u) + 5):
            switch(itemIdx) {
                case 0: return "Para id";
                case 1: return "Code";
                default: return NULL;
            }
        case ((23u << 8u) + 0):
            switch(itemIdx) {
                case 0: return "Id";
                case 1: return "Info";
                case 2: return "Code";
                case 3: return "Initial head data";
                default: return NULL;
            }
        case ((23u << 8u) + 1):
            switch(itemIdx) {
                case 0: return "Id";
                default: return NULL;
            }
        case ((23u << 8u) + 2):
            switch(itemIdx) {
                case 0: return "Count";
                default: return NULL;
            }
        case ((23u << 8u) + 3):
            switch(itemIdx) {
                case 0: return "Code";
                case 1: return "Initial head data";
                default: return NULL;
            }
        case ((23u << 8u) + 4):
            switch(itemIdx) {
                case 0: return "Id";
                case 1: return "Collator";
                case 2: return "Head hash";
                default: return NULL;
            }
        case ((23u << 8u) + 5):
            switch(itemIdx) {
                default: return NULL;
            }
        case ((23u << 8u) + 6):
            switch(itemIdx) {
                case 0: return "Other";
                default: return NULL;
            }
        case ((24u << 8u) + 0):
            switch(itemIdx) {
                case 0: return "Calls";
                default: return NULL;
            }
        case ((24u << 8u) + 1):
            switch(itemIdx) {
                case 0: return "Index";
                case 1: return "Call";
                default: return NULL;
            }
        case ((24u << 8u) + 2):
            switch(itemIdx) {
                case 0: return "Threshold";
                case 1: return "Other signatories";
                case 2: return "Maybe timepoint";
                case 3: return "Call";
                default: return NULL;
            }
        case ((24u << 8u) + 3):
            switch(itemIdx) {
                case 0: return "Threshold";
                case 1: return "Other signatories";
                case 2: return "Maybe timepoint";
                case 3: return "Call hash";
                default: return NULL;
            }
        case ((24u << 8u) + 4):
            switch(itemIdx) {
                case 0: return "Threshold";
                case 1: return "Other signatories";
                case 2: return "Timepoint";
                case 3: return "Call hash";
                default: return NULL;
            }
        case ((25u << 8u) + 0):
            switch(itemIdx) {
                case 0: return "Account";
                default: return NULL;
            }
        case ((25u << 8u) + 1):
            switch(itemIdx) {
                case 0: return "Info";
                default: return NULL;
            }
        case ((25u << 8u) + 2):
            switch(itemIdx) {
                case 0: return "Subs";
                default: return NULL;
            }
        case ((25u << 8u) + 3):
            switch(itemIdx) {
                default: return NULL;
            }
        case ((25u << 8u) + 4):
            switch(itemIdx) {
                case 0: return "Reg index";
                case 1: return "Max fee";
                default: return NULL;
            }
        case ((25u << 8u) + 5):
            switch(itemIdx) {
                case 0: return "Reg index";
                default: return NULL;
            }
        case ((25u << 8u) + 6):
            switch(itemIdx) {
                case 0: return "Index";
                case 1: return "Fee";
                default: return NULL;
            }
        case ((25u << 8u) + 7):
            switch(itemIdx) {
                case 0: return "Index";
                case 1: return "New";
                default: return NULL;
            }
        case ((25u << 8u) + 8):
            switch(itemIdx) {
                case 0: return "Index";
                case 1: return "Fields";
                default: return NULL;
            }
        case ((25u << 8u) + 9):
            switch(itemIdx) {
                case 0: return "Reg index";
                case 1: return "Target";
                case 2: return "Judgement";
                default: return NULL;
            }
        case ((25u << 8u) + 10):
            switch(itemIdx) {
                case 0: return "Target";
                default: return NULL;
            }
        case ((26u << 8u) + 0):
            switch(itemIdx) {
                case 0: return "Value";
                default: return NULL;
            }
        case ((26u << 8u) + 1):
            switch(itemIdx) {
                case 0: return "Pos";
                default: return NULL;
            }
        case ((26u << 8u) + 2):
            switch(itemIdx) {
                case 0: return "Who";
                case 1: return "Value";
                case 2: return "Tip";
                default: return NULL;
            }
        case ((26u << 8u) + 3):
            switch(itemIdx) {
                case 0: return "Pos";
                default: return NULL;
            }
        case ((26u << 8u) + 4):
            switch(itemIdx) {
                case 0: return "Candidate";
                case 1: return "Approve";
                default: return NULL;
            }
        case ((26u << 8u) + 5):
            switch(itemIdx) {
                case 0: return "Approve";
                default: return NULL;
            }
        case ((26u << 8u) + 6):
            switch(itemIdx) {
                default: return NULL;
            }
        case ((26u << 8u) + 7):
            switch(itemIdx) {
                case 0: return "Founder";
                case 1: return "Max members";
                case 2: return "Rules";
                default: return NULL;
            }
        case ((26u << 8u) + 8):
            switch(itemIdx) {
                default: return NULL;
            }
        case ((26u << 8u) + 9):
            switch(itemIdx) {
                case 0: return "Who";
                case 1: return "Forgive";
                default: return NULL;
            }
        case ((26u << 8u) + 10):
            switch(itemIdx) {
                case 0: return "Who";
                case 1: return "Judgement";
                default: return NULL;
            }
        case ((26u << 8u) + 11):
            switch(itemIdx) {
                case 0: return "Max";
                default: return NULL;
            }
        case ((27u << 8u) + 0):
            switch(itemIdx) {
                case 0: return "Account";
                case 1: return "Call";
                default: return NULL;
            }
        case ((27u << 8u) + 1):
            switch(itemIdx) {
                case 0: return "Lost";
                case 1: return "Rescuer";
                default: return NULL;
            }
        case ((27u << 8u) + 2):
            switch(itemIdx) {
                case 0: return "Friends";
                case 1: return "Threshold";
                case 2: return "Delay period";
                default: return NULL;
            }
        case ((27u << 8u) + 3):
            switch(itemIdx) {
                case 0: return "Account";
                default: return NULL;
            }
        case ((27u << 8u) + 4):
            switch(itemIdx) {
                case 0: return "Lost";
                case 1: return "Rescuer";
                default: return NULL;
            }
        case ((27u << 8u) + 5):
            switch(itemIdx) {
                case 0: return "Account";
                default: return NULL;
            }
        case ((27u << 8u) + 6):
            switch(itemIdx) {
                case 0: return "Rescuer";
                default: return NULL;
            }
        case ((27u << 8u) + 7):
            switch(itemIdx) {
                default: return NULL;
            }
        case ((27u << 8u) + 8):
            switch(itemIdx) {
                case 0: return "Account";
                default: return NULL;
            }
        case ((28u << 8u) + 0):
            switch(itemIdx) {
                default: return NULL;
            }
        case ((28u << 8u) + 1):
            switch(itemIdx) {
                case 0: return "Target";
                default: return NULL;
            }
        case ((28u << 8u) + 2):
            switch(itemIdx) {
                case 0: return "Target";
                case 1: return "Schedule";
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
    uint16_t callPrivIdx = (moduleIdx << 8u) + callIdx;

    switch(callPrivIdx) {
        case ((0u << 8u) + 0):
        switch(itemIdx) {
            case 0: /* system_fill_block - _ratio */;
                return _toStringPerbill(
                    &m->basic.system_fill_block._ratio,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case ((0u << 8u) + 1):
        switch(itemIdx) {
            case 0: /* system_remark - _remark */;
                return _toStringBytes(
                    &m->basic.system_remark._remark,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case ((0u << 8u) + 2):
        switch(itemIdx) {
            case 0: /* system_set_heap_pages - pages */;
                return _toStringu64(
                    &m->basic.system_set_heap_pages.pages,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case ((0u << 8u) + 3):
        switch(itemIdx) {
            case 0: /* system_set_code - code */;
                return _toStringBytes(
                    &m->basic.system_set_code.code,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case ((0u << 8u) + 4):
        switch(itemIdx) {
            case 0: /* system_set_code_without_checks - code */;
                return _toStringBytes(
                    &m->basic.system_set_code_without_checks.code,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case ((0u << 8u) + 5):
        switch(itemIdx) {
            case 0: /* system_set_changes_trie_config - changes_trie_config */;
                return _toStringOptionChangesTrieConfiguration(
                    &m->basic.system_set_changes_trie_config.changes_trie_config,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case ((0u << 8u) + 6):
        switch(itemIdx) {
            case 0: /* system_set_storage - items */;
                return _toStringVecKeyValue(
                    &m->basic.system_set_storage.items,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case ((0u << 8u) + 7):
        switch(itemIdx) {
            case 0: /* system_kill_storage - keys */;
                return _toStringVecKey(
                    &m->basic.system_kill_storage.keys,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case ((0u << 8u) + 8):
        switch(itemIdx) {
            case 0: /* system_kill_prefix - prefix */;
                return _toStringKey(
                    &m->basic.system_kill_prefix.prefix,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case ((0u << 8u) + 9):
        switch(itemIdx) {
            default:
                return parser_no_data;
        }
        case ((2u << 8u) + 0):
        switch(itemIdx) {
            case 0: /* timestamp_set - now */;
                return _toStringCompactMoment(
                    &m->basic.timestamp_set.now,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case ((3u << 8u) + 0):
        switch(itemIdx) {
            case 0: /* indices_claim - index */;
                return _toStringAccountIndex(
                    &m->basic.indices_claim.index,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case ((3u << 8u) + 1):
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
        case ((3u << 8u) + 2):
        switch(itemIdx) {
            case 0: /* indices_free - index */;
                return _toStringAccountIndex(
                    &m->basic.indices_free.index,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case ((3u << 8u) + 3):
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
            default:
                return parser_no_data;
        }
        case ((4u << 8u) + 0):
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
        case ((4u << 8u) + 1):
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
        case ((4u << 8u) + 2):
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
        case ((4u << 8u) + 3):
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
        case ((5u << 8u) + 0):
        switch(itemIdx) {
            case 0: /* authorship_set_uncles - new_uncles */;
                return _toStringVecHeader(
                    &m->basic.authorship_set_uncles.new_uncles,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case ((6u << 8u) + 0):
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
        case ((6u << 8u) + 1):
        switch(itemIdx) {
            case 0: /* staking_bond_extra - max_additional */;
                return _toStringCompactBalanceOf(
                    &m->basic.staking_bond_extra.max_additional,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case ((6u << 8u) + 2):
        switch(itemIdx) {
            case 0: /* staking_unbond - value */;
                return _toStringCompactBalanceOf(
                    &m->basic.staking_unbond.value,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case ((6u << 8u) + 3):
        switch(itemIdx) {
            default:
                return parser_no_data;
        }
        case ((6u << 8u) + 4):
        switch(itemIdx) {
            case 0: /* staking_validate - prefs */;
                return _toStringValidatorPrefs(
                    &m->basic.staking_validate.prefs,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case ((6u << 8u) + 5):
        switch(itemIdx) {
            case 0: /* staking_nominate - targets */;
                return _toStringVecLookupSource(
                    &m->basic.staking_nominate.targets,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case ((6u << 8u) + 6):
        switch(itemIdx) {
            default:
                return parser_no_data;
        }
        case ((6u << 8u) + 7):
        switch(itemIdx) {
            case 0: /* staking_set_payee - payee */;
                return _toStringRewardDestination(
                    &m->basic.staking_set_payee.payee,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case ((6u << 8u) + 8):
        switch(itemIdx) {
            case 0: /* staking_set_controller - controller */;
                return _toStringLookupSource(
                    &m->basic.staking_set_controller.controller,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case ((6u << 8u) + 9):
        switch(itemIdx) {
            case 0: /* staking_set_validator_count - new_ */;
                return _toStringCompactu32(
                    &m->basic.staking_set_validator_count.new_,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case ((6u << 8u) + 10):
        switch(itemIdx) {
            default:
                return parser_no_data;
        }
        case ((6u << 8u) + 11):
        switch(itemIdx) {
            default:
                return parser_no_data;
        }
        case ((6u << 8u) + 12):
        switch(itemIdx) {
            case 0: /* staking_set_invulnerables - validators */;
                return _toStringVecAccountId(
                    &m->basic.staking_set_invulnerables.validators,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case ((6u << 8u) + 13):
        switch(itemIdx) {
            case 0: /* staking_force_unstake - stash */;
                return _toStringAccountId(
                    &m->basic.staking_force_unstake.stash,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case ((6u << 8u) + 14):
        switch(itemIdx) {
            default:
                return parser_no_data;
        }
        case ((6u << 8u) + 15):
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
        case ((6u << 8u) + 16):
        switch(itemIdx) {
            case 0: /* staking_payout_nominator - era */;
                return _toStringEraIndex(
                    &m->basic.staking_payout_nominator.era,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 1: /* staking_payout_nominator - validators */;
                return _toStringVecTupleAccountIdu32(
                    &m->basic.staking_payout_nominator.validators,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case ((6u << 8u) + 17):
        switch(itemIdx) {
            case 0: /* staking_payout_validator - era */;
                return _toStringEraIndex(
                    &m->basic.staking_payout_validator.era,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case ((6u << 8u) + 18):
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
        case ((6u << 8u) + 19):
        switch(itemIdx) {
            case 0: /* staking_rebond - value */;
                return _toStringCompactBalanceOf(
                    &m->basic.staking_rebond.value,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case ((6u << 8u) + 20):
        switch(itemIdx) {
            case 0: /* staking_set_history_depth - new_history_depth */;
                return _toStringCompactEraIndex(
                    &m->basic.staking_set_history_depth.new_history_depth,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case ((6u << 8u) + 21):
        switch(itemIdx) {
            case 0: /* staking_reap_stash - stash */;
                return _toStringAccountId(
                    &m->basic.staking_reap_stash.stash,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case ((6u << 8u) + 22):
        switch(itemIdx) {
            case 0: /* staking_submit_election_solution - winners */;
                return _toStringVecValidatorIndex(
                    &m->basic.staking_submit_election_solution.winners,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 1: /* staking_submit_election_solution - compact_assignments */;
                return _toStringCompactAssignments(
                    &m->basic.staking_submit_election_solution.compact_assignments,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 2: /* staking_submit_election_solution - score */;
                return _toStringPhragmenScore(
                    &m->basic.staking_submit_election_solution.score,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 3: /* staking_submit_election_solution - era */;
                return _toStringEraIndex(
                    &m->basic.staking_submit_election_solution.era,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case ((6u << 8u) + 23):
        switch(itemIdx) {
            case 0: /* staking_submit_election_solution_unsigned - winners */;
                return _toStringVecValidatorIndex(
                    &m->basic.staking_submit_election_solution_unsigned.winners,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 1: /* staking_submit_election_solution_unsigned - compact_assignments */;
                return _toStringCompactAssignments(
                    &m->basic.staking_submit_election_solution_unsigned.compact_assignments,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 2: /* staking_submit_election_solution_unsigned - score */;
                return _toStringPhragmenScore(
                    &m->basic.staking_submit_election_solution_unsigned.score,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 3: /* staking_submit_election_solution_unsigned - era */;
                return _toStringEraIndex(
                    &m->basic.staking_submit_election_solution_unsigned.era,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case ((8u << 8u) + 0):
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
        case ((8u << 8u) + 1):
        switch(itemIdx) {
            default:
                return parser_no_data;
        }
        case ((9u << 8u) + 0):
        switch(itemIdx) {
            case 0: /* finalitytracker_final_hint - hint */;
                return _toStringCompactBlockNumber(
                    &m->basic.finalitytracker_final_hint.hint,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case ((10u << 8u) + 0):
        switch(itemIdx) {
            case 0: /* grandpa_report_misbehavior - _report */;
                return _toStringBytes(
                    &m->basic.grandpa_report_misbehavior._report,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case ((11u << 8u) + 0):
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
        case ((13u << 8u) + 0):
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
        case ((13u << 8u) + 1):
        switch(itemIdx) {
            case 0: /* democracy_second - proposal */;
                return _toStringCompactPropIndex(
                    &m->basic.democracy_second.proposal,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case ((13u << 8u) + 2):
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
        case ((13u << 8u) + 3):
        switch(itemIdx) {
            case 0: /* democracy_proxy_vote - ref_index */;
                return _toStringCompactReferendumIndex(
                    &m->basic.democracy_proxy_vote.ref_index,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 1: /* democracy_proxy_vote - vote */;
                return _toStringAccountVote(
                    &m->basic.democracy_proxy_vote.vote,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case ((13u << 8u) + 4):
        switch(itemIdx) {
            case 0: /* democracy_emergency_cancel - ref_index */;
                return _toStringReferendumIndex(
                    &m->basic.democracy_emergency_cancel.ref_index,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case ((13u << 8u) + 5):
        switch(itemIdx) {
            case 0: /* democracy_external_propose - proposal_hash */;
                return _toStringHash(
                    &m->basic.democracy_external_propose.proposal_hash,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case ((13u << 8u) + 6):
        switch(itemIdx) {
            case 0: /* democracy_external_propose_majority - proposal_hash */;
                return _toStringHash(
                    &m->basic.democracy_external_propose_majority.proposal_hash,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case ((13u << 8u) + 7):
        switch(itemIdx) {
            case 0: /* democracy_external_propose_default - proposal_hash */;
                return _toStringHash(
                    &m->basic.democracy_external_propose_default.proposal_hash,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case ((13u << 8u) + 8):
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
        case ((13u << 8u) + 9):
        switch(itemIdx) {
            case 0: /* democracy_veto_external - proposal_hash */;
                return _toStringHash(
                    &m->basic.democracy_veto_external.proposal_hash,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case ((13u << 8u) + 10):
        switch(itemIdx) {
            case 0: /* democracy_cancel_referendum - ref_index */;
                return _toStringCompactReferendumIndex(
                    &m->basic.democracy_cancel_referendum.ref_index,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case ((13u << 8u) + 11):
        switch(itemIdx) {
            case 0: /* democracy_cancel_queued - which */;
                return _toStringReferendumIndex(
                    &m->basic.democracy_cancel_queued.which,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case ((13u << 8u) + 12):
        switch(itemIdx) {
            case 0: /* democracy_activate_proxy - proxy */;
                return _toStringAccountId(
                    &m->basic.democracy_activate_proxy.proxy,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case ((13u << 8u) + 13):
        switch(itemIdx) {
            default:
                return parser_no_data;
        }
        case ((13u << 8u) + 14):
        switch(itemIdx) {
            case 0: /* democracy_deactivate_proxy - proxy */;
                return _toStringAccountId(
                    &m->basic.democracy_deactivate_proxy.proxy,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case ((13u << 8u) + 15):
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
        case ((13u << 8u) + 16):
        switch(itemIdx) {
            default:
                return parser_no_data;
        }
        case ((13u << 8u) + 17):
        switch(itemIdx) {
            default:
                return parser_no_data;
        }
        case ((13u << 8u) + 18):
        switch(itemIdx) {
            case 0: /* democracy_note_preimage - encoded_proposal */;
                return _toStringBytes(
                    &m->basic.democracy_note_preimage.encoded_proposal,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case ((13u << 8u) + 19):
        switch(itemIdx) {
            case 0: /* democracy_note_imminent_preimage - encoded_proposal */;
                return _toStringBytes(
                    &m->basic.democracy_note_imminent_preimage.encoded_proposal,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case ((13u << 8u) + 20):
        switch(itemIdx) {
            case 0: /* democracy_reap_preimage - proposal_hash */;
                return _toStringHash(
                    &m->basic.democracy_reap_preimage.proposal_hash,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case ((13u << 8u) + 21):
        switch(itemIdx) {
            case 0: /* democracy_unlock - target */;
                return _toStringAccountId(
                    &m->basic.democracy_unlock.target,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case ((13u << 8u) + 22):
        switch(itemIdx) {
            case 0: /* democracy_open_proxy - target */;
                return _toStringAccountId(
                    &m->basic.democracy_open_proxy.target,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case ((13u << 8u) + 23):
        switch(itemIdx) {
            case 0: /* democracy_remove_vote - index */;
                return _toStringReferendumIndex(
                    &m->basic.democracy_remove_vote.index,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case ((13u << 8u) + 24):
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
        case ((13u << 8u) + 25):
        switch(itemIdx) {
            case 0: /* democracy_proxy_delegate - to */;
                return _toStringAccountId(
                    &m->basic.democracy_proxy_delegate.to,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 1: /* democracy_proxy_delegate - conviction */;
                return _toStringConviction(
                    &m->basic.democracy_proxy_delegate.conviction,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 2: /* democracy_proxy_delegate - balance */;
                return _toStringBalanceOf(
                    &m->basic.democracy_proxy_delegate.balance,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case ((13u << 8u) + 26):
        switch(itemIdx) {
            default:
                return parser_no_data;
        }
        case ((13u << 8u) + 27):
        switch(itemIdx) {
            case 0: /* democracy_proxy_remove_vote - index */;
                return _toStringReferendumIndex(
                    &m->basic.democracy_proxy_remove_vote.index,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case ((13u << 8u) + 28):
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
        case ((14u << 8u) + 0):
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
            default:
                return parser_no_data;
        }
        case ((14u << 8u) + 1):
        switch(itemIdx) {
            case 0: /* council_execute - proposal */;
                return _toStringProposal(
                    &m->nested.council_execute.proposal,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case ((14u << 8u) + 2):
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
            default:
                return parser_no_data;
        }
        case ((14u << 8u) + 3):
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
        case ((14u << 8u) + 4):
        switch(itemIdx) {
            case 0: /* council_close - proposal */;
                return _toStringHash(
                    &m->basic.council_close.proposal,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 1: /* council_close - index */;
                return _toStringCompactProposalIndex(
                    &m->basic.council_close.index,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case ((15u << 8u) + 0):
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
            default:
                return parser_no_data;
        }
        case ((15u << 8u) + 1):
        switch(itemIdx) {
            case 0: /* technicalcommittee_execute - proposal */;
                return _toStringProposal(
                    &m->nested.technicalcommittee_execute.proposal,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case ((15u << 8u) + 2):
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
            default:
                return parser_no_data;
        }
        case ((15u << 8u) + 3):
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
        case ((15u << 8u) + 4):
        switch(itemIdx) {
            case 0: /* technicalcommittee_close - proposal */;
                return _toStringHash(
                    &m->basic.technicalcommittee_close.proposal,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 1: /* technicalcommittee_close - index */;
                return _toStringCompactProposalIndex(
                    &m->basic.technicalcommittee_close.index,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case ((16u << 8u) + 0):
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
        case ((16u << 8u) + 1):
        switch(itemIdx) {
            default:
                return parser_no_data;
        }
        case ((16u << 8u) + 2):
        switch(itemIdx) {
            case 0: /* electionsphragmen_report_defunct_voter - target */;
                return _toStringLookupSource(
                    &m->basic.electionsphragmen_report_defunct_voter.target,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case ((16u << 8u) + 3):
        switch(itemIdx) {
            default:
                return parser_no_data;
        }
        case ((16u << 8u) + 4):
        switch(itemIdx) {
            default:
                return parser_no_data;
        }
        case ((16u << 8u) + 5):
        switch(itemIdx) {
            case 0: /* electionsphragmen_remove_member - who */;
                return _toStringLookupSource(
                    &m->basic.electionsphragmen_remove_member.who,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case ((17u << 8u) + 0):
        switch(itemIdx) {
            case 0: /* technicalmembership_add_member - who */;
                return _toStringAccountId(
                    &m->basic.technicalmembership_add_member.who,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case ((17u << 8u) + 1):
        switch(itemIdx) {
            case 0: /* technicalmembership_remove_member - who */;
                return _toStringAccountId(
                    &m->basic.technicalmembership_remove_member.who,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case ((17u << 8u) + 2):
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
        case ((17u << 8u) + 3):
        switch(itemIdx) {
            case 0: /* technicalmembership_reset_members - members */;
                return _toStringVecAccountId(
                    &m->basic.technicalmembership_reset_members.members,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case ((17u << 8u) + 4):
        switch(itemIdx) {
            case 0: /* technicalmembership_change_key - new_ */;
                return _toStringAccountId(
                    &m->basic.technicalmembership_change_key.new_,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case ((17u << 8u) + 5):
        switch(itemIdx) {
            case 0: /* technicalmembership_set_prime - who */;
                return _toStringAccountId(
                    &m->basic.technicalmembership_set_prime.who,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case ((17u << 8u) + 6):
        switch(itemIdx) {
            default:
                return parser_no_data;
        }
        case ((18u << 8u) + 0):
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
        case ((18u << 8u) + 1):
        switch(itemIdx) {
            case 0: /* treasury_reject_proposal - proposal_id */;
                return _toStringCompactProposalIndex(
                    &m->basic.treasury_reject_proposal.proposal_id,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case ((18u << 8u) + 2):
        switch(itemIdx) {
            case 0: /* treasury_approve_proposal - proposal_id */;
                return _toStringCompactProposalIndex(
                    &m->basic.treasury_approve_proposal.proposal_id,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case ((18u << 8u) + 3):
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
        case ((18u << 8u) + 4):
        switch(itemIdx) {
            case 0: /* treasury_retract_tip - hash */;
                return _toStringHash(
                    &m->basic.treasury_retract_tip.hash,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case ((18u << 8u) + 5):
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
        case ((18u << 8u) + 6):
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
        case ((18u << 8u) + 7):
        switch(itemIdx) {
            case 0: /* treasury_close_tip - hash */;
                return _toStringHash(
                    &m->basic.treasury_close_tip.hash,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case ((19u << 8u) + 0):
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
        case ((19u << 8u) + 1):
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
            default:
                return parser_no_data;
        }
        case ((20u << 8u) + 0):
        switch(itemIdx) {
            case 0: /* parachains_set_heads - heads */;
                return _toStringVecAttestedCandidate(
                    &m->basic.parachains_set_heads.heads,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case ((20u << 8u) + 1):
        switch(itemIdx) {
            case 0: /* parachains_report_double_vote - report */;
                return _toStringDoubleVoteReport(
                    &m->basic.parachains_report_double_vote.report,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case ((21u << 8u) + 0):
        switch(itemIdx) {
            case 0: /* attestations_more_attestations - _more */;
                return _toStringMoreAttestations(
                    &m->basic.attestations_more_attestations._more,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case ((22u << 8u) + 0):
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
        case ((22u << 8u) + 1):
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
        case ((22u << 8u) + 2):
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
        case ((22u << 8u) + 3):
        switch(itemIdx) {
            case 0: /* slots_set_offboarding - dest */;
                return _toStringLookupSource(
                    &m->basic.slots_set_offboarding.dest,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case ((22u << 8u) + 4):
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
        case ((22u << 8u) + 5):
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
        case ((23u << 8u) + 0):
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
        case ((23u << 8u) + 1):
        switch(itemIdx) {
            case 0: /* registrar_deregister_para - id */;
                return _toStringCompactParaId(
                    &m->basic.registrar_deregister_para.id,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case ((23u << 8u) + 2):
        switch(itemIdx) {
            case 0: /* registrar_set_thread_count - count */;
                return _toStringu32(
                    &m->basic.registrar_set_thread_count.count,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case ((23u << 8u) + 3):
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
        case ((23u << 8u) + 4):
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
        case ((23u << 8u) + 5):
        switch(itemIdx) {
            default:
                return parser_no_data;
        }
        case ((23u << 8u) + 6):
        switch(itemIdx) {
            case 0: /* registrar_swap - other */;
                return _toStringCompactParaId(
                    &m->basic.registrar_swap.other,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case ((24u << 8u) + 0):
        switch(itemIdx) {
            case 0: /* utility_batch - calls */;
                return _toStringVecCall(
                    &m->basic.utility_batch.calls,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case ((24u << 8u) + 1):
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
        case ((24u << 8u) + 2):
        switch(itemIdx) {
            case 0: /* utility_as_multi - threshold */;
                return _toStringu16(
                    &m->basic.utility_as_multi.threshold,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 1: /* utility_as_multi - other_signatories */;
                return _toStringVecAccountId(
                    &m->basic.utility_as_multi.other_signatories,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 2: /* utility_as_multi - maybe_timepoint */;
                return _toStringOptionTimepoint(
                    &m->basic.utility_as_multi.maybe_timepoint,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 3: /* utility_as_multi - call */;
                return _toStringCall(
                    &m->basic.utility_as_multi.call,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case ((24u << 8u) + 3):
        switch(itemIdx) {
            case 0: /* utility_approve_as_multi - threshold */;
                return _toStringu16(
                    &m->basic.utility_approve_as_multi.threshold,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 1: /* utility_approve_as_multi - other_signatories */;
                return _toStringVecAccountId(
                    &m->basic.utility_approve_as_multi.other_signatories,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 2: /* utility_approve_as_multi - maybe_timepoint */;
                return _toStringOptionTimepoint(
                    &m->basic.utility_approve_as_multi.maybe_timepoint,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 3: /* utility_approve_as_multi - call_hash */;
                return _toStringu8_array_32(
                    &m->basic.utility_approve_as_multi.call_hash,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case ((24u << 8u) + 4):
        switch(itemIdx) {
            case 0: /* utility_cancel_as_multi - threshold */;
                return _toStringu16(
                    &m->basic.utility_cancel_as_multi.threshold,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 1: /* utility_cancel_as_multi - other_signatories */;
                return _toStringVecAccountId(
                    &m->basic.utility_cancel_as_multi.other_signatories,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 2: /* utility_cancel_as_multi - timepoint */;
                return _toStringTimepoint(
                    &m->basic.utility_cancel_as_multi.timepoint,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            case 3: /* utility_cancel_as_multi - call_hash */;
                return _toStringu8_array_32(
                    &m->basic.utility_cancel_as_multi.call_hash,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case ((25u << 8u) + 0):
        switch(itemIdx) {
            case 0: /* identity_add_registrar - account */;
                return _toStringAccountId(
                    &m->basic.identity_add_registrar.account,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case ((25u << 8u) + 1):
        switch(itemIdx) {
            case 0: /* identity_set_identity - info */;
                return _toStringIdentityInfo(
                    &m->basic.identity_set_identity.info,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case ((25u << 8u) + 2):
        switch(itemIdx) {
            case 0: /* identity_set_subs - subs */;
                return _toStringVecTupleAccountIdData(
                    &m->basic.identity_set_subs.subs,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case ((25u << 8u) + 3):
        switch(itemIdx) {
            default:
                return parser_no_data;
        }
        case ((25u << 8u) + 4):
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
        case ((25u << 8u) + 5):
        switch(itemIdx) {
            case 0: /* identity_cancel_request - reg_index */;
                return _toStringRegistrarIndex(
                    &m->basic.identity_cancel_request.reg_index,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case ((25u << 8u) + 6):
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
        case ((25u << 8u) + 7):
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
        case ((25u << 8u) + 8):
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
        case ((25u << 8u) + 9):
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
        case ((25u << 8u) + 10):
        switch(itemIdx) {
            case 0: /* identity_kill_identity - target */;
                return _toStringLookupSource(
                    &m->basic.identity_kill_identity.target,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case ((26u << 8u) + 0):
        switch(itemIdx) {
            case 0: /* society_bid - value */;
                return _toStringBalanceOf(
                    &m->basic.society_bid.value,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case ((26u << 8u) + 1):
        switch(itemIdx) {
            case 0: /* society_unbid - pos */;
                return _toStringu32(
                    &m->basic.society_unbid.pos,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case ((26u << 8u) + 2):
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
        case ((26u << 8u) + 3):
        switch(itemIdx) {
            case 0: /* society_unvouch - pos */;
                return _toStringu32(
                    &m->basic.society_unvouch.pos,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case ((26u << 8u) + 4):
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
        case ((26u << 8u) + 5):
        switch(itemIdx) {
            case 0: /* society_defender_vote - approve */;
                return _toStringbool(
                    &m->basic.society_defender_vote.approve,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case ((26u << 8u) + 6):
        switch(itemIdx) {
            default:
                return parser_no_data;
        }
        case ((26u << 8u) + 7):
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
        case ((26u << 8u) + 8):
        switch(itemIdx) {
            default:
                return parser_no_data;
        }
        case ((26u << 8u) + 9):
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
        case ((26u << 8u) + 10):
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
        case ((26u << 8u) + 11):
        switch(itemIdx) {
            case 0: /* society_set_max_members - max */;
                return _toStringu32(
                    &m->basic.society_set_max_members.max,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case ((27u << 8u) + 0):
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
        case ((27u << 8u) + 1):
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
        case ((27u << 8u) + 2):
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
        case ((27u << 8u) + 3):
        switch(itemIdx) {
            case 0: /* recovery_initiate_recovery - account */;
                return _toStringAccountId(
                    &m->basic.recovery_initiate_recovery.account,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case ((27u << 8u) + 4):
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
        case ((27u << 8u) + 5):
        switch(itemIdx) {
            case 0: /* recovery_claim_recovery - account */;
                return _toStringAccountId(
                    &m->basic.recovery_claim_recovery.account,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case ((27u << 8u) + 6):
        switch(itemIdx) {
            case 0: /* recovery_close_recovery - rescuer */;
                return _toStringAccountId(
                    &m->basic.recovery_close_recovery.rescuer,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case ((27u << 8u) + 7):
        switch(itemIdx) {
            default:
                return parser_no_data;
        }
        case ((27u << 8u) + 8):
        switch(itemIdx) {
            case 0: /* recovery_cancel_recovered - account */;
                return _toStringAccountId(
                    &m->basic.recovery_cancel_recovered.account,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case ((28u << 8u) + 0):
        switch(itemIdx) {
            default:
                return parser_no_data;
        }
        case ((28u << 8u) + 1):
        switch(itemIdx) {
            case 0: /* vesting_vest_other - target */;
                return _toStringLookupSource(
                    &m->basic.vesting_vest_other.target,
                    outValue, outValueLen,
                    pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case ((28u << 8u) + 2):
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
    default:
    return parser_ok;
    }

    return parser_ok;
}
