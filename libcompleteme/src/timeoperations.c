#include "timeoperations.h"

static inline long long
filetime_to_hnsec (const FILETIME *ft)
{
  long long win_time
      = ((long long)ft->dwHighDateTime << 32) + ft->dwLowDateTime;
  return win_time - 116444736000000000LL; /* UNIX EPOCH */
}

struct timespec
filetime_to_timespec(const FILETIME *ft) {
    struct timespec spec;
    long long win_time = filetime_to_hnsec(ft);

    spec.tv_sec = (time_t)(win_time/10000000);
    spec.tv_nsec = (long)(win_time % 10000000) * 100;

    return spec;
}