#ifndef COMPAT_MINGW
#define COMPAT_MINGW

#ifdef __MINGW32__
#include <inttypes.h>
#include <stdint.h>
#include <windows.h>
#include <stddef.h>

#include <sys/stat.h>
#include <sys/types.h>

#include <pthread.h>

/* sys/types.h */
typedef int gid_t;
typedef int uid_t;
typedef unsigned char  u_char;
typedef unsigned int u_int;
typedef unsigned long u_long;

/* Missing Windows Types */
typedef int nlink_t;
typedef int blksize_t;
typedef off_t blkcnt_t;

/* Similar behaviour to macOS */
#define st_atime st_atim.tv_sec
#define st_mtime st_mtim.tv_sec
#define st_ctime st_ctim.tv_sec

/* Translate WinAPI errors to POSIX errors */
int err_translate(void);

#endif /* ifdef __MINGW32__ */

#define DEFAULT_UID 4095
#define DEFAULT_GID DEFAULT_UID

char* realpath(const char*, char*);

#endif /* COMPAT_MINGW */