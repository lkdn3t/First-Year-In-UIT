#include "Monomial.h"
#include <iostream>
#include <cmath>
using namespace std;

//Khởi tạo hệ số và số mũ mặc định cho đơn thức ngay khi khai báo
Monomial::Monomial() : coefficient(0), exponent(0) {}

//Khởi tạo đơn thức bằng nhập vào số mũ và hệ số của đơn thức từ bàn phím
void Monomial::setMonomial() {
	cout << "Nhap he so: ";
	cin >> coefficient;
	cout << "Nhap so mu: ";
	cin >> exponent;
}

//Khởi tạo đơn thức từ hệ số và số mũ có sẵn
void Monomial::setMonomial(int coef, int exp) {
	coefficient = coef;
	exponent = exp;
}

//Xuất đơn thức
void Monomial::putMonomial() {
	if (exponent == 0) cout << coefficient;
	else {
		if (coefficient == 1);
		else if (coefficient == -1) cout << "-";
		else cout << coefficient;

		if (exponent == 1) cout << "x";
		else cout << "x^" << exponent;
	}
	cout << "\n";
}

//Tính giá trị đơn thức khi biết x
int Monomial::calMonomial(int& x) {
	cout << "\nNhap gia tri x: ";
	cin >> x;
	return coefficient * pow(x, exponent);
}

//Tính đạo hàm của đơn thức
//Vì đã đặc mặc định khi khởi tạo đơn thức là (0,0) nên chỉ khi có số mũ thì mới tính đơn thức
//Nếu số mũ = 0 (VD: P(x) = 3) thì không cần tính và trả về giá trị mặc định là (0, 0) vẫn đúng
Monomial Monomial::Derivative() {
	Monomial derivative;
	if (exponent) derivative.setMonomial(coefficient * exponent, exponent - 1);
	return derivative;
}