bin_PROGRAMS = fmt
dist_man_MANS = fmt.1

fmt_SOURCES = fmt.c
fmt_CFLAGS = -I$(top_srcdir)/compat -D_XOPEN_SOURCE
fmt_LDADD = $(top_builddir)/compat/libcompat.la


if LINUX
    fmt_CFLAGS += -D_GNU_SOURCE
else
    fmt_CFLAGS += -D_DEFAULT_SOURCE
endif