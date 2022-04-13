//#include <iostream>
//#include <opencv2/opencv.hpp>
//#include "ImageAnalysis.h"
//
//using namespace cv;
//
//int main()
//{
//	// 입력 이미지 로드
//	Mat binaryStuff = imread("./outputs/1_4_output_1.png", 0);
//	Mat binaryRice = imread("./outputs/1_4_output_2.png", 0);
//	// 입력 이미지 파일로 저장
//	// (프로젝트폴더/outputs 폴더가 이미 있다고 가정)
//	imwrite("./outputs/1_5_input_1.png", binaryStuff);
//	imwrite("./outputs/1_5_input_2.png", binaryRice);
//
//	// =======================================================
//
//	CImageAnalysis cia;
//
//	// 5. 이진화된 각 이미지들을 GS_findContours 함수를 사용해 외곽선을 찾아 labeling
//	Mat labeledStuff = cia.GS_findContours(binaryStuff);
//	Mat labeledRice = cia.GS_findContours(binaryRice);
//
//	// =======================================================
//
//	// 출력 이미지 확인
//	imshow("labeled stuff", labeledStuff);
//	imshow("labeled rice", labeledRice);
//	// 출력 이미지 파일로 저장
//	// (프로젝트폴더/outputs 폴더가 이미 있다고 가정)
//	imwrite("./outputs/1_5_output_1.png", labeledStuff);
//	imwrite("./outputs/1_5_output_2.png", labeledRice);
//
//	waitKey();
//}
