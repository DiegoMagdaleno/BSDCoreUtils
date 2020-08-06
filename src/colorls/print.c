/*	$OpenBSD: print.c,v 1.38 2019/02/05 02:17:32 deraadt Exp $	*/
/*	$NetBSD: print.c,v 1.15 1996/12/11 03:25:39 thorpej Exp $	*/

/*
 * Copyright (c) 1989, 1993, 1994
 *	The Regents of the University of California.  All rights reserved.
 *
 * This code is derived from software contributed to Berkeley by
 * Michael Fischbein.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#include <sys/types.h>
#include <sys/stat.h>

#include <err.h>
#include <errno.h>
#include <fts.h>
#if defined __APPLE__
#define user_from_uid user_from_uid_orig
#define group_from_gid group_from_gid_orig
#include <grp.h>
#include <pwd.h>
#undef  user_from_uid
#undef group_from_gid
#else
#include <grp.h>
#include <pwd.h>
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <limits.h>
#if defined __linux__
#include "compat/headers/util.h"
#include <sys/param.h>
#include <sys/sysmacros.h>
#else
#include <util.h>
#endif
#ifdef COLORLS
#include <ctype.h>
#include <termcap.h>
#include <signal.h>
#endif

#include "ls.h"
#include "extern.h"
#include "compat.h"

static int	printaname(FTSENT *, int, int);
static void	printlink(FTSENT *);
static void	printsize(int, off_t);
static void	printtime(time_t);
static int	printtype(mode_t);
static int	compute_columns(DISPLAY *, int *);
#ifdef COLORLS
static void	endcolor(int);
static int	colortype(mode_t);
#endif

#define	IS_NOPRINT(p)	((p)->fts_number == NO_PRINT)

#define	DATELEN		64

#define	SECSPERDAY	(24 * 60 * 60)
#define	SIXMONTHS	(SECSPERDAY * 365 / 2)

#ifdef COLORLS
/* Most of these are taken from <sys/stat.h> */
typedef enum Colors {
	C_DIR,		/* directory */
	C_LNK,		/* symbolic link */
	C_SOCK,		/* socket */
	C_FIFO,		/* pipe */
	C_EXEC,		/* executable */
	C_BLK,		/* block special */
	C_CHR,		/* character special */
	C_SUID,		/* setuid executable */
	C_SGID,		/* setgid executable */
	C_WSDIR,	/* directory writable to others, with sticky bit */
	C_WDIR,		/* directory writable to others, without sticky bit */
	C_NUMCOLORS	/* just a place-holder */
} Colors ;

const char *defcolors = "exfxcxdxbxegedabagacad";

/* colors for file types */
static struct {
	int num[2];
	int bold;
} colors[C_NUMCOLORS];
#endif

void
printscol(DISPLAY *dp)
{
	FTSENT *p;

	for (p = dp->list; p; p = p->fts_link) {
		if (IS_NOPRINT(p))
			continue;
		(void)printaname(p, dp->s_inode, dp->s_block);
		(void)putchar('\n');
	}
}

