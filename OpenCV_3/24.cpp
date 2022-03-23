//#include <iostream>
//#include <opencv2/opencv.hpp>
//#include "Color.h"
//
//using namespace cv;
//
//int main()
//{
//	// input 이미지 로드 (이전에 만든 이미지 사용)
//	// (흑백 이미지로 명시)
//	Mat h = imread("./outputs/2_2_output_1.png", 0);
//	Mat s = imread("./outputs/2_2_output_2.png", 0);
//	Mat equalizedV = imread("./outputs/2_3_output.png", 0);
//	// input 이미지 저장 (./outputs 디렉토리가 있다고 가정)
//	imwrite("./outputs/2_4_input_1.png", h);
//	imwrite("./outputs/2_4_input_2.png", s);
//	imwrite("./outputs/2_4_input_3.png", equalizedV);
//
//	// =======================================================
//
//	CColor cc;
//
//	// H, S, V 채널 이미지 배열
//	Mat hsv[3] = { h, s, equalizedV };
//
//	// H, S, V 각 채널을 합쳐 하나의 컬러 이미지로 만듬
//	Mat color;
//	merge(hsv, 3, color);
//
//	// =======================================================
//
//	// output 이미지 디스플레이
//	imshow("HSV'", color);
//	// output 이미지 저장 (./output 디렉토리가 있다고 가정)
//	imwrite("./outputs/2_4_output.png", color);
//
//	waitKey();
//}
