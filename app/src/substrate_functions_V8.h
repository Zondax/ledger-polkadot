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
parser_error_t _readAccountVoteSplit_V8(parser_context_t* c, pd_AccountVoteSplit_V8_t* v);
parser_error_t _readAccountVoteStandard_V8(parser_context_t* c, pd_AccountVoteStandard_V8_t* v);
parser_error_t _readAccountVote_V8(parser_context_t* c, pd_AccountVote_V8_t* v);
parser_error_t _readBabeEquivocationProof_V8(parser_context_t* c, pd_BabeEquivocationProof_V8_t* v);
parser_error_t _readCallHashOf_V8(parser_context_t* c, pd_CallHashOf_V8_t* v);
parser_error_t _readChangesTrieConfiguration_V8(parser_context_t* c, pd_ChangesTrieConfiguration_V8_t* v);
parser_error_t _readCompactAccountIndex_V8(parser_context_t* c, pd_CompactAccountIndex_V8_t* v);
parser_error_t _readCompactBountyIndex_V8(parser_context_t* c, pd_CompactBountyIndex_V8_t* v);
parser_error_t _readCompactEraIndex_V8(parser_context_t* c, pd_CompactEraIndex_V8_t* v);
parser_error_t _readCompactMemberCount_V8(parser_context_t* c, pd_CompactMemberCount_V8_t* v);
parser_error_t _readCompactMoment_V8(parser_context_t* c, pd_CompactMoment_V8_t* v);
parser_error_t _readCompactPerBill_V8(parser_context_t* c, pd_CompactPerBill_V8_t* v);
parser_error_t _readCompactPropIndex_V8(parser_context_t* c, pd_CompactPropIndex_V8_t* v);
parser_error_t _readCompactProposalIndex_V8(parser_context_t* c, pd_CompactProposalIndex_V8_t* v);
parser_error_t _readCompactReferendumIndex_V8(parser_context_t* c, pd_CompactReferendumIndex_V8_t* v);
parser_error_t _readCompactRegistrarIndex_V8(parser_context_t* c, pd_CompactRegistrarIndex_V8_t* v);
parser_error_t _readCompactWeight_V8(parser_context_t* c, pd_CompactWeight_V8_t* v);
parser_error_t _readConviction_V8(parser_context_t* c, pd_Conviction_V8_t* v);
parser_error_t _readEcdsaSignature_V8(parser_context_t* c, pd_EcdsaSignature_V8_t* v);
parser_error_t _readElectionScore_V8(parser_context_t* c, pd_ElectionScore_V8_t* v);
parser_error_t _readEraIndex_V8(parser_context_t* c, pd_EraIndex_V8_t* v);
parser_error_t _readEthereumAddress_V8(parser_context_t* c, pd_EthereumAddress_V8_t* v);
parser_error_t _readGrandpaEquivocationProof_V8(parser_context_t* c, pd_GrandpaEquivocationProof_V8_t* v);
parser_error_t _readIdentityFields_V8(parser_context_t* c, pd_IdentityFields_V8_t* v);
parser_error_t _readIdentityInfo_V8(parser_context_t* c, pd_IdentityInfo_V8_t* v);
parser_error_t _readIdentityJudgement_V8(parser_context_t* c, pd_IdentityJudgement_V8_t* v);
parser_error_t _readKeyOwnerProof_V8(parser_context_t* c, pd_KeyOwnerProof_V8_t* v);
parser_error_t _readKeyValue_V8(parser_context_t* c, pd_KeyValue_V8_t* v);
parser_error_t _readKey_V8(parser_context_t* c, pd_Key_V8_t* v);
parser_error_t _readKeys_V8(parser_context_t* c, pd_Keys_V8_t* v);
parser_error_t _readLookupSource_V8(parser_context_t* c, pd_LookupSource_V8_t* v);
parser_error_t _readMemberCount_V8(parser_context_t* c, pd_MemberCount_V8_t* v);
parser_error_t _readNextConfigDescriptor_V8(parser_context_t* c, pd_NextConfigDescriptor_V8_t* v);
parser_error_t _readOpaqueCall_V8(parser_context_t* c, pd_OpaqueCall_V8_t* v);
parser_error_t _readOptionAccountId_V8(parser_context_t* c, pd_OptionAccountId_V8_t* v);
parser_error_t _readOptionChangesTrieConfiguration_V8(parser_context_t* c, pd_OptionChangesTrieConfiguration_V8_t* v);
parser_error_t _readOptionElectionScore_V8(parser_context_t* c, pd_OptionElectionScore_V8_t* v);
parser_error_t _readOptionPercent_V8(parser_context_t* c, pd_OptionPercent_V8_t* v);
parser_error_t _readOptionPeriod_V8(parser_context_t* c, pd_OptionPeriod_V8_t* v);
parser_error_t _readOptionProxyType_V8(parser_context_t* c, pd_OptionProxyType_V8_t* v);
parser_error_t _readOptionReferendumIndex_V8(parser_context_t* c, pd_OptionReferendumIndex_V8_t* v);
parser_error_t _readOptionStatementKind_V8(parser_context_t* c, pd_OptionStatementKind_V8_t* v);
parser_error_t _readOptionTimepoint_V8(parser_context_t* c, pd_OptionTimepoint_V8_t* v);
parser_error_t _readOptionTupleBalanceOfBalanceOfBlockNumber_V8(parser_context_t* c, pd_OptionTupleBalanceOfBalanceOfBlockNumber_V8_t* v);
parser_error_t _readPerbill_V8(parser_context_t* c, pd_Perbill_V8_t* v);
parser_error_t _readPercent_V8(parser_context_t* c, pd_Percent_V8_t* v);
parser_error_t _readPeriod_V8(parser_context_t* c, pd_Period_V8_t* v);
parser_error_t _readPriority_V8(parser_context_t* c, pd_Priority_V8_t* v);
parser_error_t _readProxyType_V8(parser_context_t* c, pd_ProxyType_V8_t* v);
parser_error_t _readRawSolution_V8(parser_context_t* c, pd_RawSolution_V8_t* v);
parser_error_t _readReferendumIndex_V8(parser_context_t* c, pd_ReferendumIndex_V8_t* v);
parser_error_t _readRegistrarIndex_V8(parser_context_t* c, pd_RegistrarIndex_V8_t* v);
parser_error_t _readRenouncing_V8(parser_context_t* c, pd_Renouncing_V8_t* v);
parser_error_t _readRewardDestination_V8(parser_context_t* c, pd_RewardDestination_V8_t* v);
parser_error_t _readSignature_V8(parser_context_t* c, pd_Signature_V8_t* v);
parser_error_t _readSolutionOrSnapshotSize_V8(parser_context_t* c, pd_SolutionOrSnapshotSize_V8_t* v);
parser_error_t _readStatementKind_V8(parser_context_t* c, pd_StatementKind_V8_t* v);
parser_error_t _readStreamDependency_V8(parser_context_t* c, pd_StreamDependency_V8_t* v);
parser_error_t _readSupports_V8(parser_context_t* c, pd_Supports_V8_t* v);
parser_error_t _readTimepoint_V8(parser_context_t* c, pd_Timepoint_V8_t* v);
parser_error_t _readTupleAccountIdData_V8(parser_context_t* c, pd_TupleAccountIdData_V8_t* v);
parser_error_t _readTupleBalanceOfBalanceOfBlockNumber_V8(parser_context_t* c, pd_TupleBalanceOfBalanceOfBlockNumber_V8_t* v);
parser_error_t _readValidatorPrefs_V8(parser_context_t* c, pd_ValidatorPrefs_V8_t* v);
parser_error_t _readVecAccountId_V8(parser_context_t* c, pd_VecAccountId_V8_t* v);
parser_error_t _readVecKeyValue_V8(parser_context_t* c, pd_VecKeyValue_V8_t* v);
parser_error_t _readVecKey_V8(parser_context_t* c, pd_VecKey_V8_t* v);
parser_error_t _readVecLookupSource_V8(parser_context_t* c, pd_VecLookupSource_V8_t* v);
parser_error_t _readVecTupleAccountIdData_V8(parser_context_t* c, pd_VecTupleAccountIdData_V8_t* v);
parser_error_t _readVestingInfo_V8(parser_context_t* c, pd_VestingInfo_V8_t* v);
parser_error_t _readVote_V8(parser_context_t* c, pd_Vote_V8_t* v);
parser_error_t _readWeight_V8(parser_context_t* c, pd_Weight_V8_t* v);
parser_error_t _readu8_array_32_V8(parser_context_t* c, pd_u8_array_32_V8_t* v);

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

