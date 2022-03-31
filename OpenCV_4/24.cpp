#include <iostream>
#include <opencv2/opencv.hpp>
#include "Geometry.h"

using namespace cv;

Mat rotate(const Mat& image, const int degree)
{
	CGeometry cg;

	Mat rotated = cg.GS_affineRotate(image, degree, 1);

	return rotated;
}

int main()
{
	Mat originBriefcase = imread("./outputs/2_3_output.png");
	imwrite("./outputs/2_4_input.png", originBriefcase);

	// =======================================================

	Mat rotated = rotate(originBriefcase, -45);

	// =======================================================

	imshow("Rotated of Scaled Briefcase", rotated);
	imwrite("./outputs/2_4_output.png", rotated);

	waitKey();
}
