#include "INTEGER.h"

using namespace std;

INTEGER::INTEGER(int i) {
	content = i;
}

INTEGER INTEGER::operator+(const INTEGER & i) const {
	return INTEGER(content + i.content);
}

INTEGER INTEGER::operator-(const INTEGER & i) const {
	return INTEGER(content - i.content);
}

INTEGER INTEGER::operator*(const INTEGER & i) const {
	return INTEGER(content * i.content);
}

INTEGER INTEGER::operator/(const INTEGER & i) const {
	return INTEGER(content / i.content);
}

INTEGER INTEGER::operator%(const INTEGER & i) const {
	return INTEGER(content % i.content);
}

bool INTEGER::operator==(const INTEGER & i) const {
	return content == i.content;
}

bool INTEGER::operator!=(const INTEGER & i) const {
	return content != i.content;
}

bool INTEGER::operator>=(const INTEGER & i) const {
	return content >= i.content;
}

bool INTEGER::operator<=(const INTEGER & i) const {
	return content <= i.content;
}

bool INTEGER::operator>(const INTEGER & i) const {
	return content > i.content;
}

bool INTEGER::operator<(const INTEGER & i) const {
	return content < i.content;
}

int INTEGER::GetContent() {
	return content;
}

ostream & operator<<(ostream & os, const INTEGER & i) {
	os << i.content;
	return os;
}

istream & operator>>(istream & is, INTEGER & i) {
	is >> i.content;
	return is;
}
