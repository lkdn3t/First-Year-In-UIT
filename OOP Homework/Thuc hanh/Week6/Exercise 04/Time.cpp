#include "Time.h"

using namespace std;

//Convert a Time to Seconds
int Time::ToSec() const {
	return hour * 3600 + min * 60 + sec;
}

//Convert Seconds to a Time
void Time::ToTime(int TotalSec) {
	sec = TotalSec % 86400;
	min = sec / 60;
	sec = sec % 60;
	hour = min / 60;
	min %= 60;
}

//Check if the input-Time is correct
bool Time::isTime() const {
	return (hour >= 0 && min >= 0 && sec >= 0) && (hour < 24 && min < 60 && sec < 60);
}

Time::Time(int hour, int min, int sec) {
	this->hour = hour;
	this->min = min;
	this->sec = sec;
}

Time::Time(const Time & t) {
	hour = t.hour;
	min = t.min;
	sec = t.sec;
}

//Add t second(s) of Time
//If TotalSec > TotalSec of Day, mod TotalSec (as Time of a new day)
Time Time::operator+(int t) const{
	int TotalSec = ToSec() + t;
	Time Sum;
	Sum.ToTime(TotalSec);
	return Sum;
}

//Subtract t second(s) of Time
//If DiffSec < 0, mod abs(DiffSec) (as Time of a new day)
Time Time::operator-(int t) const {
	int DiffSec = ToSec() - t;
	if (DiffSec < 0) DiffSec = DiffSec % 86400 + 86400;
	Time Diff;
	Diff.ToTime(DiffSec);
	return Diff;
}

//Subtract t second(s) of Time
//If DiffSec < 0, add 86400 (as Time of a new day)
Time Time::operator-(const Time & t) const {
	int DiffSec = ToSec() - t.ToSec();
	if (DiffSec < 0) DiffSec += 86400;
	Time Diff;
	Diff.ToTime(DiffSec);
	return Diff;
}

Time& Time::operator++() {
	*this = *this + 1;
	return *this;
}

Time& Time::operator--() {
	*this = *this - 1;
	return *this;
}

//Print a format-Time (hh:mm:ss)
ostream & operator<<(ostream & os, const Time & t) {
	os << setw(2) << setfill('0') << t.hour;
	os << ":" << setw(2) << setfill('0') << t.min;
	os << ":" << setw(2) << setfill('0') << t.sec;
	return os;
}

//Input a Time from hour, minute, second
istream & operator>>(istream & is, Time & t) {
	int hour, min, sec;
	is >> hour >> min >> sec;
	t = Time(hour, min, sec);
	return is;
}