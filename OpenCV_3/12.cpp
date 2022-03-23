#include <iostream>
#include <opencv2/opencv.hpp>
#include "Pixel.h"

using namespace cv;

int main()
{
	// input �̹��� �ε� (������ ���� �̹��� ���)
	// (��� �̹����� ���)
	Mat R = imread("./outputs/1_1_output_1.png", 0);
	Mat G = imread("./outputs/1_1_output_2.png", 0);
	Mat B = imread("./outputs/1_1_output_3.png", 0);
	// input �̹��� ���� (./outputs ���丮�� �ִٰ� ����)
	imwrite("./outputs/1_2_input_1.png", R);
	imwrite("./outputs/1_2_input_2.png", G);
	imwrite("./outputs/1_2_input_3.png", B);

	// =======================================================

	CPixel cp;

	// R, G, B �� ä�ο� ���ؼ� equalization ����
	Mat equalizedR = cp.GS_histeq(R);
	Mat equalizedG = cp.GS_histeq(G);
	Mat equalizedB = cp.GS_histeq(B);

	// =======================================================

	// output �̹��� ���÷���
	imshow("Equalized R", equalizedR);
	imshow("Equalized G", equalizedG);
	imshow("Equalized B", equalizedB);
	// output �̹��� ���� (./output ���丮�� �ִٰ� ����)
	imwrite("./outputs/1_2_output_1.png", equalizedR);
	imwrite("./outputs/1_2_output_2.png", equalizedG);
	imwrite("./outputs/1_2_output_3.png", equalizedB);

	waitKey();
}
