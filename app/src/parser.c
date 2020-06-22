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
#include "parser.h"
#include "substrate_dispatch.h"
#include "coin.h"
#include "coin_ss58.h"

#if defined(APP_RESTRICTED)
#include "coin.h"
#include "crypto.h"
#include "substrate_methods.h"
#endif

#define FIELD_FIXED_TOTAL_COUNT 7

#define FIELD_METHOD        0
#define FIELD_NETWORK       1
#define FIELD_ONCE          2
#define FIELD_TIP           3
#define FIELD_ERA_PHASE     4
#define FIELD_ERA_PERIOD    5
#define FIELD_BLOCK_HASH    6

parser_error_t parser_parse(parser_context_t *ctx,
                            const uint8_t *data,
                            size_t dataLen) {
    parser_init(ctx, data, dataLen);
    return _readTx(ctx, &parser_tx_obj);
}

parser_error_t parser_validate(const parser_context_t *ctx) {
#if defined(APP_RESTRICTED)
    if (hdPath[2] == HDPATH_2_STASH) {
        if (parser_tx_obj.callIndex.moduleIdx == PD_CALL_STAKING) {
            if (parser_tx_obj.callIndex.idx==PD_CALL_STAKING_SET_PAYEE) {
                return parser_ok;
            }
            if (parser_tx_obj.callIndex.idx==PD_CALL_STAKING_NOMINATE) {
                // FIXME: Check allowlist
                return parser_ok;
            }
        }
    }
    if (hdPath[2] == HDPATH_2_VALIDATOR) {
        if (parser_tx_obj.callIndex.moduleIdx == PD_CALL_STAKING) {
            if (parser_tx_obj.callIndex.idx==PD_CALL_STAKING_SET_PAYEE) {
                return parser_ok;
            }
            if (parser_tx_obj.callIndex.idx==PD_CALL_STAKING_VALIDATE) {
                return parser_ok;
            }
        }
        if (parser_tx_obj.callIndex.moduleIdx == PD_CALL_SESSION) {
            if (parser_tx_obj.callIndex.idx==PD_CALL_SESSION_SET_KEYS) {
                return parser_ok;
            }
            if (parser_tx_obj.callIndex.idx==PD_CALL_SESSION_PURGE_KEYS) {
                return parser_ok;
            }
        }
    }
    return parser_not_supported;
#endif
    return parser_ok;
}

parser_error_t parser_getNumItems(const parser_context_t *ctx, uint8_t *num_items) {
    uint8_t methodArgCount = _getMethod_NumItems(parser_tx_obj.callIndex.moduleIdx,
                                                 parser_tx_obj.callIndex.idx,
                                                 &parser_tx_obj.method);

    *num_items = FIELD_FIXED_TOTAL_COUNT + methodArgCount;
    return parser_ok;
}

parser_error_t parser_getItem(const parser_context_t *ctx,
                              uint16_t displayIdx,
                              char *outKey, uint16_t outKeyLen,
                              char *outValue, uint16_t outValueLen,
                              uint8_t pageIdx, uint8_t *pageCount) {
    MEMZERO(outKey, outKeyLen);
    MEMZERO(outValue, outValueLen);

    uint8_t numItems;

    CHECK_PARSER_ERR(parser_getNumItems(ctx, &numItems));
    *pageCount = 1;

    if (displayIdx < 0 || displayIdx >= numItems) {
        *pageCount = 0;
        return parser_no_data;
    }

    snprintf(outKey, outKeyLen, "? %d/%d", displayIdx + 1, numItems);
    snprintf(outValue, outValueLen, "? %d", pageIdx);

    parser_error_t err = parser_ok;
    if (displayIdx == FIELD_METHOD) {
        snprintf(outKey, outKeyLen, "%s",
                 _getMethod_ModuleName(parser_tx_obj.callIndex.moduleIdx));
        snprintf(outValue, outValueLen, "%s",
                 _getMethod_Name(parser_tx_obj.callIndex.moduleIdx,
                                 parser_tx_obj.callIndex.idx));
        return err;
    }

    // VARIABLE ARGUMENTS
    uint8_t methodArgCount = _getMethod_NumItems(parser_tx_obj.callIndex.moduleIdx,
                                                 parser_tx_obj.callIndex.idx,
                                                 &parser_tx_obj.method);
    uint8_t argIdx = displayIdx - 1;
    if (argIdx < methodArgCount) {
        snprintf(outKey, outKeyLen, "%s",
                 _getMethod_ItemName(parser_tx_obj.callIndex.moduleIdx,
                                     parser_tx_obj.callIndex.idx,
                                     argIdx));

        err = _getMethod_ItemValue(&parser_tx_obj.method,
                                   parser_tx_obj.callIndex.moduleIdx, parser_tx_obj.callIndex.idx, argIdx,
                                   outValue, outValueLen,
                                   pageIdx, pageCount);
    } else {
        // CONTINUE WITH FIXED ARGUMENTS
        displayIdx -= methodArgCount;
        switch (displayIdx) {
            case FIELD_NETWORK:
                if (_detectAddressType() == PK_ADDRESS_TYPE) {
                    snprintf(outKey, outKeyLen, "Chain");
                    snprintf(outValue, outValueLen, COIN_NAME);
                    break;
                }
                snprintf(outKey, outKeyLen, "Genesis Hash");
                _toStringHash(&parser_tx_obj.genesisHash,
                              outValue, outValueLen,
                              pageIdx, pageCount);
                break;
            case FIELD_ONCE:
                snprintf(outKey, outKeyLen, "Nonce");
                _toStringCompactIndex(&parser_tx_obj.nonce,
                                      outValue, outValueLen,
                                      pageIdx, pageCount);
                break;
            case FIELD_TIP:
                snprintf(outKey, outKeyLen, "Tip");
                _toStringCompactBalance(&parser_tx_obj.tip,
                                        outValue, outValueLen,
                                        pageIdx, pageCount);
                break;
            case FIELD_ERA_PHASE:
                snprintf(outKey, outKeyLen, "Era Phase");
                uint64_to_str(outValue, outValueLen, parser_tx_obj.era.phase);
                break;
            case FIELD_ERA_PERIOD:
                snprintf(outKey, outKeyLen, "Era Period");
                uint64_to_str(outValue, outValueLen, parser_tx_obj.era.period);
                break;
            case FIELD_BLOCK_HASH:
                snprintf(outKey, outKeyLen, "Block");
                _toStringHash(&parser_tx_obj.blockHash,
                              outValue, outValueLen,
                              pageIdx, pageCount);
                break;
            default:
                *pageCount = 0;
                return parser_no_data;
        }
    }

    if (*pageCount > 1) {
        uint8_t keyLen = strlen(outKey);
        if (keyLen < outKeyLen) {
            snprintf(outKey + keyLen, outKeyLen - keyLen, " [%d/%d]", pageIdx + 1, *pageCount);
        }
    }

    return err;
}
