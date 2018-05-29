#pragma once
#include <iostream>
#include <string>

using namespace std;

class Book {
protected:
	string Name;
	string Publisher;
	int PublishYear;
	int Price;

public:
	Book() {}
	Book(const Book& b);
	string getName() const;
	string getPublisher() const;
	int getPublishYear() const;
	int getPrice() const;

public:
	void setName(string Name);
	void setPublisher(string Publisher);
	void setPublishYear(int PublishYear);
	void setPrice(int Price);

public:
	virtual void input();
	virtual void output() const;
};