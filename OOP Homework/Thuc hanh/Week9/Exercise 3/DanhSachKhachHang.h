#pragma once
#include "KhachHangThuong.h"
#include "KhachHangThanThiet.h"
#include "KhachHangDacBiet.h"

class DanhSachKhachHang {
private:
	int SoLuongKhachHang;
	KhachHang **khach_hang;

public:
	~DanhSachKhachHang();
	void NhapDanhSachKhachHang(const char* FileName);
	void XuatDanhSachThongTin(const char* FileName);
	long TinhTienKhachHang(int i);
	long TinhTongDoanhThu();
};