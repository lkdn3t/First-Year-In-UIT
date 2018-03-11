#include "IntArray.h"
#include <iostream>
#include <ctime>
#include <cstdio>
using namespace std;

//Sinh mảng khi khai báo
IntArray::IntArray() {
	n = getLarge();
	cout << "\n...Sinh mang ngau nhien gom " << n << " phan tu...\n";
	setArray();
}

//Xoá mảng khi không cần dùng
IntArray::~IntArray() {
	cout << "\nDa xoa mang!\n";
}

//Lấy số lượng phần tử để tạo mảng
int IntArray::getLarge() {
	cout << "Nhap so luong phan tu: ";
	cin >> n;
	return n;
}

//Sinh mảng ngẫu nhiên gồm n phần tử
void IntArray::setArray() {
	a = new int[n];
	srand((unsigned int)time(NULL));
	for (int i = 0; i < n; ++i)
		a[i] = rand() % 100 - 50;
}

//In mảng đã tạo
void IntArray::printArray() {
	for (int i = 0; i < n; ++i) cout << a[i] << " ";
	cout << "\n";
}

//Tìm số âm lớn nhất
int IntArray::MaxNegElement() {
	int ans = 1;
	for (int i = 0; i < n; ++i)
		if (a[i] < 0 && (a[i] > ans || ans == 1))
			ans = a[i];
	return ans;
}

//Đếm số lượng xuất hiện của một số nguyên x
int IntArray::countElement(int &x) {
	cout << "\nNhap so nguyen x can dem trong mang: ";
	cin >> x;

	int count = 0;
	for (int i = 0; i < n; ++i)
		if (a[i] == x) ++count;
	return count;
}

//Kiểm tra mảng có tăng dần hay không
bool IntArray::isIncArray() {
	if (n == 1) return false;
	for (int i = 0; i < n - 1; ++i)
		if (a[i] >= a[i + 1]) return false;
	return true;
}

//Sắp xếp mảng tăng dần
void IntArray::sortArray() {
	for (int i = 0; i < n - 1; ++i)
		for (int j = i; j < n; ++j)
			if (a[i] > a[j]) swap(a[i], a[j]);
}