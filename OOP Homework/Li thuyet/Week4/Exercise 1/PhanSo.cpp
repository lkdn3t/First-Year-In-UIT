#include "PhanSo.h"
using namespace std;

//Định các phép gán và phép lấy tử, mẫu của phân số
void PhanSo::GanTu(int tu)		{ tuso = tu; }
void PhanSo::GanMau(int mau)		{ mauso = mau; }
void PhanSo::Gan(int tu, int mau)	{ GanTu(tu); GanMau(mau); }
int PhanSo::LayTu()			{ return tuso; }
int PhanSo::LayMau()			{ return mauso; }

//Hàm tìm ước chung lớn nhất và hàm rút gọn phân số
int UCLN(int a, int b) {
	return b == 0 ? a : UCLN(b, a%b);
}

void PhanSo::RutGon() {
	int uc = UCLN(tuso, mauso);
	tuso /= uc;
	mauso /= uc;

	if (tuso > 0 && mauso < 0) {
		tuso = -tuso;
		mauso = -mauso;
	}
}

//Định khởi tạo mặc định khi khai báo phân số
PhanSo::PhanSo(int tu, int mau)		{ Gan(tu, mau); }
PhanSo::PhanSo(const PhanSo &p)		{ tuso = p.tuso; mauso = p.mauso; }

//Hàm nhập phân số
void PhanSo::Nhap() {
	cout << "Nhap tu so: ";
	cin >> tuso;
	cout << "Nhap mau so: ";
	cin >> mauso;

	while (!mauso) {
		cout << "Nhap lai mau so: ";
		cin >> mauso;
	}
}

//Hàm xuất phân số
void PhanSo::Xuat() {
	cout << tuso;
	if (tuso != 0 && mauso != 1) cout << "/" << mauso;
}

//Quá tải toán tử nhập
istream& operator>>(istream &is, PhanSo &p) {
	cin >> p.tuso >> p.mauso;
	while (!p.mauso) {
		cout << "Nhap lai mau so: ";
		cin >> p.mauso;
	}
	return is;
}

//Quá tải toán tử xuất
ostream& operator<<(ostream &os, PhanSo p) {
	os << p.tuso;
	if (p.tuso != 0 && p.mauso != 1) os << "/" << p.mauso;
	return os;
}

//Quá tải toán tử cộng
PhanSo PhanSo::operator+(PhanSo a) {
	PhanSo Tong;
	Tong.tuso = tuso * a.mauso + mauso * a.tuso;
	Tong.mauso = mauso * a.mauso;
	Tong.RutGon();
	return Tong;
}

//Quá tải toán tử trừ
PhanSo PhanSo::operator-(PhanSo a) {
	PhanSo Hieu;
	Hieu.tuso = tuso * a.mauso - mauso * a.tuso;
	Hieu.mauso = mauso * a.mauso;
	Hieu.RutGon();
	return Hieu;
}

//Quá tải toán tử so sánh lớn hơn (>)
bool PhanSo::operator>(PhanSo a) {
	return (double)tuso / mauso > (double)a.tuso / a.mauso;
}
