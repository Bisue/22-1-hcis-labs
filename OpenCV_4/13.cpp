//#include <iostream>
//#include <opencv2/opencv.hpp>
//#include "Edge.h"
//
//using namespace cv;
//
//Mat getEdgeLaplacian(const Mat& image)
//{
//	CEdge ce;
//
//	Mat edge = ce.GS_laplacian_edge_Laplacian(image);
//
//	return edge;
//}
//
//int main()
//{
//	Mat grayJenny = imread("./outputs/1_1_output_1.png", 0);
//	Mat grayRice = imread("./outputs/1_1_output_2.png", 0);
//	imwrite("./outputs/1_3_input_1.png", grayJenny);
//	imwrite("./outputs/1_3_input_2.png", grayRice);
//
//	// =======================================================
//
//	Mat edgeJenny = getEdgeLaplacian(grayJenny);
//	Mat edgeRice = getEdgeLaplacian(grayRice);
//
//	// =======================================================
//
//	imshow("Laplacian Edge of Jenny", edgeJenny);
//	imshow("Laplacian Edge of Rice", edgeRice);
//	imwrite("./outputs/1_3_output_1.png", edgeJenny);
//	imwrite("./outputs/1_3_output_2.png", edgeRice);
//
//	waitKey();
//}
