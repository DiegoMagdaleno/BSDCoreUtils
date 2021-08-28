#include "convert.h"


mode_t file_attr_to_st_mode(DWORD attr)
{
	mode_t fMode = S_IRUSR|S_IRGRP|S_IROTH;
	if (attr & FILE_ATTRIBUTE_DIRECTORY)
		fMode |= S_IFDIR|S_IXUSR|S_IXGRP|S_IXOTH;
	else if (attr & FILE_ATTRIBUTE_DEVICE)
		fMode |= S_IFCHR|S_IWOTH;
	else
		fMode |= S_IFREG;
	if (!(attr & FILE_ATTRIBUTE_READONLY))
		fMode |= S_IWUSR|S_IWGRP;
	return fMode;
}
