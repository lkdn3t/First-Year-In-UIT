#include "Convert.h"
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

	//Xuất chuỗi nhập vào và chuỗi đã chuẩn hoá
	string convert_str = ConvertString(str);
	cout << "Chuoi nhap vao: " << str;
	cout << "\nChuoi chuan hoa: " << convert_str << "\n";

	system("pause");
	return 1;
}