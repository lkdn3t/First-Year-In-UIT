#include "Polynomial.h"
#include <iostream>
#include <conio.h>
using namespace std;

int main() {
	Polynomial A, B;
	cout << "Nhap da thuc A:\n";
	A.setPolynomial();
	cout << "\nNhap da thuc B:\n";
	B.setPolynomial();

	cout << "\nDa thuc A(x) = ";
	A.putPolynomial();
	cout << "\nDa thuc B(x) = ";
	B.putPolynomial();

	int x;
	cout << "\nA(" << x << ") = " << A.calPolynomial(x);

	Polynomial Sum = A.add(B), Diff = A.subtract(B);
	cout << "\n\nTong A(x) + B(x) = ";
	Sum.putPolynomial();
	cout << "\nHieu A(x) - B(x) = ";
	Diff.putPolynomial();

	A.delPolynomial(); B.delPolynomial();
	Sum.delPolynomial(); Diff.delPolynomial();
	
	cout << "\n";
	_getch();
	return 0;
}