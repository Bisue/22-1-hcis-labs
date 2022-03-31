#include <iostream>
#include <opencv2/opencv.hpp>
#include "Pixel.h"

using namespace cv;

int main()
{
	// 입력 이미지 로드
	// (컬러 이미지)
	Mat imageA = imread("./outputs/2_2_output.png");
	Mat imageB = imread("./outputs/2_4_output.png");
	// 입력 이미지 파일로 저장
	// (프로젝트폴더/outputs 폴더가 이미 있다고 가정)
	imwrite("./outputs/2_5_input_1.png", imageA);
	imwrite("./outputs/2_5_input_2.png", imageB);

	// =======================================================

	CPixel cp;

	// 이미지 A(Scaled of rotated) 에서 이미지 B(Rotated of scaled) 를 뺌
	Mat subtracted = cp.GS_subtract_image(imageA, imageB);

	// =======================================================

	// 출력 이미지 확인
	imshow("Subtract Result Briefcase", subtracted);
	// 출력 이미지 파일로 저장
	// (프로젝트폴더/outputs 폴더가 이미 있다고 가정)
	imwrite("./outputs/2_5_output.png", subtracted);

	waitKey();
}
