#include <iostream>
#include <opencv2/opencv.hpp>
#include "Edge.h"

using namespace cv;

// 입력 이미지에 Laplacian 필터를 적용하여 엣지 추출
Mat getEdgeLaplacian(const Mat& image)
{
	CEdge ce;

	// CEdge의 GS_laplacian_edge_Laplacian 함수를 사용하여
	// Laplacian 필터를 적용해 엣지 추출
	Mat edge = ce.GS_laplacian_edge_Laplacian(image);

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
	imwrite("./outputs/1_3_input_1.png", grayJenny);
	imwrite("./outputs/1_3_input_2.png", grayRice);

	// =======================================================

	// 각 이미지의 Laplacian 필터를 적용한 edge 추출
	Mat edgeJenny = getEdgeLaplacian(grayJenny);
	Mat edgeRice = getEdgeLaplacian(grayRice);

	// =======================================================

	// 출력 이미지 확인
	imshow("Laplacian Edge of Jenny", edgeJenny);
	imshow("Laplacian Edge of Rice", edgeRice);
	// 출력 이미지 파일로 저장
	// (프로젝트폴더/outputs 폴더가 이미 있다고 가정)
	imwrite("./outputs/1_3_output_1.png", edgeJenny);
	imwrite("./outputs/1_3_output_2.png", edgeRice);

	waitKey();
}
