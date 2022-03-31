#include <iostream>
#include <opencv2/opencv.hpp>
#include "Edge.h"

using namespace cv;

Mat getEdgeSobel(const Mat& image)
{
	CEdge ce;

	Mat edge = ce.GS_sobel_edge_Sobel(image, 2);

	return edge;
}

int main()
{
	Mat grayJenny = imread("./outputs/1_1_output_1.png", 0);
	Mat grayRice = imread("./outputs/1_1_output_2.png", 0);
	imwrite("./outputs/1_2_input_1.png", grayJenny);
	imwrite("./outputs/1_2_input_2.png", grayRice);

	// =======================================================

	Mat edgeJenny = getEdgeSobel(grayJenny);
	Mat edgeRice = getEdgeSobel(grayRice);

	// =======================================================

	imshow("Sobel Edge of Jenny", edgeJenny);
	imshow("Sobel Edge of Rice", edgeRice);
	imwrite("./outputs/1_2_output_1.png", edgeJenny);
	imwrite("./outputs/1_2_output_2.png", edgeRice);

	waitKey();
}
