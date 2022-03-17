#include <iostream>
#include <opencv2/opencv.hpp>
#include "Pixel.h"

using namespace cv;

// 문제 2-4
void solve(const Mat&);

// 모든 함수에서 편하게 쓰도록 전역 CPixel 인스턴스 선언
CPixel cpixel;

int main()
{
	// 연산 대상 이미지 로드
	// (이미지들은 <프로젝트경로/images/> 에 들어있는 것으로 가정)
	Mat image1 = imread("./images/lenna.png");

	// cpixel 인스턴스 생성
	cpixel = CPixel();

	// 문제별 함수 분리
	solve(image1);
}

// 문제 2-4
void solve(const Mat& image)
{
	// 두 개의 이미지를 각각 컬러 이미지를 흑백 이미지로 변경
	Mat grayScaled;
	cvtColor(image, grayScaled, COLOR_BGR2GRAY);

	imwrite("./outputs/2_4_input.png", grayScaled);

	// GS_adaptive_threshold 메서드를 이용해 MEAN 방식으로 이미지를 지역적으로 반복하여 이진화
	Mat binaryImage = cpixel.GS_adaptive_threshold(grayScaled, 150, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY);
	imshow("Binary Image", binaryImage);

	imwrite("./outputs/2_4_output.png", binaryImage);

	waitKey();
}
