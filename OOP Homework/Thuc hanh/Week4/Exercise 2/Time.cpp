#include "Time.h"
using namespace std;

//Constructor cho Time
Time::Time(int hh, int mm, int ss): hour(hh), min(mm), sec(ss) {}

//Nhập thời gian
void Time::getTime() {
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
void Time::putTime() {
    cout << setw(2) << setfill('0') << hour;
    cout << ":" << setw(2) << setfill('0') << min;
    cout << ":" << setw(2) << setfill('0') << sec << "\n";
}

//Các hàm get - set
int  Time::getHour()              { return hour; }
int  Time::getMin()               { return min;  }
int  Time::getSec()               { return sec;  }
void Time::setHour(int hh)        { hour = hh;   }
void Time::setMin(int mm)         { min  = mm;   }
void Time::setSec(int ss)         { sec  = ss;   }

//Convert Time <-> second
int  Time::ToSec() { return hour * 3600 + min * 60 + sec; }
void Time::ToTime(int ss) {
    min  = ss / 60;
    sec  = ss % 60;
    hour = min / 60;
    min  = min % 60;
}

//Cộng hai thời gian (quy đổi ra tổng giây và convert)
Time Time::Add(Time time) {
    int SumSec = ToSec() + time.ToSec();
    Time SumTime;
    SumTime.ToTime(SumSec);
    return SumTime;
}

//Trừ hai thời gian (quy đổi ra hiệu giây và convert)
Time Time::Subtract(Time time) {
    int DiffSec = ToSec() - time.ToSec();
    if (DiffSec < 0) DiffSec = -DiffSec;

    Time DiffTime;
    DiffTime.ToTime(DiffSec);
    return DiffTime;
}

//Thêm một giây vào thời gian
void Time::AddSec()      { ToTime(ToSec() + 1); }
void Time::SubtractSec() { ToTime(ToSec() - 1); }