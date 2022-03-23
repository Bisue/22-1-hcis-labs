//#include <iostream>
//#include <opencv2/opencv.hpp>
//#include "Color.h"
//
//using namespace cv;
//
//int main()
//{
//	// input �̹��� �ε� (������ ���� �̹��� ���)
//	// (��� �̹����� ���)
//	Mat h = imread("./outputs/2_2_output_1.png", 0);
//	Mat s = imread("./outputs/2_2_output_2.png", 0);
//	Mat equalizedV = imread("./outputs/2_3_output.png", 0);
//	// input �̹��� ���� (./outputs ���丮�� �ִٰ� ����)
//	imwrite("./outputs/2_4_input_1.png", h);
//	imwrite("./outputs/2_4_input_2.png", s);
//	imwrite("./outputs/2_4_input_3.png", equalizedV);
//
//	// =======================================================
//
//	CColor cc;
//
//	// H, S, V ä�� �̹��� �迭
//	Mat hsv[3] = { h, s, equalizedV };
//
//	// H, S, V �� ä���� ���� �ϳ��� �÷� �̹����� ����
//	Mat color;
//	merge(hsv, 3, color);
//
//	// =======================================================
//
//	// output �̹��� ���÷���
//	imshow("HSV'", color);
//	// output �̹��� ���� (./output ���丮�� �ִٰ� ����)
//	imwrite("./outputs/2_4_output.png", color);
//
//	waitKey();
//}
