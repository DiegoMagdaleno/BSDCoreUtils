#include "compat.h"

#include <sys/types.h>
#include <sys/time.h>
#include <sys/stat.h>

#include <fcntl.h>
#include <string.h>
#include <unistd.h>

#include <utmpx.h>

void
darwinlogwtmpx(const char *line, const char *name, const char *host)
{
	struct stat buf;
	struct utmpx ut;

	int fd;

	if((fd = open(_PATH_UTMPX, O_WRONLY|O_APPEND|O_CLOEXEC)) == -1)
		return;
	if (fstat(fd, &buf) == 0){
		(void) strncpy(ut.ut_line, line, sizeof(ut.ut_line));
		/* We use ut.ut_user as ut.ut_name is just an alias to
		 * this so we should have no issues */
		(void) strncpy(ut.ut_user, name, sizeof(ut.ut_user));
		(void) strncpy(ut.ut_host, host, sizeof(ut.ut_host));
		/* Compat mode is disabled so we must use the ut_tv property 
		* to get a timeval struct */
		// we also get the property tv_sec so we can call time() as that
		// takes a time_t
		(void) time(&ut.ut_tv.tv_sec);
		if (write(fd, &ut, sizeof(struct utmpx)) != sizeof(struct utmpx))
			(void) ftruncate(fd, buf.st_size);
	}
	(void) close(fd);
}