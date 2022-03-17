#include <iostream>
#include <opencv2/opencv.hpp>
#include "Pixel.h"

using namespace cv;

// 문제 2-1
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

// 문제 2-1
void solve(const Mat& image)
{
	imwrite("./outputs/2_1_input.png", image);

	// 두 개의 이미지를 각각 컬러 이미지를 흑백 이미지로 변경
	Mat grayScaled;
	cvtColor(image, grayScaled, COLOR_BGR2GRAY);

	// 흑백 이미지 출력
	imshow("Gray Scaled Image", grayScaled);

	imwrite("./outputs/2_1_output.png", grayScaled);

	waitKey();
}