#pragma once

#include <stdint.h>

int8_t rs_sha512_256(const uint8_t *input, uint32_t inputSize, uint8_t *output, uint32_t outputMaxSize);
