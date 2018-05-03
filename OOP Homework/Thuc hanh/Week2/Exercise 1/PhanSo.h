#include <iostream>

class PhanSo {
private:
	int  tu;
	int  mau;
	void RutGon();

public:
	PhanSo(int TuSo = 0, int MauSo = 1);
	PhanSo(const PhanSo &ps);
	void set_tu(int);
	void set_mau(int);

public:
	int get_tu() const;
	int get_mau() const;

public:
	void Nhap();
	void Xuat();

public:
	PhanSo Cong(const PhanSo &ps) const;
	PhanSo Tru(const PhanSo &ps) const;
	PhanSo Nhan(const PhanSo &ps) const;
	PhanSo Chia(const PhanSo&ps) const;
};