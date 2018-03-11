#include "Point2D.h"
#include <iostream>
using namespace std;

//Định constructor và destructor cho điểm trong Oxy
Point2D::Point2D(float xx, float yy) { x = xx; y = yy; }
Point2D::~Point2D() {}

//Nhập điểm và xuất điểm trong Oxy
void Point2D::setPoint() {
	cout << "- Nhap hoanh do: "; cin >> x;
	cout << "- Nhap tung do: ";  cin >> y;
}

void Point2D::printPoint() {
	cout << "(" << x << "," << y << ")\n";
}

//Định constructor và destructor cho đường tròn
//Đường tròn kế thừa toạ độ tâm O (thuộc Point2D) và đặc tính riêng là bán kính
Circle::Circle(float xx, float yy, float rr) { Point2D(xx,yy); r = rr; }
Circle::~Circle() {};

//Nhập bán kính cho đường tròn
void Circle::setRadius() {
	cout << "Nhap ban kinh: ";
	cin >> r;

	while (r <= 0) {
		cout << "Nhap lai ban kinh: ";
		cin >> r;
	}
}

//Nhập đường tròn gồm tâm và bán kính
void Circle::setCircle() {
	cout << "Nhap tam duong tron:\n";
	setPoint();
	setRadius();
}

//Xuất đường tròn gồm tâm và bán kính
void Circle::printCircle() {
	cout << " - Tam: O"; printPoint();
	cout << " - Ban kinh: " << r << "\n";
}