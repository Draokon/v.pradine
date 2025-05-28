/**
 * @file Timer.h
 * @brief Pagalbinės funkcijos laiko matavimui (aukštos raiškos laikrodis)
 */

#ifndef TIMER_H
#define TIMER_H

#include "Lib.h"

/**
 * @typedef TimerPoint
 * @brief Aukštos raiškos laikrodžio laiko taškas (pradžiai ar pabaigai žymėti)
 */
using TimerPoint = high_resolution_clock::time_point;

/**
 * @brief Gražina dabartinį laiką 
 * @return TimerPoint - laiko žymė
 */
inline TimerPoint start_timer() {
    return high_resolution_clock::now();
}

/**
 * @brief Apskaičiuoja praėjusį laiką sekundėmis nuo pradžios taško
 * @param start Pradžios laiko taškas
 */
inline double elapsed_time(const TimerPoint& start) {
    return duration<double>(high_resolution_clock::now() - start).count();
}

#endif