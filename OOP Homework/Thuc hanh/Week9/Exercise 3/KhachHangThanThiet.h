#pragma once
#include "KhachHang.h"

class KhachHangThanThiet: public KhachHang {
private:
	int SoNamThanThiet;

public:
	void LayThongTin(ifstream& ifile);
	float TinhKhuyenMai();
	long SoTienPhaiTra();
};