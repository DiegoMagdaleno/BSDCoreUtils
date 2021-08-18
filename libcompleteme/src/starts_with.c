#include "starts_with.h"

bool
starts_with (const char *a, const char *b)
{
  if (strncmp (a, b, strlen (b)) == 0)
    return true;
  return false;
}