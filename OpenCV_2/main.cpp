#include <iostream>
#include <opencv2/opencv.hpp>
#include "Pixel.h"

using namespace cv;

// ���� 2-4
void solve(const Mat&);

// ��� �Լ����� ���ϰ� ������ ���� CPixel �ν��Ͻ� ����
CPixel cpixel;

int main()
{
	// ���� ��� �̹��� �ε�
	// (�̹������� <������Ʈ���/images/> �� ����ִ� ������ ����)
	Mat image1 = imread("./images/lenna.png");

	// cpixel �ν��Ͻ� ����
	cpixel = CPixel();

	// ������ �Լ� �и�
	solve(image1);
}

// ���� 2-4
void solve(const Mat& image)
{
	// �� ���� �̹����� ���� �÷� �̹����� ��� �̹����� ����
	Mat grayScaled;
	cvtColor(image, grayScaled, COLOR_BGR2GRAY);

	imwrite("./outputs/2_4_input.png", grayScaled);

	// GS_adaptive_threshold �޼��带 �̿��� MEAN ������� �̹����� ���������� �ݺ��Ͽ� ����ȭ
	Mat binaryImage = cpixel.GS_adaptive_threshold(grayScaled, 150, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY);
	imshow("Binary Image", binaryImage);

	imwrite("./outputs/2_4_output.png", binaryImage);

	waitKey();
}
