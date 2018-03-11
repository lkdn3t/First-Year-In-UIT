#include "PhanSo.h"

class DSPhanSo {
private:
	int SoLuong;
	PhanSo *ps;

public:
	DSPhanSo() : SoLuong(0), ps(NULL) {};
	~DSPhanSo() { delete[]ps; }
	void NhapMangPS();
	void XuatMangPS();
	PhanSo PhanSoMax();
	PhanSo TongPhanSo();
};