

list(APPEND crossCompatibleBins
        arch
        basename
        bsdvers
        cat
        chmod
        chroot
        comm
        cp
        csplit
        cut
        date
        dd
        dirname
        du
        echo
        env
        expand
        expr
        factor
        false
        fmt
        fold
        head
        id
        join
        ln
        logname
        ls
        )

# This tools are missing support for other platforms
#if(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
    #list(APPEND crossCompatibleBins xinstall stty)
#endif()

foreach(binary ${crossCompatibleBins})
    add_subdirectory(${binary})
endforeach()
