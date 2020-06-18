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
#include "polkadot_dispatch.h"
#include "parser_impl.h"
#include "bignum.h"

#include <stdint.h>
#include <stddef.h>
#include <zxmacros.h>

parser_error_t _readCompactAssignments(parser_context_t *c, pd_CompactAssignments_t *v) {
    return _readCompactInt(c, v);
}

parser_error_t _readCompactAuctionIndex(parser_context_t *c, pd_CompactAuctionIndex_t *v) {
    return _readCompactInt(c, v);
}

parser_error_t _readCompactBlockNumber(parser_context_t *c, pd_CompactBlockNumber_t *v) {
    return _readCompactInt(c, v);
}

parser_error_t _readCompactEraIndex(parser_context_t *c, pd_CompactEraIndex_t *v) {
    return _readCompactInt(c, v);
}

parser_error_t _readCompactLeasePeriodOf(parser_context_t *c, pd_CompactLeasePeriodOf_t *v) {
    return _readCompactInt(c, v);
}

parser_error_t _readCompactMemberCount(parser_context_t *c, pd_CompactMemberCount_t *v) {
    return _readCompactInt(c, v);
}

parser_error_t _readCompactMoment(parser_context_t *c, pd_CompactMoment_t *v) {
    return _readCompactInt(c, v);
}

parser_error_t _readCompactParaId(parser_context_t *c, pd_CompactParaId_t *v) {
    return _readCompactInt(c, v);
}

parser_error_t _readCompactPropIndex(parser_context_t *c, pd_CompactPropIndex_t *v) {
    return _readCompactInt(c, v);
}

parser_error_t _readCompactProposalIndex(parser_context_t *c, pd_CompactProposalIndex_t *v) {
    return _readCompactInt(c, v);
}

parser_error_t _readCompactReferendumIndex(parser_context_t *c, pd_CompactReferendumIndex_t *v) {
    return _readCompactInt(c, v);
}

parser_error_t _readCompactRegistrarIndex(parser_context_t *c, pd_CompactRegistrarIndex_t *v) {
    return _readCompactInt(c, v);
}

parser_error_t _readCompactSubId(parser_context_t *c, pd_CompactSubId_t *v) {
    return _readCompactInt(c, v);
}

parser_error_t _readCompactWeight(parser_context_t *c, pd_CompactWeight_t *v) {
    return _readCompactInt(c, v);
}

parser_error_t _readAccountId(parser_context_t *c, pd_AccountId_t *v) {
    GEN_DEF_READARRAY(32)
}

parser_error_t _readAccountIndex(parser_context_t *c, pd_AccountIndex_t *v) {
    return _readUInt32(c, &v->value);
}

parser_error_t _readAccountVoteSplit(parser_context_t *c, pd_AccountVoteSplit_t *v) {
    CHECK_ERROR(_readBalanceOf(c, &v->aye));
    CHECK_ERROR(_readBalanceOf(c, &v->nay));
    return parser_ok;
}

parser_error_t _readAccountVoteStandard(parser_context_t *c, pd_AccountVoteStandard_t *v) {
    CHECK_ERROR(_readVote(c, &v->vote));
    CHECK_ERROR(_readBalanceOf(c, &v->balance));
    return parser_ok;
}

parser_error_t _readAccountVote(parser_context_t *c, pd_AccountVote_t *v) {
    CHECK_INPUT();
    CHECK_ERROR(_readUInt8(c, &v->value))

    switch (v->value) {
        case 0:
            CHECK_INPUT();
            CHECK_ERROR(_readAccountVoteStandard(c, &v->voteStandard))
            break;
        case 1:
            CHECK_INPUT();
            CHECK_ERROR(_readAccountVoteSplit(c, &v->voteSplit))
            break;
        default:
            break;
    }

    return parser_ok;
}

parser_error_t _readAttestedCandidate(parser_context_t *c, pd_AttestedCandidate_t *v) {
    return parser_not_supported;
}

parser_error_t _readBalanceOf(parser_context_t *c, pd_BalanceOf_t *v) {
    GEN_DEF_READARRAY(16)
}

parser_error_t _readBytes(parser_context_t *c, pd_Bytes_t *v) {
    CHECK_INPUT()

    compactInt_t clen;
    CHECK_ERROR(_readCompactInt(c, &clen))
    CHECK_ERROR(_getValue(&clen, &v->_len))

    v->_ptr = c->buffer + c->offset;
    CTX_CHECK_AND_ADVANCE(c, v->_len);
    return parser_ok;
}

parser_error_t _readCall(parser_context_t *c, pd_Call_t *v) {
    return parser_not_supported;
}

parser_error_t _readChangesTrieConfiguration(parser_context_t *c, pd_ChangesTrieConfiguration_t *v) {
    return parser_not_supported;
}

parser_error_t _readCollatorId(parser_context_t *c, pd_CollatorId_t *v) {
    return _readHash(c, &v->value);
}

parser_error_t _readConviction(parser_context_t *c, pd_Conviction_t *v) {
    CHECK_INPUT()

    CHECK_ERROR(_readUInt8(c, &v->value))
    if (v->value > 5) {
        return parser_value_out_of_range;
    }

    return parser_ok;
}

parser_error_t _readData(parser_context_t *c, pd_Data_t *v) {
    CHECK_INPUT();
    CHECK_ERROR(_readUInt8(c, (uint8_t *) &v->type))

    // based on:
    // https://github.com/paritytech/substrate/blob/effe489951d1edab9d34846b1eefdfaf9511dab9/frame/identity/src/lib.rs#L139

    if (v->type > Data_e_NONE && v->type <= Data_e_RAW_VECU8) {
        const uint8_t bufferSize = ((uint8_t) v->type - 1);
        v->_ptr = c->buffer + c->offset;
        v->_len = bufferSize;
        CTX_CHECK_AND_ADVANCE(c, v->_len);
        return parser_ok;
    }

    switch (v->type) {
        case Data_e_NONE:
            v->_ptr = NULL;
            v->_len = 0;
            break;
        case Data_e_RAW_VECU8:
            // This should have been handled before (1..33)
            return parser_unexpected_value;
        case Data_e_BLAKETWO256U8_32:
        case Data_e_SHA256_U8_32:
        case Data_e_KECCAK256_U8_32:
        case Data_e_SHATHREE256_U8_32:
        default:
            return parser_not_supported;
    }

    return parser_ok;
}

