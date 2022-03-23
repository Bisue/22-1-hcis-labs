#include <iostream>
#include <opencv2/opencv.hpp>
#include "Color.h"

using namespace cv;

int main()
{
	// input 이미지 로드 (./images 디렉토리에 원본 컬러 이미지들이 있다고 가정)
	Mat originJenny = imread("./images/jenny.jpg");
	// input 이미지 저장 (./outputs 디렉토리가 있다고 가정)
	imwrite("./outputs/1_1_input.png", originJenny);

	// =======================================================

	CColor cc;

	// 컬러 이미지를 각 3개 채널로 분리
	Mat channels[3]; // b, g, r
	cc.GS_splitRGB(originJenny, channels);

	// GS_splitRGB는 내부적으로 cv::split을 사용하고
	// cv::split은 BGR 순서로 반환됨
	Mat R = channels[2];
	Mat G = channels[1];
	Mat B = channels[0];

	// =======================================================

	// output 이미지 디스플레이
	imshow("R", R);
	imshow("G", G);
	imshow("B", B);
	// output 이미지 저장 (./output 디렉토리가 있다고 가정)
	imwrite("./outputs/1_1_output_1.png", R);
	imwrite("./outputs/1_1_output_2.png", G);
	imwrite("./outputs/1_1_output_3.png", B);

	waitKey();
}
