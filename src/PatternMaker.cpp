#include "PatternMaker.h"
#include <iostream>
#include <cmath>

using namespace std;
using namespace cv;

Monitor::Monitor(float inch_size, int col_size, int row_size)
:inches(inch_size), cols(col_size), rows(row_size)
{
    float diag_len = inch_size * 25.4;
    pix_size = diag_len / sqrt(row_size*row_size+col_size*col_size);
}

void Monitor::printInfo(){
    cout<<"Monitor size: "<<inches<<" inches"<<endl;
    cout<<"Monitor resolution: "<<cols<<" x "<<rows<<endl;
    cout<<"Monitor size: "<<pix_size*cols/10<<" cm x "<<pix_size*rows/10<<" cm"<<endl;
    cout<<"Pixel size: "<<pix_size<<" mm"<<endl;
}

float Monitor::getPixSize(){
    return pix_size;
}

Mat PatternMaker::make_circles_pattern(int rows, int cols, float spacing, float radius_rate){
    int radius = floor(spacing/radius_rate/monitor.pix_size);
    int rowMargin = floor(spacing/2/monitor.pix_size);
    int colMargin = rowMargin;
    int imgRows = 2*rowMargin + spacing*rows/monitor.pix_size;
    int imgCols = 2*colMargin + spacing*cols/monitor.pix_size;
    this->pattern = Mat(imgRows,imgCols,CV_8UC1, Scalar(255));
    for (int row=0;row<rows;row++){
        for (int col=0;col<cols;col++){
            Point p;
            p.x = colMargin+floor((0.5+col)*spacing/monitor.pix_size);
            p.y = rowMargin+floor((0.5+row)*spacing/monitor.pix_size);
            circle(this->pattern, p, radius, Scalar(0), -1);
        }
    }
    return this->pattern;
}

Mat PatternMaker::make_acircles_pattern(int rows, int cols, float spacing, float radius_rate){
    int radius = floor(spacing/radius_rate/monitor.pix_size);
    int rowMargin = floor(spacing/2/monitor.pix_size);
    int colMargin = rowMargin;
    int imgRows = 2*rowMargin + spacing*rows/monitor.pix_size;
    int imgCols = 2*colMargin + 2*spacing*cols/monitor.pix_size;
    this->pattern = Mat(imgRows,imgCols,CV_8UC1, Scalar(255));
    for (int row=0;row<rows;row++){
        for (int col=0;col<cols;col++){
            Point p;
            p.x = colMargin+floor((0.5+col*2+row%2)*spacing/monitor.pix_size);
            p.y = rowMargin+floor((0.5+row)*spacing/monitor.pix_size);
            circle(this->pattern, p, radius, Scalar(0), -1);
        }
    }
    return this->pattern;
}

Mat PatternMaker::make_checkerboard_pattern(int rows, int cols, float spacing)
{
    int rowMargin = floor(spacing/2/monitor.pix_size);
    int colMargin = rowMargin;
    int imgRows = 2*rowMargin + spacing*rows/monitor.pix_size;
    int imgCols = 2*colMargin + spacing*cols/monitor.pix_size;
    this->pattern = Mat(imgRows,imgCols,CV_8UC1, Scalar(255));
    float pixSize = monitor.pix_size;
    int spacingPix = floor(spacing/pixSize);
    for (int row=0;row<rows;row++){
        for (int col=0;col<cols;col++){
            if(row%2==col%2){
                Rect area(colMargin+round(col*spacing/pixSize), 
                rowMargin+round(row*spacing/pixSize), spacingPix, spacingPix);
                rectangle(this->pattern, area, Scalar(0), -1);
            }
        }
    }
    return this->pattern;
}

void PatternMaker::blink(float fps){
    if(pattern.empty()){
        cout<<"Please make pattern first!"<<endl;
        return;
    }
    Mat blank = Mat(pattern.size(), CV_8UC1, Scalar(255));
    while(waitKey(1000/fps)!=27){
        imshow("pattern", pattern);
        if(waitKey(1000/fps)==27)
            break;
        imshow("pattern", blank);
    }
}

void PatternMaker::show(string winName){
    if(pattern.empty()){
        cout<<"Please make pattern first!"<<endl;
        return;
    }
    imshow(winName, pattern);
    waitKey(0);
}