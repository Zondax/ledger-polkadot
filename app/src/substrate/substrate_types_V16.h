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

#include "substrate_types.h"
#include <stddef.h>
#include <stdint.h>

// Based
// https://github.com/paritytech/substrate/blob/master/node/primitives/src/lib.rs

typedef struct {
    pd_Compactu32_t nom;
    pd_Compactu32_t denom;
} pd_Fraction_V16_t;

typedef struct {
    uint8_t value;
    union {
        pd_Bytes_t named;
        pd_Compactu32_t index;
    };
} pd_BodyId_V16_t;

typedef struct {
    uint8_t value;
    union {
        pd_Compactu32_t count;
        pd_Fraction_V16_t fraction;
    };
} pd_BodyPart_V16_t;

typedef struct {
    uint8_t value;
    pd_Bytes_t named;
} pd_NetworkId_V16_t;

typedef struct {
    const uint8_t* _ptr;
} pd_u8_array_32_V16_t;

typedef struct {
    pd_NetworkId_V16_t networkId;
    pd_u8_array_32_V16_t key;
} pd_AccountId32_V16_t;

typedef struct {
    pd_NetworkId_V16_t networkId;
    pd_Compactu64_t index;
} pd_AccountIndex64_V16_t;

typedef struct {
    pd_NetworkId_V16_t networkId;
    pd_u8_array_20_t key;
} pd_AccountKey20_V16_t;

typedef struct {
    pd_BodyId_V16_t id;
    pd_BodyPart_V16_t part;
} pd_Plurality_V16_t;

typedef struct {
    uint8_t value;
    union {
        pd_Compactu32_t parachain;
        pd_AccountId32_V16_t accountId32;
        pd_AccountIndex64_V16_t accountIndex64;
        pd_AccountKey20_V16_t accountKey20;
        uint8_t palletInstance;
        pd_Compactu128_t generalIndex;
        pd_Bytes_t generalKey;
        pd_Plurality_V16_t plurality;
    };
} pd_JunctionV0_V16_t;

typedef struct {
    uint8_t value;
    union {
        pd_Compactu32_t parachain;
        pd_AccountId32_V16_t accountId32;
        pd_AccountIndex64_V16_t accountIndex64;
        pd_AccountKey20_V16_t accountKey20;
        uint8_t palletInstance;
        pd_Compactu128_t generalIndex;
        pd_Bytes_t generalKey;
        pd_Plurality_V16_t plurality;
    };
} pd_JunctionV1_V16_t;

typedef struct {
    pd_JunctionV0_V16_t junction;
} pd_JunctionV0X1_V16_t;

typedef struct {
    pd_JunctionV0_V16_t junction0;
    pd_JunctionV0_V16_t junction1;
} pd_JunctionV0X2_V16_t;

typedef struct {
    pd_JunctionV0_V16_t junction0;
    pd_JunctionV0_V16_t junction1;
    pd_JunctionV0_V16_t junction2;
} pd_JunctionV0X3_V16_t;

typedef struct {
    pd_JunctionV0_V16_t junction0;
    pd_JunctionV0_V16_t junction1;
    pd_JunctionV0_V16_t junction2;
    pd_JunctionV0_V16_t junction3;
} pd_JunctionV0X4_V16_t;

typedef struct {
    pd_JunctionV0_V16_t junction0;
    pd_JunctionV0_V16_t junction1;
    pd_JunctionV0_V16_t junction2;
    pd_JunctionV0_V16_t junction3;
    pd_JunctionV0_V16_t junction4;
} pd_JunctionV0X5_V16_t;

typedef struct {
    pd_JunctionV0_V16_t junction0;
    pd_JunctionV0_V16_t junction1;
    pd_JunctionV0_V16_t junction2;
    pd_JunctionV0_V16_t junction3;
    pd_JunctionV0_V16_t junction4;
    pd_JunctionV0_V16_t junction5;
} pd_JunctionV0X6_V16_t;

typedef struct {
    pd_JunctionV0_V16_t junction0;
    pd_JunctionV0_V16_t junction1;
    pd_JunctionV0_V16_t junction2;
    pd_JunctionV0_V16_t junction3;
    pd_JunctionV0_V16_t junction4;
    pd_JunctionV0_V16_t junction5;
    pd_JunctionV0_V16_t junction6;
} pd_JunctionV0X7_V16_t;

