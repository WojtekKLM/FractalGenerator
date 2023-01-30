#pragma once
#ifndef GEN_TIMER_H
#define GEN_TIMER_H

#include <iostream>
#include <time.h>
#include <chrono>
#include <iomanip>

class GenTimer {
private:

public:
    GenTimer();
    float timeStart();
    float timeStop();
    float timeSum(float startTime, float stopTime);
    float returnRunTime();
};

#endif