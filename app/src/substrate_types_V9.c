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
#include "substrate_dispatch_V9.h"
#include "substrate_strings.h"

#include <stddef.h>
#include <stdint.h>
#include <zxformat.h>
#include <zxmacros.h>

parser_error_t _readAccountId_V9(parser_context_t* c, pd_AccountId_V9_t* v) {
    GEN_DEF_READARRAY(32)
}

parser_error_t _readAccountIndex_V9(parser_context_t* c, pd_AccountIndex_V9_t* v)
{
    return _readUInt32(c, &v->value);
}

parser_error_t _readAccountVoteBalanceOf_V9(parser_context_t* c, pd_AccountVoteBalanceOf_V9_t* v)
{
    return parser_not_supported;
}

parser_error_t _readAuthorityIdasRuntimeAppPublicSignature_V9(parser_context_t* c, pd_AuthorityIdasRuntimeAppPublicSignature_V9_t* v)
{
    return parser_not_supported;
}

parser_error_t _readBoxEquivocationProofHashBlockNumber_V9(parser_context_t* c, pd_BoxEquivocationProofHashBlockNumber_V9_t* v)
{
    return parser_not_supported;
}

parser_error_t _readBoxEquivocationProofHeader_V9(parser_context_t* c, pd_BoxEquivocationProofHeader_V9_t* v)
{
    return parser_not_supported;
}

parser_error_t _readBoxIdentityInfoMaxAdditionalFields_V9(parser_context_t* c, pd_BoxIdentityInfoMaxAdditionalFields_V9_t* v)
{
    return parser_not_supported;
}

parser_error_t _readBoxMultiLocation_V9(parser_context_t* c, pd_BoxMultiLocation_V9_t* v)
{
    return parser_not_supported;
}

parser_error_t _readBoxPalletsOrigin_V9(parser_context_t* c, pd_BoxPalletsOrigin_V9_t* v)
{
    return parser_not_supported;
}

parser_error_t _readBoxRawSolutionSolutionOfT_V9(parser_context_t* c, pd_BoxRawSolutionSolutionOfT_V9_t* v)
{
    return parser_not_supported;
}

parser_error_t _readBoxTasConfigIProposal_V9(parser_context_t* c, pd_BoxTasConfigIProposal_V9_t* v)
{
    return parser_not_supported;
}

parser_error_t _readBoxVersionedMultiAssets_V9(parser_context_t* c, pd_BoxVersionedMultiAssets_V9_t* v)
{
    return parser_not_supported;
}

parser_error_t _readBoxVersionedMultiLocation_V9(parser_context_t* c, pd_BoxVersionedMultiLocation_V9_t* v)
{
    return parser_not_supported;
}

parser_error_t _readBoxVersionedXcmTasSysConfigCall_V9(parser_context_t* c, pd_BoxVersionedXcmTasSysConfigCall_V9_t* v)
{
    return parser_not_supported;
}

parser_error_t _readBoxVersionedXcmTuple_V9(parser_context_t* c, pd_BoxVersionedXcmTuple_V9_t* v)
{
    return parser_not_supported;
}

parser_error_t _readCallHashOf_V9(parser_context_t* c, pd_CallHashOf_V9_t* v) {
    GEN_DEF_READARRAY(32)
}

parser_error_t _readCompactAccountIndex_V9(parser_context_t* c, pd_CompactAccountIndex_V9_t* v)
{
    return _readCompactInt(c, &v->value);
}

parser_error_t _readCompactPerBill_V9(parser_context_t* c, pd_CompactPerBill_V9_t* v)
{
    return _readCompactInt(c, &v->value);
}

parser_error_t _readConviction_V9(parser_context_t* c, pd_Conviction_V9_t* v)
{
    CHECK_INPUT()

    CHECK_ERROR(_readUInt8(c, &v->value))
    if (v->value > 5) {
        return parser_value_out_of_range;
    }

    return parser_ok;
}

