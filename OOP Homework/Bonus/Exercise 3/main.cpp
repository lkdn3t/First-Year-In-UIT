//Đề từ lớp OOP của thầy Trọng: in ra lịch treo tường
//của một tháng - năm bất kì nhập vào

#include "DateTime.h"
#include <iostream>
#include <conio.h>
using namespace std;

int main() {
	DateTime date;
	date.setMonth();
	date.setYear();
	date.printCalendar();

	_getch();
	return 1;
}