#Basic list of libcompat on current supported operating systems
list(BasicCompat setmode.c
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
    list(BasicCompat APPEND strlcpy.c
            strlcat.c)
endif()

if(APPLE)
    list(BasicCompat APPEND reallocarray.c)
endif()

add_library(
        libcompat
        ${BasicCompat}
)

