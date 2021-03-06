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
#include "substrate_methods_V7.h"
#include "substrate_types_V7.h"
#include <stddef.h>
#include <stdint.h>

// Read functions
parser_error_t _readAccountId_V7(parser_context_t* c, pd_AccountId_V7_t* v);
parser_error_t _readAccountIndex_V7(parser_context_t* c, pd_AccountIndex_V7_t* v);
parser_error_t _readAccountVoteSplit_V7(parser_context_t* c, pd_AccountVoteSplit_V7_t* v);
parser_error_t _readAccountVoteStandard_V7(parser_context_t* c, pd_AccountVoteStandard_V7_t* v);
parser_error_t _readAccountVote_V7(parser_context_t* c, pd_AccountVote_V7_t* v);
parser_error_t _readBabeEquivocationProof_V7(parser_context_t* c, pd_BabeEquivocationProof_V7_t* v);
parser_error_t _readCallHashOf_V7(parser_context_t* c, pd_CallHashOf_V7_t* v);
parser_error_t _readChangesTrieConfiguration_V7(parser_context_t* c, pd_ChangesTrieConfiguration_V7_t* v);
parser_error_t _readCompactAccountIndex_V7(parser_context_t* c, pd_CompactAccountIndex_V7_t* v);
parser_error_t _readCompactBountyIndex_V7(parser_context_t* c, pd_CompactBountyIndex_V7_t* v);
parser_error_t _readCompactEraIndex_V7(parser_context_t* c, pd_CompactEraIndex_V7_t* v);
parser_error_t _readCompactMemberCount_V7(parser_context_t* c, pd_CompactMemberCount_V7_t* v);
parser_error_t _readCompactMoment_V7(parser_context_t* c, pd_CompactMoment_V7_t* v);
parser_error_t _readCompactPerBill_V7(parser_context_t* c, pd_CompactPerBill_V7_t* v);
parser_error_t _readCompactPropIndex_V7(parser_context_t* c, pd_CompactPropIndex_V7_t* v);
parser_error_t _readCompactProposalIndex_V7(parser_context_t* c, pd_CompactProposalIndex_V7_t* v);
parser_error_t _readCompactReferendumIndex_V7(parser_context_t* c, pd_CompactReferendumIndex_V7_t* v);
parser_error_t _readCompactRegistrarIndex_V7(parser_context_t* c, pd_CompactRegistrarIndex_V7_t* v);
parser_error_t _readCompactWeight_V7(parser_context_t* c, pd_CompactWeight_V7_t* v);
parser_error_t _readConviction_V7(parser_context_t* c, pd_Conviction_V7_t* v);
parser_error_t _readEcdsaSignature_V7(parser_context_t* c, pd_EcdsaSignature_V7_t* v);
parser_error_t _readElectionScore_V7(parser_context_t* c, pd_ElectionScore_V7_t* v);
parser_error_t _readEraIndex_V7(parser_context_t* c, pd_EraIndex_V7_t* v);
parser_error_t _readEthereumAddress_V7(parser_context_t* c, pd_EthereumAddress_V7_t* v);
parser_error_t _readGrandpaEquivocationProof_V7(parser_context_t* c, pd_GrandpaEquivocationProof_V7_t* v);
parser_error_t _readIdentityFields_V7(parser_context_t* c, pd_IdentityFields_V7_t* v);
parser_error_t _readIdentityInfo_V7(parser_context_t* c, pd_IdentityInfo_V7_t* v);
parser_error_t _readIdentityJudgement_V7(parser_context_t* c, pd_IdentityJudgement_V7_t* v);
parser_error_t _readKeyOwnerProof_V7(parser_context_t* c, pd_KeyOwnerProof_V7_t* v);
parser_error_t _readKeyValue_V7(parser_context_t* c, pd_KeyValue_V7_t* v);
parser_error_t _readKey_V7(parser_context_t* c, pd_Key_V7_t* v);
parser_error_t _readKeys_V7(parser_context_t* c, pd_Keys_V7_t* v);
parser_error_t _readLookupSource_V7(parser_context_t* c, pd_LookupSource_V7_t* v);
parser_error_t _readMemberCount_V7(parser_context_t* c, pd_MemberCount_V7_t* v);
parser_error_t _readNextConfigDescriptor_V7(parser_context_t* c, pd_NextConfigDescriptor_V7_t* v);
parser_error_t _readOpaqueCall_V7(parser_context_t* c, pd_OpaqueCall_V7_t* v);
parser_error_t _readOptionAccountId_V7(parser_context_t* c, pd_OptionAccountId_V7_t* v);
parser_error_t _readOptionChangesTrieConfiguration_V7(parser_context_t* c, pd_OptionChangesTrieConfiguration_V7_t* v);
parser_error_t _readOptionElectionScore_V7(parser_context_t* c, pd_OptionElectionScore_V7_t* v);
parser_error_t _readOptionPeriod_V7(parser_context_t* c, pd_OptionPeriod_V7_t* v);
parser_error_t _readOptionProxyType_V7(parser_context_t* c, pd_OptionProxyType_V7_t* v);
parser_error_t _readOptionReferendumIndex_V7(parser_context_t* c, pd_OptionReferendumIndex_V7_t* v);
parser_error_t _readOptionStatementKind_V7(parser_context_t* c, pd_OptionStatementKind_V7_t* v);
parser_error_t _readOptionTimepoint_V7(parser_context_t* c, pd_OptionTimepoint_V7_t* v);
parser_error_t _readOptionTupleBalanceOfBalanceOfBlockNumber_V7(parser_context_t* c, pd_OptionTupleBalanceOfBalanceOfBlockNumber_V7_t* v);
parser_error_t _readPerbill_V7(parser_context_t* c, pd_Perbill_V7_t* v);
parser_error_t _readPercent_V7(parser_context_t* c, pd_Percent_V7_t* v);
parser_error_t _readPeriod_V7(parser_context_t* c, pd_Period_V7_t* v);
parser_error_t _readPriority_V7(parser_context_t* c, pd_Priority_V7_t* v);
parser_error_t _readProxyType_V7(parser_context_t* c, pd_ProxyType_V7_t* v);
parser_error_t _readRawSolution_V7(parser_context_t* c, pd_RawSolution_V7_t* v);
parser_error_t _readReadySolution_V7(parser_context_t* c, pd_ReadySolution_V7_t* v);
parser_error_t _readReferendumIndex_V7(parser_context_t* c, pd_ReferendumIndex_V7_t* v);
parser_error_t _readRegistrarIndex_V7(parser_context_t* c, pd_RegistrarIndex_V7_t* v);
parser_error_t _readRenouncing_V7(parser_context_t* c, pd_Renouncing_V7_t* v);
parser_error_t _readRewardDestination_V7(parser_context_t* c, pd_RewardDestination_V7_t* v);
parser_error_t _readSignature_V7(parser_context_t* c, pd_Signature_V7_t* v);
parser_error_t _readSolutionOrSnapshotSize_V7(parser_context_t* c, pd_SolutionOrSnapshotSize_V7_t* v);
parser_error_t _readStatementKind_V7(parser_context_t* c, pd_StatementKind_V7_t* v);
parser_error_t _readStreamDependency_V7(parser_context_t* c, pd_StreamDependency_V7_t* v);
parser_error_t _readTimepoint_V7(parser_context_t* c, pd_Timepoint_V7_t* v);
parser_error_t _readTupleAccountIdData_V7(parser_context_t* c, pd_TupleAccountIdData_V7_t* v);
parser_error_t _readTupleBalanceOfBalanceOfBlockNumber_V7(parser_context_t* c, pd_TupleBalanceOfBalanceOfBlockNumber_V7_t* v);
parser_error_t _readValidatorPrefs_V7(parser_context_t* c, pd_ValidatorPrefs_V7_t* v);
parser_error_t _readVecAccountId_V7(parser_context_t* c, pd_VecAccountId_V7_t* v);
parser_error_t _readVecKeyValue_V7(parser_context_t* c, pd_VecKeyValue_V7_t* v);
parser_error_t _readVecKey_V7(parser_context_t* c, pd_VecKey_V7_t* v);
parser_error_t _readVecLookupSource_V7(parser_context_t* c, pd_VecLookupSource_V7_t* v);
parser_error_t _readVecTupleAccountIdData_V7(parser_context_t* c, pd_VecTupleAccountIdData_V7_t* v);
parser_error_t _readVestingInfo_V7(parser_context_t* c, pd_VestingInfo_V7_t* v);
parser_error_t _readVote_V7(parser_context_t* c, pd_Vote_V7_t* v);
parser_error_t _readWeight_V7(parser_context_t* c, pd_Weight_V7_t* v);
parser_error_t _readu8_array_32_V7(parser_context_t* c, pd_u8_array_32_V7_t* v);

