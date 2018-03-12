#include "NguyenTo.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	//Khởi tạo giá trị n từ command line
	int n;
	if (argc > 1) n = atoi(argv[1]);
	else {
		cout << "Khong tu tham so nhap vao\n";
		return 0;
	}

	//Xuất các số nguyên tố nhỏ hơn n
	cout << "So nhap vao: " << n << "\n";
	XuatSNT(n);
	system("pause");
	return 1;
}