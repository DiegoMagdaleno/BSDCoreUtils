#ifdef __APPLE__
#include <CommonCrypto/CommonDigest.h>
#endif
#ifdef __linux__
#include <openssl/sha.h>
#endif

#ifdef __APPLE__
#define SHA256_CTX CC_SHA256_CTX
#define SHA256Init CC_SHA256_Init
#define SHA256Update CC_SHA256_Update
#define SHA256Final CC_SHA256_Final
#endif

#ifdef __linux__
#define SHA256_CTX SHA256_CTX
#define SHA256Init SHA256_Init
#define SHA256Update SHA256_Update
#define SHA256Final SHA256_Final
#endif


char *SHA256End(SHA256_CTX *, char *);
char *SHA256File(const char *, char *);
