#include <iostream>
#include <opencv2/opencv.hpp>
#include "Geometry.h"
#include "Pixel.h"

using namespace cv;

// �Է� �̹����� �ش� degree ��ŭ �ݽð�������� ȸ��
Mat rotate(const Mat& image, const int degree)
{
	CGeometry cg;

	// CGeometry�� GS_affineRotate �Լ��� ����Ͽ�
	// �ش� �̹����� affine ��ȯ��Ŵ.
	// (�̶�, ȸ���� �����ϱ� ���Ͽ� scale�� 1�� ��)
	Mat rotated = cg.GS_affineRotate(image, degree, 1);

	return rotated;
}

int main()
{
	// ���� �̹��� �ε�
	// (������Ʈ����/images�� ���� �̹������� �ִٰ� ����)
	Mat originBriefcase = imread("./images/briefcase.jpg");
	// �Է� �̹��� ���Ϸ� ����
	// (������Ʈ����/outputs ������ �̹� �ִٰ� ����)
	imwrite("./outputs/3_4_input.png", originBriefcase);

	// =======================================================

	// ���� briefcase �̹����� 360��(30*12) * 5�� ȸ����Ŵ
	Mat rotated = originBriefcase.clone();
	// 5ȸ
	for (int times = 0; times < 5; times++) {
		// �̹��� 30���� 12�� �� 360�� ȸ��
		for (int i = 0; i < 12; i++) {
			rotated = rotate(rotated, -30);
		}
	}

	// subtract
	CPixel cp;

	// ���� �̹������� 30*12*5�� ȸ����Ų �̹����� ��
	Mat subtracted = cp.GS_subtract_image(originBriefcase, rotated);

	// =======================================================

	// ��� �̹��� Ȯ��
	imshow("Subtracted Briefcase", subtracted);
	// ��� �̹��� ���Ϸ� ����
	// (������Ʈ����/outputs ������ �̹� �ִٰ� ����)
	imwrite("./outputs/3_4_output.png", subtracted);

	waitKey();
}
