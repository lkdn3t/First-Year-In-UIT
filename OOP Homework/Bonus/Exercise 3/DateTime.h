#include <iostream>
using namespace std;

class DateTime {
private:
	int month;
	int year;

public:
	bool isLeapYear();
	void setMonth();
	void setYear();

	int DayOfMonth();
	int DayOfWeek();
	void printCalendar();
};