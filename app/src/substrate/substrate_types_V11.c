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
#include "substrate_dispatch_V11.h"
#include "substrate_strings.h"

#include <stddef.h>
#include <stdint.h>
#include <zxformat.h>
#include <zxmacros.h>

parser_error_t _readAccountId_V11(parser_context_t* c, pd_AccountId_V11_t* v) {
    GEN_DEF_READARRAY(32)
}

parser_error_t _readAccountIndex_V11(parser_context_t* c, pd_AccountIndex_V11_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readAccountVoteBalanceOf_V11(parser_context_t* c, pd_AccountVoteBalanceOf_V11_t* v)
{
    return parser_not_supported;
}

parser_error_t _readAuthorityIdasRuntimeAppPublicSignature_V11(parser_context_t* c, pd_AuthorityIdasRuntimeAppPublicSignature_V11_t* v)
{
    return parser_not_supported;
}

parser_error_t _readBoxCallOrHashOfT_V11(parser_context_t* c, pd_BoxCallOrHashOfT_V11_t* v)
{
    return parser_not_supported;
}

parser_error_t _readBoxEquivocationProofHashBlockNumber_V11(parser_context_t* c, pd_BoxEquivocationProofHashBlockNumber_V11_t* v)
{
    return parser_not_supported;
}

parser_error_t _readBoxEquivocationProofHeader_V11(parser_context_t* c, pd_BoxEquivocationProofHeader_V11_t* v)
{
    return parser_not_supported;
}

parser_error_t _readBoxIdentityInfoMaxAdditionalFields_V11(parser_context_t* c, pd_BoxIdentityInfoMaxAdditionalFields_V11_t* v)
{
    return parser_not_supported;
}

parser_error_t _readBoxMultiLocation_V11(parser_context_t* c, pd_BoxMultiLocation_V11_t* v)
{
    return parser_not_supported;
}

parser_error_t _readBoxPalletsOrigin_V11(parser_context_t* c, pd_BoxPalletsOrigin_V11_t* v)
{
    return parser_not_supported;
}

parser_error_t _readBoxRawSolutionSolutionOfT_V11(parser_context_t* c, pd_BoxRawSolutionSolutionOfT_V11_t* v)
{
    return parser_not_supported;
}

parser_error_t _readBoxTasConfigIProposal_V11(parser_context_t* c, pd_BoxTasConfigIProposal_V11_t* v)
{
    return parser_not_supported;
}

parser_error_t _readBoxVersionedMultiAssets_V11(parser_context_t* c, pd_BoxVersionedMultiAssets_V11_t* v)
{
    return parser_not_supported;
}

parser_error_t _readBoxVersionedMultiLocation_V11(parser_context_t* c, pd_BoxVersionedMultiLocation_V11_t* v)
{
    return parser_not_supported;
}

parser_error_t _readBoxVersionedXcmTasSysConfigCall_V11(parser_context_t* c, pd_BoxVersionedXcmTasSysConfigCall_V11_t* v)
{
    return parser_not_supported;
}

parser_error_t _readBoxVersionedXcmTuple_V11(parser_context_t* c, pd_BoxVersionedXcmTuple_V11_t* v)
{
    return parser_not_supported;
}

parser_error_t _readCallHashOf_V11(parser_context_t* c, pd_CallHashOf_V11_t* v) {
    GEN_DEF_READARRAY(32)
}

parser_error_t _readCompactAccountIndex_V11(parser_context_t* c, pd_CompactAccountIndex_V11_t* v)
{
    return _readCompactInt(c, &v->value);
}

parser_error_t _readCompactPerBill_V11(parser_context_t* c, pd_CompactPerBill_V11_t* v)
{
    return _readCompactInt(c, &v->value);
}

parser_error_t _readConviction_V11(parser_context_t* c, pd_Conviction_V11_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readUInt8(c, &v->value))
    if (v->value > 5) {
        return parser_value_out_of_range;
    }
    return parser_ok;
}

