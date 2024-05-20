/*******************************************************************************
 *  (c) 2019 - 2024 Zondax AG
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

#include "substrate_dispatch_V7.h"
#include "substrate_strings.h"
#include "zxmacros.h"
#include <stdint.h>
#ifdef LEDGER_SPECIFIC
#include "bolos_target.h"
#endif

__Z_INLINE parser_error_t _readMethod_balances_transfer_allow_death_V7(
    parser_context_t* c, pd_balances_transfer_allow_death_V7_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_force_transfer_V7(
    parser_context_t* c, pd_balances_force_transfer_V7_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->source))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_transfer_keep_alive_V7(
    parser_context_t* c, pd_balances_transfer_keep_alive_V7_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_transfer_all_V7(
    parser_context_t* c, pd_balances_transfer_all_V7_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->dest))
    CHECK_ERROR(_readbool(c, &m->keep_alive))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_bond_V7(
    parser_context_t* c, pd_staking_bond_V7_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    CHECK_ERROR(_readRewardDestination(c, &m->payee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_bond_extra_V7(
    parser_context_t* c, pd_staking_bond_extra_V7_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_unbond_V7(
    parser_context_t* c, pd_staking_unbond_V7_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_withdraw_unbonded_V7(
    parser_context_t* c, pd_staking_withdraw_unbonded_V7_t* m)
{
    CHECK_ERROR(_readu32(c, &m->num_slashing_spans))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_validate_V7(
    parser_context_t* c, pd_staking_validate_V7_t* m)
{
    CHECK_ERROR(_readValidatorPrefs(c, &m->prefs))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_nominate_V7(
    parser_context_t* c, pd_staking_nominate_V7_t* m)
{
    CHECK_ERROR(_readVecAccountIdLookupOfT(c, &m->targets))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_chill_V7(
    parser_context_t* c, pd_staking_chill_V7_t* m)
{
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_payee_V7(
    parser_context_t* c, pd_staking_set_payee_V7_t* m)
{
    CHECK_ERROR(_readRewardDestination(c, &m->payee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_controller_V7(
    parser_context_t* c, pd_staking_set_controller_V7_t* m)
{
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_payout_stakers_V7(
    parser_context_t* c, pd_staking_payout_stakers_V7_t* m)
{
    CHECK_ERROR(_readAccountId(c, &m->validator_stash))
    CHECK_ERROR(_readEraIndex(c, &m->era))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_rebond_V7(
    parser_context_t* c, pd_staking_rebond_V7_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_session_set_keys_V7(
    parser_context_t* c, pd_session_set_keys_V7_t* m)
{
    CHECK_ERROR(_readKeys(c, &m->keys))
    CHECK_ERROR(_readBytes(c, &m->proof))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_session_purge_keys_V7(
    parser_context_t* c, pd_session_purge_keys_V7_t* m)
{
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_batch_V7(
    parser_context_t* c, pd_utility_batch_V7_t* m)
{
    CHECK_ERROR(_readVecCall(c, &m->calls))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_batch_all_V7(
    parser_context_t* c, pd_utility_batch_all_V7_t* m)
{
    CHECK_ERROR(_readVecCall(c, &m->calls))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_force_batch_V7(
    parser_context_t* c, pd_utility_force_batch_V7_t* m)
{
    CHECK_ERROR(_readVecCall(c, &m->calls))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_crowdloan_create_V7(
    parser_context_t* c, pd_crowdloan_create_V7_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->index))
    CHECK_ERROR(_readCompactu128(c, &m->cap))
    CHECK_ERROR(_readCompactu32(c, &m->first_period))
    CHECK_ERROR(_readCompactu32(c, &m->last_period))
    CHECK_ERROR(_readCompactu32(c, &m->end))
    CHECK_ERROR(_readOptionMultiSigner(c, &m->verifier))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_crowdloan_contribute_V7(
    parser_context_t* c, pd_crowdloan_contribute_V7_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->index))
    CHECK_ERROR(_readCompactu128(c, &m->amount))
    CHECK_ERROR(_readOptionMultiSignature(c, &m->signature))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_crowdloan_withdraw_V7(
    parser_context_t* c, pd_crowdloan_withdraw_V7_t* m)
{
    CHECK_ERROR(_readAccountId(c, &m->who))
    CHECK_ERROR(_readCompactu32(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_crowdloan_refund_V7(
    parser_context_t* c, pd_crowdloan_refund_V7_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_crowdloan_dissolve_V7(
    parser_context_t* c, pd_crowdloan_dissolve_V7_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_crowdloan_edit_V7(
    parser_context_t* c, pd_crowdloan_edit_V7_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->index))
    CHECK_ERROR(_readCompactu128(c, &m->cap))
    CHECK_ERROR(_readCompactu32(c, &m->first_period))
    CHECK_ERROR(_readCompactu32(c, &m->last_period))
    CHECK_ERROR(_readCompactu32(c, &m->end))
    CHECK_ERROR(_readOptionMultiSigner(c, &m->verifier))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_crowdloan_add_memo_V7(
    parser_context_t* c, pd_crowdloan_add_memo_V7_t* m)
{
    CHECK_ERROR(_readParaId(c, &m->index))
    CHECK_ERROR(_readVecu8(c, &m->memo))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_crowdloan_poke_V7(
    parser_context_t* c, pd_crowdloan_poke_V7_t* m)
{
    CHECK_ERROR(_readParaId(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_crowdloan_contribute_all_V7(
    parser_context_t* c, pd_crowdloan_contribute_all_V7_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->index))
    CHECK_ERROR(_readOptionMultiSignature(c, &m->signature))
    return parser_ok;
}

#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
__Z_INLINE parser_error_t _readMethod_xcmpallet_teleport_assets_V7(
    parser_context_t* c, pd_xcmpallet_teleport_assets_V7_t* m)
{
    CHECK_ERROR(_readBoxVersionedMultiLocation(c, &m->dest))
    CHECK_ERROR(_readBoxVersionedMultiLocation(c, &m->beneficiary))
    CHECK_ERROR(_readBoxVersionedMultiAssets(c, &m->assets))
    CHECK_ERROR(_readu32(c, &m->fee_asset_item))
    return parser_ok;
}
__Z_INLINE parser_error_t _readMethod_xcmpallet_reserve_transfer_assets_V7(
    parser_context_t* c, pd_xcmpallet_reserve_transfer_assets_V7_t* m)
{
    CHECK_ERROR(_readBoxVersionedMultiLocation(c, &m->dest))
    CHECK_ERROR(_readBoxVersionedMultiLocation(c, &m->beneficiary))
    CHECK_ERROR(_readBoxVersionedMultiAssets(c, &m->assets))
    CHECK_ERROR(_readu32(c, &m->fee_asset_item))
    return parser_ok;
}
__Z_INLINE parser_error_t _readMethod_xcmpallet_limited_reserve_transfer_assets_V7(
    parser_context_t* c, pd_xcmpallet_limited_reserve_transfer_assets_V7_t* m)
{
    CHECK_ERROR(_readBoxVersionedMultiLocation(c, &m->dest))
    CHECK_ERROR(_readBoxVersionedMultiLocation(c, &m->beneficiary))
    CHECK_ERROR(_readBoxVersionedMultiAssets(c, &m->assets))
    CHECK_ERROR(_readu32(c, &m->fee_asset_item))
    CHECK_ERROR(_readWeightLimit(c, &m->weight_limit))
    return parser_ok;
}
__Z_INLINE parser_error_t _readMethod_xcmpallet_limited_teleport_assets_V7(
    parser_context_t* c, pd_xcmpallet_limited_teleport_assets_V7_t* m)
{
    CHECK_ERROR(_readBoxVersionedMultiLocation(c, &m->dest))
    CHECK_ERROR(_readBoxVersionedMultiLocation(c, &m->beneficiary))
    CHECK_ERROR(_readBoxVersionedMultiAssets(c, &m->assets))
    CHECK_ERROR(_readu32(c, &m->fee_asset_item))
    CHECK_ERROR(_readWeightLimit(c, &m->weight_limit))
    return parser_ok;
}
#endif
__Z_INLINE parser_error_t _readMethod_system_remark_V7(
    parser_context_t* c, pd_system_remark_V7_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->remark))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_heap_pages_V7(
    parser_context_t* c, pd_system_set_heap_pages_V7_t* m)
{
    CHECK_ERROR(_readu64(c, &m->pages))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_code_V7(
    parser_context_t* c, pd_system_set_code_V7_t* m)
{
    CHECK_ERROR(_readVecu8(c, &m->code))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_code_without_checks_V7(
    parser_context_t* c, pd_system_set_code_without_checks_V7_t* m)
{
    CHECK_ERROR(_readVecu8(c, &m->code))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_remark_with_event_V7(
    parser_context_t* c, pd_system_remark_with_event_V7_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->remark))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_preimage_note_preimage_V7(
    parser_context_t* c, pd_preimage_note_preimage_V7_t* m)
{
    CHECK_ERROR(_readVecu8(c, &m->bytes))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_preimage_unnote_preimage_V7(
    parser_context_t* c, pd_preimage_unnote_preimage_V7_t* m)
{
    CHECK_ERROR(_readHash(c, &m->hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_preimage_request_preimage_V7(
    parser_context_t* c, pd_preimage_request_preimage_V7_t* m)
{
    CHECK_ERROR(_readHash(c, &m->hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_preimage_unrequest_preimage_V7(
    parser_context_t* c, pd_preimage_unrequest_preimage_V7_t* m)
{
    CHECK_ERROR(_readHash(c, &m->hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_preimage_ensure_updated_V7(
    parser_context_t* c, pd_preimage_ensure_updated_V7_t* m)
{
    CHECK_ERROR(_readVecHash(c, &m->hashes))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_timestamp_set_V7(
    parser_context_t* c, pd_timestamp_set_V7_t* m)
{
    CHECK_ERROR(_readCompactu64(c, &m->now))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_force_unreserve_V7(
    parser_context_t* c, pd_balances_force_unreserve_V7_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->who))
    CHECK_ERROR(_readBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_upgrade_accounts_V7(
    parser_context_t* c, pd_balances_upgrade_accounts_V7_t* m)
{
    CHECK_ERROR(_readVecAccountId(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_force_set_balance_V7(
    parser_context_t* c, pd_balances_force_set_balance_V7_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->who))
    CHECK_ERROR(_readCompactBalance(c, &m->new_free))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_validator_count_V7(
    parser_context_t* c, pd_staking_set_validator_count_V7_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_increase_validator_count_V7(
    parser_context_t* c, pd_staking_increase_validator_count_V7_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->additional))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_scale_validator_count_V7(
    parser_context_t* c, pd_staking_scale_validator_count_V7_t* m)
{
    CHECK_ERROR(_readPercent(c, &m->factor))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_no_eras_V7(
    parser_context_t* c, pd_staking_force_no_eras_V7_t* m)
{
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_new_era_V7(
    parser_context_t* c, pd_staking_force_new_era_V7_t* m)
{
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_invulnerables_V7(
    parser_context_t* c, pd_staking_set_invulnerables_V7_t* m)
{
    CHECK_ERROR(_readVecAccountId(c, &m->invulnerables))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_unstake_V7(
    parser_context_t* c, pd_staking_force_unstake_V7_t* m)
{
    CHECK_ERROR(_readAccountId(c, &m->stash))
    CHECK_ERROR(_readu32(c, &m->num_slashing_spans))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_new_era_always_V7(
    parser_context_t* c, pd_staking_force_new_era_always_V7_t* m)
{
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_cancel_deferred_slash_V7(
    parser_context_t* c, pd_staking_cancel_deferred_slash_V7_t* m)
{
    CHECK_ERROR(_readEraIndex(c, &m->era))
    CHECK_ERROR(_readVecu32(c, &m->slash_indices))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_reap_stash_V7(
    parser_context_t* c, pd_staking_reap_stash_V7_t* m)
{
    CHECK_ERROR(_readAccountId(c, &m->stash))
    CHECK_ERROR(_readu32(c, &m->num_slashing_spans))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_kick_V7(
    parser_context_t* c, pd_staking_kick_V7_t* m)
{
    CHECK_ERROR(_readVecAccountIdLookupOfT(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_staking_configs_V7(
    parser_context_t* c, pd_staking_set_staking_configs_V7_t* m)
{
    CHECK_ERROR(_readConfigOpBalanceOfT(c, &m->min_nominator_bond))
    CHECK_ERROR(_readConfigOpBalanceOfT(c, &m->min_validator_bond))
    CHECK_ERROR(_readConfigOpu32(c, &m->max_nominator_count))
    CHECK_ERROR(_readConfigOpu32(c, &m->max_validator_count))
    CHECK_ERROR(_readConfigOpPercent(c, &m->chill_threshold))
    CHECK_ERROR(_readConfigOpPerbill(c, &m->min_commission))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_chill_other_V7(
    parser_context_t* c, pd_staking_chill_other_V7_t* m)
{
    CHECK_ERROR(_readAccountId(c, &m->controller))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_apply_min_commission_V7(
    parser_context_t* c, pd_staking_force_apply_min_commission_V7_t* m)
{
    CHECK_ERROR(_readAccountId(c, &m->validator_stash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_min_commission_V7(
    parser_context_t* c, pd_staking_set_min_commission_V7_t* m)
{
    CHECK_ERROR(_readPerbill(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_propose_spend_V7(
    parser_context_t* c, pd_treasury_propose_spend_V7_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->beneficiary))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_reject_proposal_V7(
    parser_context_t* c, pd_treasury_reject_proposal_V7_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->proposal_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_approve_proposal_V7(
    parser_context_t* c, pd_treasury_approve_proposal_V7_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->proposal_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_spend_local_V7(
    parser_context_t* c, pd_treasury_spend_local_V7_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->beneficiary))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_remove_approval_V7(
    parser_context_t* c, pd_treasury_remove_approval_V7_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->proposal_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_payout_V7(
    parser_context_t* c, pd_treasury_payout_V7_t* m)
{
    CHECK_ERROR(_readSpendIndex(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_check_status_V7(
    parser_context_t* c, pd_treasury_check_status_V7_t* m)
{
    CHECK_ERROR(_readSpendIndex(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_void_spend_V7(
    parser_context_t* c, pd_treasury_void_spend_V7_t* m)
{
    CHECK_ERROR(_readSpendIndex(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_convictionvoting_vote_V7(
    parser_context_t* c, pd_convictionvoting_vote_V7_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->poll_index))
    CHECK_ERROR(_readAccountVote(c, &m->vote))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_convictionvoting_delegate_V7(
    parser_context_t* c, pd_convictionvoting_delegate_V7_t* m)
{
    CHECK_ERROR(_readClassOf(c, &m->class_))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->to))
    CHECK_ERROR(_readConviction(c, &m->conviction))
    CHECK_ERROR(_readBalanceOf(c, &m->balance))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_convictionvoting_undelegate_V7(
    parser_context_t* c, pd_convictionvoting_undelegate_V7_t* m)
{
    CHECK_ERROR(_readClassOf(c, &m->class_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_convictionvoting_unlock_V7(
    parser_context_t* c, pd_convictionvoting_unlock_V7_t* m)
{
    CHECK_ERROR(_readClassOf(c, &m->class_))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->target))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_convictionvoting_remove_vote_V7(
    parser_context_t* c, pd_convictionvoting_remove_vote_V7_t* m)
{
    CHECK_ERROR(_readOptionClassOf(c, &m->class_))
    CHECK_ERROR(_readPollIndexOf(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_convictionvoting_remove_other_vote_V7(
    parser_context_t* c, pd_convictionvoting_remove_other_vote_V7_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->target))
    CHECK_ERROR(_readClassOf(c, &m->class_))
    CHECK_ERROR(_readPollIndexOf(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_referenda_submit_V7(
    parser_context_t* c, pd_referenda_submit_V7_t* m)
{
    CHECK_ERROR(_readBoxPalletsOrigin(c, &m->proposal_origin))
    CHECK_ERROR(_readBoundedCallOfT(c, &m->proposal))
    CHECK_ERROR(_readDispatchTimeBlockNumber(c, &m->enactment_moment))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_referenda_place_decision_deposit_V7(
    parser_context_t* c, pd_referenda_place_decision_deposit_V7_t* m)
{
    CHECK_ERROR(_readReferendumIndex(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_referenda_refund_decision_deposit_V7(
    parser_context_t* c, pd_referenda_refund_decision_deposit_V7_t* m)
{
    CHECK_ERROR(_readReferendumIndex(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_referenda_cancel_V7(
    parser_context_t* c, pd_referenda_cancel_V7_t* m)
{
    CHECK_ERROR(_readReferendumIndex(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_referenda_kill_V7(
    parser_context_t* c, pd_referenda_kill_V7_t* m)
{
    CHECK_ERROR(_readReferendumIndex(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_referenda_nudge_referendum_V7(
    parser_context_t* c, pd_referenda_nudge_referendum_V7_t* m)
{
    CHECK_ERROR(_readReferendumIndex(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_referenda_one_fewer_deciding_V7(
    parser_context_t* c, pd_referenda_one_fewer_deciding_V7_t* m)
{
    CHECK_ERROR(_readTrackIdOf(c, &m->track))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_referenda_refund_submission_deposit_V7(
    parser_context_t* c, pd_referenda_refund_submission_deposit_V7_t* m)
{
    CHECK_ERROR(_readReferendumIndex(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_referenda_set_metadata_V7(
    parser_context_t* c, pd_referenda_set_metadata_V7_t* m)
{
    CHECK_ERROR(_readReferendumIndex(c, &m->index))
    CHECK_ERROR(_readOptionHash(c, &m->maybe_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_whitelist_whitelist_call_V7(
    parser_context_t* c, pd_whitelist_whitelist_call_V7_t* m)
{
    CHECK_ERROR(_readHash(c, &m->call_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_whitelist_remove_whitelisted_call_V7(
    parser_context_t* c, pd_whitelist_remove_whitelisted_call_V7_t* m)
{
    CHECK_ERROR(_readHash(c, &m->call_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_whitelist_dispatch_whitelisted_call_V7(
    parser_context_t* c, pd_whitelist_dispatch_whitelisted_call_V7_t* m)
{
    CHECK_ERROR(_readHash(c, &m->call_hash))
    CHECK_ERROR(_readu32(c, &m->call_encoded_len))
    CHECK_ERROR(_readWeight(c, &m->call_weight_witness))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_whitelist_dispatch_whitelisted_call_with_preimage_V7(
    parser_context_t* c, pd_whitelist_dispatch_whitelisted_call_with_preimage_V7_t* m)
{
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_dispatch_as_V7(
    parser_context_t* c, pd_utility_dispatch_as_V7_t* m)
{
    CHECK_ERROR(_readBoxPalletsOrigin(c, &m->as_origin))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_with_weight_V7(
    parser_context_t* c, pd_utility_with_weight_V7_t* m)
{
    CHECK_ERROR(_readCall(c, &m->call))
    CHECK_ERROR(_readWeight(c, &m->weight))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_add_registrar_V7(
    parser_context_t* c, pd_identity_add_registrar_V7_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->account))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_set_identity_V7(
    parser_context_t* c, pd_identity_set_identity_V7_t* m)
{
    CHECK_ERROR(_readIdentityInfo(c, &m->info))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_set_subs_V7(
    parser_context_t* c, pd_identity_set_subs_V7_t* m)
{
    CHECK_ERROR(_readVecTupleAccountIdData(c, &m->subs))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_clear_identity_V7(
    parser_context_t* c, pd_identity_clear_identity_V7_t* m)
{
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_request_judgement_V7(
    parser_context_t* c, pd_identity_request_judgement_V7_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->reg_index))
    CHECK_ERROR(_readCompactu128(c, &m->max_fee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_cancel_request_V7(
    parser_context_t* c, pd_identity_cancel_request_V7_t* m)
{
    CHECK_ERROR(_readRegistrarIndex(c, &m->reg_index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_set_fee_V7(
    parser_context_t* c, pd_identity_set_fee_V7_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->index))
    CHECK_ERROR(_readCompactu128(c, &m->fee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_set_account_id_V7(
    parser_context_t* c, pd_identity_set_account_id_V7_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->index))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_provide_judgement_V7(
    parser_context_t* c, pd_identity_provide_judgement_V7_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->reg_index))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->target))
    CHECK_ERROR(_readJudgementBalanceOfT(c, &m->judgement))
    CHECK_ERROR(_readHash(c, &m->identity))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_kill_identity_V7(
    parser_context_t* c, pd_identity_kill_identity_V7_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->target))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_add_sub_V7(
    parser_context_t* c, pd_identity_add_sub_V7_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->sub))
    CHECK_ERROR(_readData(c, &m->data))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_rename_sub_V7(
    parser_context_t* c, pd_identity_rename_sub_V7_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->sub))
    CHECK_ERROR(_readData(c, &m->data))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_remove_sub_V7(
    parser_context_t* c, pd_identity_remove_sub_V7_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->sub))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_quit_sub_V7(
    parser_context_t* c, pd_identity_quit_sub_V7_t* m)
{
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_proxy_V7(
    parser_context_t* c, pd_proxy_proxy_V7_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->real))
    CHECK_ERROR(_readOptionProxyType(c, &m->force_proxy_type))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_add_proxy_V7(
    parser_context_t* c, pd_proxy_add_proxy_V7_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->delegate))
    CHECK_ERROR(_readProxyType(c, &m->proxy_type))
    CHECK_ERROR(_readBlockNumber(c, &m->delay))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_remove_proxy_V7(
    parser_context_t* c, pd_proxy_remove_proxy_V7_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->delegate))
    CHECK_ERROR(_readProxyType(c, &m->proxy_type))
    CHECK_ERROR(_readBlockNumber(c, &m->delay))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_remove_proxies_V7(
    parser_context_t* c, pd_proxy_remove_proxies_V7_t* m)
{
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_create_pure_V7(
    parser_context_t* c, pd_proxy_create_pure_V7_t* m)
{
    CHECK_ERROR(_readProxyType(c, &m->proxy_type))
    CHECK_ERROR(_readBlockNumber(c, &m->delay))
    CHECK_ERROR(_readu16(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_kill_pure_V7(
    parser_context_t* c, pd_proxy_kill_pure_V7_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->spawner))
    CHECK_ERROR(_readProxyType(c, &m->proxy_type))
    CHECK_ERROR(_readu16(c, &m->index))
    CHECK_ERROR(_readCompactu32(c, &m->height))
    CHECK_ERROR(_readCompactu32(c, &m->ext_index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_proxy_announced_V7(
    parser_context_t* c, pd_proxy_proxy_announced_V7_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->delegate))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->real))
    CHECK_ERROR(_readOptionProxyType(c, &m->force_proxy_type))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_as_multi_threshold_1_V7(
    parser_context_t* c, pd_multisig_as_multi_threshold_1_V7_t* m)
{
    CHECK_ERROR(_readVecAccountId(c, &m->other_signatories))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_as_multi_V7(
    parser_context_t* c, pd_multisig_as_multi_V7_t* m)
{
    CHECK_ERROR(_readu16(c, &m->threshold))
    CHECK_ERROR(_readVecAccountId(c, &m->other_signatories))
    CHECK_ERROR(_readOptionTimepoint(c, &m->maybe_timepoint))
    CHECK_ERROR(_readCall(c, &m->call))
    CHECK_ERROR(_readWeight(c, &m->max_weight))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_approve_as_multi_V7(
    parser_context_t* c, pd_multisig_approve_as_multi_V7_t* m)
{
    CHECK_ERROR(_readu16(c, &m->threshold))
    CHECK_ERROR(_readVecAccountId(c, &m->other_signatories))
    CHECK_ERROR(_readOptionTimepoint(c, &m->maybe_timepoint))
    CHECK_ERROR(_readH256(c, &m->call_hash))
    CHECK_ERROR(_readWeight(c, &m->max_weight))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_cancel_as_multi_V7(
    parser_context_t* c, pd_multisig_cancel_as_multi_V7_t* m)
{
    CHECK_ERROR(_readu16(c, &m->threshold))
    CHECK_ERROR(_readVecAccountId(c, &m->other_signatories))
    CHECK_ERROR(_readTimepoint(c, &m->timepoint))
    CHECK_ERROR(_readH256(c, &m->call_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_voterlist_rebag_V7(
    parser_context_t* c, pd_voterlist_rebag_V7_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->dislocated))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_voterlist_put_in_front_of_V7(
    parser_context_t* c, pd_voterlist_put_in_front_of_V7_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->lighter))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_voterlist_put_in_front_of_other_V7(
    parser_context_t* c, pd_voterlist_put_in_front_of_other_V7_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->heavier))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->lighter))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_validation_upgrade_cooldown_V7(
    parser_context_t* c, pd_configuration_set_validation_upgrade_cooldown_V7_t* m)
{
    CHECK_ERROR(_readBlockNumber(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_validation_upgrade_delay_V7(
    parser_context_t* c, pd_configuration_set_validation_upgrade_delay_V7_t* m)
{
    CHECK_ERROR(_readBlockNumber(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_code_retention_period_V7(
    parser_context_t* c, pd_configuration_set_code_retention_period_V7_t* m)
{
    CHECK_ERROR(_readBlockNumber(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_max_code_size_V7(
    parser_context_t* c, pd_configuration_set_max_code_size_V7_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_max_pov_size_V7(
    parser_context_t* c, pd_configuration_set_max_pov_size_V7_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_max_head_data_size_V7(
    parser_context_t* c, pd_configuration_set_max_head_data_size_V7_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_on_demand_cores_V7(
    parser_context_t* c, pd_configuration_set_on_demand_cores_V7_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_on_demand_retries_V7(
    parser_context_t* c, pd_configuration_set_on_demand_retries_V7_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_group_rotation_frequency_V7(
    parser_context_t* c, pd_configuration_set_group_rotation_frequency_V7_t* m)
{
    CHECK_ERROR(_readBlockNumber(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_paras_availability_period_V7(
    parser_context_t* c, pd_configuration_set_paras_availability_period_V7_t* m)
{
    CHECK_ERROR(_readBlockNumber(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_scheduling_lookahead_V7(
    parser_context_t* c, pd_configuration_set_scheduling_lookahead_V7_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_max_validators_per_core_V7(
    parser_context_t* c, pd_configuration_set_max_validators_per_core_V7_t* m)
{
    CHECK_ERROR(_readOptionu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_max_validators_V7(
    parser_context_t* c, pd_configuration_set_max_validators_V7_t* m)
{
    CHECK_ERROR(_readOptionu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_dispute_post_conclusion_acceptance_period_V7(
    parser_context_t* c, pd_configuration_set_dispute_post_conclusion_acceptance_period_V7_t* m)
{
    CHECK_ERROR(_readBlockNumber(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_no_show_slots_V7(
    parser_context_t* c, pd_configuration_set_no_show_slots_V7_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_n_delay_tranches_V7(
    parser_context_t* c, pd_configuration_set_n_delay_tranches_V7_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_zeroth_delay_tranche_width_V7(
    parser_context_t* c, pd_configuration_set_zeroth_delay_tranche_width_V7_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_needed_approvals_V7(
    parser_context_t* c, pd_configuration_set_needed_approvals_V7_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_relay_vrf_modulo_samples_V7(
    parser_context_t* c, pd_configuration_set_relay_vrf_modulo_samples_V7_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_max_upward_queue_count_V7(
    parser_context_t* c, pd_configuration_set_max_upward_queue_count_V7_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_max_upward_queue_size_V7(
    parser_context_t* c, pd_configuration_set_max_upward_queue_size_V7_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_max_downward_message_size_V7(
    parser_context_t* c, pd_configuration_set_max_downward_message_size_V7_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_max_upward_message_size_V7(
    parser_context_t* c, pd_configuration_set_max_upward_message_size_V7_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_max_upward_message_num_per_candidate_V7(
    parser_context_t* c, pd_configuration_set_max_upward_message_num_per_candidate_V7_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_hrmp_open_request_ttl_V7(
    parser_context_t* c, pd_configuration_set_hrmp_open_request_ttl_V7_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_hrmp_sender_deposit_V7(
    parser_context_t* c, pd_configuration_set_hrmp_sender_deposit_V7_t* m)
{
    CHECK_ERROR(_readBalance(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_hrmp_recipient_deposit_V7(
    parser_context_t* c, pd_configuration_set_hrmp_recipient_deposit_V7_t* m)
{
    CHECK_ERROR(_readBalance(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_hrmp_channel_max_capacity_V7(
    parser_context_t* c, pd_configuration_set_hrmp_channel_max_capacity_V7_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_hrmp_channel_max_total_size_V7(
    parser_context_t* c, pd_configuration_set_hrmp_channel_max_total_size_V7_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_hrmp_max_parachain_inbound_channels_V7(
    parser_context_t* c, pd_configuration_set_hrmp_max_parachain_inbound_channels_V7_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_hrmp_channel_max_message_size_V7(
    parser_context_t* c, pd_configuration_set_hrmp_channel_max_message_size_V7_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_hrmp_max_parachain_outbound_channels_V7(
    parser_context_t* c, pd_configuration_set_hrmp_max_parachain_outbound_channels_V7_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_hrmp_max_message_num_per_candidate_V7(
    parser_context_t* c, pd_configuration_set_hrmp_max_message_num_per_candidate_V7_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_pvf_voting_ttl_V7(
    parser_context_t* c, pd_configuration_set_pvf_voting_ttl_V7_t* m)
{
    CHECK_ERROR(_readSessionIndex(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_minimum_validation_upgrade_delay_V7(
    parser_context_t* c, pd_configuration_set_minimum_validation_upgrade_delay_V7_t* m)
{
    CHECK_ERROR(_readBlockNumber(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_bypass_consistency_check_V7(
    parser_context_t* c, pd_configuration_set_bypass_consistency_check_V7_t* m)
{
    CHECK_ERROR(_readbool(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_on_demand_base_fee_V7(
    parser_context_t* c, pd_configuration_set_on_demand_base_fee_V7_t* m)
{
    CHECK_ERROR(_readBalance(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_on_demand_fee_variability_V7(
    parser_context_t* c, pd_configuration_set_on_demand_fee_variability_V7_t* m)
{
    CHECK_ERROR(_readPerbill(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_on_demand_queue_max_size_V7(
    parser_context_t* c, pd_configuration_set_on_demand_queue_max_size_V7_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_on_demand_target_queue_utilization_V7(
    parser_context_t* c, pd_configuration_set_on_demand_target_queue_utilization_V7_t* m)
{
    CHECK_ERROR(_readPerbill(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_on_demand_ttl_V7(
    parser_context_t* c, pd_configuration_set_on_demand_ttl_V7_t* m)
{
    CHECK_ERROR(_readBlockNumber(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_minimum_backing_votes_V7(
    parser_context_t* c, pd_configuration_set_minimum_backing_votes_V7_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_initializer_force_approve_V7(
    parser_context_t* c, pd_initializer_force_approve_V7_t* m)
{
    CHECK_ERROR(_readBlockNumber(c, &m->up_to))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_parasdisputes_force_unfreeze_V7(
    parser_context_t* c, pd_parasdisputes_force_unfreeze_V7_t* m)
{
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_auctions_new_auction_V7(
    parser_context_t* c, pd_auctions_new_auction_V7_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->duration))
    CHECK_ERROR(_readCompactu32(c, &m->lease_period_index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_auctions_bid_V7(
    parser_context_t* c, pd_auctions_bid_V7_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->para))
    CHECK_ERROR(_readCompactu32(c, &m->auction_index))
    CHECK_ERROR(_readCompactu32(c, &m->first_slot))
    CHECK_ERROR(_readCompactu32(c, &m->last_slot))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_auctions_cancel_auction_V7(
    parser_context_t* c, pd_auctions_cancel_auction_V7_t* m)
{
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

////////////////////////////////////////////
////// Custom
////////////////////////////////////////////

__Z_INLINE parser_error_t _readMethod_votemanager_vote_V7(
    parser_context_t* c, pd_votemanager_vote_V7_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->poll_index))
    CHECK_ERROR(_readAccountVote(c, &m->vote)) 
    CHECK_ERROR(_readVoteCurrency(c, &m->currency))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_votemanager_remove_vote_V7(
    parser_context_t* c, pd_votemanager_remove_vote_V7_t* m)
{
    CHECK_ERROR(_readOptionu16(c, &m->class))
    CHECK_ERROR(_readu32(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_votemanager_remove_other_vote_V7(
    parser_context_t* c, pd_votemanager_remove_other_vote_V7_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->target))
    CHECK_ERROR(_readu16(c, &m->class))
    CHECK_ERROR(_readu32(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_votemanager_unlock_V7(
    parser_context_t* c, pd_votemanager_unlock_V7_t* m)
{
    CHECK_ERROR(_readu16(c, &m->class))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->target))
    CHECK_ERROR(_readu32(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_validatormanager_register_validators_V7(
    parser_context_t* c, pd_validatormanager_register_validators_V7_t* m)
{
    CHECK_ERROR(_readVecAccountId(c, &m->validators))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_validatormanager_deregister_validators_V7(
    parser_context_t* c, pd_validatormanager_deregister_validators_V7_t* m)
{
    CHECK_ERROR(_readVecAccountId(c, &m->validators))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_extrinsicpause_pause_extrinsic_V7(
    parser_context_t* c, pd_extrinsicpause_pause_extrinsic_V7_t* m)
{
    CHECK_ERROR(_readCall(c, &m->call))
    CHECK_ERROR(_readbool(c, &m->pause_only_extrinsic))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_extrinsicpause_resume_extrinsic_V7(
    parser_context_t* c, pd_extrinsicpause_resume_extrinsic_V7_t* m)
{
    CHECK_ERROR(_readCall(c, &m->call))
    CHECK_ERROR(_readbool(c, &m->resume_only_extrinsic))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_stakeexchange_create_offer_V7(
        parser_context_t* c, pd_stakeexchange_create_offer_V7_t* m)
{
    CHECK_ERROR(_readOfferOfT(c, &m->offer))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_stakeexchange_cancel_offer_V7(
        parser_context_t* c, pd_stakeexchange_cancel_offer_V7_t* m)
{
    CHECK_ERROR(_readOfferId(c, &m->offer_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_stakeexchange_configure_liquidity_account_V7(
        parser_context_t* c, pd_stakeexchange_configure_liquidity_account_V7_t* m)
{
    CHECK_ERROR(_readLiquidityAccountConfigOfT(c, &m->config))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_stakeexchange_withdraw_liquidity_V7(
        parser_context_t* c, pd_stakeexchange_withdraw_liquidity_V7_t* m)
{
    CHECK_ERROR(_readOfferId(c, &m->offer_id))
    CHECK_ERROR(_readBalanceOf(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_stakeexchange_add_liquidity_V7(
        parser_context_t* c, pd_stakeexchange_add_liquidity_V7_t* m)
{
    CHECK_ERROR(_readOfferId(c, &m->offer_id))
    CHECK_ERROR(_readBalanceOf(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_stakeexchange_buy_V7(
        parser_context_t* c, pd_stakeexchange_buy_V7_t* m)
{
    CHECK_ERROR(_readOfferId(c, &m->offer_id))
    CHECK_ERROR(_readBalanceOf(c, &m->amount))
    CHECK_ERROR(_readTokenIdOf(c, &m->token_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multitokens_approve_collection_V7(
        parser_context_t* c, pd_multitokens_approve_collection_V7_t* m)
{
    CHECK_ERROR(_readCompactCollectionId(c, &m->collection_id))
    CHECK_ERROR(_readAccountId(c, &m->operator_))
    CHECK_ERROR(_readOptionu32(c, &m->expiration))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multitokens_approve_token_V7(
        parser_context_t* c, pd_multitokens_approve_token_V7_t* m)
{
    CHECK_ERROR(_readCompactCollectionId(c, &m->collection_id))
    CHECK_ERROR(_readCompactTokenId(c, &m->token_id))
    CHECK_ERROR(_readAccountId(c, &m->operator_))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    CHECK_ERROR(_readOptionu32(c, &m->expiration))
    CHECK_ERROR(_readCompactBalance(c, &m->current_amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multitokens_batch_set_attribute_V7(
        parser_context_t* c, pd_multitokens_batch_set_attribute_V7_t* m)
{
    CHECK_ERROR(_readCompactCollectionId(c, &m->collection_id))
    CHECK_ERROR(_readOptionTokenId(c, &m->token_id))
    CHECK_ERROR(_readVecAttributeKeyValuePair(c, &m->attributes))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multitokens_batch_transfer_V7(
        parser_context_t* c, pd_multitokens_batch_transfer_V7_t* m)
{
    CHECK_ERROR(_readCompactCollectionId(c, &m->collection_id))
    CHECK_ERROR(_readVecTransferRecipientsOf(c, &m->recipients))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multitokens_burn_V7(
        parser_context_t* c, pd_multitokens_burn_V7_t* m)
{
    CHECK_ERROR(_readCompactCollectionId(c, &m->collection_id))
    CHECK_ERROR(_readBurnParamsOfT(c, &m->params))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multitokens_claim_collections_V7(
        parser_context_t* c, pd_multitokens_claim_collections_V7_t* m)
{
    CHECK_ERROR(_readAccountId(c, &m->destination))
    CHECK_ERROR(_readEcdsaSignature(c, &m->ethereum_signature))
    CHECK_ERROR(_readEthereumAddress(c, &m->ethereum_address))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multitokens_claim_tokens_V7(
        parser_context_t* c, pd_multitokens_claim_tokens_V7_t* m)
{
    CHECK_ERROR(_readAccountId(c, &m->destination))
    CHECK_ERROR(_readEcdsaSignature(c, &m->ethereum_signature))
    CHECK_ERROR(_readEthereumAddress(c, &m->ethereum_address))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multitokens_create_collection_V7(
        parser_context_t* c, pd_multitokens_create_collection_V7_t* m)
{
    CHECK_ERROR(_readCollectionDescriptor(c, &m->descriptor))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multitokens_destroy_collection_V7(
        parser_context_t* c, pd_multitokens_destroy_collection_V7_t* m)
{
    CHECK_ERROR(_readCompactCollectionId(c, &m->collection_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multitokens_freeze_V7(
        parser_context_t* c, pd_multitokens_freeze_V7_t* m)
{
    CHECK_ERROR(_readFreezeOf(c, &m->info))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multitokens_mutate_collection_V7(
        parser_context_t* c, pd_multitokens_mutate_collection_V7_t* m)
{
    CHECK_ERROR(_readCompactCollectionId(c, &m->collection_id))
    CHECK_ERROR(_readCollectionMutation(c, &m->mutation))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multitokens_remove_all_attributes_V7(
        parser_context_t* c, pd_multitokens_remove_all_attributes_V7_t* m)
{
    CHECK_ERROR(_readCompactCollectionId(c, &m->collection_id))
    CHECK_ERROR(_readOptionTokenId(c, &m->token_id))
    CHECK_ERROR(_readu32(c, &m->attribute_count))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multitokens_remove_attribute_V7(
        parser_context_t* c, pd_multitokens_remove_attribute_V7_t* m)
{
    CHECK_ERROR(_readCompactCollectionId(c, &m->collection_id))
    CHECK_ERROR(_readOptionTokenId(c, &m->token_id))
    CHECK_ERROR(_readBytes(c, &m->key))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multitokens_set_attribute_V7(
        parser_context_t* c, pd_multitokens_set_attribute_V7_t* m)
{
    CHECK_ERROR(_readCompactCollectionId(c, &m->collection_id))
    CHECK_ERROR(_readOptionTokenId(c, &m->token_id))
    CHECK_ERROR(_readBytes(c, &m->key))
    CHECK_ERROR(_readBytes(c, &m->value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multitokens_thaw_V7(
        parser_context_t* c, pd_multitokens_thaw_V7_t* m)
{
    CHECK_ERROR(_readFreezeOf(c, &m->info))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multitokens_transfer_V7(
        parser_context_t* c, pd_multitokens_transfer_V7_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->recipient))
    CHECK_ERROR(_readCompactCollectionId(c, &m->collection_id))
    CHECK_ERROR(_readTransferParamsOfT(c, &m->params))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multitokens_unapprove_collection_V7(
        parser_context_t* c, pd_multitokens_unapprove_collection_V7_t* m)
{
    CHECK_ERROR(_readCompactCollectionId(c, &m->collection_id))
    CHECK_ERROR(_readAccountId(c, &m->operator_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multitokens_unapprove_token_V7(
        parser_context_t* c, pd_multitokens_unapprove_token_V7_t* m)
{
    CHECK_ERROR(_readCompactCollectionId(c, &m->collection_id))
    CHECK_ERROR(_readCompactTokenId(c, &m->token_id))
    CHECK_ERROR(_readAccountId(c, &m->operator_))
    return parser_ok;
}
__Z_INLINE parser_error_t _readMethod_multitokens_batch_mint_V7(
        parser_context_t* c, pd_multitokens_batch_mint_V7_t* m)
{
    CHECK_ERROR(_readCompactCollectionId(c, &m->collection_id))
    CHECK_ERROR(_readVecMintRecipientsOf(c, &m->recipients))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multitokens_mint_V7(
        parser_context_t* c, pd_multitokens_mint_V7_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->recipient))
    CHECK_ERROR(_readCompactCollectionId(c, &m->collection_id))
    CHECK_ERROR(_readMintParamsOf(c, &m->params))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multitokens_mutate_token_V7(
        parser_context_t* c, pd_multitokens_mutate_token_V7_t* m)
{
    CHECK_ERROR(_readCompactCollectionId(c, &m->collection_id))
    CHECK_ERROR(_readCompactTokenId(c, &m->token_id))
    CHECK_ERROR(_readTokenMutation(c, &m->mutation))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multitokens_force_approve_collection_V7(
        parser_context_t* c, pd_multitokens_force_approve_collection_V7_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->caller))
    CHECK_ERROR(_readCompactCollectionId(c, &m->collection_id))
    CHECK_ERROR(_readAccountId(c, &m->operator_))
    CHECK_ERROR(_readOptionu32(c, &m->expiration))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multitokens_force_burn_V7(
        parser_context_t* c, pd_multitokens_force_burn_V7_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->caller))
    CHECK_ERROR(_readCompactCollectionId(c, &m->collection_id))
    CHECK_ERROR(_readBurnParamsOfT(c, &m->params))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multitokens_force_create_collection_V7(
        parser_context_t* c, pd_multitokens_force_create_collection_V7_t* m)
{
    CHECK_ERROR(_readAccountId(c, &m->owner))
    CHECK_ERROR(_readCompactCollectionId(c, &m->collection_id))
    CHECK_ERROR(_readCollectionDescriptor(c, &m->descriptor))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multitokens_force_freeze_V7(
        parser_context_t* c, pd_multitokens_force_freeze_V7_t* m)
{
    CHECK_ERROR(_readFreezeOf(c, &m->info))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multitokens_force_mint_V7(
        parser_context_t* c, pd_multitokens_force_mint_V7_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->caller))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->recipient))
    CHECK_ERROR(_readCompactCollectionId(c, &m->collection_id))
    CHECK_ERROR(_readMintParamsOf(c, &m->params))
    CHECK_ERROR(_readOptionAccountIdLookupOfT(c, &m->deposit_backer))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multitokens_force_mutate_collection_V7(
        parser_context_t* c, pd_multitokens_force_mutate_collection_V7_t* m)
{
    CHECK_ERROR(_readCompactCollectionId(c, &m->collection_id))
    CHECK_ERROR(_readCollectionMutation(c, &m->mutation))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multitokens_force_set_attribute_V7(
        parser_context_t* c, pd_multitokens_force_set_attribute_V7_t* m)
{
    CHECK_ERROR(_readCompactCollectionId(c, &m->collection_id))
    CHECK_ERROR(_readOptionTokenId(c, &m->token_id))
    CHECK_ERROR(_readBytes(c, &m->key))
    CHECK_ERROR(_readOptionAttributeOf(c, &m->value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multitokens_force_set_collection_V7(
        parser_context_t* c, pd_multitokens_force_set_collection_V7_t* m)
{
    CHECK_ERROR(_readCompactCollectionId(c, &m->collection_id))
    CHECK_ERROR(_readOptionCollectionOf(c, &m->value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multitokens_force_set_collection_account_V7(
        parser_context_t* c, pd_multitokens_force_set_collection_account_V7_t* m)
{
    CHECK_ERROR(_readCompactCollectionId(c, &m->collection_id))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->account_id))
    CHECK_ERROR(_readOptionCollectionAccountOf(c, &m->value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multitokens_force_set_next_collection_id_V7(
        parser_context_t* c, pd_multitokens_force_set_next_collection_id_V7_t* m)
{
    CHECK_ERROR(_readCompactCollectionId(c, &m->value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multitokens_force_set_token_V7(
        parser_context_t* c, pd_multitokens_force_set_token_V7_t* m)
{
    CHECK_ERROR(_readCompactCollectionId(c, &m->collection_id))
    CHECK_ERROR(_readCompactTokenId(c, &m->token_id))
    CHECK_ERROR(_readOptionTokenOf(c, &m->value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multitokens_force_set_token_account_V7(
        parser_context_t* c, pd_multitokens_force_set_token_account_V7_t* m)
{
    CHECK_ERROR(_readCompactCollectionId(c, &m->collection_id))
    CHECK_ERROR(_readCompactTokenId(c, &m->token_id))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->account_id))
    CHECK_ERROR(_readOptionTokenAccountOf(c, &m->value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multitokens_force_transfer_V7(
        parser_context_t* c, pd_multitokens_force_transfer_V7_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->source))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->destination))
    CHECK_ERROR(_readCompactCollectionId(c, &m->collection_id))
    CHECK_ERROR(_readTransferParamsOfT(c, &m->params))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nominationpools_bond_V7(
        parser_context_t* c, pd_nominationpools_bond_V7_t* m)
{
    CHECK_ERROR(_readPoolId(c, &m->pool_id))
    CHECK_ERROR(_readBondValueOfT(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nominationpools_unbond_V7(
        parser_context_t* c, pd_nominationpools_unbond_V7_t* m)
{
    CHECK_ERROR(_readPoolId(c, &m->pool_id))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->member_account))
    CHECK_ERROR(_readCompactBalance(c, &m->unbonding_points))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nominationpools_withdraw_unbonded_V7(
        parser_context_t* c, pd_nominationpools_withdraw_unbonded_V7_t* m)
{
    CHECK_ERROR(_readPoolId(c, &m->pool_id))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->member_account))
    CHECK_ERROR(_readu32(c, &m->num_slashing_spans))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nominationpools_pool_withdraw_unbonded_V7(
        parser_context_t* c, pd_nominationpools_pool_withdraw_unbonded_V7_t* m)
{
    CHECK_ERROR(_readPoolId(c, &m->pool_id))
    CHECK_ERROR(_readu32(c, &m->num_slashing_spans))
    return parser_ok;
}
__Z_INLINE parser_error_t _readMethod_nominationpools_create_V7(
        parser_context_t* c, pd_nominationpools_create_V7_t* m)
{
    CHECK_ERROR(_readTokenIdOf(c, &m->token_id))
    CHECK_ERROR(_readCompactBalance(c, &m->deposit))
    CHECK_ERROR(_readCompactBalance(c, &m->capacity))
    CHECK_ERROR(_readCompactIndex(c, &m->duration))
    CHECK_ERROR(_readBytes(c, &m->name))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nominationpools_nominate_V7(
        parser_context_t* c, pd_nominationpools_nominate_V7_t* m)
{
    CHECK_ERROR(_readPoolId(c, &m->pool_id))
    CHECK_ERROR(_readVecAccountId(c, &m->validators))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nominationpools_set_configs_V7(
        parser_context_t* c, pd_nominationpools_set_configs_V7_t* m)
{
    CHECK_ERROR(_readConfigOpBalanceOfT(c, &m->min_join_bond))
    CHECK_ERROR(_readConfigOpBalanceOfT(c, &m->min_create_bond))
    CHECK_ERROR(_readConfigOpPerbill(c, &m->global_max_commission))
    CHECK_ERROR(_readConfigOpPerbill(c, &m->required_payout_count))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nominationpools_chill_V7(
        parser_context_t* c, pd_nominationpools_chill_V7_t* m)
{
    CHECK_ERROR(_readPoolId(c, &m->pool_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nominationpools_destroy_V7(
        parser_context_t* c, pd_nominationpools_destroy_V7_t* m)
{
    CHECK_ERROR(_readPoolId(c, &m->pool_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nominationpools_payout_rewards_V7(
        parser_context_t* c, pd_nominationpools_payout_rewards_V7_t* m)
{
    CHECK_ERROR(_readAccountId(c, &m->validator_stash))
    CHECK_ERROR(_readEraIndex(c, &m->era))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nominationpools_mutate_V7(
        parser_context_t* c, pd_nominationpools_mutate_V7_t* m)
{
    CHECK_ERROR(_readPoolId(c, &m->pool_id))
    CHECK_ERROR(_readPoolMutationOfT(c, &m->mutation))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nominationpools_unbond_deposit_V7(
        parser_context_t* c, pd_nominationpools_unbond_deposit_V7_t* m)
{
    CHECK_ERROR(_readPoolId(c, &m->pool_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nominationpools_withdraw_deposit_V7(
        parser_context_t* c, pd_nominationpools_withdraw_deposit_V7_t* m)
{
    CHECK_ERROR(_readPoolId(c, &m->pool_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nominationpools_set_staking_info_V7(
        parser_context_t* c, pd_nominationpools_set_staking_info_V7_t* m)
{
    CHECK_ERROR(_readStakingInfo(c, &m->info))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nominationpools_calculate_early_bird_bonus_V7(
        parser_context_t* c, pd_nominationpools_calculate_early_bird_bonus_V7_t* m)
{
    CHECK_ERROR(_readu32(c, &m->pool_count))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nominationpools_pay_early_bird_bonus_V7(
        parser_context_t* c, pd_nominationpools_pay_early_bird_bonus_V7_t* m)
{
    CHECK_ERROR(_readPoolId(c, &m->pool_id))
    CHECK_ERROR(_readu32(c, &m->payment_id))
    CHECK_ERROR(_readu32(c, &m->account_count))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nominationpools_process_payouts_V7(
        parser_context_t* c, pd_nominationpools_process_payouts_V7_t* m)
{
    CHECK_ERROR(_readu32(c, &m->pool_count))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nominationpools_withdraw_free_balance_V7(
        parser_context_t* c, pd_nominationpools_withdraw_free_balance_V7_t* m)
{
    CHECK_ERROR(_readPoolId(c, &m->pool_id))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->destination))
    CHECK_ERROR(_readu128(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nominationpools_capture_early_bird_bonus_shares_V7(
        parser_context_t* c, pd_nominationpools_capture_early_bird_bonus_shares_V7_t* m)
{
    CHECK_ERROR(_readPoolId(c, &m->pool_id))
    CHECK_ERROR(_readu32(c, &m->account_count))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nominationpools_unlock_early_bird_bonus_V7(
        parser_context_t* c, pd_nominationpools_unlock_early_bird_bonus_V7_t* m)
{
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_fellowshipcollective_add_member_V7(
        parser_context_t* c, pd_fellowshipcollective_add_member_V7_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_fellowshipcollective_promote_member_V7(
        parser_context_t* c, pd_fellowshipcollective_promote_member_V7_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_fellowshipcollective_demote_member_V7(
        parser_context_t* c, pd_fellowshipcollective_demote_member_V7_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_fellowshipcollective_remove_member_V7(
        parser_context_t* c, pd_fellowshipcollective_remove_member_V7_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->who))
    CHECK_ERROR(_readu16(c, &m->min_rank))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_fellowshipcollective_vote_V7(
        parser_context_t* c, pd_fellowshipcollective_vote_V7_t* m)
{
    CHECK_ERROR(_readu32(c, &m->poll))
    CHECK_ERROR(_readbool(c, &m->aye))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_fellowshipcollective_cleanup_poll_V7(
        parser_context_t* c, pd_fellowshipcollective_cleanup_poll_V7_t* m)
{
    CHECK_ERROR(_readu32(c, &m->poll_index))
    CHECK_ERROR(_readu32(c, &m->max))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_fellowshipreferenda_submit_V7(
        parser_context_t* c, pd_fellowshipreferenda_submit_V7_t* m)
{
    CHECK_ERROR(_readBoxPalletsProposalOrigin(c, &m->proposal_origin))
    CHECK_ERROR(_readBoundedCallOfT(c, &m->proposal))
    CHECK_ERROR(_readDispatchTimeBlockNumber(c, &m->enactment_moment))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_fellowshipreferenda_place_decision_deposit_V7(
        parser_context_t* c, pd_fellowshipreferenda_place_decision_deposit_V7_t* m)
{
    CHECK_ERROR(_readu32(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_fellowshipreferenda_refund_decision_deposit_V7(
        parser_context_t* c, pd_fellowshipreferenda_refund_decision_deposit_V7_t* m)
{
    CHECK_ERROR(_readu32(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_fellowshipreferenda_cancel_V7(
        parser_context_t* c, pd_fellowshipreferenda_cancel_V7_t* m)
{
    CHECK_ERROR(_readu32(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_fellowshipreferenda_kill_V7(
        parser_context_t* c, pd_fellowshipreferenda_kill_V7_t* m)
{
    CHECK_ERROR(_readu32(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_fellowshipreferenda_nudge_referendum_V7(
        parser_context_t* c, pd_fellowshipreferenda_nudge_referendum_V7_t* m)
{
    CHECK_ERROR(_readu32(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_fellowshipreferenda_one_fewer_deciding_V7(
        parser_context_t* c, pd_fellowshipreferenda_one_fewer_deciding_V7_t* m)
{
    CHECK_ERROR(_readu16(c, &m->track))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_fellowshipreferenda_refund_submission_deposit_V7(
        parser_context_t* c, pd_fellowshipreferenda_refund_submission_deposit_V7_t* m)
{
    CHECK_ERROR(_readu32(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_fellowshipreferenda_set_metadata_V7(
        parser_context_t* c, pd_fellowshipreferenda_set_metadata_V7_t* m)
{
    CHECK_ERROR(_readu32(c, &m->index))
    CHECK_ERROR(_readOptionHash(c, &m->maybe_hash))
    return parser_ok;
}


__Z_INLINE parser_error_t _readMethod_marketplace_cancel_listing_V7(
        parser_context_t* c, pd_marketplace_cancel_listing_V7_t* m)
{
    CHECK_ERROR(_readListingIdOf(c, &m->listing_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_marketplace_create_listing_V7(
        parser_context_t* c, pd_marketplace_create_listing_V7_t* m)
{
    CHECK_ERROR(_readTokenAssetId(c, &m->make_asset_id))
    CHECK_ERROR(_readTokenAssetId(c, &m->take_asset_id))
    CHECK_ERROR(_readCompactu128(c, &m->amount))
    CHECK_ERROR(_readCompactu128(c, &m->price))
    CHECK_ERROR(_readBytes(c, &m->salt))
    CHECK_ERROR(_readOptionAuctionDataOfT(c, &m->auction_data))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_marketplace_fill_listing_V7(
        parser_context_t* c, pd_marketplace_fill_listing_V7_t* m)
{
    CHECK_ERROR(_readListingIdOf(c, &m->listing_id))
    CHECK_ERROR(_readCompactu128(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_marketplace_finalize_auction_V7(
        parser_context_t* c, pd_marketplace_finalize_auction_V7_t* m)
{
    CHECK_ERROR(_readListingIdOf(c, &m->listing_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_marketplace_place_bid_V7(
        parser_context_t* c, pd_marketplace_place_bid_V7_t* m)
{
    CHECK_ERROR(_readListingIdOf(c, &m->listing_id))
    CHECK_ERROR(_readCompactu128(c, &m->price))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_fueltanks_add_account_V7(
        parser_context_t* c, pd_fueltanks_add_account_V7_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->tank_id))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->user_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_fueltanks_batch_add_account_V7(
        parser_context_t* c, pd_fueltanks_batch_add_account_V7_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->tank_id))
    CHECK_ERROR(_readVecAccountIdLookupOfT(c, &m->user_ids))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_fueltanks_batch_remove_account_V7(
        parser_context_t* c, pd_fueltanks_batch_remove_account_V7_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->tank_id))
    CHECK_ERROR(_readVecAccountIdLookupOfT(c, &m->user_ids))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_fueltanks_create_fuel_tank_V7(
        parser_context_t* c, pd_fueltanks_create_fuel_tank_V7_t* m)
{
    CHECK_ERROR(_readFuelTankDescriptorOf(c, &m->descriptor))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_fueltanks_destroy_fuel_tank_V7(
        parser_context_t* c, pd_fueltanks_destroy_fuel_tank_V7_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->tank_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_fueltanks_dispatch_V7(
        parser_context_t* c, pd_fueltanks_dispatch_V7_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->tank_id))
    CHECK_ERROR(_readu32(c, &m->rule_set_id))
    CHECK_ERROR(_readCall(c, &m->call))
    CHECK_ERROR(_readOptionDispatchSettings(c, &m->settings))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_fueltanks_dispatch_and_touch_V7(
        parser_context_t* c, pd_fueltanks_dispatch_and_touch_V7_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->tank_id))
    CHECK_ERROR(_readu32(c, &m->rule_set_id))
    CHECK_ERROR(_readCall(c, &m->call))
    CHECK_ERROR(_readOptionDispatchSettings(c, &m->settings))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_fueltanks_force_batch_add_account_V7(
        parser_context_t* c, pd_fueltanks_force_batch_add_account_V7_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->owner))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->tank_id))
    CHECK_ERROR(_readVecAccountIdLookupOfT(c, &m->user_ids))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_fueltanks_force_create_fuel_tank_V7(
        parser_context_t* c, pd_fueltanks_force_create_fuel_tank_V7_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->owner))
    CHECK_ERROR(_readFuelTankDescriptorOf(c, &m->descriptor))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_fueltanks_force_set_consumption_V7(
        parser_context_t* c, pd_fueltanks_force_set_consumption_V7_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->tank_id))
    CHECK_ERROR(_readOptionAccountIdLookupOfT(c, &m->user_id))
    CHECK_ERROR(_readu32(c, &m->rule_set_id))
    CHECK_ERROR(_readConsumptionOf(c, &m->consumption))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_fueltanks_insert_rule_set_V7(
        parser_context_t* c, pd_fueltanks_insert_rule_set_V7_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->tank_id))
    CHECK_ERROR(_readu32(c, &m->rule_set_id))
    CHECK_ERROR(_readVecDispatchRuleDescriptor(c, &m->rules))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_fueltanks_mutate_fuel_tank_V7(
        parser_context_t* c, pd_fueltanks_mutate_fuel_tank_V7_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->tank_id))
    CHECK_ERROR(_readFuelTankMutationOf(c, &m->mutation))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_fueltanks_remove_account_V7(
        parser_context_t* c, pd_fueltanks_remove_account_V7_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->tank_id))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->user_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_fueltanks_remove_account_rule_data_V7(
        parser_context_t* c, pd_fueltanks_remove_account_rule_data_V7_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->tank_id))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->user_id))
    CHECK_ERROR(_readu32(c, &m->rule_set_id))
    CHECK_ERROR(_readDispatchRuleKind(c, &m->rule_kind))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_fueltanks_remove_rule_set_V7(
        parser_context_t* c, pd_fueltanks_remove_rule_set_V7_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->tank_id))
    CHECK_ERROR(_readu32(c, &m->rule_set_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_fueltanks_schedule_mutate_freeze_state_V7(
        parser_context_t* c, pd_fueltanks_schedule_mutate_freeze_state_V7_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->tank_id))
    CHECK_ERROR(_readOptionu32(c, &m->rule_set_id))
    CHECK_ERROR(_readbool(c, &m->is_frozen))
    return parser_ok;
}

#endif

parser_error_t _readMethod_V7(
    parser_context_t* c,
    uint8_t moduleIdx,
    uint8_t callIdx,
    pd_Method_V7_t* method)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {

    case 1536: /* module 6 call 0 */
        CHECK_ERROR(_readMethod_balances_transfer_allow_death_V7(c, &method->nested.balances_transfer_allow_death_V7))
        break;
    case 1538: /* module 6 call 2 */
        CHECK_ERROR(_readMethod_balances_force_transfer_V7(c, &method->nested.balances_force_transfer_V7))
        break;
    case 1539: /* module 6 call 3 */
        CHECK_ERROR(_readMethod_balances_transfer_keep_alive_V7(c, &method->nested.balances_transfer_keep_alive_V7))
        break;
    case 1540: /* module 6 call 4 */
        CHECK_ERROR(_readMethod_balances_transfer_all_V7(c, &method->nested.balances_transfer_all_V7))
        break;
    case 2304: /* module 9 call 0 */
        CHECK_ERROR(_readMethod_staking_bond_V7(c, &method->nested.staking_bond_V7))
        break;
    case 2305: /* module 9 call 1 */
        CHECK_ERROR(_readMethod_staking_bond_extra_V7(c, &method->nested.staking_bond_extra_V7))
        break;
    case 2306: /* module 9 call 2 */
        CHECK_ERROR(_readMethod_staking_unbond_V7(c, &method->nested.staking_unbond_V7))
        break;
    case 2307: /* module 9 call 3 */
        CHECK_ERROR(_readMethod_staking_withdraw_unbonded_V7(c, &method->nested.staking_withdraw_unbonded_V7))
        break;
    case 2308: /* module 9 call 4 */
        CHECK_ERROR(_readMethod_staking_validate_V7(c, &method->nested.staking_validate_V7))
        break;
    case 2309: /* module 9 call 5 */
        CHECK_ERROR(_readMethod_staking_nominate_V7(c, &method->nested.staking_nominate_V7))
        break;
    case 2310: /* module 9 call 6 */
        CHECK_ERROR(_readMethod_staking_chill_V7(c, &method->nested.staking_chill_V7))
        break;
    case 2311: /* module 9 call 7 */
        CHECK_ERROR(_readMethod_staking_set_payee_V7(c, &method->nested.staking_set_payee_V7))
        break;
    case 2312: /* module 9 call 8 */
        CHECK_ERROR(_readMethod_staking_set_controller_V7(c, &method->nested.staking_set_controller_V7))
        break;
    case 2322: /* module 9 call 18 */
        CHECK_ERROR(_readMethod_staking_payout_stakers_V7(c, &method->nested.staking_payout_stakers_V7))
        break;
    case 2323: /* module 9 call 19 */
        CHECK_ERROR(_readMethod_staking_rebond_V7(c, &method->nested.staking_rebond_V7))
        break;
    case 2560: /* module 10 call 0 */
        CHECK_ERROR(_readMethod_session_set_keys_V7(c, &method->nested.session_set_keys_V7))
        break;
    case 2561: /* module 10 call 1 */
        CHECK_ERROR(_readMethod_session_purge_keys_V7(c, &method->nested.session_purge_keys_V7))
        break;
    case 5120: /* module 20 call 0 */
        CHECK_ERROR(_readMethod_utility_batch_V7(c, &method->basic.utility_batch_V7))
        break;
    case 5122: /* module 20 call 2 */
        CHECK_ERROR(_readMethod_utility_batch_all_V7(c, &method->basic.utility_batch_all_V7))
        break;
    case 5124: /* module 20 call 4 */
        CHECK_ERROR(_readMethod_utility_force_batch_V7(c, &method->basic.utility_force_batch_V7))
        break;
    case 18688: /* module 73 call 0 */
        CHECK_ERROR(_readMethod_crowdloan_create_V7(c, &method->basic.crowdloan_create_V7))
        break;
    case 18689: /* module 73 call 1 */
        CHECK_ERROR(_readMethod_crowdloan_contribute_V7(c, &method->basic.crowdloan_contribute_V7))
        break;
    case 18690: /* module 73 call 2 */
        CHECK_ERROR(_readMethod_crowdloan_withdraw_V7(c, &method->basic.crowdloan_withdraw_V7))
        break;
    case 18691: /* module 73 call 3 */
        CHECK_ERROR(_readMethod_crowdloan_refund_V7(c, &method->basic.crowdloan_refund_V7))
        break;
    case 18692: /* module 73 call 4 */
        CHECK_ERROR(_readMethod_crowdloan_dissolve_V7(c, &method->basic.crowdloan_dissolve_V7))
        break;
    case 18693: /* module 73 call 5 */
        CHECK_ERROR(_readMethod_crowdloan_edit_V7(c, &method->basic.crowdloan_edit_V7))
        break;
    case 18694: /* module 73 call 6 */
        CHECK_ERROR(_readMethod_crowdloan_add_memo_V7(c, &method->basic.crowdloan_add_memo_V7))
        break;
    case 18695: /* module 73 call 7 */
        CHECK_ERROR(_readMethod_crowdloan_poke_V7(c, &method->basic.crowdloan_poke_V7))
        break;
    case 18696: /* module 73 call 8 */
        CHECK_ERROR(_readMethod_crowdloan_contribute_all_V7(c, &method->basic.crowdloan_contribute_all_V7))
        break;

