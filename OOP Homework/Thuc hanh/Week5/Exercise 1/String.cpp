#include "String.h"
using namespace std;

//Tạo constructor và destructor
String::String()  { length = 0; }

String::String(const String &s) {
    str    = s.str;
    length = s.length;
}

String::String(const vector<char> &s) {
    str    = s;
    length = s.size();
}

//Nhập vào một string
void String::getString(int len) {
    char chr;
    for (int i = 0; i < len; i++) {
        cin >> chr;
        str.push_back(chr);
    }
    length = len;
}

//Xuất ra một string
void String::putString() const {
    for (int i = 0; i < length; i++)
        cout << str[i];
    cout << "\n";
}

//Lấy độ dài một chuỗi
int String::getLength() const {
    return length;
}

//Nối hai chuỗi
String String::Add(const String& s) const {
    vector<char> SumString(str);
    for (int i = 0; i < s.length; i++)
        SumString.push_back(s.str[i]);
    return SumString;
}

//Đảo ngược chuỗi
String String::Reverse() const {
    vector<char> RevString;
    for (int i = length - 1; i >= 0; i--)
        RevString.push_back(str[i]);
    return RevString;
}