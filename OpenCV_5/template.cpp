#include <iostream>
#include <opencv2/opencv.hpp>
#include "ImageAnalysis.h"

using namespace cv;

int main()
{
	// Template 이미지로 사용될 버즈프로 이미지
	Mat templateImage = imread("template.png");

	VideoCapture video = VideoCapture(0); // 웹캠(0)에서 이미지를 가져오기 위한 cv:VideoCapture
	
	CImageAnalysis ca; // templateMatching 헬퍼 함수가 있는 클래스
	Mat img, result; // img: 웹캠 이미지 1프레임, result: templateMatching 결과 이미지

	while (true) {
		// 노트북 내장 웹캠(0)으로부터 이미지 캡쳐
		video >> img;

		// CImageAnalysis 클래스를 사용하여 Template Matching
		result = ca.GS_templateMatching(img, templateImage);

		// 현재 프레임의 Template Matching 결과 미리보기
		imshow("matched", result);

		// Enter 누르면 while 문을 빠져나감 (현재 프레임을 Capture)
		if (waitKey(1) == 13)
			break;
	}

	// Template로 사용된 이미지 출력
	imshow("input template", templateImage);
	imwrite("input_template.png", templateImage);

	// Source Image로 사용된 웹캠 캡쳐 이미지 출력
	imshow("input image", img);
	imwrite("input_image.png", img);

	// Template Matching의 결과 이미지 출력
	imshow("output result", result);
	imwrite("output_result.png", result);

	waitKey();
}
