
#include "compat.h"
#include <stdlib.h>

#ifdef _WIN32
#define LIBCOMPAT_IS_PATHNAME_SEPARATOR(c) ((c) == '/' || (c) == '\\')
#else
#define LIBCOMPAT_IS_PATHNAME_SEPARATOR(c) ((c) == '/')
#endif

#ifndef HAVE___PROGNAME
const char *__progname = NULL;
#endif

const char*
getprogname(void)
{
    #if defined(HAVE_PROGRAM_INVOCATION_SHORT_NAME)
        if(__progname == NULL)
            __progname = program_invocation_short_name;
    #elif defined(HAVE_GETEXECNAME) // Solaris
        if(__progname == NULL)
            setprogname(getexecname());
    #elif defined(IS_USING_WHEREAMI_LIBRARY) // Musl/Linux, GNU/Linux...
        if(__progname == NULL) {
            // This code logic leaves progname as NULL btw...
            char *path = NULL;
            int lenght, dirname_lenght;

            lenght = wai_getExecutablePath(NULL, 0, &dirname_lenght);
            if (lenght > 0) {
                path = (char*)malloc(lenght + 1);
                wai_getExecutablePath(path, lenght, &dirname_lenght);
                path[lenght] = '\0';
                setprogname(path); // Must be transformed into relative path
            }
        }
    #elif defined(__UTOPIA__)
        setprogname(c_proc_getexename());
    #elif defined(_WIN32) // I hate the Windows API, I hate the Windows API
        if (__progname == NULL) {
            WCHAR *wpath = NULL;
            WCHAR *wname = NULL;
            WCHAR *wext = NULL;
            DWORD wpathsiz = MAX_PATH / 2;
            DWORD len, i;
            char *mbname = NULL;
            int mbnamesiz;

            do {
                WCHAR *wpathnew;

                wpathsiz *= 2;
                wpathsiz = MIN(wpathsiz, UNICODE_STRING_MAX_CHARS);
                wpathnew = reallocarray(wpath, wpathsiz, sizeof(*wpath));
                if (wpathnew == NULL) {
                    goto done;
                }
                wpath = wpathnew;

                len = GetModuleFileNameW(NULL, wpath, wpathsiz);
                if (wpathsiz == UNICODE_STRING_MAX_CHARS)
                    goto done;
            } while (wpathsiz == len);

            if (len == 0)
                goto done;
            
            wname = wpath;
            for (i = len; i > 0; i--) {
                if (LIBCOMPAT_IS_PATHNAME_SEPARATOR(wpath[i - 1])) {
                    wname = wpath + i;
                    break;
                }
            }

            wext = PathFindExtensionW(wname);
            wext[0] = '\0';

            mbnamesiz = WideCharToMultiByte(CP_UTF8, 0, wname, -1, NULL, 0, NULL, NULL);

            if (mbnamesiz == 0)
                goto done;
            mbname = malloc(mbnamesiz);
            if (mbname == NULL)
                goto done;
            
            mbnamesiz = WideCharToMultiByte(CP_UTF8, 0, wname, -1, mbname, mbnamesiz, NULL, NULL);

            if (mbnamesiz == 0)
                goto done;
            __progname = mbname;
            mbname = NULL;
done:
            free(wpath);
            free(mbname);
        }
        #endif

        return __progname;
}

void
setprogname(const char *progname)
{
    size_t i;

    for (i = strlen(progname); i > 0; i--) {
        if (LIBCOMPAT_IS_PATHNAME_SEPARATOR(progname[i - 1])) {
            __progname = progname + i;
            return;
        }
    }

    __progname = progname;
}