#include <iostream>
#include <opencv2/opencv.hpp>
#include "Pixel.h"

using namespace cv;

// ���� 1-1
void solve(const Mat&, const Mat&);

// ��� �Լ����� ���ϰ� ������ ���� CPixel �ν��Ͻ� ����
CPixel cpixel;

int main()
{
	// ���� ��� �̹��� �ε�
	// (�̹������� <������Ʈ���/images/> �� ����ִ� ������ ����)
	Mat image1 = imread("./images/lenna.png");
	Mat image2 = imread("./images/stuff_color_1.png");

	// cpixel �ν��Ͻ� ����
	cpixel = CPixel();

	// ������ �Լ� �и�
	solve(image1, image2);
}

// ���� 1-1
void solve(const Mat& image1, const Mat& image2)
{
	// �� ���� �̹����� ���� �÷� �̹����� ��� �̹����� ����
	Mat grayScaled1;
	cvtColor(image1, grayScaled1, COLOR_BGR2GRAY);
	Mat grayScaled2;
	cvtColor(image2, grayScaled2, COLOR_BGR2GRAY);

	imwrite("./outputs/1_1_input_1.png", grayScaled1);
	imwrite("./outputs/1_1_input_2.png", grayScaled2);

	// ������ ��� �̹����� ���ؼ� histogram ����
	Mat hist1 = cpixel.GS_imhist(grayScaled1);
	imshow("Histogram 1", hist1);
	Mat hist2 = cpixel.GS_imhist(grayScaled2);
	imshow("Histogram 2", hist2);

	imwrite("./outputs/1_1_output_1.png", grayScaled1);
	imwrite("./outputs/1_1_output_2.png", grayScaled2);

	waitKey();
}
