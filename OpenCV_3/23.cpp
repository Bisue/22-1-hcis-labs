//#include <iostream>
//#include <opencv2/opencv.hpp>
//#include "Pixel.h"
//
//using namespace cv;
//
//int main()
//{
//	// input 이미지 로드 (이전에 만든 이미지 사용)
//	// (흑백 이미지로 명시)
//	Mat v = imread("./outputs/2_2_output_3.png", 0);
//	// input 이미지 저장 (./outputs 디렉토리가 있다고 가정)
//	imwrite("./outputs/2_3_input.png", v);
//
//	// =======================================================
//
//	CPixel cp;
//
//	// hsv 중 v 채널에 대해서 equalization 실행
//	Mat equalizedV = cp.GS_histeq(v);
//
//	// =======================================================
//
//	// output 이미지 디스플레이
//	imshow("Equalized V", equalizedV);
//
//	// output 이미지 저장 (./output 디렉토리가 있다고 가정)
//	imwrite("./outputs/2_3_output.png", equalizedV);
//
//	waitKey();
//}
