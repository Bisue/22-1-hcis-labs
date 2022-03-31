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
	Mat originBriefcase = imread("./images/briefcase.jpg");
	imwrite("./outputs/3_1_input.png", originBriefcase);

	// =======================================================

	Mat rotated = rotate(originBriefcase, -30);

	// =======================================================

	imshow("Rotated Briefcase", rotated);
	imwrite("./outputs/3_1_output.png", rotated);

	waitKey();
}
