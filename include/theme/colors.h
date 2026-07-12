#ifndef M_COLORS_H
#define M_COLORS_H

#include "../../lib/clay.h"

typedef enum : uint16_t {
  M_COLOR_PRIMARY = 0,
  M_COLOR_SECONDARY = 1,
  M_COLOR_ACCENT = 2,
  M_COLOR_BACKGROUND = 3,

  M_COLOR_DARK_PRIMARY = 4,
  M_COLOR_DARK_BACKGROUND = 5,

  M_COLOR_TEXT_WHITE = 6,
  M_COLOR_TEXT_DIMMED = 7,

  M_COLOR_BORDER = 8,
} m_color_id_t;

extern Clay_Color theme_colors[];

#endif
