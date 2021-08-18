#include "compat_mingw.h"
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <ntdef.h>

/* sys/stat.h */
#define S_ISUID 0400
#define S_ISGID 0200
#define S_ISVTX 0100

#define S_IFSOCK 0140000 /* Is a socket */
#define S_IFLNK 0120000 /* Is a symbolic link */

struct stat_mingw
 {
	dev_t     st_dev;
	ino_t     st_ino;
	mode_t    st_mode;
	nlink_t   st_nlink;
	uid_t     st_uid;
	gid_t     st_gid;
	dev_t     st_rdev;
	off_t     st_size;
	struct timespec st_atim;
	struct timespec st_mtim;
	struct timespec st_ctim;
	blksize_t st_blksize;
	blkcnt_t  st_blocks;
	DWORD     st_attr;
};

int stat_mingw(const char*, struct stat_mingw *);
int lstat_mingw(const char*, struct stat_mingw *);
int fstat_mingw(int, struct stat_mingw *);