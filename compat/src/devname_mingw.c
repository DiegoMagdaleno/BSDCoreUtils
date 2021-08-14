#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdbool.h>
#include "mingw_paths.h"
#include "compat.h"

static bool 
is_unkown(struct stat filestat) {
    switch(filestat.st_mode & S_IFMT) {
        case S_IFBLK:
        case S_IFCHR:
        case S_IFDIR:
        case S_IFIFO:
        case S_IFREG:
            return true;
            break;
        default:
            return false;
    }
}

/* 
devname_mingw -> Implementation of devname() for Mingw32

devname_mingw implements the same calls and returns as normal
devname, however the internals are different, due to Windows 
not having a "d_type" on its dirent struct, we have to use
stat in order to get the information we want 
*/
char *
devname_mingw(dev_t dev, mode_t type) {
    DIR *dirp;
    char *name = NULL;
    struct dirent *entry;
    struct stat filestat;
    struct stat sb;
    static char buf[NAME_MAX + 1];

    if((dirp = opendir(_PATH_DEV)) == NULL)
    return (NULL);


    while ((entry = readdir(dirp)) != NULL) {
        stat(entry->d_name, &filestat);
        if (is_unkown(filestat) != false && (filestat.st_mode) != type) {
            continue;
        }
        if (fstatat(dirfd(dirp), entry->d_name, &sb, AT_SYMLINK_NOFOLLOW) || sb.st_rdev != dev || (sb.st_mode & S_IFMT) != type) 
        continue;
        strlcpy(buf, entry->d_name, sizeof(buf));
        name = buf;
        break;
    }
    closedir(dirp);
    return (name);

}