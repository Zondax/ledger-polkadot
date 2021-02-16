#pragma once

#include <stdint.h>

void get_sr25519_sk(uint8_t *sk_ed25519_expanded);

void sign_sr25519_phase1(const uint8_t *sk_ed25519_expanded, const uint8_t *pk, const uint8_t *context_ptr, uint32_t context_len, const uint8_t *msg_ptr, uint32_t msg_len, uint8_t *sig_ptr);
void sign_sr25519_phase2(const uint8_t *sk_ed25519_expanded, const uint8_t *pk, const uint8_t *context_ptr, uint32_t context_len, const uint8_t *msg_ptr, uint32_t msg_len, uint8_t *sig_ptr);
