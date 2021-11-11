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
#include "substrate_methods_V8.h"
#include "substrate_types_V8.h"
#include <stddef.h>
#include <stdint.h>

// Read functions
parser_error_t _readAccountId_V8(parser_context_t* c, pd_AccountId_V8_t* v);
parser_error_t _readAccountIndex_V8(parser_context_t* c, pd_AccountIndex_V8_t* v);
parser_error_t _readAccountVoteBalanceOfT_V8(parser_context_t* c, pd_AccountVoteBalanceOfT_V8_t* v);
parser_error_t _readAuthorityIdasRuntimeAppPublicSignature_V8(parser_context_t* c, pd_AuthorityIdasRuntimeAppPublicSignature_V8_t* v);
parser_error_t _readBoxEquivocationProofHashBlockNumber_V8(parser_context_t* c, pd_BoxEquivocationProofHashBlockNumber_V8_t* v);
parser_error_t _readBoxEquivocationProofHeader_V8(parser_context_t* c, pd_BoxEquivocationProofHeader_V8_t* v);
parser_error_t _readBoxIdentityInfoMaxAdditionalFields_V8(parser_context_t* c, pd_BoxIdentityInfoMaxAdditionalFields_V8_t* v);
parser_error_t _readBoxRawSolutionSolutionOfT_V8(parser_context_t* c, pd_BoxRawSolutionSolutionOfT_V8_t* v);
parser_error_t _readBoxTasConfigIProposal_V8(parser_context_t* c, pd_BoxTasConfigIProposal_V8_t* v);
parser_error_t _readCallHashOfT_V8(parser_context_t* c, pd_CallHashOfT_V8_t* v);
parser_error_t _readChangesTrieConfiguration_V8(parser_context_t* c, pd_ChangesTrieConfiguration_V8_t* v);
parser_error_t _readCompactAccountIndex_V8(parser_context_t* c, pd_CompactAccountIndex_V8_t* v);
parser_error_t _readCompactPerBill_V8(parser_context_t* c, pd_CompactPerBill_V8_t* v);
parser_error_t _readConviction_V8(parser_context_t* c, pd_Conviction_V8_t* v);
parser_error_t _readEcdsaSignature_V8(parser_context_t* c, pd_EcdsaSignature_V8_t* v);
parser_error_t _readElectionScore_V8(parser_context_t* c, pd_ElectionScore_V8_t* v);
parser_error_t _readEraIndex_V8(parser_context_t* c, pd_EraIndex_V8_t* v);
parser_error_t _readEthereumAddress_V8(parser_context_t* c, pd_EthereumAddress_V8_t* v);
parser_error_t _readHeadData_V8(parser_context_t* c, pd_HeadData_V8_t* v);
parser_error_t _readHeartbeatBlockNumber_V8(parser_context_t* c, pd_HeartbeatBlockNumber_V8_t* v);
parser_error_t _readHrmpChannelId_V8(parser_context_t* c, pd_HrmpChannelId_V8_t* v);
parser_error_t _readIdentityFields_V8(parser_context_t* c, pd_IdentityFields_V8_t* v);
parser_error_t _readJudgementBalanceOfT_V8(parser_context_t* c, pd_JudgementBalanceOfT_V8_t* v);
parser_error_t _readKeyOwnerProof_V8(parser_context_t* c, pd_KeyOwnerProof_V8_t* v);
parser_error_t _readKeyValue_V8(parser_context_t* c, pd_KeyValue_V8_t* v);
parser_error_t _readKey_V8(parser_context_t* c, pd_Key_V8_t* v);
parser_error_t _readKeys_V8(parser_context_t* c, pd_Keys_V8_t* v);
parser_error_t _readLeasePeriodOfT_V8(parser_context_t* c, pd_LeasePeriodOfT_V8_t* v);
parser_error_t _readLookupasStaticLookupSource_V8(parser_context_t* c, pd_LookupasStaticLookupSource_V8_t* v);
parser_error_t _readMemberCount_V8(parser_context_t* c, pd_MemberCount_V8_t* v);
parser_error_t _readMultiSignature_V8(parser_context_t* c, pd_MultiSignature_V8_t* v);
parser_error_t _readMultiSigner_V8(parser_context_t* c, pd_MultiSigner_V8_t* v);
parser_error_t _readNextConfigDescriptor_V8(parser_context_t* c, pd_NextConfigDescriptor_V8_t* v);
parser_error_t _readOpaqueCall_V8(parser_context_t* c, pd_OpaqueCall_V8_t* v);
parser_error_t _readOptionAccountId_V8(parser_context_t* c, pd_OptionAccountId_V8_t* v);
parser_error_t _readOptionChangesTrieConfiguration_V8(parser_context_t* c, pd_OptionChangesTrieConfiguration_V8_t* v);
parser_error_t _readOptionElectionScore_V8(parser_context_t* c, pd_OptionElectionScore_V8_t* v);
parser_error_t _readOptionMultiSignature_V8(parser_context_t* c, pd_OptionMultiSignature_V8_t* v);
parser_error_t _readOptionMultiSigner_V8(parser_context_t* c, pd_OptionMultiSigner_V8_t* v);
parser_error_t _readOptionPercent_V8(parser_context_t* c, pd_OptionPercent_V8_t* v);
parser_error_t _readOptionProxyType_V8(parser_context_t* c, pd_OptionProxyType_V8_t* v);
parser_error_t _readOptionReferendumIndex_V8(parser_context_t* c, pd_OptionReferendumIndex_V8_t* v);
parser_error_t _readOptionStatementKind_V8(parser_context_t* c, pd_OptionStatementKind_V8_t* v);
parser_error_t _readOptionTimepoint_V8(parser_context_t* c, pd_OptionTimepoint_V8_t* v);
parser_error_t _readOptionTupleBalanceOfTBalanceOfTBlockNumber_V8(parser_context_t* c, pd_OptionTupleBalanceOfTBalanceOfTBlockNumber_V8_t* v);
parser_error_t _readOptionschedulePeriodBlockNumber_V8(parser_context_t* c, pd_OptionschedulePeriodBlockNumber_V8_t* v);
parser_error_t _readOverweightIndex_V8(parser_context_t* c, pd_OverweightIndex_V8_t* v);
parser_error_t _readParaId_V8(parser_context_t* c, pd_ParaId_V8_t* v);
parser_error_t _readParachainsInherentDataHeader_V8(parser_context_t* c, pd_ParachainsInherentDataHeader_V8_t* v);
parser_error_t _readPerbill_V8(parser_context_t* c, pd_Perbill_V8_t* v);
parser_error_t _readPercent_V8(parser_context_t* c, pd_Percent_V8_t* v);
parser_error_t _readProxyType_V8(parser_context_t* c, pd_ProxyType_V8_t* v);
parser_error_t _readReferendumIndex_V8(parser_context_t* c, pd_ReferendumIndex_V8_t* v);
parser_error_t _readRegistrarIndex_V8(parser_context_t* c, pd_RegistrarIndex_V8_t* v);
parser_error_t _readRenouncing_V8(parser_context_t* c, pd_Renouncing_V8_t* v);
parser_error_t _readRewardDestination_V8(parser_context_t* c, pd_RewardDestination_V8_t* v);
parser_error_t _readSessionIndex_V8(parser_context_t* c, pd_SessionIndex_V8_t* v);
parser_error_t _readSolutionOrSnapshotSize_V8(parser_context_t* c, pd_SolutionOrSnapshotSize_V8_t* v);
parser_error_t _readStatementKind_V8(parser_context_t* c, pd_StatementKind_V8_t* v);
parser_error_t _readSupportsAccountId_V8(parser_context_t* c, pd_SupportsAccountId_V8_t* v);
parser_error_t _readTimepoint_V8(parser_context_t* c, pd_Timepoint_V8_t* v);
parser_error_t _readTupleAccountIdData_V8(parser_context_t* c, pd_TupleAccountIdData_V8_t* v);
parser_error_t _readTupleBalanceOfTBalanceOfTBlockNumber_V8(parser_context_t* c, pd_TupleBalanceOfTBalanceOfTBlockNumber_V8_t* v);
parser_error_t _readValidationCode_V8(parser_context_t* c, pd_ValidationCode_V8_t* v);
parser_error_t _readValidatorPrefs_V8(parser_context_t* c, pd_ValidatorPrefs_V8_t* v);
parser_error_t _readVecAccountId_V8(parser_context_t* c, pd_VecAccountId_V8_t* v);
parser_error_t _readVecKeyValue_V8(parser_context_t* c, pd_VecKeyValue_V8_t* v);
parser_error_t _readVecKey_V8(parser_context_t* c, pd_VecKey_V8_t* v);
parser_error_t _readVecLookupasStaticLookupSource_V8(parser_context_t* c, pd_VecLookupasStaticLookupSource_V8_t* v);
parser_error_t _readVecTupleAccountIdData_V8(parser_context_t* c, pd_VecTupleAccountIdData_V8_t* v);
parser_error_t _readVestingInfoBalanceOfTBlockNumber_V8(parser_context_t* c, pd_VestingInfoBalanceOfTBlockNumber_V8_t* v);
parser_error_t _readWeight_V8(parser_context_t* c, pd_Weight_V8_t* v);
parser_error_t _readschedulePeriodBlockNumber_V8(parser_context_t* c, pd_schedulePeriodBlockNumber_V8_t* v);
parser_error_t _readschedulePriority_V8(parser_context_t* c, pd_schedulePriority_V8_t* v);

