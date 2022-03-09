
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

#if defined(HAVE_AES_GCM) && defined(HAVE_AES)

#include "cx_ades.h"
#include "cx_aes_gcm.h"
#include "lcx_aes_gcm.h"
#include "lcx_aead.h"
#include "cx_utils.h"
#include "os_math.h"
#include "ox_bn.h"
#include <stddef.h>
#include <string.h>

#define GF2_128_MPI_BYTES (2 * 16)
#define AES_BLOCK_BYTES    16

const cx_aead_info_t cx_aes128_gcm_info = {
  CX_AEAD_AES128_GCM,
  128,
  128,
};

const cx_aead_info_t cx_aes192_gcm_info = {
  CX_AEAD_AES192_GCM,
  192,
  128,
};

const cx_aead_info_t cx_aes256_gcm_info = {
  CX_AEAD_AES256_GCM,
  256,
  128,
};

// The irreducible polynomial N(x) = x^128 + x^7 + x^2 + x + 1
const uint8_t N[17] = {0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                       0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x87};

// 2nd Montgomery constant: R2 = x^(2*t*128) mod N(x)
// t = 2 since the number of bytes of R is 17.
const uint8_t R2[4] = {0x10, 0x00, 0x01, 0x11};

/**
 * Increments the right-most 32 bits of the block.
 * The left-most 96 bits remain unchanged.
 */
static void cx_gcm_increment(uint8_t *in) {
  size_t i;

  for (i = 0; i < 4; i++) {
    // Increment the current byte and propagate the carry if necessary.
    if (++(in[15 - i]) != 0) {
      break;
    }
  }
}

/**
 * The GHASH function is composed of:
 *  - cx_gcm_xor_block
 *  - cx_gcm_mul
 * Given a 128*m-bit (hash) key H, for any 128*m-bit input X
 * It calculates a 128 bit output R = X0 * H0 + X1 * H1 + ... + X_{m-1} * H_{m-1}.
 */
static void cx_gcm_xor_block(uint8_t *r, const uint8_t *a, const uint8_t *b, size_t len) {
  size_t i;

  for (i = 0; i < len; i++) {
    r[i] = a[i] ^ b[i];
  }
}

/**
 * Reverse bit order in an octet.
 */
static uint8_t cx_reverse_8bits(uint8_t value) {

  value = ((value & 0xF0) >> 4) | ((value & 0x0F) << 4);
  value = ((value & 0xCC) >> 2) | ((value & 0x33) << 2);
  value = ((value & 0xAA) >> 1) | ((value & 0x55) << 1);

  return value;
}

/**
 * Reverse bit order in an array of octets.
 */
static void cx_reverse_buffer(uint8_t *r, uint8_t *buf, size_t buf_len) {
  size_t i;

  for (i = 0; i < buf_len; i++) {
    r[i] = cx_reverse_8bits(buf[buf_len - 1 - i]);
  }
}

/**
 * Multiplication over GF(2^128) using Nescrypt
 */
static cx_err_t cx_gcm_mul(uint8_t *r, uint8_t *a, uint8_t *b) {
  cx_err_t error;
  cx_bn_t  bn_n, bn_c, bn_a, bn_b, bn_r;
  uint8_t  tmp[AES_BLOCK_BYTES];

  CX_CHECK(cx_bn_lock(GF2_128_MPI_BYTES, 0));
  CX_CHECK(cx_bn_alloc(&bn_r, GF2_128_MPI_BYTES));
  cx_reverse_buffer(tmp, a, AES_BLOCK_BYTES);
  CX_CHECK(cx_bn_alloc_init(&bn_a, GF2_128_MPI_BYTES, tmp, AES_BLOCK_BYTES));
  cx_reverse_buffer(tmp, b, AES_BLOCK_BYTES);
  CX_CHECK(cx_bn_alloc_init(&bn_b, GF2_128_MPI_BYTES, tmp, AES_BLOCK_BYTES));
  CX_CHECK(cx_bn_alloc_init(&bn_n, GF2_128_MPI_BYTES, N, sizeof(N)));
  CX_CHECK(cx_bn_alloc_init(&bn_c, GF2_128_MPI_BYTES, R2, sizeof(R2)));
  CX_CHECK(cx_bn_gf2_n_mul(bn_r, bn_b, bn_a, bn_n, bn_c));
  CX_CHECK(cx_bn_export(bn_r, tmp, AES_BLOCK_BYTES));
  cx_reverse_buffer(r, tmp, AES_BLOCK_BYTES);

  end:
    cx_bn_unlock();
    return error;
}

