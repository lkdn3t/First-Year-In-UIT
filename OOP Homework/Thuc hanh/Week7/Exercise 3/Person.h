/*
1. Xây dựng class Person:
- string: họ tên
- struct Date: ngày tháng năm sinh
- string Place: nơi ở
- string Sex: giới tính
*/

#include <iostream>
#include <string>

using namespace std;

class Person {
private:
	string Name;
	struct Date {
		int day;
		int month;
		int year;
	} Birth;
	string Address;
	string Sex;

public:
	Person() {};
	Person(string name, int day, int month, int year, string address, string sex);

public:
	void setName(string name);
	void setBirth(int day, int month, int year);
	void setAddress(string address);
	void setSex(string sex);

public:
	string getName() const;
	string getAddress() const;
	string getSex() const;
	int getBirthDay() const;
	int getBirthMonth() const;
	int getBirthYear() const;

public:
	virtual void input();
	virtual void output() const;
};