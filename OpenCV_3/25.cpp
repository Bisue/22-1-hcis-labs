//#include <iostream>
//#include <opencv2/opencv.hpp>
//#include "Color.h"
//
//using namespace cv;
//
//int main()
//{
//	// input 이미지 로드 (이전에 만든 이미지 사용)
//	Mat hsv = imread("./outputs/2_4_output.png");
//	// input 이미지 저장 (./outputs 디렉토리가 있다고 가정)
//	imwrite("./outputs/2_5_input.png", hsv);
//
//	// =======================================================
//
//	// HSV' 이미지를 RGB로 변환
//	Mat converted;
//	cvtColor(hsv, converted, COLOR_HSV2BGR);
//
//	// =======================================================
//
//	// output 이미지 디스플레이
//	imshow("Converted RGB", converted);
//	// output 이미지 저장 (./output 디렉토리가 있다고 가정)
//	imwrite("./outputs/2_5_output.png", converted);
//
//	waitKey();
//}
