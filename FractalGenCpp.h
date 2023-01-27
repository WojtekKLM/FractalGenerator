#pragma once
#ifndef MANDELBROT_GENERATOR_H
#define MANDELBROT_GENERATOR_H

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

class FractalGenCpp {
private:
    int WIDTH;
    int HEIGHT;
    int MAX_ITER;
    int NUM_THREADS;

public:
    FractalGenCpp(int width, int height, int maxIter, int numThreads);
    void threadManagement();
    void fractalGenerate(int id, int numThreads, std::vector<std::vector<int>>& image);
};

#endif

