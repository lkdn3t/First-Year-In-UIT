#include <iostream>
#include "Circle.h"
#define pi 3.14159265359
using namespace std;

//Nhập các thuộc tính của đường tròn
//Gồm toạ độ tâm và bán kính
void Circle:: inputInfo() {
	cout << "Nhap hoanh do tam: ";
	cin >> O.Ox;
	cout << "Nhap tung do tam: ";
	cin >> O.Oy;
	cout << "Nhap ban kinh: ";
	cin >> R;
};

//Tính chu vi đường tròn
float Circle:: Perimeter() {
	return 2 * pi * R;
}

//Tính diện tích hình tròn
float Circle:: Surface() {
	return R * R * pi;
}

//Xuất kết quả
void Circle::printInfo() {
	cout << "Chu vi: " << Perimeter();
	cout << "\nDien tich: " << Surface() << "\n";
}