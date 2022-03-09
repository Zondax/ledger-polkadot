
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

#if defined(HAVE_DES) || defined(HAVE_AES)

#include "exceptions.h"
#include "cx_ades.h"
#include "cx_utils.h"
#include "os_math.h"
#include "os_utils.h"

#include <stddef.h>
#include <string.h>

static cx_err_t cx_unpad(uint8_t *buff, uint32_t pad, size_t block_size, size_t *padded_size);
static cx_err_t cx_pad(uint8_t *buff, size_t len, uint32_t pad, size_t block_size, size_t *padded_size);

#ifdef HAVE_DES
#define ALGO_DES 1
#endif

#ifdef HAVE_AES
#define ALGO_AES 2
#endif


#ifdef HAVE_DES

cx_err_t cx_des_init_key_no_throw(const uint8_t *raw_key, size_t key_len, cx_des_key_t *key) {
  memset(key, 0, sizeof(cx_des_key_t));
  switch (key_len) {
  case 8:
  case 16:
  case 24:
    key->size = (uint8_t)key_len;
    memmove(key->keys, raw_key, key_len);
    return CX_OK;

  default:
    return CX_INVALID_PARAMETER;
  }
}
#endif

#ifdef HAVE_AES

cx_err_t cx_aes_init_key_no_throw(const uint8_t *raw_key, size_t key_len, cx_aes_key_t *key) {
  memset(key, 0, sizeof(cx_aes_key_t));
  switch (key_len) {
  case 16:
  case 24:
  case 32:
    key->size = key_len;
    memmove(key->keys, raw_key, key_len);
    return CX_OK;
  default:
    return CX_INVALID_PARAMETER;
  }
}
#endif

/* ----------------------------------------------------------------------- */
/*                                                                         */
/* ----------------------------------------------------------------------- */
#ifdef HAVE_DES
static cx_err_t cx_des_block_hw_helper(const uint8_t *inblock, uint8_t *outblock)
{
  cx_des_block_hw(inblock, outblock);
  return CX_OK;
}
#endif

typedef cx_err_t (*cx_func_encdec_block_t)(const uint8_t *, uint8_t *);

