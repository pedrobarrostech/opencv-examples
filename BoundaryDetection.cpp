/*
 * BondaryDetection.cpp
 *
 *  Created on: Jun 24, 2014
 *      Author: pedroaugust8
 */

#include <opencv/cxcore.h>
#include <opencv2/highgui/highgui.hpp> //funções principais do OpenCV
#include <opencv/cv.h> //OpenCV Funções relativas a GUI

int main() {
	IplImage* newImg = NULL;
	IplImage* grayImg = NULL;
	IplImage* contourImg = NULL;
	//parâmetros para a detecção de contornos
	CvMemStorage * storage = cvCreateMemStorage(0);
	CvSeq * contour = 0;
	int mode = CV_RETR_EXTERNAL;

	mode = CV_RETR_CCOMP; //detecta tanto contornos internos quanto externos

	cvNamedWindow("src", 1);
	cvNamedWindow("contour", 1);

	//carregue a imagem original
	newImg = cvLoadImage("image.bmp", 1);

	//cria uma imagem de apenas um canal com 1 byte (i.e. imagem em nível de cinza)
	grayImg = cvCreateImage(cvSize(newImg->width, newImg->height),IPL_DEPTH_8U, 1);

	//converte a imagem colorida (3 canais em rgb) para imagem grayscale
	cvCvtColor(newImg, grayImg, CV_BGR2GRAY);
	cvShowImage("src", newImg); //exibe a imagem da maçã em preto e branco (bw)

	//faça uma cópia da imagem original para poder desenhar os contornos detectados
	contourImg = cvCreateImage(cvGetSize(newImg), IPL_DEPTH_8U, 3);
	contourImg = cvCloneImage(newImg);

	//encontre os contornos
	cvFindContours(grayImg, storage, &contour, sizeof(CvContour), mode,	CV_CHAIN_APPROX_SIMPLE, cvPoint(0, 0));
	//… e desenhe os contornos
	cvDrawContours(contourImg, contour, CV_RGB(0, 255, 0), CV_RGB(255, 0, 0), 2, 2, 8);
	cvShowImage("contour", contourImg); //exiba o resultado
	cvWaitKey(0);

	//não se esqueça de destruir as janelas e liberar a memória!
	cvDestroyWindow("src");
	cvDestroyWindow("contour");
	cvReleaseImage(&newImg);
	cvReleaseImage(&grayImg);
	cvReleaseImage(&contourImg);
	return 0;
}
