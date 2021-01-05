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
#include "substrate_methods_V5.h"
#include "substrate_types_V5.h"
#include <stddef.h>
#include <stdint.h>

// Read functions
parser_error_t _readAccountId_V5(parser_context_t* c, pd_AccountId_V5_t* v);
parser_error_t _readAccountIndex_V5(parser_context_t* c, pd_AccountIndex_V5_t* v);
parser_error_t _readAccountVoteSplit_V5(parser_context_t* c, pd_AccountVoteSplit_V5_t* v);
parser_error_t _readAccountVoteStandard_V5(parser_context_t* c, pd_AccountVoteStandard_V5_t* v);
parser_error_t _readAccountVote_V5(parser_context_t* c, pd_AccountVote_V5_t* v);
parser_error_t _readBalanceOf_V5(parser_context_t* c, pd_BalanceOf_V5_t* v);
parser_error_t _readCallHashOf_V5(parser_context_t* c, pd_CallHashOf_V5_t* v);
parser_error_t _readCall_V5(parser_context_t* c, pd_Call_V5_t* v);
parser_error_t _readChangesTrieConfiguration_V5(parser_context_t* c, pd_ChangesTrieConfiguration_V5_t* v);
parser_error_t _readCompactAssignments_V5(parser_context_t* c, pd_CompactAssignments_V5_t* v);
parser_error_t _readCompactBountyIndex_V5(parser_context_t* c, pd_CompactBountyIndex_V5_t* v);
parser_error_t _readCompactEraIndex_V5(parser_context_t* c, pd_CompactEraIndex_V5_t* v);
parser_error_t _readCompactMemberCount_V5(parser_context_t* c, pd_CompactMemberCount_V5_t* v);
parser_error_t _readCompactMoment_V5(parser_context_t* c, pd_CompactMoment_V5_t* v);
parser_error_t _readCompactPerBill_V5(parser_context_t* c, pd_CompactPerBill_V5_t* v);
parser_error_t _readCompactPropIndex_V5(parser_context_t* c, pd_CompactPropIndex_V5_t* v);
parser_error_t _readCompactProposalIndex_V5(parser_context_t* c, pd_CompactProposalIndex_V5_t* v);
parser_error_t _readCompactReferendumIndex_V5(parser_context_t* c, pd_CompactReferendumIndex_V5_t* v);
parser_error_t _readCompactRegistrarIndex_V5(parser_context_t* c, pd_CompactRegistrarIndex_V5_t* v);
parser_error_t _readCompactWeight_V5(parser_context_t* c, pd_CompactWeight_V5_t* v);
parser_error_t _readConviction_V5(parser_context_t* c, pd_Conviction_V5_t* v);
parser_error_t _readDefunctVoter_V5(parser_context_t* c, pd_DefunctVoter_V5_t* v);
parser_error_t _readEcdsaSignature_V5(parser_context_t* c, pd_EcdsaSignature_V5_t* v);
parser_error_t _readElectionScore_V5(parser_context_t* c, pd_ElectionScore_V5_t* v);
parser_error_t _readElectionSize_V5(parser_context_t* c, pd_ElectionSize_V5_t* v);
parser_error_t _readEquivocationProof_V5(parser_context_t* c, pd_EquivocationProof_V5_t* v);
parser_error_t _readEraIndex_V5(parser_context_t* c, pd_EraIndex_V5_t* v);
parser_error_t _readEthereumAddress_V5(parser_context_t* c, pd_EthereumAddress_V5_t* v);
parser_error_t _readIdentityFields_V5(parser_context_t* c, pd_IdentityFields_V5_t* v);
parser_error_t _readIdentityInfo_V5(parser_context_t* c, pd_IdentityInfo_V5_t* v);
parser_error_t _readJudgement_V5(parser_context_t* c, pd_Judgement_V5_t* v);
parser_error_t _readKeyOwnerProof_V5(parser_context_t* c, pd_KeyOwnerProof_V5_t* v);
parser_error_t _readKeyValue_V5(parser_context_t* c, pd_KeyValue_V5_t* v);
parser_error_t _readKey_V5(parser_context_t* c, pd_Key_V5_t* v);
parser_error_t _readKeys_V5(parser_context_t* c, pd_Keys_V5_t* v);
parser_error_t _readLookupSource_V5(parser_context_t* c, pd_LookupSource_V5_t* v);
parser_error_t _readMemberCount_V5(parser_context_t* c, pd_MemberCount_V5_t* v);
parser_error_t _readOpaqueCall_V5(parser_context_t* c, pd_OpaqueCall_V5_t* v);
parser_error_t _readOptionAccountId_V5(parser_context_t* c, pd_OptionAccountId_V5_t* v);
parser_error_t _readOptionChangesTrieConfiguration_V5(parser_context_t* c, pd_OptionChangesTrieConfiguration_V5_t* v);
parser_error_t _readOptionPeriod_V5(parser_context_t* c, pd_OptionPeriod_V5_t* v);
parser_error_t _readOptionProxyType_V5(parser_context_t* c, pd_OptionProxyType_V5_t* v);
parser_error_t _readOptionReferendumIndex_V5(parser_context_t* c, pd_OptionReferendumIndex_V5_t* v);
parser_error_t _readOptionStatementKind_V5(parser_context_t* c, pd_OptionStatementKind_V5_t* v);
parser_error_t _readOptionTimepoint_V5(parser_context_t* c, pd_OptionTimepoint_V5_t* v);
parser_error_t _readOptionTupleBalanceOfBalanceOfBlockNumber_V5(parser_context_t* c, pd_OptionTupleBalanceOfBalanceOfBlockNumber_V5_t* v);
parser_error_t _readPerbill_V5(parser_context_t* c, pd_Perbill_V5_t* v);
parser_error_t _readPercent_V5(parser_context_t* c, pd_Percent_V5_t* v);
parser_error_t _readPeriod_V5(parser_context_t* c, pd_Period_V5_t* v);
parser_error_t _readPriority_V5(parser_context_t* c, pd_Priority_V5_t* v);
parser_error_t _readProxyType_V5(parser_context_t* c, pd_ProxyType_V5_t* v);
parser_error_t _readReferendumIndex_V5(parser_context_t* c, pd_ReferendumIndex_V5_t* v);
parser_error_t _readRegistrarIndex_V5(parser_context_t* c, pd_RegistrarIndex_V5_t* v);
parser_error_t _readRenouncing_V5(parser_context_t* c, pd_Renouncing_V5_t* v);
parser_error_t _readRewardDestination_V5(parser_context_t* c, pd_RewardDestination_V5_t* v);
parser_error_t _readSignature_V5(parser_context_t* c, pd_Signature_V5_t* v);
parser_error_t _readStatementKind_V5(parser_context_t* c, pd_StatementKind_V5_t* v);
parser_error_t _readStreamDependency_V5(parser_context_t* c, pd_StreamDependency_V5_t* v);
parser_error_t _readTimepoint_V5(parser_context_t* c, pd_Timepoint_V5_t* v);
parser_error_t _readTupleAccountIdData_V5(parser_context_t* c, pd_TupleAccountIdData_V5_t* v);
parser_error_t _readTupleBalanceOfBalanceOfBlockNumber_V5(parser_context_t* c, pd_TupleBalanceOfBalanceOfBlockNumber_V5_t* v);
parser_error_t _readValidatorIndex_V5(parser_context_t* c, pd_ValidatorIndex_V5_t* v);
parser_error_t _readValidatorPrefs_V5(parser_context_t* c, pd_ValidatorPrefs_V5_t* v);
parser_error_t _readVecAccountId_V5(parser_context_t* c, pd_VecAccountId_V5_t* v);
parser_error_t _readVecCall_V5(parser_context_t* c, pd_VecCall_V5_t* v);
parser_error_t _readVecKeyValue_V5(parser_context_t* c, pd_VecKeyValue_V5_t* v);
parser_error_t _readVecKey_V5(parser_context_t* c, pd_VecKey_V5_t* v);
parser_error_t _readVecLookupSource_V5(parser_context_t* c, pd_VecLookupSource_V5_t* v);
parser_error_t _readVecTupleAccountIdData_V5(parser_context_t* c, pd_VecTupleAccountIdData_V5_t* v);
parser_error_t _readVecValidatorIndex_V5(parser_context_t* c, pd_VecValidatorIndex_V5_t* v);
parser_error_t _readVestingInfo_V5(parser_context_t* c, pd_VestingInfo_V5_t* v);
parser_error_t _readVote_V5(parser_context_t* c, pd_Vote_V5_t* v);
parser_error_t _readWeight_V5(parser_context_t* c, pd_Weight_V5_t* v);
parser_error_t _readu8_array_32_V5(parser_context_t* c, pd_u8_array_32_V5_t* v);

