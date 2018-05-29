#pragma once
#include "Hinh.h"

class Tron: public Hinh {
public:
	Tron() {}
	void Nhap(ifstream& ifile);
	char getLoai();
	Diem getTam();
	float getBanKinh();

private:
	Diem Tam;
	float BanKinh;
};