// toString functions
parser_error_t _toStringAccountId_V7(
    const pd_AccountId_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountIndex_V7(
    const pd_AccountIndex_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountVoteSplit_V7(
    const pd_AccountVoteSplit_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountVoteStandard_V7(
    const pd_AccountVoteStandard_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountVote_V7(
    const pd_AccountVote_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBabeEquivocationProof_V7(
    const pd_BabeEquivocationProof_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCallHashOf_V7(
    const pd_CallHashOf_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringChangesTrieConfiguration_V7(
    const pd_ChangesTrieConfiguration_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactAccountIndex_V7(
    const pd_CompactAccountIndex_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactBountyIndex_V7(
    const pd_CompactBountyIndex_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactEraIndex_V7(
    const pd_CompactEraIndex_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactMemberCount_V7(
    const pd_CompactMemberCount_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactMoment_V7(
    const pd_CompactMoment_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactPerBill_V7(
    const pd_CompactPerBill_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactPropIndex_V7(
    const pd_CompactPropIndex_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactProposalIndex_V7(
    const pd_CompactProposalIndex_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactReferendumIndex_V7(
    const pd_CompactReferendumIndex_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactRegistrarIndex_V7(
    const pd_CompactRegistrarIndex_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactWeight_V7(
    const pd_CompactWeight_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringConviction_V7(
    const pd_Conviction_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEcdsaSignature_V7(
    const pd_EcdsaSignature_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringElectionScore_V7(
    const pd_ElectionScore_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEraIndex_V7(
    const pd_EraIndex_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEthereumAddress_V7(
    const pd_EthereumAddress_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringGrandpaEquivocationProof_V7(
    const pd_GrandpaEquivocationProof_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringIdentityFields_V7(
    const pd_IdentityFields_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringIdentityInfo_V7(
    const pd_IdentityInfo_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringIdentityJudgement_V7(
    const pd_IdentityJudgement_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKeyOwnerProof_V7(
    const pd_KeyOwnerProof_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKeyValue_V7(
    const pd_KeyValue_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKey_V7(
    const pd_Key_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKeys_V7(
    const pd_Keys_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringLookupSource_V7(
    const pd_LookupSource_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMemberCount_V7(
    const pd_MemberCount_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringNextConfigDescriptor_V7(
    const pd_NextConfigDescriptor_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOpaqueCall_V7(
    const pd_OpaqueCall_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionAccountId_V7(
    const pd_OptionAccountId_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionChangesTrieConfiguration_V7(
    const pd_OptionChangesTrieConfiguration_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionElectionScore_V7(
    const pd_OptionElectionScore_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionPeriod_V7(
    const pd_OptionPeriod_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionProxyType_V7(
    const pd_OptionProxyType_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionReferendumIndex_V7(
    const pd_OptionReferendumIndex_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionStatementKind_V7(
    const pd_OptionStatementKind_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionTimepoint_V7(
    const pd_OptionTimepoint_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionTupleBalanceOfBalanceOfBlockNumber_V7(
    const pd_OptionTupleBalanceOfBalanceOfBlockNumber_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPerbill_V7(
    const pd_Perbill_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPercent_V7(
    const pd_Percent_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPeriod_V7(
    const pd_Period_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPriority_V7(
    const pd_Priority_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringProxyType_V7(
    const pd_ProxyType_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringRawSolution_V7(
    const pd_RawSolution_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringReadySolution_V7(
    const pd_ReadySolution_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringReferendumIndex_V7(
    const pd_ReferendumIndex_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringRegistrarIndex_V7(
    const pd_RegistrarIndex_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringRenouncing_V7(
    const pd_Renouncing_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringRewardDestination_V7(
    const pd_RewardDestination_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSignature_V7(
    const pd_Signature_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSolutionOrSnapshotSize_V7(
    const pd_SolutionOrSnapshotSize_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringStatementKind_V7(
    const pd_StatementKind_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringStreamDependency_V7(
    const pd_StreamDependency_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTimepoint_V7(
    const pd_Timepoint_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTupleAccountIdData_V7(
    const pd_TupleAccountIdData_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTupleBalanceOfBalanceOfBlockNumber_V7(
    const pd_TupleBalanceOfBalanceOfBlockNumber_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringValidatorPrefs_V7(
    const pd_ValidatorPrefs_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecAccountId_V7(
    const pd_VecAccountId_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecKeyValue_V7(
    const pd_VecKeyValue_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecKey_V7(
    const pd_VecKey_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecLookupSource_V7(
    const pd_VecLookupSource_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecTupleAccountIdData_V7(
    const pd_VecTupleAccountIdData_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVestingInfo_V7(
    const pd_VestingInfo_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVote_V7(
    const pd_Vote_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringWeight_V7(
    const pd_Weight_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringu8_array_32_V7(
    const pd_u8_array_32_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

#ifdef __cplusplus
}
#endif
