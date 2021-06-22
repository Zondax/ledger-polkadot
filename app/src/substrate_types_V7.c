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
#include "bignum.h"
#include "coin.h"
#include "parser_impl.h"
#include "substrate_dispatch_V7.h"
#include "substrate_strings.h"

#include <stddef.h>
#include <stdint.h>
#include <zxmacros.h>

parser_error_t _readCompactBountyIndex_V7(parser_context_t* c, pd_CompactBountyIndex_V7_t* v)
{
    return _readCompactInt(c, v);
}

parser_error_t _readCompactEraIndex_V7(parser_context_t* c, pd_CompactEraIndex_V7_t* v)
{
    return _readCompactInt(c, v);
}

parser_error_t _readCompactMemberCount_V7(parser_context_t* c, pd_CompactMemberCount_V7_t* v)
{
    return _readCompactInt(c, v);
}

parser_error_t _readCompactMoment_V7(parser_context_t* c, pd_CompactMoment_V7_t* v)
{
    return _readCompactInt(c, v);
}

parser_error_t _readCompactPropIndex_V7(parser_context_t* c, pd_CompactPropIndex_V7_t* v)
{
    return _readCompactInt(c, v);
}

parser_error_t _readCompactProposalIndex_V7(parser_context_t* c, pd_CompactProposalIndex_V7_t* v)
{
    return _readCompactInt(c, v);
}

parser_error_t _readCompactReferendumIndex_V7(parser_context_t* c, pd_CompactReferendumIndex_V7_t* v)
{
    return _readCompactInt(c, v);
}

parser_error_t _readCompactRegistrarIndex_V7(parser_context_t* c, pd_CompactRegistrarIndex_V7_t* v)
{
    return _readCompactInt(c, v);
}

parser_error_t _readCompactWeight_V7(parser_context_t* c, pd_CompactWeight_V7_t* v)
{
    return _readCompactInt(c, v);
}

parser_error_t _readAccountId_V7(parser_context_t* c, pd_AccountId_V7_t* v) {
    GEN_DEF_READARRAY(32)
}

parser_error_t _readAccountIndex_V7(parser_context_t* c, pd_AccountIndex_V7_t* v)
{
    return _readUInt32(c, &v->value);
}

parser_error_t _readAccountVoteSplit_V7(parser_context_t* c, pd_AccountVoteSplit_V7_t* v)
{
    CHECK_ERROR(_readBalanceOf(c, &v->aye));
    CHECK_ERROR(_readBalanceOf(c, &v->nay));
    return parser_ok;
}

parser_error_t _readAccountVoteStandard_V7(parser_context_t* c, pd_AccountVoteStandard_V7_t* v)
{
    CHECK_ERROR(_readVote_V7(c, &v->vote));
    CHECK_ERROR(_readBalanceOf(c, &v->balance));
    return parser_ok;
}

parser_error_t _readAccountVote_V7(parser_context_t* c, pd_AccountVote_V7_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readUInt8(c, &v->value))

    switch (v->value) {
    case 0:
        CHECK_ERROR(_readAccountVoteStandard_V7(c, &v->voteStandard))
        break;
    case 1:
        CHECK_ERROR(_readAccountVoteSplit_V7(c, &v->voteSplit))
        break;
    default:
        break;
    }

    return parser_ok;
}

parser_error_t _readBabeEquivocationProof_V7(parser_context_t* c, pd_BabeEquivocationProof_V7_t* v)
{
    return parser_not_supported;
}

parser_error_t _readCallHashOf_V7(parser_context_t* c, pd_CallHashOf_V7_t* v) {
    GEN_DEF_READARRAY(32)
}

parser_error_t _readChangesTrieConfiguration_V7(parser_context_t* c, pd_ChangesTrieConfiguration_V7_t* v)
{
    CHECK_ERROR(_readu32(c, &v->digest_interval))
    CHECK_ERROR(_readu32(c, &v->digest_levels))
    return parser_ok;
}

parser_error_t _readCompactAccountIndex_V7(parser_context_t* c, pd_CompactAccountIndex_V7_t* v)
{
    return _readCompactInt(c, &v->value);
}

