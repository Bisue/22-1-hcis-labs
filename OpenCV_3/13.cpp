//#include <iostream>
//#include <opencv2/opencv.hpp>
//#include "Color.h"
//
//using namespace cv;
//
//int main()
//{
//	// input 이미지 로드 (이전에 만든 이미지 사용)
//	// (1채널 이미지로 명시)
//	Mat equalizedR = imread("./outputs/1_2_output_1.png", 0);
//	Mat equalizedG = imread("./outputs/1_2_output_2.png", 0);
//	Mat equalizedB = imread("./outputs/1_2_output_3.png", 0);
//	// input 이미지 저장 (./outputs 디렉토리가 있다고 가정)
//	imwrite("./outputs/1_3_input_1.png", equalizedR);
//	imwrite("./outputs/1_3_input_2.png", equalizedG);
//	imwrite("./outputs/1_3_input_3.png", equalizedB);
//
//	// =======================================================
//
//	CColor cc;
//
//	// R, G, B 채널 이미지 배열 (B-G-R 순서)
//	Mat rgb[3] = { equalizedB, equalizedG, equalizedR };
//
//	// R, G, B 각 채널을 합쳐 하나의 컬러 이미지로 만듬
//	Mat color = cc.GS_compositeRGB(rgb);
//
//	// =======================================================
//
//	// output 이미지 디스플레이
//	imshow("Equalized R", color);
//	// output 이미지 저장 (./output 디렉토리가 있다고 가정)
//	imwrite("./outputs/1_3_output.png", color);
//
//	waitKey();
//}
