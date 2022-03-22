#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;

Mat makeGrayScaled(const Mat& image) {
	Mat gray;
	cvtColor(image, gray, COLOR_BGR2GRAY);

	return gray;
}

int main()
{
	Mat originLenna = imread("./images/lenna.jpg");
	Mat originJenny = imread("./images/jenny.jpg");

	Mat grayLenna = makeGrayScaled(originLenna);
	Mat grayJenny = makeGrayScaled(originJenny);

	imshow("Lenna", grayLenna);
	imshow("Jenny", grayJenny);
}
