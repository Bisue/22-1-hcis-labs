#include <iostream>
#include <opencv2/opencv.hpp>
#include "Edge.h"
#include "Morph.h"

using namespace cv;

// MORPH_RECT 형태의 kernel로 이미지 erosion
Mat erosionImage(const Mat& image, const Size& size, const Point& anchor)
{
	Mat erosion;

	// 사각형의 3x3이고 중앙이 anchor인 structuring element
	Mat kernel = cv::getStructuringElement(MORPH_RECT, size, anchor);

	// 만든 structuring element로 입력 이미지를 erode
	cv::erode(image, erosion, kernel);

	return erosion;
}

// MORPH_RECT 형태의 kernel로 이미지 dilation
Mat dilationImage(const Mat& image, const Size& size, const Point& anchor)
{
	Mat dilation;

	// 사각형의 3x3이고 중앙이 anchor인 structuring element
	Mat kernel = cv::getStructuringElement(MORPH_RECT, size, anchor);

	// 만든 structuring element로 입력 이미지를 dilate
	cv::dilate(image, dilation, kernel);

	return dilation;
}

// 이미지 closing (dilation -> erosion)
Mat closingImage(const Mat& image, const Size& size, const Point& center)
{
	// 입력 이미지의 dilation
	Mat dilation = dilationImage(image, size, center);
	
	// erosion of dilation of 입력이미지 반환
	return erosionImage(dilation, size, center);
}

// 이미지 opening (erosion -> dilation)
Mat openingImage(const Mat& image, const Size& size, const Point& center)
{
	// 입력 이미지의 erosion
	Mat erosion = erosionImage(image, size, center);

	// dilation of erosion of 입력이미지 반환
	return dilationImage(erosion, size, center);
}

int main()
{
	// 입력 이미지(step 4 outputs) 로드
	Mat binaryStuff = imread("./outputs/1_4_output_1.png", 0);
	Mat binaryRice = imread("./outputs/1_4_output_2.png", 0);

	// 입력 이미지 파일로 저장
	imwrite("./outputs/2_1_input_1.png", binaryStuff);
	imwrite("./outputs/2_1_input_2.png", binaryRice);

	// =======================================================

	CEdge ce;
	CMorph cm;

	// 6. step 4 output 의 edge를 canny edge detector로 추출
	Mat cannyStuff = ce.GS_canny_edge_Canny(binaryStuff, 50, 100);
	Mat cannyRice = ce.GS_canny_edge_Canny(binaryRice, 50, 100);

	// 중간 출력 이미지 출력/저장
	imshow("stuff", cannyStuff);
	imshow("rice", cannyRice);
	imwrite("./outputs/2_1_output_1.png", cannyStuff);
	imwrite("./outputs/2_1_output_2.png", cannyRice);

	// 키 입력 대기
	waitKey();

	// 7. step 4 output 의 edge를 sobel edge detector로 추출
	Mat sobelStuff = ce.GS_sobel_edge(binaryStuff);
	Mat sobelRice = ce.GS_sobel_edge(binaryRice);

	// 중간 출력 이미지 출력/저장
	imshow("stuff", sobelStuff);
	imshow("rice", sobelRice);
	imwrite("./outputs/2_2_output_1.png", sobelStuff);
	imwrite("./outputs/2_2_output_2.png", sobelRice);

	// 키 입력 대기
	waitKey();

	Size kernelSize = Size(3, 3);
	Point kernelCenter = Point(1, 1);

	// 8. step 7 output(sobel dege) 이미지의 closing 이미지
	Mat closingStuff = closingImage(sobelStuff, kernelSize, kernelCenter);
	Mat closingRice = closingImage(sobelRice, kernelSize, kernelCenter);

	// 중간 출력 이미지 출력/저장
	imshow("stuff", closingStuff);
	imshow("rice", closingRice);
	imwrite("./outputs/2_3_output_1.png", closingStuff);
	imwrite("./outputs/2_3_output_2.png", closingRice);

	// 키 입력 대기
	waitKey();

	// 9. step 8 output(closing of sobel dege) 이미지의 opening 이미지
	Mat openingStuff = openingImage(closingStuff, kernelSize, kernelCenter);
	Mat openingRice = openingImage(closingRice, kernelSize, kernelCenter);

	// 최종 출력 이미지 출력/저장
	imshow("stuff", openingStuff);
	imshow("rice", openingRice);
	imwrite("./outputs/2_4_output_1.png", openingStuff);
	imwrite("./outputs/2_4_output_2.png", openingRice);

	waitKey();
}
