#include "Point2D.h"
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

//Lấy toạ độ điểm cho trước
Point2D Point2D::getPoint() {
	Point2D tmp;
	cin >> tmp.x >> tmp.y;
	return tmp;
}

//Gán toạ độ điểm
void Point2D::setPoint() {
	Point2D tmp = getPoint();
	x = tmp.x;
	y = tmp.y;
}

//In toạ độ điểm theo phương thức X = (X1, Y1)
void Point2D::printPoint() {
	cout << "(" << x << "," << y << ")\n";
}

//Tìm điểm dời = Tổng hai toạ độ điểm
Point2D Point2D::MovedPoint(Point2D P) {
	Point2D mPoint;
	mPoint.x = x + P.x;
	mPoint.y = y + P.y;
	return mPoint;
}

//Tìm khoảng cách giữa hai điểm
float Point2D::Distance(Point2D P) {
	return sqrt((float)(x - P.x)*(x - P.x) + (float)(y - P.y)*(y - P.y));
}

//Kiểm tra hai điểm có cùng nằm trên đường thẳng ax + by = 0
bool Point2D::isInLine(int a, int b) {
	return a * x + b * y == 0;
}