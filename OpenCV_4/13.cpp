#include <iostream>
#include <opencv2/opencv.hpp>
#include "Edge.h"

using namespace cv;

// �Է� �̹����� Laplacian ���͸� �����Ͽ� ���� ����
Mat getEdgeLaplacian(const Mat& image)
{
	CEdge ce;

	// CEdge�� GS_laplacian_edge_Laplacian �Լ��� ����Ͽ�
	// Laplacian ���͸� ������ ���� ����
	Mat edge = ce.GS_laplacian_edge_Laplacian(image);

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
	imwrite("./outputs/1_3_input_1.png", grayJenny);
	imwrite("./outputs/1_3_input_2.png", grayRice);

	// =======================================================

	// �� �̹����� Laplacian ���͸� ������ edge ����
	Mat edgeJenny = getEdgeLaplacian(grayJenny);
	Mat edgeRice = getEdgeLaplacian(grayRice);

	// =======================================================

	// ��� �̹��� Ȯ��
	imshow("Laplacian Edge of Jenny", edgeJenny);
	imshow("Laplacian Edge of Rice", edgeRice);
	// ��� �̹��� ���Ϸ� ����
	// (������Ʈ����/outputs ������ �̹� �ִٰ� ����)
	imwrite("./outputs/1_3_output_1.png", edgeJenny);
	imwrite("./outputs/1_3_output_2.png", edgeRice);

	waitKey();
}
