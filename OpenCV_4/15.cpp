//#include <iostream>
//#include <opencv2/opencv.hpp>
//#include "Edge.h"
//#include "Filter.h"
//
//using namespace cv;
//
//// 입력 이미지에 대하여 Gaussian 필터를 적용 후,
//// 그 결과에 Laplacian 필터로 엣지를 추출하여 반환
//Mat getLaplacianOfGaussian(const Mat& image)
//{
//	CEdge ce;
//	CFilter cf;
//
//	// 입력 이미지에 Gaussian 필터를 적용
//	Mat gaussian = cf.GS_gaussian_smoothing_filtering(image, 2);
//	// Gaussian 필터가 적용된 이미지에 Laplacian 필터를 적용해 엣지 추출
//	Mat laplacian = ce.GS_laplacian_edge_Laplacian(gaussian);
//
//	return laplacian;
//}
//
//int main()
//{
//	// 입력 이미지 로드
//	// (흑백 이미지 명시하여 로드)
//	Mat grayJenny = imread("./outputs/1_1_output_1.png", 0);
//	Mat grayRice = imread("./outputs/1_1_output_2.png", 0);
//	// 입력 이미지 파일로 저장
//	// (프로젝트폴더/outputs 폴더가 이미 있다고 가정)
//	imwrite("./outputs/1_5_input_1.png", grayJenny);
//	imwrite("./outputs/1_5_input_2.png", grayRice);
//
//	// =======================================================
//
//	// 각 이미지의 Laplacian edge of Gaussian 추출
//	Mat lofgJenny = getLaplacianOfGaussian(grayJenny);
//	Mat lofgRice = getLaplacianOfGaussian(grayRice);
//
//	// =======================================================
//
//	// 출력 이미지 확인
//	imshow("Laplacian of Gaussian of Jenny", lofgJenny);
//	imshow("Laplacian of Gaussian of Rice", lofgRice);
//	// 출력 이미지 파일로 저장
//	// (프로젝트폴더/outputs 폴더가 이미 있다고 가정)
//	imwrite("./outputs/1_5_output_1.png", lofgJenny);
//	imwrite("./outputs/1_5_output_2.png", lofgRice);
//
//	waitKey();
//}
