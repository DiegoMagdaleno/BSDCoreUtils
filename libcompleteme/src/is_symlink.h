#include <windows.h>

int is_symlink(DWORD attr, const char*, WIN32_FIND_DATAA *fbuf) {
    if (attr& FILE_ATTRIBUTE_REPARSE_POINT) {
        HANDLE handle = FindFirstFileA(pathname, fbuf);
    }
}