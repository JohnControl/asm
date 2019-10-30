// timing.h
#ifndef TIMING_H
#define TIMING_H

#include <time.h>
#include <inttypes.h>

class Time
{
private:
  struct timespec start, end;

public:
  void tic();
  void toc();
  uint64_t elapsed();

};

#endif