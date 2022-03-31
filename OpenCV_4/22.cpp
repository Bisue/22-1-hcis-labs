#include <iostream>
#include <opencv2/opencv.hpp>
#include "Geometry.h"

using namespace cv;

Mat scale(const Mat& image, const double amount)
{
	CGeometry cg;

	Mat scaled = cg.GS_affineRotate(image, 0, amount);

	return scaled;
}

int main()
{
	Mat originBriefcase = imread("./outputs/2_1_output.png");
	imwrite("./outputs/2_2_input.png", originBriefcase);

	// =======================================================

	Mat scaled = scale(originBriefcase, 1.5);

	// =======================================================

	imshow("Scaled of Rotated Briefcase", scaled);
	imwrite("./outputs/2_2_output.png", scaled);

	waitKey();
}
