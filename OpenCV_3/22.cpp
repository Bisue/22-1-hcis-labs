//#include <iostream>
//#include <opencv2/opencv.hpp>
//#include "Color.h"
//
//using namespace cv;
//
//int main()
//{
//	// input �̹��� �ε� (������ ���� �̹��� ���)
//	Mat hsv = imread("./outputs/2_1_output.png");
//	// input �̹��� ���� (./outputs ���丮�� �ִٰ� ����)
//	imwrite("./outputs/2_2_input.png", hsv);
//
//	// =======================================================
//
//	// hsv �̹����� h, s, v�� split
//	Mat channels[3];
//	split(hsv, channels);
//
//	Mat h = channels[0];
//	Mat s = channels[1];
//	Mat v = channels[2];
//
//	// =======================================================
//
//	// output �̹��� ���÷���
//	imshow("H", h);
//	imshow("S", s);
//	imshow("V", v);
//
//	// output �̹��� ���� (./output ���丮�� �ִٰ� ����)
//	imwrite("./outputs/2_2_output_1.png", h);
//	imwrite("./outputs/2_2_output_2.png", s);
//	imwrite("./outputs/2_2_output_3.png", v);
//
//	waitKey();
//}
