/*******************************************************************************
 *   (c) 2018 - 2024 Zondax AG
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

#include "substrate_types.h"

typedef enum {
    Bool = 0,
    Char,
    String,
    U8,
    U16,
    U32,
    U64,
    U128,
    U256,
    I8,
    I16,
    I32,
    I64,
    I128,
    I256,
    CompactU8,
    CompactU16,
    CompactU32,
    CompactU64,
    CompactU128,
    CompactU256,
    Void,
    ById,
    TypeRefLast
} TypeRef_e;

typedef enum { Composite = 0, Enumeration, Sequence, Array, Tuple, BitSequenceType, TypeDefLast } TypeDef_e;

typedef struct {
    uint8_t index;
    uint32_t byId;  // Only used for ById entry
} TypeRef_t;

typedef struct {
    OptBytes_t name;
    TypeRef_t type;
    OptBytes_t typeName;
} Field_t;

// Generic way for Vec<type>
// Store how many elements we have and a ctx to read
typedef struct {
    uint32_t len;
    parser_context_t ctx;
} Vector_t;

typedef Vector_t Composite_t;  // Vec<Field>

typedef struct {
    Bytes_t name;
    Composite_t fields;  // Vec<Fields> --> Use Composite
    uint32_t index;
} Enumeration_t;

typedef TypeRef_t Sequence_t;  // TypeRef

typedef struct {
    uint32_t len;
    TypeRef_t typeParam;
} TypeDefArray_t;

typedef TypeDefArray_t Array_t;

typedef Vector_t Tuple_t;  // Vec<TypeRef>

typedef struct {
    uint8_t numBytes;
    bool lsbFirst;
} BitSequence_t;

typedef struct {
    Bytes_t identifier;
    TypeRef_t includedInExtrinsic;
    TypeRef_t includedInSignedData;
} SignedExtension_t;

typedef struct {
    Vector_t path;
    uint32_t typeId;
    TypeDef_e kind;
    union {
        Composite_t composite;
        Enumeration_t enumeration;
        Sequence_t sequence;
        Array_t array;
        Tuple_t tuple;
        BitSequence_t bitSequence;
    };
} RegistryEntry_t;

#ifdef __cplusplus
}
#endif
