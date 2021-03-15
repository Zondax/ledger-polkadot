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
#include "substrate_methods_V6.h"
#include "substrate_types_V6.h"
#include <stddef.h>
#include <stdint.h>

// Read functions
parser_error_t _readAccountId_V6(parser_context_t* c, pd_AccountId_V6_t* v);
parser_error_t _readAccountIndex_V6(parser_context_t* c, pd_AccountIndex_V6_t* v);
parser_error_t _readAccountVoteSplit_V6(parser_context_t* c, pd_AccountVoteSplit_V6_t* v);
parser_error_t _readAccountVoteStandard_V6(parser_context_t* c, pd_AccountVoteStandard_V6_t* v);
parser_error_t _readAccountVote_V6(parser_context_t* c, pd_AccountVote_V6_t* v);
parser_error_t _readBabeEquivocationProof_V6(parser_context_t* c, pd_BabeEquivocationProof_V6_t* v);
parser_error_t _readCallHashOf_V6(parser_context_t* c, pd_CallHashOf_V6_t* v);
parser_error_t _readChangesTrieConfiguration_V6(parser_context_t* c, pd_ChangesTrieConfiguration_V6_t* v);
parser_error_t _readCompactAccountIndex_V6(parser_context_t* c, pd_CompactAccountIndex_V6_t* v);
parser_error_t _readCompactAssignments_V6(parser_context_t* c, pd_CompactAssignments_V6_t* v);
parser_error_t _readCompactBountyIndex_V6(parser_context_t* c, pd_CompactBountyIndex_V6_t* v);
parser_error_t _readCompactEraIndex_V6(parser_context_t* c, pd_CompactEraIndex_V6_t* v);
parser_error_t _readCompactMemberCount_V6(parser_context_t* c, pd_CompactMemberCount_V6_t* v);
parser_error_t _readCompactMoment_V6(parser_context_t* c, pd_CompactMoment_V6_t* v);
parser_error_t _readCompactPerBill_V6(parser_context_t* c, pd_CompactPerBill_V6_t* v);
parser_error_t _readCompactPropIndex_V6(parser_context_t* c, pd_CompactPropIndex_V6_t* v);
parser_error_t _readCompactProposalIndex_V6(parser_context_t* c, pd_CompactProposalIndex_V6_t* v);
parser_error_t _readCompactReferendumIndex_V6(parser_context_t* c, pd_CompactReferendumIndex_V6_t* v);
parser_error_t _readCompactRegistrarIndex_V6(parser_context_t* c, pd_CompactRegistrarIndex_V6_t* v);
parser_error_t _readCompactWeight_V6(parser_context_t* c, pd_CompactWeight_V6_t* v);
parser_error_t _readConviction_V6(parser_context_t* c, pd_Conviction_V6_t* v);
parser_error_t _readEcdsaSignature_V6(parser_context_t* c, pd_EcdsaSignature_V6_t* v);
parser_error_t _readElectionScore_V6(parser_context_t* c, pd_ElectionScore_V6_t* v);
parser_error_t _readElectionSize_V6(parser_context_t* c, pd_ElectionSize_V6_t* v);
parser_error_t _readEraIndex_V6(parser_context_t* c, pd_EraIndex_V6_t* v);
parser_error_t _readEthereumAddress_V6(parser_context_t* c, pd_EthereumAddress_V6_t* v);
parser_error_t _readGrandpaEquivocationProof_V6(parser_context_t* c, pd_GrandpaEquivocationProof_V6_t* v);
parser_error_t _readIdentityFields_V6(parser_context_t* c, pd_IdentityFields_V6_t* v);
parser_error_t _readIdentityInfo_V6(parser_context_t* c, pd_IdentityInfo_V6_t* v);
parser_error_t _readIdentityJudgement_V6(parser_context_t* c, pd_IdentityJudgement_V6_t* v);
parser_error_t _readKeyOwnerProof_V6(parser_context_t* c, pd_KeyOwnerProof_V6_t* v);
parser_error_t _readKeyValue_V6(parser_context_t* c, pd_KeyValue_V6_t* v);
parser_error_t _readKey_V6(parser_context_t* c, pd_Key_V6_t* v);
parser_error_t _readKeys_V6(parser_context_t* c, pd_Keys_V6_t* v);
parser_error_t _readLookupSource_V6(parser_context_t* c, pd_LookupSource_V6_t* v);
parser_error_t _readMemberCount_V6(parser_context_t* c, pd_MemberCount_V6_t* v);
parser_error_t _readOpaqueCall_V6(parser_context_t* c, pd_OpaqueCall_V6_t* v);
parser_error_t _readOptionAccountId_V6(parser_context_t* c, pd_OptionAccountId_V6_t* v);
parser_error_t _readOptionChangesTrieConfiguration_V6(parser_context_t* c, pd_OptionChangesTrieConfiguration_V6_t* v);
parser_error_t _readOptionPeriod_V6(parser_context_t* c, pd_OptionPeriod_V6_t* v);
parser_error_t _readOptionProxyType_V6(parser_context_t* c, pd_OptionProxyType_V6_t* v);
parser_error_t _readOptionReferendumIndex_V6(parser_context_t* c, pd_OptionReferendumIndex_V6_t* v);
parser_error_t _readOptionStatementKind_V6(parser_context_t* c, pd_OptionStatementKind_V6_t* v);
parser_error_t _readOptionTimepoint_V6(parser_context_t* c, pd_OptionTimepoint_V6_t* v);
parser_error_t _readOptionTupleBalanceOfBalanceOfBlockNumber_V6(parser_context_t* c, pd_OptionTupleBalanceOfBalanceOfBlockNumber_V6_t* v);
parser_error_t _readPerbill_V6(parser_context_t* c, pd_Perbill_V6_t* v);
parser_error_t _readPercent_V6(parser_context_t* c, pd_Percent_V6_t* v);
parser_error_t _readPeriod_V6(parser_context_t* c, pd_Period_V6_t* v);
parser_error_t _readPriority_V6(parser_context_t* c, pd_Priority_V6_t* v);
parser_error_t _readProxyType_V6(parser_context_t* c, pd_ProxyType_V6_t* v);
parser_error_t _readReferendumIndex_V6(parser_context_t* c, pd_ReferendumIndex_V6_t* v);
parser_error_t _readRegistrarIndex_V6(parser_context_t* c, pd_RegistrarIndex_V6_t* v);
parser_error_t _readRenouncing_V6(parser_context_t* c, pd_Renouncing_V6_t* v);
parser_error_t _readRewardDestination_V6(parser_context_t* c, pd_RewardDestination_V6_t* v);
parser_error_t _readSignature_V6(parser_context_t* c, pd_Signature_V6_t* v);
parser_error_t _readStatementKind_V6(parser_context_t* c, pd_StatementKind_V6_t* v);
parser_error_t _readStreamDependency_V6(parser_context_t* c, pd_StreamDependency_V6_t* v);
parser_error_t _readTimepoint_V6(parser_context_t* c, pd_Timepoint_V6_t* v);
parser_error_t _readTupleAccountIdData_V6(parser_context_t* c, pd_TupleAccountIdData_V6_t* v);
parser_error_t _readTupleBalanceOfBalanceOfBlockNumber_V6(parser_context_t* c, pd_TupleBalanceOfBalanceOfBlockNumber_V6_t* v);
parser_error_t _readValidatorIndex_V6(parser_context_t* c, pd_ValidatorIndex_V6_t* v);
parser_error_t _readValidatorPrefs_V6(parser_context_t* c, pd_ValidatorPrefs_V6_t* v);
parser_error_t _readVecAccountId_V6(parser_context_t* c, pd_VecAccountId_V6_t* v);
parser_error_t _readVecKeyValue_V6(parser_context_t* c, pd_VecKeyValue_V6_t* v);
parser_error_t _readVecKey_V6(parser_context_t* c, pd_VecKey_V6_t* v);
parser_error_t _readVecLookupSource_V6(parser_context_t* c, pd_VecLookupSource_V6_t* v);
parser_error_t _readVecTupleAccountIdData_V6(parser_context_t* c, pd_VecTupleAccountIdData_V6_t* v);
parser_error_t _readVecValidatorIndex_V6(parser_context_t* c, pd_VecValidatorIndex_V6_t* v);
parser_error_t _readVestingInfo_V6(parser_context_t* c, pd_VestingInfo_V6_t* v);
parser_error_t _readVote_V6(parser_context_t* c, pd_Vote_V6_t* v);
parser_error_t _readWeight_V6(parser_context_t* c, pd_Weight_V6_t* v);
parser_error_t _readu8_array_32_V6(parser_context_t* c, pd_u8_array_32_V6_t* v);

