#include "Book.h"

Book::Book(const Book & b) {
	Name = b.Name;
	Publisher = b.Publisher;
	PublishYear = b.PublishYear;
	Price = b.Price;
}

string Book::getName() const {
	return Name;
}

string Book::getPublisher() const {
	return Publisher;
}

int Book::getPublishYear() const {
	return PublishYear;
}

int Book::getPrice() const {
	return Price;
}

void Book::setName(string Name) {
	this->Name = Name;
}

void Book::setPublisher(string Publisher) {
	this->Publisher = Publisher;
}

void Book::setPublishYear(int PublishYear) {
	this->PublishYear = PublishYear;
}

void Book::setPrice(int Price) {
	this->Price = Price;
}

void Book::input() {
	cout << " Enter Name: "        ; getline(cin, Name);
	cout << " Enter Publisher: "   ; getline(cin, Publisher);
	cout << " Enter Publish year: "; cin >> PublishYear;
	cout << " Enter Price: "       ; cin >> Price;
}

void Book::output() const {
	cout << " Name: " << Name;
	cout << "\n Publisher: " << Publisher;
	cout << "\n Publish year: " << PublishYear;
	cout << "\n Price: " << Price;
}