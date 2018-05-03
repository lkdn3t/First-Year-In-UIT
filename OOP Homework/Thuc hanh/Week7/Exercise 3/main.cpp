#include "ListPeople.h"

int main() {
	ListPeople* LstPpl = new ListPeople();
	LstPpl->input();
	LstPpl->output();

	delete LstPpl;
	system("pause");
	return 0;
}