#pragma once
#include "Hinh.h"
class TamGiac : public Hinh {
public:
	TamGiac() {}
	void Nhap(ifstream& ifile);
	char getLoai();
	float getAx(); float getAy();
	float getBx(); float getBy();
	float getCx(); float getCy();

private:
	Diem A, B, C;
};