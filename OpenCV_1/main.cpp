#include <iostream>
#include <opencv2/opencv.hpp>
#include "Pixel.h"
#include <time.h>

using namespace cv;

// �ǽ� 1-1, 1-2
void solve1_addition(const Mat&, const Mat&);
// �ǽ� 2-1, 2-2
void solve2_subtraction(const Mat&, const Mat&);
// �ǽ� 3-1, 3-2
void solve3_blending(const Mat&, const Mat&, const double&);
// �ǽ� 4-1, 4-2
void solve4_adjustment(const Mat&, const double&, const int&);
// �׽�Ʈ
void test1_fade_animation(const Mat&, const Mat&, const int&);

// ��� �Լ����� ���ϰ� ������ ���� CPixel �ν��Ͻ� ����
CPixel cpixel;

int main()
{
	// ���� ��� �̹��� �ε�
	// (�̹������� <������Ʈ���/images/> �� ����ִ� ������ ����)
	Mat image1 = imread("./images/stuff_color_1.png");
	//Mat image2 = imread("./images/stuff_color_2.png");
	//Mat image1 = imread("./images/lenna.png");
	//Mat image2 = imread("./images/orange.jpg");

	// cpixel �ν��Ͻ� ����
	cpixel = CPixel();

	// ������ �Լ� �и�
	//solve1_addition(image1, image2);
	//solve2_subtraction(image1, image2);
	//solve3_blending(image1, image2, 0.66);
	solve4_adjustment(image1, 1.5, 30);
	
	// fade-out-in �ִϸ��̼�
	//test1_fade_animation(image1, image2, 3000);
}

// �ǽ� 1-1, 1-2
void solve1_addition(const Mat& image1, const Mat& image2)
{
	// �� �̹��� ��� �ùٸ� �̹������� Ȯ��
	if (image1.empty() || image2.empty()) {
		std::cout << "Image load failed!" << std::endl;
		return;
	}

	// CPixel Ŭ������ �̿��� �̹��� add
	Mat result = cpixel.GS_add_image(image1, image2);

	// ��� �̹��� ���
	imshow("Output Image", result);

	waitKey();
}

void solve2_subtraction(const Mat& image1, const Mat& image2)
{
	// �� �̹��� ��� �ùٸ� �̹������� Ȯ��
	if (image1.empty() || image2.empty()) {
		std::cout << "Image load failed!" << std::endl;
		return;
	}

	// CPixel Ŭ������ �̿��� �̹��� sub
	Mat result = cpixel.GS_subtract_image(image1, image2);

	// ��� �̹��� ���
	imshow("Output Image", result);

	waitKey();
}

void solve3_blending(const Mat& image1, const Mat& image2, const double& alpha)
{
	// �� �̹��� ��� �ùٸ� �̹������� Ȯ��
	if (image1.empty() || image2.empty()) {
		std::cout << "Image load failed!" << std::endl;
		return;
	}

	// CPixel Ŭ������ �̿��� �̹��� blending
	// (alpha ���� image1�� weight��)
	Mat result = cpixel.GS_blending_effect(image1, image2, alpha);

	// ��� �̹��� ���
	imshow("Output Image", result);

	waitKey();
}

void solve4_adjustment(const Mat& image, const double& contrast, const int& brightness)
{
	// ��� �̹����� �ùٸ� �̹������� Ȯ��
	if (image.empty()) {
		std::cout << "Image load failed!" << std::endl;
		return;
	}

	// opencv�� cvtColor �Լ��� �̿��� RGB �÷� �̹����� ��� �̹����� ��ȯ
	Mat grayScaled;
	cvtColor(image, grayScaled, COLOR_RGB2GRAY);
	imwrite("3-1-gray.jpg", grayScaled);

	// CPixel Ŭ������ �̿��� ��� �̹����� contrast, brightness ����
	Mat result = cpixel.GS_LUT_basic_contrast_brightness(grayScaled, contrast, brightness);

	// ��� �̹��� ���
	imshow("Output Image", result);
	imwrite("3-1.jpg", result);

	waitKey();
}

void test1_fade_animation(const Mat& image1, const Mat& image2, const int& durationMs)
{
	// �� �̹��� ��� �ùٸ� �̹������� Ȯ��
	if (image1.empty() || image2.empty()) {
		std::cout << "Image load failed!" << std::endl;
		return;
	}

	// ������ �� ms
	int msPerFrame = 150;
	// �ִϸ��̼� ���ӽð� ������ �� ������ ��
	double numOfFrames = (double)durationMs / msPerFrame;
	
	// blending ����ġ �ʱ�ȭ
	double alpha = 0;

	// �ִϸ��̼� ��� �ð� ���� ����
	clock_t animStart = clock();
	while (alpha < 1) {
		// ������ ���� �ð� capture
		clock_t frameStart = clock();

		// CPixel Ŭ������ �̿��� �̹��� blending ��, ����� ���
		// (image1�� blending ����ġ(alpha)�� �����Ӹ��� ������)
		Mat result = cpixel.GS_blending_effect(image1, image2, alpha);
		imshow("Output Image", result);

		// �� ������ ���� ���� �����Ӵ� ����ġ��ŭ blending ����ġ ����
		alpha += (1.0 / numOfFrames);

		// ������ ���� ���� �ð� capture
		clock_t frameEnd = clock();
		// ���� �������� ���� �ð���ŭ delay
		waitKey(frameStart + msPerFrame - frameEnd);
	}
	// �ִϸ��̼� ��� �ð� ���� ����
	clock_t animEnd = clock();

	// �ִϸ��̼� ��� �ð� ���
	std::cout << "duration: " << animEnd - animStart << std::endl;

	waitKey();
}