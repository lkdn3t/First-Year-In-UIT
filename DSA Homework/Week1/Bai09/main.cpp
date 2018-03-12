#include "TangGiam.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
	//Khởi tạo n và kiểm tra n phải số nguyên dương hay không
	int n;
	if (argc > 1) {
		n = atoi(argv[1]);
		if (n <= 0) {
			cout << "Vui long nhap so nguyen duong!\n";
			return 0;
		}
	}
	else {
		cout << "Khong du tham so nhap vao!\n";
		return 0;
	}

	//Kiểm tra tính tăng giảm của các chữ số n từ trái sang phải
	int kt = KTTangGiam(n);
	cout << "So nhap vao: " << n << "\n";
	kt == 1 ? cout << "Cac chu so cua " << n << " tang dan tu trai sang phai\n"
		: kt == -1 ? cout << "Cac chu so cua " << n << " giam dan tu trai sang phai\n"
		: cout << "Cac chu so cua " << n << " khong tang cung khong giam tu trai sang phai\n";

	system("pause");
	return 1;
}