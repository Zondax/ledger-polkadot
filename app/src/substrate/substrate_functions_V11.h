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
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "parser_common.h"
#include "substrate_methods_V11.h"
#include "substrate_types_V11.h"
#include <stddef.h>
#include <stdint.h>

// Read functions
parser_error_t _readAccountId_V11(parser_context_t* c, pd_AccountId_V11_t* v);
parser_error_t _readAccountIndex_V11(parser_context_t* c, pd_AccountIndex_V11_t* v);
parser_error_t _readAccountVoteBalanceOf_V11(parser_context_t* c, pd_AccountVoteBalanceOf_V11_t* v);
parser_error_t _readAuthorityIdasRuntimeAppPublicSignature_V11(parser_context_t* c, pd_AuthorityIdasRuntimeAppPublicSignature_V11_t* v);
parser_error_t _readBoxCallOrHashOfT_V11(parser_context_t* c, pd_BoxCallOrHashOfT_V11_t* v);
parser_error_t _readBoxEquivocationProofHashBlockNumber_V11(parser_context_t* c, pd_BoxEquivocationProofHashBlockNumber_V11_t* v);
parser_error_t _readBoxEquivocationProofHeader_V11(parser_context_t* c, pd_BoxEquivocationProofHeader_V11_t* v);
parser_error_t _readBoxIdentityInfoMaxAdditionalFields_V11(parser_context_t* c, pd_BoxIdentityInfoMaxAdditionalFields_V11_t* v);
parser_error_t _readBoxMultiLocation_V11(parser_context_t* c, pd_BoxMultiLocation_V11_t* v);
parser_error_t _readBoxPalletsOrigin_V11(parser_context_t* c, pd_BoxPalletsOrigin_V11_t* v);
parser_error_t _readBoxRawSolutionSolutionOfT_V11(parser_context_t* c, pd_BoxRawSolutionSolutionOfT_V11_t* v);
parser_error_t _readBoxTasConfigIProposal_V11(parser_context_t* c, pd_BoxTasConfigIProposal_V11_t* v);
parser_error_t _readBoxVersionedMultiAssets_V11(parser_context_t* c, pd_BoxVersionedMultiAssets_V11_t* v);
parser_error_t _readBoxVersionedMultiLocation_V11(parser_context_t* c, pd_BoxVersionedMultiLocation_V11_t* v);
parser_error_t _readBoxVersionedXcmTasSysConfigCall_V11(parser_context_t* c, pd_BoxVersionedXcmTasSysConfigCall_V11_t* v);
parser_error_t _readBoxVersionedXcmTuple_V11(parser_context_t* c, pd_BoxVersionedXcmTuple_V11_t* v);
parser_error_t _readCallHashOf_V11(parser_context_t* c, pd_CallHashOf_V11_t* v);
parser_error_t _readCompactAccountIndex_V11(parser_context_t* c, pd_CompactAccountIndex_V11_t* v);
parser_error_t _readCompactPerBill_V11(parser_context_t* c, pd_CompactPerBill_V11_t* v);
parser_error_t _readConviction_V11(parser_context_t* c, pd_Conviction_V11_t* v);
parser_error_t _readEcdsaSignature_V11(parser_context_t* c, pd_EcdsaSignature_V11_t* v);
parser_error_t _readElectionScore_V11(parser_context_t* c, pd_ElectionScore_V11_t* v);
parser_error_t _readEraIndex_V11(parser_context_t* c, pd_EraIndex_V11_t* v);
parser_error_t _readEthereumAddress_V11(parser_context_t* c, pd_EthereumAddress_V11_t* v);
parser_error_t _readHeadData_V11(parser_context_t* c, pd_HeadData_V11_t* v);
parser_error_t _readHeartbeatBlockNumber_V11(parser_context_t* c, pd_HeartbeatBlockNumber_V11_t* v);
parser_error_t _readHrmpChannelId_V11(parser_context_t* c, pd_HrmpChannelId_V11_t* v);
parser_error_t _readIdentityFields_V11(parser_context_t* c, pd_IdentityFields_V11_t* v);
parser_error_t _readJudgementBalanceOfT_V11(parser_context_t* c, pd_JudgementBalanceOfT_V11_t* v);
parser_error_t _readKeyOwnerProof_V11(parser_context_t* c, pd_KeyOwnerProof_V11_t* v);
parser_error_t _readKeyValue_V11(parser_context_t* c, pd_KeyValue_V11_t* v);
parser_error_t _readKey_V11(parser_context_t* c, pd_Key_V11_t* v);
parser_error_t _readKeys_V11(parser_context_t* c, pd_Keys_V11_t* v);
parser_error_t _readLeasePeriodOfT_V11(parser_context_t* c, pd_LeasePeriodOfT_V11_t* v);
parser_error_t _readLookupasStaticLookupSource_V11(parser_context_t* c, pd_LookupasStaticLookupSource_V11_t* v);
parser_error_t _readMemberCount_V11(parser_context_t* c, pd_MemberCount_V11_t* v);
parser_error_t _readMultiSignature_V11(parser_context_t* c, pd_MultiSignature_V11_t* v);
parser_error_t _readMultiSigner_V11(parser_context_t* c, pd_MultiSigner_V11_t* v);
parser_error_t _readNextConfigDescriptor_V11(parser_context_t* c, pd_NextConfigDescriptor_V11_t* v);
parser_error_t _readOpaqueCall_V11(parser_context_t* c, pd_OpaqueCall_V11_t* v);
parser_error_t _readOptionAccountId_V11(parser_context_t* c, pd_OptionAccountId_V11_t* v);
parser_error_t _readOptionElectionScore_V11(parser_context_t* c, pd_OptionElectionScore_V11_t* v);
parser_error_t _readOptionMultiSignature_V11(parser_context_t* c, pd_OptionMultiSignature_V11_t* v);
parser_error_t _readOptionMultiSigner_V11(parser_context_t* c, pd_OptionMultiSigner_V11_t* v);
parser_error_t _readOptionPercent_V11(parser_context_t* c, pd_OptionPercent_V11_t* v);
parser_error_t _readOptionProxyType_V11(parser_context_t* c, pd_OptionProxyType_V11_t* v);
parser_error_t _readOptionReferendumIndex_V11(parser_context_t* c, pd_OptionReferendumIndex_V11_t* v);
parser_error_t _readOptionStatementKind_V11(parser_context_t* c, pd_OptionStatementKind_V11_t* v);
parser_error_t _readOptionTimepoint_V11(parser_context_t* c, pd_OptionTimepoint_V11_t* v);
parser_error_t _readOptionTupleBalanceOfTBalanceOfTBlockNumber_V11(parser_context_t* c, pd_OptionTupleBalanceOfTBalanceOfTBlockNumber_V11_t* v);
parser_error_t _readOptionXcmVersion_V11(parser_context_t* c, pd_OptionXcmVersion_V11_t* v);
parser_error_t _readOptionschedulePeriodBlockNumber_V11(parser_context_t* c, pd_OptionschedulePeriodBlockNumber_V11_t* v);
parser_error_t _readOverweightIndex_V11(parser_context_t* c, pd_OverweightIndex_V11_t* v);
parser_error_t _readParaId_V11(parser_context_t* c, pd_ParaId_V11_t* v);
parser_error_t _readParachainsInherentDataHeader_V11(parser_context_t* c, pd_ParachainsInherentDataHeader_V11_t* v);
parser_error_t _readPerbill_V11(parser_context_t* c, pd_Perbill_V11_t* v);
parser_error_t _readPercent_V11(parser_context_t* c, pd_Percent_V11_t* v);
parser_error_t _readProxyType_V11(parser_context_t* c, pd_ProxyType_V11_t* v);
parser_error_t _readPvfCheckStatement_V11(parser_context_t* c, pd_PvfCheckStatement_V11_t* v);
parser_error_t _readReferendumIndex_V11(parser_context_t* c, pd_ReferendumIndex_V11_t* v);
parser_error_t _readRegistrarIndex_V11(parser_context_t* c, pd_RegistrarIndex_V11_t* v);
parser_error_t _readRenouncing_V11(parser_context_t* c, pd_Renouncing_V11_t* v);
parser_error_t _readRewardDestination_V11(parser_context_t* c, pd_RewardDestination_V11_t* v);
parser_error_t _readSessionIndex_V11(parser_context_t* c, pd_SessionIndex_V11_t* v);
parser_error_t _readSolutionOrSnapshotSize_V11(parser_context_t* c, pd_SolutionOrSnapshotSize_V11_t* v);
parser_error_t _readStatementKind_V11(parser_context_t* c, pd_StatementKind_V11_t* v);
parser_error_t _readSupportsAccountId_V11(parser_context_t* c, pd_SupportsAccountId_V11_t* v);
parser_error_t _readTimepoint_V11(parser_context_t* c, pd_Timepoint_V11_t* v);
parser_error_t _readTupleAccountIdData_V11(parser_context_t* c, pd_TupleAccountIdData_V11_t* v);
parser_error_t _readTupleBalanceOfTBalanceOfTBlockNumber_V11(parser_context_t* c, pd_TupleBalanceOfTBalanceOfTBlockNumber_V11_t* v);
parser_error_t _readValidationCodeHash_V11(parser_context_t* c, pd_ValidationCodeHash_V11_t* v);
parser_error_t _readValidationCode_V11(parser_context_t* c, pd_ValidationCode_V11_t* v);
parser_error_t _readValidatorPrefs_V11(parser_context_t* c, pd_ValidatorPrefs_V11_t* v);
parser_error_t _readValidatorSignature_V11(parser_context_t* c, pd_ValidatorSignature_V11_t* v);
parser_error_t _readVecAccountId_V11(parser_context_t* c, pd_VecAccountId_V11_t* v);
parser_error_t _readVecKeyValue_V11(parser_context_t* c, pd_VecKeyValue_V11_t* v);
parser_error_t _readVecKey_V11(parser_context_t* c, pd_VecKey_V11_t* v);
parser_error_t _readVecLookupasStaticLookupSource_V11(parser_context_t* c, pd_VecLookupasStaticLookupSource_V11_t* v);
parser_error_t _readVecTupleAccountIdData_V11(parser_context_t* c, pd_VecTupleAccountIdData_V11_t* v);
parser_error_t _readVestingInfoBalanceOfTBlockNumber_V11(parser_context_t* c, pd_VestingInfoBalanceOfTBlockNumber_V11_t* v);
parser_error_t _readWeightLimit_V11(parser_context_t* c, pd_WeightLimit_V11_t* v);
parser_error_t _readWeight_V11(parser_context_t* c, pd_Weight_V11_t* v);
parser_error_t _readXcmVersion_V11(parser_context_t* c, pd_XcmVersion_V11_t* v);
parser_error_t _readschedulePeriodBlockNumber_V11(parser_context_t* c, pd_schedulePeriodBlockNumber_V11_t* v);
parser_error_t _readschedulePriority_V11(parser_context_t* c, pd_schedulePriority_V11_t* v);

