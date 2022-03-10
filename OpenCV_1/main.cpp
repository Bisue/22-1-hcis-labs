#include <iostream>
#include <opencv2/opencv.hpp>
#include "Pixel.h"

using namespace cv;

void solve1_addition(const Mat&, const Mat&);
void solve2_subtraction(const Mat&, const Mat&);
void solve3_blending(const Mat&, const Mat&, const double&);
void solve4_adjustment(const Mat&);

CPixel cpixel;

int main()
{
	Mat image1 = imread("./images/stuff_color_1.png");
	Mat image2 = imread("./images/stuff_color_2.png");

	cpixel = CPixel();

	solve4_adjustment(image1);
}

void solve1_addition(const Mat& image1, const Mat& image2)
{
	if (image1.empty() || image2.empty()) {
		std::cout << "Image load failed!" << std::endl;
		return;
	}

	Mat result = cpixel.GS_add_image(image1, image2);

	imshow("Output Image", result);

	waitKey();
}

void solve2_subtraction(const Mat& image1, const Mat& image2)
{
	if (image1.empty() || image2.empty()) {
		std::cout << "Image load failed!" << std::endl;
		return;
	}

	Mat result = cpixel.GS_subtract_image(image1, image2);

	imshow("Output Image", result);

	waitKey();
}

void solve3_blending(const Mat& image1, const Mat& image2, const double& alpha)
{
	if (image1.empty() || image2.empty()) {
		std::cout << "Image load failed!" << std::endl;
		return;
	}

	Mat result = cpixel.GS_blending_effect(image1, image2, alpha);

	imshow("Output Image", result);

	waitKey();
}

void solve4_adjustment(const Mat& image)
{
	if (image.empty()) {
		std::cout << "Image load failed!" << std::endl;
		return;
	}

	Mat grayScaled;
	cvtColor(image, grayScaled, COLOR_RGB2GRAY);

	Mat result = cpixel.GS_LUT_basic_contrast_brightness(grayScaled, 2, 50);

	imshow("Output Image", result);

	waitKey();
}