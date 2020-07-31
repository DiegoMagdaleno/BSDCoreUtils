noinst_LTLIBRARIES = libcompat.la
libcompat_la_CFLAGS =
libcompat_la_SOURCES = setmode.c strtonum.c strmode.c pwcache.c \
                       logwtmp.c ohash.c fmt_scaled.c getbsize.c \
                       devname.c merge.c heapsort.c recallocarray.c

if LINUX
    libcompat_la_CFLAGS += -I$(top_srcdir)/compat -D_GNU_SOURCE
    libcompat_la_SOURCES += strlcpy.c strlcat.c
endif

if DARWIN
    libcompat_la_SOURCES += reallocarray.c
endif