// toString functions
parser_error_t _toStringAccountId_V8(
    const pd_AccountId_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountIndex_V8(
    const pd_AccountIndex_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountVoteBalanceOfT_V8(
    const pd_AccountVoteBalanceOfT_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAuthorityIdasRuntimeAppPublicSignature_V8(
    const pd_AuthorityIdasRuntimeAppPublicSignature_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxEquivocationProofHashBlockNumber_V8(
    const pd_BoxEquivocationProofHashBlockNumber_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxEquivocationProofHeader_V8(
    const pd_BoxEquivocationProofHeader_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxIdentityInfoMaxAdditionalFields_V8(
    const pd_BoxIdentityInfoMaxAdditionalFields_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxRawSolutionSolutionOfT_V8(
    const pd_BoxRawSolutionSolutionOfT_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxTasConfigIProposal_V8(
    const pd_BoxTasConfigIProposal_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCallHashOfT_V8(
    const pd_CallHashOfT_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringChangesTrieConfiguration_V8(
    const pd_ChangesTrieConfiguration_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactAccountIndex_V8(
    const pd_CompactAccountIndex_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactPerBill_V8(
    const pd_CompactPerBill_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringConviction_V8(
    const pd_Conviction_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEcdsaSignature_V8(
    const pd_EcdsaSignature_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringElectionScore_V8(
    const pd_ElectionScore_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEraIndex_V8(
    const pd_EraIndex_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEthereumAddress_V8(
    const pd_EthereumAddress_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringHeadData_V8(
    const pd_HeadData_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringHeartbeatBlockNumber_V8(
    const pd_HeartbeatBlockNumber_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringHrmpChannelId_V8(
    const pd_HrmpChannelId_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringIdentityFields_V8(
    const pd_IdentityFields_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJudgementBalanceOfT_V8(
    const pd_JudgementBalanceOfT_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKeyOwnerProof_V8(
    const pd_KeyOwnerProof_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKeyValue_V8(
    const pd_KeyValue_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKey_V8(
    const pd_Key_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKeys_V8(
    const pd_Keys_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringLeasePeriodOfT_V8(
    const pd_LeasePeriodOfT_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringLookupasStaticLookupSource_V8(
    const pd_LookupasStaticLookupSource_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMemberCount_V8(
    const pd_MemberCount_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMultiSignature_V8(
    const pd_MultiSignature_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMultiSigner_V8(
    const pd_MultiSigner_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringNextConfigDescriptor_V8(
    const pd_NextConfigDescriptor_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOpaqueCall_V8(
    const pd_OpaqueCall_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionAccountId_V8(
    const pd_OptionAccountId_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionChangesTrieConfiguration_V8(
    const pd_OptionChangesTrieConfiguration_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionElectionScore_V8(
    const pd_OptionElectionScore_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionMultiSignature_V8(
    const pd_OptionMultiSignature_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionMultiSigner_V8(
    const pd_OptionMultiSigner_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionPercent_V8(
    const pd_OptionPercent_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionProxyType_V8(
    const pd_OptionProxyType_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionReferendumIndex_V8(
    const pd_OptionReferendumIndex_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionStatementKind_V8(
    const pd_OptionStatementKind_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionTimepoint_V8(
    const pd_OptionTimepoint_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionTupleBalanceOfTBalanceOfTBlockNumber_V8(
    const pd_OptionTupleBalanceOfTBalanceOfTBlockNumber_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionschedulePeriodBlockNumber_V8(
    const pd_OptionschedulePeriodBlockNumber_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOverweightIndex_V8(
    const pd_OverweightIndex_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringParaId_V8(
    const pd_ParaId_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringParachainsInherentDataHeader_V8(
    const pd_ParachainsInherentDataHeader_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPerbill_V8(
    const pd_Perbill_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPercent_V8(
    const pd_Percent_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringProxyType_V8(
    const pd_ProxyType_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringReferendumIndex_V8(
    const pd_ReferendumIndex_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringRegistrarIndex_V8(
    const pd_RegistrarIndex_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringRenouncing_V8(
    const pd_Renouncing_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringRewardDestination_V8(
    const pd_RewardDestination_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSessionIndex_V8(
    const pd_SessionIndex_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSolutionOrSnapshotSize_V8(
    const pd_SolutionOrSnapshotSize_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringStatementKind_V8(
    const pd_StatementKind_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSupportsAccountId_V8(
    const pd_SupportsAccountId_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTimepoint_V8(
    const pd_Timepoint_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTupleAccountIdData_V8(
    const pd_TupleAccountIdData_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTupleBalanceOfTBalanceOfTBlockNumber_V8(
    const pd_TupleBalanceOfTBalanceOfTBlockNumber_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringValidationCode_V8(
    const pd_ValidationCode_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringValidatorPrefs_V8(
    const pd_ValidatorPrefs_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecAccountId_V8(
    const pd_VecAccountId_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecKeyValue_V8(
    const pd_VecKeyValue_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecKey_V8(
    const pd_VecKey_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecLookupasStaticLookupSource_V8(
    const pd_VecLookupasStaticLookupSource_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecTupleAccountIdData_V8(
    const pd_VecTupleAccountIdData_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVestingInfoBalanceOfTBlockNumber_V8(
    const pd_VestingInfoBalanceOfTBlockNumber_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringWeight_V8(
    const pd_Weight_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringschedulePeriodBlockNumber_V8(
    const pd_schedulePeriodBlockNumber_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringschedulePriority_V8(
    const pd_schedulePriority_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

#ifdef __cplusplus
}
#endif