#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
    case 25345: /* module 99 call 1 */
        CHECK_ERROR(_readMethod_xcmpallet_teleport_assets_V7(c, &method->basic.xcmpallet_teleport_assets_V7))
        break;
    case 25346: /* module 99 call 2 */
        CHECK_ERROR(_readMethod_xcmpallet_reserve_transfer_assets_V7(c, &method->basic.xcmpallet_reserve_transfer_assets_V7))
        break;
    case 25352: /* module 99 call 8 */
        CHECK_ERROR(_readMethod_xcmpallet_limited_reserve_transfer_assets_V7(c, &method->basic.xcmpallet_limited_reserve_transfer_assets_V7))
        break;
    case 25353: /* module 99 call 9 */
        CHECK_ERROR(_readMethod_xcmpallet_limited_teleport_assets_V7(c, &method->basic.xcmpallet_limited_teleport_assets_V7))
        break;
#endif
    case 0: /* module 0 call 0 */
        CHECK_ERROR(_readMethod_system_remark_V7(c, &method->nested.system_remark_V7))
        break;
    case 1: /* module 0 call 1 */
        CHECK_ERROR(_readMethod_system_set_heap_pages_V7(c, &method->nested.system_set_heap_pages_V7))
        break;
    case 2: /* module 0 call 2 */
        CHECK_ERROR(_readMethod_system_set_code_V7(c, &method->nested.system_set_code_V7))
        break;
    case 3: /* module 0 call 3 */
        CHECK_ERROR(_readMethod_system_set_code_without_checks_V7(c, &method->nested.system_set_code_without_checks_V7))
        break;
    case 7: /* module 0 call 7 */
        CHECK_ERROR(_readMethod_system_remark_with_event_V7(c, &method->nested.system_remark_with_event_V7))
        break;
    case 25856: /* module 101 call 0 */
        CHECK_ERROR(_readMethod_preimage_note_preimage_V7(c, &method->basic.preimage_note_preimage_V7))
        break;
    case 25857: /* module 101 call 1 */
        CHECK_ERROR(_readMethod_preimage_unnote_preimage_V7(c, &method->basic.preimage_unnote_preimage_V7))
        break;
    case 25858: /* module 101 call 2 */
        CHECK_ERROR(_readMethod_preimage_request_preimage_V7(c, &method->basic.preimage_request_preimage_V7))
        break;
    case 25859: /* module 101 call 3 */
        CHECK_ERROR(_readMethod_preimage_unrequest_preimage_V7(c, &method->basic.preimage_unrequest_preimage_V7))
        break;
    case 25860: /* module 101 call 4 */
        CHECK_ERROR(_readMethod_preimage_ensure_updated_V7(c, &method->basic.preimage_ensure_updated_V7))
        break;
    case 512: /* module 2 call 0 */
        CHECK_ERROR(_readMethod_timestamp_set_V7(c, &method->basic.timestamp_set_V7))
        break;
    case 1541: /* module 6 call 5 */
        CHECK_ERROR(_readMethod_balances_force_unreserve_V7(c, &method->basic.balances_force_unreserve_V7))
        break;
    case 1542: /* module 6 call 6 */
        CHECK_ERROR(_readMethod_balances_upgrade_accounts_V7(c, &method->basic.balances_upgrade_accounts_V7))
        break;
    case 1544: /* module 6 call 8 */
        CHECK_ERROR(_readMethod_balances_force_set_balance_V7(c, &method->basic.balances_force_set_balance_V7))
        break;
    case 2313: /* module 9 call 9 */
        CHECK_ERROR(_readMethod_staking_set_validator_count_V7(c, &method->basic.staking_set_validator_count_V7))
        break;
    case 2314: /* module 9 call 10 */
        CHECK_ERROR(_readMethod_staking_increase_validator_count_V7(c, &method->basic.staking_increase_validator_count_V7))
        break;
    case 2315: /* module 9 call 11 */
        CHECK_ERROR(_readMethod_staking_scale_validator_count_V7(c, &method->basic.staking_scale_validator_count_V7))
        break;
    case 2316: /* module 9 call 12 */
        CHECK_ERROR(_readMethod_staking_force_no_eras_V7(c, &method->basic.staking_force_no_eras_V7))
        break;
    case 2317: /* module 9 call 13 */
        CHECK_ERROR(_readMethod_staking_force_new_era_V7(c, &method->basic.staking_force_new_era_V7))
        break;
    case 2318: /* module 9 call 14 */
        CHECK_ERROR(_readMethod_staking_set_invulnerables_V7(c, &method->basic.staking_set_invulnerables_V7))
        break;
    case 2319: /* module 9 call 15 */
        CHECK_ERROR(_readMethod_staking_force_unstake_V7(c, &method->basic.staking_force_unstake_V7))
        break;
    case 2320: /* module 9 call 16 */
        CHECK_ERROR(_readMethod_staking_force_new_era_always_V7(c, &method->basic.staking_force_new_era_always_V7))
        break;
    case 2321: /* module 9 call 17 */
        CHECK_ERROR(_readMethod_staking_cancel_deferred_slash_V7(c, &method->basic.staking_cancel_deferred_slash_V7))
        break;
    case 2324: /* module 9 call 20 */
        CHECK_ERROR(_readMethod_staking_reap_stash_V7(c, &method->basic.staking_reap_stash_V7))
        break;
    case 2325: /* module 9 call 21 */
        CHECK_ERROR(_readMethod_staking_kick_V7(c, &method->basic.staking_kick_V7))
        break;
    case 2326: /* module 9 call 22 */
        CHECK_ERROR(_readMethod_staking_set_staking_configs_V7(c, &method->basic.staking_set_staking_configs_V7))
        break;
    case 2327: /* module 9 call 23 */
        CHECK_ERROR(_readMethod_staking_chill_other_V7(c, &method->basic.staking_chill_other_V7))
        break;
    case 2328: /* module 9 call 24 */
        CHECK_ERROR(_readMethod_staking_force_apply_min_commission_V7(c, &method->basic.staking_force_apply_min_commission_V7))
        break;
    case 2329: /* module 9 call 25 */
        CHECK_ERROR(_readMethod_staking_set_min_commission_V7(c, &method->basic.staking_set_min_commission_V7))
        break;
    case 3072: /* module 12 call 0 */
        CHECK_ERROR(_readMethod_treasury_propose_spend_V7(c, &method->basic.treasury_propose_spend_V7))
        break;
    case 3073: /* module 12 call 1 */
        CHECK_ERROR(_readMethod_treasury_reject_proposal_V7(c, &method->basic.treasury_reject_proposal_V7))
        break;
    case 3074: /* module 12 call 2 */
        CHECK_ERROR(_readMethod_treasury_approve_proposal_V7(c, &method->basic.treasury_approve_proposal_V7))
        break;
    case 3075: /* module 12 call 3 */
        CHECK_ERROR(_readMethod_treasury_spend_local_V7(c, &method->basic.treasury_spend_local_V7))
        break;
    case 3076: /* module 12 call 4 */
        CHECK_ERROR(_readMethod_treasury_remove_approval_V7(c, &method->basic.treasury_remove_approval_V7))
        break;
    case 3078: /* module 12 call 6 */
        CHECK_ERROR(_readMethod_treasury_payout_V7(c, &method->basic.treasury_payout_V7))
        break;
    case 3079: /* module 12 call 7 */
        CHECK_ERROR(_readMethod_treasury_check_status_V7(c, &method->basic.treasury_check_status_V7))
        break;
    case 3080: /* module 12 call 8 */
        CHECK_ERROR(_readMethod_treasury_void_spend_V7(c, &method->basic.treasury_void_spend_V7))
        break;
    case 26112: /* module 102 call 0 */
        CHECK_ERROR(_readMethod_convictionvoting_vote_V7(c, &method->nested.convictionvoting_vote_V7))
        break;
    case 26113: /* module 102 call 1 */
        CHECK_ERROR(_readMethod_convictionvoting_delegate_V7(c, &method->nested.convictionvoting_delegate_V7))
        break;
    case 26114: /* module 102 call 2 */
        CHECK_ERROR(_readMethod_convictionvoting_undelegate_V7(c, &method->nested.convictionvoting_undelegate_V7))
        break;
    case 26115: /* module 102 call 3 */
        CHECK_ERROR(_readMethod_convictionvoting_unlock_V7(c, &method->nested.convictionvoting_unlock_V7))
        break;
    case 26116: /* module 102 call 4 */
        CHECK_ERROR(_readMethod_convictionvoting_remove_vote_V7(c, &method->nested.convictionvoting_remove_vote_V7))
        break;
    case 26117: /* module 102 call 5 */
        CHECK_ERROR(_readMethod_convictionvoting_remove_other_vote_V7(c, &method->nested.convictionvoting_remove_other_vote_V7))
        break;
    case 26368: /* module 103 call 0 */
        CHECK_ERROR(_readMethod_referenda_submit_V7(c, &method->basic.referenda_submit_V7))
        break;
    case 26369: /* module 103 call 1 */
        CHECK_ERROR(_readMethod_referenda_place_decision_deposit_V7(c, &method->basic.referenda_place_decision_deposit_V7))
        break;
    case 26370: /* module 103 call 2 */
        CHECK_ERROR(_readMethod_referenda_refund_decision_deposit_V7(c, &method->basic.referenda_refund_decision_deposit_V7))
        break;
    case 26371: /* module 103 call 3 */
        CHECK_ERROR(_readMethod_referenda_cancel_V7(c, &method->basic.referenda_cancel_V7))
        break;
    case 26372: /* module 103 call 4 */
        CHECK_ERROR(_readMethod_referenda_kill_V7(c, &method->basic.referenda_kill_V7))
        break;
    case 26373: /* module 103 call 5 */
        CHECK_ERROR(_readMethod_referenda_nudge_referendum_V7(c, &method->basic.referenda_nudge_referendum_V7))
        break;
    case 26374: /* module 103 call 6 */
        CHECK_ERROR(_readMethod_referenda_one_fewer_deciding_V7(c, &method->basic.referenda_one_fewer_deciding_V7))
        break;
    case 26375: /* module 103 call 7 */
        CHECK_ERROR(_readMethod_referenda_refund_submission_deposit_V7(c, &method->basic.referenda_refund_submission_deposit_V7))
        break;
    case 26376: /* module 103 call 8 */
        CHECK_ERROR(_readMethod_referenda_set_metadata_V7(c, &method->basic.referenda_set_metadata_V7))
        break;
    case 26880: /* module 105 call 0 */
        CHECK_ERROR(_readMethod_whitelist_whitelist_call_V7(c, &method->basic.whitelist_whitelist_call_V7))
        break;
    case 26881: /* module 105 call 1 */
        CHECK_ERROR(_readMethod_whitelist_remove_whitelisted_call_V7(c, &method->basic.whitelist_remove_whitelisted_call_V7))
        break;
    case 26882: /* module 105 call 2 */
        CHECK_ERROR(_readMethod_whitelist_dispatch_whitelisted_call_V7(c, &method->basic.whitelist_dispatch_whitelisted_call_V7))
        break;
    case 26883: /* module 105 call 3 */
        CHECK_ERROR(_readMethod_whitelist_dispatch_whitelisted_call_with_preimage_V7(c, &method->basic.whitelist_dispatch_whitelisted_call_with_preimage_V7))
        break;
    case 5123: /* module 20 call 3 */
        CHECK_ERROR(_readMethod_utility_dispatch_as_V7(c, &method->basic.utility_dispatch_as_V7))
        break;
    case 5125: /* module 20 call 5 */
        CHECK_ERROR(_readMethod_utility_with_weight_V7(c, &method->basic.utility_with_weight_V7))
        break;
    case 27648: /* module 108 call 0 */
        CHECK_ERROR(_readMethod_identity_add_registrar_V7(c, &method->basic.identity_add_registrar_V7))
        break;
    case 27649: /* module 108 call 1 */
        CHECK_ERROR(_readMethod_identity_set_identity_V7(c, &method->basic.identity_set_identity_V7))
        break;
    case 27650: /* module 108 call 2 */
        CHECK_ERROR(_readMethod_identity_set_subs_V7(c, &method->basic.identity_set_subs_V7))
        break;
    case 27651: /* module 108 call 3 */
        CHECK_ERROR(_readMethod_identity_clear_identity_V7(c, &method->basic.identity_clear_identity_V7))
        break;
    case 27652: /* module 108 call 4 */
        CHECK_ERROR(_readMethod_identity_request_judgement_V7(c, &method->basic.identity_request_judgement_V7))
        break;
    case 27653: /* module 108 call 5 */
        CHECK_ERROR(_readMethod_identity_cancel_request_V7(c, &method->basic.identity_cancel_request_V7))
        break;
    case 27654: /* module 108 call 6 */
        CHECK_ERROR(_readMethod_identity_set_fee_V7(c, &method->basic.identity_set_fee_V7))
        break;
    case 27655: /* module 108 call 7 */
        CHECK_ERROR(_readMethod_identity_set_account_id_V7(c, &method->basic.identity_set_account_id_V7))
        break;
    case 27657: /* module 108 call 9 */
        CHECK_ERROR(_readMethod_identity_provide_judgement_V7(c, &method->basic.identity_provide_judgement_V7))
        break;
    case 27658: /* module 108 call 10 */
        CHECK_ERROR(_readMethod_identity_kill_identity_V7(c, &method->basic.identity_kill_identity_V7))
        break;
    case 27659: /* module 108 call 11 */
        CHECK_ERROR(_readMethod_identity_add_sub_V7(c, &method->basic.identity_add_sub_V7))
        break;
    case 27660: /* module 108 call 12 */
        CHECK_ERROR(_readMethod_identity_rename_sub_V7(c, &method->basic.identity_rename_sub_V7))
        break;
    case 27661: /* module 108 call 13 */
        CHECK_ERROR(_readMethod_identity_remove_sub_V7(c, &method->basic.identity_remove_sub_V7))
        break;
    case 27662: /* module 108 call 14 */
        CHECK_ERROR(_readMethod_identity_quit_sub_V7(c, &method->basic.identity_quit_sub_V7))
        break;
    case 7424: /* module 29 call 0 */
        CHECK_ERROR(_readMethod_proxy_proxy_V7(c, &method->nested.proxy_proxy_V7))
        break;
    case 7425: /* module 29 call 1 */
        CHECK_ERROR(_readMethod_proxy_add_proxy_V7(c, &method->nested.proxy_add_proxy_V7))
        break;
    case 7426: /* module 29 call 2 */
        CHECK_ERROR(_readMethod_proxy_remove_proxy_V7(c, &method->nested.proxy_remove_proxy_V7))
        break;
    case 7427: /* module 29 call 3 */
        CHECK_ERROR(_readMethod_proxy_remove_proxies_V7(c, &method->basic.proxy_remove_proxies_V7))
        break;
    case 7428: /* module 29 call 4 */
        CHECK_ERROR(_readMethod_proxy_create_pure_V7(c, &method->nested.proxy_create_pure_V7))
        break;
    case 7429: /* module 29 call 5 */
        CHECK_ERROR(_readMethod_proxy_kill_pure_V7(c, &method->nested.proxy_kill_pure_V7))
        break;
    case 7433: /* module 29 call 9 */
        CHECK_ERROR(_readMethod_proxy_proxy_announced_V7(c, &method->basic.proxy_proxy_announced_V7))
        break;
    case 5376: /* module 21 call 0 */
        CHECK_ERROR(_readMethod_multisig_as_multi_threshold_1_V7(c, &method->nested.multisig_as_multi_threshold_1_V7))
        break;
    case 5377: /* module 21 call 1 */
        CHECK_ERROR(_readMethod_multisig_as_multi_V7(c, &method->nested.multisig_as_multi_V7))
        break;
    case 5378: /* module 21 call 2 */
        CHECK_ERROR(_readMethod_multisig_approve_as_multi_V7(c, &method->nested.multisig_approve_as_multi_V7))
        break;
    case 5379: /* module 21 call 3 */
        CHECK_ERROR(_readMethod_multisig_cancel_as_multi_V7(c, &method->nested.multisig_cancel_as_multi_V7))
        break;
    case 4352: /* module 17 call 0 */
        CHECK_ERROR(_readMethod_voterlist_rebag_V7(c, &method->basic.voterlist_rebag_V7))
        break;
    case 4353: /* module 17 call 1 */
        CHECK_ERROR(_readMethod_voterlist_put_in_front_of_V7(c, &method->basic.voterlist_put_in_front_of_V7))
        break;
    case 4354: /* module 17 call 2 */
        CHECK_ERROR(_readMethod_voterlist_put_in_front_of_other_V7(c, &method->basic.voterlist_put_in_front_of_other_V7))
        break;
    case 13056: /* module 51 call 0 */
        CHECK_ERROR(_readMethod_configuration_set_validation_upgrade_cooldown_V7(c, &method->basic.configuration_set_validation_upgrade_cooldown_V7))
        break;
    case 13057: /* module 51 call 1 */
        CHECK_ERROR(_readMethod_configuration_set_validation_upgrade_delay_V7(c, &method->basic.configuration_set_validation_upgrade_delay_V7))
        break;
    case 13058: /* module 51 call 2 */
        CHECK_ERROR(_readMethod_configuration_set_code_retention_period_V7(c, &method->basic.configuration_set_code_retention_period_V7))
        break;
    case 13059: /* module 51 call 3 */
        CHECK_ERROR(_readMethod_configuration_set_max_code_size_V7(c, &method->basic.configuration_set_max_code_size_V7))
        break;
    case 13060: /* module 51 call 4 */
        CHECK_ERROR(_readMethod_configuration_set_max_pov_size_V7(c, &method->basic.configuration_set_max_pov_size_V7))
        break;
    case 13061: /* module 51 call 5 */
        CHECK_ERROR(_readMethod_configuration_set_max_head_data_size_V7(c, &method->basic.configuration_set_max_head_data_size_V7))
        break;
    case 13062: /* module 51 call 6 */
        CHECK_ERROR(_readMethod_configuration_set_on_demand_cores_V7(c, &method->basic.configuration_set_on_demand_cores_V7))
        break;
    case 13063: /* module 51 call 7 */
        CHECK_ERROR(_readMethod_configuration_set_on_demand_retries_V7(c, &method->basic.configuration_set_on_demand_retries_V7))
        break;
    case 13064: /* module 51 call 8 */
        CHECK_ERROR(_readMethod_configuration_set_group_rotation_frequency_V7(c, &method->basic.configuration_set_group_rotation_frequency_V7))
        break;
    case 13065: /* module 51 call 9 */
        CHECK_ERROR(_readMethod_configuration_set_paras_availability_period_V7(c, &method->basic.configuration_set_paras_availability_period_V7))
        break;
    case 13067: /* module 51 call 11 */
        CHECK_ERROR(_readMethod_configuration_set_scheduling_lookahead_V7(c, &method->basic.configuration_set_scheduling_lookahead_V7))
        break;
    case 13068: /* module 51 call 12 */
        CHECK_ERROR(_readMethod_configuration_set_max_validators_per_core_V7(c, &method->basic.configuration_set_max_validators_per_core_V7))
        break;
    case 13069: /* module 51 call 13 */
        CHECK_ERROR(_readMethod_configuration_set_max_validators_V7(c, &method->basic.configuration_set_max_validators_V7))
        break;
    case 13071: /* module 51 call 15 */
        CHECK_ERROR(_readMethod_configuration_set_dispute_post_conclusion_acceptance_period_V7(c, &method->basic.configuration_set_dispute_post_conclusion_acceptance_period_V7))
        break;
    case 13074: /* module 51 call 18 */
        CHECK_ERROR(_readMethod_configuration_set_no_show_slots_V7(c, &method->basic.configuration_set_no_show_slots_V7))
        break;
    case 13075: /* module 51 call 19 */
        CHECK_ERROR(_readMethod_configuration_set_n_delay_tranches_V7(c, &method->basic.configuration_set_n_delay_tranches_V7))
        break;
    case 13076: /* module 51 call 20 */
        CHECK_ERROR(_readMethod_configuration_set_zeroth_delay_tranche_width_V7(c, &method->basic.configuration_set_zeroth_delay_tranche_width_V7))
        break;
    case 13077: /* module 51 call 21 */
        CHECK_ERROR(_readMethod_configuration_set_needed_approvals_V7(c, &method->basic.configuration_set_needed_approvals_V7))
        break;
    case 13078: /* module 51 call 22 */
        CHECK_ERROR(_readMethod_configuration_set_relay_vrf_modulo_samples_V7(c, &method->basic.configuration_set_relay_vrf_modulo_samples_V7))
        break;
    case 13079: /* module 51 call 23 */
        CHECK_ERROR(_readMethod_configuration_set_max_upward_queue_count_V7(c, &method->basic.configuration_set_max_upward_queue_count_V7))
        break;
    case 13080: /* module 51 call 24 */
        CHECK_ERROR(_readMethod_configuration_set_max_upward_queue_size_V7(c, &method->basic.configuration_set_max_upward_queue_size_V7))
        break;
    case 13081: /* module 51 call 25 */
        CHECK_ERROR(_readMethod_configuration_set_max_downward_message_size_V7(c, &method->basic.configuration_set_max_downward_message_size_V7))
        break;
    case 13083: /* module 51 call 27 */
        CHECK_ERROR(_readMethod_configuration_set_max_upward_message_size_V7(c, &method->basic.configuration_set_max_upward_message_size_V7))
        break;
    case 13084: /* module 51 call 28 */
        CHECK_ERROR(_readMethod_configuration_set_max_upward_message_num_per_candidate_V7(c, &method->basic.configuration_set_max_upward_message_num_per_candidate_V7))
        break;
    case 13085: /* module 51 call 29 */
        CHECK_ERROR(_readMethod_configuration_set_hrmp_open_request_ttl_V7(c, &method->basic.configuration_set_hrmp_open_request_ttl_V7))
        break;
    case 13086: /* module 51 call 30 */
        CHECK_ERROR(_readMethod_configuration_set_hrmp_sender_deposit_V7(c, &method->basic.configuration_set_hrmp_sender_deposit_V7))
        break;
    case 13087: /* module 51 call 31 */
        CHECK_ERROR(_readMethod_configuration_set_hrmp_recipient_deposit_V7(c, &method->basic.configuration_set_hrmp_recipient_deposit_V7))
        break;
    case 13088: /* module 51 call 32 */
        CHECK_ERROR(_readMethod_configuration_set_hrmp_channel_max_capacity_V7(c, &method->basic.configuration_set_hrmp_channel_max_capacity_V7))
        break;
    case 13089: /* module 51 call 33 */
        CHECK_ERROR(_readMethod_configuration_set_hrmp_channel_max_total_size_V7(c, &method->basic.configuration_set_hrmp_channel_max_total_size_V7))
        break;
    case 13090: /* module 51 call 34 */
        CHECK_ERROR(_readMethod_configuration_set_hrmp_max_parachain_inbound_channels_V7(c, &method->basic.configuration_set_hrmp_max_parachain_inbound_channels_V7))
        break;
    case 13092: /* module 51 call 36 */
        CHECK_ERROR(_readMethod_configuration_set_hrmp_channel_max_message_size_V7(c, &method->basic.configuration_set_hrmp_channel_max_message_size_V7))
        break;
    case 13093: /* module 51 call 37 */
        CHECK_ERROR(_readMethod_configuration_set_hrmp_max_parachain_outbound_channels_V7(c, &method->basic.configuration_set_hrmp_max_parachain_outbound_channels_V7))
        break;
    case 13095: /* module 51 call 39 */
        CHECK_ERROR(_readMethod_configuration_set_hrmp_max_message_num_per_candidate_V7(c, &method->basic.configuration_set_hrmp_max_message_num_per_candidate_V7))
        break;
    case 13098: /* module 51 call 42 */
        CHECK_ERROR(_readMethod_configuration_set_pvf_voting_ttl_V7(c, &method->basic.configuration_set_pvf_voting_ttl_V7))
        break;
    case 13099: /* module 51 call 43 */
        CHECK_ERROR(_readMethod_configuration_set_minimum_validation_upgrade_delay_V7(c, &method->basic.configuration_set_minimum_validation_upgrade_delay_V7))
        break;
    case 13100: /* module 51 call 44 */
        CHECK_ERROR(_readMethod_configuration_set_bypass_consistency_check_V7(c, &method->basic.configuration_set_bypass_consistency_check_V7))
        break;
    case 13103: /* module 51 call 47 */
        CHECK_ERROR(_readMethod_configuration_set_on_demand_base_fee_V7(c, &method->basic.configuration_set_on_demand_base_fee_V7))
        break;
    case 13104: /* module 51 call 48 */
        CHECK_ERROR(_readMethod_configuration_set_on_demand_fee_variability_V7(c, &method->basic.configuration_set_on_demand_fee_variability_V7))
        break;
    case 13105: /* module 51 call 49 */
        CHECK_ERROR(_readMethod_configuration_set_on_demand_queue_max_size_V7(c, &method->basic.configuration_set_on_demand_queue_max_size_V7))
        break;
    case 13106: /* module 51 call 50 */
        CHECK_ERROR(_readMethod_configuration_set_on_demand_target_queue_utilization_V7(c, &method->basic.configuration_set_on_demand_target_queue_utilization_V7))
        break;
    case 13107: /* module 51 call 51 */
        CHECK_ERROR(_readMethod_configuration_set_on_demand_ttl_V7(c, &method->basic.configuration_set_on_demand_ttl_V7))
        break;
    case 13108: /* module 51 call 52 */
        CHECK_ERROR(_readMethod_configuration_set_minimum_backing_votes_V7(c, &method->basic.configuration_set_minimum_backing_votes_V7))
        break;
    case 14592: /* module 57 call 0 */
        CHECK_ERROR(_readMethod_initializer_force_approve_V7(c, &method->basic.initializer_force_approve_V7))
        break;
    case 15872: /* module 62 call 0 */
        CHECK_ERROR(_readMethod_parasdisputes_force_unfreeze_V7(c, &method->basic.parasdisputes_force_unfreeze_V7))
        break;
    case 18432: /* module 72 call 0 */
        CHECK_ERROR(_readMethod_auctions_new_auction_V7(c, &method->basic.auctions_new_auction_V7))
        break;
    case 18433: /* module 72 call 1 */
        CHECK_ERROR(_readMethod_auctions_bid_V7(c, &method->basic.auctions_bid_V7))
        break;
    case 18434: /* module 72 call 2 */
        CHECK_ERROR(_readMethod_auctions_cancel_auction_V7(c, &method->basic.auctions_cancel_auction_V7))
        break;
