#include <stdio.h>
#include "timer.h"

clock_t startTimer()
{
    return clock();
}

double endTimer(clock_t start, const char *label)
{
    clock_t end = clock();
    double time_spent = ((double)(end - start) / CLOCKS_PER_SEC) * 1000;
    printf("%s: %.2f ms\n", label, time_spent);
    return time_spent;
}