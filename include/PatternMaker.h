#pragma once
#include <opencv2/opencv.hpp>

class PatternMaker;
class Monitor
{
public:
    Monitor(float inch_size, int col_size, int row_size);
    float getPixSize();
    void printInfo();

    const float inches;
    const int rows;
    const int cols;
private:
    float pix_size;
    friend class PatternMaker;
};


class PatternMaker{
public:
    PatternMaker(Monitor monitor):monitor(monitor){};
    cv::Mat make_acircles_pattern(int rows, int cols, float spacing, float radius_rate);
    cv::Mat make_circles_pattern(int rows, int cols, float spacing, float radius_rate);
    cv::Mat make_checkerboard_pattern(int rows, int cols, float spacing);
    void blink(float fps);
    void show(std::string winName);
private:
    Monitor monitor;
    cv::Mat pattern;

};