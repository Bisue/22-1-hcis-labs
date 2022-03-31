//#include <iostream>
//#include <opencv2/opencv.hpp>
//#include "Pixel.h"
//
//using namespace cv;
//
//int main()
//{
//	Mat imageA = imread("./images/briefcase.jpg");
//	Mat imageB = imread("./outputs/3_2_output.png");
//	imwrite("./outputs/3_3_input_1.png", imageA);
//	imwrite("./outputs/3_3_input_2.png", imageB);
//
//	// =======================================================
//
//	CPixel cp;
//
//	Mat subtracted = cp.GS_subtract_image(imageA, imageB);
//
//	// =======================================================
//
//	imshow("Subtract Result Briefcase", subtracted);
//	imwrite("./outputs/3_3_output.png", subtracted);
//
//	waitKey();
//}
