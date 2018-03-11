#include <iostream>
using namespace std;

class PhanSo {
private:
	int tuso;
	int mauso;
	void RutGon();

public:
	PhanSo(int tu = 0, int mau = 1);
	PhanSo(const PhanSo &p);
	int LayTu();
	int LayMau();
	void GanTu(int tu);
	void GanMau(int mau);
	void Gan(int tu, int mau);
	void Nhap();
	void Xuat();
	
	bool operator>(PhanSo);
	PhanSo operator+(PhanSo);
	PhanSo operator-(PhanSo);

	friend istream& operator>>(istream &is, PhanSo &p);
	friend ostream& operator<<(ostream &os, PhanSo p);
};