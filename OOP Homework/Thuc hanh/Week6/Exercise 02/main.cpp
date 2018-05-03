#include "Fraction.h"

using namespace std;

int main(int argc, char *argv[]) {
	//Nhập và xuất hai phân số
	Fraction f1, f2;
	cout << "Nhap phan so thu nhat: "; cin >> f1;
	cout << "Nhap phan so thu hai: " ; cin >> f2;

	cout << "\nPhan so thu nhat: " << f1;
	cout << "\nPhan so thu hai:  " << f2 << endl;

	//Xuất các phép tính hai phân số
	cout << "\nTong phan so = " << f1 + f2;
	cout << "\nHieu phan so = " << f1 - f2;
	cout << "\nTich phan so = " << f1 * f2;

	//Xuất phép chia hai phân số (đk: số chia khác 0)
	if (!f2.getNumer()) {
		cout << "\nKhong the chia phan so cho 0." << endl;
	}
	else {
		cout << "\nThuong phan so = " << f1 / f2 << endl;
	}

	//Xuất phép so sánh hai phân số (bằng, lớn, nhỏ)
	cout << endl << "So sanh: ";
	if (f1 == f2) {
		cout << f1 << " = " << f2 << endl;
	}
	else if (f1 > f2) {
		cout << f1 << " > " << f2 << endl;
	}
	else if (f1 < f2) {
		cout << f1 << " < " << f2 << endl;
	}

	cout << endl;
	system("pause");
	return 0;
}