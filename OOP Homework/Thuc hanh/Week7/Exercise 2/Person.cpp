#include "Person.h"

using namespace std;

Person::Person(string name, int day, int month, int year, string address, string sex) {
	Name        = name;
	Birth.day   = day;
	Birth.month = month;
	Birth.year  = year;
	Address     = address;
	Sex         = sex;
}

void Person::setBirth(int day, int month, int year)
{
	Birth.day = day;
	Birth.month = month;
	Birth.year = year;
}

void Person::setName(string name)       { Name = name;        }

void Person::setAddress(string address) { Address = address;  }

void Person::setSex(string sex)         { Sex = sex;          }

string Person::getName() const          { return Name;        }

string Person::getAddress() const       { return Address;     }

string Person::getSex() const           { return Sex;         }

int Person::getBirthDay() const         { return Birth.day;   }

int Person::getBirthMonth() const       { return Birth.month; }

int Person::getBirthYear() const        { return Birth.year;  }

void Person::input()
{
	cout << " Enter name: "          ; getline(cin, Name);
	cout << " Enter day of birth: "  ; cin >> Birth.day;
	cout << " Enter month of birth: "; cin >> Birth.month;
	cout << " Enter year of birth: " ; cin >> Birth.year;
	cin.ignore();
	cout << " Enter address: "       ; getline(cin, Address);
	cout << " Enter sex: "           ; getline(cin, Sex);
}

void Person::output() const
{
	cout << " Name: "    << Name << endl;
	cout << " Birth: "   << Birth.day << "/" << Birth.month << "/" << Birth.year << endl;
	cout << " Address: " << Address << endl;
	cout << " Sex: "     << Sex << endl;
}