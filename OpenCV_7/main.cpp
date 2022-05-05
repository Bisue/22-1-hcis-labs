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


	while (true) {
		// Step 1.
		Mat camera;
		Mat masked;
		video >> camera;

		resize(mask, mask, Size(camera.size().width, camera.size().height));
		add(camera, mask, masked);

		imshow("Step 1.", camera);

		// Step 2.
		Mat converted;
		cvtColor(masked, converted, COLOR_BGR2YCrCb);

		Mat skin;
		inRange(converted, Scalar(0, 130, 90), Scalar(255, 168, 130), skin);

		imshow("Step 2.", skin);

		// Step 3.
		Mat grayMasked;
		cvtColor(masked, grayMasked, COLOR_BGR2GRAY);

		Mat skinGray = grayMasked + (~skin);

		imshow("Step 3.", skinGray);

		// Step 4.
		Mat binary;
		threshold(skinGray, binary, 200, 255, THRESH_BINARY);

		Mat noiseCanceled;
		erode(~binary, noiseCanceled, Mat(3, 3, CV_8U, Scalar(1)), Point(-1, -1), 2);
		//dilate(noiseCanceled, noiseCanceled, Mat(3, 3, CV_8U, Scalar(1)), Point(-1, -1), 2);

		int cx, cy;
		int radius = 40;
		findCenterMass(noiseCanceled, cx, cy);
		circle(noiseCanceled, Point(cx, cy), radius, Scalar(128, 128, 128), 2);
		circle(camera, Point(cx, cy), radius, Scalar(130, 255, 100), 2);

		Mat temp = skinGray.clone();
		circle(temp, Point(cx, cy), (int)(radius + 0.5), Scalar(0, 0, 0), -1);
		Mat sub = skinGray - temp;

		imshow("Step 4.", sub);

		// Step 5.
		Mat edge;
		Canny(sub, edge, 40, 110);
		circle(edge, Point(cx, cy), radius, Scalar(0, 0, 0), 4);

		imshow("Step 5.", edge);

		// Enter 키를 누르면 while 빠져나가기
		if (waitKey(1) == 13) {
			imwrite("./outputs/step1.png", camera);
			imwrite("./outputs/masked.png", masked);
			imwrite("./outputs/converted.png", converted);
			imwrite("./outputs/step2.png", skin);
			imwrite("./outputs/graymasked.png", grayMasked);
			imwrite("./outputs/step3.png", skinGray);
			imwrite("./outputs/binary.png", binary);
			imwrite("./outputs/noiseCanceled.png", noiseCanceled);
			imwrite("./outputs/step4.png", sub);
			imwrite("./outputs/step5.png", edge);

			break;
		}
	}
}
