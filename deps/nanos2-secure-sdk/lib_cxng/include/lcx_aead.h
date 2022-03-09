
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

/**
 * @file    lcx_aead.h
 * @brief   Authenticated Encryption with Associated Data (AEAD)
 *
 * @section Description
 *
 * Authenticated encryption provides confidentiality for the plaintext
 * and integrity and authenticity checks. Authentication Encryption with
 * Associated Data enables to check the integrity and authenticity of
 * some associated data called "additional authenticated data".
 *
 * @author  Ledger
 * @version 1.0
 **/

#if defined(HAVE_AEAD) && defined(HAVE_AES_GCM)

#ifndef LCX_AEAD_H
#define LCX_AEAD_H

#include "cx_errors.h"
#include "lcx_aes_gcm.h"
#include <stddef.h>

#define MAX_IV_LENGTH    64
#define MAX_TAG_LENGTH   16

/**
 * @brief Supported AEAD algorithms.
 */
typedef enum {
  CX_AEAD_AES128_GCM,
  CX_AEAD_AES192_GCM,
  CX_AEAD_AES256_GCM,
} cx_aead_type_t;

/**
 * @brief AEAD information.
 */

typedef struct {
  cx_aead_type_t type;       ///< AEAD algorithm
  size_t         key_bitlen; ///< Bit length of the key
  size_t         block_size; ///< Block size
} cx_aead_info_t;

/**
 * @brief AEAD context.
 */
typedef struct {
  const cx_aead_info_t *info;                  ///< Pointer to the AEAD information
  cx_aes_gcm_context_t *aes_gcm_ctx;           ///< Pointer to the AES-GCM context
  uint32_t              mode;                  ///< Encrypt or decrypt
  uint8_t               iv_set[MAX_IV_LENGTH]; ///< Initialization vector
  size_t                iv_set_len;            ///< Length of the IV
} cx_aead_context_t;

/**
 * @brief AEAD initialization.
 * 
 * @param[in] ctx Pointer to the AEAD context.
 * 
 * @return        Error code.
 */
cx_err_t cx_aead_init(cx_aead_context_t *ctx);

/**
 * @brief   AEAD set up.
 * 
 * @details The AEAD context must be initialized. Initialization of the specific AEAD algorithm context.
 *          Supported AEAD algorithm:
 *            - AES-GCM
 * 
 * @param[in] ctx  Pointer to the AEAD context.
 * 
 * @param[in] type AEAD algorithm.
 * 
 * @return         Error code
 */
cx_err_t cx_aead_setup(cx_aead_context_t *ctx, cx_aead_type_t type);

/**
 * @brief   Set the cipher key.
 * 
 * @details The AEAD context must be set up.
 * 
 * @param[in] ctx     Pointer to the AEAD context.
 * 
 * @param[in] key     Cipher key.
 * 
 * @param[in] key_len Length of the key.
 * 
 * @param[in] mode    Operation the key will be used for: encryption or decryption.
 * 
 * @return            Error code
 */
cx_err_t cx_aead_set_key(cx_aead_context_t *ctx, const uint8_t *key, size_t key_len, uint32_t mode);

/**
 * @brief   Set the initialization vector.
 * 
 * @details The AEAD context must be set up. The initialization vector is kept within the context.
 * 
 * @param[in] ctx    Pointer to the AEAD context.
 * 
 * @param[in] iv     Initialization vector.
 * 
 * @param[in] iv_len Length of the initialization vector.
 * 
 * @return           Error code.
 */
cx_err_t cx_aead_set_iv(cx_aead_context_t *ctx, const uint8_t *iv, size_t iv_len);

/**
 * @brief   Add associated data to the context.
 * 
 * @details The AEAD context must be set up. The data length and the processed data
 *          are kept within the context.
 * 
 * @param[in] ctx    Pointer to the AEAD context.
 * 
 * @param[in] ad     Associated data to add.
 * 
 * @param[in] ad_len Length of the associated data.
 * 
 * @return           Error code.
 */
cx_err_t cx_aead_update_ad(cx_aead_context_t *ctx, const uint8_t *ad, size_t ad_len);

