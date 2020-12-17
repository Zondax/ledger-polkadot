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
#include <stddef.h>
#include <stdint.h>

parser_error_t _readAddress(parser_context_t* c, pd_Address_t* v);

parser_error_t _readCompactBalance(parser_context_t* c, pd_CompactBalance_t* v);

parser_error_t _readHash(parser_context_t* c, pd_Hash_t* v);

parser_error_t _toStringAddress(const pd_Address_t* v,
    char* outValue, uint16_t outValueLen,
    uint8_t pageIdx, uint8_t* pageCount);

parser_error_t _toStringCompactBalance(const pd_CompactBalance_t* v,
    char* outValue, uint16_t outValueLen,
    uint8_t pageIdx, uint8_t* pageCount);

parser_error_t _toStringHash(const pd_Hash_t* v,
    char* outValue, uint16_t outValueLen,
    uint8_t pageIdx, uint8_t* pageCount);

// Read functions

parser_error_t _readAccountId(parser_context_t* c, pd_AccountId_t* v);
parser_error_t _readAccountIndex(parser_context_t* c, pd_AccountIndex_t* v);
parser_error_t _readAccountVoteSplit(parser_context_t* c, pd_AccountVoteSplit_t* v);
parser_error_t _readAccountVoteStandard(parser_context_t* c, pd_AccountVoteStandard_t* v);
parser_error_t _readAccountVote(parser_context_t* c, pd_AccountVote_t* v);
parser_error_t _readBalanceOf(parser_context_t* c, pd_BalanceOf_t* v);
parser_error_t _readBlockNumber(parser_context_t* c, pd_BlockNumber_t* v);
parser_error_t _readBytes(parser_context_t* c, pd_Bytes_t* v);
parser_error_t _readCallHashOf(parser_context_t* c, pd_CallHashOf_t* v);
parser_error_t _readCall(parser_context_t* c, pd_Call_t* v);
parser_error_t _readChangesTrieConfiguration(parser_context_t* c, pd_ChangesTrieConfiguration_t* v);
parser_error_t _readCompactAssignments(parser_context_t* c, pd_CompactAssignments_t* v);
parser_error_t _readCompactBalanceOf(parser_context_t* c, pd_CompactBalanceOf_t* v);
parser_error_t _readCompactBlockNumber(parser_context_t* c, pd_CompactBlockNumber_t* v);
parser_error_t _readCompactBountyIndex(parser_context_t* c, pd_CompactBountyIndex_t* v);
parser_error_t _readCompactEraIndex(parser_context_t* c, pd_CompactEraIndex_t* v);
parser_error_t _readCompactMemberCount(parser_context_t* c, pd_CompactMemberCount_t* v);
parser_error_t _readCompactMoment(parser_context_t* c, pd_CompactMoment_t* v);
parser_error_t _readCompactPerBill(parser_context_t* c, pd_CompactPerBill_t* v);
parser_error_t _readCompactPropIndex(parser_context_t* c, pd_CompactPropIndex_t* v);
parser_error_t _readCompactProposalIndex(parser_context_t* c, pd_CompactProposalIndex_t* v);
parser_error_t _readCompactReferendumIndex(parser_context_t* c, pd_CompactReferendumIndex_t* v);
parser_error_t _readCompactRegistrarIndex(parser_context_t* c, pd_CompactRegistrarIndex_t* v);
parser_error_t _readCompactWeight(parser_context_t* c, pd_CompactWeight_t* v);
parser_error_t _readCompactu32(parser_context_t* c, pd_Compactu32_t* v);
parser_error_t _readConviction(parser_context_t* c, pd_Conviction_t* v);
parser_error_t _readData(parser_context_t* c, pd_Data_t* v);
parser_error_t _readDefunctVoter(parser_context_t* c, pd_DefunctVoter_t* v);
parser_error_t _readEcdsaSignature(parser_context_t* c, pd_EcdsaSignature_t* v);
parser_error_t _readElectionScore(parser_context_t* c, pd_ElectionScore_t* v);
parser_error_t _readElectionSize(parser_context_t* c, pd_ElectionSize_t* v);
parser_error_t _readEquivocationProof(parser_context_t* c, pd_EquivocationProof_t* v);
parser_error_t _readEraIndex(parser_context_t* c, pd_EraIndex_t* v);
parser_error_t _readEthereumAddress(parser_context_t* c, pd_EthereumAddress_t* v);
parser_error_t _readHeader(parser_context_t* c, pd_Header_t* v);
parser_error_t _readHeartbeat(parser_context_t* c, pd_Heartbeat_t* v);
parser_error_t _readIdentityFields(parser_context_t* c, pd_IdentityFields_t* v);
parser_error_t _readIdentityInfo(parser_context_t* c, pd_IdentityInfo_t* v);
parser_error_t _readJudgement(parser_context_t* c, pd_Judgement_t* v);
parser_error_t _readKeyOwnerProof(parser_context_t* c, pd_KeyOwnerProof_t* v);
parser_error_t _readKeyValue(parser_context_t* c, pd_KeyValue_t* v);
parser_error_t _readKey(parser_context_t* c, pd_Key_t* v);
parser_error_t _readKeys(parser_context_t* c, pd_Keys_t* v);
parser_error_t _readLookupSource(parser_context_t* c, pd_LookupSource_t* v);
parser_error_t _readMemberCount(parser_context_t* c, pd_MemberCount_t* v);
parser_error_t _readOpaqueCall(parser_context_t* c, pd_OpaqueCall_t* v);
parser_error_t _readOptionAccountId(parser_context_t* c, pd_OptionAccountId_t* v);
parser_error_t _readOptionChangesTrieConfiguration(parser_context_t* c, pd_OptionChangesTrieConfiguration_t* v);
parser_error_t _readOptionPeriod(parser_context_t* c, pd_OptionPeriod_t* v);
parser_error_t _readOptionProxyType(parser_context_t* c, pd_OptionProxyType_t* v);
parser_error_t _readOptionReferendumIndex(parser_context_t* c, pd_OptionReferendumIndex_t* v);
parser_error_t _readOptionStatementKind(parser_context_t* c, pd_OptionStatementKind_t* v);
parser_error_t _readOptionTimepoint(parser_context_t* c, pd_OptionTimepoint_t* v);
parser_error_t _readOptionTupleBalanceOfBalanceOfBlockNumber(parser_context_t* c, pd_OptionTupleBalanceOfBalanceOfBlockNumber_t* v);
parser_error_t _readOptionu8_array_20(parser_context_t* c, pd_Optionu8_array_20_t* v);
parser_error_t _readPerbill(parser_context_t* c, pd_Perbill_t* v);
parser_error_t _readPercent(parser_context_t* c, pd_Percent_t* v);
parser_error_t _readPeriod(parser_context_t* c, pd_Period_t* v);
parser_error_t _readPriority(parser_context_t* c, pd_Priority_t* v);
parser_error_t _readProxyType(parser_context_t* c, pd_ProxyType_t* v);
parser_error_t _readReferendumIndex(parser_context_t* c, pd_ReferendumIndex_t* v);
parser_error_t _readRegistrarIndex(parser_context_t* c, pd_RegistrarIndex_t* v);
parser_error_t _readRenouncing(parser_context_t* c, pd_Renouncing_t* v);
parser_error_t _readRewardDestination(parser_context_t* c, pd_RewardDestination_t* v);
parser_error_t _readSignature(parser_context_t* c, pd_Signature_t* v);
parser_error_t _readStatementKind(parser_context_t* c, pd_StatementKind_t* v);
parser_error_t _readStreamDependency(parser_context_t* c, pd_StreamDependency_t* v);
parser_error_t _readTimepoint(parser_context_t* c, pd_Timepoint_t* v);
parser_error_t _readTupleAccountIdData(parser_context_t* c, pd_TupleAccountIdData_t* v);
parser_error_t _readTupleBalanceOfBalanceOfBlockNumber(parser_context_t* c, pd_TupleBalanceOfBalanceOfBlockNumber_t* v);
parser_error_t _readTupleDataData(parser_context_t* c, pd_TupleDataData_t* v);
parser_error_t _readValidatorIndex(parser_context_t* c, pd_ValidatorIndex_t* v);
parser_error_t _readValidatorPrefs(parser_context_t* c, pd_ValidatorPrefs_t* v);
parser_error_t _readVecAccountId(parser_context_t* c, pd_VecAccountId_t* v);
parser_error_t _readVecCall(parser_context_t* c, pd_VecCall_t* v);
parser_error_t _readVecHeader(parser_context_t* c, pd_VecHeader_t* v);
parser_error_t _readVecKeyValue(parser_context_t* c, pd_VecKeyValue_t* v);
parser_error_t _readVecKey(parser_context_t* c, pd_VecKey_t* v);
parser_error_t _readVecLookupSource(parser_context_t* c, pd_VecLookupSource_t* v);
parser_error_t _readVecTupleAccountIdData(parser_context_t* c, pd_VecTupleAccountIdData_t* v);
parser_error_t _readVecTupleDataData(parser_context_t* c, pd_VecTupleDataData_t* v);
parser_error_t _readVecValidatorIndex(parser_context_t* c, pd_VecValidatorIndex_t* v);
parser_error_t _readVecu32(parser_context_t* c, pd_Vecu32_t* v);
parser_error_t _readVestingInfo(parser_context_t* c, pd_VestingInfo_t* v);
parser_error_t _readVote(parser_context_t* c, pd_Vote_t* v);
parser_error_t _readWeight(parser_context_t* c, pd_Weight_t* v);
parser_error_t _readbool(parser_context_t* c, pd_bool_t* v);
parser_error_t _readu16(parser_context_t* c, pd_u16_t* v);
parser_error_t _readu32(parser_context_t* c, pd_u32_t* v);
parser_error_t _readu64(parser_context_t* c, pd_u64_t* v);
parser_error_t _readu8_array_20(parser_context_t* c, pd_u8_array_20_t* v);
parser_error_t _readu8_array_32(parser_context_t* c, pd_u8_array_32_t* v);

