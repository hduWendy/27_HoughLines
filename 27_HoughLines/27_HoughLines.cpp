// 27_HoughLines.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
int main()
{
	//��ȡ���ص�һ��ͼƬ������ֱ�ߣ�����ʾ������
	cv::Mat srcMat = imread("C:/Users/lenovo/Desktop/��ͼͼƬ/metal-part-distorted-03.png",0);
	cv::Mat canny;
	Canny(srcMat, canny, 60, 180);

	cv::Mat lineMat;
	cv::HoughLines(canny, lineMat, 1, CV_PI / 180, 100);

	//��ֱ��
	for (int it = 0; it < lineMat.rows; it++)
	{
		float rho = lineMat.at<Vec2f>(it,0)[0], theta = lineMat.at<Vec2f>(it, 0)[1];
		cv::Point pt1, pt2;
		double a = cos(theta);
		double b = sin(theta);
		double x0 = a * rho;
		double y0 = b * rho;
		pt1.x = cv::saturate_cast<int>(x0 + 1000 * (-b));
		pt1.y = cv::saturate_cast<int>(y0 + 1000 * (a));
		pt2.x = cv::saturate_cast<int>(x0 - 1000 * (-b));
		pt2.y = cv::saturate_cast<int>(y0 - 1000 * (a));
		cv::line(srcMat, pt1, pt2, cv::Scalar(255, 255, 255), 1, CV_AA);
	}

	imshow("src", srcMat);
//	imshow("out2", canny);
	//�ȴ��û�����
	waitKey(0);
	return 0;
}
