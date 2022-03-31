//#include <iostream>
//#include <opencv2/opencv.hpp>
//#include "Edge.h"
//#include "Filter.h"
//
//using namespace cv;
//
//// �Է� �̹����� ���Ͽ� Gaussian ���͸� ���� ��,
//// �� ����� Laplacian ���ͷ� ������ �����Ͽ� ��ȯ
//Mat getLaplacianOfGaussian(const Mat& image)
//{
//	CEdge ce;
//	CFilter cf;
//
//	// �Է� �̹����� Gaussian ���͸� ����
//	Mat gaussian = cf.GS_gaussian_smoothing_filtering(image, 2);
//	// Gaussian ���Ͱ� ����� �̹����� Laplacian ���͸� ������ ���� ����
//	Mat laplacian = ce.GS_laplacian_edge_Laplacian(gaussian);
//
//	return laplacian;
//}
//
//int main()
//{
//	// �Է� �̹��� �ε�
//	// (��� �̹��� ����Ͽ� �ε�)
//	Mat grayJenny = imread("./outputs/1_1_output_1.png", 0);
//	Mat grayRice = imread("./outputs/1_1_output_2.png", 0);
//	// �Է� �̹��� ���Ϸ� ����
//	// (������Ʈ����/outputs ������ �̹� �ִٰ� ����)
//	imwrite("./outputs/1_5_input_1.png", grayJenny);
//	imwrite("./outputs/1_5_input_2.png", grayRice);
//
//	// =======================================================
//
//	// �� �̹����� Laplacian edge of Gaussian ����
//	Mat lofgJenny = getLaplacianOfGaussian(grayJenny);
//	Mat lofgRice = getLaplacianOfGaussian(grayRice);
//
//	// =======================================================
//
//	// ��� �̹��� Ȯ��
//	imshow("Laplacian of Gaussian of Jenny", lofgJenny);
//	imshow("Laplacian of Gaussian of Rice", lofgRice);
//	// ��� �̹��� ���Ϸ� ����
//	// (������Ʈ����/outputs ������ �̹� �ִٰ� ����)
//	imwrite("./outputs/1_5_output_1.png", lofgJenny);
//	imwrite("./outputs/1_5_output_2.png", lofgRice);
//
//	waitKey();
//}
