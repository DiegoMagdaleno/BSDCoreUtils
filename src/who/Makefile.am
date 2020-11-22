bin_PROGRAMS = who
dist_man_MANS = who.1

who_SOURCES = who.c utmpentry.c
who_CFLAGS = -I$(top_srcdir)/compat
who_LDADD = $(top_builddir)/compat/libcompat.la

if LINUX
who_CFLAGS += -DSUPPORT_UTMP
endif

if DARWIN
who_CFLAGS += -DSUPPORT_UTMPX
endif