// toString functions
parser_error_t _toStringAccountId_V11(
    const pd_AccountId_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountIndex_V11(
    const pd_AccountIndex_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountVoteBalanceOf_V11(
    const pd_AccountVoteBalanceOf_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAuthorityIdasRuntimeAppPublicSignature_V11(
    const pd_AuthorityIdasRuntimeAppPublicSignature_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxCallOrHashOfT_V11(
    const pd_BoxCallOrHashOfT_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxEquivocationProofHashBlockNumber_V11(
    const pd_BoxEquivocationProofHashBlockNumber_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxEquivocationProofHeader_V11(
    const pd_BoxEquivocationProofHeader_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxIdentityInfoMaxAdditionalFields_V11(
    const pd_BoxIdentityInfoMaxAdditionalFields_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxMultiLocation_V11(
    const pd_BoxMultiLocation_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxPalletsOrigin_V11(
    const pd_BoxPalletsOrigin_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxRawSolutionSolutionOfT_V11(
    const pd_BoxRawSolutionSolutionOfT_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxTasConfigIProposal_V11(
    const pd_BoxTasConfigIProposal_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxVersionedMultiAssets_V11(
    const pd_BoxVersionedMultiAssets_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxVersionedMultiLocation_V11(
    const pd_BoxVersionedMultiLocation_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxVersionedXcmTasSysConfigCall_V11(
    const pd_BoxVersionedXcmTasSysConfigCall_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxVersionedXcmTuple_V11(
    const pd_BoxVersionedXcmTuple_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCallHashOf_V11(
    const pd_CallHashOf_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactAccountIndex_V11(
    const pd_CompactAccountIndex_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactPerBill_V11(
    const pd_CompactPerBill_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringConviction_V11(
    const pd_Conviction_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEcdsaSignature_V11(
    const pd_EcdsaSignature_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringElectionScore_V11(
    const pd_ElectionScore_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEraIndex_V11(
    const pd_EraIndex_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEthereumAddress_V11(
    const pd_EthereumAddress_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringHeadData_V11(
    const pd_HeadData_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringHeartbeatBlockNumber_V11(
    const pd_HeartbeatBlockNumber_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringHrmpChannelId_V11(
    const pd_HrmpChannelId_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringIdentityFields_V11(
    const pd_IdentityFields_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJudgementBalanceOfT_V11(
    const pd_JudgementBalanceOfT_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKeyOwnerProof_V11(
    const pd_KeyOwnerProof_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKeyValue_V11(
    const pd_KeyValue_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKey_V11(
    const pd_Key_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKeys_V11(
    const pd_Keys_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringLeasePeriodOfT_V11(
    const pd_LeasePeriodOfT_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringLookupasStaticLookupSource_V11(
    const pd_LookupasStaticLookupSource_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMemberCount_V11(
    const pd_MemberCount_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMultiSignature_V11(
    const pd_MultiSignature_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMultiSigner_V11(
    const pd_MultiSigner_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringNextConfigDescriptor_V11(
    const pd_NextConfigDescriptor_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOpaqueCall_V11(
    const pd_OpaqueCall_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionAccountId_V11(
    const pd_OptionAccountId_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionElectionScore_V11(
    const pd_OptionElectionScore_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionMultiSignature_V11(
    const pd_OptionMultiSignature_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionMultiSigner_V11(
    const pd_OptionMultiSigner_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionPercent_V11(
    const pd_OptionPercent_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionProxyType_V11(
    const pd_OptionProxyType_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionReferendumIndex_V11(
    const pd_OptionReferendumIndex_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionStatementKind_V11(
    const pd_OptionStatementKind_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionTimepoint_V11(
    const pd_OptionTimepoint_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionTupleBalanceOfTBalanceOfTBlockNumber_V11(
    const pd_OptionTupleBalanceOfTBalanceOfTBlockNumber_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionXcmVersion_V11(
    const pd_OptionXcmVersion_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionschedulePeriodBlockNumber_V11(
    const pd_OptionschedulePeriodBlockNumber_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOverweightIndex_V11(
    const pd_OverweightIndex_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringParaId_V11(
    const pd_ParaId_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringParachainsInherentDataHeader_V11(
    const pd_ParachainsInherentDataHeader_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPerbill_V11(
    const pd_Perbill_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPercent_V11(
    const pd_Percent_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringProxyType_V11(
    const pd_ProxyType_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPvfCheckStatement_V11(
    const pd_PvfCheckStatement_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringReferendumIndex_V11(
    const pd_ReferendumIndex_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringRegistrarIndex_V11(
    const pd_RegistrarIndex_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringRenouncing_V11(
    const pd_Renouncing_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringRewardDestination_V11(
    const pd_RewardDestination_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSessionIndex_V11(
    const pd_SessionIndex_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSolutionOrSnapshotSize_V11(
    const pd_SolutionOrSnapshotSize_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringStatementKind_V11(
    const pd_StatementKind_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSupportsAccountId_V11(
    const pd_SupportsAccountId_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTimepoint_V11(
    const pd_Timepoint_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTupleAccountIdData_V11(
    const pd_TupleAccountIdData_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTupleBalanceOfTBalanceOfTBlockNumber_V11(
    const pd_TupleBalanceOfTBalanceOfTBlockNumber_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringValidationCodeHash_V11(
    const pd_ValidationCodeHash_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringValidationCode_V11(
    const pd_ValidationCode_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringValidatorPrefs_V11(
    const pd_ValidatorPrefs_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringValidatorSignature_V11(
    const pd_ValidatorSignature_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecAccountId_V11(
    const pd_VecAccountId_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecKeyValue_V11(
    const pd_VecKeyValue_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecKey_V11(
    const pd_VecKey_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecLookupasStaticLookupSource_V11(
    const pd_VecLookupasStaticLookupSource_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecTupleAccountIdData_V11(
    const pd_VecTupleAccountIdData_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVestingInfoBalanceOfTBlockNumber_V11(
    const pd_VestingInfoBalanceOfTBlockNumber_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringWeightLimit_V11(
    const pd_WeightLimit_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringWeight_V11(
    const pd_Weight_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringXcmVersion_V11(
    const pd_XcmVersion_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringschedulePeriodBlockNumber_V11(
    const pd_schedulePeriodBlockNumber_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringschedulePriority_V11(
    const pd_schedulePriority_V11_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

#ifdef __cplusplus
}
#endif