///////////////////////////////////////
// Custom
///////////////////////////////////////
    case 27904: /* module 109 call 0 */
        CHECK_ERROR(_readMethod_votemanager_vote_V7(c, &method->basic.votemanager_vote_V7))
        break;
    case 27905: /* module 109 call 1 */
        CHECK_ERROR(_readMethod_votemanager_remove_vote_V7(c, &method->basic.votemanager_remove_vote_V7))
        break;
    case 27906: /* module 109 call 2 */
        CHECK_ERROR(_readMethod_votemanager_remove_other_vote_V7(c, &method->basic.votemanager_remove_other_vote_V7))
        break;
    case 27907: /* module 109 call 3 */
        CHECK_ERROR(_readMethod_votemanager_unlock_V7(c, &method->basic.votemanager_unlock_V7))
        break;
    case 64512: /* module 252 call 0 */
        CHECK_ERROR(_readMethod_validatormanager_register_validators_V7(c, &method->basic.validatormanager_register_validators_V7))
        break;
    case 64513: /* module 252 call 1 */
        CHECK_ERROR(_readMethod_validatormanager_deregister_validators_V7(c, &method->basic.validatormanager_deregister_validators_V7))
        break;
    case 65280: /* module 255 call 0 */
        CHECK_ERROR(_readMethod_extrinsicpause_pause_extrinsic_V7(c, &method->basic.extrinsicpause_pause_extrinsic_V7))
        break;
    case 65281: /* module 255 call 1 */
        CHECK_ERROR(_readMethod_extrinsicpause_resume_extrinsic_V7(c, &method->basic.extrinsicpause_resume_extrinsic_V7))
        break;
    case 4864: /* module 19 call 0 */
        CHECK_ERROR(_readMethod_stakeexchange_create_offer_V7(c, &method->basic.stakeexchange_create_offer_V7))
            break;
    case 4865: /* module 19 call 1 */
        CHECK_ERROR(_readMethod_stakeexchange_cancel_offer_V7(c, &method->basic.stakeexchange_cancel_offer_V7))
        break;
    case 4866: /* module 19 call 2 */
        CHECK_ERROR(_readMethod_stakeexchange_configure_liquidity_account_V7(c, &method->basic.stakeexchange_configure_liquidity_account_V7))
        break;
    case 4867: /* module 19 call 3 */
        CHECK_ERROR(_readMethod_stakeexchange_withdraw_liquidity_V7(c, &method->basic.stakeexchange_withdraw_liquidity_V7))
        break;
    case 4868: /* module 19 call 4 */
        CHECK_ERROR(_readMethod_stakeexchange_add_liquidity_V7(c, &method->basic.stakeexchange_add_liquidity_V7))
        break;
    case 4869: /* module 19 call 5 */
        CHECK_ERROR(_readMethod_stakeexchange_buy_V7(c, &method->basic.stakeexchange_buy_V7))
        break;
    case 64768: /* module 253 call 0 */
        CHECK_ERROR(_readMethod_multitokens_create_collection_V7(c, &method->basic.multitokens_create_collection_V7))
        break;
    case 64769: /* module 253 call 1 */
        CHECK_ERROR(_readMethod_multitokens_destroy_collection_V7(c, &method->basic.multitokens_destroy_collection_V7))
        break;
    case 64770: /* module 253 call 2 */
        CHECK_ERROR(_readMethod_multitokens_mutate_collection_V7(c, &method->basic.multitokens_mutate_collection_V7))
        break;
    case 64773: /* module 253 call 5 */
        CHECK_ERROR(_readMethod_multitokens_burn_V7(c, &method->basic.multitokens_burn_V7))
        break;
    case 64774: /* module 253 call 6 */
        CHECK_ERROR(_readMethod_multitokens_transfer_V7(c, &method->basic.multitokens_transfer_V7))
        break;
    case 64775: /* module 253 call 7 */
        CHECK_ERROR(_readMethod_multitokens_freeze_V7(c, &method->basic.multitokens_freeze_V7))
        break;
    case 64776: /* module 253 call 8 */
        CHECK_ERROR(_readMethod_multitokens_thaw_V7(c, &method->basic.multitokens_thaw_V7))
        break;
    case 64777: /* module 253 call 9 */
        CHECK_ERROR(_readMethod_multitokens_set_attribute_V7(c, &method->basic.multitokens_set_attribute_V7))
        break;
    case 64778: /* module 253 call 10 */
        CHECK_ERROR(_readMethod_multitokens_remove_attribute_V7(c, &method->basic.multitokens_remove_attribute_V7))
        break;
    case 64779: /* module 253 call 11 */
        CHECK_ERROR(_readMethod_multitokens_remove_all_attributes_V7(c, &method->basic.multitokens_remove_all_attributes_V7))
        break;
    case 64780: /* module 253 call 12 */
        CHECK_ERROR(_readMethod_multitokens_batch_transfer_V7(c, &method->basic.multitokens_batch_transfer_V7))
        break;
    case 64782: /* module 253 call 14 */
        CHECK_ERROR(_readMethod_multitokens_batch_set_attribute_V7(c, &method->basic.multitokens_batch_set_attribute_V7))
        break;
    case 64783: /* module 253 call 15 */
        CHECK_ERROR(_readMethod_multitokens_approve_collection_V7(c, &method->basic.multitokens_approve_collection_V7))
        break;
    case 64784: /* module 253 call 16 */
        CHECK_ERROR(_readMethod_multitokens_unapprove_collection_V7(c, &method->basic.multitokens_unapprove_collection_V7))
        break;
    case 64785: /* module 253 call 17 */
        CHECK_ERROR(_readMethod_multitokens_approve_token_V7(c, &method->basic.multitokens_approve_token_V7))
        break;
    case 64786: /* module 253 call 18 */
        CHECK_ERROR(_readMethod_multitokens_unapprove_token_V7(c, &method->basic.multitokens_unapprove_token_V7))
        break;
    case 64800: /* module 253 call 32 */
        CHECK_ERROR(_readMethod_multitokens_claim_collections_V7(c, &method->basic.multitokens_claim_collections_V7))
        break;
    case 64801: /* module 253 call 33 */
        CHECK_ERROR(_readMethod_multitokens_claim_tokens_V7(c, &method->basic.multitokens_claim_tokens_V7))
        break;
    case 64771: /* module 253 call 3 */
        CHECK_ERROR(_readMethod_multitokens_mutate_token_V7(c, &method->basic.multitokens_mutate_token_V7))
        break;
    case 64772: /* module 253 call 4 */
        CHECK_ERROR(_readMethod_multitokens_mint_V7(c, &method->basic.multitokens_mint_V7))
        break;
    case 64781: /* module 253 call 13 */
        CHECK_ERROR(_readMethod_multitokens_batch_mint_V7(c, &method->basic.multitokens_batch_mint_V7))
        break;
    case 64787: /* module 253 call 19 */
        CHECK_ERROR(_readMethod_multitokens_force_mutate_collection_V7(c, &method->basic.multitokens_force_mutate_collection_V7))
        break;
    case 64788: /* module 253 call 20 */
        CHECK_ERROR(_readMethod_multitokens_force_transfer_V7(c, &method->basic.multitokens_force_transfer_V7))
        break;
    case 64789: /* module 253 call 21 */
        CHECK_ERROR(_readMethod_multitokens_force_set_collection_V7(c, &method->basic.multitokens_force_set_collection_V7))
        break;
    case 64790: /* module 253 call 22 */
        CHECK_ERROR(_readMethod_multitokens_force_set_token_V7(c, &method->basic.multitokens_force_set_token_V7))
        break;
    case 64791: /* module 253 call 23 */
        CHECK_ERROR(_readMethod_multitokens_force_set_attribute_V7(c, &method->basic.multitokens_force_set_attribute_V7))
        break;
    case 64792: /* module 253 call 24 */
        CHECK_ERROR(_readMethod_multitokens_force_set_collection_account_V7(c, &method->basic.multitokens_force_set_collection_account_V7))
        break;
    case 64793: /* module 253 call 25 */
        CHECK_ERROR(_readMethod_multitokens_force_set_token_account_V7(c, &method->basic.multitokens_force_set_token_account_V7))
        break;
    case 64794: /* module 253 call 26 */
        CHECK_ERROR(_readMethod_multitokens_force_create_collection_V7(c, &method->basic.multitokens_force_create_collection_V7))
        break;
    case 64795: /* module 253 call 27 */
        CHECK_ERROR(_readMethod_multitokens_force_mint_V7(c, &method->basic.multitokens_force_mint_V7))
        break;
    case 64796: /* module 253 call 28 */
        CHECK_ERROR(_readMethod_multitokens_force_burn_V7(c, &method->basic.multitokens_force_burn_V7))
        break;
    case 64797: /* module 253 call 29 */
        CHECK_ERROR(_readMethod_multitokens_force_approve_collection_V7(c, &method->basic.multitokens_force_approve_collection_V7))
        break;
    case 64798: /* module 253 call 30 */
        CHECK_ERROR(_readMethod_multitokens_force_freeze_V7(c, &method->basic.multitokens_force_freeze_V7))
        break;
    case 64799: /* module 253 call 31 */
        CHECK_ERROR(_readMethod_multitokens_force_set_next_collection_id_V7(c, &method->basic.multitokens_force_set_next_collection_id_V7))
        break;
    case 4608: /* module 18 call 0 */
        CHECK_ERROR(_readMethod_nominationpools_bond_V7(c, &method->basic.nominationpools_bond_V7))
        break;
    case 4611: /* module 18 call 3 */
        CHECK_ERROR(_readMethod_nominationpools_unbond_V7(c, &method->basic.nominationpools_unbond_V7))
        break;
    case 4612: /* module 18 call 4 */
        CHECK_ERROR(_readMethod_nominationpools_pool_withdraw_unbonded_V7(c, &method->basic.nominationpools_pool_withdraw_unbonded_V7))
        break;
    case 4613: /* module 18 call 5 */
        CHECK_ERROR(_readMethod_nominationpools_withdraw_unbonded_V7(c, &method->basic.nominationpools_withdraw_unbonded_V7))
        break;
    case 4614: /* module 18 call 6 */
        CHECK_ERROR(_readMethod_nominationpools_create_V7(c, &method->basic.nominationpools_create_V7))
        break;
    case 4616: /* module 18 call 8 */
        CHECK_ERROR(_readMethod_nominationpools_nominate_V7(c, &method->basic.nominationpools_nominate_V7))
        break;
    case 4619: /* module 18 call 11 */
        CHECK_ERROR(_readMethod_nominationpools_set_configs_V7(c, &method->basic.nominationpools_set_configs_V7))
        break;
    case 4621: /* module 18 call 13 */
        CHECK_ERROR(_readMethod_nominationpools_chill_V7(c, &method->basic.nominationpools_chill_V7))
        break;
    case 4622: /* module 18 call 14 */
        CHECK_ERROR(_readMethod_nominationpools_destroy_V7(c, &method->basic.nominationpools_destroy_V7))
        break;
    case 4626: /* module 18 call 18 */
        CHECK_ERROR(_readMethod_nominationpools_payout_rewards_V7(c, &method->basic.nominationpools_payout_rewards_V7))
        break;
    case 4627: /* module 18 call 19 */
        CHECK_ERROR(_readMethod_nominationpools_mutate_V7(c, &method->basic.nominationpools_mutate_V7))
        break;
    case 4628: /* module 18 call 20 */
        CHECK_ERROR(_readMethod_nominationpools_unbond_deposit_V7(c, &method->basic.nominationpools_unbond_deposit_V7))
        break;
    case 4629: /* module 18 call 21 */
        CHECK_ERROR(_readMethod_nominationpools_withdraw_deposit_V7(c, &method->basic.nominationpools_withdraw_deposit_V7))
        break;
    case 4630: /* module 18 call 22 */
        CHECK_ERROR(_readMethod_nominationpools_set_staking_info_V7(c, &method->basic.nominationpools_set_staking_info_V7))
        break;
    case 4631: /* module 18 call 23 */
        CHECK_ERROR(_readMethod_nominationpools_calculate_early_bird_bonus_V7(c, &method->basic.nominationpools_calculate_early_bird_bonus_V7))
        break;
    case 4632: /* module 18 call 24 */
        CHECK_ERROR(_readMethod_nominationpools_pay_early_bird_bonus_V7(c, &method->basic.nominationpools_pay_early_bird_bonus_V7))
        break;
    case 4633: /* module 18 call 25 */
        CHECK_ERROR(_readMethod_nominationpools_process_payouts_V7(c, &method->basic.nominationpools_process_payouts_V7))
        break;
    case 4634: /* module 18 call 26 */
        CHECK_ERROR(_readMethod_nominationpools_withdraw_free_balance_V7(c, &method->basic.nominationpools_withdraw_free_balance_V7))
        break;
    case 4635: /* module 18 call 27 */
        CHECK_ERROR(_readMethod_nominationpools_capture_early_bird_bonus_shares_V7(c, &method->basic.nominationpools_capture_early_bird_bonus_shares_V7))
        break;
    case 4636: /* module 18 call 28 */
        CHECK_ERROR(_readMethod_nominationpools_unlock_early_bird_bonus_V7(c, &method->basic.nominationpools_unlock_early_bird_bonus_V7))
        break;
    case 27136: /* module 106 call 0 */
        CHECK_ERROR(_readMethod_fellowshipcollective_add_member_V7(c, &method->basic.fellowshipcollective_add_member_V7))
        break;
    case 27137: /* module 106 call 1 */
        CHECK_ERROR(_readMethod_fellowshipcollective_promote_member_V7(c, &method->basic.fellowshipcollective_promote_member_V7))
        break;
    case 27138: /* module 106 call 2 */
        CHECK_ERROR(_readMethod_fellowshipcollective_demote_member_V7(c, &method->basic.fellowshipcollective_demote_member_V7))
        break;
    case 27139: /* module 106 call 3 */
        CHECK_ERROR(_readMethod_fellowshipcollective_remove_member_V7(c, &method->basic.fellowshipcollective_remove_member_V7))
        break;
    case 27140: /* module 106 call 4 */
        CHECK_ERROR(_readMethod_fellowshipcollective_vote_V7(c, &method->basic.fellowshipcollective_vote_V7))
        break;
    case 27141: /* module 106 call 5 */
        CHECK_ERROR(_readMethod_fellowshipcollective_cleanup_poll_V7(c, &method->basic.fellowshipcollective_cleanup_poll_V7))
        break;
    case 27392: /* module 107 call 0 */
        CHECK_ERROR(_readMethod_fellowshipreferenda_submit_V7(c, &method->basic.fellowshipreferenda_submit_V7))
        break;
    case 27393: /* module 107 call 1 */
        CHECK_ERROR(_readMethod_fellowshipreferenda_place_decision_deposit_V7(c, &method->basic.fellowshipreferenda_place_decision_deposit_V7))
        break;
    case 27394: /* module 107 call 2 */
        CHECK_ERROR(_readMethod_fellowshipreferenda_refund_decision_deposit_V7(c, &method->basic.fellowshipreferenda_refund_decision_deposit_V7))
        break;
    case 27395: /* module 107 call 3 */
        CHECK_ERROR(_readMethod_fellowshipreferenda_cancel_V7(c, &method->basic.fellowshipreferenda_cancel_V7))
        break;
    case 27396: /* module 107 call 4 */
        CHECK_ERROR(_readMethod_fellowshipreferenda_kill_V7(c, &method->basic.fellowshipreferenda_kill_V7))
        break;
    case 27397: /* module 107 call 5 */
        CHECK_ERROR(_readMethod_fellowshipreferenda_nudge_referendum_V7(c, &method->basic.fellowshipreferenda_nudge_referendum_V7))
        break;
    case 27398: /* module 107 call 6 */
        CHECK_ERROR(_readMethod_fellowshipreferenda_one_fewer_deciding_V7(c, &method->basic.fellowshipreferenda_one_fewer_deciding_V7))
        break;
    case 27399: /* module 107 call 7 */
        CHECK_ERROR(_readMethod_fellowshipreferenda_refund_submission_deposit_V7(c, &method->basic.fellowshipreferenda_refund_submission_deposit_V7))
        break;
    case 27400: /* module 107 call 8 */
        CHECK_ERROR(_readMethod_fellowshipreferenda_set_metadata_V7(c, &method->basic.fellowshipreferenda_set_metadata_V7))
        break;
    case 63744: /* module 249 call 0 */
        CHECK_ERROR(_readMethod_marketplace_create_listing_V7(c, &method->basic.marketplace_create_listing_V7))
        break;
    case 63745: /* module 249 call 1 */
        CHECK_ERROR(_readMethod_marketplace_cancel_listing_V7(c, &method->basic.marketplace_cancel_listing_V7))
        break;
    case 63746: /* module 249 call 2 */
        CHECK_ERROR(_readMethod_marketplace_fill_listing_V7(c, &method->basic.marketplace_fill_listing_V7))
        break;
    case 63747: /* module 249 call 3 */
        CHECK_ERROR(_readMethod_marketplace_place_bid_V7(c, &method->basic.marketplace_place_bid_V7))
        break;
    case 63748: /* module 249 call 4 */
        CHECK_ERROR(_readMethod_marketplace_finalize_auction_V7(c, &method->basic.marketplace_finalize_auction_V7))
        break;
    case 13824: /* module 54 call 0 */
        CHECK_ERROR(_readMethod_fueltanks_create_fuel_tank_V7(c, &method->basic.fueltanks_create_fuel_tank_V7))
        break;
    case 13825: /* module 54 call 1 */
        CHECK_ERROR(_readMethod_fueltanks_mutate_fuel_tank_V7(c, &method->basic.fueltanks_mutate_fuel_tank_V7))
        break;
    case 13826: /* module 54 call 2 */
        CHECK_ERROR(_readMethod_fueltanks_add_account_V7(c, &method->basic.fueltanks_add_account_V7))
        break;
    case 13827: /* module 54 call 3 */
        CHECK_ERROR(_readMethod_fueltanks_remove_account_V7(c, &method->basic.fueltanks_remove_account_V7))
        break;
    case 13828: /* module 54 call 4 */
        CHECK_ERROR(_readMethod_fueltanks_remove_account_rule_data_V7(c, &method->basic.fueltanks_remove_account_rule_data_V7))
        break;
    case 13829: /* module 54 call 5 */
        CHECK_ERROR(_readMethod_fueltanks_dispatch_V7(c, &method->basic.fueltanks_dispatch_V7))
        break;
    case 13830: /* module 54 call 6 */
        CHECK_ERROR(_readMethod_fueltanks_dispatch_and_touch_V7(c, &method->basic.fueltanks_dispatch_and_touch_V7))
        break;
    case 13831: /* module 54 call 7 */
        CHECK_ERROR(_readMethod_fueltanks_schedule_mutate_freeze_state_V7(c, &method->basic.fueltanks_schedule_mutate_freeze_state_V7))
        break;
    case 13832: /* module 54 call 8 */
        CHECK_ERROR(_readMethod_fueltanks_insert_rule_set_V7(c, &method->basic.fueltanks_insert_rule_set_V7))
        break;
    case 13833: /* module 54 call 9 */
        CHECK_ERROR(_readMethod_fueltanks_remove_rule_set_V7(c, &method->basic.fueltanks_remove_rule_set_V7))
        break;
    case 13834: /* module 54 call 10 */
        CHECK_ERROR(_readMethod_fueltanks_batch_add_account_V7(c, &method->basic.fueltanks_batch_add_account_V7))
        break;
    case 13835: /* module 54 call 11 */
        CHECK_ERROR(_readMethod_fueltanks_batch_remove_account_V7(c, &method->basic.fueltanks_batch_remove_account_V7))
        break;
    case 13836: /* module 54 call 12 */
        CHECK_ERROR(_readMethod_fueltanks_force_set_consumption_V7(c, &method->basic.fueltanks_force_set_consumption_V7))
        break;
    case 13837: /* module 54 call 13 */
        CHECK_ERROR(_readMethod_fueltanks_destroy_fuel_tank_V7(c, &method->basic.fueltanks_destroy_fuel_tank_V7))
        break;
    case 13838: /* module 54 call 14 */
        CHECK_ERROR(_readMethod_fueltanks_force_create_fuel_tank_V7(c, &method->basic.fueltanks_force_create_fuel_tank_V7))
        break;
    case 13839: /* module 54 call 15 */
        CHECK_ERROR(_readMethod_fueltanks_force_batch_add_account_V7(c, &method->basic.fueltanks_force_batch_add_account_V7))
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

