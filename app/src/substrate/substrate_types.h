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

#include "stdbool.h"
#include <stddef.h>
#include <stdint.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wextern-c-compat"
#pragma clang diagnostic pop

// https://github.com/paritytech/substrate/blob/effe489951d1edab9d34846b1eefdfaf9511dab9/frame/identity/src/lib.rs
#define Data_e_NONE 0
#define Data_e_RAW_VECU8 33
#define Data_e_BLAKETWO256U8_32 34
#define Data_e_SHA256_U8_32 35
#define Data_e_KECCAK256_U8_32 36
#define Data_e_SHATHREE256_U8_32 37

typedef uint8_t pd_bool_t;
typedef uint8_t pd_u8_t;
typedef uint16_t pd_u16_t;
typedef uint32_t pd_u32_t;
typedef uint64_t pd_u64_t;
typedef uint32_t pd_BlockNumber_t;

#define CHECK_ERROR(FUNC_CALL)          \
    {                                   \
        parser_error_t err = FUNC_CALL; \
        if (err != parser_ok)           \
            return err;                 \
    }

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

typedef struct {
    uint32_t _lenBuffer;
    const uint8_t* _ptr; // Pointer to actual
    const uint8_t* _nextPtr; // Pointer to next Call
    uint8_t slotIdx; // Count of nested calls
    bool isTail;
} pd_NestCallIdx_t;

////////////////////////
// Common types
////////////////////////

typedef compactInt_t pd_Compactu32_t; // u32
typedef compactInt_t pd_Compactu64_t; // u64
typedef compactInt_t pd_CompactAssignments_t;
typedef compactInt_t pd_CompactBountyIndex_t;
typedef compactInt_t pd_CompactEraIndex_t;
typedef compactInt_t pd_CompactMemberCount_t;
typedef compactInt_t pd_CompactMoment_t;
typedef compactInt_t pd_CompactPropIndex_t;
typedef compactInt_t pd_CompactProposalIndex_t;
typedef compactInt_t pd_CompactReferendumIndex_t;
typedef compactInt_t pd_CompactRegistrarIndex_t;
typedef compactInt_t pd_CompactWeight_t;

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
    uint64_t _len;
    const uint8_t* _ptr;
} pd_Bytes_t;

typedef struct {
    pd_Compactu32_t nom;
    pd_Compactu32_t denom;
} pd_Fraction_t;

typedef struct {
    uint8_t value;
    union {
        pd_Bytes_t named;
        pd_Compactu32_t index;
    };
} pd_BodyId_t;

typedef struct {
    uint8_t value;
    union {
        pd_Compactu32_t count;
        pd_Fraction_t fraction;
    };
} pd_BodyPart_t;

typedef struct {
    uint8_t value;
    pd_Bytes_t named;
} pd_NetworkId_t;

typedef struct {
    const uint8_t* _ptr;
} pd_u8_array_20_t;

typedef struct {
    const uint8_t* _ptr;
} pd_u8_array_32_t;

typedef struct {
    pd_NetworkId_t networkId;
    pd_u8_array_32_t key;
} pd_AccountId32_t;

typedef struct {
    pd_NetworkId_t networkId;
    pd_Compactu64_t index;
} pd_AccountIndex64_t;

typedef struct {
    pd_NetworkId_t networkId;
    pd_u8_array_20_t key;
} pd_AccountKey20_t;

typedef compactInt_t pd_Compactu128_t;

typedef struct {
    pd_BodyId_t id;
    pd_BodyPart_t part;
} pd_Plurality_t;

typedef struct {
    uint8_t value;
    union {
        pd_Compactu32_t parachain;
        pd_AccountId32_t accountId32;
        pd_AccountIndex64_t accountIndex64;
        pd_AccountKey20_t accountKey20;
        uint8_t palletInstance;
        pd_Compactu128_t generalIndex;
        pd_Bytes_t generalKey;
        pd_Plurality_t plurality;
    };
} pd_JunctionV0_t;

typedef struct {
    uint8_t value;
    union {
        pd_Compactu32_t parachain;
        pd_AccountId32_t accountId32;
        pd_AccountIndex64_t accountIndex64;
        pd_AccountKey20_t accountKey20;
        uint8_t palletInstance;
        pd_Compactu128_t generalIndex;
        pd_Bytes_t generalKey;
        pd_Plurality_t plurality;
    };
} pd_JunctionV1_t;

typedef struct {
    pd_JunctionV0_t junction;
} pd_JunctionV0X1_t;

typedef struct {
    pd_JunctionV0_t junction0;
    pd_JunctionV0_t junction1;
} pd_JunctionV0X2_t;

