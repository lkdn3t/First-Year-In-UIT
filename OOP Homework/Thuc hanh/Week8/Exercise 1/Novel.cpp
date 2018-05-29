#include "Novel.h"

Novel::Novel(const Novel & n) {
	Type = n.Type;
	Author = n.Author;
}

string Novel::getType() const {
	return Type;
}

string Novel::getAuthor() const {
	return Author;
}

void Novel::setType(string Type) {
	this->Type = Type;
}

void Novel::setAuthor(string Author) {
	this->Author = Author;
}

void Novel::input() {
	Book::input(); cin.ignore();
	cout << " Enter Type: "  ; getline(cin, Type);
	cout << " Enter Author: "; getline(cin, Author);
}

void Novel::output() const {
	Book::output();
	cout << "\n Type: " << Type;
	cout << "\n Author: " << Author;
	cout << endl;
}