// toString functions

parser_error_t _toStringAccountId(
    const pd_AccountId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountIndex(
    const pd_AccountIndex_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountVoteSplit(
    const pd_AccountVoteSplit_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountVoteStandard(
    const pd_AccountVoteStandard_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountVote(
    const pd_AccountVote_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBalanceOf(
    const pd_BalanceOf_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBlockNumber(
    const pd_BlockNumber_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBytes(
    const pd_Bytes_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCallHashOf(
    const pd_CallHashOf_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCall(
    const pd_Call_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringChangesTrieConfiguration(
    const pd_ChangesTrieConfiguration_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactAssignments(
    const pd_CompactAssignments_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactBalanceOf(
    const pd_CompactBalanceOf_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactBlockNumber(
    const pd_CompactBlockNumber_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactBountyIndex(
    const pd_CompactBountyIndex_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactEraIndex(
    const pd_CompactEraIndex_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactMemberCount(
    const pd_CompactMemberCount_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactMoment(
    const pd_CompactMoment_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactPerBill(
    const pd_CompactPerBill_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactPropIndex(
    const pd_CompactPropIndex_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactProposalIndex(
    const pd_CompactProposalIndex_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactReferendumIndex(
    const pd_CompactReferendumIndex_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactRegistrarIndex(
    const pd_CompactRegistrarIndex_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactWeight(
    const pd_CompactWeight_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactu32(
    const pd_Compactu32_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringConviction(
    const pd_Conviction_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringData(
    const pd_Data_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringDefunctVoter(
    const pd_DefunctVoter_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEcdsaSignature(
    const pd_EcdsaSignature_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringElectionScore(
    const pd_ElectionScore_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringElectionSize(
    const pd_ElectionSize_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEquivocationProof(
    const pd_EquivocationProof_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEraIndex(
    const pd_EraIndex_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEthereumAddress(
    const pd_EthereumAddress_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringHeader(
    const pd_Header_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringHeartbeat(
    const pd_Heartbeat_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringIdentityFields(
    const pd_IdentityFields_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringIdentityInfo(
    const pd_IdentityInfo_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJudgement(
    const pd_Judgement_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKeyOwnerProof(
    const pd_KeyOwnerProof_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKeyValue(
    const pd_KeyValue_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKey(
    const pd_Key_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKeys(
    const pd_Keys_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringLookupSource(
    const pd_LookupSource_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMemberCount(
    const pd_MemberCount_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOpaqueCall(
    const pd_OpaqueCall_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionAccountId(
    const pd_OptionAccountId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionChangesTrieConfiguration(
    const pd_OptionChangesTrieConfiguration_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionPeriod(
    const pd_OptionPeriod_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionProxyType(
    const pd_OptionProxyType_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionReferendumIndex(
    const pd_OptionReferendumIndex_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionStatementKind(
    const pd_OptionStatementKind_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionTimepoint(
    const pd_OptionTimepoint_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionTupleBalanceOfBalanceOfBlockNumber(
    const pd_OptionTupleBalanceOfBalanceOfBlockNumber_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionu8_array_20(
    const pd_Optionu8_array_20_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPerbill(
    const pd_Perbill_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPercent(
    const pd_Percent_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPeriod(
    const pd_Period_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPriority(
    const pd_Priority_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringProxyType(
    const pd_ProxyType_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringReferendumIndex(
    const pd_ReferendumIndex_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringRegistrarIndex(
    const pd_RegistrarIndex_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringRenouncing(
    const pd_Renouncing_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringRewardDestination(
    const pd_RewardDestination_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSignature(
    const pd_Signature_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringStatementKind(
    const pd_StatementKind_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringStreamDependency(
    const pd_StreamDependency_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTimepoint(
    const pd_Timepoint_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTupleAccountIdData(
    const pd_TupleAccountIdData_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTupleBalanceOfBalanceOfBlockNumber(
    const pd_TupleBalanceOfBalanceOfBlockNumber_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTupleDataData(
    const pd_TupleDataData_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringValidatorIndex(
    const pd_ValidatorIndex_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringValidatorPrefs(
    const pd_ValidatorPrefs_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecAccountId(
    const pd_VecAccountId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecCall(
    const pd_VecCall_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecHeader(
    const pd_VecHeader_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecKeyValue(
    const pd_VecKeyValue_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecKey(
    const pd_VecKey_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecLookupSource(
    const pd_VecLookupSource_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecTupleAccountIdData(
    const pd_VecTupleAccountIdData_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecTupleDataData(
    const pd_VecTupleDataData_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecValidatorIndex(
    const pd_VecValidatorIndex_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecu32(
    const pd_Vecu32_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVestingInfo(
    const pd_VestingInfo_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVote(
    const pd_Vote_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringWeight(
    const pd_Weight_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringbool(
    const pd_bool_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringu16(
    const pd_u16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringu32(
    const pd_u32_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringu64(
    const pd_u64_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringu8_array_20(
    const pd_u8_array_20_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringu8_array_32(
    const pd_u8_array_32_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _readProposal(parser_context_t* c, pd_Proposal_t* v);
parser_error_t _toStringProposal(
    const pd_Proposal_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

#ifdef __cplusplus
}
#endif
