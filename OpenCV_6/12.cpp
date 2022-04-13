//#include <iostream>
//#include <opencv2/opencv.hpp>
//
//using namespace cv;
//
//// 2 - MORPH_ELLIPSE 형태의 11x11 kenel로 이미지 dilation
//Mat dilationImage(const Mat& image)
//{
//	Mat dilation;
//
//	// 원형(타원형)의 11x11이고 중앙이 anchor인 structuring element
//	Mat kernel = cv::getStructuringElement(MORPH_ELLIPSE, Size(11, 11), Point(5, 5));
//
//	// 만든 structuring element로 입력 이미지를 dilate
//	cv::dilate(image, dilation, kernel);
//
//	return dilation;
//}
//
//int main()
//{
//	// 입력 이미지 로드
//	Mat erosionStuff = imread("./outputs/1_1_output_1.png");
//	Mat erosionRice = imread("./outputs/1_1_output_2.png");
//	// 입력 이미지 파일로 저장
//	// (프로젝트폴더/outputs 폴더가 이미 있다고 가정)
//	imwrite("./outputs/1_2_input_1.png", erosionStuff);
//	imwrite("./outputs/1_2_input_2.png", erosionRice);
//
//	// =======================================================
//
//	// 2. 전 단계에서 erosion된 각 이미지들의 dilation
//	Mat dilationStuff = dilationImage(erosionStuff);
//	Mat dilationRice = dilationImage(erosionRice);
//
//	// =======================================================
//
//	// 출력 이미지 확인
//	imshow("dilation of erosion of stuff", dilationStuff);
//	imshow("dilation of erosion of rice", dilationRice);
//	// 출력 이미지 파일로 저장
//	// (프로젝트폴더/outputs 폴더가 이미 있다고 가정)
//	imwrite("./outputs/1_2_output_1.png", dilationStuff);
//	imwrite("./outputs/1_2_output_2.png", dilationRice);
//
//	waitKey();
//}
