#include <iostream>
#include <cmath>
using namespace std;

#pragma once
class Point2D {
private:
	//Định các thuộc tính cho điểm trong không gian Oxy
	//Gồm Hoành độ và Tung độ
	float x;
	float y;

public:
	//Định các phương thức
	//Gồm: Nhập, tính khoảng cách và xuất kết quả
	void	inputPoint();
	float	Distance(Point2D);
	void	printDistance(Point2D);
};

