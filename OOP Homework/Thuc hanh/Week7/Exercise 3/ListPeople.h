#include "Artist_Singer.h"

class ListPeople {
	int NumPeople;
	string* Type;
	Person** ListPerson;

public:
	ListPeople(int NumPeople = 0, string* Type = NULL, Person** ListPerson = NULL);
	~ListPeople();
	void setNumPeople(int NumPeople);
	void setListPerson(Person** ListPerson);

public:
	int getNumPeople() const;
	Person** getListPerson() const;

public:
	void input();
	void output() const;
};