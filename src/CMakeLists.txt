list(APPEND crossCompatibleBins
        arch
        basename
        bsdvers
        cat
        chmod
        chmod
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
        mkdir
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
        touch
        tr
        true
        tsort
        tty
        uname
        unexpand
        uniq
        users
        wc
        who
        xargs
        yes)

# This tools are missing support for other platforms
if(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
    list(APPEND crossCompatibleBins xinstall stty)
endif()

#foreach(binary ${crossCompatibleBins})
 #   add_subdirectory(${binary})
#endforeach()

add_subdirectory(chmod)