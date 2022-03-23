#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;

// 이미지의 흑백 이미지 반환
Mat makeGrayScaled(const Mat& image) {
	Mat gray;
	// cv::cvtColor를 이용해 BGR에서 GRAY이미지로 변환
	cvtColor(image, gray, COLOR_BGR2GRAY);

	return gray;
}

int main()
{
	// 원본 이미지 저장 (./images 디렉토리에 이미지들이 있다고 가정)
	Mat originLenna = imread("./images/lenna.png");
	Mat originJenny = imread("./images/jenny.jpg");
	// 원본 이미지 저장 (./outputs 디렉토리가 있다고 가정)
	imwrite("./outputs/1_1_input_1.png", originLenna);
	imwrite("./outputs/1_1_input_2.png", originJenny);

	// 이미지 각각 흑백 변환
	Mat grayLenna = makeGrayScaled(originLenna);
	Mat grayJenny = makeGrayScaled(originJenny);

	// 결과 이미지 디스플레이
	imshow("Lenna", grayLenna);
	imshow("Jenny", grayJenny);
	// 결과 이미지 저장 (./output 디렉토리가 있다고 가정)
	imwrite("./outputs/1_1_output_1.png", grayLenna);
	imwrite("./outputs/1_1_output_2.png", grayJenny);

	waitKey();
}
