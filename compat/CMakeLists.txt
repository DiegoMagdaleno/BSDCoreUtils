#Basic list of libcompat on current supported operating systems
# Functions that are not defined in any OS that we are targeting
# neither on macOS, Windows or Linux.
list(APPEND CompatBase
        common/strtonum.c
        common/strmode.c
        common/pwcache.c
        common/ohash.c
        common/fmt_scaled.c
        common/getbsize.c
        common/merge.c
        common/heapsort.c
        common/recallocarray.c
)

if(USE_LIBWHEREAMI)
        list(APPEND CompatBase common/progname.c)
endif()

if (UNIX)
        list(APPEND CompatBase unix/devname.c )
        if (APPLE) 
        list(APPEND CompatBase darwin/explicit_bzero.c darwin/reallocarray.c)
        endif()
        if (LINUX)
        list(APPEND CompatBase linux/strlcat.c linux/setmode.c unkown_brother/strlcpy.c)
        endif()
endif()

if (WIN32) 
        list(APPEND CompatBase win32/strtoul.c unkown_brother/strlcpy.c)
endif()

add_library(
        compat
        ${CompatBase}
)

if(USE_LIBWHEREAMI)
        target_link_libraries(compat PRIVATE whereami)
        target_include_directories(compat PRIVATE "${CMAKE_SOURCE_DIR}/libwhereami/src")
endif()
target_include_directories(compat PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")