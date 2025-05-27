#ifndef TIMER_H
#define TIMER_H

#include "Lib.h"

using TimerPoint = high_resolution_clock::time_point;

inline TimerPoint start_timer() {
    return high_resolution_clock::now();
}

inline double elapsed_time(const TimerPoint& start) {
    return duration<double>(high_resolution_clock::now() - start).count();
}

#endif