cx_err_t cx_aes_gcm_init(cx_aes_gcm_context_t *ctx) {
  if (NULL == ctx) {
    return CX_INVALID_PARAMETER;
  }
  memset(ctx, 0, sizeof(cx_aes_gcm_context_t));
  return CX_OK;
}

cx_err_t cx_aes_gcm_set_key(cx_aes_gcm_context_t *ctx, const uint8_t *raw_key, size_t key_len) {
  if (NULL == ctx) {
    return CX_INVALID_PARAMETER;
  }
  return cx_aes_init_key_no_throw(raw_key, key_len, &ctx->key);
}

cx_err_t cx_aes_gcm_start(cx_aes_gcm_context_t *ctx, uint32_t mode,
                          const uint8_t *iv, size_t iv_len,
                          const uint8_t *aad, size_t aad_len) {

  cx_err_t error = CX_INVALID_PARAMETER;
  size_t   i, block_len;

  if (NULL == ctx) {
    return error;
  }

  ctx->mode = mode;
  if (!ctx->flag) {
    memset(ctx->enc_block, 0, AES_BLOCK_BYTES);

    // Compute H = AES_K(0)
    CX_CHECK(cx_aes_enc_block(&ctx->key, ctx->enc_block, ctx->hash_key));
    memset(ctx->J0, 0, 16);

    // J0 = (IV|0|1)
    if (12 == iv_len) {
      memcpy(ctx->J0, iv, iv_len);
      STORE32BE(1, ctx->J0 + 12);
    }
    // J0 = GHASH_H(IV|0^(s+64)|[len(IV)]_64)
    else {
      i = iv_len;
      while (i > 0) {
        block_len = MIN(i, AES_BLOCK_BYTES);
        cx_gcm_xor_block(ctx->J0, ctx->J0, iv, block_len);
        CX_CHECK(cx_gcm_mul(ctx->J0, ctx->hash_key, ctx->J0));
        iv += block_len;
        i  -= block_len;
      }
      memset(ctx->enc_block, 0, 8);
      STORE64BE(iv_len * 8, ctx->enc_block + 8);
      cx_gcm_xor_block(ctx->J0, ctx->J0, ctx->enc_block, AES_BLOCK_BYTES);
      CX_CHECK(cx_gcm_mul(ctx->J0, ctx->hash_key, ctx->J0));
    }
    // Save ctx->buf for cx_aes_gcm_finish
    CX_CHECK(cx_aes_enc_block(&ctx->key, ctx->J0, ctx->enc_block));
    ctx->flag = 1;
  }

  // Process additional data
  // Save for cx_aes_gcm_finish
  ctx->aad_len += aad_len;
  i             = aad_len;
  while (i > 0) {
    block_len = MIN(i, AES_BLOCK_BYTES);
    cx_gcm_xor_block(ctx->processed, ctx->processed, aad, block_len);
    CX_CHECK(cx_gcm_mul(ctx->processed, ctx->hash_key, ctx->processed));
    aad += block_len;
    i   -= block_len;
  }
  error = CX_OK;
  end:
    return error;
}

