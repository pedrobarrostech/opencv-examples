/*
 * Threshold.cpp
 *
 *  Created on: Jun 24, 2014
 *      Author: pedroaugust8
 */
#include "math.h"
#include <opencv2/highgui/highgui.hpp> //funções principais do OpenCV
#include <opencv/cv.h> //OpenCV Funções relativas a GUI


int main() {
	IplImage* src;
	IplImage* colorThresh;
	IplImage* gray;
	IplImage* grayThresh;
	int threshold = 120, maxValue = 255;
	int thresholdType = CV_THRESH_BINARY;

	src = cvLoadImage("image.bmp", 1);
	colorThresh = cvCloneImage(src);

	gray = cvCreateImage(cvSize(src->width, src->height), IPL_DEPTH_8U, 1);
	cvCvtColor(src, gray, CV_BGR2GRAY);
	grayThresh = cvCloneImage(gray);

	cvNamedWindow("src", 1);
	cvShowImage("src", src);

	cvThreshold(src, colorThresh, threshold, maxValue, thresholdType);
	cvNamedWindow("colorThresh", 1);
	cvShowImage("colorThresh", colorThresh);

	cvNamedWindow("gray", 1);
	cvShowImage("gray", gray);

	cvThreshold(gray, grayThresh, threshold, maxValue, thresholdType);
	cvNamedWindow("grayThresh", 1);
	cvShowImage("grayThresh", grayThresh);

	cvWaitKey(0);
	cvDestroyWindow("src");
	cvDestroyWindow("colorThresh");
	cvDestroyWindow("gray");
	cvDestroyWindow("grayThresh");
	cvReleaseImage(&src);
	cvReleaseImage(&colorThresh);
	cvReleaseImage(&gray);
	cvReleaseImage(&grayThresh);

	return 0;
}

