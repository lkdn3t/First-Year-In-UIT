#include "DaThuc.h"

using namespace std;

int main(int argc, char *argv[]) {
	DaThuc dt1, dt2;
	cout << "\n...Nhap da thuc 1...\n";
	cin >> dt1;

	cout << "\n...Nhap da thuc 2...\n";
	cin >> dt2;

	cout << "\n...Da thuc da nhap...";
	cout << "\nDa thuc 1: " << dt1;
	cout << "\nDa thuc 2: " << dt2;

	cout << "\n\n...Tong hieu da thuc...";
	cout << "\nTong da thuc: " << dt1 + dt2;
	cout << "\nHieu da thuc: " << dt1 - dt2;

	cout << "\n\n";
	system("pause");
	return 0;
}