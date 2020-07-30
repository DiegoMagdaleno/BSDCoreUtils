bin_PROGRAMS = mv
dist_man_MANS = mv.1

mv_SOURCES = mv.c cp.c rm.c
mv_CFLAGS = -I$(top_srcdir)/compat -D_DARWIN_C_SOURCE
mv_LDADD = $(top_builddir)/compat/libcompat.la
