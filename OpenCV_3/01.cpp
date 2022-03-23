#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;

// �̹����� ��� �̹��� ��ȯ
Mat makeGrayScaled(const Mat& image) {
	Mat gray;
	// cv::cvtColor�� �̿��� BGR���� GRAY�̹����� ��ȯ
	cvtColor(image, gray, COLOR_BGR2GRAY);

	return gray;
}

int main()
{
	// input �̹��� �ε� (./images ���丮�� ���� �÷� �̹������� �ִٰ� ����)
	Mat originLenna = imread("./images/lenna.png");
	Mat originJenny = imread("./images/jenny.jpg");
	// input �̹��� ���� (./outputs ���丮�� �ִٰ� ����)
	imwrite("./outputs/0_1_input_1.png", originLenna);
	imwrite("./outputs/0_1_input_2.png", originJenny);

	// =======================================================

	// �̹��� ���� ��� ��ȯ
	Mat grayLenna = makeGrayScaled(originLenna);
	Mat grayJenny = makeGrayScaled(originJenny);

	// =======================================================

	// output �̹��� ���÷���
	imshow("Lenna", grayLenna);
	imshow("Jenny", grayJenny);
	// output �̹��� ���� (./output ���丮�� �ִٰ� ����)
	imwrite("./outputs/0_1_output_1.png", grayLenna);
	imwrite("./outputs/0_1_output_2.png", grayJenny);

	waitKey();
}
