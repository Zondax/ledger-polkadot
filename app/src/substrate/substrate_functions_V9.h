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
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "parser_common.h"
#include "substrate_methods_V9.h"
#include "substrate_types_V9.h"
#include <stddef.h>
#include <stdint.h>

// Read functions
parser_error_t _readAccountId_V9(parser_context_t* c, pd_AccountId_V9_t* v);
parser_error_t _readAccountIndex_V9(parser_context_t* c, pd_AccountIndex_V9_t* v);
parser_error_t _readAccountVoteBalanceOf_V9(parser_context_t* c, pd_AccountVoteBalanceOf_V9_t* v);
parser_error_t _readAuthorityIdasRuntimeAppPublicSignature_V9(parser_context_t* c, pd_AuthorityIdasRuntimeAppPublicSignature_V9_t* v);
parser_error_t _readBoxEquivocationProofHashBlockNumber_V9(parser_context_t* c, pd_BoxEquivocationProofHashBlockNumber_V9_t* v);
parser_error_t _readBoxEquivocationProofHeader_V9(parser_context_t* c, pd_BoxEquivocationProofHeader_V9_t* v);
parser_error_t _readBoxIdentityInfoMaxAdditionalFields_V9(parser_context_t* c, pd_BoxIdentityInfoMaxAdditionalFields_V9_t* v);
parser_error_t _readBoxMultiLocation_V9(parser_context_t* c, pd_BoxMultiLocation_V9_t* v);
parser_error_t _readBoxPalletsOrigin_V9(parser_context_t* c, pd_BoxPalletsOrigin_V9_t* v);
parser_error_t _readBoxRawSolutionSolutionOfT_V9(parser_context_t* c, pd_BoxRawSolutionSolutionOfT_V9_t* v);
parser_error_t _readBoxTasConfigIProposal_V9(parser_context_t* c, pd_BoxTasConfigIProposal_V9_t* v);
parser_error_t _readBoxVersionedMultiAssets_V9(parser_context_t* c, pd_BoxVersionedMultiAssets_V9_t* v);
parser_error_t _readBoxVersionedMultiLocation_V9(parser_context_t* c, pd_BoxVersionedMultiLocation_V9_t* v);
parser_error_t _readBoxVersionedXcmTasSysConfigCall_V9(parser_context_t* c, pd_BoxVersionedXcmTasSysConfigCall_V9_t* v);
parser_error_t _readBoxVersionedXcmTuple_V9(parser_context_t* c, pd_BoxVersionedXcmTuple_V9_t* v);
parser_error_t _readCallHashOf_V9(parser_context_t* c, pd_CallHashOf_V9_t* v);
parser_error_t _readCompactAccountIndex_V9(parser_context_t* c, pd_CompactAccountIndex_V9_t* v);
parser_error_t _readCompactPerBill_V9(parser_context_t* c, pd_CompactPerBill_V9_t* v);
parser_error_t _readConviction_V9(parser_context_t* c, pd_Conviction_V9_t* v);
parser_error_t _readEcdsaSignature_V9(parser_context_t* c, pd_EcdsaSignature_V9_t* v);
parser_error_t _readElectionScore_V9(parser_context_t* c, pd_ElectionScore_V9_t* v);
parser_error_t _readEraIndex_V9(parser_context_t* c, pd_EraIndex_V9_t* v);
parser_error_t _readEthereumAddress_V9(parser_context_t* c, pd_EthereumAddress_V9_t* v);
parser_error_t _readHeadData_V9(parser_context_t* c, pd_HeadData_V9_t* v);
parser_error_t _readHeartbeatBlockNumber_V9(parser_context_t* c, pd_HeartbeatBlockNumber_V9_t* v);
parser_error_t _readHrmpChannelId_V9(parser_context_t* c, pd_HrmpChannelId_V9_t* v);
parser_error_t _readIdentityFields_V9(parser_context_t* c, pd_IdentityFields_V9_t* v);
parser_error_t _readJudgementBalanceOfT_V9(parser_context_t* c, pd_JudgementBalanceOfT_V9_t* v);
parser_error_t _readKeyOwnerProof_V9(parser_context_t* c, pd_KeyOwnerProof_V9_t* v);
parser_error_t _readKeyValue_V9(parser_context_t* c, pd_KeyValue_V9_t* v);
parser_error_t _readKey_V9(parser_context_t* c, pd_Key_V9_t* v);
parser_error_t _readKeys_V9(parser_context_t* c, pd_Keys_V9_t* v);
parser_error_t _readLeasePeriodOfT_V9(parser_context_t* c, pd_LeasePeriodOfT_V9_t* v);
parser_error_t _readLookupasStaticLookupSource_V9(parser_context_t* c, pd_LookupasStaticLookupSource_V9_t* v);
parser_error_t _readMemberCount_V9(parser_context_t* c, pd_MemberCount_V9_t* v);
parser_error_t _readMultiSignature_V9(parser_context_t* c, pd_MultiSignature_V9_t* v);
parser_error_t _readMultiSigner_V9(parser_context_t* c, pd_MultiSigner_V9_t* v);
parser_error_t _readNextConfigDescriptor_V9(parser_context_t* c, pd_NextConfigDescriptor_V9_t* v);
parser_error_t _readOpaqueCallT_V9(parser_context_t* c, pd_OpaqueCallT_V9_t* v);
parser_error_t _readOptionAccountId_V9(parser_context_t* c, pd_OptionAccountId_V9_t* v);
parser_error_t _readOptionElectionScore_V9(parser_context_t* c, pd_OptionElectionScore_V9_t* v);
parser_error_t _readOptionMultiSignature_V9(parser_context_t* c, pd_OptionMultiSignature_V9_t* v);
parser_error_t _readOptionMultiSigner_V9(parser_context_t* c, pd_OptionMultiSigner_V9_t* v);
parser_error_t _readOptionPercent_V9(parser_context_t* c, pd_OptionPercent_V9_t* v);
parser_error_t _readOptionProxyType_V9(parser_context_t* c, pd_OptionProxyType_V9_t* v);
parser_error_t _readOptionReferendumIndex_V9(parser_context_t* c, pd_OptionReferendumIndex_V9_t* v);
parser_error_t _readOptionStatementKind_V9(parser_context_t* c, pd_OptionStatementKind_V9_t* v);
parser_error_t _readOptionTimepoint_V9(parser_context_t* c, pd_OptionTimepoint_V9_t* v);
parser_error_t _readOptionTupleBalanceOfTBalanceOfTBlockNumber_V9(parser_context_t* c, pd_OptionTupleBalanceOfTBalanceOfTBlockNumber_V9_t* v);
parser_error_t _readOptionXcmVersion_V9(parser_context_t* c, pd_OptionXcmVersion_V9_t* v);
parser_error_t _readOptionschedulePeriodBlockNumber_V9(parser_context_t* c, pd_OptionschedulePeriodBlockNumber_V9_t* v);
parser_error_t _readOverweightIndex_V9(parser_context_t* c, pd_OverweightIndex_V9_t* v);
parser_error_t _readParaId_V9(parser_context_t* c, pd_ParaId_V9_t* v);
parser_error_t _readParachainsInherentDataHeader_V9(parser_context_t* c, pd_ParachainsInherentDataHeader_V9_t* v);
parser_error_t _readPerbill_V9(parser_context_t* c, pd_Perbill_V9_t* v);
parser_error_t _readPercent_V9(parser_context_t* c, pd_Percent_V9_t* v);
parser_error_t _readProxyType_V9(parser_context_t* c, pd_ProxyType_V9_t* v);
parser_error_t _readReferendumIndex_V9(parser_context_t* c, pd_ReferendumIndex_V9_t* v);
parser_error_t _readRegistrarIndex_V9(parser_context_t* c, pd_RegistrarIndex_V9_t* v);
parser_error_t _readRenouncing_V9(parser_context_t* c, pd_Renouncing_V9_t* v);
parser_error_t _readRewardDestination_V9(parser_context_t* c, pd_RewardDestination_V9_t* v);
parser_error_t _readSessionIndex_V9(parser_context_t* c, pd_SessionIndex_V9_t* v);
parser_error_t _readSolutionOrSnapshotSize_V9(parser_context_t* c, pd_SolutionOrSnapshotSize_V9_t* v);
parser_error_t _readStatementKind_V9(parser_context_t* c, pd_StatementKind_V9_t* v);
parser_error_t _readSupportsAccountId_V9(parser_context_t* c, pd_SupportsAccountId_V9_t* v);
parser_error_t _readTimepoint_V9(parser_context_t* c, pd_Timepoint_V9_t* v);
parser_error_t _readTupleAccountIdData_V9(parser_context_t* c, pd_TupleAccountIdData_V9_t* v);
parser_error_t _readTupleBalanceOfTBalanceOfTBlockNumber_V9(parser_context_t* c, pd_TupleBalanceOfTBalanceOfTBlockNumber_V9_t* v);
parser_error_t _readValidationCode_V9(parser_context_t* c, pd_ValidationCode_V9_t* v);
parser_error_t _readValidatorPrefs_V9(parser_context_t* c, pd_ValidatorPrefs_V9_t* v);
parser_error_t _readVecAccountId_V9(parser_context_t* c, pd_VecAccountId_V9_t* v);
parser_error_t _readVecKeyValue_V9(parser_context_t* c, pd_VecKeyValue_V9_t* v);
parser_error_t _readVecKey_V9(parser_context_t* c, pd_VecKey_V9_t* v);
parser_error_t _readVecLookupasStaticLookupSource_V9(parser_context_t* c, pd_VecLookupasStaticLookupSource_V9_t* v);
parser_error_t _readVecTupleAccountIdData_V9(parser_context_t* c, pd_VecTupleAccountIdData_V9_t* v);
parser_error_t _readVestingInfoBalanceOfTBlockNumber_V9(parser_context_t* c, pd_VestingInfoBalanceOfTBlockNumber_V9_t* v);
parser_error_t _readWeightLimit_V9(parser_context_t* c, pd_WeightLimit_V9_t* v);
parser_error_t _readWeight_V9(parser_context_t* c, pd_Weight_V9_t* v);
parser_error_t _readXcmVersion_V9(parser_context_t* c, pd_XcmVersion_V9_t* v);
parser_error_t _readschedulePeriodBlockNumber_V9(parser_context_t* c, pd_schedulePeriodBlockNumber_V9_t* v);
parser_error_t _readschedulePriority_V9(parser_context_t* c, pd_schedulePriority_V9_t* v);