typedef struct {
    pd_JunctionV0_V16_t junction0;
    pd_JunctionV0_V16_t junction1;
    pd_JunctionV0_V16_t junction2;
    pd_JunctionV0_V16_t junction3;
    pd_JunctionV0_V16_t junction4;
    pd_JunctionV0_V16_t junction5;
    pd_JunctionV0_V16_t junction6;
    pd_JunctionV0_V16_t junction7;
} pd_JunctionV0X8_V16_t;

typedef struct {
    pd_JunctionV1_V16_t junction;
} pd_JunctionV1X1_V16_t;

typedef struct {
    pd_JunctionV1_V16_t junction0;
    pd_JunctionV1_V16_t junction1;
} pd_JunctionV1X2_V16_t;

typedef struct {
    pd_JunctionV1_V16_t junction0;
    pd_JunctionV1_V16_t junction1;
    pd_JunctionV1_V16_t junction2;
} pd_JunctionV1X3_V16_t;

typedef struct {
    pd_JunctionV1_V16_t junction0;
    pd_JunctionV1_V16_t junction1;
    pd_JunctionV1_V16_t junction2;
    pd_JunctionV1_V16_t junction3;
} pd_JunctionV1X4_V16_t;

typedef struct {
    pd_JunctionV1_V16_t junction0;
    pd_JunctionV1_V16_t junction1;
    pd_JunctionV1_V16_t junction2;
    pd_JunctionV1_V16_t junction3;
    pd_JunctionV1_V16_t junction4;
} pd_JunctionV1X5_V16_t;

typedef struct {
    pd_JunctionV1_V16_t junction0;
    pd_JunctionV1_V16_t junction1;
    pd_JunctionV1_V16_t junction2;
    pd_JunctionV1_V16_t junction3;
    pd_JunctionV1_V16_t junction4;
    pd_JunctionV1_V16_t junction5;
} pd_JunctionV1X6_V16_t;

typedef struct {
    pd_JunctionV1_V16_t junction0;
    pd_JunctionV1_V16_t junction1;
    pd_JunctionV1_V16_t junction2;
    pd_JunctionV1_V16_t junction3;
    pd_JunctionV1_V16_t junction4;
    pd_JunctionV1_V16_t junction5;
    pd_JunctionV1_V16_t junction6;
} pd_JunctionV1X7_V16_t;

typedef struct {
    pd_JunctionV1_V16_t junction0;
    pd_JunctionV1_V16_t junction1;
    pd_JunctionV1_V16_t junction2;
    pd_JunctionV1_V16_t junction3;
    pd_JunctionV1_V16_t junction4;
    pd_JunctionV1_V16_t junction5;
    pd_JunctionV1_V16_t junction6;
    pd_JunctionV1_V16_t junction7;
} pd_JunctionV1X8_V16_t;

typedef struct {
    uint8_t value;
    union {
        pd_JunctionV0X1_V16_t x1;
        pd_JunctionV0X2_V16_t x2;
        pd_JunctionV0X3_V16_t x3;
        pd_JunctionV0X4_V16_t x4;
        pd_JunctionV0X5_V16_t x5;
        pd_JunctionV0X6_V16_t x6;
        pd_JunctionV0X7_V16_t x7;
        pd_JunctionV0X8_V16_t x8;
    };
} pd_JunctionsV0_V16_t;

typedef struct {
    uint8_t value;
    union {
        pd_JunctionV1X1_V16_t x1;
        pd_JunctionV1X2_V16_t x2;
        pd_JunctionV1X3_V16_t x3;
        pd_JunctionV1X4_V16_t x4;
        pd_JunctionV1X5_V16_t x5;
        pd_JunctionV1X6_V16_t x6;
        pd_JunctionV1X7_V16_t x7;
        pd_JunctionV1X8_V16_t x8;
    };
} pd_JunctionsV1_V16_t;

typedef struct {
    uint8_t value;
    union {
        const uint8_t* _ptr;
        pd_Compactu128_t index;
        pd_Bytes_t blob;
    };
} pd_AssetInstance_V16_t;

typedef struct {
    pd_JunctionsV0_V16_t junctions;
} pd_MultiLocationV0_V16_t;

typedef struct {
    uint8_t parents;
    pd_JunctionsV1_V16_t interior;
} pd_MultiLocationV1_V16_t;

typedef struct {
    pd_Bytes_t id;
    pd_Compactu128_t amount;
} pd_AbstractFungible_V16_t;

typedef struct {
    pd_Bytes_t _class;
    pd_AssetInstance_V16_t instance;
} pd_AbstractNonFungible_V16_t;