const char* _getMethod_ModuleName_V7(uint8_t moduleIdx)
{
    switch (moduleIdx) {
    case 6: // ok
        return STR_MO_BALANCES;
    case 7:
        return STR_MO_STAKING;
    case 10: // ok 
        return STR_MO_SESSION;
    case 20: // ok
        return STR_MO_UTILITY;
    case 73: // ok
        return STR_MO_CROWDLOAN;
#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
    case 99: // ok
        return STR_MO_XCMPALLET;
#endif
    case 0: // ok
        return STR_MO_SYSTEM;
    case 101: // ok
        return STR_MO_PREIMAGE;
    case 2: // ok
        return STR_MO_TIMESTAMP;
    case 12: // ok
        return STR_MO_TREASURY;
    case 102: // ok
        return STR_MO_CONVICTIONVOTING;
    case 103: // ok
        return STR_MO_REFERENDA;
    case 105: // ok
        return STR_MO_WHITELIST;
    case 108: // ok
        return STR_MO_IDENTITY;
    case 29:
        return STR_MO_PROXY;
    case 21: // ok
        return STR_MO_MULTISIG;
    case 17: // ok
        return STR_MO_VOTERLIST;
    case 51: // ok
        return STR_MO_CONFIGURATION;
    case 57: // ok
        return STR_MO_INITIALIZER;
    case 62: // ok
        return STR_MO_PARASDISPUTES;
    case 72: // ok
        return STR_MO_AUCTIONS;
/////////////////////////
// Custom
/////////////////////////
    case 109: // ok
        return STR_MO_VOTEMANAGER;
    case 252: // ok
        return STR_MO_VALIDATORMANAGER;
    case 255: // ok
        return STR_MO_EXTRINSICPAUSE;
    case 19: // ok
        return STR_MO_STAKEEXCHANGE;
    case 253: // ok
        return STR_MO_MULTITOKENS;
    case 18: // ok
        return STR_MO_NOMINATIONPOOLS;
    case 106: // ok
        return STR_MO_FELLOWSHIPCOLLECTIVE;
    case 107: // ok
        return STR_MO_FELLOWSHIPREFERENDA;
    case 249: // ok
        return STR_MO_MARKETPLACE;
    case 254: //
        return STR_MO_FUELTANKS;

#endif
    default:
        return NULL;
    }

    return NULL;
}

const char* _getMethod_Name_V7(uint8_t moduleIdx, uint8_t callIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 1536: /* module 6 call 0 */
        return STR_ME_TRANSFER_ALLOW_DEATH;
    case 1538: /* module 6 call 2 */
        return STR_ME_FORCE_TRANSFER;
    case 1539: /* module 6 call 3 */
        return STR_ME_TRANSFER_KEEP_ALIVE;
    case 1540: /* module 6 call 4 */
        return STR_ME_TRANSFER_ALL;
    case 2304: /* module 9 call 0 */
        return STR_ME_BOND;
    case 2305: /* module 9 call 1 */
        return STR_ME_BOND_EXTRA;
    case 2306: /* module 9 call 2 */
        return STR_ME_UNBOND;
    case 2307: /* module 9 call 3 */
        return STR_ME_WITHDRAW_UNBONDED;
    case 2308: /* module 9 call 4 */
        return STR_ME_VALIDATE;
    case 2309: /* module 9 call 5 */
        return STR_ME_NOMINATE;
    case 2310: /* module 9 call 6 */
        return STR_ME_CHILL;
    case 2311: /* module 9 call 7 */
        return STR_ME_SET_PAYEE;
    case 2312: /* module 9 call 8 */
        return STR_ME_SET_CONTROLLER;
    case 2322: /* module 9 call 18 */
        return STR_ME_PAYOUT_STAKERS;
    case 2323: /* module 9 call 19 */
        return STR_ME_REBOND;
    case 2560: /* module 10 call 0 */
        return STR_ME_SET_KEYS;
    case 2561: /* module 10 call 1 */
        return STR_ME_PURGE_KEYS;
    case 5120: /* module 20 call 0 */
        return STR_ME_BATCH;
    case 5122: /* module 20 call 2 */
        return STR_ME_BATCH_ALL;
    case 5124: /* module 20 call 4 */
        return STR_ME_FORCE_BATCH;
    case 18688: /* module 73 call 0 */
        return STR_ME_CREATE;
    case 18689: /* module 73 call 1 */
        return STR_ME_CONTRIBUTE;
    case 18690: /* module 73 call 2 */
        return STR_ME_WITHDRAW;
    case 18691: /* module 73 call 3 */
        return STR_ME_REFUND;
    case 18692: /* module 73 call 4 */
        return STR_ME_DISSOLVE;
    case 18693: /* module 73 call 5 */
        return STR_ME_EDIT;
    case 18694: /* module 73 call 6 */
        return STR_ME_ADD_MEMO;
    case 18695: /* module 73 call 7 */
        return STR_ME_POKE;
    case 18696: /* module 73 call 8 */
        return STR_ME_CONTRIBUTE_ALL;
    default:
        return _getMethod_Name_V7_ParserFull(callPrivIdx);
    }

    return NULL;
}

const char* _getMethod_Name_V7_ParserFull(uint16_t callPrivIdx)
{
    switch (callPrivIdx) {
#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
    case 25345: /* module 99 call 1 */
        return STR_ME_TELEPORT_ASSETS;
    case 25346: /* module 99 call 2 */
        return STR_ME_RESERVE_TRANSFER_ASSETS;
    case 25352: /* module 99 call 8 */
        return STR_ME_LIMITED_RESERVE_TRANSFER_ASSETS;
    case 25353: /* module 99 call 9 */
        return STR_ME_LIMITED_TELEPORT_ASSETS;
#endif
    case 0: /* module 0 call 0 */
        return STR_ME_REMARK;
    case 1: /* module 0 call 1 */
        return STR_ME_SET_HEAP_PAGES;
    case 2: /* module 0 call 2 */
        return STR_ME_SET_CODE;
    case 3: /* module 0 call 3 */
        return STR_ME_SET_CODE_WITHOUT_CHECKS;
    case 7: /* module 0 call 7 */
        return STR_ME_REMARK_WITH_EVENT;
    case 25856: /* module 101 call 0 */
        return STR_ME_NOTE_PREIMAGE;
    case 25857: /* module 101 call 1 */
        return STR_ME_UNNOTE_PREIMAGE;
    case 25858: /* module 101 call 2 */
        return STR_ME_REQUEST_PREIMAGE;
    case 25859: /* module 101 call 3 */
        return STR_ME_UNREQUEST_PREIMAGE;    
    case 1541: /* module 6 call 5 */
        return STR_ME_FORCE_UNRESERVE;
    case 1542: /* module 6 call 6 */
        return STR_ME_UPGRADE_ACCOUNTS;
    case 1544: /* module 6 call 8 */
        return STR_ME_FORCE_SET_BALANCE;
    case 2313: /* module 9 call 9 */
        return STR_ME_SET_VALIDATOR_COUNT;
    case 2314: /* module 9 call 10 */
        return STR_ME_INCREASE_VALIDATOR_COUNT;
    case 2315: /* module 9 call 11 */
        return STR_ME_SCALE_VALIDATOR_COUNT;
    case 2316: /* module 9 call 12 */
        return STR_ME_FORCE_NO_ERAS;
    case 2317: /* module 9 call 13 */
        return STR_ME_FORCE_NEW_ERA;
    case 2318: /* module 9 call 14 */
        return STR_ME_SET_INVULNERABLES;
    case 2319: /* module 9 call 15 */
        return STR_ME_FORCE_UNSTAKE;
    case 2320: /* module 9 call 16 */
        return STR_ME_FORCE_NEW_ERA_ALWAYS;
    case 2321: /* module 9 call 17 */
        return STR_ME_CANCEL_DEFERRED_SLASH;
    case 2324: /* module 9 call 20 */
        return STR_ME_REAP_STASH;
    case 2325: /* module 9 call 21 */
        return STR_ME_KICK;
    case 2326: /* module 9 call 22 */
        return STR_ME_SET_STAKING_CONFIGS;
    case 2327: /* module 9 call 23 */
        return STR_ME_CHILL_OTHER;
    case 2328: /* module 9 call 24 */
        return STR_ME_FORCE_APPLY_MIN_COMMISSION;
    case 2329: /* module 9 call 25 */
        return STR_ME_SET_MIN_COMMISSION;
    case 3072: /* module 12 call 0 */
        return STR_ME_PROPOSE_SPEND;
    case 3073: /* module 12 call 1 */
        return STR_ME_REJECT_PROPOSAL;
    case 3074: /* module 12 call 2 */
        return STR_ME_APPROVE_PROPOSAL;
    case 3075: /* module 12 call 3 */
        return STR_ME_SPEND_LOCAL;
    case 3076: /* module 12 call 4 */
        return STR_ME_REMOVE_APPROVAL;
    case 3078: /* module 12 call 6 */
        return STR_ME_PAYOUT;
    case 3079: /* module 12 call 7 */
        return STR_ME_CHECK_STATUS;
    case 3080: /* module 12 call 8 */
        return STR_ME_VOID_SPEND;
    case 26112: /* module 102 call 0 */
        return STR_ME_VOTE;
    case 26113: /* module 102 call 1 */
        return STR_ME_DELEGATE;
    case 26114: /* module 102 call 2 */
        return STR_ME_UNDELEGATE;
    case 26115: /* module 102 call 3 */
        return STR_ME_UNLOCK;
    case 26116: /* module 102 call 4 */
        return STR_ME_REMOVE_VOTE;
    case 26117: /* module 102 call 5 */
        return STR_ME_REMOVE_OTHER_VOTE;
    case 26368: /* module 103 call 0 */
        return STR_ME_SUBMIT;
    case 26369: /* module 103 call 1 */
        return STR_ME_PLACE_DECISION_DEPOSIT;
    case 26370: /* module 103 call 2 */
        return STR_ME_REFUND_DECISION_DEPOSIT;
    case 26371: /* module 103 call 3 */
        return STR_ME_CANCEL;
    case 26372: /* module 103 call 4 */
        return STR_ME_KILL;
    case 26373: /* module 103 call 5 */
        return STR_ME_NUDGE_REFERENDUM;
    case 26374: /* module 103 call 6 */
        return STR_ME_ONE_FEWER_DECIDING;
    case 26375: /* module 103 call 7 */
        return STR_ME_REFUND_SUBMISSION_DEPOSIT;
    case 26376: /* module 103 call 8 */
        return STR_ME_SET_METADATA;
    case 26880: /* module 105 call 0 */
        return STR_ME_WHITELIST_CALL;
    case 26881: /* module 105 call 1 */
        return STR_ME_REMOVE_WHITELISTED_CALL;
    case 26882: /* module 105 call 2 */
        return STR_ME_DISPATCH_WHITELISTED_CALL;
    case 26883: /* module 105 call 3 */
        return STR_ME_DISPATCH_WHITELISTED_CALL_WITH_PREIMAGE;
    case 5123: /* module 20 call 3 */
        return STR_ME_DISPATCH_AS;
    case 5125: /* module 20 call 5 */
        return STR_ME_WITH_WEIGHT;
    case 27648: /* module 108 call 0 */
        return STR_ME_ADD_REGISTRAR;
    case 27649: /* module 108 call 1 */
        return STR_ME_SET_IDENTITY;
    case 27650: /* module 108 call 2 */
        return STR_ME_SET_SUBS;
    case 27651: /* module 108 call 3 */
        return STR_ME_CLEAR_IDENTITY;
    case 27652: /* module 108 call 4 */
        return STR_ME_REQUEST_JUDGEMENT;
    case 27653: /* module 108 call 5 */
        return STR_ME_CANCEL_REQUEST;
    case 27654: /* module 108 call 6 */
        return STR_ME_SET_FEE;
    case 27655: /* module 108 call 7 */
        return STR_ME_SET_ACCOUNT_ID;
    case 27657: /* module 108 call 9 */
        return STR_ME_PROVIDE_JUDGEMENT;
    case 27658: /* module 108 call 10 */
        return STR_ME_KILL_IDENTITY;
    case 27659: /* module 108 call 11 */
        return STR_ME_ADD_SUB;
    case 27660: /* module 108 call 12 */
        return STR_ME_RENAME_SUB;
    case 27661: /* module 108 call 13 */
        return STR_ME_REMOVE_SUB;
    case 27662: /* module 108 call 14 */
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
        return STR_ME_CREATE_PURE;
    case 7429: /* module 29 call 5 */
        return STR_ME_KILL_PURE;
    case 7433: /* module 29 call 9 */
        return STR_ME_PROXY_ANNOUNCED;
    case 5376: /* module 21 call 0 */
        return STR_ME_AS_MULTI_THRESHOLD_1;
    case 5377: /* module 21 call 1 */
        return STR_ME_AS_MULTI;
    case 5378: /* module 21 call 2 */
        return STR_ME_APPROVE_AS_MULTI;
    case 5379: /* module 21 call 3 */
        return STR_ME_CANCEL_AS_MULTI;
    case 4352: /* module 17 call 0 */
        return STR_ME_REBAG;
    case 4353: /* module 17 call 1 */
        return STR_ME_PUT_IN_FRONT_OF;
    case 4354: /* module 17 call 2 */
        return STR_ME_PUT_IN_FRONT_OF_OTHER;
    case 13056: /* module 51 call 0 */
        return STR_ME_SET_VALIDATION_UPGRADE_COOLDOWN;
    case 13057: /* module 51 call 1 */
        return STR_ME_SET_VALIDATION_UPGRADE_DELAY;
    case 13058: /* module 51 call 2 */
        return STR_ME_SET_CODE_RETENTION_PERIOD;
    case 13059: /* module 51 call 3 */
        return STR_ME_SET_MAX_CODE_SIZE;
    case 13060: /* module 51 call 4 */
        return STR_ME_SET_MAX_POV_SIZE;
    case 13061: /* module 51 call 5 */
        return STR_ME_SET_MAX_HEAD_DATA_SIZE;
    case 13062: /* module 51 call 6 */
        return STR_ME_SET_ON_DEMAND_CORES;
    case 13063: /* module 51 call 7 */
        return STR_ME_SET_ON_DEMAND_RETRIES;
    case 13064: /* module 51 call 8 */
        return STR_ME_SET_GROUP_ROTATION_FREQUENCY;
    case 13065: /* module 51 call 9 */
        return STR_ME_SET_PARAS_AVAILABILITY_PERIOD;
    case 13067: /* module 51 call 11 */
        return STR_ME_SET_SCHEDULING_LOOKAHEAD;
    case 13068: /* module 51 call 12 */
        return STR_ME_SET_MAX_VALIDATORS_PER_CORE;
    case 13069: /* module 51 call 13 */
        return STR_ME_SET_MAX_VALIDATORS;
    case 13071: /* module 51 call 15 */
        return STR_ME_SET_DISPUTE_POST_CONCLUSION_ACCEPTANCE_PERIOD;
    case 13074: /* module 51 call 18 */
        return STR_ME_SET_NO_SHOW_SLOTS;
    case 13075: /* module 51 call 19 */
        return STR_ME_SET_N_DELAY_TRANCHES;
    case 13076: /* module 51 call 20 */
        return STR_ME_SET_ZEROTH_DELAY_TRANCHE_WIDTH;
    case 13077: /* module 51 call 21 */
        return STR_ME_SET_NEEDED_APPROVALS;
    case 13078: /* module 51 call 22 */
        return STR_ME_SET_RELAY_VRF_MODULO_SAMPLES;
    case 13079: /* module 51 call 23 */
        return STR_ME_SET_MAX_UPWARD_QUEUE_COUNT;
    case 13080: /* module 51 call 24 */
        return STR_ME_SET_MAX_UPWARD_QUEUE_SIZE;
    case 13081: /* module 51 call 25 */
        return STR_ME_SET_MAX_DOWNWARD_MESSAGE_SIZE;
    case 13083: /* module 51 call 27 */
        return STR_ME_SET_MAX_UPWARD_MESSAGE_SIZE;
    case 13084: /* module 51 call 28 */
        return STR_ME_SET_MAX_UPWARD_MESSAGE_NUM_PER_CANDIDATE;
    case 13085: /* module 51 call 29 */
        return STR_ME_SET_HRMP_OPEN_REQUEST_TTL;
    case 13086: /* module 51 call 30 */
        return STR_ME_SET_HRMP_SENDER_DEPOSIT;
    case 13087: /* module 51 call 31 */
        return STR_ME_SET_HRMP_RECIPIENT_DEPOSIT;
    case 13088: /* module 51 call 32 */
        return STR_ME_SET_HRMP_CHANNEL_MAX_CAPACITY;
    case 13089: /* module 51 call 33 */
        return STR_ME_SET_HRMP_CHANNEL_MAX_TOTAL_SIZE;
    case 13090: /* module 51 call 34 */
        return STR_ME_SET_HRMP_MAX_PARACHAIN_INBOUND_CHANNELS;
    case 13092: /* module 51 call 36 */
        return STR_ME_SET_HRMP_CHANNEL_MAX_MESSAGE_SIZE;
    case 13093: /* module 51 call 37 */
        return STR_ME_SET_HRMP_MAX_PARACHAIN_OUTBOUND_CHANNELS;
    case 13095: /* module 51 call 39 */
        return STR_ME_SET_HRMP_MAX_MESSAGE_NUM_PER_CANDIDATE;
    case 13098: /* module 51 call 42 */
        return STR_ME_SET_PVF_VOTING_TTL;
    case 13099: /* module 51 call 43 */
        return STR_ME_SET_MINIMUM_VALIDATION_UPGRADE_DELAY;
    case 13100: /* module 51 call 44 */
        return STR_ME_SET_BYPASS_CONSISTENCY_CHECK;
    case 13103: /* module 51 call 47 */
        return STR_ME_SET_ON_DEMAND_BASE_FEE;
    case 13104: /* module 51 call 48 */
        return STR_ME_SET_ON_DEMAND_FEE_VARIABILITY;
    case 13105: /* module 51 call 49 */
        return STR_ME_SET_ON_DEMAND_QUEUE_MAX_SIZE;
    case 13106: /* module 51 call 50 */
        return STR_ME_SET_ON_DEMAND_TARGET_QUEUE_UTILIZATION;
    case 13107: /* module 51 call 51 */
        return STR_ME_SET_ON_DEMAND_TTL;
    case 13108: /* module 51 call 52 */
        return STR_ME_SET_MINIMUM_BACKING_VOTES;
    case 14592: /* module 57 call 0 */
        return STR_ME_FORCE_APPROVE;
    case 15872: /* module 62 call 0 */
        return STR_ME_FORCE_UNFREEZE;
    case 18432: /* module 72 call 0 */
        return STR_ME_NEW_AUCTION;
    case 18433: /* module 72 call 1 */
        return STR_ME_BID;
    case 18434: /* module 72 call 2 */
        return STR_ME_CANCEL_AUCTION;
//////////////////////////////////
// Custom
//////////////////////////////////
    case 27904: /* module 109 call 0 */
        return STR_ME_VOTE;
    case 27905: /* module 109 call 1 */
        return STR_ME_REMOVE_VOTE;
    case 27906: /* module 109 call 2 */
        return STR_ME_REMOVE_OTHER_VOTE;
    case 27907: /* module 109 call 3 */
        return STR_ME_UNLOCK;
    case 64512: /* module 252 call 0 */
        return STR_ME_REGISTER_VALIDATORS;
    case 64513: /* module 252 call 1 */
        return STR_ME_DEREGISTER_VALIDATORS;
    case 65280: /* module 255 call 0 */
        return STR_ME_PAUSE_EXTRINSIC;
    case 65281: /* module 255 call 1 */
        return STR_ME_RESUME_EXTRINSIC;
    case 4865: /* module 19 call 1 */
        return STR_ME_CANCEL_OFFER;
    case 4866: /* module 19 call 2 */
        return STR_ME_CONFIGURE_LIQUIDITY_ACCOUNT;
    case 4867: /* module 19 call 3 */
        return STR_ME_WITHDRAW_LIQUIDITY;
    case 4868: /* module 19 call 4 */
        return STR_ME_ADD_LIQUIDITY;
    case 4869: /* module 19 call 5 */
        return STR_ME_BUY;
    case 64768: /* module 253 call 0 */
        return STR_ME_CREATE_COLLECTION;
    case 64769: /* module 253 call 1 */
        return STR_ME_DESTROY_COLLECTION;
    case 64770: /* module 253 call 2 */
        return STR_ME_MUTATE_COLLECTION;
    case 64771: /* module 253 call 3 */
        return STR_ME_MUTATE_TOKEN;
    case 64772: /* module 253 call 4 */
        return STR_ME_MINT;
    case 64773: /* module 253 call 5 */
        return STR_ME_BURN;
    case 64774: /* module 253 call 6 */
        return STR_ME_TRANSFER;
    case 64775: /* module 253 call 7 */
        return STR_ME_FREEZE;
    case 64776: /* module 253 call 8 */
        return STR_ME_THAW;
    case 64777: /* module 253 call 9 */
        return STR_ME_SET_ATTRIBUTE;
    case 64778: /* module 253 call 10 */
        return STR_ME_REMOVE_ATTRIBUTE;
    case 64779: /* module 253 call 11 */
        return STR_ME_REMOVE_ALL_ATTRIBUTES;
    case 64780: /* module 253 call 12 */
        return STR_ME_BATCH_TRANSFER;
    case 64781: /* module 253 call 13 */
        return STR_ME_BATCH_MINT;
    case 64782: /* module 253 call 14 */
        return STR_ME_BATCH_SET_ATTRIBUTE;
    case 64783: /* module 253 call 15 */
        return STR_ME_APPROVE_COLLECTION;
    case 64784: /* module 253 call 16 */
        return STR_ME_UNAPPROVE_COLLECTION;
    case 64785: /* module 253 call 17 */
        return STR_ME_APPROVE_TOKEN;
    case 64786: /* module 253 call 18 */
        return STR_ME_UNAPPROVE_TOKEN;
    case 64787: /* module 253 call 19 */
        return STR_ME_FORCE_MUTATE_COLLECTION;
    case 64788: /* module 253 call 20 */
        return STR_ME_FORCE_TRANSFER;
    case 64789: /* module 253 call 21 */
        return STR_ME_FORCE_SET_COLLECTION;
    case 64790: /* module 253 call 22 */
        return STR_ME_FORCE_SET_TOKEN;
    case 64791: /* module 253 call 23 */
        return STR_ME_FORCE_SET_ATTRIBUTE;
    case 64792: /* module 253 call 24 */
        return STR_ME_FORCE_SET_COLLECTION_ACCOUNT;
    case 64793: /* module 253 call 25 */
        return STR_ME_FORCE_SET_TOKEN_ACCOUNT;
    case 64794: /* module 253 call 26 */
        return STR_ME_FORCE_CREATE_COLLECTION;
    case 64795: /* module 253 call 27 */
        return STR_ME_FORCE_MINT;
    case 64796: /* module 253 call 28 */
        return STR_ME_FORCE_BURN;
    case 64797: /* module 253 call 29 */
        return STR_ME_FORCE_APPROVE_COLLECTION;
    case 64798: /* module 253 call 30 */
        return STR_ME_FORCE_FREEZE;
    case 64799: /* module 253 call 31 */
        return STR_ME_FORCE_SET_NEXT_COLLECTION_ID;
    case 64800: /* module 253 call 32 */
        return STR_ME_CLAIM_COLLECTIONS;
    case 64801: /* module 253 call 33 */
        return STR_ME_CLAIM_TOKENS;
    case 4608: /* module 18 call 0 */
        return STR_ME_BOND;
    case 4611: /* module 18 call 3 */
        return STR_ME_UNBOND;
    case 4612: /* module 18 call 4 */
        return STR_ME_POOL_WITHDRAW_UNBONDED;
    case 4613: /* module 18 call 5 */
        return STR_ME_WITHDRAW_UNBONDED;
    case 4614: /* module 18 call 6 */
        return STR_ME_CREATE;
    case 4616: /* module 18 call 8 */
       return STR_ME_NOMINATE;
    case 4619: /* module 18 call 11 */
        return STR_ME_SET_CONFIGS;
    case 4621: /* module 18 call 13 */
        return STR_ME_CHILL;
    case 4622: /* module 18 call 14 */
        return STR_ME_DESTROY;
    case 4626: /* module 18 call 18 */
        return STR_ME_PAYOUT_REWARDS;
    case 4627: /* module 18 call 19 */
        return STR_ME_MUTATE;
    case 4628: /* module 18 call 20 */
        return STR_ME_UNBOND_DEPOSIT;
    case 4629: /* module 18 call 21 */
        return STR_ME_WITHDRAW_DEPOSIT;
    case 4630: /* module 18 call 22 */
        return STR_ME_SET_STAKING_INFO;
    case 4631: /* module 18 call 23 */
        return STR_ME_CALCULATE_EARLY_BIRD_BONUS;
    case 4632: /* module 18 call 24 */
        return STR_ME_PAY_EARLY_BIRD_BONUS;
    case 4633: /* module 18 call 25 */
        return STR_ME_PROCESS_PAYOUTS;
    case 4634: /* module 18 call 26 */
        return STR_ME_WITHDRAW_FREE_BALANCE;
    case 4635: /* module 18 call 27 */
        return STR_ME_CAPTURE_EARLY_BIRD_BONUS_SHARES;
    case 4636: /* module 18 call 28 */
        return STR_ME_UNLOCK_EARLY_BIRD_BONUS;
    case 27136: /* module 106 call 0 */
        return STR_ME_ADD_MEMBER;
    case 27137: /* module 106 call 1 */
        return STR_ME_PROMOTE_MEMBER;
    case 27138: /* module 106 call 2 */
        return STR_ME_DEMOTE_MEMBER;
    case 27139: /* module 106 call 3 */
        return STR_ME_REMOVE_MEMBER;
    case 27140: /* module 106 call 4 */
        return STR_ME_VOTE;
    case 27141: /* module 106 call 5 */
        return STR_ME_CLEANUP_POLL;
    case 27392: /* module 107 call 0 */
        return STR_ME_SUBMIT;
    case 27393: /* module 107 call 1 */
        return STR_ME_PLACE_DECISION_DEPOSIT;
    case 27394: /* module 107 call 2 */
        return STR_ME_REFUND_DECISION_DEPOSIT;
    case 27395: /* module 107 call 3 */
        return STR_ME_CANCEL;
    case 27396: /* module 107 call 4 */
        return STR_ME_KILL;
    case 27397: /* module 107 call 5 */
        return STR_ME_NUDGE_REFERENDUM;
    case 27398: /* module 107 call 6 */
        return STR_ME_ONE_FEWER_DECIDING;
    case 27399: /* module 107 call 7 */
        return STR_ME_REFUND_SUBMISSION_DEPOSIT;
    case 27400: /* module 107 call 8 */
        return STR_ME_SET_METADATA;
    case 63744: /* module 249 call 0 */
        return STR_ME_CREATE_LISTING;
    case 63745: /* module 249 call 1 */
        return STR_ME_CANCEL_LISTING;
    case 63746: /* module 249 call 2 */
        return STR_ME_FILL_LISTING;
    case 63747: /* module 249 call 3 */
        return STR_ME_PLACE_BID;
    case 63748: /* module 249 call 4 */
        return STR_ME_FINALIZE_AUCTION;
    case 63749: /* module 249 call 5 */
        return STR_ME_SET_PROTOCOL_FEE;
    case 63750: /* module 249 call 6 */
        return STR_ME_FORCE_CREATE_LISTING;
    case 63751: /* module 249 call 7 */
        return STR_ME_FORCE_PLACE_BID;
    case 13824: /* module 54 call 0 */
        return STR_ME_CREATE_FUEL_TANK;
    case 13825: /* module 54 call 1 */
        return STR_ME_MUTATE_FUEL_TANK;
    case 13826: /* module 54 call 2 */
        return STR_ME_ADD_ACCOUNT;
    case 13827: /* module 54 call 3 */
        return STR_ME_REMOVE_ACCOUNT;
    case 13828: /* module 54 call 4 */
        return STR_ME_REMOVE_ACCOUNT_RULE_DATA;
    case 13829: /* module 54 call 5 */
        return STR_ME_DISPATCH;
    case 13830: /* module 54 call 6 */
        return STR_ME_DISPATCH_AND_TOUCH;
    case 13831: /* module 54 call 7 */
        return STR_ME_SCHEDULE_MUTATE_FREEZE_STATE;
    case 13832: /* module 54 call 8 */
        return STR_ME_INSERT_RULE_SET;
    case 13833: /* module 54 call 9 */
        return STR_ME_REMOVE_RULE_SET;
    case 13834: /* module 54 call 10 */
        return STR_ME_BATCH_ADD_ACCOUNT;
    case 13835: /* module 54 call 11 */
        return STR_ME_BATCH_REMOVE_ACCOUNT;
    case 13836: /* module 54 call 12 */
        return STR_ME_FORCE_SET_CONSUMPTION;
    case 13837: /* module 54 call 13 */
        return STR_ME_DESTROY_FUEL_TANK;
    case 13838: /* module 54 call 14 */
        return STR_ME_FORCE_CREATE_FUEL_TANK;
    case 13839: /* module 54 call 15 */
        return STR_ME_FORCE_BATCH_ADD_ACCOUNT;
#endif
    default:
        return NULL;
    }

    return NULL;
}

