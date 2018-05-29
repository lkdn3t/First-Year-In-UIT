#include "ListBook.h"

ListBook::ListBook() {}

ListBook::ListBook(const ListBook & lst) {
	NumberOfBook = lst.NumberOfBook;
	NumberOfMagazine = lst.NumberOfMagazine;
	NumberOfNovel = lst.NumberOfNovel;
	NumberOfTextbook = lst.NumberOfTextbook;
	book = lst.book;
}

ListBook::~ListBook() {
	for (int i = 0; i < NumberOfBook; i++) {
		delete book[i];
	}
}

string ListBook::TypeBook(Book* book) {
	string FullType = typeid(*book).name();
	string Type;
	for (int i = 6; i < FullType.length(); i++)
		Type += FullType[i];
	return Type;
}

void ListBook::InputListBook() {
	cout << " Enter number of Textbook: "; cin >> NumberOfTextbook;
	cout << " Enter number of Magazine: "; cin >> NumberOfMagazine;
	cout << " Enter number of Novel: "   ; cin >> NumberOfNovel;

	NumberOfBook = NumberOfNovel + NumberOfMagazine + NumberOfTextbook;
	cin.ignore();

	for (int i = 0; i < NumberOfTextbook; i++) {
		cout << "\n...ENTER INFORMATION OF TEXTBOOK " << i + 1 << "...\n";
		Book* TBook = new Textbook();
		TBook->input();
		book.push_back(TBook);
	}

	for (int i = 0; i < NumberOfMagazine; i++) {
		cout << "\n...ENTER INFORMATION OF MAGAZINE " << i + 1 << "...\n";
		Book* MBook = new Magazine();
		MBook->input();
		book.push_back(MBook);
	}

	for (int i = 0; i < NumberOfNovel; i++) {
		cout << "\n...ENTER INFORMATION OF NOVEL " << i + 1 << "...\n";
		Book* NBook = new Novel();
		NBook->input();
		book.push_back(NBook);
	}
}

void ListBook::OutputListBook() {
	if (!NumberOfBook) {
		cout << "List of book is empty!\n";
		return;
	}

	for (int i = 0; i < NumberOfBook; i++) {
		cout << "\n...INFORMATION OF BOOK " << i + 1 << "...\n";
		cout << " Book type: " << TypeBook(book[i]) << endl;
		book[i]->output();
	}
}

void ListBook::InsertBook() {
	int NumInsertBook;
	cout << " Enter number of book(s) to insert: ";
	cin >> NumInsertBook; cin.ignore();

	for (int i = 0; i < NumInsertBook; i++) {
		cout << "\n...ENTER INFORMATION OF BOOK " << i + 1 << "...\n";
		string type;
		do {
			cout << " Enter type of book (Textbook/Magazine/Novel): ";
			getline(cin, type);
		} while (type != "Textbook" && type != "Magazine" && type != "Novel");

		Book* newBook;
		if (type == "Textbook") {
			newBook = new Textbook;
			NumberOfTextbook++;
		}

		else if (type == "Novel") {
			newBook = new Novel;
			NumberOfNovel++;
		}

		else {
			newBook = new Magazine;
			NumberOfMagazine++;
		}

		newBook->input();
		book.push_back(newBook);
		NumberOfBook = book.size();
		cout << " -> Sucessfully added a " << TypeBook(newBook) << ".\n";
	}
}

void ListBook::RemoveBook() {
	if (!NumberOfBook) {
		cout << "List of book is empty!\n";
		return;
	}

	int BookNumber;
	do {
		cout << " Enter book number to remove: ";
		cin >> BookNumber;
	} while (BookNumber < 1 || BookNumber > NumberOfBook);

	string BookType = TypeBook(book[BookNumber - 1]);
	cout << "...INFORMATION OF BOOK " << BookNumber << "...\n";
	book[BookNumber - 1]->output();
	
	char c;
	do {
		cout << "\n Are you sure to delete this book (Y/N): ";
		cin >> c;
	} while (c != 'Y' && c != 'N');

	if (c == 'Y') {
		book.erase(book.begin() + BookNumber - 1);
		if (BookType == "Textbook") NumberOfTextbook--;
		else if (BookType == "Novel") NumberOfNovel--;
		else NumberOfMagazine--;
		NumberOfBook--;
		cout << " -> Sucessfully removed the input-book!\n";
	}
	else cout << " -> Cancel removal\n";
}