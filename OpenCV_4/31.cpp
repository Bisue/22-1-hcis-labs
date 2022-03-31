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
//	// ���� �̹��� �ε�
//	// (������Ʈ����/images�� ���� �̹������� �ִٰ� ����)
//	Mat originBriefcase = imread("./images/briefcase.jpg");
//	// �Է� �̹��� ���Ϸ� ����
//	// (������Ʈ����/outputs ������ �̹� �ִٰ� ����)
//	imwrite("./outputs/3_1_input.png", originBriefcase);
//
//	// =======================================================
//
//	// �̹����� �ð����(clockwise)���� 30�� ȸ����Ŵ
//	Mat rotated = rotate(originBriefcase, -30);
//
//	// =======================================================
//
//	// ��� �̹��� Ȯ��
//	imshow("Rotated Briefcase", rotated);
//	// ��� �̹��� ���Ϸ� ����
//	// (������Ʈ����/outputs ������ �̹� �ִٰ� ����)
//	imwrite("./outputs/3_1_output.png", rotated);
//
//	waitKey();
//}
