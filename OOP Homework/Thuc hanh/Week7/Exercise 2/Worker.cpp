#include "Worker.h"

Worker::Worker(string WorkPlace, long long Salary) {
	this->WorkPlace = WorkPlace;
	this->Salary = Salary;
}

string Worker::getWorkPlace() const {
	return WorkPlace;
}

long long Worker::getSalary() const {
	return Salary;
}

void Worker::setWorkPlace(string WorkPlace) {
	this->WorkPlace = WorkPlace;
}

void Worker::setSalary(long long Salary) {
	this->Salary = Salary;
}

void Worker::input() {
	Person::input();
	cout << " Enter Workplace: "; getline(cin, WorkPlace);
	cout << " Enter Salary: "; cin >> Salary;
	cin.ignore();
}

void Worker::output() const {
	Person::output();
	cout << " Workplace: " << WorkPlace << endl;
	cout << " Salary: " << Salary << endl;
}
