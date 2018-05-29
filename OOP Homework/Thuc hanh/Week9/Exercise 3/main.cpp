#include "DanhSachKhachHang.h"

int main() {
	const char *iFileName = "XYZ.INP";
	const char *oFileName = "XYZ.OUT";
	DanhSachKhachHang *DS_KhachHang = new DanhSachKhachHang();
	DS_KhachHang->NhapDanhSachKhachHang(iFileName);
	DS_KhachHang->XuatDanhSachThongTin(oFileName);
	delete DS_KhachHang;
	return 0;
}