parser_error_t _readCompactPerBill_V7(parser_context_t* c, pd_CompactPerBill_V7_t* v)
{
    return _readCompactInt(c, &v->value);
}

parser_error_t _readConviction_V7(parser_context_t* c, pd_Conviction_V7_t* v)
{
    CHECK_INPUT()

    CHECK_ERROR(_readUInt8(c, &v->value))
    if (v->value > 5) {
        return parser_value_out_of_range;
    }

    return parser_ok;
}

parser_error_t _readEcdsaSignature_V7(parser_context_t* c, pd_EcdsaSignature_V7_t* v) {
    GEN_DEF_READARRAY(65)
}

parser_error_t _readElectionScore_V7(parser_context_t* c, pd_ElectionScore_V7_t* v)
{
    return parser_not_supported;
}

parser_error_t _readEraIndex_V7(parser_context_t* c, pd_EraIndex_V7_t* v)
{
    return _readUInt32(c, &v->value);
}

parser_error_t _readEthereumAddress_V7(parser_context_t* c, pd_EthereumAddress_V7_t* v) {
    GEN_DEF_READARRAY(20)
}

parser_error_t _readGrandpaEquivocationProof_V7(parser_context_t* c, pd_GrandpaEquivocationProof_V7_t* v)
{
    return parser_not_supported;
}

parser_error_t _readIdentityFields_V7(parser_context_t* c, pd_IdentityFields_V7_t* v)
{
    return parser_not_supported;
}

parser_error_t _readIdentityInfo_V7(parser_context_t* c, pd_IdentityInfo_V7_t* v)
{
    CHECK_ERROR(_readVecTupleDataData(c, &v->additional));
    CHECK_ERROR(_readData(c, &v->display));
    CHECK_ERROR(_readData(c, &v->legal));
    CHECK_ERROR(_readData(c, &v->web));
    CHECK_ERROR(_readData(c, &v->riot));
    CHECK_ERROR(_readData(c, &v->email));
    CHECK_ERROR(_readOptionu8_array_20(c, &v->pgp_fingerprint));
    CHECK_ERROR(_readData(c, &v->image));
    CHECK_ERROR(_readData(c, &v->twitter));
    return parser_ok;
}

parser_error_t _readIdentityJudgement_V7(parser_context_t* c, pd_IdentityJudgement_V7_t* v)
{
    return parser_not_supported;
}

parser_error_t _readKeyOwnerProof_V7(parser_context_t* c, pd_KeyOwnerProof_V7_t* v)
{
    return parser_not_supported;
}

parser_error_t _readKeyValue_V7(parser_context_t* c, pd_KeyValue_V7_t* v) {
    GEN_DEF_READARRAY(32)
}

parser_error_t _readKey_V7(parser_context_t* c, pd_Key_V7_t* v) {
    GEN_DEF_READARRAY(32)
}

parser_error_t _readKeys_V7(parser_context_t* c, pd_Keys_V7_t* v) {
    GEN_DEF_READARRAY(6 * 32)
}

