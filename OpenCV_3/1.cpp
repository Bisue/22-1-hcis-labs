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
	// ���� �̹��� ���� (./images ���丮�� �̹������� �ִٰ� ����)
	Mat originLenna = imread("./images/lenna.png");
	Mat originJenny = imread("./images/jenny.jpg");
	// ���� �̹��� ���� (./outputs ���丮�� �ִٰ� ����)
	imwrite("./outputs/1_1_input_1.png", originLenna);
	imwrite("./outputs/1_1_input_2.png", originJenny);

	// �̹��� ���� ��� ��ȯ
	Mat grayLenna = makeGrayScaled(originLenna);
	Mat grayJenny = makeGrayScaled(originJenny);

	// ��� �̹��� ���÷���
	imshow("Lenna", grayLenna);
	imshow("Jenny", grayJenny);
	// ��� �̹��� ���� (./output ���丮�� �ִٰ� ����)
	imwrite("./outputs/1_1_output_1.png", grayLenna);
	imwrite("./outputs/1_1_output_2.png", grayJenny);

	waitKey();
}
