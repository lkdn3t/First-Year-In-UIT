#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;

class KhachHang {
protected:
	string TenKhachHang;
	int SoLuongHang;
	int DonGiaHang;
	const float ThueVAT = 0.1;

public:
	string getTenKhachHang() const;
	int getSoLuongHang() const;
	int getDonGiaHang() const;

public:
	void setTenKhachHang(string TenKhachHang);
	void setSoLuongHang(int SoLuongHang);
	void setDonGiaHang(int DonGiaHang);

public:
	virtual void LayThongTin(ifstream& ifile);
	virtual void XuatThongTin(ofstream& ofile);
	virtual long SoTienPhaiTra() = 0;
};