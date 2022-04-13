#include <iostream>
#include <opencv2/opencv.hpp>
#include "Pixel.h"

using namespace cv;

int main()
{
	// 입력 이미지 로드
	Mat grayStuff = imread("./outputs/1_1_input_1.png", 0);
	Mat erosionStuff = imread("./outputs/1_1_output_1.png", 0);
	Mat grayRice = imread("./outputs/1_1_input_2.png", 0);
	Mat erosionRice = imread("./outputs/1_1_output_2.png", 0);
	// 입력 이미지 파일로 저장
	// (프로젝트폴더/outputs 폴더가 이미 있다고 가정)
	imwrite("./outputs/1_3_input_1_1.png", grayStuff);
	imwrite("./outputs/1_3_input_1_2.png", erosionStuff);
	imwrite("./outputs/1_3_input_2_1.png", grayRice);
	imwrite("./outputs/1_3_input_2_2.png", erosionRice);

	// =======================================================

	CPixel cp;

	// 3. 원본(gray-scaled) 이미지에서 dilation of erosion 이미지를 뺌
	Mat subtractStuff = cp.GS_subtract_image(grayStuff, erosionStuff);
	Mat subtractRice = cp.GS_subtract_image(grayRice, erosionRice);

	// =======================================================

	// 출력 이미지 확인
	imshow("subtraction stuff", subtractStuff);
	imshow("subtraction rice", subtractRice);
	// 출력 이미지 파일로 저장
	// (프로젝트폴더/outputs 폴더가 이미 있다고 가정)
	imwrite("./outputs/1_3_output_1.png", subtractStuff);
	imwrite("./outputs/1_3_output_2.png", subtractRice);

	waitKey();
}
