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
#include "substrate_methods_V15.h"
#include "substrate_types_V15.h"
#include <stddef.h>
#include <stdint.h>

// Read functions
parser_error_t _readAbstractFungible_V15(parser_context_t* c, pd_AbstractFungible_V15_t* v);
parser_error_t _readAbstractNonFungible_V15(parser_context_t* c, pd_AbstractNonFungible_V15_t* v);
parser_error_t _readAccountId32_V15(parser_context_t* c, pd_AccountId32_V15_t* v);
parser_error_t _readAccountIdLookupOfT_V15(parser_context_t* c, pd_AccountIdLookupOfT_V15_t* v);
parser_error_t _readAccountId_V15(parser_context_t* c, pd_AccountId_V15_t* v);
parser_error_t _readAccountIndex64_V15(parser_context_t* c, pd_AccountIndex64_V15_t* v);
parser_error_t _readAccountIndex_V15(parser_context_t* c, pd_AccountIndex_V15_t* v);
parser_error_t _readAccountKey20_V15(parser_context_t* c, pd_AccountKey20_V15_t* v);
parser_error_t _readAccountVoteSplit_V15(parser_context_t* c, pd_AccountVoteSplit_V15_t* v);
parser_error_t _readAccountVoteStandard_V15(parser_context_t* c, pd_AccountVoteStandard_V15_t* v);
parser_error_t _readAccountVote_V15(parser_context_t* c, pd_AccountVote_V15_t* v);
parser_error_t _readAssetInstance_V15(parser_context_t* c, pd_AssetInstance_V15_t* v);
parser_error_t _readBodyId_V15(parser_context_t* c, pd_BodyId_V15_t* v);
parser_error_t _readBodyPart_V15(parser_context_t* c, pd_BodyPart_V15_t* v);
parser_error_t _readBondExtraBalanceOfT_V15(parser_context_t* c, pd_BondExtraBalanceOfT_V15_t* v);
parser_error_t _readBoxVersionedMultiAssets_V15(parser_context_t* c, pd_BoxVersionedMultiAssets_V15_t* v);
parser_error_t _readBoxVersionedMultiLocation_V15(parser_context_t* c, pd_BoxVersionedMultiLocation_V15_t* v);
parser_error_t _readCompactAccountIndex_V15(parser_context_t* c, pd_CompactAccountIndex_V15_t* v);
parser_error_t _readCompactPerBill_V15(parser_context_t* c, pd_CompactPerBill_V15_t* v);
parser_error_t _readConcreteFungible_V15(parser_context_t* c, pd_ConcreteFungible_V15_t* v);
parser_error_t _readConcreteNonFungible_V15(parser_context_t* c, pd_ConcreteNonFungible_V15_t* v);
parser_error_t _readConfigOpAccountId_V15(parser_context_t* c, pd_ConfigOpAccountId_V15_t* v);
parser_error_t _readConfigOpBalanceOfT_V15(parser_context_t* c, pd_ConfigOpBalanceOfT_V15_t* v);
parser_error_t _readConfigOpPerbill_V15(parser_context_t* c, pd_ConfigOpPerbill_V15_t* v);
parser_error_t _readConfigOpPercent_V15(parser_context_t* c, pd_ConfigOpPercent_V15_t* v);
parser_error_t _readConfigOpu32_V15(parser_context_t* c, pd_ConfigOpu32_V15_t* v);
parser_error_t _readConviction_V15(parser_context_t* c, pd_Conviction_V15_t* v);
parser_error_t _readEcdsaPublic_V15(parser_context_t* c, pd_EcdsaPublic_V15_t* v);
parser_error_t _readEcdsaSignature_V15(parser_context_t* c, pd_EcdsaSignature_V15_t* v);
parser_error_t _readEd25519Public_V15(parser_context_t* c, pd_Ed25519Public_V15_t* v);
parser_error_t _readEd25519Signature_V15(parser_context_t* c, pd_Ed25519Signature_V15_t* v);
parser_error_t _readEraIndex_V15(parser_context_t* c, pd_EraIndex_V15_t* v);
parser_error_t _readEthereumAddress_V15(parser_context_t* c, pd_EthereumAddress_V15_t* v);
parser_error_t _readFraction_V15(parser_context_t* c, pd_Fraction_V15_t* v);
parser_error_t _readFungibility_V15(parser_context_t* c, pd_Fungibility_V15_t* v);
parser_error_t _readIdentityInfo_V15(parser_context_t* c, pd_IdentityInfo_V15_t* v);
parser_error_t _readJudgementBalanceOfT_V15(parser_context_t* c, pd_JudgementBalanceOfT_V15_t* v);
parser_error_t _readJunctionV0X1_V15(parser_context_t* c, pd_JunctionV0X1_V15_t* v);
parser_error_t _readJunctionV0X2_V15(parser_context_t* c, pd_JunctionV0X2_V15_t* v);
parser_error_t _readJunctionV0X3_V15(parser_context_t* c, pd_JunctionV0X3_V15_t* v);
parser_error_t _readJunctionV0X4_V15(parser_context_t* c, pd_JunctionV0X4_V15_t* v);
parser_error_t _readJunctionV0X5_V15(parser_context_t* c, pd_JunctionV0X5_V15_t* v);
parser_error_t _readJunctionV0X6_V15(parser_context_t* c, pd_JunctionV0X6_V15_t* v);
parser_error_t _readJunctionV0X7_V15(parser_context_t* c, pd_JunctionV0X7_V15_t* v);
parser_error_t _readJunctionV0X8_V15(parser_context_t* c, pd_JunctionV0X8_V15_t* v);
parser_error_t _readJunctionV0_V15(parser_context_t* c, pd_JunctionV0_V15_t* v);
parser_error_t _readJunctionV1X1_V15(parser_context_t* c, pd_JunctionV1X1_V15_t* v);
parser_error_t _readJunctionV1X2_V15(parser_context_t* c, pd_JunctionV1X2_V15_t* v);
parser_error_t _readJunctionV1X3_V15(parser_context_t* c, pd_JunctionV1X3_V15_t* v);
parser_error_t _readJunctionV1X4_V15(parser_context_t* c, pd_JunctionV1X4_V15_t* v);
parser_error_t _readJunctionV1X5_V15(parser_context_t* c, pd_JunctionV1X5_V15_t* v);
parser_error_t _readJunctionV1X6_V15(parser_context_t* c, pd_JunctionV1X6_V15_t* v);
parser_error_t _readJunctionV1X7_V15(parser_context_t* c, pd_JunctionV1X7_V15_t* v);
parser_error_t _readJunctionV1X8_V15(parser_context_t* c, pd_JunctionV1X8_V15_t* v);
parser_error_t _readJunctionV1_V15(parser_context_t* c, pd_JunctionV1_V15_t* v);
parser_error_t _readJunctionsV0_V15(parser_context_t* c, pd_JunctionsV0_V15_t* v);
parser_error_t _readJunctionsV1_V15(parser_context_t* c, pd_JunctionsV1_V15_t* v);
parser_error_t _readKeys_V15(parser_context_t* c, pd_Keys_V15_t* v);
parser_error_t _readMemberCount_V15(parser_context_t* c, pd_MemberCount_V15_t* v);
parser_error_t _readMultiAssetId_V15(parser_context_t* c, pd_MultiAssetId_V15_t* v);
parser_error_t _readMultiAssetV0_V15(parser_context_t* c, pd_MultiAssetV0_V15_t* v);
parser_error_t _readMultiAssetV1_V15(parser_context_t* c, pd_MultiAssetV1_V15_t* v);
parser_error_t _readMultiLocationV0_V15(parser_context_t* c, pd_MultiLocationV0_V15_t* v);
parser_error_t _readMultiLocationV1_V15(parser_context_t* c, pd_MultiLocationV1_V15_t* v);
parser_error_t _readMultiSignature_V15(parser_context_t* c, pd_MultiSignature_V15_t* v);
parser_error_t _readMultiSigner_V15(parser_context_t* c, pd_MultiSigner_V15_t* v);
parser_error_t _readNetworkId_V15(parser_context_t* c, pd_NetworkId_V15_t* v);
parser_error_t _readOpaqueCall_V15(parser_context_t* c, pd_OpaqueCall_V15_t* v);
parser_error_t _readOptionAccountId_V15(parser_context_t* c, pd_OptionAccountId_V15_t* v);
parser_error_t _readOptionMultiSignature_V15(parser_context_t* c, pd_OptionMultiSignature_V15_t* v);
parser_error_t _readOptionMultiSigner_V15(parser_context_t* c, pd_OptionMultiSigner_V15_t* v);
parser_error_t _readOptionProxyType_V15(parser_context_t* c, pd_OptionProxyType_V15_t* v);
parser_error_t _readOptionTimepoint_V15(parser_context_t* c, pd_OptionTimepoint_V15_t* v);
parser_error_t _readOverweightIndex_V15(parser_context_t* c, pd_OverweightIndex_V15_t* v);
parser_error_t _readParaId_V15(parser_context_t* c, pd_ParaId_V15_t* v);
parser_error_t _readPerbill_V15(parser_context_t* c, pd_Perbill_V15_t* v);
parser_error_t _readPercent_V15(parser_context_t* c, pd_Percent_V15_t* v);
parser_error_t _readPlurality_V15(parser_context_t* c, pd_Plurality_V15_t* v);
parser_error_t _readPoolId_V15(parser_context_t* c, pd_PoolId_V15_t* v);
parser_error_t _readPoolState_V15(parser_context_t* c, pd_PoolState_V15_t* v);
parser_error_t _readProxyType_V15(parser_context_t* c, pd_ProxyType_V15_t* v);
parser_error_t _readReferendumIndex_V15(parser_context_t* c, pd_ReferendumIndex_V15_t* v);
parser_error_t _readRegistrarIndex_V15(parser_context_t* c, pd_RegistrarIndex_V15_t* v);
parser_error_t _readRewardDestination_V15(parser_context_t* c, pd_RewardDestination_V15_t* v);
parser_error_t _readSessionIndex_V15(parser_context_t* c, pd_SessionIndex_V15_t* v);
parser_error_t _readSr25519Public_V15(parser_context_t* c, pd_Sr25519Public_V15_t* v);
parser_error_t _readSr25519Signature_V15(parser_context_t* c, pd_Sr25519Signature_V15_t* v);
parser_error_t _readTimepoint_V15(parser_context_t* c, pd_Timepoint_V15_t* v);
parser_error_t _readTupleAccountIdData_V15(parser_context_t* c, pd_TupleAccountIdData_V15_t* v);
parser_error_t _readValidatorPrefs_V15(parser_context_t* c, pd_ValidatorPrefs_V15_t* v);
parser_error_t _readVecAccountIdLookupOfT_V15(parser_context_t* c, pd_VecAccountIdLookupOfT_V15_t* v);
parser_error_t _readVecAccountId_V15(parser_context_t* c, pd_VecAccountId_V15_t* v);
parser_error_t _readVecMultiAssetV0_V15(parser_context_t* c, pd_VecMultiAssetV0_V15_t* v);
parser_error_t _readVecMultiAssetV1_V15(parser_context_t* c, pd_VecMultiAssetV1_V15_t* v);
parser_error_t _readVecTupleAccountIdData_V15(parser_context_t* c, pd_VecTupleAccountIdData_V15_t* v);
parser_error_t _readVestingInfo_V15(parser_context_t* c, pd_VestingInfo_V15_t* v);
parser_error_t _readVote_V15(parser_context_t* c, pd_Vote_V15_t* v);
parser_error_t _readWeightLimit_V15(parser_context_t* c, pd_WeightLimit_V15_t* v);
parser_error_t _readWeight_V15(parser_context_t* c, pd_Weight_V15_t* v);
parser_error_t _readu8_array_32_V15(parser_context_t* c, pd_u8_array_32_V15_t* v);

