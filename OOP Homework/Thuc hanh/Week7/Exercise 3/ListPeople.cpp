#include "ListPeople.h"
#define elif else if
#define PutLine cout << "\n-------------------------------------------\n"

ListPeople::ListPeople(int NumPeople, string* Type, Person ** ListPerson) {
	this->NumPeople = NumPeople;
	this->Type = Type;
	this->ListPerson = ListPerson;
}

ListPeople::~ListPeople() {
	if (Type != NULL)
		delete[]Type;

	for (int i = 0; i < NumPeople; i++)
		if (ListPerson[i] != NULL) 
			delete ListPerson[i];

	if (ListPerson != NULL)
		delete[]ListPerson;
}

int ListPeople::getNumPeople() const {
	return NumPeople;
}

void ListPeople::setNumPeople(int NumPeople) {
	this->NumPeople = NumPeople;
}

Person** ListPeople::getListPerson() const {
	return ListPerson;
}

void ListPeople::input() {
	cout << " Enter number of people: ";
	cin >> NumPeople; cin.ignore();

	Type = new string[NumPeople];
	ListPerson = new Person*[NumPeople];

	for (int i = 0; i < NumPeople; i++) {
		do {
			cout << "\n Type of person " << i + 1 << ": ";
			getline(cin, Type[i]);
		} 
		while (Type[i] != "Student" && Type[i] != "Pupil" 
			&& Type[i] != "Worker" && Type[i] != "Artist" && Type[i] != "Singer");

		if (Type[i] == "Student")  ListPerson[i] = new Student();
		elif (Type[i] == "Pupil")  ListPerson[i] = new Pupil();
		elif (Type[i] == "Worker") ListPerson[i] = new Worker();
		elif (Type[i] == "Artist" || Type[i] == "Singer") 
			ListPerson[i] = new Artist_Singer();

		cout << "\n...Input information of person " << i + 1 << "...\n";
		ListPerson[i]->input();
		PutLine;
	}
}

void ListPeople::output() const {
	for (int i = 0; i < NumPeople; i++) {
		cout << "\n...Information of person " << i + 1 << "...\n";
		cout << " Type of person: " << Type[i] << endl;
		ListPerson[i]->output();
		PutLine;
	}
}

void ListPeople::setListPerson(Person** ListPerson) {
	this->ListPerson = ListPerson;
}