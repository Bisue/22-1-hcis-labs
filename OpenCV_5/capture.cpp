#include <iostream>
#include <opencv2/opencv.hpp>
#include "ImageAnalysis.h"

using namespace cv;

int main()
{
	VideoCapture video = VideoCapture(0); // 웹캠(0)에서 이미지를 가져오기 위한 cv:VideoCapture

	Mat img; // 웹캠 이미지 1프레임을 저장할 Mat

	while (true) {
		// 노트북 내장 웹캠(0)으로부터 이미지 캡쳐
		video >> img;

		// 현재 웹캠에서 가져온 프레임 미리보기
		imshow("Img", img);

		// Enter 키를 누르면 while 빠져나가기
		if (waitKey(1) == 13)
			break;
	}

	// Enter 키를 누른 해당 프레임을 출력
	imshow("capture", img);
	imwrite("capture.png", img);

	waitKey();
}
