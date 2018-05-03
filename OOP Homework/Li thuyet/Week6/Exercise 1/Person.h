#include <iostream>
#include <string>

using namespace std;

class Person {
	string Name;
	int Age;
	string Sex;
	string Address;
	string PhoneNum;

public:
	Person() {};
	Person(string Name, int Age, string Sex, string Address, string PhoneNum);
	void input();
	void output() const;

public:
	string getName() const;
	int getAge() const;
	string getSex() const;
	string getAddress() const;
	string getPhoneNum() const;

public:
	void setName(string Name);
	void setAge(int Age);
	void setSex(string Sex);
	void setAddress(string Address);
	void setPhoneNum(string PhoneNum);
};