uint8_t _getMethod_NumItems_V7(uint8_t moduleIdx, uint8_t callIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 1536: /* module 6 call 0 */
        return 2;
    case 1538: /* module 6 call 2 */
        return 3;
    case 1539: /* module 6 call 3 */
        return 2;
    case 1540: /* module 6 call 4 */
        return 2;
    case 2304: /* module 9 call 0 */
        return 2;
    case 2305: /* module 9 call 1 */
        return 1;
    case 2306: /* module 9 call 2 */
        return 1;
    case 2307: /* module 9 call 3 */
        return 1;
    case 2308: /* module 9 call 4 */
        return 1;
    case 2309: /* module 9 call 5 */
        return 1;
    case 2310: /* module 9 call 6 */
        return 0;
    case 2311: /* module 9 call 7 */
        return 1;
    case 2312: /* module 9 call 8 */
        return 0;
    case 2322: /* module 9 call 18 */
        return 2;
    case 2323: /* module 9 call 19 */
        return 1;
    case 2560: /* module 10 call 0 */
        return 2;
    case 2561: /* module 10 call 1 */
        return 0;
    case 5120: /* module 20 call 0 */
        return 1;
    case 5122: /* module 20 call 2 */
        return 1;
    case 5124: /* module 20 call 4 */
        return 1;
    case 18688: /* module 73 call 0 */
        return 6;
    case 18689: /* module 73 call 1 */
        return 3;
    case 18690: /* module 73 call 2 */
        return 2;
    case 18691: /* module 73 call 3 */
        return 1;
    case 18692: /* module 73 call 4 */
        return 1;
    case 18693: /* module 73 call 5 */
        return 6;
    case 18694: /* module 73 call 6 */
        return 2;
    case 18695: /* module 73 call 7 */
        return 1;
    case 18696: /* module 73 call 8 */
        return 2;
#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
    case 25345: /* module 99 call 1 */
        return 4;
    case 25346: /* module 99 call 2 */
        return 4;
    case 25352: /* module 99 call 8 */
        return 5;
    case 25353: /* module 99 call 9 */
        return 5;
#endif
    case 0: /* module 0 call 0 */
        return 1;
    case 1: /* module 0 call 1 */
        return 1;
    case 2: /* module 0 call 2 */
        return 1;
    case 3: /* module 0 call 3 */
        return 1;
    case 7: /* module 0 call 7 */
        return 1;
    case 25856: /* module 101 call 0 */
        return 1;
    case 25857: /* module 101 call 1 */
        return 1;
    case 25858: /* module 101 call 2 */
        return 1;
    case 25859: /* module 101 call 3 */
        return 1;
    case 25860: /* module 101 call 4 */
        return 1;
    case 512: /* module 2 call 0 */
        return 1;
    case 1541: /* module 6 call 5 */
        return 2;
    case 1542: /* module 6 call 6 */
        return 1;
    case 1544: /* module 6 call 8 */
        return 2;
    case 2313: /* module 9 call 9 */
        return 1;
    case 2314: /* module 9 call 10 */
        return 1;
    case 2315: /* module 9 call 11 */
        return 1;
    case 2316: /* module 9 call 12 */
        return 0;
    case 2317: /* module 9 call 13 */
        return 0;
    case 2318: /* module 9 call 14 */
        return 1;
    case 2319: /* module 9 call 15 */
        return 2;
    case 2320: /* module 9 call 16 */
        return 0;
    case 2321: /* module 9 call 17 */
        return 2;
    case 2324: /* module 9 call 20 */
        return 2;
    case 2325: /* module 9 call 21 */
        return 1;
    case 2326: /* module 9 call 22 */
        return 6;
    case 2327: /* module 9 call 23 */
        return 1;
    case 2328: /* module 9 call 24 */
        return 1;
    case 2329: /* module 9 call 25 */
        return 1;
    case 3072: /* module 12 call 0 */
        return 2;
    case 3073: /* module 12 call 1 */
        return 1;
    case 3074: /* module 12 call 2 */
        return 1;
    case 3075: /* module 12 call 3 */
        return 2;
    case 3076: /* module 12 call 4 */
        return 1;
    case 3078: /* module 12 call 6 */
        return 1;
    case 3079: /* module 12 call 7 */
        return 1;
    case 3080: /* module 12 call 8 */
        return 1;
    case 26112: /* module 102 call 0 */
        return 2;
    case 26113: /* module 102 call 1 */
        return 4;
    case 26114: /* module 102 call 2 */
        return 1;
    case 26115: /* module 102 call 3 */
        return 2;
    case 26116: /* module 102 call 4 */
        return 2;
    case 26117: /* module 102 call 5 */
        return 3;
    case 26368: /* module 103 call 0 */
        return 3;
    case 26369: /* module 103 call 1 */
        return 1;
    case 26370: /* module 103 call 2 */
        return 1;
    case 26371: /* module 103 call 3 */
        return 1;
    case 26372: /* module 103 call 4 */
        return 1;
    case 26373: /* module 103 call 5 */
        return 1;
    case 26374: /* module 103 call 6 */
        return 1;
    case 26375: /* module 103 call 7 */
        return 1;
    case 26376: /* module 103 call 8 */
        return 2;
    case 26880: /* module 105 call 0 */
        return 1;
    case 26881: /* module 105 call 1 */
        return 1;
    case 26882: /* module 105 call 2 */
        return 3;
    case 26883: /* module 105 call 3 */
        return 1;
    case 5123: /* module 20 call 3 */
        return 2;
    case 5125: /* module 20 call 5 */
        return 2;
    case 27648: /* module 108 call 0 */
        return 1;
    case 27649: /* module 108 call 1 */
        return 1;
    case 27650: /* module 108 call 2 */
        return 1;
    case 27651: /* module 108 call 3 */
        return 0;
    case 27652: /* module 108 call 4 */
        return 2;
    case 27653: /* module 108 call 5 */
        return 1;
    case 27654: /* module 108 call 6 */
        return 2;
    case 27655: /* module 108 call 7 */
        return 2;
    case 27657: /* module 108 call 9 */
        return 4;
    case 27658: /* module 108 call 10 */
        return 1;
    case 27659: /* module 108 call 11 */
        return 2;
    case 27660: /* module 108 call 12 */
        return 2;
    case 27661: /* module 108 call 13 */
        return 1;
    case 27662: /* module 108 call 14 */
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
    case 7433: /* module 29 call 9 */
        return 4;
    case 5376: /* module 21 call 0 */
        return 2;
    case 5377: /* module 21 call 1 */
        return 5;
    case 5378: /* module 21 call 2 */
        return 5;
    case 5379: /* module 21 call 3 */
        return 4;
    case 4352: /* module 17 call 0 */
        return 1;
    case 4353: /* module 17 call 1 */
        return 1;
    case 4354: /* module 17 call 2 */
        return 2;
    case 13056: /* module 51 call 0 */
        return 1;
    case 13057: /* module 51 call 1 */
        return 1;
    case 13058: /* module 51 call 2 */
        return 1;
    case 13059: /* module 51 call 3 */
        return 1;
    case 13060: /* module 51 call 4 */
        return 1;
    case 13061: /* module 51 call 5 */
        return 1;
    case 13062: /* module 51 call 6 */
        return 1;
    case 13063: /* module 51 call 7 */
        return 1;
    case 13064: /* module 51 call 8 */
        return 1;
    case 13065: /* module 51 call 9 */
        return 1;
    case 13067: /* module 51 call 11 */
        return 1;
    case 13068: /* module 51 call 12 */
        return 1;
    case 13069: /* module 51 call 13 */
        return 1;
    case 13071: /* module 51 call 15 */
        return 1;
    case 13074: /* module 51 call 18 */
        return 1;
    case 13075: /* module 51 call 19 */
        return 1;
    case 13076: /* module 51 call 20 */
        return 1;
    case 13077: /* module 51 call 21 */
        return 1;
    case 13078: /* module 51 call 22 */
        return 1;
    case 13079: /* module 51 call 23 */
        return 1;
    case 13080: /* module 51 call 24 */
        return 1;
    case 13081: /* module 51 call 25 */
        return 1;
    case 13083: /* module 51 call 27 */
        return 1;
    case 13084: /* module 51 call 28 */
        return 1;
    case 13085: /* module 51 call 29 */
        return 1;
    case 13086: /* module 51 call 30 */
        return 1;
    case 13087: /* module 51 call 31 */
        return 1;
    case 13088: /* module 51 call 32 */
        return 1;
    case 13089: /* module 51 call 33 */
        return 1;
    case 13090: /* module 51 call 34 */
        return 1;
    case 13092: /* module 51 call 36 */
        return 1;
    case 13093: /* module 51 call 37 */
        return 1;
    case 13095: /* module 51 call 39 */
        return 1;
    case 13098: /* module 51 call 42 */
        return 1;
    case 13099: /* module 51 call 43 */
        return 1;
    case 13100: /* module 51 call 44 */
        return 1;
    case 13103: /* module 51 call 47 */
        return 1;
    case 13104: /* module 51 call 48 */
        return 1;
    case 13105: /* module 51 call 49 */
        return 1;
    case 13106: /* module 51 call 50 */
        return 1;
    case 13107: /* module 51 call 51 */
        return 1;
    case 13108: /* module 51 call 52 */
        return 1;
    case 14592: /* module 57 call 0 */
        return 1;
    case 15872: /* module 62 call 0 */
        return 0;
    case 18432: /* module 72 call 0 */
        return 2;
    case 18433: /* module 72 call 1 */
        return 5;
    case 18434: /* module 72 call 2 */
        return 0;
//////////////////////////////////
// Custom
//////////////////////////////////
    case 27904: /* module 109 call 0 */
        return 3;
    case 27905: /* module 109 call 1 */
        return 2;
    case 27906: /* module 109 call 2 */
        return 3;
    case 27907: /* module 109 call 3 */
        return 3;
    case 64512: /* module 252 call 0 */
        return 1;
    case 64513: /* module 252 call 1 */
        return 1;
    case 65280: /* module 255 call 0 */
        return 2;
    case 65281: /* module 255 call 1 */
        return 2;
    case 4864: /* module 19 call 0 */
        return 1;
    case 4865: /* module 19 call 1 */
        return 1;
    case 4866: /* module 19 call 2 */
        return 1;
    case 4867: /* module 19 call 3 */
        return 2;
    case 4868: /* module 19 call 4 */
        return 2;
    case 4869: /* module 19 call 5 */
        return 3;
    case 64768: /* module 253 call 0 */
        return 1;
    case 64769: /* module 253 call 1 */
        return 1;
    case 64770: /* module 253 call 2 */
        return 2;
    case 64771: /* module 253 call 3 */
        return 3;
    case 64772: /* module 253 call 4 */
        return 3;
    case 64773: /* module 253 call 5 */
        return 2;
    case 64774: /* module 253 call 6 */
        return 3;
    case 64775: /* module 253 call 7 */
        return 1;
    case 64776: /* module 253 call 8 */
        return 1;
    case 64777: /* module 253 call 9 */
        return 4;
    case 64778: /* module 253 call 10 */
        return 3;
    case 64779: /* module 253 call 11 */
        return 3;
    case 64780: /* module 253 call 12 */
        return 2;
    case 64781: /* module 253 call 13 */
        return 2;
    case 64782: /* module 253 call 14 */
        return 3;
    case 64783: /* module 253 call 15 */
        return 3;
    case 64784: /* module 253 call 16 */
        return 2;
    case 64785: /* module 253 call 17 */
        return 6;
    case 64786: /* module 253 call 18 */
        return 3;
    case 64787: /* module 253 call 19 */
        return 2;
    case 64788: /* module 253 call 20 */
        return 4;
    case 64789: /* module 253 call 21 */
        return 2;
    case 64790: /* module 253 call 22 */
        return 3;
    case 64791: /* module 253 call 23 */
        return 4;
    case 64792: /* module 253 call 24 */
        return 3;
    case 64793: /* module 253 call 25 */
        return 4;
    case 64794: /* module 253 call 26 */
        return 3;
    case 64795: /* module 253 call 27 */
        return 5;
    case 64796: /* module 253 call 28 */
        return 3;
    case 64797: /* module 253 call 29 */
        return 4;
    case 64798: /* module 253 call 30 */
        return 1;
    case 64799: /* module 253 call 31 */
        return 1;
    case 64800: /* module 253 call 32 */
        return 3;
    case 64801: /* module 253 call 33 */
        return 3;
    case 27136: /* module 106 call 0 */
        return 1;
    case 27137: /* module 106 call 1 */
        return 1;
    case 27138: /* module 106 call 2 */
        return 1;
    case 27139: /* module 106 call 3 */
        return 2;
    case 27140: /* module 106 call 4 */
        return 2;
    case 27141: /* module 106 call 5 */
        return 2;
    case 27392: /* module 107 call 0 */
        return 3;
    case 27393: /* module 107 call 1 */
        return 1;
    case 27394: /* module 107 call 2 */
        return 1;
    case 27395: /* module 107 call 3 */
        return 1;
    case 27396: /* module 107 call 4 */
        return 1;
    case 27397: /* module 107 call 5 */
        return 1;
    case 27398: /* module 107 call 6 */
        return 1;
    case 27399: /* module 107 call 7 */
        return 1;
    case 27400: /* module 107 call 8 */
        return 2;
    case 63744: /* module 249 call 0 */
        return 6;
    case 63745: /* module 249 call 1 */
        return 1;
    case 63746: /* module 249 call 2 */
        return 2;
    case 63747: /* module 249 call 3 */
        return 2;
    case 63748: /* module 249 call 4 */
        return 1;
    case 13824: /* module 54 call 0 */
        return 1;
    case 13825: /* module 54 call 1 */
        return 2;
    case 13826: /* module 54 call 2 */
        return 2;
    case 13827: /* module 54 call 3 */
        return 2;
    case 13828: /* module 54 call 4 */
        return 4;
    case 13829: /* module 54 call 5 */
        return 4;
    case 13830: /* module 54 call 6 */
        return 4;
    case 13831: /* module 54 call 7 */
        return 3;
    case 13832: /* module 54 call 8 */
        return 3;
    case 13833: /* module 54 call 9 */
        return 2;
    case 13834: /* module 54 call 10 */
        return 2;
    case 13835: /* module 54 call 11 */
        return 2;
    case 13836: /* module 54 call 12 */
        return 4;
    case 13837: /* module 54 call 13 */
        return 1;
    case 13838: /* module 54 call 14 */
        return 2;
    case 13839: /* module 54 call 15 */
        return 3;
   case 4608: /* module 18 call 0 */
        return 2;
    case 4611: /* module 18 call 3 */
        return 3;
    case 4612: /* module 18 call 4 */
        return 2;
    case 4613: /* module 18 call 5 */
        return 3;
    case 4614: /* module 18 call 6 */
        return 5;
    case 4616: /* module 18 call 8 */
        return 2;
    case 4619: /* module 18 call 11 */
        return 4;
    case 4621: /* module 18 call 13 */
        return 1;
    case 4622: /* module 18 call 14 */
        return 1;
    case 4626: /* module 18 call 18 */
        return 2;
    case 4627: /* module 18 call 19 */
        return 2;
    case 4628: /* module 18 call 20 */
        return 1;
    case 4629: /* module 18 call 21 */
        return 1;
    case 4630: /* module 18 call 22 */
        return 1;
    case 4631: /* module 18 call 23 */
        return 1;
    case 4632: /* module 18 call 24 */
        return 3;
    case 4633: /* module 18 call 25 */
        return 1;
    case 4634: /* module 18 call 26 */
        return 3;
    case 4635: /* module 18 call 27 */
        return 2;
    case 4636: /* module 18 call 28 */
        return 0;
#endif
    default:
        return 0;
    }

    return 0;
}

const char* _getMethod_ItemName_V7(uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 1536: /* module 6 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 1538: /* module 6 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_source;
        case 1:
            return STR_IT_dest;
        case 2:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 1539: /* module 6 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 1540: /* module 6 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_keep_alive;
        default:
            return NULL;
        }
    case 2304: /* module 9 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        case 1:
            return STR_IT_payee;
        default:
            return NULL;
        }
    case 2305: /* module 9 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 2306: /* module 9 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 2307: /* module 9 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_num_slashing_spans;
        default:
            return NULL;
        }
    case 2308: /* module 9 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_prefs;
        default:
            return NULL;
        }
    case 2309: /* module 9 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_targets;
        default:
            return NULL;
        }
    case 2310: /* module 9 call 6 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 2311: /* module 9 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_payee;
        default:
            return NULL;
        }
    case 2312: /* module 9 call 8 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 2322: /* module 9 call 18 */
        switch (itemIdx) {
        case 0:
            return STR_IT_validator_stash;
        case 1:
            return STR_IT_era;
        default:
            return NULL;
        }
    case 2323: /* module 9 call 19 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 2560: /* module 10 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_keys;
        case 1:
            return STR_IT_proof;
        default:
            return NULL;
        }
    case 2561: /* module 10 call 1 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 5120: /* module 20 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_calls;
        default:
            return NULL;
        }
    case 5122: /* module 20 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_calls;
        default:
            return NULL;
        }
    case 5124: /* module 20 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_calls;
        default:
            return NULL;
        }
    case 18688: /* module 73 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        case 1:
            return STR_IT_cap;
        case 2:
            return STR_IT_first_period;
        case 3:
            return STR_IT_last_period;
        case 4:
            return STR_IT_end;
        case 5:
            return STR_IT_verifier;
        default:
            return NULL;
        }
    case 18689: /* module 73 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        case 1:
            return STR_IT_amount;
        case 2:
            return STR_IT_signature;
        default:
            return NULL;
        }
    case 18690: /* module 73 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        case 1:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 18691: /* module 73 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 18692: /* module 73 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 18693: /* module 73 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        case 1:
            return STR_IT_cap;
        case 2:
            return STR_IT_first_period;
        case 3:
            return STR_IT_last_period;
        case 4:
            return STR_IT_end;
        case 5:
            return STR_IT_verifier;
        default:
            return NULL;
        }
    case 18694: /* module 73 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        case 1:
            return STR_IT_memo;
        default:
            return NULL;
        }
    case 18695: /* module 73 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 18696: /* module 73 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        case 1:
            return STR_IT_signature;
        default:
            return NULL;
        }
#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
    case 25345: /* module 99 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_beneficiary;
        case 2:
            return STR_IT_assets;
        case 3:
            return STR_IT_fee_asset_item;
        default:
            return NULL;
        }
    case 25346: /* module 99 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_beneficiary;
        case 2:
            return STR_IT_assets;
        case 3:
            return STR_IT_fee_asset_item;
        default:
            return NULL;
        }
    case 25352: /* module 99 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_beneficiary;
        case 2:
            return STR_IT_assets;
        case 3:
            return STR_IT_fee_asset_item;
        case 4:
            return STR_IT_weight_limit;
        default:
            return NULL;
        }
    case 25353: /* module 99 call 9 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_beneficiary;
        case 2:
            return STR_IT_assets;
        case 3:
            return STR_IT_fee_asset_item;
        case 4:
            return STR_IT_weight_limit;
        default:
            return NULL;
        }
#endif
    case 0: /* module 0 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_remark;
        default:
            return NULL;
        }
    case 1: /* module 0 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_pages;
        default:
            return NULL;
        }
    case 2: /* module 0 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_code;
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
    case 7: /* module 0 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_remark;
        default:
            return NULL;
        }
    case 25856: /* module 101 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bytes;
        default:
            return NULL;
        }
    case 25857: /* module 101 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_hash;
        default:
            return NULL;
        }
    case 25858: /* module 101 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_hash;
        default:
            return NULL;
        }
    case 25859: /* module 101 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_hash;
        default:
            return NULL;
        }
    case 25860: /* module 101 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_hashes;
        default:
            return NULL;
        }
    case 512: /* module 2 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_now;
        default:
            return NULL;
        }
    case 1541: /* module 6 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        case 1:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 1542: /* module 6 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 1544: /* module 6 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        case 1:
            return STR_IT_new_free;
        default:
            return NULL;
        }
    case 2313: /* module 9 call 9 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 2314: /* module 9 call 10 */
        switch (itemIdx) {
        case 0:
            return STR_IT_additional;
        default:
            return NULL;
        }
    case 2315: /* module 9 call 11 */
        switch (itemIdx) {
        case 0:
            return STR_IT_factor;
        default:
            return NULL;
        }
    case 2316: /* module 9 call 12 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 2317: /* module 9 call 13 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 2318: /* module 9 call 14 */
        switch (itemIdx) {
        case 0:
            return STR_IT_invulnerables;
        default:
            return NULL;
        }
    case 2319: /* module 9 call 15 */
        switch (itemIdx) {
        case 0:
            return STR_IT_stash;
        case 1:
            return STR_IT_num_slashing_spans;
        default:
            return NULL;
        }
    case 2320: /* module 9 call 16 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 2321: /* module 9 call 17 */
        switch (itemIdx) {
        case 0:
            return STR_IT_era;
        case 1:
            return STR_IT_slash_indices;
        default:
            return NULL;
        }
    case 2324: /* module 9 call 20 */
        switch (itemIdx) {
        case 0:
            return STR_IT_stash;
        case 1:
            return STR_IT_num_slashing_spans;
        default:
            return NULL;
        }
    case 2325: /* module 9 call 21 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 2326: /* module 9 call 22 */
        switch (itemIdx) {
        case 0:
            return STR_IT_min_nominator_bond;
        case 1:
            return STR_IT_min_validator_bond;
        case 2:
            return STR_IT_max_nominator_count;
        case 3:
            return STR_IT_max_validator_count;
        case 4:
            return STR_IT_chill_threshold;
        case 5:
            return STR_IT_min_commission;
        default:
            return NULL;
        }
    case 2327: /* module 9 call 23 */
        switch (itemIdx) {
        case 0:
            return STR_IT_controller;
        default:
            return NULL;
        }
    case 2328: /* module 9 call 24 */
        switch (itemIdx) {
        case 0:
            return STR_IT_validator_stash;
        default:
            return NULL;
        }
    case 2329: /* module 9 call 25 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 3072: /* module 12 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        case 1:
            return STR_IT_beneficiary;
        default:
            return NULL;
        }
    case 3073: /* module 12 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_id;
        default:
            return NULL;
        }
    case 3074: /* module 12 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_id;
        default:
            return NULL;
        }
    case 3075: /* module 12 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        case 1:
            return STR_IT_beneficiary;
        default:
            return NULL;
        }
    case 3076: /* module 12 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_id;
        default:
            return NULL;
        }
    case 3078: /* module 12 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 3079: /* module 12 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 3080: /* module 12 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 26112: /* module 102 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_poll_index;
        case 1:
            return STR_IT_vote;
        default:
            return NULL;
        }
    case 26113: /* module 102 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_class_;
        case 1:
            return STR_IT_to;
        case 2:
            return STR_IT_conviction;
        case 3:
            return STR_IT_balance;
        default:
            return NULL;
        }
    case 26114: /* module 102 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_class_;
        default:
            return NULL;
        }
    case 26115: /* module 102 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_class_;
        case 1:
            return STR_IT_target;
        default:
            return NULL;
        }
    case 26116: /* module 102 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_class_;
        case 1:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 26117: /* module 102 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_target;
        case 1:
            return STR_IT_class_;
        case 2:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 26368: /* module 103 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_origin;
        case 1:
            return STR_IT_proposal;
        case 2:
            return STR_IT_enactment_moment;
        default:
            return NULL;
        }
    case 26369: /* module 103 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 26370: /* module 103 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 26371: /* module 103 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 26372: /* module 103 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 26373: /* module 103 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 26374: /* module 103 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_track;
        default:
            return NULL;
        }
    case 26375: /* module 103 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 26376: /* module 103 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        case 1:
            return STR_IT_maybe_hash;
        default:
            return NULL;
        }
    case 26880: /* module 105 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_call_hash;
        default:
            return NULL;
        }
    case 26881: /* module 105 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_call_hash;
        default:
            return NULL;
        }
    case 26882: /* module 105 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_call_hash;
        case 1:
            return STR_IT_call_encoded_len;
        case 2:
            return STR_IT_call_weight_witness;
        default:
            return NULL;
        }
    case 26883: /* module 105 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 5123: /* module 20 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_as_origin;
        case 1:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 5125: /* module 20 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_call;
        case 1:
            return STR_IT_weight;
        default:
            return NULL;
        }
    case 27648: /* module 108 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_account;
        default:
            return NULL;
        }
    case 27649: /* module 108 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_info;
        default:
            return NULL;
        }
    case 27650: /* module 108 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_subs;
        default:
            return NULL;
        }
    case 27651: /* module 108 call 3 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 27652: /* module 108 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_reg_index;
        case 1:
            return STR_IT_max_fee;
        default:
            return NULL;
        }
    case 27653: /* module 108 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_reg_index;
        default:
            return NULL;
        }
    case 27654: /* module 108 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        case 1:
            return STR_IT_fee;
        default:
            return NULL;
        }
    case 27655: /* module 108 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        case 1:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 27657: /* module 108 call 9 */
        switch (itemIdx) {
        case 0:
            return STR_IT_reg_index;
        case 1:
            return STR_IT_target;
        case 2:
            return STR_IT_judgement;
        case 3:
            return STR_IT_identity;
        default:
            return NULL;
        }
    case 27658: /* module 108 call 10 */
        switch (itemIdx) {
        case 0:
            return STR_IT_target;
        default:
            return NULL;
        }
    case 27659: /* module 108 call 11 */
        switch (itemIdx) {
        case 0:
            return STR_IT_sub;
        case 1:
            return STR_IT_data;
        default:
            return NULL;
        }
    case 27660: /* module 108 call 12 */
        switch (itemIdx) {
        case 0:
            return STR_IT_sub;
        case 1:
            return STR_IT_data;
        default:
            return NULL;
        }
    case 27661: /* module 108 call 13 */
        switch (itemIdx) {
        case 0:
            return STR_IT_sub;
        default:
            return NULL;
        }
    case 27662: /* module 108 call 14 */
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
    case 5376: /* module 21 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_other_signatories;
        case 1:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 5377: /* module 21 call 1 */
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
            return STR_IT_max_weight;
        default:
            return NULL;
        }
    case 5378: /* module 21 call 2 */
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
    case 5379: /* module 21 call 3 */
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
    case 4352: /* module 17 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dislocated;
        default:
            return NULL;
        }
    case 4353: /* module 17 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_lighter;
        default:
            return NULL;
        }
    case 4354: /* module 17 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_heavier;
        case 1:
            return STR_IT_lighter;
        default:
            return NULL;
        }
    case 13056: /* module 51 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13057: /* module 51 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13058: /* module 51 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13059: /* module 51 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13060: /* module 51 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13061: /* module 51 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13062: /* module 51 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13063: /* module 51 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13064: /* module 51 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13065: /* module 51 call 9 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13067: /* module 51 call 11 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13068: /* module 51 call 12 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13069: /* module 51 call 13 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13071: /* module 51 call 15 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13074: /* module 51 call 18 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13075: /* module 51 call 19 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13076: /* module 51 call 20 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13077: /* module 51 call 21 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13078: /* module 51 call 22 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13079: /* module 51 call 23 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13080: /* module 51 call 24 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13081: /* module 51 call 25 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13083: /* module 51 call 27 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13084: /* module 51 call 28 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13085: /* module 51 call 29 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13086: /* module 51 call 30 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13087: /* module 51 call 31 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13088: /* module 51 call 32 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13089: /* module 51 call 33 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13090: /* module 51 call 34 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13092: /* module 51 call 36 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13093: /* module 51 call 37 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13095: /* module 51 call 39 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13098: /* module 51 call 42 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13099: /* module 51 call 43 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13100: /* module 51 call 44 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13103: /* module 51 call 47 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13104: /* module 51 call 48 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13105: /* module 51 call 49 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13106: /* module 51 call 50 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13107: /* module 51 call 51 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13108: /* module 51 call 52 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 14592: /* module 57 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_up_to;
        default:
            return NULL;
        }
    case 15872: /* module 62 call 0 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 18432: /* module 72 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_duration;
        case 1:
            return STR_IT_lease_period_index;
        default:
            return NULL;
        }
    case 18433: /* module 72 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_para;
        case 1:
            return STR_IT_auction_index;
        case 2:
            return STR_IT_first_slot;
        case 3:
            return STR_IT_last_slot;
        case 4:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 18434: /* module 72 call 2 */
        switch (itemIdx) {
        default:
            return NULL;
        }
