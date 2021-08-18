#include "is_symlink.h"

int
is_symlink (DWORD attr, const char *pathname, WIN32_FIND_DATAA *fbuf)
{
  if (attr & FILE_ATTRIBUTE_REPARSE_POINT)
    {
      HANDLE handle = FindFirstFileA (pathname, fbuf);
      if (handle != INVALID_HANDLE_VALUE)
        {
          FindClose (handle);
          return ((fbuf->dwFileAttributes & FILE_ATTRIBUTE_REPARSE_POINT)
                      && fbuf->dwReserved0
                  == IO_REPARSE_TAG_SYMLINK);
        }
    }
  return 0;
}