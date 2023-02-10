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

extern "C" void mandelbrot_calculation(int* tablica, double* tablicaRes);

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
    double** tablicaRes = new double* [NUM_THREADS];

public:
    FractalGenAsm(int width, int height, int maxIter, int numThreads);
    void threadManagement();
    void fractalGenerate(int id, int numThreads, std::vector<std::vector<int>>& image);
    float returnRunTime();
};

#endif