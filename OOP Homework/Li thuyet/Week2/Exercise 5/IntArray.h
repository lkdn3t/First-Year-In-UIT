#include <iostream>
using namespace std;

#pragma once
class IntArray {
private:
	//Định thuộc tính của mảng
	//Gồm số lượng phần tử và mảng cấp phát
	int n;
	int *a;

public:
	IntArray();
	~IntArray();

	int getLarge();
	void setArray();
	void printArray();

	int MaxNegElement();
	int countElement(int&);
	bool isIncArray();
	void sortArray();
};