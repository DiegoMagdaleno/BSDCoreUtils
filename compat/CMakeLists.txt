#Basic list of libcompat on current supported operating systems
list(APPEND BasicCompat
        setmode.c
        strtonum.c
        strmode.c
        pwcache.c
        ohash.c
        fmt_scaled.c
        getbsize.c
        devname.c
        merge.c
        heapsort.c
        recallocarray.c)


if(LINUX)
    list(APPEND BasicCompat strlcpy.c
            strlcat.c)
endif()

if(APPLE)
    list(APPEND BasicCompat reallocarray.c)
endif()

add_library(
        compat
        ${BasicCompat}
)