parser_error_t _readEcdsaSignature_V11(parser_context_t* c, pd_EcdsaSignature_V11_t* v) {
    GEN_DEF_READARRAY(65)
}

parser_error_t _readElectionScore_V11(parser_context_t* c, pd_ElectionScore_V11_t* v)
{
    return parser_not_supported;
}

parser_error_t _readEraIndex_V11(parser_context_t* c, pd_EraIndex_V11_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readEthereumAddress_V11(parser_context_t* c, pd_EthereumAddress_V11_t* v) {
    GEN_DEF_READARRAY(20)
}

parser_error_t _readHeadData_V11(parser_context_t* c, pd_HeadData_V11_t* v)
{
    return parser_not_supported;
}

parser_error_t _readHeartbeatBlockNumber_V11(parser_context_t* c, pd_HeartbeatBlockNumber_V11_t* v)
{
    return parser_not_supported;
}

parser_error_t _readHrmpChannelId_V11(parser_context_t* c, pd_HrmpChannelId_V11_t* v)
{
    return parser_not_supported;
}

parser_error_t _readIdentityFields_V11(parser_context_t* c, pd_IdentityFields_V11_t* v)
{
    return parser_not_supported;
}

parser_error_t _readJudgementBalanceOfT_V11(parser_context_t* c, pd_JudgementBalanceOfT_V11_t* v)
{
    return parser_not_supported;
}

parser_error_t _readKeyOwnerProof_V11(parser_context_t* c, pd_KeyOwnerProof_V11_t* v)
{
    return parser_not_supported;
}

parser_error_t _readKeyValue_V11(parser_context_t* c, pd_KeyValue_V11_t* v) {
    GEN_DEF_READARRAY(32)
}

parser_error_t _readKey_V11(parser_context_t* c, pd_Key_V11_t* v) {
    GEN_DEF_READARRAY(32)
}

parser_error_t _readKeys_V11(parser_context_t* c, pd_Keys_V11_t* v) {
    GEN_DEF_READARRAY(6 * 32)
}

parser_error_t _readLeasePeriodOfT_V11(parser_context_t* c, pd_LeasePeriodOfT_V11_t* v)
{
    return parser_not_supported;
}

parser_error_t _readLookupasStaticLookupSource_V11(parser_context_t* c, pd_LookupasStaticLookupSource_V11_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // Id
        CHECK_ERROR(_readAccountId_V11(c, &v->id))
        break;
    case 1: // Index
        CHECK_ERROR(_readCompactAccountIndex_V11(c, &v->index))
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

parser_error_t _readMemberCount_V11(parser_context_t* c, pd_MemberCount_V11_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readMultiSignature_V11(parser_context_t* c, pd_MultiSignature_V11_t* v)
{
    return parser_not_supported;
}

parser_error_t _readMultiSigner_V11(parser_context_t* c, pd_MultiSigner_V11_t* v)
{
    return parser_not_supported;
}

parser_error_t _readNextConfigDescriptor_V11(parser_context_t* c, pd_NextConfigDescriptor_V11_t* v)
{
    return parser_not_supported;
}

parser_error_t _readOpaqueCall_V11(parser_context_t* c, pd_OpaqueCall_V11_t* v)
{
    // Encoded as Byte[], array size comes first
    uint8_t size;
    CHECK_ERROR(_readUInt8(c, &size))
    return _readCall(c, &v->call);
}

parser_error_t _readOverweightIndex_V11(parser_context_t* c, pd_OverweightIndex_V11_t* v)
{
    return parser_not_supported;
}

parser_error_t _readParaId_V11(parser_context_t* c, pd_ParaId_V11_t* v)
{
    return parser_not_supported;
}

parser_error_t _readParachainsInherentDataHeader_V11(parser_context_t* c, pd_ParachainsInherentDataHeader_V11_t* v)
{
    return parser_not_supported;
}

parser_error_t _readPerbill_V11(parser_context_t* c, pd_Perbill_V11_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readPercent_V11(parser_context_t* c, pd_Percent_V11_t* v)
{
    return _readCompactInt(c, &v->value);
}

parser_error_t _readProxyType_V11(parser_context_t* c, pd_ProxyType_V11_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readUInt8(c, &v->value))
    if (v->value > 3) {
        return parser_value_out_of_range;
    }
    return parser_ok;
}

parser_error_t _readPvfCheckStatement_V11(parser_context_t* c, pd_PvfCheckStatement_V11_t* v)
{
    return parser_not_supported;
}

parser_error_t _readReferendumIndex_V11(parser_context_t* c, pd_ReferendumIndex_V11_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readRegistrarIndex_V11(parser_context_t* c, pd_RegistrarIndex_V11_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readRenouncing_V11(parser_context_t* c, pd_Renouncing_V11_t* v)
{
    return parser_not_supported;
}

parser_error_t _readRewardDestination_V11(parser_context_t* c, pd_RewardDestination_V11_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readUInt8(c, &v->value))
    if (v->value > 2) {
        return parser_value_out_of_range;
    }
    return parser_ok;
}

parser_error_t _readSessionIndex_V11(parser_context_t* c, pd_SessionIndex_V11_t* v)
{
    return _readUInt32(c, &v->value);
}

parser_error_t _readSolutionOrSnapshotSize_V11(parser_context_t* c, pd_SolutionOrSnapshotSize_V11_t* v)
{
    return parser_not_supported;
}

parser_error_t _readStatementKind_V11(parser_context_t* c, pd_StatementKind_V11_t* v)
{
    return parser_not_supported;
}

parser_error_t _readSupportsAccountId_V11(parser_context_t* c, pd_SupportsAccountId_V11_t* v)
{
    return parser_not_supported;
}

parser_error_t _readTimepoint_V11(parser_context_t* c, pd_Timepoint_V11_t* v)
{
    CHECK_ERROR(_readBlockNumber(c, &v->height))
    CHECK_ERROR(_readu32(c, &v->index))
    return parser_ok;
}

parser_error_t _readTupleAccountIdData_V11(parser_context_t* c, pd_TupleAccountIdData_V11_t* v)
{
    return parser_not_supported;
}

parser_error_t _readTupleBalanceOfTBalanceOfTBlockNumber_V11(parser_context_t* c, pd_TupleBalanceOfTBalanceOfTBlockNumber_V11_t* v)
{
    return parser_not_supported;
}

parser_error_t _readValidationCodeHash_V11(parser_context_t* c, pd_ValidationCodeHash_V11_t* v)
{
    return parser_not_supported;
}

parser_error_t _readValidationCode_V11(parser_context_t* c, pd_ValidationCode_V11_t* v)
{
    return parser_not_supported;
}

parser_error_t _readValidatorPrefs_V11(parser_context_t* c, pd_ValidatorPrefs_V11_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readCompactPerBill_V11(c, &v->commission));
    CHECK_ERROR(_readbool(c, &v->blocked))
    return parser_ok;
}

parser_error_t _readValidatorSignature_V11(parser_context_t* c, pd_ValidatorSignature_V11_t* v)
{
    return parser_not_supported;
}

parser_error_t _readVestingInfoBalanceOfTBlockNumber_V11(parser_context_t* c, pd_VestingInfoBalanceOfTBlockNumber_V11_t* v)
{
    return parser_not_supported;
}

parser_error_t _readWeightLimit_V11(parser_context_t* c, pd_WeightLimit_V11_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readUInt64(c, &v->value))
    return parser_ok;
}

parser_error_t _readWeight_V11(parser_context_t* c, pd_Weight_V11_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readUInt64(c, &v->value))
    return parser_ok;
}

parser_error_t _readXcmVersion_V11(parser_context_t* c, pd_XcmVersion_V11_t* v)
{
    return parser_not_supported;
}

parser_error_t _readschedulePeriodBlockNumber_V11(parser_context_t* c, pd_schedulePeriodBlockNumber_V11_t* v)
{
    return parser_not_supported;
}

parser_error_t _readschedulePriority_V11(parser_context_t* c, pd_schedulePriority_V11_t* v)
{
    return parser_not_supported;
}

parser_error_t _readVecAccountId_V11(parser_context_t* c, pd_VecAccountId_V11_t* v) {
    GEN_DEF_READVECTOR(AccountId_V11)
}

parser_error_t _readVecKeyValue_V11(parser_context_t* c, pd_VecKeyValue_V11_t* v) {
    GEN_DEF_READVECTOR(KeyValue_V11)
}

parser_error_t _readVecKey_V11(parser_context_t* c, pd_VecKey_V11_t* v) {
    GEN_DEF_READVECTOR(Key_V11)
}

parser_error_t _readVecLookupasStaticLookupSource_V11(parser_context_t* c, pd_VecLookupasStaticLookupSource_V11_t* v) {
    GEN_DEF_READVECTOR(LookupasStaticLookupSource_V11)
}

parser_error_t _readVecTupleAccountIdData_V11(parser_context_t* c, pd_VecTupleAccountIdData_V11_t* v) {
    GEN_DEF_READVECTOR(TupleAccountIdData_V11)
}

parser_error_t _readOptionAccountId_V11(parser_context_t* c, pd_OptionAccountId_V11_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readAccountId_V11(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionElectionScore_V11(parser_context_t* c, pd_OptionElectionScore_V11_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readElectionScore_V11(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionMultiSignature_V11(parser_context_t* c, pd_OptionMultiSignature_V11_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readMultiSignature_V11(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionMultiSigner_V11(parser_context_t* c, pd_OptionMultiSigner_V11_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readMultiSigner_V11(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionPercent_V11(parser_context_t* c, pd_OptionPercent_V11_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readPercent_V11(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionProxyType_V11(parser_context_t* c, pd_OptionProxyType_V11_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readProxyType_V11(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionReferendumIndex_V11(parser_context_t* c, pd_OptionReferendumIndex_V11_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readReferendumIndex_V11(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionStatementKind_V11(parser_context_t* c, pd_OptionStatementKind_V11_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readStatementKind_V11(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionTimepoint_V11(parser_context_t* c, pd_OptionTimepoint_V11_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readTimepoint_V11(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionTupleBalanceOfTBalanceOfTBlockNumber_V11(parser_context_t* c, pd_OptionTupleBalanceOfTBalanceOfTBlockNumber_V11_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readTupleBalanceOfTBalanceOfTBlockNumber_V11(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionXcmVersion_V11(parser_context_t* c, pd_OptionXcmVersion_V11_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readXcmVersion_V11(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionschedulePeriodBlockNumber_V11(parser_context_t* c, pd_OptionschedulePeriodBlockNumber_V11_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readschedulePeriodBlockNumber_V11(c, &v->contained))
    }
    return parser_ok;
}

///////////////////////////////////
///////////////////////////////////
///////////////////////////////////

parser_error_t _toStringAccountId_V11(
    const pd_AccountId_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringPubkeyAsAddress(v->_ptr, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringAccountIndex_V11(
    const pd_AccountIndex_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringAccountVoteBalanceOf_V11(
    const pd_AccountVoteBalanceOf_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringAuthorityIdasRuntimeAppPublicSignature_V11(
    const pd_AuthorityIdasRuntimeAppPublicSignature_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringBoxCallOrHashOfT_V11(
    const pd_BoxCallOrHashOfT_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringBoxEquivocationProofHashBlockNumber_V11(
    const pd_BoxEquivocationProofHashBlockNumber_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringBoxEquivocationProofHeader_V11(
    const pd_BoxEquivocationProofHeader_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringBoxIdentityInfoMaxAdditionalFields_V11(
    const pd_BoxIdentityInfoMaxAdditionalFields_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringBoxMultiLocation_V11(
    const pd_BoxMultiLocation_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringBoxPalletsOrigin_V11(
    const pd_BoxPalletsOrigin_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringBoxRawSolutionSolutionOfT_V11(
    const pd_BoxRawSolutionSolutionOfT_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringBoxTasConfigIProposal_V11(
    const pd_BoxTasConfigIProposal_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringBoxVersionedMultiAssets_V11(
    const pd_BoxVersionedMultiAssets_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringBoxVersionedMultiLocation_V11(
    const pd_BoxVersionedMultiLocation_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringBoxVersionedXcmTasSysConfigCall_V11(
    const pd_BoxVersionedXcmTasSysConfigCall_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringBoxVersionedXcmTuple_V11(
    const pd_BoxVersionedXcmTuple_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringCallHashOf_V11(
    const pd_CallHashOf_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount) {
    GEN_DEF_TOSTRING_ARRAY(32)
}

parser_error_t _toStringCompactAccountIndex_V11(
    const pd_CompactAccountIndex_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringCompactInt(&v->value, 0, "", "", outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringCompactPerBill_V11(
    const pd_CompactPerBill_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    // 9 but shift 2 to show as percentage
    return _toStringCompactInt(&v->value, 7, "%", "", outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringConviction_V11(
    const pd_Conviction_V11_t* v,
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

parser_error_t _toStringEcdsaSignature_V11(
    const pd_EcdsaSignature_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount) {
    GEN_DEF_TOSTRING_ARRAY(65)
}

parser_error_t _toStringElectionScore_V11(
    const pd_ElectionScore_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringEraIndex_V11(
    const pd_EraIndex_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringEthereumAddress_V11(
    const pd_EthereumAddress_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount) {
    GEN_DEF_TOSTRING_ARRAY(20)
}

parser_error_t _toStringHeadData_V11(
    const pd_HeadData_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringHeartbeatBlockNumber_V11(
    const pd_HeartbeatBlockNumber_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringHrmpChannelId_V11(
    const pd_HrmpChannelId_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringIdentityFields_V11(
    const pd_IdentityFields_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringJudgementBalanceOfT_V11(
    const pd_JudgementBalanceOfT_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringKeyOwnerProof_V11(
    const pd_KeyOwnerProof_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringKeyValue_V11(
    const pd_KeyValue_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    return parser_print_not_supported;
}

parser_error_t _toStringKey_V11(
    const pd_Key_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    return parser_print_not_supported;
}

parser_error_t _toStringKeys_V11(
    const pd_Keys_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount) {
    GEN_DEF_TOSTRING_ARRAY(4 * 32)
}

parser_error_t _toStringLeasePeriodOfT_V11(
    const pd_LeasePeriodOfT_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringLookupasStaticLookupSource_V11(
    const pd_LookupasStaticLookupSource_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    switch (v->value) {
    case 0: // Id
        CHECK_ERROR(_toStringAccountId_V11(&v->id, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 1: // Index
        CHECK_ERROR(_toStringCompactAccountIndex_V11(&v->index, outValue, outValueLen, pageIdx, pageCount))
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

parser_error_t _toStringMemberCount_V11(
    const pd_MemberCount_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringMultiSignature_V11(
    const pd_MultiSignature_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringMultiSigner_V11(
    const pd_MultiSigner_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringNextConfigDescriptor_V11(
    const pd_NextConfigDescriptor_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringOpaqueCall_V11(
    const pd_OpaqueCall_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringCall(&v->call, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringOverweightIndex_V11(
    const pd_OverweightIndex_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringParaId_V11(
    const pd_ParaId_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringParachainsInherentDataHeader_V11(
    const pd_ParachainsInherentDataHeader_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringPerbill_V11(
    const pd_Perbill_V11_t* v,
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

parser_error_t _toStringPercent_V11(
    const pd_Percent_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    // 9 but shift 2 to show as percentage
    return _toStringCompactInt(&v->value, 7, "%", "", outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringProxyType_V11(
    const pd_ProxyType_V11_t* v,
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

parser_error_t _toStringPvfCheckStatement_V11(
    const pd_PvfCheckStatement_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringReferendumIndex_V11(
    const pd_ReferendumIndex_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringRegistrarIndex_V11(
    const pd_RegistrarIndex_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringRenouncing_V11(
    const pd_Renouncing_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringRewardDestination_V11(
    const pd_RewardDestination_V11_t* v,
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

parser_error_t _toStringSessionIndex_V11(
    const pd_SessionIndex_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringSolutionOrSnapshotSize_V11(
    const pd_SolutionOrSnapshotSize_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringStatementKind_V11(
    const pd_StatementKind_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringSupportsAccountId_V11(
    const pd_SupportsAccountId_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringTimepoint_V11(
    const pd_Timepoint_V11_t* v,
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

parser_error_t _toStringTupleAccountIdData_V11(
    const pd_TupleAccountIdData_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringTupleBalanceOfTBalanceOfTBlockNumber_V11(
    const pd_TupleBalanceOfTBalanceOfTBlockNumber_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringValidationCodeHash_V11(
    const pd_ValidationCodeHash_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringValidationCode_V11(
    const pd_ValidationCode_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringValidatorPrefs_V11(
    const pd_ValidatorPrefs_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2];
    CHECK_ERROR(_toStringCompactPerBill_V11(&v->commission, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringbool(&v->blocked, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringCompactPerBill_V11(&v->commission, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringbool(&v->blocked, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringValidatorSignature_V11(
    const pd_ValidatorSignature_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringVestingInfoBalanceOfTBlockNumber_V11(
    const pd_VestingInfoBalanceOfTBlockNumber_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringWeightLimit_V11(
    const pd_WeightLimit_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu64(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringWeight_V11(
    const pd_Weight_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu64(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringXcmVersion_V11(
    const pd_XcmVersion_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringschedulePeriodBlockNumber_V11(
    const pd_schedulePeriodBlockNumber_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringschedulePriority_V11(
    const pd_schedulePriority_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringVecAccountId_V11(
    const pd_VecAccountId_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(AccountId_V11);
}

parser_error_t _toStringVecKeyValue_V11(
    const pd_VecKeyValue_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(KeyValue_V11);
}

parser_error_t _toStringVecKey_V11(
    const pd_VecKey_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(Key_V11);
}

parser_error_t _toStringVecLookupasStaticLookupSource_V11(
    const pd_VecLookupasStaticLookupSource_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(LookupasStaticLookupSource_V11);
}

parser_error_t _toStringVecTupleAccountIdData_V11(
    const pd_VecTupleAccountIdData_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(TupleAccountIdData_V11);
}

parser_error_t _toStringOptionAccountId_V11(
    const pd_OptionAccountId_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringAccountId_V11(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionElectionScore_V11(
    const pd_OptionElectionScore_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringElectionScore_V11(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionMultiSignature_V11(
    const pd_OptionMultiSignature_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringMultiSignature_V11(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionMultiSigner_V11(
    const pd_OptionMultiSigner_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringMultiSigner_V11(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionPercent_V11(
    const pd_OptionPercent_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringPercent_V11(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionProxyType_V11(
    const pd_OptionProxyType_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringProxyType_V11(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionReferendumIndex_V11(
    const pd_OptionReferendumIndex_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringReferendumIndex_V11(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionStatementKind_V11(
    const pd_OptionStatementKind_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringStatementKind_V11(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionTimepoint_V11(
    const pd_OptionTimepoint_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringTimepoint_V11(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionTupleBalanceOfTBalanceOfTBlockNumber_V11(
    const pd_OptionTupleBalanceOfTBalanceOfTBlockNumber_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringTupleBalanceOfTBalanceOfTBlockNumber_V11(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionXcmVersion_V11(
    const pd_OptionXcmVersion_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringXcmVersion_V11(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionschedulePeriodBlockNumber_V11(
    const pd_OptionschedulePeriodBlockNumber_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringschedulePeriodBlockNumber_V11(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}
