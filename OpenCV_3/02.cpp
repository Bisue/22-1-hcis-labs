//#include <iostream>
//#include <opencv2/opencv.hpp>
//#include "Filter.h"
//
//using namespace cv;
//
//// blurred �� �̹����� ����� ��ȯ
//Mat makeBlurred(const Mat& image)
//{
//	CFilter cf;
//
//	// CFilter�� blurring �޼��� ���
//	// (option 1 - OpenCV ����)
//	return cf.GS_blurring(image, 1, CV_BLUR);
//}
//
//int main()
//{
//	// input �̹��� �ε� (0-1���� ���� grayscaled �̹��� ���)
//	Mat grayLenna = imread("./outputs/0_1_output_1.png");
//	Mat grayJenny = imread("./outputs/0_1_output_2.png");
//	// input �̹��� ���� (./outputs ���丮�� �ִٰ� ����)
//	imwrite("./outputs/0_2_input_1.png", grayLenna);
//	imwrite("./outputs/0_2_input_2.png", grayJenny);
//
//	// =======================================================
//
//	// �̹��� ���� ��� ��ȯ
//	Mat blurredLenna = makeBlurred(grayLenna);
//	Mat blurredJenny = makeBlurred(grayJenny);
//
//	// =======================================================
//
//	// output �̹��� ���÷���
//	imshow("Lenna", blurredLenna);
//	imshow("Jenny", blurredJenny);
//	// output �̹��� ���� (./output ���丮�� �ִٰ� ����)
//	imwrite("./outputs/0_2_output_1.png", blurredLenna);
//	imwrite("./outputs/0_2_output_2.png", blurredJenny);
//
//	waitKey();
//}
