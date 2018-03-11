#include <iostream>
using namespace std;

class Set {
private:
	//Định thuộc tính của tập hợp
	//Gồm số phần tử và các phần tử
	int size;
	int *ele;

public:
	//Định các chức năng
	void setElements();
	void setElements(int, int*);
	void printSet();
	void sortSet();

	Set	Intersect(Set);
	Set Union(Set);
};