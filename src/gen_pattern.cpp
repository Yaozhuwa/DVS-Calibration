#include "PatternMaker.h"
#include <iostream>

using namespace std;
using namespace cv;


int main(){
    Monitor monitor(15.6, 1920, 1080);
    monitor.printInfo();
    PatternMaker pmaker(monitor);
    // Mat pattern = pmaker.make_acircles_pattern(7, 5, 20, 2);
    Mat pattern = pmaker.make_acircles_pattern(7, 5, 20, 2.2);
    // imshow("pattern",pattern);
    // pmaker.blink(10);
    pmaker.show("pattern");
    // waitKey(0);
    return 0;
}