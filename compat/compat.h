/*
 * compat.h
 * Local prototype definitions for functions put together in this library.
 * We don't have the full OpenBSD system headers, so use this header file
 * to be a placeholder.
 */

/* 
 * Reference from Apple's archived OS X (now macOS documentation 
 * we need to import this else we are going to get a "declaration expected at line 
 * 29" 
 * 
 * including types.h allows us to fix erros in the mget declaration
 * 
 */
#if defined __APPLE__
#include <pwd.h>
#include <grp.h>
#include <sys/types.h>
#endif

/* setmode.c */
mode_t getmode(const void *, mode_t);
void *setmode(const char *);

/* strtonum.c */
long long strtonum(const char *, long long, long long, const char **);

/* strmode.c */
void strmode(int, char *);

/* pwcache.c */
/* Darwin (OSX/macOS) requires the nouser and nogroup
to be added */

#if defined __APPLE__
char *user_from_uid(uid_t, int nouser);
char *group_from_gid(gid_t, int nogroup);
#else
char *user_from_uid(uid_t, int);
char *group_from_gid(gid_t, int);
#endif

/* logwtmp.c */
void logwtmp(const char *, const char *, const char *);

/* fmt_scaled.c */
int scan_scaled(char *, long long *);
int fmt_scaled(long long, char *);

/* getbsize.c */
char *getbsize(int *, long *);

/* devname.c */
char *devname(dev_t, mode_t);

/* merge.c */
int mergesort(void *, size_t, size_t, int (*)(const void *, const void *));

/* heapsort.c */
int heapsort(void *, size_t, size_t, int (*)(const void *, const void *));

/* recallocarray.c */
void *recallocarray(void *, size_t, size_t, size_t);

/* reallocarray.c */
void *reallocarray(void *ptr, size_t nmemb, size_t size);

/* 
 * macOS doesn't have a mtio.h
 * so the solution we perform here
 * is declaring the necesary definitions
 * and structures
 */
#ifdef __APPLE__

struct mtop
{
    short mt_op;
    daddr_t mt_count;
};
#define MTFSR 3
#define MTBSR 4
#define MTIOCTOP _IOW('m', 1, struct mtop)

struct mtget
{
    short mt_type;
    short mt_dsreg;
    short mt_erreg;
    short mt_resid;
    daddr_t mt_fileno;
    daddr_t mt_blkno;
};

#define MTIOCGET _IOR('m', 2, struct mtget)

#endif

/*
 * Darwin comes with an outdated version of sys/queue.h
 * however since Darwin is BSD based we can fix this by 
 * using a fake queue, and redefinging a lot of the structures
 */
#ifdef __APPLE__
#undef SIMPLEQ_HEAD
#undef SIMPLEQ_ENTRY
#undef SIMPLEQ_FOREACH
#undef SIMPLEQ_INSERT_TAIL
#undef SIMPLEQ_FIRST
#undef SIMPLEQ_END
#undef SIMPLEQ_NEXT

#define SIMPLEQ_FIRST(head) ((head)->sqh_first)
#define SIMPLEQ_EMPTY(head) (SIMPLEQ_FIRST(head) == SIMPLEQ_END(head))
#define SIMPLEQ_END(head) NULL

#define SIMPLEQ_HEAD(name, type) \
    struct name                  \
    {                            \
        struct type *sqh_first;  \
        struct type **sqh_last;  \
    }

#define SIMPLEQ_ENTRY(type)    \
    struct                     \
    {                          \
        struct type *sqe_next; \
    }

#define SIMPLEQ_INSERT_TAIL(head, elm, field)      \
    do                                             \
    {                                              \
        (elm)->field.sqe_next = NULL;              \
        *(head)->sqh_last = (elm);                 \
        (head)->sqh_last = &(elm)->field.sqe_next; \
    } while (0)

#define SIMPLEQ_HEAD_INITIALIZER(head) \
    {                                  \
        NULL, &(head).sqh_first        \
    }

#define SIMPLEQ_FOREACH(var, head, field) \
    for ((var) = SIMPLEQ_FIRST(head);     \
         (var) != SIMPLEQ_END(head);      \
         (var) = SIMPLEQ_NEXT(var, field))
#endif
/*
 * MAXBSIZE does not exist on Linux because filesystem block size
 * limits are per filesystem and not consistently enforced across
 * the different filesystems.  If you look at e2fsprogs and its
 * header files, you'll see the max block size is defined as 65536
 * via (1 << EXT2_MAX_BLOCK_LOG_SIZE) where EXT2_MAX_BLOCK_LOG_SIZE
 * is 16.  On OpenBSD, MAXBSIZE is simply (64 * 1024), which is
 * 65536.  So we'll just define that here so as to avoid having
 * bsdutils depend on e2fsprogs to compile.
 */
#define MAXBSIZE (64 * 1024)

/*
 * fmt_scaled(3) specific flags.
 * This comes from lib/libutil/util.h in the OpenBSD source.
 */
#define FMT_SCALED_STRSIZE 7 /* minus sign, 4 digits, suffix, null byte */
