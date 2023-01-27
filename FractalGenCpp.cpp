#include "pch.h"
#include "fractalGenCpp.h"
#include "ImageOutput.h"

using namespace std;

FractalGenCpp::FractalGenCpp(int width, int height, int maxIter, int numThreads) : WIDTH(width), HEIGHT(height), MAX_ITER(maxIter), NUM_THREADS(numThreads) {
    output = new ImageOutput(width, height, maxIter);
}
void FractalGenCpp::fractalGenerate(int id, int numThreads, vector<vector<int>>& image) {
    for (int i = id; i < WIDTH * HEIGHT; i += numThreads) {
        int x = i % WIDTH;
        int y = i / WIDTH;
        complex<double> point((x - WIDTH / 2) * 4.0 / WIDTH, (y - HEIGHT / 2) * 4.0 / WIDTH);
        complex<double> z(0, 0);
        int iterations = 0;
        while (abs(z) < 2 && iterations < MAX_ITER) {
            z = z * z + point;
            iterations++;
        }
        image[x][y] = iterations;
    }
}
void FractalGenCpp::threadManagement() {
    vector<vector<int>> image(WIDTH, vector<int>(HEIGHT));
    vector<thread> threads;
    for (int i = 0; i < NUM_THREADS; i++) {
        threads.push_back(thread(&FractalGenCpp::fractalGenerate, this, i, NUM_THREADS, ref(image)));
    }
    for (int i = 0; i < NUM_THREADS; i++) {
        threads[i].join();
    }
    output->print(image);
}
