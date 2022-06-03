#include <iostream>
#include <opencv2/opencv.hpp>
#include "Filter.h"

using namespace cv;

// 입력 이미지의 흑백 이미지를 만들어 반환
Mat makeGrayScaled(const Mat& image)
{
	Mat gray;

	// cv::cvtColor 함수를 사용해 BGR 컬러이미지에서 GRAY이미지로 변경
	cvtColor(image, gray, COLOR_BGR2GRAY);

	return gray;
}

int main()
{
	// 원본 이미지 로드
	// (프로젝트폴더/images에 원본 이미지들이 있다고 가정)
	Mat originJenny = imread("./images/jenny.jpg");
	Mat originRice = imread("./images/rice.png");
	// 입력 이미지 파일로 저장
	// (프로젝트폴더/outputs 폴더가 이미 있다고 가정)
	imwrite("./outputs/1_1_input_1.png", originJenny);
	imwrite("./outputs/1_1_input_2.png", originRice);

	// =======================================================

	// 각 입력 이미지의 흑백 이미지를 생성
	Mat grayJenny = makeGrayScaled(originJenny);
	Mat grayRice = makeGrayScaled(originRice);

	CFilter cp;

	int cnt = 0;
	Mat blurred = grayJenny;
	while (true) {
		blurred = cp.GS_blurring(blurred , CV_BLUR, 1);
		std::cout << cnt++ << std::endl;
		imshow("Blurred", blurred);
		if (waitKey(1) == 13) {
			break;
		}
	}

	// =======================================================

	//// 출력 이미지 확인
	//imshow("Grayscaled Jenny", grayJenny);
	//imshow("Grayscaled Rice", grayRice);
	//// 출력 이미지 파일로 저장
	//// (프로젝트폴더/outputs 폴더가 이미 있다고 가정)
	//imwrite("./outputs/1_1_output_1.png", grayJenny);
	//imwrite("./outputs/1_1_output_2.png", grayRice);

	waitKey();
}
