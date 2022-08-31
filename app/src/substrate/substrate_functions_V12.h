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
#include "substrate_methods_V12.h"
#include "substrate_types_V12.h"
#include <stddef.h>
#include <stdint.h>

// Read functions
parser_error_t _readAccountId_V12(parser_context_t* c, pd_AccountId_V12_t* v);
parser_error_t _readAccountIndex_V12(parser_context_t* c, pd_AccountIndex_V12_t* v);
parser_error_t _readAccountVoteSplit_V12(parser_context_t* c, pd_AccountVoteSplit_V12_t* v);
parser_error_t _readAccountVoteStandard_V12(parser_context_t* c, pd_AccountVoteStandard_V12_t* v);
parser_error_t _readAccountVote_V12(parser_context_t* c, pd_AccountVote_V12_t* v);
parser_error_t _readCompactAccountIndex_V12(parser_context_t* c, pd_CompactAccountIndex_V12_t* v);
parser_error_t _readCompactPerBill_V12(parser_context_t* c, pd_CompactPerBill_V12_t* v);
parser_error_t _readConviction_V12(parser_context_t* c, pd_Conviction_V12_t* v);
parser_error_t _readEcdsaPublic_V12(parser_context_t* c, pd_EcdsaPublic_V12_t* v);
parser_error_t _readEcdsaSignature_V12(parser_context_t* c, pd_EcdsaSignature_V12_t* v);
parser_error_t _readEd25519Public_V12(parser_context_t* c, pd_Ed25519Public_V12_t* v);
parser_error_t _readEd25519Signature_V12(parser_context_t* c, pd_Ed25519Signature_V12_t* v);
parser_error_t _readEraIndex_V12(parser_context_t* c, pd_EraIndex_V12_t* v);
parser_error_t _readEthereumAddress_V12(parser_context_t* c, pd_EthereumAddress_V12_t* v);
parser_error_t _readKeys_V12(parser_context_t* c, pd_Keys_V12_t* v);
parser_error_t _readLookupasStaticLookupSource_V12(parser_context_t* c, pd_LookupasStaticLookupSource_V12_t* v);
parser_error_t _readMemberCount_V12(parser_context_t* c, pd_MemberCount_V12_t* v);
parser_error_t _readMultiSignature_V12(parser_context_t* c, pd_MultiSignature_V12_t* v);
parser_error_t _readMultiSigner_V12(parser_context_t* c, pd_MultiSigner_V12_t* v);
parser_error_t _readOpaqueCall_V12(parser_context_t* c, pd_OpaqueCall_V12_t* v);
parser_error_t _readOptionAccountId_V12(parser_context_t* c, pd_OptionAccountId_V12_t* v);
parser_error_t _readOptionMultiSignature_V12(parser_context_t* c, pd_OptionMultiSignature_V12_t* v);
parser_error_t _readOptionMultiSigner_V12(parser_context_t* c, pd_OptionMultiSigner_V12_t* v);
parser_error_t _readOptionProxyType_V12(parser_context_t* c, pd_OptionProxyType_V12_t* v);
parser_error_t _readOptionTimepoint_V12(parser_context_t* c, pd_OptionTimepoint_V12_t* v);
parser_error_t _readParaId_V12(parser_context_t* c, pd_ParaId_V12_t* v);
parser_error_t _readPerbill_V12(parser_context_t* c, pd_Perbill_V12_t* v);
parser_error_t _readProxyType_V12(parser_context_t* c, pd_ProxyType_V12_t* v);
parser_error_t _readReferendumIndex_V12(parser_context_t* c, pd_ReferendumIndex_V12_t* v);
parser_error_t _readRegistrarIndex_V12(parser_context_t* c, pd_RegistrarIndex_V12_t* v);
parser_error_t _readRewardDestination_V12(parser_context_t* c, pd_RewardDestination_V12_t* v);
parser_error_t _readSessionIndex_V12(parser_context_t* c, pd_SessionIndex_V12_t* v);
parser_error_t _readSr25519Public_V12(parser_context_t* c, pd_Sr25519Public_V12_t* v);
parser_error_t _readSr25519Signature_V12(parser_context_t* c, pd_Sr25519Signature_V12_t* v);
parser_error_t _readTimepoint_V12(parser_context_t* c, pd_Timepoint_V12_t* v);
parser_error_t _readValidatorPrefs_V12(parser_context_t* c, pd_ValidatorPrefs_V12_t* v);
parser_error_t _readVecAccountId_V12(parser_context_t* c, pd_VecAccountId_V12_t* v);
parser_error_t _readVecLookupasStaticLookupSource_V12(parser_context_t* c, pd_VecLookupasStaticLookupSource_V12_t* v);
parser_error_t _readVestingInfo_V12(parser_context_t* c, pd_VestingInfo_V12_t* v);
parser_error_t _readVote_V12(parser_context_t* c, pd_Vote_V12_t* v);
parser_error_t _readWeight_V12(parser_context_t* c, pd_Weight_V12_t* v);

// toString functions
parser_error_t _toStringAccountId_V12(
    const pd_AccountId_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountIndex_V12(
    const pd_AccountIndex_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountVoteSplit_V12(
    const pd_AccountVoteSplit_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountVoteStandard_V12(
    const pd_AccountVoteStandard_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountVote_V12(
    const pd_AccountVote_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactAccountIndex_V12(
    const pd_CompactAccountIndex_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactPerBill_V12(
    const pd_CompactPerBill_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringConviction_V12(
    const pd_Conviction_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEcdsaPublic_V12(
    const pd_EcdsaPublic_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEcdsaSignature_V12(
    const pd_EcdsaSignature_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEd25519Public_V12(
    const pd_Ed25519Public_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEd25519Signature_V12(
    const pd_Ed25519Signature_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEraIndex_V12(
    const pd_EraIndex_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEthereumAddress_V12(
    const pd_EthereumAddress_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKeys_V12(
    const pd_Keys_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringLookupasStaticLookupSource_V12(
    const pd_LookupasStaticLookupSource_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMemberCount_V12(
    const pd_MemberCount_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMultiSignature_V12(
    const pd_MultiSignature_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMultiSigner_V12(
    const pd_MultiSigner_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOpaqueCall_V12(
    const pd_OpaqueCall_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionAccountId_V12(
    const pd_OptionAccountId_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionMultiSignature_V12(
    const pd_OptionMultiSignature_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionMultiSigner_V12(
    const pd_OptionMultiSigner_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionProxyType_V12(
    const pd_OptionProxyType_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionTimepoint_V12(
    const pd_OptionTimepoint_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringParaId_V12(
    const pd_ParaId_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPerbill_V12(
    const pd_Perbill_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringProxyType_V12(
    const pd_ProxyType_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringReferendumIndex_V12(
    const pd_ReferendumIndex_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringRegistrarIndex_V12(
    const pd_RegistrarIndex_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringRewardDestination_V12(
    const pd_RewardDestination_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSessionIndex_V12(
    const pd_SessionIndex_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSr25519Public_V12(
    const pd_Sr25519Public_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSr25519Signature_V12(
    const pd_Sr25519Signature_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTimepoint_V12(
    const pd_Timepoint_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringValidatorPrefs_V12(
    const pd_ValidatorPrefs_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecAccountId_V12(
    const pd_VecAccountId_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecLookupasStaticLookupSource_V12(
    const pd_VecLookupasStaticLookupSource_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVestingInfo_V12(
    const pd_VestingInfo_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVote_V12(
    const pd_Vote_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringWeight_V12(
    const pd_Weight_V12_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

#ifdef __cplusplus
}
#endif
