#include "Monomial.h"
#include <iostream>
#include <cmath>
#include <conio.h>
using namespace std;

int main() {
	//Khởi tạo và nhập đơn thức
	Monomial p;
	p.setMonomial();

	//Xuất đơn thức
	cout << "-> Don thuc da nhap: ";
	p.putMonomial();

	//Tính đạo hàm của đơn thức
	cout << "-> Dao ham P'(x) = ";
	p.Derivative().putMonomial();

	//Tính giá trị của đơn thức khi nhập vào x
	int x;
	cout << "-> P(" << x << ") = " << p.calMonomial(x) << "\n";
	
	_getch();
	return 1;
}