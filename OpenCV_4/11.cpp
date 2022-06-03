#include <iostream>
#include <opencv2/opencv.hpp>
#include "Filter.h"

using namespace cv;

// �Է� �̹����� ��� �̹����� ����� ��ȯ
Mat makeGrayScaled(const Mat& image)
{
	Mat gray;

	// cv::cvtColor �Լ��� ����� BGR �÷��̹������� GRAY�̹����� ����
	cvtColor(image, gray, COLOR_BGR2GRAY);

	return gray;
}

int main()
{
	// ���� �̹��� �ε�
	// (������Ʈ����/images�� ���� �̹������� �ִٰ� ����)
	Mat originJenny = imread("./images/jenny.jpg");
	Mat originRice = imread("./images/rice.png");
	// �Է� �̹��� ���Ϸ� ����
	// (������Ʈ����/outputs ������ �̹� �ִٰ� ����)
	imwrite("./outputs/1_1_input_1.png", originJenny);
	imwrite("./outputs/1_1_input_2.png", originRice);

	// =======================================================

	// �� �Է� �̹����� ��� �̹����� ����
	Mat grayJenny = makeGrayScaled(originJenny);
	Mat grayRice = makeGrayScaled(originRice);

	CFilter cp;

	int cnt = 0;
	Mat blurred = grayJenny;
	while (true) {
		blurred = cp.GS_blurring(blurred , CV_BLUR, 1);
		std::cout << cnt++ << std::endl;
		imshow("Blurred", blurred);
		if (waitKey(1) == 13) {
			break;
		}
	}

	// =======================================================

	//// ��� �̹��� Ȯ��
	//imshow("Grayscaled Jenny", grayJenny);
	//imshow("Grayscaled Rice", grayRice);
	//// ��� �̹��� ���Ϸ� ����
	//// (������Ʈ����/outputs ������ �̹� �ִٰ� ����)
	//imwrite("./outputs/1_1_output_1.png", grayJenny);
	//imwrite("./outputs/1_1_output_2.png", grayRice);

	waitKey();
}
