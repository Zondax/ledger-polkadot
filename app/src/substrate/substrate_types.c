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

#include "bignum.h"
#include "coin.h"
#include "parser_impl.h"

#include "substrate_dispatch.h"
#include <stddef.h>
#include <stdint.h>
#include <zxformat.h>
#include <zxmacros.h>

parser_error_t _readbool(parser_context_t* c, pd_bool_t* v)
{
    return _readUInt8(c, v);
}

parser_error_t _readu8(parser_context_t* c, pd_u8_t* v)
{
    return _readUInt8(c, v);
}

parser_error_t _readu16(parser_context_t* c, pd_u16_t* v)
{
    return _readUInt16(c, v);
}

parser_error_t _readu32(parser_context_t* c, pd_u32_t* v)
{
    return _readUInt32(c, v);
}

parser_error_t _readu64(parser_context_t* c, pd_u64_t* v)
{
    return _readUInt64(c, v);
}

parser_error_t _readBlockNumber(parser_context_t* c, pd_BlockNumber_t* v)
{
    return _readUInt32(c, v);
}

parser_error_t _readCompactu32(parser_context_t* c, pd_Compactu32_t* v)
{
    return _readCompactInt(c, v);
}

parser_error_t _readCompactu64(parser_context_t* c, pd_Compactu64_t* v)
{
    return _readCompactInt(c, v);
}

parser_error_t _readCallImpl(parser_context_t* c, pd_Call_t* v, pd_MethodNested_t* m)
{
    // If it's the first Call, store a pointer to it
    if (c->tx_obj->nestCallIdx._ptr == NULL) {
        c->tx_obj->nestCallIdx._ptr = c->buffer + c->offset;
        c->tx_obj->nestCallIdx._lenBuffer = c->bufferLen - c->offset;
    } else {
        // If _ptr is not null, and landed here, means we're inside a nested call.
        // We stored the pointer to the first Call and now we store
        // the pointer to the 'next' Call.
        if (c->tx_obj->nestCallIdx._nextPtr == NULL) {
            c->tx_obj->nestCallIdx._nextPtr = c->buffer + c->offset;
        }
    }

    // To keep track on how many nested Calls we have
    c->tx_obj->nestCallIdx.slotIdx++;
    if (c->tx_obj->nestCallIdx.slotIdx > MAX_CALL_NESTING_SIZE) {
        return parser_tx_nesting_limit_reached;
    }

    CHECK_ERROR(_readCallIndex(c, &v->callIndex));

    if (!_getMethod_IsNestingSupported(c->tx_obj->transactionVersion, v->callIndex.moduleIdx, v->callIndex.idx)) {
        return parser_tx_nesting_not_supported;
    }

    // Read and check the contained method on this Call
    CHECK_ERROR(_readMethod(c, v->callIndex.moduleIdx, v->callIndex.idx, (pd_Method_t*)m))

    // The instance of 'v' corresponding to the upper call on the stack (persisted variable)
    // will end up having the pointer to the first Call and to the 'next' one if exists.
    v->_txVerPtr = &c->tx_obj->transactionVersion;
    v->nestCallIdx._lenBuffer = c->tx_obj->nestCallIdx._lenBuffer;
    v->nestCallIdx._ptr = c->tx_obj->nestCallIdx._ptr;
    v->nestCallIdx._nextPtr = c->tx_obj->nestCallIdx._nextPtr;

    return parser_ok;
}

///////////////////////////////////
///////////////////////////////////
///////////////////////////////////
parser_error_t _readCompactu128(parser_context_t* c, pd_Compactu128_t* v)
{
    return _readCompactInt(c, v);
}

parser_error_t _readBytes(parser_context_t* c, pd_Bytes_t* v)
{
    CHECK_INPUT()

    compactInt_t clen;
    CHECK_ERROR(_readCompactInt(c, &clen))
    CHECK_ERROR(_getValue(&clen, &v->_len))

    v->_ptr = c->buffer + c->offset;
    CTX_CHECK_AND_ADVANCE(c, v->_len);
    return parser_ok;
}

parser_error_t _readFraction(parser_context_t* c, pd_Fraction_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readCompactu32(c, &v->nom))
    CHECK_ERROR(_readCompactu32(c, &v->denom))
    return parser_ok;
}

parser_error_t _readBodyId(parser_context_t* c, pd_BodyId_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // Unit
        break;
    case 1: // Named
        CHECK_ERROR(_readBytes(c, &v->named))
        break;
    case 2: // Index
        CHECK_ERROR(_readCompactu32(c, &v->index))
        break;
    case 3: // Executive
    case 4: // Technical
    case 5: // Legislative
    case 6: // Judicial
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _readBodyPart(parser_context_t* c, pd_BodyPart_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // Voice
        break;
    case 1: // Members
        CHECK_ERROR(_readCompactu32(c, &v->count))
        break;
    case 2: // Fraction
    case 3: // AtleastProportion
    case 4: // MoreThanProportion
        CHECK_ERROR(_readFraction(c, &v->fraction))
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _readNetworkId(parser_context_t* c, pd_NetworkId_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // Any
    case 2: // Polkadot
    case 3: // Kusama
        break;
    case 1: // Index
        CHECK_ERROR(_readBytes(c, &v->named))
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _readu8_array_20(parser_context_t* c, pd_u8_array_20_t* v) {
    GEN_DEF_READARRAY(20)
}

parser_error_t _readu8_array_32(parser_context_t* c, pd_u8_array_32_t* v) {
    GEN_DEF_READARRAY(32)
}

parser_error_t _readAccountId32(parser_context_t* c, pd_AccountId32_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readNetworkId(c, &v->networkId))
    CHECK_ERROR(_readu8_array_32(c, &v->key))
    return parser_ok;
}

parser_error_t _readAccountIndex64(parser_context_t* c, pd_AccountIndex64_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readNetworkId(c, &v->networkId))
    CHECK_ERROR(_readCompactu64(c, &v->index))
    return parser_ok;
}

parser_error_t _readAccountKey20(parser_context_t* c, pd_AccountKey20_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readNetworkId(c, &v->networkId))
    CHECK_ERROR(_readu8_array_20(c, &v->key))
    return parser_ok;
}

parser_error_t _readPlurality(parser_context_t* c, pd_Plurality_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readBodyId(c, &v->id))
    CHECK_ERROR(_readBodyPart(c, &v->part))
    return parser_ok;
}

parser_error_t _readJunctionV0(parser_context_t* c, pd_JunctionV0_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // Parent
        break;
    case 1: // Parachain
        CHECK_ERROR(_readCompactu32(c, &v->parachain))
        break;
    case 2: // AccountId32
        CHECK_ERROR(_readAccountId32(c, &v->accountId32))
        break;
    case 3: // AccountIndex64
        CHECK_ERROR(_readAccountIndex64(c, &v->accountIndex64))
        break;
    case 4: // AccountKey20
        CHECK_ERROR(_readAccountKey20(c, &v->accountKey20))
        break;
    case 5: // PalletInstance
        CHECK_ERROR(_readUInt8(c, &v->palletInstance))
        break;
    case 6: // GeneralIndex
        CHECK_ERROR(_readCompactu128(c, &v->generalIndex))
        break;
    case 7: // GeneralKey
        CHECK_ERROR(_readBytes(c, &v->generalKey))
        break;
    case 8: // OnlyChild
        break;
    case 9: // Plurality
        CHECK_ERROR(_readPlurality(c, &v->plurality))
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _readJunctionV1(parser_context_t* c, pd_JunctionV1_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // Parachain
        CHECK_ERROR(_readCompactu32(c, &v->parachain))
        break;
    case 1: // AccountId32
        CHECK_ERROR(_readAccountId32(c, &v->accountId32))
        break;
    case 2: // AccountIndex64
        CHECK_ERROR(_readAccountIndex64(c, &v->accountIndex64))
        break;
    case 3: // AccountKey20
        CHECK_ERROR(_readAccountKey20(c, &v->accountKey20))
        break;
    case 4: // PalletInstance
        CHECK_ERROR(_readUInt8(c, &v->palletInstance))
        break;
    case 5: // GeneralIndex
        CHECK_ERROR(_readCompactu128(c, &v->generalIndex))
        break;
    case 6: // GeneralKey
        CHECK_ERROR(_readBytes(c, &v->generalKey))
        break;
    case 7: // OnlyChild
        break;
    case 8: // Plurality
        CHECK_ERROR(_readPlurality(c, &v->plurality))
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _readJunctionV0X1(parser_context_t* c, pd_JunctionV0X1_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readJunctionV0(c, &v->junction))
    return parser_ok;
}

parser_error_t _readJunctionV0X2(parser_context_t* c, pd_JunctionV0X2_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readJunctionV0(c, &v->junction0))
    CHECK_ERROR(_readJunctionV0(c, &v->junction1))
    return parser_ok;
}

parser_error_t _readJunctionV0X3(parser_context_t* c, pd_JunctionV0X3_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readJunctionV0(c, &v->junction0))
    CHECK_ERROR(_readJunctionV0(c, &v->junction1))
    CHECK_ERROR(_readJunctionV0(c, &v->junction2))
    return parser_ok;
}

parser_error_t _readJunctionV0X4(parser_context_t* c, pd_JunctionV0X4_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readJunctionV0(c, &v->junction0))
    CHECK_ERROR(_readJunctionV0(c, &v->junction1))
    CHECK_ERROR(_readJunctionV0(c, &v->junction2))
    CHECK_ERROR(_readJunctionV0(c, &v->junction3))
    return parser_ok;
}

parser_error_t _readJunctionV0X5(parser_context_t* c, pd_JunctionV0X5_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readJunctionV0(c, &v->junction0))
    CHECK_ERROR(_readJunctionV0(c, &v->junction1))
    CHECK_ERROR(_readJunctionV0(c, &v->junction2))
    CHECK_ERROR(_readJunctionV0(c, &v->junction3))
    CHECK_ERROR(_readJunctionV0(c, &v->junction4))
    return parser_ok;
}

parser_error_t _readJunctionV0X6(parser_context_t* c, pd_JunctionV0X6_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readJunctionV0(c, &v->junction0))
    CHECK_ERROR(_readJunctionV0(c, &v->junction1))
    CHECK_ERROR(_readJunctionV0(c, &v->junction2))
    CHECK_ERROR(_readJunctionV0(c, &v->junction3))
    CHECK_ERROR(_readJunctionV0(c, &v->junction4))
    CHECK_ERROR(_readJunctionV0(c, &v->junction5))
    return parser_ok;
}

parser_error_t _readJunctionV0X7(parser_context_t* c, pd_JunctionV0X7_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readJunctionV0(c, &v->junction0))
    CHECK_ERROR(_readJunctionV0(c, &v->junction1))
    CHECK_ERROR(_readJunctionV0(c, &v->junction2))
    CHECK_ERROR(_readJunctionV0(c, &v->junction3))
    CHECK_ERROR(_readJunctionV0(c, &v->junction4))
    CHECK_ERROR(_readJunctionV0(c, &v->junction5))
    CHECK_ERROR(_readJunctionV0(c, &v->junction6))
    return parser_ok;
}

