#include <iostream>
#include <opencv2/opencv.hpp>
#include "ImageAnalysis.h"

using namespace cv;

int main()
{
	VideoCapture video = VideoCapture(0); // ��ķ(0)���� �̹����� �������� ���� cv:VideoCapture

	Mat img; // ��ķ �̹��� 1�������� ������ Mat

	while (true) {
		// ��Ʈ�� ���� ��ķ(0)���κ��� �̹��� ĸ��
		video >> img;

		// ���� ��ķ���� ������ ������ �̸�����
		imshow("Img", img);

		// Enter Ű�� ������ while ����������
		if (waitKey(1) == 13)
			break;
	}

	// Enter Ű�� ���� �ش� �������� ���
	imshow("capture", img);
	imwrite("capture.png", img);

	waitKey();
}
