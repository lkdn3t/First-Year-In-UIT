#pragma once
#include "Book.h"

class Textbook : public Book {
private:
	string Specialization;
	int NumberOfAuthor;
	string* Author;

public:
	Textbook() {}
	~Textbook();

public:
	string getSpecialization() const;
	int getNumberOfAuthor() const;
	string* getAuthor() const;

public:
	void setSpecialization(string Specialization);
	void setNumberOfAuthor(int NumberOfAuthor);
	void setAuthor(string* Author);

public:
	void input();
	void output() const;
};