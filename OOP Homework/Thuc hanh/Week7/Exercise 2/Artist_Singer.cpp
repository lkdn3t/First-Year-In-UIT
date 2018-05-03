#include "Artist_Singer.h"

Artist_Singer::Artist_Singer(string StageName, string Specialize) {
	this->StageName = StageName;
	this->Specialize = Specialize;
}

string Artist_Singer::getStageName() const {
	return StageName;
}

string Artist_Singer::getSpecialize() const {
	return Specialize;
}

void Artist_Singer::setStageName(string StageName) {
	this->StageName = StageName;
}

void Artist_Singer::setSpecialize(string Specialize) {
	this->Specialize = Specialize;
}

void Artist_Singer::input() {
	Person::input();
	cout << " Enter Stage name: "; getline(cin, StageName);
	cout << " Enter Specialize: "; getline(cin, Specialize);
}

void Artist_Singer::output() const {
	Person::output();
	cout << " Stage name: " << StageName << endl;
	cout << " Specialize: " << Specialize << endl;
}