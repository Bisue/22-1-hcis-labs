//#include <iostream>
//#include <opencv2/opencv.hpp>
//#include "Pixel.h"
//
//using namespace cv;
//
//int main()
//{
//	// input �̹��� �ε� (������ ���� �̹��� ���)
//	// (��� �̹����� ���)
//	Mat v = imread("./outputs/2_2_output_3.png", 0);
//	// input �̹��� ���� (./outputs ���丮�� �ִٰ� ����)
//	imwrite("./outputs/2_3_input.png", v);
//
//	// =======================================================
//
//	CPixel cp;
//
//	// hsv �� v ä�ο� ���ؼ� equalization ����
//	Mat equalizedV = cp.GS_histeq(v);
//
//	// =======================================================
//
//	// output �̹��� ���÷���
//	imshow("Equalized V", equalizedV);
//
//	// output �̹��� ���� (./output ���丮�� �ִٰ� ����)
//	imwrite("./outputs/2_3_output.png", equalizedV);
//
//	waitKey();
//}
