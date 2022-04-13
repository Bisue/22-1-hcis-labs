#include <iostream>
#include <opencv2/opencv.hpp>
#include "Edge.h"
#include "Morph.h"

using namespace cv;

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
	Mat closingStuff = cm.GS_closing(sobelStuff, MORPH_RECT, 1);
	Mat closingRice = cm.GS_closing(sobelRice, MORPH_RECT, 1);

	// �߰� ��� �̹��� ���/����
	imshow("stuff", closingStuff);
	imshow("rice", closingRice);
	imwrite("./outputs/2_3_output_1.png", closingStuff);
	imwrite("./outputs/2_3_output_2.png", closingRice);

	// Ű �Է� ���
	waitKey();

	// 9. step 8 output(closing of sobel dege) �̹����� opening �̹���
	Mat openingStuff = cm.GS_opening(closingStuff, MORPH_RECT, 1);
	Mat openingRice = cm.GS_opening(closingRice, MORPH_RECT, 1);

	// ���� ��� �̹��� ���/����
	imshow("stuff", openingStuff);
	imshow("rice", openingRice);
	imwrite("./outputs/2_4_output_1.png", openingStuff);
	imwrite("./outputs/2_4_output_2.png", openingRice);

	waitKey();
}
