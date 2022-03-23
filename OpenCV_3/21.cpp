//#include <iostream>
//#include <opencv2/opencv.hpp>
//#include "Color.h"
//
//using namespace cv;
//
//int main()
//{
//	// input 이미지 로드 (./images 디렉토리에 원본 컬러 이미지들이 있다고 가정)
//	Mat originJenny = imread("./images/jenny.jpg");
//	// input 이미지 저장 (./outputs 디렉토리가 있다고 가정)
//	imwrite("./outputs/2_1_input.png", originJenny);
//
//	// =======================================================
//
//	// 원본 이미지를 hsv로 변경
//	Mat hsv;
//	cvtColor(originJenny, hsv, COLOR_BGR2HSV);
//
//	// =======================================================
//
//	// output 이미지 디스플레이
//	imshow("HSV", hsv);
//	// output 이미지 저장 (./output 디렉토리가 있다고 가정)
//	imwrite("./outputs/2_1_output.png", hsv);
//
//	waitKey();
//}
