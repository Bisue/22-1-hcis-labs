//#include <iostream>
//#include <opencv2/opencv.hpp>
//#include "Geometry.h"
//
//using namespace cv;
//
//// �Է� �̹����� �ش� degree ��ŭ �ݽð�������� ȸ��
//Mat rotate(const Mat& image, const int degree)
//{
//	CGeometry cg;
//
//	// CGeometry�� GS_affineRotate �Լ��� ����Ͽ�
//	// �ش� �̹����� affine ��ȯ��Ŵ.
//	// (�̶�, ȸ���� �����ϱ� ���Ͽ� scale�� 1�� ��)
//	Mat rotated = cg.GS_affineRotate(image, degree, 1);
//
//	return rotated;
//}
//
//int main()
//{
//	// �Է� �̹��� �ε�
//	// (�÷� �̹���)
//	Mat originBriefcase = imread("./outputs/2_3_output.png");
//	// �Է� �̹��� ���Ϸ� ����
//	// (������Ʈ����/outputs ������ �̹� �ִٰ� ����)
//	imwrite("./outputs/2_4_input.png", originBriefcase);
//
//	// =======================================================
//
//	// �̹����� �ð����(clockwise)���� 45�� ȸ����Ŵ
//	Mat rotated = rotate(originBriefcase, -45);
//
//	// =======================================================
//
//	// ��� �̹��� Ȯ��
//	imshow("Rotated of Scaled Briefcase", rotated);
//	// ��� �̹��� ���Ϸ� ����
//	// (������Ʈ����/outputs ������ �̹� �ִٰ� ����)
//	imwrite("./outputs/2_4_output.png", rotated);
//
//	waitKey();
//}