static cx_err_t cx_ades(const void *                   key,
                        uint32_t                       mode,
                        const uint8_t *                iv,
                        __attribute__((unused)) size_t iv_len,
                        const uint8_t *                in,
                        size_t                         len,
                        uint8_t *                      out,
                        size_t *                       out_len,
                        int                            algo) {
#if defined(HAVE_DES) && defined(HAVE_AES)
#define CX_BLK_SZ MAX(CX_DES_BLOCK_SIZE, CX_AES_BLOCK_SIZE)
#elif defined(HAVE_AES)
#define CX_BLK_SZ CX_AES_BLOCK_SIZE
#else
#define CX_BLK_SZ CX_DES_BLOCK_SIZE
#endif
  uint8_t                block[CX_BLK_SZ];
  uint8_t                last[CX_BLK_SZ * 2];
  uint32_t               lblock;
  uint32_t               cx_mode;
  size_t                 len_out, out_len_;
  uint8_t                block_size;
  cx_func_encdec_block_t func;
  cx_err_t error = CX_INVALID_PARAMETER;

  out_len_ = *out_len;

  switch (algo) {
#ifdef HAVE_DES
  case ALGO_DES:
    block_size = CX_DES_BLOCK_SIZE;
    func = cx_des_block_hw_helper;
    cx_des_set_key_hw(key, mode);
    break;
#endif
#ifdef HAVE_AES
  case ALGO_AES:
    block_size = CX_AES_BLOCK_SIZE;
    func       = cx_aes_block_hw;
    CX_CHECK(cx_aes_set_key_hw(key, mode));
    break;
#endif
  default:
    return CX_INVALID_PARAMETER;
  }

  if (len == 0) {
    return 0;
  }

  if ((!(mode & CX_LAST)) && (len % block_size)) {
    switch (algo) {
#ifdef HAVE_DES
    case ALGO_DES:
      cx_des_reset_hw();
      break;
#endif
#ifdef HAVE_AES
    case ALGO_AES:
      cx_aes_reset_hw();
      break;
#endif
    default:
      return CX_INVALID_PARAMETER;
    }
  }

  memset(block, 0, sizeof(block));
  memset(last, 0, sizeof(last));

  if (iv) {
    if (iv_len!=block_size) {
      return CX_INVALID_PARAMETER;
    }
    memmove(block, iv, block_size);
    memmove(last, iv, block_size);
  }

  cx_mode = mode & CX_MASK_SIGCRYPT;
  switch (mode & CX_MASK_CHAIN) {
    // === CBC ===
  case CX_CHAIN_CBC:
    switch (cx_mode) {
      // --- SIGNATURE ---
    case CX_SIGN:
    case CX_VERIFY:
      // all blocks
      while (len >= block_size) {
        // next block, xored with previous encryped block
        cx_memxor(block, in, block_size);
        // encrypt block, only keep it for next loop
        CX_CHECK(func(block, block));
        len -= block_size;
        in += block_size;
      }
      // pad last block
      memmove(last, in, len);
      // if last block exist,
      if (cx_pad(last, len, mode & CX_MASK_PAD, block_size, &len) != CX_OK) {
        return CX_INVALID_PARAMETER;
      }
      in  = last;
      while (len) {
        // next block, xored with previous encryped block
        cx_memxor(block, in, block_size);
        // encrypt block, only keep it for next loop
        CX_CHECK(func(block, block));
        len -= block_size;
        in += block_size;
      }
      // either set sig or check it
      if (cx_mode == CX_SIGN) {
        memmove(out, block, block_size);
        len_out = block_size;
      } else {
        len_out = (memcmp(block, out, block_size) == 0) ? block_size : 0;
      }
      break;

      // --- ENCRYPTION ---
    case CX_ENCRYPT: // Ci = Enc(Pi xor Ci_1)
      len_out = len - len % block_size;
      // all blocks
      while (len >= block_size) {
        // next block, xored with previous encryped block
        cx_memxor(block, in, block_size);
        // encrypt block
        CX_CHECK(func(block, block));
        // set block result
        memmove(out, block, block_size);
        //++
        len -= block_size;
        in += block_size;
        out_len_ -= block_size;
        out += block_size;
      }
      // pad last block
      memmove(last, in, len);
      if (cx_pad(last, len, mode & CX_MASK_PAD, block_size, &len) != CX_OK) {
        return CX_INVALID_PARAMETER;
      }
      in  = last;
      len_out += len;
      // if last block exist,
      while (len) {
        // next block, xored with previous encryped block
        cx_memxor(block, in, block_size);
        // encrypt block
        CX_CHECK(func(block, block));
        // set block result
        memmove(out, block, block_size);
        //++
        len -= block_size;
        in += block_size;
        out_len_ -= block_size;
        out += block_size;
      }
      break;

      // --- DECRYPTION ---
    case CX_DECRYPT: // Pi = Dec(Ci) xor Ci_1
      // all blocks but last
      len_out = len - block_size;
      while (len > block_size) {
        // next block
        memmove(block, in, block_size);
        // decrypt
        CX_CHECK(func(block, block));
        // xor with previous encrypted block
        cx_memxor(block, last, block_size);
        // keep current crypted block for next loop
        memmove(last, in, block_size);
        // set block result
        memmove(out, block, block_size);
        //++
        len -= block_size;
        in += block_size;
        out_len_ -= block_size;
        out += block_size;
      }
      // last block
      memmove(block, in, block_size);
      CX_CHECK(func(block, block));
      cx_memxor(block, last, block_size);
      if (cx_unpad(block, mode & CX_MASK_PAD, block_size, &len) != CX_OK) {
        return CX_INVALID_PARAMETER;
      }
      memmove(out, block, len);
      len_out += len;
      break;

      // --- OOPS ---
    default:
      return CX_INVALID_PARAMETER;
    }
    break;

    // === ECB ===
  case CX_CHAIN_ECB:
    switch (cx_mode) {
      // --- ENCRYPTION ---
    case CX_ENCRYPT:
      // all blocks
      len_out = len - len % block_size;
      while (len >= block_size) {
        CX_CHECK(func(in, out));
        len -= block_size;
        in += block_size;
        out += block_size;
      }
      memmove(last, in, len);
      if (cx_pad(last, len, mode & CX_MASK_PAD, block_size, &len) != CX_OK) {
        return CX_INVALID_PARAMETER;
      }
      in  = last;
      len_out += len;
      if (len > out_len_) {
        return CX_INVALID_PARAMETER;
      }
      while (len) {
        CX_CHECK(func(in, out));
        len -= block_size;
        in += block_size;
        out_len_ -= block_size;
        out += block_size;
      }
      break;

      // --- DECRYPTION ---
    case CX_DECRYPT:
      // all blocks but last
      len_out = len - block_size;
      while (len > block_size) {
        CX_CHECK(func(in, out));
        len -= block_size;
        in += block_size;
        out += block_size;
        out_len_ -= block_size;
      }
      memmove(block, in, len);
      CX_CHECK(func(block, block));
      if (cx_unpad(block, mode & CX_MASK_PAD, block_size, &len) != CX_OK) {
        return CX_INVALID_PARAMETER;
      }
      memmove(out, block, len);
      len_out += len;
      break;

      // --- OOPS ---
    default:
      return CX_INVALID_PARAMETER;
    }

    break;

    // === CTR ===
  case CX_CHAIN_CTR:
    // --- DECRYPTION && ENCRYPTION ---
    if (iv == NULL) {
      return CX_INVALID_PARAMETER;
    }
    len_out  = len;
    memmove(last, iv, block_size);
    while (len) {
      lblock = (len>block_size) ? block_size : len;
      CX_CHECK(func(last, block));
      memmove(out, in, lblock);
      cx_memxor(out,block,lblock);
      len -= lblock;
      in += lblock;
      out += lblock;
      lblock = ((last[block_size-1] << 0)  |
                (last[block_size-2] << 8)  |
                (last[block_size-3] << 16) |
                (last[block_size-4] << 24));
      lblock++;
      last[block_size-1] = lblock >> 0;
      last[block_size-2] = lblock >> 8;
      last[block_size-3] = lblock >> 16;
      last[block_size-4] = lblock >> 24;
    }
    break;

    // --- OOPS ---
  default:
    return CX_INVALID_PARAMETER;
  }
  switch (algo) {
#ifdef HAVE_DES
  case ALGO_DES:
    cx_des_reset_hw();
    break;
#endif
#ifdef HAVE_AES
  case ALGO_AES:
    cx_aes_reset_hw();
    break;
#endif
  default:
    return CX_INVALID_PARAMETER;
  }

  *out_len = len_out;

 end:
  return error;
}

