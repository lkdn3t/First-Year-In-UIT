#include "Time.h"
#include <iostream>
#include <iomanip>
using namespace std;

//Hàm gán giá trị giờ - phút - giây cho thời gian
void setTime(Time& t, int hh, int mm, int ss) {
	t.hour = hh;
	t.min = mm;
	t.sec = ss;
}

//Hàm xuất thời gian theo định dạng hh:mm:ss
void outputTime(Time t) {
	cout << setfill('0') << setw(2) << t.hour;
	cout << ":" << setfill('0') << setw(2) << t.min;
	cout << ":" << setfill('0') << setw(2) << t.sec << "\n";
}

//Hàm kiểm tra tính hợp lệ của thời gian nhập vào
bool isTime(Time t) {
	return t.hour >= 0 && t.hour < 24 && t.min >= 0 && t.min < 60 && t.sec >= 0 && t.sec < 60;
}

//Hàm đưa thời gian về đúng định dạng (dùng cho phép toán '+' và '-' hai thời gian)
//VD: 08:59:60 => 09:00:00
void convertTime(Time &t) {
	t.min += t.sec / 60;
	t.sec %= 60;
	t.hour += t.min / 60;
	t.min %= 60;
}

//Hàm tính tổng hai thời gian
Time sumTime(Time t1, Time t2) {
	t1.hour += t2.hour;
	t1.min += t2.min;
	t1.sec += t2.sec;
	convertTime(t1);
	return t1;
}

//Hàm tính hiệu hai thời gian (ở đây quy ước lấy giá trị tuyệt đối giữa 2 thời gian)
//Đổi hai thời gian ra giây, tìm hiệu số giây và đưa về dạng hh:mm:ss
Time diffTime(Time t1, Time t2) {
	int sec1 = t1.hour * 3600 + t1.min * 60 + t1.sec;
	int sec2 = t2.hour * 3600 + t2.min * 60 + t2.sec;
	int diff_sec;
	sec1 > sec2 ? diff_sec = sec1 - sec2 : diff_sec = sec2 - sec1;
	
	Time diff;
	setTime(diff, 0, 0, diff_sec);
	convertTime(diff);
	return diff;
}