cx_err_t cx_aes_gcm_update(cx_aes_gcm_context_t *ctx, uint8_t *in, size_t len, uint8_t *out) {
  cx_err_t error = CX_INVALID_PARAMETER;
  size_t   i, block_len;
  uint8_t  tmp[AES_BLOCK_BYTES];

  if (NULL == ctx) {
    return error;
  }

  ctx->len += len;
  i         = len;
  switch (ctx->mode) {
    case CX_ENCRYPT:
      while (i > 0) {
        block_len = MIN(i, AES_BLOCK_BYTES);
        cx_gcm_increment(ctx->J0);
        CX_CHECK(cx_aes_enc_block(&ctx->key, ctx->J0, tmp));
        cx_gcm_xor_block(out, in, tmp, block_len);
        cx_gcm_xor_block(ctx->processed, ctx->processed, out, block_len);
        CX_CHECK(cx_gcm_mul(ctx->processed, ctx->hash_key, ctx->processed));
        if (i - block_len > 0) {
          in  += block_len;
          out += block_len;
        }
        i -= block_len;
      }
      break;
    case CX_DECRYPT:
      while (i > 0) {
        block_len = MIN(i, AES_BLOCK_BYTES);
        cx_gcm_xor_block(ctx->processed, ctx->processed, in, block_len);
        CX_CHECK(cx_gcm_mul(ctx->processed, ctx->hash_key, ctx->processed));
        cx_gcm_increment(ctx->J0);
        CX_CHECK(cx_aes_enc_block(&ctx->key, ctx->J0, tmp));
        cx_gcm_xor_block(out, in, tmp, block_len);
        if (i - block_len > 0) {
          out += block_len;
          in  += block_len;
        }
        i -= block_len;
      }
      break;
    default:
      return CX_INVALID_PARAMETER_VALUE;
  }
  error = CX_OK;
  end:
    return error;
}

cx_err_t cx_aes_gcm_finish(cx_aes_gcm_context_t *ctx, uint8_t *tag, size_t tag_len) {
  cx_err_t error;

  if (NULL == ctx) {
    return CX_INVALID_PARAMETER;
  }

  STORE64BE(ctx->aad_len * 8, ctx->J0);
  STORE64BE(ctx->len * 8, ctx->J0 + 8);
  cx_gcm_xor_block(ctx->processed, ctx->processed, ctx->J0, AES_BLOCK_BYTES);
  CX_CHECK(cx_gcm_mul(ctx->processed, ctx->hash_key, ctx->processed));
  cx_gcm_xor_block(tag, ctx->enc_block, ctx->processed, tag_len);

  end:
    return error;
}

cx_err_t cx_aes_gcm_encrypt_and_tag(cx_aes_gcm_context_t *ctx, uint32_t mode, uint8_t *in, size_t len,
                                    const uint8_t *iv, size_t iv_len, const uint8_t *aad, size_t aad_len,
                                    uint8_t *out, uint8_t *tag, size_t tag_len) {
  cx_err_t error;

  if (NULL == ctx) {
    return CX_INVALID_PARAMETER;
  }
  CX_CHECK(cx_aes_gcm_start(ctx, mode, iv, iv_len, aad, aad_len));
  CX_CHECK(cx_aes_gcm_update(ctx, in, len, out));
  CX_CHECK(cx_aes_gcm_finish(ctx, tag, tag_len));

  end:
    return error;
}

cx_err_t cx_aes_gcm_decrypt_and_auth(cx_aes_gcm_context_t *ctx, uint8_t *in, size_t len,
                                     const uint8_t *iv, size_t iv_len, const uint8_t *aad,
                                     size_t aad_len, uint8_t *out, const uint8_t *tag, size_t tag_len) {

  cx_err_t error;
  uint8_t  check_tag[AES_BLOCK_BYTES];
  uint8_t  diff;
  size_t   i;

  if (NULL == ctx) {
    return CX_INVALID_PARAMETER;
  }
  CX_CHECK(cx_aes_gcm_encrypt_and_tag(ctx, CX_DECRYPT, in, len, iv, iv_len,
                                      aad, aad_len, out, check_tag, tag_len));

  for (diff = 0, i = 0; i < tag_len; i++) {
    diff |= check_tag[i] ^ tag[i];
  }
  error = ((diff == 0) ? CX_OK : CX_INVALID_PARAMETER_VALUE);

  // The output buffer is set to 0 if the tag verification fails.
  if (error) {
    for (i = 0; i < len; i++) {
      out[i] = 0;
    }
  }

  end:
    return error;
}

#endif // HAVE_AES_GCM && AES
