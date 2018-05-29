#include "ListCattle.h"

void Initialize(vector<Cattle*> &cattle, int & NumCow, int & NumSheep, int & NumGoat) {
	cout << " Enter number of cows: "; cin >> NumCow;
	cout << " Enter number of sheeps: "; cin >> NumSheep;
	cout << " Enter number of goats: "; cin >> NumGoat;
	for (int i = 0; i < NumCow; i++)   cattle.push_back(new Cow);
	for (int i = 0; i < NumSheep; i++) cattle.push_back(new Sheep);
	for (int i = 0; i < NumGoat; i++)  cattle.push_back(new Goat);
}

void MakeAllNoise(vector<Cattle*> cattle) {
	cout << "\n...List noise get from all cattle...\n";
	for (int i = 0; i < cattle.size(); i++)
		cattle[i]->MakeNoise();
}

string GetType(Cattle* cattle) {
	if (cattle->getNoise() == "Moooo!")
		return "Cow";
	else if (cattle->getNoise() == "Baaaa!")
		return "Sheep";
	return "Goat";
}

void ListBirthMilk(vector<Cattle*> &cattle) {
	int NumCattle = cattle.size();
	cout << "\n...List Birth & Milk of all cattle..." << endl;
	for (int i = 0; i < NumCattle; i++) {
		cout << "\nCattle no. " << i + 1 << endl;
		cout << " + Type: "     << GetType(cattle[i]) << endl;
		cout << " + Children: " << cattle[i]->getBirth() << endl;
		cout << " + Milk: "     << cattle[i]->getMilk() << endl;
	}

	for (int i = 0; i < NumCattle; i++) {
		for (int j = 0; j < cattle[i]->getBirth(); j++) {
			string type = GetType(cattle[i]);
			if (type == "Cow") cattle.push_back(new Cow);
			else if (type == "Sheep") cattle.push_back(new Sheep);
			else cattle.push_back(new Goat);
		}
	}
}