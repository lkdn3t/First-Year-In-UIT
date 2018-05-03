#include "String.h"

String::String(const char *str) {
	if (!str) len = 0;
	else len = strlen(str);
	this->str = new char[len + 1];

	for (int i = 0; i < len; i++)
		this->str[i] = *(str + i);
	this->str[len] = NULL;
}

String::String(const String & s) {
	len = s.len;
	str = new char[len + 1];

	for (int i = 0; i < len; i++)
		str[i] = *(s.str + i);
	str[len] = NULL;
}

String::~String() {
	delete[] str;
}

void String::setString(const char *s) {
	if (str != NULL) delete[]str;
	len = strlen(s);
	str = new char[len + 1];

	for (int i = 0; i < len; i++)
		str[i] = *(s + i);
	str[len] = NULL;
}

char * String::getString() const {
	char *s = new char[len + 1];
	for (int i = 0; i < len; i++)
		s[i] = str[i];
	s[len] = NULL;
	return s;
}

int String::getLength() const {
	return len;
}

String String::operator+(const String & s) const {
	char* SumString = new char[len + s.len + 1];
	int LENGTH = len + s.len;
	
	for (int i = 0; i < len; i++)
		SumString[i] = *(str + i);

	for (int i = len; i < LENGTH; i++)
		SumString[i] = *(s.str + i - len);
	SumString[LENGTH] = NULL;

	return String(SumString);
}

bool String::operator==(const String & s) const {
	return strcmp(str, s.str) == 0;
}

bool String::operator!=(const String & s) const {
	return strcmp(str, s.str);
}

bool String::operator>=(const String & s) const {
	return strcmp(str, s.str) != -1;
}

bool String::operator<=(const String & s) const {
	return strcmp(str, s.str) != 1;
}

bool String::operator>(const String & s) const {
	return strcmp(str, s.str) == 1;
}

bool String::operator<(const String & s) const {
	return strcmp(str, s.str) == -1;
}

ostream & operator<<(ostream & os, const String & s) {
	for (int i = 0; i < s.len; i++)
		os << s.str[i];
	return os;
}

istream & operator>>(istream & is, String & s) {
	int length;
	cout << "Nhap so luong ki tu: ";
	is >> length;
	s.len = length;
	
	cout << "Nhap chuoi ki tu: ";
	s.str = new char[length + 1];
	for (int i = 0; i < length; i++)
		is >> s.str[i];

	s.str[length] = NULL;
	return is;
}