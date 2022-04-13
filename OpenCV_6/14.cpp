//#include <iostream>
//#include <opencv2/opencv.hpp>
//#include "Pixel.h"
//
//using namespace cv;
//
//int main()
//{
//	// 입력 이미지 로드
//	Mat subtractionStuff = imread("./outputs/1_3_output_1.png", 0);
//	Mat subtractionRice = imread("./outputs/1_3_output_2.png", 0);
//	// 입력 이미지 파일로 저장
//	// (프로젝트폴더/outputs 폴더가 이미 있다고 가정)
//	imwrite("./outputs/1_4_input_1.png", subtractionStuff);
//	imwrite("./outputs/1_4_input_2.png", subtractionRice);
//
//	// =======================================================
//
//	CPixel cp;
//
//	// 4. 1-3에서 빼기로 추출된 이미지에 otzu binarization 실행
//	Mat binaryStuff = cp.GS_threshold(subtractionStuff, 0, THRESH_BINARY | THRESH_OTSU);
//	Mat binaryRice = cp.GS_threshold(subtractionRice, 0, THRESH_BINARY | THRESH_OTSU);
//
//	// =======================================================
//
//	// 출력 이미지 확인
//	imshow("binary edge stuff", binaryStuff);
//	imshow("binary edge rice", binaryRice);
//	// 출력 이미지 파일로 저장
//	// (프로젝트폴더/outputs 폴더가 이미 있다고 가정)
//	imwrite("./outputs/1_4_output_1.png", binaryStuff);
//	imwrite("./outputs/1_4_output_2.png", binaryRice);
//
//	waitKey();
//}
