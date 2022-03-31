#include <iostream>
#include <opencv2/opencv.hpp>
#include "Edge.h"

using namespace cv;

// �Է� �̹����� Canny Edge Detector�� ������ ���� ����
Mat getEdgeCanny(const Mat& image)
{
	CEdge ce;

	// CEdge�� GS_canny_edge_Canny �Լ��� �����
	// �ش� �̹����� Canny Edge Detector�� �����Ͽ� ���� ����
	Mat edge = ce.GS_canny_edge_Canny(image);

	return edge;
}

int main()
{
	// �Է� �̹��� �ε�
	// (��� �̹��� ����Ͽ� �ε�)
	Mat grayJenny = imread("./outputs/1_1_output_1.png", 0);
	Mat grayRice = imread("./outputs/1_1_output_2.png", 0);
	// �Է� �̹��� ���Ϸ� ����
	// (������Ʈ����/outputs ������ �̹� �ִٰ� ����)
	imwrite("./outputs/1_4_input_1.png", grayJenny);
	imwrite("./outputs/1_4_input_2.png", grayRice);

	// =======================================================

	// �� �̹����� ���� Canny ����� Edge ����
	Mat edgeJenny = getEdgeCanny(grayJenny);
	Mat edgeRice = getEdgeCanny(grayRice);

	// =======================================================

	// ��� �̹��� Ȯ��
	imshow("Canny Edge of Jenny", edgeJenny);
	imshow("Canny Edge of Rice", edgeRice);
	// ��� �̹��� ���Ϸ� ����
	// (������Ʈ����/outputs ������ �̹� �ִٰ� ����)
	imwrite("./outputs/1_4_output_1.png", edgeJenny);
	imwrite("./outputs/1_4_output_2.png", edgeRice);

	waitKey();
}
