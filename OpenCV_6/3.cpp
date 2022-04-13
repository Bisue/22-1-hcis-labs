#include <iostream>
#include <opencv2/opencv.hpp>
#include "ImageAnalysis.h"
#include "Edge.h"

using namespace cv;

Mat customHoughTransform(const Mat& grayscaled)
{
	CEdge ce;
	
	Mat edge = ce.GS_canny_edge_Canny(grayscaled, 50, 100);

	std::vector<Vec2f> lines;
	HoughLines(edge, lines, 1, CV_PI / 180, 150);

	Mat result;
	cvtColor(grayscaled, result, COLOR_GRAY2BGR);

	for (int i = 0; i < lines.size(); i++)
	{
		Vec2f cur = lines[i];
		float rho = cur[0];
		float theta = cur[1];
		Point pt1, pt2;
		double a = cos(theta), b = sin(theta);
		double x0 = a * rho, y0 = b * rho;

		int BIG_NUMBER = 1000000;

		pt1.x = cvRound(x0 + BIG_NUMBER * (-b));
		pt1.y = cvRound(y0 + BIG_NUMBER * (a));
		pt2.x = cvRound(x0 - BIG_NUMBER * (-b));
		pt2.y = cvRound(y0 - BIG_NUMBER * (a));
		cv::line(result, pt1, pt2, Scalar(255, 0, 0), 1, 8);
	}

	return result;
}

int main()
{
	// �Է� �̹���(step 4 outputs) �ε�
	Mat binaryStuff = imread("./outputs/1_4_output_1.png", 0);
	Mat binaryRice = imread("./outputs/1_4_output_2.png", 0);

	// �Է� �̹��� ���Ϸ� ����
	imwrite("./outputs/3_1_input_1.png", binaryStuff);
	imwrite("./outputs/3_1_input_2.png", binaryRice);

	// =======================================================

	// 10. step 4 output �� line�� hough transform�� �̿��Ͽ� ����
	Mat lineStuff = customHoughTransform(binaryStuff);
	Mat lineRice = customHoughTransform(binaryRice);

	// �߰� ��� �̹��� ���/����
	imshow("stuff", lineStuff);
	imshow("rice", lineRice);
	imwrite("./outputs/3_1_output_1.png", lineStuff);
	imwrite("./outputs/3_1_output_2.png", lineRice);

	// Ű �Է� ���
	waitKey();
}
