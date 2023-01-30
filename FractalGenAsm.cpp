#include "pch.h"
#include "FractalGenAsm.h"
#include "ImageOutput.h"
#include "GenTimer.h"

using namespace std;

FractalGenAsm::FractalGenAsm(int width, int height, int maxIter, int numThreads) : WIDTH(width), HEIGHT(height), MAX_ITER(maxIter), NUM_THREADS(numThreads) {
    output = new ImageOutput(width, height, maxIter);
    timer = new GenTimer();
}
void FractalGenAsm::fractalGenerate(int id, int numThreads, vector<vector<int>>& image) {
    for (int i = id; i < WIDTH * HEIGHT; i += numThreads) {
        int x = i % WIDTH;
        int y = i / WIDTH;
        complex<double> point = mandelbrot_calculation(x, WIDTH, y, HEIGHT);

        complex<double> z(0, 0);
        int iterations = 0;
        while (abs(z) < 2 && iterations < MAX_ITER) {
            z = z * z + point;
            iterations++;
        }
        image[x][y] = iterations;
    }
}
void FractalGenAsm::threadManagement() {
    vector<vector<int>> image(WIDTH, vector<int>(HEIGHT));
    vector<thread> threads;
    startTime = timer->timeStart();
    for (int i = 0; i < NUM_THREADS; i++) {
        threads.push_back(thread(&FractalGenAsm::fractalGenerate, this, i, NUM_THREADS, ref(image)));
    }
    for (int i = 0; i < NUM_THREADS; i++) {
        threads[i].join();
    }
    runTime = timer->timeSum(startTime, timer->timeStop());
    output->print(image);
}

float FractalGenAsm::returnRunTime() {
    return runTime;
}
