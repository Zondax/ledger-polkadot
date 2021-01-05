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

#include "bignum.h"
#include "coin.h"
#include "parser_impl.h"

#include <stddef.h>
#include <stdint.h>
#include <zxmacros.h>

parser_error_t _readbool(parser_context_t* c, pd_bool_t* v)
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

///////////////////////////////////
///////////////////////////////////
///////////////////////////////////
parser_error_t _readCompactBlockNumber(parser_context_t* c, pd_CompactBlockNumber_t* v)
{
    return _readCompactInt(c, v);
}

parser_error_t _readData(parser_context_t* c, pd_Data_t* v)
{

    CHECK_INPUT();
    MEMZERO(v, sizeof(pd_Data_t));
    CHECK_ERROR(_readUInt8(c, (uint8_t*)&v->type))

    v->_ptr = NULL;
    v->_len = 0;

    // based on:
    // https://github.com/paritytech/substrate/blob/effe489951d1edab9d34846b1eefdfaf9511dab9/frame/identity/src/lib.rs#L139
    switch (v->type) {
    case Data_e_NONE: {
        v->_ptr = NULL;
        v->_len = 0;
        return parser_ok;
    }
    case Data_e_BLAKETWO256U8_32:
    case Data_e_SHA256_U8_32:
    case Data_e_KECCAK256_U8_32:
    case Data_e_SHATHREE256_U8_32:
        return parser_not_supported;
    default: {
        if (v->type > Data_e_NONE && v->type <= Data_e_RAW_VECU8) {
            const uint8_t bufferSize = ((uint8_t)v->type - 1);
            v->_ptr = c->buffer + c->offset;
            v->_len = bufferSize;
            CTX_CHECK_AND_ADVANCE(c, v->_len);
            return parser_ok;
        }
        return parser_not_supported;
    }
    }
}
parser_error_t _readTupleDataData(parser_context_t* c, pd_TupleDataData_t* v)
{

    CHECK_INPUT();
    CHECK_ERROR(_readData(c, &v->data1))
    CHECK_ERROR(_readData(c, &v->data2))
    return parser_ok;
}
parser_error_t _readu8_array_20(parser_context_t* c, pd_u8_array_20_t* v){

    GEN_DEF_READARRAY(20)
} parser_error_t _readHeader(parser_context_t* c, pd_Header_t* v)
{

    return parser_not_supported;
}
parser_error_t _readLookupSource(parser_context_t* c, pd_LookupSource_t* v){

    GEN_DEF_READARRAY(32)
} parser_error_t _readBytes(parser_context_t* c, pd_Bytes_t* v)
{

    CHECK_INPUT()

    compactInt_t clen;
    CHECK_ERROR(_readCompactInt(c, &clen))
    CHECK_ERROR(_getValue(&clen, &v->_len))

    v->_ptr = c->buffer + c->offset;
    CTX_CHECK_AND_ADVANCE(c, v->_len);
    return parser_ok;
}
parser_error_t _readCompactBalanceOf(parser_context_t* c, pd_CompactBalanceOf_t* v)
{

    CHECK_INPUT();
    CHECK_ERROR(_readCompactInt(c, &v->value));
    return parser_ok;
}
parser_error_t _readHash(parser_context_t* c, pd_Hash_t* v){

    GEN_DEF_READARRAY(32)
} parser_error_t _readHeartbeat(parser_context_t* c, pd_Heartbeat_t* v)
{

    return parser_not_supported;
}
parser_error_t _readVecHeader(parser_context_t* c, pd_VecHeader_t* v){

    GEN_DEF_READVECTOR(Header)
}

parser_error_t _readVecTupleDataData(parser_context_t* c, pd_VecTupleDataData_t* v){
    GEN_DEF_READVECTOR(TupleDataData)
}

parser_error_t _readVecLookupSource(parser_context_t* c, pd_VecLookupSource_t* v){
    GEN_DEF_READVECTOR(LookupSource)
}

parser_error_t _readVecu32(parser_context_t* c, pd_Vecu32_t* v){
    GEN_DEF_READVECTOR(u32)
}

parser_error_t _readOptionu8_array_20(parser_context_t* c, pd_Optionu8_array_20_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readu8_array_20(c, &v->contained))
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
    return _toStringCompactInt(v, 0, 0, outValue, outValueLen, pageIdx, pageCount, bool_true);
}

///////////////////////////////////
///////////////////////////////////
///////////////////////////////////

parser_error_t _toStringCompactBlockNumber(
    const pd_CompactBlockNumber_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringCompactInt(v, 0, 0, outValue, outValueLen, pageIdx, pageCount, bool_true);
}

parser_error_t _toStringData(
    const pd_Data_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{

    CLEAN_AND_CHECK()

    if (v->_ptr == NULL || v->_len == 0) {
        return parser_unexpected_value;
    }

    if (v->type > Data_e_NONE && v->type <= Data_e_RAW_VECU8) {
        const uint8_t bufferSize = ((uint8_t)v->type - 1);
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

parser_error_t _toStringTupleDataData(
    const pd_TupleDataData_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{

    CLEAN_AND_CHECK()

    uint8_t pages[2];
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

    /////////
    /////////

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringData(&v->data2, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringu8_array_20(
    const pd_u8_array_20_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount){

    GEN_DEF_TOSTRING_ARRAY(20)
}

parser_error_t _toStringHeader(
    const pd_Header_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{

    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringLookupSource(
    const pd_LookupSource_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{

    return _toStringPubkeyAsAddress(v->_ptr, outValue, outValueLen, pageIdx, pageCount);
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

parser_error_t _toStringCompactBalanceOf(
    const pd_CompactBalanceOf_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{

    CHECK_ERROR(_toStringCompactInt(&v->value, COIN_AMOUNT_DECIMAL_PLACES, 0, outValue, outValueLen, pageIdx, pageCount, bool_false))
    number_inplace_trimming(outValue);
    _appendCoinSymbol(outValue);

    char bufferUI[outValueLen];
    strcpy(bufferUI, outValue);
    pageString(outValue, outValueLen, bufferUI, pageIdx, pageCount);
    return parser_ok;
}

parser_error_t _toStringHash(
    const pd_Hash_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount){

    GEN_DEF_TOSTRING_ARRAY(32)
}

parser_error_t _toStringHeartbeat(
    const pd_Heartbeat_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{

    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringVecHeader(
    const pd_VecHeader_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount){

    GEN_DEF_TOSTRING_VECTOR(Header)
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

parser_error_t _toStringVecLookupSource(
    const pd_VecLookupSource_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(LookupSource);
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

///////////////////////////////////
///////////////////////////////////
///////////////////////////////////