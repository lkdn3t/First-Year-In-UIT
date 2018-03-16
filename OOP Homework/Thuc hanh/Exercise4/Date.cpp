#include "Date.h"
using namespace std;

//Tạo constructor cho class Date
Date::Date(int d, int m, int y) {
    day = d; month = m; year = y;
}

//Nhập ngày (kiểm tra điều kiện)
void Date::inputDate() {
    cout << "\tNhap ngay: " ;  cin >> day;
    cout << "\tNhap thang: ";  cin >> month;
    cout << "\tNhap nam: "  ;  cin >> year;

    if (day < 1 || month < 1 || year < 1 || day > DayOfMonth() || month > 12) {
        cout << "\nNgay nhap khong hop le!";
        cout << "\nVui long nhap lai ngay\n";
        inputDate();
    }
}

//Xuất ngày theo định dạng d/m/y
void Date::putDate() {
    cout << day << "/" << month << "/" << year << "\n";
}

//Tạo các hàm get, set cho class Date
int  Date::get_day()         { return day;      }
int  Date::get_month()       { return month;    }
int  Date::get_year()        { return year;     }
void Date::set_day(int d)    { this->day   = d; }
void Date::set_month(int m)  { this->month = m; }
void Date::set_year(int y)   { this->year  = y; }

//Kiểm tra năm nhuận
bool Date::isLeapYear() {
    return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
}

//Tìm số ngày trong tháng đã nhập
int Date::DayOfMonth() {
    switch (month) {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        return 31;
    case 4: case 6: case 9: case 11:
        return 30;
    case 2:
        return isLeapYear() ? 29 : 28;
    default:
        return -1;
    }
}

//Tìm ngày kế tiếp (trường hợp đặc biệt là ngày cuối tháng)
Date Date::NextDay() {
    Date nDay(day, month, year);
    if (day == DayOfMonth()) {
        nDay.day = 1;
        if (month == 12) {
            nDay.month = 1;
            nDay.year++;
        }
        else nDay.month++;
    }
    else nDay.day++;
    return nDay;
}