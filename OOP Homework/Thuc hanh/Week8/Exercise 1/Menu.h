#include "ListBook.h"

void PrintMenuBoard() {
	cout << "\n...BOOK MANAGEMENT...\n";
	cout << "\n 1. Input list of books.\n";
	cout << "\n 2. Print list of books.\n";
	cout << "\n 3. Insert book(s).\n";
	cout << "\n 4. Remove a book.\n";
	cout << "\n 0. Exit\n";
}

int GetChoice() {
	int choice;
	do {
		cout << "\n-> Enter request-number: ";
		cin >> choice;
	} while (choice < 0 || choice > 4);
	return choice;
}

void MenuChoice(ListBook *& ListOfBook, char &Choice) {
	do {
		system("cls");
		PrintMenuBoard();
		int RequestChoice = GetChoice();

		switch (RequestChoice) {
		case 1:
			system("cls");
			if (ListOfBook != NULL) delete ListOfBook;
			ListOfBook = new ListBook();
			ListOfBook->InputListBook();
			break;

		case 2:
			system("cls");
			ListOfBook->OutputListBook();
			break;

		case 3:
			system("cls");
			ListOfBook->InsertBook();
			break;

		case 4:
			system("cls");
			ListOfBook->RemoveBook();
			break;

		default:
			cout << "\nExiting... ";
			system("pause");
			return;
		}

		cout << "\nBack to Menu (Y/N): ";
		cin >> Choice;
	} while (Choice == 'Y');

}