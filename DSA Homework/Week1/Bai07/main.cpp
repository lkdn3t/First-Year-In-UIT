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

	//Phân tích n thành thừa số nguyên tố
	cout << "So nhap vao: " << n << "\n";
	ThuaSoNT(n);
	system("pause");
	return 0;
}