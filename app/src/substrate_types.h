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

#include <stddef.h>
#include <stdint.h>

// https://github.com/paritytech/substrate/blob/effe489951d1edab9d34846b1eefdfaf9511dab9/frame/identity/src/lib.rs
#define Data_e_NONE 0
#define Data_e_RAW_VECU8 33
#define Data_e_BLAKETWO256U8_32 34
#define Data_e_SHA256_U8_32 35
#define Data_e_KECCAK256_U8_32 36
#define Data_e_SHATHREE256_U8_32 37

typedef uint8_t pd_bool_t;
typedef uint16_t pd_u16_t;
typedef uint32_t pd_u32_t;
typedef uint64_t pd_u64_t;

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
    const uint8_t* ptr;
    uint8_t len;
} compactInt_t;

////////////////////////
// Not supported types
////////////////////////

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wextern-c-compat"
// NOTE: These are large types that cannot be reviewed in the device.
// They will be marked as not supported
typedef struct {
} pd_AttestedCandidate_t;
typedef struct {
} pd_Header_t;
typedef struct {
} pd_Heartbeat_t;
#pragma clang diagnostic pop

////////////////////////
// Types that require out of order declaration
////////////////////////

typedef enum {
    eAddressIndex = 0,
    eAddressId = 1
} pd_Address_e;

typedef struct {
    pd_Address_e type;
    uint64_t idx;
    const uint8_t* idPtr;
} pd_Address_t;

typedef struct {
    compactInt_t index;
} pd_CompactIndex_t;

typedef struct {
    compactInt_t value;
} pd_CompactBalance_t;

typedef struct {
    const uint8_t* _ptr;
} pd_Hash_t;

typedef struct {
    const uint8_t* _ptr;
} pd_BalanceOf_t;

typedef struct {
    uint8_t value;
} pd_Conviction_t;

typedef struct {
    const uint8_t* _ptr;
} pd_u8_array_20_t;

typedef struct {
    uint8_t some;
    pd_u8_array_20_t contained;
} pd_Optionu8_array_20_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecTupleDataData_t;

////////////////////////
////////////////////////
////////////////////////
////////////////////////

typedef compactInt_t pd_Compactu32_t; // u32
typedef compactInt_t pd_Compactu64_t; // u64
typedef pd_CompactBalance_t pd_CompactBalanceOf_t;
typedef uint32_t pd_BlockNumber_t; // u32

// Based
// https://github.com/paritytech/substrate/blob/master/node/primitives/src/lib.rs

typedef struct {
    uint8_t type;
    const uint8_t* _ptr;
    uint8_t _len;
} pd_Data_t;

typedef struct {
    pd_Data_t data1;
    pd_Data_t data2;
} pd_TupleDataData_t;

typedef struct {
    pd_bool_t aye;
    pd_Conviction_t conviction;
} pd_Vote_t;

typedef struct {
    const uint8_t* _ptr;
} pd_AccountId_t;

typedef struct {
    pd_BalanceOf_t aye;
    pd_BalanceOf_t nay;
} pd_AccountVoteSplit_t;

typedef struct {
    pd_Vote_t vote;
    pd_BalanceOf_t balance;
} pd_AccountVoteStandard_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_Call_t;

typedef struct {
    pd_u32_t digest_interval;
    pd_u32_t digest_levels;
} pd_ChangesTrieConfiguration_t;

typedef struct {
    compactInt_t value;
} pd_CompactPerBill_t;

typedef struct {
    const uint8_t* _ptr;
} pd_Key_t;

typedef struct {
    const uint8_t* _ptr;
} pd_LookupSource_t;

typedef struct {
    uint64_t value;
} pd_Period_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_ProxyType_t;

typedef struct {
    uint32_t value;
} pd_ReferendumIndex_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_StatementKind_t;

typedef struct {
    pd_u32_t dependency_id;
    uint8_t weight;
    pd_bool_t is_exclusive;
} pd_StreamDependency_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_Timepoint_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_TupleAccountIdData_t;

typedef struct {
    pd_BalanceOf_t balance1;
    pd_BalanceOf_t balance2;
    pd_BlockNumber_t blockNumber;
} pd_TupleBalanceOfBalanceOfBlockNumber_t;

