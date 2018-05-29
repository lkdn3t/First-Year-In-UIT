#pragma once
#include "Textbook.h"
#include "Magazine.h"
#include "Novel.h"
#include <vector>

class ListBook {
private:
	int NumberOfBook = 0;
	int NumberOfTextbook = 0;
	int NumberOfMagazine = 0;
	int NumberOfNovel = 0;
	vector<Book*> book;

public:
	ListBook();
	ListBook(const ListBook& lst);
	~ListBook();

public:
	string TypeBook(Book* book);
	void InputListBook();
	void OutputListBook();
	void InsertBook();
	void RemoveBook();
};