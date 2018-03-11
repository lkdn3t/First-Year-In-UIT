#include "Complex.h"
#include <iostream>
using namespace std;

//Nhập số phức
void Complex::inputComplex() {
	cout << "Nhap phan thuc: ";
	cin >> a;
	cout << "Nhap phan ao: ";
	cin >> b;
};

//Xuất số phức
void Complex::printComplex() {
	cout << a;
	if (b < 0) cout << "-" << -b;
	else cout << "+" << b;
	cout << "i\n";
};

//Cộng hai số phức
Complex Complex::Add(Complex p) {
	Complex add;
	add.a = a + p.a;
	add.b = b + p.b;
	return add;
};

//Trừ hai số phức
Complex Complex::Subtract(Complex p) {
	Complex subtract;
	subtract.a = a - p.a;
	subtract.b = b - p.b;
	return subtract;
};

//Nhân hai số phức
Complex Complex::Multiply(Complex p) {
	Complex multi;
	multi.a = a * p.a - b * p.b;
	multi.b = a * p.b + p.a * b;
	return multi;
};

//Chia hai số phức
Complex Complex::Divide(Complex p) {
	Complex divide;
	float t = p.a * p.a + p.b * p.b;
	divide.a = (p.a * a + p.b * b) / t;
	divide.b = (p.a * b - a * p.b) / t;
	return divide;
};