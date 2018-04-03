#include "Array.h"
#include "Search.h"
#include "Sort.h"
#include "SortRev.h"

using namespace std;

int main() {
	int *a, n;
	RandomArray(a, n);
	int h[4] = { 7,5,1 };

	cout << "Mang sinh ngau nhien: ";
	PutArray(a, n);

	//Choose your sort here
	ShellSort_Rev(a, n, h, 3);
	cout << "Mang da sap xep: ";
	PutArray(a, n);

	delete[]a;
	system("pause");
	return 0;
}