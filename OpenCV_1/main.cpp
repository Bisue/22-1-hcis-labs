#include <iostream>
#include <opencv2/opencv.hpp>
#include "Pixel.h"

using namespace cv;

CPixel cpixel;

int main()
{
	Mat image1 = imread("./images/stuff_color_1.png");
	Mat image2 = imread("./images/stuff_color_2.png");

	cpixel = CPixel();

	solve1_1(image1, image2);
}

void solve1_1(Mat image1, Mat image2)
{
	if (image1.empty() || image2.empty()) {
		std::cout << "Image load failed!" << std::endl;
	}

	Mat result = cpixel.GS_add_image(image1, image2);

	imshow("image1", result);

	waitKey();
}

void solve1_2(Mat image1, Mat image2)
{
	if (image1.empty() || image2.empty()) {
		std::cout << "Image load failed!" << std::endl;
	}

	Mat result = cpixel.GS_add_image(image1, image2);

	imshow("image1", result);

	waitKey();
}

void solve2_1(Mat image1, Mat image2)
{
	if (image1.empty() || image2.empty()) {
		std::cout << "Image load failed!" << std::endl;
	}

	Mat result = cpixel.GS_subtract_image(image1, image2);

	imshow("image1", result);

	waitKey();
}

void solve2_2(Mat image1, Mat image2)
{
	if (image1.empty() || image2.empty()) {
		std::cout << "Image load failed!" << std::endl;
	}

	Mat result = cpixel.GS_subtract_image(image1, image2);

	imshow("image1", result);

	waitKey();
}

void solve3_1(Mat image1, Mat image2)
{
	if (image1.empty() || image2.empty()) {
		std::cout << "Image load failed!" << std::endl;
	}

	Mat result = cpixel.GS_blending_effect(image1, image2, 0);

	imshow("image1", result);

	waitKey();
}