#include "Time.h"
using namespace std;

//Hàm main giống như bài 2
//Hàm main bài này dùng để test đếm ngược thời gian
int main(int argc, char *argv[]) {
	cout << "!...INSERT TIME...!\n";
	Time time;
	time.getTime();

	int TotalSec = time.ToSec();
	while (TotalSec--) {
		system("cls");
		cout << "!...COUNTING DOWN TIME...!\n\t";
		time.SubtractSec();
		time.putTime();
		Sleep(1000);
	}

	system("cls");
	cout << "...TIME UP...\n";
	system("pause");
	return 0;
}