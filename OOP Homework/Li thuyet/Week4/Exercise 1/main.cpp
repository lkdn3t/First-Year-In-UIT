#include "DSPhanSo.h"
#include <iostream>
#include <conio.h>
using namespace std;

int main() {
	DSPhanSo ps;
	ps.NhapMangPS();

	cout << "\nMang phan so da nhap: ";
	ps.XuatMangPS();

	cout << "- Phan so lon nhat = " << ps.PhanSoMax() << "\n";
	cout << "- Tong cac phan so = " << ps.TongPhanSo() << "\n";

	_getch();
	return 1;
}