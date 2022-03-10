#include <iostream>
#include <opencv2/opencv.hpp>
#include "Pixel.h"
#include <time.h>

using namespace cv;

// 실습 1-1, 1-2
void solve1_addition(const Mat&, const Mat&);
// 실습 2-1, 2-2
void solve2_subtraction(const Mat&, const Mat&);
// 실습 3-1, 3-2
void solve3_blending(const Mat&, const Mat&, const double&);
// 실습 4-1, 4-2
void solve4_adjustment(const Mat&, const double&, const int&);
// 테스트
void test1_fade_animation(const Mat&, const Mat&, const int&);

// 모든 함수에서 편하게 쓰도록 전역 CPixel 인스턴스 선언
CPixel cpixel;

int main()
{
	// 연산 대상 이미지 로드
	// (이미지들은 <프로젝트경로/images/> 에 들어있는 것으로 가정)
	Mat image1 = imread("./images/stuff_color_1.png");
	//Mat image2 = imread("./images/stuff_color_2.png");
	//Mat image1 = imread("./images/lenna.png");
	//Mat image2 = imread("./images/orange.jpg");

	// cpixel 인스턴스 생성
	cpixel = CPixel();

	// 문제별 함수 분리
	//solve1_addition(image1, image2);
	//solve2_subtraction(image1, image2);
	//solve3_blending(image1, image2, 0.66);
	solve4_adjustment(image1, 1.5, 30);
	
	// fade-out-in 애니메이션
	//test1_fade_animation(image1, image2, 3000);
}

// 실습 1-1, 1-2
void solve1_addition(const Mat& image1, const Mat& image2)
{
	// 두 이미지 모두 올바른 이미지인지 확인
	if (image1.empty() || image2.empty()) {
		std::cout << "Image load failed!" << std::endl;
		return;
	}

	// CPixel 클래스를 이용한 이미지 add
	Mat result = cpixel.GS_add_image(image1, image2);

	// 결과 이미지 출력
	imshow("Output Image", result);

	waitKey();
}

void solve2_subtraction(const Mat& image1, const Mat& image2)
{
	// 두 이미지 모두 올바른 이미지인지 확인
	if (image1.empty() || image2.empty()) {
		std::cout << "Image load failed!" << std::endl;
		return;
	}

	// CPixel 클래스를 이용한 이미지 sub
	Mat result = cpixel.GS_subtract_image(image1, image2);

	// 결과 이미지 출력
	imshow("Output Image", result);

	waitKey();
}

void solve3_blending(const Mat& image1, const Mat& image2, const double& alpha)
{
	// 두 이미지 모두 올바른 이미지인지 확인
	if (image1.empty() || image2.empty()) {
		std::cout << "Image load failed!" << std::endl;
		return;
	}

	// CPixel 클래스를 이용한 이미지 blending
	// (alpha 값은 image1의 weight임)
	Mat result = cpixel.GS_blending_effect(image1, image2, alpha);

	// 결과 이미지 출력
	imshow("Output Image", result);

	waitKey();
}

void solve4_adjustment(const Mat& image, const double& contrast, const int& brightness)
{
	// 대상 이미지가 올바른 이미지인지 확인
	if (image.empty()) {
		std::cout << "Image load failed!" << std::endl;
		return;
	}

	// opencv의 cvtColor 함수를 이용해 RGB 컬러 이미지를 흑백 이미지로 변환
	Mat grayScaled;
	cvtColor(image, grayScaled, COLOR_RGB2GRAY);
	imwrite("3-1-gray.jpg", grayScaled);

	// CPixel 클래스를 이용해 흑백 이미지의 contrast, brightness 조정
	Mat result = cpixel.GS_LUT_basic_contrast_brightness(grayScaled, contrast, brightness);

	// 결과 이미지 출력
	imshow("Output Image", result);
	imwrite("3-1.jpg", result);

	waitKey();
}

void test1_fade_animation(const Mat& image1, const Mat& image2, const int& durationMs)
{
	// 두 이미지 모두 올바른 이미지인지 확인
	if (image1.empty() || image2.empty()) {
		std::cout << "Image load failed!" << std::endl;
		return;
	}

	// 프레임 당 ms
	int msPerFrame = 150;
	// 애니메이션 지속시간 동안의 총 프레임 수
	double numOfFrames = (double)durationMs / msPerFrame;
	
	// blending 가중치 초기화
	double alpha = 0;

	// 애니메이션 재생 시간 측정 시작
	clock_t animStart = clock();
	while (alpha < 1) {
		// 프레임 시작 시간 capture
		clock_t frameStart = clock();

		// CPixel 클래스를 이용한 이미지 blending 후, 결과물 출력
		// (image1의 blending 가중치(alpha)는 프레임마다 증가됨)
		Mat result = cpixel.GS_blending_effect(image1, image2, alpha);
		imshow("Output Image", result);

		// 총 프레임 수로 계산된 프레임당 증가치만큼 blending 가중치 증가
		alpha += (1.0 / numOfFrames);

		// 프레임 연산 종료 시각 capture
		clock_t frameEnd = clock();
		// 현재 프레임의 남은 시간만큼 delay
		waitKey(frameStart + msPerFrame - frameEnd);
	}
	// 애니메이션 재생 시간 측정 종료
	clock_t animEnd = clock();

	// 애니메이션 재생 시간 출력
	std::cout << "duration: " << animEnd - animStart << std::endl;

	waitKey();
}