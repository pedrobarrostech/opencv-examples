/*
 * FloodFill.cpp
 *
 *  Created on: Jun 24, 2014
 *      Author: pedroaugust8
 */

#include <opencv/cxcore.h>
#include <opencv2/highgui/highgui.hpp> //funções principais do OpenCV
#include <opencv/cv.h> //OpenCV Funções relativas a GUI

int main() {
	IplImage* newImg = NULL;
	IplImage* ffImg = NULL;

	//Parametros para o preenchimento e inundação
	int lo_diff, up_diff; //ajuste dos limites inferior e superior
	CvConnectedComp comp;
	CvPoint floodSeed; //pixel de origem para o preenchimento
	CvScalar floodColor;
	lo_diff = 8;
	up_diff = 8;
	floodColor = CV_RGB(255, 0, 0); //preenchimento será vermelho

	cvNamedWindow("src", 1);
	cvNamedWindow("flood&fill", 1);

	//carrega a imagem original
	newImg = cvLoadImage( "image.bmp" , 1 );
	cvShowImage( "src", newImg );

	//faz uma cópia da imagem original
	ffImg = cvCloneImage(newImg);
	floodSeed = cvPoint(60, 60); //preenchimento iniciando no pixel(60, 60)

	//Preencher e inundar a partir do pixel(60, 60) com cor vermelha e intervalo de preenchimento de (-8, +8)
	cvFloodFill( ffImg, floodSeed, floodColor, CV_RGB( lo_diff, lo_diff, lo_diff ), CV_RGB( up_diff, up_diff, up_diff ), &comp, 8, NULL);
	cvShowImage("flood&fill", ffImg);


	cvWaitKey(0);
	cvDestroyWindow("src");
	cvDestroyWindow("flood&fill");
	cvReleaseImage(&newImg);
	cvReleaseImage(&ffImg);
	return 0;
}
