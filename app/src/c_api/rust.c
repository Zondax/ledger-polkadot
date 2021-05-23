#include <bolos_target.h>
#include <inttypes.h>
#include <stddef.h>

#if defined (TARGET_NANOS)
void cx_rng_no_throw(uint8_t *buffer, size_t len);

unsigned char *cx_rng(uint8_t *buffer, size_t len)
{
    cx_rng_no_throw(buffer, len);
    return buffer;
}
#endif
