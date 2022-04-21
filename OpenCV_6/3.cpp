//#include <iostream>
//#include <opencv2/opencv.hpp>
//#include "ImageAnalysis.h"
//#include "Edge.h"
//
//using namespace cv;
//
//Mat customHoughTransform(const Mat& grayscaled)
//{
//	CEdge ce;
//	
//	// 이미지의 edge 추출
//	Mat edge = ce.GS_canny_edge_Canny(grayscaled, 50, 100);
//
//	// cv::HoughLines 함수를 통해 edge 이미지의 line 성분 찾기
//	std::vector<Vec2f> lines;
//	HoughLines(edge, lines, 1, CV_PI / 180, 150);
//
//	// 찾아진 line을 그려서 반환할 이미지
//	Mat result;
//	cvtColor(grayscaled, result, COLOR_GRAY2BGR);
//
//	// 찾아진 line 들을 순환하며 result에 그림
//	for (int i = 0; i < lines.size(); i++)
//	{
//		// 현재 line의 rho, theta 변수화
//		Vec2f cur = lines[i];
//		float rho = cur[0];
//		float theta = cur[1];
//
//		// 선을 그리기 위한 두개의 점
//		Point pt1, pt2;
//		// 극좌표의 직선 방정식을 통해 x0와 y0를 구함
//		double a = cos(theta), b = sin(theta);
//		double x0 = a * rho, y0 = b * rho;
//
//		// 구하려는 직선 위의 두 점을 찾아내기 위해서
//		// (x0, y0)를 기준으로 BIG_NUMBER 만큼 양쪽으로 떨어진
//		// 2개의 pt1, pt2를 구함.
//		int BIG_NUMBER = 1000;
//		pt1.x = cvRound(x0 + BIG_NUMBER * (-b));
//		pt1.y = cvRound(y0 + BIG_NUMBER * (a));
//		pt2.x = cvRound(x0 - BIG_NUMBER * (-b));
//		pt2.y = cvRound(y0 - BIG_NUMBER * (a));
//
//		// 구한 pt1, pt2를 잇는 파란색 직선을 그림
//		cv::line(result, pt1, pt2, Scalar(255, 0, 0), 1, 8);
//	}
//
//	// 선이 모두 그려진 result를 반환
//	return result;
//}
//
//int main()
//{
//	// 입력 이미지(step 4 outputs) 로드
//	Mat binaryStuff = imread("./outputs/1_4_output_1.png", 0);
//	Mat binaryRice = imread("./outputs/1_4_output_2.png", 0);
//
//	// 입력 이미지 파일로 저장
//	imwrite("./outputs/3_1_input_1.png", binaryStuff);
//	imwrite("./outputs/3_1_input_2.png", binaryRice);
//
//	// =======================================================
//
//	// 10. step 4 output 의 line을 hough transform을 이용하여 추출
//	Mat lineStuff = customHoughTransform(binaryStuff);
//	Mat lineRice = customHoughTransform(binaryRice);
//
//	// 중간 출력 이미지 출력/저장
//	imshow("stuff", lineStuff);
//	imshow("rice", lineRice);
//	imwrite("./outputs/3_1_output_1.png", lineStuff);
//	imwrite("./outputs/3_1_output_2.png", lineRice);
//
//	// 키 입력 대기
//	waitKey();
//}
