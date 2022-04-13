//#include <iostream>
//#include <opencv2/opencv.hpp>
//
//using namespace cv;
//
//// 2 - MORPH_ELLIPSE ������ 11x11 kenel�� �̹��� dilation
//Mat dilationImage(const Mat& image)
//{
//	Mat dilation;
//
//	// ����(Ÿ����)�� 11x11�̰� �߾��� anchor�� structuring element
//	Mat kernel = cv::getStructuringElement(MORPH_ELLIPSE, Size(11, 11), Point(5, 5));
//
//	// ���� structuring element�� �Է� �̹����� dilate
//	cv::dilate(image, dilation, kernel);
//
//	return dilation;
//}
//
//int main()
//{
//	// �Է� �̹��� �ε�
//	Mat erosionStuff = imread("./outputs/1_1_output_1.png");
//	Mat erosionRice = imread("./outputs/1_1_output_2.png");
//	// �Է� �̹��� ���Ϸ� ����
//	// (������Ʈ����/outputs ������ �̹� �ִٰ� ����)
//	imwrite("./outputs/1_2_input_1.png", erosionStuff);
//	imwrite("./outputs/1_2_input_2.png", erosionRice);
//
//	// =======================================================
//
//	// 2. �� �ܰ迡�� erosion�� �� �̹������� dilation
//	Mat dilationStuff = dilationImage(erosionStuff);
//	Mat dilationRice = dilationImage(erosionRice);
//
//	// =======================================================
//
//	// ��� �̹��� Ȯ��
//	imshow("dilation of erosion of stuff", dilationStuff);
//	imshow("dilation of erosion of rice", dilationRice);
//	// ��� �̹��� ���Ϸ� ����
//	// (������Ʈ����/outputs ������ �̹� �ִٰ� ����)
//	imwrite("./outputs/1_2_output_1.png", dilationStuff);
//	imwrite("./outputs/1_2_output_2.png", dilationRice);
//
//	waitKey();
//}
