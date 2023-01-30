#include "pch.h"
#include "GenTimer.h"

using namespace std;

GenTimer::GenTimer(){}

//Metoda zwracaj¹ca czas z systemu w momêcie rozpoczynania pracy funkcji  
float GenTimer::timeStart() {
    clock_t clockTime;
    clockTime = clock();
    return ((double)(clockTime) / CLOCKS_PER_SEC);
}

//Metoda zwracaj¹ca czas z systemu w momêcie koñczenia pracy funkcji 
float GenTimer::timeStop() {
    clock_t clockTime;
    clockTime = clock();
    return ((double)(clockTime) / CLOCKS_PER_SEC);
};

//Metoda zwracaj¹ca czas z systemu w momêcie koñczenia pracy funkcji 
float GenTimer::timeSum(float startTime, float stopTime) {
    return (stopTime - startTime);
}