parser_error_t _readEcdsaSignature_V9(parser_context_t* c, pd_EcdsaSignature_V9_t* v) {
    GEN_DEF_READARRAY(65)
}

parser_error_t _readElectionScore_V9(parser_context_t* c, pd_ElectionScore_V9_t* v)
{
    return parser_not_supported;
}

parser_error_t _readEraIndex_V9(parser_context_t* c, pd_EraIndex_V9_t* v)
{
    return _readUInt32(c, &v->value);
}

parser_error_t _readEthereumAddress_V9(parser_context_t* c, pd_EthereumAddress_V9_t* v) {
    GEN_DEF_READARRAY(20)
}

parser_error_t _readHeadData_V9(parser_context_t* c, pd_HeadData_V9_t* v)
{
    return parser_not_supported;
}

parser_error_t _readHeartbeatBlockNumber_V9(parser_context_t* c, pd_HeartbeatBlockNumber_V9_t* v)
{
    return parser_not_supported;
}

parser_error_t _readHrmpChannelId_V9(parser_context_t* c, pd_HrmpChannelId_V9_t* v)
{
    return parser_not_supported;
}

parser_error_t _readIdentityFields_V9(parser_context_t* c, pd_IdentityFields_V9_t* v)
{
    return parser_not_supported;
}

parser_error_t _readJudgementBalanceOfT_V9(parser_context_t* c, pd_JudgementBalanceOfT_V9_t* v)
{
    return parser_not_supported;
}

parser_error_t _readKeyOwnerProof_V9(parser_context_t* c, pd_KeyOwnerProof_V9_t* v)
{
    return parser_not_supported;
}

parser_error_t _readKeyValue_V9(parser_context_t* c, pd_KeyValue_V9_t* v) {
    GEN_DEF_READARRAY(32)
}

parser_error_t _readKey_V9(parser_context_t* c, pd_Key_V9_t* v) {
    GEN_DEF_READARRAY(32)
}

parser_error_t _readKeys_V9(parser_context_t* c, pd_Keys_V9_t* v) {
    GEN_DEF_READARRAY(6 * 32)
}

parser_error_t _readLeasePeriodOfT_V9(parser_context_t* c, pd_LeasePeriodOfT_V9_t* v)
{
    return parser_not_supported;
}

