#include <iostream>
#include <windows.h>
#include <iomanip>

class Time {
private:
    int hour;
    int min;
    int sec;

public:
    int  getHour();
    int  getMin();
    int  getSec();
    void setHour(int);
    void setMin(int);
    void setSec(int);

public:
    Time(int hour = 0, int min = 0, int sec = 0);
    void getTime();
    void putTime();
    void ToTime(int);
    int  ToSec();

public:
    void AddSec();
    void SubtractSec();
    Time Add(Time);
    Time Subtract(Time);
};