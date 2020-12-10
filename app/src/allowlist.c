/*******************************************************************************
*   (c) 2020 Zondax GmbH
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

#if defined(APP_RESTRICTED)

#include "os.h"
#include "cx.h"
#include "coin.h"
#include "app_main.h"
#include "tx.h"
#include "allowlist.h"

typedef struct {
    uint8_t has_been_set;
    union {
        struct {
            uint8_t dummy;
            uint8_t pubkey[32];
        };
        struct {
            uint8_t ledger_pubkey[33];
        };
    };
} allowlist_metadata_t;

allowlist_t NV_CONST
N_allowlist_impl __attribute__ ((aligned(64)));
allowlist_metadata_t NV_CONST
N_allowlist_metadata_impl __attribute__ ((aligned(64)));

#define N_allowlist (*(NV_VOLATILE allowlist_t *)PIC(&N_allowlist_impl))
#define N_allowlist_metadata (*(NV_VOLATILE allowlist_metadata_t *)PIC(&N_allowlist_metadata_impl))

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

bool allowlist_pubkey_is_set() {
    return N_allowlist_metadata.has_been_set;
}

bool allowlist_pubkey_get(uint8_t *out, size_t outLen) {
    if (!allowlist_pubkey_is_set()) {
        return false;
    }
    if (outLen < 32) {
        return false;
    }

    MEMCPY(out, N_allowlist_metadata.pubkey, 32);
    return true;
}

bool allowlist_pubkey_set(const uint8_t *in, size_t inLen) {
    allowlist_metadata_t metadata;

    metadata.has_been_set = 1;
    metadata.dummy = 0x02;          // Required by Ledger's SDK
    MEMCPY(&metadata.pubkey, in, inLen);
    MEMCPY_NV( (void*) &N_allowlist_metadata, (void*) &metadata, sizeof(allowlist_metadata_t));

    return true;
}

bool allowlist_is_active() {
    return allowlist_pubkey_is_set() && N_allowlist.header.len > 0;
}

bool allowlist_item_validate(const char *address) {
    if (!allowlist_is_active()) {
        return false;
    }

    if (N_allowlist.header.len >= ALLOW_LIST_SIZE) {
        return false;
    }

    char buffer[100];
    for (size_t i = 0; i < N_allowlist.header.len; i++) {
        const char * p = (const char *) PIC(N_allowlist.items[i].address);
        if (strncmp(p, (const char *) address, ALLOW_LIST_ITEM_ADDRESS_SIZE) == 0) {
            snprintf(buffer, sizeof(buffer), "Check OK: %s\n", address);
            zemu_log(buffer);
            return true;
        }
    }

    snprintf(buffer, sizeof(buffer), "No matches: %s\n", address);
    zemu_log(buffer);
    return false;
}

void allowlist_calculate_digest(uint8_t *digest, const allowlist_t *list) {
    cx_blake2b_t ctx;
    cx_blake2b_init(&ctx, 256);
    cx_hash(&ctx.header, 0, (uint8_t *) &list->header.nonce, sizeof(uint32_t), NULL, 0);
    cx_hash(&ctx.header, 0, (uint8_t *) &list->header.len, sizeof(uint32_t), NULL, 0);
    const uint8_t *data = (uint8_t *) PIC(list->items);
    const size_t dataLen = sizeof(allowlist_item_t) * list->header.len;
    cx_hash(&ctx.header, CX_LAST, data, dataLen, digest, 32);
}

void allowlist_hash(uint8_t *digest) {
    allowlist_calculate_digest(digest, &N_allowlist);
}

bool allowlist_list_validate(const uint8_t *new_list_buffer, size_t new_list_buffer_len) {
    if (!allowlist_pubkey_is_set()) {
        zemu_log_stack("allowlist: ERR pubkey not set");
        return false;
    }

    if (new_list_buffer == NULL) {
        zemu_log_stack("allowlist: ERR new_list_buffer empty");
        return false;
    }

    if (new_list_buffer_len < sizeof(uint32_t)) {
        // new list does not have enough data to contain the header
        zemu_log_stack("allowlist: ERR not enough data");
        return false;
    }

    // Let's check number of items
    allowlist_t *new_list = (allowlist_t *) new_list_buffer;
    if (new_list->header.len >= ALLOW_LIST_SIZE) {
        char buffer[30];
        snprintf(buffer, sizeof(buffer), "%d", new_list->header.len);
        zemu_log_stack(buffer);
        zemu_log_stack("allowlist: ERR Too many elements");
        return false;
    }

    // Check size is correct. Header (signature+len) + items * len
    const size_t expected_size = sizeof(allowlist_header_t) + sizeof(allowlist_item_t) * new_list->header.len;
    if (new_list_buffer_len != expected_size) {
        zemu_log_stack("allowlist: ERR unexpected size");
        return false;
    }

    // If there is already a list, check that nonce is moving forward
    if (allowlist_is_active() && new_list->header.nonce <= N_allowlist.header.nonce) {
        zemu_log_stack("allowlist: ERR invalid nonce");
        return false;
    }

    zemu_log_stack("\n");
    // Hash allowlist (len + items)
    uint8_t digest[32];
    allowlist_calculate_digest(digest, new_list);

    zemu_log_stack("Digest ready");

    // Confirm Ed25519 signature is valid
    // *     - '04 x y'  or '02 y' (plus sign) for twisted Edward curves
    uint8_t pubkey_XY[65];
    MEMCPY(pubkey_XY, (const uint8_t *) PIC(N_allowlist_metadata.ledger_pubkey), 33);
    cx_edward_decompress_point(CX_CURVE_Ed25519, pubkey_XY, sizeof(pubkey_XY));

    cx_ecfp_public_key_t cx_publicKey;
    cx_ecfp_init_public_key(CX_CURVE_Ed25519, pubkey_XY, 65, &cx_publicKey);
    zemu_log_stack("Decompressed key imported");

    zemu_log("********************** \n\n");

    char buf[140];
    array_to_hexstr(buf, sizeof(buf), (const uint8_t *) digest, 32);
    zemu_log("dig :"); zemu_log(buf); zemu_log("\n");
    array_to_hexstr(buf, sizeof(buf), (const uint8_t *) PIC(N_allowlist_metadata.ledger_pubkey), 33);
    zemu_log("pk  :"); zemu_log(buf); zemu_log("\n");
    array_to_hexstr(buf, sizeof(buf), (const uint8_t *) new_list->header.signature, 64);
    zemu_log("sig :"); zemu_log(buf); zemu_log("\n");

    snprintf(buf, sizeof(buf), "w    %d\n", cx_publicKey.W[0]);
    zemu_log(buf);
    snprintf(buf, sizeof(buf), "wlen %d\n", cx_publicKey.W_len);
    zemu_log(buf);

    zemu_log("\n\n********************** \n");

    bool valid_signature = cx_eddsa_verify(&cx_publicKey,
                           0, CX_SHA512,
                           digest, sizeof(digest), NULL, 0,
                           new_list->header.signature, 64) == 1;

    if (valid_signature) {
        zemu_log_stack("verified OK");
    } else {
        zemu_log_stack("verified ERR");
    }

    return valid_signature;
}

bool allowlist_upgrade(const uint8_t *new_list_buffer, size_t new_list_buffer_len) {
    if (!allowlist_list_validate(new_list_buffer, new_list_buffer_len)) {
        // conditions to update allowlist are not satisfied
        return false;
    }
    MEMCPY_NV( (void*) PIC(&N_allowlist), (void*) PIC(new_list_buffer), new_list_buffer_len);
    return true;
}

zxerr_t allowlist_getNumItems(uint8_t *num_items) {
    zemu_log_stack("allowlist_getNumItems");
    *num_items = 1;
    return zxerr_ok;
}

zxerr_t allowlist_getItem(int8_t displayIdx,
                          char *outKey, uint16_t outKeyLen,
                          char *outVal, uint16_t outValLen,
                          uint8_t pageIdx, uint8_t *pageCount) {
    zemu_log_stack("allowlist_getItem");
    if (displayIdx != 0) {
        return zxerr_no_data;
    }

    switch (G_io_apdu_buffer[OFFSET_INS]) {
        case INS_ALLOWLIST_SET_PUBKEY: {
            snprintf(outKey, outKeyLen, "Set Pubkey");

            char bufferUI[100];
            if (array_to_hexstr(bufferUI, sizeof(bufferUI), G_io_apdu_buffer+OFFSET_DATA, 32) != 64) {
                return zxerr_encoding_failed;
            }
            pageString(outVal, outValLen, bufferUI, pageIdx, pageCount);
            return zxerr_ok;
        }
        case INS_ALLOWLIST_UPLOAD: {
            snprintf(outKey, outKeyLen, "Allowlist Upload");

            uint8_t digest[32];
            allowlist_t *new_list = (allowlist_t *) tx_get_buffer();
            allowlist_calculate_digest(digest, new_list);

            char bufferUI[100];
            if (array_to_hexstr(bufferUI, sizeof(bufferUI), digest, sizeof(digest)) != 64) {
                return zxerr_encoding_failed;
            }
            pageString(outVal, outValLen, bufferUI, pageIdx, pageCount);
            return zxerr_ok;
        }
        default:
            break;
    }

    return zxerr_no_data;
}

#endif
