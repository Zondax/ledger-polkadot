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

#include <sigutils.h>
#include <zxmacros.h>

#define MINPAYLOADLEN 1
#define PAYLOADLEN 32
#define MAXPAYLOADLEN 33

err_convert_e convertDERtoRSV(const uint8_t *inSignatureDER,
                              unsigned int inInfo,
                              uint8_t *outR,
                              uint8_t *outS,
                              uint8_t *outV) {

    // https://github.com/libbitcoin/libbitcoin-system/wiki/ECDSA-and-DER-Signatures#serialised-der-signature-sequence
    // 0                [1 byte]   - DER Prefix
    // 1                [1 byte]   - Payload len
    // 2                [1 byte]   - R Marker. Always 02
    // 3                [1 byte]   - R Len                      RLEN
    // ROFFSET ...      [.?. byte] - R                          ROFFSET
    // ROFFSET+RLEN     [1 byte]   - S Marker. Always 02
    // ROFFSET+RLEN+1   [1 byte]   - S Length                   SLEN
    // ROFFSET+RLEN+2   [.?. byte] - S                          SOFFSET
    // Prepare response
    // R [32]
    // S [32]
    // V [1]

    MEMZERO(outR, 32);
    MEMZERO(outS, 32);
    MEMZERO(outV, 1);

    const uint8_t derPrefix = *(inSignatureDER);
    if (derPrefix != 0x30) {
        return invalid_derPrefix;
    }

    const uint8_t payloadLen = *(inSignatureDER + 1);
    const uint8_t minPayloadLen = 2 + MINPAYLOADLEN + 2 + MINPAYLOADLEN;
    const uint8_t maxPayloadLen = 2 + MAXPAYLOADLEN + 2 + MAXPAYLOADLEN;
    if (payloadLen < minPayloadLen || payloadLen > maxPayloadLen) {
        return invalid_payloadLen;
    }

    const uint8_t rMarker = *(inSignatureDER + 2);
    if (rMarker != 0x02) {
        return invalid_rmaker;
    }

    uint8_t rLen = *(inSignatureDER + 3);
    if (rLen > MAXPAYLOADLEN || rLen < MINPAYLOADLEN) {
        return invalid_rLen;
    }

    const uint8_t sMarker = *(inSignatureDER + 4 + rLen);
    if (sMarker != 0x02) {
        return invalid_smarker;
    }

    uint8_t sLen = *(inSignatureDER + 4 + rLen + 1);
    if (sLen > MAXPAYLOADLEN || sLen < MINPAYLOADLEN) {
        return invalid_sLen;
    }

    // Get data fields
    const uint8_t *rPtr = inSignatureDER + 4;
    const uint8_t *sPtr = inSignatureDER + 4 + rLen + 2;

    // Correct field pointers
    if (rLen < PAYLOADLEN) {
        outR += PAYLOADLEN - rLen;
    }
    if (rLen > PAYLOADLEN) {
        rPtr += rLen - PAYLOADLEN;       // move forward get only 32 bytes
        rLen = PAYLOADLEN;
    }

    if (sLen < PAYLOADLEN) {
        outS += PAYLOADLEN - sLen;
    }
    if (sLen > PAYLOADLEN) {
        sPtr += sLen - PAYLOADLEN;       // move forward get only 32 bytes
        sLen = PAYLOADLEN;
    }

    // Prepare V
    *outV = 0;
    if (inInfo & CX_ECCINFO_PARITY_ODD) {
        *outV += 1;
    }
    if (inInfo & CX_ECCINFO_xGTn) {
        *outV += 2;
    }

    // Copy things
    MEMCPY(outR, rPtr, rLen);
    MEMCPY(outS, sPtr, sLen);

    return no_error;
}
