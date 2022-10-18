#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;
int main()
{
	# 定义需要识别的图像和转灰度化后的图像，以及高斯模糊后的图像。
	Mat img,img_gray,dst;
	img = imread("D:\\Edge download\\Picture\\OpencvSave\\tag.png");
	if (img.empty()) {
		cout << "could not load image...\n";
		return -1;
	}
	Mat edge;
	GaussianBlur(img, dst, Size(3, 3), 0, 0);
	cvtColor(dst, img_gray, COLOR_BGR2GRAY);
	Laplacian(img_gray, edge, CV_16S, 3);
	convertScaleAbs(edge, edge);
	imshow("Ê¶±ð", edge);
	threshold(edge, edge, 0, 255, THRESH_OTSU | THRESH_BINARY);
	imshow("¶þÖµ»¯ºó", edge);
	waitKey(0);
	return 0;
}
