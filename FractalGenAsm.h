#pragma once
#ifndef FRACTAL_GEN_ASM_H
#define FRACTAL_GEN_ASM_H

#include <thread>
#include <vector>
#include <complex>
#include <iostream>
#include <thread>
#include <vector>
#include <complex>
#include <iostream>
#include <fstream>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <windows.h>
#include "ImageOutput.h"
#include "GenTimer.h"

extern "C" double mandelbrot_calculation(int x, int width, int y, int height);

class FractalGenAsm {
private:
    int WIDTH;
    int HEIGHT;
    int MAX_ITER;
    int NUM_THREADS;
    float runTime;
    float startTime;
    ImageOutput* output;
    GenTimer* timer;

public:
    FractalGenAsm(int width, int height, int maxIter, int numThreads);
    void threadManagement();
    void fractalGenerate(int id, int numThreads, std::vector<std::vector<int>>& image);
    float returnRunTime();
};

#endif