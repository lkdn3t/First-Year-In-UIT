#include "Date.h"

using namespace std;

bool Date::isLeapYear() {
	return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
}

Date::Date(int dd, int mm, int yy) {
	day = dd; month = mm; year = yy;
}

Date::Date(const Date & d) {
	day   = d.day;
	month = d.month;
	year  = d.year;
}

void Date::setDay(int dd) {
	day = dd;
}

void Date::setMonth(int mm) {
	month = mm;
}

void Date::setYear(int yy) {
	year = yy;
}

bool Date::isDate() {
	return (day > 0 && month > 0 && year > 0) && (day <= DayOfMonth() && month <= 12);
}

int Date::getDay() const {
	return day;
}

int Date::getMonth() const {
	return month;
}

int Date::getYear() const {
	return year;
}

int Date::DayOfMonth() {
	switch (month) {
	case 1: case 3: case 5: case 7: case 8: case 10 :case 12:
		return 31;
	case 4: case 6: case 9: case 11:
		return 30;
	case 2:
		return 28 + isLeapYear();
	}
}

int Date::DayOfYear() {
	return 365 + isLeapYear();
}

Date Date::operator+(int delta) const {
	Date AddDate(*this);
	AddDate.day = day + delta;
	
	while (AddDate.day > AddDate.DayOfMonth()) {
		AddDate.day -= AddDate.DayOfMonth();
		AddDate.month++;

		if (AddDate.month == 13) {
			AddDate.month = 1;
			AddDate.year++;
		}
	}
	return AddDate;
}

Date Date::operator-(int delta) const {
	Date DiffDate(*this);
	DiffDate.day = day - delta;

	while (DiffDate.day < 1) {
		DiffDate.month--;

		if (DiffDate.month == 0) {
			DiffDate.month = 12;
			DiffDate.year--;
		}

		DiffDate.day += DiffDate.DayOfMonth();
	}
	return DiffDate;
}

//Calculate difference days of 2 Date(s)
//Set date2 > date1, add days until month and year of 2 Date(s) are equal
//Result = Difference days
int Date::operator-(const Date & date) const {
	Date date1 = Date(*this);
	Date date2 = Date(date);

	if (date1.year == date2.year) {
		if (date1.month == date2.month)
			return abs(date1.day - date2.day);

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

	else {
		if (date1.year > date2.year)
			swap(date1, date2);

		while (date2.year > date1.year) {
			date2.year--;
			date2.day += date2.DayOfYear();
		}
		return date2 - date1;
	}
}

ostream & operator<<(ostream & os, const Date & date) {
	os << setw(2) << setfill('0') << date.day;
	os << "/" << setw(2) << setfill('0') << date.month;
	os << "/" << setw(2) << setfill('0') << date.year;
	return os;
}

istream & operator>>(istream & is, Date & date) {
	int day, month, year;
	is >> day >> month >> year;
	date = Date(day, month, year);
	return is;
}
