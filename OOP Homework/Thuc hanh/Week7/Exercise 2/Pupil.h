/*
3. Xây dựng class Pupil: kế thừa class Person
- string SchoolName: tên trường
- string Class: tên lớp
*/

#include "Student.h"

class Pupil: public Person {
private:
	string SchoolName;
	string Class;

public:
	Pupil() {};
	Pupil(string Schoolname, string Class);
	
public:
	string getSchoolName() const;
	string getClass() const;
	void setSchoolName(string SchoolName);
	void setClass(string Class);

public:
	void input();
	void output() const;
};