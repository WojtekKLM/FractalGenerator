#include "pch.h"
#include "DataController.h"

using namespace std;

DataController::DataController() {
    index = 0;
    data1 = 0;
    data2 = 0;
    data3 = 0;
    data4 = 0;
    data5 = 0;
    indexAsm = 0;
    dataAsm1 = 0;
    dataAsm2 = 0;
    dataAsm3 = 0;
    dataAsm4 = 0;
    dataAsm5 = 0;
}

void DataController::addData(float value) {
    switch (index)
    {
    case 0:
        data5 = value;
        break;
    case 1:
        data4 = value;
        break;
    case 2:
        data3 = value;
        break;
    case 3:
        data2 = value;
        break;
    case 4:
        data1 = value;
        break;
    }
    index = (index + 1) % 5;
    if (index == 0) {
        isFull = true;
    }
}

float DataController::getAverage() {
    return (data1 + data2 + data3 + data4 + data5) / 5;
}

bool DataController::isDataFull() {
    return isFull;
}

void DataController::addDataAsm(float valueAsm) {
    switch (indexAsm)
    {
    case 0:
        dataAsm5 = valueAsm;
        break;
    case 1:
        dataAsm4 = valueAsm;
        break;
    case 2:
        dataAsm3 = valueAsm;
        break;
    case 3:
        dataAsm2 = valueAsm;
        break;
    case 4:
        dataAsm1 = valueAsm;
        break;
    }
    indexAsm = (indexAsm + 1) % 5;
    if (indexAsm == 0) {
        isFullAsm = true;
    }
}

float DataController::getAverageAsm() {
    return (dataAsm1 + dataAsm2 + dataAsm3 + dataAsm4 + dataAsm5) / 5;
}

bool DataController::isDataFullAsm() {
    return isFullAsm;
}