// toString functions
parser_error_t _toStringAbstractFungible_V15(
    const pd_AbstractFungible_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAbstractNonFungible_V15(
    const pd_AbstractNonFungible_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountId32_V15(
    const pd_AccountId32_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountIdLookupOfT_V15(
    const pd_AccountIdLookupOfT_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountId_V15(
    const pd_AccountId_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountIndex64_V15(
    const pd_AccountIndex64_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountIndex_V15(
    const pd_AccountIndex_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountKey20_V15(
    const pd_AccountKey20_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountVoteSplit_V15(
    const pd_AccountVoteSplit_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountVoteStandard_V15(
    const pd_AccountVoteStandard_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountVote_V15(
    const pd_AccountVote_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAssetInstance_V15(
    const pd_AssetInstance_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBodyId_V15(
    const pd_BodyId_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBodyPart_V15(
    const pd_BodyPart_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBondExtraBalanceOfT_V15(
    const pd_BondExtraBalanceOfT_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxVersionedMultiAssets_V15(
    const pd_BoxVersionedMultiAssets_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxVersionedMultiLocation_V15(
    const pd_BoxVersionedMultiLocation_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactAccountIndex_V15(
    const pd_CompactAccountIndex_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactPerBill_V15(
    const pd_CompactPerBill_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringConcreteFungible_V15(
    const pd_ConcreteFungible_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringConcreteNonFungible_V15(
    const pd_ConcreteNonFungible_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringConfigOpAccountId_V15(
    const pd_ConfigOpAccountId_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringConfigOpBalanceOfT_V15(
    const pd_ConfigOpBalanceOfT_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringConfigOpPerbill_V15(
    const pd_ConfigOpPerbill_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringConfigOpPercent_V15(
    const pd_ConfigOpPercent_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringConfigOpu32_V15(
    const pd_ConfigOpu32_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringConviction_V15(
    const pd_Conviction_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEcdsaPublic_V15(
    const pd_EcdsaPublic_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEcdsaSignature_V15(
    const pd_EcdsaSignature_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEd25519Public_V15(
    const pd_Ed25519Public_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEd25519Signature_V15(
    const pd_Ed25519Signature_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEraIndex_V15(
    const pd_EraIndex_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEthereumAddress_V15(
    const pd_EthereumAddress_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringFraction_V15(
    const pd_Fraction_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringFungibility_V15(
    const pd_Fungibility_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringIdentityInfo_V15(
    const pd_IdentityInfo_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJudgementBalanceOfT_V15(
    const pd_JudgementBalanceOfT_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV0X1_V15(
    const pd_JunctionV0X1_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV0X2_V15(
    const pd_JunctionV0X2_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV0X3_V15(
    const pd_JunctionV0X3_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV0X4_V15(
    const pd_JunctionV0X4_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV0X5_V15(
    const pd_JunctionV0X5_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV0X6_V15(
    const pd_JunctionV0X6_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV0X7_V15(
    const pd_JunctionV0X7_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV0X8_V15(
    const pd_JunctionV0X8_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV0_V15(
    const pd_JunctionV0_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV1X1_V15(
    const pd_JunctionV1X1_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV1X2_V15(
    const pd_JunctionV1X2_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV1X3_V15(
    const pd_JunctionV1X3_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV1X4_V15(
    const pd_JunctionV1X4_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV1X5_V15(
    const pd_JunctionV1X5_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV1X6_V15(
    const pd_JunctionV1X6_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV1X7_V15(
    const pd_JunctionV1X7_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV1X8_V15(
    const pd_JunctionV1X8_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV1_V15(
    const pd_JunctionV1_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionsV0_V15(
    const pd_JunctionsV0_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionsV1_V15(
    const pd_JunctionsV1_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKeys_V15(
    const pd_Keys_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMemberCount_V15(
    const pd_MemberCount_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMultiAssetId_V15(
    const pd_MultiAssetId_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMultiAssetV0_V15(
    const pd_MultiAssetV0_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMultiAssetV1_V15(
    const pd_MultiAssetV1_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMultiLocationV0_V15(
    const pd_MultiLocationV0_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMultiLocationV1_V15(
    const pd_MultiLocationV1_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMultiSignature_V15(
    const pd_MultiSignature_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMultiSigner_V15(
    const pd_MultiSigner_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringNetworkId_V15(
    const pd_NetworkId_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOpaqueCall_V15(
    const pd_OpaqueCall_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionAccountId_V15(
    const pd_OptionAccountId_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionMultiSignature_V15(
    const pd_OptionMultiSignature_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionMultiSigner_V15(
    const pd_OptionMultiSigner_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionProxyType_V15(
    const pd_OptionProxyType_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionTimepoint_V15(
    const pd_OptionTimepoint_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOverweightIndex_V15(
    const pd_OverweightIndex_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringParaId_V15(
    const pd_ParaId_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPerbill_V15(
    const pd_Perbill_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPercent_V15(
    const pd_Percent_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPlurality_V15(
    const pd_Plurality_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPoolId_V15(
    const pd_PoolId_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPoolState_V15(
    const pd_PoolState_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringProxyType_V15(
    const pd_ProxyType_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringReferendumIndex_V15(
    const pd_ReferendumIndex_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringRegistrarIndex_V15(
    const pd_RegistrarIndex_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringRewardDestination_V15(
    const pd_RewardDestination_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSessionIndex_V15(
    const pd_SessionIndex_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSr25519Public_V15(
    const pd_Sr25519Public_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSr25519Signature_V15(
    const pd_Sr25519Signature_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTimepoint_V15(
    const pd_Timepoint_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTupleAccountIdData_V15(
    const pd_TupleAccountIdData_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringValidatorPrefs_V15(
    const pd_ValidatorPrefs_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecAccountIdLookupOfT_V15(
    const pd_VecAccountIdLookupOfT_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecAccountId_V15(
    const pd_VecAccountId_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecMultiAssetV0_V15(
    const pd_VecMultiAssetV0_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecMultiAssetV1_V15(
    const pd_VecMultiAssetV1_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecTupleAccountIdData_V15(
    const pd_VecTupleAccountIdData_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVestingInfo_V15(
    const pd_VestingInfo_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVote_V15(
    const pd_Vote_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringWeightLimit_V15(
    const pd_WeightLimit_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringWeight_V15(
    const pd_Weight_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringu8_array_32_V15(
    const pd_u8_array_32_V15_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

#ifdef __cplusplus
}
#endif
