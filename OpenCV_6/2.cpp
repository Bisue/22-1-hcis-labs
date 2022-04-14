#include <iostream>
#include <opencv2/opencv.hpp>
#include "Edge.h"
#include "Morph.h"

using namespace cv;

// 1 - MORPH_ELLIPSE ������ 11x11 kenel�� �̹��� erosion
Mat erosionImage(const Mat& image)
{
	Mat erosion;

	// �簢���� 3x3�̰� �߾��� anchor�� structuring element
	Mat kernel = cv::getStructuringElement(MORPH_RECT, Size(3, 3), Point(1, 1));

	// ���� structuring element�� �Է� �̹����� erode
	cv::erode(image, erosion, kernel);

	imshow("erosion", erosion);

	return erosion;
}

// 2 - MORPH_ELLIPSE ������ 11x11 kenel�� �̹��� dilation
Mat dilationImage(const Mat& image)
{
	Mat dilation;

	// �簢���� 3x3�̰� �߾��� anchor�� structuring element
	Mat kernel = cv::getStructuringElement(MORPH_RECT, Size(3, 3), Point(1, 1));

	// ���� structuring element�� �Է� �̹����� dilate
	cv::dilate(image, dilation, kernel);

	imshow("dilation", dilation);

	return dilation;
}

Mat closingImage(const Mat& image)
{
	Mat dilation = dilationImage(image);
	return erosionImage(dilation);
}

Mat openingImage(const Mat& image)
{
	Mat erosion = erosionImage(image);
	return dilationImage(erosion);
}

int main()
{
	// �Է� �̹���(step 4 outputs) �ε�
	Mat binaryStuff = imread("./outputs/1_4_output_1.png", 0);
	Mat binaryRice = imread("./outputs/1_4_output_2.png", 0);

	// �Է� �̹��� ���Ϸ� ����
	imwrite("./outputs/2_1_input_1.png", binaryStuff);
	imwrite("./outputs/2_1_input_2.png", binaryRice);

	// =======================================================

	CEdge ce;
	CMorph cm;

	// 6. step 4 output �� edge�� canny edge detector�� ����
	Mat cannyStuff = ce.GS_canny_edge_Canny(binaryStuff, 50, 100);
	Mat cannyRice = ce.GS_canny_edge_Canny(binaryRice, 50, 100);

	// �߰� ��� �̹��� ���/����
	imshow("stuff", cannyStuff);
	imshow("rice", cannyRice);
	imwrite("./outputs/2_1_output_1.png", cannyStuff);
	imwrite("./outputs/2_1_output_2.png", cannyRice);

	// Ű �Է� ���
	waitKey();

	// 7. step 4 output �� edge�� sobel edge detector�� ����
	Mat sobelStuff = ce.GS_sobel_edge(binaryStuff);
	Mat sobelRice = ce.GS_sobel_edge(binaryRice);

	// �߰� ��� �̹��� ���/����
	imshow("stuff", sobelStuff);
	imshow("rice", sobelRice);
	imwrite("./outputs/2_2_output_1.png", sobelStuff);
	imwrite("./outputs/2_2_output_2.png", sobelRice);

	// Ű �Է� ���
	waitKey();

	// 8. step 7 output(sobel dege) �̹����� closing �̹���
	Mat closingStuff = closingImage(sobelStuff);
	Mat closingRice = closingImage(sobelRice);

	// �߰� ��� �̹��� ���/����
	imshow("stuff", closingStuff);
	imshow("rice", closingRice);
	imwrite("./outputs/2_3_output_1.png", closingStuff);
	imwrite("./outputs/2_3_output_2.png", closingRice);

	// Ű �Է� ���
	waitKey();

	// 9. step 8 output(closing of sobel dege) �̹����� opening �̹���
	Mat openingStuff = openingImage(closingStuff);
	Mat openingRice = openingImage(closingRice);

	// ���� ��� �̹��� ���/����
	imshow("stuff", openingStuff);
	imshow("rice", openingRice);
	imwrite("./outputs/2_4_output_1.png", openingStuff);
	imwrite("./outputs/2_4_output_2.png", openingRice);

	waitKey();
}