parser_error_t _toStringAccountVoteSplit_V8(
    const pd_AccountVoteSplit_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountVoteStandard_V8(
    const pd_AccountVoteStandard_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountVote_V8(
    const pd_AccountVote_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBabeEquivocationProof_V8(
    const pd_BabeEquivocationProof_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCallHashOf_V8(
    const pd_CallHashOf_V8_t* v,
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

parser_error_t _toStringCompactBountyIndex_V8(
    const pd_CompactBountyIndex_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactEraIndex_V8(
    const pd_CompactEraIndex_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactMemberCount_V8(
    const pd_CompactMemberCount_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactMoment_V8(
    const pd_CompactMoment_V8_t* v,
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

parser_error_t _toStringCompactPropIndex_V8(
    const pd_CompactPropIndex_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactProposalIndex_V8(
    const pd_CompactProposalIndex_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactReferendumIndex_V8(
    const pd_CompactReferendumIndex_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactRegistrarIndex_V8(
    const pd_CompactRegistrarIndex_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactWeight_V8(
    const pd_CompactWeight_V8_t* v,
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

parser_error_t _toStringGrandpaEquivocationProof_V8(
    const pd_GrandpaEquivocationProof_V8_t* v,
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

parser_error_t _toStringIdentityInfo_V8(
    const pd_IdentityInfo_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringIdentityJudgement_V8(
    const pd_IdentityJudgement_V8_t* v,
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

parser_error_t _toStringLookupSource_V8(
    const pd_LookupSource_V8_t* v,
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

parser_error_t _toStringOptionPercent_V8(
    const pd_OptionPercent_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionPeriod_V8(
    const pd_OptionPeriod_V8_t* v,
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

parser_error_t _toStringOptionTupleBalanceOfBalanceOfBlockNumber_V8(
    const pd_OptionTupleBalanceOfBalanceOfBlockNumber_V8_t* v,
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

parser_error_t _toStringPeriod_V8(
    const pd_Period_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPriority_V8(
    const pd_Priority_V8_t* v,
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

parser_error_t _toStringRawSolution_V8(
    const pd_RawSolution_V8_t* v,
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

parser_error_t _toStringSignature_V8(
    const pd_Signature_V8_t* v,
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

parser_error_t _toStringStreamDependency_V8(
    const pd_StreamDependency_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSupports_V8(
    const pd_Supports_V8_t* v,
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

parser_error_t _toStringTupleBalanceOfBalanceOfBlockNumber_V8(
    const pd_TupleBalanceOfBalanceOfBlockNumber_V8_t* v,
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

parser_error_t _toStringVecLookupSource_V8(
    const pd_VecLookupSource_V8_t* v,
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

parser_error_t _toStringVestingInfo_V8(
    const pd_VestingInfo_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVote_V8(
    const pd_Vote_V8_t* v,
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

parser_error_t _toStringu8_array_32_V8(
    const pd_u8_array_32_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

#ifdef __cplusplus
}
#endif
