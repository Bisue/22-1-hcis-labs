#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;

// 0 - 입력 이미지의 gray-scaled 된 이미지 반환
Mat makeGrayScaled(const Mat& image) {
	Mat gray;
	// cv:cvtColor 함수로 BGR 채널 이미지를 gray-scaled 이미지로 변환
	cvtColor(image, gray, COLOR_BGR2GRAY);

	return gray;
}

// 1 - MORPH_ELLIPSE 형태의 11x11 kenel로 이미지 erosion
Mat erosionImage(const Mat& image)
{
	Mat erosion;

	// 원형(타원형)의 11x11이고 중앙이 anchor인 structuring element
	Mat kernel = cv::getStructuringElement(MORPH_ELLIPSE, Size(11, 11), Point(5, 5));

	// 만든 structuring element로 입력 이미지를 erode
	cv::erode(image, erosion, kernel);

	return erosion;
}

int main()
{
	// 원본 이미지 로드
	// (프로젝트폴더/images에 원본 이미지들이 있다고 가정)
	Mat originStuff = imread("./images/stuff_color.png");
	Mat originRice = imread("./images/rice.png");

	// =======================================================

	// 0. stuff_color, rice 이미지의 gray-scaled 이미지 준비
	Mat grayStuff = makeGrayScaled(originStuff);
	Mat grayRice = makeGrayScaled(originRice);

	// 입력 이미지 파일로 저장
	// (프로젝트폴더/outputs 폴더가 이미 있다고 가정)
	imwrite("./outputs/1_1_input_1.png", grayStuff);
	imwrite("./outputs/1_1_input_2.png", grayRice);

	// 1. 각 이미지의 erosion
	Mat erosionStuff = erosionImage(grayStuff);
	Mat erosionRice = erosionImage(grayRice);

	// =======================================================

	// 출력 이미지 확인
	imshow("erosion of stuff", erosionStuff);
	imshow("erosion of rice", erosionRice);
	// 출력 이미지 파일로 저장
	// (프로젝트폴더/outputs 폴더가 이미 있다고 가정)
	imwrite("./outputs/1_1_output_1.png", erosionStuff);
	imwrite("./outputs/1_1_output_2.png", erosionRice);

	waitKey();
}
