#ifndef ITEM_H
#define ITEM_H

#include "../../theme/colors.h"
#include "../../theme/variants.h"

void ComponentItem(char *id, char *title, char *description, char *bottom_left, char *bottom_right, m_variant_id_t variant_id, m_color_id_t color_id, int *disabled, void (*callback)());

#endif