// toString functions
parser_error_t _toStringAccountId_V6(
    const pd_AccountId_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountIndex_V6(
    const pd_AccountIndex_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountVoteSplit_V6(
    const pd_AccountVoteSplit_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountVoteStandard_V6(
    const pd_AccountVoteStandard_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountVote_V6(
    const pd_AccountVote_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBabeEquivocationProof_V6(
    const pd_BabeEquivocationProof_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCallHashOf_V6(
    const pd_CallHashOf_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringChangesTrieConfiguration_V6(
    const pd_ChangesTrieConfiguration_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactAccountIndex_V6(
    const pd_CompactAccountIndex_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactAssignments_V6(
    const pd_CompactAssignments_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactBountyIndex_V6(
    const pd_CompactBountyIndex_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactEraIndex_V6(
    const pd_CompactEraIndex_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactMemberCount_V6(
    const pd_CompactMemberCount_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactMoment_V6(
    const pd_CompactMoment_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactPerBill_V6(
    const pd_CompactPerBill_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactPropIndex_V6(
    const pd_CompactPropIndex_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactProposalIndex_V6(
    const pd_CompactProposalIndex_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactReferendumIndex_V6(
    const pd_CompactReferendumIndex_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactRegistrarIndex_V6(
    const pd_CompactRegistrarIndex_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactWeight_V6(
    const pd_CompactWeight_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringConviction_V6(
    const pd_Conviction_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEcdsaSignature_V6(
    const pd_EcdsaSignature_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringElectionScore_V6(
    const pd_ElectionScore_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringElectionSize_V6(
    const pd_ElectionSize_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEraIndex_V6(
    const pd_EraIndex_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEthereumAddress_V6(
    const pd_EthereumAddress_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringGrandpaEquivocationProof_V6(
    const pd_GrandpaEquivocationProof_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringIdentityFields_V6(
    const pd_IdentityFields_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringIdentityInfo_V6(
    const pd_IdentityInfo_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringIdentityJudgement_V6(
    const pd_IdentityJudgement_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKeyOwnerProof_V6(
    const pd_KeyOwnerProof_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKeyValue_V6(
    const pd_KeyValue_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKey_V6(
    const pd_Key_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKeys_V6(
    const pd_Keys_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringLookupSource_V6(
    const pd_LookupSource_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMemberCount_V6(
    const pd_MemberCount_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOpaqueCall_V6(
    const pd_OpaqueCall_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionAccountId_V6(
    const pd_OptionAccountId_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionChangesTrieConfiguration_V6(
    const pd_OptionChangesTrieConfiguration_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionPeriod_V6(
    const pd_OptionPeriod_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionProxyType_V6(
    const pd_OptionProxyType_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionReferendumIndex_V6(
    const pd_OptionReferendumIndex_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionStatementKind_V6(
    const pd_OptionStatementKind_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionTimepoint_V6(
    const pd_OptionTimepoint_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionTupleBalanceOfBalanceOfBlockNumber_V6(
    const pd_OptionTupleBalanceOfBalanceOfBlockNumber_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPerbill_V6(
    const pd_Perbill_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPercent_V6(
    const pd_Percent_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPeriod_V6(
    const pd_Period_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPriority_V6(
    const pd_Priority_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringProxyType_V6(
    const pd_ProxyType_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringReferendumIndex_V6(
    const pd_ReferendumIndex_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringRegistrarIndex_V6(
    const pd_RegistrarIndex_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringRenouncing_V6(
    const pd_Renouncing_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringRewardDestination_V6(
    const pd_RewardDestination_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSignature_V6(
    const pd_Signature_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringStatementKind_V6(
    const pd_StatementKind_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringStreamDependency_V6(
    const pd_StreamDependency_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTimepoint_V6(
    const pd_Timepoint_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTupleAccountIdData_V6(
    const pd_TupleAccountIdData_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTupleBalanceOfBalanceOfBlockNumber_V6(
    const pd_TupleBalanceOfBalanceOfBlockNumber_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringValidatorIndex_V6(
    const pd_ValidatorIndex_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringValidatorPrefs_V6(
    const pd_ValidatorPrefs_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecAccountId_V6(
    const pd_VecAccountId_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecKeyValue_V6(
    const pd_VecKeyValue_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecKey_V6(
    const pd_VecKey_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecLookupSource_V6(
    const pd_VecLookupSource_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecTupleAccountIdData_V6(
    const pd_VecTupleAccountIdData_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecValidatorIndex_V6(
    const pd_VecValidatorIndex_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVestingInfo_V6(
    const pd_VestingInfo_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVote_V6(
    const pd_Vote_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringWeight_V6(
    const pd_Weight_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringu8_array_32_V6(
    const pd_u8_array_32_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

#ifdef __cplusplus
}
#endif
