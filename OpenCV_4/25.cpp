#include <iostream>
#include <opencv2/opencv.hpp>
#include "Pixel.h"

using namespace cv;

int main()
{
	// �Է� �̹��� �ε�
	// (�÷� �̹���)
	Mat imageA = imread("./outputs/2_2_output.png");
	Mat imageB = imread("./outputs/2_4_output.png");
	// �Է� �̹��� ���Ϸ� ����
	// (������Ʈ����/outputs ������ �̹� �ִٰ� ����)
	imwrite("./outputs/2_5_input_1.png", imageA);
	imwrite("./outputs/2_5_input_2.png", imageB);

	// =======================================================

	CPixel cp;

	// �̹��� A(Scaled of rotated) ���� �̹��� B(Rotated of scaled) �� ��
	Mat subtracted = cp.GS_subtract_image(imageA, imageB);

	// =======================================================

	// ��� �̹��� Ȯ��
	imshow("Subtract Result Briefcase", subtracted);
	// ��� �̹��� ���Ϸ� ����
	// (������Ʈ����/outputs ������ �̹� �ִٰ� ����)
	imwrite("./outputs/2_5_output.png", subtracted);

	waitKey();
}
