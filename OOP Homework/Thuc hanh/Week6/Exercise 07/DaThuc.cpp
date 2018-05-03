#include "DaThuc.h"
#define elif else if

using namespace std;

DaThuc::DaThuc(const DaThuc & dt) {
	if (heso != NULL) delete[]heso;

	bac = dt.bac;
	heso = new float[bac + 1];
	
	for (int i = 0; i <= bac; i++)
		heso[i] = *(dt.heso + i);
}

DaThuc::~DaThuc() {
	delete[]heso;
}

DaThuc DaThuc::operator+(const DaThuc & dt) const {
	DaThuc *Tong;

	if (bac > dt.bac) {
		Tong = new DaThuc(*this);
		for (int i = 0; i <= dt.bac; i++)
			Tong->heso[i] += dt.heso[i];
	}

	else {
		Tong = new DaThuc(dt);
		for (int i = 0; i <= bac; i++)
			Tong->heso[i] += heso[i];
	}
	return *Tong;
}

DaThuc DaThuc::operator-(const DaThuc &dt) const {
	DaThuc *Hieu;
	
	if (bac > dt.bac) {
		Hieu = new DaThuc(*this);
		for (int i = 0; i <= dt.bac; i++)
			Hieu->heso[i] -= dt.heso[i];
	}
	else {
		Hieu = new DaThuc(dt);
		for (int i = 0; i <= bac; i++)
			Hieu->heso[i] -= dt.heso[i];

		for (int i = 0; i <= Hieu->bac; i++)
			Hieu->heso[i] = -Hieu->heso[i];
	}
	return *Hieu;
}

ostream & operator<<(ostream & os, const DaThuc & dt) {
	//Nếu là đa thức bậc 0 (chỉ có hệ số cuối)
	if (dt.bac == 0) os << dt.heso[0];
	else {
		//Xuất hệ số đầu (bậc lớn nhất) của đa thức
		if (dt.heso[dt.bac] == 1);
		elif (dt.heso[dt.bac] == -1) os << "-";
		else os << dt.heso[dt.bac];
		dt.bac == 1 ? os << "x" : os << "x^" << dt.bac;

		//Xuất các đơn thức con sau bậc khác 0
		for (int i = dt.bac - 1; i > 0; --i) {
			if (!dt.heso[i]) continue;
			else {
				//Xuất phần hệ số
				if (dt.heso[i] == 1) os << "+";
				elif (dt.heso[i] == -1) os << "-";
				elif (dt.heso[i] > 0) os << "+" << dt.heso[i];
				else os << dt.heso[i];

				//Xuất phần bậc
				if (i == 1) os << "x";
				elif (i) os << "x^" << i;
			}
		}

		//Xuất hệ số cuối cùng (bậc 0)
		if (dt.heso[0] > 0) os << "+";
		if (dt.heso[0]) os << dt.heso[0];
	}
	return os;
}

istream & operator>>(istream & is, DaThuc & dt) {
	cout << "Nhap bac da thuc: ";
	is >> dt.bac;

	dt.heso = new float[dt.bac + 1];
	cout << "Nhap cac he so theo bac giam dan: ";
	for (int i = dt.bac; i >= 0; i--)
		is >> dt.heso[i];
	return is;
}