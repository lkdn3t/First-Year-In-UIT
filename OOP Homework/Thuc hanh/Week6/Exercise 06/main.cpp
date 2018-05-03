#include "String.h"
#define elif else if

using namespace std;

int main(int argc, char *argv[]) {
	String s1, s2;
	cout << "...Nhap chuoi s1...\n"  ; cin >> s1;
	cout << "\n...Nhap chuoi s2...\n"; cin >> s2;

	cout << "\n...Hai chuoi nhap vao...\n";
	cout << " Chuoi s1: " << s1 << endl;
	cout << " Chuoi s2: " << s2 << endl;

	cout << "\n...Noi chuoi va so sanh...\n";
	cout << " Chuoi s1 + s2: " << s1 + s2 << endl;
	
	cout << " So sanh: ";
	if   (s1 == s2) cout << "s1 = s2";
	elif (s1 > s2)  cout << "s1 > s2";
	elif (s1 < s2)  cout << "s1 < s2";

	cout << "\n\n";
	system("pause");
	return 0;
}