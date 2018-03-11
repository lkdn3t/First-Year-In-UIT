#include "DateTime.h"
#include <iostream>
using namespace std;

//Kiểm tra năm nhuận
bool DateTime::isLeapYear() {
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

//Nhập vào tháng và năm
void DateTime::setMonth() {
	cout << "Nhap vao thang: ";
	cin >> month;
	while (month < 1 || month>12) {
		cout << "Nhap lai thang: ";
		cin >> month;
	}
}

void DateTime::setYear() {
	cout << "Nhap vao nam: ";
	cin >> year;
	while (year < 0) {
		cout << "Nhap lai nam: ";
		cin >> year;
	}
}

//Tìm số ngày trong một tháng
int DateTime::DayOfMonth() {
	switch (month) {
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		return 31;
	case 4: case 6: case 9: case 11:
		return 30;
	case 2:
		return isLeapYear() ? 29 : 28;
	}
}

//Tìm thứ của ngày đầu tiên trong tháng (ngày 1)
int DateTime::DayOfWeek() {
	int tMonth = month;
	int tYear = year;

	if (tMonth < 3) {
		tMonth += 12;
		tYear -= 1;
	}

	int weekday = (1 + 2 * tMonth + (3 * (tMonth + 1)) / 5 + tYear + (tYear / 4)) % 7;
	return weekday == 0 ? 8 : weekday + 1;
}

//In lịch của tháng - năm nhập vào
void DateTime::printCalendar() {
	//In các thứ ở đầu lịch
	cout << "\n\t\t   LICH THANG " << month << "/" << year << "\n\n";
	cout << "Thu 2\tThu 3\tThu 4\tThu 5\tThu 6\tThu 7\tChu nhat\n\n";

	//Xác định thứ của ngày 1 (ngày đầu của tháng và bắt đầu ghi)
	int weekday = DayOfWeek();
	for (int i = 2; i < weekday; ++i) cout << "\t";

	for (int day = 1; day <= DayOfMonth(); ++day, ++weekday) {
		cout << "  " << day << "\t";
		if (weekday == 8) {
			weekday = 1;
			cout << "\n\n";
		}
	}
	cout << "\n\n";
}