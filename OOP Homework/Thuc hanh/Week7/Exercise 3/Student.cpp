#include "Student.h"

Student::Student(int Grade, string SchoolName, int BeginYear, int FinishYear) {
	this->Grade             = Grade;
	this->SchoolName        = SchoolName;
	AcademicYear.BeginYear  = BeginYear;
	AcademicYear.FinishYear = FinishYear;
}

void Student::setGrade(int Grade)              { this->Grade = Grade; }

void Student::setSchoolName(string SchoolName) { this->SchoolName = SchoolName; }

void Student::setBeginYear(int BeginYear)      { AcademicYear.BeginYear = BeginYear; }

void Student::setFinishYear(int FinishYear)    { AcademicYear.FinishYear = FinishYear; }

int Student::getGrade()         const          { return Grade; }

int Student::getBeginYear()     const          { return AcademicYear.BeginYear;  }

int Student::getFinishYear()    const          { return AcademicYear.FinishYear; }

string Student::getSchoolName() const          { return SchoolName; }

void Student::input()
{
	Person::input();
	cout << " Enter grade: "      ; cin >> Grade;
	cout << " Enter begin year: " ; cin >> AcademicYear.BeginYear;
	cout << " Enter finish year: "; cin >> AcademicYear.FinishYear;
	cin.ignore();
	cout << " Enter School Name: "; getline(cin, SchoolName);
}

void Student::output() const
{
	Person::output();
	cout << " Grade: " << Grade << endl;
	cout << " Academic year: " << AcademicYear.BeginYear << " - " << AcademicYear.FinishYear << endl;
	cout << " School name: " << SchoolName << endl;
}