#!/bin/sh
#
# import-src.sh - Import specific release of OpenBSD source in to
#                 this tree.  Primarily for maintenance use when
#                 a new version of OpenBSD comes out.
#
# Author: David Cantrell <david.l.cantrell@gmail.com>
# Author: Diego Magdaleno <diegomagdaleno@protonmail.com>
#

# Set our fail exist function, this is useful for Downdalos
function fail_exit() {
    cd ${CWD}
    rm -rf ${TMPDIR}
    exit 1
}

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

for sub in compat src ; do
    [ -d ${CWD}/${sub} ] || mkdir -p ${CWD}/${sub}
done

# While it doesn't really make sense we are copying and pasting the code
# for the same operating and this could be a function
# the problem is, this is bash, so positional paremeters just suck, so its better
# to write a few lines and just avoid problems.

# Note for Diego of the future if you screw up, you did this to yourself.
cd ${TMPDIR}
curl -L --retry 3 --ftp-pasv -O ${SRC} || fail_exit
if [ "$OS" = "Darwin" ]; then
    SHA256OFSRC="$(shasum -a 256 src.tar.gz | awk '{print $1}')"
else
    SHA256OFSRC="$(sha256sum --check src.tar.gz)"
fi
if [ "$SHA256OFSRC" != ${SHA256SRC} ]; then
    echo "Error, the integrity of the file failed, operating is unsafe and cannot continue."
    exit 1
fi
gzip -dc src.tar.gz | tar -xvf -
curl -L --retry 3 --ftp-pasv -O ${SYS} || fail_exit
if [ "$OS" = "Darwin" ]; then
    SHA256OFSYS="$(shasum -a 256 sys.tar.gz | awk '{print $1}')"
else
    SHA256OFSYS="$(sha256sum --check sys.tar.gz)"
fi
if [ "$SHA256OFSYS" != ${SHA256SYS} ]; then
    echo "Error, the integrity of the file failed, operating is unsafe and cannot continue."
    exit 1
fi
gzip -dc sys.tar.gz | tar -xvf -

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
    if [ ! -d ${CWD}/compat/headers ]; then
        mkdir -p ${CWD}/compat/headers
    fi
    cp -p $header ${CWD}/compat/headers/
done

for filef in "${FACTOR_C[@]}"
do
    cp -p $filef ${CWD}/src/factor
done

for headerf in "${FACTOR_HEADER[@]}"
do
    cp -p $filef ${CWD}/src/factor
done

################
# COMMON EDITS #
################

# Perform some common compatibility edits on the imported source
for cfile in ${CWD}/compat/*.c ; do
    # This macro does not exist and we don't want it #TODO: Does this exist on Darwin?
    if [ "$OS" = "Darwin" ]; then
        gsed -i -e '/DEF_WEAK/d' ${cfile}
    else
        sed -i -e '/DEF_WEAK/d' ${cfile}
    fi
    
    # Include our 'compat.h' header before other includes
    # TODO: Redo this to look better currently a nested if depending on the operating system
    # is not a very clean solution!
    
    if [ "$OS" = "Darwin" ]; then
        if ! ggrep -q "compat\.h" ${cfile} 2>&1 ; then
            linenum=$(($(ggrep -n ^#include ${cfile} | gsort -n | ghead -n 1 | gcut -d ':' -f 1) - 1))
            [ ${linenum} = 0 ] && linenum=1
            gsed -i -e "${linenum}i #include \"compat.h\"" ${cfile}
        fi
    else
        if ! grep -q "compat\.h" ${cfile} 2>&1 ; then
            linenum=$(($(grep -n ^#include ${cfile} | sort -n | head -n 1 | cut -d ':' -f 1) - 1))
            [ ${linenum} = 0 ] && linenum=1
            sed -i -e "${linenum}i #include \"compat.h\"" ${cfile}
        fi
    fi
done

# Remove unnecessary declarations in compat/util.h
if [ "$OS" = "Darwin" ]; then
    strtline=$(ggrep -n "^__BEGIN_DECLS" ${CWD}/compat/headers/util.h | gcut -d ':' -f 1)
    lastline=$(ggrep -n "^__END_DECLS" ${CWD}/compat/headers/util.h | gcut -d ':' -f 1)
    sed -i -e "${strtline},${lastline}d" ${CWD}/compat/headers/util.h
else
    strtline=$(grep -n "^__BEGIN_DECLS" ${CWD}/compat/headers/util.h | cut -d ':' -f 1)
    lastline=$(grep -n "^__END_DECLS" ${CWD}/compat/headersutil.h | cut -d ':' -f 1)
    sed -i -e "${strtline},${lastline}d" ${CWD}/compat/headers/util.h
fi

# Common edits needed for src/ files
for cfile in $(find ${CWD}/src -type f -name '*.c' -print) ; do
    # remove __dead
    if [ "$OS" = "Darwin" ]; then
        gsed -i -r 's|\s+__dead\s+| |g' ${cfile}
        gsed -i -r 's|^__dead\s+||g' ${cfile}
        gsed -i -r 's|\s+__dead$||g' ${cfile}
        gsed -i -r 's|\s+__dead;|;|g' ${cfile}
    else
        sed -i -r 's|\s+__dead\s+| |g' ${cfile}
        sed -i -r 's|^__dead\s+||g' ${cfile}
        sed -i -r 's|\s+__dead$||g' ${cfile}
        sed -i -r 's|\s+__dead;|;|g' ${cfile}
    fi
done

#####################
# APPLY ANY PATCHES #
#####################

if [ -d ${CWD}/patches/compat ]; then
    for patchfile in ${CWD}/patches/compat/*.patch ; do
        destfile="$(basename ${patchfile} .patch)"
        [ -f "${CWD}/compat/${destfile}.orig" ] && rm -f "${CWD}/compat/${destfile}.orig"
        if [ "$OS" = "Darwin" ]; then
            gpatch -d ${CWD}/compat -p0 -b -z .orig < ${patchfile}
        else
            patch -d ${CWD}/compat -p0 -b -z .orig < ${patchfile}
        fi
    done
fi

if [ -d ${CWD}/patches/src ]; then
    cd ${CWD}/patches/src
    for subdir in * ; do
        [ -d ${subdir} ] || continue
        for patchfile in ${CWD}/patches/src/${subdir}/*.patch ; do
            destfile="$(basename ${patchfile} .patch)"
            [ -f "${CWD}/src/${subdir}/${destfile}.orig" ] && rm -f "${CWD}/src/${subdir}/${destfile}.orig"
             if [ "$OS" = "Darwin" ]; then 
                gpatch -d ${CWD}/src/${subdir} -p0 -b -z .orig < ${patchfile}
            else
                patch -d ${CWD}/src/${subdir} -p0 -b -z .orig < ${patchfile}
            fi
        done
    done
fi

# Clean up
#rm -rf ${TMPDIR}
