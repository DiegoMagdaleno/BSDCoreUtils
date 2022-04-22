

list(APPEND crossCompatibleBins
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
        df
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
        mkdir
        mknod
        mktemp
        mv
        nice
        nl
        nohup
        paste
        pathchk
        pr
        printenv
        printf
        pwd
        readlink
        realpath
        rm
        rmdir
        sleep
        sort
        split
        stat
        sync
        tee
        test
        touch
        tr
        true
        tsort
        tty
        uname
        uniq
        users
        wc
        who
        xargs
        yes
        )

# This tools are missing support for other platforms
if(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
    list(APPEND crossCompatibleBins xinstall stty arch)
endif()

# This tools are missing support for other platforms
if(${CMAKE_SYSTEM_NAME} STREQUAL "Darwin")
    list(APPEND crossCompatibleBins arch)
endif()

foreach(binary ${crossCompatibleBins})
    add_subdirectory(${binary})
endforeach()
