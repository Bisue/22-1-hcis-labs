#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;

void findCenterMass(const Mat& image, int& px, int& py)
{
	int cnt = 0;
	int mx = 0;
	int my = 0;

	for (int i = 0; i < image.size().height; i++) {
		for (int j = 0; j < image.size().width; j++) {
			if (image.at<uchar>(i, j) > 200) {
				cnt++;
				mx += j;
				my += i;
			}
		}
	}
	
	if (cnt == 0) {
		cnt = 1;
	}

	if (cnt > 0) {
		px = mx / cnt;
		py = my / cnt;
	}
}

int main()
{
	Mat mask = imread("./images/mask.png");

	VideoCapture video(0);

	Mat cameraRaw;
	Mat cameraResized;
	Mat masked;
	while (true) {
		video >> cameraRaw;

		resize(cameraRaw, cameraResized, Size(600, 400));
		add(cameraResized, mask, masked);

		// ==

		Mat converted;
		cvtColor(masked, converted, COLOR_BGR2YCrCb);

		Mat skin;
		inRange(converted, Scalar(0, 130, 90), Scalar(255, 168, 130), skin);

		Mat grayMasked;
		cvtColor(masked, grayMasked, COLOR_BGR2GRAY);

		Mat skinGray = grayMasked + (~skin);

		Mat binary;
		threshold(skinGray, binary, 200, 255, THRESH_BINARY);

		Mat noiseCanceled;
		erode(~binary, noiseCanceled, Mat(3, 3, CV_8U, Scalar(1)), Point(-1, -1), 2);
		//dilate(noiseCanceled, noiseCanceled, Mat(3, 3, CV_8U, Scalar(1)), Point(-1, -1), 2);

		int cx, cy;
		int radius = 40;
		findCenterMass(noiseCanceled, cx, cy);
		circle(noiseCanceled, Point(cx, cy), radius, Scalar(128, 128, 128), 2);
		circle(cameraRaw, Point(cx, cy), radius, Scalar(130, 255, 100), 2);

		Mat temp = skinGray.clone();
		circle(temp, Point(cx, cy), (int)(radius + 0.5), Scalar(0, 0, 0), -1);
		Mat sub = skinGray - temp;

		Mat edge;
		Canny(sub, edge, 40, 110);
		circle(edge, Point(cx, cy), radius, Scalar(0, 0, 0), 4);


		imshow("cam", masked);
		imshow("edge", edge);
		imshow("preview", noiseCanceled);


		// Enter 키를 누르면 while 빠져나가기
		if (waitKey(1) == 13)
			break;
	}
}
