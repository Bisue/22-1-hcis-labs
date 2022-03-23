#include <iostream>
#include <opencv2/opencv.hpp>
#include "Pixel.h"

using namespace cv;

int main()
{
	// input 이미지 로드 (이전에 만든 이미지 사용)
	// (흑백 이미지로 명시)
	Mat R = imread("./outputs/1_1_output_1.png", 0);
	Mat G = imread("./outputs/1_1_output_2.png", 0);
	Mat B = imread("./outputs/1_1_output_3.png", 0);
	// input 이미지 저장 (./outputs 디렉토리가 있다고 가정)
	imwrite("./outputs/1_2_input_1.png", R);
	imwrite("./outputs/1_2_input_2.png", G);
	imwrite("./outputs/1_2_input_3.png", B);

	// =======================================================

	CPixel cp;

	// R, G, B 각 채널에 대해서 equalization 실행
	Mat equalizedR = cp.GS_histeq(R);
	Mat equalizedG = cp.GS_histeq(G);
	Mat equalizedB = cp.GS_histeq(B);

	// =======================================================

	// output 이미지 디스플레이
	imshow("Equalized R", equalizedR);
	imshow("Equalized G", equalizedG);
	imshow("Equalized B", equalizedB);
	// output 이미지 저장 (./output 디렉토리가 있다고 가정)
	imwrite("./outputs/1_2_output_1.png", equalizedR);
	imwrite("./outputs/1_2_output_2.png", equalizedG);
	imwrite("./outputs/1_2_output_3.png", equalizedB);

	waitKey();
}
