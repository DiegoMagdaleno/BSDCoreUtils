/* mdXhl.c
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <phk@FreeBSD.org> wrote this file.  As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return.   Poul-Henning Kamp
 * ----------------------------------------------------------------------------
 */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

#include "commoncrypto.h"

#ifdef __linux__
#include <openssl/sha.h>
#endif

#ifdef __APPLE__
#define LENGHT CC_SHA256_DIGEST_LENGHT
#endif

#ifdef __linux__
#define LENGTH SHA256_DIGEST_LENGTH
#endif

char *SHA256FileChunk(const char *, char *, off_t, off_t);

char *
SHA256End(SHA256_CTX *ctx, char *buf)
{
	int i;
	unsigned char digest[LENGTH];
	static const char hex[]="0123456789abcdef";

	if (!buf)
		buf = malloc(2*LENGTH + 1);
	if (!buf)
		return 0;
	SHA256Final(digest, ctx);
	for (i = 0; i < LENGTH; i++) {
		buf[i+i] = hex[digest[i] >> 4];
		buf[i+i+1] = hex[digest[i] & 0x0f];
	}
	buf[i+i] = '\0';
	return buf;
}

char *
SHA256File(const char *filename, char *buf)
{
	return (SHA256FileChunk(filename, buf, 0, 0));
}

char *
SHA256FileChunk(const char *filename, char *buf, off_t ofs, off_t len)
{
	unsigned char buffer[16*1024];
	SHA256_CTX ctx;
	int fd, readrv, e;
	off_t remain;

	if (len < 0) {
		errno = EINVAL;
		return NULL;
	}

	SHA256Init(&ctx);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return NULL;
	if (ofs != 0) {
		errno = 0;
		if (lseek(fd, ofs, SEEK_SET) != ofs ||
		    (ofs == -1 && errno != 0)) {
			readrv = -1;
			goto error;
		}
	}
	remain = len;
	readrv = 0;
	while (len == 0 || remain > 0) {
		if (len == 0 || remain > (off_t)sizeof(buffer))
			readrv = read(fd, buffer, sizeof(buffer));
		else
			readrv = read(fd, buffer, remain);
		if (readrv <= 0) 
			break;
		SHA256Update(&ctx, buffer, readrv);
		remain -= readrv;
	} 
error:
	e = errno;
	close(fd);
	errno = e;
	if (readrv < 0)
		return NULL;
	return (SHA256End(&ctx, buf));
}
