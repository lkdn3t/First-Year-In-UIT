#include "Worker.h"

using namespace std;

//----------------- FOR WORKER-------------------- -
Worker::Worker() { }

void Worker::setName(string name) { Name = name; }

void Worker::setBirth(int d, int m, int y) {
	Birth.day   = d;
	Birth.month = m;
	Birth.year  = y;
}

void Worker::setSalary(long long salary) { Salary = salary; }

string Worker::getName()      const { return Name;        } 

int Worker::getBirthDay()     const { return Birth.day;   }

int Worker::getBirthMonth()   const { return Birth.month; }

int Worker::getBirthYear()    const { return Birth.year;  }

long long Worker::getSalary() const { return Salary;      }

void Worker::input()
{
	cout << "Enter worker name: "   ; getline(cin, Name);
	cout << "Enter day of birth: "  ; cin >> Birth.day;
	cout << "Enter month of birth: "; cin >> Birth.month;
	cout << "Enter year of birth: " ; cin >> Birth.year;
	cout << "Enter salary: "        ; cin >> Salary;
}

void Worker::output() const
{
	cout << "Worker name: " << Name << endl;
	cout << "Date of birth: " << Birth.day << "/" << Birth.month << "/" << Birth.year << endl;
	cout << "Salary: " << Salary << endl;
}

void Worker::computeSalary()
{
	return;
}

//-----------------FOR PRODUCTION WORKER---------------------

void ProductionWorker::input()
{
	cout << "Enter worker name: "       ; getline(cin, Name);
	cout << "Enter day of birth: "      ; cin >> Birth.day;
	cout << "Enter month of birth: "    ; cin >> Birth.month;
	cout << "Enter year of birth: "     ; cin >> Birth.year;
	cout << "Enter base salary: "       ; cin >> BaseSalary;
	cout << "Enter number of products: "; cin >> NumProducts;
}

void ProductionWorker::output() const
{
	cout << "Type of worker: Production Worker" << endl;
	cout << "Worker name: " << Name << endl;
	cout << "Date of birth: " << Birth.day << "/" << Birth.month << "/" << Birth.year << endl;
	cout << "Number of products: " << NumProducts << endl;
	cout << "Salary: " << Salary << endl;
}

void ProductionWorker::computeSalary() { 
	Salary = BaseSalary + NumProducts * 5000; 
}

void ProductionWorker::setNumProducts(int np)       { NumProducts = np;   }

void ProductionWorker::setBaseSalary(long long bs)  { BaseSalary = bs;    }

int ProductionWorker::getNumProducts() const        { return NumProducts; }

long long ProductionWorker::getBaseSalary() const   { return BaseSalary;  }

//-----------------FOR OFFICE WORKER---------------------

void OfficeWorker::input()
{
	cout << "Enter worker name: "       ; getline(cin, Name);
	cout << "Enter day of birth: "      ; cin >> Birth.day;
	cout << "Enter month of birth: "    ; cin >> Birth.month;
	cout << "Enter year of birth: "     ; cin >> Birth.year;
	cout << "Enter number of products: "; cin >> WorkDays;
}

void OfficeWorker::output() const
{
	cout << "Type of worker: Office Worker" << endl;
	cout << "Worker name: " << Name << endl;
	cout << "Date of birth: " << Birth.day << "/" << Birth.month << "/" << Birth.year << endl;
	cout << "Number of work days: " << WorkDays << endl;
	cout << "Salary: " << Salary << endl;
}

void OfficeWorker::computeSalary()
{
	Salary = WorkDays * 100000;
}

int OfficeWorker::getWorkDays() const  { return WorkDays; }

void OfficeWorker::setWorkDays(int wd) { WorkDays = wd;  }