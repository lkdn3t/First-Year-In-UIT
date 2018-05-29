#pragma once
#include "ChuNhat.h"

class Vuong: public ChuNhat {
public:
	Vuong() {}
	void Nhap(ifstream& ifile);
	char getLoai();
};