#include <iostream>
#include <opencv2/opencv.hpp>
#include "Pixel.h"

using namespace cv;

// 문제 1-1
void solve(const Mat&, const Mat&);

// 모든 함수에서 편하게 쓰도록 전역 CPixel 인스턴스 선언
CPixel cpixel;

int main()
{
	// 연산 대상 이미지 로드
	// (이미지들은 <프로젝트경로/images/> 에 들어있는 것으로 가정)
	Mat image1 = imread("./images/lenna.png");
	Mat image2 = imread("./images/stuff_color_1.png");

	// cpixel 인스턴스 생성
	cpixel = CPixel();

	// 문제별 함수 분리
	solve(image1, image2);
}

// 문제 1-1
void solve(const Mat& image1, const Mat& image2)
{
	// 두 개의 이미지를 각각 컬러 이미지를 흑백 이미지로 변경
	Mat grayScaled1;
	cvtColor(image1, grayScaled1, COLOR_BGR2GRAY);
	Mat grayScaled2;
	cvtColor(image2, grayScaled2, COLOR_BGR2GRAY);

	imwrite("./outputs/1_1_input_1.png", grayScaled1);
	imwrite("./outputs/1_1_input_2.png", grayScaled2);

	// 각각의 흑백 이미지에 대해서 histogram 생성
	Mat hist1 = cpixel.GS_imhist(grayScaled1);
	imshow("Histogram 1", hist1);
	Mat hist2 = cpixel.GS_imhist(grayScaled2);
	imshow("Histogram 2", hist2);

	imwrite("./outputs/1_1_output_1.png", grayScaled1);
	imwrite("./outputs/1_1_output_2.png", grayScaled2);

	waitKey();
}