parser_error_t _readDefunctVoter(parser_context_t *c, pd_DefunctVoter_t *v) {
    return parser_not_supported;
}

parser_error_t _readDoubleVoteReport(parser_context_t *c, pd_DoubleVoteReport_t *v) {
    return parser_not_supported;
}

parser_error_t _readEcdsaSignature(parser_context_t *c, pd_EcdsaSignature_t *v) {
    GEN_DEF_READARRAY(65)
}

parser_error_t _readElectionScore(parser_context_t *c, pd_ElectionScore_t *v) {
    return parser_not_supported;
}

parser_error_t _readElectionSize(parser_context_t *c, pd_ElectionSize_t *v) {
    return parser_not_supported;
}

parser_error_t _readEquivocationProof(parser_context_t *c, pd_EquivocationProof_t *v) {
    return parser_not_supported;
}

parser_error_t _readEraIndex(parser_context_t *c, pd_EraIndex_t *v) {
    return _readUInt32(c, &v->value);
}

parser_error_t _readEthereumAddress(parser_context_t *c, pd_EthereumAddress_t *v) {
    GEN_DEF_READARRAY(20)
}

parser_error_t _readHeadData(parser_context_t *c, pd_HeadData_t *v) {
    return parser_not_supported;
}

parser_error_t _readHeader(parser_context_t *c, pd_Header_t *v) {
    return parser_not_supported;
}

parser_error_t _readHeartbeat(parser_context_t *c, pd_Heartbeat_t *v) {
    return parser_not_supported;
}

parser_error_t _readIdentityFields(parser_context_t *c, pd_IdentityFields_t *v) {
    return parser_not_supported;
}

parser_error_t _readIdentityInfo(parser_context_t *c, pd_IdentityInfo_t *v) {
    CHECK_ERROR(_readVecTupleDataData(c, &v->additional));
    CHECK_ERROR(_readData(c, &v->display));
    CHECK_ERROR(_readData(c, &v->legal));
    CHECK_ERROR(_readData(c, &v->web));
    CHECK_ERROR(_readData(c, &v->riot));
    CHECK_ERROR(_readData(c, &v->email));
    CHECK_ERROR(_readOptionu8_array_20(c, &v->pgp_fingerprint));
    CHECK_ERROR(_readData(c, &v->image));
    CHECK_ERROR(_readData(c, &v->twitter));
    return parser_ok;
}

parser_error_t _readIdentityJudgement(parser_context_t *c, pd_IdentityJudgement_t *v) {
    return parser_not_supported;
}

parser_error_t _readKeyOwnerProof(parser_context_t *c, pd_KeyOwnerProof_t *v) {
    return parser_not_supported;
}

parser_error_t _readKeyValue(parser_context_t *c, pd_KeyValue_t *v) {
    return parser_not_supported;
}

parser_error_t _readKey(parser_context_t *c, pd_Key_t *v) {
    GEN_DEF_READARRAY(32)
}

parser_error_t _readLookupSource(parser_context_t *c, pd_LookupSource_t *v) {
    GEN_DEF_READARRAY(32)
}

parser_error_t _readMemberCount(parser_context_t *c, pd_MemberCount_t *v) {
    return _readUInt32(c, &v->value);
}

parser_error_t _readMoreAttestations(parser_context_t *c, pd_MoreAttestations_t *v) {
    return parser_not_supported;
}

parser_error_t _readParaInfo(parser_context_t *c, pd_ParaInfo_t *v) {
    CHECK_INPUT();
    CHECK_ERROR(_readUInt8(c, &v->scheduling))
    return parser_ok;
}

parser_error_t _readPerbill(parser_context_t *c, pd_Perbill_t *v) {
    return _readUInt32(c, &v->value);
}

parser_error_t _readPeriod(parser_context_t *c, pd_Period_t *v) {
    return parser_not_supported;
}

parser_error_t _readPriority(parser_context_t *c, pd_Priority_t *v) {
    return parser_not_supported;
}

parser_error_t _readProxyType(parser_context_t *c, pd_ProxyType_t *v) {
    return parser_not_supported;
}

parser_error_t _readReferendumIndex(parser_context_t *c, pd_ReferendumIndex_t *v) {
    return _readUInt32(c, &v->value);
}

parser_error_t _readRegistrarIndex(parser_context_t *c, pd_RegistrarIndex_t *v) {
    return _readUInt32(c, &v->value);
}

parser_error_t _readRenouncing(parser_context_t *c, pd_Renouncing_t *v) {
    return parser_not_supported;
}

parser_error_t _readRewardDestination(parser_context_t *c, pd_RewardDestination_t *v) {
    CHECK_INPUT();

    CHECK_ERROR(_readUInt8(c, &v->value))
    if (v->value > 2) {
        return parser_value_out_of_range;
    }

    return parser_ok;
}

parser_error_t _readSignature(parser_context_t *c, pd_Signature_t *v) {
    GEN_DEF_READARRAY(64)
}

parser_error_t _readSocietyJudgement(parser_context_t *c, pd_SocietyJudgement_t *v) {
    return parser_not_supported;
}

parser_error_t _readStatementKind(parser_context_t *c, pd_StatementKind_t *v) {
    return parser_not_supported;
}

