#include "TimeSpan.h"
using namespace std;

//Constructor cho TimeSpan
TimeSpan::TimeSpan(int hh, int mm, int ss): hour(hh), min(mm), sec(ss) {}

//Nhập thời gian
void TimeSpan::getTime() {
    cout << "   - Nhap gio: " ; cin >> hour;
    cout << "   - Nhap phut: "; cin >> min;
    cout << "   - Nhap giay: "; cin >> sec; 
    cout << "\n";

    if (hour < 0 || min < 0 || sec < 0 || hour > 23 || min > 59 || sec > 59) {
        cout << " Nhap lai thoi gian:\n";
        getTime();
    }
}

//Xuất thời gian (định dạng hh:mm:ss)
void TimeSpan::putTime() {
    cout << setw(2) << setfill('0') << hour;
    cout << ":" << setw(2) << setfill('0') << min;
    cout << ":" << setw(2) << setfill('0') << sec << "\n";
}

//Các hàm get - set
int  TimeSpan::getHour()              { return hour; }
int  TimeSpan::getMin()               { return min;  }
int  TimeSpan::getSec()               { return sec;  }
void TimeSpan::setHour(int hh)        { hour = hh;   }
void TimeSpan::setMin(int mm)         { min  = mm;   }
void TimeSpan::setSec(int ss)         { sec  = ss;   }

//Convert TimeSpan <-> second
int  TimeSpan::ToSec() { return hour * 3600 + min * 60 + sec; }
void TimeSpan::ToTime(int ss) {
    min  = ss / 60;
    sec  = ss % 60;
    hour = min / 60;
    min  = min % 60;
}

//Cộng hai thời gian (quy đổi ra tổng giây và convert)
TimeSpan TimeSpan::Add(TimeSpan time) {
    int SumSec = ToSec() + time.ToSec();
    TimeSpan SumTime;
    SumTime.ToTime(SumSec);
    return SumTime;
}

//Trừ hai thời gian (quy đổi ra hiệu giây và convert)
TimeSpan TimeSpan::Subtract(TimeSpan time) {
    int DiffSec = ToSec() - time.ToSec();
    if (DiffSec < 0) DiffSec = -DiffSec;
    TimeSpan DiffTime;
    DiffTime.ToTime(DiffSec);
    return DiffTime;
}

bool TimeSpan::isEqual      (TimeSpan time)       { return ToSec() == time.ToSec(); }
bool TimeSpan::isNotEqual   (TimeSpan time)       { return ToSec() != time.ToSec(); }
bool TimeSpan::isBigger     (TimeSpan time)       { return ToSec() >  time.ToSec(); }
bool TimeSpan::isSmaller    (TimeSpan time)       { return ToSec() <  time.ToSec(); }
bool TimeSpan::isNotBigger  (TimeSpan time)       { return ToSec() <= time.ToSec(); }
bool TimeSpan::isNotSmaller (TimeSpan time)       { return ToSec() >= time.ToSec(); }