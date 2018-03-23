#include "DaThuc.h"
using namespace std;

int main() {
	DaThuc A, B;
	cout << "Nhap da thuc A(x):\n";
	cin >> A;
	cout << "Nhap da thuc B(x):\n";
	cin >> B;

	cout << "\nA(x) = " << A << endl;
	cout << "B(x) = " << B << endl;
	cout << "A(x) + B(x) = " << A + B << endl;
	cout << "A(x) - B(x) = " << A - B << endl;

	system("pause");
	return 1;
}