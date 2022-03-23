//#include <iostream>
//#include <opencv2/opencv.hpp>
//#include "Pixel.h"
//
//using namespace cv;
//
//// 원본 흑백 이미지에서 blurred 된 이미지를 빼서
//// Edge 만 추출된 이미지를 만들어 반환
//Mat makeSubtracted(const Mat& original, const Mat& blurred)
//{
//	CPixel cp;
//
//	// original 이미지에서 blurred 이미지 뺀 결과를 반환
//	return cp.GS_subtract_image(original, blurred);
//}
//
//int main()
//{
//	// input 이미지 로드 (이전에 만든 이미지들 사용)
//	// (흑백 이미지 명시)
//	Mat grayLenna = imread("./outputs/0_1_output_1.png", 0);
//	Mat blurredLenna = imread("./outputs/0_2_output_1.png", 0);
//
//	Mat grayJenny = imread("./outputs/0_1_output_2.png", 0);
//	Mat blurredJenny = imread("./outputs/0_2_output_2.png", 0);
//
//	// input 이미지 저장 (./outputs 디렉토리가 있다고 가정)
//	imwrite("./outputs/0_3_input_1_1.png", grayLenna);
//	imwrite("./outputs/0_3_input_1_2.png", blurredLenna);
//
//	imwrite("./outputs/0_3_input_2_1.png", grayJenny);
//	imwrite("./outputs/0_3_input_2_2.png", blurredJenny);
//
//	// =======================================================
//
//	// 흑백 이미지에서 bluured 된 이미지를 뺌
//	// (edge 추출)
//	Mat edgeLenna = makeSubtracted(grayLenna, blurredLenna);
//	Mat edgeJenny = makeSubtracted(grayJenny, blurredJenny);
//
//	// =======================================================
//
//	// output 이미지 디스플레이
//	imshow("Lenna", edgeLenna);
//	imshow("Jenny", edgeJenny);
//	// output 이미지 저장 (./output 디렉토리가 있다고 가정)
//	imwrite("./outputs/0_3_output_1.png", edgeLenna);
//	imwrite("./outputs/0_3_output_2.png", edgeJenny);
//
//	waitKey();
//}