parser_error_t _readLookupSource_V7(parser_context_t* c, pd_LookupSource_V7_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // Id
        CHECK_ERROR(_readAccountId_V7(c, &v->id))
        break;
    case 1: // Index
        CHECK_ERROR(_readCompactAccountIndex_V7(c, &v->index))
        break;
    case 2: // Raw
        CHECK_ERROR(_readBytes(c, &v->raw))
        break;
    case 3: // Address32
        GEN_DEF_READARRAY(32)
    case 4: // Address20
        GEN_DEF_READARRAY(20)
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _readMemberCount_V7(parser_context_t* c, pd_MemberCount_V7_t* v)
{
    return _readUInt32(c, &v->value);
}

parser_error_t _readNextConfigDescriptor_V7(parser_context_t* c, pd_NextConfigDescriptor_V7_t* v)
{
    return parser_not_supported;
}

parser_error_t _readOpaqueCall_V7(parser_context_t* c, pd_OpaqueCall_V7_t* v)
{
    // Encoded as Byte[], array size comes first
    uint8_t size;
    CHECK_ERROR(_readUInt8(c, &size))
    return _readCall(c, &v->call);
}

parser_error_t _readPerbill_V7(parser_context_t* c, pd_Perbill_V7_t* v)
{
    return _readUInt32(c, &v->value);
}

parser_error_t _readPercent_V7(parser_context_t* c, pd_Percent_V7_t* v)
{
    return _readCompactInt(c, &v->value);
}

parser_error_t _readPeriod_V7(parser_context_t* c, pd_Period_V7_t* v)
{
    return _readUInt64(c, &v->value);
}

parser_error_t _readPriority_V7(parser_context_t* c, pd_Priority_V7_t* v)
{
    CHECK_ERROR(_readu32(c, &v->stream_id))
    CHECK_ERROR(_readStreamDependency_V7(c, &v->dependency))
    return parser_ok;
}

parser_error_t _readProxyType_V7(parser_context_t* c, pd_ProxyType_V7_t* v)
{
    CHECK_INPUT()

    CHECK_ERROR(_readUInt8(c, &v->value))
    if (v->value > 3) {
        return parser_value_out_of_range;
    }

    return parser_ok;
}

parser_error_t _readRawSolution_V7(parser_context_t* c, pd_RawSolution_V7_t* v)
{
    return parser_not_supported;
}

parser_error_t _readReadySolution_V7(parser_context_t* c, pd_ReadySolution_V7_t* v)
{
    return parser_not_supported;
}

parser_error_t _readReferendumIndex_V7(parser_context_t* c, pd_ReferendumIndex_V7_t* v)
{
    return _readUInt32(c, &v->value);
}

parser_error_t _readRegistrarIndex_V7(parser_context_t* c, pd_RegistrarIndex_V7_t* v)
{
    return _readUInt32(c, &v->value);
}

parser_error_t _readRenouncing_V7(parser_context_t* c, pd_Renouncing_V7_t* v)
{
    return parser_not_supported;
}

parser_error_t _readRewardDestination_V7(parser_context_t* c, pd_RewardDestination_V7_t* v)
{
    CHECK_INPUT();

    CHECK_ERROR(_readUInt8(c, &v->value))
    if (v->value > 2) {
        return parser_value_out_of_range;
    }

    return parser_ok;
}

parser_error_t _readSignature_V7(parser_context_t* c, pd_Signature_V7_t* v) {
    GEN_DEF_READARRAY(64)
}

parser_error_t _readSolutionOrSnapshotSize_V7(parser_context_t* c, pd_SolutionOrSnapshotSize_V7_t* v)
{
    return parser_not_supported;
}

parser_error_t _readStatementKind_V7(parser_context_t* c, pd_StatementKind_V7_t* v)
{
    return parser_not_supported;
}

parser_error_t _readStreamDependency_V7(parser_context_t* c, pd_StreamDependency_V7_t* v)
{
    CHECK_ERROR(_readu32(c, &v->dependency_id))
    CHECK_ERROR(_readUInt8(c, &v->weight))
    CHECK_ERROR(_readbool(c, &v->is_exclusive))
    return parser_ok;
}

parser_error_t _readTimepoint_V7(parser_context_t* c, pd_Timepoint_V7_t* v)
{
    CHECK_ERROR(_readBlockNumber(c, &v->height))
    CHECK_ERROR(_readu32(c, &v->index))
    return parser_ok;
}

parser_error_t _readTupleAccountIdData_V7(parser_context_t* c, pd_TupleAccountIdData_V7_t* v)
{
    return parser_not_supported;
}

parser_error_t _readTupleBalanceOfBalanceOfBlockNumber_V7(parser_context_t* c, pd_TupleBalanceOfBalanceOfBlockNumber_V7_t* v)
{
    CHECK_ERROR(_readBalanceOf(c, &v->balance1))
    CHECK_ERROR(_readBalanceOf(c, &v->balance2))
    CHECK_ERROR(_readBlockNumber(c, &v->blockNumber))
    return parser_ok;
}

parser_error_t _readValidatorPrefs_V7(parser_context_t* c, pd_ValidatorPrefs_V7_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readCompactPerBill_V7(c, &v->commission));
    CHECK_ERROR(_readbool(c, &v->blocked))
    return parser_ok;
}