// toString functions
parser_error_t _toStringAccountId_V5(
    const pd_AccountId_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountIndex_V5(
    const pd_AccountIndex_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountVoteSplit_V5(
    const pd_AccountVoteSplit_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountVoteStandard_V5(
    const pd_AccountVoteStandard_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountVote_V5(
    const pd_AccountVote_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBalanceOf_V5(
    const pd_BalanceOf_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCallHashOf_V5(
    const pd_CallHashOf_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCall_V5(
    const pd_Call_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringChangesTrieConfiguration_V5(
    const pd_ChangesTrieConfiguration_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactAssignments_V5(
    const pd_CompactAssignments_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactBountyIndex_V5(
    const pd_CompactBountyIndex_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactEraIndex_V5(
    const pd_CompactEraIndex_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactMemberCount_V5(
    const pd_CompactMemberCount_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactMoment_V5(
    const pd_CompactMoment_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactPerBill_V5(
    const pd_CompactPerBill_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactPropIndex_V5(
    const pd_CompactPropIndex_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactProposalIndex_V5(
    const pd_CompactProposalIndex_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactReferendumIndex_V5(
    const pd_CompactReferendumIndex_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactRegistrarIndex_V5(
    const pd_CompactRegistrarIndex_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactWeight_V5(
    const pd_CompactWeight_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringConviction_V5(
    const pd_Conviction_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringDefunctVoter_V5(
    const pd_DefunctVoter_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEcdsaSignature_V5(
    const pd_EcdsaSignature_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringElectionScore_V5(
    const pd_ElectionScore_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringElectionSize_V5(
    const pd_ElectionSize_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEquivocationProof_V5(
    const pd_EquivocationProof_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEraIndex_V5(
    const pd_EraIndex_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEthereumAddress_V5(
    const pd_EthereumAddress_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringIdentityFields_V5(
    const pd_IdentityFields_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringIdentityInfo_V5(
    const pd_IdentityInfo_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJudgement_V5(
    const pd_Judgement_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKeyOwnerProof_V5(
    const pd_KeyOwnerProof_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKeyValue_V5(
    const pd_KeyValue_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKey_V5(
    const pd_Key_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKeys_V5(
    const pd_Keys_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringLookupSource_V5(
    const pd_LookupSource_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMemberCount_V5(
    const pd_MemberCount_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOpaqueCall_V5(
    const pd_OpaqueCall_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionAccountId_V5(
    const pd_OptionAccountId_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionChangesTrieConfiguration_V5(
    const pd_OptionChangesTrieConfiguration_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionPeriod_V5(
    const pd_OptionPeriod_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionProxyType_V5(
    const pd_OptionProxyType_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionReferendumIndex_V5(
    const pd_OptionReferendumIndex_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionStatementKind_V5(
    const pd_OptionStatementKind_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionTimepoint_V5(
    const pd_OptionTimepoint_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionTupleBalanceOfBalanceOfBlockNumber_V5(
    const pd_OptionTupleBalanceOfBalanceOfBlockNumber_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPerbill_V5(
    const pd_Perbill_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPercent_V5(
    const pd_Percent_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPeriod_V5(
    const pd_Period_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPriority_V5(
    const pd_Priority_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringProxyType_V5(
    const pd_ProxyType_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringReferendumIndex_V5(
    const pd_ReferendumIndex_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringRegistrarIndex_V5(
    const pd_RegistrarIndex_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringRenouncing_V5(
    const pd_Renouncing_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringRewardDestination_V5(
    const pd_RewardDestination_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSignature_V5(
    const pd_Signature_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringStatementKind_V5(
    const pd_StatementKind_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringStreamDependency_V5(
    const pd_StreamDependency_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTimepoint_V5(
    const pd_Timepoint_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTupleAccountIdData_V5(
    const pd_TupleAccountIdData_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTupleBalanceOfBalanceOfBlockNumber_V5(
    const pd_TupleBalanceOfBalanceOfBlockNumber_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringValidatorIndex_V5(
    const pd_ValidatorIndex_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringValidatorPrefs_V5(
    const pd_ValidatorPrefs_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecAccountId_V5(
    const pd_VecAccountId_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecCall_V5(
    const pd_VecCall_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecKeyValue_V5(
    const pd_VecKeyValue_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecKey_V5(
    const pd_VecKey_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecLookupSource_V5(
    const pd_VecLookupSource_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecTupleAccountIdData_V5(
    const pd_VecTupleAccountIdData_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecValidatorIndex_V5(
    const pd_VecValidatorIndex_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVestingInfo_V5(
    const pd_VestingInfo_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVote_V5(
    const pd_Vote_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringWeight_V5(
    const pd_Weight_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringu8_array_32_V5(
    const pd_u8_array_32_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _readProposal_V5(parser_context_t* c, pd_Proposal_V5_t* v);
parser_error_t _toStringProposal_V5(
    const pd_Proposal_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

#ifdef __cplusplus
}
#endif