parser_error_t _readTimepoint(parser_context_t *c, pd_Timepoint_t *v) {
    return parser_not_supported;
}

parser_error_t _readTupleAccountIdData(parser_context_t *c, pd_TupleAccountIdData_t *v) {
    return parser_not_supported;
}

parser_error_t _readTupleBalanceOfBalanceOfBlockNumber(parser_context_t *c, pd_TupleBalanceOfBalanceOfBlockNumber_t *v) {
    CHECK_ERROR(_readBalanceOf(c, &v->balance1))
    CHECK_ERROR(_readBalanceOf(c, &v->balance2))
    CHECK_ERROR(_readBlockNumber(c, &v->blockNumber))
    return parser_ok;
}

parser_error_t _readTupleDataData(parser_context_t *c, pd_TupleDataData_t *v) {
    CHECK_INPUT();
    CHECK_ERROR(_readData(c, &v->data1))
    CHECK_ERROR(_readData(c, &v->data1))
    return parser_ok;
}

parser_error_t _readValidationCode(parser_context_t *c, pd_ValidationCode_t *v) {
    return parser_not_supported;
}

parser_error_t _readValidatorIndex(parser_context_t *c, pd_ValidatorIndex_t *v) {
    return parser_not_supported;
}

parser_error_t _readValidatorPrefs(parser_context_t *c, pd_ValidatorPrefs_t *v) {
    CHECK_INPUT();
    return _readCompactBalance(c, &v->balance);
}

parser_error_t _readVestingInfo(parser_context_t *c, pd_VestingInfo_t *v) {
    CHECK_ERROR(_readBalanceOf(c, &v->locked))
    CHECK_ERROR(_readBalanceOf(c, &v->per_block))
    CHECK_ERROR(_readBlockNumber(c, &v->starting_block))
    return parser_ok;
}

parser_error_t _readVote(parser_context_t *c, pd_Vote_t *v) {
    CHECK_INPUT();
    uint8_t b;
    CHECK_ERROR(_readUInt8(c, &b))

    v->aye = (b & 0x80u) >> 7u;
    v->conviction.value = b & 0x7Fu;

    if (v->conviction.value > 5) {
        return parser_value_out_of_range;
    }

    return parser_ok;
}

parser_error_t _readu8_array_20(parser_context_t *c, pd_u8_array_20_t *v) {
    GEN_DEF_READARRAY(20)
}

parser_error_t _readu8_array_32(parser_context_t *c, pd_u8_array_32_t *v) {
    GEN_DEF_READARRAY(32)
}

parser_error_t _readVecAccountId(parser_context_t *c, pd_VecAccountId_t *v) {
    GEN_DEF_READVECTOR(AccountId)
}

parser_error_t _readVecAttestedCandidate(parser_context_t *c, pd_VecAttestedCandidate_t *v) {
    GEN_DEF_READVECTOR(AttestedCandidate)
}

parser_error_t _readVecCall(parser_context_t *c, pd_VecCall_t *v) {
    GEN_DEF_READVECTOR(Call)
}

parser_error_t _readVecHeader(parser_context_t *c, pd_VecHeader_t *v) {
    GEN_DEF_READVECTOR(Header)
}

parser_error_t _readVecKeyValue(parser_context_t *c, pd_VecKeyValue_t *v) {
    GEN_DEF_READVECTOR(KeyValue)
}

parser_error_t _readVecKey(parser_context_t *c, pd_VecKey_t *v) {
    GEN_DEF_READVECTOR(Key)
}

parser_error_t _readVecLookupSource(parser_context_t *c, pd_VecLookupSource_t *v) {
    GEN_DEF_READVECTOR(LookupSource)
}

parser_error_t _readVecTupleAccountIdData(parser_context_t *c, pd_VecTupleAccountIdData_t *v) {
    GEN_DEF_READVECTOR(TupleAccountIdData)
}

parser_error_t _readVecTupleDataData(parser_context_t *c, pd_VecTupleDataData_t *v) {
    GEN_DEF_READVECTOR(TupleDataData)
}

parser_error_t _readVecValidatorIndex(parser_context_t *c, pd_VecValidatorIndex_t *v) {
    GEN_DEF_READVECTOR(ValidatorIndex)
}

parser_error_t _readVecu32(parser_context_t *c, pd_Vecu32_t *v) {
    GEN_DEF_READVECTOR(u32)
}

