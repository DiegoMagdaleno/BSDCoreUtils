#include <string.h>

enum {
    DEV_NULL,
    DEV_ZERO,
    DEV_URANDOM,
    NOT_DEVICE = -1
};

#define DEV_FD_PREFIX "/dev/fd"

typedef struct { char *key; int val; } t_symstruct;

int get_device_type(const char*);
int get_device_fd(const char*);