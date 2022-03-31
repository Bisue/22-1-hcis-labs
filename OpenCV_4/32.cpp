#include <iostream>
#include <opencv2/opencv.hpp>
#include "Geometry.h"

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
	// �Է� �̹��� �ε�
	// (�÷� �̹���)
	Mat rotatedBriefcase = imread("./outputs/3_1_output.png");
	// �Է� �̹��� ���Ϸ� ����
	// (������Ʈ����/outputs ������ �̹� �ִٰ� ����)
	imwrite("./outputs/3_2_input.png", rotatedBriefcase);

	// =======================================================

	// ���� �ð�������� 30�� ������ �̹�����
	// �ð�������� 30���� 11�� �� ȸ������
	// ���� step ���� �� �ð�������� 360�� ȸ����Ŵ.
	for (int i = 0; i < 11; i++) {
		rotatedBriefcase = rotate(rotatedBriefcase, -30);
	}

	// =======================================================

	// ��� �̹��� Ȯ��
	imshow("Rotated Briefcase", rotatedBriefcase);
	// ��� �̹��� ���Ϸ� ����
	// (������Ʈ����/outputs ������ �̹� �ִٰ� ����)
	imwrite("./outputs/3_2_output.png", rotatedBriefcase);

	waitKey();
}