/* ----------------------------------------------------------------------- */
/*                                                                         */
/* ----------------------------------------------------------------------- */
#ifdef HAVE_DES
cx_err_t cx_des_no_throw(const cx_des_key_t *key, uint32_t mode, const uint8_t *in, size_t len, uint8_t *out, size_t *out_len) {
  return cx_des_iv_no_throw(key, mode, NULL, 0, in, len, out, out_len);
}

cx_err_t cx_des_iv_no_throw(const cx_des_key_t *key,
                 uint32_t            mode,
                 const uint8_t *     iv,
                 size_t              iv_len,
                 const uint8_t *     in,
                 size_t              len,
                 uint8_t *           out,
                 size_t *            out_len) {
  size_t out_len_ = *out_len;

  // cx_scc_struct_check_deskey(key);
  if (iv) {
    if (iv_len != CX_DES_BLOCK_SIZE) {
      return CX_INVALID_PARAMETER;
    }
  } else {
    if (iv_len != 0) {
      return CX_INVALID_PARAMETER;
    }
  }
  if (in == NULL) {
    if (len != 0) {
      return CX_INVALID_PARAMETER;
    }
  }
  if (((mode & CX_MASK_SIGCRYPT) == CX_SIGN) || ((mode & CX_MASK_SIGCRYPT) == CX_VERIFY)) {
    if (out_len_ < 8) {
      return CX_INVALID_PARAMETER;
    }
  } else if ((mode & CX_MASK_SIGCRYPT) == CX_DECRYPT) {
    if (out_len_ < len) {
      return CX_INVALID_PARAMETER;
    }
  } else if ((mode & CX_MASK_SIGCRYPT) == CX_ENCRYPT) {
    // depends on padding !
    if ((mode & CX_MASK_PAD) == CX_PAD_NONE) {
      if (out_len_ < UPPER_ALIGN(len, 8, size_t)) {
        return CX_INVALID_PARAMETER;
      }
    } else {
      if (out_len_ < UPPER_ALIGN(len + 7, 8, size_t)) {
        return CX_INVALID_PARAMETER;
      }
    }
  }
  return cx_ades(key, mode, iv, iv_len, in, len, out, out_len, ALGO_DES);
}
#endif

/* ----------------------------------------------------------------------- */
/*                                                                         */
/* ----------------------------------------------------------------------- */
#ifdef HAVE_AES
cx_err_t cx_aes_no_throw(const cx_aes_key_t *key, uint32_t mode, const uint8_t *in, size_t in_len, uint8_t *out, size_t *out_len) {
  return cx_aes_iv_no_throw(key, mode, NULL, 0, in, in_len, out, out_len);
}

