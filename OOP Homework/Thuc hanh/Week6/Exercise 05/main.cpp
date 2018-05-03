#include "Date.h"

using namespace std;

int main() {
	Date d1, d2;
	do {
		cout << "Nhap ngay thang t1: ";
		cin >> d1;
	} while (!d1.isDate());
	
	do {
		cout << "Nhap ngay thang t2: ";
		cin >> d2;
	} while (!d2.isDate());
	
	cout << "\nNgay thang t1: " << d1;
	cout << "\nNgay thang t2: " << d2;
	cout << "\nHai ngay cach nhau " << d1 - d2 << " ngay" << endl;

	system("pause");
	return 0;
}