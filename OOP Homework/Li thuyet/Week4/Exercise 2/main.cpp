#include "SoPhuc.h"
#include <iostream>
#include <conio.h>
using namespace std;

int main(int argc, char* argv[]) {
	//Khởi tạo và yêu cầu nhập hai số phức
	SoPhuc a, b;
	cout << "Nhap so phuc a: ";
	cin >> a;
	cout << "Nhap so phuc b: ";
	cin >> b;

	//Xuất hai số phức và kết quả các phép tính
	cout << "\nSo phuc a = " << a;
	cout << "\nSo phuc b = " << b;
	cout << "\nTong a + b = " << a + b;
	cout << "\nHieu a - b = " << a - b;
	cout << "\nTich a * b = " << a * b;
	cout << "\nThuong a / b = " << a / b << "\n";

	_getch();
	return 1;
}