#include "zxutils_ledger.h"

#ifndef NULL
#define NULL ((void *)0)
#endif

// We implement a light mecanism in order to be able to retrieve the width of
// nano S characters, in the two possible fonts:
// - BAGL_FONT_OPEN_SANS_EXTRABOLD_11px,
// - BAGL_FONT_OPEN_SANS_REGULAR_11px.
#define NANOS_FIRST_CHAR          0x20
#define NANOS_LAST_CHAR           0x7F

// OPEN_SANS_REGULAR_11PX << 4 | OPEN_SANS_EXTRABOLD_11PX
const char nanos_characters_width[96] = {
   3 << 4 |  3,   /* code 0020 */
   3 << 4 |  3,   /* code 0021 */
   4 << 4 |  6,   /* code 0022 */
   7 << 4 |  7,   /* code 0023 */
   6 << 4 |  6,   /* code 0024 */
   9 << 4 | 10,   /* code 0025 */
   8 << 4 |  9,   /* code 0026 */
   2 << 4 |  3,   /* code 0027 */
   3 << 4 |  4,   /* code 0028 */
   3 << 4 |  4,   /* code 0029 */
   6 << 4 |  6,   /* code 002A */
   6 << 4 |  6,   /* code 002B */
   3 << 4 |  3,   /* code 002C */
   4 << 4 |  4,   /* code 002D */
   3 << 4 |  3,   /* code 002E */
   4 << 4 |  5,   /* code 002F */
   6 << 4 |  8,   /* code 0030 */
   6 << 4 |  6,   /* code 0031 */
   6 << 4 |  7,   /* code 0032 */
   6 << 4 |  7,   /* code 0033 */
   8 << 4 |  8,   /* code 0034 */
   6 << 4 |  6,   /* code 0035 */
   6 << 4 |  8,   /* code 0036 */
   6 << 4 |  7,   /* code 0037 */
   6 << 4 |  8,   /* code 0038 */
   6 << 4 |  8,   /* code 0039 */
   3 << 4 |  3,   /* code 003A */
   3 << 4 |  3,   /* code 003B */
   6 << 4 |  5,   /* code 003C */
   6 << 4 |  6,   /* code 003D */
   6 << 4 |  5,   /* code 003E */
   5 << 4 |  6,   /* code 003F */
  10 << 4 | 10,   /* code 0040 */
   7 << 4 |  8,   /* code 0041 */
   7 << 4 |  7,   /* code 0042 */
   7 << 4 |  7,   /* code 0043 */
   8 << 4 |  8,   /* code 0044 */
   6 << 4 |  6,   /* code 0045 */
   6 << 4 |  6,   /* code 0046 */
   8 << 4 |  8,   /* code 0047 */
   8 << 4 |  8,   /* code 0048 */
   3 << 4 |  4,   /* code 0049 */
   4 << 4 |  5,   /* code 004A */
   7 << 4 |  8,   /* code 004B */
   6 << 4 |  6,   /* code 004C */
  10 << 4 | 11,   /* code 004D */
   8 << 4 |  9,   /* code 004E */
   9 << 4 |  9,   /* code 004F */
   7 << 4 |  7,   /* code 0050 */
   9 << 4 |  9,   /* code 0051 */
   7 << 4 |  8,   /* code 0052 */
   6 << 4 |  6,   /* code 0053 */
   7 << 4 |  6,   /* code 0054 */
   8 << 4 |  8,   /* code 0055 */
   7 << 4 |  6,   /* code 0056 */
  10 << 4 | 11,   /* code 0057 */
   6 << 4 |  8,   /* code 0058 */
   6 << 4 |  7,   /* code 0059 */
   6 << 4 |  7,   /* code 005A */
   4 << 4 |  5,   /* code 005B */
   4 << 4 |  5,   /* code 005C */
   4 << 4 |  5,   /* code 005D */
   6 << 4 |  7,   /* code 005E */
   5 << 4 |  6,   /* code 005F */
   6 << 4 |  7,   /* code 0060 */
   6 << 4 |  7,   /* code 0061 */
   7 << 4 |  7,   /* code 0062 */
   5 << 4 |  6,   /* code 0063 */
   7 << 4 |  7,   /* code 0064 */
   6 << 4 |  7,   /* code 0065 */
   5 << 4 |  6,   /* code 0066 */
   6 << 4 |  7,   /* code 0067 */
   7 << 4 |  7,   /* code 0068 */
   3 << 4 |  4,   /* code 0069 */
   4 << 4 |  5,   /* code 006A */
   6 << 4 |  7,   /* code 006B */
   3 << 4 |  4,   /* code 006C */
  10 << 4 | 10,   /* code 006D */
   7 << 4 |  7,   /* code 006E */
   7 << 4 |  7,   /* code 006F */
   7 << 4 |  7,   /* code 0070 */
   7 << 4 |  7,   /* code 0071 */
   4 << 4 |  5,   /* code 0072 */
   5 << 4 |  6,   /* code 0073 */
   4 << 4 |  5,   /* code 0074 */
   7 << 4 |  7,   /* code 0075 */
   6 << 4 |  7,   /* code 0076 */
   9 << 4 | 10,   /* code 0077 */
   6 << 4 |  7,   /* code 0078 */
   6 << 4 |  7,   /* code 0079 */
   5 << 4 |  6,   /* code 007A */
   4 << 4 |  5,   /* code 007B */
   6 << 4 |  6,   /* code 007C */
   4 << 4 |  5,   /* code 007D */
   6 << 4 |  6,   /* code 007E */
   7 << 4 |  6,   /* code 007F */
};

unsigned short zx_compute_line_width_light(const char* text, unsigned char text_length) {
  char current_char;
  unsigned short line_width = 0;
  
  if(text == NULL) {
    return 0xFFFF;
  }

  // We parse the characters of the input text on all the input length.
  while (text_length--) {
    current_char = *text;

    if (current_char < NANOS_FIRST_CHAR || current_char > NANOS_LAST_CHAR) {
      if (current_char == '\n' || current_char == '\r') {
        break;
      }
    }
    else {
        // Regular.
        line_width += (nanos_characters_width[current_char - NANOS_FIRST_CHAR] >> 0x04) & 0x0F;
    }
    text++;
  }
  return line_width;
}