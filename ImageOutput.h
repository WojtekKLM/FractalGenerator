#pragma once
#ifndef IMAGEOUTPUT_H
#define IMAGEOUTPUT_H

#include <vector>
#include <complex>
#include <iostream>
#include <fstream>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <stdio.h>
#include <windows.h>
#include "pch.h"

#include <string>
#include <bitset>
#include <direct.h>
#include <msclr\marshal_cppstd.h>

using namespace std;

class ImageOutput {
private:
    int WIDTH;
    int HEIGHT;
    int MAX_ITER;
public:
    ImageOutput(int width, int height, int maxIter);
    void print(const std::vector<std::vector<int>>& image);
};

#endif

