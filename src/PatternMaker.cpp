#include "PatternMaker.h"
#include <iostream>
#include <cmath>

using namespace std;
using namespace cv;

Monitor::Monitor(int inch_size, int col_size, int row_size)
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