parser_error_t _readLookupasStaticLookupSource_V9(parser_context_t* c, pd_LookupasStaticLookupSource_V9_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // Id
        CHECK_ERROR(_readAccountId_V9(c, &v->id))
        break;
    case 1: // Index
        CHECK_ERROR(_readCompactAccountIndex_V9(c, &v->index))
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

parser_error_t _readMemberCount_V9(parser_context_t* c, pd_MemberCount_V9_t* v)
{
    return _readUInt32(c, &v->value);
}

parser_error_t _readMultiSignature_V9(parser_context_t* c, pd_MultiSignature_V9_t* v)
{
    return parser_not_supported;
}

parser_error_t _readMultiSigner_V9(parser_context_t* c, pd_MultiSigner_V9_t* v)
{
    return parser_not_supported;
}

parser_error_t _readNextConfigDescriptor_V9(parser_context_t* c, pd_NextConfigDescriptor_V9_t* v)
{
    return parser_not_supported;
}

parser_error_t _readOpaqueCallT_V9(parser_context_t* c, pd_OpaqueCallT_V9_t* v)
{
    return parser_not_supported;
}

parser_error_t _readOverweightIndex_V9(parser_context_t* c, pd_OverweightIndex_V9_t* v)
{
    return parser_not_supported;
}

parser_error_t _readParaId_V9(parser_context_t* c, pd_ParaId_V9_t* v)
{
    return parser_not_supported;
}

parser_error_t _readParachainsInherentDataHeader_V9(parser_context_t* c, pd_ParachainsInherentDataHeader_V9_t* v)
{
    return parser_not_supported;
}

parser_error_t _readPerbill_V9(parser_context_t* c, pd_Perbill_V9_t* v)
{
    return _readUInt32(c, &v->value);
}

parser_error_t _readPercent_V9(parser_context_t* c, pd_Percent_V9_t* v)
{
    return _readCompactInt(c, &v->value);
}

parser_error_t _readProxyType_V9(parser_context_t* c, pd_ProxyType_V9_t* v)
{
    CHECK_INPUT()

    CHECK_ERROR(_readUInt8(c, &v->value))
    if (v->value > 3) {
        return parser_value_out_of_range;
    }

    return parser_ok;
}

parser_error_t _readReferendumIndex_V9(parser_context_t* c, pd_ReferendumIndex_V9_t* v)
{
    return _readUInt32(c, &v->value);
}

parser_error_t _readRegistrarIndex_V9(parser_context_t* c, pd_RegistrarIndex_V9_t* v)
{
    return _readUInt32(c, &v->value);
}

parser_error_t _readRenouncing_V9(parser_context_t* c, pd_Renouncing_V9_t* v)
{
    return parser_not_supported;
}

parser_error_t _readRewardDestination_V9(parser_context_t* c, pd_RewardDestination_V9_t* v)
{
    CHECK_INPUT();

    CHECK_ERROR(_readUInt8(c, &v->value))
    if (v->value > 2) {
        return parser_value_out_of_range;
    }

    return parser_ok;
}

parser_error_t _readSessionIndex_V9(parser_context_t* c, pd_SessionIndex_V9_t* v)
{
    return parser_not_supported;
}

parser_error_t _readSolutionOrSnapshotSize_V9(parser_context_t* c, pd_SolutionOrSnapshotSize_V9_t* v)
{
    return parser_not_supported;
}

parser_error_t _readStatementKind_V9(parser_context_t* c, pd_StatementKind_V9_t* v)
{
    return parser_not_supported;
}

parser_error_t _readSupportsAccountId_V9(parser_context_t* c, pd_SupportsAccountId_V9_t* v)
{
    return parser_not_supported;
}

parser_error_t _readTimepoint_V9(parser_context_t* c, pd_Timepoint_V9_t* v)
{
    CHECK_ERROR(_readBlockNumber(c, &v->height))
    CHECK_ERROR(_readu32(c, &v->index))
    return parser_ok;
}

parser_error_t _readTupleAccountIdData_V9(parser_context_t* c, pd_TupleAccountIdData_V9_t* v)
{
    return parser_not_supported;
}

parser_error_t _readTupleBalanceOfTBalanceOfTBlockNumber_V9(parser_context_t* c, pd_TupleBalanceOfTBalanceOfTBlockNumber_V9_t* v)
{
    return parser_not_supported;
}

parser_error_t _readValidationCode_V9(parser_context_t* c, pd_ValidationCode_V9_t* v)
{
    return parser_not_supported;
}

parser_error_t _readValidatorPrefs_V9(parser_context_t* c, pd_ValidatorPrefs_V9_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readCompactPerBill_V9(c, &v->commission));
    CHECK_ERROR(_readbool(c, &v->blocked))
    return parser_ok;
}

parser_error_t _readVestingInfoBalanceOfTBlockNumber_V9(parser_context_t* c, pd_VestingInfoBalanceOfTBlockNumber_V9_t* v)
{
    return parser_not_supported;
}

parser_error_t _readWeightLimit_V9(parser_context_t* c, pd_WeightLimit_V9_t* v)
{
    return _readUInt64(c, &v->value);
}

parser_error_t _readWeight_V9(parser_context_t* c, pd_Weight_V9_t* v)
{
    return _readUInt64(c, &v->value);
}

parser_error_t _readXcmVersion_V9(parser_context_t* c, pd_XcmVersion_V9_t* v)
{
    return parser_not_supported;
}

parser_error_t _readschedulePeriodBlockNumber_V9(parser_context_t* c, pd_schedulePeriodBlockNumber_V9_t* v)
{
    return parser_not_supported;
}

