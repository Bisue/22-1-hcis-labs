#include <iostream>
#include <opencv2/opencv.hpp>
#include "Geometry.h"

using namespace cv;

// 입력 이미지를 해당 degree 만큼 반시계방향으로 회전
Mat rotate(const Mat& image, const int degree)
{
	CGeometry cg;

	// CGeometry의 GS_affineRotate 함수를 사용하여
	// 해당 이미지를 affine 변환시킴.
	// (이때, 회전만 적용하기 위하여 scale을 1로 함)
	Mat rotated = cg.GS_affineRotate(image, degree, 1);

	return rotated;
}

int main()
{
	// 입력 이미지 로드
	// (컬러 이미지)
	Mat rotatedBriefcase = imread("./outputs/3_1_output.png");
	// 입력 이미지 파일로 저장
	// (프로젝트폴더/outputs 폴더가 이미 있다고 가정)
	imwrite("./outputs/3_2_input.png", rotatedBriefcase);

	// =======================================================

	// 기존 시계방향으로 30도 기울어진 이미지에
	// 시계방향으로 30도를 11번 더 회전시켜
	// 이전 step 포함 총 시계방향으로 360도 회전시킴.
	for (int i = 0; i < 11; i++) {
		rotatedBriefcase = rotate(rotatedBriefcase, -30);
	}

	// =======================================================

	// 출력 이미지 확인
	imshow("Rotated Briefcase", rotatedBriefcase);
	// 출력 이미지 파일로 저장
	// (프로젝트폴더/outputs 폴더가 이미 있다고 가정)
	imwrite("./outputs/3_2_output.png", rotatedBriefcase);

	waitKey();
}
