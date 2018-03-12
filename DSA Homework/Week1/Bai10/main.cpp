#include <iostream>
#include "SapXep.h"
using namespace std;

int main(int argc, char* argv[]) {
	int *arr, n = argc - 1;
	//Khởi tạo n và kiểm tra n phải số nguyên dương hay không
	if (argc > 1) {
		cout << "So phan tu trong mang nhap vao: " << n << endl;
		arr = new int[n];
		for (int i = 0; i < n; ++i)
			arr[i] = atoi(argv[i + 1]);
	}
	else {
		cout << "Vui long nhap mot mang cach nhau boi khoang trang!\n";
		return 0;
	}

	//Nhập mảng và in ra mảng ban đầu và mảng đã sắp xếp
	cout << "Mang ban dau: ";
	XuatMang(arr, n);

	//Sắp xếp mảng theo đề bài và in ra mảng đã sắp xếp
	cout << "Mang sau khi sap xep: ";
	SapXepMang(arr, n);
	XuatMang(arr, n);

	delete[]arr;
	system("pause");
	return 1;
}