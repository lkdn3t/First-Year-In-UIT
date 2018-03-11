#include "SoPhuc.h"
#include <iostream>
using namespace std;

//Các phép gán và lấy dữ liệu
void SoPhuc::setSoPhuc(float t, float a)	{ thuc = t; ao = a; }
float SoPhuc::getThuc()				{ return thuc; }
float SoPhuc::getAo()				{ return ao; }

//Phép khởi tạo bằng gán phần thực và ảo
SoPhuc::SoPhuc(float t, float a)	{ setSoPhuc(t, a); }
SoPhuc::SoPhuc(const SoPhuc &z)		{ thuc = z.thuc; ao = z.ao; }

//Định phép toán cộng
SoPhuc SoPhuc::operator+(SoPhuc z) {
	return SoPhuc(thuc + z.thuc, ao + z.ao);
}

//Định phép toán trừ
SoPhuc SoPhuc::operator-(SoPhuc z) {
	return SoPhuc(thuc - z.thuc, ao - z.ao);
}

//Định phép toán nhân
SoPhuc SoPhuc::operator*(SoPhuc z) {
	return SoPhuc(thuc*ao - z.thuc*z.ao, thuc*z.ao + z.thuc*ao);
}

//Định phép toán chia
SoPhuc SoPhuc::operator/(SoPhuc z) {
	SoPhuc divide;
	float t = z.thuc * z.thuc + z.ao * z.ao;
	divide.thuc = (z.thuc * thuc + z.ao * ao) / t;
	divide.ao = (z.thuc * ao - thuc * z.ao) / t;
	return divide;
}

//Định phép nhập
istream& operator>>(istream& is, SoPhuc &z) {
	is >> z.thuc >> z.ao;
	return is;
}

//Định phép xuất
ostream& operator<<(ostream& os, SoPhuc z) {
	os << z.thuc;
	if (z.ao) {
		if (z.ao > 0) os << "+";
		os << z.ao << "i";
	}
	return os;
}
