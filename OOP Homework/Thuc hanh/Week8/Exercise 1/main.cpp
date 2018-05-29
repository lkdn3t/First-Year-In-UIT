#include "Menu.h"

using namespace std;

int main() {
	char Choice;
	ListBook * ListOfBook = new ListBook();
	MenuChoice(ListOfBook, Choice);
	delete ListOfBook;
	return 0;
}