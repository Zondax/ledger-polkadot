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

#include "substrate_types.h"
#include <stddef.h>
#include <stdint.h>

// Based
// https://github.com/paritytech/substrate/blob/master/node/primitives/src/lib.rs

typedef struct {
    const uint8_t* _ptr;
} pd_AccountId_V9_t;

typedef struct {
    compactInt_t value;
} pd_CompactAccountIndex_V9_t;

typedef struct {
    compactInt_t value;
} pd_CompactPerBill_V9_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_ElectionScore_V9_t;

typedef struct {
    const uint8_t* _ptr;
} pd_KeyValue_V9_t;

typedef struct {
    const uint8_t* _ptr;
} pd_Key_V9_t;

typedef struct {
    uint8_t value;
    union {
        pd_AccountId_V9_t id;
        pd_CompactAccountIndex_V9_t index;
        pd_Bytes_t raw;
        const uint8_t* _ptr;
    };
} pd_LookupasStaticLookupSource_V9_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_MultiSignature_V9_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_MultiSigner_V9_t;

typedef struct {
    compactInt_t value;
} pd_Percent_V9_t;

typedef struct {
    uint8_t value;
} pd_ProxyType_V9_t;

typedef struct {
    uint32_t value;
} pd_ReferendumIndex_V9_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_StatementKind_V9_t;

typedef struct {
    pd_BlockNumber_t height;
    uint32_t index;
} pd_Timepoint_V9_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_TupleAccountIdData_V9_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_TupleBalanceOfTBalanceOfTBlockNumber_V9_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_XcmVersion_V9_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_schedulePeriodBlockNumber_V9_t;

typedef struct {
    uint8_t some;
    pd_Timepoint_V9_t contained;
} pd_OptionTimepoint_V9_t;

typedef struct {
    pd_CompactPerBill_V9_t commission;
    pd_bool_t blocked;
} pd_ValidatorPrefs_V9_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecLookupasStaticLookupSource_V9_t;

typedef struct {
    uint32_t value;
} pd_AccountIndex_V9_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_AccountVoteBalanceOf_V9_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_AuthorityIdasRuntimeAppPublicSignature_V9_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_BoxEquivocationProofHashBlockNumber_V9_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_BoxEquivocationProofHeader_V9_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_BoxIdentityInfoMaxAdditionalFields_V9_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_BoxMultiLocation_V9_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_BoxPalletsOrigin_V9_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_BoxRawSolutionSolutionOfT_V9_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_BoxTasConfigIProposal_V9_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_BoxVersionedMultiAssets_V9_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_BoxVersionedMultiLocation_V9_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_BoxVersionedXcmTasSysConfigCall_V9_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_BoxVersionedXcmTuple_V9_t;

typedef struct {
    const uint8_t* _ptr;
} pd_CallHashOf_V9_t;

typedef struct {
    uint8_t value;
} pd_Conviction_V9_t;

typedef struct {
    const uint8_t* _ptr;
} pd_EcdsaSignature_V9_t;

typedef struct {
    uint32_t value;
} pd_EraIndex_V9_t;

typedef struct {
    const uint8_t* _ptr;
} pd_EthereumAddress_V9_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_HeadData_V9_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_HeartbeatBlockNumber_V9_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_HrmpChannelId_V9_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_IdentityFields_V9_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_JudgementBalanceOfT_V9_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_KeyOwnerProof_V9_t;

typedef struct {
    const uint8_t* _ptr;
} pd_Keys_V9_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_LeasePeriodOfT_V9_t;

typedef struct {
    uint32_t value;
} pd_MemberCount_V9_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_NextConfigDescriptor_V9_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_OpaqueCallT_V9_t;

typedef struct {
    uint8_t some;
    pd_AccountId_V9_t contained;
} pd_OptionAccountId_V9_t;

typedef struct {
    uint8_t some;
    pd_ElectionScore_V9_t contained;
} pd_OptionElectionScore_V9_t;

typedef struct {
    uint8_t some;
    pd_MultiSignature_V9_t contained;
} pd_OptionMultiSignature_V9_t;

typedef struct {
    uint8_t some;
    pd_MultiSigner_V9_t contained;
} pd_OptionMultiSigner_V9_t;

typedef struct {
    uint8_t some;
    pd_Percent_V9_t contained;
} pd_OptionPercent_V9_t;

typedef struct {
    uint8_t some;
    pd_ProxyType_V9_t contained;
} pd_OptionProxyType_V9_t;

typedef struct {
    uint8_t some;
    pd_ReferendumIndex_V9_t contained;
} pd_OptionReferendumIndex_V9_t;

typedef struct {
    uint8_t some;
    pd_StatementKind_V9_t contained;
} pd_OptionStatementKind_V9_t;

typedef struct {
    uint8_t some;
    pd_TupleBalanceOfTBalanceOfTBlockNumber_V9_t contained;
} pd_OptionTupleBalanceOfTBalanceOfTBlockNumber_V9_t;

typedef struct {
    uint8_t some;
    pd_XcmVersion_V9_t contained;
} pd_OptionXcmVersion_V9_t;

typedef struct {
    uint8_t some;
    pd_schedulePeriodBlockNumber_V9_t contained;
} pd_OptionschedulePeriodBlockNumber_V9_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_OverweightIndex_V9_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_ParaId_V9_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_ParachainsInherentDataHeader_V9_t;

typedef struct {
    uint32_t value;
} pd_Perbill_V9_t;

typedef struct {
    uint32_t value;
} pd_RegistrarIndex_V9_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_Renouncing_V9_t;

typedef struct {
    uint8_t value;
} pd_RewardDestination_V9_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_SessionIndex_V9_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_SolutionOrSnapshotSize_V9_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_SupportsAccountId_V9_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_ValidationCode_V9_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecAccountId_V9_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecKeyValue_V9_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecKey_V9_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecTupleAccountIdData_V9_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_VestingInfoBalanceOfTBlockNumber_V9_t;

typedef struct {
    uint64_t value;
} pd_WeightLimit_V9_t;

typedef struct {
    uint64_t value;
} pd_Weight_V9_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_schedulePriority_V9_t;

#ifdef __cplusplus
}
#endif
