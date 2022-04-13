#include <iostream>
#include <opencv2/opencv.hpp>
#include "Pixel.h"
#include "ImageAnalysis.h"

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

// 2 - MORPH_ELLIPSE 형태의 11x11 kenel로 이미지 dilation
Mat dilationImage(const Mat& image)
{
	Mat dilation;

	// 원형(타원형)의 11x11이고 중앙이 anchor인 structuring element
	Mat kernel = cv::getStructuringElement(MORPH_ELLIPSE, Size(11, 11), Point(5, 5));

	// 만든 structuring element로 입력 이미지를 dilate
	cv::dilate(image, dilation, kernel);

	return dilation;
}


int main()
{
	// 원본 이미지 로드
	// (프로젝트폴더/images에 원본 이미지들이 있다고 가정)
	Mat originStuff = imread("./images/stuff_color.png");
	Mat originRice = imread("./images/rice.png");

	// =======================================================

	CPixel cp;
	CImageAnalysis cia;

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

	// 중간 출력 이미지 저장
	imwrite("./outputs/1_1_output_1.png", erosionStuff);
	imwrite("./outputs/1_1_output_2.png", erosionRice);

	// 2. 전 단계에서 erosion된 각 이미지들의 dilation
	Mat dilationStuff = dilationImage(erosionStuff);
	Mat dilationRice = dilationImage(erosionRice);

	// 중간 출력 이미지 저장
	imwrite("./outputs/1_2_output_1.png", dilationStuff);
	imwrite("./outputs/1_2_output_2.png", dilationRice);

	// 3. 원본(gray-scaled) 이미지에서 dilation of erosion 이미지를 뺌
	Mat subtractStuff = cp.GS_subtract_image(grayStuff, erosionStuff);
	Mat subtractRice = cp.GS_subtract_image(grayRice, erosionRice);

	// 중간 출력 이미지 저장
	imwrite("./outputs/1_3_output_1.png", subtractStuff);
	imwrite("./outputs/1_3_output_2.png", subtractRice);

	// 4. 1-3에서 빼기로 추출된 이미지에 otzu binarization 실행
	Mat binaryStuff = cp.GS_threshold(subtractStuff, 0, THRESH_BINARY | THRESH_OTSU);
	Mat binaryRice = cp.GS_threshold(subtractRice, 0, THRESH_BINARY | THRESH_OTSU);

	// 중간 출력 이미지 저장
	imwrite("./outputs/1_4_output_1.png", binaryStuff);
	imwrite("./outputs/1_4_output_2.png", binaryRice);

	// 5. 이진화된 각 이미지들을 GS_findContours 함수를 사용해 외곽선을 찾아 labeling
	Mat labeledStuff = cia.GS_findContours(binaryStuff);
	Mat labeledRice = cia.GS_findContours(binaryRice);

	// =======================================================

	// 최종 출력 이미지 확인
	imshow("erosion of stuff", labeledStuff);
	imshow("erosion of rice", labeledRice);
	// 최종 출력 이미지 파일로 저장
	// (프로젝트폴더/outputs 폴더가 이미 있다고 가정)
	imwrite("./outputs/1_5_output_1.png", labeledStuff);
	imwrite("./outputs/1_5_output_2.png", labeledRice);

	waitKey();
}
