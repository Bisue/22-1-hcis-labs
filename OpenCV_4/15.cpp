//#include <iostream>
//#include <opencv2/opencv.hpp>
//#include "Edge.h"
//#include "Filter.h"
//
//using namespace cv;
//
//Mat getLaplacianOfGaussian(const Mat& image)
//{
//	CEdge ce;
//	CFilter cf;
//
//	Mat gaussian = cf.GS_gaussian_smoothing_filtering(image, 2);
//
//	Mat laplacian = ce.GS_laplacian_edge_Laplacian(gaussian);
//
//	return laplacian;
//}
//
//int main()
//{
//	Mat grayJenny = imread("./outputs/1_1_output_1.png", 0);
//	Mat grayRice = imread("./outputs/1_1_output_2.png", 0);
//	imwrite("./outputs/1_5_input_1.png", grayJenny);
//	imwrite("./outputs/1_5_input_2.png", grayRice);
//
//	// =======================================================
//
//	Mat lofgJenny = getLaplacianOfGaussian(grayJenny);
//	Mat lofgRice = getLaplacianOfGaussian(grayRice);
//
//	// =======================================================
//
//	imshow("Laplacian of Gaussian of Jenny", lofgJenny);
//	imshow("Laplacian of Gaussian of Rice", lofgRice);
//	imwrite("./outputs/1_5_output_1.png", lofgJenny);
//	imwrite("./outputs/1_5_output_2.png", lofgRice);
//
//	waitKey();
//}
