#include "Textbook.h"

Textbook::~Textbook() {
	delete[] Author;
}

string Textbook::getSpecialization() const {
	return Specialization;
}

int Textbook::getNumberOfAuthor() const {
	return NumberOfAuthor;
}

string* Textbook::getAuthor() const {
	return Author;
}

void Textbook::setSpecialization(string Specialization) {
	this->Specialization = Specialization;
}

void Textbook::setNumberOfAuthor(int NumberOfAuthor) {
	this->NumberOfAuthor = NumberOfAuthor;
}

void Textbook::setAuthor(string* Author) {
	this->Author = Author;
}

void Textbook::input() {
	Book::input(); cin.ignore();
	cout << " Enter Specialization: "     ; getline(cin, Specialization);
	cout << " Enter number of author(s): "; cin >> NumberOfAuthor;
	cin.ignore();

	Author = new string[NumberOfAuthor];
	for (int i = 0; i < NumberOfAuthor; i++) {
		cout << " Enter Author " << i + 1 << ": ";
		getline(cin, Author[i]);
	}
}

void Textbook::output() const {
	Book::output();
	cout << "\n Specialization: " << Specialization;
	cout << "\n Number of author(s): " << NumberOfAuthor;
	for (int i = 0; i < NumberOfAuthor; i++) {
		cout << "\n  . Author " << i + 1 << ": " << Author[i];
	}
	cout << endl;
}