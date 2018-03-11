#include "IntArray.h"
#include <iostream>
using namespace std;

int main() {
	//Khởi tạo mảng ngẫu nhiên và in mảng
	IntArray a;
	a.setArray();
	cout << "\nMang sinh ngau nhien: ";
	a.printArray();

	//Yêu cầu 1: Tìm phần tử âm lớn nhất
	int maxNegEle = a.MaxNegElement();
	maxNegEle == 1	? cout << "\nMang khong co phan tu am.\n" 
					: cout << "\nPhan tu am lon nhat = " << maxNegEle << "\n";

	//Yêu cầu 2: Đếm số lượng của phần tử x trong mảng
	int x;
	cout << "\n=> So lan xuat hien cua phan tu " << x << " la " << a.countElement(x) << " lan.\n";

	//Yêu cầu 3: Kiểm tra mảng có tăng dần hay không
	a.isIncArray()	? cout << "\n=> Mang tang dan.\n" 
					: cout << "\n=> Mang khong tang dan.\n";

	//Yêu cầu 4: Sắp xếp mảng tăng dần
	a.sortArray();
	cout << "\n=> Mang sap xep tang dan: ";
	a.printArray();
	
	//Dừng màn hình
	cout << "\n\n";
	system("pause");
	return 0;
}