parser_error_t _readschedulePriority_V9(parser_context_t* c, pd_schedulePriority_V9_t* v)
{
    return parser_not_supported;
}

parser_error_t _readVecAccountId_V9(parser_context_t* c, pd_VecAccountId_V9_t* v) {
    GEN_DEF_READVECTOR(AccountId_V9)
}

parser_error_t _readVecKeyValue_V9(parser_context_t* c, pd_VecKeyValue_V9_t* v) {
    GEN_DEF_READVECTOR(KeyValue_V9)
}

parser_error_t _readVecKey_V9(parser_context_t* c, pd_VecKey_V9_t* v) {
    GEN_DEF_READVECTOR(Key_V9)
}

parser_error_t _readVecLookupasStaticLookupSource_V9(parser_context_t* c, pd_VecLookupasStaticLookupSource_V9_t* v) {
    GEN_DEF_READVECTOR(LookupasStaticLookupSource_V9)
}

parser_error_t _readVecTupleAccountIdData_V9(parser_context_t* c, pd_VecTupleAccountIdData_V9_t* v) {
    GEN_DEF_READVECTOR(TupleAccountIdData_V9)
}

parser_error_t _readOptionAccountId_V9(parser_context_t* c, pd_OptionAccountId_V9_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readAccountId_V9(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionElectionScore_V9(parser_context_t* c, pd_OptionElectionScore_V9_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readElectionScore_V9(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionMultiSignature_V9(parser_context_t* c, pd_OptionMultiSignature_V9_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readMultiSignature_V9(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionMultiSigner_V9(parser_context_t* c, pd_OptionMultiSigner_V9_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readMultiSigner_V9(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionPercent_V9(parser_context_t* c, pd_OptionPercent_V9_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readPercent_V9(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionProxyType_V9(parser_context_t* c, pd_OptionProxyType_V9_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readProxyType_V9(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionReferendumIndex_V9(parser_context_t* c, pd_OptionReferendumIndex_V9_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readReferendumIndex_V9(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionStatementKind_V9(parser_context_t* c, pd_OptionStatementKind_V9_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readStatementKind_V9(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionTimepoint_V9(parser_context_t* c, pd_OptionTimepoint_V9_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readTimepoint_V9(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionTupleBalanceOfTBalanceOfTBlockNumber_V9(parser_context_t* c, pd_OptionTupleBalanceOfTBalanceOfTBlockNumber_V9_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readTupleBalanceOfTBalanceOfTBlockNumber_V9(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionXcmVersion_V9(parser_context_t* c, pd_OptionXcmVersion_V9_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readXcmVersion_V9(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionschedulePeriodBlockNumber_V9(parser_context_t* c, pd_OptionschedulePeriodBlockNumber_V9_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readschedulePeriodBlockNumber_V9(c, &v->contained))
    }
    return parser_ok;
}

///////////////////////////////////
///////////////////////////////////
///////////////////////////////////

parser_error_t _toStringAccountId_V9(
    const pd_AccountId_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringPubkeyAsAddress(v->_ptr, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringAccountIndex_V9(
    const pd_AccountIndex_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringAccountVoteBalanceOf_V9(
    const pd_AccountVoteBalanceOf_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringAuthorityIdasRuntimeAppPublicSignature_V9(
    const pd_AuthorityIdasRuntimeAppPublicSignature_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringBoxEquivocationProofHashBlockNumber_V9(
    const pd_BoxEquivocationProofHashBlockNumber_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringBoxEquivocationProofHeader_V9(
    const pd_BoxEquivocationProofHeader_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringBoxIdentityInfoMaxAdditionalFields_V9(
    const pd_BoxIdentityInfoMaxAdditionalFields_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringBoxMultiLocation_V9(
    const pd_BoxMultiLocation_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringBoxPalletsOrigin_V9(
    const pd_BoxPalletsOrigin_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringBoxRawSolutionSolutionOfT_V9(
    const pd_BoxRawSolutionSolutionOfT_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringBoxTasConfigIProposal_V9(
    const pd_BoxTasConfigIProposal_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringBoxVersionedMultiAssets_V9(
    const pd_BoxVersionedMultiAssets_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringBoxVersionedMultiLocation_V9(
    const pd_BoxVersionedMultiLocation_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringBoxVersionedXcmTasSysConfigCall_V9(
    const pd_BoxVersionedXcmTasSysConfigCall_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringBoxVersionedXcmTuple_V9(
    const pd_BoxVersionedXcmTuple_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringCallHashOf_V9(
    const pd_CallHashOf_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount) {
    GEN_DEF_TOSTRING_ARRAY(32)
}

parser_error_t _toStringCompactAccountIndex_V9(
    const pd_CompactAccountIndex_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringCompactInt(&v->value, 0, "", "", outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringCompactPerBill_V9(
    const pd_CompactPerBill_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    // 9 but shift 2 to show as percentage
    return _toStringCompactInt(&v->value, 7, "%", "", outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringConviction_V9(
    const pd_Conviction_V9_t* v,
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

parser_error_t _toStringEcdsaSignature_V9(
    const pd_EcdsaSignature_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount) {
    GEN_DEF_TOSTRING_ARRAY(65)
}

parser_error_t _toStringElectionScore_V9(
    const pd_ElectionScore_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringEraIndex_V9(
    const pd_EraIndex_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringEthereumAddress_V9(
    const pd_EthereumAddress_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount) {
    GEN_DEF_TOSTRING_ARRAY(20)
}

parser_error_t _toStringHeadData_V9(
    const pd_HeadData_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringHeartbeatBlockNumber_V9(
    const pd_HeartbeatBlockNumber_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringHrmpChannelId_V9(
    const pd_HrmpChannelId_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringIdentityFields_V9(
    const pd_IdentityFields_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringJudgementBalanceOfT_V9(
    const pd_JudgementBalanceOfT_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringKeyOwnerProof_V9(
    const pd_KeyOwnerProof_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringKeyValue_V9(
    const pd_KeyValue_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    return parser_print_not_supported;
}

parser_error_t _toStringKey_V9(
    const pd_Key_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    return parser_print_not_supported;
}

parser_error_t _toStringKeys_V9(
    const pd_Keys_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount) {
    GEN_DEF_TOSTRING_ARRAY(4 * 32)
}

parser_error_t _toStringLeasePeriodOfT_V9(
    const pd_LeasePeriodOfT_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringLookupasStaticLookupSource_V9(
    const pd_LookupasStaticLookupSource_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    switch (v->value) {
    case 0: // Id
        CHECK_ERROR(_toStringAccountId_V9(&v->id, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 1: // Index
        CHECK_ERROR(_toStringCompactAccountIndex_V9(&v->index, outValue, outValueLen, pageIdx, pageCount))
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
        return parser_unexpected_address_type;
    }

    return parser_ok;
}

parser_error_t _toStringMemberCount_V9(
    const pd_MemberCount_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringMultiSignature_V9(
    const pd_MultiSignature_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringMultiSigner_V9(
    const pd_MultiSigner_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringNextConfigDescriptor_V9(
    const pd_NextConfigDescriptor_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringOpaqueCallT_V9(
    const pd_OpaqueCallT_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringOverweightIndex_V9(
    const pd_OverweightIndex_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringParaId_V9(
    const pd_ParaId_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringParachainsInherentDataHeader_V9(
    const pd_ParachainsInherentDataHeader_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringPerbill_V9(
    const pd_Perbill_V9_t* v,
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

parser_error_t _toStringPercent_V9(
    const pd_Percent_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    // 9 but shift 2 to show as percentage
    return _toStringCompactInt(&v->value, 7, "%", "", outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringProxyType_V9(
    const pd_ProxyType_V9_t* v,
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

parser_error_t _toStringReferendumIndex_V9(
    const pd_ReferendumIndex_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringRegistrarIndex_V9(
    const pd_RegistrarIndex_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringRenouncing_V9(
    const pd_Renouncing_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringRewardDestination_V9(
    const pd_RewardDestination_V9_t* v,
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

parser_error_t _toStringSessionIndex_V9(
    const pd_SessionIndex_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringSolutionOrSnapshotSize_V9(
    const pd_SolutionOrSnapshotSize_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringStatementKind_V9(
    const pd_StatementKind_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringSupportsAccountId_V9(
    const pd_SupportsAccountId_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringTimepoint_V9(
    const pd_Timepoint_V9_t* v,
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

parser_error_t _toStringTupleAccountIdData_V9(
    const pd_TupleAccountIdData_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringTupleBalanceOfTBalanceOfTBlockNumber_V9(
    const pd_TupleBalanceOfTBalanceOfTBlockNumber_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringValidationCode_V9(
    const pd_ValidationCode_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringValidatorPrefs_V9(
    const pd_ValidatorPrefs_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    uint8_t pages[2];
    CHECK_ERROR(_toStringCompactPerBill_V9(&v->commission, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringbool(&v->blocked, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringCompactPerBill_V9(&v->commission, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringbool(&v->blocked, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringVestingInfoBalanceOfTBlockNumber_V9(
    const pd_VestingInfoBalanceOfTBlockNumber_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringWeightLimit_V9(
    const pd_WeightLimit_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu64(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringWeight_V9(
    const pd_Weight_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu64(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringXcmVersion_V9(
    const pd_XcmVersion_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringschedulePeriodBlockNumber_V9(
    const pd_schedulePeriodBlockNumber_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringschedulePriority_V9(
    const pd_schedulePriority_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringVecAccountId_V9(
    const pd_VecAccountId_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(AccountId_V9);
}

parser_error_t _toStringVecKeyValue_V9(
    const pd_VecKeyValue_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(KeyValue_V9);
}

parser_error_t _toStringVecKey_V9(
    const pd_VecKey_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(Key_V9);
}

parser_error_t _toStringVecLookupasStaticLookupSource_V9(
    const pd_VecLookupasStaticLookupSource_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(LookupasStaticLookupSource_V9);
}

parser_error_t _toStringVecTupleAccountIdData_V9(
    const pd_VecTupleAccountIdData_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(TupleAccountIdData_V9);
}

parser_error_t _toStringOptionAccountId_V9(
    const pd_OptionAccountId_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringAccountId_V9(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionElectionScore_V9(
    const pd_OptionElectionScore_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringElectionScore_V9(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionMultiSignature_V9(
    const pd_OptionMultiSignature_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringMultiSignature_V9(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionMultiSigner_V9(
    const pd_OptionMultiSigner_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringMultiSigner_V9(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionPercent_V9(
    const pd_OptionPercent_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringPercent_V9(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionProxyType_V9(
    const pd_OptionProxyType_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringProxyType_V9(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionReferendumIndex_V9(
    const pd_OptionReferendumIndex_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringReferendumIndex_V9(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionStatementKind_V9(
    const pd_OptionStatementKind_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringStatementKind_V9(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionTimepoint_V9(
    const pd_OptionTimepoint_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringTimepoint_V9(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionTupleBalanceOfTBalanceOfTBlockNumber_V9(
    const pd_OptionTupleBalanceOfTBalanceOfTBlockNumber_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringTupleBalanceOfTBalanceOfTBlockNumber_V9(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionXcmVersion_V9(
    const pd_OptionXcmVersion_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringXcmVersion_V9(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionschedulePeriodBlockNumber_V9(
    const pd_OptionschedulePeriodBlockNumber_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringschedulePeriodBlockNumber_V9(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}
