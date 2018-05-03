#include "TimeSpan.h"

using namespace std;

//Convert a TimeSpan to Seconds
int TimeSpan::ToSec() const {
	return hour * 3600 + min * 60 + sec;
}

//Convert Seconds to a TimeSpan
void TimeSpan::ToTime(int TotalSec) {
	sec  = TotalSec;
	min  = sec / 60;
	sec  = sec % 60;
	hour = min / 60;
	min %= 60;
}

//Check if the input-TimeSpan is correct
bool TimeSpan::isTime() const {
	return (hour >= 0 && min >= 0 && sec >= 0) && (hour < 24 && min < 60 && sec < 60);
}

TimeSpan::TimeSpan(int hour, int min, int sec) {
	this->hour = hour;
	this->min  = min;
	this->sec  = sec;
}

TimeSpan::TimeSpan(const TimeSpan & t) {
	hour = t.hour;
	min  = t.min;
	sec  = t.sec;
}

//Sum of 2 TimeSpan(s) = Sum Seconds
TimeSpan TimeSpan::operator+(const TimeSpan & t) const {
	TimeSpan Sum;
	Sum.ToTime(ToSec() + t.ToSec());
	return Sum;
}

//Difference of 2 TimeSpan(s) = Difference Seconds 
TimeSpan TimeSpan::operator-(const TimeSpan & t) const {
	TimeSpan Diff;
	Diff.ToTime(abs(ToSec() - t.ToSec()));
	return Diff;
}

//Compare-operator of 2 TimeSpan(s) by comparing Total each total Seconds
bool TimeSpan::operator==(const TimeSpan & t) const { return ToSec() == t.ToSec(); }
bool TimeSpan::operator!=(const TimeSpan & t) const { return ToSec() != t.ToSec(); }
bool TimeSpan::operator> (const TimeSpan & t) const { return ToSec() >  t.ToSec(); }
bool TimeSpan::operator< (const TimeSpan & t) const { return ToSec() <  t.ToSec(); }
bool TimeSpan::operator>=(const TimeSpan & t) const { return ToSec() >= t.ToSec(); }
bool TimeSpan::operator<=(const TimeSpan & t) const { return ToSec() <= t.ToSec(); }

//Print a format-TimeSpan (hh:mm:ss)
ostream & operator<<(ostream & os, const TimeSpan & t) {
	os << setw(2) << setfill('0') << t.hour;
	os << ":" << setw(2) << setfill('0') << t.min;
	os << ":" << setw(2) << setfill('0') << t.sec;
	return os;
}

//Input a TimeSpan from hour, minute, second
istream & operator>>(istream & is, TimeSpan & t) {
	int hour, min, sec;
	is >> hour >> min >> sec;
	t = TimeSpan(hour, min, sec);
	return is;
}