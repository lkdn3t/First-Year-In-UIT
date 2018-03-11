#include "Point2D.h"
#include <iostream>
#include <conio.h>
using namespace std;

int main(int argc, char* argv[]) {
	Circle C;
	C.setCircle();

	cout << "\nDuong tron dan nhap:\n";
	C.printCircle();
	cout << "\n";

	_getch();
	return 0;
}