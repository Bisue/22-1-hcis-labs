//#include <iostream>
//#include <opencv2/opencv.hpp>
//#include "Color.h"
//
//using namespace cv;
//
//int main()
//{
//	// input 이미지 로드 (이전에 만든 이미지 사용)
//	Mat hsv = imread("./outputs/2_1_output.png");
//	// input 이미지 저장 (./outputs 디렉토리가 있다고 가정)
//	imwrite("./outputs/2_2_input.png", hsv);
//
//	// =======================================================
//
//	// hsv 이미지를 h, s, v로 split
//	Mat channels[3];
//	split(hsv, channels);
//
//	Mat h = channels[0];
//	Mat s = channels[1];
//	Mat v = channels[2];
//
//	// =======================================================
//
//	// output 이미지 디스플레이
//	imshow("H", h);
//	imshow("S", s);
//	imshow("V", v);
//
//	// output 이미지 저장 (./output 디렉토리가 있다고 가정)
//	imwrite("./outputs/2_2_output_1.png", h);
//	imwrite("./outputs/2_2_output_2.png", s);
//	imwrite("./outputs/2_2_output_3.png", v);
//
//	waitKey();
//}
