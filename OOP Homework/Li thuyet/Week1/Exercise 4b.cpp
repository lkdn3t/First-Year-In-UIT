#include <iostream>
#include <string>
using namespace std;

struct HocSinh {
	string HoTen;
	float DiemToan;
	float DiemVan;
};

void nhapHocSinh(HocSinh &hs) {
	cout << "Nhap ho va ten: ";
	getline(cin, hs.HoTen);
	cout << "Nhap diem van: ";
	cin >> hs.DiemVan;
	cout << "Nhap diem toan: ";
	cin >> hs.DiemToan;
}

void xuatHocSinh(HocSinh hs) {
	cout << "\nHo va ten: ";
	cout << hs.HoTen << endl;
	cout << "Diem van: ";
	cout << hs.DiemVan << endl;
	cout << "Diem toan: ";
	cout << hs.DiemToan << endl;
	float TrungBinh = (hs.DiemVan + hs.DiemToan) / 2;
	cout << "Diem trung binh: " << TrungBinh << endl;
}

int main() {
	HocSinh hs;
	nhapHocSinh(hs);
	xuatHocSinh(hs);
	system("pause");
}