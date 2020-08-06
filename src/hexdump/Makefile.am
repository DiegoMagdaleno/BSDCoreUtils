bin_PROGRAMS = hexdump

hexdump_SOURCES = conv.c display.c hexdump.c hexsyntax.c odsyntax.c parse.c
hexdump_CFLAGS = -I$(top_srcdir)/compat -D_BSD_SOURCE
hexdump_LDADD = $(top_builddir)/compat/libcompat.la


EXTRA_DIST =  hexdump.h