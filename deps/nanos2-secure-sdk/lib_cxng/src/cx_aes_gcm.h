
/*******************************************************************************
*   Ledger Nano S - Secure firmware
*   (c) 2022 Ledger
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

#ifndef CX_AES_GCM_H
#define CX_AES_GCM_H

#include "lcx_aead.h"
#include <stddef.h>

 // Store unaligned 32-bit integer (big-endian encoding)
 #define STORE32BE(a, p) \
    ((uint8_t *)(p))[0] = ((uint32_t)(a) >> 24) & 0xFFU, \
    ((uint8_t *)(p))[1] = ((uint32_t)(a) >> 16) & 0xFFU, \
    ((uint8_t *)(p))[2] = ((uint32_t)(a) >> 8) & 0xFFU, \
    ((uint8_t *)(p))[3] = ((uint32_t)(a) >> 0) & 0xFFU

 // Store unaligned 64-bit integer (big-endian encoding)
 #define STORE64BE(a, p) \
    ((uint8_t *)(p))[0] = ((uint64_t)(a) >> 56) & 0xFFU, \
    ((uint8_t *)(p))[1] = ((uint64_t)(a) >> 48) & 0xFFU, \
    ((uint8_t *)(p))[2] = ((uint64_t)(a) >> 40) & 0xFFU, \
    ((uint8_t *)(p))[3] = ((uint64_t)(a) >> 32) & 0xFFU, \
    ((uint8_t *)(p))[4] = ((uint64_t)(a) >> 24) & 0xFFU, \
    ((uint8_t *)(p))[5] = ((uint64_t)(a) >> 16) & 0xFFU, \
    ((uint8_t *)(p))[6] = ((uint64_t)(a) >> 8) & 0xFFU, \
    ((uint8_t *)(p))[7] = ((uint64_t)(a) >> 0) & 0xFFU

extern const cx_aead_info_t cx_aes128_gcm_info;
extern const cx_aead_info_t cx_aes192_gcm_info;
extern const cx_aead_info_t cx_aes256_gcm_info;

cx_err_t cx_aes_gcm_init(cx_aes_gcm_context_t *ctx);
cx_err_t cx_aes_gcm_set_key(cx_aes_gcm_context_t *ctx, const uint8_t *raw_key, size_t key_len);
cx_err_t cx_aes_gcm_start(cx_aes_gcm_context_t *ctx, uint32_t mode,
                          const uint8_t *iv, size_t iv_len,
                          const uint8_t *aad, size_t aad_len);
cx_err_t cx_aes_gcm_update(cx_aes_gcm_context_t *ctx, uint8_t *in, size_t len, uint8_t *out);
cx_err_t cx_aes_gcm_finish(cx_aes_gcm_context_t *ctx, uint8_t *tag, size_t tag_len);
cx_err_t cx_aes_gcm_encrypt_and_tag(cx_aes_gcm_context_t *ctx, uint32_t mode, uint8_t *in, size_t len,
                                    const uint8_t *iv, size_t iv_len, const uint8_t *aad, size_t aad_len,
                                    uint8_t *out, uint8_t *tag, size_t tag_len);
cx_err_t cx_aes_gcm_decrypt_and_auth(cx_aes_gcm_context_t *ctx, uint8_t *in, size_t len,
                                     const uint8_t *iv, size_t iv_len, const uint8_t *aad,
                                     size_t aad_len, uint8_t *out, const uint8_t *tag, size_t tag_len);

#endif // CX_AES_GCM_H
