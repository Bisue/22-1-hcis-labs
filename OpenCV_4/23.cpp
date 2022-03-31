#include <iostream>
#include <opencv2/opencv.hpp>
#include "Geometry.h"

using namespace cv;

// 입력 이미지를 amount만큼 scale(확대 or 축소) 시킴
Mat scale(const Mat& image, const double amount)
{
	CGeometry cg;

	// CGeometry의 GS_affineRotate 메서드를 사용해
	// 이미지를 affine 변환시킴.
	// (이때, 회전은 시키지 않고 확대/축소만 하기 위하여 angle은 0으로 할당)
	Mat rotated = cg.GS_affineRotate(image, 0, amount);

	return rotated;
}

int main()
{
	// 원본 이미지 로드
	// (프로젝트폴더/images에 원본 이미지들이 있다고 가정)
	Mat originBriefcase = imread("./images/briefcase.jpg");
	// 입력 이미지 파일로 저장
	// (프로젝트폴더/outputs 폴더가 이미 있다고 가정)
	imwrite("./outputs/2_3_input.png", originBriefcase);

	// =======================================================

	// 입력 이미지를 1.5배 확대시킴
	Mat scaled = scale(originBriefcase, 1.5);

	// =======================================================

	// 출력 이미지 확인
	imshow("Scaled Briefcase", scaled);
	// 출력 이미지 파일로 저장
	// (프로젝트폴더/outputs 폴더가 이미 있다고 가정)
	imwrite("./outputs/2_3_output.png", scaled);

	waitKey();
}
