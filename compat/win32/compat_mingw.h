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

/* sys/stat.h */
#define S_ISUID 0400
#define S_ISGID 0200
#define S_ISVTX 0100

#define S_IFSOCK 0140000 /* Is a socket */
#define S_IFLNK 0120000 /* Is a symbolic link */


/* Translate WinAPI errors to POSIX errors */
int err_translate(void);

#endif /* ifdef __MINGW32__ */

#endif /* COMPAT_MINGW */