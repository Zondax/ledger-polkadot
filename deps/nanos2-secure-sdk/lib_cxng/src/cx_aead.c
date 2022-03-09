
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

#if defined(HAVE_AEAD) && defined(HAVE_AES_GCM)

#include "lcx_aead.h"
#include "lcx_common.h"
#include "cx_aes_gcm.h"
#include <string.h>

const cx_aead_info_t *cx_aead_get_info(cx_aead_type_t type) {
  switch (type) {
    case CX_AEAD_AES128_GCM:
      return &cx_aes128_gcm_info;
    case CX_AEAD_AES192_GCM:
      return &cx_aes192_gcm_info;
    case CX_AEAD_AES256_GCM:
      return &cx_aes256_gcm_info;
    default:
      return NULL;
  }
}

cx_err_t cx_aead_init(cx_aead_context_t *ctx) {
  if (NULL == ctx) {
    return CX_INVALID_PARAMETER;
  }
  memset(ctx, 0, sizeof(cx_aead_context_t));
  return CX_OK;
}

cx_err_t cx_aead_setup(cx_aead_context_t *ctx, cx_aead_type_t type) {
  if (NULL == ctx) {
    return CX_INVALID_PARAMETER;
  }
  const cx_aead_info_t *info = cx_aead_get_info(type);
  if (NULL == info) {
    return CX_INVALID_PARAMETER;
  }
  ctx->info = info;
  switch (type) {
    case CX_AEAD_AES128_GCM:
    case CX_AEAD_AES192_GCM:
    case CX_AEAD_AES256_GCM:
      return cx_aes_gcm_init(ctx->aes_gcm_ctx);
    default:
      return CX_INVALID_PARAMETER;
  }
}

cx_err_t cx_aead_set_key(cx_aead_context_t *ctx, const uint8_t *key, size_t key_len, uint32_t mode) {
  if ((NULL == key) || (NULL == ctx)) {
    return CX_INVALID_PARAMETER;
  }
  if (ctx->info->key_bitlen != key_len * 8) {
    return CX_INVALID_PARAMETER_SIZE;
  }
  if ((mode != CX_ENCRYPT) && (mode != CX_DECRYPT)) {
    return CX_INVALID_PARAMETER_VALUE;
  }
  ctx->mode = mode;
  switch (ctx->info->type) {
    case CX_AEAD_AES128_GCM:
    case CX_AEAD_AES192_GCM:
    case CX_AEAD_AES256_GCM:
      return cx_aes_gcm_set_key(ctx->aes_gcm_ctx, key, key_len);
    default:
      return CX_INVALID_PARAMETER;
  }
}

cx_err_t cx_aead_set_iv(cx_aead_context_t *ctx, const uint8_t *iv, size_t iv_len) {
  if ((NULL == ctx) || (NULL == iv) || (iv_len < 1)) {
    return CX_INVALID_PARAMETER;
  }
  if (NULL == ctx->info) {
    return CX_INVALID_PARAMETER;
  }
  switch (ctx->info->type) {
    case CX_AEAD_AES128_GCM:
    case CX_AEAD_AES192_GCM:
    case CX_AEAD_AES256_GCM:
      memcpy(ctx->iv_set, iv, iv_len);
      ctx->iv_set_len = iv_len;
      return CX_OK;
    default:
      return CX_INVALID_PARAMETER;
  }
}

cx_err_t cx_aead_update_ad(cx_aead_context_t *ctx, const uint8_t *ad, size_t ad_len) {
  if ((NULL == ctx) || (NULL == ctx->info)) {
    return CX_INVALID_PARAMETER;
  }
  switch (ctx->info->type) {
    case CX_AEAD_AES128_GCM:
    case CX_AEAD_AES192_GCM:
    case CX_AEAD_AES256_GCM:
      return cx_aes_gcm_start(ctx->aes_gcm_ctx, ctx->mode, ctx->iv_set,
                              ctx->iv_set_len, ad, ad_len);
    default:
      return CX_INVALID_PARAMETER;
  }
}

