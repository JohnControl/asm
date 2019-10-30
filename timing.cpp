
#include "timing.h"
#include <inttypes.h>

void Time::tic()
{
  clock_gettime(CLOCK_MONOTONIC, &start);
}

void Time::toc()
{
  clock_gettime(CLOCK_MONOTONIC, &end);
}

uint64_t Time::elapsed()
{
  return 1000000000L * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;  
}