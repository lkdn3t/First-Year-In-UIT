#include "KhachHangThanThiet.h"

void KhachHangThanThiet::LayThongTin(ifstream & ifile) {
	KhachHang::LayThongTin(ifile);
	ifile >> SoNamThanThiet;
}

float KhachHangThanThiet::TinhKhuyenMai() {
	return min(0.05 * SoNamThanThiet, 0.5);
}

long KhachHangThanThiet::SoTienPhaiTra() {
	return SoLuongHang * DonGiaHang * (1 + ThueVAT - TinhKhuyenMai());
}