#include "pch.h"
#include "ImageOutput.h"

using namespace std;

    ImageOutput::ImageOutput(int width, int height, int maxIter) : WIDTH(width), HEIGHT(height), MAX_ITER(maxIter) {}

    void ImageOutput::print(const std::vector<std::vector<int>>& image) {
        std::ofstream out("output.ppm");
        out << "P3" << std::endl;
        out << WIDTH << " " << HEIGHT << std::endl;
        out << "255" << std::endl;
        for (int y = 0; y < HEIGHT; y++) {
            for (int x = 0; x < WIDTH; x++) {
                int iterations = image[x][y];
                int color = 255 - (int)(255 * iterations / (double)MAX_ITER);
                out << color << " " << color << " " << color << " ";
            }
            out << std::endl;
        }
        out.close();
    }