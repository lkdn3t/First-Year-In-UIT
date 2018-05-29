#pragma once
#include "PhongKhachSan.h"

class PhongDeluxe : public PhongKhachSan {
private:
	int PhiDichVu;
	float PhiPhucVu;

public:
	long DoanhThuPhong() {
		return (SoDem * 750000 + PhiDichVu) * (1 + PhiPhucVu);
	}

	void LayThongTin(ifstream& ifile) {
		PhongKhachSan::LayThongTin(ifile);
		ifile >> PhiDichVu;
		ifile >> PhiPhucVu;
	}
};