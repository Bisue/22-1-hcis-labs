#include <iostream>
#include <opencv2/opencv.hpp>
#include "Color.h"

using namespace cv;

int main()
{
	// input �̹��� �ε� (./images ���丮�� ���� �÷� �̹������� �ִٰ� ����)
	Mat originJenny = imread("./images/jenny.jpg");
	// input �̹��� ���� (./outputs ���丮�� �ִٰ� ����)
	imwrite("./outputs/1_1_input.png", originJenny);

	// =======================================================

	CColor cc;

	// �÷� �̹����� �� 3�� ä�η� �и�
	Mat channels[3]; // b, g, r
	cc.GS_splitRGB(originJenny, channels);

	// GS_splitRGB�� ���������� cv::split�� ����ϰ�
	// cv::split�� BGR ������ ��ȯ��
	Mat R = channels[2];
	Mat G = channels[1];
	Mat B = channels[0];

	// =======================================================

	// output �̹��� ���÷���
	imshow("R", R);
	imshow("G", G);
	imshow("B", B);
	// output �̹��� ���� (./output ���丮�� �ִٰ� ����)
	imwrite("./outputs/1_1_output_1.png", R);
	imwrite("./outputs/1_1_output_2.png", G);
	imwrite("./outputs/1_1_output_3.png", B);

	waitKey();
}
