#include "DaThuc.h"
using namespace std;

//Định hai phép gán: mặc định và gán bằng đa thức
DaThuc::DaThuc() : heso(0), bac(0) {}
DaThuc::DaThuc(const DaThuc &f) {
	bac = f.bac;
	heso = new int[bac + 1];
	for (int i = 0; i <= bac; ++i)
        heso[i] = f.heso[i];
}
DaThuc::~DaThuc() { delete[]heso; }

//Tính đa thức f(x) khi biết giá trị của x
int DaThuc::fx(int x) const {
	int f = 0;
	for (int i = 0; i <= bac; ++i)
		f += heso[i] * pow(x, i);
	return f;
}

//Quá tải toán tử cộng hai đa thức
DaThuc DaThuc::operator+(const DaThuc &f) const {
	DaThuc tong;
	tong.bac = max(bac, f.bac);

	tong.heso = new int[tong.bac + 1];
	if (tong.bac == bac)
		for (int i = bac; i >= 0; --i)
			if (i > f.bac) tong.heso[i] = heso[i];
			else tong.heso[i] = heso[i] + f.heso[i];

	else 
		for (int i = f.bac; i >= 0; --i)
			if (i > bac) tong.heso[i] = f.heso[i];
			else tong.heso[i] = heso[i] + f.heso[i];

	return tong;
}

//Quá tải toán tử trừ hai đa thức
DaThuc DaThuc::operator-(const DaThuc &f) const {
	DaThuc hieu;
	hieu.bac = max(bac, f.bac);

	hieu.heso = new int[hieu.bac + 1];
	if (hieu.bac == bac)
		for (int i = bac; i >= 0; --i)
			if (i > f.bac) hieu.heso[i] = heso[i];
			else hieu.heso[i] = heso[i] - f.heso[i];
	else
		for (int i = f.bac; i >= 0; --i)
			if (i > bac) hieu.heso[i] = -f.heso[i];
			else hieu.heso[i] = heso[i] - f.heso[i];

	return hieu;
}

//Quá tải toán tử nhập
istream& operator>>(istream& is, DaThuc &f) {
	cout << "- Nhap bac da thuc: ";
	is >> f.bac;

	while (f.bac < 0) {
		cout << "- Nhap lai bac da thuc: ";
		is >> f.bac;
	}

	f.heso = new int[f.bac + 1];
	cout << "- Nhap cac he so theo bac tu lon den nho: ";
	for (int i = f.bac; i >= 0; --i) is >> f.heso[i];
	return is;
}

//Quá tải toán tử xuất
ostream& operator<<(ostream& os, DaThuc f) {
	//Nếu là đa thức bậc 0 (chỉ có hệ số cuối)
	if (f.bac == 0) os << f.heso[0];
	else {
		//Xuất hệ số đầu (bậc lớn nhất) của đa thức
		if (f.heso[f.bac] == 1);
		else if (f.heso[f.bac] == -1) os << "-";
		else os << f.heso[f.bac];
		f.bac == 1 ? os << "x" : os << "x^" << f.bac;

		//Xuất các đơn thức con sau bậc khác 0
		for (int i = f.bac - 1; i > 0; --i) {
			if (!f.heso[i]) continue;
			else {
				//Xuất phần hệ số
				if (f.heso[i] == 1) os << "+";
				else if (f.heso[i] == -1) os << "-";
				else if (f.heso[i] > 0) os << "+" << f.heso[i];
				else os << f.heso[i];

				//Xuất phần bậc
				if (i == 1) os << "x";
				else if (i) os << "x^" << i;
			}
		}

		//Xuất hệ số cuối cùng (bậc 0)
		if (f.heso[0] > 0) os << "+";
		if (f.heso[0]) os << f.heso[0];
	}
	return os;
}