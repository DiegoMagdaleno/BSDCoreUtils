#ifndef DIRENT_H
#define DIRENT_H

#include <inttypes.h>
#include <stdint.h>
#include <windows.h>
#include <stddef.h>

#include <sys/stat.h>
#include <sys/types.h>

#include <pthread.h>
#include "compat_mingw.h"

/* Dirent implementations */

typedef struct dirent {
    long d_ino;
    long d_off;
    unsigned short d_reclen;
    char d_name[MAX_PATH];
    size_t d_namlen;
    int d_type;
} dirent;

/* Keep Win32/Mingw DIR implementation */
typedef struct DIR {
    WIN32_FIND_DATAW data;
    struct dirent ent;
    HANDLE handle;
    int cached;
    wchar_t *patt;
} DIR;

/*
 * Dirent reimplementation that borrows from win32 and makes it more POSIX like.
 * MAX_PATH AND PATH_MAX are technically identical, both being defined by most POSIX systems as 260
 * while on Windows it looks to be 259.
 * 
 * Borrowing from UNIX we are missing our d_type, this causes problems
 * mainly in things like devmode.c that use some macros, this implements d_type the way an FreeBSD
 * operating system would, we are doing this with hopes neither the win32 API or 
 * NT kernel complain about this. 
*/



/* 
* Macros 
* DT_UNKOWN - unkown filetype
* DT_DIR - Directory
* DT_REG - Regular
* DT_LNK - Symlink
*/
/* File type flags for d_type */
#define DT_UNKNOWN 0
#define DT_REG S_IFREG
#define DT_DIR S_IFDIR
#define DT_FIFO S_IFIFO
#define DT_SOCK S_IFSOCK
#define DT_CHR S_IFCHR
#define DT_BLK S_IFBLK
#define DT_LNK S_IFLNK


/* DTTOIF is the equivalent of getting the st_mode of a struct */
#define DTTOIF(type) (type)

DIR *opendir(const char *);


#endif