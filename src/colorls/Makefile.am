bin_PROGRAMS = colorls
dist_man_MANS = colorls.1

colorls_SOURCES = cmp.c ls.c main.c print.c util.c utf8.c
colorls_CFLAGS = -I$(top_srcdir)/compat -D_XOPEN_SOURCE=700 -DCOLORLS
colorls_LDADD = $(top_builddir)/compat/libcompat.la  -lncurses -lutil 
if DARWIN
    colorls_CFLAGS += -D_DARWIN_C_SOURCE
endif
if LINUX
    colorls_CFLAGS += -D_GNU_SOURCE
endif

EXTRA_DIST = extern.h ls.h