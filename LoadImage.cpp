/*
 * LoadImage.cpp
 *
 *  Created on: Jun 24, 2014
 *      Author: pedroaugust8
 */


#include <opencv2/highgui/highgui.hpp> //funções principais do OpenCV
#include <opencv/cv.h> //OpenCV Funções relativas a GUI
#include <stdio.h>
int main() {
	/* Declare um novo ponteiro do tipo IplImage. */
	/* Essa é a estrutura básica para imagens no OpenCV */
	IplImage* newImg;
	/* carrege a imagem "apple.bmp“ */
	/* O parâmetro 1 significa que a imagem é colorida */
	newImg = cvLoadImage("image.jpg", 1);
	//crie uma nova janela
	cvNamedWindow("Window", 1);
	//exiba a imagem na janela
	cvShowImage("Window", newImg);
	//aguarde uma tecla qualquer para fechar a janela
	cvWaitKey(0);
	cvDestroyWindow("Window"); //destrua a janela
	cvReleaseImage(&newImg); //libere a memória relativa a imagem
	return 0;
}