/**
 * @brief   Update the data to encrypt or decrypt.
 * 
 * @details The AEAD context must be set up. The input length and the processed input
 *          are kept within the context.
 * 
 * @param[in]  ctx     Pointer to the AEAD context. 
 * 
 * @param[in]  in      Input data.
 * 
 * @param[in]  in_len  Length of the input.
 * 
 * @param[out] out     Buffer the output data. This must be able to hold at least in_len + block_size.
 *                     This must be not the same buffer as in.
 * 
 * @param[out] out_len The length of the output data. This must not be NULL.
 * 
 * @return             Error code.
 * 
 */
cx_err_t cx_aead_update(cx_aead_context_t *ctx, uint8_t *in, size_t in_len, uint8_t *out, size_t *out_len);

/**
 * @brief   Write the tag of the AEAD cipher.
 * 
 * @details The AEAD context must be set up.
 * 
 * @param[in]  ctx     Pointer to the AEAD context.
 * 
 * @param[out] tag     Buffer to write the tag to.
 * 
 * @param[in]  tag_len Length of the tag.
 * 
 * @return             Error code.
 */
cx_err_t cx_aead_write_tag(cx_aead_context_t *ctx, uint8_t *tag, size_t tag_len);

/**
 * @brief   Check the tag of the AEAD cipher.
 * 
 * @details The AEAD context must be set up.
 * 
 * @param[in] ctx     Pointer to the AEAD context.
 * 
 * @param[in] tag     Buffer holding the tag.
 * 
 * @param[in] tag_len Length of the tag.
 * 
 * @return            Error code.
 */
cx_err_t cx_aead_check_tag(cx_aead_context_t *ctx, const uint8_t *tag, size_t tag_len);

/**
 * @brief   All-in-one authenticated encryption.
 * 
 * @details Perform an authenticated encryption according to the specified algorithm.
 *          The AEAD context must be set up.
 * 
 * @param[in]  ctx     Pointer to the AEAD context.
 * 
 * @param[in]  iv      Initialization vector.
 * 
 * @param[in]  iv_len  Length of the initialization vector.
 * 
 * @param[in]  ad      Associated data to authenticate.
 * 
 * @param[in]  ad_len  Length of the associated data.
 * 
 * @param[in]  in      Input data.
 * 
 * @param[in]  in_len  Length of the input data.
 * 
 * @param[out] out     Buffer for the output data.
 *
 * @param[out] out_len Length of the output data. This must not be NULL.
 * 
 * @param[out] tag     Buffer for the authentication tag.
 * 
 * @param[in]  tag_len Length of the tag.
 * 
 * @return             Error code.
 */
cx_err_t cx_aead_encrypt(cx_aead_context_t *ctx, const uint8_t *iv, size_t iv_len,
                         const uint8_t *ad, size_t ad_len, uint8_t *in, size_t in_len,
                         uint8_t *out, size_t *out_len, uint8_t *tag, size_t tag_len);

/**
 * @brief   All-in-one authenticated decryption.
 * 
 * @details Perform an authenticated decryption according to the specified algorithm.
 *          The AEAD context must be set up. If the data is not authentic then the
 *          output buffer is zeroed.
 * 
 * @param[in]  ctx     Pointer to the AEAD context.
 * 
 * @param[in]  iv      Initialization vector.
 * 
 * @param[in]  iv_len  Length of the initialization vector.
 * 
 * @param[in]  ad      Associated data to authenticate.
 * 
 * @param[in]  ad_len  Length of the associated data.
 * 
 * @param[in]  in      Input data.
 * 
 * @param[in]  in_len  Length of the input data.
 * 
 * @param[out] out     Buffer for the output data.
 *
 * @param[out] out_len Length of the output data. This must not be NULL.
 * 
 * @param[out] tag     Authentication tag to verify.
 * 
 * @param[in]  tag_len Length of the tag.
 * 
 * @return             Error code.
 */
cx_err_t cx_aead_decrypt(cx_aead_context_t *ctx, const uint8_t *iv, size_t iv_len,
                         const uint8_t *ad, size_t ad_len, uint8_t *in, size_t in_len,
                         uint8_t *out, size_t *out_len, const uint8_t *tag, size_t tag_len);

#endif
#endif // HAVE_AEAD && HAVE_AES_GCM
