#include "Complex.h"
#include <iostream>
using namespace std;

int main() {
	Complex a, b;
	cout << "Nhap so phuc a:\n";
	a.inputComplex();
	cout << "\nNhap so phuc b:\n";
	b.inputComplex();

	cout << "\nSo phuc a: ";
	a.printComplex();
	cout << "So phuc b: ";
	b.printComplex();

	cout << "\nTong = ";
	a.Add(b).printComplex();
	cout << "Hieu = ";
	a.Subtract(b).printComplex();
	cout << "Tich = ";
	a.Multiply(b).printComplex();
	cout << "Thuong = ";
	a.Divide(b).printComplex();

	system("pause");
	return 0;
}