parser_error_t _readOptionAccountId(parser_context_t *c, pd_OptionAccountId_t *v) {
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readAccountId(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionChangesTrieConfiguration(parser_context_t *c, pd_OptionChangesTrieConfiguration_t *v) {
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readChangesTrieConfiguration(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionPeriod(parser_context_t *c, pd_OptionPeriod_t *v) {
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readPeriod(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionProxyType(parser_context_t *c, pd_OptionProxyType_t *v) {
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readProxyType(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionStatementKind(parser_context_t *c, pd_OptionStatementKind_t *v) {
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readStatementKind(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionTimepoint(parser_context_t *c, pd_OptionTimepoint_t *v) {
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readTimepoint(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionTupleBalanceOfBalanceOfBlockNumber(parser_context_t *c, pd_OptionTupleBalanceOfBalanceOfBlockNumber_t *v) {
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readTupleBalanceOfBalanceOfBlockNumber(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionu8_array_20(parser_context_t *c, pd_Optionu8_array_20_t *v) {
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readu8_array_20(c, &v->contained))
    }
    return parser_ok;
}

///////////////////////////////////
///////////////////////////////////
///////////////////////////////////

parser_error_t _toStringCompactAssignments(
        const pd_CompactAssignments_t *v,
        char *outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t *pageCount) {
    return _toStringCompactInt(v, 0, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringCompactAuctionIndex(
        const pd_CompactAuctionIndex_t *v,
        char *outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t *pageCount) {
    return _toStringCompactInt(v, 0, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringCompactBlockNumber(
        const pd_CompactBlockNumber_t *v,
        char *outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t *pageCount) {
    return _toStringCompactInt(v, 0, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringCompactEraIndex(
        const pd_CompactEraIndex_t *v,
        char *outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t *pageCount) {
    return _toStringCompactInt(v, 0, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringCompactLeasePeriodOf(
        const pd_CompactLeasePeriodOf_t *v,
        char *outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t *pageCount) {
    return _toStringCompactInt(v, 0, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringCompactMemberCount(
        const pd_CompactMemberCount_t *v,
        char *outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t *pageCount) {
    return _toStringCompactInt(v, 0, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringCompactMoment(
        const pd_CompactMoment_t *v,
        char *outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t *pageCount) {
    return _toStringCompactInt(v, 0, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringCompactParaId(
        const pd_CompactParaId_t *v,
        char *outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t *pageCount) {
    return _toStringCompactInt(v, 0, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringCompactPropIndex(
        const pd_CompactPropIndex_t *v,
        char *outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t *pageCount) {
    return _toStringCompactInt(v, 0, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringCompactProposalIndex(
        const pd_CompactProposalIndex_t *v,
        char *outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t *pageCount) {
    return _toStringCompactInt(v, 0, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringCompactReferendumIndex(
        const pd_CompactReferendumIndex_t *v,
        char *outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t *pageCount) {
    return _toStringCompactInt(v, 0, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringCompactRegistrarIndex(
        const pd_CompactRegistrarIndex_t *v,
        char *outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t *pageCount) {
    return _toStringCompactInt(v, 0, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringCompactSubId(
        const pd_CompactSubId_t *v,
        char *outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t *pageCount) {
    return _toStringCompactInt(v, 0, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringCompactWeight(
        const pd_CompactWeight_t *v,
        char *outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t *pageCount) {
    return _toStringCompactInt(v, 0, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringAccountId(
        const pd_AccountId_t *v,
        char *outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t *pageCount) {
    return _toStringPubkeyAsAddress(v->_ptr, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringAccountIndex(
        const pd_AccountIndex_t *v,
        char *outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t *pageCount) {
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringAccountVoteSplit(
        const pd_AccountVoteSplit_t *v,
        char *outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t *pageCount) {
    CLEAN_AND_CHECK()
    // First measure number of pages
    uint8_t pages[3];

    pages[0] = 1;
    CHECK_ERROR(_toStringBalanceOf(&v->aye, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringBalanceOf(&v->nay, outValue, outValueLen, 0, &pages[2]));

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t) sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx < pages[0]) {
        snprintf(outValue, outValueLen, "Split");
        return parser_ok;
    }
    pageIdx -= pages[0];

    /////////
    /////////

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringBalanceOf(&v->aye, outValue, outValueLen, 0, &pages[1]));
        return parser_ok;
    }
    pageIdx -= pages[1];

    /////////
    /////////

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringBalanceOf(&v->nay, outValue, outValueLen, 0, &pages[2]));
        return parser_ok;
    }
    pageIdx -= pages[2];

    /////////
    /////////

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringAccountVoteStandard(
        const pd_AccountVoteStandard_t *v,
        char *outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t *pageCount) {
    CLEAN_AND_CHECK()
    // First measure number of pages
    uint8_t pages[3];

    pages[0] = 1;
    CHECK_ERROR(_toStringVote(&v->vote, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringBalanceOf(&v->balance, outValue, outValueLen, 0, &pages[2]));

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t) sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        snprintf(outValue, outValueLen, "Standard");
        return parser_ok;
    }
    pageIdx -= pages[0];

    /////////
    /////////

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringVote(&v->vote, outValue, outValueLen, 0, &pages[1]));
        return parser_ok;
    }
    pageIdx -= pages[1];

    /////////
    /////////

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringBalanceOf(&v->balance, outValue, outValueLen, 0, &pages[2]));
        return parser_ok;
    }
    pageIdx -= pages[2];

    /////////
    /////////

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringAccountVote(
        const pd_AccountVote_t *v,
        char *outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t *pageCount) {
    CLEAN_AND_CHECK()
    switch (v->value) {
        case 0:
            _toStringAccountVoteStandard(&v->voteStandard, outValue, outValueLen, pageIdx, pageCount);
            break;
        case 1:
            _toStringAccountVoteSplit(&v->voteSplit, outValue, outValueLen, pageIdx, pageCount);
            break;
        default:
           return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _toStringAttestedCandidate(
        const pd_AttestedCandidate_t *v,
        char *outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t *pageCount) {
    CLEAN_AND_CHECK()

    return parser_print_not_supported;
}

parser_error_t _toStringBalanceOf(
        const pd_BalanceOf_t *v,
        char *outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t *pageCount) {
    CLEAN_AND_CHECK()

    MEMSET(outValue, 0, outValueLen);
    MEMSET(bufferUI, 0, sizeof(bufferUI));
    *pageCount = 1;

    uint8_t bcdOut[50];
    const uint16_t bcdOutLen = sizeof(bcdOut);

    bignumLittleEndian_to_bcd(bcdOut, bcdOutLen, v->_ptr, 16);
    if (!bignumLittleEndian_bcdprint(bufferUI, sizeof(bufferUI), bcdOut, bcdOutLen)) {
        return parser_unexpected_buffer_end;
    }

    pageString(outValue, outValueLen, bufferUI, pageIdx, pageCount);
    return parser_ok;
}

parser_error_t _toStringBytes(
        const pd_Bytes_t *v,
        char *outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t *pageCount) {
    GEN_DEF_TOSTRING_ARRAY(v->_len);
}

parser_error_t _toStringCall(
        const pd_Call_t *v,
        char *outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t *pageCount) {
    CLEAN_AND_CHECK()

    return parser_print_not_supported;
}

parser_error_t _toStringChangesTrieConfiguration(
        const pd_ChangesTrieConfiguration_t *v,
        char *outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t *pageCount) {
    CLEAN_AND_CHECK()

    return parser_print_not_supported;
}

parser_error_t _toStringCollatorId(
        const pd_CollatorId_t *v,
        char *outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t *pageCount) {
    return _toStringHash(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringConviction(
        const pd_Conviction_t *v,
        char *outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t *pageCount) {
    CLEAN_AND_CHECK()

    *pageCount = 1;
    switch (v->value) {
        case 0:
            snprintf(outValue, outValueLen, "None");
            break;
        case 1:
            snprintf(outValue, outValueLen, "Locked1x");
            break;
        case 2:
            snprintf(outValue, outValueLen, "Locked2x");
            break;
        case 3:
            snprintf(outValue, outValueLen, "Locked3x");
            break;
        case 4:
            snprintf(outValue, outValueLen, "Locked4x");
            break;
        case 5:
            snprintf(outValue, outValueLen, "Locked5x");
            break;
        default:
            return parser_print_not_supported;
    }

    return parser_ok;
}

parser_error_t _toStringData(
        const pd_Data_t *v,
        char *outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t *pageCount) {
    CLEAN_AND_CHECK()

    if (v->type > Data_e_NONE && v->type <= Data_e_RAW_VECU8) {
        const uint8_t bufferSize = ((uint8_t) v->type - 1);
        // FIXME: page+print utf8
        GEN_DEF_TOSTRING_ARRAY(bufferSize)
    }

    switch (v->type) {
        case Data_e_NONE:
            *pageCount = 1;
            snprintf(outValue, outValueLen, "None");
            return parser_ok;
        case Data_e_RAW_VECU8:
            // This should have been handled before (1..33)
            return parser_unexpected_value;
        case Data_e_BLAKETWO256U8_32:
        case Data_e_SHA256_U8_32:
        case Data_e_KECCAK256_U8_32:
        case Data_e_SHATHREE256_U8_32:
        default:
            break;
    }

    return parser_print_not_supported;
}

parser_error_t _toStringDefunctVoter(
        const pd_DefunctVoter_t *v,
        char *outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t *pageCount) {
    CLEAN_AND_CHECK()

    return parser_print_not_supported;
}

parser_error_t _toStringDoubleVoteReport(
        const pd_DoubleVoteReport_t *v,
        char *outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t *pageCount) {
    CLEAN_AND_CHECK()

    return parser_print_not_supported;
}

parser_error_t _toStringEcdsaSignature(
        const pd_EcdsaSignature_t *v,
        char *outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t *pageCount) {
    GEN_DEF_TOSTRING_ARRAY(65)
}

parser_error_t _toStringElectionScore(
        const pd_ElectionScore_t *v,
        char *outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t *pageCount) {
    CLEAN_AND_CHECK()

    return parser_print_not_supported;
}

parser_error_t _toStringElectionSize(
        const pd_ElectionSize_t *v,
        char *outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t *pageCount) {
    CLEAN_AND_CHECK()

    return parser_print_not_supported;
}

parser_error_t _toStringEquivocationProof(
        const pd_EquivocationProof_t *v,
        char *outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t *pageCount) {
    CLEAN_AND_CHECK()

    return parser_print_not_supported;
}

parser_error_t _toStringEraIndex(
        const pd_EraIndex_t *v,
        char *outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t *pageCount) {
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringEthereumAddress(
        const pd_EthereumAddress_t *v,
        char *outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t *pageCount) {
    GEN_DEF_TOSTRING_ARRAY(20)
}

parser_error_t _toStringHeadData(
        const pd_HeadData_t *v,
        char *outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t *pageCount) {
    CLEAN_AND_CHECK()

    return parser_print_not_supported;
}

parser_error_t _toStringHeader(
        const pd_Header_t *v,
        char *outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t *pageCount) {
    CLEAN_AND_CHECK()

    return parser_print_not_supported;
}

parser_error_t _toStringHeartbeat(
        const pd_Heartbeat_t *v,
        char *outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t *pageCount) {
    CLEAN_AND_CHECK()

    return parser_print_not_supported;
}

parser_error_t _toStringIdentityFields(
        const pd_IdentityFields_t *v,
        char *outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t *pageCount) {
    CLEAN_AND_CHECK()

    return parser_print_not_supported;
}

parser_error_t _toStringIdentityInfo(
        const pd_IdentityInfo_t *v,
        char *outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t *pageCount) {
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[9];
    CHECK_ERROR(_toStringVecTupleDataData(&v->additional, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringData(&v->display, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringData(&v->legal, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringData(&v->web, outValue, outValueLen, 0, &pages[3]))
    CHECK_ERROR(_toStringData(&v->riot, outValue, outValueLen, 0, &pages[4]))
    CHECK_ERROR(_toStringData(&v->email, outValue, outValueLen, 0, &pages[5]))
    CHECK_ERROR(_toStringOptionu8_array_20(&v->pgp_fingerprint, outValue, outValueLen, 0, &pages[6]))
    CHECK_ERROR(_toStringData(&v->image, outValue, outValueLen, 0, &pages[7]))
    CHECK_ERROR(_toStringData(&v->twitter, outValue, outValueLen, 0, &pages[8]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t) sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringVecTupleDataData(&v->additional, outValue, outValueLen, 0, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    /////////
    /////////

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringData(&v->display, outValue, outValueLen, 0, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    /////////
    /////////

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringData(&v->legal, outValue, outValueLen, 0, &pages[2]))
        return parser_ok;
    }
    pageIdx -= pages[2];

    /////////
    /////////

    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringData(&v->web, outValue, outValueLen, 0, &pages[3]))
        return parser_ok;
    }
    pageIdx -= pages[3];

    /////////
    /////////

    if (pageIdx < pages[4]) {
        CHECK_ERROR(_toStringData(&v->riot, outValue, outValueLen, 0, &pages[4]))
        return parser_ok;
    }
    pageIdx -= pages[4];

    /////////
    /////////

    if (pageIdx < pages[5]) {
        CHECK_ERROR(_toStringData(&v->email, outValue, outValueLen, 0, &pages[5]))
        return parser_ok;
    }
    pageIdx -= pages[5];

    /////////
    /////////

    if (pageIdx < pages[6]) {
        CHECK_ERROR(_toStringOptionu8_array_20(&v->pgp_fingerprint, outValue, outValueLen, 0, &pages[6]))
        return parser_ok;
    }
    pageIdx -= pages[6];

    /////////
    /////////

    if (pageIdx < pages[7]) {
        CHECK_ERROR(_toStringData(&v->image, outValue, outValueLen, 0, &pages[7]))
        return parser_ok;
    }
    pageIdx -= pages[7];

    /////////
    /////////

    if (pageIdx < pages[8]) {
        CHECK_ERROR(_toStringData(&v->twitter, outValue, outValueLen, 0, &pages[8]))
        return parser_ok;
    }
    pageIdx -= pages[8];

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringIdentityJudgement(
        const pd_IdentityJudgement_t *v,
        char *outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t *pageCount) {
    CLEAN_AND_CHECK()

    return parser_print_not_supported;
}

parser_error_t _toStringKeyOwnerProof(
        const pd_KeyOwnerProof_t *v,
        char *outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t *pageCount) {
    CLEAN_AND_CHECK()

    return parser_print_not_supported;
}

parser_error_t _toStringKeyValue(
        const pd_KeyValue_t *v,
        char *outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t *pageCount) {
    CLEAN_AND_CHECK()

    return parser_print_not_supported;
}

parser_error_t _toStringKey(
        const pd_Key_t *v,
        char *outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t *pageCount) {
    CLEAN_AND_CHECK()

    return parser_print_not_supported;
}

parser_error_t _toStringLookupSource(
        const pd_LookupSource_t *v,
        char *outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t *pageCount) {
    return _toStringPubkeyAsAddress(v->_ptr, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringMemberCount(
        const pd_MemberCount_t *v,
        char *outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t *pageCount) {
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringMoreAttestations(
        const pd_MoreAttestations_t *v,
        char *outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t *pageCount) {
    CLEAN_AND_CHECK()

    return parser_print_not_supported;
}

parser_error_t _toStringParaInfo(
        const pd_ParaInfo_t *v,
        char *outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t *pageCount) {
    CLEAN_AND_CHECK()

    switch (v->scheduling) {
        case 0:
            snprintf(outValue, outValueLen, "Scheduling: Always");
            break;
        case 1:
            snprintf(outValue, outValueLen, "Scheduling: Dynamic");
            break;
        default:
            snprintf(outValue, outValueLen, "Scheduling: %d", v->scheduling);
            break;
    }

    return parser_ok;
}

parser_error_t _toStringPerbill(
        const pd_Perbill_t *v,
        char *outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t *pageCount) {
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringPeriod(
        const pd_Period_t *v,
        char *outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t *pageCount) {
    CLEAN_AND_CHECK()

    return parser_print_not_supported;
}

parser_error_t _toStringPriority(
        const pd_Priority_t *v,
        char *outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t *pageCount) {
    CLEAN_AND_CHECK()

    return parser_print_not_supported;
}

parser_error_t _toStringProxyType(
        const pd_ProxyType_t *v,
        char *outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t *pageCount) {
    CLEAN_AND_CHECK()

    return parser_print_not_supported;
}

parser_error_t _toStringReferendumIndex(
        const pd_ReferendumIndex_t *v,
        char *outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t *pageCount) {
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringRegistrarIndex(
        const pd_RegistrarIndex_t *v,
        char *outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t *pageCount) {
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringRenouncing(
        const pd_Renouncing_t *v,
        char *outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t *pageCount) {
    CLEAN_AND_CHECK()

    return parser_print_not_supported;
}

parser_error_t _toStringRewardDestination(
        const pd_RewardDestination_t *v,
        char *outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t *pageCount) {
    CLEAN_AND_CHECK()

    *pageCount = 1;
    switch (v->value) {
        case 0:
            snprintf(outValue, outValueLen, "Staked");
            break;
        case 1:
            snprintf(outValue, outValueLen, "Stash");
            break;
        case 2:
            snprintf(outValue, outValueLen, "Controller");
            break;
        default:
            return parser_print_not_supported;
    }

    return parser_ok;
}

parser_error_t _toStringSignature(
        const pd_Signature_t *v,
        char *outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t *pageCount) {
    GEN_DEF_TOSTRING_ARRAY(64)
}

parser_error_t _toStringSocietyJudgement(
        const pd_SocietyJudgement_t *v,
        char *outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t *pageCount) {
    CLEAN_AND_CHECK()

    return parser_print_not_supported;
}

parser_error_t _toStringStatementKind(
        const pd_StatementKind_t *v,
        char *outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t *pageCount) {
    CLEAN_AND_CHECK()

    return parser_print_not_supported;
}

parser_error_t _toStringTimepoint(
        const pd_Timepoint_t *v,
        char *outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t *pageCount) {
    CLEAN_AND_CHECK()

    return parser_print_not_supported;
}

parser_error_t _toStringTupleAccountIdData(
        const pd_TupleAccountIdData_t *v,
        char *outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t *pageCount) {
    CLEAN_AND_CHECK()

    return parser_print_not_supported;
}

parser_error_t _toStringTupleBalanceOfBalanceOfBlockNumber(
        const pd_TupleBalanceOfBalanceOfBlockNumber_t *v,
        char *outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t *pageCount) {
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[3];
    CHECK_ERROR(_toStringBalanceOf(&v->balance1, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringBalanceOf(&v->balance2, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringBlockNumber(&v->blockNumber, outValue, outValueLen, 0, &pages[2]))

    *pageCount = pages[0] + pages[1] + pages[2];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringBalanceOf(&v->balance1, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringBalanceOf(&v->balance2, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    //////
    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringBlockNumber(&v->blockNumber, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringTupleDataData(
        const pd_TupleDataData_t *v,
        char *outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t *pageCount) {
    CLEAN_AND_CHECK()

    uint8_t pages[2];
    CHECK_ERROR(_toStringData(&v->data1, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringData(&v->data2, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t) sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringData(&v->data1, outValue, outValueLen, 0, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    /////////
    /////////

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringData(&v->data2, outValue, outValueLen, 0, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringValidationCode(
        const pd_ValidationCode_t *v,
        char *outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t *pageCount) {
    CLEAN_AND_CHECK()

    return parser_print_not_supported;
}

parser_error_t _toStringValidatorIndex(
        const pd_ValidatorIndex_t *v,
        char *outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t *pageCount) {
    CLEAN_AND_CHECK()

    return parser_print_not_supported;
}

parser_error_t _toStringValidatorPrefs(
        const pd_ValidatorPrefs_t *v,
        char *outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t *pageCount) {
    return _toStringCompactBalance(&v->balance, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringVestingInfo(
        const pd_VestingInfo_t *v,
        char *outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t *pageCount) {
  CLEAN_AND_CHECK()

  // Index + count pages
  uint8_t pages[3];
  CHECK_ERROR(_toStringBalanceOf(&v->locked, outValue, outValueLen, 0, &pages[0]))
  CHECK_ERROR(_toStringBalanceOf(&v->per_block, outValue, outValueLen, 0, &pages[1]))
  CHECK_ERROR(_toStringBlockNumber(&v->starting_block, outValue, outValueLen, 0, &pages[2]))

  *pageCount = pages[0] + pages[1] + pages[2];
  if (pageIdx > *pageCount) {
    return parser_display_idx_out_of_range;
  }

  if (pageIdx < pages[0]) {
    CHECK_ERROR(_toStringBalanceOf(&v->locked, outValue, outValueLen, pageIdx, &pages[0]))
    return parser_ok;
  }
  pageIdx -= pages[0];

  //////
  if (pageIdx < pages[1]) {
    CHECK_ERROR(_toStringBalanceOf(&v->per_block, outValue, outValueLen, pageIdx, &pages[1]))
    return parser_ok;
  }
  pageIdx -= pages[1];

  //////
  if (pageIdx < pages[2]) {
    CHECK_ERROR(_toStringBlockNumber(&v->starting_block, outValue, outValueLen, pageIdx, &pages[2]))
    return parser_ok;
  }

  return parser_display_idx_out_of_range;
}

parser_error_t _toStringVote(
        const pd_Vote_t *v,
        char *outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t *pageCount) {
    CLEAN_AND_CHECK()

    CHECK_PARSER_ERR(_toStringbool(&v->aye, outValue, outValueLen, pageIdx, pageCount));
    uint16_t offset = strlen(outValue);
    outValue[offset++] = ' ';
    CHECK_PARSER_ERR(_toStringConviction(&v->conviction,
                        outValue + offset,
                        outValueLen - offset,
                        pageIdx,
                        pageCount));
    *pageCount = 1;
    return parser_ok;
}

parser_error_t _toStringu8_array_20(
        const pd_u8_array_20_t *v,
        char *outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t *pageCount) {
    GEN_DEF_TOSTRING_ARRAY(20)
}

parser_error_t _toStringu8_array_32(
        const pd_u8_array_32_t *v,
        char *outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t *pageCount) {
    GEN_DEF_TOSTRING_ARRAY(32)
}

parser_error_t _toStringVecAccountId(
        const pd_VecAccountId_t *v,
        char *outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t *pageCount) {
    GEN_DEF_TOSTRING_VECTOR(AccountId);
}

parser_error_t _toStringVecAttestedCandidate(
        const pd_VecAttestedCandidate_t *v,
        char *outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t *pageCount) {
    GEN_DEF_TOSTRING_VECTOR(AttestedCandidate);
}

parser_error_t _toStringVecCall(
        const pd_VecCall_t *v,
        char *outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t *pageCount) {
    GEN_DEF_TOSTRING_VECTOR(Call);
}

parser_error_t _toStringVecHeader(
        const pd_VecHeader_t *v,
        char *outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t *pageCount) {
    GEN_DEF_TOSTRING_VECTOR(Header);
}

parser_error_t _toStringVecKeyValue(
        const pd_VecKeyValue_t *v,
        char *outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t *pageCount) {
    GEN_DEF_TOSTRING_VECTOR(KeyValue);
}

parser_error_t _toStringVecKey(
        const pd_VecKey_t *v,
        char *outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t *pageCount) {
    GEN_DEF_TOSTRING_VECTOR(Key);
}

parser_error_t _toStringVecLookupSource(
        const pd_VecLookupSource_t *v,
        char *outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t *pageCount) {
    GEN_DEF_TOSTRING_VECTOR(LookupSource);
}

parser_error_t _toStringVecTupleAccountIdData(
        const pd_VecTupleAccountIdData_t *v,
        char *outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t *pageCount) {
    GEN_DEF_TOSTRING_VECTOR(TupleAccountIdData);
}

parser_error_t _toStringVecTupleDataData(
        const pd_VecTupleDataData_t *v,
        char *outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t *pageCount) {
    GEN_DEF_TOSTRING_VECTOR(TupleDataData);
}

parser_error_t _toStringVecValidatorIndex(
        const pd_VecValidatorIndex_t *v,
        char *outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t *pageCount) {
    GEN_DEF_TOSTRING_VECTOR(ValidatorIndex);
}

parser_error_t _toStringVecu32(
        const pd_Vecu32_t *v,
        char *outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t *pageCount) {
    GEN_DEF_TOSTRING_VECTOR(u32);
}

parser_error_t _toStringOptionAccountId(
    const pd_OptionAccountId_t *v,
    char *outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t *pageCount) {
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringAccountId(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount
        ));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionChangesTrieConfiguration(
    const pd_OptionChangesTrieConfiguration_t *v,
    char *outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t *pageCount) {
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringChangesTrieConfiguration(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount
        ));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionPeriod(
    const pd_OptionPeriod_t *v,
    char *outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t *pageCount) {
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringPeriod(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount
        ));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionProxyType(
    const pd_OptionProxyType_t *v,
    char *outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t *pageCount) {
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringProxyType(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount
        ));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionStatementKind(
    const pd_OptionStatementKind_t *v,
    char *outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t *pageCount) {
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringStatementKind(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount
        ));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionTimepoint(
    const pd_OptionTimepoint_t *v,
    char *outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t *pageCount) {
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringTimepoint(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount
        ));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionTupleBalanceOfBalanceOfBlockNumber(
    const pd_OptionTupleBalanceOfBalanceOfBlockNumber_t *v,
    char *outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t *pageCount) {
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringTupleBalanceOfBalanceOfBlockNumber(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount
        ));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionu8_array_20(
    const pd_Optionu8_array_20_t *v,
    char *outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t *pageCount) {
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringu8_array_20(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount
        ));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}


///////////////////////////////////
///////////////////////////////////
///////////////////////////////////

parser_error_t _readbool(parser_context_t *c, pd_bool_t *v) {
    return _readUInt8(c, v);
}

parser_error_t _readu16(parser_context_t *c, pd_u16_t *v) {
    return _readUInt16(c, v);
}

parser_error_t _readu32(parser_context_t *c, pd_u32_t *v) {
    return _readUInt32(c, v);
}

parser_error_t _readu64(parser_context_t *c, pd_u64_t *v) {
    return _readUInt64(c, v);
}

parser_error_t _readBlockNumber(parser_context_t *c, pd_BlockNumber_t *v) {
    return _readUInt32(c, v);
}

parser_error_t _readCompactu32(parser_context_t *c, pd_Compactu32_t *v) {
    return _readCompactInt(c, v);
}

parser_error_t _readCompactu64(parser_context_t *c, pd_Compactu64_t *v) {
    return _readCompactInt(c, v);
}

parser_error_t _readCompactBalanceOf(parser_context_t *c, pd_CompactBalanceOf_t *v) {
    return _readCompactBalance(c, v);
}

parser_error_t _readKeys(parser_context_t *c, pd_Keys_t *v) {
    GEN_DEF_READARRAY(5 * 32);
}

///////////////////////////////////
///////////////////////////////////
///////////////////////////////////

parser_error_t _toStringbool(
        const pd_bool_t *v,
        char *outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t *pageCount) {
    CLEAN_AND_CHECK()

    *pageCount = 1;
    switch (*v) {
        case 0:
            snprintf(outValue, outValueLen, "False");
            return parser_ok;
        case 1:
            snprintf(outValue, outValueLen, "True");
            return parser_ok;
    }

    return parser_not_supported;
}

parser_error_t _toStringu16(
        const pd_u16_t *v,
        char *outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t *pageCount) {
    CLEAN_AND_CHECK()

    uint64_to_str(bufferUI, sizeof(bufferUI), *v);
    pageString(outValue, outValueLen, bufferUI, pageIdx, pageCount);
    return parser_ok;
}

parser_error_t _toStringu32(
        const pd_u32_t *v,
        char *outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t *pageCount) {
    CLEAN_AND_CHECK()

    uint64_to_str(bufferUI, sizeof(bufferUI), *v);
    pageString(outValue, outValueLen, bufferUI, pageIdx, pageCount);
    return parser_ok;
}

parser_error_t _toStringu64(
        const pd_u64_t *v,
        char *outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t *pageCount) {
    CLEAN_AND_CHECK()

    uint64_to_str(bufferUI, sizeof(bufferUI), *v);
    pageString(outValue, outValueLen, bufferUI, pageIdx, pageCount);
    return parser_ok;
}

parser_error_t _toStringBlockNumber(
        const pd_BlockNumber_t *v,
        char *outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t *pageCount) {
    return _toStringu32(v, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringCompactBalanceOf(
        const pd_CompactBalanceOf_t *v,
        char *outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t *pageCount) {
    return _toStringCompactBalance(v, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringCompactu32(
        const pd_Compactu32_t *v,
        char *outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t *pageCount) {
    return _toStringCompactInt(v, 0, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringKeys(
        const pd_Keys_t *v,
        char *outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t *pageCount) {
    GEN_DEF_TOSTRING_ARRAY(5 * 32);
}

///////////////////////////////////
///////////////////////////////////
///////////////////////////////////

parser_error_t _readProposal(parser_context_t *c, pd_Proposal_t *v) {
    CHECK_INPUT();
    uint16_t startOffset = c->offset;
    CHECK_ERROR(_readCallIndex(c, &v->callIndex))
    CHECK_ERROR(_readMethodBasic(c, v->callIndex.moduleIdx, v->callIndex.idx, &v->method))
    v->_ptr = c->buffer + startOffset;
    v->_len = c->offset - startOffset;
    return parser_ok;
}

parser_error_t _toStringProposal(
        const pd_Proposal_t *v,
        char *outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t *pageCount) {
    GEN_DEF_TOSTRING_ARRAY(v->_len);
}