typedef struct {
    pd_MultiLocationV0_V16_t id;
    pd_CompactBalance_t amount;
} pd_ConcreteFungible_V16_t;

typedef struct {
    pd_MultiLocationV0_V16_t _class;
    pd_AssetInstance_V16_t instance;
} pd_ConcreteNonFungible_V16_t;

typedef struct {
    uint8_t value;
    union {
        pd_Compactu128_t fungible;
        pd_AssetInstance_V16_t nonFungible;
    };
} pd_Fungibility_V16_t;

typedef struct {
    uint8_t value;
    union {
        pd_MultiLocationV1_V16_t concrete;
        pd_Bytes_t abstract;
    };
} pd_MultiAssetId_V16_t;

typedef struct {
    const uint8_t* _ptr;
} pd_AccountId_V16_t;

typedef struct {
    compactInt_t value;
} pd_CompactAccountIndex_V16_t;

typedef struct {
    const uint8_t* _ptr;
} pd_EcdsaPublic_V16_t;

typedef struct {
    const uint8_t* _ptr;
} pd_EcdsaSignature_V16_t;

typedef struct {
    const uint8_t* _ptr;
} pd_Ed25519Public_V16_t;

typedef struct {
    const uint8_t* _ptr;
} pd_Ed25519Signature_V16_t;

typedef struct {
    uint8_t value;
    union {
        pd_Bytes_t abstract;
        pd_MultiLocationV0_V16_t concrete;
        pd_AbstractFungible_V16_t abstractFungible;
        pd_AbstractNonFungible_V16_t abstractNonFungible;
        pd_ConcreteFungible_V16_t concreteFungible;
        pd_ConcreteNonFungible_V16_t concreteNonFungible;
    };
} pd_MultiAssetV0_V16_t;

typedef struct {
    pd_MultiAssetId_V16_t assetId;
    pd_Fungibility_V16_t fungibility;
} pd_MultiAssetV1_V16_t;

typedef struct {
    const uint8_t* _ptr;
} pd_Sr25519Public_V16_t;

typedef struct {
    const uint8_t* _ptr;
} pd_Sr25519Signature_V16_t;

typedef struct {
    uint8_t value;
} pd_Vote_V16_t;

typedef struct {
    uint8_t value;
    union {
        pd_AccountId_V16_t id;
        pd_CompactAccountIndex_V16_t index;
        pd_Bytes_t raw;
        const uint8_t* _ptr;
    };
} pd_AccountIdLookupOfT_V16_t;

typedef struct {
    pd_BalanceOf_t aye;
    pd_BalanceOf_t nay;
} pd_AccountVoteSplit_V16_t;

typedef struct {
    pd_Vote_V16_t vote;
    pd_BalanceOf_t balance;
} pd_AccountVoteStandard_V16_t;

typedef struct {
    compactInt_t value;
} pd_CompactPerBill_V16_t;

typedef struct {
    uint8_t value;
    union {
        pd_Ed25519Signature_V16_t ed25519;
        pd_Sr25519Signature_V16_t sr25519;
        pd_EcdsaSignature_V16_t ecdsa;
    };
} pd_MultiSignature_V16_t;

typedef struct {
    uint8_t value;
    union {
        pd_Ed25519Public_V16_t ed25519;
        pd_Sr25519Public_V16_t sr25519;
        pd_EcdsaPublic_V16_t ecdsa;
    };
} pd_MultiSigner_V16_t;

typedef struct {
    uint32_t value;
} pd_Perbill_V16_t;

typedef struct {
    uint8_t value;
} pd_Percent_V16_t;

typedef struct {
    uint8_t value;
} pd_ProxyType_V16_t;

typedef struct {
    uint32_t value;
} pd_ReferendumIndex_V16_t;

typedef struct {
    pd_BlockNumber_t height;
    uint32_t index;
} pd_Timepoint_V16_t;

typedef struct {
    pd_AccountId_V16_t id;
    pd_Data_t data;
} pd_TupleAccountIdData_V16_t;

typedef struct {
    pd_H256_t h256;
    uint32_t u32;
} pd_TupleH256u32_V16_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecMultiAssetV0_V16_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecMultiAssetV1_V16_t;

typedef struct {
    uint8_t value;
    union {
        pd_AccountVoteStandard_V16_t voteStandard;
        pd_AccountVoteSplit_V16_t voteSplit;
    };
} pd_AccountVote_V16_t;

