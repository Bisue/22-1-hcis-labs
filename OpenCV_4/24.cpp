//#include <iostream>
//#include <opencv2/opencv.hpp>
//#include "Geometry.h"
//
//using namespace cv;
//
//// 입력 이미지를 해당 degree 만큼 반시계방향으로 회전
//Mat rotate(const Mat& image, const int degree)
//{
//	CGeometry cg;
//
//	// CGeometry의 GS_affineRotate 함수를 사용하여
//	// 해당 이미지를 affine 변환시킴.
//	// (이때, 회전만 적용하기 위하여 scale을 1로 함)
//	Mat rotated = cg.GS_affineRotate(image, degree, 1);
//
//	return rotated;
//}
//
//int main()
//{
//	// 입력 이미지 로드
//	// (컬러 이미지)
//	Mat originBriefcase = imread("./outputs/2_3_output.png");
//	// 입력 이미지 파일로 저장
//	// (프로젝트폴더/outputs 폴더가 이미 있다고 가정)
//	imwrite("./outputs/2_4_input.png", originBriefcase);
//
//	// =======================================================
//
//	// 이미지를 시계방향(clockwise)으로 45도 회전시킴
//	Mat rotated = rotate(originBriefcase, -45);
//
//	// =======================================================
//
//	// 출력 이미지 확인
//	imshow("Rotated of Scaled Briefcase", rotated);
//	// 출력 이미지 파일로 저장
//	// (프로젝트폴더/outputs 폴더가 이미 있다고 가정)
//	imwrite("./outputs/2_4_output.png", rotated);
//
//	waitKey();
//}
