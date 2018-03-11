#include "Matrix.h"
#include <iostream>
#include <conio.h>
using namespace std;

int main() {
	//Khởi tạo hai ma trận A, B 
	//và cho sinh ngẫu nhiên theo cỡ nhập vào
	Matrix A, B;
	cout << "...Sinh ngau nhien ma tran A...\n";
	A.randomize();
	cout << "\nMa tran A:\n\n" << A;

	cout << "...Sinh ngau nhien ma tran B...\n";
	B.randomize();
	cout << "\nMa tran B:\n\n" << B;

	//Xuất tổng và tích hai ma trận
	cout << "\n...Tong A + B...\n";
	A.getCol() == B.getCol() && A.getRow() == B.getRow()
		? cout << "\n" << A + B << "\n"
		: cout << "ERROR: Hai ma tran phai cung co!\n";

	cout << "\n...Tich A * B...\n";
	A.getCol() == B.getRow()
		? cout << "\n" << A * B << "\n"
		: cout << "ERROR: Hang cua A phai bang cot cua B!";

	_getch();
	return 0;
}