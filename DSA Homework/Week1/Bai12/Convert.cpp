#include "Convert.h"
using namespace std;

//Xoá kí tự khoảng trắng ở đầu chuỗi
void delFirstSpace(string& str) {
	while (str[0] == ' ') str.erase(0, 1);
}

//Xoá kí tự trắng ở cuối chuỗi
void delLastSpace(string& str) {
	int n = str.length() - 1;
	while (str[n] == ' ')
		str.erase(n--);
}

//Xoá kí tự trắng liên tiếp
void delDupSpace(string& str) {
	int n = str.length();
	for (int i = 1; i < n; ++i)
		if (str[i] == ' ' && str[i - 1] == ' ') {
			str.erase(i, 1); 
			--i; --n;
		}
}

//Chuẩn hoá chuỗi (xoá khoảng trắng đầu, cuối, và đúp)
string ConvertString(string str) {
	delFirstSpace(str);
	delLastSpace(str);
	delDupSpace(str);
	return str;
}