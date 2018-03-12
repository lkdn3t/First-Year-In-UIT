//Ví dụ đề bài sai: 1 không là số nguyên tố
#include <iostream>
#include "NguyenTo.h"
using namespace std;

int main(int argc, char *argv[]) {
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

	//Kiểm tra n có toàn chữ số nguyên tố
	cout << "So nhap vao: " << n << "\n";
	int kt = KiemTraToanSNT(n);
	kt ? cout << n << " toan chua chu so nguyen to\n" : cout << n << " khong chua toan chu so nguyen to\n";
	
	system("pause");
	return 1;
}