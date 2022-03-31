//#include <iostream>
//#include <opencv2/opencv.hpp>
//#include "Pixel.h"
//
//using namespace cv;
//
//int main()
//{
//	// �Է� �̹��� �ε�
//	// (�÷� �̹���)
//	Mat imageA = imread("./images/briefcase.jpg");
//	Mat imageB = imread("./outputs/3_2_output.png");
//	// �Է� �̹��� ���Ϸ� ����
//	// (������Ʈ����/outputs ������ �̹� �ִٰ� ����
//	imwrite("./outputs/3_3_input_1.png", imageA);
//	imwrite("./outputs/3_3_input_2.png", imageB);
//
//	// =======================================================
//
//	CPixel cp;
//
//	// �̹��� A(���� briefcase) ���� �̹��� B(360 rotated of briefcase) �� ��
//	Mat subtracted = cp.GS_subtract_image(imageA, imageB);
//
//	// =======================================================
//
//	// ��� �̹��� Ȯ��
//	imshow("Subtract Result Briefcase", subtracted);
//	// ��� �̹��� ���Ϸ� ����
//	// (������Ʈ����/outputs ������ �̹� �ִٰ� ����)
//	imwrite("./outputs/3_3_output.png", subtracted);
//
//	waitKey();
//}
