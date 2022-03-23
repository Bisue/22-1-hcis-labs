//#include <iostream>
//#include <opencv2/opencv.hpp>
//#include "Pixel.h"
//
//using namespace cv;
//
//// ���� ��� �̹������� blurred �� �̹����� ����
//// Edge �� ����� �̹����� ����� ��ȯ
//Mat makeSubtracted(const Mat& original, const Mat& blurred)
//{
//	CPixel cp;
//
//	// original �̹������� blurred �̹��� �� ����� ��ȯ
//	return cp.GS_subtract_image(original, blurred);
//}
//
//int main()
//{
//	// input �̹��� �ε� (������ ���� �̹����� ���)
//	// (��� �̹��� ���)
//	Mat grayLenna = imread("./outputs/0_1_output_1.png", 0);
//	Mat blurredLenna = imread("./outputs/0_2_output_1.png", 0);
//
//	Mat grayJenny = imread("./outputs/0_1_output_2.png", 0);
//	Mat blurredJenny = imread("./outputs/0_2_output_2.png", 0);
//
//	// input �̹��� ���� (./outputs ���丮�� �ִٰ� ����)
//	imwrite("./outputs/0_3_input_1_1.png", grayLenna);
//	imwrite("./outputs/0_3_input_1_2.png", blurredLenna);
//
//	imwrite("./outputs/0_3_input_2_1.png", grayJenny);
//	imwrite("./outputs/0_3_input_2_2.png", blurredJenny);
//
//	// =======================================================
//
//	// ��� �̹������� bluured �� �̹����� ��
//	// (edge ����)
//	Mat edgeLenna = makeSubtracted(grayLenna, blurredLenna);
//	Mat edgeJenny = makeSubtracted(grayJenny, blurredJenny);
//
//	// =======================================================
//
//	// output �̹��� ���÷���
//	imshow("Lenna", edgeLenna);
//	imshow("Jenny", edgeJenny);
//	// output �̹��� ���� (./output ���丮�� �ִٰ� ����)
//	imwrite("./outputs/0_3_output_1.png", edgeLenna);
//	imwrite("./outputs/0_3_output_2.png", edgeJenny);
//
//	waitKey();
//}