typedef struct {
    uint8_t value;
    pd_Balance_t freeBalance;
} pd_BondExtraBalanceOfT_V16_t;

typedef struct {
    uint8_t value;
    union {
        pd_H256_t legacy;
        pd_Bytes_t _inline;
        pd_TupleH256u32_V16_t lookup;
    };
} pd_BoundedCallOfT_V16_t;

typedef struct {
    uint8_t value;
    union {
        pd_VecMultiAssetV0_V16_t vecMultiassetV0;
        pd_VecMultiAssetV1_V16_t vecMultiassetV1;
    };
} pd_BoxVersionedMultiAssets_V16_t;

typedef struct {
    uint8_t value;
    union {
        pd_MultiLocationV0_V16_t multilocationV0;
        pd_MultiLocationV1_V16_t multilocationV1;
    };
} pd_BoxVersionedMultiLocation_V16_t;

typedef struct {
    uint8_t value;
    pd_AccountId_V16_t set;
} pd_ConfigOpAccountId_V16_t;

typedef struct {
    uint8_t value;
    pd_Balance_t set;
} pd_ConfigOpBalanceOfT_V16_t;

typedef struct {
    uint8_t value;
    pd_Perbill_V16_t set;
} pd_ConfigOpPerbill_V16_t;

typedef struct {
    uint8_t value;
    pd_Percent_V16_t set;
} pd_ConfigOpPercent_V16_t;

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
} pd_IdentityInfo_V16_t;

typedef struct {
    uint8_t value;
    pd_Balance_t feePaid;
} pd_JudgementBalanceOfT_V16_t;

typedef struct {
    uint8_t some;
    pd_MultiSignature_V16_t contained;
} pd_OptionMultiSignature_V16_t;

typedef struct {
    uint8_t some;
    pd_MultiSigner_V16_t contained;
} pd_OptionMultiSigner_V16_t;

typedef struct {
    uint8_t some;
    pd_Timepoint_V16_t contained;
} pd_OptionTimepoint_V16_t;

typedef struct {
    uint8_t value;
    pd_AccountId_V16_t accountId;
} pd_RewardDestination_V16_t;

typedef struct {
    pd_CompactPerBill_V16_t commission;
    pd_bool_t blocked;
} pd_ValidatorPrefs_V16_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecAccountIdLookupOfT_V16_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecTupleAccountIdData_V16_t;

typedef struct {
    pd_BalanceOf_t locked;
    pd_BalanceOf_t per_block;
    pd_BlockNumber_t starting_block;
} pd_VestingInfo_V16_t;

typedef struct {
    uint8_t value;
    pd_Compactu64_t limited;
} pd_WeightLimit_V16_t;

typedef struct {
    pd_Compactu64_t refTime;
    pd_Compactu64_t proofSize;
} pd_Weight_V16_t;

typedef struct {
    uint32_t value;
} pd_AccountIndex_V16_t;

typedef struct {
    uint8_t value;
    uint32_t set;
} pd_ConfigOpu32_V16_t;

typedef struct {
    uint8_t value;
} pd_Conviction_V16_t;

typedef struct {
    uint32_t value;
} pd_EraIndex_V16_t;

typedef struct {
    const uint8_t* _ptr;
} pd_EthereumAddress_V16_t;

typedef struct {
    const uint8_t* _ptr;
} pd_Keys_V16_t;

typedef struct {
    uint32_t value;
} pd_MemberCount_V16_t;

typedef struct {
    uint8_t some;
    pd_AccountId_V16_t contained;
} pd_OptionAccountId_V16_t;

typedef struct {
    uint8_t some;
    pd_ProxyType_V16_t contained;
} pd_OptionProxyType_V16_t;

typedef struct {
    uint8_t some;
    pd_ReferendumIndex_V16_t contained;
} pd_OptionReferendumIndex_V16_t;

typedef struct {
    uint64_t value;
} pd_OverweightIndex_V16_t;

typedef struct {
    uint32_t value;
} pd_ParaId_V16_t;

typedef struct {
    uint32_t value;
} pd_PoolId_V16_t;

typedef struct {
    uint8_t value;
} pd_PoolState_V16_t;

typedef struct {
    uint32_t value;
} pd_RegistrarIndex_V16_t;

typedef struct {
    uint32_t value;
} pd_SessionIndex_V16_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecAccountId_V16_t;

#ifdef __cplusplus
}
#endif
