#include <iostream>
using namespace std;

class Date {
private:
    int  day;
    int  month;
    int  year;

public:
    Date(int d = 1, int m = 1, int y = 1900);
    void inputDate();
    void putDate();

public:
    int  get_day();
    int  get_month();
    int  get_year();
    void set_day(int);
    void set_month(int);
    void set_year(int);

public:
    bool isLeapYear();
    int  DayOfMonth();
    Date NextDay();
};