typedef struct {
    pd_JunctionV0_t junction0;
    pd_JunctionV0_t junction1;
    pd_JunctionV0_t junction2;
} pd_JunctionV0X3_t;

typedef struct {
    pd_JunctionV0_t junction0;
    pd_JunctionV0_t junction1;
    pd_JunctionV0_t junction2;
    pd_JunctionV0_t junction3;
} pd_JunctionV0X4_t;

typedef struct {
    pd_JunctionV0_t junction0;
    pd_JunctionV0_t junction1;
    pd_JunctionV0_t junction2;
    pd_JunctionV0_t junction3;
    pd_JunctionV0_t junction4;
} pd_JunctionV0X5_t;

typedef struct {
    pd_JunctionV0_t junction0;
    pd_JunctionV0_t junction1;
    pd_JunctionV0_t junction2;
    pd_JunctionV0_t junction3;
    pd_JunctionV0_t junction4;
    pd_JunctionV0_t junction5;
} pd_JunctionV0X6_t;

typedef struct {
    pd_JunctionV0_t junction0;
    pd_JunctionV0_t junction1;
    pd_JunctionV0_t junction2;
    pd_JunctionV0_t junction3;
    pd_JunctionV0_t junction4;
    pd_JunctionV0_t junction5;
    pd_JunctionV0_t junction6;
} pd_JunctionV0X7_t;

typedef struct {
    pd_JunctionV0_t junction0;
    pd_JunctionV0_t junction1;
    pd_JunctionV0_t junction2;
    pd_JunctionV0_t junction3;
    pd_JunctionV0_t junction4;
    pd_JunctionV0_t junction5;
    pd_JunctionV0_t junction6;
    pd_JunctionV0_t junction7;
} pd_JunctionV0X8_t;

typedef struct {
    pd_JunctionV1_t junction;
} pd_JunctionV1X1_t;

typedef struct {
    pd_JunctionV1_t junction0;
    pd_JunctionV1_t junction1;
} pd_JunctionV1X2_t;

typedef struct {
    pd_JunctionV1_t junction0;
    pd_JunctionV1_t junction1;
    pd_JunctionV1_t junction2;
} pd_JunctionV1X3_t;

typedef struct {
    pd_JunctionV1_t junction0;
    pd_JunctionV1_t junction1;
    pd_JunctionV1_t junction2;
    pd_JunctionV1_t junction3;
} pd_JunctionV1X4_t;

typedef struct {
    pd_JunctionV1_t junction0;
    pd_JunctionV1_t junction1;
    pd_JunctionV1_t junction2;
    pd_JunctionV1_t junction3;
    pd_JunctionV1_t junction4;
} pd_JunctionV1X5_t;

typedef struct {
    pd_JunctionV1_t junction0;
    pd_JunctionV1_t junction1;
    pd_JunctionV1_t junction2;
    pd_JunctionV1_t junction3;
    pd_JunctionV1_t junction4;
    pd_JunctionV1_t junction5;
} pd_JunctionV1X6_t;

typedef struct {
    pd_JunctionV1_t junction0;
    pd_JunctionV1_t junction1;
    pd_JunctionV1_t junction2;
    pd_JunctionV1_t junction3;
    pd_JunctionV1_t junction4;
    pd_JunctionV1_t junction5;
    pd_JunctionV1_t junction6;
} pd_JunctionV1X7_t;

typedef struct {
    pd_JunctionV1_t junction0;
    pd_JunctionV1_t junction1;
    pd_JunctionV1_t junction2;
    pd_JunctionV1_t junction3;
    pd_JunctionV1_t junction4;
    pd_JunctionV1_t junction5;
    pd_JunctionV1_t junction6;
    pd_JunctionV1_t junction7;
} pd_JunctionV1X8_t;

typedef struct {
    uint8_t value;
    union {
        pd_JunctionV0X1_t x1;
        pd_JunctionV0X2_t x2;
        pd_JunctionV0X3_t x3;
        pd_JunctionV0X4_t x4;
        pd_JunctionV0X5_t x5;
        pd_JunctionV0X6_t x6;
        pd_JunctionV0X7_t x7;
        pd_JunctionV0X8_t x8;
    };
} pd_JunctionsV0_t;

typedef struct {
    uint8_t value;
    union {
        pd_JunctionV1X1_t x1;
        pd_JunctionV1X2_t x2;
        pd_JunctionV1X3_t x3;
        pd_JunctionV1X4_t x4;
        pd_JunctionV1X5_t x5;
        pd_JunctionV1X6_t x6;
        pd_JunctionV1X7_t x7;
        pd_JunctionV1X8_t x8;
    };
} pd_JunctionsV1_t;

typedef struct {
    uint8_t value;
    union {
        const uint8_t* _ptr;
        pd_Compactu128_t index;
        pd_Bytes_t blob;
    };
} pd_AssetInstance_t;

