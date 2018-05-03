#include <iostream>
#include <string>

using namespace std;

class Human {
	string Name;
	int Age;
	string Sex;

public:
	Human() {};
	Human(string Name, int Age, string Sex);
	void input();
	void output() const;

public:
	string getName() const;
	int getAge() const;
	string getSex() const;

public:
	void setName(string Name);
	void setAge(int Age);
	void setSex(string Sex);
};