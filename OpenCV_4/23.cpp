#include <iostream>
#include <opencv2/opencv.hpp>
#include "Geometry.h"

using namespace cv;

Mat scale(const Mat& image, const double amount)
{
	CGeometry cg;

	Mat rotated = cg.GS_affineRotate(image, 0, amount);

	return rotated;
}

int main()
{
	Mat originBriefcase = imread("./images/briefcase.jpg");
	imwrite("./outputs/2_3_input.png", originBriefcase);

	// =======================================================

	Mat scaled = scale(originBriefcase, 1.5);

	// =======================================================

	imshow("Scaled Briefcase", scaled);
	imwrite("./outputs/2_3_output.png", scaled);

	waitKey();
}
