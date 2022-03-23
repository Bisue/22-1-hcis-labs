//#include <iostream>
//#include <opencv2/opencv.hpp>
//#include "Color.h"
//
//using namespace cv;
//
//int main()
//{
//	// input �̹��� �ε� (./images ���丮�� ���� �÷� �̹������� �ִٰ� ����)
//	Mat originJenny = imread("./images/jenny.jpg");
//	// input �̹��� ���� (./outputs ���丮�� �ִٰ� ����)
//	imwrite("./outputs/2_1_input.png", originJenny);
//
//	// =======================================================
//
//	// ���� �̹����� hsv�� ����
//	Mat hsv;
//	cvtColor(originJenny, hsv, COLOR_BGR2HSV);
//
//	// =======================================================
//
//	// output �̹��� ���÷���
//	imshow("HSV", hsv);
//	// output �̹��� ���� (./output ���丮�� �ִٰ� ����)
//	imwrite("./outputs/2_1_output.png", hsv);
//
//	waitKey();
//}
