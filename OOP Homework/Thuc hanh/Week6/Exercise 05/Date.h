#include <iostream>
#include <iomanip>

using namespace std;

class Date {
private:
	int day;
	int month;
	int year;
	bool isLeapYear();

public:
	Date(int dd = 1, int mm = 1, int yy = 1900);
	Date(const Date& d);

public:
	void setDay(int dd);
	void setMonth(int mm);
	void setYear(int yy);
	bool isDate();

public:
	int getDay() const;
	int getMonth() const;
	int getYear() const;

public:
	int DayOfMonth();
	int DayOfYear();

public:
	Date operator+(int delta) const;
	Date operator-(int delta) const;
	int  operator-(const Date& date) const;

public:
	friend ostream& operator<<(ostream& os, const Date& date);
	friend istream& operator>>(istream& is, Date& date);
};