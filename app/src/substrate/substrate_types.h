/*******************************************************************************
 *  (c) 2019 - 2024 Zondax AG
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

#ifdef __cplusplus
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wextern-c-compat"
#pragma clang diagnostic pop
#endif

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
    const uint8_t* _ptr;
} pd_u8_array_32_t;

typedef struct {
    uint64_t blockNumber;
    pd_u8_array_32_t blockHash;
} pd_ByFork_t;

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
        pd_u8_array_32_t byGenesis;
        pd_ByFork_t byFork;
        pd_Compactu64_t chainId;
    };
} pd_NetworkIdV3_t;

typedef struct {
    uint8_t value;
    union {
        pd_Bytes_t named;
        pd_Compactu32_t index;
    };
} pd_BodyIdV2_t;

typedef struct {
    uint8_t value;
    union {
        const uint8_t* _ptr;
        pd_Compactu32_t index;
    };
} pd_BodyIdV3_t;

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
} pd_NetworkIdV2_t;

typedef struct {
    uint8_t some;
    pd_NetworkIdV3_t contained;
} pd_OptionNetworkIdV3_t;

typedef struct {
    const uint8_t* _ptr;
} pd_u8_array_20_t;

typedef struct {
    pd_NetworkIdV2_t networkId;
    pd_u8_array_32_t key;
} pd_AccountId32V2_t;

typedef struct {
    pd_OptionNetworkIdV3_t networkId;
    pd_u8_array_32_t key;
} pd_AccountId32V3_t;

typedef struct {
    pd_NetworkIdV2_t networkId;
    pd_Compactu64_t index;
} pd_AccountIndex64V2_t;

typedef struct {
    pd_OptionNetworkIdV3_t networkId;
    pd_Compactu64_t index;
} pd_AccountIndex64V3_t;

typedef struct {
    pd_NetworkIdV2_t networkId;
    pd_u8_array_20_t key;
} pd_AccountKey20V2_t;

typedef struct {
    pd_OptionNetworkIdV3_t networkId;
    pd_u8_array_20_t key;
} pd_AccountKey20V3_t;

typedef compactInt_t pd_Compactu128_t;

typedef struct {
    uint8_t length;
    pd_u8_array_32_t data;
} pd_GeneralKeyV3_t;

typedef struct {
    pd_BodyIdV2_t id;
    pd_BodyPart_t part;
} pd_PluralityV2_t;

typedef struct {
    pd_BodyIdV3_t id;
    pd_BodyPart_t part;
} pd_PluralityV3_t;

typedef struct {
    uint8_t value;
    union {
        pd_Compactu32_t parachain;
        pd_AccountId32V2_t accountId32;
        pd_AccountIndex64V2_t accountIndex64;
        pd_AccountKey20V2_t accountKey20;
        uint8_t palletInstance;
        pd_Compactu128_t generalIndex;
        pd_Bytes_t generalKey;
        pd_PluralityV2_t plurality;
    };
} pd_JunctionV2_t;

typedef struct {
    uint8_t value;
    union {
        pd_Compactu32_t parachain;
        pd_AccountId32V3_t accountId32;
        pd_AccountIndex64V3_t accountIndex64;
        pd_AccountKey20V3_t accountKey20;
        uint8_t palletInstance;
        pd_Compactu128_t generalIndex;
        pd_GeneralKeyV3_t generalKey;
        pd_PluralityV3_t plurality;
        pd_NetworkIdV3_t globalConsensus;
    };
} pd_JunctionV3_t;

typedef struct {
    pd_JunctionV2_t junction;
} pd_JunctionV2X1_t;

typedef struct {
    pd_JunctionV2_t junction0;
    pd_JunctionV2_t junction1;
} pd_JunctionV2X2_t;

typedef struct {
    pd_JunctionV2_t junction0;
    pd_JunctionV2_t junction1;
    pd_JunctionV2_t junction2;
} pd_JunctionV2X3_t;

typedef struct {
    pd_JunctionV2_t junction0;
    pd_JunctionV2_t junction1;
    pd_JunctionV2_t junction2;
    pd_JunctionV2_t junction3;
} pd_JunctionV2X4_t;

typedef struct {
    pd_JunctionV2_t junction0;
    pd_JunctionV2_t junction1;
    pd_JunctionV2_t junction2;
    pd_JunctionV2_t junction3;
    pd_JunctionV2_t junction4;
} pd_JunctionV2X5_t;

typedef struct {
    pd_JunctionV2_t junction0;
    pd_JunctionV2_t junction1;
    pd_JunctionV2_t junction2;
    pd_JunctionV2_t junction3;
    pd_JunctionV2_t junction4;
    pd_JunctionV2_t junction5;
} pd_JunctionV2X6_t;

typedef struct {
    pd_JunctionV2_t junction0;
    pd_JunctionV2_t junction1;
    pd_JunctionV2_t junction2;
    pd_JunctionV2_t junction3;
    pd_JunctionV2_t junction4;
    pd_JunctionV2_t junction5;
    pd_JunctionV2_t junction6;
} pd_JunctionV2X7_t;

typedef struct {
    pd_JunctionV2_t junction0;
    pd_JunctionV2_t junction1;
    pd_JunctionV2_t junction2;
    pd_JunctionV2_t junction3;
    pd_JunctionV2_t junction4;
    pd_JunctionV2_t junction5;
    pd_JunctionV2_t junction6;
    pd_JunctionV2_t junction7;
} pd_JunctionV2X8_t;

typedef struct {
    pd_JunctionV3_t junction;
} pd_JunctionV3X1_t;

typedef struct {
    pd_JunctionV3_t junction0;
    pd_JunctionV3_t junction1;
} pd_JunctionV3X2_t;

typedef struct {
    pd_JunctionV3_t junction0;
    pd_JunctionV3_t junction1;
    pd_JunctionV3_t junction2;
} pd_JunctionV3X3_t;

typedef struct {
    pd_JunctionV3_t junction0;
    pd_JunctionV3_t junction1;
    pd_JunctionV3_t junction2;
    pd_JunctionV3_t junction3;
} pd_JunctionV3X4_t;

typedef struct {
    pd_JunctionV3_t junction0;
    pd_JunctionV3_t junction1;
    pd_JunctionV3_t junction2;
    pd_JunctionV3_t junction3;
    pd_JunctionV3_t junction4;
} pd_JunctionV3X5_t;

typedef struct {
    pd_JunctionV3_t junction0;
    pd_JunctionV3_t junction1;
    pd_JunctionV3_t junction2;
    pd_JunctionV3_t junction3;
    pd_JunctionV3_t junction4;
    pd_JunctionV3_t junction5;
} pd_JunctionV3X6_t;

typedef struct {
    pd_JunctionV3_t junction0;
    pd_JunctionV3_t junction1;
    pd_JunctionV3_t junction2;
    pd_JunctionV3_t junction3;
    pd_JunctionV3_t junction4;
    pd_JunctionV3_t junction5;
    pd_JunctionV3_t junction6;
} pd_JunctionV3X7_t;

typedef struct {
    pd_JunctionV3_t junction0;
    pd_JunctionV3_t junction1;
    pd_JunctionV3_t junction2;
    pd_JunctionV3_t junction3;
    pd_JunctionV3_t junction4;
    pd_JunctionV3_t junction5;
    pd_JunctionV3_t junction6;
    pd_JunctionV3_t junction7;
} pd_JunctionV3X8_t;

typedef struct {
    uint8_t value;
    union {
        pd_JunctionV2X1_t x1;
        pd_JunctionV2X2_t x2;
        pd_JunctionV2X3_t x3;
        pd_JunctionV2X4_t x4;
        pd_JunctionV2X5_t x5;
        pd_JunctionV2X6_t x6;
        pd_JunctionV2X7_t x7;
        pd_JunctionV2X8_t x8;
    };
} pd_JunctionsV2_t;

typedef struct {
    uint8_t value;
    union {
        pd_JunctionV3X1_t x1;
        pd_JunctionV3X2_t x2;
        pd_JunctionV3X3_t x3;
        pd_JunctionV3X4_t x4;
        pd_JunctionV3X5_t x5;
        pd_JunctionV3X6_t x6;
        pd_JunctionV3X7_t x7;
        pd_JunctionV3X8_t x8;
    };
} pd_JunctionsV3_t;

typedef struct {
    uint8_t value;
    union {
        const uint8_t* _ptr;
        pd_Compactu128_t index;
        pd_Bytes_t blob;
    };
} pd_AssetInstanceV2_t;

typedef struct {
    uint8_t value;
    union {
        const uint8_t* _ptr;
        pd_Compactu128_t index;
    };
} pd_AssetInstanceV3_t;

typedef struct {
    uint8_t parents;
    pd_JunctionsV2_t interior;
} pd_MultiLocationV2_t;

typedef struct {
    uint8_t parents;
    pd_JunctionsV3_t interior;
} pd_MultiLocationV3_t;

typedef struct {
    const uint8_t* _ptr;
} pd_Balance_t;

typedef struct {
    uint8_t value;
    const uint8_t* _ptr;
} pd_Data_t;

typedef struct {
    uint8_t value;
    union {
        pd_Compactu128_t fungible;
        pd_AssetInstanceV2_t nonFungible;
    };
} pd_FungibilityV2_t;

typedef struct {
    uint8_t value;
    union {
        pd_Compactu128_t fungible;
        pd_AssetInstanceV3_t nonFungible;
    };
} pd_FungibilityV3_t;

typedef struct {
    uint8_t value;
    union {
        pd_MultiLocationV2_t concrete;
        pd_Bytes_t abstract;
    };
} pd_MultiAssetIdV2_t;

typedef struct {
    uint8_t value;
    union {
        pd_MultiLocationV3_t concrete;
        pd_u8_array_32_t abstract;
    };
} pd_MultiAssetIdV3_t;

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
    pd_MultiAssetIdV2_t assetId;
    pd_FungibilityV2_t fungibility;
} pd_MultiAssetV2_t;

typedef struct {
    pd_MultiAssetIdV3_t assetId;
    pd_FungibilityV3_t fungibility;
} pd_MultiAssetV3_t;

typedef struct {
    uint32_t value;
} pd_ParaId_t;

typedef struct {
    uint32_t value;
} pd_Perbill_t;

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
    pd_BalanceOf_t abstain;
} pd_AccountVoteSplitAbstain_t;

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
    uint16_t value;
} pd_ClassOf_t;

typedef struct {
    compactInt_t value;
} pd_CompactPerBill_t;

typedef struct {
    const uint8_t* _ptr;
} pd_Hash_t;

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
    uint8_t value;
    pd_ParaId_t parachain;
} pd_ParachainsOrigin_t;

typedef struct {
    uint8_t value;
} pd_Percent_t;

typedef struct {
    uint8_t value;
} pd_PolkadotOrigins_t;

typedef struct {
    uint8_t value;
} pd_ProxyType_t;

typedef struct {
    uint8_t value;
    pd_AccountId_t _signed;
} pd_SystemOrigin_t;

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
    pd_Perbill_t perbill;
    pd_AccountId_t id;
} pd_TuplePerbillAccountId_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecMultiAssetV2_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecMultiAssetV3_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecTupleDataData_t;

typedef struct {
    pd_Compactu64_t refTime;
    pd_Compactu64_t proofSize;
} pd_Weight_t;

typedef struct {
    uint8_t value;
    union {
        pd_AccountVoteStandard_t voteStandard;
        pd_AccountVoteSplit_t voteSplit;
        pd_AccountVoteSplitAbstain_t voteSplitAbstain;
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
        pd_Bytes_t bytes_inline;
        pd_TupleH256u32_t lookup;
    };
} pd_BoundedCallOfT_t;

typedef struct {
    uint8_t value;
    union {
        pd_SystemOrigin_t system;
        pd_PolkadotOrigins_t origins;
        pd_ParachainsOrigin_t parachainsOrigin;
    };
} pd_BoxPalletsOrigin_t;

typedef struct {
    uint8_t value;
    union {
        pd_VecMultiAssetV2_t vecMultiassetV2;
        pd_VecMultiAssetV3_t vecMultiassetV3;
    };
} pd_BoxVersionedMultiAssets_t;

typedef struct {
    uint8_t value;
    union {
        pd_MultiLocationV2_t multilocationV2;
        pd_MultiLocationV3_t multilocationV3;
    };
} pd_BoxVersionedMultiLocation_t;

typedef struct {
    pd_Perbill_t maxIncrease;
    uint32_t minDelay;
} pd_CommissionChangeRateBlockNumber_t;

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
    uint8_t some;
    pd_TuplePerbillAccountId_t contained;
} pd_OptionTuplePerbillAccountId_t;

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
    pd_Weight_t limited;
} pd_WeightLimit_t;

typedef struct {
    uint32_t value;
} pd_AccountIndex_t;

typedef struct {
    uint8_t value;
} pd_ClaimPermission_t;

typedef struct {
    uint8_t value;
    uint32_t set;
} pd_ConfigOpu32_t;

typedef struct {
    uint8_t value;
} pd_Conviction_t;

typedef struct {
    uint8_t value;
    uint32_t block;
} pd_DispatchTimeBlockNumber_t;

typedef struct {
    uint32_t value;
} pd_EraIndex_t;

typedef struct {
    const uint8_t* _ptr;
} pd_EthereumAddress_t;

typedef struct {
    const uint8_t* _ptr;
} pd_Keys_t;

typedef struct {
    uint8_t some;
    pd_AccountId_t contained;
} pd_OptionAccountId_t;

typedef struct {
    uint8_t some;
    pd_ClassOf_t contained;
} pd_OptionClassOf_t;

typedef struct {
    uint8_t some;
    pd_Hash_t contained;
} pd_OptionHash_t;

typedef struct {
    uint8_t some;
    pd_ProxyType_t contained;
} pd_OptionProxyType_t;

typedef struct {
    uint8_t some;
    pd_u16_t contained;
} pd_Optionu16_t;

typedef struct {
    uint8_t some;
    pd_u32_t contained;
} pd_Optionu32_t;

typedef struct {
    uint32_t value;
} pd_PollIndexOf_t;

typedef struct {
    uint32_t value;
} pd_PoolId_t;

typedef struct {
    uint8_t value;
} pd_PoolState_t;

typedef struct {
    uint32_t value;
} pd_ReferendumIndex_t;

typedef struct {
    uint32_t value;
} pd_RegistrarIndex_t;

typedef struct {
    uint32_t value;
} pd_SessionIndex_t;

typedef struct {
    uint32_t value;
} pd_SpendIndex_t;

typedef struct {
    uint16_t value;
} pd_TrackIdOf_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecAccountId_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecHash_t;

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
////////////////////////////////////////
// Custom
////////////////////////////////////////
typedef struct {
    uint8_t value;
    union {
        pd_MultiLocationV3_t xcm;
        pd_MultiLocationV3_t response;
    };
} pd_XcmOrigin_t;

typedef struct {
    uint8_t value;
    union {
        pd_SystemOrigin_t system;
        pd_PolkadotOrigins_t origins;
        pd_XcmOrigin_t xcmPallet;
        pd_ParachainsOrigin_t parachainsOrigin;
    };
} pd_BoxPalletsProposalOrigin_t;

typedef struct {
    uint8_t some;
    pd_AccountIdLookupOfT_t contained;
} pd_OptionAccountIdLookupOfT_t;

typedef struct {
    uint8_t some;
    pd_Bytes_t contained;
} pd_OptionBytes_t;

typedef struct {
    const uint8_t* _ptr;
} pd_u128_t;

typedef struct {
    uint8_t some;
    pd_u64_t contained;
} pd_Optionu64_t;

typedef struct {
    uint8_t some;
    pd_u128_t contained;
} pd_Optionu128_t;

typedef struct {
    compactInt_t value;
} pd_CompactPerbill_t;

typedef struct {
    uint8_t some;
    pd_bool_t contained;
} pd_Optionbool_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_Vecu128_t;

typedef struct {
    uint8_t value;
    pd_u128_t senj;
} pd_VoteCurrency_t;

typedef struct {
    pd_u128_t value;
} pd_OfferId_t;

typedef struct {
    pd_AccountId_t account;
    pd_u128_t total;
    pd_u128_t rate;
    pd_Perbill_t min_average_commission;
} pd_OfferOfT_t;

typedef struct {
    pd_u128_t value;
} pd_CollectionId_t;

typedef struct {
    pd_Compactu128_t value;
} pd_CompactCollectionId_t;

typedef struct {
    pd_bool_t isFrozen;
} pd_TransferPolicy_t;

typedef struct {
    pd_Optionu64_t maxTokenCount;
    pd_Optionu128_t maxTokenSupply;
    pd_bool_t forceSingleMint;
} pd_MintPolicyDescriptor_t;

typedef struct {
    pd_AccountId_t beneficiary;
    pd_CompactPerbill_t percentage;
} pd_MarketPolicyRoyalty_t;

typedef struct {
    uint8_t some;
    pd_MarketPolicyRoyalty_t contained;
} pd_OptionMarketPolicyRoyalty_t;

typedef struct {
    pd_MintPolicyDescriptor_t mint;
    pd_TransferPolicy_t transfer;
    pd_OptionMarketPolicyRoyalty_t market;
} pd_CollectionPolicy_t;

typedef struct {
    pd_AccountId_t owner;
    pd_CollectionPolicy_t policy;
    pd_Compactu64_t tokenCount;
    pd_Compactu32_t attributeCount;
    pd_Compactu128_t totalDeposit;
    pd_OptionBytes_t explicitRoyaltyCurrencies;
} pd_CollectionOf_t;

typedef struct {
    uint8_t some;
    pd_CollectionOf_t contained;
} pd_OptionCollectionOf_t;

typedef struct {
    uint8_t value;
    pd_Vecu128_t set;
} pd_LiquidityAccountConfigOfT_t;

typedef struct {
    pd_Compactu128_t value;
} pd_CompactTokenId_t;

typedef struct {
    pd_u128_t value;
} pd_TokenId_t;

typedef struct {
    pd_TokenId_t value;
} pd_TokenIdOf_t;

typedef struct {
    uint8_t some;
    pd_TokenId_t contained;
} pd_OptionTokenId_t;

typedef struct {
    pd_CompactTokenId_t tokenId;
    pd_Compactu128_t amount;
    pd_bool_t keepAlive;
    pd_bool_t removeTokenStorage;
} pd_BurnParamsOfT_t;

typedef struct {
    pd_CompactTokenId_t tokenId;
    pd_Compactu128_t amount;
    pd_bool_t keepAlive;
} pd_SimpleTransferParams_t;

typedef struct {
    pd_CompactTokenId_t tokenId;
    pd_AccountId_t source;
    pd_Compactu128_t amount;
    pd_bool_t keepAlive;
} pd_OperatorTransferParams_t;

typedef struct {
    uint8_t value;
    union {
        pd_SimpleTransferParams_t simple;
        pd_OperatorTransferParams_t operator_;
    };
} pd_TransferParamsOfT_t;

typedef struct {
    pd_AccountId_t accountId;
    pd_TransferParamsOfT_t params;
} pd_TransferRecipientsOf_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecTransferRecipientsOf_t;

typedef struct {
    uint8_t value;
} pd_FreezeState_t;

typedef struct {
    uint8_t some;
    pd_FreezeState_t contained;
} pd_OptionFreezeState_t;

typedef struct {
    pd_TokenId_t tokenId;
    pd_OptionFreezeState_t freezeState;
} pd_TokenFreezeType_t;

typedef struct {
    pd_CompactTokenId_t tokenId;
    pd_AccountId_t accountId;
} pd_TokenAccountFreezeType_t;

typedef struct {
    uint8_t value;
    union {
        pd_TokenFreezeType_t token;
        pd_AccountId_t collectionAccount;
        pd_TokenAccountFreezeType_t tokenAccount;
    };
} pd_FreezeType_t;

typedef struct {
    pd_Compactu128_t collectionId;
    pd_FreezeType_t freezeType;
} pd_FreezeOf_t;

typedef struct {
    pd_CompactTokenId_t tokenId;
    pd_Compactu128_t amount;
    pd_Optionu128_t unitPrice;
} pd_MintTokenMintParam_t;

typedef struct {
    pd_Optionu128_t unitPrice;
} pd_InsufficientPolicyMintSufficiencyParam_t;

typedef struct {
    pd_u128_t minimumBalance;
} pd_SufficientPolicyMintSufficiencyParam_t;

typedef struct {
    uint8_t value;
    union {
        pd_InsufficientPolicyMintSufficiencyParam_t insufficient;
        pd_SufficientPolicyMintSufficiencyParam_t sufficient;
    };
} pd_PolicyMintSufficiencyParam_t;

typedef struct {
    uint8_t value;
    union {
        pd_Compactu128_t supply;
        pd_Compactu128_t collapsingSupply;
    };
} pd_TokenTokenCap_t;

typedef struct {
    uint8_t some;
    pd_TokenTokenCap_t contained;
} pd_OptionTokenTokenCap_t;

typedef struct {
    pd_AccountId_t beneficiary;
    pd_CompactPerbill_t percentage;
} pd_HasRoyaltyTokenTokenMarketBehavior;

typedef struct {
    uint8_t value;
    pd_HasRoyaltyTokenTokenMarketBehavior hasRoyalty;
} pd_TokenTokenMarketBehavior_t;

typedef struct {
    uint8_t some;
    pd_TokenTokenMarketBehavior_t contained;
} pd_OptionTokenTokenMarketBehavior_t;

typedef struct {
    pd_Bytes_t key;
    pd_Bytes_t value;
} pd_AttributeKeyValuePair_t;

typedef struct {
    pd_Bytes_t value;
    pd_Compactu128_t deposit;
} pd_AttributeOf_t;

typedef struct {
    uint8_t some;
    pd_AttributeOf_t contained;
} pd_OptionAttributeOf_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecAttributeKeyValuePair_t;

typedef struct {
    uint8_t some;
    pd_MultiLocationV3_t contained;
} pd_OptionXcmV3MultiLocation;

typedef struct {
    pd_Compactu32_t decimalCount;
    pd_Bytes_t name;
    pd_Bytes_t symbol;
    pd_OptionXcmV3MultiLocation location;
    pd_Optionu128_t unitsPerSecond;

} pd_PolicyMintForeignTokenCreationParams_t;

typedef struct {
    uint8_t some;
    pd_PolicyMintForeignTokenCreationParams_t contained;
} pd_OptionPolicyMintForeignTokenCreationParams_t;

typedef struct {
    pd_OptionMarketPolicyRoyalty_t royalty;
} pd_MarketPolicyDescriptor_t;

typedef struct {
    pd_MintPolicyDescriptor_t mint;
    pd_MarketPolicyDescriptor_t market;
} pd_CollectionPolicyDescriptor_t;

typedef struct {
    pd_Compactu128_t collectionId;
    pd_CompactTokenId_t tokenId;
} pd_TokenAssetId_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecTokenAssetId_t;

typedef struct {
    pd_CollectionPolicyDescriptor_t policy;
    pd_VecTokenAssetId_t explicitRoyaltyCurrencies;
    pd_VecAttributeKeyValuePair_t attributes;
} pd_CollectionDescriptor_t;

typedef struct {
    pd_CompactTokenId_t tokenId;
    pd_Compactu128_t initialSupply;
    pd_PolicyMintSufficiencyParam_t sufficiency;
    pd_OptionTokenTokenCap_t cap;
    pd_OptionTokenTokenMarketBehavior_t behavior;
    pd_bool_t listingForbidden;
    pd_OptionFreezeState_t freezeState;
    pd_VecAttributeKeyValuePair_t attributes;
    pd_OptionPolicyMintForeignTokenCreationParams_t foreignParams;
} pd_CreateTokenMintParam_t;

typedef struct {
    uint8_t value;
    union {
        pd_CreateTokenMintParam_t createToken;
        pd_MintTokenMintParam_t mint;
    };
} pd_MintParamsOf_t;

typedef struct {
    pd_AccountId_t accountId;
    pd_MintParamsOf_t params;
} pd_MintRecipientsOf_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecMintRecipientsOf_t;

typedef struct {
    uint8_t some;
    pd_VecTokenAssetId_t contained;
} pd_OptionVecTokenAssetId_t;

typedef struct {
    uint8_t value;
    pd_OptionMarketPolicyRoyalty_t set;
} pd_RoyaltyMutation_t;

typedef struct {
    pd_OptionAccountId_t owner;
    pd_RoyaltyMutation_t royalty;
    pd_OptionVecTokenAssetId_t explicitRoyaltyCurrencies;
} pd_CollectionMutation_t;

typedef struct {
    uint8_t value;
    pd_OptionTokenTokenMarketBehavior_t set;
} pd_TokenTokenMarketBehaviorMutation_t;

typedef struct {
    uint8_t value;
    pd_bool_t set;
} pd_ShouldMutateBool_t;

typedef struct {
    pd_Compactu32_t decimalCount;
    pd_Bytes_t name;
    pd_Bytes_t symbol;
    pd_OptionXcmV3MultiLocation location;
    pd_Optionu128_t unitsPerSecond;
    pd_Compactu128_t premintedSupply;
} pd_MutateForeignTokenMetadata_t;

typedef struct {
    uint8_t value;
    pd_MutateForeignTokenMetadata_t set;
} pd_TokenMetadata_t;

typedef struct {
    uint8_t value;
    pd_TokenMetadata_t set;
} pd_ShouldMutateTokenMetadata_t;

typedef struct {
    uint8_t value;
    pd_OptionTokenTokenMarketBehavior_t set;
} pd_ShouldMutateTokenMarketBehavior_t;

typedef struct {
    pd_ShouldMutateTokenMarketBehavior_t behavior;
    pd_ShouldMutateBool_t listingForbidden;
    pd_ShouldMutateTokenMetadata_t metadata;
} pd_TokenMutation_t;


typedef struct {
    pd_Compactu128_t unitPrice;
} pd_InsufficientTokenSufficiency_t;

typedef struct {
    uint8_t value;
    pd_InsufficientTokenSufficiency_t set;
} pd_TokenSufficiency_t;

typedef struct {
    pd_Compactu128_t supply;
    pd_OptionTokenTokenCap_t cap;
    pd_OptionFreezeState_t freezeState;
    pd_Compactu128_t minimumBalance;
    pd_TokenSufficiency_t sufficiency;
    pd_Compactu128_t mintDeposit;
    pd_Compactu32_t attributeCount;
    pd_OptionTokenTokenMarketBehavior_t marketBehavior;
    pd_bool_t listingForbidden;
    pd_TokenMetadata_t metadata;
} pd_TokenOf_t;

typedef struct {
    uint8_t some;
    pd_TokenOf_t contained;
} pd_OptionTokenOf_t;

typedef struct {
    pd_bool_t isFrozen;
    pd_OptionBytes_t approvals;
    pd_Compactu32_t accountCount;
} pd_CollectionAccountOf_t;

typedef struct {
    uint8_t some;
    pd_CollectionAccountOf_t contained;
} pd_OptionCollectionAccountOf_t;

typedef struct {
    pd_Compactu128_t balance;
    pd_Compactu128_t reservedBalance;
    pd_Compactu128_t lockedBalance;
    pd_OptionBytes_t namedReserves;
    pd_OptionBytes_t locks;
    pd_OptionBytes_t approvals;
    pd_bool_t isFrozen;
} pd_TokenAccountOf_t;

typedef struct {
    uint8_t some;
    pd_TokenAccountOf_t contained;
} pd_OptionTokenAccountOf_t;

typedef struct {
    uint8_t some;
    pd_Perbill_t contained;
} pd_OptionPerbill_t;

typedef struct {
    uint8_t value;
    pd_OptionPerbill_t set;
} pd_CommissionNewCommission_t;

typedef struct {
    pd_Perbill_t maxDelta;
    pd_u32_t minDelay;
} pd_ChangeRate_t;

typedef struct {
    uint8_t some;
    pd_ChangeRate_t contained;
} pd_OptionCommissionChangeRate_t;

typedef struct {
    uint8_t value;
    pd_OptionAccountId_t set;
} pd_NewAdminMutation_t;

typedef struct {
    uint8_t value;
    pd_OptionAccountId_t set;
} pd_NewNominatorMutation_t;

typedef struct {
    pd_NewAdminMutation_t newAdmin;
    pd_NewNominatorMutation_t newNominator;
} pd_RolesMutation_t;

typedef struct {
    uint8_t some;
    pd_RolesMutation_t contained;
} pd_OptionPoolRolesMutation_t;

typedef struct {
    pd_Optionu32_t duration;
    pd_CommissionNewCommission_t newCommission;
    pd_OptionPerbill_t maxCommission;
    pd_OptionCommissionChangeRate_t changeRate;
    pd_OptionPoolRolesMutation_t roles;
    pd_Optionu128_t capacity;
} pd_PoolMutationOfT_t;

typedef struct {
    uint8_t value;
    pd_CompactBalance_t amount;
} pd_BondValueOfT_t;

typedef struct {
    pd_Perbill_t annual_inflation_rate;
    pd_Perbill_t collator_payout_cut;
} pd_StakingInfo_t;

typedef struct {
    pd_Compactu32_t startBlock;
    pd_Compactu32_t endBlock;
} pd_AuctionDataOfT_t;

typedef struct {
    uint8_t some;
    pd_AuctionDataOfT_t contained;
} pd_OptionAuctionDataOfT_t;

typedef struct {
    pd_H256_t value;
} pd_ListingIdOfT_t;

typedef struct {
    uint8_t value;
} pd_DispatchRuleKind_t;

typedef struct {
    pd_bool_t tankReservesExistentialDeposit;
    pd_bool_t tankReservesAccountCreationDeposit;
} pd_UserAccountManagement_t;

typedef struct {
    uint8_t some;
    pd_UserAccountManagement_t contained;
} pd_OptionUserAccountManagement_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecRulesAccountRuleDescriptor_t;

typedef struct {
    pd_Bytes_t name;
    pd_OptionUserAccountManagement_t userAccountManagement;
    pd_Bytes_t ruleSets;
    pd_bool_t providesDeposit;
    pd_VecRulesAccountRuleDescriptor_t accountRules;
} pd_FuelTankDescriptorOf_t;

typedef struct {
    pd_bool_t useNoneOrigin;
    pd_bool_t paysRemainingFee;
} pd_DispatchSettings_t;

typedef struct {
    uint8_t some;
    pd_DispatchSettings_t contained;
} pd_OptionDispatchSettings_t;

typedef struct {
    pd_Compactu128_t totalConsumed;
    pd_Optionu32_t lastResetBlock;
} pd_ConsumptionOf_t;

typedef struct {
    uint8_t value;
    pd_OptionUserAccountManagement_t set;
} pd_ShouldMutateOption_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecAccountRuleDescriptor_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecDispatchRuleDescriptor_t;

typedef struct {
    uint8_t some;
    pd_VecAccountRuleDescriptor_t contained;
} pd_OptionVecAccountRuleDescriptor_t;

typedef struct {
    pd_ShouldMutateOption_t userAccountManagement;
    pd_Optionbool_t providesDeposit;
    pd_OptionVecAccountRuleDescriptor_t accountRules;
} pd_FuelTankMutationOf_t;

#ifdef __cplusplus
}
#endif
