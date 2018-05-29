#pragma once
#include "PhongKhachSan.h"

class PhongBusiness : public PhongKhachSan {
public:
	long DoanhThuPhong() {
		return 300000 * SoDem;
	}
};