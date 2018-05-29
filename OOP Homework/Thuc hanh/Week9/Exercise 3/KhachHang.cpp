#include "KhachHang.h"

string KhachHang::getTenKhachHang() const {
	return TenKhachHang;
}

int KhachHang::getSoLuongHang() const {
	return SoLuongHang;
}

int KhachHang::getDonGiaHang() const {
	return DonGiaHang;
}

void KhachHang::setTenKhachHang(string TenKhachHang) {
	this->TenKhachHang = TenKhachHang;
}

void KhachHang::setSoLuongHang(int SoLuongHang) {
	this->SoLuongHang = SoLuongHang;
}

void KhachHang::setDonGiaHang(int DonGiaHang) {
	this->DonGiaHang = DonGiaHang;
}

void KhachHang::LayThongTin(ifstream & ifile) {
	getline(ifile, TenKhachHang);
	ifile >> SoLuongHang;
	ifile >> DonGiaHang;
}

void KhachHang::XuatThongTin(ofstream & ofile) {
	ofile << TenKhachHang << endl;
	ofile << SoTienPhaiTra() << endl;
}