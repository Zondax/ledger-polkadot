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

#include "substrate_types.h"
#include <stddef.h>
#include <stdint.h>

// Based
// https://github.com/paritytech/substrate/blob/master/node/primitives/src/lib.rs

typedef struct {
    const uint8_t* _ptr;
} pd_AccountId_V12_t;

typedef struct {
    compactInt_t value;
} pd_CompactAccountIndex_V12_t;

typedef struct {
    uint8_t value;
} pd_Vote_V12_t;

typedef struct {
    pd_BalanceOf_t aye;
    pd_BalanceOf_t nay;
} pd_AccountVoteSplit_V12_t;

typedef struct {
    pd_Vote_V12_t vote;
    pd_BalanceOf_t balance;
} pd_AccountVoteStandard_V12_t;

typedef struct {
    compactInt_t value;
} pd_CompactPerBill_V12_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_ElectionScore_V12_t;

typedef struct {
    const uint8_t* _ptr;
} pd_KeyValue_V12_t;

typedef struct {
    const uint8_t* _ptr;
} pd_Key_V12_t;

typedef struct {
    uint8_t value;
    union {
        pd_AccountId_V12_t id;
        pd_CompactAccountIndex_V12_t index;
        pd_Bytes_t raw;
        const uint8_t* _ptr;
    };
} pd_LookupasStaticLookupSource_V12_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_MultiSignature_V12_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_MultiSigner_V12_t;

typedef struct {
    uint8_t value;
} pd_ProxyType_V12_t;

typedef struct {
    uint32_t value;
} pd_ReferendumIndex_V12_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_StatementKind_V12_t;

typedef struct {
    pd_BlockNumber_t height;
    uint32_t index;
} pd_Timepoint_V12_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_TupleAccountIdData_V12_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_TupleBalanceOfTBalanceOfTBlockNumber_V12_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_XcmVersion_V12_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_schedulePeriodBlockNumber_V12_t;

typedef struct {
    uint8_t value;
    union {
        pd_AccountVoteStandard_V12_t voteStandard;
        pd_AccountVoteSplit_V12_t voteSplit;
    };
} pd_AccountVote_V12_t;

typedef struct {
    pd_Call_t call;
} pd_OpaqueCall_V12_t;

typedef struct {
    uint8_t some;
    pd_Timepoint_V12_t contained;
} pd_OptionTimepoint_V12_t;

typedef struct {
    pd_CompactPerBill_V12_t commission;
    pd_bool_t blocked;
} pd_ValidatorPrefs_V12_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecLookupasStaticLookupSource_V12_t;

typedef struct {
    uint32_t value;
} pd_AccountIndex_V12_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_AuthorityIdasRuntimeAppPublicSignature_V12_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_BoxCallOrHashOfT_V12_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_BoxEquivocationProofHashBlockNumber_V12_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_BoxEquivocationProofHeader_V12_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_BoxIdentityInfoMaxAdditionalFields_V12_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_BoxMultiLocation_V12_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_BoxPalletsOrigin_V12_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_BoxRawSolutionSolutionOfT_V12_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_BoxVersionedMultiAssets_V12_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_BoxVersionedMultiLocation_V12_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_BoxVersionedXcmTasSysConfigCall_V12_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_BoxVersionedXcmTuple_V12_t;

typedef struct {
    const uint8_t* _ptr;
} pd_CallHashOf_V12_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_ConfigOpBalanceOfT_V12_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_ConfigOpPerbill_V12_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_ConfigOpPercent_V12_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_ConfigOpu32_V12_t;

typedef struct {
    uint8_t value;
} pd_Conviction_V12_t;

typedef struct {
    const uint8_t* _ptr;
} pd_EcdsaSignature_V12_t;

typedef struct {
    uint32_t value;
} pd_EraIndex_V12_t;

typedef struct {
    const uint8_t* _ptr;
} pd_EthereumAddress_V12_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_HeadData_V12_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_HeartbeatBlockNumber_V12_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_HrmpChannelId_V12_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_IdentityFields_V12_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_JudgementBalanceOfT_V12_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_KeyOwnerProof_V12_t;

typedef struct {
    const uint8_t* _ptr;
} pd_Keys_V12_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_LeasePeriodOfT_V12_t;

typedef struct {
    uint32_t value;
} pd_MemberCount_V12_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_NextConfigDescriptor_V12_t;

typedef struct {
    uint8_t some;
    pd_AccountId_V12_t contained;
} pd_OptionAccountId_V12_t;

typedef struct {
    uint8_t some;
    pd_ElectionScore_V12_t contained;
} pd_OptionElectionScore_V12_t;

typedef struct {
    uint8_t some;
    pd_MultiSignature_V12_t contained;
} pd_OptionMultiSignature_V12_t;

typedef struct {
    uint8_t some;
    pd_MultiSigner_V12_t contained;
} pd_OptionMultiSigner_V12_t;

typedef struct {
    uint8_t some;
    pd_ProxyType_V12_t contained;
} pd_OptionProxyType_V12_t;

typedef struct {
    uint8_t some;
    pd_ReferendumIndex_V12_t contained;
} pd_OptionReferendumIndex_V12_t;

typedef struct {
    uint8_t some;
    pd_StatementKind_V12_t contained;
} pd_OptionStatementKind_V12_t;

typedef struct {
    uint8_t some;
    pd_TupleBalanceOfTBalanceOfTBlockNumber_V12_t contained;
} pd_OptionTupleBalanceOfTBalanceOfTBlockNumber_V12_t;

typedef struct {
    uint8_t some;
    pd_XcmVersion_V12_t contained;
} pd_OptionXcmVersion_V12_t;

typedef struct {
    uint8_t some;
    pd_schedulePeriodBlockNumber_V12_t contained;
} pd_OptionschedulePeriodBlockNumber_V12_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_OverweightIndex_V12_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_ParaId_V12_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_ParachainsInherentDataHeader_V12_t;

typedef struct {
    uint32_t value;
} pd_Perbill_V12_t;

typedef struct {
    compactInt_t value;
} pd_Percent_V12_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_PvfCheckStatement_V12_t;

typedef struct {
    uint32_t value;
} pd_RegistrarIndex_V12_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_Renouncing_V12_t;

typedef struct {
    uint8_t value;
} pd_RewardDestination_V12_t;

typedef struct {
    uint32_t value;
} pd_SessionIndex_V12_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_SolutionOrSnapshotSize_V12_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_SupportsAccountId_V12_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_ValidationCodeHash_V12_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_ValidationCode_V12_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_ValidatorSignature_V12_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecAccountId_V12_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecKeyValue_V12_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecKey_V12_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecTupleAccountIdData_V12_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_VestingInfoBalanceOfTBlockNumber_V12_t;

typedef struct {
    uint64_t value;
} pd_WeightLimit_V12_t;

typedef struct {
    uint64_t value;
} pd_Weight_V12_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_schedulePriority_V12_t;

#ifdef __cplusplus
}
#endif
