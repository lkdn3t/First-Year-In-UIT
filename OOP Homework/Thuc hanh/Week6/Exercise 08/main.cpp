#include "Vector.h"

using namespace std;

int main(int argc, char *argv[]) {
	Vector *v1 = new Vector();
	Vector *v2 = new Vector();

	cin >> *v1;
	cout << *v1 << endl;

	cin >> *v2;
	cout << *v2 << endl;

	cout << *v1 + *v2 << endl;
	cout << *v1 - *v2;
	cout << *v1 * 3;
	
	delete v1, v2;
	system("pause");
	return 0;
}