cx_err_t cx_aes_iv_no_throw(const cx_aes_key_t *key,
                   uint32_t            mode,
                   const uint8_t *     iv,
                   size_t              iv_len,
                   const uint8_t *     in,
                   size_t              in_len,
                   uint8_t *           out,
                   size_t *            out_len) {
  size_t out_len_ = *out_len;

  // cx_scc_struct_check_aeskey(key);
  if (iv) {
    if (iv_len != CX_AES_BLOCK_SIZE) {
      return CX_INVALID_PARAMETER;
    }
  } else {
    if (iv_len != 0) {
      return CX_INVALID_PARAMETER;
    }
  }
  if (in == NULL) {
    if (in_len != 0) {
      return CX_INVALID_PARAMETER;
    }
  }
  if (((mode & CX_MASK_SIGCRYPT) == CX_SIGN) || ((mode & CX_MASK_SIGCRYPT) == CX_VERIFY)) {
    if (out_len_ < 16) {
      return CX_INVALID_PARAMETER;
    }
  } else if ((mode & CX_MASK_SIGCRYPT) == CX_DECRYPT) {
    if (out_len_ < in_len) {
      return CX_INVALID_PARAMETER;
    }
  } else if ((mode & CX_MASK_SIGCRYPT) == CX_ENCRYPT) {
    // depends on padding !
    if ((mode & CX_MASK_PAD) == CX_PAD_NONE) {
      if (out_len_ < UPPER_ALIGN(in_len, 16, size_t)) {
        return CX_INVALID_PARAMETER;
      }
    } else {
      if (out_len_ < UPPER_ALIGN(in_len + 15, 16, size_t)) {
        return CX_INVALID_PARAMETER;
      }
    }
  }
  return cx_ades(key, mode, iv, iv_len, in, in_len, out, out_len, ALGO_AES);
}
#endif

static cx_err_t cx_pad(uint8_t *buff, size_t len, uint32_t pad, size_t block_size, size_t *padded_size) {
  *padded_size = 0;
  switch (pad) {
  case CX_PAD_NONE:
    return CX_OK;

  case CX_PAD_ISO9797M1:
    if (len == 0) {
      return CX_OK;
    }
  _CX_PAD_ISO9797M1:
    buff += len;
    while (len < block_size) {
      *buff = 0;
      buff++;
      len++;
    }
    *padded_size += block_size;
    return CX_OK;

  case CX_PAD_ISO9797M2:
    if (len == block_size) {
      *padded_size = block_size;
    }
    buff[len] = 0x80;
    len++;
    goto _CX_PAD_ISO9797M1;
  default:
    break;
  }
  return CX_INVALID_PARAMETER;
}

static inline uint32_t neq_zero(uint32_t x) {
  return (x|-x)>>31;
}

// returns cond ? a : b
static inline uint32_t conditional_choice(uint32_t a, uint32_t b, uint32_t cond) {
  return (a ^ b) ^ (b & (-cond));
}

static cx_err_t cx_unpad(uint8_t *buff, uint32_t pad, size_t block_size, size_t *padded_size) {
  cx_err_t error = CX_INVALID_PARAMETER;
  switch (pad) {
  case CX_PAD_NONE:
  case CX_PAD_ISO9797M1:
    *padded_size = block_size;
    error = CX_OK;
    break;

  case CX_PAD_ISO9797M2:
    {
      uint32_t acc = 0; // keeps track of consecutive zeroes
      // result[0] is 1 if the padding is correct
      // result[1] serves as a dummy value for constant time purposes
      uint8_t result[2] = {0};

      // padsize[0] will containt the padding length
      // padsize[1] is a dummy value
      uint8_t padsize[2] = {0}; 

      for(int32_t i=block_size-1;i>=0;i--) {
        uint32_t is_0x80 = neq_zero(buff[i] ^ 0x80); // 0 if current byte == 0x80
        uint32_t is_zero = neq_zero(acc);

        result[is_0x80 | is_zero] = 1; // result[0] == 1 if t==0 and is_zero==0
        padsize[is_0x80 | is_zero] = i; // update padded_size the same way

        acc |= buff[i];
      }
      *padded_size = padsize[0]; // this is 0 if padding is invalid
      uint32_t is_correct = neq_zero((uint32_t)result[0]);
      error = conditional_choice(CX_OK, CX_INVALID_PARAMETER, is_correct);
    }
    break;
  default:
    break;
  }

  return error;
}

#ifdef HAVE_AES

cx_err_t cx_aes_enc_block(const cx_aes_key_t *key, const uint8_t *inblock, uint8_t *outblock) {
  cx_err_t error;
  CX_CHECK(cx_aes_set_key_hw(key, CX_ENCRYPT));
  CX_CHECK(cx_aes_block_hw(inblock, outblock));
  cx_aes_reset_hw();
 end:
  return error;
}

