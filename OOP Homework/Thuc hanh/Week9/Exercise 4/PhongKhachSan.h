#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class PhongKhachSan
{
protected:
	string MaPhong;
	int SoDem;

public:
	string getMaPhong() {
		return MaPhong;
	};

	virtual long DoanhThuPhong() = 0;
	virtual void LayThongTin(ifstream& ifile) {
		getline(ifile, MaPhong);
		ifile >> SoDem;
	}
};