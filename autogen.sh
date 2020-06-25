#!/bin/sh
if hash glibtoolize 2>/dev/null; then
    glibtoolize --copy --force
else 
    libtoolize --copy --force
fi
aclocal
autoconf
autoheader --force
automake --foreign --add-missing --copy
rm -rf autom4te.cache
