#include "is_prefixed_with.h"
#include "first_component.h"

bool
is_prefixed_with (const char *path, const char *prefix)
{
  struct list *comp;
  struct lnode *nd;

  if (!path)
    {
      return NULL;
    }

  comp = get_comp_of_path (path);
  nd = getatindx (comp, 0);
  if (!nd)
    {
      return NULL;
    }

  return (bool)(strcmp (prefix, nd->component)==0);
}