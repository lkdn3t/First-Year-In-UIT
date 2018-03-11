#include <iostream>
using namespace std;

class Array {
private:
	//Định thuộc tính của mảng
	//Gồm số phần tử và các phần tử
	int NumberOfElements;
	int *Elements;

public:
	//Định thuộc tính
	void setArray();
	void putArray();
	void delArray();
	int countElement(int&);
	bool isIncreaseArray();
	int minOddElement();
};