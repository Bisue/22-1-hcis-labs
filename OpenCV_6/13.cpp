#include <iostream>
#include <opencv2/opencv.hpp>
#include "Pixel.h"

using namespace cv;

int main()
{
	// �Է� �̹��� �ε�
	Mat grayStuff = imread("./outputs/1_1_input_1.png", 0);
	Mat erosionStuff = imread("./outputs/1_1_output_1.png", 0);
	Mat grayRice = imread("./outputs/1_1_input_2.png", 0);
	Mat erosionRice = imread("./outputs/1_1_output_2.png", 0);
	// �Է� �̹��� ���Ϸ� ����
	// (������Ʈ����/outputs ������ �̹� �ִٰ� ����)
	imwrite("./outputs/1_3_input_1_1.png", grayStuff);
	imwrite("./outputs/1_3_input_1_2.png", erosionStuff);
	imwrite("./outputs/1_3_input_2_1.png", grayRice);
	imwrite("./outputs/1_3_input_2_2.png", erosionRice);

	// =======================================================

	CPixel cp;

	// 3. ����(gray-scaled) �̹������� dilation of erosion �̹����� ��
	Mat subtractStuff = cp.GS_subtract_image(grayStuff, erosionStuff);
	Mat subtractRice = cp.GS_subtract_image(grayRice, erosionRice);

	// =======================================================

	// ��� �̹��� Ȯ��
	imshow("subtraction stuff", subtractStuff);
	imshow("subtraction rice", subtractRice);
	// ��� �̹��� ���Ϸ� ����
	// (������Ʈ����/outputs ������ �̹� �ִٰ� ����)
	imwrite("./outputs/1_3_output_1.png", subtractStuff);
	imwrite("./outputs/1_3_output_2.png", subtractRice);

	waitKey();
}