cx_err_t cx_aes_dec_block(const cx_aes_key_t *key, const uint8_t *inblock, uint8_t *outblock) {
  cx_err_t error;
  CX_CHECK(cx_aes_set_key_hw(key, CX_DECRYPT));
  CX_CHECK(cx_aes_block_hw(inblock, outblock));
  cx_aes_reset_hw();
 end:
  return error;
}
#endif


#ifdef HAVE_DES

void cx_des_enc_block(const cx_des_key_t *key, const uint8_t *inblock, uint8_t *outblock) {
  cx_des_set_key_hw(key, CX_ENCRYPT);
  cx_des_block_hw(inblock, outblock);
  cx_des_reset_hw();
}

void cx_des_dec_block(const cx_des_key_t *key, const uint8_t *inblock, uint8_t *outblock) {
  cx_des_set_key_hw(key, CX_DECRYPT);
  cx_des_block_hw(inblock, outblock);
  cx_des_reset_hw();
}
#endif
#endif // defines(HAVE_DES) || defined(HAVE_AES)

#ifdef UNITTEST
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <stdint.h>
#include <cmocka.h>

static void test_iso9797_method2_unpad(void **state) {
  uint8_t buf1[8] = {0, 1, 2, 3, 4, 5, 6, 0x80};
  size_t unpadded_size = 0;
  assert_int_equal(cx_unpad(buf1, CX_PAD_ISO9797M2, 8, &unpadded_size), CX_OK);
  assert_int_equal(unpadded_size, 7);

  uint8_t buf2[8] = {0, 1, 2, 3, 0x80, 0, 0, 0};
  unpadded_size = 0;
  assert_int_equal(cx_unpad(buf2, CX_PAD_ISO9797M2, 8, &unpadded_size), CX_OK);
  assert_int_equal(unpadded_size, 4);

  unpadded_size = 0;
  uint8_t buf3[8] = {0, 1, 2, 3, 4, 5, 6, 7};
  assert_int_equal(cx_unpad(buf3, CX_PAD_ISO9797M2, 8, &unpadded_size), CX_INVALID_PARAMETER);

  uint8_t buf4[8] = {0, 1, 2, 3, 4, 5, 0x80, 7};
  unpadded_size = 0;
  assert_int_equal(cx_unpad(buf4, CX_PAD_ISO9797M2, 8, &unpadded_size), CX_INVALID_PARAMETER);

  uint8_t buf5[8] = {0x80, 0, 0, 0, 0, 0, 0, 0};
  unpadded_size = 0;
  assert_int_equal(cx_unpad(buf5, CX_PAD_ISO9797M2, 8, &unpadded_size), CX_OK);
  assert_int_equal(unpadded_size, 0);
}

static void test_iso9797_method2_pad(void **state) {
  uint8_t buf1[8] = {0};
  const uint8_t buf1_padded[8] = {0x80, 0, 0, 0, 0, 0, 0, 0};

  size_t padded_size = 0;
  assert_int_equal(cx_pad(buf1, 0, CX_PAD_ISO9797M2, 8, &padded_size), CX_OK);
  assert_int_equal(padded_size, 8);
  assert_memory_equal(buf1, buf1_padded, sizeof(buf1_padded));

  uint8_t buf2[8] = {0xaa, 0xbb, 0xcc};
  const uint8_t buf2_padded[8] = {0xaa, 0xbb, 0xcc, 0x80, 0, 0, 0, 0};

  padded_size = 0;
  assert_int_equal(cx_pad(buf2, 3, CX_PAD_ISO9797M2, 8, &padded_size), CX_OK);
  assert_int_equal(padded_size, 8);
  assert_memory_equal(buf2, buf2_padded, sizeof(buf2_padded));

  padded_size = 0;
  uint8_t buf3[16] = {0, 1, 2, 3, 4, 5, 6, 7};
  const uint8_t buf3_padded[16] = {0, 1, 2, 3, 4, 5, 6, 7, 0x80, 0, 0, 0, 0, 0, 0, 0};
  assert_int_equal(cx_pad(buf3, 8, CX_PAD_ISO9797M2, 8, &padded_size), CX_OK);
  assert_int_equal(padded_size, 16);
  assert_memory_equal(buf3, buf3_padded, sizeof(buf3_padded));
}

int main() {
  const struct CMUnitTest tests[] = {
    cmocka_unit_test(test_iso9797_method2_pad),
    cmocka_unit_test(test_iso9797_method2_unpad),
  };

  return cmocka_run_group_tests(tests, NULL, NULL);
}
#endif // UNITTEST
