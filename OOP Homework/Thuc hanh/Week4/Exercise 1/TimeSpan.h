#include <iostream>
#include <iomanip>

class TimeSpan {
private:
    int hour;
    int min;
    int sec;
    int  ToSec();
    void ToTime(int);

public:
    int  getHour();
    int  getMin();
    int  getSec();
    void setHour(int);
    void setMin(int);
    void setSec(int);

public:
    TimeSpan(int hour = 0, int min = 0, int sec = 0);
    void getTime();
    void putTime();

public:
    TimeSpan Add(TimeSpan);
    TimeSpan Subtract(TimeSpan);
    bool isEqual(TimeSpan);
    bool isNotEqual(TimeSpan);
    bool isBigger(TimeSpan);
    bool isSmaller(TimeSpan);
    bool isNotBigger(TimeSpan);
    bool isNotSmaller(TimeSpan);
};