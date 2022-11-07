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
#include "substrate_methods_V16.h"
#include "substrate_types_V16.h"
#include <stddef.h>
#include <stdint.h>

// Read functions
parser_error_t _readAbstractFungible_V16(parser_context_t* c, pd_AbstractFungible_V16_t* v);
parser_error_t _readAbstractNonFungible_V16(parser_context_t* c, pd_AbstractNonFungible_V16_t* v);
parser_error_t _readAccountId32_V16(parser_context_t* c, pd_AccountId32_V16_t* v);
parser_error_t _readAccountIdLookupOfT_V16(parser_context_t* c, pd_AccountIdLookupOfT_V16_t* v);
parser_error_t _readAccountId_V16(parser_context_t* c, pd_AccountId_V16_t* v);
parser_error_t _readAccountIndex64_V16(parser_context_t* c, pd_AccountIndex64_V16_t* v);
parser_error_t _readAccountIndex_V16(parser_context_t* c, pd_AccountIndex_V16_t* v);
parser_error_t _readAccountKey20_V16(parser_context_t* c, pd_AccountKey20_V16_t* v);
parser_error_t _readAccountVoteSplit_V16(parser_context_t* c, pd_AccountVoteSplit_V16_t* v);
parser_error_t _readAccountVoteStandard_V16(parser_context_t* c, pd_AccountVoteStandard_V16_t* v);
parser_error_t _readAccountVote_V16(parser_context_t* c, pd_AccountVote_V16_t* v);
parser_error_t _readAssetInstance_V16(parser_context_t* c, pd_AssetInstance_V16_t* v);
parser_error_t _readBodyId_V16(parser_context_t* c, pd_BodyId_V16_t* v);
parser_error_t _readBodyPart_V16(parser_context_t* c, pd_BodyPart_V16_t* v);
parser_error_t _readBondExtraBalanceOfT_V16(parser_context_t* c, pd_BondExtraBalanceOfT_V16_t* v);
parser_error_t _readBoundedCallOfT_V16(parser_context_t* c, pd_BoundedCallOfT_V16_t* v);
parser_error_t _readBoxVersionedMultiAssets_V16(parser_context_t* c, pd_BoxVersionedMultiAssets_V16_t* v);
parser_error_t _readBoxVersionedMultiLocation_V16(parser_context_t* c, pd_BoxVersionedMultiLocation_V16_t* v);
parser_error_t _readCompactAccountIndex_V16(parser_context_t* c, pd_CompactAccountIndex_V16_t* v);
parser_error_t _readCompactPerBill_V16(parser_context_t* c, pd_CompactPerBill_V16_t* v);
parser_error_t _readConcreteFungible_V16(parser_context_t* c, pd_ConcreteFungible_V16_t* v);
parser_error_t _readConcreteNonFungible_V16(parser_context_t* c, pd_ConcreteNonFungible_V16_t* v);
parser_error_t _readConfigOpAccountId_V16(parser_context_t* c, pd_ConfigOpAccountId_V16_t* v);
parser_error_t _readConfigOpBalanceOfT_V16(parser_context_t* c, pd_ConfigOpBalanceOfT_V16_t* v);
parser_error_t _readConfigOpPerbill_V16(parser_context_t* c, pd_ConfigOpPerbill_V16_t* v);
parser_error_t _readConfigOpPercent_V16(parser_context_t* c, pd_ConfigOpPercent_V16_t* v);
parser_error_t _readConfigOpu32_V16(parser_context_t* c, pd_ConfigOpu32_V16_t* v);
parser_error_t _readConviction_V16(parser_context_t* c, pd_Conviction_V16_t* v);
parser_error_t _readEcdsaPublic_V16(parser_context_t* c, pd_EcdsaPublic_V16_t* v);
parser_error_t _readEcdsaSignature_V16(parser_context_t* c, pd_EcdsaSignature_V16_t* v);
parser_error_t _readEd25519Public_V16(parser_context_t* c, pd_Ed25519Public_V16_t* v);
parser_error_t _readEd25519Signature_V16(parser_context_t* c, pd_Ed25519Signature_V16_t* v);
parser_error_t _readEraIndex_V16(parser_context_t* c, pd_EraIndex_V16_t* v);
parser_error_t _readEthereumAddress_V16(parser_context_t* c, pd_EthereumAddress_V16_t* v);
parser_error_t _readFraction_V16(parser_context_t* c, pd_Fraction_V16_t* v);
parser_error_t _readFungibility_V16(parser_context_t* c, pd_Fungibility_V16_t* v);
parser_error_t _readIdentityInfo_V16(parser_context_t* c, pd_IdentityInfo_V16_t* v);
parser_error_t _readJudgementBalanceOfT_V16(parser_context_t* c, pd_JudgementBalanceOfT_V16_t* v);
parser_error_t _readJunctionV0X1_V16(parser_context_t* c, pd_JunctionV0X1_V16_t* v);
parser_error_t _readJunctionV0X2_V16(parser_context_t* c, pd_JunctionV0X2_V16_t* v);
parser_error_t _readJunctionV0X3_V16(parser_context_t* c, pd_JunctionV0X3_V16_t* v);
parser_error_t _readJunctionV0X4_V16(parser_context_t* c, pd_JunctionV0X4_V16_t* v);
parser_error_t _readJunctionV0X5_V16(parser_context_t* c, pd_JunctionV0X5_V16_t* v);
parser_error_t _readJunctionV0X6_V16(parser_context_t* c, pd_JunctionV0X6_V16_t* v);
parser_error_t _readJunctionV0X7_V16(parser_context_t* c, pd_JunctionV0X7_V16_t* v);
parser_error_t _readJunctionV0X8_V16(parser_context_t* c, pd_JunctionV0X8_V16_t* v);
parser_error_t _readJunctionV0_V16(parser_context_t* c, pd_JunctionV0_V16_t* v);
parser_error_t _readJunctionV1X1_V16(parser_context_t* c, pd_JunctionV1X1_V16_t* v);
parser_error_t _readJunctionV1X2_V16(parser_context_t* c, pd_JunctionV1X2_V16_t* v);
parser_error_t _readJunctionV1X3_V16(parser_context_t* c, pd_JunctionV1X3_V16_t* v);
parser_error_t _readJunctionV1X4_V16(parser_context_t* c, pd_JunctionV1X4_V16_t* v);
parser_error_t _readJunctionV1X5_V16(parser_context_t* c, pd_JunctionV1X5_V16_t* v);
parser_error_t _readJunctionV1X6_V16(parser_context_t* c, pd_JunctionV1X6_V16_t* v);
parser_error_t _readJunctionV1X7_V16(parser_context_t* c, pd_JunctionV1X7_V16_t* v);
parser_error_t _readJunctionV1X8_V16(parser_context_t* c, pd_JunctionV1X8_V16_t* v);
parser_error_t _readJunctionV1_V16(parser_context_t* c, pd_JunctionV1_V16_t* v);
parser_error_t _readJunctionsV0_V16(parser_context_t* c, pd_JunctionsV0_V16_t* v);
parser_error_t _readJunctionsV1_V16(parser_context_t* c, pd_JunctionsV1_V16_t* v);
parser_error_t _readKeys_V16(parser_context_t* c, pd_Keys_V16_t* v);
parser_error_t _readMemberCount_V16(parser_context_t* c, pd_MemberCount_V16_t* v);
parser_error_t _readMultiAssetId_V16(parser_context_t* c, pd_MultiAssetId_V16_t* v);
parser_error_t _readMultiAssetV0_V16(parser_context_t* c, pd_MultiAssetV0_V16_t* v);
parser_error_t _readMultiAssetV1_V16(parser_context_t* c, pd_MultiAssetV1_V16_t* v);
parser_error_t _readMultiLocationV0_V16(parser_context_t* c, pd_MultiLocationV0_V16_t* v);
parser_error_t _readMultiLocationV1_V16(parser_context_t* c, pd_MultiLocationV1_V16_t* v);
parser_error_t _readMultiSignature_V16(parser_context_t* c, pd_MultiSignature_V16_t* v);
parser_error_t _readMultiSigner_V16(parser_context_t* c, pd_MultiSigner_V16_t* v);
parser_error_t _readNetworkId_V16(parser_context_t* c, pd_NetworkId_V16_t* v);
parser_error_t _readOptionAccountId_V16(parser_context_t* c, pd_OptionAccountId_V16_t* v);
parser_error_t _readOptionMultiSignature_V16(parser_context_t* c, pd_OptionMultiSignature_V16_t* v);
parser_error_t _readOptionMultiSigner_V16(parser_context_t* c, pd_OptionMultiSigner_V16_t* v);
parser_error_t _readOptionProxyType_V16(parser_context_t* c, pd_OptionProxyType_V16_t* v);
parser_error_t _readOptionReferendumIndex_V16(parser_context_t* c, pd_OptionReferendumIndex_V16_t* v);
parser_error_t _readOptionTimepoint_V16(parser_context_t* c, pd_OptionTimepoint_V16_t* v);
parser_error_t _readOverweightIndex_V16(parser_context_t* c, pd_OverweightIndex_V16_t* v);
parser_error_t _readParaId_V16(parser_context_t* c, pd_ParaId_V16_t* v);
parser_error_t _readPerbill_V16(parser_context_t* c, pd_Perbill_V16_t* v);
parser_error_t _readPercent_V16(parser_context_t* c, pd_Percent_V16_t* v);
parser_error_t _readPlurality_V16(parser_context_t* c, pd_Plurality_V16_t* v);
parser_error_t _readPoolId_V16(parser_context_t* c, pd_PoolId_V16_t* v);
parser_error_t _readPoolState_V16(parser_context_t* c, pd_PoolState_V16_t* v);
parser_error_t _readProxyType_V16(parser_context_t* c, pd_ProxyType_V16_t* v);
parser_error_t _readReferendumIndex_V16(parser_context_t* c, pd_ReferendumIndex_V16_t* v);
parser_error_t _readRegistrarIndex_V16(parser_context_t* c, pd_RegistrarIndex_V16_t* v);
parser_error_t _readRewardDestination_V16(parser_context_t* c, pd_RewardDestination_V16_t* v);
parser_error_t _readSessionIndex_V16(parser_context_t* c, pd_SessionIndex_V16_t* v);
parser_error_t _readSr25519Public_V16(parser_context_t* c, pd_Sr25519Public_V16_t* v);
parser_error_t _readSr25519Signature_V16(parser_context_t* c, pd_Sr25519Signature_V16_t* v);
parser_error_t _readTimepoint_V16(parser_context_t* c, pd_Timepoint_V16_t* v);
parser_error_t _readTupleAccountIdData_V16(parser_context_t* c, pd_TupleAccountIdData_V16_t* v);
parser_error_t _readTupleH256u32_V16(parser_context_t* c, pd_TupleH256u32_V16_t* v);
parser_error_t _readValidatorPrefs_V16(parser_context_t* c, pd_ValidatorPrefs_V16_t* v);
parser_error_t _readVecAccountIdLookupOfT_V16(parser_context_t* c, pd_VecAccountIdLookupOfT_V16_t* v);
parser_error_t _readVecAccountId_V16(parser_context_t* c, pd_VecAccountId_V16_t* v);
parser_error_t _readVecMultiAssetV0_V16(parser_context_t* c, pd_VecMultiAssetV0_V16_t* v);
parser_error_t _readVecMultiAssetV1_V16(parser_context_t* c, pd_VecMultiAssetV1_V16_t* v);
parser_error_t _readVecTupleAccountIdData_V16(parser_context_t* c, pd_VecTupleAccountIdData_V16_t* v);
parser_error_t _readVestingInfo_V16(parser_context_t* c, pd_VestingInfo_V16_t* v);
parser_error_t _readVote_V16(parser_context_t* c, pd_Vote_V16_t* v);
parser_error_t _readWeightLimit_V16(parser_context_t* c, pd_WeightLimit_V16_t* v);
parser_error_t _readWeight_V16(parser_context_t* c, pd_Weight_V16_t* v);
parser_error_t _readu8_array_32_V16(parser_context_t* c, pd_u8_array_32_V16_t* v);

