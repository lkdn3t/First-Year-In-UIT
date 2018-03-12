#include "BCNN.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	//Khởi tạo hai biến a, b từ tham số đầu vào
	int a, b;
	if (argc > 2) {
		a = atoi(argv[1]);
		b = atoi(argv[2]);

		//Kiểm tra hai số nhập vào có là hai số nguyên dương hay không
		if (a <= 0 || b <= 0) {
			cout << "Vui long chi nhap hai so nguyen duong!\n";
			return 0;
		}
	}
	else {
		cout << "Khong du tham so!\n";
		return 0;
	}

	//Xuất hai số và BSCNN của hai số đó
	cout << "So thu nhat: " << a << "\n";
	cout << "So thu hai: " << b << "\n";
	cout << "Boi chung nho nhat = " << BSCNN(a, b) << "\n";

	system("pause");
	return 1;
}