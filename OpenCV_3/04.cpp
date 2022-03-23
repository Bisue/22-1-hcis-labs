#include <iostream>
#include <opencv2/opencv.hpp>
#include "Pixel.h"

using namespace cv;

// 원본 흑백 이미지에 추출된 edge 이미지를 더해
// image sharpning 을 수행
Mat makeAdded(const Mat& original, const Mat& edge)
{
	CPixel cp;

	// original 이미지에 edge 이미지 더한 결과를 반환
	return cp.GS_add_image(original, edge);
}

int main()
{
	// input 이미지 로드 (0-1, 0-2 에서 만든 이미지들 사용)
	Mat grayLenna = imread("./outputs/0_1_output_1.png");
	Mat edgeLenna = imread("./outputs/0_3_output_1.png");

	Mat grayJenny = imread("./outputs/0_1_output_2.png");
	Mat edgeJenny = imread("./outputs/0_3_output_2.png");

	// input 이미지 저장 (./outputs 디렉토리가 있다고 가정)
	imwrite("./outputs/0_4_input_1_1.png", grayLenna);
	imwrite("./outputs/0_4_input_1_2.png", edgeLenna);

	imwrite("./outputs/0_4_input_2_1.png", grayJenny);
	imwrite("./outputs/0_4_input_2_2.png", edgeJenny);

	// =======================================================

	// 흑백 이미지, 추출된 edge 이미지를 더함
	Mat sharpnedLenna = makeAdded(grayLenna, edgeLenna);
	Mat sharpnedJenny = makeAdded(grayJenny, edgeJenny);

	// =======================================================

	// output 이미지 디스플레이
	imshow("Lenna", sharpnedLenna);
	imshow("Jenny", sharpnedJenny);
	// output 이미지 저장 (./output 디렉토리가 있다고 가정)
	imwrite("./outputs/0_4_output_1.png", sharpnedLenna);
	imwrite("./outputs/0_4_output_2.png", sharpnedJenny);

	waitKey();
}
