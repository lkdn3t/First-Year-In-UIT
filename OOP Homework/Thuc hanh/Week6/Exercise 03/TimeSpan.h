#include <iostream>
#include <iomanip>

using namespace std;

class TimeSpan {
private:
	int hour;
	int min;
	int sec;

public:
	int  ToSec() const;
	void ToTime(int TotalSec);
	bool isTime() const;

public:
	TimeSpan(int hour = 0, int min = 0, int sec = 0);
	TimeSpan(const TimeSpan &t);

public:
	TimeSpan operator+(const TimeSpan& t) const;
	TimeSpan operator-(const TimeSpan& t) const;

public:
	bool operator==(const TimeSpan& t) const;
	bool operator!=(const TimeSpan& t) const;
	bool operator> (const TimeSpan& t) const;
	bool operator< (const TimeSpan& t) const;
	bool operator>=(const TimeSpan& t) const;
	bool operator<=(const TimeSpan& t) const;

public:
	friend ostream& operator<<(ostream& os, const TimeSpan& t);
	friend istream& operator>>(istream& is, TimeSpan& t);
};