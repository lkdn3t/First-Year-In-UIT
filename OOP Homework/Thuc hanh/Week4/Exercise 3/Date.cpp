#include "Date.h"
using namespace std;

//Construtor cho ngày tháng năm
Date::Date(int d, int m, int y): day(d), month(m), year(y) {}
Date::Date(const Date &date) {
    this->day   = date.day;
    this->month = date.month;
    this->year  = date.year; 
}

//Các hàm get - set
int  Date::getDay()   const    { return day;      }
int  Date::getMonth() const    { return month;    }
int  Date::getYear()  const    { return year;     }
void Date::setDay(int d)       { this->day   = d; }
void Date::setMonth(int m)     { this->month = m; }
void Date::setYear(int y)      { this->year  = y; }
    
//Kiểm tra năm nhuận
bool Date::isLeapYear() const {
    return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
}

//Tìm số ngày của một tháng
int Date::DayOfMonth() const {
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return 28 + isLeapYear();
        default:
            return -1;
    }
}

//Tìm số ngày của một năm
int Date::DayOfYear() const {
    return 365 + isLeapYear();
}

//Nhập ngày
void Date::getDate() {
    do {
        cout << " - Nhap ngay: " ; cin >> day;
        cout << " - Nhap thang: "; cin >> month;
        cout << " - Nhap nam: "  ; cin >> year;
    } while (day < 1 || month < 1 || year < 1 || day > DayOfMonth() || month > 12);
}

//Xuất ngày (định dạng dd/mm/yyyy)
void Date::putDate() const {
    cout << setw(2) << setfill('0') << day;
    cout << "/" << setw(2) << setfill('0') << month;
    cout << "/" << setw(4) << setfill('0') << year << "\n";
}

//Đưa ngày về đúng định dạng (dành cho phép toán)
void Date::convertDate() {
    //TH1: vượt quá số ngày trong tháng
    while (day > DayOfMonth()) {
        day -= DayOfMonth();
        if (month == 12) {
            month = 1;
            year++;
        } else month++;
    }

    //TH2: thiếu ngày trong tháng đó
    while (day < 1) {
        if (month == 1) {
            month = 12;
            day += 31;
            year--;
        }
        else {
            month--;
            day += DayOfMonth();
        }
    }
}

//Cộng ngày cho một Date
Date Date::addDays(int days) const {
    Date sumDate(day + days, month, year);
    sumDate.convertDate();
    return sumDate;
}

//Bản chất các hàm tính toán còn lại đều từ phép cộng và suy
Date Date::subDays(int days) const  { return addDays(-days); }
Date Date::addOne() const           { return addDays(1);     }
Date Date::subOne() const           { return addDays(-1);    }

//Tìm độ lệch giữa hai ngày (tính bằng ngày)
int Date::DiffDays(const Date& date) const {
    Date date1(day, month, year);
    Date date2(date);

    //Nếu trùng năm
    if (date1.year == date2.year) {
        //Nếu trùng tháng: so sánh ngày
        if (date1.month == date2.month)
            return abs(date1.day - date2.day);

        //Nếu khác tháng: tìm tháng lớn hơn
        //Sau đó giảm tháng cho bằng nhau (đẩy dồn cho ngày)
        else {
            if (date1.month > date2.month)
                swap(date1, date2);

            while (date2.month > date1.month) {
                date2.month--;
                date2.day += date2.DayOfMonth();
            }
            return abs(date2.day - date1.day);
        }
    }
    //Nếu khác năm, đẩy dồn cho tháng
    //Sau đó đẩy tháng dồn cho ngày đến khi tháng, năm
    else {
        if (date1.year > date2.year)
            swap(date1, date2);
        
        if (date2.month > 2 && date2.isLeapYear())
            date2.day++;
        while (date2.year > date1.year) {
            date2.year--;
            date2.day += date2.DayOfYear();
        }
        return date1.DiffDays(date2);
    }
}