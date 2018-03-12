#include "SapXep.h"
#include <iostream>
using namespace std;

//Nhập mảng arr[] gồm n phần tử
void NhapMang(int arr[], int n) {
	for (int i = 0; i < n; ++i) {
		cout << "a[" << i << "] = ";
		cin >> arr[i];
	}
}

//Xuất mảng arr[] gồm n phần tử
void XuatMang(int arr[], int n) {
	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";
	cout << "\n";
}

//Sắp xếp mảng tăng dần từ vị trí left -> right
void SapXepTang(int arr[], int left, int right) {
	for (int i = left; i < right; ++i)
		for (int j = i; j <= right; ++j)
			if (arr[i] > arr[j]) swap(arr[i], arr[j]);
}

//Sắp xếp mảng giảm dần từ vị trí left -> right
void SapXepGiam(int arr[], int left, int right) {
	for (int i = left; i < right; ++i)
		for (int j = i; j <= right; ++j)
			if (arr[i] < arr[j]) swap(arr[i], arr[j]);
}

//Sắp xếp mảng, phần âm trái giảm dần, phần còn lại tăng dần về phải
void SapXepMang(int arr[], int n) {
	//Đưa hết số âm về phần trái mảng, dùng biến chạy để đánh dấu vị trí số âm cuối cùng
	int vt = -1;
	for (int i = vt + 1; i < n; ++i)
		if (arr[i] < 0) swap(arr[++vt], arr[i]);

	//Sắp xếp phần mảng âm bên trái giảm, phần còn lại tăng
	SapXepGiam(arr, 0, vt);
	SapXepTang(arr, vt + 1, n - 1);
}

//Cách khác: áp dụng tư tưởng QuickSort để đưa phần âm về bên trái, dương về bên phải
//Bằng cách đặt pivot = 0 và left, right cho con chạy để đánh dấu 2 vị trí