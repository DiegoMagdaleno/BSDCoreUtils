cmake_minimum_required(VERSION 3.16)
project(bsdcoreutils)

set(CMAKE_C_STANDARD 11)

add_library(bsdcoreutils STATIC
    compat/devname.c
    compat/fmt_scaled.c
    compat/getbsize.c
    compat/heapsort.c
    compat/merge.c
    compat/ohash.c
    compat/pwcache.c
    compat/reallocarray.c
    compat/recallocarray.c
    compat/setmode.c
    compat/strlcat.c
    compat/strlcpy.c
    compat/strmode.c)
