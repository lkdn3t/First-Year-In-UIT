/*
2. Xây d?ng class Student: k? th?a class Person
- int Grade: n?m th? m?y
- struct AcademicYear AcademicYear: niên khoá
- string SchoolName: tên tr??ng
*/

#include "Person.h"

class Student: public Person {
private:
	int Grade;
	string SchoolName;
	struct Academic_Year {
		int BeginYear;
		int FinishYear;
	} AcademicYear;

public:
	Student() {};
	Student(int Grade, string SchoolName, int BeginYear, int FinishYear);
	
public:
	void setGrade(int Grade);
	void setSchoolName(string SchoolName);
	void setBeginYear(int BeginYear);
	void setFinishYear(int FinishYear);

public:
	int getGrade() const;
	int getBeginYear() const;
	int getFinishYear() const;
	string getSchoolName() const;

public:
	void input();
	void output() const;
};