#include <iostream>
#include <opencv2/opencv.hpp>
#include "Pixel.h"

using namespace cv;

// 문제 2-3
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

// 문제 2-3
void solve(const Mat& image)
{
	// 두 개의 이미지를 각각 컬러 이미지를 흑백 이미지로 변경
	Mat grayScaled;
	cvtColor(image, grayScaled, COLOR_BGR2GRAY);

	imwrite("./outputs/2_3_input.png", grayScaled);

	// GS_threshold 메서드를 이용하여 임계값에 대해 OTSU 방식으로 이미지 이진화
	Mat binaryImage = cpixel.GS_threshold(grayScaled, 0, THRESH_BINARY | THRESH_OTSU);
	imshow("Binary Image", binaryImage);

	imwrite("./outputs/2_3_output.png", binaryImage);

	waitKey();
}