typedef struct {
    pd_JunctionsV0_t junctions;
} pd_MultiLocationV0_t;

typedef struct {
    uint8_t parents;
    pd_JunctionsV1_t interior;
} pd_MultiLocationV1_t;

typedef struct {
    pd_Bytes_t id;
    pd_Compactu128_t amount;
} pd_AbstractFungible_t;

typedef struct {
    pd_Bytes_t _class;
    pd_AssetInstance_t instance;
} pd_AbstractNonFungible_t;

typedef struct {
    const uint8_t* _ptr;
} pd_Balance_t;

typedef struct {
    pd_MultiLocationV0_t id;
    pd_CompactBalance_t amount;
} pd_ConcreteFungible_t;

typedef struct {
    pd_MultiLocationV0_t _class;
    pd_AssetInstance_t instance;
} pd_ConcreteNonFungible_t;

typedef struct {
    uint8_t value;
    const uint8_t* _ptr;
} pd_Data_t;

typedef struct {
    uint8_t value;
    union {
        pd_Compactu128_t fungible;
        pd_AssetInstance_t nonFungible;
    };
} pd_Fungibility_t;

typedef struct {
    uint8_t value;
    union {
        pd_MultiLocationV1_t concrete;
        pd_Bytes_t abstract;
    };
} pd_MultiAssetId_t;

typedef struct {
    const uint8_t* _ptr;
} pd_AccountId_t;

typedef struct {
    pd_Balance_t value;
} pd_BalanceOf_t;

typedef struct {
    compactInt_t value;
} pd_CompactAccountIndex_t;

typedef struct {
    const uint8_t* _ptr;
} pd_EcdsaPublic_t;

typedef struct {
    const uint8_t* _ptr;
} pd_EcdsaSignature_t;

typedef struct {
    const uint8_t* _ptr;
} pd_Ed25519Public_t;

typedef struct {
    const uint8_t* _ptr;
} pd_Ed25519Signature_t;

typedef struct {
    const uint8_t* _ptr;
} pd_H256_t;

typedef struct {
    uint8_t value;
    union {
        pd_Bytes_t abstract;
        pd_MultiLocationV0_t concrete;
        pd_AbstractFungible_t abstractFungible;
        pd_AbstractNonFungible_t abstractNonFungible;
        pd_ConcreteFungible_t concreteFungible;
        pd_ConcreteNonFungible_t concreteNonFungible;
    };
} pd_MultiAssetV0_t;

typedef struct {
    pd_MultiAssetId_t assetId;
    pd_Fungibility_t fungibility;
} pd_MultiAssetV1_t;

typedef struct {
    const uint8_t* _ptr;
} pd_Sr25519Public_t;

typedef struct {
    const uint8_t* _ptr;
} pd_Sr25519Signature_t;

typedef struct {
    pd_Data_t data1;
    pd_Data_t data2;
} pd_TupleDataData_t;

typedef struct {
    uint8_t value;
} pd_Vote_t;

typedef struct {
    uint8_t value;
    union {
        pd_AccountId_t id;
        pd_CompactAccountIndex_t index;
        pd_Bytes_t raw;
        const uint8_t* _ptr;
    };
} pd_AccountIdLookupOfT_t;

typedef struct {
    pd_BalanceOf_t aye;
    pd_BalanceOf_t nay;
} pd_AccountVoteSplit_t;

typedef struct {
    pd_Vote_t vote;
    pd_BalanceOf_t balance;
} pd_AccountVoteStandard_t;

typedef struct {
    pd_CallIndex_t callIndex;
    const uint32_t* _txVerPtr;
    pd_NestCallIdx_t nestCallIdx;
} pd_Call_t;

typedef struct {
    compactInt_t value;
} pd_CompactPerBill_t;

typedef struct {
    uint8_t value;
    union {
        pd_Ed25519Signature_t ed25519;
        pd_Sr25519Signature_t sr25519;
        pd_EcdsaSignature_t ecdsa;
    };
} pd_MultiSignature_t;

typedef struct {
    uint8_t value;
    union {
        pd_Ed25519Public_t ed25519;
        pd_Sr25519Public_t sr25519;
        pd_EcdsaPublic_t ecdsa;
    };
} pd_MultiSigner_t;

typedef struct {
    uint8_t some;
    pd_u8_array_20_t contained;
} pd_Optionu8_array_20_t;

typedef struct {
    uint32_t value;
} pd_Perbill_t;

typedef struct {
    uint8_t value;
} pd_Percent_t;

typedef struct {
    uint8_t value;
} pd_ProxyType_t;

typedef struct {
    uint32_t value;
} pd_ReferendumIndex_t;

