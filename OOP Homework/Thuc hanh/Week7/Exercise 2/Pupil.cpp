#include "Pupil.h"

Pupil::Pupil(string Schoolname, string Class) {
	this->SchoolName = SchoolName;
	this->Class = Class;
}

string Pupil::getSchoolName() const {
	return SchoolName;
}

string Pupil::getClass() const {
	return Class;
}

void Pupil::setSchoolName(string SchoolName) {
	this->SchoolName = SchoolName;
}

void Pupil::setClass(string Class) {
	this->Class = Class;
}

void Pupil::input() {
	Person::input();
	cout << " Enter School name: "; getline(cin, SchoolName);
	cout << " Enter Class: name: "; getline(cin, Class);
}

void Pupil::output() const {
	Person::output();
	cout << " School name: " << SchoolName << endl;
	cout << " Class name: " << Class << endl;
}
