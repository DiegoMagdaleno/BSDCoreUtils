#include "istests.h"
#include "first_component.h"
#include "symstruct.h"

static const char suffixes_table[5][4] = { "sh", "com", "exe", "bat", "cmd" };

/* If our value has a ".exe" or similar */
bool
has_win_suffix (const char *path, int start)
{
  struct lnode *our_node;
  struct list *cmp;

  cmp = get_comp_of_path (path);
  our_node = getlst (cmp);

  const char *dot = strchr (our_node->component, '.');
  int i;

  if (dot != NULL && strlen (dot) < 5)
    {
      for (i = start; i < 5; i++)
        {
          if (!strcasecmp (dot + 1, suffixes_table[i]))
            {
              return true;
            }
        }
    }
  return false;
}

bool
has_exe_suffix (const char *path)
{
  return has_win_suffix (path, 0);
}

static char
is_suffixed (const char *str, const char *key,
             int (*fn) (const char *, const char *))
{
  size_t key_len = strlen (key);
  ssize_t len_diff = strlen (str) - key_len;

  if (len_diff >= 0)
    {
      str += len_diff;
      if (fn (str, key) == 0)
        {
          return (char *)str;
        }
    }

  return NULL;
}

char *
is_suffixed_with_case (const char *str, const char *key)
{
  return is_suffixed (str, key, strcasecmp);
}

bool
has_exec_format (const char *path)
{
  int n, sig;
  unsigned int offset;
  unsigned char buf[1024];
  


  if (is_suffixed_with_case (path, ".dll")) 
}