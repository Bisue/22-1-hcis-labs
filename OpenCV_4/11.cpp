//#include <iostream>
//#include <opencv2/opencv.hpp>
//
//using namespace cv;
//
//Mat makeGrayScaled(const Mat& image)
//{
//	Mat gray;
//	cvtColor(image, gray, COLOR_BGR2GRAY);
//	return gray;
//}
//
//int main()
//{
//	Mat originJenny = imread("./images/jenny.jpg");
//	Mat originRice = imread("./images/rice.png");
//	imwrite("./outputs/1_1_input_1.png", originJenny);
//	imwrite("./outputs/1_1_input_2.png", originRice);
//
//	// =======================================================
//
//	Mat grayJenny = makeGrayScaled(originJenny);
//	Mat grayRice = makeGrayScaled(originRice);
//
//	// =======================================================
//
//	imshow("Grayscaled Jenny", grayJenny);
//	imshow("Grayscaled Rice", grayRice);
//	imwrite("./outputs/1_1_output_1.png", grayJenny);
//	imwrite("./outputs/1_1_output_2.png", grayRice);
//
//	waitKey();
//}
