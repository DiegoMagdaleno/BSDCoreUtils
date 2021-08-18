#include "stat_mingw.h"
#include "dev_opera.h"

static int
get_attributes_of_file (const char *filename,
                        WIN32_FILE_ATTRIBUTE_DATA *filedata)
{
  size_t len;

  if (get_device_type (filename) != NOT_DEVICE || get_device_fd (filename) > 0)
    {
      FILETIME unix_epoch = { 0xd53e8000, 0x019db1de };
      filedata->dwFileAttributes = FILE_ATTRIBUTE_DEVICE;
      filedata->ftCreationTime = filedata->ftLastAccessTime
          = filedata->ftLastWriteTime = unix_epoch;
      filedata->nFileSizeHigh = filedata->nFileSizeLow = 0;
      return 0;
    }

  if (GetFileAttributesExA (filename, GetFileExInfoStandard, filedata))
    {
      filedata->dwFileAttributes &= ~FILE_ATTRIBUTE_DEVICE;
      return 0;
    }

  if (GetLastError () == ERROR_SHARING_VIOLATION)
    {
      HANDLE hnd;
      WIN32_FIND_DATA fdata;

      if ((hnd = FindFirstFile (filename, &filedata)) != INVALID_HANDLE_VALUE)
        {
          filedata->dwFileAttributes
              = fdata.dwFileAttributes & ~FILE_ATTRIBUTE_DEVICE;
          filedata->ftCreationTime = fdata.ftCreationTime;
          filedata->ftLastAccessTime = fdata.ftLastAccessTime;
          filedata->ftLastWriteTime = fdata.ftLastWriteTime;
          filedata->nFileSizeHigh = fdata.nFileSizeHigh;
          filedata->nFileSizeLow = fdata.nFileSizeLow;
          FindClose (hnd);
          return 0;
        }
    }

  switch (GetLastError ())
    {
    case ERROR_ACCESS_DENIED:
    case ERROR_SHARING_VIOLATION:
    case ERROR_LOCK_VIOLATION:
    case ERROR_SHARING_BUFFER_EXCEEDED:
      return EACCES;
    case ERROR_BUFFER_OVERFLOW:
      return ENAMETOOLONG;
    case ERROR_NOT_ENOUGH_MEMORY:
      return ENOMEM;
    case ERROR_INVALID_NAME:
      len = strlen (filename);
      if (len > 1 && (filename[len - 1] == '/' || filename[len - 1] == '\\'))
        return ENOTDIR;
    default:
      return ENOENT;
    }
}

static int
meta_stat (int follow, const char *filename, struct stat_mingw* buf)
{
  int err = EINVAL;
  WIN32_FILE_ATTRIBUTE_DATA file_data;
  WIN32_FIND_DATAA find_buffer;
  DWORD low, high;
  off64_t size;

  while (filename && !(err = get_attributes_of_file(filename, &file_data))) {
    buf->st_ino = 0;
    buf->st_uid = DEFAULT_UID;
    buf->st_gid = DEFAULT_GID;
    buf->st_dev = buf->st_dev = 0;

  }
}