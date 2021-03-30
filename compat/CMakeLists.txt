#Basic list of libcompat on current supported operating systems
list(APPEND BasicCompat
        src/setmode.c
        src/strtonum.c
        src/strmode.c
        src/pwcache.c
        src/ohash.c
        src/fmt_scaled.c
        src/getbsize.c
        src/devname.c
        src/merge.c
        src/heapsort.c
        src/recallocarray.c)


if(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
    list(APPEND BasicCompat src/strlcpy.c
            src/strlcat.c)
endif()

if(${CMAKE_SYSTEM_NAME} STREQUAL "Darwin")
    list(APPEND BasicCompat src/reallocarray.c
                        src/explicit_bzero.c)
endif()

add_library(
        compat
        ${BasicCompat}
)

target_include_directories(compat PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")