cx_err_t cx_aead_update(cx_aead_context_t *ctx, uint8_t *in, size_t in_len, uint8_t *out, size_t *out_len) {
  if ((NULL == ctx) || (NULL == ctx->info) || (NULL == out_len)) {
    return CX_INVALID_PARAMETER;
  }
  *out_len = 0;
  switch (ctx->info->type) {
    case CX_AEAD_AES128_GCM:
    case CX_AEAD_AES192_GCM:
    case CX_AEAD_AES256_GCM:
      *out_len = in_len;
      return cx_aes_gcm_update(ctx->aes_gcm_ctx, in, in_len, out);
    default:
      return CX_INVALID_PARAMETER;
  }
}

cx_err_t cx_aead_write_tag(cx_aead_context_t *ctx, uint8_t *tag, size_t tag_len) {
  if ((NULL == ctx) || (NULL == ctx->info) || (NULL == tag)) {
    return CX_INVALID_PARAMETER;
  }
  if (ctx->mode != CX_ENCRYPT) {
    return CX_INVALID_PARAMETER_VALUE;
  }
  switch (ctx->info->type) {
    case CX_AEAD_AES128_GCM:
    case CX_AEAD_AES192_GCM:
    case CX_AEAD_AES256_GCM:
      return cx_aes_gcm_finish(ctx->aes_gcm_ctx, tag, tag_len);
    default:
      return CX_INVALID_PARAMETER;
  }
}

cx_err_t cx_aead_check_tag(cx_aead_context_t *ctx, const uint8_t *tag, size_t tag_len) {
  cx_err_t error;
  size_t   i;
  uint8_t  diff;
  uint8_t  check_tag[MAX_TAG_LENGTH];

  if ((NULL == ctx) || (NULL == ctx->info) || (ctx->mode != CX_DECRYPT)) {
    return CX_INVALID_PARAMETER;
  }
  switch (ctx->info->type) {
    case CX_AEAD_AES128_GCM:
    case CX_AEAD_AES192_GCM:
    case CX_AEAD_AES256_GCM:
      if (tag_len > MAX_TAG_LENGTH) {
        return CX_INVALID_PARAMETER_SIZE;
      }
      CX_CHECK(cx_aes_gcm_finish(ctx->aes_gcm_ctx, check_tag, tag_len));
      for (diff = 0, i = 0; i < tag_len; i++) {
        diff |= tag[i] ^ check_tag[i];
      }
      return ((diff == 0) ? CX_OK : CX_INVALID_PARAMETER_VALUE);
    default:
      return CX_INVALID_PARAMETER;
  }
  end:
    return error;
}

cx_err_t cx_aead_encrypt(cx_aead_context_t *ctx, const uint8_t *iv, size_t iv_len,
                         const uint8_t *ad, size_t ad_len, uint8_t *in, size_t in_len,
                         uint8_t *out, size_t *out_len, uint8_t *tag, size_t tag_len) {
  if ((NULL == ctx) || (NULL == ctx->info)) {
    return CX_INVALID_PARAMETER;
  }
  switch (ctx->info->type) {
    case CX_AEAD_AES128_GCM:
    case CX_AEAD_AES192_GCM:
    case CX_AEAD_AES256_GCM:
      *out_len = in_len;
      return cx_aes_gcm_encrypt_and_tag(ctx->aes_gcm_ctx, CX_ENCRYPT, in, in_len,
                                        iv, iv_len, ad, ad_len, out, tag, tag_len);
    default:
      return CX_INVALID_PARAMETER;
  }
}

cx_err_t cx_aead_decrypt(cx_aead_context_t *ctx, const uint8_t *iv, size_t iv_len,
                         const uint8_t *ad, size_t ad_len, uint8_t *in, size_t in_len,
                         uint8_t *out, size_t *out_len, const uint8_t *tag, size_t tag_len) {
  if ((NULL == ctx) || (NULL == ctx->info)) {
    return CX_INVALID_PARAMETER;
  }
  switch (ctx->info->type) {
    case CX_AEAD_AES128_GCM:
    case CX_AEAD_AES192_GCM:
    case CX_AEAD_AES256_GCM:
      *out_len = in_len;
      return cx_aes_gcm_decrypt_and_auth(ctx->aes_gcm_ctx, in, in_len,
                                            iv, iv_len, ad, ad_len, out, tag, tag_len);
    default:
      return CX_INVALID_PARAMETER;
  }
}

#endif // HAVE_AEAD && HAVE_AES_GCM
