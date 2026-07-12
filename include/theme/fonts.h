#ifndef M_FONTS_H
#define M_FONTS_H

#include <stdint.h>

#define FONT_COUNT 11

typedef enum : uint16_t {
  M_FONT_REGULAR = 0,
  M_FONT_SEMIBOLD = 1,
  M_FONT_BOLD = 2,

  M_FONT_DISPLAY_BOLD = 3,
  M_FONT_DISPLAY_ITALIC = 4,

  M_FONT_MONO_REGULAR = 5,
  M_FONT_MONO_BOLD = 6,
  M_FONT_MONO_ITALIC = 7,

  M_FONT_REGULAR_SM = 8,
  M_FONT_SEMIBOLD_SM = 9,
  M_FONT_MONO_REGULAR_SM = 10,
} m_font_id_t; // just for convenience

#endif
