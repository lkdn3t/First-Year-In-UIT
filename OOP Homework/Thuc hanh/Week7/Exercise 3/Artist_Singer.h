/*
5. Xây dựng class Artist/Singer: kế thừa class Person
- string StageName: nghệ danh
- string Specialize: chuyên môn
*/

#include "Worker.h"

class Artist_Singer: public Person {
private:
	string StageName;
	string Specialize;

public:
	Artist_Singer() {};
	Artist_Singer(string StageName, string Specialize);

public:
	string getStageName () const;
	string getSpecialize () const;
	void setStageName(string StageName);
	void setSpecialize(string Specialize);

public:
	void input();
	void output() const;
} typedef Artist, Singer;