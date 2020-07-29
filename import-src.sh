#!/bin/sh
#
# import-src.sh - Import specific release of OpenBSD source in to
#                 this tree.  Primarily for maintenance use when
#                 a new version of OpenBSD comes out.
#
# Author: David Cantrell <david.l.cantrell@gmail.com>
# Author: Diego Magdaleno <diegomagdaleno@protonmail.com>
#

OS="$(uname)"
if [ "$OS" = "Darwin" ]; then
    if hash gmktemp 2>/dev/null; then
        TMPDIR="$(gmktemp -d --tmpdir=${CWD})"
    else
        echo "You need GNU coreutils to run this script"
        exit 1
    fi
else
    TMPDIR="$(mktemp -d --tmpdir=${CWD})"
fi


PATH=/bin:/usr/bin

if [ "$OS" = Darwin ]; then
    if hash greadlink 2>/dev/null; then
        CWD="$(dirname "$(greadlink -f "$0")")"
    else
        echo "You need GNU coreutils to run this script on Darwin"
        exit 1
    fi
else
    CWD="$(dirname "$(readlink -f "$0")")"
fi

if ["$OS" = Darwin]; then
    if hash greadlink 2>/dev/null; then
        FILE_SOURCE_LIST=($(find $CWD/configurations -type f \( -name "*.conf"\) -exec greadlink -f {} \;))
    else
        echo "You need GNU coreutils to run this script on Darwin"
        exit 1
    fi
else
    FILE_SOURCE_LIST=($(find $CWD/configurations -type f \( -name "*.conf"\) -exec readlink -f {} \;)) #TODO: Verifiy this works properly on Linux. Due to the use of GNU find
fi

for configuration in "${FILE_SOURCE_LIST[@]}"
do
    . $configuration
done

fail_exit() {
    cd ${CWD}
    rm -rf ${TMPDIR}
    exit 1
}

for sub in compat src ; do
    [ -d ${CWD}/${sub} ] || mkdir -p ${CWD}/${sub}
done

cd ${TMPDIR}
curl -L --retry 3 --ftp-pasv -O ${SRC} || fail_exit
gzip -dc src.tar.gz | tar -xvf -

for p in ${CMDS} ; do
    sp="$(basename ${p})"
    find ${p} -type d -name CVS | xargs rm -rf
    
    # Rename the upstream Makefile for later manual checking.  We don't
    # commit these to our tree, but just look at them when rebasing and
    # pick up any rule changes to put in our Makefile.am files.
    if [ -f "${p}/Makefile" ]; then
        mv ${p}/Makefile ${p}/Makefile.bsd
    fi
    
    # Copy in the upstream files
    [ -d ${CWD}/src/${dp} ] || mkdir -p ${CWD}/src/${dp}
    cp -pr ${p}/* ${CWD}/src/${dp}
done

if [ "$OS" = "Linux" ]; then
    echo "Your OS is Linux, removing chflags as it is not supported"
    rm ${CWD}/src/chmod/chflags.1
fi

# 'compat' is our static library with a subset of BSD library functions
cp -p lib/libc/gen/pwcache.c ${CWD}/compat
cp -p lib/libc/gen/setmode.c ${CWD}/compat
cp -p lib/libc/gen/getbsize.c ${CWD}/compat
cp -p lib/libc/gen/devname.c ${CWD}/compat
cp -p lib/libc/stdlib/merge.c ${CWD}/compat
cp -p lib/libc/stdlib/recallocarray.c ${CWD}/compat
cp -p lib/libc/stdlib/strtonum.c ${CWD}/compat
cp -p lib/libc/string/strmode.c ${CWD}/compat
cp -p lib/libutil/logwtmp.c ${CWD}/compat
cp -p lib/libutil/ohash.c ${CWD}/compat
cp -p lib/libutil/ohash.h ${CWD}/compat
cp -p lib/libutil/fmt_scaled.h ${CWD}/compat

# These files are needed for the factor command
cp -p games/primes/primes.h ${CWD}/src/factor
cp -p games/primes/pattern.c ${CWD}/src/factor
cp -p games/primes/pr_tbl.c ${CWD}/src/factor

# Clean up
rm -rf ${TMPDIR}
