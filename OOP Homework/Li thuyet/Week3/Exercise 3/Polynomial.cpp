#include "Polynomial.h"
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

//Khởi tạo đơn thức ban đầu có bậc là 0
Polynomial::Polynomial() :exponent(0) {}

//Khởi tạo đa thức nhập từ bàn phím
void Polynomial::setPolynomial() {
	do {
		cout << "- Nhap bac don thuc (khong am): ";
		cin >> exponent;
	} while (exponent < 0);

	coefficient = new int[exponent + 1];
	do {
		cout << "- Nhap cac he so theo bac giam dan (he so dau khac 0): ";
		for (int i = exponent; i >= 0; --i)
			cin >> coefficient[i];
	} while (coefficient[exponent] == 0 && exponent);
}

//Lấy đa thức đã có
Polynomial Polynomial::getPolynomial() {
	Polynomial p;
	p.exponent = exponent;
	p.coefficient = new int[exponent + 1];
	for (int i = exponent; i >= 0; --i) p.coefficient[i] = coefficient[i];
	return p;
}

//Khởi tạo đa thức bằng việc gán với đa thức khác
void Polynomial::setPolynomial(Polynomial p) {
	exponent = p.exponent;
	coefficient = new int[exponent + 1];
	for (int i = exponent; i >= 0; --i) coefficient[i] = p.coefficient[i];
}

//Xuất đa thức
void Polynomial::putPolynomial() {
	//Nếu là đa thức bậc 0 (chỉ có hệ số cuối)
	if (exponent == 0) cout << coefficient[0];
	else {
		//Xuất hệ số đầu (bậc lớn nhất) của đa thức
		if (coefficient[exponent] == 1);
		else if (coefficient[exponent] == -1) cout << "-";
		else cout << coefficient[exponent];
		exponent == 1 ? cout << "x" : cout << "x^" << exponent;

		//Xuất các đơn thức con sau bậc khác 0
		for (int i = exponent - 1; i > 0; --i) {
			if (!coefficient[i]) continue;
			else {
				//Xuất phần hệ số
				if (coefficient[i] == 1) cout << "+";
				else if (coefficient[i] == -1) cout << "-";
				else if (coefficient[i] > 0) cout << "+" << coefficient[i];
				else cout << coefficient[i];

				//Xuất phần bậc
				if (i == 1) cout << "x";
				else if (i) cout << "x^" << i;
			}
		}

		//Xuất hệ số cuối cùng (bậc 0)
		if (coefficient[0] > 0) cout << "+";
		if (coefficient[0]) cout << coefficient[0];
	}
}

//Cộng hai đa thức
Polynomial Polynomial::add(Polynomial p) {
	Polynomial sum;
	Polynomial q = getPolynomial();

	if (exponent > p.exponent) {
		sum.setPolynomial(q);
		for (int i = p.exponent; i >= 0; --i)
			sum.coefficient[i] += p.coefficient[i];
	}
	else {
		sum.setPolynomial(p);
		for (int i = exponent; i >= 0; --i)
			sum.coefficient[i] += coefficient[i];
	}
	return sum;
}

//Trừ hai đa thức
Polynomial Polynomial::subtract(Polynomial p) {
	Polynomial diff;
	Polynomial q = getPolynomial();

	if (exponent > p.exponent) {
		diff.setPolynomial(q);
		for (int i = p.exponent; i >= 0; --i)
			diff.coefficient[i] -= p.coefficient[i];
	}
	else {
		diff.setPolynomial(p);
		for (int i = exponent; i >= 0; --i)
			diff.coefficient[i] -= coefficient[i];
		for (int i = p.exponent; i >= 0; --i)
			diff.coefficient[i] = -diff.coefficient[i];
	}
	return diff;
}

//Tính giá trị của đa thức khi biết x
int Polynomial::calPolynomial(int &x) {
	cout << "\n\nNhap gia tri x: ";
	cin >> x;

	int ans = 0;
	for (int i = exponent; i >= 0; --i)
		ans += coefficient[i] * pow(x, i);
	return ans;
}

//Xoá đa thức
void Polynomial::delPolynomial() {
	delete[]coefficient;
	exponent = 0;
}