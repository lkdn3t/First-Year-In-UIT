#pragma once
#include "Book.h"

class Magazine : public Book {
private:
	string Type;
	int Circulation;
	int NumberOfArticle;

public:
	Magazine() {}
	Magazine(const Magazine& m);

public:
	string getType() const;
	int getCirculation() const;
	int getNumberOfArticle() const;

public:
	void setType(string Type);
	void setCirculation(int Circulation);
	void setNumberOfArticle(int NumberOfArticle);

public:
	void input();
	void output() const;
};