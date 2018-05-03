/*
4. Xây d?ng class Worker: k? th?a class Person
- string WorkPlace: n?i làm vi?c
- long long Salary: l??ng
*/

#include "Pupil.h"

class Worker : public Person {
private:
	string WorkPlace;
	long long Salary;

public:
	Worker() {};
	Worker(string WorkPlace, long long Salary);

public:
	string getWorkPlace() const;
	long long getSalary() const;
	void setWorkPlace(string WorkPlace);
	void setSalary(long long Salary);

public:
	void input();
	void output() const;
};