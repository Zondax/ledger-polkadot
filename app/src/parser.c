/*******************************************************************************
*   (c) 2019 Zondax GmbH
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

#include <stdio.h>
#include <zxmacros.h>
#include "zbuffer.h"
#include "parser.h"
#include "coin.h"
#include "coin_ss58.h"
#include "substrate_dispatch.h"

#if defined(APP_RESTRICTED)
#include "coin.h"
#include "crypto.h"
#include "substrate_methods.h"
#include "allowlist.h"
#endif

#if defined(TARGET_NANOX)
// For some reason NanoX requires this function
void __assert_fail(const char * assertion, const char * file, unsigned int line, const char * function){
    while(1) {};
}
#endif

#define FIELD_FIXED_TOTAL_COUNT 7

#define FIELD_METHOD        0
#define FIELD_NETWORK       1
#define FIELD_ONCE          2
#define FIELD_TIP           3
#define FIELD_ERA_PHASE     4
#define FIELD_ERA_PERIOD    5
#define FIELD_BLOCK_HASH    6

parser_error_t parser_parse(parser_context_t *ctx, const uint8_t *data, size_t dataLen, parser_tx_t *tx_obj) {
    CHECK_PARSER_ERR(parser_init(ctx, data, dataLen))
    ctx->tx_obj = tx_obj;
    parser_error_t err = _readTx(ctx, ctx->tx_obj);
    CTX_CHECK_AVAIL(ctx, 0)
    zb_check_canary();

    return err;
}

#if defined(APP_RESTRICTED)
parser_error_t parser_validate_vecLookupSource(pd_VecLookupSource_t *targets) {
    if (!allowlist_is_active()) {
        return parser_not_allowed;
    }

    parser_context_t ctx;
    // each look up source is 32 bytes
    pd_LookupSource_t lookupSource;

    parser_init(&ctx, targets->_ptr, targets->_lenBuffer);
    for (uint16_t i = 0; i < targets->_len; i++) {
        CHECK_ERROR(_readLookupSource(&ctx, &lookupSource));
        char buffer[100];
        uint8_t dummy;
        CHECK_ERROR(_toStringLookupSource(&lookupSource, buffer, sizeof(buffer), 0, &dummy));

        if (!allowlist_item_validate(buffer)) {
            return parser_not_allowed;
        }
    }

    return parser_ok;
}
#endif

parser_error_t parser_validate(const parser_context_t *ctx) {
    // Iterate through all items to check that all can be shown and are valid
    uint8_t numItems = 0;
    CHECK_PARSER_ERR(parser_getNumItems(ctx, &numItems));

    char tmpKey[40];
    char tmpVal[40];

    for (uint8_t idx = 0; idx < numItems; idx++) {
        uint8_t pageCount = 0;
        CHECK_PARSER_ERR(parser_getItem(ctx, idx, tmpKey, sizeof(tmpKey), tmpVal, sizeof(tmpVal), 0, &pageCount))
    }

#if defined(APP_RESTRICTED)
    if (hdPath[2] == HDPATH_2_STASH) {
        if (ctx->tx_obj->callIndex.moduleIdx == PD_CALL_STAKING) {
            if (ctx->tx_obj->callIndex.idx==PD_CALL_STAKING_SET_PAYEE) {
                return parser_ok;
            }
            if (ctx->tx_obj->callIndex.idx==PD_CALL_STAKING_NOMINATE) {
                pd_VecLookupSource_t *targets = &ctx->tx_obj->method.basic.staking_nominate.targets;
                CHECK_PARSER_ERR(parser_validate_vecLookupSource(targets))
                return parser_ok;
            }
        }
    }
    if (hdPath[2] == HDPATH_2_VALIDATOR) {
        if (ctx->tx_obj->callIndex.moduleIdx == PD_CALL_STAKING) {
            if (ctx->tx_obj->callIndex.idx==PD_CALL_STAKING_SET_PAYEE) {
                return parser_ok;
            }
            if (ctx->tx_obj->callIndex.idx==PD_CALL_STAKING_VALIDATE) {
                return parser_ok;
            }
        }
        if (ctx->tx_obj->callIndex.moduleIdx == PD_CALL_SESSION) {
            if (ctx->tx_obj->callIndex.idx==PD_CALL_SESSION_SET_KEYS) {
                return parser_ok;
            }
            if (ctx->tx_obj->callIndex.idx==PD_CALL_SESSION_PURGE_KEYS) {
                return parser_ok;
            }
        }
    }
    return parser_not_allowed;
#endif
    return parser_ok;
}

parser_error_t parser_getNumItems(const parser_context_t *ctx, uint8_t *num_items) {
    uint8_t methodArgCount = _getMethod_NumItems(ctx->tx_obj->callIndex.moduleIdx,
                                                 ctx->tx_obj->callIndex.idx,
                                                 &ctx->tx_obj->method);

    *num_items = FIELD_FIXED_TOTAL_COUNT + methodArgCount;
    return parser_ok;
}

parser_error_t parser_getItem(const parser_context_t *ctx,
                              uint8_t displayIdx,
                              char *outKey, uint16_t outKeyLen,
                              char *outVal, uint16_t outValLen,
                              uint8_t pageIdx, uint8_t *pageCount) {
    MEMZERO(outKey, outKeyLen);
    MEMZERO(outVal, outValLen);
    snprintf(outKey, outKeyLen, "?");
    snprintf(outVal, outValLen, "?");
    *pageCount = 1;

    uint8_t numItems;
    CHECK_PARSER_ERR(parser_getNumItems(ctx, &numItems))
    CHECK_APP_CANARY()

    if (displayIdx < 0 || displayIdx >= numItems) {
        return parser_no_data;
    }

    parser_error_t err = parser_ok;
    if (displayIdx == FIELD_METHOD) {
        snprintf(outKey, outKeyLen, "%s", _getMethod_ModuleName(ctx->tx_obj->callIndex.moduleIdx));
        snprintf(outVal, outValLen, "%s", _getMethod_Name(ctx->tx_obj->callIndex.moduleIdx,
                                                          ctx->tx_obj->callIndex.idx));
        return err;
    }

    // VARIABLE ARGUMENTS
    uint8_t methodArgCount = _getMethod_NumItems(ctx->tx_obj->callIndex.moduleIdx,
                                                 ctx->tx_obj->callIndex.idx,
                                                 &ctx->tx_obj->method);
    uint8_t argIdx = displayIdx - 1;
    if (argIdx < methodArgCount) {
        snprintf(outKey, outKeyLen, "%s",
                 _getMethod_ItemName(ctx->tx_obj->callIndex.moduleIdx,
                                     ctx->tx_obj->callIndex.idx,
                                     argIdx));

        err = _getMethod_ItemValue(&ctx->tx_obj->method,
                                   ctx->tx_obj->callIndex.moduleIdx, ctx->tx_obj->callIndex.idx, argIdx,
                                   outVal, outValLen,
                                   pageIdx, pageCount);
    } else {
        // CONTINUE WITH FIXED ARGUMENTS
        // FIXME: Review. We can probably show this only in expert mode
        displayIdx -= methodArgCount;
        switch (displayIdx) {
            case FIELD_NETWORK:
                if (_getAddressType() == PK_ADDRESS_TYPE) {
                    snprintf(outKey, outKeyLen, "Chain");
                    snprintf(outVal, outValLen, COIN_NAME);
                    break;
                }
                snprintf(outKey, outKeyLen, "Genesis Hash");
                _toStringHash(&ctx->tx_obj->genesisHash,
                              outVal, outValLen,
                              pageIdx, pageCount);
                break;
            case FIELD_ONCE:
                snprintf(outKey, outKeyLen, "Nonce");
                _toStringCompactIndex(&ctx->tx_obj->nonce,
                                      outVal, outValLen,
                                      pageIdx, pageCount);
                break;
            case FIELD_TIP:
                snprintf(outKey, outKeyLen, "Tip");
                _toStringCompactBalance(&ctx->tx_obj->tip,
                                        outVal, outValLen,
                                        pageIdx, pageCount);
                break;
            case FIELD_ERA_PHASE:
                snprintf(outKey, outKeyLen, "Era Phase");
                uint64_to_str(outVal, outValLen, ctx->tx_obj->era.phase);
                break;
            case FIELD_ERA_PERIOD:
                snprintf(outKey, outKeyLen, "Era Period");
                uint64_to_str(outVal, outValLen, ctx->tx_obj->era.period);
                break;
            case FIELD_BLOCK_HASH:
                snprintf(outKey, outKeyLen, "Block");
                _toStringHash(&ctx->tx_obj->blockHash,
                              outVal, outValLen,
                              pageIdx, pageCount);
                break;
            default:
                return parser_no_data;
        }
    }

    return err;
}
