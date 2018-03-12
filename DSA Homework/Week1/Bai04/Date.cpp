#include <iostream>
#include <iomanip>
#include "Date.h"
using namespace std;

//Hàm kiểm tra năm nhuận
bool isLeapYear(int year) {
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

//Hàm kiểm tra tính hợp lệ của thời gian nhập vào
bool isDate(Date date) {
	return date.year <= 0
		|| date.month < 1 || date.month > 12
		|| date.day < 1 || date.day > DayOfMonth(date.month, date.year) ? false : true;
}

//Hàm tìm số ngày của tháng trong năm
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

//Hàm in ra ngày theo định dạng dd/mm/yyyy
void outputDate(Date date) {
	cout << setfill('0') << setw(2) << date.day;
	cout << "/" << setfill('0') << setw(2) << date.month;
	cout << "/" << setfill('0') << setw(4) << date.year << "\n";
}

//Hàm tìm ngày kế tiếp
Date NextDay(Date date) {
	//Nếu là cuối tháng (ngày = số ngày trong tháng đó)
	if (date.day == DayOfMonth(date.month, date.year)) {
		date.day = 1;
		//Nếu là ngày cuối của năm (31/12)
		if (date.month == 12) {
			date.month = 1;
			date.year++;
		}
		//Không thì tăng tháng
		else date.month++;
	}
	//Nếu không là ngày cuối tháng thì tăng ngày
	else date.day++;
	return date;
}

//Hàm tìm ngày trước
Date LastDay(Date date) {
	//Nếu là đầu tháng (ngày = 1)
	if (date.day == 1) {
		//Nếu là ngày đầu năm (1/1)
		if (date.month == 1) {
			date.day = 31;
			date.month = 12;
			date.year--;
		}
		//Nếu không thì ngày trước = số ngày của tháng trước
		else {
			date.month--;
			date.day = DayOfMonth(date.month, date.year);
		}
	}
	//Nếu không là đầu tháng thì giảm ngày
	else date.day--;
	return date;
}