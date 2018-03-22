#include <iostream>
#include <iomanip>
#include <cmath>

class Date {
private:
    int day;
    int month;
    int year;
    
private:
    bool isLeapYear() const;
    int DayOfMonth() const;
    int DayOfYear() const;

public:
    Date(int d = 1, int m = 1, int y = 1900);
    Date(const Date&);
    void getDate();
    void putDate() const;
    void convertDate();

public:
    int  getDay() const;
    int  getMonth() const;
    int  getYear() const;
    void setDay(int);
    void setMonth(int);
    void setYear(int);

public:
    Date addDays(int) const;
    Date subDays(int) const;
    Date addOne() const;
    Date subOne() const;
    int  DiffDays(const Date&) const;
};