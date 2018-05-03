#include "Person.h"

Person::Person(string Name, int Age, string Sex, string Address, string PhoneNum) {
	this->Name = Name;
	this->Age = Age;
	this->Sex = Sex;
	this->Address = Address;
	this->PhoneNum = PhoneNum;
}

string Person::getName() const {
	return Name;
}

int Person::getAge() const {
	return Age;
}

string Person::getSex() const {
	return Sex;
}

string Person::getAddress() const {
	return Address;
}

string Person::getPhoneNum() const {
	return PhoneNum;
}

void Person::setName(string Name) {
	this->Name = Name;
}

void Person::setAge(int Age) {
	this->Age = Age;
}

void Person::setSex(string Sex) {
	this->Sex = Sex;
}

void Person::setAddress(string Address) {
	this->Address = Address;
}

void Person::setPhoneNum(string PhoneNum) {
	this->PhoneNum = PhoneNum;
}

void Person::input() {
	cout << " Nhap ten: "          ; getline(cin, Name);
	cout << " Nhap tuoi: "         ; cin >> Age;
	cin.ignore();
	cout << " Nhap gioi tinh: "    ; getline(cin, Sex);
	cout << " Nhap dia chi: "      ; getline(cin, Address);
	cout << " Nhap so dien thoai: "; getline(cin, PhoneNum);
}

void Person::output() const {
	cout << " Ten: " << Name << endl;
	cout << " Tuoi: " << Age << endl;
	cout << " Gioi tinh: " << Sex << endl;
	cout << " Dia chi: " << Address << endl;
	cout << " So dien thoai: " << PhoneNum << endl;
}