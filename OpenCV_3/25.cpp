//#include <iostream>
//#include <opencv2/opencv.hpp>
//#include "Color.h"
//
//using namespace cv;
//
//int main()
//{
//	// input �̹��� �ε� (������ ���� �̹��� ���)
//	Mat hsv = imread("./outputs/2_4_output.png");
//	// input �̹��� ���� (./outputs ���丮�� �ִٰ� ����)
//	imwrite("./outputs/2_5_input.png", hsv);
//
//	// =======================================================
//
//	// HSV' �̹����� RGB�� ��ȯ
//	Mat converted;
//	cvtColor(hsv, converted, COLOR_HSV2BGR);
//
//	// =======================================================
//
//	// output �̹��� ���÷���
//	imshow("Converted RGB", converted);
//	// output �̹��� ���� (./output ���丮�� �ִٰ� ����)
//	imwrite("./outputs/2_5_output.png", converted);
//
//	waitKey();
//}
