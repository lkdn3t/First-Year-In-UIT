#include "DoiTien.h"
#include <iostream>
using namespace std;

//Số tờ = phép chia lấy nguyên số tiền hiện có cho mệnh giá
//Sau khi đổi thì phần còn thừa (phần dư) đổi cho mệnh giá nhỏ hơn
void DoiTien(int n) {
	if (n < 0) {
		cout << "So tien nhap vao khong hop le!\n";
		return;
	}

	int temp = n;
	int to10, to5, to1;
	to10 = temp / 10;
	temp %= 10;
	to5 = temp / 5;
	temp %= 5;
	to1 = temp;
	cout << n << "d = " << to10 << " to 10d + " << to5 << " to 5d + " << to1 << " to 1d\n";
}