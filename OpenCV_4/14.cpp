//#include <iostream>
//#include <opencv2/opencv.hpp>
//#include "Edge.h"
//
//using namespace cv;
//
//Mat getEdgeCanny(const Mat& image)
//{
//	CEdge ce;
//
//	Mat edge = ce.GS_canny_edge_Canny(image);
//
//	return edge;
//}
//
//int main()
//{
//	Mat grayJenny = imread("./outputs/1_1_output_1.png", 0);
//	Mat grayRice = imread("./outputs/1_1_output_2.png", 0);
//	imwrite("./outputs/1_4_input_1.png", grayJenny);
//	imwrite("./outputs/1_4_input_2.png", grayRice);
//
//	// =======================================================
//
//	Mat edgeJenny = getEdgeCanny(grayJenny);
//	Mat edgeRice = getEdgeCanny(grayRice);
//
//	// =======================================================
//
//	imshow("Canny Edge of Jenny", edgeJenny);
//	imshow("Canny Edge of Rice", edgeRice);
//	imwrite("./outputs/1_4_output_1.png", edgeJenny);
//	imwrite("./outputs/1_4_output_2.png", edgeRice);
//
//	waitKey();
//}
