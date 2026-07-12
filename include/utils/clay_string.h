#ifndef M_CLAY_STRING_H
#define M_CLAY_STRING_H

#include "../../lib/clay.h"

Clay_String DynamicClayString(char* string);
Clay_String DynamicClayStringConcat(char buffer[], size_t size, char* a, char* b);

#endif
