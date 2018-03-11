#include "Array.h"
#include <iostream>
using namespace std;

//Khởi tạo mảng theo phương thức nhập từ bàn phím
void Array::setArray() {
	cout << "Nhap so luong phan tu: ";
	cin >> NumberOfElements;
	
	Elements = new int[NumberOfElements];
	for (int i = 0; i < NumberOfElements; ++i) {
		cout << "- Nhap phan tu thu " << i + 1 << ": ";
		cin >> Elements[i];
	}
}

//In mảng đã nhập vào
void Array::putArray() {
	cout << "\nMang da nhap vao: ";
	for (int i = 0; i < NumberOfElements; ++i)
		cout << Elements[i] << " ";
	cout << "\n";
}

//Xoá mảng (cần thiết!?)
void Array::delArray() {
	NumberOfElements = 0;
	delete[]Elements;
}

//Đếm số lần xuất hiện của một phần tử trong mảng
int Array::countElement(int &ele) {
	cout << "\nNhap phan tu x can dem: ";
	cin >> ele;

	int count = 0;
	for (int i = 0; i < NumberOfElements; ++i)
		if (Elements[i] == ele) ++count;
	return count;
}

//Kiểm tra mảng có là mảng tăng dần
bool Array::isIncreaseArray() {
	if (NumberOfElements == 1) return false;
	for (int i = 1; i < NumberOfElements; ++i)
		if (Elements[i - 1] >= Elements[i]) return false;
	return true;
}

//Tìm phần tử lẻ nhỏ nhất trong mảng
int Array::minOddElement() {
	int ans = 0;
	for (int i = 0; i < NumberOfElements; ++i)
		if (Elements[i] % 2 == 1 && (Elements[i] < ans || ans == 0))
			ans = Elements[i];
	return ans;
}