typedef struct {
    pd_BlockNumber_t height;
    uint32_t index;
} pd_Timepoint_t;

typedef struct {
    pd_AccountId_t id;
    pd_Data_t data;
} pd_TupleAccountIdData_t;

typedef struct {
    pd_H256_t h256;
    uint32_t u32;
} pd_TupleH256u32_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecMultiAssetV0_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecMultiAssetV1_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecTupleDataData_t;

typedef struct {
    uint8_t value;
    union {
        pd_AccountVoteStandard_t voteStandard;
        pd_AccountVoteSplit_t voteSplit;
    };
} pd_AccountVote_t;

typedef struct {
    uint8_t value;
    pd_Balance_t freeBalance;
} pd_BondExtraBalanceOfT_t;

typedef struct {
    uint8_t value;
    union {
        pd_H256_t legacy;
        pd_Bytes_t _inline;
        pd_TupleH256u32_t lookup;
    };
} pd_BoundedCallOfT_t;

typedef struct {
    uint8_t value;
    union {
        pd_VecMultiAssetV0_t vecMultiassetV0;
        pd_VecMultiAssetV1_t vecMultiassetV1;
    };
} pd_BoxVersionedMultiAssets_t;

typedef struct {
    uint8_t value;
    union {
        pd_MultiLocationV0_t multilocationV0;
        pd_MultiLocationV1_t multilocationV1;
    };
} pd_BoxVersionedMultiLocation_t;

typedef struct {
    uint8_t value;
    pd_AccountId_t set;
} pd_ConfigOpAccountId_t;

typedef struct {
    uint8_t value;
    pd_Balance_t set;
} pd_ConfigOpBalanceOfT_t;

typedef struct {
    uint8_t value;
    pd_Perbill_t set;
} pd_ConfigOpPerbill_t;

typedef struct {
    uint8_t value;
    pd_Percent_t set;
} pd_ConfigOpPercent_t;

typedef struct {
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
    uint8_t value;
    pd_Balance_t feePaid;
} pd_JudgementBalanceOfT_t;

typedef struct {
    uint8_t some;
    pd_MultiSignature_t contained;
} pd_OptionMultiSignature_t;

typedef struct {
    uint8_t some;
    pd_MultiSigner_t verifier;
} pd_OptionMultiSigner_t;

typedef struct {
    uint8_t some;
    pd_Timepoint_t contained;
} pd_OptionTimepoint_t;

typedef struct {
    pd_Call_t call;
} pd_Proposal_t;

typedef struct {
    uint8_t value;
    pd_AccountId_t accountId;
} pd_RewardDestination_t;

typedef struct {
    pd_CompactPerBill_t commission;
    pd_bool_t blocked;
} pd_ValidatorPrefs_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecAccountIdLookupOfT_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
    uint32_t callTxVersion;
} pd_VecCall_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecTupleAccountIdData_t;

typedef struct {
    pd_BalanceOf_t locked;
    pd_BalanceOf_t per_block;
    pd_BlockNumber_t starting_block;
} pd_VestingInfo_t;

typedef struct {
    uint8_t value;
    pd_Compactu64_t limited;
} pd_WeightLimit_t;

typedef struct {
    pd_Compactu64_t refTime;
    pd_Compactu64_t proofSize;
} pd_Weight_t;

typedef struct {
    uint32_t value;
} pd_AccountIndex_t;

typedef struct {
    uint8_t value;
    uint32_t set;
} pd_ConfigOpu32_t;

typedef struct {
    uint8_t value;
} pd_Conviction_t;

typedef struct {
    uint32_t value;
} pd_EraIndex_t;

typedef struct {
    const uint8_t* _ptr;
} pd_EthereumAddress_t;

typedef struct {
    const uint8_t* _ptr;
} pd_Hash_t;

typedef struct {
    const uint8_t* _ptr;
} pd_Keys_t;

typedef struct {
    uint32_t value;
} pd_MemberCount_t;

typedef struct {
    uint8_t some;
    pd_AccountId_t contained;
} pd_OptionAccountId_t;

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
    pd_u32_t contained;
} pd_Optionu32_t;

typedef struct {
    uint64_t value;
} pd_OverweightIndex_t;

typedef struct {
    uint32_t value;
} pd_ParaId_t;

typedef struct {
    uint32_t value;
} pd_PoolId_t;

typedef struct {
    uint8_t value;
} pd_PoolState_t;

typedef struct {
    uint32_t value;
} pd_RegistrarIndex_t;

typedef struct {
    uint32_t value;
} pd_SessionIndex_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecAccountId_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_Vecu32_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_Vecu8_t;

#ifdef __cplusplus
}
#endif
