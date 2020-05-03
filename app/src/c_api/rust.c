#include <inttypes.h>
#include "os.h"
#include "cx.h"

#define CTX_REDJUBJUB "Zcash_RedJubjubH"
#define CTX_REDJUBJUB_LEN 16
#define CTX_REDJUBJUB_HASH_LEN 64

#define CTX_EXPAND_SEED "Zcash_ExpandSeed"
#define CTX_EXPAND_SEED_LEN 16
#define CTX_EXPAND_SEED_HASH_LEN 64

void zcash_blake2b_expand_seed(const uint8_t *a, uint32_t a_len,
                               const uint8_t *b, uint32_t b_len,
                               uint8_t *out) {
    cx_blake2b_t ctx;
    cx_blake2b_init2(&ctx, 8 * CTX_EXPAND_SEED_HASH_LEN, NULL, 0, (uint8_t *) CTX_EXPAND_SEED, CTX_EXPAND_SEED_LEN);
    cx_hash(&ctx.header, 0, a, a_len, NULL, 0);
    cx_hash(&ctx.header, CX_LAST, b, b_len, out, CTX_EXPAND_SEED_HASH_LEN);
}

void zcash_blake2b_hash_two(
        const uint8_t *perso, uint32_t perso_len,
        const uint8_t *a, uint32_t a_len,
        const uint8_t *b, uint32_t b_len,
        uint8_t *out, uint32_t out_len) {
    cx_blake2b_t zcashHashBlake2b;
    cx_blake2b_init2(&zcashHashBlake2b, 8 * out_len, NULL, 0, (uint8_t *) perso, perso_len);
    cx_hash(&zcashHashBlake2b.header, 0, a, a_len, NULL, 0);
    cx_hash(&zcashHashBlake2b.header, CX_LAST, b, b_len, out, out_len);
}

// Replace functions affected by non-constant time opcodes
// Overriding requires -z muldefs
// FIXME: add a python script to ensure that the correct version is used by inspecting app.asm

//#define LMULSIZE sizeof(long long)
//
//long long __aeabi_lmul(long long a, long long b) {
//    char result[2 * LMULSIZE];
//    cx_math_mult((unsigned char *) &result, (unsigned char *) &a, (unsigned char *) &b, LMULSIZE);
//    return *((long long *) result);
//}
//
//long long __multi3(long long a, long long b) {
//    char result[2 * LMULSIZE];
//    cx_math_mult((unsigned char *) &result, (unsigned char *) &a, (unsigned char *) &b, LMULSIZE);
//    return *((long long *) result);
//}

//typedef struct {
//    unsigned quot;
//    unsigned rem;
//} __aeabi_uidivmod_result_t;
//
//// FIXME: Complete implementation, redirect and enable
////__aeabi_uidivmod_result_t __aeabi_uidivmod(unsigned numerator, unsigned denominator) {
////    __aeabi_uidivmod_result_t r;
////    return r;
////}