parser_error_t _readJunctionV0X8(parser_context_t* c, pd_JunctionV0X8_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readJunctionV0(c, &v->junction0))
    CHECK_ERROR(_readJunctionV0(c, &v->junction1))
    CHECK_ERROR(_readJunctionV0(c, &v->junction2))
    CHECK_ERROR(_readJunctionV0(c, &v->junction3))
    CHECK_ERROR(_readJunctionV0(c, &v->junction4))
    CHECK_ERROR(_readJunctionV0(c, &v->junction5))
    CHECK_ERROR(_readJunctionV0(c, &v->junction6))
    CHECK_ERROR(_readJunctionV0(c, &v->junction7))
    return parser_ok;
}

parser_error_t _readJunctionV1X1(parser_context_t* c, pd_JunctionV1X1_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readJunctionV1(c, &v->junction))
    return parser_ok;
}

parser_error_t _readJunctionV1X2(parser_context_t* c, pd_JunctionV1X2_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readJunctionV1(c, &v->junction0))
    CHECK_ERROR(_readJunctionV1(c, &v->junction1))
    return parser_ok;
}

parser_error_t _readJunctionV1X3(parser_context_t* c, pd_JunctionV1X3_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readJunctionV1(c, &v->junction0))
    CHECK_ERROR(_readJunctionV1(c, &v->junction1))
    CHECK_ERROR(_readJunctionV1(c, &v->junction2))
    return parser_ok;
}

parser_error_t _readJunctionV1X4(parser_context_t* c, pd_JunctionV1X4_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readJunctionV1(c, &v->junction0))
    CHECK_ERROR(_readJunctionV1(c, &v->junction1))
    CHECK_ERROR(_readJunctionV1(c, &v->junction2))
    CHECK_ERROR(_readJunctionV1(c, &v->junction3))
    return parser_ok;
}

parser_error_t _readJunctionV1X5(parser_context_t* c, pd_JunctionV1X5_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readJunctionV1(c, &v->junction0))
    CHECK_ERROR(_readJunctionV1(c, &v->junction1))
    CHECK_ERROR(_readJunctionV1(c, &v->junction2))
    CHECK_ERROR(_readJunctionV1(c, &v->junction3))
    CHECK_ERROR(_readJunctionV1(c, &v->junction4))
    return parser_ok;
}

parser_error_t _readJunctionV1X6(parser_context_t* c, pd_JunctionV1X6_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readJunctionV1(c, &v->junction0))
    CHECK_ERROR(_readJunctionV1(c, &v->junction1))
    CHECK_ERROR(_readJunctionV1(c, &v->junction2))
    CHECK_ERROR(_readJunctionV1(c, &v->junction3))
    CHECK_ERROR(_readJunctionV1(c, &v->junction4))
    CHECK_ERROR(_readJunctionV1(c, &v->junction5))
    return parser_ok;
}

parser_error_t _readJunctionV1X7(parser_context_t* c, pd_JunctionV1X7_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readJunctionV1(c, &v->junction0))
    CHECK_ERROR(_readJunctionV1(c, &v->junction1))
    CHECK_ERROR(_readJunctionV1(c, &v->junction2))
    CHECK_ERROR(_readJunctionV1(c, &v->junction3))
    CHECK_ERROR(_readJunctionV1(c, &v->junction4))
    CHECK_ERROR(_readJunctionV1(c, &v->junction5))
    CHECK_ERROR(_readJunctionV1(c, &v->junction6))
    return parser_ok;
}

parser_error_t _readJunctionV1X8(parser_context_t* c, pd_JunctionV1X8_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readJunctionV1(c, &v->junction0))
    CHECK_ERROR(_readJunctionV1(c, &v->junction1))
    CHECK_ERROR(_readJunctionV1(c, &v->junction2))
    CHECK_ERROR(_readJunctionV1(c, &v->junction3))
    CHECK_ERROR(_readJunctionV1(c, &v->junction4))
    CHECK_ERROR(_readJunctionV1(c, &v->junction5))
    CHECK_ERROR(_readJunctionV1(c, &v->junction6))
    CHECK_ERROR(_readJunctionV1(c, &v->junction7))
    return parser_ok;
}

parser_error_t _readJunctionsV0(parser_context_t* c, pd_JunctionsV0_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // Null
        break;
    case 1: // X1
        CHECK_ERROR(_readJunctionV0X1(c, &v->x1))
        break;
    case 2: // X2
        CHECK_ERROR(_readJunctionV0X2(c, &v->x2))
        break;
    case 3: // X3
        CHECK_ERROR(_readJunctionV0X3(c, &v->x3))
        break;
    case 4: // X4
        CHECK_ERROR(_readJunctionV0X4(c, &v->x4))
        break;
    case 5: // X5
        CHECK_ERROR(_readJunctionV0X5(c, &v->x5))
        break;
    case 6: // X6
        CHECK_ERROR(_readJunctionV0X6(c, &v->x6))
        break;
    case 7: // X7
        CHECK_ERROR(_readJunctionV0X7(c, &v->x7))
        break;
    case 8: // X8
        CHECK_ERROR(_readJunctionV0X8(c, &v->x8))
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _readJunctionsV1(parser_context_t* c, pd_JunctionsV1_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // Here
        break;
    case 1: // X1
        CHECK_ERROR(_readJunctionV1X1(c, &v->x1))
        break;
    case 2: // X2
        CHECK_ERROR(_readJunctionV1X2(c, &v->x2))
        break;
    case 3: // X3
        CHECK_ERROR(_readJunctionV1X3(c, &v->x3))
        break;
    case 4: // X4
        CHECK_ERROR(_readJunctionV1X4(c, &v->x4))
        break;
    case 5: // X5
        CHECK_ERROR(_readJunctionV1X5(c, &v->x5))
        break;
    case 6: // X6
        CHECK_ERROR(_readJunctionV1X6(c, &v->x6))
        break;
    case 7: // X7
        CHECK_ERROR(_readJunctionV1X7(c, &v->x7))
        break;
    case 8: // X8
        CHECK_ERROR(_readJunctionV1X8(c, &v->x8))
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _readAssetInstance(parser_context_t* c, pd_AssetInstance_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // Undefined
        // Empty
        break;
    case 1: // Index
        CHECK_ERROR(_readCompactu128(c, &v->index))
        break;
    case 2: // array4
        GEN_DEF_READARRAY(4)
        break;
    case 3: // array8
        GEN_DEF_READARRAY(8)
        break;
    case 4: // array16
        GEN_DEF_READARRAY(16)
        break;
    case 5: // array32
        GEN_DEF_READARRAY(32)
        break;
    case 6: // blob
        CHECK_ERROR(_readBytes(c, &v->blob))
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _readMultiLocationV0(parser_context_t* c, pd_MultiLocationV0_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readJunctionsV0(c, &v->junctions))
    return parser_ok;
}

parser_error_t _readMultiLocationV1(parser_context_t* c, pd_MultiLocationV1_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->parents))
    CHECK_ERROR(_readJunctionsV1(c, &v->interior))
    return parser_ok;
}

parser_error_t _readAbstractFungible(parser_context_t* c, pd_AbstractFungible_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readBytes(c, &v->id))
    CHECK_ERROR(_readCompactu128(c, &v->amount))
    return parser_ok;
}

parser_error_t _readAbstractNonFungible(parser_context_t* c, pd_AbstractNonFungible_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readBytes(c, &v->_class))
    CHECK_ERROR(_readAssetInstance(c, &v->instance))
    return parser_ok;
}

parser_error_t _readBalance(parser_context_t* c, pd_Balance_t* v) {
    GEN_DEF_READARRAY(16)
}

parser_error_t _readConcreteFungible(parser_context_t* c, pd_ConcreteFungible_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readMultiLocationV0(c, &v->id))
    CHECK_ERROR(_readCompactBalance(c, &v->amount))
    return parser_ok;
}

parser_error_t _readConcreteNonFungible(parser_context_t* c, pd_ConcreteNonFungible_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readMultiLocationV0(c, &v->_class))
    CHECK_ERROR(_readAssetInstance(c, &v->instance))
    return parser_ok;
}