// toString functions
parser_error_t _toStringAccountId_V9(
    const pd_AccountId_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountIndex_V9(
    const pd_AccountIndex_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountVoteBalanceOf_V9(
    const pd_AccountVoteBalanceOf_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAuthorityIdasRuntimeAppPublicSignature_V9(
    const pd_AuthorityIdasRuntimeAppPublicSignature_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxEquivocationProofHashBlockNumber_V9(
    const pd_BoxEquivocationProofHashBlockNumber_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxEquivocationProofHeader_V9(
    const pd_BoxEquivocationProofHeader_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxIdentityInfoMaxAdditionalFields_V9(
    const pd_BoxIdentityInfoMaxAdditionalFields_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxMultiLocation_V9(
    const pd_BoxMultiLocation_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxPalletsOrigin_V9(
    const pd_BoxPalletsOrigin_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxRawSolutionSolutionOfT_V9(
    const pd_BoxRawSolutionSolutionOfT_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxTasConfigIProposal_V9(
    const pd_BoxTasConfigIProposal_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxVersionedMultiAssets_V9(
    const pd_BoxVersionedMultiAssets_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxVersionedMultiLocation_V9(
    const pd_BoxVersionedMultiLocation_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxVersionedXcmTasSysConfigCall_V9(
    const pd_BoxVersionedXcmTasSysConfigCall_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxVersionedXcmTuple_V9(
    const pd_BoxVersionedXcmTuple_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCallHashOf_V9(
    const pd_CallHashOf_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactAccountIndex_V9(
    const pd_CompactAccountIndex_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactPerBill_V9(
    const pd_CompactPerBill_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringConviction_V9(
    const pd_Conviction_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEcdsaSignature_V9(
    const pd_EcdsaSignature_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringElectionScore_V9(
    const pd_ElectionScore_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEraIndex_V9(
    const pd_EraIndex_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEthereumAddress_V9(
    const pd_EthereumAddress_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringHeadData_V9(
    const pd_HeadData_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringHeartbeatBlockNumber_V9(
    const pd_HeartbeatBlockNumber_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringHrmpChannelId_V9(
    const pd_HrmpChannelId_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringIdentityFields_V9(
    const pd_IdentityFields_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJudgementBalanceOfT_V9(
    const pd_JudgementBalanceOfT_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKeyOwnerProof_V9(
    const pd_KeyOwnerProof_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKeyValue_V9(
    const pd_KeyValue_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKey_V9(
    const pd_Key_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKeys_V9(
    const pd_Keys_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringLeasePeriodOfT_V9(
    const pd_LeasePeriodOfT_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringLookupasStaticLookupSource_V9(
    const pd_LookupasStaticLookupSource_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMemberCount_V9(
    const pd_MemberCount_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMultiSignature_V9(
    const pd_MultiSignature_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMultiSigner_V9(
    const pd_MultiSigner_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringNextConfigDescriptor_V9(
    const pd_NextConfigDescriptor_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOpaqueCallT_V9(
    const pd_OpaqueCallT_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionAccountId_V9(
    const pd_OptionAccountId_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionElectionScore_V9(
    const pd_OptionElectionScore_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionMultiSignature_V9(
    const pd_OptionMultiSignature_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionMultiSigner_V9(
    const pd_OptionMultiSigner_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionPercent_V9(
    const pd_OptionPercent_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionProxyType_V9(
    const pd_OptionProxyType_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionReferendumIndex_V9(
    const pd_OptionReferendumIndex_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionStatementKind_V9(
    const pd_OptionStatementKind_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionTimepoint_V9(
    const pd_OptionTimepoint_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionTupleBalanceOfTBalanceOfTBlockNumber_V9(
    const pd_OptionTupleBalanceOfTBalanceOfTBlockNumber_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionXcmVersion_V9(
    const pd_OptionXcmVersion_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionschedulePeriodBlockNumber_V9(
    const pd_OptionschedulePeriodBlockNumber_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOverweightIndex_V9(
    const pd_OverweightIndex_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringParaId_V9(
    const pd_ParaId_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringParachainsInherentDataHeader_V9(
    const pd_ParachainsInherentDataHeader_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPerbill_V9(
    const pd_Perbill_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPercent_V9(
    const pd_Percent_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringProxyType_V9(
    const pd_ProxyType_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringReferendumIndex_V9(
    const pd_ReferendumIndex_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringRegistrarIndex_V9(
    const pd_RegistrarIndex_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringRenouncing_V9(
    const pd_Renouncing_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringRewardDestination_V9(
    const pd_RewardDestination_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSessionIndex_V9(
    const pd_SessionIndex_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSolutionOrSnapshotSize_V9(
    const pd_SolutionOrSnapshotSize_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringStatementKind_V9(
    const pd_StatementKind_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSupportsAccountId_V9(
    const pd_SupportsAccountId_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTimepoint_V9(
    const pd_Timepoint_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTupleAccountIdData_V9(
    const pd_TupleAccountIdData_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTupleBalanceOfTBalanceOfTBlockNumber_V9(
    const pd_TupleBalanceOfTBalanceOfTBlockNumber_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringValidationCode_V9(
    const pd_ValidationCode_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringValidatorPrefs_V9(
    const pd_ValidatorPrefs_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecAccountId_V9(
    const pd_VecAccountId_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecKeyValue_V9(
    const pd_VecKeyValue_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecKey_V9(
    const pd_VecKey_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecLookupasStaticLookupSource_V9(
    const pd_VecLookupasStaticLookupSource_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecTupleAccountIdData_V9(
    const pd_VecTupleAccountIdData_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVestingInfoBalanceOfTBlockNumber_V9(
    const pd_VestingInfoBalanceOfTBlockNumber_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringWeightLimit_V9(
    const pd_WeightLimit_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringWeight_V9(
    const pd_Weight_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringXcmVersion_V9(
    const pd_XcmVersion_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringschedulePeriodBlockNumber_V9(
    const pd_schedulePeriodBlockNumber_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringschedulePriority_V9(
    const pd_schedulePriority_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

#ifdef __cplusplus
}
#endif
