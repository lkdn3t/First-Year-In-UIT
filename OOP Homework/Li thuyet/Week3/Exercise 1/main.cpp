#include "Array.h"
#include <iostream>
#include <conio.h>
using namespace std;

int main() {
	Array arr;
	arr.setArray();
	arr.putArray();

	int ele;
	cout << "\n-> So lan xuat hien cua phan tu " << ele << " trong mang: " << arr.countElement(ele) << "\n";
	arr.isIncreaseArray() ? cout << "\n-> Mang tang dan.\n" : cout << "\n-> Mang khong tang dan.\n";
	arr.minOddElement()	? cout << "\n-> Phan tu le nho nhat: " << arr.minOddElement() << "\n"
						: cout << "\n-> Mang khong co phan tu le.\n";
	
	arr.delArray();
	_getch();
	return 1;
}