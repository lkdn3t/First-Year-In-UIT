#include "Human.h"

Human::Human(string Name, int Age, string Sex) {
	this->Name = Name;
	this->Age = Age;
	this->Sex = Sex;
}

void Human::input() {
	cout << " Nhap ten: "      ; getline(cin, Name);
	cout << " Nhap tuoi: "     ; cin >> Age;
	cin.ignore();
	cout << " Nhap gioi tinh: "; getline(cin, Sex);
}

void Human::output() const {
	cout << " Ten: " << Name << endl;
	cout << " Tuoi: " << Age << endl;
	cout << " Gioi tinh:" << Sex << endl;
}

string Human::getName() const {
	return Name;
}

int Human::getAge() const {
	return Age;
}

string Human::getSex() const {
	return Sex;
}

void Human::setName(string Name) {
	this->Name = Name;
}

void Human::setAge(int Age) {
	this->Age = Age;
}

void Human::setSex(string Sex) {
	this->Sex = Sex;
}
