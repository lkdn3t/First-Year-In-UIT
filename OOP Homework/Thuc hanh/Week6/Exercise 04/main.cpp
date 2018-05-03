#include "Time.h"

using namespace std;

int main(int argc, char *argv[]) {
	Time time;
	do {
		cout << "Nhap thoi gian: ";
		cin >> time;
	} while (!time.isTime());

	cout << "\nThoi gian da nhap: " << time << endl;
	
	int delta;
	cout << "\nNhap do lech thoi gian (s): ";
	cin >> delta;

	cout << "\nThoi gian sau khi cong = " << time + delta << endl;
	cout << "Thoi gian sau khi tru  = "   << time - delta << endl << endl;

	system("pause");
	return 0;
}