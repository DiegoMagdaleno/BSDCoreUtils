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
if  [ "$OS" = "Darwin" ]; then
    PATH=/bin:/usr/bin:/usr/local/bin
else
    PATH=/bin:/usr/bin
fi

if [ "$OS" = "Darwin" ]; then
    if hash greadlink 2>/dev/null; then
        CWD="$(dirname "$(greadlink -f "$0")")"
    else    
        echo "You need GNU coreutils to run this script on Darwin"
        exit 1
    fi
else
    CWD="$(dirname "$(readlink -f "$0")")"
fi

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

if [ "$OS" = "Darwin" ]; then
    if hash greadlink 2>/dev/null; then
        FILE_SOURCE_LIST=($(find $CWD/configurations -type f \( -name "*.conf" \) -exec greadlink -f {} \;))
    else
        echo "You need GNU coreutils to run this script on Darwin"
        exit 1
    fi
else
    FILE_SOURCE_LIST=($(find $CWD/configurations -type f \( -name "*.conf" \) -exec readlink -f {} \;))#TODO: Verifiy this works properly on Linux. Due to the use of GNU find
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

for file in "${COMPAT_TOOLS_C[@]}"
do
    cp -p $file ${CWD}/compat
done

for header in "${COMPAT_TOOLS_HEADERS[@]}"
do 
    cp -p $header ${CWD}/headers/
done

for filef in "${FACTOR_C[@]}"
do
    cp -p $filef ${CWD}/src/factor
done

for headerf in "${FACTOR_HEADER[@]}"
do
    cp -p $filef ${CWD}/src/factor
done

# Clean up
rm -rf ${TMPDIR}