//////////////////////////////////
// Custom
//////////////////////////////////
    case 27904: /* module 109 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_poll_index;
        case 1:
            return STR_IT_vote;
        case 2:
            return STR_IT_currency;
        default:
            return NULL;
        }
    case 27905: /* module 109 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_class_;
        case 1:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 27906: /* module 109 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_target;
        case 1:
            return STR_IT_class_;
        case 2:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 27907: /* module 109 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_class_;
        case 1:
            return STR_IT_target;
        case 2:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 64512: /* module 252 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_validators;
        default:
            return NULL;
        }
    case 64513: /* module 252 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_validators;
        default:
            return NULL;
        }
    case 65280: /* module 255 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_call;
        case 1:
            return STR_IT_pause_only_extrinsic;
        default:
            return NULL;
        }
    case 65281: /* module 255 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_call;
        case 1:
            return STR_IT_resume_only_extrinsic;
        default:
            return NULL;
    }
    case 4864: /* module 19 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_offer;
        default:
            return NULL;
        }
    case 4865: /* module 19 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_offer_id;
        default:
            return NULL;
        }
    case 4866: /* module 19 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_config;
        default:
            return NULL;
        }
    case 4867: /* module 19 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_offer_id;
        case 1:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 4868: /* module 19 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_offer_id;
        case 1:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 4869: /* module 19 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_offer_id;
        case 1:
            return STR_IT_amount;
        case 2:
            return STR_IT_token_id;
        default:
            return NULL;
        }
    case 64768: /* module 253 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_descriptor;
        default:
            return NULL;
        }
    case 64769: /* module 253 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_collection_id;
        default:
            return NULL;
        }
    case 64770: /* module 253 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_collection_id;
        case 1:
            return STR_IT_mutation;
        default:
            return NULL;
        }
    case 64771: /* module 253 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_collection_id;
        case 1:
            return STR_IT_token_id;
        case 2:
            return STR_IT_mutation;
        default:
            return NULL;
        }
    case 64772: /* module 253 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_recipient;
        case 1:
            return STR_IT_collection_id;
        case 2:
            return STR_IT_params;
        default:
            return NULL;
        }
    case 64773: /* module 253 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_collection_id;
        case 1:
            return STR_IT_params;
        default:
            return NULL;
        }
    case 64774: /* module 253 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_recipient;
        case 1:
            return STR_IT_collection_id;
        case 2:
            return STR_IT_params;
        default:
            return NULL;
        }
    case 64775: /* module 253 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_info;
        default:
            return NULL;
        }
    case 64776: /* module 253 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_info;
        default:
            return NULL;
        }
    case 64777: /* module 253 call 9 */
        switch (itemIdx) {
        case 0:
            return STR_IT_collection_id;
        case 1:
            return STR_IT_token_id;
        case 2:
            return STR_IT_key;
        case 3:
            return STR_IT_value;
        default:
            return NULL;
        }
    case 64778: /* module 253 call 10 */
        switch (itemIdx) {
        case 0:
            return STR_IT_collection_id;
        case 1:
            return STR_IT_token_id;
        case 2:
            return STR_IT_key;
        default:
            return NULL;
        }
    case 64779: /* module 253 call 11 */
        switch (itemIdx) {
        case 0:
            return STR_IT_collection_id;
        case 1:
            return STR_IT_token_id;
        case 2:
            return STR_IT_attribute_count;
        default:
            return NULL;
        }
    case 64780: /* module 253 call 12 */
        switch (itemIdx) {
        case 0:
            return STR_IT_collection_id;
        case 1:
            return STR_IT_recipients;
        default:
            return NULL;
        }
    case 64781: /* module 253 call 13 */
        switch (itemIdx) {
        case 0:
            return STR_IT_collection_id;
        case 1:
            return STR_IT_recipients;
        default:
            return NULL;
        }
    case 64782: /* module 253 call 14 */
        switch (itemIdx) {
        case 0:
            return STR_IT_collection_id;
        case 1:
            return STR_IT_token_id;
        case 2:
            return STR_IT_attributes;
        default:
            return NULL;
        }
    case 64783: /* module 253 call 15 */
        switch (itemIdx) {
        case 0:
            return STR_IT_collection_id;
        case 1:
            return STR_IT_operator;
        case 2:
            return STR_IT_expiration;
        default:
            return NULL;
        }
    case 64784: /* module 253 call 16 */
        switch (itemIdx) {
        case 0:
            return STR_IT_collection_id;
        case 1:
            return STR_IT_operator;
        default:
            return NULL;
        }
    case 64785: /* module 253 call 17 */
        switch (itemIdx) {
        case 0:
            return STR_IT_collection_id;
        case 1:
            return STR_IT_token_id;
        case 2:
            return STR_IT_operator;
        case 3:
            return STR_IT_amount;
        case 4:
            return STR_IT_expiration;
        case 5:
            return STR_IT_current_amount;
        default:
            return NULL;
        }
    case 64786: /* module 253 call 18 */
        switch (itemIdx) {
        case 0:
            return STR_IT_collection_id;
        case 1:
            return STR_IT_token_id;
        case 2:
            return STR_IT_operator;
        default:
            return NULL;
        }
    case 64787: /* module 253 call 19 */
        switch (itemIdx) {
        case 0:
            return STR_IT_collection_id;
        case 1:
            return STR_IT_mutation;
        default:
            return NULL;
        }
    case 64788: /* module 253 call 20 */
        switch (itemIdx) {
        case 0:
            return STR_IT_source;
        case 1:
            return STR_IT_destination;
        case 2:
            return STR_IT_collection_id;
        case 3:
            return STR_IT_params;
        default:
            return NULL;
        }
    case 64789: /* module 253 call 21 */
        switch (itemIdx) {
        case 0:
            return STR_IT_collection_id;
        case 1:
            return STR_IT_value;
        default:
            return NULL;
        }
    case 64790: /* module 253 call 22 */
        switch (itemIdx) {
        case 0:
            return STR_IT_collection_id;
        case 1:
            return STR_IT_token_id;
        case 2:
            return STR_IT_value;
        default:
            return NULL;
        }
    case 64791: /* module 253 call 23 */
        switch (itemIdx) {
        case 0:
            return STR_IT_collection_id;
        case 1:
            return STR_IT_token_id;
        case 2:
            return STR_IT_key;
        case 3:
            return STR_IT_value;
        default:
            return NULL;
        }
    case 64792: /* module 253 call 24 */
        switch (itemIdx) {
        case 0:
            return STR_IT_collection_id;
        case 1:
            return STR_IT_account_id;
        case 2:
            return STR_IT_value;
        default:
            return NULL;
        }
    case 64793: /* module 253 call 25 */
        switch (itemIdx) {
        case 0:
            return STR_IT_collection_id;
        case 1:
            return STR_IT_token_id;
        case 2:
            return STR_IT_account_id;
        case 3:
            return STR_IT_value;
        default:
            return NULL;
        }
    case 64794: /* module 253 call 26 */
        switch (itemIdx) {
        case 0:
            return STR_IT_owner;
        case 1:
            return STR_IT_collection_id;
        case 2:
            return STR_IT_descriptor;
        default:
            return NULL;
        }
    case 64795: /* module 253 call 27 */
        switch (itemIdx) {
        case 0:
            return STR_IT_caller;
        case 1:
            return STR_IT_recipient;
        case 2:
            return STR_IT_collection_id;
        case 3:
            return STR_IT_params;
        case 4:
            return STR_IT_deposit_backer;
        default:
            return NULL;
        }
    case 64796: /* module 253 call 28 */
        switch (itemIdx) {
        case 0:
            return STR_IT_caller;
        case 1:
            return STR_IT_collection_id;
        case 2:
            return STR_IT_params;
        default:
            return NULL;
        }
    case 64797: /* module 253 call 29 */
        switch (itemIdx) {
        case 0:
            return STR_IT_caller;
        case 1:
            return STR_IT_collection_id;
        case 2:
            return STR_IT_operator;
        case 3:
            return STR_IT_expiration;
        default:
            return NULL;
        }
    case 64798: /* module 253 call 30 */
        switch (itemIdx) {
        case 0:
            return STR_IT_info;
        default:
            return NULL;
        }
    case 64799: /* module 253 call 31 */
        switch (itemIdx) {
        case 0:
            return STR_IT_value;
        default:
            return NULL;
        }
    case 64800: /* module 253 call 32 */
        switch (itemIdx) {
        case 0:
            return STR_IT_destination;
        case 1:
            return STR_IT_ethereum_signature;
        case 2:
            return STR_IT_ethereum_address;
        default:
            return NULL;
        }
    case 64801: /* module 253 call 33 */
        switch (itemIdx) {
        case 0:
            return STR_IT_destination;
        case 1:
            return STR_IT_ethereum_signature;
        case 2:
            return STR_IT_ethereum_address;
        default:
            return NULL;
        }
    case 27136: /* module 106 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 27137: /* module 106 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 27138: /* module 106 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 27139: /* module 106 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        case 1:
            return STR_IT_min_rank;
        default:
            return NULL;
        }
    case 27140: /* module 106 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_poll;
        case 1:
            return STR_IT_aye;
        default:
            return NULL;
        }
    case 27141: /* module 106 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_poll_index;
        case 1:
            return STR_IT_max;
        default:
            return NULL;
        }
    case 27392: /* module 107 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_origin;
        case 1:
            return STR_IT_proposal;
        case 2:
            return STR_IT_enactment_moment;
        default:
            return NULL;
        }
    case 27393: /* module 107 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 27394: /* module 107 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 27395: /* module 107 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 27396: /* module 107 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 27397: /* module 107 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 27398: /* module 107 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_track;
        default:
            return NULL;
        }
    case 27399: /* module 107 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 27400: /* module 107 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        case 1:
            return STR_IT_maybe_hash;
        default:
            return NULL;
        }
    case 63744: /* module 249 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_make_asset_id;
        case 1:
            return STR_IT_take_asset_id;
        case 2:
            return STR_IT_amount;
        case 3:
            return STR_IT_price;
        case 4:
            return STR_IT_salt;
        case 5:
            return STR_IT_auction_data;
        default:
            return NULL;
        }
    case 63745: /* module 249 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_listing_id;
        default:
            return NULL;
        }
    case 63746: /* module 249 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_listing_id;
        case 1:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 63747: /* module 249 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_listing_id;
        case 1:
            return STR_IT_price;
        default:
            return NULL;
        }
    case 63748: /* module 249 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_listing_id;
        default:
            return NULL;
        }
    case 63749: /* module 249 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_protocol_fee;
        default:
            return NULL;
        }
    case 63750: /* module 249 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_seller;
        case 1:
            return STR_IT_make_asset_id;
        case 2:
            return STR_IT_take_asset_id;
        case 3:
            return STR_IT_amount;
        case 4:
            return STR_IT_price;
        case 5:
            return STR_IT_salt;
        case 6:
            return STR_IT_auction_data;
        case 7:
            return STR_IT_deposit_backer;
        default:
            return NULL;
        }
    case 63751: /* module 249 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 13824: /* module 54 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_descriptor;
        default:
            return NULL;
        }
    case 13825: /* module 54 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_tank_id;
        case 1:
            return STR_IT_mutation;
        default:
            return NULL;
        }
    case 13826: /* module 54 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_tank_id;
        case 1:
            return STR_IT_user_id;
        default:
            return NULL;
        }
    case 13827: /* module 54 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_tank_id;
        case 1:
            return STR_IT_user_id;
        default:
            return NULL;
        }
    case 13828: /* module 54 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_tank_id;
        case 1:
            return STR_IT_user_id;
        case 2:
            return STR_IT_rule_set_id;
        case 3:
            return STR_IT_rule_kind;
        default:
            return NULL;
        }
    case 13829: /* module 54 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_tank_id;
        case 1:
            return STR_IT_rule_set_id;
        case 2:
            return STR_IT_call;
        case 3:
            return STR_IT_settings;
        default:
            return NULL;
        }
    case 13830: /* module 54 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_tank_id;
        case 1:
            return STR_IT_rule_set_id;
        case 2:
            return STR_IT_call;
        case 3:
            return STR_IT_settings;
        default:
            return NULL;
        }
    case 13831: /* module 54 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_tank_id;
        case 1:
            return STR_IT_rule_set_id;
        case 2:
            return STR_IT_is_frozen;
        default:
            return NULL;
        }
    case 13832: /* module 54 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_tank_id;
        case 1:
            return STR_IT_rule_set_id;
        case 2:
            return STR_IT_rules;
        default:
            return NULL;
        }
    case 13833: /* module 54 call 9 */
        switch (itemIdx) {
        case 0:
            return STR_IT_tank_id;
        case 1:
            return STR_IT_rule_set_id;
        default:
            return NULL;
        }
    case 13834: /* module 54 call 10 */
        switch (itemIdx) {
        case 0:
            return STR_IT_tank_id;
        case 1:
            return STR_IT_user_ids;
        default:
            return NULL;
        }
    case 13835: /* module 54 call 11 */
        switch (itemIdx) {
        case 0:
            return STR_IT_tank_id;
        case 1:
            return STR_IT_user_ids;
        default:
            return NULL;
        }
    case 13836: /* module 54 call 12 */
        switch (itemIdx) {
        case 0:
            return STR_IT_tank_id;
        case 1:
            return STR_IT_user_id;
        case 2:
            return STR_IT_rule_set_id;
        case 3:
            return STR_IT_consumption;
        default:
            return NULL;
        }
    case 13837: /* module 54 call 13 */
        switch (itemIdx) {
        case 0:
            return STR_IT_tank_id;
        default:
            return NULL;
        }
    case 13838: /* module 54 call 14 */
        switch (itemIdx) {
        case 0:
            return STR_IT_owner;
        case 1:
            return STR_IT_descriptor;
        default:
            return NULL;
        }
    case 13839: /* module 54 call 15 */
        switch (itemIdx) {
        case 0:
            return STR_IT_owner;
        case 1:
            return STR_IT_tank_id;
        case 2:
            return STR_IT_user_ids;
        default:
            return NULL;
        }
    case 4608: /* module 18 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_pool_id;
        case 1:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 4611: /* module 18 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_pool_id;
        case 1:
            return STR_IT_member_account;
        case 2:
            return STR_IT_unbonding_points;
        default:
            return NULL;
        }
    case 4612: /* module 18 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_pool_id;
        case 1:
            return STR_IT_num_slashing_spans;
        default:
            return NULL;
        }
    case 4613: /* module 18 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_pool_id;
        case 1:
            return STR_IT_member_account;
        case 2:
            return STR_IT_num_slashing_spans;
        default:
            return NULL;
        }
    case 4614: /* module 18 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_pool_id;
        case 1:
            return STR_IT_deposit;
        case 2:
            return STR_IT_capacity;
        case 3:
            return STR_IT_duration;
        case 4:
            return STR_IT_name;
        default:
            return NULL;
        }
    case 4616: /* module 18 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_pool_id;
        case 1:
            return STR_IT_validators;
        default:
            return NULL;
        }
    case 4619: /* module 18 call 11 */
        switch (itemIdx) {
        case 0:
            return STR_IT_min_join_bond;
        case 1:
            return STR_IT_min_create_bond;
        case 2:
            return STR_IT_global_max_commission;
        case 3:
            return STR_IT_required_payout_count;
        default:
            return NULL;
        }
    case 4621: /* module 18 call 13 */
        switch (itemIdx) {
        case 0:
            return STR_IT_pool_id;
        default:
            return NULL;
        }
    case 4622: /* module 18 call 14 */
        switch (itemIdx) {
        case 0:
            return STR_IT_pool_id;
        default:
            return NULL;
        }
    case 4626: /* module 18 call 18 */
        switch (itemIdx) {
        case 0:
            return STR_IT_validator_stash;
        case 1:
            return STR_IT_era;
        default:
            return NULL;
        }
    case 4627: /* module 18 call 19 */
        switch (itemIdx) {
        case 0:
            return STR_IT_pool_id;
        case 1:
            return STR_IT_mutation;
        default:
            return NULL;
        }
        return STR_ME_MUTATE;
    case 4628: /* module 18 call 20 */
        switch (itemIdx) {
        case 0:
            return STR_IT_pool_id;
        default:
            return NULL;
        }
    case 4629: /* module 18 call 21 */
        switch (itemIdx) {
        case 0:
            return STR_IT_pool_id;
        default:
            return NULL;
        }
    case 4630: /* module 18 call 22 */
        switch (itemIdx) {
        case 0:
            return STR_IT_info;
        default:
            return NULL;
        }
    case 4631: /* module 18 call 23 */
        switch (itemIdx) {
        case 0:
            return STR_IT_pool_count;
        default:
            return NULL;
        }
    case 4632: /* module 18 call 24 */
        switch (itemIdx) {
        case 0:
            return STR_IT_pool_id;
        case 1:
            return STR_IT_payment_id;
        case 2:
            return STR_IT_account_count;
        default:
            return NULL;
        }
    case 4633: /* module 18 call 25 */
        switch (itemIdx) {
        case 0:
            return STR_IT_pool_count;
        default:
            return NULL;
        }
    case 4634: /* module 18 call 26 */
        switch (itemIdx) {
        case 0:
            return STR_IT_pool_id;
        case 1:
            return STR_IT_destination;
        case 2:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 4635: /* module 18 call 27 */
        switch (itemIdx) {
        case 0:
            return STR_IT_pool_id;
        case 1:
            return STR_IT_account_count;
        default:
            return NULL;
        }
    case 4636: /* module 18 call 28 */
        switch (itemIdx) {
        default:
            return NULL;
        }
#endif
    default:
        return NULL;
    }

    return NULL;
}

