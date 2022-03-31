#include <iostream>
#include <opencv2/opencv.hpp>
#include "Pixel.h"

using namespace cv;

int main()
{
	Mat imageA = imread("./outputs/2_2_output.png");
	Mat imageB = imread("./outputs/2_4_output.png");
	imwrite("./outputs/2_5_input_1.png", imageA);
	imwrite("./outputs/2_5_input_2.png", imageB);

	// =======================================================

	CPixel cp;

	Mat subtracted = cp.GS_subtract_image(imageA, imageB);

	// =======================================================

	imshow("Subtract Result Briefcase", subtracted);
	imwrite("./outputs/2_5_output.png", subtracted);

	waitKey();
}
