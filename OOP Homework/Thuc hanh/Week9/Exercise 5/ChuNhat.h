#pragma once
#include "Hinh.h"
class ChuNhat :	public Hinh {
public:
	ChuNhat() {}
	virtual void Nhap(ifstream& ifile);
	virtual char getLoai();
	Diem getTraiTren();
	float getDai();
	float getRong();

protected:
	Diem TraiTren;
	float Dai;
	float Rong;
};