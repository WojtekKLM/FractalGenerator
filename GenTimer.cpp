#include "pch.h"
#include "GenTimer.h"

using namespace std;

GenTimer::GenTimer(){}

//Metoda zwracaj�ca czas z systemu w mom�cie rozpoczynania pracy funkcji  
float GenTimer::timeStart() {
    clock_t clockTime;
    clockTime = clock();
    return ((double)(clockTime) / CLOCKS_PER_SEC);
}

//Metoda zwracaj�ca czas z systemu w mom�cie ko�czenia pracy funkcji 
float GenTimer::timeStop() {
    clock_t clockTime;
    clockTime = clock();
    return ((double)(clockTime) / CLOCKS_PER_SEC);
};

//Metoda zwracaj�ca czas z systemu w mom�cie ko�czenia pracy funkcji 
float GenTimer::timeSum(float startTime, float stopTime) {
    return (stopTime - startTime);
}