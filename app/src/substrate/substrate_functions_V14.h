/*******************************************************************************
 *  (c) 2019 - 2022 Zondax AG
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
#include "substrate_methods_V14.h"
#include "substrate_types_V14.h"
#include <stddef.h>
#include <stdint.h>

// Read functions
parser_error_t _readAccountIdLookupOfT_V14(parser_context_t* c, pd_AccountIdLookupOfT_V14_t* v);
parser_error_t _readAccountId_V14(parser_context_t* c, pd_AccountId_V14_t* v);
parser_error_t _readAccountIndex_V14(parser_context_t* c, pd_AccountIndex_V14_t* v);
parser_error_t _readAccountVoteSplit_V14(parser_context_t* c, pd_AccountVoteSplit_V14_t* v);
parser_error_t _readAccountVoteStandard_V14(parser_context_t* c, pd_AccountVoteStandard_V14_t* v);
parser_error_t _readAccountVote_V14(parser_context_t* c, pd_AccountVote_V14_t* v);
parser_error_t _readBondExtraBalanceOfT_V14(parser_context_t* c, pd_BondExtraBalanceOfT_V14_t* v);
parser_error_t _readCompactAccountIndex_V14(parser_context_t* c, pd_CompactAccountIndex_V14_t* v);
parser_error_t _readCompactPerBill_V14(parser_context_t* c, pd_CompactPerBill_V14_t* v);
parser_error_t _readConfigOpAccountId_V14(parser_context_t* c, pd_ConfigOpAccountId_V14_t* v);
parser_error_t _readConfigOpBalanceOfT_V14(parser_context_t* c, pd_ConfigOpBalanceOfT_V14_t* v);
parser_error_t _readConfigOpu32_V14(parser_context_t* c, pd_ConfigOpu32_V14_t* v);
parser_error_t _readConviction_V14(parser_context_t* c, pd_Conviction_V14_t* v);
parser_error_t _readEcdsaPublic_V14(parser_context_t* c, pd_EcdsaPublic_V14_t* v);
parser_error_t _readEcdsaSignature_V14(parser_context_t* c, pd_EcdsaSignature_V14_t* v);
parser_error_t _readEd25519Public_V14(parser_context_t* c, pd_Ed25519Public_V14_t* v);
parser_error_t _readEd25519Signature_V14(parser_context_t* c, pd_Ed25519Signature_V14_t* v);
parser_error_t _readEraIndex_V14(parser_context_t* c, pd_EraIndex_V14_t* v);
parser_error_t _readEthereumAddress_V14(parser_context_t* c, pd_EthereumAddress_V14_t* v);
parser_error_t _readKeys_V14(parser_context_t* c, pd_Keys_V14_t* v);
parser_error_t _readMemberCount_V14(parser_context_t* c, pd_MemberCount_V14_t* v);
parser_error_t _readMultiSignature_V14(parser_context_t* c, pd_MultiSignature_V14_t* v);
parser_error_t _readMultiSigner_V14(parser_context_t* c, pd_MultiSigner_V14_t* v);
parser_error_t _readOpaqueCall_V14(parser_context_t* c, pd_OpaqueCall_V14_t* v);
parser_error_t _readOptionAccountId_V14(parser_context_t* c, pd_OptionAccountId_V14_t* v);
parser_error_t _readOptionMultiSignature_V14(parser_context_t* c, pd_OptionMultiSignature_V14_t* v);
parser_error_t _readOptionMultiSigner_V14(parser_context_t* c, pd_OptionMultiSigner_V14_t* v);
parser_error_t _readOptionProxyType_V14(parser_context_t* c, pd_OptionProxyType_V14_t* v);
parser_error_t _readOptionTimepoint_V14(parser_context_t* c, pd_OptionTimepoint_V14_t* v);
parser_error_t _readOverweightIndex_V14(parser_context_t* c, pd_OverweightIndex_V14_t* v);
parser_error_t _readParaId_V14(parser_context_t* c, pd_ParaId_V14_t* v);
parser_error_t _readPerbill_V14(parser_context_t* c, pd_Perbill_V14_t* v);
parser_error_t _readPoolId_V14(parser_context_t* c, pd_PoolId_V14_t* v);
parser_error_t _readPoolState_V14(parser_context_t* c, pd_PoolState_V14_t* v);
parser_error_t _readProxyType_V14(parser_context_t* c, pd_ProxyType_V14_t* v);
parser_error_t _readReferendumIndex_V14(parser_context_t* c, pd_ReferendumIndex_V14_t* v);
parser_error_t _readRegistrarIndex_V14(parser_context_t* c, pd_RegistrarIndex_V14_t* v);
parser_error_t _readRewardDestination_V14(parser_context_t* c, pd_RewardDestination_V14_t* v);
parser_error_t _readSessionIndex_V14(parser_context_t* c, pd_SessionIndex_V14_t* v);
parser_error_t _readSr25519Public_V14(parser_context_t* c, pd_Sr25519Public_V14_t* v);
parser_error_t _readSr25519Signature_V14(parser_context_t* c, pd_Sr25519Signature_V14_t* v);
parser_error_t _readTimepoint_V14(parser_context_t* c, pd_Timepoint_V14_t* v);
parser_error_t _readValidatorPrefs_V14(parser_context_t* c, pd_ValidatorPrefs_V14_t* v);
parser_error_t _readVecAccountIdLookupOfT_V14(parser_context_t* c, pd_VecAccountIdLookupOfT_V14_t* v);
parser_error_t _readVecAccountId_V14(parser_context_t* c, pd_VecAccountId_V14_t* v);
parser_error_t _readVestingInfo_V14(parser_context_t* c, pd_VestingInfo_V14_t* v);
parser_error_t _readVote_V14(parser_context_t* c, pd_Vote_V14_t* v);
parser_error_t _readWeight_V14(parser_context_t* c, pd_Weight_V14_t* v);

// toString functions
parser_error_t _toStringAccountIdLookupOfT_V14(
    const pd_AccountIdLookupOfT_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountId_V14(
    const pd_AccountId_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountIndex_V14(
    const pd_AccountIndex_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountVoteSplit_V14(
    const pd_AccountVoteSplit_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountVoteStandard_V14(
    const pd_AccountVoteStandard_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountVote_V14(
    const pd_AccountVote_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBondExtraBalanceOfT_V14(
    const pd_BondExtraBalanceOfT_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactAccountIndex_V14(
    const pd_CompactAccountIndex_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactPerBill_V14(
    const pd_CompactPerBill_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringConfigOpAccountId_V14(
    const pd_ConfigOpAccountId_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringConfigOpBalanceOfT_V14(
    const pd_ConfigOpBalanceOfT_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringConfigOpu32_V14(
    const pd_ConfigOpu32_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringConviction_V14(
    const pd_Conviction_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEcdsaPublic_V14(
    const pd_EcdsaPublic_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEcdsaSignature_V14(
    const pd_EcdsaSignature_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEd25519Public_V14(
    const pd_Ed25519Public_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEd25519Signature_V14(
    const pd_Ed25519Signature_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEraIndex_V14(
    const pd_EraIndex_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEthereumAddress_V14(
    const pd_EthereumAddress_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKeys_V14(
    const pd_Keys_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMemberCount_V14(
    const pd_MemberCount_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMultiSignature_V14(
    const pd_MultiSignature_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMultiSigner_V14(
    const pd_MultiSigner_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOpaqueCall_V14(
    const pd_OpaqueCall_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionAccountId_V14(
    const pd_OptionAccountId_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionMultiSignature_V14(
    const pd_OptionMultiSignature_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionMultiSigner_V14(
    const pd_OptionMultiSigner_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionProxyType_V14(
    const pd_OptionProxyType_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionTimepoint_V14(
    const pd_OptionTimepoint_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOverweightIndex_V14(
    const pd_OverweightIndex_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringParaId_V14(
    const pd_ParaId_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPerbill_V14(
    const pd_Perbill_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPoolId_V14(
    const pd_PoolId_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPoolState_V14(
    const pd_PoolState_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringProxyType_V14(
    const pd_ProxyType_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringReferendumIndex_V14(
    const pd_ReferendumIndex_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringRegistrarIndex_V14(
    const pd_RegistrarIndex_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringRewardDestination_V14(
    const pd_RewardDestination_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSessionIndex_V14(
    const pd_SessionIndex_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSr25519Public_V14(
    const pd_Sr25519Public_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSr25519Signature_V14(
    const pd_Sr25519Signature_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTimepoint_V14(
    const pd_Timepoint_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringValidatorPrefs_V14(
    const pd_ValidatorPrefs_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecAccountIdLookupOfT_V14(
    const pd_VecAccountIdLookupOfT_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecAccountId_V14(
    const pd_VecAccountId_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVestingInfo_V14(
    const pd_VestingInfo_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVote_V14(
    const pd_Vote_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringWeight_V14(
    const pd_Weight_V14_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

#ifdef __cplusplus
}
#endif
