/*
 * Canny.cpp
 *
 *  Created on: Jun 24, 2014
 *      Author: pedroaugust8
 */

#include <opencv2/highgui/highgui.hpp> //funções principais do OpenCV
#include <opencv/cv.h> //OpenCV Funções relativas a GUI

int main() {
	IplImage* newImg; //imagem original
	IplImage* grayImg; //imagem em nível de cinza para conversão
	IplImage* cannyImg; //imagem em nível de cinza para detecção das bordas

	//carregando a imagem original
	newImg = cvLoadImage("image3.png", 1);
	//criando uma imagem de um canal (i.e. imagem de nível de cinza)
	grayImg = cvCreateImage(cvSize(newImg->width, newImg->height), IPL_DEPTH_8U, 1);


	//convertendo a imagem colorida (3 canais rgb) para a imagem em nível de cinza
	cvCvtColor(newImg, grayImg, CV_BGR2GRAY);
	cannyImg = cvCreateImage(cvGetSize(newImg), IPL_DEPTH_8U, 1);

	// Detecção de borda Canny
	cvCanny(grayImg, cannyImg, 50, 150, 3);
	cvNamedWindow("src", 1);
	cvShowImage("src", newImg);
	cvNamedWindow("canny", 1);
	cvShowImage("canny", cannyImg);
	cvWaitKey(0);

	//não se esqueça de destruir as janelas e liberar a memória!
	cvDestroyWindow("src");
	cvDestroyWindow("canny");
	cvReleaseImage(&newImg);
	cvReleaseImage(&grayImg);
	cvReleaseImage(&cannyImg);


	return 0;
}