void
printlong(DISPLAY *dp)
{
	struct stat *sp;
	FTSENT *p;
	NAMES *np;
	char buf[20];
#ifdef COLORLS
	int color_printed = 0;
#endif

	if (dp->list->fts_level != FTS_ROOTLEVEL && (f_longform || f_size))
		(void)printf("total %llu\n", howmany(dp->btotal, blocksize));

	for (p = dp->list; p; p = p->fts_link) {
		if (IS_NOPRINT(p))
			continue;
		sp = p->fts_statp;
		if (f_inode)
			(void)printf("%*llu ", dp->s_inode,
			    (unsigned long long)sp->st_ino);
		if (f_size)
			(void)printf("%*lld ", dp->s_block,
			    howmany((long long)sp->st_blocks, blocksize));
		(void)strmode(sp->st_mode, buf);
		np = p->fts_pointer;
		(void)printf("%s %*u ", buf, dp->s_nlink, sp->st_nlink);
		if (!f_grouponly)
			(void)printf("%-*s  ", dp->s_user, np->user);
		(void)printf("%-*s  ", dp->s_group, np->group);
		if (f_flags)
			(void)printf("%-*s ", dp->s_flags, np->flags);
		if (S_ISCHR(sp->st_mode) || S_ISBLK(sp->st_mode))
			(void)printf("%3u, %3u ",
			    major(sp->st_rdev), minor(sp->st_rdev));
		else if (dp->bcfile)
			(void)printf("%*s%*lld ",
			    8 - dp->s_size, "", dp->s_size,
			    (long long)sp->st_size);
		else
			printsize(dp->s_size, sp->st_size);
		if (f_accesstime)
			printtime(sp->st_atime);
		else if (f_statustime)
			printtime(sp->st_ctime);
		else
			printtime(sp->st_mtime);
#ifdef COLORLS
		if (f_color)
			color_printed = colortype(sp->st_mode);
#endif
		(void)mbsprint(p->fts_name, 1);
#ifdef COLORLS
		if (f_color && color_printed)
			endcolor(0);
#endif
		if (f_type || (f_typedir && S_ISDIR(sp->st_mode)))
			(void)printtype(sp->st_mode);
		if (S_ISLNK(sp->st_mode))
			printlink(p);
		(void)putchar('\n');
	}
}

static int
compute_columns(DISPLAY *dp, int *pnum)
{
	int colwidth;
	extern int termwidth;
	int mywidth;

	colwidth = dp->maxlen;
	if (f_inode)
		colwidth += dp->s_inode + 1;
	if (f_size)
		colwidth += dp->s_block + 1;
	if (f_type || f_typedir)
		colwidth += 1;

	colwidth += 1;
	mywidth = termwidth + 1;	/* no extra space for last column */

	if (mywidth < 2 * colwidth) {
		printscol(dp);
		return (0);
	}

	*pnum = mywidth / colwidth;
	return (mywidth / *pnum);		/* spread out if possible */
}

void
printcol(DISPLAY *dp)
{
	static FTSENT **array;
	static int lastentries = -1;
	FTSENT *p;
	int base, chcnt, col, colwidth, num;
	int numcols, numrows, row;

	if ((colwidth = compute_columns(dp, &numcols)) == 0)
		return;
	/*
	 * Have to do random access in the linked list -- build a table
	 * of pointers.
	 */
	if (dp->entries > lastentries) {
		FTSENT **a;

		if ((a = reallocarray(array, dp->entries, sizeof(FTSENT *))) ==
		    NULL) {
			free(array);
			array = NULL;
			dp->entries = 0;
			lastentries = -1;
			warn(NULL);
			printscol(dp);
			return;
		}
		lastentries = dp->entries;
		array = a;
	}
	for (p = dp->list, num = 0; p; p = p->fts_link)
		if (p->fts_number != NO_PRINT)
			array[num++] = p;

	numrows = num / numcols;
	if (num % numcols)
		++numrows;

	if (dp->list->fts_level != FTS_ROOTLEVEL && (f_longform || f_size))
		(void)printf("total %llu\n", howmany(dp->btotal, blocksize));
	for (row = 0; row < numrows; ++row) {
		for (base = row, col = 0;;) {
			chcnt = printaname(array[base], dp->s_inode, dp->s_block);
			if ((base += numrows) >= num)
				break;
			if (++col == numcols)
				break;
			while (chcnt++ < colwidth)
				putchar(' ');
		}
		(void)putchar('\n');
	}
}

/*
 * print [inode] [size] name
 * return # of characters printed, no trailing characters.
 */
