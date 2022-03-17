#include <iostream>
#include <opencv2/opencv.hpp>
#include "Pixel.h"

using namespace cv;

// ���� 2-1
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

// ���� 2-1
void solve(const Mat& image)
{
	imwrite("./outputs/2_1_input.png", image);

	// �� ���� �̹����� ���� �÷� �̹����� ��� �̹����� ����
	Mat grayScaled;
	cvtColor(image, grayScaled, COLOR_BGR2GRAY);

	// ��� �̹��� ���
	imshow("Gray Scaled Image", grayScaled);

	imwrite("./outputs/2_1_output.png", grayScaled);

	waitKey();
}