parser_error_t _readVestingInfo_V7(parser_context_t* c, pd_VestingInfo_V7_t* v)
{
    CHECK_ERROR(_readBalanceOf(c, &v->locked))
    CHECK_ERROR(_readBalanceOf(c, &v->per_block))
    CHECK_ERROR(_readBlockNumber(c, &v->starting_block))
    return parser_ok;
}

parser_error_t _readVote_V7(parser_context_t* c, pd_Vote_V7_t* v)
{
    CHECK_INPUT();
    uint8_t b;
    CHECK_ERROR(_readUInt8(c, &b))

    v->aye = (b & 0x80u) >> 7u;
    v->conviction.value = b & 0x7Fu;

    if (v->conviction.value > 5) {
        return parser_value_out_of_range;
    }

    return parser_ok;
}

parser_error_t _readWeight_V7(parser_context_t* c, pd_Weight_V7_t* v)
{
    return _readUInt64(c, &v->value);
}

parser_error_t _readu8_array_32_V7(parser_context_t* c, pd_u8_array_32_V7_t* v) {
    GEN_DEF_READARRAY(32)
}

parser_error_t _readVecAccountId_V7(parser_context_t* c, pd_VecAccountId_V7_t* v) {
    GEN_DEF_READVECTOR(AccountId_V7)
}

parser_error_t _readVecKeyValue_V7(parser_context_t* c, pd_VecKeyValue_V7_t* v) {
    GEN_DEF_READVECTOR(KeyValue_V7)
}

parser_error_t _readVecKey_V7(parser_context_t* c, pd_VecKey_V7_t* v) {
    GEN_DEF_READVECTOR(Key_V7)
}

parser_error_t _readVecLookupSource_V7(parser_context_t* c, pd_VecLookupSource_V7_t* v) {
    GEN_DEF_READVECTOR(LookupSource_V7)
}

parser_error_t _readVecTupleAccountIdData_V7(parser_context_t* c, pd_VecTupleAccountIdData_V7_t* v) {
    GEN_DEF_READVECTOR(TupleAccountIdData_V7)
}

