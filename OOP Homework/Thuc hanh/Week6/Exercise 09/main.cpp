#include "INTEGER.h"

using namespace std;

int main() {
	INTEGER a, b;
	cout << "Nhap so nguyen a: ";
	cin >> a;
	cout << "Nhap so nguyen b: ";
	cin >> b;

	cout << "\nTong " << a << " + " << b << " = " << a + b;
	cout << "\nHieu " << a << " - " << b << " = " << a - b;
	cout << "\nTich " << a << " * " << b << " = " << a * b;
	
	if (b == 0) cout << "\nKhong the chia cho 0 ";
	else {
		cout << "\nChia nguyen " << a << " / " << b << " = " << a / b;
		cout << "\nChia du " << a << " % " << b << " = " << a % b;
	}

	cout << "\n\nSo sanh: ";
	if (a > b) cout << a << " > " << b;
	else if (a < b) cout << a << " < " << b;
	else cout << a << " = " << b;

	cout << "\n\n";
	system("pause");
	return 0;
}