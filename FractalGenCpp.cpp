#include "pch.h"
#include "FractalGenCpp.h"
#include "ImageOutput.h"
#include "GenTimer.h"

using namespace std;

FractalGenCpp::FractalGenCpp(int width, int height, int maxIter, int numThreads) : WIDTH(width), HEIGHT(height), MAX_ITER(maxIter), NUM_THREADS(numThreads) {
    output = new ImageOutput(width, height, maxIter);
    timer = new GenTimer();
}

// P�tla for iteruje przez wszystkie piksele w obrazie.
// 'id' - oznacza numer w�tku, kt�ry wykonuje t� funkcj�
// 'numThreads' - oznacza liczb� w�tk�w, kt�re s� uruchomione r�wnolegle
// 'image' - to wektor dwuwymiarowy, kt�ry przechowuje wynikowy obraz fraktala

void FractalGenCpp::fractalGenerate(int id, int numThreads, vector<vector<int>>& image) {

    for (int i = id; i < WIDTH * HEIGHT; i += numThreads) {
        // 'x' i 'y' oznaczaj� po�o�enie piksela w obrazie
        int x = i % WIDTH;
        int y = i / WIDTH;
        // 'point' to sta�a liczba zespolona, kt�ra jest parametrem fraktala
        complex<double> point((x - WIDTH / 2) * 4.0 / WIDTH, (y - HEIGHT / 2) * 4.0 / WIDTH);
        // 'z' jest liczb� zespolon�, kt�ra jest iterowana w celu generowania fraktala
        complex<double> z(0, 0);
        int iterations = 0;
        // P�tla iteruje do momentu, gdy warto�� bezwzgl�dna liczby zespolonej 'z' jest mniejsza ni� 2 
        // lub liczba iteracji jest mniejsza ni� 'MAX_ITER'
        while (abs(z) < 2 && iterations < MAX_ITER) {
            // Mno�enie 'z' przez siebie i dodawanie 'point'
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
    // Uruchamianie wszystkich w�tk�w, kt�re wykonuj� funkcj� 'fractalGenerate'
    for (int i = 0; i < NUM_THREADS; i++) {
        threads.push_back(thread(&FractalGenCpp::fractalGenerate, this, i, NUM_THREADS, ref(image)));
    }
    // Czekanie na zako�czenie wszystkich w�tk�w
    for (int i = 0; i < NUM_THREADS; i++) {
        threads[i].join();
    }
    runTime = timer->timeSum(startTime, timer->timeStop());
    // Wywo�anie funkcji 'outputImage' obiektu 'output', kt�ra wy�wietla wynikowy obraz fraktala
    output->print(image);
}

float FractalGenCpp::returnRunTime() {
    return runTime;
}

