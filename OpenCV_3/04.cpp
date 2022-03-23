#include <iostream>
#include <opencv2/opencv.hpp>
#include "Pixel.h"

using namespace cv;

// ���� ��� �̹����� ����� edge �̹����� ����
// image sharpning �� ����
Mat makeAdded(const Mat& original, const Mat& edge)
{
	CPixel cp;

	// original �̹����� edge �̹��� ���� ����� ��ȯ
	return cp.GS_add_image(original, edge);
}

int main()
{
	// input �̹��� �ε� (0-1, 0-2 ���� ���� �̹����� ���)
	Mat grayLenna = imread("./outputs/0_1_output_1.png");
	Mat edgeLenna = imread("./outputs/0_3_output_1.png");

	Mat grayJenny = imread("./outputs/0_1_output_2.png");
	Mat edgeJenny = imread("./outputs/0_3_output_2.png");

	// input �̹��� ���� (./outputs ���丮�� �ִٰ� ����)
	imwrite("./outputs/0_4_input_1_1.png", grayLenna);
	imwrite("./outputs/0_4_input_1_2.png", edgeLenna);

	imwrite("./outputs/0_4_input_2_1.png", grayJenny);
	imwrite("./outputs/0_4_input_2_2.png", edgeJenny);

	// =======================================================

	// ��� �̹���, ����� edge �̹����� ����
	Mat sharpnedLenna = makeAdded(grayLenna, edgeLenna);
	Mat sharpnedJenny = makeAdded(grayJenny, edgeJenny);

	// =======================================================

	// output �̹��� ���÷���
	imshow("Lenna", sharpnedLenna);
	imshow("Jenny", sharpnedJenny);
	// output �̹��� ���� (./output ���丮�� �ִٰ� ����)
	imwrite("./outputs/0_4_output_1.png", sharpnedLenna);
	imwrite("./outputs/0_4_output_2.png", sharpnedJenny);

	waitKey();
}
