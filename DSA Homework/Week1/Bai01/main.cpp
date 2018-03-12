#include "DoiTien.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
	//Khởi tạo tham số từ command line gắn cho biến tien
	int tien;
	if (argc > 1) tien = atoi(argv[1]);
	else {
		cout << "Khong du tham so nhap vao!\n";
		system("pause");
		return 1;
	}

	cout << "So tien da nhap: " << tien << "d\n";
	DoiTien(tien);
	
	system("pause");
	return 1;
}