#include <iostream>
#include <iomanip>

using namespace std;

class Time {
private:
	int hour;
	int min;
	int sec;

public:
	int  ToSec() const;
	void ToTime(int TotalSec);
	bool isTime() const;

public:
	Time(int hour = 0, int min = 0, int sec = 0);
	Time(const Time &t);

public:
	Time operator+(int t) const;
	Time operator-(int t) const;
	Time operator-(const Time& t) const;
	Time& operator++();
	Time& operator--();


public:
	friend ostream& operator<<(ostream& os, const Time& t);
	friend istream& operator>>(istream& is, Time& t);
};