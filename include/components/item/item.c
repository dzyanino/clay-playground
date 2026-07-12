#include "item.h"
#include "../../../lib/clay.h"
#include "../../theme/fonts.h"
#include "../../utils/clay_string.h"
#include "../button/button.h"
#include <raylib.h>

void ComponentItem(char *id, char *title, char *description, char *bottom_left, char *bottom_right, m_variant_id_t variant_id, m_color_id_t color_id, int *disabled, void (*callback)()) {
  bool is_outline = variant_id == M_VARIANT_OUTLINE;
  bool is_disabled = *disabled;

  char buf_spacer[100], buf_bottom[100], buf_bottom_spacer[100];

  Clay_Color hover_bg = is_outline
    ? theme_colors[M_COLOR_BORDER]
    : theme_colors[M_COLOR_BACKGROUND];

  Clay_Color disabled_bg = is_outline
    ? (Clay_Color){0, 0, 0, 0}
    : theme_colors[M_COLOR_BORDER];

  CLAY(
    CLAY_SID(DynamicClayString(id)),
    {
      .layout = {
        .sizing = {
          .width = CLAY_SIZING_GROW(0),
          .height = CLAY_SIZING_FIXED(78)
        },
        .layoutDirection = CLAY_TOP_TO_BOTTOM,
        .childGap = 0,
        .padding = CLAY_PADDING_ALL(12)
      },
      .cornerRadius = (Clay_CornerRadius) {5, 5, 5, 5},
      .border = is_outline
        ? (Clay_BorderElementConfig) {
            .width = CLAY_BORDER_OUTSIDE(2),
            .color = is_disabled ? theme_colors[M_COLOR_BORDER] : theme_colors[color_id]
          }
        : (Clay_BorderElementConfig) {0},
      .backgroundColor = Clay_Hovered()
        ? is_disabled
          ? (SetMouseCursor(MOUSE_CURSOR_NOT_ALLOWED), disabled_bg)
          : (SetMouseCursor(MOUSE_CURSOR_POINTING_HAND), hover_bg)
        : disabled_bg
    }
  ) {
    if (!is_disabled) { Clay_OnHover(HandleClick, callback); }

    CLAY_TEXT(DynamicClayString(title), {
      .fontId = M_FONT_SEMIBOLD,
      .fontSize = 18,
      .textColor = is_disabled
        ? theme_colors[M_COLOR_TEXT_DIMMED]
        : theme_colors[M_COLOR_TEXT_WHITE]
    });

    CLAY_TEXT(DynamicClayString(description), {
      .fontId = M_FONT_MONO_REGULAR_SM,
      .fontSize = 16,
      .textColor = theme_colors[M_COLOR_TEXT_DIMMED]
    });

    CLAY(CLAY_SID(DynamicClayStringConcat(buf_spacer, sizeof(buf_spacer), id, "-spacer")), {
      .layout = {.sizing = {.height = CLAY_SIZING_GROW(0)}}
    }) {};

    CLAY(
      CLAY_SID(DynamicClayStringConcat(buf_bottom, sizeof(buf_bottom), id, "-bottom")),
      {
        .layout = {
          .layoutDirection = CLAY_LEFT_TO_RIGHT,
          .sizing = {.width = CLAY_SIZING_GROW(0)},
          .childAlignment = {.y = CLAY_ALIGN_Y_CENTER}
        }
      }
    ) {
      CLAY_TEXT(DynamicClayString(bottom_left), {
        .fontId = M_FONT_REGULAR_SM,
        .fontSize = 14,
        .textColor = is_disabled
          ? theme_colors[M_COLOR_TEXT_DIMMED]
          : theme_colors[M_COLOR_TEXT_WHITE]
      });
      CLAY(CLAY_SID(DynamicClayStringConcat(buf_bottom_spacer, sizeof(buf_bottom_spacer), id, "-bottom-spacer")), {
        .layout = {.sizing = {.width = CLAY_SIZING_GROW(0)}}
      }) {};
      CLAY_TEXT(DynamicClayString(bottom_right), {
        .fontId = M_FONT_REGULAR_SM,
        .fontSize = 14,
        .textColor = is_disabled
          ? theme_colors[M_COLOR_TEXT_DIMMED]
          : theme_colors[M_COLOR_TEXT_WHITE]
      });
    }
  }
}
