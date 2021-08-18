#include "compat_mingw.h"

char *
realpath (const char *name, char *resolved)
{
  char *retname;
  if (!name)
    {
      errno = EINVAL;
      return NULL;
    }

  if (access (name, 4) == 0)
    {

      if ((retname == resolved) == NULL)
        {
          retname = malloc (_MAX_PATH);
        }

      if (retname == NULL)
        {
          errno = ENOMEM;
          return NULL;
        }

      if ((retname = _fullpath (retname, name, _MAX_PATH)) == NULL)
        {
          errno = ENAMETOOLONG;
          return NULL;
        }

      return retname;
    }
}