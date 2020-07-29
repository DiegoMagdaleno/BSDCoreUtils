/* 
 * macOS doesn't have a mtio.h
 * so the solution we perform here
 * is declaring the necessary definitions
 * and structures
 */

#include <sys/types.h>

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