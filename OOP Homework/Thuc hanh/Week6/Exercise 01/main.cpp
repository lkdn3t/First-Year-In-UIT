#include "Complex.h"

using namespace std;

int main(int argc, char *argv[]) {
	//Nhập và xuất hai số phức
	Complex c1, c2;
	cout << "Nhap so phuc thu nhat: "; cin >> c1;
	cout << "Nhap so phuc thu hai: " ; cin >> c2;

	cout << "\nSo phuc thu nhat: " << c1 << endl;
	cout << "So phuc thu hai: "    << c2 << endl;

	//Xuất các phép tính với số phức
	cout << "\nTong hai so phuc = " << c1 + c2 << endl;
	cout << "\nHieu hai so phuc = " << c1 - c2 << endl;
	cout << "\nTich hai so phuc = " << c1 * c2 << endl;

	if (!c2.getReal() && !c2.getImg()) {
		cout << "\nKhong the chia so phuc cho 0." << endl;
	}
	else {
		cout << "\nThuong hai so phuc = " << c1 / c2 << endl;
	}

	cout << endl;
	system("pause");
	return 0;
}