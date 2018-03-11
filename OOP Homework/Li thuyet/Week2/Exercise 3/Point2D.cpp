#include "Point2D.h"

//Nhập hoành độ và tung độ điểm
void Point2D:: inputPoint() {
	cout << "Nhap hoanh do: ";
	cin >> x;
	cout << "Nhap tung do: ";
	cin >> y;
};

//Tính khoảng cách giữa 2 điểm
float Point2D:: Distance(Point2D A) {
	return sqrt((A.x - x)*(A.x - x) + (A.y - y)*(A.y - y));
};

//In khoảng cách giữa hai điểm
void Point2D::printDistance(Point2D A) {
	cout << "\nKhoang cach giua hai diem = " << Distance(A) << "\n";
} 