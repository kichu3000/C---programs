// timer.h
#ifndef TIMER_H
#define TIMER_H

#include <time.h>

clock_t startTimer();
double endTimer(clock_t start, const char *label);

#endif
