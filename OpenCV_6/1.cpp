#include <iostream>
#include <opencv2/opencv.hpp>
#include "Pixel.h"
#include "ImageAnalysis.h"

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

// 2 - MORPH_ELLIPSE ������ 11x11 kenel�� �̹��� dilation
Mat dilationImage(const Mat& image)
{
	Mat dilation;

	// ����(Ÿ����)�� 11x11�̰� �߾��� anchor�� structuring element
	Mat kernel = cv::getStructuringElement(MORPH_ELLIPSE, Size(11, 11), Point(5, 5));

	// ���� structuring element�� �Է� �̹����� dilate
	cv::dilate(image, dilation, kernel);

	return dilation;
}


int main()
{
	// ���� �̹��� �ε�
	// (������Ʈ����/images�� ���� �̹������� �ִٰ� ����)
	Mat originStuff = imread("./images/stuff_color.png");
	Mat originRice = imread("./images/rice.png");

	// =======================================================

	CPixel cp;
	CImageAnalysis cia;

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

	// �߰� ��� �̹��� ����
	imwrite("./outputs/1_1_output_1.png", erosionStuff);
	imwrite("./outputs/1_1_output_2.png", erosionRice);

	// 2. �� �ܰ迡�� erosion�� �� �̹������� dilation
	Mat dilationStuff = dilationImage(erosionStuff);
	Mat dilationRice = dilationImage(erosionRice);

	// �߰� ��� �̹��� ����
	imwrite("./outputs/1_2_output_1.png", dilationStuff);
	imwrite("./outputs/1_2_output_2.png", dilationRice);

	// 3. ����(gray-scaled) �̹������� dilation of erosion �̹����� ��
	Mat subtractStuff = cp.GS_subtract_image(grayStuff, erosionStuff);
	Mat subtractRice = cp.GS_subtract_image(grayRice, erosionRice);

	// �߰� ��� �̹��� ����
	imwrite("./outputs/1_3_output_1.png", subtractStuff);
	imwrite("./outputs/1_3_output_2.png", subtractRice);

	// 4. 1-3���� ����� ����� �̹����� otzu binarization ����
	Mat binaryStuff = cp.GS_threshold(subtractStuff, 0, THRESH_BINARY | THRESH_OTSU);
	Mat binaryRice = cp.GS_threshold(subtractRice, 0, THRESH_BINARY | THRESH_OTSU);

	// �߰� ��� �̹��� ����
	imwrite("./outputs/1_4_output_1.png", binaryStuff);
	imwrite("./outputs/1_4_output_2.png", binaryRice);

	// 5. ����ȭ�� �� �̹������� GS_findContours �Լ��� ����� �ܰ����� ã�� labeling
	Mat labeledStuff = cia.GS_findContours(binaryStuff);
	Mat labeledRice = cia.GS_findContours(binaryRice);

	// =======================================================

	// ���� ��� �̹��� Ȯ��
	imshow("erosion of stuff", labeledStuff);
	imshow("erosion of rice", labeledRice);
	// ���� ��� �̹��� ���Ϸ� ����
	// (������Ʈ����/outputs ������ �̹� �ִٰ� ����)
	imwrite("./outputs/1_5_output_1.png", labeledStuff);
	imwrite("./outputs/1_5_output_2.png", labeledRice);

	waitKey();
}
