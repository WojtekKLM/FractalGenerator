#include "pch.h"
#include "FractalGenCpp.h"
#include "ImageOutput.h"
#include "GenTimer.h"

using namespace std;

FractalGenCpp::FractalGenCpp(int width, int height, int maxIter, int numThreads) : WIDTH(width), HEIGHT(height), MAX_ITER(maxIter), NUM_THREADS(numThreads) {
    output = new ImageOutput(width, height, maxIter);
    timer = new GenTimer();
}

// Pêtla for iteruje przez wszystkie piksele w obrazie.
// 'id' - oznacza numer w¹tku, który wykonuje t¹ funkcjê
// 'numThreads' - oznacza liczbê w¹tków, które s¹ uruchomione równolegle
// 'image' - to wektor dwuwymiarowy, który przechowuje wynikowy obraz fraktala

void FractalGenCpp::fractalGenerate(int id, int numThreads, vector<vector<int>>& image) {

    for (int i = id; i < WIDTH * HEIGHT; i += numThreads) {
        // 'x' i 'y' oznaczaj¹ po³o¿enie piksela w obrazie
        int x = i % WIDTH;
        int y = i / WIDTH;
        // 'point' to sta³a liczba zespolona, która jest parametrem fraktala
        complex<double> point((x - WIDTH / 2) * 4.0 / WIDTH, (y - HEIGHT / 2) * 4.0 / WIDTH);
        // 'z' jest liczb¹ zespolon¹, która jest iterowana w celu generowania fraktala
        complex<double> z(0, 0);
        int iterations = 0;
        // Pêtla iteruje do momentu, gdy wartoœæ bezwzglêdna liczby zespolonej 'z' jest mniejsza ni¿ 2 
        // lub liczba iteracji jest mniejsza ni¿ 'MAX_ITER'
        while (abs(z) < 2 && iterations < MAX_ITER) {
            // Mno¿enie 'z' przez siebie i dodawanie 'point'
            z = z * z + point;
            iterations++;
        }
        // Przypisanie liczby iteracji do odpowiedniego piksela w obrazie
        image[x][y] = iterations;
    }
}

void FractalGenCpp::threadManagement() {
    vector<vector<int>> image(WIDTH, vector<int>(HEIGHT));
    vector<thread> threads;
    startTime = timer->timeStart();
    // Uruchamianie wszystkich w¹tków, które wykonuj¹ funkcjê 'fractalGenerate'
    for (int i = 0; i < NUM_THREADS; i++) {
        threads.push_back(thread(&FractalGenCpp::fractalGenerate, this, i, NUM_THREADS, ref(image)));
    }
    // Czekanie na zakoñczenie wszystkich w¹tków
    for (int i = 0; i < NUM_THREADS; i++) {
        threads[i].join();
    }
    runTime = timer->timeSum(startTime, timer->timeStop());
    // Wywo³anie funkcji 'outputImage' obiektu 'output', która wyœwietla wynikowy obraz fraktala
    output->print(image);
}

float FractalGenCpp::returnRunTime() {
    return runTime;
}

