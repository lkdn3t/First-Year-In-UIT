#include "PhanSo.h"

using namespace std;

//Tìm ước chung lớn nhất của hai số
int UCLN(int a, int b) {
	return b == 0 ? a : UCLN(b, a%b);
}

//Rút gọn phân số
void PhanSo::RutGon() {
	int t = UCLN(tu, mau);
	tu /= t;
	mau /= t;

	if (mau < 0) {
		tu = -tu;
		mau = -mau;
	}
}

//Constructor cho phân số (gồm tử và mẫu)
PhanSo::PhanSo(int TuSo, int MauSo) {
	tu  = TuSo;
	mau = MauSo;
}

//Constructor sao chép cho phân số
PhanSo::PhanSo(const PhanSo & ps) {
	tu  = ps.tu;
	mau = ps.mau;
}

//Set các dữ liệu của phân số (tử, mẫu)
void PhanSo::set_tu(int TuSo)    { tu = TuSo; }
void PhanSo::set_mau(int MauSo)  { mau = MauSo; }

//Get các dữ liệu của phân số (tử, mẫu)
int PhanSo::get_tu() const {
	return tu;
}

int PhanSo::get_mau() const {
	return mau;
}

void PhanSo::Nhap() {
	cout << " Nhap tu so: "; cin >> tu;
	do {
		cout << " Nhap mau so: ";
		cin >> mau;
	} while (!mau);
}

void PhanSo::Xuat() {
	cout << tu;
	if (tu && mau != 1)
		cout << "/" << mau;
	cout << endl;
}

PhanSo PhanSo::Cong(const PhanSo & ps) const {
	PhanSo Tong(tu * ps.mau + mau * ps.tu, mau * ps.mau);
	Tong.RutGon();
	return Tong;
}

PhanSo PhanSo::Tru(const PhanSo & ps) const {
	PhanSo Hieu(tu * ps.mau - mau * ps.tu, mau*ps.mau);
	Hieu.RutGon();
	return Hieu;
}

PhanSo PhanSo::Nhan(const PhanSo & ps) const {
	PhanSo Tich(tu * ps.tu, mau * ps.mau);
	Tich.RutGon();
	return Tich;
}

PhanSo PhanSo::Chia(const PhanSo & ps) const {
	PhanSo Thuong(tu * ps.mau, mau * ps.tu);
	Thuong.RutGon();
	return Thuong;
}