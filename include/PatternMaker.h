#pragma once
#include <opencv2/opencv.hpp>

class PatternMaker;
class Monitor
{
public:
    Monitor(int inch_size, int col_size, int row_size);
    float getPixSize();
    void printInfo();

    const int inches;
    const int rows;
    const int cols;
private:
    float pix_size;
    friend class PatternMaker;
};


class PatternMaker{
public:
    PatternMaker(Monitor monitor):monitor(monitor){};

private:
    Monitor monitor;
    cv::Mat pattern;

};