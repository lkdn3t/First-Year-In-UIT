#pragma once
#include <iostream>
#include <fstream>

using namespace std;

struct Diem {
	float x;
	float y;
};

class Hinh {
public:
	Hinh() {}
	virtual char getLoai() = 0;
	virtual void Nhap(ifstream& ifile) = 0;
};