typedef struct {
    uint16_t value;
} pd_ValidatorIndex_t;

typedef struct {
    uint8_t value;
    union {
        pd_AccountVoteStandard_t voteStandard;
        pd_AccountVoteSplit_t voteSplit;
    };
} pd_AccountVote_t;

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
    uint8_t some;
    pd_ChangesTrieConfiguration_t contained;
} pd_OptionChangesTrieConfiguration_t;

typedef struct {
    uint8_t some;
    pd_TupleBalanceOfBalanceOfBlockNumber_t contained;
} pd_OptionTupleBalanceOfBalanceOfBlockNumber_t;

typedef struct {
    uint32_t stream_id;
    pd_StreamDependency_t dependency;
} pd_Priority_t;

typedef struct {
    pd_CompactPerBill_t commission;
} pd_ValidatorPrefs_t;

typedef struct {
    pd_BalanceOf_t locked;
    pd_BalanceOf_t per_block;
    pd_BlockNumber_t starting_block;
} pd_VestingInfo_t;

typedef struct {
    uint32_t value;
} pd_AccountIndex_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_Bytes_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_CallHashOf_t;

typedef compactInt_t pd_CompactAssignments_t;

typedef compactInt_t pd_CompactBlockNumber_t;

typedef compactInt_t pd_CompactBountyIndex_t;

typedef compactInt_t pd_CompactEraIndex_t;

typedef compactInt_t pd_CompactMemberCount_t;

typedef compactInt_t pd_CompactMoment_t;

typedef compactInt_t pd_CompactPropIndex_t;

typedef compactInt_t pd_CompactProposalIndex_t;

typedef compactInt_t pd_CompactReferendumIndex_t;

typedef compactInt_t pd_CompactRegistrarIndex_t;

typedef compactInt_t pd_CompactWeight_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_DefunctVoter_t;

typedef struct {
    const uint8_t* _ptr;
} pd_EcdsaSignature_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_ElectionScore_t;

typedef struct {
    compactInt_t validators;
    compactInt_t nominators;
} pd_ElectionSize_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_EquivocationProof_t;

typedef struct {
    uint32_t value;
} pd_EraIndex_t;

typedef struct {
    const uint8_t* _ptr;
} pd_EthereumAddress_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_IdentityFields_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_Judgement_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_KeyOwnerProof_t;

typedef struct {
    uint32_t value;
} pd_MemberCount_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_OpaqueCall_t;

typedef struct {
    uint8_t some;
    pd_AccountId_t contained;
} pd_OptionAccountId_t;

typedef struct {
    uint8_t some;
    pd_Period_t contained;
} pd_OptionPeriod_t;

typedef struct {
    uint8_t some;
    pd_ProxyType_t contained;
} pd_OptionProxyType_t;

typedef struct {
    uint8_t some;
    pd_ReferendumIndex_t contained;
} pd_OptionReferendumIndex_t;

typedef struct {
    uint8_t some;
    pd_StatementKind_t contained;
} pd_OptionStatementKind_t;

typedef struct {
    uint8_t some;
    pd_Timepoint_t contained;
} pd_OptionTimepoint_t;

typedef struct {
    uint32_t value;
} pd_Perbill_t;

typedef struct {
    compactInt_t value;
} pd_Percent_t;

typedef struct {
    uint32_t value;
} pd_RegistrarIndex_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_Renouncing_t;

typedef struct {
    uint8_t value;
} pd_RewardDestination_t;

typedef struct {
    const uint8_t* _ptr;
} pd_Signature_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecAccountId_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecCall_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecHeader_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecKeyValue_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecKey_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecLookupSource_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecTupleAccountIdData_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecValidatorIndex_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_Vecu32_t;

typedef struct {
    uint64_t value;
} pd_Weight_t;

typedef struct {
    const uint8_t* _ptr;
} pd_u8_array_32_t;

// Types with dependencies

typedef pd_VecKey_t pd_Keys_t;
typedef pd_Key_t pd_KeyValue_t;

#include "substrate_methods.h"

#ifdef __cplusplus
}
#endif