parser_error_t _readData(parser_context_t* c, pd_Data_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    if (v->value <= 1) {
        return parser_ok;
    } else if (v->value <= 37) {
        const uint8_t length = v->value <= 32 ? v->value - 1 : 32;
        GEN_DEF_READARRAY(length)
    } else {
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _readFungibility(parser_context_t* c, pd_Fungibility_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // Undefined
        CHECK_ERROR(_readCompactu128(c, &v->fungible))
        break;
    case 1: // Index
        CHECK_ERROR(_readAssetInstance(c, &v->nonFungible))
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _readMultiAssetId(parser_context_t* c, pd_MultiAssetId_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // Concrete
        CHECK_ERROR(_readMultiLocationV1(c, &v->concrete))
        break;
    case 1: // Abstract
        CHECK_ERROR(_readBytes(c, &v->abstract))
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _readAccountId(parser_context_t* c, pd_AccountId_t* v) {
    GEN_DEF_READARRAY(32)
}

parser_error_t _readBalanceOf(parser_context_t* c, pd_BalanceOf_t* v)
{
    return _readBalance(c, &v->value);
}

parser_error_t _readCompactAccountIndex(parser_context_t* c, pd_CompactAccountIndex_t* v)
{
    return _readCompactInt(c, &v->value);
}

parser_error_t _readEcdsaPublic(parser_context_t* c, pd_EcdsaPublic_t* v) {
    GEN_DEF_READARRAY(33)
}

parser_error_t _readEcdsaSignature(parser_context_t* c, pd_EcdsaSignature_t* v) {
    GEN_DEF_READARRAY(65)
}

parser_error_t _readEd25519Public(parser_context_t* c, pd_Ed25519Public_t* v) {
    GEN_DEF_READARRAY(32)
}

parser_error_t _readEd25519Signature(parser_context_t* c, pd_Ed25519Signature_t* v) {
    GEN_DEF_READARRAY(64)
}

parser_error_t _readH256(parser_context_t* c, pd_H256_t* v) {
    GEN_DEF_READARRAY(32)
}

parser_error_t _readMultiAssetV0(parser_context_t* c, pd_MultiAssetV0_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // None
    case 1: // All
    case 2: // AllFungible
    case 3: // AllNonFungible
        break;
    case 4: // AllAbstractFungible
    case 5: // AllAbstractNonFungible
        CHECK_ERROR(_readBytes(c, &v->abstract))
        break;
    case 6: // AllConcreteFungible
    case 7: // AllConcreteNonFungible
        CHECK_ERROR(_readMultiLocationV0(c, &v->concrete))
        break;
    case 8: // AbstractFungible
        CHECK_ERROR(_readAbstractFungible(c, &v->abstractFungible))
        break;
    case 9: // AbstractNonFungible
        CHECK_ERROR(_readAbstractNonFungible(c, &v->abstractNonFungible))
        break;
    case 10: // ConcreteFungible
        CHECK_ERROR(_readConcreteFungible(c, &v->concreteFungible))
        break;
    case 11: // ConcreteNonFungible
        CHECK_ERROR(_readConcreteNonFungible(c, &v->concreteNonFungible))
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _readMultiAssetV1(parser_context_t* c, pd_MultiAssetV1_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readMultiAssetId(c, &v->assetId))
    CHECK_ERROR(_readFungibility(c, &v->fungibility))
    return parser_ok;
}

parser_error_t _readSr25519Public(parser_context_t* c, pd_Sr25519Public_t* v) {
    GEN_DEF_READARRAY(32)
}

parser_error_t _readSr25519Signature(parser_context_t* c, pd_Sr25519Signature_t* v) {
    GEN_DEF_READARRAY(64)
}

parser_error_t _readTupleDataData(parser_context_t* c, pd_TupleDataData_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readData(c, &v->data1))
    CHECK_ERROR(_readData(c, &v->data2))
    return parser_ok;
}

parser_error_t _readVote(parser_context_t* c, pd_Vote_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    const uint8_t aye = v->value & 0xF0;
    const uint8_t conviction = v->value & 0x0F;
    if ((aye == 0x80 || aye == 0x00) && conviction <= 0x06) {
        return parser_ok;
    }
    return parser_value_out_of_range;
}

parser_error_t _readAccountIdLookupOfT(parser_context_t* c, pd_AccountIdLookupOfT_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // Id
        CHECK_ERROR(_readAccountId(c, &v->id))
        break;
    case 1: // Index
        CHECK_ERROR(_readCompactAccountIndex(c, &v->index))
        break;
    case 2: // Raw
        CHECK_ERROR(_readBytes(c, &v->raw))
        break;
    case 3: // Address32
        GEN_DEF_READARRAY(32)
        break;
    case 4: // Address20
        GEN_DEF_READARRAY(20)
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _readAccountVoteSplit(parser_context_t* c, pd_AccountVoteSplit_t* v)
{
    CHECK_ERROR(_readBalanceOf(c, &v->aye));
    CHECK_ERROR(_readBalanceOf(c, &v->nay));
    return parser_ok;
}

parser_error_t _readAccountVoteStandard(parser_context_t* c, pd_AccountVoteStandard_t* v)
{
    CHECK_ERROR(_readVote(c, &v->vote));
    CHECK_ERROR(_readBalanceOf(c, &v->balance));
    return parser_ok;
}

parser_error_t _readCall(parser_context_t* c, pd_Call_t* v)
{
    pd_MethodNested_t _method;
    if (c->tx_obj->nestCallIdx.isTail) {
        c->tx_obj->nestCallIdx.isTail = false;
        v->nestCallIdx.isTail = true;
    } else {
        v->nestCallIdx.isTail = false;
    }

    CHECK_ERROR(_readCallImpl(c, v, &_method))
    if (c->tx_obj->nestCallIdx._ptr != NULL && c->tx_obj->nestCallIdx._nextPtr != NULL) {
        v->nestCallIdx._ptr = c->tx_obj->nestCallIdx._ptr;
        v->nestCallIdx._nextPtr = c->tx_obj->nestCallIdx._nextPtr;
    }
    v->nestCallIdx.slotIdx = c->tx_obj->nestCallIdx.slotIdx;
    return parser_ok;
}

parser_error_t _readCompactPerBill(parser_context_t* c, pd_CompactPerBill_t* v)
{
    return _readCompactInt(c, &v->value);
}

parser_error_t _readMultiSignature(parser_context_t* c, pd_MultiSignature_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // Ed25519
        CHECK_ERROR(_readEd25519Signature(c, &v->ed25519))
        break;
    case 1: // Sr25519
        CHECK_ERROR(_readSr25519Signature(c, &v->sr25519))
        break;
    case 2: // Ecdsa
        CHECK_ERROR(_readEcdsaSignature(c, &v->ecdsa))
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _readMultiSigner(parser_context_t* c, pd_MultiSigner_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // Ed25519
        CHECK_ERROR(_readEd25519Public(c, &v->ed25519))
        break;
    case 1: // Sr25519
        CHECK_ERROR(_readSr25519Public(c, &v->sr25519))
        break;
    case 2: // Ecdsa
        CHECK_ERROR(_readEcdsaPublic(c, &v->ecdsa))
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _readPerbill(parser_context_t* c, pd_Perbill_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readPercent(parser_context_t* c, pd_Percent_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    return parser_ok;
}

parser_error_t _readProxyType(parser_context_t* c, pd_ProxyType_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->value))
    if (v->value == 4 || v->value > 7) {
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _readReferendumIndex(parser_context_t* c, pd_ReferendumIndex_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readTimepoint(parser_context_t* c, pd_Timepoint_t* v)
{
    CHECK_ERROR(_readBlockNumber(c, &v->height))
    CHECK_ERROR(_readu32(c, &v->index))
    return parser_ok;
}

parser_error_t _readTupleAccountIdData(parser_context_t* c, pd_TupleAccountIdData_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readAccountId(c, &v->id));
    CHECK_ERROR(_readData(c, &v->data));
    return parser_ok;
}

parser_error_t _readTupleH256u32(parser_context_t* c, pd_TupleH256u32_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readH256(c, &v->h256))
    CHECK_ERROR(_readUInt32(c, &v->u32))
    return parser_ok;
}

parser_error_t _readAccountVote(parser_context_t* c, pd_AccountVote_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))

    switch (v->value) {
    case 0:
        CHECK_ERROR(_readAccountVoteStandard(c, &v->voteStandard))
        break;
    case 1:
        CHECK_ERROR(_readAccountVoteSplit(c, &v->voteSplit))
        break;
    default:
        break;
    }

    return parser_ok;
}

parser_error_t _readBondExtraBalanceOfT(parser_context_t* c, pd_BondExtraBalanceOfT_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0:
        CHECK_ERROR(_readBalance(c, &v->freeBalance))
        break;
    case 1: // Rewards
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _readBoundedCallOfT(parser_context_t* c, pd_BoundedCallOfT_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0:
        CHECK_ERROR(_readH256(c, &v->legacy))
        break;
    case 1:
        CHECK_ERROR(_readBytes(c, &v->_inline))
        break;
    case 2:
        CHECK_ERROR(_readTupleH256u32(c, &v->lookup))
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _readBoxVersionedMultiAssets(parser_context_t* c, pd_BoxVersionedMultiAssets_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // V0
        CHECK_ERROR(_readVecMultiAssetV0(c, &v->vecMultiassetV0))
        break;
    case 1: // V1
        CHECK_ERROR(_readVecMultiAssetV1(c, &v->vecMultiassetV1))
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _readBoxVersionedMultiLocation(parser_context_t* c, pd_BoxVersionedMultiLocation_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // V0
        CHECK_ERROR(_readMultiLocationV0(c, &v->multilocationV0))
        break;
    case 1: // V1
        CHECK_ERROR(_readMultiLocationV1(c, &v->multilocationV1))
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _readConfigOpAccountId(parser_context_t* c, pd_ConfigOpAccountId_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // Noop
    case 2: // Remove
        break;
    case 1:
        CHECK_ERROR(_readAccountId(c, &v->set))
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _readConfigOpBalanceOfT(parser_context_t* c, pd_ConfigOpBalanceOfT_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // Noop
    case 2: // Remove
        break;
    case 1:
        CHECK_ERROR(_readBalance(c, &v->set))
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _readConfigOpPerbill(parser_context_t* c, pd_ConfigOpPerbill_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // Noop
    case 2: // Remove
        break;
    case 1:
        CHECK_ERROR(_readPerbill(c, &v->set))
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _readConfigOpPercent(parser_context_t* c, pd_ConfigOpPercent_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // Noop
    case 2: // Remove
        break;
    case 1:
        CHECK_ERROR(_readPercent(c, &v->set))
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _readIdentityInfo(parser_context_t* c, pd_IdentityInfo_t* v)
{
    CHECK_INPUT()
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

parser_error_t _readJudgementBalanceOfT(parser_context_t* c, pd_JudgementBalanceOfT_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // Unknown
    case 2: // Reasonable
    case 3: // KnownGood
    case 4: // OutOfDate
    case 5: // LowQuality
    case 6: // Erroneous
        break;
    case 1: // FeePaid
        CHECK_ERROR(_readBalance(c, &v->feePaid))
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _readOptionMultiSigner(parser_context_t* c, pd_OptionMultiSigner_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readMultiSigner(c, &v->verifier))
    }
    return parser_ok;
}

parser_error_t _readProposal(parser_context_t* c, pd_Proposal_t* v)
{
    return _readCall(c, &v->call);
}

parser_error_t _readRewardDestination(parser_context_t* c, pd_RewardDestination_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))

    if (v->value == 3) {
        CHECK_ERROR(_readAccountId(c, &v->accountId))
    } else if (v->value > 4) {
        return parser_value_out_of_range;
    }
    return parser_ok;
}

parser_error_t _readValidatorPrefs(parser_context_t* c, pd_ValidatorPrefs_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readCompactPerBill(c, &v->commission));
    CHECK_ERROR(_readbool(c, &v->blocked))
    return parser_ok;
}

parser_error_t _readVecCall(parser_context_t* c, pd_VecCall_t* v)
{
    compactInt_t clen;
    pd_Call_t dummy;
    CHECK_PARSER_ERR(_readCompactInt(c, &clen));
    CHECK_PARSER_ERR(_getValue(&clen, &v->_len));

    if (v->_len > MAX_CALL_VEC_SIZE) {
        return parser_tx_call_vec_too_large;
    }

    v->_ptr = c->buffer + c->offset;
    v->_lenBuffer = c->offset;
    if (v->_len == 0) {
        return parser_unexpected_buffer_end;
    }

    for (uint64_t i = 0; i < v->_len; i++) {
        c->tx_obj->nestCallIdx.slotIdx = 0;
        CHECK_ERROR(_readCall(c, &dummy))
    }
    v->_lenBuffer = c->offset - v->_lenBuffer;
    v->callTxVersion = c->tx_obj->transactionVersion;

    return parser_ok;
}

parser_error_t _readVestingInfo(parser_context_t* c, pd_VestingInfo_t* v)
{
    CHECK_ERROR(_readBalanceOf(c, &v->locked))
    CHECK_ERROR(_readBalanceOf(c, &v->per_block))
    CHECK_ERROR(_readBlockNumber(c, &v->starting_block))
    return parser_ok;
}

parser_error_t _readWeightLimit(parser_context_t* c, pd_WeightLimit_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // Unlimited
        break;
    case 1: // Limited
        CHECK_ERROR(_readCompactu64(c, &v->limited))
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _readWeight(parser_context_t* c, pd_Weight_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readCompactu64(c, &v->refTime))
    CHECK_ERROR(_readCompactu64(c, &v->proofSize))
    return parser_ok;
}

parser_error_t _readAccountIndex(parser_context_t* c, pd_AccountIndex_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readConfigOpu32(parser_context_t* c, pd_ConfigOpu32_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // Noop
    case 2: // Remove
        break;
    case 1:
        CHECK_ERROR(_readUInt32(c, &v->set))
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _readConviction(parser_context_t* c, pd_Conviction_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    if (v->value > 5) {
        return parser_value_out_of_range;
    }
    return parser_ok;
}

parser_error_t _readEraIndex(parser_context_t* c, pd_EraIndex_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readEthereumAddress(parser_context_t* c, pd_EthereumAddress_t* v) {
    GEN_DEF_READARRAY(20)
}

parser_error_t _readHash(parser_context_t* c, pd_Hash_t* v) {
    GEN_DEF_READARRAY(32)
}

parser_error_t _readKeys(parser_context_t* c, pd_Keys_t* v) {
    GEN_DEF_READARRAY(6 * 32)
}

parser_error_t _readMemberCount(parser_context_t* c, pd_MemberCount_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readOverweightIndex(parser_context_t* c, pd_OverweightIndex_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt64(c, &v->value))
    return parser_ok;
}

parser_error_t _readParaId(parser_context_t* c, pd_ParaId_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readPoolId(parser_context_t* c, pd_PoolId_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readPoolState(parser_context_t* c, pd_PoolState_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    return parser_ok;
}

parser_error_t _readRegistrarIndex(parser_context_t* c, pd_RegistrarIndex_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readSessionIndex(parser_context_t* c, pd_SessionIndex_t* v)
{
    return _readUInt32(c, &v->value);
}

parser_error_t _readVecMultiAssetV0(parser_context_t* c, pd_VecMultiAssetV0_t* v) {
    GEN_DEF_READVECTOR(MultiAssetV0)
}

parser_error_t _readVecMultiAssetV1(parser_context_t* c, pd_VecMultiAssetV1_t* v) {
    GEN_DEF_READVECTOR(MultiAssetV1)
}

parser_error_t _readVecTupleDataData(parser_context_t* c, pd_VecTupleDataData_t* v) {
    GEN_DEF_READVECTOR(TupleDataData)
}

parser_error_t _readVecAccountIdLookupOfT(parser_context_t* c, pd_VecAccountIdLookupOfT_t* v) {
    GEN_DEF_READVECTOR(AccountIdLookupOfT)
}

parser_error_t _readVecTupleAccountIdData(parser_context_t* c, pd_VecTupleAccountIdData_t* v) {
    GEN_DEF_READVECTOR(TupleAccountIdData)
}

parser_error_t _readVecAccountId(parser_context_t* c, pd_VecAccountId_t* v) {
    GEN_DEF_READVECTOR(AccountId)
}

parser_error_t _readVecu32(parser_context_t* c, pd_Vecu32_t* v) {
    GEN_DEF_READVECTOR(u32)
}

parser_error_t _readVecu8(parser_context_t* c, pd_Vecu8_t* v) {
    GEN_DEF_READVECTOR(u8)
}

parser_error_t _readOptionu8_array_20(parser_context_t* c, pd_Optionu8_array_20_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readu8_array_20(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionMultiSignature(parser_context_t* c, pd_OptionMultiSignature_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readMultiSignature(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionTimepoint(parser_context_t* c, pd_OptionTimepoint_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readTimepoint(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionAccountId(parser_context_t* c, pd_OptionAccountId_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readAccountId(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionProxyType(parser_context_t* c, pd_OptionProxyType_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readProxyType(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionReferendumIndex(parser_context_t* c, pd_OptionReferendumIndex_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readReferendumIndex(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionu32(parser_context_t* c, pd_Optionu32_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readu32(c, &v->contained))
    }
    return parser_ok;
}

///////////////////////////////////
///////////////////////////////////
///////////////////////////////////

parser_error_t _toStringbool(
    const pd_bool_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
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

parser_error_t _toStringu8(
    const pd_u8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    char bufferUI[50];

    uint64_to_str(bufferUI, sizeof(bufferUI), *v);
    pageString(outValue, outValueLen, bufferUI, pageIdx, pageCount);
    return parser_ok;
}

parser_error_t _toStringu16(
    const pd_u16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    char bufferUI[50];

    uint64_to_str(bufferUI, sizeof(bufferUI), *v);
    pageString(outValue, outValueLen, bufferUI, pageIdx, pageCount);
    return parser_ok;
}

parser_error_t _toStringu32(
    const pd_u32_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    char bufferUI[100];

    uint64_to_str(bufferUI, sizeof(bufferUI), *v);
    pageString(outValue, outValueLen, bufferUI, pageIdx, pageCount);
    return parser_ok;
}

parser_error_t _toStringu64(
    const pd_u64_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    char bufferUI[100];

    uint64_to_str(bufferUI, sizeof(bufferUI), *v);
    pageString(outValue, outValueLen, bufferUI, pageIdx, pageCount);
    return parser_ok;
}

parser_error_t _toStringBlockNumber(
    const pd_BlockNumber_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(v, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringCompactu32(
    const pd_Compactu32_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringCompactInt(v, 0, false, "", "", outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringCompactu64(
    const pd_Compactu64_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringCompactInt(v, 0, false, "", "", outValue, outValueLen, pageIdx, pageCount);
}

///////////////////////////////////
///////////////////////////////////
///////////////////////////////////

parser_error_t _toStringCompactu128(
    const pd_Compactu128_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringCompactInt(v, 0, false, "", "", outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringBytes(
    const pd_Bytes_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_ARRAY(v->_len);
}

parser_error_t _toStringFraction(
    const pd_Fraction_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringCompactu32(&v->nom, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringCompactu32(&v->denom, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringCompactu32(&v->nom, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringCompactu32(&v->denom, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringBodyId(
    const pd_BodyId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    *pageCount = 1;
    switch (v->value) {
    case 0: // Unit
        snprintf(outValue, outValueLen, "Unit");
        break;
    case 1: // Named
        CHECK_ERROR(_toStringBytes(&v->named, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 2: // Index
        CHECK_ERROR(_toStringCompactu32(&v->index, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 3: // Executive
        snprintf(outValue, outValueLen, "Executive");
        break;
    case 4: // Technical
        snprintf(outValue, outValueLen, "Technical");
        break;
    case 5: // Legislative
        snprintf(outValue, outValueLen, "Legislative");
        break;
    case 6: // Judicial
        snprintf(outValue, outValueLen, "Judicial");
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _toStringBodyPart(
    const pd_BodyPart_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    *pageCount = 1;
    switch (v->value) {
    case 0: // Voice
        snprintf(outValue, outValueLen, "Voice");
        break;
    case 1: // Members
        CHECK_ERROR(_toStringCompactu32(&v->count, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 2: // Fraction
        CHECK_ERROR(_toStringFraction(&v->fraction, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 3: // AtLeastProportion
        CHECK_ERROR(_toStringFraction(&v->fraction, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 4: // MoreThanProportion
        CHECK_ERROR(_toStringFraction(&v->fraction, outValue, outValueLen, pageIdx, pageCount))
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _toStringNetworkId(
    const pd_NetworkId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    *pageCount = 1;
    switch (v->value) {
    case 0: // Any
        snprintf(outValue, outValueLen, "Any");
        break;
    case 1: // Named
        CHECK_ERROR(_toStringBytes(&v->named, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 2: // Polkadot
        snprintf(outValue, outValueLen, "Polkadot");
        break;
    case 3: // Kusama
        snprintf(outValue, outValueLen, "Kusama");
        break;
    default:
        return parser_not_supported;
    }

    return parser_ok;
}

parser_error_t _toStringu8_array_20(
    const pd_u8_array_20_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount) {
    GEN_DEF_TOSTRING_ARRAY(20)
}

parser_error_t _toStringu8_array_32(
    const pd_u8_array_32_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount) {
    GEN_DEF_TOSTRING_ARRAY(32)
}

parser_error_t _toStringAccountId32(
    const pd_AccountId32_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringNetworkId(&v->networkId, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringu8_array_32(&v->key, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringNetworkId(&v->networkId, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringu8_array_32(&v->key, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringAccountIndex64(
    const pd_AccountIndex64_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringNetworkId(&v->networkId, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringCompactu64(&v->index, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringNetworkId(&v->networkId, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringCompactu64(&v->index, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringAccountKey20(
    const pd_AccountKey20_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringNetworkId(&v->networkId, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringu8_array_20(&v->key, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringNetworkId(&v->networkId, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringu8_array_20(&v->key, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringPlurality(
    const pd_Plurality_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringBodyId(&v->id, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringBodyPart(&v->part, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringBodyId(&v->id, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringBodyPart(&v->part, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringJunctionV0(
    const pd_JunctionV0_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    *pageCount = 1;
    switch (v->value) {
    case 0: // Parent
        snprintf(outValue, outValueLen, "Parent");
        break;
    case 1: // Parachain
        CHECK_ERROR(_toStringCompactu32(&v->parachain, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 2: // AccountId32
        CHECK_ERROR(_toStringAccountId32(&v->accountId32, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 3: // AccountIndex64
        CHECK_ERROR(_toStringAccountIndex64(&v->accountIndex64, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 4: // AccountKey20
        CHECK_ERROR(_toStringAccountKey20(&v->accountKey20, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 5: // PalletInstance
        CHECK_ERROR(_toStringu8(&v->palletInstance, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 6: // GeneralIndex
        CHECK_ERROR(_toStringCompactu128(&v->generalIndex, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 7: // GeneralKey
        CHECK_ERROR(_toStringBytes(&v->generalKey, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 8: // OnlyChild
        snprintf(outValue, outValueLen, "OnlyChild");
        break;
    case 9: // Plurality
        CHECK_ERROR(_toStringPlurality(&v->plurality, outValue, outValueLen, pageIdx, pageCount))
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _toStringJunctionV1(
    const pd_JunctionV1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    *pageCount = 1;
    switch (v->value) {
    case 0: // Parachain
        CHECK_ERROR(_toStringCompactu32(&v->parachain, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 1: // AccountId32
        CHECK_ERROR(_toStringAccountId32(&v->accountId32, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 2: // AccountIndex64
        CHECK_ERROR(_toStringAccountIndex64(&v->accountIndex64, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 3: // AccountKey20
        CHECK_ERROR(_toStringAccountKey20(&v->accountKey20, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 4: // PalletInstance
        CHECK_ERROR(_toStringu8(&v->palletInstance, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 5: // GeneralIndex
        CHECK_ERROR(_toStringCompactu128(&v->generalIndex, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 6: // GeneralKey
        CHECK_ERROR(_toStringBytes(&v->generalKey, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 7: // OnlyChild
        snprintf(outValue, outValueLen, "OnlyChild");
        break;
    case 8: // Plurality
        CHECK_ERROR(_toStringPlurality(&v->plurality, outValue, outValueLen, pageIdx, pageCount))
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _toStringJunctionV0X1(
    const pd_JunctionV0X1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[1] = { 0 };
    CHECK_ERROR(_toStringJunctionV0(&v->junction, outValue, outValueLen, 0, &pages[0]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringJunctionV0(&v->junction, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringJunctionV0X2(
    const pd_JunctionV0X2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringJunctionV0(&v->junction0, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringJunctionV0(&v->junction1, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringJunctionV0(&v->junction0, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringJunctionV0(&v->junction1, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringJunctionV0X3(
    const pd_JunctionV0X3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[3] = { 0 };
    CHECK_ERROR(_toStringJunctionV0(&v->junction0, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringJunctionV0(&v->junction1, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringJunctionV0(&v->junction2, outValue, outValueLen, 0, &pages[2]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringJunctionV0(&v->junction0, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringJunctionV0(&v->junction1, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringJunctionV0(&v->junction2, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringJunctionV0X4(
    const pd_JunctionV0X4_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[4] = { 0 };
    CHECK_ERROR(_toStringJunctionV0(&v->junction0, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringJunctionV0(&v->junction1, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringJunctionV0(&v->junction2, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringJunctionV0(&v->junction3, outValue, outValueLen, 0, &pages[3]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringJunctionV0(&v->junction0, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringJunctionV0(&v->junction1, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringJunctionV0(&v->junction2, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }
    pageIdx -= pages[2];

    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringJunctionV0(&v->junction3, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringJunctionV0X5(
    const pd_JunctionV0X5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[5] = { 0 };
    CHECK_ERROR(_toStringJunctionV0(&v->junction0, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringJunctionV0(&v->junction1, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringJunctionV0(&v->junction2, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringJunctionV0(&v->junction3, outValue, outValueLen, 0, &pages[3]))
    CHECK_ERROR(_toStringJunctionV0(&v->junction4, outValue, outValueLen, 0, &pages[4]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringJunctionV0(&v->junction0, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringJunctionV0(&v->junction1, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringJunctionV0(&v->junction2, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }
    pageIdx -= pages[2];

    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringJunctionV0(&v->junction3, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }
    pageIdx -= pages[3];

    if (pageIdx < pages[4]) {
        CHECK_ERROR(_toStringJunctionV0(&v->junction4, outValue, outValueLen, pageIdx, &pages[4]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringJunctionV0X6(
    const pd_JunctionV0X6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[6] = { 0 };
    CHECK_ERROR(_toStringJunctionV0(&v->junction0, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringJunctionV0(&v->junction1, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringJunctionV0(&v->junction2, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringJunctionV0(&v->junction3, outValue, outValueLen, 0, &pages[3]))
    CHECK_ERROR(_toStringJunctionV0(&v->junction4, outValue, outValueLen, 0, &pages[4]))
    CHECK_ERROR(_toStringJunctionV0(&v->junction5, outValue, outValueLen, 0, &pages[5]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringJunctionV0(&v->junction0, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringJunctionV0(&v->junction1, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringJunctionV0(&v->junction2, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }
    pageIdx -= pages[2];

    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringJunctionV0(&v->junction3, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }
    pageIdx -= pages[3];

    if (pageIdx < pages[4]) {
        CHECK_ERROR(_toStringJunctionV0(&v->junction4, outValue, outValueLen, pageIdx, &pages[4]))
        return parser_ok;
    }
    pageIdx -= pages[4];

    if (pageIdx < pages[5]) {
        CHECK_ERROR(_toStringJunctionV0(&v->junction5, outValue, outValueLen, pageIdx, &pages[5]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringJunctionV0X7(
    const pd_JunctionV0X7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[7] = { 0 };
    CHECK_ERROR(_toStringJunctionV0(&v->junction0, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringJunctionV0(&v->junction1, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringJunctionV0(&v->junction2, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringJunctionV0(&v->junction3, outValue, outValueLen, 0, &pages[3]))
    CHECK_ERROR(_toStringJunctionV0(&v->junction4, outValue, outValueLen, 0, &pages[4]))
    CHECK_ERROR(_toStringJunctionV0(&v->junction5, outValue, outValueLen, 0, &pages[5]))
    CHECK_ERROR(_toStringJunctionV0(&v->junction6, outValue, outValueLen, 0, &pages[6]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringJunctionV0(&v->junction0, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringJunctionV0(&v->junction1, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringJunctionV0(&v->junction2, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }
    pageIdx -= pages[2];

    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringJunctionV0(&v->junction3, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }
    pageIdx -= pages[3];

    if (pageIdx < pages[4]) {
        CHECK_ERROR(_toStringJunctionV0(&v->junction4, outValue, outValueLen, pageIdx, &pages[4]))
        return parser_ok;
    }
    pageIdx -= pages[4];

    if (pageIdx < pages[5]) {
        CHECK_ERROR(_toStringJunctionV0(&v->junction5, outValue, outValueLen, pageIdx, &pages[5]))
        return parser_ok;
    }
    pageIdx -= pages[5];

    if (pageIdx < pages[6]) {
        CHECK_ERROR(_toStringJunctionV0(&v->junction6, outValue, outValueLen, pageIdx, &pages[6]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringJunctionV0X8(
    const pd_JunctionV0X8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[8] = { 0 };
    CHECK_ERROR(_toStringJunctionV0(&v->junction0, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringJunctionV0(&v->junction1, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringJunctionV0(&v->junction2, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringJunctionV0(&v->junction3, outValue, outValueLen, 0, &pages[3]))
    CHECK_ERROR(_toStringJunctionV0(&v->junction4, outValue, outValueLen, 0, &pages[4]))
    CHECK_ERROR(_toStringJunctionV0(&v->junction5, outValue, outValueLen, 0, &pages[5]))
    CHECK_ERROR(_toStringJunctionV0(&v->junction6, outValue, outValueLen, 0, &pages[6]))
    CHECK_ERROR(_toStringJunctionV0(&v->junction7, outValue, outValueLen, 0, &pages[7]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringJunctionV0(&v->junction0, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringJunctionV0(&v->junction1, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringJunctionV0(&v->junction2, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }
    pageIdx -= pages[2];

    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringJunctionV0(&v->junction3, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }
    pageIdx -= pages[3];

    if (pageIdx < pages[4]) {
        CHECK_ERROR(_toStringJunctionV0(&v->junction4, outValue, outValueLen, pageIdx, &pages[4]))
        return parser_ok;
    }
    pageIdx -= pages[4];

    if (pageIdx < pages[5]) {
        CHECK_ERROR(_toStringJunctionV0(&v->junction5, outValue, outValueLen, pageIdx, &pages[5]))
        return parser_ok;
    }
    pageIdx -= pages[5];

    if (pageIdx < pages[6]) {
        CHECK_ERROR(_toStringJunctionV0(&v->junction6, outValue, outValueLen, pageIdx, &pages[6]))
        return parser_ok;
    }
    pageIdx -= pages[6];

    if (pageIdx < pages[7]) {
        CHECK_ERROR(_toStringJunctionV0(&v->junction7, outValue, outValueLen, pageIdx, &pages[7]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringJunctionV1X1(
    const pd_JunctionV1X1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[1] = { 0 };
    CHECK_ERROR(_toStringJunctionV1(&v->junction, outValue, outValueLen, 0, &pages[0]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringJunctionV1(&v->junction, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringJunctionV1X2(
    const pd_JunctionV1X2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringJunctionV1(&v->junction0, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringJunctionV1(&v->junction1, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringJunctionV1(&v->junction0, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringJunctionV1(&v->junction1, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringJunctionV1X3(
    const pd_JunctionV1X3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[3] = { 0 };
    CHECK_ERROR(_toStringJunctionV1(&v->junction0, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringJunctionV1(&v->junction1, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringJunctionV1(&v->junction2, outValue, outValueLen, 0, &pages[2]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringJunctionV1(&v->junction0, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringJunctionV1(&v->junction1, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringJunctionV1(&v->junction2, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringJunctionV1X4(
    const pd_JunctionV1X4_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[4] = { 0 };
    CHECK_ERROR(_toStringJunctionV1(&v->junction0, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringJunctionV1(&v->junction1, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringJunctionV1(&v->junction2, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringJunctionV1(&v->junction3, outValue, outValueLen, 0, &pages[3]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringJunctionV1(&v->junction0, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringJunctionV1(&v->junction1, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringJunctionV1(&v->junction2, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }
    pageIdx -= pages[2];

    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringJunctionV1(&v->junction3, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringJunctionV1X5(
    const pd_JunctionV1X5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[5] = { 0 };
    CHECK_ERROR(_toStringJunctionV1(&v->junction0, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringJunctionV1(&v->junction1, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringJunctionV1(&v->junction2, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringJunctionV1(&v->junction3, outValue, outValueLen, 0, &pages[3]))
    CHECK_ERROR(_toStringJunctionV1(&v->junction4, outValue, outValueLen, 0, &pages[4]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringJunctionV1(&v->junction0, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringJunctionV1(&v->junction1, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringJunctionV1(&v->junction2, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }
    pageIdx -= pages[2];

    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringJunctionV1(&v->junction3, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }
    pageIdx -= pages[3];

    if (pageIdx < pages[4]) {
        CHECK_ERROR(_toStringJunctionV1(&v->junction4, outValue, outValueLen, pageIdx, &pages[4]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringJunctionV1X6(
    const pd_JunctionV1X6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[6] = { 0 };
    CHECK_ERROR(_toStringJunctionV1(&v->junction0, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringJunctionV1(&v->junction1, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringJunctionV1(&v->junction2, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringJunctionV1(&v->junction3, outValue, outValueLen, 0, &pages[3]))
    CHECK_ERROR(_toStringJunctionV1(&v->junction4, outValue, outValueLen, 0, &pages[4]))
    CHECK_ERROR(_toStringJunctionV1(&v->junction5, outValue, outValueLen, 0, &pages[5]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringJunctionV1(&v->junction0, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringJunctionV1(&v->junction1, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringJunctionV1(&v->junction2, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }
    pageIdx -= pages[2];

    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringJunctionV1(&v->junction3, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }
    pageIdx -= pages[3];

    if (pageIdx < pages[4]) {
        CHECK_ERROR(_toStringJunctionV1(&v->junction4, outValue, outValueLen, pageIdx, &pages[4]))
        return parser_ok;
    }
    pageIdx -= pages[4];

    if (pageIdx < pages[5]) {
        CHECK_ERROR(_toStringJunctionV1(&v->junction5, outValue, outValueLen, pageIdx, &pages[5]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringJunctionV1X7(
    const pd_JunctionV1X7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[7] = { 0 };
    CHECK_ERROR(_toStringJunctionV1(&v->junction0, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringJunctionV1(&v->junction1, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringJunctionV1(&v->junction2, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringJunctionV1(&v->junction3, outValue, outValueLen, 0, &pages[3]))
    CHECK_ERROR(_toStringJunctionV1(&v->junction4, outValue, outValueLen, 0, &pages[4]))
    CHECK_ERROR(_toStringJunctionV1(&v->junction5, outValue, outValueLen, 0, &pages[5]))
    CHECK_ERROR(_toStringJunctionV1(&v->junction6, outValue, outValueLen, 0, &pages[6]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringJunctionV1(&v->junction0, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringJunctionV1(&v->junction1, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringJunctionV1(&v->junction2, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }
    pageIdx -= pages[2];

    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringJunctionV1(&v->junction3, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }
    pageIdx -= pages[3];

    if (pageIdx < pages[4]) {
        CHECK_ERROR(_toStringJunctionV1(&v->junction4, outValue, outValueLen, pageIdx, &pages[4]))
        return parser_ok;
    }
    pageIdx -= pages[4];

    if (pageIdx < pages[5]) {
        CHECK_ERROR(_toStringJunctionV1(&v->junction5, outValue, outValueLen, pageIdx, &pages[5]))
        return parser_ok;
    }
    pageIdx -= pages[5];

    if (pageIdx < pages[6]) {
        CHECK_ERROR(_toStringJunctionV1(&v->junction6, outValue, outValueLen, pageIdx, &pages[6]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringJunctionV1X8(
    const pd_JunctionV1X8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[8] = { 0 };
    CHECK_ERROR(_toStringJunctionV1(&v->junction0, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringJunctionV1(&v->junction1, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringJunctionV1(&v->junction2, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringJunctionV1(&v->junction3, outValue, outValueLen, 0, &pages[3]))
    CHECK_ERROR(_toStringJunctionV1(&v->junction4, outValue, outValueLen, 0, &pages[4]))
    CHECK_ERROR(_toStringJunctionV1(&v->junction5, outValue, outValueLen, 0, &pages[5]))
    CHECK_ERROR(_toStringJunctionV1(&v->junction6, outValue, outValueLen, 0, &pages[6]))
    CHECK_ERROR(_toStringJunctionV1(&v->junction7, outValue, outValueLen, 0, &pages[7]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringJunctionV1(&v->junction0, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringJunctionV1(&v->junction1, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringJunctionV1(&v->junction2, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }
    pageIdx -= pages[2];

    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringJunctionV1(&v->junction3, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }
    pageIdx -= pages[3];

    if (pageIdx < pages[4]) {
        CHECK_ERROR(_toStringJunctionV1(&v->junction4, outValue, outValueLen, pageIdx, &pages[4]))
        return parser_ok;
    }
    pageIdx -= pages[4];

    if (pageIdx < pages[5]) {
        CHECK_ERROR(_toStringJunctionV1(&v->junction5, outValue, outValueLen, pageIdx, &pages[5]))
        return parser_ok;
    }
    pageIdx -= pages[5];

    if (pageIdx < pages[6]) {
        CHECK_ERROR(_toStringJunctionV1(&v->junction6, outValue, outValueLen, pageIdx, &pages[6]))
        return parser_ok;
    }
    pageIdx -= pages[6];

    if (pageIdx < pages[7]) {
        CHECK_ERROR(_toStringJunctionV1(&v->junction7, outValue, outValueLen, pageIdx, &pages[7]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringJunctionsV0(
    const pd_JunctionsV0_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    switch (v->value) {
    case 0: // Null
        *pageCount = 1;
        snprintf(outValue, outValueLen, "Null");
        break;
    case 1: // X1
        CHECK_ERROR(_toStringJunctionV0X1(&v->x1, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 2: // X2
        CHECK_ERROR(_toStringJunctionV0X2(&v->x2, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 3: // X3
        CHECK_ERROR(_toStringJunctionV0X3(&v->x3, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 4: // X4
        CHECK_ERROR(_toStringJunctionV0X4(&v->x4, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 5: // X5
        CHECK_ERROR(_toStringJunctionV0X5(&v->x5, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 6: // X6
        CHECK_ERROR(_toStringJunctionV0X6(&v->x6, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 7: // X7
        CHECK_ERROR(_toStringJunctionV0X7(&v->x7, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 8: // X8
        CHECK_ERROR(_toStringJunctionV0X8(&v->x8, outValue, outValueLen, pageIdx, pageCount))
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _toStringJunctionsV1(
    const pd_JunctionsV1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    switch (v->value) {
    case 0: // Here
        *pageCount = 1;
        snprintf(outValue, outValueLen, "Here");
        break;
    case 1: // X1
        CHECK_ERROR(_toStringJunctionV1X1(&v->x1, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 2: // X2
        CHECK_ERROR(_toStringJunctionV1X2(&v->x2, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 3: // X3
        CHECK_ERROR(_toStringJunctionV1X3(&v->x3, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 4: // X4
        CHECK_ERROR(_toStringJunctionV1X4(&v->x4, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 5: // X5
        CHECK_ERROR(_toStringJunctionV1X5(&v->x5, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 6: // X6
        CHECK_ERROR(_toStringJunctionV1X6(&v->x6, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 7: // X7
        CHECK_ERROR(_toStringJunctionV1X7(&v->x7, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 8: // X8
        CHECK_ERROR(_toStringJunctionV1X8(&v->x8, outValue, outValueLen, pageIdx, pageCount))
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _toStringAssetInstance(
    const pd_AssetInstance_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    switch (v->value) {
    case 0: // Undefined
        *pageCount = 1;
        snprintf(outValue, outValueLen, "Undefined");
        break;
    case 1: // Index
        CHECK_ERROR(_toStringCompactu128(&v->index, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 2: // Array4
    {
        GEN_DEF_TOSTRING_ARRAY(4)
    }
    case 3: // Array8
    {
        GEN_DEF_TOSTRING_ARRAY(8)
    }
    case 4: // Array16
    {
        GEN_DEF_TOSTRING_ARRAY(16)
    }
    case 5: // Array32
    {
        GEN_DEF_TOSTRING_ARRAY(32)
    }
    case 6: // Blob
    {
        CHECK_ERROR(_toStringBytes(&v->blob, outValue, outValueLen, pageIdx, pageCount))
        break;
    }
    default:
        return parser_not_supported;
    }

    return parser_ok;
}

parser_error_t _toStringMultiLocationV0(
    const pd_MultiLocationV0_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    CHECK_ERROR(_toStringJunctionsV0(&v->junctions, outValue, outValueLen, pageIdx, pageCount))
    return parser_ok;
}

parser_error_t _toStringMultiLocationV1(
    const pd_MultiLocationV1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringu8(&v->parents, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringJunctionsV1(&v->interior, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringu8(&v->parents, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringJunctionsV1(&v->interior, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringAbstractFungible(
    const pd_AbstractFungible_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringBytes(&v->id, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringCompactu128(&v->amount, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringBytes(&v->id, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringCompactu128(&v->amount, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringAbstractNonFungible(
    const pd_AbstractNonFungible_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringBytes(&v->_class, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringAssetInstance(&v->instance, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringBytes(&v->_class, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringAssetInstance(&v->instance, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringBalance(
    const pd_Balance_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    char bufferUI[200];
    memset(outValue, 0, outValueLen);
    memset(bufferUI, 0, sizeof(bufferUI));
    *pageCount = 1;

    uint8_t bcdOut[100];
    const uint16_t bcdOutLen = sizeof(bcdOut);

    bignumLittleEndian_to_bcd(bcdOut, bcdOutLen, v->_ptr, 16);
    if (!bignumLittleEndian_bcdprint(bufferUI, sizeof(bufferUI), bcdOut, bcdOutLen)) {
        return parser_unexpected_buffer_end;
    }

    // Format number
    if (intstr_to_fpstr_inplace(bufferUI, sizeof(bufferUI), COIN_AMOUNT_DECIMAL_PLACES) == 0) {
        return parser_unexpected_value;
    }

    number_inplace_trimming(bufferUI, 1);
    number_inplace_trimming(bufferUI, 1);
    if (z_str3join(bufferUI, sizeof(bufferUI), COIN_TICKER, "") != zxerr_ok) {
        return parser_print_not_supported;
    }

    pageString(outValue, outValueLen, bufferUI, pageIdx, pageCount);
    return parser_ok;
}

parser_error_t _toStringConcreteFungible(
    const pd_ConcreteFungible_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringMultiLocationV0(&v->id, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringCompactBalance(&v->amount, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringMultiLocationV0(&v->id, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringCompactBalance(&v->amount, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringConcreteNonFungible(
    const pd_ConcreteNonFungible_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringMultiLocationV0(&v->_class, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringAssetInstance(&v->instance, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringMultiLocationV0(&v->_class, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringAssetInstance(&v->instance, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringData(
    const pd_Data_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    *pageCount = 1;
    if (v->value == 0) {
        snprintf(outValue, outValueLen, "None");
        return parser_ok;
    } else if (v->value == 1) {
        snprintf(outValue, outValueLen, "Empty raw");
        return parser_ok;
    } else if (v->value > 37) {
        return parser_unexpected_value;
    }
    const uint8_t length = v->value <= 32 ? v->value - 1 : 32;
    bool allPrintable = true;
    if (v->value <= 33) {
        for (uint8_t i = 0; i < length; i++) {
            allPrintable &= IS_PRINTABLE(v->_ptr[i]);
        }
    }
    if (v->value <= 33 && allPrintable) {
        char bufferUI[40] = { 0 };
        snprintf(bufferUI, length + 1, "%s", v->_ptr); // it counts null terminator
        pageString(outValue, outValueLen, (const char*)bufferUI, pageIdx, pageCount);
    } else {
        GEN_DEF_TOSTRING_ARRAY(length)
    }
    return parser_ok;
}

parser_error_t _toStringFungibility(
    const pd_Fungibility_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    switch (v->value) {
    case 0: // Undefined
        CHECK_ERROR(_toStringCompactu128(&v->fungible, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 1: // Index
        CHECK_ERROR(_toStringAssetInstance(&v->nonFungible, outValue, outValueLen, pageIdx, pageCount))
        break;
    default:
        return parser_not_supported;
    }

    return parser_ok;
}

parser_error_t _toStringMultiAssetId(
    const pd_MultiAssetId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    switch (v->value) {
    case 0: // Concrete
        CHECK_ERROR(_toStringMultiLocationV1(&v->concrete, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 1: // Abstract
        CHECK_ERROR(_toStringBytes(&v->abstract, outValue, outValueLen, pageIdx, pageCount))
        break;
    default:
        return parser_not_supported;
    }

    return parser_ok;
}

parser_error_t _toStringAccountId(
    const pd_AccountId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringPubkeyAsAddress(v->_ptr, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringBalanceOf(
    const pd_BalanceOf_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringBalance(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringCompactAccountIndex(
    const pd_CompactAccountIndex_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringCompactInt(&v->value, 0, false, "", "", outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringEcdsaPublic(
    const pd_EcdsaPublic_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount) {
    GEN_DEF_TOSTRING_ARRAY(33)
}

parser_error_t _toStringEcdsaSignature(
    const pd_EcdsaSignature_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount) {
    GEN_DEF_TOSTRING_ARRAY(65)
}

parser_error_t _toStringEd25519Public(
    const pd_Ed25519Public_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount) {
    GEN_DEF_TOSTRING_ARRAY(32)
}

parser_error_t _toStringEd25519Signature(
    const pd_Ed25519Signature_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount) {
    GEN_DEF_TOSTRING_ARRAY(64)
}

parser_error_t _toStringH256(
    const pd_H256_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_ARRAY(32);
}

parser_error_t _toStringMultiAssetV0(
    const pd_MultiAssetV0_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    *pageCount = 1;
    switch (v->value) {
    case 0: // None
        snprintf(outValue, outValueLen, "None");
        break;
    case 1: // All
        snprintf(outValue, outValueLen, "All");
        break;
    case 2: // AllFungible
        snprintf(outValue, outValueLen, "AllFungible");
        break;
    case 3: // AllNonFungible
        snprintf(outValue, outValueLen, "AllNonFungible");
        break;
    case 4: // AllAbstractFungible
    case 5: // AllAbstractNonFungible
        CHECK_ERROR(_toStringBytes(&v->abstract, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 6: // AllConcreteFungible
    case 7: // AllConcreteNonFungible
        CHECK_ERROR(_toStringMultiLocationV0(&v->concrete, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 8: // AbstractFungible
        CHECK_ERROR(_toStringAbstractFungible(&v->abstractFungible, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 9: // AbstractNonFungible
        CHECK_ERROR(_toStringAbstractNonFungible(&v->abstractNonFungible, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 10: // ConcreteFungible
        CHECK_ERROR(_toStringConcreteFungible(&v->concreteFungible, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 11: // ConcreteNonFungible
        CHECK_ERROR(_toStringConcreteNonFungible(&v->concreteNonFungible, outValue, outValueLen, pageIdx, pageCount))
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _toStringMultiAssetV1(
    const pd_MultiAssetV1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringMultiAssetId(&v->assetId, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringFungibility(&v->fungibility, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringMultiAssetId(&v->assetId, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringFungibility(&v->fungibility, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringSr25519Public(
    const pd_Sr25519Public_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount) {
    GEN_DEF_TOSTRING_ARRAY(32)
}

parser_error_t _toStringSr25519Signature(
    const pd_Sr25519Signature_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount) {
    GEN_DEF_TOSTRING_ARRAY(64)
}

parser_error_t _toStringTupleDataData(
    const pd_TupleDataData_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringData(&v->data1, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringData(&v->data2, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringData(&v->data1, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringData(&v->data2, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringVote(
    const pd_Vote_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    *pageCount = 1;
    const uint8_t conviction = v->value & 0x0F;

    switch (v->value & 0xF0) {
    case 0x80:
        snprintf(outValue, outValueLen, "Aye - ");
        break;
    case 0x00:
        snprintf(outValue, outValueLen, "Nay - ");
        break;
    default:
        return parser_unexpected_value;
    }

    switch (conviction) {
    case 0:
        snprintf(outValue + 6, outValueLen - 6, "None");
        break;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
        snprintf(outValue + 6, outValueLen - 6, "Locked%dx", conviction);
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _toStringAccountIdLookupOfT(
    const pd_AccountIdLookupOfT_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    switch (v->value) {
    case 0: // Id
        CHECK_ERROR(_toStringAccountId(&v->id, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 1: // Index
        CHECK_ERROR(_toStringCompactAccountIndex(&v->index, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 2: // Raw
        CHECK_ERROR(_toStringBytes(&v->raw, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 3: // Address32
    {
        GEN_DEF_TOSTRING_ARRAY(32)
    }
    case 4: // Address20
    {
        GEN_DEF_TOSTRING_ARRAY(20)
    }
    default:
        return parser_not_supported;
    }

    return parser_ok;
}

parser_error_t _toStringAccountVoteSplit(
    const pd_AccountVoteSplit_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    // First measure number of pages
    uint8_t pages[3];

    pages[0] = 1;
    CHECK_ERROR(_toStringBalanceOf(&v->aye, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringBalanceOf(&v->nay, outValue, outValueLen, 0, &pages[2]));

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
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
        CHECK_ERROR(_toStringBalanceOf(&v->aye, outValue, outValueLen, pageIdx, &pages[1]));
        return parser_ok;
    }
    pageIdx -= pages[1];

    /////////
    /////////

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringBalanceOf(&v->nay, outValue, outValueLen, pageIdx, &pages[2]));
        return parser_ok;
    }

    /////////
    /////////

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringAccountVoteStandard(
    const pd_AccountVoteStandard_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    // First measure number of pages
    uint8_t pages[3];

    pages[0] = 1;
    CHECK_ERROR(_toStringVote(&v->vote, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringBalanceOf(&v->balance, outValue, outValueLen, 0, &pages[2]));

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
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

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringVote(&v->vote, outValue, outValueLen, pageIdx, &pages[1]));
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringBalanceOf(&v->balance, outValue, outValueLen, pageIdx, &pages[2]));
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringCall(
    const pd_Call_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    *pageCount = 1;

    parser_context_t ctx;

    const uint8_t* buffer;
    if (v->nestCallIdx.isTail) {
        buffer = v->nestCallIdx._ptr;
    } else {
        buffer = v->nestCallIdx._nextPtr;
    }

    parser_init(&ctx, buffer, v->nestCallIdx._lenBuffer);
    parser_tx_t _txObj;

    pd_Call_t _call;
    _call.nestCallIdx.isTail = false;

    ctx.tx_obj = &_txObj;
    _txObj.transactionVersion = *v->_txVerPtr;

    ctx.tx_obj->nestCallIdx._ptr = NULL;
    ctx.tx_obj->nestCallIdx._nextPtr = NULL;
    ctx.tx_obj->nestCallIdx._lenBuffer = 0;
    ctx.tx_obj->nestCallIdx.slotIdx = 0;
    ctx.tx_obj->nestCallIdx.isTail = false;

    // Read the Call, so we get the contained Method
    parser_error_t err = _readCallImpl(&ctx, &_call, (pd_MethodNested_t*)&_txObj.method);
    if (err != parser_ok) {
        return err;
    }

    // Get num items of this current Call
    uint8_t callNumItems = _getMethod_NumItems(*v->_txVerPtr, v->callIndex.moduleIdx, v->callIndex.idx);

    // Count how many pages this call has (including nested ones if they exists)
    for (uint8_t i = 0; i < callNumItems; i++) {
        uint8_t itemPages = 0;
        _getMethod_ItemValue(*v->_txVerPtr, &_txObj.method, _call.callIndex.moduleIdx, _call.callIndex.idx, i,
            outValue, outValueLen, 0, &itemPages);
        (*pageCount) += itemPages;
    }

    if (pageIdx == 0) {
        snprintf(outValue, outValueLen, "%s", _getMethod_Name(*v->_txVerPtr, v->callIndex.moduleIdx, v->callIndex.idx));
        return parser_ok;
    }

    pageIdx--;

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    for (uint8_t i = 0; i < callNumItems; i++) {
        uint8_t itemPages = 0;
        _getMethod_ItemValue(*v->_txVerPtr, &_txObj.method, v->callIndex.moduleIdx, v->callIndex.idx, i,
            outValue, outValueLen, 0, &itemPages);

        if (pageIdx < itemPages) {
            uint8_t tmp;
            _getMethod_ItemValue(*v->_txVerPtr, &_txObj.method, v->callIndex.moduleIdx, v->callIndex.idx, i,
                outValue, outValueLen, pageIdx, &tmp);
            return parser_ok;
        }

        pageIdx -= itemPages;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringCompactPerBill(
    const pd_CompactPerBill_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    // 9 but shift 2 to show as percentage
    return _toStringCompactInt(&v->value, 7, false, "%", "", outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringMultiSignature(
    const pd_MultiSignature_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    switch (v->value) {
    case 0: // Ed25519
        CHECK_ERROR(_toStringEd25519Signature(&v->ed25519, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 1: // Sr25519
        CHECK_ERROR(_toStringSr25519Signature(&v->sr25519, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 2: // Ecdsa
        CHECK_ERROR(_toStringEcdsaSignature(&v->ecdsa, outValue, outValueLen, pageIdx, pageCount))
        break;
    default:
        return parser_not_supported;
    }

    return parser_ok;
}

parser_error_t _toStringMultiSigner(
    const pd_MultiSigner_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    switch (v->value) {
    case 0: // Ed25519
        CHECK_ERROR(_toStringEd25519Public(&v->ed25519, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 1: // Sr25519
        CHECK_ERROR(_toStringSr25519Public(&v->sr25519, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 2: // Ecdsa
        CHECK_ERROR(_toStringEcdsaPublic(&v->ecdsa, outValue, outValueLen, pageIdx, pageCount))
        break;
    default:
        return parser_not_supported;
    }

    return parser_ok;
}

parser_error_t _toStringPerbill(
    const pd_Perbill_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    char bufferUI[100];
    char ratioBuffer[80];
    memset(outValue, 0, outValueLen);
    memset(ratioBuffer, 0, sizeof(ratioBuffer));
    memset(bufferUI, 0, sizeof(bufferUI));
    *pageCount = 1;

    if (fpuint64_to_str(ratioBuffer, sizeof(ratioBuffer), v->value, 7) == 0) {
        return parser_unexpected_value;
    }

    snprintf(bufferUI, sizeof(bufferUI), "%s%%", ratioBuffer);
    pageString(outValue, outValueLen, bufferUI, pageIdx, pageCount);
    return parser_ok;
}

parser_error_t _toStringPercent(
    const pd_Percent_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    char bufferUI[50];
    char bufferRatio[50];

    uint64_to_str(bufferRatio, sizeof(bufferRatio), v->value);

    snprintf(bufferUI, sizeof(bufferUI), "%s%%", bufferRatio);
    pageString(outValue, outValueLen, bufferUI, pageIdx, pageCount);
    return parser_ok;
}

parser_error_t _toStringProxyType(
    const pd_ProxyType_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    switch (v->value) {
    case 0:
        snprintf(outValue, outValueLen, "Any");
        break;
    case 1:
        snprintf(outValue, outValueLen, "NonTransfer");
        break;
    case 2:
        snprintf(outValue, outValueLen, "Governance");
        break;
    case 3:
        snprintf(outValue, outValueLen, "Staking");
        break;
    case 5:
        snprintf(outValue, outValueLen, "IdentityJudgement");
        break;
    case 6:
        snprintf(outValue, outValueLen, "CancelProxy");
        break;
    case 7:
        snprintf(outValue, outValueLen, "Auction");
        break;
    default:
        return parser_print_not_supported;
    }

    return parser_ok;
}

parser_error_t _toStringReferendumIndex(
    const pd_ReferendumIndex_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringTimepoint(
    const pd_Timepoint_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringBlockNumber(&v->height, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringu32(&v->index, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringBlockNumber(&v->height, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringu32(&v->index, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringTupleAccountIdData(
    const pd_TupleAccountIdData_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringAccountId(&v->id, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringData(&v->data, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringAccountId(&v->id, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringData(&v->data, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringTupleH256u32(
    const pd_TupleH256u32_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringH256(&v->h256, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringu32(&v->u32, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringH256(&v->h256, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringu32(&v->u32, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringAccountVote(
    const pd_AccountVote_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    switch (v->value) {
    case 0:
        CHECK_ERROR(_toStringAccountVoteStandard(&v->voteStandard, outValue, outValueLen, pageIdx, pageCount));
        break;
    case 1:
        CHECK_ERROR(_toStringAccountVoteSplit(&v->voteSplit, outValue, outValueLen, pageIdx, pageCount));
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _toStringBondExtraBalanceOfT(
    const pd_BondExtraBalanceOfT_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    *pageCount = 1;
    switch (v->value) {
    case 0:
        CHECK_ERROR(_toStringBalance(&v->freeBalance, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 1:
        snprintf(outValue, outValueLen, "Rewards");
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _toStringBoundedCallOfT(
    const pd_BoundedCallOfT_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    switch (v->value) {
    case 0:
        CHECK_ERROR(_toStringH256(&v->legacy, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 1:
        CHECK_ERROR(_toStringBytes(&v->_inline, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 2:
        CHECK_ERROR(_toStringTupleH256u32(&v->lookup, outValue, outValueLen, pageIdx, pageCount))
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _toStringBoxVersionedMultiAssets(
    const pd_BoxVersionedMultiAssets_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    switch (v->value) {
    case 0: // V0
        CHECK_ERROR(_toStringVecMultiAssetV0(&v->vecMultiassetV0, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 1: // V1
        CHECK_ERROR(_toStringVecMultiAssetV1(&v->vecMultiassetV1, outValue, outValueLen, pageIdx, pageCount))
        break;
    default:
        return parser_not_supported;
    }

    return parser_ok;
}

parser_error_t _toStringBoxVersionedMultiLocation(
    const pd_BoxVersionedMultiLocation_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    switch (v->value) {
    case 0: // V0
        CHECK_ERROR(_toStringMultiLocationV0(&v->multilocationV0, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 1: // V1
        CHECK_ERROR(_toStringMultiLocationV1(&v->multilocationV1, outValue, outValueLen, pageIdx, pageCount))
        break;
    default:
        return parser_not_supported;
    }

    return parser_ok;
}

parser_error_t _toStringConfigOpAccountId(
    const pd_ConfigOpAccountId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    *pageCount = 1;
    switch (v->value) {
    case 0:
        snprintf(outValue, outValueLen, "Noop");
        break;
    case 1:
        CHECK_ERROR(_toStringAccountId(&v->set, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 2:
        snprintf(outValue, outValueLen, "Remove");
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _toStringConfigOpBalanceOfT(
    const pd_ConfigOpBalanceOfT_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    *pageCount = 1;
    switch (v->value) {
    case 0:
        snprintf(outValue, outValueLen, "Noop");
        break;
    case 1:
        CHECK_ERROR(_toStringBalance(&v->set, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 2:
        snprintf(outValue, outValueLen, "Remove");
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _toStringConfigOpPerbill(
    const pd_ConfigOpPerbill_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    *pageCount = 1;
    switch (v->value) {
    case 0:
        snprintf(outValue, outValueLen, "Noop");
        break;
    case 1:
        CHECK_ERROR(_toStringPerbill(&v->set, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 2:
        snprintf(outValue, outValueLen, "Remove");
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _toStringConfigOpPercent(
    const pd_ConfigOpPercent_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    *pageCount = 1;
    switch (v->value) {
    case 0:
        snprintf(outValue, outValueLen, "Noop");
        break;
    case 1:
        CHECK_ERROR(_toStringPercent(&v->set, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 2:
        snprintf(outValue, outValueLen, "Remove");
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _toStringIdentityInfo(
    const pd_IdentityInfo_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[9] = { 0 };
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
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringVecTupleDataData(&v->additional, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringData(&v->display, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringData(&v->legal, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }
    pageIdx -= pages[2];

    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringData(&v->web, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }
    pageIdx -= pages[3];

    if (pageIdx < pages[4]) {
        CHECK_ERROR(_toStringData(&v->riot, outValue, outValueLen, pageIdx, &pages[4]))
        return parser_ok;
    }
    pageIdx -= pages[4];

    if (pageIdx < pages[5]) {
        CHECK_ERROR(_toStringData(&v->email, outValue, outValueLen, pageIdx, &pages[5]))
        return parser_ok;
    }
    pageIdx -= pages[5];

    if (pageIdx < pages[6]) {
        CHECK_ERROR(_toStringOptionu8_array_20(&v->pgp_fingerprint, outValue, outValueLen, pageIdx, &pages[6]))
        return parser_ok;
    }
    pageIdx -= pages[6];

    if (pageIdx < pages[7]) {
        CHECK_ERROR(_toStringData(&v->image, outValue, outValueLen, pageIdx, &pages[7]))
        return parser_ok;
    }
    pageIdx -= pages[7];

    if (pageIdx < pages[8]) {
        CHECK_ERROR(_toStringData(&v->twitter, outValue, outValueLen, pageIdx, &pages[8]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringJudgementBalanceOfT(
    const pd_JudgementBalanceOfT_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    *pageCount = 1;
    switch (v->value) {
    case 0: // Unknown
        snprintf(outValue, outValueLen, "Unknown");
        break;
    case 2: // Reasonable
        snprintf(outValue, outValueLen, "Reasonable");
        break;
    case 3: // KnownGood
        snprintf(outValue, outValueLen, "KnownGood");
        break;
    case 4: // OutOfDate
        snprintf(outValue, outValueLen, "OutOfDate");
        break;
    case 5: // LowQuality
        snprintf(outValue, outValueLen, "LowQuality");
        break;
    case 6: // Erroneous
        snprintf(outValue, outValueLen, "Erroneous");
        break;
    case 1: // FeePaid
        CHECK_ERROR(_toStringBalance(&v->feePaid, outValue, outValueLen, pageIdx, pageCount))
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _toStringOptionMultiSigner(
    const pd_OptionMultiSigner_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    if (v->some == 0) {
        snprintf(outValue, outValueLen, "None");
        return parser_ok;
    }
    return _toStringMultiSigner(&v->verifier, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringProposal(
    const pd_Proposal_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringCall(&v->call, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringRewardDestination(
    const pd_RewardDestination_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
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
    case 3:
        CHECK_ERROR(_toStringAccountId(&v->accountId, outValue, outValueLen, pageIdx, pageCount));
        break;
    case 4:
        snprintf(outValue, outValueLen, "None");
        break;
    default:
        return parser_print_not_supported;
    }

    return parser_ok;
}

parser_error_t _toStringValidatorPrefs(
    const pd_ValidatorPrefs_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringCompactPerBill(&v->commission, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringbool(&v->blocked, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringCompactPerBill(&v->commission, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringbool(&v->blocked, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringVecCall(
    const pd_VecCall_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    /* count number of pages, then output specific */
    *pageCount = 0;
    uint8_t chunkPageCount;
    uint16_t currentPage, currentTotalPage = 0;
    /* We need to do it twice because there is no memory to keep intermediate results*/
    /* First count*/
    parser_context_t ctx;
    parser_init(&ctx, v->_ptr, v->_lenBuffer);
    parser_tx_t _txObj;
    pd_Call_t _call;
    ctx.tx_obj = &_txObj;
    _txObj.transactionVersion = v->callTxVersion;
    _call._txVerPtr = &v->callTxVersion;
    _call.nestCallIdx.isTail = true;

    ctx.tx_obj->nestCallIdx.slotIdx = 0;
    ctx.tx_obj->nestCallIdx._lenBuffer = 0;
    ctx.tx_obj->nestCallIdx._ptr = NULL;
    ctx.tx_obj->nestCallIdx._nextPtr = NULL;
    ctx.tx_obj->nestCallIdx.isTail = true;

    for (uint16_t i = 0; i < v->_len; i++) {
        ctx.tx_obj->nestCallIdx._ptr = NULL;
        ctx.tx_obj->nestCallIdx._nextPtr = NULL;
        ctx.tx_obj->nestCallIdx.slotIdx = 0;
        CHECK_ERROR(_readCallImpl(&ctx, &_call, (pd_MethodNested_t*)&_txObj.method));
        CHECK_ERROR(_toStringCall(&_call, outValue, outValueLen, 0, &chunkPageCount));
        (*pageCount) += chunkPageCount;
    }

    /* Then iterate until we can print the corresponding chunk*/
    parser_init(&ctx, v->_ptr, v->_lenBuffer);
    for (uint16_t i = 0; i < v->_len; i++) {
        ctx.tx_obj->nestCallIdx._ptr = NULL;
        ctx.tx_obj->nestCallIdx._nextPtr = NULL;
        ctx.tx_obj->nestCallIdx.slotIdx = 0;
        CHECK_ERROR(_readCallImpl(&ctx, &_call, (pd_MethodNested_t*)&_txObj.method));
        chunkPageCount = 1;
        currentPage = 0;
        while (currentPage < chunkPageCount) {
            CHECK_ERROR(_toStringCall(&_call, outValue, outValueLen, currentPage, &chunkPageCount));
            if (currentTotalPage == pageIdx) {
                return parser_ok;
            }
            currentPage++;
            currentTotalPage++;
        }
    }

    return parser_print_not_supported;
}

parser_error_t _toStringVestingInfo(
    const pd_VestingInfo_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[3] = { 0 };
    CHECK_ERROR(_toStringBalanceOf(&v->locked, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringBalanceOf(&v->per_block, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringBlockNumber(&v->starting_block, outValue, outValueLen, 0, &pages[2]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringBalanceOf(&v->locked, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringBalanceOf(&v->per_block, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringBlockNumber(&v->starting_block, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringWeightLimit(
    const pd_WeightLimit_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    switch (v->value) {
    case 0: // Unlimited
        *pageCount = 1;
        snprintf(outValue, outValueLen, "Unlimited");
        break;
    case 1: // Limited
        CHECK_ERROR(_toStringCompactu64(&v->limited, outValue, outValueLen, pageIdx, pageCount))
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _toStringWeight(
    const pd_Weight_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringCompactu64(&v->refTime, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringCompactu64(&v->proofSize, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringCompactu64(&v->refTime, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringCompactu64(&v->proofSize, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringAccountIndex(
    const pd_AccountIndex_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringConfigOpu32(
    const pd_ConfigOpu32_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    *pageCount = 1;
    switch (v->value) {
    case 0:
        snprintf(outValue, outValueLen, "Noop");
        break;
    case 1:
        CHECK_ERROR(_toStringu32(&v->set, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 2:
        snprintf(outValue, outValueLen, "Remove");
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _toStringConviction(
    const pd_Conviction_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
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

parser_error_t _toStringEraIndex(
    const pd_EraIndex_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringEthereumAddress(
    const pd_EthereumAddress_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount) {
    GEN_DEF_TOSTRING_ARRAY(20)
}

parser_error_t _toStringHash(
    const pd_Hash_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount) {
    GEN_DEF_TOSTRING_ARRAY(32)
}

parser_error_t _toStringKeys(
    const pd_Keys_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount) {
    GEN_DEF_TOSTRING_ARRAY(6 * 32)
}

parser_error_t _toStringMemberCount(
    const pd_MemberCount_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringOverweightIndex(
    const pd_OverweightIndex_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu64(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringParaId(
    const pd_ParaId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringPoolId(
    const pd_PoolId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringPoolState(
    const pd_PoolState_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    *pageCount = 1;
    switch (v->value) {
    case 0:
        snprintf(outValue, outValueLen, "Open");
        break;
    case 1:
        snprintf(outValue, outValueLen, "Blocked");
        break;
    case 2:
        snprintf(outValue, outValueLen, "Destroying");
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _toStringRegistrarIndex(
    const pd_RegistrarIndex_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringSessionIndex(
    const pd_SessionIndex_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringVecMultiAssetV0(
    const pd_VecMultiAssetV0_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(MultiAssetV0);
}

parser_error_t _toStringVecMultiAssetV1(
    const pd_VecMultiAssetV1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(MultiAssetV1);
}

parser_error_t _toStringVecTupleDataData(
    const pd_VecTupleDataData_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(TupleDataData);
}

parser_error_t _toStringVecAccountIdLookupOfT(
    const pd_VecAccountIdLookupOfT_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(AccountIdLookupOfT);
}

parser_error_t _toStringVecTupleAccountIdData(
    const pd_VecTupleAccountIdData_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(TupleAccountIdData);
}

parser_error_t _toStringVecAccountId(
    const pd_VecAccountId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(AccountId);
}

parser_error_t _toStringVecu32(
    const pd_Vecu32_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(u32);
}

parser_error_t _toStringVecu8(
    const pd_Vecu8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(u8);
}

parser_error_t _toStringOptionu8_array_20(
    const pd_Optionu8_array_20_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringu8_array_20(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionMultiSignature(
    const pd_OptionMultiSignature_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringMultiSignature(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionTimepoint(
    const pd_OptionTimepoint_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringTimepoint(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionAccountId(
    const pd_OptionAccountId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringAccountId(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionProxyType(
    const pd_OptionProxyType_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringProxyType(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionReferendumIndex(
    const pd_OptionReferendumIndex_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringReferendumIndex(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionu32(
    const pd_Optionu32_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringu32(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

///////////////////////////////////
///////////////////////////////////
///////////////////////////////////
