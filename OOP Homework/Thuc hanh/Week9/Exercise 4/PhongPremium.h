#pragma once
#include "PhongKhachSan.h"

class PhongPremium : public PhongKhachSan {
private:
	int PhiDichVu;

public:
	void LayThongTin(ifstream& ifile) {
		PhongKhachSan::LayThongTin(ifile);
		ifile >> PhiDichVu;
	}

	long DoanhThuPhong() {
		return (SoDem * 500000 + PhiDichVu) * 1.05;
	}
};