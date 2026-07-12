#ifndef M_VARIANTS_H
#define M_VARIANTS_H

#include <stdint.h>

#define VARIANT_COUNT 2

typedef enum : uint16_t {
  M_VARIANT_SOLID = 0,
  M_VARIANT_OUTLINE = 1,
} m_variant_id_t;

#endif
