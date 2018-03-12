#include "Time.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
	//Gắn thời gian cho t1 và t2
	Time t1, t2;
	if (argc > 6) {
		setTime(t1, atoi(argv[1]), atoi(argv[2]), atoi(argv[3]));
		setTime(t2, atoi(argv[4]), atoi(argv[5]), atoi(argv[6]));
	}
	else {
		cout << "Khong du tham so nhap vao!\n";
		system("pause");
		return 1;
	}

	//Xuất hai thời gian đã nhập
	cout << "Thoi gian t1 = "; outputTime(t1);
	cout << "Thoi gian t2 = "; outputTime(t2);
	cout << "\n";

	//Kiểm tra tính hợp lệ của hai thời gian nhập vào
	isTime(t1) ? cout << "Thoi gian t1 hop le\n" : cout << "Thoi gian t1 khong hop le\n";
	isTime(t2) ? cout << "Thoi gian t2 hop le\n" : cout << "Thoi gian t2 khong hop le\n";
	cout << "\n";

	//Xuất tổng và hiệu hai thời gian
	if (isTime(t1) && isTime(t2)) {
		Time sum = sumTime(t1, t2);
		Time diff = diffTime(t1, t2);
		cout << "Tong t1 + t2 = "; outputTime(sum);
		cout << "Hieu |t1 - t2| = "; outputTime(diff);
	}
	else cout << "Khong the thuc hien phep toan vi co thoi gian khong hop le!\n";
	system("pause");
	return 1;
}