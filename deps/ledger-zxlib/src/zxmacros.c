/*******************************************************************************
*   (c) 2018 Zondax GmbH
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
#include "zxmacros.h"
#include "utf8.h"

size_t asciify(char *utf8_in_ascii_out)
{
    return asciify_ext(utf8_in_ascii_out, utf8_in_ascii_out);
}

size_t asciify_ext(const char *utf8_in, char *ascii_only_out) {
    void *p = (void *) utf8_in;
    char *q = ascii_only_out;

    // utf8valid returns zero on success
    while (*((char *) p) && utf8valid(p) == 0) {
        utf8_int32_t tmp_codepoint = 0;
        p = utf8codepoint(p, &tmp_codepoint);
        *q = (tmp_codepoint >= 32 && tmp_codepoint <= 0x7F) ? tmp_codepoint : '.';
        q++;
    }

    // Terminate string
    *q = 0;
    return q - ascii_only_out;
}

void handle_stack_overflow() {
#if defined (TARGET_NANOS) || defined(TARGET_NANOX)
    io_seproxyhal_se_reset();
#else
    while(1);
#endif
}
