#include <iostream>
#include <opencv2/opencv.hpp>
#include "ImageAnalysis.h"

using namespace cv;

int main()
{
	// Template �̹����� ���� �������� �̹���
	Mat templateImage = imread("template.png");

	VideoCapture video = VideoCapture(0); // ��ķ(0)���� �̹����� �������� ���� cv:VideoCapture
	
	CImageAnalysis ca; // templateMatching ���� �Լ��� �ִ� Ŭ����
	Mat img, result; // img: ��ķ �̹��� 1������, result: templateMatching ��� �̹���

	while (true) {
		// ��Ʈ�� ���� ��ķ(0)���κ��� �̹��� ĸ��
		video >> img;

		// CImageAnalysis Ŭ������ ����Ͽ� Template Matching
		result = ca.GS_templateMatching(img, templateImage);

		// ���� �������� Template Matching ��� �̸�����
		imshow("matched", result);

		// Enter ������ while ���� �������� (���� �������� Capture)
		if (waitKey(1) == 13)
			break;
	}

	// Template�� ���� �̹��� ���
	imshow("input template", templateImage);
	imwrite("input_template.png", templateImage);

	// Source Image�� ���� ��ķ ĸ�� �̹��� ���
	imshow("input image", img);
	imwrite("input_image.png", img);

	// Template Matching�� ��� �̹��� ���
	imshow("output result", result);
	imwrite("output_result.png", result);

	waitKey();
}
