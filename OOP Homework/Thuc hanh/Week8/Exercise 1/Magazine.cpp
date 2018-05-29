#include "Magazine.h"

Magazine::Magazine(const Magazine & m) {
	Type = m.Type;
	Circulation = m.Circulation;
	NumberOfArticle = m.NumberOfArticle;
}

string Magazine::getType() const {
	return Type;
}

int Magazine::getCirculation() const {
	return Circulation;
}

int Magazine::getNumberOfArticle() const {
	return NumberOfArticle;
}

void Magazine::setType(string Type) {
	this->Type = Type;
}

void Magazine::setCirculation(int Circulation) {
	this->Circulation = Circulation;
}

void Magazine::setNumberOfArticle(int NumberOfArticle) {
	this->NumberOfArticle = NumberOfArticle;
}

void Magazine::input() {
	Book::input(); cin.ignore();
	cout << " Enter type: "           ; getline(cin, Type);
	cout << " Enter Circulation: "    ; cin >> Circulation;
	cout << " Enter NumberOfArticle: "; cin >> NumberOfArticle;
	cin.ignore();
}

void Magazine::output() const {
	Book::output();
	cout << "\n Type: " << Type;
	cout << "\n Circulation: " << Circulation;
	cout << "\n Number of article: " << NumberOfArticle;
	cout << endl;
}
