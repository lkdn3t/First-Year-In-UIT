#include "DSPhanSo.h"
#include <iostream>
using namespace std;

//Nhập các phân số bằng cấp phát động
void DSPhanSo::NhapMangPS() {
	cout << "Nhap so luong phan so: ";
	cin >> SoLuong;

	while (SoLuong <= 0) {
		cout << "Nhap lai so luong phan so: ";
		cin >> SoLuong;
	}

	ps = new PhanSo[SoLuong];
	for (int i = 0; i < SoLuong; ++i) {
		cout << "- Nhap phan so thu " << i + 1 << ": ";
		cin >> ps[i];
	}
}

//Xuất danh sách phân số
void DSPhanSo::XuatMangPS() {
	for (int i = 0; i < SoLuong; ++i) {
		cout << ps[i] << " ";
	}
	cout << "\n";
}

//Tìm phân số lớn nhất
PhanSo DSPhanSo::PhanSoMax() {
	PhanSo PSMax(ps[0]);
	for (int i = 0; i < SoLuong; ++i)
		if (ps[i] > PSMax) PSMax = ps[i];
	return PSMax;
}

//Tính tổng các phân số trong mảng
PhanSo DSPhanSo::TongPhanSo() {
	PhanSo Tong;
	for (int i = 0; i < SoLuong; ++i)
		Tong = Tong + ps[i];
	return Tong;
}