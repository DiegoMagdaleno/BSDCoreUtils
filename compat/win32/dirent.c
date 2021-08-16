#include "dirent.h"

static int
closedir (DIR *dirp)
{
  if (!dirp)
    {
      errno = EBADF;
      return -1;
    }

  if (dirp->handle != INVALID_HANDLE_VALUE)
    {
      FindClose (dirp->handle);
    }

  free (dirp->patt);

  free (dirp);
  return 0;
}

static WIN32_FIND_DATAW *
dirent_first (DIR *dirp)
{
  if (!dirp)
    {
      return NULL;
    }

  dirp->handle = FindFirstFileExW (dirp->patt, FindExInfoStandard, &dirp->data,
                                   FindExSearchNameMatch, NULL, 0);
  if (dirp->handle == INVALID_HANDLE_VALUE)
    goto error;

  dirp->cached = 1;

  return &dirp->data;

error:
  dirp->cached = 0;

  errno = err_translate ();
  return NULL;
}

DIR *
opendir (const char *dirname)
{
  struct DIR *dirp;
  int error;
  DWORD pathname;
  wchar_t *pattern;

  /* Ensure our name is not empty */
  if (!dirname || dirname[0] == '\0')
    {
      errno = ENOENT;
      return NULL;
    }

  dirp = (DIR *)malloc (sizeof (struct DIR));
  /* Something went wrong with xmalloc */
  if (!dirp)
    {
      return NULL;
    }

  wchar_t win_name[PATH_MAX + 1];
  size_t size;

  error = mbstowcs_s (&size, win_name, PATH_MAX + 1, dirname, PATH_MAX + 1);
  if (error)
    goto exit_closedir;

  dirp->handle = INVALID_HANDLE_VALUE;
  dirp->patt = NULL;
  dirp->cached = 0;

  pathname = GetFullPathNameW (win_name, 0, NULL, NULL);

  dirp->patt = (wchar_t *)malloc (sizeof (wchar_t) * pathname + 16);
  if (!dirp->patt)
    goto exit_closedir;

  pathname = GetFullPathNameW (win_name, pathname, dirp->patt, NULL);
  if (pathname <= 0)
    goto exit_closedir;

  pattern = dirp->patt + pathname;
  switch (pattern[-1])
    {
    case '\\':
    case '/':
    case ':':
      break;
    default:
      *pattern = '\\';
    }

  *pattern++ = '*';
  *pattern = '\0';

  if (dirent_first (dirp))
    goto exit_closedir;

  return dirp;

exit_closedir:
  closedir (dirp);
  return NULL;
}