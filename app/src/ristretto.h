/*******************************************************************************
*   (c) 2021 Zondax GmbH
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

#define ED25519_SCALAR_BYTES       32
#define RISTRETTO_BYTES            32
#define ED25519_SDKPOINT_BYTES     65

typedef unsigned char fe25519_sdk[ED25519_SCALAR_BYTES];

typedef struct {
    fe25519_sdk X;
    fe25519_sdk Y;
    fe25519_sdk Z;
    fe25519_sdk T;
} ge25519_p3_sdk;

#define SWAP_BYTES(x, y, tmp) { \
                   tmp = x;     \
                   x = y;       \
                   y = tmp;\
}

#define SWAP_ENDIAN(x, tmp) { \
                 for (int i = 0; i < ED25519_SCALAR_BYTES/2; i++){ \
                          SWAP_BYTES(*(x + i), *(x + (ED25519_SCALAR_BYTES-1-i)), tmp); \
                 }          \
}


cx_err_t crypto_scalarmult_ristretto255_base_sdk(unsigned char *q, const unsigned char *n);
