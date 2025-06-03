#pragma once
#include "quantum/color.h"

/*
  colors.h

  Defines base colours and an OFFSET() macro for generating
  lighter/darker shades in compile‐time‐constant initializers.
*/

//-----------------------------------------------------------------------------
// 1) RGB literal helper (if you ever want to build a one‐off rgb_t)
//-----------------------------------------------------------------------------
#define RGB(r, g, b)   (rgb_t){ (r), (g), (b) }

//-----------------------------------------------------------------------------
// 2) Base‐colour channel constants
//    – one macro per channel, named XXX_R, XXX_G, XXX_B
//-----------------------------------------------------------------------------
#define BCK_R 0x00  // black
#define BCK_G 0x00
#define BCK_B 0x00

#define BLU_R 0x00  // blue
#define BLU_G 0x00
#define BLU_B 0xFF

#define GRN_R 0x00  // green
#define GRN_G 0xFF
#define GRN_B 0x00

#define RED_R 0xFF  // red
#define RED_G 0x00
#define RED_B 0x00

#define CYA_R 0x00  // cyan
#define CYA_G 0xFF
#define CYA_B 0xFF

#define YEL_R 0xFF  // yellow
#define YEL_G 0xFF
#define YEL_B 0x00

#define MAG_R 0xFF  // magenta
#define MAG_G 0x00
#define MAG_B 0xFF

#define ORG_R 0xFF  // orange
#define ORG_G 0xA5
#define ORG_B 0x00

#define PUP_R 0x80  // purple
#define PUP_G 0x00
#define PUP_B 0x80

#define WHT_R 0xFF  // white
#define WHT_G 0xFF
#define WHT_B 0xFF

//-----------------------------------------------------------------------------
// 3) Base‐colour initializers
//    – each expands to one literal {r, g, b}
//-----------------------------------------------------------------------------
#define BCK { BCK_R, BCK_G, BCK_B }
#define BLU { BLU_R, BLU_G, BLU_B }
#define GRN { GRN_R, GRN_G, GRN_B }
#define RED { RED_R, RED_G, RED_B }
#define CYA { CYA_R, CYA_G, CYA_B }
#define YEL { YEL_R, YEL_G, YEL_B }
#define MAG { MAG_R, MAG_G, MAG_B }
#define ORG { ORG_R, ORG_G, ORG_B }
#define PUP { PUP_R, PUP_G, PUP_B }
#define WHT { WHT_R, WHT_G, WHT_B }

//-----------------------------------------------------------------------------
// 4) Clamp macro (constant‐expression safe)
//-----------------------------------------------------------------------------
#define CLAMP(v)     ( ((v) > 255) ? 255 : ( ((v) < 0) ? 0 : (v) ) )

//-----------------------------------------------------------------------------
// 5) OFFSET(base,delta)
//    – produce one { r+Δ, g+Δ, b+Δ } initializer, channels clamped [0..255]
//-----------------------------------------------------------------------------
#define OFFSET(c, d)                                            \
  { CLAMP((c##_R) + (d)), CLAMP((c##_G) + (d)), CLAMP((c##_B) + (d)) }

//-----------------------------------------------------------------------------
// Usage in your keymap.c:
//   #include "colors.h"
//   static const rgb_t layer_colors[][MATRIX_ROWS][MATRIX_COLS] = {
//     [_LOWER] = {
//       { BLU, OFFSET(BLU,+16), OFFSET(BLU,+32), /* ... */ },
//       /* ... */
//     },
//     /* ... */
//   };
//-----------------------------------------------------------------------------