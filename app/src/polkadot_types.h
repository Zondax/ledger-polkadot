/*******************************************************************************
*  (c) 2019 ZondaX GmbH
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

#include <stdint.h>
#include <stddef.h>
#include "parser_common.h"

// https://github.com/paritytech/substrate/blob/effe489951d1edab9d34846b1eefdfaf9511dab9/frame/identity/src/lib.rs
#define    Data_e_NONE              0
#define    Data_e_RAW_VECU8         33
#define    Data_e_BLAKETWO256U8_32  34
#define    Data_e_SHA256_U8_32      35
#define    Data_e_KECCAK256_U8_32   36
#define    Data_e_SHATHREE256_U8_32 37

typedef struct {
    uint8_t moduleIdx;
    uint8_t idx;
} pd_CallIndex_t;

typedef enum {
    eEraImmortal = 0,
    eEraMortal = 1
} pd_ExtrinsicEra_e;

// This type has a non-standard serialization
// core/sr-primitives/src/generic/era.rs
typedef struct {
    pd_ExtrinsicEra_e type;
    uint64_t period;
    uint64_t phase;
} pd_ExtrinsicEra_t;

typedef struct {
    const uint8_t *ptr;
    uint8_t len;
} compactInt_t;

////////////////////////
// Not supported types
////////////////////////

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wextern-c-compat"
// NOTE: These are large types that cannot be reviewed in the device. 
// They will be marked as not supported
typedef struct {} pd_AttestedCandidate_t;
typedef struct {} pd_Header_t;
typedef struct {} pd_Heartbeat_t;
#pragma clang diagnostic pop

////////////////////////
////////////////////////
////////////////////////
////////////////////////

typedef enum {
    eAddressIndex = 0,
    eAddressId = 1
} pd_Address_e;

typedef struct {
    pd_Address_e type;
    uint64_t idx;
    const uint8_t *idPtr;
} pd_Address_t;

typedef struct {
    compactInt_t index;
} pd_CompactIndex_t;

typedef struct {
    compactInt_t value;
} pd_CompactBalance_t;

typedef struct {
    const uint8_t *_ptr;
} pd_Hash_t;

parser_error_t _readAddress(parser_context_t *c, pd_Address_t *v);

parser_error_t _readCompactBalance(parser_context_t *c, pd_CompactBalance_t *v);

parser_error_t _readHash(parser_context_t *c, pd_Hash_t *v);

parser_error_t _toStringAddress(const pd_Address_t *v,
                                char *outValue, uint16_t outValueLen,
                                uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringCompactBalance(const pd_CompactBalance_t *v,
                                       char *outValue, uint16_t outValueLen,
                                       uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringHash(const pd_Hash_t *v,
                             char *outValue, uint16_t outValueLen,
                             uint8_t pageIdx, uint8_t *pageCount);

typedef struct {
    const uint8_t *_ptr;
} pd_u8_array_20_t;

typedef struct {
    uint8_t some;
    pd_u8_array_20_t contained;
} pd_Optionu8_array_20_t;

typedef struct {
    uint64_t _len;
    const uint8_t *_ptr;
    uint64_t _lenBuffer;
} pd_VecTupleDataData_t;

////////////////////////
////////////////////////
////////////////////////
////////////////////////

typedef uint8_t pd_bool_t;
typedef uint16_t pd_u16_t;
typedef uint32_t pd_u32_t;
typedef uint64_t pd_u64_t;

typedef compactInt_t pd_Compactu32_t;               // u32
typedef compactInt_t pd_Compactu64_t;               // u64
typedef pd_CompactBalance_t pd_CompactBalanceOf_t;
typedef uint32_t pd_BlockNumber_t;                  // u32

// Based
// https://github.com/paritytech/substrate/blob/master/node/primitives/src/lib.rs

typedef compactInt_t pd_CompactAssignments_t;

typedef compactInt_t pd_CompactAuctionIndex_t;

typedef compactInt_t pd_CompactBlockNumber_t;

typedef compactInt_t pd_CompactEraIndex_t;

typedef compactInt_t pd_CompactLeasePeriodOf_t;

typedef compactInt_t pd_CompactMemberCount_t;

typedef compactInt_t pd_CompactMoment_t;

typedef compactInt_t pd_CompactParaId_t;

typedef compactInt_t pd_CompactPropIndex_t;

typedef compactInt_t pd_CompactProposalIndex_t;

typedef compactInt_t pd_CompactReferendumIndex_t;

typedef compactInt_t pd_CompactRegistrarIndex_t;

typedef compactInt_t pd_CompactSubId_t;


typedef struct { 
    const uint8_t *_ptr;
} pd_AccountId_t;

typedef struct { 
    uint32_t value;
} pd_AccountIndex_t;

typedef struct {
    const uint8_t *_ptr;
} pd_BalanceOf_t;

typedef struct { 
    pd_BalanceOf_t aye;
    pd_BalanceOf_t nay;
} pd_AccountVoteSplit_t;

typedef struct {
    uint8_t value;
} pd_Conviction_t;

typedef struct {
    pd_bool_t aye;
    pd_Conviction_t conviction;
} pd_Vote_t;

typedef struct { 
    pd_Vote_t vote;
    pd_BalanceOf_t balance;
} pd_AccountVoteStandard_t;

typedef struct { 
    uint8_t value;
     union {
        pd_AccountVoteStandard_t voteStandard;
        pd_AccountVoteSplit_t voteSplit;
    };
} pd_AccountVote_t;

typedef struct { 
    uint64_t _len;
    const uint8_t *_ptr;
} pd_Bytes_t;

typedef struct { 
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_Call_t;

typedef struct { 
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_ChangesTrieConfiguration_t;

typedef struct { 
    pd_Hash_t value;
} pd_CollatorId_t;

typedef struct { 
    uint8_t type;
    const uint8_t *_ptr;
    uint8_t _len;
} pd_Data_t;

typedef struct { 
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_DoubleVoteReport_t;

typedef struct { 
    const uint8_t *_ptr;
} pd_EcdsaSignature_t;

typedef struct { 
    uint32_t value;
} pd_EraIndex_t;

typedef struct { 
    const uint8_t *_ptr;
} pd_EthereumAddress_t;

typedef struct { 
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_HeadData_t;

typedef struct { 
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_IdentityFields_t;

typedef struct { 
    // https://github.com/paritytech/substrate/blob/effe489951d1edab9d34846b1eefdfaf9511dab9/frame/identity/src/lib.rs#L276
    pd_VecTupleDataData_t additional;
    pd_Data_t display;
    pd_Data_t legal;
    pd_Data_t web;
    pd_Data_t riot;
    pd_Data_t email;
    pd_Optionu8_array_20_t pgp_fingerprint;
    pd_Data_t image;
    pd_Data_t twitter;
} pd_IdentityInfo_t;

typedef struct { 
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_IdentityJudgement_t;

typedef struct { 
    const uint8_t *_ptr;
} pd_Key_t;

typedef struct { 
  	const uint8_t *_ptr;
} pd_LookupSource_t;

typedef struct { 
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_MoreAttestations_t;

typedef struct { 
    uint8_t scheduling;     //pd_ParaScheduling_t
    // 0 - Always
    // 1 - Dynamic
} pd_ParaInfo_t;

typedef struct { 
    uint32_t value;
} pd_Perbill_t;

typedef struct { 
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_PhragmenScore_t;

typedef struct { 
    uint32_t value;
} pd_ReferendumIndex_t;

typedef struct { 
    uint32_t value;
} pd_RegistrarIndex_t;

typedef struct { 
    uint8_t value;
} pd_RewardDestination_t;

typedef struct { 
    const uint8_t *_ptr;
} pd_Signature_t;

typedef struct { 
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_SocietyJudgement_t;

typedef struct { 
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_Timepoint_t;

typedef struct { 
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_TupleAccountIdData_t;

typedef struct { 
  	pd_AccountId_t accountId;
    pd_u32_t num;
} pd_TupleAccountIdu32_t;

typedef struct { 
    pd_BalanceOf_t balance1;
    pd_BalanceOf_t balance2;
    pd_BlockNumber_t blockNumber;
} pd_TupleBalanceOfBalanceOfBlockNumber_t;

typedef struct { 
    pd_Data_t data1;
    pd_Data_t data2;
} pd_TupleDataData_t;

typedef struct { 
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_ValidationCode_t;

typedef struct { 
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_ValidatorIndex_t;

typedef struct { 
    pd_CompactBalance_t balance;
} pd_ValidatorPrefs_t;

typedef struct { 
    pd_BalanceOf_t locked;
    pd_BalanceOf_t per_block;
    pd_BlockNumber_t starting_block;
} pd_VestingInfo_t;

typedef struct { 
    const uint8_t *_ptr;
} pd_u8_array_32_t;

typedef struct {
    uint64_t _len;
    const uint8_t *_ptr;
    uint64_t _lenBuffer;
} pd_VecAccountId_t;

typedef struct {
    uint64_t _len;
    const uint8_t *_ptr;
    uint64_t _lenBuffer;
} pd_VecAttestedCandidate_t;

typedef struct {
    uint64_t _len;
    const uint8_t *_ptr;
    uint64_t _lenBuffer;
} pd_VecCall_t;

typedef struct {
    uint64_t _len;
    const uint8_t *_ptr;
    uint64_t _lenBuffer;
} pd_VecHeader_t;

typedef struct {
    uint64_t _len;
    const uint8_t *_ptr;
    uint64_t _lenBuffer;
} pd_VecKeyValue_t;

typedef struct {
    uint64_t _len;
    const uint8_t *_ptr;
    uint64_t _lenBuffer;
} pd_VecKey_t;

typedef struct {
    uint64_t _len;
    const uint8_t *_ptr;
    uint64_t _lenBuffer;
} pd_VecLookupSource_t;

typedef struct {
    uint64_t _len;
    const uint8_t *_ptr;
    uint64_t _lenBuffer;
} pd_VecTupleAccountIdData_t;

typedef struct {
    uint64_t _len;
    const uint8_t *_ptr;
    uint64_t _lenBuffer;
} pd_VecTupleAccountIdu32_t;

typedef struct {
    uint64_t _len;
    const uint8_t *_ptr;
    uint64_t _lenBuffer;
} pd_VecValidatorIndex_t;

typedef struct {
    uint64_t _len;
    const uint8_t *_ptr;
    uint64_t _lenBuffer;
} pd_Vecu32_t;

typedef struct {
    uint8_t some;
    pd_AccountId_t contained;
} pd_OptionAccountId_t;

typedef struct {
    uint8_t some;
    pd_ChangesTrieConfiguration_t contained;
} pd_OptionChangesTrieConfiguration_t;

typedef struct {
    uint8_t some;
    pd_Timepoint_t contained;
} pd_OptionTimepoint_t;

typedef struct {
    uint8_t some;
    pd_TupleBalanceOfBalanceOfBlockNumber_t contained;
} pd_OptionTupleBalanceOfBalanceOfBlockNumber_t;

// Types with dependencies

typedef pd_VecKey_t pd_Keys_t;
typedef pd_Key_t pd_KeyValue_t;

// Read functions

parser_error_t _readAccountId(parser_context_t *c, pd_AccountId_t *v);
parser_error_t _readAccountIndex(parser_context_t *c, pd_AccountIndex_t *v);
parser_error_t _readAccountVoteSplit(parser_context_t *c, pd_AccountVoteSplit_t *v);
parser_error_t _readAccountVoteStandard(parser_context_t *c, pd_AccountVoteStandard_t *v);
parser_error_t _readAccountVote(parser_context_t *c, pd_AccountVote_t *v);
parser_error_t _readAttestedCandidate(parser_context_t *c, pd_AttestedCandidate_t *v);
parser_error_t _readBalanceOf(parser_context_t *c, pd_BalanceOf_t *v);
parser_error_t _readBlockNumber(parser_context_t *c, pd_BlockNumber_t *v);
parser_error_t _readBytes(parser_context_t *c, pd_Bytes_t *v);
parser_error_t _readCall(parser_context_t *c, pd_Call_t *v);
parser_error_t _readChangesTrieConfiguration(parser_context_t *c, pd_ChangesTrieConfiguration_t *v);
parser_error_t _readCollatorId(parser_context_t *c, pd_CollatorId_t *v);
parser_error_t _readCompactAssignments(parser_context_t *c, pd_CompactAssignments_t *v);
parser_error_t _readCompactAuctionIndex(parser_context_t *c, pd_CompactAuctionIndex_t *v);
parser_error_t _readCompactBalanceOf(parser_context_t *c, pd_CompactBalanceOf_t *v);
parser_error_t _readCompactBlockNumber(parser_context_t *c, pd_CompactBlockNumber_t *v);
parser_error_t _readCompactEraIndex(parser_context_t *c, pd_CompactEraIndex_t *v);
parser_error_t _readCompactLeasePeriodOf(parser_context_t *c, pd_CompactLeasePeriodOf_t *v);
parser_error_t _readCompactMemberCount(parser_context_t *c, pd_CompactMemberCount_t *v);
parser_error_t _readCompactMoment(parser_context_t *c, pd_CompactMoment_t *v);
parser_error_t _readCompactParaId(parser_context_t *c, pd_CompactParaId_t *v);
parser_error_t _readCompactPropIndex(parser_context_t *c, pd_CompactPropIndex_t *v);
parser_error_t _readCompactProposalIndex(parser_context_t *c, pd_CompactProposalIndex_t *v);
parser_error_t _readCompactReferendumIndex(parser_context_t *c, pd_CompactReferendumIndex_t *v);
parser_error_t _readCompactRegistrarIndex(parser_context_t *c, pd_CompactRegistrarIndex_t *v);
parser_error_t _readCompactSubId(parser_context_t *c, pd_CompactSubId_t *v);
parser_error_t _readCompactu32(parser_context_t *c, pd_Compactu32_t *v);
parser_error_t _readConviction(parser_context_t *c, pd_Conviction_t *v);
parser_error_t _readData(parser_context_t *c, pd_Data_t *v);
parser_error_t _readDoubleVoteReport(parser_context_t *c, pd_DoubleVoteReport_t *v);
parser_error_t _readEcdsaSignature(parser_context_t *c, pd_EcdsaSignature_t *v);
parser_error_t _readEraIndex(parser_context_t *c, pd_EraIndex_t *v);
parser_error_t _readEthereumAddress(parser_context_t *c, pd_EthereumAddress_t *v);
parser_error_t _readHeadData(parser_context_t *c, pd_HeadData_t *v);
parser_error_t _readHeader(parser_context_t *c, pd_Header_t *v);
parser_error_t _readHeartbeat(parser_context_t *c, pd_Heartbeat_t *v);
parser_error_t _readIdentityFields(parser_context_t *c, pd_IdentityFields_t *v);
parser_error_t _readIdentityInfo(parser_context_t *c, pd_IdentityInfo_t *v);
parser_error_t _readIdentityJudgement(parser_context_t *c, pd_IdentityJudgement_t *v);
parser_error_t _readKeyValue(parser_context_t *c, pd_KeyValue_t *v);
parser_error_t _readKey(parser_context_t *c, pd_Key_t *v);
parser_error_t _readKeys(parser_context_t *c, pd_Keys_t *v);
parser_error_t _readLookupSource(parser_context_t *c, pd_LookupSource_t *v);
parser_error_t _readMoreAttestations(parser_context_t *c, pd_MoreAttestations_t *v);
parser_error_t _readOptionAccountId(parser_context_t *c, pd_OptionAccountId_t *v);
parser_error_t _readOptionChangesTrieConfiguration(parser_context_t *c, pd_OptionChangesTrieConfiguration_t *v);
parser_error_t _readOptionTimepoint(parser_context_t *c, pd_OptionTimepoint_t *v);
parser_error_t _readOptionTupleBalanceOfBalanceOfBlockNumber(parser_context_t *c, pd_OptionTupleBalanceOfBalanceOfBlockNumber_t *v);
parser_error_t _readOptionu8_array_20(parser_context_t *c, pd_Optionu8_array_20_t *v);
parser_error_t _readParaInfo(parser_context_t *c, pd_ParaInfo_t *v);
parser_error_t _readPerbill(parser_context_t *c, pd_Perbill_t *v);
parser_error_t _readPhragmenScore(parser_context_t *c, pd_PhragmenScore_t *v);
parser_error_t _readReferendumIndex(parser_context_t *c, pd_ReferendumIndex_t *v);
parser_error_t _readRegistrarIndex(parser_context_t *c, pd_RegistrarIndex_t *v);
parser_error_t _readRewardDestination(parser_context_t *c, pd_RewardDestination_t *v);
parser_error_t _readSignature(parser_context_t *c, pd_Signature_t *v);
parser_error_t _readSocietyJudgement(parser_context_t *c, pd_SocietyJudgement_t *v);
parser_error_t _readTimepoint(parser_context_t *c, pd_Timepoint_t *v);
parser_error_t _readTupleAccountIdData(parser_context_t *c, pd_TupleAccountIdData_t *v);
parser_error_t _readTupleAccountIdu32(parser_context_t *c, pd_TupleAccountIdu32_t *v);
parser_error_t _readTupleBalanceOfBalanceOfBlockNumber(parser_context_t *c, pd_TupleBalanceOfBalanceOfBlockNumber_t *v);
parser_error_t _readTupleDataData(parser_context_t *c, pd_TupleDataData_t *v);
parser_error_t _readValidationCode(parser_context_t *c, pd_ValidationCode_t *v);
parser_error_t _readValidatorIndex(parser_context_t *c, pd_ValidatorIndex_t *v);
parser_error_t _readValidatorPrefs(parser_context_t *c, pd_ValidatorPrefs_t *v);
parser_error_t _readVecAccountId(parser_context_t *c, pd_VecAccountId_t *v);
parser_error_t _readVecAttestedCandidate(parser_context_t *c, pd_VecAttestedCandidate_t *v);
parser_error_t _readVecCall(parser_context_t *c, pd_VecCall_t *v);
parser_error_t _readVecHeader(parser_context_t *c, pd_VecHeader_t *v);
parser_error_t _readVecKeyValue(parser_context_t *c, pd_VecKeyValue_t *v);
parser_error_t _readVecKey(parser_context_t *c, pd_VecKey_t *v);
parser_error_t _readVecLookupSource(parser_context_t *c, pd_VecLookupSource_t *v);
parser_error_t _readVecTupleAccountIdData(parser_context_t *c, pd_VecTupleAccountIdData_t *v);
parser_error_t _readVecTupleAccountIdu32(parser_context_t *c, pd_VecTupleAccountIdu32_t *v);
parser_error_t _readVecTupleDataData(parser_context_t *c, pd_VecTupleDataData_t *v);
parser_error_t _readVecValidatorIndex(parser_context_t *c, pd_VecValidatorIndex_t *v);
parser_error_t _readVecu32(parser_context_t *c, pd_Vecu32_t *v);
parser_error_t _readVestingInfo(parser_context_t *c, pd_VestingInfo_t *v);
parser_error_t _readVote(parser_context_t *c, pd_Vote_t *v);
parser_error_t _readbool(parser_context_t *c, pd_bool_t *v);
parser_error_t _readu16(parser_context_t *c, pd_u16_t *v);
parser_error_t _readu32(parser_context_t *c, pd_u32_t *v);
parser_error_t _readu64(parser_context_t *c, pd_u64_t *v);
parser_error_t _readu8_array_20(parser_context_t *c, pd_u8_array_20_t *v);
parser_error_t _readu8_array_32(parser_context_t *c, pd_u8_array_32_t *v);

// toString functions

parser_error_t _toStringAccountId(
    const pd_AccountId_t *v,
    char *outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t *pageCount);

parser_error_t _toStringAccountIndex(
    const pd_AccountIndex_t *v,
    char *outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t *pageCount);

parser_error_t _toStringAccountVoteSplit(
    const pd_AccountVoteSplit_t *v,
    char *outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t *pageCount);

parser_error_t _toStringAccountVoteStandard(
    const pd_AccountVoteStandard_t *v,
    char *outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t *pageCount);

parser_error_t _toStringAccountVote(
    const pd_AccountVote_t *v,
    char *outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t *pageCount);

parser_error_t _toStringAttestedCandidate(
    const pd_AttestedCandidate_t *v,
    char *outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t *pageCount);

parser_error_t _toStringBalanceOf(
    const pd_BalanceOf_t *v,
    char *outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t *pageCount);

parser_error_t _toStringBlockNumber(
    const pd_BlockNumber_t *v,
    char *outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t *pageCount);

parser_error_t _toStringBytes(
    const pd_Bytes_t *v,
    char *outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t *pageCount);

parser_error_t _toStringCall(
    const pd_Call_t *v,
    char *outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t *pageCount);

parser_error_t _toStringChangesTrieConfiguration(
    const pd_ChangesTrieConfiguration_t *v,
    char *outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t *pageCount);

parser_error_t _toStringCollatorId(
    const pd_CollatorId_t *v,
    char *outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t *pageCount);

parser_error_t _toStringCompactAssignments(
    const pd_CompactAssignments_t *v,
    char *outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t *pageCount);

parser_error_t _toStringCompactAuctionIndex(
    const pd_CompactAuctionIndex_t *v,
    char *outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t *pageCount);

parser_error_t _toStringCompactBalanceOf(
    const pd_CompactBalanceOf_t *v,
    char *outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t *pageCount);

parser_error_t _toStringCompactBlockNumber(
    const pd_CompactBlockNumber_t *v,
    char *outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t *pageCount);

parser_error_t _toStringCompactEraIndex(
    const pd_CompactEraIndex_t *v,
    char *outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t *pageCount);

parser_error_t _toStringCompactLeasePeriodOf(
    const pd_CompactLeasePeriodOf_t *v,
    char *outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t *pageCount);

parser_error_t _toStringCompactMemberCount(
    const pd_CompactMemberCount_t *v,
    char *outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t *pageCount);

parser_error_t _toStringCompactMoment(
    const pd_CompactMoment_t *v,
    char *outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t *pageCount);

parser_error_t _toStringCompactParaId(
    const pd_CompactParaId_t *v,
    char *outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t *pageCount);

parser_error_t _toStringCompactPropIndex(
    const pd_CompactPropIndex_t *v,
    char *outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t *pageCount);

parser_error_t _toStringCompactProposalIndex(
    const pd_CompactProposalIndex_t *v,
    char *outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t *pageCount);

parser_error_t _toStringCompactReferendumIndex(
    const pd_CompactReferendumIndex_t *v,
    char *outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t *pageCount);

parser_error_t _toStringCompactRegistrarIndex(
    const pd_CompactRegistrarIndex_t *v,
    char *outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t *pageCount);

parser_error_t _toStringCompactSubId(
    const pd_CompactSubId_t *v,
    char *outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t *pageCount);

parser_error_t _toStringCompactu32(
    const pd_Compactu32_t *v,
    char *outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t *pageCount);

parser_error_t _toStringConviction(
    const pd_Conviction_t *v,
    char *outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t *pageCount);

parser_error_t _toStringData(
    const pd_Data_t *v,
    char *outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t *pageCount);

parser_error_t _toStringDoubleVoteReport(
    const pd_DoubleVoteReport_t *v,
    char *outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t *pageCount);

parser_error_t _toStringEcdsaSignature(
    const pd_EcdsaSignature_t *v,
    char *outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t *pageCount);

parser_error_t _toStringEraIndex(
    const pd_EraIndex_t *v,
    char *outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t *pageCount);

parser_error_t _toStringEthereumAddress(
    const pd_EthereumAddress_t *v,
    char *outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t *pageCount);

parser_error_t _toStringHeadData(
    const pd_HeadData_t *v,
    char *outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t *pageCount);

parser_error_t _toStringHeader(
    const pd_Header_t *v,
    char *outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t *pageCount);

parser_error_t _toStringHeartbeat(
    const pd_Heartbeat_t *v,
    char *outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t *pageCount);

parser_error_t _toStringIdentityFields(
    const pd_IdentityFields_t *v,
    char *outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t *pageCount);

parser_error_t _toStringIdentityInfo(
    const pd_IdentityInfo_t *v,
    char *outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t *pageCount);

parser_error_t _toStringIdentityJudgement(
    const pd_IdentityJudgement_t *v,
    char *outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t *pageCount);

parser_error_t _toStringKeyValue(
    const pd_KeyValue_t *v,
    char *outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t *pageCount);

parser_error_t _toStringKey(
    const pd_Key_t *v,
    char *outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t *pageCount);

parser_error_t _toStringKeys(
    const pd_Keys_t *v,
    char *outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t *pageCount);

parser_error_t _toStringLookupSource(
    const pd_LookupSource_t *v,
    char *outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t *pageCount);

parser_error_t _toStringMoreAttestations(
    const pd_MoreAttestations_t *v,
    char *outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t *pageCount);

parser_error_t _toStringOptionAccountId(
    const pd_OptionAccountId_t *v,
    char *outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t *pageCount);

parser_error_t _toStringOptionChangesTrieConfiguration(
    const pd_OptionChangesTrieConfiguration_t *v,
    char *outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t *pageCount);

parser_error_t _toStringOptionTimepoint(
    const pd_OptionTimepoint_t *v,
    char *outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t *pageCount);

parser_error_t _toStringOptionTupleBalanceOfBalanceOfBlockNumber(
    const pd_OptionTupleBalanceOfBalanceOfBlockNumber_t *v,
    char *outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t *pageCount);

parser_error_t _toStringOptionu8_array_20(
    const pd_Optionu8_array_20_t *v,
    char *outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t *pageCount);

parser_error_t _toStringParaInfo(
    const pd_ParaInfo_t *v,
    char *outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t *pageCount);

parser_error_t _toStringPerbill(
    const pd_Perbill_t *v,
    char *outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t *pageCount);

parser_error_t _toStringPhragmenScore(
    const pd_PhragmenScore_t *v,
    char *outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t *pageCount);

parser_error_t _toStringReferendumIndex(
    const pd_ReferendumIndex_t *v,
    char *outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t *pageCount);

parser_error_t _toStringRegistrarIndex(
    const pd_RegistrarIndex_t *v,
    char *outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t *pageCount);

parser_error_t _toStringRewardDestination(
    const pd_RewardDestination_t *v,
    char *outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t *pageCount);

parser_error_t _toStringSignature(
    const pd_Signature_t *v,
    char *outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t *pageCount);

parser_error_t _toStringSocietyJudgement(
    const pd_SocietyJudgement_t *v,
    char *outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t *pageCount);

parser_error_t _toStringTimepoint(
    const pd_Timepoint_t *v,
    char *outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t *pageCount);

parser_error_t _toStringTupleAccountIdData(
    const pd_TupleAccountIdData_t *v,
    char *outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t *pageCount);

parser_error_t _toStringTupleAccountIdu32(
    const pd_TupleAccountIdu32_t *v,
    char *outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t *pageCount);

parser_error_t _toStringTupleBalanceOfBalanceOfBlockNumber(
    const pd_TupleBalanceOfBalanceOfBlockNumber_t *v,
    char *outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t *pageCount);

parser_error_t _toStringTupleDataData(
    const pd_TupleDataData_t *v,
    char *outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t *pageCount);

parser_error_t _toStringValidationCode(
    const pd_ValidationCode_t *v,
    char *outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t *pageCount);

parser_error_t _toStringValidatorIndex(
    const pd_ValidatorIndex_t *v,
    char *outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t *pageCount);

parser_error_t _toStringValidatorPrefs(
    const pd_ValidatorPrefs_t *v,
    char *outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t *pageCount);

parser_error_t _toStringVecAccountId(
    const pd_VecAccountId_t *v,
    char *outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t *pageCount);

parser_error_t _toStringVecAttestedCandidate(
    const pd_VecAttestedCandidate_t *v,
    char *outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t *pageCount);

parser_error_t _toStringVecCall(
    const pd_VecCall_t *v,
    char *outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t *pageCount);

parser_error_t _toStringVecHeader(
    const pd_VecHeader_t *v,
    char *outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t *pageCount);

parser_error_t _toStringVecKeyValue(
    const pd_VecKeyValue_t *v,
    char *outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t *pageCount);

parser_error_t _toStringVecKey(
    const pd_VecKey_t *v,
    char *outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t *pageCount);

parser_error_t _toStringVecLookupSource(
    const pd_VecLookupSource_t *v,
    char *outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t *pageCount);

parser_error_t _toStringVecTupleAccountIdData(
    const pd_VecTupleAccountIdData_t *v,
    char *outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t *pageCount);

parser_error_t _toStringVecTupleAccountIdu32(
    const pd_VecTupleAccountIdu32_t *v,
    char *outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t *pageCount);

parser_error_t _toStringVecTupleDataData(
    const pd_VecTupleDataData_t *v,
    char *outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t *pageCount);

parser_error_t _toStringVecValidatorIndex(
    const pd_VecValidatorIndex_t *v,
    char *outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t *pageCount);

parser_error_t _toStringVecu32(
    const pd_Vecu32_t *v,
    char *outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t *pageCount);

parser_error_t _toStringVestingInfo(
    const pd_VestingInfo_t *v,
    char *outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t *pageCount);

parser_error_t _toStringVote(
    const pd_Vote_t *v,
    char *outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t *pageCount);

parser_error_t _toStringbool(
    const pd_bool_t *v,
    char *outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t *pageCount);

parser_error_t _toStringu16(
    const pd_u16_t *v,
    char *outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t *pageCount);

parser_error_t _toStringu32(
    const pd_u32_t *v,
    char *outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t *pageCount);

parser_error_t _toStringu64(
    const pd_u64_t *v,
    char *outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t *pageCount);

parser_error_t _toStringu8_array_20(
    const pd_u8_array_20_t *v,
    char *outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t *pageCount);

parser_error_t _toStringu8_array_32(
    const pd_u8_array_32_t *v,
    char *outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t *pageCount);


#include "polkadot_methods.h"

#ifdef __cplusplus
}
#endif