// toString functions
parser_error_t _toStringAbstractFungible_V16(
    const pd_AbstractFungible_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAbstractNonFungible_V16(
    const pd_AbstractNonFungible_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountId32_V16(
    const pd_AccountId32_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountIdLookupOfT_V16(
    const pd_AccountIdLookupOfT_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountId_V16(
    const pd_AccountId_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountIndex64_V16(
    const pd_AccountIndex64_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountIndex_V16(
    const pd_AccountIndex_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountKey20_V16(
    const pd_AccountKey20_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountVoteSplit_V16(
    const pd_AccountVoteSplit_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountVoteStandard_V16(
    const pd_AccountVoteStandard_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountVote_V16(
    const pd_AccountVote_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAssetInstance_V16(
    const pd_AssetInstance_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBodyId_V16(
    const pd_BodyId_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBodyPart_V16(
    const pd_BodyPart_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBondExtraBalanceOfT_V16(
    const pd_BondExtraBalanceOfT_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoundedCallOfT_V16(
    const pd_BoundedCallOfT_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxVersionedMultiAssets_V16(
    const pd_BoxVersionedMultiAssets_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxVersionedMultiLocation_V16(
    const pd_BoxVersionedMultiLocation_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactAccountIndex_V16(
    const pd_CompactAccountIndex_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactPerBill_V16(
    const pd_CompactPerBill_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringConcreteFungible_V16(
    const pd_ConcreteFungible_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringConcreteNonFungible_V16(
    const pd_ConcreteNonFungible_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringConfigOpAccountId_V16(
    const pd_ConfigOpAccountId_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringConfigOpBalanceOfT_V16(
    const pd_ConfigOpBalanceOfT_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringConfigOpPerbill_V16(
    const pd_ConfigOpPerbill_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringConfigOpPercent_V16(
    const pd_ConfigOpPercent_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringConfigOpu32_V16(
    const pd_ConfigOpu32_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringConviction_V16(
    const pd_Conviction_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEcdsaPublic_V16(
    const pd_EcdsaPublic_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEcdsaSignature_V16(
    const pd_EcdsaSignature_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEd25519Public_V16(
    const pd_Ed25519Public_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEd25519Signature_V16(
    const pd_Ed25519Signature_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEraIndex_V16(
    const pd_EraIndex_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEthereumAddress_V16(
    const pd_EthereumAddress_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringFraction_V16(
    const pd_Fraction_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringFungibility_V16(
    const pd_Fungibility_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringIdentityInfo_V16(
    const pd_IdentityInfo_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJudgementBalanceOfT_V16(
    const pd_JudgementBalanceOfT_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV0X1_V16(
    const pd_JunctionV0X1_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV0X2_V16(
    const pd_JunctionV0X2_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV0X3_V16(
    const pd_JunctionV0X3_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV0X4_V16(
    const pd_JunctionV0X4_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV0X5_V16(
    const pd_JunctionV0X5_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV0X6_V16(
    const pd_JunctionV0X6_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV0X7_V16(
    const pd_JunctionV0X7_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV0X8_V16(
    const pd_JunctionV0X8_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV0_V16(
    const pd_JunctionV0_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV1X1_V16(
    const pd_JunctionV1X1_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV1X2_V16(
    const pd_JunctionV1X2_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV1X3_V16(
    const pd_JunctionV1X3_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV1X4_V16(
    const pd_JunctionV1X4_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV1X5_V16(
    const pd_JunctionV1X5_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV1X6_V16(
    const pd_JunctionV1X6_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV1X7_V16(
    const pd_JunctionV1X7_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV1X8_V16(
    const pd_JunctionV1X8_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV1_V16(
    const pd_JunctionV1_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionsV0_V16(
    const pd_JunctionsV0_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionsV1_V16(
    const pd_JunctionsV1_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKeys_V16(
    const pd_Keys_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMemberCount_V16(
    const pd_MemberCount_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMultiAssetId_V16(
    const pd_MultiAssetId_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMultiAssetV0_V16(
    const pd_MultiAssetV0_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMultiAssetV1_V16(
    const pd_MultiAssetV1_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMultiLocationV0_V16(
    const pd_MultiLocationV0_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMultiLocationV1_V16(
    const pd_MultiLocationV1_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMultiSignature_V16(
    const pd_MultiSignature_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMultiSigner_V16(
    const pd_MultiSigner_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringNetworkId_V16(
    const pd_NetworkId_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionAccountId_V16(
    const pd_OptionAccountId_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionMultiSignature_V16(
    const pd_OptionMultiSignature_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionMultiSigner_V16(
    const pd_OptionMultiSigner_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionProxyType_V16(
    const pd_OptionProxyType_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionReferendumIndex_V16(
    const pd_OptionReferendumIndex_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionTimepoint_V16(
    const pd_OptionTimepoint_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOverweightIndex_V16(
    const pd_OverweightIndex_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringParaId_V16(
    const pd_ParaId_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPerbill_V16(
    const pd_Perbill_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPercent_V16(
    const pd_Percent_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPlurality_V16(
    const pd_Plurality_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPoolId_V16(
    const pd_PoolId_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPoolState_V16(
    const pd_PoolState_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringProxyType_V16(
    const pd_ProxyType_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringReferendumIndex_V16(
    const pd_ReferendumIndex_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringRegistrarIndex_V16(
    const pd_RegistrarIndex_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringRewardDestination_V16(
    const pd_RewardDestination_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSessionIndex_V16(
    const pd_SessionIndex_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSr25519Public_V16(
    const pd_Sr25519Public_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSr25519Signature_V16(
    const pd_Sr25519Signature_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTimepoint_V16(
    const pd_Timepoint_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTupleAccountIdData_V16(
    const pd_TupleAccountIdData_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTupleH256u32_V16(
    const pd_TupleH256u32_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringValidatorPrefs_V16(
    const pd_ValidatorPrefs_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecAccountIdLookupOfT_V16(
    const pd_VecAccountIdLookupOfT_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecAccountId_V16(
    const pd_VecAccountId_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecMultiAssetV0_V16(
    const pd_VecMultiAssetV0_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecMultiAssetV1_V16(
    const pd_VecMultiAssetV1_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecTupleAccountIdData_V16(
    const pd_VecTupleAccountIdData_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVestingInfo_V16(
    const pd_VestingInfo_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVote_V16(
    const pd_Vote_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringWeightLimit_V16(
    const pd_WeightLimit_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringWeight_V16(
    const pd_Weight_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringu8_array_32_V16(
    const pd_u8_array_32_V16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

#ifdef __cplusplus
}
#endif
