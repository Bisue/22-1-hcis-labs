//#include <iostream>
//#include <opencv2/opencv.hpp>
//#include "Geometry.h"
//#include "Pixel.h"
//
//using namespace cv;
//
//Mat rotate(const Mat& image, const int degree)
//{
//	CGeometry cg;
//
//	Mat rotated = cg.GS_affineRotate(image, degree, 1);
//
//	return rotated;
//}
//
//int main()
//{
//	Mat originBriefcase = imread("./images/briefcase.jpg");
//	imwrite("./outputs/3_4_input.png", originBriefcase);
//
//	// =======================================================
//
//	// roated
//	Mat rotated = originBriefcase.clone();
//	for (int times = 0; times < 5; times++) {
//		for (int i = 0; i < 12; i++) {
//			rotated = rotate(rotated, -30);
//		}
//	}
//
//	// subtract
//	CPixel cp;
//
//	Mat subtracted = cp.GS_subtract_image(originBriefcase, rotated);
//
//	// =======================================================
//
//	imshow("Subtracted Briefcase", subtracted);
//	imwrite("./outputs/3_4_output.png", subtracted);
//
//	waitKey();
//}