parser_error_t _getMethod_ItemValue_V7(
    pd_Method_V7_t* m,
    uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx,
    char* outValue, uint16_t outValueLen,
    uint8_t pageIdx, uint8_t* pageCount)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 1536: /* module 6 call 0 */
        switch (itemIdx) {
        case 0: /* balances_transfer_allow_death_V7 - dest */;
            return _toStringAccountIdLookupOfT(
                &m->nested.balances_transfer_allow_death_V7.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_transfer_allow_death_V7 - amount */;
            return _toStringCompactBalance(
                &m->nested.balances_transfer_allow_death_V7.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1538: /* module 6 call 2 */
        switch (itemIdx) {
        case 0: /* balances_force_transfer_V7 - source */;
            return _toStringAccountIdLookupOfT(
                &m->nested.balances_force_transfer_V7.source,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_force_transfer_V7 - dest */;
            return _toStringAccountIdLookupOfT(
                &m->nested.balances_force_transfer_V7.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* balances_force_transfer_V7 - amount */;
            return _toStringCompactBalance(
                &m->nested.balances_force_transfer_V7.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1539: /* module 6 call 3 */
        switch (itemIdx) {
        case 0: /* balances_transfer_keep_alive_V7 - dest */;
            return _toStringAccountIdLookupOfT(
                &m->nested.balances_transfer_keep_alive_V7.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_transfer_keep_alive_V7 - amount */;
            return _toStringCompactBalance(
                &m->nested.balances_transfer_keep_alive_V7.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1540: /* module 6 call 4 */
        switch (itemIdx) {
        case 0: /* balances_transfer_all_V7 - dest */;
            return _toStringAccountIdLookupOfT(
                &m->nested.balances_transfer_all_V7.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_transfer_all_V7 - keep_alive */;
            return _toStringbool(
                &m->nested.balances_transfer_all_V7.keep_alive,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2304: /* module 9 call 0 */
        switch (itemIdx) {
        case 0: /* staking_bond_V7 - amount */;
            return _toStringCompactBalance(
                &m->nested.staking_bond_V7.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_bond_V7 - payee */;
            return _toStringRewardDestination(
                &m->nested.staking_bond_V7.payee,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2305: /* module 9 call 1 */
        switch (itemIdx) {
        case 0: /* staking_bond_extra_V7 - amount */;
            return _toStringCompactBalance(
                &m->nested.staking_bond_extra_V7.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2306: /* module 9 call 2 */
        switch (itemIdx) {
        case 0: /* staking_unbond_V7 - amount */;
            return _toStringCompactBalance(
                &m->nested.staking_unbond_V7.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2307: /* module 9 call 3 */
        switch (itemIdx) {
        case 0: /* staking_withdraw_unbonded_V7 - num_slashing_spans */;
            return _toStringu32(
                &m->nested.staking_withdraw_unbonded_V7.num_slashing_spans,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2308: /* module 9 call 4 */
        switch (itemIdx) {
        case 0: /* staking_validate_V7 - prefs */;
            return _toStringValidatorPrefs(
                &m->nested.staking_validate_V7.prefs,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2309: /* module 9 call 5 */
        switch (itemIdx) {
        case 0: /* staking_nominate_V7 - targets */;
            return _toStringVecAccountIdLookupOfT(
                &m->nested.staking_nominate_V7.targets,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2310: /* module 9 call 6 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 2311: /* module 9 call 7 */
        switch (itemIdx) {
        case 0: /* staking_set_payee_V7 - payee */;
            return _toStringRewardDestination(
                &m->nested.staking_set_payee_V7.payee,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2312: /* module 9 call 8 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 2322: /* module 9 call 18 */
        switch (itemIdx) {
        case 0: /* staking_payout_stakers_V7 - validator_stash */;
            return _toStringAccountId(
                &m->nested.staking_payout_stakers_V7.validator_stash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_payout_stakers_V7 - era */;
            return _toStringEraIndex(
                &m->nested.staking_payout_stakers_V7.era,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2323: /* module 9 call 19 */
        switch (itemIdx) {
        case 0: /* staking_rebond_V7 - amount */;
            return _toStringCompactBalance(
                &m->nested.staking_rebond_V7.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2560: /* module 10 call 0 */
        switch (itemIdx) {
        case 0: /* session_set_keys_V7 - keys */;
            return _toStringKeys(
                &m->nested.session_set_keys_V7.keys,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* session_set_keys_V7 - proof */;
            return _toStringBytes(
                &m->nested.session_set_keys_V7.proof,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2561: /* module 10 call 1 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 5120: /* module 20 call 0 */
        switch (itemIdx) {
        case 0: /* utility_batch_V7 - calls */;
            return _toStringVecCall(
                &m->basic.utility_batch_V7.calls,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5122: /* module 20 call 2 */
        switch (itemIdx) {
        case 0: /* utility_batch_all_V7 - calls */;
            return _toStringVecCall(
                &m->basic.utility_batch_all_V7.calls,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5124: /* module 20 call 4 */
        switch (itemIdx) {
        case 0: /* utility_force_batch_V7 - calls */;
            return _toStringVecCall(
                &m->basic.utility_force_batch_V7.calls,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 18688: /* module 73 call 0 */
        switch (itemIdx) {
        case 0: /* crowdloan_create_V7 - index */;
            return _toStringCompactu32(
                &m->basic.crowdloan_create_V7.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* crowdloan_create_V7 - cap */;
            return _toStringCompactu128(
                &m->basic.crowdloan_create_V7.cap,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* crowdloan_create_V7 - first_period */;
            return _toStringCompactu32(
                &m->basic.crowdloan_create_V7.first_period,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* crowdloan_create_V7 - last_period */;
            return _toStringCompactu32(
                &m->basic.crowdloan_create_V7.last_period,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* crowdloan_create_V7 - end */;
            return _toStringCompactu32(
                &m->basic.crowdloan_create_V7.end,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* crowdloan_create_V7 - verifier */;
            return _toStringOptionMultiSigner(
                &m->basic.crowdloan_create_V7.verifier,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 18689: /* module 73 call 1 */
        switch (itemIdx) {
        case 0: /* crowdloan_contribute_V7 - index */;
            return _toStringCompactu32(
                &m->basic.crowdloan_contribute_V7.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* crowdloan_contribute_V7 - amount */;
            return _toStringCompactu128(
                &m->basic.crowdloan_contribute_V7.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* crowdloan_contribute_V7 - signature */;
            return _toStringOptionMultiSignature(
                &m->basic.crowdloan_contribute_V7.signature,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 18690: /* module 73 call 2 */
        switch (itemIdx) {
        case 0: /* crowdloan_withdraw_V7 - who */;
            return _toStringAccountId(
                &m->basic.crowdloan_withdraw_V7.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* crowdloan_withdraw_V7 - index */;
            return _toStringCompactu32(
                &m->basic.crowdloan_withdraw_V7.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 18691: /* module 73 call 3 */
        switch (itemIdx) {
        case 0: /* crowdloan_refund_V7 - index */;
            return _toStringCompactu32(
                &m->basic.crowdloan_refund_V7.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 18692: /* module 73 call 4 */
        switch (itemIdx) {
        case 0: /* crowdloan_dissolve_V7 - index */;
            return _toStringCompactu32(
                &m->basic.crowdloan_dissolve_V7.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 18693: /* module 73 call 5 */
        switch (itemIdx) {
        case 0: /* crowdloan_edit_V7 - index */;
            return _toStringCompactu32(
                &m->basic.crowdloan_edit_V7.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* crowdloan_edit_V7 - cap */;
            return _toStringCompactu128(
                &m->basic.crowdloan_edit_V7.cap,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* crowdloan_edit_V7 - first_period */;
            return _toStringCompactu32(
                &m->basic.crowdloan_edit_V7.first_period,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* crowdloan_edit_V7 - last_period */;
            return _toStringCompactu32(
                &m->basic.crowdloan_edit_V7.last_period,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* crowdloan_edit_V7 - end */;
            return _toStringCompactu32(
                &m->basic.crowdloan_edit_V7.end,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* crowdloan_edit_V7 - verifier */;
            return _toStringOptionMultiSigner(
                &m->basic.crowdloan_edit_V7.verifier,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 18694: /* module 73 call 6 */
        switch (itemIdx) {
        case 0: /* crowdloan_add_memo_V7 - index */;
            return _toStringParaId(
                &m->basic.crowdloan_add_memo_V7.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* crowdloan_add_memo_V7 - memo */;
            return _toStringVecu8(
                &m->basic.crowdloan_add_memo_V7.memo,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 18695: /* module 73 call 7 */
        switch (itemIdx) {
        case 0: /* crowdloan_poke_V7 - index */;
            return _toStringParaId(
                &m->basic.crowdloan_poke_V7.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 18696: /* module 73 call 8 */
        switch (itemIdx) {
        case 0: /* crowdloan_contribute_all_V7 - index */;
            return _toStringCompactu32(
                &m->basic.crowdloan_contribute_all_V7.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* crowdloan_contribute_all_V7 - signature */;
            return _toStringOptionMultiSignature(
                &m->basic.crowdloan_contribute_all_V7.signature,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
    case 25345: /* module 99 call 1 */
        switch (itemIdx) {
        case 0: /* xcmpallet_teleport_assets_V7 - dest */;
            return _toStringBoxVersionedMultiLocation(
                &m->basic.xcmpallet_teleport_assets_V7.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* xcmpallet_teleport_assets_V7 - beneficiary */;
            return _toStringBoxVersionedMultiLocation(
                &m->basic.xcmpallet_teleport_assets_V7.beneficiary,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* xcmpallet_teleport_assets_V7 - assets */;
            return _toStringBoxVersionedMultiAssets(
                &m->basic.xcmpallet_teleport_assets_V7.assets,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* xcmpallet_teleport_assets_V7 - fee_asset_item */;
            return _toStringu32(
                &m->basic.xcmpallet_teleport_assets_V7.fee_asset_item,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 25346: /* module 99 call 2 */
        switch (itemIdx) {
        case 0: /* xcmpallet_reserve_transfer_assets_V7 - dest */;
            return _toStringBoxVersionedMultiLocation(
                &m->basic.xcmpallet_reserve_transfer_assets_V7.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* xcmpallet_reserve_transfer_assets_V7 - beneficiary */;
            return _toStringBoxVersionedMultiLocation(
                &m->basic.xcmpallet_reserve_transfer_assets_V7.beneficiary,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* xcmpallet_reserve_transfer_assets_V7 - assets */;
            return _toStringBoxVersionedMultiAssets(
                &m->basic.xcmpallet_reserve_transfer_assets_V7.assets,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* xcmpallet_reserve_transfer_assets_V7 - fee_asset_item */;
            return _toStringu32(
                &m->basic.xcmpallet_reserve_transfer_assets_V7.fee_asset_item,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 25352: /* module 99 call 8 */
        switch (itemIdx) {
        case 0: /* xcmpallet_limited_reserve_transfer_assets_V7 - dest */;
            return _toStringBoxVersionedMultiLocation(
                &m->basic.xcmpallet_limited_reserve_transfer_assets_V7.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* xcmpallet_limited_reserve_transfer_assets_V7 - beneficiary */;
            return _toStringBoxVersionedMultiLocation(
                &m->basic.xcmpallet_limited_reserve_transfer_assets_V7.beneficiary,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* xcmpallet_limited_reserve_transfer_assets_V7 - assets */;
            return _toStringBoxVersionedMultiAssets(
                &m->basic.xcmpallet_limited_reserve_transfer_assets_V7.assets,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* xcmpallet_limited_reserve_transfer_assets_V7 - fee_asset_item */;
            return _toStringu32(
                &m->basic.xcmpallet_limited_reserve_transfer_assets_V7.fee_asset_item,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* xcmpallet_limited_reserve_transfer_assets_V7 - weight_limit */;
            return _toStringWeightLimit(
                &m->basic.xcmpallet_limited_reserve_transfer_assets_V7.weight_limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 25353: /* module 99 call 9 */
        switch (itemIdx) {
        case 0: /* xcmpallet_limited_teleport_assets_V7 - dest */;
            return _toStringBoxVersionedMultiLocation(
                &m->basic.xcmpallet_limited_teleport_assets_V7.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* xcmpallet_limited_teleport_assets_V7 - beneficiary */;
            return _toStringBoxVersionedMultiLocation(
                &m->basic.xcmpallet_limited_teleport_assets_V7.beneficiary,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* xcmpallet_limited_teleport_assets_V7 - assets */;
            return _toStringBoxVersionedMultiAssets(
                &m->basic.xcmpallet_limited_teleport_assets_V7.assets,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* xcmpallet_limited_teleport_assets_V7 - fee_asset_item */;
            return _toStringu32(
                &m->basic.xcmpallet_limited_teleport_assets_V7.fee_asset_item,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* xcmpallet_limited_teleport_assets_V7 - weight_limit */;
            return _toStringWeightLimit(
                &m->basic.xcmpallet_limited_teleport_assets_V7.weight_limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
#endif
    case 0: /* module 0 call 0 */
        switch (itemIdx) {
        case 0: /* system_remark_V7 - remark */;
            return _toStringBytes(
                &m->nested.system_remark_V7.remark,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1: /* module 0 call 1 */
        switch (itemIdx) {
        case 0: /* system_set_heap_pages_V7 - pages */;
            return _toStringu64(
                &m->nested.system_set_heap_pages_V7.pages,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2: /* module 0 call 2 */
        switch (itemIdx) {
        case 0: /* system_set_code_V7 - code */;
            return _toStringVecu8(
                &m->nested.system_set_code_V7.code,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3: /* module 0 call 3 */
        switch (itemIdx) {
        case 0: /* system_set_code_without_checks_V7 - code */;
            return _toStringVecu8(
                &m->nested.system_set_code_without_checks_V7.code,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7: /* module 0 call 7 */
        switch (itemIdx) {
        case 0: /* system_remark_with_event_V7 - remark */;
            return _toStringBytes(
                &m->nested.system_remark_with_event_V7.remark,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 25856: /* module 101 call 0 */
        switch (itemIdx) {
        case 0: /* preimage_note_preimage_V7 - bytes */;
            return _toStringVecu8(
                &m->basic.preimage_note_preimage_V7.bytes,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 25857: /* module 101 call 1 */
        switch (itemIdx) {
        case 0: /* preimage_unnote_preimage_V7 - hash */;
            return _toStringHash(
                &m->basic.preimage_unnote_preimage_V7.hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 25858: /* module 101 call 2 */
        switch (itemIdx) {
        case 0: /* preimage_request_preimage_V7 - hash */;
            return _toStringHash(
                &m->basic.preimage_request_preimage_V7.hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 25859: /* module 101 call 3 */
        switch (itemIdx) {
        case 0: /* preimage_unrequest_preimage_V7 - hash */;
            return _toStringHash(
                &m->basic.preimage_unrequest_preimage_V7.hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 25860: /* module 101 call 4 */
        switch (itemIdx) {
        case 0: /* preimage_ensure_updated_V7 - hashes */;
            return _toStringVecHash(
                &m->basic.preimage_ensure_updated_V7.hashes,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 512: /* module 2 call 0 */
        switch (itemIdx) {
        case 0: /* timestamp_set_V7 - now */;
            return _toStringCompactu64(
                &m->basic.timestamp_set_V7.now,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1541: /* module 6 call 5 */
        switch (itemIdx) {
        case 0: /* balances_force_unreserve_V7 - who */;
            return _toStringAccountIdLookupOfT(
                &m->basic.balances_force_unreserve_V7.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_force_unreserve_V7 - amount */;
            return _toStringBalance(
                &m->basic.balances_force_unreserve_V7.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1542: /* module 6 call 6 */
        switch (itemIdx) {
        case 0: /* balances_upgrade_accounts_V7 - who */;
            return _toStringVecAccountId(
                &m->basic.balances_upgrade_accounts_V7.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1544: /* module 6 call 8 */
        switch (itemIdx) {
        case 0: /* balances_force_set_balance_V7 - who */;
            return _toStringAccountIdLookupOfT(
                &m->basic.balances_force_set_balance_V7.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_force_set_balance_V7 - new_free */;
            return _toStringCompactBalance(
                &m->basic.balances_force_set_balance_V7.new_free,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2313: /* module 9 call 9 */
        switch (itemIdx) {
        case 0: /* staking_set_validator_count_V7 - new_ */;
            return _toStringCompactu32(
                &m->basic.staking_set_validator_count_V7.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2314: /* module 9 call 10 */
        switch (itemIdx) {
        case 0: /* staking_increase_validator_count_V7 - additional */;
            return _toStringCompactu32(
                &m->basic.staking_increase_validator_count_V7.additional,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2315: /* module 9 call 11 */
        switch (itemIdx) {
        case 0: /* staking_scale_validator_count_V7 - factor */;
            return _toStringPercent(
                &m->basic.staking_scale_validator_count_V7.factor,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2316: /* module 9 call 12 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 2317: /* module 9 call 13 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 2318: /* module 9 call 14 */
        switch (itemIdx) {
        case 0: /* staking_set_invulnerables_V7 - invulnerables */;
            return _toStringVecAccountId(
                &m->basic.staking_set_invulnerables_V7.invulnerables,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2319: /* module 9 call 15 */
        switch (itemIdx) {
        case 0: /* staking_force_unstake_V7 - stash */;
            return _toStringAccountId(
                &m->basic.staking_force_unstake_V7.stash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_force_unstake_V7 - num_slashing_spans */;
            return _toStringu32(
                &m->basic.staking_force_unstake_V7.num_slashing_spans,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2320: /* module 9 call 16 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 2321: /* module 9 call 17 */
        switch (itemIdx) {
        case 0: /* staking_cancel_deferred_slash_V7 - era */;
            return _toStringEraIndex(
                &m->basic.staking_cancel_deferred_slash_V7.era,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_cancel_deferred_slash_V7 - slash_indices */;
            return _toStringVecu32(
                &m->basic.staking_cancel_deferred_slash_V7.slash_indices,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2324: /* module 9 call 20 */
        switch (itemIdx) {
        case 0: /* staking_reap_stash_V7 - stash */;
            return _toStringAccountId(
                &m->basic.staking_reap_stash_V7.stash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_reap_stash_V7 - num_slashing_spans */;
            return _toStringu32(
                &m->basic.staking_reap_stash_V7.num_slashing_spans,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2325: /* module 9 call 21 */
        switch (itemIdx) {
        case 0: /* staking_kick_V7 - who */;
            return _toStringVecAccountIdLookupOfT(
                &m->basic.staking_kick_V7.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2326: /* module 9 call 22 */
        switch (itemIdx) {
        case 0: /* staking_set_staking_configs_V7 - min_nominator_bond */;
            return _toStringConfigOpBalanceOfT(
                &m->basic.staking_set_staking_configs_V7.min_nominator_bond,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_set_staking_configs_V7 - min_validator_bond */;
            return _toStringConfigOpBalanceOfT(
                &m->basic.staking_set_staking_configs_V7.min_validator_bond,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* staking_set_staking_configs_V7 - max_nominator_count */;
            return _toStringConfigOpu32(
                &m->basic.staking_set_staking_configs_V7.max_nominator_count,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* staking_set_staking_configs_V7 - max_validator_count */;
            return _toStringConfigOpu32(
                &m->basic.staking_set_staking_configs_V7.max_validator_count,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* staking_set_staking_configs_V7 - chill_threshold */;
            return _toStringConfigOpPercent(
                &m->basic.staking_set_staking_configs_V7.chill_threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* staking_set_staking_configs_V7 - min_commission */;
            return _toStringConfigOpPerbill(
                &m->basic.staking_set_staking_configs_V7.min_commission,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2327: /* module 9 call 23 */
        switch (itemIdx) {
        case 0: /* staking_chill_other_V7 - controller */;
            return _toStringAccountId(
                &m->basic.staking_chill_other_V7.controller,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2328: /* module 9 call 24 */
        switch (itemIdx) {
        case 0: /* staking_force_apply_min_commission_V7 - validator_stash */;
            return _toStringAccountId(
                &m->basic.staking_force_apply_min_commission_V7.validator_stash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2329: /* module 9 call 25 */
        switch (itemIdx) {
        case 0: /* staking_set_min_commission_V7 - new_ */;
            return _toStringPerbill(
                &m->basic.staking_set_min_commission_V7.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3072: /* module 12 call 0 */
        switch (itemIdx) {
        case 0: /* treasury_propose_spend_V7 - amount */;
            return _toStringCompactBalance(
                &m->basic.treasury_propose_spend_V7.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* treasury_propose_spend_V7 - beneficiary */;
            return _toStringAccountIdLookupOfT(
                &m->basic.treasury_propose_spend_V7.beneficiary,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3073: /* module 12 call 1 */
        switch (itemIdx) {
        case 0: /* treasury_reject_proposal_V7 - proposal_id */;
            return _toStringCompactu32(
                &m->basic.treasury_reject_proposal_V7.proposal_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3074: /* module 12 call 2 */
        switch (itemIdx) {
        case 0: /* treasury_approve_proposal_V7 - proposal_id */;
            return _toStringCompactu32(
                &m->basic.treasury_approve_proposal_V7.proposal_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3075: /* module 12 call 3 */
        switch (itemIdx) {
        case 0: /* treasury_spend_local_V7 - amount */;
            return _toStringCompactBalance(
                &m->basic.treasury_spend_local_V7.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* treasury_spend_local_V7 - beneficiary */;
            return _toStringAccountIdLookupOfT(
                &m->basic.treasury_spend_local_V7.beneficiary,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3076: /* module 12 call 4 */
        switch (itemIdx) {
        case 0: /* treasury_remove_approval_V7 - proposal_id */;
            return _toStringCompactu32(
                &m->basic.treasury_remove_approval_V7.proposal_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3078: /* module 12 call 6 */
        switch (itemIdx) {
        case 0: /* treasury_payout_V7 - index */;
            return _toStringSpendIndex(
                &m->basic.treasury_payout_V7.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3079: /* module 12 call 7 */
        switch (itemIdx) {
        case 0: /* treasury_check_status_V7 - index */;
            return _toStringSpendIndex(
                &m->basic.treasury_check_status_V7.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3080: /* module 12 call 8 */
        switch (itemIdx) {
        case 0: /* treasury_void_spend_V7 - index */;
            return _toStringSpendIndex(
                &m->basic.treasury_void_spend_V7.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 26112: /* module 102 call 0 */
        switch (itemIdx) {
        case 0: /* convictionvoting_vote_V7 - poll_index */;
            return _toStringCompactu32(
                &m->nested.convictionvoting_vote_V7.poll_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* convictionvoting_vote_V7 - vote */;
            return _toStringAccountVote(
                &m->nested.convictionvoting_vote_V7.vote,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 26113: /* module 102 call 1 */
        switch (itemIdx) {
        case 0: /* convictionvoting_delegate_V7 - class_ */;
            return _toStringClassOf(
                &m->nested.convictionvoting_delegate_V7.class_,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* convictionvoting_delegate_V7 - to */;
            return _toStringAccountIdLookupOfT(
                &m->nested.convictionvoting_delegate_V7.to,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* convictionvoting_delegate_V7 - conviction */;
            return _toStringConviction(
                &m->nested.convictionvoting_delegate_V7.conviction,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* convictionvoting_delegate_V7 - balance */;
            return _toStringBalanceOf(
                &m->nested.convictionvoting_delegate_V7.balance,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 26114: /* module 102 call 2 */
        switch (itemIdx) {
        case 0: /* convictionvoting_undelegate_V7 - class_ */;
            return _toStringClassOf(
                &m->nested.convictionvoting_undelegate_V7.class_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 26115: /* module 102 call 3 */
        switch (itemIdx) {
        case 0: /* convictionvoting_unlock_V7 - class_ */;
            return _toStringClassOf(
                &m->nested.convictionvoting_unlock_V7.class_,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* convictionvoting_unlock_V7 - target */;
            return _toStringAccountIdLookupOfT(
                &m->nested.convictionvoting_unlock_V7.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 26116: /* module 102 call 4 */
        switch (itemIdx) {
        case 0: /* convictionvoting_remove_vote_V7 - class_ */;
            return _toStringOptionClassOf(
                &m->nested.convictionvoting_remove_vote_V7.class_,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* convictionvoting_remove_vote_V7 - index */;
            return _toStringPollIndexOf(
                &m->nested.convictionvoting_remove_vote_V7.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 26117: /* module 102 call 5 */
        switch (itemIdx) {
        case 0: /* convictionvoting_remove_other_vote_V7 - target */;
            return _toStringAccountIdLookupOfT(
                &m->nested.convictionvoting_remove_other_vote_V7.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* convictionvoting_remove_other_vote_V7 - class_ */;
            return _toStringClassOf(
                &m->nested.convictionvoting_remove_other_vote_V7.class_,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* convictionvoting_remove_other_vote_V7 - index */;
            return _toStringPollIndexOf(
                &m->nested.convictionvoting_remove_other_vote_V7.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 26368: /* module 103 call 0 */
        switch (itemIdx) {
        case 0: /* referenda_submit_V7 - proposal_origin */;
            return _toStringBoxPalletsOrigin(
                &m->basic.referenda_submit_V7.proposal_origin,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* referenda_submit_V7 - proposal */;
            return _toStringBoundedCallOfT(
                &m->basic.referenda_submit_V7.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* referenda_submit_V7 - enactment_moment */;
            return _toStringDispatchTimeBlockNumber(
                &m->basic.referenda_submit_V7.enactment_moment,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 26369: /* module 103 call 1 */
        switch (itemIdx) {
        case 0: /* referenda_place_decision_deposit_V7 - index */;
            return _toStringReferendumIndex(
                &m->basic.referenda_place_decision_deposit_V7.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 26370: /* module 103 call 2 */
        switch (itemIdx) {
        case 0: /* referenda_refund_decision_deposit_V7 - index */;
            return _toStringReferendumIndex(
                &m->basic.referenda_refund_decision_deposit_V7.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 26371: /* module 103 call 3 */
        switch (itemIdx) {
        case 0: /* referenda_cancel_V7 - index */;
            return _toStringReferendumIndex(
                &m->basic.referenda_cancel_V7.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 26372: /* module 103 call 4 */
        switch (itemIdx) {
        case 0: /* referenda_kill_V7 - index */;
            return _toStringReferendumIndex(
                &m->basic.referenda_kill_V7.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 26373: /* module 103 call 5 */
        switch (itemIdx) {
        case 0: /* referenda_nudge_referendum_V7 - index */;
            return _toStringReferendumIndex(
                &m->basic.referenda_nudge_referendum_V7.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 26374: /* module 103 call 6 */
        switch (itemIdx) {
        case 0: /* referenda_one_fewer_deciding_V7 - track */;
            return _toStringTrackIdOf(
                &m->basic.referenda_one_fewer_deciding_V7.track,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 26375: /* module 103 call 7 */
        switch (itemIdx) {
        case 0: /* referenda_refund_submission_deposit_V7 - index */;
            return _toStringReferendumIndex(
                &m->basic.referenda_refund_submission_deposit_V7.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 26376: /* module 103 call 8 */
        switch (itemIdx) {
        case 0: /* referenda_set_metadata_V7 - index */;
            return _toStringReferendumIndex(
                &m->basic.referenda_set_metadata_V7.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* referenda_set_metadata_V7 - maybe_hash */;
            return _toStringOptionHash(
                &m->basic.referenda_set_metadata_V7.maybe_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 26880: /* module 105 call 0 */
        switch (itemIdx) {
        case 0: /* whitelist_whitelist_call_V7 - call_hash */;
            return _toStringHash(
                &m->basic.whitelist_whitelist_call_V7.call_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 26881: /* module 105 call 1 */
        switch (itemIdx) {
        case 0: /* whitelist_remove_whitelisted_call_V7 - call_hash */;
            return _toStringHash(
                &m->basic.whitelist_remove_whitelisted_call_V7.call_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 26882: /* module 105 call 2 */
        switch (itemIdx) {
        case 0: /* whitelist_dispatch_whitelisted_call_V7 - call_hash */;
            return _toStringHash(
                &m->basic.whitelist_dispatch_whitelisted_call_V7.call_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* whitelist_dispatch_whitelisted_call_V7 - call_encoded_len */;
            return _toStringu32(
                &m->basic.whitelist_dispatch_whitelisted_call_V7.call_encoded_len,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* whitelist_dispatch_whitelisted_call_V7 - call_weight_witness */;
            return _toStringWeight(
                &m->basic.whitelist_dispatch_whitelisted_call_V7.call_weight_witness,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 26883: /* module 105 call 3 */
        switch (itemIdx) {
        case 0: /* whitelist_dispatch_whitelisted_call_with_preimage_V7 - call */;
            return _toStringCall(
                &m->basic.whitelist_dispatch_whitelisted_call_with_preimage_V7.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5123: /* module 20 call 3 */
        switch (itemIdx) {
        case 0: /* utility_dispatch_as_V7 - as_origin */;
            return _toStringBoxPalletsOrigin(
                &m->basic.utility_dispatch_as_V7.as_origin,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* utility_dispatch_as_V7 - call */;
            return _toStringCall(
                &m->basic.utility_dispatch_as_V7.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5125: /* module 20 call 5 */
        switch (itemIdx) {
        case 0: /* utility_with_weight_V7 - call */;
            return _toStringCall(
                &m->basic.utility_with_weight_V7.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* utility_with_weight_V7 - weight */;
            return _toStringWeight(
                &m->basic.utility_with_weight_V7.weight,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 27648: /* module 108 call 0 */
        switch (itemIdx) {
        case 0: /* identity_add_registrar_V7 - account */;
            return _toStringAccountIdLookupOfT(
                &m->basic.identity_add_registrar_V7.account,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 27649: /* module 108 call 1 */
        switch (itemIdx) {
        case 0: /* identity_set_identity_V7 - info */;
            return _toStringIdentityInfo(
                &m->basic.identity_set_identity_V7.info,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 27650: /* module 108 call 2 */
        switch (itemIdx) {
        case 0: /* identity_set_subs_V7 - subs */;
            return _toStringVecTupleAccountIdData(
                &m->basic.identity_set_subs_V7.subs,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 27651: /* module 108 call 3 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 27652: /* module 108 call 4 */
        switch (itemIdx) {
        case 0: /* identity_request_judgement_V7 - reg_index */;
            return _toStringCompactu32(
                &m->basic.identity_request_judgement_V7.reg_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_request_judgement_V7 - max_fee */;
            return _toStringCompactu128(
                &m->basic.identity_request_judgement_V7.max_fee,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 27653: /* module 108 call 5 */
        switch (itemIdx) {
        case 0: /* identity_cancel_request_V7 - reg_index */;
            return _toStringRegistrarIndex(
                &m->basic.identity_cancel_request_V7.reg_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 27654: /* module 108 call 6 */
        switch (itemIdx) {
        case 0: /* identity_set_fee_V7 - index */;
            return _toStringCompactu32(
                &m->basic.identity_set_fee_V7.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_set_fee_V7 - fee */;
            return _toStringCompactu128(
                &m->basic.identity_set_fee_V7.fee,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 27655: /* module 108 call 7 */
        switch (itemIdx) {
        case 0: /* identity_set_account_id_V7 - index */;
            return _toStringCompactu32(
                &m->basic.identity_set_account_id_V7.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_set_account_id_V7 - new_ */;
            return _toStringAccountIdLookupOfT(
                &m->basic.identity_set_account_id_V7.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 27657: /* module 108 call 9 */
        switch (itemIdx) {
        case 0: /* identity_provide_judgement_V7 - reg_index */;
            return _toStringCompactu32(
                &m->basic.identity_provide_judgement_V7.reg_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_provide_judgement_V7 - target */;
            return _toStringAccountIdLookupOfT(
                &m->basic.identity_provide_judgement_V7.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* identity_provide_judgement_V7 - judgement */;
            return _toStringJudgementBalanceOfT(
                &m->basic.identity_provide_judgement_V7.judgement,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* identity_provide_judgement_V7 - identity */;
            return _toStringHash(
                &m->basic.identity_provide_judgement_V7.identity,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 27658: /* module 108 call 10 */
        switch (itemIdx) {
        case 0: /* identity_kill_identity_V7 - target */;
            return _toStringAccountIdLookupOfT(
                &m->basic.identity_kill_identity_V7.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 27659: /* module 108 call 11 */
        switch (itemIdx) {
        case 0: /* identity_add_sub_V7 - sub */;
            return _toStringAccountIdLookupOfT(
                &m->basic.identity_add_sub_V7.sub,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_add_sub_V7 - data */;
            return _toStringData(
                &m->basic.identity_add_sub_V7.data,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 27660: /* module 108 call 12 */
        switch (itemIdx) {
        case 0: /* identity_rename_sub_V7 - sub */;
            return _toStringAccountIdLookupOfT(
                &m->basic.identity_rename_sub_V7.sub,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_rename_sub_V7 - data */;
            return _toStringData(
                &m->basic.identity_rename_sub_V7.data,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 27661: /* module 108 call 13 */
        switch (itemIdx) {
        case 0: /* identity_remove_sub_V7 - sub */;
            return _toStringAccountIdLookupOfT(
                &m->basic.identity_remove_sub_V7.sub,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 27662: /* module 108 call 14 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 7424: /* module 29 call 0 */
        switch (itemIdx) {
        case 0: /* proxy_proxy_V7 - real */;
            return _toStringAccountIdLookupOfT(
                &m->nested.proxy_proxy_V7.real,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_proxy_V7 - force_proxy_type */;
            return _toStringOptionProxyType(
                &m->nested.proxy_proxy_V7.force_proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* proxy_proxy_V7 - call */;
            return _toStringCall(
                &m->nested.proxy_proxy_V7.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7425: /* module 29 call 1 */
        switch (itemIdx) {
        case 0: /* proxy_add_proxy_V7 - delegate */;
            return _toStringAccountIdLookupOfT(
                &m->nested.proxy_add_proxy_V7.delegate,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_add_proxy_V7 - proxy_type */;
            return _toStringProxyType(
                &m->nested.proxy_add_proxy_V7.proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* proxy_add_proxy_V7 - delay */;
            return _toStringBlockNumber(
                &m->nested.proxy_add_proxy_V7.delay,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7426: /* module 29 call 2 */
        switch (itemIdx) {
        case 0: /* proxy_remove_proxy_V7 - delegate */;
            return _toStringAccountIdLookupOfT(
                &m->nested.proxy_remove_proxy_V7.delegate,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_remove_proxy_V7 - proxy_type */;
            return _toStringProxyType(
                &m->nested.proxy_remove_proxy_V7.proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* proxy_remove_proxy_V7 - delay */;
            return _toStringBlockNumber(
                &m->nested.proxy_remove_proxy_V7.delay,
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
        case 0: /* proxy_create_pure_V7 - proxy_type */;
            return _toStringProxyType(
                &m->nested.proxy_create_pure_V7.proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_create_pure_V7 - delay */;
            return _toStringBlockNumber(
                &m->nested.proxy_create_pure_V7.delay,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* proxy_create_pure_V7 - index */;
            return _toStringu16(
                &m->nested.proxy_create_pure_V7.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7429: /* module 29 call 5 */
        switch (itemIdx) {
        case 0: /* proxy_kill_pure_V7 - spawner */;
            return _toStringAccountIdLookupOfT(
                &m->nested.proxy_kill_pure_V7.spawner,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_kill_pure_V7 - proxy_type */;
            return _toStringProxyType(
                &m->nested.proxy_kill_pure_V7.proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* proxy_kill_pure_V7 - index */;
            return _toStringu16(
                &m->nested.proxy_kill_pure_V7.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* proxy_kill_pure_V7 - height */;
            return _toStringCompactu32(
                &m->nested.proxy_kill_pure_V7.height,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* proxy_kill_pure_V7 - ext_index */;
            return _toStringCompactu32(
                &m->nested.proxy_kill_pure_V7.ext_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7433: /* module 29 call 9 */
        switch (itemIdx) {
        case 0: /* proxy_proxy_announced_V7 - delegate */;
            return _toStringAccountIdLookupOfT(
                &m->basic.proxy_proxy_announced_V7.delegate,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_proxy_announced_V7 - real */;
            return _toStringAccountIdLookupOfT(
                &m->basic.proxy_proxy_announced_V7.real,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* proxy_proxy_announced_V7 - force_proxy_type */;
            return _toStringOptionProxyType(
                &m->basic.proxy_proxy_announced_V7.force_proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* proxy_proxy_announced_V7 - call */;
            return _toStringCall(
                &m->basic.proxy_proxy_announced_V7.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5376: /* module 21 call 0 */
        switch (itemIdx) {
        case 0: /* multisig_as_multi_threshold_1_V7 - other_signatories */;
            return _toStringVecAccountId(
                &m->nested.multisig_as_multi_threshold_1_V7.other_signatories,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_as_multi_threshold_1_V7 - call */;
            return _toStringCall(
                &m->nested.multisig_as_multi_threshold_1_V7.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5377: /* module 21 call 1 */
        switch (itemIdx) {
        case 0: /* multisig_as_multi_V7 - threshold */;
            return _toStringu16(
                &m->nested.multisig_as_multi_V7.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_as_multi_V7 - other_signatories */;
            return _toStringVecAccountId(
                &m->nested.multisig_as_multi_V7.other_signatories,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* multisig_as_multi_V7 - maybe_timepoint */;
            return _toStringOptionTimepoint(
                &m->nested.multisig_as_multi_V7.maybe_timepoint,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* multisig_as_multi_V7 - call */;
            return _toStringCall(
                &m->nested.multisig_as_multi_V7.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* multisig_as_multi_V7 - max_weight */;
            return _toStringWeight(
                &m->nested.multisig_as_multi_V7.max_weight,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5378: /* module 21 call 2 */
        switch (itemIdx) {
        case 0: /* multisig_approve_as_multi_V7 - threshold */;
            return _toStringu16(
                &m->nested.multisig_approve_as_multi_V7.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_approve_as_multi_V7 - other_signatories */;
            return _toStringVecAccountId(
                &m->nested.multisig_approve_as_multi_V7.other_signatories,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* multisig_approve_as_multi_V7 - maybe_timepoint */;
            return _toStringOptionTimepoint(
                &m->nested.multisig_approve_as_multi_V7.maybe_timepoint,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* multisig_approve_as_multi_V7 - call_hash */;
            return _toStringH256(
                &m->nested.multisig_approve_as_multi_V7.call_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* multisig_approve_as_multi_V7 - max_weight */;
            return _toStringWeight(
                &m->nested.multisig_approve_as_multi_V7.max_weight,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5379: /* module 21 call 3 */
        switch (itemIdx) {
        case 0: /* multisig_cancel_as_multi_V7 - threshold */;
            return _toStringu16(
                &m->nested.multisig_cancel_as_multi_V7.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_cancel_as_multi_V7 - other_signatories */;
            return _toStringVecAccountId(
                &m->nested.multisig_cancel_as_multi_V7.other_signatories,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* multisig_cancel_as_multi_V7 - timepoint */;
            return _toStringTimepoint(
                &m->nested.multisig_cancel_as_multi_V7.timepoint,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* multisig_cancel_as_multi_V7 - call_hash */;
            return _toStringH256(
                &m->nested.multisig_cancel_as_multi_V7.call_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4352: /* module 17 call 0 */
        switch (itemIdx) {
        case 0: /* voterlist_rebag_V7 - dislocated */;
            return _toStringAccountIdLookupOfT(
                &m->basic.voterlist_rebag_V7.dislocated,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4353: /* module 17 call 1 */
        switch (itemIdx) {
        case 0: /* voterlist_put_in_front_of_V7 - lighter */;
            return _toStringAccountIdLookupOfT(
                &m->basic.voterlist_put_in_front_of_V7.lighter,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4354: /* module 17 call 2 */
        switch (itemIdx) {
        case 0: /* voterlist_put_in_front_of_other_V7 - heavier */;
            return _toStringAccountIdLookupOfT(
                &m->basic.voterlist_put_in_front_of_other_V7.heavier,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* voterlist_put_in_front_of_other_V7 - lighter */;
            return _toStringAccountIdLookupOfT(
                &m->basic.voterlist_put_in_front_of_other_V7.lighter,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13056: /* module 51 call 0 */
        switch (itemIdx) {
        case 0: /* configuration_set_validation_upgrade_cooldown_V7 - new_ */;
            return _toStringBlockNumber(
                &m->basic.configuration_set_validation_upgrade_cooldown_V7.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13057: /* module 51 call 1 */
        switch (itemIdx) {
        case 0: /* configuration_set_validation_upgrade_delay_V7 - new_ */;
            return _toStringBlockNumber(
                &m->basic.configuration_set_validation_upgrade_delay_V7.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13058: /* module 51 call 2 */
        switch (itemIdx) {
        case 0: /* configuration_set_code_retention_period_V7 - new_ */;
            return _toStringBlockNumber(
                &m->basic.configuration_set_code_retention_period_V7.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13059: /* module 51 call 3 */
        switch (itemIdx) {
        case 0: /* configuration_set_max_code_size_V7 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_max_code_size_V7.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13060: /* module 51 call 4 */
        switch (itemIdx) {
        case 0: /* configuration_set_max_pov_size_V7 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_max_pov_size_V7.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13061: /* module 51 call 5 */
        switch (itemIdx) {
        case 0: /* configuration_set_max_head_data_size_V7 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_max_head_data_size_V7.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13062: /* module 51 call 6 */
        switch (itemIdx) {
        case 0: /* configuration_set_on_demand_cores_V7 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_on_demand_cores_V7.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13063: /* module 51 call 7 */
        switch (itemIdx) {
        case 0: /* configuration_set_on_demand_retries_V7 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_on_demand_retries_V7.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13064: /* module 51 call 8 */
        switch (itemIdx) {
        case 0: /* configuration_set_group_rotation_frequency_V7 - new_ */;
            return _toStringBlockNumber(
                &m->basic.configuration_set_group_rotation_frequency_V7.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13065: /* module 51 call 9 */
        switch (itemIdx) {
        case 0: /* configuration_set_paras_availability_period_V7 - new_ */;
            return _toStringBlockNumber(
                &m->basic.configuration_set_paras_availability_period_V7.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13067: /* module 51 call 11 */
        switch (itemIdx) {
        case 0: /* configuration_set_scheduling_lookahead_V7 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_scheduling_lookahead_V7.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13068: /* module 51 call 12 */
        switch (itemIdx) {
        case 0: /* configuration_set_max_validators_per_core_V7 - new_ */;
            return _toStringOptionu32(
                &m->basic.configuration_set_max_validators_per_core_V7.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13069: /* module 51 call 13 */
        switch (itemIdx) {
        case 0: /* configuration_set_max_validators_V7 - new_ */;
            return _toStringOptionu32(
                &m->basic.configuration_set_max_validators_V7.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13071: /* module 51 call 15 */
        switch (itemIdx) {
        case 0: /* configuration_set_dispute_post_conclusion_acceptance_period_V7 - new_ */;
            return _toStringBlockNumber(
                &m->basic.configuration_set_dispute_post_conclusion_acceptance_period_V7.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13074: /* module 51 call 18 */
        switch (itemIdx) {
        case 0: /* configuration_set_no_show_slots_V7 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_no_show_slots_V7.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13075: /* module 51 call 19 */
        switch (itemIdx) {
        case 0: /* configuration_set_n_delay_tranches_V7 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_n_delay_tranches_V7.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13076: /* module 51 call 20 */
        switch (itemIdx) {
        case 0: /* configuration_set_zeroth_delay_tranche_width_V7 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_zeroth_delay_tranche_width_V7.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13077: /* module 51 call 21 */
        switch (itemIdx) {
        case 0: /* configuration_set_needed_approvals_V7 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_needed_approvals_V7.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13078: /* module 51 call 22 */
        switch (itemIdx) {
        case 0: /* configuration_set_relay_vrf_modulo_samples_V7 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_relay_vrf_modulo_samples_V7.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13079: /* module 51 call 23 */
        switch (itemIdx) {
        case 0: /* configuration_set_max_upward_queue_count_V7 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_max_upward_queue_count_V7.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13080: /* module 51 call 24 */
        switch (itemIdx) {
        case 0: /* configuration_set_max_upward_queue_size_V7 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_max_upward_queue_size_V7.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13081: /* module 51 call 25 */
        switch (itemIdx) {
        case 0: /* configuration_set_max_downward_message_size_V7 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_max_downward_message_size_V7.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13083: /* module 51 call 27 */
        switch (itemIdx) {
        case 0: /* configuration_set_max_upward_message_size_V7 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_max_upward_message_size_V7.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13084: /* module 51 call 28 */
        switch (itemIdx) {
        case 0: /* configuration_set_max_upward_message_num_per_candidate_V7 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_max_upward_message_num_per_candidate_V7.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13085: /* module 51 call 29 */
        switch (itemIdx) {
        case 0: /* configuration_set_hrmp_open_request_ttl_V7 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_hrmp_open_request_ttl_V7.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13086: /* module 51 call 30 */
        switch (itemIdx) {
        case 0: /* configuration_set_hrmp_sender_deposit_V7 - new_ */;
            return _toStringBalance(
                &m->basic.configuration_set_hrmp_sender_deposit_V7.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13087: /* module 51 call 31 */
        switch (itemIdx) {
        case 0: /* configuration_set_hrmp_recipient_deposit_V7 - new_ */;
            return _toStringBalance(
                &m->basic.configuration_set_hrmp_recipient_deposit_V7.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13088: /* module 51 call 32 */
        switch (itemIdx) {
        case 0: /* configuration_set_hrmp_channel_max_capacity_V7 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_hrmp_channel_max_capacity_V7.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13089: /* module 51 call 33 */
        switch (itemIdx) {
        case 0: /* configuration_set_hrmp_channel_max_total_size_V7 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_hrmp_channel_max_total_size_V7.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13090: /* module 51 call 34 */
        switch (itemIdx) {
        case 0: /* configuration_set_hrmp_max_parachain_inbound_channels_V7 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_hrmp_max_parachain_inbound_channels_V7.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13092: /* module 51 call 36 */
        switch (itemIdx) {
        case 0: /* configuration_set_hrmp_channel_max_message_size_V7 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_hrmp_channel_max_message_size_V7.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13093: /* module 51 call 37 */
        switch (itemIdx) {
        case 0: /* configuration_set_hrmp_max_parachain_outbound_channels_V7 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_hrmp_max_parachain_outbound_channels_V7.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13095: /* module 51 call 39 */
        switch (itemIdx) {
        case 0: /* configuration_set_hrmp_max_message_num_per_candidate_V7 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_hrmp_max_message_num_per_candidate_V7.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13098: /* module 51 call 42 */
        switch (itemIdx) {
        case 0: /* configuration_set_pvf_voting_ttl_V7 - new_ */;
            return _toStringSessionIndex(
                &m->basic.configuration_set_pvf_voting_ttl_V7.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13099: /* module 51 call 43 */
        switch (itemIdx) {
        case 0: /* configuration_set_minimum_validation_upgrade_delay_V7 - new_ */;
            return _toStringBlockNumber(
                &m->basic.configuration_set_minimum_validation_upgrade_delay_V7.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13100: /* module 51 call 44 */
        switch (itemIdx) {
        case 0: /* configuration_set_bypass_consistency_check_V7 - new_ */;
            return _toStringbool(
                &m->basic.configuration_set_bypass_consistency_check_V7.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13103: /* module 51 call 47 */
        switch (itemIdx) {
        case 0: /* configuration_set_on_demand_base_fee_V7 - new_ */;
            return _toStringBalance(
                &m->basic.configuration_set_on_demand_base_fee_V7.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13104: /* module 51 call 48 */
        switch (itemIdx) {
        case 0: /* configuration_set_on_demand_fee_variability_V7 - new_ */;
            return _toStringPerbill(
                &m->basic.configuration_set_on_demand_fee_variability_V7.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13105: /* module 51 call 49 */
        switch (itemIdx) {
        case 0: /* configuration_set_on_demand_queue_max_size_V7 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_on_demand_queue_max_size_V7.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13106: /* module 51 call 50 */
        switch (itemIdx) {
        case 0: /* configuration_set_on_demand_target_queue_utilization_V7 - new_ */;
            return _toStringPerbill(
                &m->basic.configuration_set_on_demand_target_queue_utilization_V7.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13107: /* module 51 call 51 */
        switch (itemIdx) {
        case 0: /* configuration_set_on_demand_ttl_V7 - new_ */;
            return _toStringBlockNumber(
                &m->basic.configuration_set_on_demand_ttl_V7.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13108: /* module 51 call 52 */
        switch (itemIdx) {
        case 0: /* configuration_set_minimum_backing_votes_V7 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_minimum_backing_votes_V7.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 14592: /* module 57 call 0 */
        switch (itemIdx) {
        case 0: /* initializer_force_approve_V7 - up_to */;
            return _toStringBlockNumber(
                &m->basic.initializer_force_approve_V7.up_to,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 15872: /* module 62 call 0 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 18432: /* module 72 call 0 */
        switch (itemIdx) {
        case 0: /* auctions_new_auction_V7 - duration */;
            return _toStringCompactu32(
                &m->basic.auctions_new_auction_V7.duration,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* auctions_new_auction_V7 - lease_period_index */;
            return _toStringCompactu32(
                &m->basic.auctions_new_auction_V7.lease_period_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 18433: /* module 72 call 1 */
        switch (itemIdx) {
        case 0: /* auctions_bid_V7 - para */;
            return _toStringCompactu32(
                &m->basic.auctions_bid_V7.para,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* auctions_bid_V7 - auction_index */;
            return _toStringCompactu32(
                &m->basic.auctions_bid_V7.auction_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* auctions_bid_V7 - first_slot */;
            return _toStringCompactu32(
                &m->basic.auctions_bid_V7.first_slot,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* auctions_bid_V7 - last_slot */;
            return _toStringCompactu32(
                &m->basic.auctions_bid_V7.last_slot,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* auctions_bid_V7 - amount */;
            return _toStringCompactBalance(
                &m->basic.auctions_bid_V7.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 18434: /* module 72 call 2 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
//////////////////////////////
// Custom
//////////////////////////////
    case 27904: /* module 109 call 0 */
        switch (itemIdx) {
        case 0: /* votemanager_vote_V7 - poll_index */;
            return _toStringCompactu32(
                &m->basic.votemanager_vote_V7.poll_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* votemanager_vote_V7 - vote */;
            return _toStringAccountVote(
                &m->basic.votemanager_vote_V7.vote,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* votemanager_vote_V7 - currency */;
            return _toStringVoteCurrency(
                &m->basic.votemanager_vote_V7.currency,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 27905: /* module 109 call 1 */
        switch (itemIdx) {
        case 0: /* votemanager_remove_vote_V7 - class */;
            return _toStringOptionu16(
                &m->basic.votemanager_remove_vote_V7.class,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* votemanager_remove_vote_V7 - index */;
            return _toStringu32(
                &m->basic.votemanager_remove_vote_V7.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 27906: /* module 109 call 2 */
        switch (itemIdx) {
        case 0: /* votemanager_remove_other_vote_V7 - target */;
            return _toStringAccountIdLookupOfT(
                &m->basic.votemanager_remove_other_vote_V7.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* votemanager_remove_other_vote_V7 - class */;
            return _toStringu16(
                &m->basic.votemanager_remove_other_vote_V7.class,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* votemanager_remove_other_vote_V7 - index */;
            return _toStringu32(
                &m->basic.votemanager_remove_other_vote_V7.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 27907: /* module 109 call 3 */
        switch (itemIdx) {
        case 0: /* votemanager_unlock_V7 - class */;
            return _toStringu16(
                &m->basic.votemanager_unlock_V7.class,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* votemanager_unlock_V7 - target */;
            return _toStringAccountIdLookupOfT(
                &m->basic.votemanager_unlock_V7.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* votemanager_unlock_V7 - index */;
            return _toStringu32(
                &m->basic.votemanager_unlock_V7.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 64512: /* module 252 call 0 */
        switch (itemIdx) {
        case 0: /* validatormanager_register_validators_V7 - validators */;
            return _toStringVecAccountId(
                &m->basic.validatormanager_register_validators_V7.validators,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 64513: /* module 252 call 1 */
        switch (itemIdx) {
        case 0: /* validatormanager_deregister_validators_V7 - validators */;
            return _toStringVecAccountId(
                &m->basic.validatormanager_deregister_validators_V7.validators,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 65280: /* module 255 call 0 */
        switch (itemIdx) {
        case 0: /* extrinsicpause_pause_extrinsic_V7 - call */;
            return _toStringCall(
                &m->basic.extrinsicpause_pause_extrinsic_V7.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* extrinsicpause_pause_extrinsic_V7 - pause_only_extrinsic */;
            return _toStringbool(
                &m->basic.extrinsicpause_pause_extrinsic_V7.pause_only_extrinsic,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 65281: /* module 255 call 1 */
        switch (itemIdx) {
        case 0: /* extrinsicpause_resume_extrinsic_V7 - call */;
            return _toStringCall(
                &m->basic.extrinsicpause_resume_extrinsic_V7.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* extrinsicpause_resume_extrinsic_V7 - resume_only_extrinsic */;
            return _toStringbool(
                &m->basic.extrinsicpause_resume_extrinsic_V7.resume_only_extrinsic,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
   case 4864: /* module 19 call 0 */
        switch (itemIdx) {
        case 0: /* stakeexchange_create_offer_V7 - offer */;
            return _toStringOfferOfT(
                            &m->basic.stakeexchange_create_offer_V7.offer,
                            outValue, outValueLen,
                            pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4865: /* module 19 call 1 */
        switch (itemIdx) {
        case 0: /* stakeexchange_cancel_offer_V7 - offer_id */;
            return _toStringOfferId(
                            &m->basic.stakeexchange_cancel_offer_V7.offer_id,
                            outValue, outValueLen,
                            pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4866: /* module 19 call 2 */
        switch (itemIdx) {
        case 0: /* stakeexchange_configure_liquidity_account_V7 - config */;
            return _toStringLiquidityAccountConfigOfT(
                            &m->basic.stakeexchange_configure_liquidity_account_V7.config,
                            outValue, outValueLen,
                            pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4867: /* module 19 call 3 */
        switch (itemIdx) {
        case 0: /* stakeexchange_withdraw_liquidity_V7 - offer_id */;
            return _toStringOfferId(
                            &m->basic.stakeexchange_withdraw_liquidity_V7.offer_id,
                            outValue, outValueLen,
                            pageIdx, pageCount);
        case 1: /* stakeexchange_withdraw_liquidity_V7 - amount */;
            return _toStringBalanceOf(
                            &m->basic.stakeexchange_withdraw_liquidity_V7.amount,
                            outValue, outValueLen,
                            pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4868: /* module 19 call 4 */
        switch (itemIdx) {
        case 0: /* stakeexchange_add_liquidity_V7 - offer_id */;
            return _toStringOfferId(
                            &m->basic.stakeexchange_add_liquidity_V7.offer_id,
                            outValue, outValueLen,
                            pageIdx, pageCount);
        case 1: /* stakeexchange_add_liquidity_V7 - amount */;
            return _toStringBalanceOf(
                            &m->basic.stakeexchange_add_liquidity_V7.amount,
                            outValue, outValueLen,
                            pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4869: /* module 19 call 5 */
        switch (itemIdx) {
        case 0: /* stakeexchange_buy_V7 - offer_id */;
            return _toStringOfferId(
                            &m->basic.stakeexchange_buy_V7.offer_id,
                            outValue, outValueLen,
                            pageIdx, pageCount);
        case 1: /* stakeexchange_buy_V7 - amount */;
            return _toStringBalanceOf(
                            &m->basic.stakeexchange_buy_V7.amount,
                            outValue, outValueLen,
                            pageIdx, pageCount);
        case 2: /* stakeexchange_buy_V7 - token_id */;
            return _toStringTokenIdOf(
                            &m->basic.stakeexchange_buy_V7.token_id,
                            outValue, outValueLen,
                            pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 64768: /* module 253 call 0 */
        switch (itemIdx) {
        case 0: /* multitokens_create_collection_V7 - descriptor */;
            return _toStringCollectionDescriptor(
                    &m->basic.multitokens_create_collection_V7.descriptor,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 64769: /* module 253 call 1 */
        switch (itemIdx) {
        case 0: /* multitokens_destroy_collection_V7 - collection_id */;
            return _toStringCompactCollectionId(
                    &m->basic.multitokens_destroy_collection_V7.collection_id,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 64770: /* module 253 call 2 */
        switch (itemIdx) {
        case 0: /* multitokens_mutate_collection_V7 - collection_id */;
            return _toStringCompactCollectionId(
                    &m->basic.multitokens_mutate_collection_V7.collection_id,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        case 1: /* multitokens_mutate_collection_V7 - mutation */;
            return _toStringCollectionMutation(
                    &m->basic.multitokens_mutate_collection_V7.mutation,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 64773: /* module 253 call 5 */
        switch (itemIdx) {
        case 0: /* multitokens_burn_V7 - collection_id */;
            return _toStringCompactCollectionId(
                    &m->basic.multitokens_burn_V7.collection_id,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        case 1: /* multitokens_burn_V7 - params */;
            return _toStringBurnParamsOfT(
                    &m->basic.multitokens_burn_V7.params,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 64774: /* module 253 call 6 */
        switch (itemIdx) {
        case 0: /* multitokens_transfer_V7 - recipient */;
            return _toStringAccountIdLookupOfT(
                    &m->basic.multitokens_transfer_V7.recipient,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        case 1: /* multitokens_transfer_V7 - collection_id */;
            return _toStringCompactCollectionId(
                    &m->basic.multitokens_transfer_V7.collection_id,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        case 2: /* multitokens_transfer_V7 - params */;
            return _toStringTransferParamsOfT(
                    &m->basic.multitokens_transfer_V7.params,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 64775: /* module 253 call 7 */
        switch (itemIdx) {
        case 0: /* multitokens_freeze_V7 - info */;
            return _toStringFreezeOf(
                    &m->basic.multitokens_freeze_V7.info,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 64776: /* module 253 call 8 */
        switch (itemIdx) {
        case 0: /* multitokens_thaw_V7 - info */;
            return _toStringFreezeOf(
                    &m->basic.multitokens_thaw_V7.info,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 64777: /* module 253 call 9 */
        switch (itemIdx) {
        case 0: /* multitokens_set_attribute_V7 - collection_id */;
            return _toStringCompactCollectionId(
                    &m->basic.multitokens_set_attribute_V7.collection_id,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        case 1: /* multitokens_set_attribute_V7 - token_id */;
            return _toStringOptionTokenId(
                    &m->basic.multitokens_set_attribute_V7.token_id,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        case 2: /* multitokens_set_attribute_V7 - key */;
            return _toStringBytes(
                    &m->basic.multitokens_set_attribute_V7.key,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        case 3: /* multitokens_set_attribute_V7 - value */;
            return _toStringBytes(
                    &m->basic.multitokens_set_attribute_V7.value,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 64778: /* module 253 call 10 */
        switch (itemIdx) {
        case 0: /* multitokens_remove_attribute_V7 - collection_id */;
            return _toStringCompactCollectionId(
                    &m->basic.multitokens_remove_attribute_V7.collection_id,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        case 1: /* multitokens_remove_attribute_V7 - token_id */;
            return _toStringOptionTokenId(
                    &m->basic.multitokens_remove_attribute_V7.token_id,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        case 2: /* multitokens_remove_attribute_V7 - key */;
            return _toStringBytes(
                    &m->basic.multitokens_remove_attribute_V7.key,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 64779: /* module 253 call 11 */
        switch (itemIdx) {
        case 0: /* multitokens_remove_all_attributes_V7 - collection_id */;
            return _toStringCompactCollectionId(
                    &m->basic.multitokens_remove_all_attributes_V7.collection_id,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        case 1: /* multitokens_remove_all_attributes_V7 - token_id */;
            return _toStringOptionTokenId(
                    &m->basic.multitokens_remove_all_attributes_V7.token_id,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        case 2: /* multitokens_remove_all_attributes_V7 - attribute_count */;
            return _toStringu32(
                    &m->basic.multitokens_remove_all_attributes_V7.attribute_count,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 64780: /* module 253 call 12 */
        switch (itemIdx) {
        case 0: /* multitokens_batch_transfer_V7 - collection_id */;
            return _toStringCompactCollectionId(
                    &m->basic.multitokens_batch_transfer_V7.collection_id,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        case 1: /* multitokens_batch_transfer_V7 - recipients */;
            return _toStringVecTransferRecipientsOf(
                    &m->basic.multitokens_batch_transfer_V7.recipients,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 64782: /* module 253 call 14 */
        switch (itemIdx) {
        case 0: /* multitokens_batch_set_attribute_V7 - collection_id */;
            return _toStringCompactCollectionId(
                    &m->basic.multitokens_batch_set_attribute_V7.collection_id,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        case 1: /* multitokens_batch_set_attribute_V7 - token_id */;
            return _toStringOptionTokenId(
                    &m->basic.multitokens_batch_set_attribute_V7.token_id,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        case 2: /* multitokens_batch_set_attribute_V7 - attributes */;
            return _toStringVecAttributeKeyValuePair(
                    &m->basic.multitokens_batch_set_attribute_V7.attributes,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 64783: /* module 253 call 15 */
        switch (itemIdx) {
        case 0: /* multitokens_approve_collection_V7 - collection_id */;
            return _toStringCompactCollectionId(
                    &m->basic.multitokens_approve_collection_V7.collection_id,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        case 1: /* multitokens_approve_collection_V7 - operator */;
            return _toStringAccountId(
                    &m->basic.multitokens_approve_collection_V7.operator_,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        case 2: /* multitokens_approve_collection_V7 - expiration */;
            return _toStringOptionu32(
                    &m->basic.multitokens_approve_collection_V7.expiration,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 64784: /* module 253 call 16 */
        switch (itemIdx) {
        case 0: /* multitokens_unapprove_collection_V7 - collection_id */;
            return _toStringCompactCollectionId(
                    &m->basic.multitokens_unapprove_collection_V7.collection_id,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        case 1: /* multitokens_unapprove_collection_V7 - operator */;
            return _toStringAccountId(
                    &m->basic.multitokens_unapprove_collection_V7.operator_,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 64785: /* module 253 call 17 */
        switch (itemIdx) {
        case 0: /* multitokens_approve_token_V7 - collection_id */;
            return _toStringCompactCollectionId(
                    &m->basic.multitokens_approve_token_V7.collection_id,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        case 1: /* multitokens_approve_token_V7 - token_id */;
            return _toStringCompactTokenId(
                    &m->basic.multitokens_approve_token_V7.token_id,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        case 2: /* multitokens_approve_token_V7 - operator */;
            return _toStringAccountId(
                    &m->basic.multitokens_approve_token_V7.operator_,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        case 3: /* multitokens_approve_token_V7 - amount */;
            return _toStringCompactBalance(
                    &m->basic.multitokens_approve_token_V7.amount,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        case 4: /* multitokens_approve_token_V7 - expiration */;
            return _toStringOptionu32(
                    &m->basic.multitokens_approve_token_V7.expiration,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        case 5: /* multitokens_approve_token_V7 - current_amount */;
            return _toStringCompactBalance(
                    &m->basic.multitokens_approve_token_V7.current_amount,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 64786: /* module 253 call 18 */
        switch (itemIdx) {
        case 0: /* multitokens_unapprove_token_V7 - collection_id */;
            return _toStringCompactCollectionId(
                    &m->basic.multitokens_unapprove_token_V7.collection_id,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        case 1: /* multitokens_unapprove_token_V7 - token_id */;
            return _toStringCompactTokenId(
                    &m->basic.multitokens_unapprove_token_V7.token_id,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        case 2: /* multitokens_unapprove_token_V7 - operator */;
            return _toStringAccountId(
                    &m->basic.multitokens_unapprove_token_V7.operator_,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 64800: /* module 253 call 32 */
        switch (itemIdx) {
        case 0: /* multitokens_claim_collections_V7 - destination */;
            return _toStringAccountId(
                    &m->basic.multitokens_claim_collections_V7.destination,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        case 1: /* multitokens_claim_collections_V7 - ethereum_signature */;
            return _toStringEcdsaSignature(
                    &m->basic.multitokens_claim_collections_V7.ethereum_signature,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        case 2: /* multitokens_claim_collections_V7 - ethereum_address */;
            return _toStringEthereumAddress(
                    &m->basic.multitokens_claim_collections_V7.ethereum_address,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 64801: /* module 253 call 33 */
        switch (itemIdx) {
        case 0: /* multitokens_claim_tokens_V7 - destination */;
            return _toStringAccountId(
                    &m->basic.multitokens_claim_tokens_V7.destination,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        case 1: /* multitokens_claim_tokens_V7 - ethereum_signature */;
            return _toStringEcdsaSignature(
                    &m->basic.multitokens_claim_tokens_V7.ethereum_signature,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        case 2: /* multitokens_claim_tokens_V7 - ethereum_address */;
            return _toStringEthereumAddress(
                    &m->basic.multitokens_claim_tokens_V7.ethereum_address,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 27136: /* module 106 call 0 */
        switch (itemIdx) {
        case 0: /* fellowshipcollective_add_member_V7 - who */;
            return _toStringAccountIdLookupOfT(
                    &m->basic.fellowshipcollective_add_member_V7.who,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 27137: /* module 106 call 1 */
        switch (itemIdx) {
        case 0: /* fellowshipcollective_promote_member_V7 - who */;
            return _toStringAccountIdLookupOfT(
                    &m->basic.fellowshipcollective_promote_member_V7.who,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 27138: /* module 106 call 2 */
        switch (itemIdx) {
        case 0: /* fellowshipcollective_demote_member_V7 - who */;
            return _toStringAccountIdLookupOfT(
                    &m->basic.fellowshipcollective_demote_member_V7.who,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 27139: /* module 106 call 3 */
        switch (itemIdx) {
        case 0: /* fellowshipcollective_remove_member_V7 - who */;
            return _toStringAccountIdLookupOfT(
                    &m->basic.fellowshipcollective_remove_member_V7.who,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        case 1: /* fellowshipcollective_remove_member_V7 - min_rank */;
            return _toStringu16(
                    &m->basic.fellowshipcollective_remove_member_V7.min_rank,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 27140: /* module 106 call 4 */
        switch (itemIdx) {
        case 0: /* fellowshipcollective_vote_V7 - poll */;
            return _toStringu32(
                    &m->basic.fellowshipcollective_vote_V7.poll,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        case 1: /* fellowshipcollective_vote_V7 - aye */;
            return _toStringbool(
                    &m->basic.fellowshipcollective_vote_V7.aye,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 27141: /* module 106 call 5 */
        switch (itemIdx) {
        case 0: /* fellowshipcollective_cleanup_poll_V7 - poll_index */;
            return _toStringu32(
                    &m->basic.fellowshipcollective_cleanup_poll_V7.poll_index,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        case 1: /* fellowshipcollective_cleanup_poll_V7 - max */;
            return _toStringu32(
                    &m->basic.fellowshipcollective_cleanup_poll_V7.max,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 27392: /* module 107 call 0 */
        switch (itemIdx) {
        case 0: /* fellowshipreferenda_submit_V7 - proposal_origin */;
            return _toStringBoxPalletsProposalOrigin(
                    &m->basic.fellowshipreferenda_submit_V7.proposal_origin,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        case 1: /* fellowshipreferenda_submit_V7 - proposal */;
            return _toStringBoundedCallOfT(
                    &m->basic.fellowshipreferenda_submit_V7.proposal,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        case 2: /* fellowshipreferenda_submit_V7 - enactment_moment */;
            return _toStringDispatchTimeBlockNumber(
                    &m->basic.fellowshipreferenda_submit_V7.enactment_moment,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 27393: /* module 107 call 1 */
        switch (itemIdx) {
        case 0: /* fellowshipreferenda_place_decision_deposit_V7 - index */;
            return _toStringu32(
                    &m->basic.fellowshipreferenda_place_decision_deposit_V7.index,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 27394: /* module 107 call 2 */
        switch (itemIdx) {
        case 0: /* fellowshipreferenda_refund_decision_deposit_V7 - index */;
            return _toStringu32(
                    &m->basic.fellowshipreferenda_refund_decision_deposit_V7.index,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 27395: /* module 107 call 3 */
        switch (itemIdx) {
        case 0: /* fellowshipreferenda_cancel_V7 - index */;
            return _toStringu32(
                    &m->basic.fellowshipreferenda_cancel_V7.index,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 27396: /* module 107 call 4 */
        switch (itemIdx) {
        case 0: /* fellowshipreferenda_kill_V7 - index */;
            return _toStringu32(
                    &m->basic.fellowshipreferenda_kill_V7.index,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 27397: /* module 107 call 5 */
        switch (itemIdx) {
        case 0: /* fellowshipreferenda_nudge_referendum_V7 - index */;
            return _toStringu32(
                    &m->basic.fellowshipreferenda_nudge_referendum_V7.index,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 27398: /* module 107 call 6 */
        switch (itemIdx) {
        case 0: /* fellowshipreferenda_one_fewer_deciding_V7 - track */;
            return _toStringu16(
                    &m->basic.fellowshipreferenda_one_fewer_deciding_V7.track,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 27399: /* module 107 call 7 */
        switch (itemIdx) {
        case 0: /* fellowshipreferenda_refund_submission_deposit_V7 - index */;
            return _toStringu32(
                    &m->basic.fellowshipreferenda_refund_submission_deposit_V7.index,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 27400: /* module 107 call 8 */
        switch (itemIdx) {
        case 0: /* fellowshipreferenda_set_metadata_V7 - index */;
            return _toStringu32(
                    &m->basic.fellowshipreferenda_set_metadata_V7.index,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        case 1: /* fellowshipreferenda_set_metadata_V7 - maybe_hash */;
            return _toStringOptionHash(
                    &m->basic.fellowshipreferenda_set_metadata_V7.maybe_hash,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 63744: /* module 249 call 0 */
        switch (itemIdx) {
        case 0: /* marketplace_create_listing_V7 - make_asset_id */;
            return _toStringTokenAssetId(
                    &m->basic.marketplace_create_listing_V7.make_asset_id,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        case 1: /* marketplace_create_listing_V7 - take_asset_id */;
            return _toStringTokenAssetId(
                    &m->basic.marketplace_create_listing_V7.take_asset_id,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        case 2: /* marketplace_create_listing_V7 - amount */;
            return _toStringCompactu128(
                    &m->basic.marketplace_create_listing_V7.amount,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        case 3: /* marketplace_create_listing_V7 - price */;
            return _toStringCompactu128(
                    &m->basic.marketplace_create_listing_V7.price,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        case 4: /* marketplace_create_listing_V7 - salt */;
            return _toStringBytes(
                    &m->basic.marketplace_create_listing_V7.salt,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        case 5: /* marketplace_create_listing_V7 - auction_data */;
            return _toStringOptionAuctionDataOfT(
                    &m->basic.marketplace_create_listing_V7.auction_data,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 63745: /* module 249 call 1 */
        switch (itemIdx) {
        case 0: /* marketplace_cancel_listing_V7 - listing_id */;
            return _toStringListingId(
                    &m->basic.marketplace_cancel_listing_V7.listing_id,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 63746: /* module 249 call 2 */
        switch (itemIdx) {
        case 0: /* marketplace_fill_listing_V7 - listing_id */;
            return _toStringListingId(
                    &m->basic.marketplace_fill_listing_V7.listing_id,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        case 1: /* marketplace_fill_listing_V7 - amount */;
            return _toStringCompactu128(
                    &m->basic.marketplace_fill_listing_V7.amount,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 63747: /* module 249 call 3 */
        switch (itemIdx) {
        case 0: /* marketplace_place_bid_V7 - listing_id */;
            return _toStringListingId(
                    &m->basic.marketplace_place_bid_V7.listing_id,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        case 1: /* marketplace_place_bid_V7 - price */;
            return _toStringCompactu128(
                    &m->basic.marketplace_place_bid_V7.price,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 63748: /* module 249 call 4 */
        switch (itemIdx) {
        case 0: /* marketplace_finalize_auction_V7 - listing_id */;
            return _toStringListingId(
                    &m->basic.marketplace_finalize_auction_V7.listing_id,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 63749: /* module 249 call 5 */
        switch (itemIdx) {
        case 0: /* marketplace_set_protocol_fee_V7 - protocol_fee */;
            return _toStringPerbill(
                    &m->basic.marketplace_set_protocol_fee_V7.protocol_fee,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 63750: /* module 249 call 6 */
        switch (itemIdx) {
        case 0: /* marketplace_force_create_listing_V7 - seller */;
            return _toStringAccountIdLookupOfT(
                    &m->basic.marketplace_force_create_listing_V7.seller,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        case 1: /* marketplace_force_create_listing_V7 - make_asset_id */;
            return _toStringTokenAssetId(
                    &m->basic.marketplace_force_create_listing_V7.make_asset_id,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        case 2: /* marketplace_force_create_listing_V7 - take_asset_id */;
            return _toStringTokenAssetId(
                    &m->basic.marketplace_force_create_listing_V7.take_asset_id,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        case 3: /* marketplace_force_create_listing_V7 - amount */;
            return _toStringCompactu128(
                    &m->basic.marketplace_force_create_listing_V7.amount,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        case 4: /* marketplace_force_create_listing_V7 - price */;
            return _toStringCompactu128(
                    &m->basic.marketplace_force_create_listing_V7.price,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        case 5: /* marketplace_force_create_listing_V7 - salt */;
            return _toStringBytes(
                    &m->basic.marketplace_force_create_listing_V7.salt,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        case 6: /* marketplace_force_create_listing_V7 - auction_data */;
            return _toStringOptionAuctionDataOfT(
                    &m->basic.marketplace_force_create_listing_V7.auction_data,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        case 7: /* marketplace_force_create_listing_V7 - deposit_backer */;
            return _toStringOptionAccountIdLookupOfT(
                    &m->basic.marketplace_force_create_listing_V7.deposit_backer,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 63751: /* module 249 call 7 */
        switch (itemIdx) {
        case 0: /* marketplace_force_place_bid_V7 - bidder */;
            return _toStringAccountIdLookupOfT(
                    &m->basic.marketplace_force_place_bid_V7.bidder,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        case 1: /* marketplace_force_place_bid_V7 - listing_id */;
            return _toStringListingId(
                    &m->basic.marketplace_force_place_bid_V7.listing_id,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        case 2: /* marketplace_force_place_bid_V7 - price */;
            return _toStringCompactu128(
                    &m->basic.marketplace_force_place_bid_V7.price,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        case 3: /* marketplace_force_place_bid_V7 - funds_backer */;
            return _toStringOptionAccountIdLookupOfT(
                    &m->basic.marketplace_force_place_bid_V7.funds_backer,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        default:
            return parser_no_data;
        }
     case 13824: /* module 54 call 0 */
        switch (itemIdx) {
        case 0: /* fueltanks_create_fuel_tank_V7 - descriptor */;
            return _toStringCollectionDescriptor(
                    &m->basic.fueltanks_create_fuel_tank_V7.descriptor,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13825: /* module 54 call 1 */
        switch (itemIdx) {
        case 0: /* fueltanks_mutate_fuel_tank_V7 - tank_id */;
            return _toStringAccountIdLookupOfT(
                    &m->basic.fueltanks_mutate_fuel_tank_V7.tank_id,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        case 1: /* fueltanks_mutate_fuel_tank_V7 - mutation */;
            return _toStringCollectionDescriptor(
                    &m->basic.fueltanks_mutate_fuel_tank_V7.mutation,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13826: /* module 54 call 2 */
        switch (itemIdx) {
        case 0: /* fueltanks_add_account_V7 - tank_id */;
            return _toStringAccountIdLookupOfT(
                    &m->basic.fueltanks_add_account_V7.tank_id,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        case 1: /* fueltanks_add_account_V7 - user_id */;
            return _toStringAccountIdLookupOfT(
                    &m->basic.fueltanks_add_account_V7.user_id,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13827: /* module 54 call 3 */
        switch (itemIdx) {
        case 0: /* fueltanks_remove_account_V7 - tank_id */;
            return _toStringAccountIdLookupOfT(
                    &m->basic.fueltanks_remove_account_V7.tank_id,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        case 1: /* fueltanks_remove_account_V7 - user_id */;
            return _toStringAccountIdLookupOfT(
                    &m->basic.fueltanks_remove_account_V7.user_id,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13828: /* module 54 call 4 */
        switch (itemIdx) {
        case 0: /* fueltanks_remove_account_rule_data_V7 - tank_id */;
            return _toStringAccountIdLookupOfT(
                    &m->basic.fueltanks_remove_account_rule_data_V7.tank_id,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        case 1: /* fueltanks_remove_account_rule_data_V7 - user_id */;
            return _toStringAccountIdLookupOfT(
                    &m->basic.fueltanks_remove_account_rule_data_V7.user_id,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        case 2: /* fueltanks_remove_account_rule_data_V7 - rule_set_id */;
            return _toStringu32(
                    &m->basic.fueltanks_remove_account_rule_data_V7.rule_set_id,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        case 3: /* fueltanks_remove_account_rule_data_V7 - rule_kind */;
            return _toStringCollectionDescriptor(
                    &m->basic.fueltanks_remove_account_rule_data_V7.rule_kind,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13829: /* module 54 call 5 */
        switch (itemIdx) {
        case 0: /* fueltanks_dispatch_V7 - tank_id */;
            return _toStringAccountIdLookupOfT(
                    &m->basic.fueltanks_dispatch_V7.tank_id,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        case 1: /* fueltanks_dispatch_V7 - rule_set_id */;
            return _toStringu32(
                    &m->basic.fueltanks_dispatch_V7.rule_set_id,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        case 2: /* fueltanks_dispatch_V7 - call */;
            return _toStringCall(
                    &m->basic.fueltanks_dispatch_V7.call,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        case 3: /* fueltanks_dispatch_V7 - settings */;
            return _toStringCollectionDescriptor(
                    &m->basic.fueltanks_dispatch_V7.settings,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13830: /* module 54 call 6 */
        switch (itemIdx) {
        case 0: /* fueltanks_dispatch_and_touch_V7 - tank_id */;
            return _toStringAccountIdLookupOfT(
                    &m->basic.fueltanks_dispatch_and_touch_V7.tank_id,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        case 1: /* fueltanks_dispatch_and_touch_V7 - rule_set_id */;
            return _toStringu32(
                    &m->basic.fueltanks_dispatch_and_touch_V7.rule_set_id,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        case 2: /* fueltanks_dispatch_and_touch_V7 - call */;
            return _toStringCall(
                    &m->basic.fueltanks_dispatch_and_touch_V7.call,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        case 3: /* fueltanks_dispatch_and_touch_V7 - settings */;
            return _toStringCollectionDescriptor(
                    &m->basic.fueltanks_dispatch_and_touch_V7.settings,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13831: /* module 54 call 7 */
        switch (itemIdx) {
        case 0: /* fueltanks_schedule_mutate_freeze_state_V7 - tank_id */;
            return _toStringCollectionDescriptor(
                    &m->basic.fueltanks_schedule_mutate_freeze_state_V7.tank_id,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        case 1: /* fueltanks_schedule_mutate_freeze_state_V7 - rule_set_id */;
            return _toStringCollectionDescriptor(
                    &m->basic.fueltanks_schedule_mutate_freeze_state_V7.rule_set_id,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        case 2: /* fueltanks_schedule_mutate_freeze_state_V7 - is_frozen */;
            return _toStringCollectionDescriptor(
                    &m->basic.fueltanks_schedule_mutate_freeze_state_V7.is_frozen,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13832: /* module 54 call 8 */
        switch (itemIdx) {
        case 0: /* fueltanks_insert_rule_set_V7 - tank_id */;
            return _toStringAccountIdLookupOfT(
                    &m->basic.fueltanks_insert_rule_set_V7.tank_id,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        case 1: /* fueltanks_insert_rule_set_V7 - rule_set_id */;
            return _toStringu32(
                    &m->basic.fueltanks_insert_rule_set_V7.rule_set_id,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        case 2: /* fueltanks_insert_rule_set_V7 - rules */;
            return _toStringCollectionDescriptor(
                    &m->basic.fueltanks_insert_rule_set_V7.rules,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13833: /* module 54 call 9 */
        switch (itemIdx) {
        case 0: /* fueltanks_remove_rule_set_V7 - tank_id */;
            return _toStringAccountIdLookupOfT(
                    &m->basic.fueltanks_remove_rule_set_V7.tank_id,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        case 1: /* fueltanks_remove_rule_set_V7 - rule_set_id */;
            return _toStringu32(
                    &m->basic.fueltanks_remove_rule_set_V7.rule_set_id,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13834: /* module 54 call 10 */
        switch (itemIdx) {
        case 0: /* fueltanks_batch_add_account_V7 - tank_id */;
            return _toStringAccountIdLookupOfT(
                    &m->basic.fueltanks_batch_add_account_V7.tank_id,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        case 1: /* fueltanks_batch_add_account_V7 - user_ids */;
            return _toStringVecAccountIdLookupOfT(
                    &m->basic.fueltanks_batch_add_account_V7.user_ids,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13835: /* module 54 call 11 */
        switch (itemIdx) {
        case 0: /* fueltanks_batch_remove_account_V7 - tank_id */;
            return _toStringAccountIdLookupOfT(
                    &m->basic.fueltanks_batch_remove_account_V7.tank_id,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        case 1: /* fueltanks_batch_remove_account_V7 - user_ids */;
            return _toStringVecAccountIdLookupOfT(
                    &m->basic.fueltanks_batch_remove_account_V7.user_ids,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13836: /* module 54 call 12 */
        switch (itemIdx) {
        case 0: /* fueltanks_force_set_consumption_V7 - tank_id */;
            return _toStringAccountIdLookupOfT(
                    &m->basic.fueltanks_force_set_consumption_V7.tank_id,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        case 1: /* fueltanks_force_set_consumption_V7 - user_id */;
            return _toStringOptionAccountIdLookupOfT(
                    &m->basic.fueltanks_force_set_consumption_V7.user_id,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        case 2: /* fueltanks_force_set_consumption_V7 - rule_set_id */;
            return _toStringu32(
                    &m->basic.fueltanks_force_set_consumption_V7.rule_set_id,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        case 3: /* fueltanks_force_set_consumption_V7 - consumption */;
            return _toStringCollectionDescriptor(
                    &m->basic.fueltanks_force_set_consumption_V7.consumption,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13837: /* module 54 call 13 */
        switch (itemIdx) {
        case 0: /* fueltanks_destroy_fuel_tank_V7 - tank_id */;
            return _toStringAccountIdLookupOfT(
                    &m->basic.fueltanks_destroy_fuel_tank_V7.tank_id,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13838: /* module 54 call 14 */
        switch (itemIdx) {
        case 0: /* fueltanks_force_create_fuel_tank_V7 - owner */;
            return _toStringAccountIdLookupOfT(
                    &m->basic.fueltanks_force_create_fuel_tank_V7.owner,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        case 1: /* fueltanks_force_create_fuel_tank_V7 - descriptor */;
            return _toStringCollectionDescriptor(
                    &m->basic.fueltanks_force_create_fuel_tank_V7.descriptor,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13839: /* module 54 call 15 */
        switch (itemIdx) {
        case 0: /* fueltanks_force_batch_add_account_V7 - owner */;
            return _toStringAccountIdLookupOfT(
                    &m->basic.fueltanks_force_batch_add_account_V7.owner,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        case 1: /* fueltanks_force_batch_add_account_V7 - tank_id */;
            return _toStringAccountIdLookupOfT(
                    &m->basic.fueltanks_force_batch_add_account_V7.tank_id,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        case 2: /* fueltanks_force_batch_add_account_V7 - user_ids */;
            return _toStringVecAccountIdLookupOfT(
                    &m->basic.fueltanks_force_batch_add_account_V7.user_ids,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4608: /* module 18 call 0 */
        switch (itemIdx) {
        case 0: /* nominationpools_ -  */;
            return _toStringPoolId(
                    &m->basic.nominationpools_.,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        default:
            return parser_no_data;
        }
        switch (itemIdx) {
        case 0:
            return STR_IT_pool_id;
        case 1:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 4611: /* module 18 call 3 */
        switch (itemIdx) {
        case 0: /* nominationpools_ -  */;
            return _toStringPoolId(
                    &m->basic.nominationpools_.,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        default:
            return parser_no_data;
        }
        switch (itemIdx) {
        case 0:
            return STR_IT_pool_id;
        case 1:
            return STR_IT_member_account;
        case 2:
            return STR_IT_unbonding_points;
        default:
            return NULL;
        }
    case 4612: /* module 18 call 4 */
        switch (itemIdx) {
        case 0: /* nominationpools_ -  */;
            return _toStringPoolId(
                    &m->basic.nominationpools_.,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        default:
            return parser_no_data;
        }
        switch (itemIdx) {
        case 0:
            return STR_IT_pool_id;
        case 1:
            return STR_IT_num_slashing_spans;
        default:
            return NULL;
        }
    case 4613: /* module 18 call 5 */
        switch (itemIdx) {
        case 0: /* nominationpools_ -  */;
            return _toStringPoolId(
                    &m->basic.nominationpools_.,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        default:
            return parser_no_data;
        }
        switch (itemIdx) {
        case 0:
            return STR_IT_pool_id;
        case 1:
            return STR_IT_member_account;
        case 2:
            return STR_IT_num_slashing_spans;
        default:
            return NULL;
        }
    case 4614: /* module 18 call 6 */
        switch (itemIdx) {
        case 0: /* nominationpools_ -  */;
            return _toStringPoolId(
                    &m->basic.nominationpools_.,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        default:
            return parser_no_data;
        }
        switch (itemIdx) {
        case 0:
            return STR_IT_pool_id;
        case 1:
            return STR_IT_deposit;
        case 2:
            return STR_IT_capacity;
        case 3:
            return STR_IT_duration;
        case 4:
            return STR_IT_name;
        default:
            return NULL;
        }
    case 4616: /* module 18 call 8 */
        switch (itemIdx) {
        case 0: /* nominationpools_ -  */;
            return _toStringPoolId(
                    &m->basic.nominationpools_.,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        default:
            return parser_no_data;
        }
        switch (itemIdx) {
        case 0:
            return STR_IT_pool_id;
        case 1:
            return STR_IT_validators;
        default:
            return NULL;
        }
    case 4619: /* module 18 call 11 */
        switch (itemIdx) {
        case 0: /* nominationpools_ -  */;
            return _toStringPoolId(
                    &m->basic.nominationpools_.,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        default:
            return parser_no_data;
        }
        switch (itemIdx) {
        case 0:
            return STR_IT_min_join_bond;
        case 1:
            return STR_IT_min_create_bond;
        case 2:
            return STR_IT_global_max_commission;
        case 3:
            return STR_IT_required_payout_count;
        default:
            return NULL;
        }
    case 4621: /* module 18 call 13 */
        switch (itemIdx) {
        case 0: /* nominationpools_ -  */;
            return _toStringPoolId(
                    &m->basic.nominationpools_.,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        default:
            return parser_no_data;
        }
        switch (itemIdx) {
        case 0:
            return STR_IT_pool_id;
        default:
            return NULL;
        }
    case 4622: /* module 18 call 14 */
        switch (itemIdx) {
        case 0: /* nominationpools_ -  */;
            return _toStringPoolId(
                    &m->basic.nominationpools_.,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        default:
            return parser_no_data;
        }
        switch (itemIdx) {
        case 0:
            return STR_IT_pool_id;
        default:
            return NULL;
        }
    case 4626: /* module 18 call 18 */
        switch (itemIdx) {
        case 0: /* nominationpools_ -  */;
            return _toStringPoolId(
                    &m->basic.nominationpools_.,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        default:
            return parser_no_data;
        }
        switch (itemIdx) {
        case 0:
            return STR_IT_validator_stash;
        case 1:
            return STR_IT_era;
        default:
            return NULL;
        }
    case 4627: /* module 18 call 19 */
        switch (itemIdx) {
        case 0: /* nominationpools_ -  */;
            return _toStringPoolId(
                    &m->basic.nominationpools_.,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        default:
            return parser_no_data;
        }
        switch (itemIdx) {
        case 0:
            return STR_IT_pool_id;
        case 1:
            return STR_IT_mutation;
        default:
            return NULL;
        }
        return STR_ME_MUTATE;
    case 4628: /* module 18 call 20 */
        switch (itemIdx) {
        case 0: /* nominationpools_ -  */;
            return _toStringPoolId(
                    &m->basic.nominationpools_.,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        default:
            return parser_no_data;
        }
        switch (itemIdx) {
        case 0:
            return STR_IT_pool_id;
        default:
            return NULL;
        }
    case 4629: /* module 18 call 21 */
        switch (itemIdx) {
        case 0: /* nominationpools_ -  */;
            return _toStringPoolId(
                    &m->basic.nominationpools_.,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        default:
            return parser_no_data;
        }
        switch (itemIdx) {
        case 0:
            return STR_IT_pool_id;
        default:
            return NULL;
        }
    case 4630: /* module 18 call 22 */
        switch (itemIdx) {
        case 0: /* nominationpools_ -  */;
            return _toStringPoolId(
                    &m->basic.nominationpools_.,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        default:
            return parser_no_data;
        }
        switch (itemIdx) {
        case 0:
            return STR_IT_info;
        default:
            return NULL;
        }
    case 4631: /* module 18 call 23 */
        switch (itemIdx) {
        case 0: /* nominationpools_ -  */;
            return _toStringPoolId(
                    &m->basic.nominationpools_.,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        default:
            return parser_no_data;
        }
        switch (itemIdx) {
        case 0:
            return STR_IT_pool_count;
        default:
            return NULL;
        }
    case 4632: /* module 18 call 24 */
        switch (itemIdx) {
        case 0: /* nominationpools_ -  */;
            return _toStringPoolId(
                    &m->basic.nominationpools_.,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        default:
            return parser_no_data;
        }
        switch (itemIdx) {
        case 0:
            return STR_IT_pool_id;
        case 1:
            return STR_IT_payment_id;
        case 2:
            return STR_IT_account_count;
        default:
            return NULL;
        }
    case 4633: /* module 18 call 25 */
        switch (itemIdx) {
        case 0: /* nominationpools_ -  */;
            return _toStringPoolId(
                    &m->basic.nominationpools_.,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        default:
            return parser_no_data;
        }
        switch (itemIdx) {
        case 0:
            return STR_IT_pool_count;
        default:
            return NULL;
        }
    case 4634: /* module 18 call 26 */
        switch (itemIdx) {
        case 0: /* nominationpools_ -  */;
            return _toStringPoolId(
                    &m->basic.nominationpools_.,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        default:
            return parser_no_data;
        }
        switch (itemIdx) {
        case 0:
            return STR_IT_pool_id;
        case 1:
            return STR_IT_destination;
        case 2:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 4635: /* module 18 call 27 */
        switch (itemIdx) {
        case 0: /* nominationpools_ -  */;
            return _toStringPoolId(
                    &m->basic.nominationpools_.,
                    outValue, outValueLen,
                    pageIdx, pageCount);
        default:
            return parser_no_data;
        }
        switch (itemIdx) {
        case 0:
            return STR_IT_pool_id;
        case 1:
            return STR_IT_account_count;
        default:
            return NULL;
        }
    case 4636: /* module 18 call 28 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
#endif
    default:
        return parser_ok;
    }

    return parser_ok;
}

bool _getMethod_ItemIsExpert_V7(uint8_t moduleIdx, uint8_t callIdx, __Z_UNUSED uint8_t itemIdx)
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
    case 1812: // Staking:Reap stash
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

bool _getMethod_IsNestingSupported_V7(uint8_t moduleIdx, uint8_t callIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 2560: // Preimage:Note preimage
    case 2561: // Preimage:Unnote preimage
    case 2562: // Preimage:Request preimage
    case 2563: // Preimage:Unrequest preimage
    case 2564: // Preimage:Ensure updated
    case 768: // Timestamp:Set
    case 1285: // Balances:Force unreserve
    case 1286: // Balances:Upgrade accounts
    case 1288: // Balances:Force set balance
    case 1801: // Staking:Set validator count
    case 1802: // Staking:Increase validator count
    case 1803: // Staking:Scale validator count
    case 1804: // Staking:Force no eras
    case 1805: // Staking:Force new era
    case 1806: // Staking:Set invulnerables
    case 1807: // Staking:Force unstake
    case 1808: // Staking:Force new era always
    case 1809: // Staking:Cancel deferred slash
    case 1812: // Staking:Reap stash
    case 1813: // Staking:Kick
    case 1814: // Staking:Set staking configs
    case 1815: // Staking:Chill other
    case 1816: // Staking:Force apply min commission
    case 1817: // Staking:Set min commission
    case 4864: // Treasury:Propose spend
    case 4865: // Treasury:Reject proposal
    case 4866: // Treasury:Approve proposal
    case 4867: // Treasury:Spend local
    case 4868: // Treasury:Remove approval
    case 4870: // Treasury:Payout
    case 4871: // Treasury:Check status
    case 4872: // Treasury:Void spend
    case 5376: // Referenda:Submit
    case 5377: // Referenda:Place decision deposit
    case 5378: // Referenda:Refund decision deposit
    case 5379: // Referenda:Cancel
    case 5380: // Referenda:Kill
    case 5381: // Referenda:Nudge referendum
    case 5382: // Referenda:One fewer deciding
    case 5383: // Referenda:Refund submission deposit
    case 5384: // Referenda:Set metadata
    case 5888: // Whitelist:Whitelist call
    case 5889: // Whitelist:Remove whitelisted call
    case 5890: // Whitelist:Dispatch whitelisted call
    case 5891: // Whitelist:Dispatch whitelisted call with preimage
    case 6656: // Utility:Batch
    case 6658: // Utility:Batch all
    case 6659: // Utility:Dispatch as
    case 6660: // Utility:Force batch
    case 6661: // Utility:With weight
    case 7168: // Identity:Add registrar
    case 7169: // Identity:Set identity
    case 7170: // Identity:Set subs
    case 7171: // Identity:Clear identity
    case 7172: // Identity:Request judgement
    case 7173: // Identity:Cancel request
    case 7174: // Identity:Set fee
    case 7175: // Identity:Set account id
    case 7177: // Identity:Provide judgement
    case 7178: // Identity:Kill identity
    case 7179: // Identity:Add sub
    case 7180: // Identity:Rename sub
    case 7181: // Identity:Remove sub
    case 7182: // Identity:Quit sub
    case 7427: // Proxy:Remove proxies
    case 7433: // Proxy:Proxy announced
    case 9472: // VoterList:Rebag
    case 9473: // VoterList:Put in front of
    case 9474: // VoterList:Put in front of other
    case 13056: // Configuration:Set validation upgrade cooldown
    case 13057: // Configuration:Set validation upgrade delay
    case 13058: // Configuration:Set code retention period
    case 13059: // Configuration:Set max code size
    case 13060: // Configuration:Set max pov size
    case 13061: // Configuration:Set max head data size
    case 13062: // Configuration:Set on demand cores
    case 13063: // Configuration:Set on demand retries
    case 13064: // Configuration:Set group rotation frequency
    case 13065: // Configuration:Set paras availability period
    case 13067: // Configuration:Set scheduling lookahead
    case 13068: // Configuration:Set max validators per core
    case 13069: // Configuration:Set max validators
    case 13071: // Configuration:Set dispute post conclusion acceptance period
    case 13074: // Configuration:Set no show slots
    case 13075: // Configuration:Set n delay tranches
    case 13076: // Configuration:Set zeroth delay tranche width
    case 13077: // Configuration:Set needed approvals
    case 13078: // Configuration:Set relay vrf modulo samples
    case 13079: // Configuration:Set max upward queue count
    case 13080: // Configuration:Set max upward queue size
    case 13081: // Configuration:Set max downward message size
    case 13083: // Configuration:Set max upward message size
    case 13084: // Configuration:Set max upward message num per candidate
    case 13085: // Configuration:Set hrmp open request ttl
    case 13086: // Configuration:Set hrmp sender deposit
    case 13087: // Configuration:Set hrmp recipient deposit
    case 13088: // Configuration:Set hrmp channel max capacity
    case 13089: // Configuration:Set hrmp channel max total size
    case 13090: // Configuration:Set hrmp max parachain inbound channels
    case 13092: // Configuration:Set hrmp channel max message size
    case 13093: // Configuration:Set hrmp max parachain outbound channels
    case 13095: // Configuration:Set hrmp max message num per candidate
    case 13098: // Configuration:Set pvf voting ttl
    case 13099: // Configuration:Set minimum validation upgrade delay
    case 13100: // Configuration:Set bypass consistency check
    case 13103: // Configuration:Set on demand base fee
    case 13104: // Configuration:Set on demand fee variability
    case 13105: // Configuration:Set on demand queue max size
    case 13106: // Configuration:Set on demand target queue utilization
    case 13107: // Configuration:Set on demand ttl
    case 13108: // Configuration:Set minimum backing votes
    case 14592: // Initializer:Force approve
    case 15872: // ParasDisputes:Force unfreeze
    case 18432: // Auctions:New auction
    case 18433: // Auctions:Bid
    case 18434: // Auctions:Cancel auction
    case 18688: // Crowdloan:Create
    case 18689: // Crowdloan:Contribute
    case 18690: // Crowdloan:Withdraw
    case 18691: // Crowdloan:Refund
    case 18692: // Crowdloan:Dissolve
    case 18693: // Crowdloan:Edit
    case 18694: // Crowdloan:Add memo
    case 18695: // Crowdloan:Poke
    case 18696: // Crowdloan:Contribute all
    case 25345: // XcmPallet:Teleport assets
    case 25346: // XcmPallet:Reserve transfer assets
    case 25352: // XcmPallet:Limited reserve transfer assets
    case 25353: // XcmPallet:Limited teleport assets
        return false;
    default:
        return true;
    }
}
