//#include <iostream>
//#include <opencv2/opencv.hpp>
//#include "ImageAnalysis.h"
//
//using namespace cv;
//
//int main()
//{
//	// �Է� �̹��� �ε�
//	Mat binaryStuff = imread("./outputs/1_4_output_1.png", 0);
//	Mat binaryRice = imread("./outputs/1_4_output_2.png", 0);
//	// �Է� �̹��� ���Ϸ� ����
//	// (������Ʈ����/outputs ������ �̹� �ִٰ� ����)
//	imwrite("./outputs/1_5_input_1.png", binaryStuff);
//	imwrite("./outputs/1_5_input_2.png", binaryRice);
//
//	// =======================================================
//
//	CImageAnalysis cia;
//
//	// 5. ����ȭ�� �� �̹������� GS_findContours �Լ��� ����� �ܰ����� ã�� labeling
//	Mat labeledStuff = cia.GS_findContours(binaryStuff);
//	Mat labeledRice = cia.GS_findContours(binaryRice);
//
//	// =======================================================
//
//	// ��� �̹��� Ȯ��
//	imshow("labeled stuff", labeledStuff);
//	imshow("labeled rice", labeledRice);
//	// ��� �̹��� ���Ϸ� ����
//	// (������Ʈ����/outputs ������ �̹� �ִٰ� ����)
//	imwrite("./outputs/1_5_output_1.png", labeledStuff);
//	imwrite("./outputs/1_5_output_2.png", labeledRice);
//
//	waitKey();
//}
