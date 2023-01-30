#pragma once
//#ifndef DATACONTROLLER_H
//#define DATACONTROLLER_H

#include <vector>
#include "pch.h"

using namespace std;

ref class DataController {
private:
    float data1, data2, data3, data4, data5;
    int index;
    bool isFull;
    float dataAsm1, dataAsm2, dataAsm3, dataAsm4, dataAsm5;
    int indexAsm;
    bool isFullAsm;
public:
    DataController();
    void addData(float value);
    float getAverage();
    bool isDataFull();
    void addDataAsm(float value);
    float getAverageAsm();
    bool isDataFullAsm();
};
