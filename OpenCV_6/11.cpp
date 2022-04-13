#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;

// 0 - �Է� �̹����� gray-scaled �� �̹��� ��ȯ
Mat makeGrayScaled(const Mat& image) {
	Mat gray;
	// cv:cvtColor �Լ��� BGR ä�� �̹����� gray-scaled �̹����� ��ȯ
	cvtColor(image, gray, COLOR_BGR2GRAY);

	return gray;
}

// 1 - MORPH_ELLIPSE ������ 11x11 kenel�� �̹��� erosion
Mat erosionImage(const Mat& image)
{
	Mat erosion;

	// ����(Ÿ����)�� 11x11�̰� �߾��� anchor�� structuring element
	Mat kernel = cv::getStructuringElement(MORPH_ELLIPSE, Size(11, 11), Point(5, 5));

	// ���� structuring element�� �Է� �̹����� erode
	cv::erode(image, erosion, kernel);

	return erosion;
}

int main()
{
	// ���� �̹��� �ε�
	// (������Ʈ����/images�� ���� �̹������� �ִٰ� ����)
	Mat originStuff = imread("./images/stuff_color.png");
	Mat originRice = imread("./images/rice.png");

	// =======================================================

	// 0. stuff_color, rice �̹����� gray-scaled �̹��� �غ�
	Mat grayStuff = makeGrayScaled(originStuff);
	Mat grayRice = makeGrayScaled(originRice);

	// �Է� �̹��� ���Ϸ� ����
	// (������Ʈ����/outputs ������ �̹� �ִٰ� ����)
	imwrite("./outputs/1_1_input_1.png", grayStuff);
	imwrite("./outputs/1_1_input_2.png", grayRice);

	// 1. �� �̹����� erosion
	Mat erosionStuff = erosionImage(grayStuff);
	Mat erosionRice = erosionImage(grayRice);

	// =======================================================

	// ��� �̹��� Ȯ��
	imshow("erosion of stuff", erosionStuff);
	imshow("erosion of rice", erosionRice);
	// ��� �̹��� ���Ϸ� ����
	// (������Ʈ����/outputs ������ �̹� �ִٰ� ����)
	imwrite("./outputs/1_1_output_1.png", erosionStuff);
	imwrite("./outputs/1_1_output_2.png", erosionRice);

	waitKey();
}
