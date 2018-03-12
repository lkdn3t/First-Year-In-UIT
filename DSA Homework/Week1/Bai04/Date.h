struct Date {
	int day;
	int month;
	int year;
};

bool isLeapYear(int);
bool isDate(Date);
int DayOfMonth(int, int);
void outputDate(Date);
Date NextDay(Date);
Date LastDay(Date);