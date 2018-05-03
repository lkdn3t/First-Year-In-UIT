#include "TimeSpan.h"

using namespace std;

int main(int argc, char *argv[]) {
	//Input two TimeSpan(s), check if the input is correct
	TimeSpan t1, t2;
	cout << "...Nhap thoi gian...\n";
	do {
		cout << " Nhap thoi gian thu nhat: ";
		cin >> t1;
	} while (!t1.isTime());

	do {
		cout << " Nhap thoi gian thu hai: ";
		cin >> t2;
	} while (!t2.isTime());

	//Output two format-input-TimeSpan(s)
	cout << "\n...Thoi gian da nhap...\n";
	cout << " Thoi gian t1 = " << t1 << endl;
	cout << " Thoi gian t2 = " << t2 << endl;

	//Calculate Sum and Difference of two TimeSpan(s)
	cout << "\n...Tong va hieu hai thoi gian...\n";
	cout << " Tong hai thoi gian " << t1 + t2 << endl;
	cout << " Hieu hai thoi gian " << t1 - t2 << endl;

	//Compare two TimeSpan(s)
	cout << "\n...So sanh hai thoi gian...\n ";
	if (t1 == t2) cout << t1 << " = " << t2;
	else if (t1 > t2) cout << t1 << " > " << t2;
	else cout << t1 << " < " << t2;

	cout << endl << endl;
	system("pause");
	return 0;
}