#include "Human.h"
#include "Person.h"

using namespace std;

int main() {
	Human* person = new Human();
	person->input();
	person->output();

	delete person;
	system("pause");
	return 0;
}