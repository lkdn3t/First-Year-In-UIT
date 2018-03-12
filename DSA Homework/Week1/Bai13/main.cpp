#include "MaxWordStr.h"
using namespace std;

int main(int argc, char* argv[]) {
	//Khởi tạo chuỗi string từ command line
	//Cách khởi tạo: nhập chuỗi trong ngoặc kép từ command line
	//(VD: "  abc  " => str = "   abc  ")
	string str;
	if (argc > 1)
		str = argv[1];
	else {
		cout << "Khong du tham so nhap vao!\n";
		return 0;
	}

	//Xuất chuỗi nhập vào và chuỗi chỉ gồm những từ dài nhất của chuỗi nhập vào
	string MaxString = MaxWordString(str);
	cout << "Chuoi nhap vao: " << str;
	cout << "\nChuoi gom cac tu dai nhat: " << MaxString << "\n";

	system("pause");
	return 1;
}