parser_error_t _readOptionAccountId_V7(parser_context_t* c, pd_OptionAccountId_V7_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readAccountId_V7(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionChangesTrieConfiguration_V7(parser_context_t* c, pd_OptionChangesTrieConfiguration_V7_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readChangesTrieConfiguration_V7(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionElectionScore_V7(parser_context_t* c, pd_OptionElectionScore_V7_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readElectionScore_V7(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionPeriod_V7(parser_context_t* c, pd_OptionPeriod_V7_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readPeriod_V7(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionProxyType_V7(parser_context_t* c, pd_OptionProxyType_V7_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readProxyType_V7(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionReferendumIndex_V7(parser_context_t* c, pd_OptionReferendumIndex_V7_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readReferendumIndex_V7(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionStatementKind_V7(parser_context_t* c, pd_OptionStatementKind_V7_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readStatementKind_V7(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionTimepoint_V7(parser_context_t* c, pd_OptionTimepoint_V7_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readTimepoint_V7(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionTupleBalanceOfBalanceOfBlockNumber_V7(parser_context_t* c, pd_OptionTupleBalanceOfBalanceOfBlockNumber_V7_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readTupleBalanceOfBalanceOfBlockNumber_V7(c, &v->contained))
    }
    return parser_ok;
}

///////////////////////////////////
///////////////////////////////////
///////////////////////////////////

parser_error_t _toStringCompactBountyIndex_V7(
    const pd_CompactBountyIndex_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringCompactInt(v, 0, 0, "", outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringCompactEraIndex_V7(
    const pd_CompactEraIndex_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringCompactInt(v, 0, 0, "", outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringCompactMemberCount_V7(
    const pd_CompactMemberCount_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringCompactInt(v, 0, 0, "", outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringCompactMoment_V7(
    const pd_CompactMoment_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringCompactInt(v, 0, 0, "", outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringCompactPropIndex_V7(
    const pd_CompactPropIndex_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringCompactInt(v, 0, 0, "", outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringCompactProposalIndex_V7(
    const pd_CompactProposalIndex_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringCompactInt(v, 0, 0, "", outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringCompactReferendumIndex_V7(
    const pd_CompactReferendumIndex_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringCompactInt(v, 0, 0, "", outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringCompactRegistrarIndex_V7(
    const pd_CompactRegistrarIndex_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringCompactInt(v, 0, 0, "", outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringCompactWeight_V7(
    const pd_CompactWeight_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringCompactInt(v, 0, 0, "", outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringAccountId_V7(
    const pd_AccountId_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringPubkeyAsAddress(v->_ptr, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringAccountIndex_V7(
    const pd_AccountIndex_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringAccountVoteSplit_V7(
    const pd_AccountVoteSplit_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    // First measure number of pages
    uint8_t pages[3];

    pages[0] = 1;
    CHECK_ERROR(_toStringBalanceOf(&v->aye, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringBalanceOf(&v->nay, outValue, outValueLen, 0, &pages[2]));

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx < pages[0]) {
        snprintf(outValue, outValueLen, "Split");
        return parser_ok;
    }
    pageIdx -= pages[0];

    /////////
    /////////

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringBalanceOf(&v->aye, outValue, outValueLen, pageIdx, &pages[1]));
        return parser_ok;
    }
    pageIdx -= pages[1];

    /////////
    /////////

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringBalanceOf(&v->nay, outValue, outValueLen, pageIdx, &pages[2]));
        return parser_ok;
    }
    pageIdx -= pages[2];

    /////////
    /////////

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringAccountVoteStandard_V7(
    const pd_AccountVoteStandard_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    // First measure number of pages
    uint8_t pages[3];

    pages[0] = 1;
    CHECK_ERROR(_toStringVote_V7(&v->vote, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringBalanceOf(&v->balance, outValue, outValueLen, 0, &pages[2]));

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        snprintf(outValue, outValueLen, "Standard");
        return parser_ok;
    }
    pageIdx -= pages[0];

    /////////
    /////////

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringVote_V7(&v->vote, outValue, outValueLen, pageIdx, &pages[1]));
        return parser_ok;
    }
    pageIdx -= pages[1];

    /////////
    /////////

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringBalanceOf(&v->balance, outValue, outValueLen, pageIdx, &pages[2]));
        return parser_ok;
    }
    pageIdx -= pages[2];

    /////////
    /////////

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringAccountVote_V7(
    const pd_AccountVote_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    switch (v->value) {
    case 0:
        _toStringAccountVoteStandard_V7(&v->voteStandard, outValue, outValueLen, pageIdx, pageCount);
        break;
    case 1:
        _toStringAccountVoteSplit_V7(&v->voteSplit, outValue, outValueLen, pageIdx, pageCount);
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _toStringBabeEquivocationProof_V7(
    const pd_BabeEquivocationProof_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringCallHashOf_V7(
    const pd_CallHashOf_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount) {
    GEN_DEF_TOSTRING_ARRAY(32)
}

parser_error_t _toStringChangesTrieConfiguration_V7(
    const pd_ChangesTrieConfiguration_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    // Get all pages first
    uint8_t pages[2];
    CHECK_ERROR(_toStringu32(&v->digest_interval, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringu32(&v->digest_levels, outValue, outValueLen, 0, &pages[1]))

    *pageCount = pages[0] + pages[1];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringu32(&v->digest_interval, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringu32(&v->digest_levels, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringCompactAccountIndex_V7(
    const pd_CompactAccountIndex_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringCompactInt(&v->value, 0, 0, "", outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringCompactPerBill_V7(
    const pd_CompactPerBill_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    // 9 but shift 2 to show as percentage
    return _toStringCompactInt(&v->value, 7, '%', "", outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringConviction_V7(
    const pd_Conviction_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    switch (v->value) {
    case 0:
        snprintf(outValue, outValueLen, "None");
        break;
    case 1:
        snprintf(outValue, outValueLen, "Locked1x");
        break;
    case 2:
        snprintf(outValue, outValueLen, "Locked2x");
        break;
    case 3:
        snprintf(outValue, outValueLen, "Locked3x");
        break;
    case 4:
        snprintf(outValue, outValueLen, "Locked4x");
        break;
    case 5:
        snprintf(outValue, outValueLen, "Locked5x");
        break;
    default:
        return parser_print_not_supported;
    }

    return parser_ok;
}

parser_error_t _toStringEcdsaSignature_V7(
    const pd_EcdsaSignature_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount) {
    GEN_DEF_TOSTRING_ARRAY(65)
}

parser_error_t _toStringElectionScore_V7(
    const pd_ElectionScore_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringEraIndex_V7(
    const pd_EraIndex_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringEthereumAddress_V7(
    const pd_EthereumAddress_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount) {
    GEN_DEF_TOSTRING_ARRAY(20)
}

parser_error_t _toStringGrandpaEquivocationProof_V7(
    const pd_GrandpaEquivocationProof_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringIdentityFields_V7(
    const pd_IdentityFields_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringIdentityInfo_V7(
    const pd_IdentityInfo_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[9];
    CHECK_ERROR(_toStringVecTupleDataData(&v->additional, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringData(&v->display, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringData(&v->legal, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringData(&v->web, outValue, outValueLen, 0, &pages[3]))
    CHECK_ERROR(_toStringData(&v->riot, outValue, outValueLen, 0, &pages[4]))
    CHECK_ERROR(_toStringData(&v->email, outValue, outValueLen, 0, &pages[5]))
    CHECK_ERROR(_toStringOptionu8_array_20(&v->pgp_fingerprint, outValue, outValueLen, 0, &pages[6]))
    CHECK_ERROR(_toStringData(&v->image, outValue, outValueLen, 0, &pages[7]))
    CHECK_ERROR(_toStringData(&v->twitter, outValue, outValueLen, 0, &pages[8]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringVecTupleDataData(&v->additional, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    /////////
    /////////

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringData(&v->display, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    /////////
    /////////

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringData(&v->legal, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }
    pageIdx -= pages[2];

    /////////
    /////////

    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringData(&v->web, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }
    pageIdx -= pages[3];

    /////////
    /////////

    if (pageIdx < pages[4]) {
        CHECK_ERROR(_toStringData(&v->riot, outValue, outValueLen, pageIdx, &pages[4]))
        return parser_ok;
    }
    pageIdx -= pages[4];

    /////////
    /////////

    if (pageIdx < pages[5]) {
        CHECK_ERROR(_toStringData(&v->email, outValue, outValueLen, pageIdx, &pages[5]))
        return parser_ok;
    }
    pageIdx -= pages[5];

    /////////
    /////////

    if (pageIdx < pages[6]) {
        CHECK_ERROR(_toStringOptionu8_array_20(&v->pgp_fingerprint, outValue, outValueLen, pageIdx, &pages[6]))
        return parser_ok;
    }
    pageIdx -= pages[6];

    /////////
    /////////

    if (pageIdx < pages[7]) {
        CHECK_ERROR(_toStringData(&v->image, outValue, outValueLen, pageIdx, &pages[7]))
        return parser_ok;
    }
    pageIdx -= pages[7];

    /////////
    /////////

    if (pageIdx < pages[8]) {
        CHECK_ERROR(_toStringData(&v->twitter, outValue, outValueLen, pageIdx, &pages[8]))
        return parser_ok;
    }
    pageIdx -= pages[8];

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringIdentityJudgement_V7(
    const pd_IdentityJudgement_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringKeyOwnerProof_V7(
    const pd_KeyOwnerProof_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringKeyValue_V7(
    const pd_KeyValue_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    return parser_print_not_supported;
}

parser_error_t _toStringKey_V7(
    const pd_Key_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    return parser_print_not_supported;
}

parser_error_t _toStringKeys_V7(
    const pd_Keys_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount) {
    GEN_DEF_TOSTRING_ARRAY(4 * 32)
}

parser_error_t _toStringLookupSource_V7(
    const pd_LookupSource_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    switch (v->value) {
    case 0: // Id
        CHECK_ERROR(_toStringAccountId_V7(&v->id, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 1: // Index
        CHECK_ERROR(_toStringCompactAccountIndex_V7(&v->index, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 2: // Raw
        CHECK_ERROR(_toStringBytes(&v->raw, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 3: // Address32
    {
        GEN_DEF_TOSTRING_ARRAY(32)
    }
    case 4: // Address20
    {
        GEN_DEF_TOSTRING_ARRAY(20)
    }
    default:
        return parser_not_supported;
    }

    return parser_ok;
}

parser_error_t _toStringMemberCount_V7(
    const pd_MemberCount_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringNextConfigDescriptor_V7(
    const pd_NextConfigDescriptor_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringOpaqueCall_V7(
    const pd_OpaqueCall_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringCall(&v->call, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringPerbill_V7(
    const pd_Perbill_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    char bufferUI[100];
    char ratioBuffer[80];
    MEMSET(outValue, 0, outValueLen);
    MEMSET(ratioBuffer, 0, sizeof(ratioBuffer));
    MEMSET(bufferUI, 0, sizeof(bufferUI));
    *pageCount = 1;

    if (fpuint64_to_str(ratioBuffer, sizeof(ratioBuffer), v->value, 7) == 0) {
        return parser_unexpected_value;
    }

    snprintf(bufferUI, sizeof(bufferUI), "%s%%", ratioBuffer);
    pageString(outValue, outValueLen, bufferUI, pageIdx, pageCount);
    return parser_ok;
}

parser_error_t _toStringPercent_V7(
    const pd_Percent_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    // 9 but shift 2 to show as percentage
    return _toStringCompactInt(&v->value, 7, '%', "", outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringPeriod_V7(
    const pd_Period_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu64(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringPriority_V7(
    const pd_Priority_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    // Get all pages first
    uint8_t pages[2];
    CHECK_ERROR(_toStringu32(&v->stream_id, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringStreamDependency_V7(&v->dependency, outValue, outValueLen, 0, &pages[1]))

    *pageCount = pages[0] + pages[1];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringu32(&v->stream_id, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringStreamDependency_V7(&v->dependency, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringProxyType_V7(
    const pd_ProxyType_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    switch (v->value) {
    case 0:
        snprintf(outValue, outValueLen, "Any");
        break;
    case 1:
        snprintf(outValue, outValueLen, "NonTransfer");
        break;
    case 2:
        snprintf(outValue, outValueLen, "Governance");
        break;
    case 3:
        snprintf(outValue, outValueLen, "Staking");
        break;
    default:
        return parser_print_not_supported;
    }

    return parser_ok;
}

parser_error_t _toStringRawSolution_V7(
    const pd_RawSolution_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringReadySolution_V7(
    const pd_ReadySolution_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringReferendumIndex_V7(
    const pd_ReferendumIndex_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringRegistrarIndex_V7(
    const pd_RegistrarIndex_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringRenouncing_V7(
    const pd_Renouncing_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringRewardDestination_V7(
    const pd_RewardDestination_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    switch (v->value) {
    case 0:
        snprintf(outValue, outValueLen, "Staked");
        break;
    case 1:
        snprintf(outValue, outValueLen, "Stash");
        break;
    case 2:
        snprintf(outValue, outValueLen, "Controller");
        break;
    default:
        return parser_print_not_supported;
    }

    return parser_ok;
}

parser_error_t _toStringSignature_V7(
    const pd_Signature_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount) {
    GEN_DEF_TOSTRING_ARRAY(64)
}

parser_error_t _toStringSolutionOrSnapshotSize_V7(
    const pd_SolutionOrSnapshotSize_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringStatementKind_V7(
    const pd_StatementKind_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringStreamDependency_V7(
    const pd_StreamDependency_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[3];
    CHECK_ERROR(_toStringu32(&v->dependency_id, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringu16((const pd_u16_t*)&v->weight, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringbool(&v->is_exclusive, outValue, outValueLen, 0, &pages[2]))

    *pageCount = pages[0] + pages[1] + pages[2];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringu32(&v->dependency_id, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringu16((const pd_u16_t*)&v->weight, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    //////
    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringbool(&v->is_exclusive, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringTimepoint_V7(
    const pd_Timepoint_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[2];
    CHECK_ERROR(_toStringBlockNumber(&v->height, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringu32(&v->index, outValue, outValueLen, 0, &pages[1]))

    *pageCount = pages[0] + pages[1];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringBlockNumber(&v->height, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringu32(&v->index, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringTupleAccountIdData_V7(
    const pd_TupleAccountIdData_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringTupleBalanceOfBalanceOfBlockNumber_V7(
    const pd_TupleBalanceOfBalanceOfBlockNumber_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[3];
    CHECK_ERROR(_toStringBalanceOf(&v->balance1, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringBalanceOf(&v->balance2, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringBlockNumber(&v->blockNumber, outValue, outValueLen, 0, &pages[2]))

    *pageCount = pages[0] + pages[1] + pages[2];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringBalanceOf(&v->balance1, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringBalanceOf(&v->balance2, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    //////
    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringBlockNumber(&v->blockNumber, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringValidatorPrefs_V7(
    const pd_ValidatorPrefs_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    uint8_t pages[2];
    CHECK_ERROR(_toStringCompactPerBill_V7(&v->commission, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringbool(&v->blocked, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringCompactPerBill_V7(&v->commission, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringbool(&v->blocked, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringVestingInfo_V7(
    const pd_VestingInfo_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[3];
    CHECK_ERROR(_toStringBalanceOf(&v->locked, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringBalanceOf(&v->per_block, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringBlockNumber(&v->starting_block, outValue, outValueLen, 0, &pages[2]))

    *pageCount = pages[0] + pages[1] + pages[2];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringBalanceOf(&v->locked, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringBalanceOf(&v->per_block, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    //////
    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringBlockNumber(&v->starting_block, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringVote_V7(
    const pd_Vote_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    CHECK_PARSER_ERR(_toStringbool(&v->aye, outValue, outValueLen, pageIdx, pageCount));
    uint16_t offset = strlen(outValue);
    outValue[offset++] = ' ';
    CHECK_PARSER_ERR(_toStringConviction_V7(&v->conviction,
        outValue + offset,
        outValueLen - offset,
        pageIdx,
        pageCount));
    *pageCount = 1;
    return parser_ok;
}

parser_error_t _toStringWeight_V7(
    const pd_Weight_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu64(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringu8_array_32_V7(
    const pd_u8_array_32_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount) {
    GEN_DEF_TOSTRING_ARRAY(32)
}

parser_error_t _toStringVecAccountId_V7(
    const pd_VecAccountId_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(AccountId_V7);
}

parser_error_t _toStringVecKeyValue_V7(
    const pd_VecKeyValue_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(KeyValue_V7);
}

parser_error_t _toStringVecKey_V7(
    const pd_VecKey_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(Key_V7);
}

parser_error_t _toStringVecLookupSource_V7(
    const pd_VecLookupSource_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(LookupSource_V7);
}

parser_error_t _toStringVecTupleAccountIdData_V7(
    const pd_VecTupleAccountIdData_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(TupleAccountIdData_V7);
}

parser_error_t _toStringOptionAccountId_V7(
    const pd_OptionAccountId_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringAccountId_V7(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionChangesTrieConfiguration_V7(
    const pd_OptionChangesTrieConfiguration_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringChangesTrieConfiguration_V7(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionElectionScore_V7(
    const pd_OptionElectionScore_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringElectionScore_V7(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionPeriod_V7(
    const pd_OptionPeriod_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringPeriod_V7(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionProxyType_V7(
    const pd_OptionProxyType_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringProxyType_V7(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionReferendumIndex_V7(
    const pd_OptionReferendumIndex_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringReferendumIndex_V7(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionStatementKind_V7(
    const pd_OptionStatementKind_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringStatementKind_V7(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionTimepoint_V7(
    const pd_OptionTimepoint_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringTimepoint_V7(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionTupleBalanceOfBalanceOfBlockNumber_V7(
    const pd_OptionTupleBalanceOfBalanceOfBlockNumber_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringTupleBalanceOfBalanceOfBlockNumber_V7(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}
