#include <iostream>
#include <opencv2/opencv.hpp>
#include "Geometry.h"

using namespace cv;

// �Է� �̹����� amount��ŭ scale(Ȯ�� or ���) ��Ŵ
Mat scale(const Mat& image, const double amount)
{
	CGeometry cg;

	// CGeometry�� GS_affineRotate �޼��带 �����
	// �̹����� affine ��ȯ��Ŵ.
	// (�̶�, ȸ���� ��Ű�� �ʰ� Ȯ��/��Ҹ� �ϱ� ���Ͽ� angle�� 0���� �Ҵ�)
	Mat rotated = cg.GS_affineRotate(image, 0, amount);

	return rotated;
}

int main()
{
	// ���� �̹��� �ε�
	// (������Ʈ����/images�� ���� �̹������� �ִٰ� ����)
	Mat originBriefcase = imread("./images/briefcase.jpg");
	// �Է� �̹��� ���Ϸ� ����
	// (������Ʈ����/outputs ������ �̹� �ִٰ� ����)
	imwrite("./outputs/2_3_input.png", originBriefcase);

	// =======================================================

	// �Է� �̹����� 1.5�� Ȯ���Ŵ
	Mat scaled = scale(originBriefcase, 1.5);

	// =======================================================

	// ��� �̹��� Ȯ��
	imshow("Scaled Briefcase", scaled);
	// ��� �̹��� ���Ϸ� ����
	// (������Ʈ����/outputs ������ �̹� �ִٰ� ����)
	imwrite("./outputs/2_3_output.png", scaled);

	waitKey();
}