static int
printaname(FTSENT *p, int inodefield, int sizefield)
{
	struct stat *sp;
	int chcnt;
#ifdef COLORLS
	int color_printed = 0;
#endif

	sp = p->fts_statp;
	chcnt = 0;
	if (f_inode)
		chcnt += printf("%*llu ", inodefield,
		    (unsigned long long)sp->st_ino);
	if (f_size)
		chcnt += printf("%*lld ", sizefield,
		    howmany((long long)sp->st_blocks, blocksize));
#ifdef COLORLS
	if (f_color)
		color_printed = colortype(sp->st_mode);
#endif
	chcnt += mbsprint(p->fts_name, 1);
#ifdef COLORLS
	if (f_color && color_printed)
		endcolor(0);
#endif
	if (f_type || (f_typedir && S_ISDIR(sp->st_mode)))
		chcnt += printtype(sp->st_mode);
	return (chcnt);
}

static void
printtime(time_t ftime)
{
	char f_date[DATELEN];
	static time_t now;
	static int now_set = 0;

	if (! now_set) {
		now = time(NULL);
		now_set = 1;
	}

	/*
	 * convert time to string, and print
	 */
	if (strftime(f_date, sizeof(f_date), f_sectime ? "%b %e %H:%M:%S %Y" :
	    (ftime <= now - SIXMONTHS || ftime > now) ? "%b %e  %Y" :
	    "%b %e %H:%M", localtime(&ftime)) == 0)
		f_date[0] = '\0';

	printf("%s ", f_date);
}

void
printacol(DISPLAY *dp)
{
	FTSENT *p;
	int chcnt, col, colwidth;
	int numcols;

	if ( (colwidth = compute_columns(dp, &numcols)) == 0)
		return;

	if (dp->list->fts_level != FTS_ROOTLEVEL && (f_longform || f_size))
		(void)printf("total %llu\n", howmany(dp->btotal, blocksize));
	col = 0;
	for (p = dp->list; p; p = p->fts_link) {
		if (IS_NOPRINT(p))
			continue;
		if (col >= numcols) {
			col = 0;
			(void)putchar('\n');
		}
		chcnt = printaname(p, dp->s_inode, dp->s_block);
		col++;
		if (col < numcols)
			while (chcnt++ < colwidth)
				(void)putchar(' ');
	}
	(void)putchar('\n');
}

void
printstream(DISPLAY *dp)
{
	extern int termwidth;
	FTSENT *p;
	int col;
	int extwidth;

	extwidth = 0;
	if (f_inode)
		extwidth += dp->s_inode + 1;
	if (f_size)
		extwidth += dp->s_block + 1;
	if (f_type)
		extwidth += 1;

	for (col = 0, p = dp->list; p != NULL; p = p->fts_link) {
		if (IS_NOPRINT(p))
			continue;
		if (col > 0) {
			(void)putchar(','), col++;
			if (col + 1 + extwidth + mbsprint(p->fts_name, 0) >=
			    termwidth)
				(void)putchar('\n'), col = 0;
			else
				(void)putchar(' '), col++;
		}
		col += printaname(p, dp->s_inode, dp->s_block);
	}
	(void)putchar('\n');
}

static int
printtype(mode_t mode)
{
	switch (mode & S_IFMT) {
	case S_IFDIR:
		(void)putchar('/');
		return (1);
	case S_IFIFO:
		(void)putchar('|');
		return (1);
	case S_IFLNK:
		(void)putchar('@');
		return (1);
	case S_IFSOCK:
		(void)putchar('=');
		return (1);
	}
	if (mode & (S_IXUSR | S_IXGRP | S_IXOTH)) {
		(void)putchar('*');
		return (1);
	}
	return (0);
}

#ifdef COLORLS
static int
putch(int c)
{
	(void)putchar(c);
	return 0;
}

static int
writech(int c)
{
	char tmp = c;

	(void)write(STDOUT_FILENO, &tmp, 1);
	return 0;
}

static void
printcolor(Colors c)
{
	char *ansiseq;

	if (colors[c].bold)
		tputs(enter_bold, 1, putch);

	if (colors[c].num[0] != -1) {
		ansiseq = tgoto(ansi_fgcol, 0, colors[c].num[0]);
		if (ansiseq)
			tputs(ansiseq, 1, putch);
	}
	if (colors[c].num[1] != -1) {
		ansiseq = tgoto(ansi_bgcol, 0, colors[c].num[1]);
		if (ansiseq)
			tputs(ansiseq, 1, putch);
	}
}

