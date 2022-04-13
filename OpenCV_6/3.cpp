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
	// 입력 이미지(step 4 outputs) 로드
	Mat binaryStuff = imread("./outputs/1_4_output_1.png", 0);
	Mat binaryRice = imread("./outputs/1_4_output_2.png", 0);

	// 입력 이미지 파일로 저장
	imwrite("./outputs/3_1_input_1.png", binaryStuff);
	imwrite("./outputs/3_1_input_2.png", binaryRice);

	// =======================================================

	// 10. step 4 output 의 line을 hough transform을 이용하여 추출
	Mat lineStuff = customHoughTransform(binaryStuff);
	Mat lineRice = customHoughTransform(binaryRice);

	// 중간 출력 이미지 출력/저장
	imshow("stuff", lineStuff);
	imshow("rice", lineRice);
	imwrite("./outputs/3_1_output_1.png", lineStuff);
	imwrite("./outputs/3_1_output_2.png", lineRice);

	// 키 입력 대기
	waitKey();
}
