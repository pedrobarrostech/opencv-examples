/*
 * DilationErosion.cpp
 *
 *  Created on: Jun 24, 2014
 *      Author: pedroaugust8
 */

#include <opencv/cxcore.h>
#include <opencv2/highgui/highgui.hpp> //funções principais do OpenCV
#include <opencv/cv.h> //OpenCV Funções relativas a GUI

int main() {
	IplImage* newImg = NULL;
	IplImage* dilateImg = NULL;
	IplImage* erodeImg = NULL;

	cvNamedWindow("src", 1);
	cvNamedWindow("dilate", 1);
	cvNamedWindow("erode", 1);


	//carregue a imagem original
	newImg = cvLoadImage("image.bmp", 1);
	cvShowImage("src", newImg);

	//faça duas cópias da imagem original
	dilateImg = cvCloneImage(newImg);
	erodeImg = cvCloneImage(newImg);

	//dilate a imagem
	cvDilate(newImg, dilateImg, NULL, 4);

	//eroda a imagem
	cvErode(newImg, erodeImg, NULL, 4);

	//exiba os resultados
	cvShowImage("dilate", dilateImg);
	cvShowImage("erode", erodeImg);
	cvWaitKey(0);

	cvDestroyWindow("src");
	cvDestroyWindow("dilate");
	cvDestroyWindow("erode");
	cvReleaseImage(&newImg);
	cvReleaseImage(&dilateImg);
	cvReleaseImage(&erodeImg);
	return 0;
}
