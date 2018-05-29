#pragma once
#include "Book.h"

class Novel : public Book {
private:
	string Type;
	string Author;

public:
	Novel() {}
	Novel(const Novel& n);

public:
	string getType() const;
	string getAuthor() const;
	void setType(string Type);
	void setAuthor(string Author);

public:
	void input();
	void output() const;
};

