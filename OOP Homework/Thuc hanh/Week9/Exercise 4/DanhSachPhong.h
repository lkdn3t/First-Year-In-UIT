#pragma once
#include "PhongBusiness.h"
#include "PhongDeluxe.h"
#include "PhongPremium.h"
#include <vector>

class DanhSachPhong {
private:
	int SoLuongPhong;
	PhongKhachSan **PhongKS;
	int SoPhongDeluxe;
	int SoPhongPremium;
	int SoPhongBusiness;
	
public:
	~DanhSachPhong();
	void LayDanhSach(const char* FileName);
	void XuatDanhSach(const char* FileName);
	long TongDoanhThuPhong(string TenLoaiPhong, int SoLuong);
	vector<string> DanhSachPhongVuotTroi();
};