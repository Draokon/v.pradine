
#ifndef TIMER_H
#define TIMER_H

#include <chrono>

using TimerPoint = std::chrono::high_resolution_clock::time_point;

inline TimerPoint start_timer() {
    return std::chrono::high_resolution_clock::now();
}

inline double elapsed_time(const TimerPoint& start) {
    return std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - start).count();
}

#endif
