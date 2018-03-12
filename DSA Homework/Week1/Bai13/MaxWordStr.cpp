#include "MaxWordStr.h"
using namespace std;

//Tìm độ dài của kí tự dài nhất
int LengthMaxWord(string str) {
	int maxLength = 0;
	int length = 0;
	int n = str.length();

	//Cho biến đếm length tăng, khi gặp dấu cách (' ') hoặc kí tự cuối cùng tức là hết từ
	//So sánh độ dài maxLength và độ dài length đếm được và cập nhật
	for (int i = 0; i < n; ++i) {
		if (str[i] != ' ' && i != n - 1) ++length;
		else {
			if (i == n - 1) ++length;
			if (length > maxLength) maxLength = length;
			length = 0;
		}
	}
	return maxLength;
}

//Tạo chuỗi chỉ gồm các từ có độ dài dài nhất trong chuỗi ban đầu
string MaxWordString(string str) {
	string temp = "";
	string MaxString = "";
	int n = str.length(), length = 0;
	int maxLength = LengthMaxWord(str);

	//Tương tự như hàm LengthMaxWord + lưu các kí tự để lưu từ
	//Sau đó gán từ đó (nếu là từ dài nhất) vào MaxString
	for (int i = 0; i < n; ++i) {
		if (str[i] != ' ' && i != n - 1) {
			temp += str[i];
			++length;
		} 
		else {
			if (i == n - 1) { ++length; temp += str[n - 1]; }
			if (length == maxLength)
				if (!MaxString.length()) MaxString += temp;
				else MaxString += (" " + temp);
			temp = ""; length = 0;
		}
	}
	return MaxString;
}