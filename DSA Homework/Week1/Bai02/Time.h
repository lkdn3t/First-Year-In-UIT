struct Time {
	int hour;
	int min;
	int sec;
};

void setTime(Time&, int, int, int);
void outputTime(Time);
bool isTime(Time);
void convertTime(Time&);
Time sumTime(Time, Time);
Time diffTime(Time, Time);