#include <iostream>
#include <opencv2/opencv.hpp>
#include "Geometry.h"
#include "Pixel.h"

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
	// 원본 이미지 로드
	// (프로젝트폴더/images에 원본 이미지들이 있다고 가정)
	Mat originBriefcase = imread("./images/briefcase.jpg");
	// 입력 이미지 파일로 저장
	// (프로젝트폴더/outputs 폴더가 이미 있다고 가정)
	imwrite("./outputs/3_4_input.png", originBriefcase);

	// =======================================================

	// 원본 briefcase 이미지를 360도(30*12) * 5번 회전시킴
	Mat rotated = originBriefcase.clone();
	// 5회
	for (int times = 0; times < 5; times++) {
		// 이미지 30도씩 12번 총 360도 회전
		for (int i = 0; i < 12; i++) {
			rotated = rotate(rotated, -30);
		}
	}

	// subtract
	CPixel cp;

	// 원본 이미지에서 30*12*5도 회전시킨 이미지를 뺌
	Mat subtracted = cp.GS_subtract_image(originBriefcase, rotated);

	// =======================================================

	// 출력 이미지 확인
	imshow("Subtracted Briefcase", subtracted);
	// 출력 이미지 파일로 저장
	// (프로젝트폴더/outputs 폴더가 이미 있다고 가정)
	imwrite("./outputs/3_4_output.png", subtracted);

	waitKey();
}
