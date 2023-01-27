#pragma once
//#ifndef DATACONTROLLER_H
//#define DATACONTROLLER_H

#include <iostream>
#include <string>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <stdio.h>
#include <windows.h>
#include "pch.h"


using namespace std;

class DataController {
private:
	int width, height, maxIter, numThreads;
public:
	DataController();
	int getWidth();
	int getHeight();
	int getMaxIter();
	int getNumThreads();
	void setWidth(int w);
	void setHeight(int h);
	void setMaxIter(int m);
	void setNumThreads(int n);
};