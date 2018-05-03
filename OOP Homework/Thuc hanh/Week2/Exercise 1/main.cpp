#include "PhanSo.h"

using namespace std;

int main(int argc, char *argv[]) {
	PhanSo ps1, ps2;
	cout << "...Nhap phan so thu nhat...\n" ;  ps1.Nhap();
	cout << "\n...Nhap phan so thu hai...\n";  ps2.Nhap();

	cout << "\n Phan so thu nhat: "; ps1.Xuat();
	cout << " Phan so thu hai: "   ; ps2.Xuat();

	PhanSo Tong = ps1.Cong(ps2);
	PhanSo Hieu = ps1.Tru(ps2);
	PhanSo Tich = ps1.Nhan(ps2);

	cout << "\n Tong phan so: "; Tong.Xuat();
	cout << " Hieu phan so: "  ; Hieu.Xuat();
	cout << " Tich phan so: "  ; Tich.Xuat();

	if (!ps2.get_tu()) {
		cout << " Khong the chia phan so cho 0" << endl;
	}
	else {
		PhanSo Thuong = ps1.Chia(ps2);
		cout << " Thuong phan so: ";
		Thuong.Xuat();
	}

	cout << endl;
	system("pause");
	return 0;
}