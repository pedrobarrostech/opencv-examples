
#include <opencv2/highgui/highgui.hpp>
#include <opencv/cv.h>

#include <iostream>
using namespace std;

int main(void) {
	//cv::Mat M(2,2, CV_8UC3, cv::Scalar(0,0,255));
    //cout << "M = " << endl << " " << M << endl << endl;

    IplImage* img = cvLoadImage("image.jpg", 1);
    cv::Mat mtx(img); // convert IplImage* -> Mat
    cout << "MTXs = " << endl << " " << mtx << endl << endl;
}
