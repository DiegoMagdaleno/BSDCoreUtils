bin_PROGRAMS = ls
dist_man_MANS = ls.1

ls_SOURCES = cmp.c ls.c main.c print.c util.c utf8.c
ls_CFLAGS = -I$(top_srcdir)/compat -D_XOPEN_SOURCE=700
ls_LDADD = $(top_builddir)/compat/libcompat.la
if DARWIN
    ls_CFLAGS += -D_DARWIN_C_SOURCE
endif
if LINUX
    ls_CFLAGS += -D_DEFAULT_SOURCE
endif

EXTRA_DIST = extern.h ls.h
