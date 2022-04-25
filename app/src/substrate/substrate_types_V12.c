/*******************************************************************************
 *  (c) 2019 - 2022 Zondax GmbH
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
#include "substrate_dispatch_V12.h"
#include "substrate_strings.h"

#include <stddef.h>
#include <stdint.h>
#include <zxformat.h>
#include <zxmacros.h>

parser_error_t _readAccountId_V12(parser_context_t* c, pd_AccountId_V12_t* v) {
    GEN_DEF_READARRAY(32)
}

parser_error_t _readAccountIndex_V12(parser_context_t* c, pd_AccountIndex_V12_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readAccountVoteSplit_V12(parser_context_t* c, pd_AccountVoteSplit_V12_t* v)
{
    CHECK_ERROR(_readBalanceOf(c, &v->aye));
    CHECK_ERROR(_readBalanceOf(c, &v->nay));
    return parser_ok;
}

parser_error_t _readAccountVoteStandard_V12(parser_context_t* c, pd_AccountVoteStandard_V12_t* v)
{
    CHECK_ERROR(_readVote_V12(c, &v->vote));
    CHECK_ERROR(_readBalanceOf(c, &v->balance));
    return parser_ok;
}

parser_error_t _readAccountVote_V12(parser_context_t* c, pd_AccountVote_V12_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))

    switch (v->value) {
    case 0:
        CHECK_ERROR(_readAccountVoteStandard_V12(c, &v->voteStandard))
        break;
    case 1:
        CHECK_ERROR(_readAccountVoteSplit_V12(c, &v->voteSplit))
        break;
    default:
        break;
    }

    return parser_ok;
}

parser_error_t _readAuthorityIdasRuntimeAppPublicSignature_V12(parser_context_t* c, pd_AuthorityIdasRuntimeAppPublicSignature_V12_t* v)
{
    return parser_not_supported;
}

parser_error_t _readBoxCallOrHashOfT_V12(parser_context_t* c, pd_BoxCallOrHashOfT_V12_t* v)
{
    return parser_not_supported;
}

parser_error_t _readBoxEquivocationProofHashBlockNumber_V12(parser_context_t* c, pd_BoxEquivocationProofHashBlockNumber_V12_t* v)
{
    return parser_not_supported;
}

parser_error_t _readBoxEquivocationProofHeader_V12(parser_context_t* c, pd_BoxEquivocationProofHeader_V12_t* v)
{
    return parser_not_supported;
}

parser_error_t _readBoxIdentityInfoMaxAdditionalFields_V12(parser_context_t* c, pd_BoxIdentityInfoMaxAdditionalFields_V12_t* v)
{
    return parser_not_supported;
}

parser_error_t _readBoxMultiLocation_V12(parser_context_t* c, pd_BoxMultiLocation_V12_t* v)
{
    return parser_not_supported;
}

parser_error_t _readBoxPalletsOrigin_V12(parser_context_t* c, pd_BoxPalletsOrigin_V12_t* v)
{
    return parser_not_supported;
}

parser_error_t _readBoxRawSolutionSolutionOfT_V12(parser_context_t* c, pd_BoxRawSolutionSolutionOfT_V12_t* v)
{
    return parser_not_supported;
}

parser_error_t _readBoxVersionedMultiAssets_V12(parser_context_t* c, pd_BoxVersionedMultiAssets_V12_t* v)
{
    return parser_not_supported;
}

parser_error_t _readBoxVersionedMultiLocation_V12(parser_context_t* c, pd_BoxVersionedMultiLocation_V12_t* v)
{
    return parser_not_supported;
}

parser_error_t _readBoxVersionedXcmTasSysConfigCall_V12(parser_context_t* c, pd_BoxVersionedXcmTasSysConfigCall_V12_t* v)
{
    return parser_not_supported;
}

parser_error_t _readBoxVersionedXcmTuple_V12(parser_context_t* c, pd_BoxVersionedXcmTuple_V12_t* v)
{
    return parser_not_supported;
}

parser_error_t _readCallHashOf_V12(parser_context_t* c, pd_CallHashOf_V12_t* v) {
    GEN_DEF_READARRAY(32)
}

parser_error_t _readCompactAccountIndex_V12(parser_context_t* c, pd_CompactAccountIndex_V12_t* v)
{
    return _readCompactInt(c, &v->value);
}

parser_error_t _readCompactPerBill_V12(parser_context_t* c, pd_CompactPerBill_V12_t* v)
{
    return _readCompactInt(c, &v->value);
}

parser_error_t _readConfigOpBalanceOfT_V12(parser_context_t* c, pd_ConfigOpBalanceOfT_V12_t* v)
{
    return parser_not_supported;
}

parser_error_t _readConfigOpPerbill_V12(parser_context_t* c, pd_ConfigOpPerbill_V12_t* v)
{
    return parser_not_supported;
}

parser_error_t _readConfigOpPercent_V12(parser_context_t* c, pd_ConfigOpPercent_V12_t* v)
{
    return parser_not_supported;
}

parser_error_t _readConfigOpu32_V12(parser_context_t* c, pd_ConfigOpu32_V12_t* v)
{
    return parser_not_supported;
}

parser_error_t _readConviction_V12(parser_context_t* c, pd_Conviction_V12_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    if (v->value > 5) {
        return parser_value_out_of_range;
    }
    return parser_ok;
}

parser_error_t _readEcdsaSignature_V12(parser_context_t* c, pd_EcdsaSignature_V12_t* v) {
    GEN_DEF_READARRAY(65)
}

parser_error_t _readElectionScore_V12(parser_context_t* c, pd_ElectionScore_V12_t* v)
{
    return parser_not_supported;
}

parser_error_t _readEraIndex_V12(parser_context_t* c, pd_EraIndex_V12_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readEthereumAddress_V12(parser_context_t* c, pd_EthereumAddress_V12_t* v) {
    GEN_DEF_READARRAY(20)
}

parser_error_t _readHeadData_V12(parser_context_t* c, pd_HeadData_V12_t* v)
{
    return parser_not_supported;
}

parser_error_t _readHeartbeatBlockNumber_V12(parser_context_t* c, pd_HeartbeatBlockNumber_V12_t* v)
{
    return parser_not_supported;
}

parser_error_t _readHrmpChannelId_V12(parser_context_t* c, pd_HrmpChannelId_V12_t* v)
{
    return parser_not_supported;
}

parser_error_t _readIdentityFields_V12(parser_context_t* c, pd_IdentityFields_V12_t* v)
{
    return parser_not_supported;
}

parser_error_t _readJudgementBalanceOfT_V12(parser_context_t* c, pd_JudgementBalanceOfT_V12_t* v)
{
    return parser_not_supported;
}

parser_error_t _readKeyOwnerProof_V12(parser_context_t* c, pd_KeyOwnerProof_V12_t* v)
{
    return parser_not_supported;
}

parser_error_t _readKeyValue_V12(parser_context_t* c, pd_KeyValue_V12_t* v) {
    GEN_DEF_READARRAY(32)
}

parser_error_t _readKey_V12(parser_context_t* c, pd_Key_V12_t* v) {
    GEN_DEF_READARRAY(32)
}

parser_error_t _readKeys_V12(parser_context_t* c, pd_Keys_V12_t* v) {
    GEN_DEF_READARRAY(6 * 32)
}

parser_error_t _readLeasePeriodOfT_V12(parser_context_t* c, pd_LeasePeriodOfT_V12_t* v)
{
    return parser_not_supported;
}

parser_error_t _readLookupasStaticLookupSource_V12(parser_context_t* c, pd_LookupasStaticLookupSource_V12_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // Id
        CHECK_ERROR(_readAccountId_V12(c, &v->id))
        break;
    case 1: // Index
        CHECK_ERROR(_readCompactAccountIndex_V12(c, &v->index))
        break;
    case 2: // Raw
        CHECK_ERROR(_readBytes(c, &v->raw))
        break;
    case 3: // Address32
        GEN_DEF_READARRAY(32)
        break;
    case 4: // Address20
        GEN_DEF_READARRAY(20)
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _readMemberCount_V12(parser_context_t* c, pd_MemberCount_V12_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readMultiSignature_V12(parser_context_t* c, pd_MultiSignature_V12_t* v)
{
    return parser_not_supported;
}

parser_error_t _readMultiSigner_V12(parser_context_t* c, pd_MultiSigner_V12_t* v)
{
    return parser_not_supported;
}

parser_error_t _readNextConfigDescriptor_V12(parser_context_t* c, pd_NextConfigDescriptor_V12_t* v)
{
    return parser_not_supported;
}

parser_error_t _readOpaqueCall_V12(parser_context_t* c, pd_OpaqueCall_V12_t* v)
{
    // Encoded as Byte[], array size comes first
    uint8_t size;
    CHECK_ERROR(_readUInt8(c, &size))
    return _readCall(c, &v->call);
}

parser_error_t _readOverweightIndex_V12(parser_context_t* c, pd_OverweightIndex_V12_t* v)
{
    return parser_not_supported;
}

parser_error_t _readParaId_V12(parser_context_t* c, pd_ParaId_V12_t* v)
{
    return parser_not_supported;
}

parser_error_t _readParachainsInherentDataHeader_V12(parser_context_t* c, pd_ParachainsInherentDataHeader_V12_t* v)
{
    return parser_not_supported;
}

parser_error_t _readPerbill_V12(parser_context_t* c, pd_Perbill_V12_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readPercent_V12(parser_context_t* c, pd_Percent_V12_t* v)
{
    return _readCompactInt(c, &v->value);
}

parser_error_t _readProxyType_V12(parser_context_t* c, pd_ProxyType_V12_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    if (v->value > 3) {
        return parser_value_out_of_range;
    }
    return parser_ok;
}

parser_error_t _readPvfCheckStatement_V12(parser_context_t* c, pd_PvfCheckStatement_V12_t* v)
{
    return parser_not_supported;
}

parser_error_t _readReferendumIndex_V12(parser_context_t* c, pd_ReferendumIndex_V12_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readRegistrarIndex_V12(parser_context_t* c, pd_RegistrarIndex_V12_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readRenouncing_V12(parser_context_t* c, pd_Renouncing_V12_t* v)
{
    return parser_not_supported;
}

parser_error_t _readRewardDestination_V12(parser_context_t* c, pd_RewardDestination_V12_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    if (v->value > 2) {
        return parser_value_out_of_range;
    }
    return parser_ok;
}

parser_error_t _readSessionIndex_V12(parser_context_t* c, pd_SessionIndex_V12_t* v)
{
    return _readUInt32(c, &v->value);
}

parser_error_t _readSolutionOrSnapshotSize_V12(parser_context_t* c, pd_SolutionOrSnapshotSize_V12_t* v)
{
    return parser_not_supported;
}

parser_error_t _readStatementKind_V12(parser_context_t* c, pd_StatementKind_V12_t* v)
{
    return parser_not_supported;
}

parser_error_t _readSupportsAccountId_V12(parser_context_t* c, pd_SupportsAccountId_V12_t* v)
{
    return parser_not_supported;
}

parser_error_t _readTimepoint_V12(parser_context_t* c, pd_Timepoint_V12_t* v)
{
    CHECK_ERROR(_readBlockNumber(c, &v->height))
    CHECK_ERROR(_readu32(c, &v->index))
    return parser_ok;
}

parser_error_t _readTupleAccountIdData_V12(parser_context_t* c, pd_TupleAccountIdData_V12_t* v)
{
    return parser_not_supported;
}

parser_error_t _readTupleBalanceOfTBalanceOfTBlockNumber_V12(parser_context_t* c, pd_TupleBalanceOfTBalanceOfTBlockNumber_V12_t* v)
{
    return parser_not_supported;
}

parser_error_t _readValidationCodeHash_V12(parser_context_t* c, pd_ValidationCodeHash_V12_t* v)
{
    return parser_not_supported;
}

parser_error_t _readValidationCode_V12(parser_context_t* c, pd_ValidationCode_V12_t* v)
{
    return parser_not_supported;
}

parser_error_t _readValidatorPrefs_V12(parser_context_t* c, pd_ValidatorPrefs_V12_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readCompactPerBill_V12(c, &v->commission));
    CHECK_ERROR(_readbool(c, &v->blocked))
    return parser_ok;
}

parser_error_t _readValidatorSignature_V12(parser_context_t* c, pd_ValidatorSignature_V12_t* v)
{
    return parser_not_supported;
}

parser_error_t _readVestingInfoBalanceOfTBlockNumber_V12(parser_context_t* c, pd_VestingInfoBalanceOfTBlockNumber_V12_t* v)
{
    return parser_not_supported;
}

parser_error_t _readVote_V12(parser_context_t* c, pd_Vote_V12_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))

    if (v->value & 0x7F) {
        return parser_value_out_of_range;
    }
    v->value = (v->value & 0x80u) >> 7u;

    return parser_ok;
}

parser_error_t _readWeightLimit_V12(parser_context_t* c, pd_WeightLimit_V12_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt64(c, &v->value))
    return parser_ok;
}

parser_error_t _readWeight_V12(parser_context_t* c, pd_Weight_V12_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt64(c, &v->value))
    return parser_ok;
}

parser_error_t _readXcmVersion_V12(parser_context_t* c, pd_XcmVersion_V12_t* v)
{
    return parser_not_supported;
}

parser_error_t _readschedulePeriodBlockNumber_V12(parser_context_t* c, pd_schedulePeriodBlockNumber_V12_t* v)
{
    return parser_not_supported;
}

parser_error_t _readschedulePriority_V12(parser_context_t* c, pd_schedulePriority_V12_t* v)
{
    return parser_not_supported;
}

parser_error_t _readVecAccountId_V12(parser_context_t* c, pd_VecAccountId_V12_t* v) {
    GEN_DEF_READVECTOR(AccountId_V12)
}

parser_error_t _readVecKeyValue_V12(parser_context_t* c, pd_VecKeyValue_V12_t* v) {
    GEN_DEF_READVECTOR(KeyValue_V12)
}

parser_error_t _readVecKey_V12(parser_context_t* c, pd_VecKey_V12_t* v) {
    GEN_DEF_READVECTOR(Key_V12)
}

parser_error_t _readVecLookupasStaticLookupSource_V12(parser_context_t* c, pd_VecLookupasStaticLookupSource_V12_t* v) {
    GEN_DEF_READVECTOR(LookupasStaticLookupSource_V12)
}

parser_error_t _readVecTupleAccountIdData_V12(parser_context_t* c, pd_VecTupleAccountIdData_V12_t* v) {
    GEN_DEF_READVECTOR(TupleAccountIdData_V12)
}

parser_error_t _readOptionAccountId_V12(parser_context_t* c, pd_OptionAccountId_V12_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readAccountId_V12(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionElectionScore_V12(parser_context_t* c, pd_OptionElectionScore_V12_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readElectionScore_V12(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionMultiSignature_V12(parser_context_t* c, pd_OptionMultiSignature_V12_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readMultiSignature_V12(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionMultiSigner_V12(parser_context_t* c, pd_OptionMultiSigner_V12_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readMultiSigner_V12(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionProxyType_V12(parser_context_t* c, pd_OptionProxyType_V12_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readProxyType_V12(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionReferendumIndex_V12(parser_context_t* c, pd_OptionReferendumIndex_V12_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readReferendumIndex_V12(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionStatementKind_V12(parser_context_t* c, pd_OptionStatementKind_V12_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readStatementKind_V12(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionTimepoint_V12(parser_context_t* c, pd_OptionTimepoint_V12_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readTimepoint_V12(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionTupleBalanceOfTBalanceOfTBlockNumber_V12(parser_context_t* c, pd_OptionTupleBalanceOfTBalanceOfTBlockNumber_V12_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readTupleBalanceOfTBalanceOfTBlockNumber_V12(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionXcmVersion_V12(parser_context_t* c, pd_OptionXcmVersion_V12_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readXcmVersion_V12(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionschedulePeriodBlockNumber_V12(parser_context_t* c, pd_OptionschedulePeriodBlockNumber_V12_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readschedulePeriodBlockNumber_V12(c, &v->contained))
    }
    return parser_ok;
}

///////////////////////////////////
///////////////////////////////////
///////////////////////////////////

parser_error_t _toStringAccountId_V12(
    const pd_AccountId_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringPubkeyAsAddress(v->_ptr, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringAccountIndex_V12(
    const pd_AccountIndex_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringAccountVoteSplit_V12(
    const pd_AccountVoteSplit_V12_t* v,
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

    /////////
    /////////

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringAccountVoteStandard_V12(
    const pd_AccountVoteStandard_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    // First measure number of pages
    uint8_t pages[3];

    pages[0] = 1;
    CHECK_ERROR(_toStringVote_V12(&v->vote, outValue, outValueLen, 0, &pages[1]))
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

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringVote_V12(&v->vote, outValue, outValueLen, pageIdx, &pages[1]));
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringBalanceOf(&v->balance, outValue, outValueLen, pageIdx, &pages[2]));
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringAccountVote_V12(
    const pd_AccountVote_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    switch (v->value) {
    case 0:
        _toStringAccountVoteStandard_V12(&v->voteStandard, outValue, outValueLen, pageIdx, pageCount);
        break;
    case 1:
        _toStringAccountVoteSplit_V12(&v->voteSplit, outValue, outValueLen, pageIdx, pageCount);
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _toStringAuthorityIdasRuntimeAppPublicSignature_V12(
    const pd_AuthorityIdasRuntimeAppPublicSignature_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringBoxCallOrHashOfT_V12(
    const pd_BoxCallOrHashOfT_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringBoxEquivocationProofHashBlockNumber_V12(
    const pd_BoxEquivocationProofHashBlockNumber_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringBoxEquivocationProofHeader_V12(
    const pd_BoxEquivocationProofHeader_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringBoxIdentityInfoMaxAdditionalFields_V12(
    const pd_BoxIdentityInfoMaxAdditionalFields_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringBoxMultiLocation_V12(
    const pd_BoxMultiLocation_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringBoxPalletsOrigin_V12(
    const pd_BoxPalletsOrigin_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringBoxRawSolutionSolutionOfT_V12(
    const pd_BoxRawSolutionSolutionOfT_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringBoxVersionedMultiAssets_V12(
    const pd_BoxVersionedMultiAssets_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringBoxVersionedMultiLocation_V12(
    const pd_BoxVersionedMultiLocation_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringBoxVersionedXcmTasSysConfigCall_V12(
    const pd_BoxVersionedXcmTasSysConfigCall_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringBoxVersionedXcmTuple_V12(
    const pd_BoxVersionedXcmTuple_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringCallHashOf_V12(
    const pd_CallHashOf_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount) {
    GEN_DEF_TOSTRING_ARRAY(32)
}

parser_error_t _toStringCompactAccountIndex_V12(
    const pd_CompactAccountIndex_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringCompactInt(&v->value, 0, "", "", outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringCompactPerBill_V12(
    const pd_CompactPerBill_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    // 9 but shift 2 to show as percentage
    return _toStringCompactInt(&v->value, 7, "%", "", outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringConfigOpBalanceOfT_V12(
    const pd_ConfigOpBalanceOfT_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringConfigOpPerbill_V12(
    const pd_ConfigOpPerbill_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringConfigOpPercent_V12(
    const pd_ConfigOpPercent_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringConfigOpu32_V12(
    const pd_ConfigOpu32_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringConviction_V12(
    const pd_Conviction_V12_t* v,
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

parser_error_t _toStringEcdsaSignature_V12(
    const pd_EcdsaSignature_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount) {
    GEN_DEF_TOSTRING_ARRAY(65)
}

parser_error_t _toStringElectionScore_V12(
    const pd_ElectionScore_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringEraIndex_V12(
    const pd_EraIndex_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringEthereumAddress_V12(
    const pd_EthereumAddress_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount) {
    GEN_DEF_TOSTRING_ARRAY(20)
}

parser_error_t _toStringHeadData_V12(
    const pd_HeadData_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringHeartbeatBlockNumber_V12(
    const pd_HeartbeatBlockNumber_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringHrmpChannelId_V12(
    const pd_HrmpChannelId_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringIdentityFields_V12(
    const pd_IdentityFields_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringJudgementBalanceOfT_V12(
    const pd_JudgementBalanceOfT_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringKeyOwnerProof_V12(
    const pd_KeyOwnerProof_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringKeyValue_V12(
    const pd_KeyValue_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    return parser_print_not_supported;
}

parser_error_t _toStringKey_V12(
    const pd_Key_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    return parser_print_not_supported;
}

parser_error_t _toStringKeys_V12(
    const pd_Keys_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount) {
    GEN_DEF_TOSTRING_ARRAY(6 * 32)
}

parser_error_t _toStringLeasePeriodOfT_V12(
    const pd_LeasePeriodOfT_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringLookupasStaticLookupSource_V12(
    const pd_LookupasStaticLookupSource_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    switch (v->value) {
    case 0: // Id
        CHECK_ERROR(_toStringAccountId_V12(&v->id, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 1: // Index
        CHECK_ERROR(_toStringCompactAccountIndex_V12(&v->index, outValue, outValueLen, pageIdx, pageCount))
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

parser_error_t _toStringMemberCount_V12(
    const pd_MemberCount_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringMultiSignature_V12(
    const pd_MultiSignature_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringMultiSigner_V12(
    const pd_MultiSigner_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringNextConfigDescriptor_V12(
    const pd_NextConfigDescriptor_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringOpaqueCall_V12(
    const pd_OpaqueCall_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringCall(&v->call, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringOverweightIndex_V12(
    const pd_OverweightIndex_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringParaId_V12(
    const pd_ParaId_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringParachainsInherentDataHeader_V12(
    const pd_ParachainsInherentDataHeader_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringPerbill_V12(
    const pd_Perbill_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    char bufferUI[100];
    char ratioBuffer[80];
    memset(outValue, 0, outValueLen);
    memset(ratioBuffer, 0, sizeof(ratioBuffer));
    memset(bufferUI, 0, sizeof(bufferUI));
    *pageCount = 1;

    if (fpuint64_to_str(ratioBuffer, sizeof(ratioBuffer), v->value, 7) == 0) {
        return parser_unexpected_value;
    }

    snprintf(bufferUI, sizeof(bufferUI), "%s%%", ratioBuffer);
    pageString(outValue, outValueLen, bufferUI, pageIdx, pageCount);
    return parser_ok;
}

parser_error_t _toStringPercent_V12(
    const pd_Percent_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    // 9 but shift 2 to show as percentage
    return _toStringCompactInt(&v->value, 7, "%", "", outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringProxyType_V12(
    const pd_ProxyType_V12_t* v,
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

parser_error_t _toStringPvfCheckStatement_V12(
    const pd_PvfCheckStatement_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringReferendumIndex_V12(
    const pd_ReferendumIndex_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringRegistrarIndex_V12(
    const pd_RegistrarIndex_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringRenouncing_V12(
    const pd_Renouncing_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringRewardDestination_V12(
    const pd_RewardDestination_V12_t* v,
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

parser_error_t _toStringSessionIndex_V12(
    const pd_SessionIndex_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringSolutionOrSnapshotSize_V12(
    const pd_SolutionOrSnapshotSize_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringStatementKind_V12(
    const pd_StatementKind_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringSupportsAccountId_V12(
    const pd_SupportsAccountId_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringTimepoint_V12(
    const pd_Timepoint_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2];
    CHECK_ERROR(_toStringBlockNumber(&v->height, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringu32(&v->index, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringBlockNumber(&v->height, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringu32(&v->index, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringTupleAccountIdData_V12(
    const pd_TupleAccountIdData_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringTupleBalanceOfTBalanceOfTBlockNumber_V12(
    const pd_TupleBalanceOfTBalanceOfTBlockNumber_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringValidationCodeHash_V12(
    const pd_ValidationCodeHash_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringValidationCode_V12(
    const pd_ValidationCode_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringValidatorPrefs_V12(
    const pd_ValidatorPrefs_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2];
    CHECK_ERROR(_toStringCompactPerBill_V12(&v->commission, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringbool(&v->blocked, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringCompactPerBill_V12(&v->commission, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringbool(&v->blocked, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringValidatorSignature_V12(
    const pd_ValidatorSignature_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringVestingInfoBalanceOfTBlockNumber_V12(
    const pd_VestingInfoBalanceOfTBlockNumber_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringVote_V12(
    const pd_Vote_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    switch (v->value) {
    case 0:
        snprintf(outValue, outValueLen, "Nay");
        break;
    case 1:
        snprintf(outValue, outValueLen, "Aye");
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _toStringWeightLimit_V12(
    const pd_WeightLimit_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu64(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringWeight_V12(
    const pd_Weight_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu64(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringXcmVersion_V12(
    const pd_XcmVersion_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringschedulePeriodBlockNumber_V12(
    const pd_schedulePeriodBlockNumber_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringschedulePriority_V12(
    const pd_schedulePriority_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringVecAccountId_V12(
    const pd_VecAccountId_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(AccountId_V12);
}

parser_error_t _toStringVecKeyValue_V12(
    const pd_VecKeyValue_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(KeyValue_V12);
}

parser_error_t _toStringVecKey_V12(
    const pd_VecKey_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(Key_V12);
}

parser_error_t _toStringVecLookupasStaticLookupSource_V12(
    const pd_VecLookupasStaticLookupSource_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(LookupasStaticLookupSource_V12);
}

parser_error_t _toStringVecTupleAccountIdData_V12(
    const pd_VecTupleAccountIdData_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(TupleAccountIdData_V12);
}

parser_error_t _toStringOptionAccountId_V12(
    const pd_OptionAccountId_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringAccountId_V12(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionElectionScore_V12(
    const pd_OptionElectionScore_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringElectionScore_V12(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionMultiSignature_V12(
    const pd_OptionMultiSignature_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringMultiSignature_V12(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionMultiSigner_V12(
    const pd_OptionMultiSigner_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringMultiSigner_V12(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionProxyType_V12(
    const pd_OptionProxyType_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringProxyType_V12(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionReferendumIndex_V12(
    const pd_OptionReferendumIndex_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringReferendumIndex_V12(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionStatementKind_V12(
    const pd_OptionStatementKind_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringStatementKind_V12(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionTimepoint_V12(
    const pd_OptionTimepoint_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringTimepoint_V12(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionTupleBalanceOfTBalanceOfTBlockNumber_V12(
    const pd_OptionTupleBalanceOfTBalanceOfTBlockNumber_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringTupleBalanceOfTBalanceOfTBlockNumber_V12(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionXcmVersion_V12(
    const pd_OptionXcmVersion_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringXcmVersion_V12(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionschedulePeriodBlockNumber_V12(
    const pd_OptionschedulePeriodBlockNumber_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringschedulePeriodBlockNumber_V12(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}
