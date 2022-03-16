#include <iostream>
#include <opencv2/opencv.hpp>
#include "Pixel.h"

using namespace cv;

// 모든 함수에서 편하게 쓰도록 전역 CPixel 인스턴스 선언
CPixel cpixel;

int main()
{
	// 연산 대상 이미지 로드
	// (이미지들은 <프로젝트경로/images/> 에 들어있는 것으로 가정)
	Mat image1 = imread("./images/stuff_color_1.png");
	Mat image2 = imread("./images/stuff_color_2.png");

	// cpixel 인스턴스 생성
	cpixel = CPixel();

	// 문제별 함수 분리
	//solve1_addition(image1, image2);
}