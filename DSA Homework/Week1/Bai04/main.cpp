#include "Date.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
	//Khởi tạo ngày bằng tham số nhập vào
	Date date;
	if (argc > 3) {
		date.day   = atoi(argv[1]);
		date.month = atoi(argv[2]);
		date.year  = atoi(argv[3]);
	}
	else {
		cout << "Khong du tham so nhap vao!\n";
		return 0;
	}
	
	//Xuất ngày đã nhập, kiểm tra tính hợp lệ
	cout << "Ngay nhap vao: "; outputDate(date);
	if (!isDate(date)) {
		cout << "Ngay nhap vao khong hop le!\n";
		return 0;
	}
	
	//Tìm ngày trước và sau (nếu ngày hợp lệ)
	Date next = NextDay(date);
	Date last = LastDay(date);
	cout << "Ngay truoc: "; outputDate(last);
	cout << "Ngay sau: "; outputDate(next);

	system("pause");
	return 1;
}