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
	Mat rotatedBriefcase = imread("./outputs/3_1_output.png");
	imwrite("./outputs/3_2_input.png", rotatedBriefcase);

	// =======================================================

	for (int i = 0; i < 11; i++) {
		rotatedBriefcase = rotate(rotatedBriefcase, -30);
	}

	// =======================================================

	imshow("Rotated Briefcase", rotatedBriefcase);
	imwrite("./outputs/3_2_output.png", rotatedBriefcase);

	waitKey();
}
