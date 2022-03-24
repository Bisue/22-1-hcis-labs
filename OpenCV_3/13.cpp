//#include <iostream>
//#include <opencv2/opencv.hpp>
//#include "Color.h"
//
//using namespace cv;
//
//int main()
//{
//	// input �̹��� �ε� (������ ���� �̹��� ���)
//	// (1ä�� �̹����� ���)
//	Mat equalizedR = imread("./outputs/1_2_output_1.png", 0);
//	Mat equalizedG = imread("./outputs/1_2_output_2.png", 0);
//	Mat equalizedB = imread("./outputs/1_2_output_3.png", 0);
//	// input �̹��� ���� (./outputs ���丮�� �ִٰ� ����)
//	imwrite("./outputs/1_3_input_1.png", equalizedR);
//	imwrite("./outputs/1_3_input_2.png", equalizedG);
//	imwrite("./outputs/1_3_input_3.png", equalizedB);
//
//	// =======================================================
//
//	CColor cc;
//
//	// R, G, B ä�� �̹��� �迭 (B-G-R ����)
//	Mat rgb[3] = { equalizedB, equalizedG, equalizedR };
//
//	// R, G, B �� ä���� ���� �ϳ��� �÷� �̹����� ����
//	Mat color = cc.GS_compositeRGB(rgb);
//
//	// =======================================================
//
//	// output �̹��� ���÷���
//	imshow("Equalized R", color);
//	// output �̹��� ���� (./output ���丮�� �ִٰ� ����)
//	imwrite("./outputs/1_3_output.png", color);
//
//	waitKey();
//}
