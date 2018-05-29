#include "DanhSachKhachHang.h"

long (DanhSachKhachHang::*pTinhTienKH)(int) = &DanhSachKhachHang::TinhTienKhachHang;

void DanhSachKhachHang::NhapDanhSachKhachHang(const char * FileName) {
	ifstream ifile;
	ifile.open(FileName);

	int SoLuongKHThuong, SoLuongKHThanThiet, SoLuongKHDacBiet;
	ifile >> SoLuongKHThuong >> SoLuongKHThanThiet >> SoLuongKHDacBiet;
	ifile.ignore();

	int vt = 0;
	SoLuongKhachHang = SoLuongKHThuong + SoLuongKHThanThiet + SoLuongKHDacBiet;
	khach_hang = new KhachHang*[SoLuongKhachHang];

	for (int i = 0; i < SoLuongKHThuong; i++, vt++) {
		khach_hang[vt] = new KhachHangThuong;
		khach_hang[vt]->LayThongTin(ifile);
		ifile.ignore();
	}

	for (int i = 0; i < SoLuongKHThanThiet; i++, vt++) {
		khach_hang[vt] = new KhachHangThanThiet;
		khach_hang[vt]->LayThongTin(ifile);
		ifile.ignore();
	}

	for (int i = 0; i < SoLuongKHDacBiet; i++, vt++) {
		khach_hang[vt] = new KhachHangDacBiet;
		khach_hang[vt]->LayThongTin(ifile);
		ifile.ignore();
	}
	ifile.close();
}

void DanhSachKhachHang::XuatDanhSachThongTin(const char * FileName) {
	ofstream ofile;
	ofile.open(FileName);

	for (int i = 0; i < SoLuongKhachHang; i++) {
		ofile << khach_hang[i]->getTenKhachHang() << endl;
		ofile << (*this.*pTinhTienKH)(i) << endl;
	}

	ofile << TinhTongDoanhThu();
	ofile.close();
}

long DanhSachKhachHang::TinhTienKhachHang(int i) {
	return khach_hang[i]->SoTienPhaiTra();
}

long DanhSachKhachHang::TinhTongDoanhThu() {
	long TongDoanhThu = 0;
	for (int i = 0; i < SoLuongKhachHang; i++) {
		TongDoanhThu += (*this.*pTinhTienKH)(i);
	}
	return TongDoanhThu;
}

DanhSachKhachHang::~DanhSachKhachHang() {
	for (int i = 0; i < SoLuongKhachHang; i++)
		delete khach_hang[i];
	delete[] khach_hang;
}