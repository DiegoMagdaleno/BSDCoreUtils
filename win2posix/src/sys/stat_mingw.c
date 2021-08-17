#include "stat_mingw.h"

static int get_attributes_of_file(const char* filename, WIN32_FILE_ATTRIBUTE_DATA *filedata) {
  size_t len;

  
}

static int
meta_stat (int follow, const char *filename, struct mingw_stat *buf)
{
  int err = EINVAL;
  WIN32_FILE_ATTRIBUTE_DATA file_data;
  WIN32_FIND_DATAA find_buffer;
  DWORD low, high;
  off64_t size;

  while (filename && !(err = get_file_attr))
}