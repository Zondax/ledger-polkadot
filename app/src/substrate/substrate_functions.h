/*******************************************************************************
 *  (c) 2019 - 2023 Zondax AG
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

#include <stddef.h>
#include <stdint.h>

// Common read functions

parser_error_t _readbool(parser_context_t* c, pd_bool_t* v);
parser_error_t _readu8(parser_context_t* c, pd_u8_t* v);
parser_error_t _readu16(parser_context_t* c, pd_u16_t* v);
parser_error_t _readu32(parser_context_t* c, pd_u32_t* v);
parser_error_t _readu64(parser_context_t* c, pd_u64_t* v);
parser_error_t _readBlockNumber(parser_context_t* c, pd_BlockNumber_t* v);
parser_error_t _readCompactu32(parser_context_t* c, pd_Compactu32_t* v);
parser_error_t _readCompactu64(parser_context_t* c, pd_Compactu64_t* v);
parser_error_t _readCallImpl(parser_context_t* c, pd_Call_t* v, pd_MethodNested_t* m);

parser_error_t _readBytes(parser_context_t* c, pd_Bytes_t* v);
parser_error_t _readFraction(parser_context_t* c, pd_Fraction_t* v);
parser_error_t _readBodyId(parser_context_t* c, pd_BodyId_t* v);
parser_error_t _readBodyPart(parser_context_t* c, pd_BodyPart_t* v);
parser_error_t _readNetworkId(parser_context_t* c, pd_NetworkId_t* v);
parser_error_t _readu8_array_20(parser_context_t* c, pd_u8_array_20_t* v);
parser_error_t _readu8_array_32(parser_context_t* c, pd_u8_array_32_t* v);
parser_error_t _readAccountId32(parser_context_t* c, pd_AccountId32_t* v);
parser_error_t _readAccountIndex64(parser_context_t* c, pd_AccountIndex64_t* v);
parser_error_t _readAccountKey20(parser_context_t* c, pd_AccountKey20_t* v);
parser_error_t _readCompactu128(parser_context_t* c, pd_Compactu128_t* v);
parser_error_t _readPlurality(parser_context_t* c, pd_Plurality_t* v);
parser_error_t _readJunctionV0(parser_context_t* c, pd_JunctionV0_t* v);
parser_error_t _readJunctionV1(parser_context_t* c, pd_JunctionV1_t* v);
parser_error_t _readJunctionV0X1(parser_context_t* c, pd_JunctionV0X1_t* v);
parser_error_t _readJunctionV0X2(parser_context_t* c, pd_JunctionV0X2_t* v);
parser_error_t _readJunctionV0X3(parser_context_t* c, pd_JunctionV0X3_t* v);
parser_error_t _readJunctionV0X4(parser_context_t* c, pd_JunctionV0X4_t* v);
parser_error_t _readJunctionV0X5(parser_context_t* c, pd_JunctionV0X5_t* v);
parser_error_t _readJunctionV0X6(parser_context_t* c, pd_JunctionV0X6_t* v);
parser_error_t _readJunctionV0X7(parser_context_t* c, pd_JunctionV0X7_t* v);
parser_error_t _readJunctionV0X8(parser_context_t* c, pd_JunctionV0X8_t* v);
parser_error_t _readJunctionV1X1(parser_context_t* c, pd_JunctionV1X1_t* v);
parser_error_t _readJunctionV1X2(parser_context_t* c, pd_JunctionV1X2_t* v);
parser_error_t _readJunctionV1X3(parser_context_t* c, pd_JunctionV1X3_t* v);
parser_error_t _readJunctionV1X4(parser_context_t* c, pd_JunctionV1X4_t* v);
parser_error_t _readJunctionV1X5(parser_context_t* c, pd_JunctionV1X5_t* v);
parser_error_t _readJunctionV1X6(parser_context_t* c, pd_JunctionV1X6_t* v);
parser_error_t _readJunctionV1X7(parser_context_t* c, pd_JunctionV1X7_t* v);
parser_error_t _readJunctionV1X8(parser_context_t* c, pd_JunctionV1X8_t* v);
parser_error_t _readJunctionsV0(parser_context_t* c, pd_JunctionsV0_t* v);
parser_error_t _readJunctionsV1(parser_context_t* c, pd_JunctionsV1_t* v);
parser_error_t _readAssetInstance(parser_context_t* c, pd_AssetInstance_t* v);
parser_error_t _readMultiLocationV0(parser_context_t* c, pd_MultiLocationV0_t* v);
parser_error_t _readMultiLocationV1(parser_context_t* c, pd_MultiLocationV1_t* v);
parser_error_t _readAbstractFungible(parser_context_t* c, pd_AbstractFungible_t* v);
parser_error_t _readAbstractNonFungible(parser_context_t* c, pd_AbstractNonFungible_t* v);
parser_error_t _readBalance(parser_context_t* c, pd_Balance_t* v);
parser_error_t _readConcreteFungible(parser_context_t* c, pd_ConcreteFungible_t* v);
parser_error_t _readConcreteNonFungible(parser_context_t* c, pd_ConcreteNonFungible_t* v);
parser_error_t _readData(parser_context_t* c, pd_Data_t* v);
parser_error_t _readFungibility(parser_context_t* c, pd_Fungibility_t* v);
parser_error_t _readMultiAssetId(parser_context_t* c, pd_MultiAssetId_t* v);
parser_error_t _readAccountId(parser_context_t* c, pd_AccountId_t* v);
parser_error_t _readBalanceOf(parser_context_t* c, pd_BalanceOf_t* v);
parser_error_t _readCompactAccountIndex(parser_context_t* c, pd_CompactAccountIndex_t* v);
parser_error_t _readEcdsaPublic(parser_context_t* c, pd_EcdsaPublic_t* v);
parser_error_t _readEcdsaSignature(parser_context_t* c, pd_EcdsaSignature_t* v);
parser_error_t _readEd25519Public(parser_context_t* c, pd_Ed25519Public_t* v);
parser_error_t _readEd25519Signature(parser_context_t* c, pd_Ed25519Signature_t* v);
parser_error_t _readH256(parser_context_t* c, pd_H256_t* v);
parser_error_t _readMultiAssetV0(parser_context_t* c, pd_MultiAssetV0_t* v);
parser_error_t _readMultiAssetV1(parser_context_t* c, pd_MultiAssetV1_t* v);
parser_error_t _readSr25519Public(parser_context_t* c, pd_Sr25519Public_t* v);
parser_error_t _readSr25519Signature(parser_context_t* c, pd_Sr25519Signature_t* v);
parser_error_t _readTupleDataData(parser_context_t* c, pd_TupleDataData_t* v);
parser_error_t _readVote(parser_context_t* c, pd_Vote_t* v);
parser_error_t _readAccountIdLookupOfT(parser_context_t* c, pd_AccountIdLookupOfT_t* v);
parser_error_t _readAccountVoteSplit(parser_context_t* c, pd_AccountVoteSplit_t* v);
parser_error_t _readAccountVoteStandard(parser_context_t* c, pd_AccountVoteStandard_t* v);
parser_error_t _readCall(parser_context_t* c, pd_Call_t* v);
parser_error_t _readCompactPerBill(parser_context_t* c, pd_CompactPerBill_t* v);
parser_error_t _readMultiSignature(parser_context_t* c, pd_MultiSignature_t* v);
parser_error_t _readMultiSigner(parser_context_t* c, pd_MultiSigner_t* v);
parser_error_t _readOptionu8_array_20(parser_context_t* c, pd_Optionu8_array_20_t* v);
parser_error_t _readPerbill(parser_context_t* c, pd_Perbill_t* v);
parser_error_t _readPercent(parser_context_t* c, pd_Percent_t* v);
parser_error_t _readProxyType(parser_context_t* c, pd_ProxyType_t* v);
parser_error_t _readReferendumIndex(parser_context_t* c, pd_ReferendumIndex_t* v);
parser_error_t _readTimepoint(parser_context_t* c, pd_Timepoint_t* v);
parser_error_t _readTupleAccountIdData(parser_context_t* c, pd_TupleAccountIdData_t* v);
parser_error_t _readTupleH256u32(parser_context_t* c, pd_TupleH256u32_t* v);
parser_error_t _readVecMultiAssetV0(parser_context_t* c, pd_VecMultiAssetV0_t* v);
parser_error_t _readVecMultiAssetV1(parser_context_t* c, pd_VecMultiAssetV1_t* v);
parser_error_t _readVecTupleDataData(parser_context_t* c, pd_VecTupleDataData_t* v);
parser_error_t _readAccountVote(parser_context_t* c, pd_AccountVote_t* v);
parser_error_t _readBondExtraBalanceOfT(parser_context_t* c, pd_BondExtraBalanceOfT_t* v);
parser_error_t _readBoundedCallOfT(parser_context_t* c, pd_BoundedCallOfT_t* v);
parser_error_t _readBoxVersionedMultiAssets(parser_context_t* c, pd_BoxVersionedMultiAssets_t* v);
parser_error_t _readBoxVersionedMultiLocation(parser_context_t* c, pd_BoxVersionedMultiLocation_t* v);
parser_error_t _readConfigOpAccountId(parser_context_t* c, pd_ConfigOpAccountId_t* v);
parser_error_t _readConfigOpBalanceOfT(parser_context_t* c, pd_ConfigOpBalanceOfT_t* v);
parser_error_t _readConfigOpPerbill(parser_context_t* c, pd_ConfigOpPerbill_t* v);
parser_error_t _readConfigOpPercent(parser_context_t* c, pd_ConfigOpPercent_t* v);
parser_error_t _readIdentityInfo(parser_context_t* c, pd_IdentityInfo_t* v);
parser_error_t _readJudgementBalanceOfT(parser_context_t* c, pd_JudgementBalanceOfT_t* v);
parser_error_t _readOptionMultiSignature(parser_context_t* c, pd_OptionMultiSignature_t* v);
parser_error_t _readOptionMultiSigner(parser_context_t* c, pd_OptionMultiSigner_t* v);
parser_error_t _readOptionTimepoint(parser_context_t* c, pd_OptionTimepoint_t* v);
parser_error_t _readProposal(parser_context_t* c, pd_Proposal_t* v);
parser_error_t _readRewardDestination(parser_context_t* c, pd_RewardDestination_t* v);
parser_error_t _readValidatorPrefs(parser_context_t* c, pd_ValidatorPrefs_t* v);
parser_error_t _readVecAccountIdLookupOfT(parser_context_t* c, pd_VecAccountIdLookupOfT_t* v);
parser_error_t _readVecCall(parser_context_t* c, pd_VecCall_t* v);
parser_error_t _readVecTupleAccountIdData(parser_context_t* c, pd_VecTupleAccountIdData_t* v);
parser_error_t _readVestingInfo(parser_context_t* c, pd_VestingInfo_t* v);
parser_error_t _readWeightLimit(parser_context_t* c, pd_WeightLimit_t* v);
parser_error_t _readWeight(parser_context_t* c, pd_Weight_t* v);
parser_error_t _readAccountIndex(parser_context_t* c, pd_AccountIndex_t* v);
parser_error_t _readConfigOpu32(parser_context_t* c, pd_ConfigOpu32_t* v);
parser_error_t _readConviction(parser_context_t* c, pd_Conviction_t* v);
parser_error_t _readEraIndex(parser_context_t* c, pd_EraIndex_t* v);
parser_error_t _readEthereumAddress(parser_context_t* c, pd_EthereumAddress_t* v);
parser_error_t _readHash(parser_context_t* c, pd_Hash_t* v);
parser_error_t _readKeys(parser_context_t* c, pd_Keys_t* v);
parser_error_t _readMemberCount(parser_context_t* c, pd_MemberCount_t* v);
parser_error_t _readOptionAccountId(parser_context_t* c, pd_OptionAccountId_t* v);
parser_error_t _readOptionProxyType(parser_context_t* c, pd_OptionProxyType_t* v);
parser_error_t _readOptionReferendumIndex(parser_context_t* c, pd_OptionReferendumIndex_t* v);
parser_error_t _readOptionu32(parser_context_t* c, pd_Optionu32_t* v);
parser_error_t _readOverweightIndex(parser_context_t* c, pd_OverweightIndex_t* v);
parser_error_t _readParaId(parser_context_t* c, pd_ParaId_t* v);
parser_error_t _readPoolId(parser_context_t* c, pd_PoolId_t* v);
parser_error_t _readPoolState(parser_context_t* c, pd_PoolState_t* v);
parser_error_t _readRegistrarIndex(parser_context_t* c, pd_RegistrarIndex_t* v);
parser_error_t _readSessionIndex(parser_context_t* c, pd_SessionIndex_t* v);
parser_error_t _readVecAccountId(parser_context_t* c, pd_VecAccountId_t* v);
parser_error_t _readVecu32(parser_context_t* c, pd_Vecu32_t* v);
parser_error_t _readVecu8(parser_context_t* c, pd_Vecu8_t* v);

// Common toString functions

parser_error_t _toStringu8(
    const pd_u8_t* v,
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

parser_error_t _toStringbool(
    const pd_bool_t* v,
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

parser_error_t _toStringCompactu32(
    const pd_Compactu32_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactu64(
    const pd_Compactu64_t* v,
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

parser_error_t _toStringFraction(
    const pd_Fraction_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBodyId(
    const pd_BodyId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBodyPart(
    const pd_BodyPart_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringNetworkId(
    const pd_NetworkId_t* v,
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

parser_error_t _toStringAccountId32(
    const pd_AccountId32_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountIndex64(
    const pd_AccountIndex64_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountKey20(
    const pd_AccountKey20_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactu128(
    const pd_Compactu128_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPlurality(
    const pd_Plurality_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV0(
    const pd_JunctionV0_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV1(
    const pd_JunctionV1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV0X1(
    const pd_JunctionV0X1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV0X2(
    const pd_JunctionV0X2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV0X3(
    const pd_JunctionV0X3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV0X4(
    const pd_JunctionV0X4_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV0X5(
    const pd_JunctionV0X5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV0X6(
    const pd_JunctionV0X6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV0X7(
    const pd_JunctionV0X7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV0X8(
    const pd_JunctionV0X8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV1X1(
    const pd_JunctionV1X1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV1X2(
    const pd_JunctionV1X2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV1X3(
    const pd_JunctionV1X3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV1X4(
    const pd_JunctionV1X4_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV1X5(
    const pd_JunctionV1X5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV1X6(
    const pd_JunctionV1X6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV1X7(
    const pd_JunctionV1X7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV1X8(
    const pd_JunctionV1X8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionsV0(
    const pd_JunctionsV0_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionsV1(
    const pd_JunctionsV1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAssetInstance(
    const pd_AssetInstance_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMultiLocationV0(
    const pd_MultiLocationV0_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMultiLocationV1(
    const pd_MultiLocationV1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAbstractFungible(
    const pd_AbstractFungible_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAbstractNonFungible(
    const pd_AbstractNonFungible_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBalance(
    const pd_Balance_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringConcreteFungible(
    const pd_ConcreteFungible_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringConcreteNonFungible(
    const pd_ConcreteNonFungible_t* v,
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

parser_error_t _toStringFungibility(
    const pd_Fungibility_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMultiAssetId(
    const pd_MultiAssetId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountId(
    const pd_AccountId_t* v,
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

parser_error_t _toStringCompactAccountIndex(
    const pd_CompactAccountIndex_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEcdsaPublic(
    const pd_EcdsaPublic_t* v,
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

parser_error_t _toStringEd25519Public(
    const pd_Ed25519Public_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEd25519Signature(
    const pd_Ed25519Signature_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringH256(
    const pd_H256_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMultiAssetV0(
    const pd_MultiAssetV0_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMultiAssetV1(
    const pd_MultiAssetV1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSr25519Public(
    const pd_Sr25519Public_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSr25519Signature(
    const pd_Sr25519Signature_t* v,
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

parser_error_t _toStringVote(
    const pd_Vote_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountIdLookupOfT(
    const pd_AccountIdLookupOfT_t* v,
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

parser_error_t _toStringCall(
    const pd_Call_t* v,
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

parser_error_t _toStringMultiSignature(
    const pd_MultiSignature_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMultiSigner(
    const pd_MultiSigner_t* v,
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

parser_error_t _toStringTupleH256u32(
    const pd_TupleH256u32_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecMultiAssetV0(
    const pd_VecMultiAssetV0_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecMultiAssetV1(
    const pd_VecMultiAssetV1_t* v,
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

parser_error_t _toStringAccountVote(
    const pd_AccountVote_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBondExtraBalanceOfT(
    const pd_BondExtraBalanceOfT_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoundedCallOfT(
    const pd_BoundedCallOfT_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxVersionedMultiAssets(
    const pd_BoxVersionedMultiAssets_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxVersionedMultiLocation(
    const pd_BoxVersionedMultiLocation_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringConfigOpAccountId(
    const pd_ConfigOpAccountId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringConfigOpBalanceOfT(
    const pd_ConfigOpBalanceOfT_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringConfigOpPerbill(
    const pd_ConfigOpPerbill_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringConfigOpPercent(
    const pd_ConfigOpPercent_t* v,
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

parser_error_t _toStringJudgementBalanceOfT(
    const pd_JudgementBalanceOfT_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionMultiSignature(
    const pd_OptionMultiSignature_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionMultiSigner(
    const pd_OptionMultiSigner_t* v,
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

parser_error_t _toStringProposal(
    const pd_Proposal_t* v,
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

parser_error_t _toStringValidatorPrefs(
    const pd_ValidatorPrefs_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecAccountIdLookupOfT(
    const pd_VecAccountIdLookupOfT_t* v,
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

parser_error_t _toStringVecTupleAccountIdData(
    const pd_VecTupleAccountIdData_t* v,
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

parser_error_t _toStringWeightLimit(
    const pd_WeightLimit_t* v,
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

parser_error_t _toStringAccountIndex(
    const pd_AccountIndex_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringConfigOpu32(
    const pd_ConfigOpu32_t* v,
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

parser_error_t _toStringHash(
    const pd_Hash_t* v,
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

parser_error_t _toStringMemberCount(
    const pd_MemberCount_t* v,
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

parser_error_t _toStringOptionu32(
    const pd_Optionu32_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOverweightIndex(
    const pd_OverweightIndex_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringParaId(
    const pd_ParaId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPoolId(
    const pd_PoolId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPoolState(
    const pd_PoolState_t* v,
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

parser_error_t _toStringSessionIndex(
    const pd_SessionIndex_t* v,
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

parser_error_t _toStringVecu32(
    const pd_Vecu32_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecu8(
    const pd_Vecu8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

#ifdef __cplusplus
}
#endif
