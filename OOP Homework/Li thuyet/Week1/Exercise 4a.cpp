#include <iostream>
using namespace std;

//Định dạng kiểu dữ liệu ngày, gồm ngày - tháng - năm
struct date {
	int day;
	int month;
	int year;
};

//Kiểm tra năm nhuận
bool isLeapYear(int year) {
	return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
}

//Định số ngày trong tháng
int DayOfMonth(int month, int year) {
	switch (month) {
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		return 31;
	case 4: case 6: case 9: case 11:
		return 30;
	case 2:
		return isLeapYear(year) ? 29 : 28;
	}
}

//Tìm ngày tiếp theo
date NextDay(date Today) {
	//Nếu ngày đã nhập trùng với số ngày của tháng (ngày cuối của tháng)
	//Ngày tiếp theo sẽ là ngày 1
	if (Today.day == DayOfMonth(Today.month, Today.year)) {
		Today.day = 1;
		//Nếu là tháng 12 thì đưa sang năm mới
		if (Today.month == 12) {
			Today.month = 1;
			Today.year++;
		}
		//Nếu là các tháng khác thì tăng tháng
		else Today.month++;
	}
	//Nếu không phải là ngày của cuối tháng thì tăng một ngày
	else Today.day++;
	return Today;
}

//In ngày theo định dạng dd/mm/yyyy
void printDay(date Day) {
	cout << Day.day << "/" << Day.month << "/" << Day.year << "\n";
}

int main() {
	//Yêu cầu nhập ngày
	date Today, Nextday;
	cout << "Nhap ngay: ";	cin >> Today.day;
	cout << "Nhap thang: "; cin >> Today.month;
	cout << "Nhap nam: ";	cin >> Today.year;
	
	//Xuất ngày đã nhập
	cout << "Ngay da nhap: ";
	printDay(Today);

	//Xuất ngày tiếp theo
	cout << "Ngay tiep theo: ";
	Nextday = NextDay(Today);
	printDay(Nextday);

	system("pause");
}