static void
endcolor(int sig)
{
	tputs(ansi_coloff, 1, sig ? writech : putch);
	tputs(attrs_off, 1, sig ? writech : putch);
}

static int
colortype(mode_t mode)
{
	switch (mode & S_IFMT) {
	case S_IFDIR:
		if (mode & S_IWOTH)
			if (mode & S_ISTXT)
				printcolor(C_WSDIR);
			else
				printcolor(C_WDIR);
		else
			printcolor(C_DIR);
		return (1);
	case S_IFLNK:
		printcolor(C_LNK);
		return (1);
	case S_IFSOCK:
		printcolor(C_SOCK);
		return (1);
	case S_IFIFO:
		printcolor(C_FIFO);
		return (1);
	case S_IFBLK:
		printcolor(C_BLK);
		return (1);
	case S_IFCHR:
		printcolor(C_CHR);
		return (1);
	default:;
	}
	if (mode & (S_IXUSR | S_IXGRP | S_IXOTH)) {
		if (mode & S_ISUID)
			printcolor(C_SUID);
		else if (mode & S_ISGID)
			printcolor(C_SGID);
		else
			printcolor(C_EXEC);
		return (1);
	}
	return (0);
}

void
parsecolors(const char *cs)
{
	int i;
	int j;
	size_t len;
	char c[2];
	short legacy_warn = 0;

	if (cs == NULL)
		cs = "";	/* LSCOLORS not set */
	len = strlen(cs);
	for (i = 0; i < (int)C_NUMCOLORS ; i++) {
		colors[i].bold = 0;

		if (len <= 2 * (size_t)i) {
			c[0] = defcolors[2 * i];
			c[1] = defcolors[2 * i + 1];
		} else {
			c[0] = cs[2 * i];
			c[1] = cs[2 * i + 1];
		}
		for (j = 0; j < 2 ; j++) {
			/* Legacy colours used 0-7 */
			if (c[j] >= '0' && c[j] <= '7') {
				colors[i].num[j] = c[j] - '0';
				if (!legacy_warn) {
					warnx("LSCOLORS should use "
					    "characters a-h instead of 0-9 ("
					    "see the manual page)");
				}
				legacy_warn = 1;
			} else if (c[j] >= 'a' && c[j] <= 'h')
				colors[i].num[j] = c[j] - 'a';
			else if (c[j] >= 'A' && c[j] <= 'H') {
				colors[i].num[j] = c[j] - 'A';
				colors[i].bold = 1;
			} else if (tolower((unsigned char)c[j]) == 'x')
				colors[i].num[j] = -1;
			else {
				warnx("invalid character '%c' in LSCOLORS"
				    " env var", c[j]);
				colors[i].num[j] = -1;
			}
		}
	}
}

void
colorquit(int sig)
{
	endcolor(sig);

	(void)signal(sig, SIG_DFL);
	(void)kill(getpid(), sig);
}

#endif /* COLORLS */

static void
printlink(FTSENT *p)
{
	int lnklen;
	char name[PATH_MAX], path[PATH_MAX];

	if (p->fts_level == FTS_ROOTLEVEL)
		(void)snprintf(name, sizeof(name), "%s", p->fts_name);
	else
		(void)snprintf(name, sizeof(name),
		    "%s/%s", p->fts_parent->fts_accpath, p->fts_name);
	if ((lnklen = readlink(name, path, sizeof(path) - 1)) == -1) {
		(void)fprintf(stderr, "\nls: %s: %s\n", name, strerror(errno));
		return;
	}
	path[lnklen] = '\0';
	(void)printf(" -> ");
	(void)mbsprint(path, 1);
}

static void
printsize(int width, off_t bytes)
{
	char ret[FMT_SCALED_STRSIZE];

	if ((f_humanval) && (fmt_scaled(bytes, ret) != -1)) {
		(void)printf("%*s ", width, ret);
		return;
	}
	(void)printf("%*lld ", width, (long long)bytes);
}
