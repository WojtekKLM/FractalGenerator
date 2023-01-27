#include "pch.h"
#include "DataController.h"

using namespace std;

	DataController::DataController() {}

	int DataController::getWidth() {
		return width;
	}
	int DataController::getHeight() {
		return height;
	}
	int DataController::getMaxIter() {
		return maxIter;
	}
	int DataController::getNumThreads() {
		return numThreads;
	}
	void DataController::setWidth(int w) {
		width = w;
	}
	void DataController::setHeight(int h) {
		height = h;
	}
	void DataController::setMaxIter(int m) {
		maxIter = m;
	}
	void DataController::setNumThreads(int n) {
		numThreads = n;
	}