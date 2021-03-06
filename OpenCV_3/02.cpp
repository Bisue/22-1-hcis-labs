#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;

// 입력 이미지의 blurred 된 이미지를 만들어 반환
Mat makeBlurred(const Mat& image)
{
	// cv::GaussianBlur 함수를 사용해서, 15x15 크기의 Gaussian 마스크로
	// 이미지를 blurring 함
	Mat blurred;
	GaussianBlur(image, blurred, cv::Size(15, 15), 0, 0);

	return blurred;
}

int main()
{
	// input 이미지 로드 (이전에 만든 grayscaled 이미지 사용)
	// (흑백 이미지 명시)
	Mat grayLenna = imread("./outputs/0_1_output_1.png", 0);
	Mat grayJenny = imread("./outputs/0_1_output_2.png", 0);
	// input 이미지 저장 (./outputs 디렉토리가 있다고 가정)
	imwrite("./outputs/0_2_input_1.png", grayLenna);
	imwrite("./outputs/0_2_input_2.png", grayJenny);

	// =======================================================

	// 두 흑백 이미지 각각 blurred 된 이미지 생성
	Mat blurredLenna = makeBlurred(grayLenna);
	Mat blurredJenny = makeBlurred(grayJenny);

	// =======================================================

	// output 이미지 디스플레이
	imshow("Lenna", blurredLenna);
	imshow("Jenny", blurredJenny);
	// output 이미지 저장 (./output 디렉토리가 있다고 가정)
	imwrite("./outputs/0_2_output_1.png", blurredLenna);
	imwrite("./outputs/0_2_output_2.png", blurredJenny);

	waitKey();
}
