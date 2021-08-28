#include "dev_opera.h"
#include "first_component.h"
#include "starts_with.h"
#include "compat.h"
#include "symstruct.h"

static t_symstruct devices_table[] = { { "null", DEV_NULL },
                                       { "urandom", DEV_URANDOM },
                                       { "zero", DEV_ZERO } };

static int
get_type_meta (char *key)
{
  int i;

  int nkey = (sizeof (devices_table) / sizeof (t_symstruct));
  for (i = 0; i < nkey; i++)
    {
      t_symstruct symv = devices_table[i];
      if (strcmp (symv.key, key) == 0)
        {
          return symv.val;
        }
    }
  return NOT_DEVICE;
}

int
get_device_type (const char *path)
{
  struct lnode *nd;
  struct list *cmp;
  int result;

  cmp = get_comp_of_path (path);
  nd = getatindx (cmp, 1);

  result = get_type_meta (nd->component);

  return result;
}

int
get_device_fd (const char *path) {
    int fd;

    if (!path) {
      return -1;
    }

    if (starts_with(path, DEV_FD_PREFIX)) {
      fd = strtoul(path+(sizeof(DEV_FD_PREFIX)-1), NULL, 10);
      if (errno == 0 && (HANDLE)_get_osfhandle(fd) != INVALID_HANDLE_VALUE)
        return fd;
    }
    return -1;
}