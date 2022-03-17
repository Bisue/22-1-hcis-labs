#include <iostream>
#include <opencv2/opencv.hpp>
#include "Pixel.h"

using namespace cv;

// ���� 1-3
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

// ���� 1-3
void solve(const Mat& image1, const Mat& image2)
{
	// �� ���� �̹����� ���� �÷� �̹����� ��� �̹����� ����
	Mat grayScaled1;
	cvtColor(image1, grayScaled1, COLOR_BGR2GRAY);
	Mat grayScaled2;
	cvtColor(image2, grayScaled2, COLOR_BGR2GRAY);

	imwrite("./outputs/1_3_input_1.png", grayScaled1);
	imwrite("./outputs/1_3_input_2.png", grayScaled2);

	// ������ ��� �̹����� ���ؼ� histogram equalization ���� ��, ��� �̹����� ���ؼ� histogram �̹��� ����
	Mat equal1 = cpixel.GS_histeq(grayScaled1);
	Mat hist1 = cpixel.GS_imhist(equal1);
	imshow("A_equlizedHist", hist1);

	Mat equal2 = cpixel.GS_histeq(grayScaled2);
	Mat hist2 = cpixel.GS_imhist(equal2);
	imshow("B_equlizedHist", hist2);

	imwrite("./outputs/1_3_output_1.png", hist1);
	imwrite("./outputs/1_3_output_2.png", hist2);

	waitKey();
}
