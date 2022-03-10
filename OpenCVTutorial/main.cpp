#include <opencv2/opencv.hpp>

using namespace cv;

int main()
{
	Mat image = Mat(Size(300, 400), CV_8UC1, Scalar(255));
	image(Rect(0, 0, 300, 200)) = Scalar(1);

	putText(image, "2018112041", Point(50, 100), FONT_HERSHEY_PLAIN, 2, Scalar(255, 255, 255));
	putText(image, "ByeonChanHyuk", Point(20, 300), FONT_HERSHEY_PLAIN, 2, Scalar(0, 0, 0));

	std::cout << "2018112041 º¯ÂùÇõ" << std::endl;
	//namedWindow("test window", WINDOW_AUTOSIZE);
	imshow("image", image);

	waitKey();

	return 0;
}