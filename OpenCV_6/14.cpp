//#include <iostream>
//#include <opencv2/opencv.hpp>
//#include "Pixel.h"
//
//using namespace cv;
//
//int main()
//{
//	// �Է� �̹��� �ε�
//	Mat subtractionStuff = imread("./outputs/1_3_output_1.png", 0);
//	Mat subtractionRice = imread("./outputs/1_3_output_2.png", 0);
//	// �Է� �̹��� ���Ϸ� ����
//	// (������Ʈ����/outputs ������ �̹� �ִٰ� ����)
//	imwrite("./outputs/1_4_input_1.png", subtractionStuff);
//	imwrite("./outputs/1_4_input_2.png", subtractionRice);
//
//	// =======================================================
//
//	CPixel cp;
//
//	// 4. 1-3���� ����� ����� �̹����� otzu binarization ����
//	Mat binaryStuff = cp.GS_threshold(subtractionStuff, 0, THRESH_BINARY | THRESH_OTSU);
//	Mat binaryRice = cp.GS_threshold(subtractionRice, 0, THRESH_BINARY | THRESH_OTSU);
//
//	// =======================================================
//
//	// ��� �̹��� Ȯ��
//	imshow("binary edge stuff", binaryStuff);
//	imshow("binary edge rice", binaryRice);
//	// ��� �̹��� ���Ϸ� ����
//	// (������Ʈ����/outputs ������ �̹� �ִٰ� ����)
//	imwrite("./outputs/1_4_output_1.png", binaryStuff);
//	imwrite("./outputs/1_4_output_2.png", binaryRice);
//
//	waitKey();
//}
