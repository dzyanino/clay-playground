#include "clay_string.h"
#include <string.h>
#include <stdio.h>

Clay_String DynamicClayString(char* string) {
  if (strlen(string) == 0) {
    return CLAY_STRING("");
  }
  return ((Clay_String) { .chars = string, .length = strlen(string), .isStaticallyAllocated = false });
}

Clay_String DynamicClayStringConcat(char buffer[], size_t size, char* a, char* b) {
  snprintf(buffer, size, "%s%s", a, b);
  return DynamicClayString(buffer);
}
