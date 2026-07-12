#ifndef M_FONTS_H
#define M_FONTS_H

#include <stdint.h>

#define FONT_COUNT 8

typedef enum : uint16_t {
  M_FONT_REGULAR = 0,
  M_FONT_SEMIBOLD = 1,
  M_FONT_BOLD = 2,

  M_FONT_DISPLAY_BOLD = 3,
  M_FONT_DISPLAY_ITALIC = 4,

  M_FONT_MONO_REGULAR = 5,
  M_FONT_MONO_BOLD = 6,
  M_FONT_MONO_ITALIC = 7,
} m_font_id_t; // just for convenience

#endif
