#include <iostream>
#include <opencv2/opencv.hpp>
#include "Edge.h"

using namespace cv;

// 입력 이미지에 대하여 수직/수평 Sobel 필터를 적용하여 엣지 추출 
Mat getEdgeSobel(const Mat& image)
{
	CEdge ce;

	// CEdge 클래스의 GS_sobel_edge_Sobel 함수를 사용하여
	// 수직/수평 엣지성분을 모두 검출
	Mat edge = ce.GS_sobel_edge_Sobel(image, 2);

	return edge;
}

int main()
{
	// 입력 이미지 로드
	// (흑백 이미지 명시하여 로드)
	Mat grayJenny = imread("./outputs/1_1_output_1.png", 0);
	Mat grayRice = imread("./outputs/1_1_output_2.png", 0);
	// 입력 이미지 파일로 저장
	// (프로젝트폴더/outputs 폴더가 이미 있다고 가정)
	imwrite("./outputs/1_2_input_1.png", grayJenny);
	imwrite("./outputs/1_2_input_2.png", grayRice);

	// =======================================================

	// 각 입력 이미지에 대해서 Sobel 필터를 사용해 엣지 추출
	Mat edgeJenny = getEdgeSobel(grayJenny);
	Mat edgeRice = getEdgeSobel(grayRice);

	// =======================================================

	// 출력 이미지 확인
	imshow("Sobel Edge of Jenny", edgeJenny);
	imshow("Sobel Edge of Rice", edgeRice);
	// 출력 이미지 파일로 저장
	// (프로젝트폴더/outputs 폴더가 이미 있다고 가정)
	imwrite("./outputs/1_2_output_1.png", edgeJenny);
	imwrite("./outputs/1_2_output_2.png", edgeRice);

	waitKey();
}
